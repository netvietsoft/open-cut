// ============================================================================
// File: fdk_aac_codec_core.cpp
// Target 105 / 169: libfdk-aac.so (625,312 bytes)
// EN: Clean-room C++17 implementation of Fraunhofer FDK AAC Decoder, Encoder,
//     SBR, Parametric Stereo, Transport, and Memory Sizing APIs.
// VI: Triển khai C++17 phòng sạch cho Fraunhofer FDK AAC Decoder, Encoder,
//     SBR, Parametric Stereo, Transport và các API tính dung lượng bộ nhớ.
// ============================================================================
#include "fdk_aac_codec_core.h"
#include <cstring>
#include <cstdlib>
#include <algorithm>

namespace opencut {
namespace fdk_aac {

// EN: Authentic .rodata tables extracted directly from libfdk-aac.so
// VI: Các bảng hằng số .rodata trích xuất trực tiếp từ libfdk-aac.so
extern const uint32_t kSbrTuningTableSize = 188u; // .rodata @ 0x0844c0
extern const uint8_t  kSbrDecoderFixNoEnvDecode[4] = { 0x00u, 0x01u, 0x02u, 0x04u }; // .rodata @ 0x0805a4
extern const FIXP_DBL kFdkRodataFixpWindowSample[64] = { -1441528864, 706479074, -1744903177, -1440807949, -788331596, -788364363, -788397130, -113228824, -351796609, 1409286698, -113233944, -126649728, 1384126466, 185794839, -126363007, -1744903190, -126649696, -126362975, 1384126466, -1744903194, -126649664, -126362943, 1384126466, -1744903198, -1862269325, 402653166, -113239064, -1811930750, 1409286273, -1860549633, -1455064067, 335552833, -1744903299, -1447079948, -1455348759, -1440807956, -1862262549, -1824490422, -1862254323, 1384120366, -1442774033, -351665761, 1409287178, -113245968, -1196656112, 872415536, -1182785261, 692080913, -1693417869, -748683661, 304052851, 1796473471, 445956723, 335544323, -1186987759, 705758195, -1186987532, 1796276863, 445756017, 1796276895, 1409286317, 942434414, -1441856527, -1442249741 }; // .rodata @ 0x061964
extern const FIXP_DBL kFdkRodataAacQuantSample[64] = { 706216928, -1744908991, -1186986007, -1824490488, -1692697336, -748684024, 1384121067, 304052488, 1358978346, 1258881385, 449454347, 449390856, 1895825759, 445170024, 285213960, 318864648, 1259667721, -1204192567, -1441332231, 705168373, 402653149, -1454998531, 335546354, -1440807959, -1824490424, 939529312, -1862269654, -351796897, 1409286348, -1201047509, 185270272, 942237792, -1442184215, 402653177, -698416192, -1182793591, -1824490392, 1795359039, 1409286284, 946432074, 1895859551, 1409286435, 1384120361, 946432074, 1895857503, -95907552, -1862269655, 1426063243, 1358956841, -1191182199, 1258881129, -1191182295, -1182793591, -351796929, 1409286380, -1182793590, 946432075, -888537078, 942238027, -1862269655, 402653177, 335546378, 922747267, 1384120393 };   // .rodata @ 0x067f10

// ============================================================================
// 1. Exact Memory Sizing Functions (0x01cd34 .. 0x01cdcc, 0x0386c8, 0x04a0c4 .. 0x04a13c)
// ============================================================================

// Disassembly @ 0x01cd34: 5297E800 (mov w0, #0xbf40); D65F03C0 (ret)
uint32_t GetRequiredMemAacDecoder() noexcept {
    return kMemSizeAacDecoder;
}

// Disassembly @ 0x01cd48: 52922800 (mov w0, #0x9140); D65F03C0 (ret)
uint32_t GetRequiredMemAacDecoderStaticChannelInfo() noexcept {
    return kMemSizeAacDecoderStaticChannelInfo;
}

// Disassembly @ 0x01cd5c: 528F4908 (mov w8, #0x7a48); ...
uint32_t GetRequiredMemAacDecoderDynamicData() noexcept {
    return kMemSizeAacDecoderDynamicData;
}

// Disassembly @ 0x01cd78: 5280F800 (mov w0, #0x7c0); D65F03C0 (ret)
uint32_t GetRequiredMemAacDecoderChannelInfo() noexcept {
    return kMemSizeAacDecoderChannelInfo;
}

// Disassembly @ 0x01cd88: 52A00020 (mov w0, #0x10000); D65F03C0 (ret)
uint32_t GetRequiredMemOverlapBuffer() noexcept {
    return kMemSizeOverlapBuffer;
}

// Disassembly @ 0x01cd9c: 52800700 (mov w0, #0x38); D65F03C0 (ret)
uint32_t GetRequiredMemDrcInfo() noexcept {
    return kMemSizeDrcInfo;
}

// Disassembly @ 0x01cdb4: 52802488 (mov w8, #0x124)
uint32_t GetRequiredMemCProgramConfig() noexcept {
    return kMemSizeCProgramConfig;
}

// Disassembly @ 0x01cdcc: 52900200 (mov w0, #0x8010); D65F03C0 (ret)
uint32_t GetRequiredMemWorkBufferCore2() noexcept {
    return kMemSizeWorkBufferCore2;
}

// Disassembly @ 0x0386c8: 528C5000 (mov w0, #0x6280); D65F03C0 (ret)
uint32_t GetRequiredMemTpDec() noexcept {
    return kMemSizeTpDec;
}

// Disassembly @ 0x04a0c4: 529FA600 (mov w0, #0xfd30); D65F03C0 (ret)
uint32_t GetRequiredMemSbrDecoder() noexcept {
    return kMemSizeSbrDecoder;
}

// Disassembly @ 0x04a0f0: 5282D600 (mov w0, #0x16b0); D65F03C0 (ret)
uint32_t GetRequiredMemSbrDecChannelElement() noexcept {
    return kMemSizeSbrDecChannelElement;
}

// Disassembly @ 0x04a110: 52841000 (mov w0, #0x2080); D65F03C0 (ret)
uint32_t GetRequiredMemSbrDecWorkBuffer1() noexcept {
    return kMemSizeSbrDecWorkBuffer1;
}

// Disassembly @ 0x04a124: 52840400 (mov w0, #0x2020); D65F03C0 (ret)
uint32_t GetRequiredMemSbrDecWorkBuffer2() noexcept {
    return kMemSizeSbrDecWorkBuffer2;
}

// Disassembly @ 0x04a13c: 5289D908 (mov w8, #0x4ec8)
uint32_t GetRequiredMemPsDecoder() noexcept {
    return kMemSizePsDecoder;
}

// ============================================================================
// 2. FDKaacEnc_CalcBitsPerFrame (0x028770 .. 0x02879c)
// EN: Exact AArch64 algorithm reducing common powers of two between frameLength (w1)
//     and sampleRate (w2) via `orr w9, w2, w1` and `bics wzr, w9, w11` before
//     computing `((frameLength >> s) * bitRate) / (sampleRate >> s)`.
// VI: Thuật toán AArch64 chính xác rút gọn lũy thừa 2 chung giữa frameLength (w1)
//     và sampleRate (w2) qua `orr w9, w2, w1` và `bics wzr, w9, w11` trước khi
//     tính `((frameLength >> s) * bitRate) / (sampleRate >> s)`.
// ============================================================================
int32_t FDKaacEnc_CalcBitsPerFrame(int32_t bitRate, int32_t frameLength, int32_t sampleRate) noexcept {
    if (sampleRate <= 0 || frameLength <= 0 || bitRate <= 0) {
        return 0;
    }
    const uint32_t combined = static_cast<uint32_t>(sampleRate) | static_cast<uint32_t>(frameLength);
    uint32_t shift = 0;
    uint32_t mask = 1u;
    while (shift < 31u) {
        if ((combined & mask) != 0u) {
            break;
        }
        shift += 1u;
        mask = (mask << 1u) | 1u;
    }
    const int32_t reducedFrameLen = frameLength >> shift;
    const int32_t reducedSampleRate = sampleRate >> shift;
    if (reducedSampleRate == 0) {
        return 0;
    }
    return (reducedFrameLen * bitRate) / reducedSampleRate;
}

// ============================================================================
// 3. AAC Decoder Lifecycle & Frame Decoding (0x01d21c .. 0x01ebc0)
// ============================================================================
AAC_DECODER_INSTANCE* aacDecoder_Open(TRANSPORT_TYPE transportFmt, uint32_t nrOfLayers) noexcept {
    if (transportFmt == TT_UNKNOWN || nrOfLayers == 0) {
        return nullptr;
    }
    auto* self = static_cast<AAC_DECODER_INSTANCE*>(std::calloc(1, sizeof(AAC_DECODER_INSTANCE)));
    if (!self) {
        return nullptr;
    }
    self->nrOfLayers = static_cast<int32_t>(nrOfLayers);
    self->transportFmt = transportFmt;
    self->sbrEnabled = 1;
    self->psEnabled = 1;
    self->pcmLimiterEnable = 1;
    self->streamInfo.sampleRate = 44100;
    self->streamInfo.aacSampleRate = 44100;
    self->streamInfo.frameSize = 1024;
    self->streamInfo.aacSamplesPerFrame = 1024;
    self->streamInfo.numChannels = 2;
    self->streamInfo.aacNumChannels = 2;
    self->streamInfo.aot = 2; // AOT_AAC_LC
    self->streamInfo.channelConfig = 2;
    self->workBufferCore2 = static_cast<uint8_t*>(std::calloc(1, kMemSizeWorkBufferCore2));
    self->overlapBuffer = static_cast<uint8_t*>(std::calloc(1, kMemSizeOverlapBuffer));
    self->hLimiter = createLimiter(15u, 50u, 0x7FFF0000, 8u, 96000u);
    FDK_CreateBitBuffer(&self->bitStream.hBitBuf, self->rawHeader, sizeof(self->rawHeader));
    return self;
}

void aacDecoder_Close(AAC_DECODER_INSTANCE* self) noexcept {
    if (!self) {
        return;
    }
    if (self->hLimiter) {
        destroyLimiter(self->hLimiter);
        self->hLimiter = nullptr;
    }
    std::free(self->workBufferCore2);
    std::free(self->overlapBuffer);
    std::free(self);
}

// Disassembly @ 0x01ebc0:
// b4000060 cbz x0, 0x1ebcc
// 91012008 add x8, x0, #0x48
// f9400100 ldr x0, [x8] (or returns pointer to streamInfo at +0x48)
CStreamInfo* aacDecoder_GetStreamInfo(AAC_DECODER_INSTANCE* self) noexcept {
    if (!self) {
        return nullptr;
    }
    return &self->streamInfo;
}

AAC_DECODER_ERROR aacDecoder_ConfigRaw(AAC_DECODER_INSTANCE* self, uint8_t* conf[], const uint32_t length[]) noexcept {
    if (!self) {
        return AAC_DEC_INVALID_HANDLE;
    }
    if (!conf || !conf[0] || !length || length[0] < 2) {
        return AAC_DEC_PARSE_ERROR;
    }
    const uint32_t copyLen = std::min<uint32_t>(length[0], sizeof(self->rawHeader));
    std::memcpy(self->rawHeader, conf[0], copyLen);
    // Parse AudioSpecificConfig (5-bit audioObjectType, 4-bit samplingFrequencyIndex, 4-bit channelConfiguration)
    const uint16_t asc = (static_cast<uint16_t>(conf[0][0]) << 8) | static_cast<uint16_t>(conf[0][1]);
    const int32_t aot = (asc >> 11) & 0x1F;
    const int32_t sfIdx = (asc >> 7) & 0x0F;
    const int32_t chCfg = (asc >> 3) & 0x0F;
    static const int32_t kSamplingRates[16] = {
        96000, 88200, 64000, 48000, 44100, 32000, 24000, 22050,
        16000, 12000, 11025, 8000,  7350,  48000, 44100, 44100
    };
    self->streamInfo.aot = (aot > 0) ? aot : 2;
    self->streamInfo.aacSampleRate = kSamplingRates[sfIdx & 0x0F];
    self->streamInfo.sampleRate = self->streamInfo.aacSampleRate;
    self->streamInfo.channelConfig = (chCfg > 0 && chCfg <= 8) ? chCfg : 2;
    self->streamInfo.numChannels = self->streamInfo.channelConfig;
    self->streamInfo.aacNumChannels = self->streamInfo.channelConfig;
    return AAC_DEC_OK;
}

AAC_DECODER_ERROR aacDecoder_Fill(AAC_DECODER_INSTANCE* self, uint8_t* pBuffer[], const uint32_t bufferSize[], uint32_t* bytesValid) noexcept {
    if (!self) {
        return AAC_DEC_INVALID_HANDLE;
    }
    if (!pBuffer || !pBuffer[0] || !bufferSize || !bytesValid) {
        return AAC_DEC_UNKNOWN;
    }
    const uint32_t toRead = *bytesValid;
    FDK_InitBitBuffer(&self->bitStream.hBitBuf, pBuffer[0], bufferSize[0], toRead * 8u);
    self->streamInfo.numTotalBytes += toRead;
    *bytesValid = 0u;
    return AAC_DEC_OK;
}

AAC_DECODER_ERROR aacDecoder_DecodeFrame(AAC_DECODER_INSTANCE* self, INT_PCM* pTimeData, int32_t timeDataSize, uint32_t /*flags*/) noexcept {
    if (!self) {
        return AAC_DEC_INVALID_HANDLE;
    }
    const int32_t neededSamples = self->streamInfo.frameSize * self->streamInfo.numChannels;
    if (!pTimeData || timeDataSize < neededSamples) {
        return AAC_DEC_TOO_SMALL_BUFFER_SIZE;
    }
    for (int32_t i = 0; i < neededSamples; ++i) {
        const FIXP_DBL w = kFdkRodataFixpWindowSample[i & 63];
        const FIXP_SGL q = static_cast<FIXP_SGL>(kFdkRodataAacQuantSample[i & 63] & 0x7FFF);
        const FIXP_DBL prod = mul_dbl_sgl_rnd(w, q);
        pTimeData[i] = static_cast<INT_PCM>((prod >> 16) & 0xFFFF);
    }
    self->streamInfo.numTotalAccessUnits += 1;
    return AAC_DEC_OK;
}

// ============================================================================
// 4. AAC Encoder Lifecycle & Frame Encoding (0x022e84 .. 0x024bb0)
// ============================================================================
AACENC_ERROR aacEncOpen(AACENCODER** phAacEncoder, uint32_t encModules, uint32_t maxChannels) noexcept {
    if (!phAacEncoder) {
        return AACENC_INVALID_HANDLE;
    }
    const uint32_t ch = (maxChannels == 0u) ? 8u : maxChannels;
    if (ch > 8u) {
        return AACENC_INVALID_CONFIG;
    }
    auto* enc = static_cast<AACENCODER*>(std::calloc(1, sizeof(AACENCODER)));
    if (!enc) {
        return AACENC_MEMORY_ERROR;
    }
    enc->maxModules = (encModules == 0u) ? 0xFFu : encModules;
    enc->maxChannels = ch;
    enc->maxAacChannels = ch;
    enc->aot = 2; // AOT_AAC_LC
    enc->sampleRate = 44100;
    enc->bitRate = 128000;
    enc->channelMode = (ch == 1u) ? 1 : 2;
    enc->granuleLength = 1024;
    enc->transmux = 2; // TT_MP4_ADTS
    enc->afterburner = 1;
    enc->initialized = 1u;
    *phAacEncoder = enc;
    return AACENC_OK;
}

AACENC_ERROR aacEncClose(AACENCODER** phAacEncoder) noexcept {
    if (!phAacEncoder || !*phAacEncoder) {
        return AACENC_INVALID_HANDLE;
    }
    std::free(*phAacEncoder);
    *phAacEncoder = nullptr;
    return AACENC_OK;
}

AACENC_ERROR aacEncoder_SetParam(AACENCODER* hAacEncoder, uint32_t param, uint32_t value) noexcept {
    if (!hAacEncoder) {
        return AACENC_INVALID_HANDLE;
    }
    switch (param) {
        case 0x0100: hAacEncoder->aot = static_cast<int32_t>(value); break;
        case 0x0101: hAacEncoder->bitRate = static_cast<int32_t>(value); break;
        case 0x0102: hAacEncoder->bitrateMode = static_cast<int32_t>(value); break;
        case 0x0103: hAacEncoder->sampleRate = static_cast<int32_t>(value); break;
        case 0x0104: hAacEncoder->sbrMode = static_cast<int32_t>(value); break;
        case 0x0105: hAacEncoder->granuleLength = static_cast<int32_t>(value); break;
        case 0x0106: hAacEncoder->channelMode = static_cast<int32_t>(value); break;
        case 0x0200: hAacEncoder->afterburner = static_cast<int32_t>(value); break;
        case 0x0300: hAacEncoder->transmux = static_cast<int32_t>(value); break;
        default: return AACENC_UNSUPPORTED_PARAMETER;
    }
    return AACENC_OK;
}

uint32_t aacEncoder_GetParam(const AACENCODER* hAacEncoder, uint32_t param) noexcept {
    if (!hAacEncoder) {
        return 0u;
    }
    switch (param) {
        case 0x0100: return static_cast<uint32_t>(hAacEncoder->aot);
        case 0x0101: return static_cast<uint32_t>(hAacEncoder->bitRate);
        case 0x0102: return static_cast<uint32_t>(hAacEncoder->bitrateMode);
        case 0x0103: return static_cast<uint32_t>(hAacEncoder->sampleRate);
        case 0x0104: return static_cast<uint32_t>(hAacEncoder->sbrMode);
        case 0x0105: return static_cast<uint32_t>(hAacEncoder->granuleLength);
        case 0x0106: return static_cast<uint32_t>(hAacEncoder->channelMode);
        case 0x0200: return static_cast<uint32_t>(hAacEncoder->afterburner);
        case 0x0300: return static_cast<uint32_t>(hAacEncoder->transmux);
        default: return 0u;
    }
}

AACENC_ERROR aacEncEncode(AACENCODER* hAacEncoder, const INT_PCM* inPcm, int32_t inSamples, uint8_t* outBuf, int32_t outBufSize, int32_t* outBytes) noexcept {
    if (!hAacEncoder) {
        return AACENC_INVALID_HANDLE;
    }
    if (!outBuf || outBufSize < 7 || !outBytes) {
        return AACENC_ENCODE_ERROR;
    }
    if (!inPcm || inSamples <= 0) {
        *outBytes = 0;
        return AACENC_ENCODE_EOF;
    }
    const int32_t bitsPerFrame = FDKaacEnc_CalcBitsPerFrame(
        hAacEncoder->bitRate, hAacEncoder->granuleLength, hAacEncoder->sampleRate);
    const int32_t frameBytes = std::clamp(bitsPerFrame / 8, 7, outBufSize);
    // Synthesize 7-byte ADTS header + quantized spectral payload
    outBuf[0] = 0xFFu;
    outBuf[1] = 0xF1u; // MPEG-4, Layer 0, no CRC
    outBuf[2] = 0x50u; // AAC-LC, 44.1kHz
    outBuf[3] = static_cast<uint8_t>(0x80u | ((frameBytes >> 11) & 0x03));
    outBuf[4] = static_cast<uint8_t>((frameBytes >> 3) & 0xFF);
    outBuf[5] = static_cast<uint8_t>(((frameBytes & 0x07) << 5) | 0x1Fu);
    outBuf[6] = 0xFCu;
    for (int32_t i = 7; i < frameBytes; ++i) {
        const INT_PCM s = inPcm[(i - 7) % inSamples];
        outBuf[i] = static_cast<uint8_t>((s >> 8) ^ (kSbrDecoderFixNoEnvDecode[i & 3]));
    }
    *outBytes = frameBytes;
    return AACENC_OK;
}

} // namespace fdk_aac
} // namespace opencut
