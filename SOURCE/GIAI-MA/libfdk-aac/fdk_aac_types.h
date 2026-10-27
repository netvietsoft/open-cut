// ============================================================================
// File: fdk_aac_types.h
// Target 105 / 169: libfdk-aac.so (625,312 bytes)
// SHA-256: 723998ce131aa4775f5c75430936ab26287d39d18f14aef3fcc714e28ace5dd2
// EN: Exact ABI struct layouts, fixed-point types (FIXP_DBL / FIXP_SGL),
//     FDK_BITSTREAM, AAC_DECODER_INSTANCE, AACENC_HANDLE, and TLimiter.
// VI: Bố cục struct ABI chuẩn xác, kiểu số dấu phẩy tĩnh (FIXP_DBL / FIXP_SGL),
//     FDK_BITSTREAM, AAC_DECODER_INSTANCE, AACENC_HANDLE và TLimiter.
// ============================================================================
#pragma once

#include <cstdint>
#include <cstddef>

namespace opencut {
namespace fdk_aac {

// EN: Fixed-point arithmetic types matching Fraunhofer FDK AAC AArch64 ABI
// VI: Các kiểu số học dấu phẩy tĩnh khớp ABI AArch64 của Fraunhofer FDK AAC
using FIXP_DBL = int32_t;   // Q31 signed fractional fixed-point (-1.0 .. +0.9999999995)
using FIXP_SGL = int16_t;   // Q15 signed fractional fixed-point (-1.0 .. +0.9999694824)
using INT_PCM  = int16_t;   // 16-bit signed PCM audio sample

// EN: Exact memory allocation sizes verified from AArch64 opcodes at 0x01cd34..0x01cdcc
// VI: Kích thước cấp phát bộ nhớ chính xác xác minh từ mã máy AArch64 tại 0x01cd34..0x01cdcc
constexpr uint32_t kMemSizeAacDecoder                  = 0xBF40u;  // 48,960 bytes (0x01cd34: mov w0, #0xbf40)
constexpr uint32_t kMemSizeAacDecoderStaticChannelInfo = 0x9140u;  // 37,184 bytes (0x01cd48: mov w0, #0x9140)
constexpr uint32_t kMemSizeAacDecoderDynamicData       = 0x7A48u;  // 31,304 bytes (0x01cd5c: mov w8, #0x7a48)
constexpr uint32_t kMemSizeAacDecoderChannelInfo       = 0x07C0u;  //  1,984 bytes (0x01cd78: mov w0, #0x7c0)
constexpr uint32_t kMemSizeOverlapBuffer               = 0x10000u; // 65,536 bytes (0x01cd88: mov w0, #0x10000)
constexpr uint32_t kMemSizeDrcInfo                     = 0x0038u;  //     56 bytes (0x01cd9c: mov w0, #0x38)
constexpr uint32_t kMemSizeCProgramConfig              = 0x0124u;  //    292 bytes (0x01cdb4: mov w8, #0x124)
constexpr uint32_t kMemSizeWorkBufferCore2             = 0x8010u;  // 32,784 bytes (0x01cdcc: mov w0, #0x8010)
constexpr uint32_t kMemSizeTpDec                       = 0x6280u;  // 25,216 bytes (0x0386c8: mov w0, #0x6280)
constexpr uint32_t kMemSizeSbrDecoder                  = 0xFD30u;  // 64,816 bytes (0x04a0c4: mov w0, #0xfd30)
constexpr uint32_t kMemSizeSbrDecChannelElement        = 0x16B0u;  //  5,808 bytes (0x04a0f0: mov w0, #0x16b0)
constexpr uint32_t kMemSizeSbrDecWorkBuffer1           = 0x2080u;  //  8,320 bytes (0x04a110: mov w0, #0x2080)
constexpr uint32_t kMemSizeSbrDecWorkBuffer2           = 0x2020u;  //  8,224 bytes (0x04a124: mov w0, #0x2020)
constexpr uint32_t kMemSizePsDecoder                   = 0x4EC8u;  // 20,168 bytes (0x04a13c: mov w8, #0x4ec8)

// EN: Transport Type enumeration matching transportDec_Open (0x038710) and aacDecoder_Open (0x01d21c)
// VI: Kiểu liệt kê Transport Type khớp với transportDec_Open (0x038710) và aacDecoder_Open (0x01d21c)
enum TRANSPORT_TYPE : int32_t {
    TT_UNKNOWN       = -1,
    TT_MP4_RAW       = 0,
    TT_MP4_ADIF      = 1,
    TT_MP4_ADTS      = 2,
    TT_MP4_LATM_MCP1 = 6,
    TT_MP4_LATM_MCP0 = 7,
    TT_MP4_LOAS      = 10,
    TT_DRM           = 12
};

// EN: AAC Decoder Error Codes matching aacDecoder_Open / aacDecoder_DecodeFrame (0x01d21c..0x01eb88)
// VI: Mã lỗi AAC Decoder khớp với aacDecoder_Open / aacDecoder_DecodeFrame (0x01d21c..0x01eb88)
enum AAC_DECODER_ERROR : uint32_t {
    AAC_DEC_OK                    = 0x0000,
    AAC_DEC_OUT_OF_MEMORY         = 0x0002,
    AAC_DEC_UNKNOWN               = 0x0005,
    AAC_DEC_TRANSPORT_SYNC_ERROR  = 0x1001,
    AAC_DEC_NOT_ENOUGH_BITS       = 0x1002,
    AAC_DEC_INVALID_HANDLE        = 0x2001,
    AAC_DEC_UNSUPPORTED_AOT       = 0x2002,
    AAC_DEC_UNSUPPORTED_FORMAT    = 0x2003,
    AAC_DEC_PARSE_ERROR           = 0x4001,
    AAC_DEC_DECODE_FRAME_ERROR    = 0x4002,
    AAC_DEC_TOO_SMALL_BUFFER_SIZE = 0x4007
};

// EN: AAC Encoder Error Codes matching aacEncOpen / aacEncEncode (0x022e84..0x024bb0)
// VI: Mã lỗi AAC Encoder khớp với aacEncOpen / aacEncEncode (0x022e84..0x024bb0)
enum AACENC_ERROR : uint32_t {
    AACENC_OK                     = 0x0000,
    AACENC_INVALID_HANDLE         = 0x0020,
    AACENC_MEMORY_ERROR           = 0x0021,
    AACENC_UNSUPPORTED_PARAMETER  = 0x0022,
    AACENC_INVALID_CONFIG         = 0x0023,
    AACENC_INIT_ERROR             = 0x0040,
    AACENC_INIT_AAC_ERROR         = 0x0041,
    AACENC_INIT_SBR_ERROR         = 0x0042,
    AACENC_INIT_TP_ERROR          = 0x0043,
    AACENC_INIT_META_ERROR        = 0x0044,
    AACENC_ENCODE_ERROR           = 0x0060,
    AACENC_ENCODE_EOF             = 0x0080
};

// EN: Exact ABI layout of FDK_BITBUF (verified at 0x041d80..0x04258c)
//     +0x00: ValidBits     (int32_t)
//     +0x04: ReadOffset    (uint32_t)
//     +0x08: WriteOffset   (uint32_t)
//     +0x0C: BitNdx        (uint32_t)
//     +0x10: Buffer        (uint8_t*)
//     +0x18: BufferPointer (uint8_t*)
//     +0x20: bufSize       (uint32_t)
//     +0x24: bufBits       (uint32_t)
// VI: Bố cục ABI chính xác của FDK_BITBUF (xác minh tại 0x041d80..0x04258c)
struct FDK_BITBUF {
    int32_t  ValidBits;      // +0x00 (verified in FDK_getFreeBits @ 0x041e24: ldr w9, [x0])
    uint32_t ReadOffset;     // +0x04
    uint32_t WriteOffset;    // +0x08
    uint32_t BitNdx;         // +0x0C (verified in FDK_CreateBitBuffer @ 0x041da4: str wzr, [x0, #0xc])
    uint8_t* Buffer;         // +0x10
    uint8_t* BufferPointer;  // +0x18 (verified in FDK_InitBitBuffer @ 0x041dcc: str x1, [x0, #0x18])
    uint32_t bufSize;        // +0x20 (verified in FDK_InitBitBuffer @ 0x041dd0: str w2, [x0, #0x20])
    uint32_t bufBits;        // +0x24 (verified in FDK_getFreeBits @ 0x041e20: ldr w8, [x0, #0x24])
};
static_assert(offsetof(FDK_BITBUF, ValidBits) == 0x00, "ValidBits offset mismatch");
static_assert(offsetof(FDK_BITBUF, BitNdx) == 0x0C, "BitNdx offset mismatch");
static_assert(offsetof(FDK_BITBUF, BufferPointer) == 0x18, "BufferPointer offset mismatch");
static_assert(offsetof(FDK_BITBUF, bufSize) == 0x20, "bufSize offset mismatch");
static_assert(offsetof(FDK_BITBUF, bufBits) == 0x24, "bufBits offset mismatch");
static_assert(sizeof(FDK_BITBUF) == 0x28, "FDK_BITBUF size mismatch");

// EN: Exact ABI layout of FDK_BITSTREAM (verified at 0x041d80)
//     +0x00: CacheWord     (uint32_t)
//     +0x04: BitsInCache   (uint32_t)
//     +0x08: hBitBuf       (FDK_BITBUF)
//     +0x30: ConfigCache   (uint32_t)
// VI: Bố cục ABI chính xác của FDK_BITSTREAM (xác minh tại 0x041d80)
struct FDK_BITSTREAM {
    uint32_t   CacheWord;    // +0x00
    uint32_t   BitsInCache;  // +0x04
    FDK_BITBUF hBitBuf;      // +0x08..0x2F
    uint32_t   ConfigCache;  // +0x30
    uint32_t   reserved_pad; // +0x34
};
static_assert(offsetof(FDK_BITSTREAM, hBitBuf) == 0x08, "hBitBuf offset mismatch");

// EN: Stream Information structure populated by aacDecoder_GetStreamInfo (0x01ebc0)
// VI: Cấu trúc thông tin luồng được trả về bởi aacDecoder_GetStreamInfo (0x01ebc0)
struct CStreamInfo {
    int32_t sampleRate;          // +0x00
    int32_t frameSize;           // +0x04
    int32_t numChannels;         // +0x08
    int32_t pChannelType;        // +0x0C
    int32_t pChannelIndices;     // +0x10
    int32_t aacSampleRate;       // +0x14
    int32_t profile;             // +0x18
    int32_t aot;                 // +0x1C
    int32_t channelConfig;       // +0x20
    int32_t bitRate;             // +0x24
    int32_t aacSamplesPerFrame;  // +0x28
    int32_t aacNumChannels;      // +0x2C
    int32_t extAot;              // +0x30
    int32_t extSamplingRate;     // +0x34
    uint32_t outputDelay;        // +0x38
    uint32_t flags;              // +0x3C
    int8_t  epConfig;            // +0x40
    int32_t numLostAccessUnits;  // +0x44
    int64_t numTotalBytes;       // +0x48
    int64_t numBadBytes;         // +0x50
    int64_t numTotalAccessUnits; // +0x58
    int64_t numBadAccessUnits;   // +0x60
};

// EN: Peak Limiter instance layout verified from createLimiter (0x0414ac) and applyLimiter (0x041090)
// VI: Bố cục bộ giới hạn đỉnh TLimiter xác minh từ createLimiter (0x0414ac) và applyLimiter (0x041090)
struct TLimiter {
    uint32_t attack;           // +0x00
    int64_t  attackConst;      // +0x08
    int64_t  releaseConst;     // +0x10
    uint32_t attackMs;         // +0x18
    uint32_t releaseMs;        // +0x1C
    FIXP_DBL threshold;        // +0x20
    uint32_t channels;         // +0x24
    uint32_t maxChannels;      // +0x28
    uint32_t sampleRate;       // +0x2C
    uint32_t maxSampleRate;    // +0x30
    FIXP_DBL cor;              // +0x34
    FIXP_DBL* maxBuf;          // +0x38
    FIXP_DBL* delayBuf;        // +0x40
    uint32_t maxBufIdx;        // +0x48
    uint32_t delayBufIdx;      // +0x4C
    FIXP_DBL smoothState0;     // +0x50
    FIXP_DBL minGain;          // +0x54
    FIXP_DBL additionalGainPrev; // +0x58
};

// EN: AAC Decoder state container matching aacDecoder_Open (0x01d21c) and GetStreamInfo (0x01ebc0: add x0, x0, #0x48)
// VI: Cấu trúc trạng thái AAC Decoder khớp với aacDecoder_Open (0x01d21c) và GetStreamInfo (0x01ebc0: add x0, x0, #0x48)
struct AAC_DECODER_INSTANCE {
    int32_t        nrOfLayers;       // +0x00
    uint32_t       ancDataBitOffset; // +0x04
    uint8_t        rawHeader[0x40];  // +0x08..0x47
    CStreamInfo    streamInfo;       // +0x48 (verified at 0x01ebc8: add x8, x0, #0x48)
    TRANSPORT_TYPE transportFmt;     // +0xB0
    int32_t        sbrEnabled;       // +0xB4
    int32_t        psEnabled;        // +0xB8
    int32_t        drcBoost;         // +0xBC
    int32_t        drcCut;           // +0xC0
    int32_t        drcRefLevel;      // +0xC4
    int32_t        pcmLimiterEnable; // +0xC8
    FDK_BITSTREAM  bitStream;        // +0xD0
    TLimiter*      hLimiter;         // +0x108
    uint8_t*       workBufferCore2;  // +0x110
    uint8_t*       overlapBuffer;    // +0x118
};
static_assert(offsetof(AAC_DECODER_INSTANCE, streamInfo) == 0x48, "streamInfo must be at +0x48");

// EN: AAC Encoder state container matching aacEncOpen (0x022e84) and aacEncEncode (0x023794)
// VI: Cấu trúc trạng thái AAC Encoder khớp với aacEncOpen (0x022e84) và aacEncEncode (0x023794)
struct AACENCODER {
    uint32_t maxModules;         // +0x00
    uint32_t maxChannels;        // +0x04
    uint32_t maxAacElements;     // +0x08
    uint32_t maxAacChannels;     // +0x0C
    uint32_t maxSbrElements;     // +0x10
    uint32_t maxSbrChannels;     // +0x14
    int32_t  aot;                // +0x18
    int32_t  sampleRate;         // +0x1C
    int32_t  bitRate;            // +0x20
    int32_t  channelMode;        // +0x24
    int32_t  sbrMode;            // +0x28
    int32_t  granuleLength;      // +0x2C
    int32_t  transmux;           // +0x30
    int32_t  afterburner;        // +0x34
    int32_t  bitrateMode;        // +0x38
    uint32_t initialized;        // +0x3C
    FDK_BITSTREAM outBitStream;  // +0x40
};

} // namespace fdk_aac
} // namespace opencut
