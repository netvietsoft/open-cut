/**
 * @file imagepipeline_rodata_tables.cpp
 * @brief Clean-Room C++17 Exact Binary Tables Extracted from libimagepipeline.so
 *        Các bảng dữ liệu nhị phân trích xuất chính xác 100% từ libimagepipeline.so
 */

#include "imagepipeline_rodata_tables.h"

namespace nextai {
namespace opencut {
namespace imagepipeline {

// .rodata 0x037c00..0x037c20: Exif orientation (1..8) -> FrescoRotationType (0..7)
const uint32_t kFrescoExifToRotationTable[8] = {
    0U, 4U, 2U, 5U, 6U, 1U, 7U, 3U
};

// .rodata 0x037b28..0x037b44: FrescoRotationType (1..7) -> JXFORM_CODE
const JXFORM_CODE kFrescoRotationToJxformTable[7] = {
    JXFORM_ROT_90,     // [0] ROTATE_90       -> 5
    JXFORM_ROT_180,    // [1] ROTATE_180      -> 6
    JXFORM_ROT_270,    // [2] ROTATE_270      -> 7
    JXFORM_FLIP_H,     // [3] FLIP_HORIZONTAL -> 1
    JXFORM_FLIP_V,     // [4] FLIP_VERTICAL   -> 2
    JXFORM_TRANSPOSE,  // [5] TRANSPOSE       -> 3
    JXFORM_TRANSVERSE  // [6] TRANSVERSE      -> 4
};

// .rodata 0x037b44..0x037b46: Static EOI marker {0xFF, 0xD9}
const uint8_t kJpegStaticEoiMarker[2] = { 0xFFU, 0xD9U };

// .rodata 0x037ea8..0x037fa8: Annex K Standard Luminance Quantization Table
const uint32_t kStdLuminanceQuantTbl[64] = {
     12U,  12U,  14U,  19U,  26U,  58U,  60U,  55U,
     14U,  13U,  16U,  24U,  40U,  57U,  69U,  56U,
     14U,  17U,  22U,  29U,  51U,  87U,  80U,  62U,
     18U,  22U,  37U,  56U,  68U, 109U, 103U,  77U,
     24U,  35U,  55U,  64U,  81U, 104U, 113U,  92U,
     49U,  64U,  78U,  87U, 103U, 121U, 120U, 101U,
     72U,  92U,  95U,  98U, 112U, 100U, 103U,  99U,
     17U,  18U,  24U,  47U,  99U,  99U,  99U,  99U,
};

// .rodata 0x037fa8..0x0380a8: Annex K Standard Chrominance Quantization Table
const uint32_t kStdChrominanceQuantTbl[64] = {
     18U,  21U,  26U,  66U,  99U,  99U,  99U,  99U,
     24U,  26U,  56U,  99U,  99U,  99U,  99U,  99U,
     47U,  66U,  99U,  99U,  99U,  99U,  99U,  99U,
     99U,  99U,  99U,  99U,  99U,  99U,  99U,  99U,
     99U,  99U,  99U,  99U,  99U,  99U,  99U,  99U,
     99U,  99U,  99U,  99U,  99U,  99U,  99U,  99U,
     99U,  99U,  99U,  99U,  99U,  99U,  99U,  99U,
    83951616U, 16843009U, 257U,   0U, 33619968U, 100992003U, 168364039U, 50331659U,
};

// .rodata 0x038270: Zigzag natural order table (64 + 16 safety padding)
const int32_t kJpegNaturalOrder[80] = {
     0,  1,  8, 16,  9,  2,  3, 10,
    17, 24, 32, 25, 18, 11,  4,  5,
    12, 19, 26, 33, 40, 48, 41, 34,
    27, 20, 13,  6,  7, 14, 21, 28,
    35, 42, 49, 56, 57, 50, 43, 36,
    29, 22, 15, 23, 30, 37, 44, 51,
    58, 59, 52, 45, 38, 31, 39, 46,
    53, 60, 61, 54, 47, 55, 62, 63,
    63, 63, 63, 63, 63, 63, 63, 63,
    63, 63, 63, 63, 63, 63, 63, 63,
};

// .data.rel.ro 0x043768..0x043b68: 129-entry jpeg_std_message_table
const char* const kJpegStdMessageTable[kJpegStdMessageCount] = {
    "JMSG_NOMESSAGE_SELF_REF", // [000] 0x043768
    "Bogus message code %d", // [001] 0x038661
    "ALIGN_TYPE is wrong, please fix", // [002] 0x038677
    "MAX_ALLOC_CHUNK is wrong, please fix", // [003] 0x038697
    "Bogus buffer control mode", // [004] 0x0386bc
    "Invalid component ID %d in SOS", // [005] 0x0386d6
    "Invalid crop request", // [006] 0x0386f5
    "DCT coefficient out of range", // [007] 0x03870a
    "IDCT output block size %d not supported", // [008] 0x038727
    "Component index %d: mismatching sampling ratio %d:%d, %d:%d, %c", // [009] 0x03874f
    "Bogus Huffman table definition", // [010] 0x03878f
    "Bogus input colorspace", // [011] 0x0387ae
    "Bogus JPEG colorspace", // [012] 0x0387c5
    "Bogus marker length", // [013] 0x0387db
    "Wrong JPEG library version: library is %d, caller expects %d", // [014] 0x0387ef
    "Sampling factors too large for interleaved scan", // [015] 0x03882c
    "Invalid memory pool code %d", // [016] 0x03885c
    "Unsupported JPEG data precision %d", // [017] 0x038878
    "Invalid progressive parameters Ss=%d Se=%d Ah=%d Al=%d", // [018] 0x03889b
    "Invalid progressive parameters at scan script entry %d", // [019] 0x0388d2
    "Bogus sampling factors", // [020] 0x038909
    "Invalid scan script at entry %d", // [021] 0x038920
    "Improper call to JPEG library in state %d", // [022] 0x038940
    "JPEG parameter struct mismatch: library thinks size is %u, caller expects %u", // [023] 0x03896a
    "Bogus virtual array access", // [024] 0x0389b7
    "Buffer passed to JPEG library is too small", // [025] 0x0389d2
    "Suspension not allowed here", // [026] 0x0389fd
    "CCIR601 sampling not implemented yet", // [027] 0x038a19
    "Too many color components: %d, max %d", // [028] 0x038a3e
    "Unsupported color conversion request", // [029] 0x038a64
    "Bogus DAC index %d", // [030] 0x038a89
    "Bogus DAC value 0x%x", // [031] 0x038a9c
    "Bogus DHT index %d", // [032] 0x038ab1
    "Bogus DQT index %d", // [033] 0x038ac4
    "Empty JPEG image (DNL not supported)", // [034] 0x038ad7
    "Read from EMS failed", // [035] 0x038afc
    "Write to EMS failed", // [036] 0x038b11
    "Didn't expect more than one scan", // [037] 0x038b25
    "Input file read error", // [038] 0x038b46
    "Output file write error --- out of disk space?", // [039] 0x038b5c
    "Fractional sampling not implemented yet", // [040] 0x038b8b
    "Huffman code size table overflow", // [041] 0x038bb3
    "Missing Huffman code table entry", // [042] 0x038bd4
    "Maximum supported image dimension is %u pixels", // [043] 0x038bf5
    "Empty input file", // [044] 0x038c24
    "Premature end of input file", // [045] 0x038c35
    "Cannot transcode due to multiple use of quantization table %d", // [046] 0x038c51
    "Scan script does not transmit all data", // [047] 0x038c8f
    "Invalid color quantization mode change", // [048] 0x038cb6
    "Not implemented yet", // [049] 0x038cdd
    "Requested feature was omitted at compile time", // [050] 0x038cf1
    "Arithmetic table 0x%02x was not defined", // [051] 0x038d1f
    "Backing store not supported", // [052] 0x038d47
    "Huffman table 0x%02x was not defined", // [053] 0x038d63
    "JPEG datastream contains no image", // [054] 0x038d88
    "Quantization table 0x%02x was not defined", // [055] 0x038daa
    "Not a JPEG file: starts with 0x%02x 0x%02x", // [056] 0x038dd4
    "Insufficient memory (case %d)", // [057] 0x038dff
    "Cannot quantize more than %d color components", // [058] 0x038e1d
    "Cannot quantize to fewer than %d colors", // [059] 0x038e4b
    "Cannot quantize to more than %d colors", // [060] 0x038e73
    "Invalid JPEG file structure: two SOF markers", // [061] 0x038e9a
    "Invalid JPEG file structure: missing SOS marker", // [062] 0x038ec7
    "Unsupported JPEG process: SOF type 0x%02x", // [063] 0x038ef7
    "Invalid JPEG file structure: two SOI markers", // [064] 0x038f21
    "Invalid JPEG file structure: SOS before SOF", // [065] 0x038f4e
    "Failed to create temporary file %s", // [066] 0x038f7a
    "Read failed on temporary file", // [067] 0x038f9d
    "Seek failed on temporary file", // [068] 0x038fbb
    "Write failed on temporary file --- out of disk space?", // [069] 0x038fd9
    "Application transferred too few scanlines", // [070] 0x03900f
    "Unsupported marker type 0x%02x", // [071] 0x039039
    "Virtual array controller messed up", // [072] 0x039058
    "Image too wide for this implementation", // [073] 0x03907b
    "Read from XMS failed", // [074] 0x0390a2
    "Write to XMS failed", // [075] 0x0390b7
    "Copyright (C) 1991-2017 The libjpeg-turbo Project and many others", // [076] 0x0390cb
    "8d  15-Jan-2012", // [077] 0x03910d
    "Caution: quantization tables are too coarse for baseline JPEG", // [078] 0x03911d
    "Adobe APP14 marker: version %d, flags 0x%04x 0x%04x, transform %d", // [079] 0x03915b
    "Unknown APP0 marker (not JFIF), length %u", // [080] 0x03919d
    "Unknown APP14 marker (not Adobe), length %u", // [081] 0x0391c7
    "Define Arithmetic Table 0x%02x: 0x%02x", // [082] 0x0391f3
    "Define Huffman Table 0x%02x", // [083] 0x03921a
    "Define Quantization Table %d  precision %d", // [084] 0x039236
    "Define Restart Interval %u", // [085] 0x039261
    "Freed EMS handle %u", // [086] 0x03927c
    "Obtained EMS handle %u", // [087] 0x039290
    "End Of Image", // [088] 0x0392a7
    "        %3d %3d %3d %3d %3d %3d %3d %3d", // [089] 0x0392b4
    "JFIF APP0 marker: version %d.%02d, density %dx%d  %d", // [090] 0x0392dc
    "Warning: thumbnail image size does not match data length %u", // [091] 0x039311
    "JFIF extension marker: type 0x%02x, length %u", // [092] 0x03934d
    "    with %d x %d thumbnail image", // [093] 0x03937b
    "Miscellaneous marker 0x%02x, length %u", // [094] 0x03939c
    "Unexpected marker 0x%02x", // [095] 0x0393c3
    "        %4u %4u %4u %4u %4u %4u %4u %4u", // [096] 0x0393dc
    "Quantizing to %d = %d*%d*%d colors", // [097] 0x039404
    "Quantizing to %d colors", // [098] 0x039427
    "Selected %d colors for quantization", // [099] 0x03943f
    "At marker 0x%02x, recovery action %d", // [100] 0x039463
    "RST%d", // [101] 0x03985f
    "Smoothing not supported with nonstandard sampling ratios", // [102] 0x039488
    "Start Of Frame 0x%02x: width=%u, height=%u, components=%d", // [103] 0x0394c1
    "    Component %d: %dhx%dv q=%d", // [104] 0x0394fb
    "Start of Image", // [105] 0x03951a
    "Start Of Scan: %d components", // [106] 0x039529
    "    Component %d: dc=%d ac=%d", // [107] 0x039546
    "  Ss=%d, Se=%d, Ah=%d, Al=%d", // [108] 0x039564
    "Closed temporary file %s", // [109] 0x039581
    "Opened temporary file %s", // [110] 0x03959a
    "JFIF extension marker: JPEG-compressed thumbnail image, length %u", // [111] 0x0395b3
    "JFIF extension marker: palette thumbnail image, length %u", // [112] 0x0395f5
    "JFIF extension marker: RGB thumbnail image, length %u", // [113] 0x03962f
    "Unrecognized component IDs %d %d %d, assuming YCbCr", // [114] 0x039665
    "Freed XMS handle %u", // [115] 0x039699
    "Obtained XMS handle %u", // [116] 0x0396ad
    "Unknown Adobe color transform code %d", // [117] 0x0396c4
    "Corrupt JPEG data: bad arithmetic code", // [118] 0x0396ea
    "Inconsistent progression sequence for component %d coefficient %d", // [119] 0x039711
    "Corrupt JPEG data: %u extraneous bytes before marker 0x%02x", // [120] 0x039753
    "Corrupt JPEG data: premature end of data segment", // [121] 0x03978f
    "Corrupt JPEG data: bad Huffman code", // [122] 0x0397c0
    "Warning: unknown JFIF revision number %d.%02d", // [123] 0x0397e4
    "Premature end of JPEG file", // [124] 0x039812
    "Corrupt JPEG data: found marker 0x%02x instead of RST%d", // [125] 0x03982d
    "Invalid SOS parameters for sequential JPEG", // [126] 0x039865
    "Application transferred too many scanlines", // [127] 0x039890
    nullptr, // [128] 0x000000
};

// .data 0x044000..0x0440f0: 10 JNINativeMethod registration records
const ImagePipelineJniRegRecord kImagePipelineJniMethodTable[10] = {
    {  0U, 0x044000ULL, 0x037cafULL, "nativeTranscodeJpeg", 0x037cc3ULL, "(Ljava/io/InputStream;Ljava/io/OutputStream;III)V", 0x0035b8ULL, "com/facebook/imagepipeline/nativecode/NativeJpegTranscoder" },
    {  1U, 0x044018ULL, 0x037cf5ULL, "nativeTranscodeJpegWithExifOrientation", 0x037cc3ULL, "(Ljava/io/InputStream;Ljava/io/OutputStream;III)V", 0x003664ULL, "com/facebook/imagepipeline/nativecode/NativeJpegTranscoder" },
    {  2U, 0x044030ULL, 0x03a72bULL, "nativeCopyBitmap", 0x03a73cULL, "(Landroid/graphics/Bitmap;ILandroid/graphics/Bitmap;II)V", 0x0373b4ULL, "com/facebook/imagepipeline/nativecode/Bitmaps" },
    {  3U, 0x044048ULL, 0x03a7b7ULL, "nativePinBitmap", 0x03a7c7ULL, "(Landroid/graphics/Bitmap;)V", 0x037654ULL, "com/facebook/imagepipeline/nativecode/DalvikPurgeableDecoder" },
    {  4U, 0x044060ULL, 0x03a82dULL, "nativeAllocate", 0x03a83cULL, "(I)J", 0x037764ULL, "com/facebook/imagepipeline/memory/NativeMemoryChunk" },
    {  5U, 0x044078ULL, 0x03a841ULL, "nativeFree", 0x03a84cULL, "(J)V", 0x0377b0ULL, "com/facebook/imagepipeline/memory/NativeMemoryChunk" },
    {  6U, 0x044090ULL, 0x03a851ULL, "nativeCopyToByteArray", 0x03a867ULL, "(J[BII)V", 0x0377b8ULL, "com/facebook/imagepipeline/memory/NativeMemoryChunk" },
    {  7U, 0x0440a8ULL, 0x03a870ULL, "nativeCopyFromByteArray", 0x03a867ULL, "(J[BII)V", 0x0377d8ULL, "com/facebook/imagepipeline/memory/NativeMemoryChunk" },
    {  8U, 0x0440c0ULL, 0x03a888ULL, "nativeMemcpy", 0x03a895ULL, "(JJI)V", 0x0377f8ULL, "com/facebook/imagepipeline/memory/NativeMemoryChunk" },
    {  9U, 0x0440d8ULL, 0x03a89cULL, "nativeReadByte", 0x03a8abULL, "(J)B", 0x03780cULL, "com/facebook/imagepipeline/memory/NativeMemoryChunk" },
};

// .eh_frame_hdr 0x03a8cc: 393 function descriptors in .text (0x001ffc..0x037814)
const ImagePipelineFdeEntry kImagePipelineFdeTable[kImagePipelineFdeFunctionCount] = {
    {   0U, 0x001ffcU,   100U, 0xf81d0ff5U, 0xa9014ff4U },
    {   1U, 0x002060U,   716U, 0xd10143ffU, 0xf9000bf7U },
    {   2U, 0x00232cU,   436U, 0xd106c3ffU, 0xf900abfcU },
    {   3U, 0x0024e0U,   668U, 0xf81b0ffcU, 0xa9015ff8U },
    {   4U, 0x00277cU,   464U, 0xa9bc5ffcU, 0xa90157f6U },
    {   5U, 0x00294cU,    52U, 0xf81e0ff3U, 0xa9017bfdU },
    {   6U, 0x002980U,    48U, 0xd103c3ffU, 0xf9006bf3U },
    {   7U, 0x0029b0U,    12U, 0xf9000020U, 0xf900d801U },
    {   8U, 0x0029bcU,    12U, 0xf9000020U, 0xf900dc01U },
    {   9U, 0x0029c8U,    84U, 0xa9be4ff4U, 0xa9017bfdU },
    {  10U, 0x002a1cU,    60U, 0xf81e0ff3U, 0xa9017bfdU },
    {  11U, 0x002a58U,    60U, 0xf81e0ff3U, 0xa9017bfdU },
    {  12U, 0x002a94U,    64U, 0xa9047c1fU, 0xb000020bU },
    {  13U, 0x002ad4U,    20U, 0xf9401408U, 0xa943a909U },
    {  14U, 0x002ae8U,    28U, 0xf9401408U, 0xb00001a9U },
    {  15U, 0x002b04U,    32U, 0xf9401408U, 0xa940250aU },
    {  16U, 0x002b24U,     4U, 0xd65f03c0U, 0x00000000U },
    {  17U, 0x002b28U,    40U, 0x90000008U, 0x90000009U },
    {  18U, 0x002b50U,    88U, 0xa9be4ff4U, 0xa9017bfdU },
    {  19U, 0x002ba8U,    64U, 0xf81e0ff3U, 0xa9017bfdU },
    {  20U, 0x002be8U,    32U, 0xf9401408U, 0xf9400509U },
    {  21U, 0x002c08U,   720U, 0xd101c3ffU, 0xa9016ffcU },
    {  22U, 0x002ed8U,    64U, 0x90000008U, 0x90000009U },
    {  23U, 0x002f18U,   128U, 0xa9be4ff4U, 0xa9017bfdU },
    {  24U, 0x002f98U,   208U, 0xa9bd57f6U, 0xa9014ff4U },
    {  25U, 0x003068U,   112U, 0xa9be4ff4U, 0xa9017bfdU },
    {  26U, 0x0030d8U,     4U, 0xd65f03c0U, 0x00000000U },
    {  27U, 0x0030dcU,    40U, 0x90000008U, 0x90000009U },
    {  28U, 0x003104U,   124U, 0xa9be4ff4U, 0xa9017bfdU },
    {  29U, 0x003180U,   128U, 0xa9bd57f6U, 0xa9014ff4U },
    {  30U, 0x003200U,   148U, 0xa9bd57f6U, 0xa9014ff4U },
    {  31U, 0x003294U,   156U, 0xd10483ffU, 0xa9104ffcU },
    {  32U, 0x003330U,   156U, 0xd10483ffU, 0xa9104ffcU },
    {  33U, 0x0033ccU,   156U, 0xd10483ffU, 0xa9104ffcU },
    {  34U, 0x003468U,   116U, 0x12003c28U, 0x7102cd1fU },
    {  35U, 0x0034dcU,    84U, 0xa9bf7bfdU, 0x910003fdU },
    {  36U, 0x003530U,   136U, 0xf81e0ff3U, 0xa9017bfdU },
    {  37U, 0x0035b8U,   172U, 0xd10143ffU, 0xa9015ff8U },
    {  38U, 0x003664U,   172U, 0xd10143ffU, 0xa9015ff8U },
    {  39U, 0x003710U,   272U, 0xf81d0ff5U, 0xa9014ff4U },
    {  40U, 0x003820U,     4U, 0x1400102dU, 0x00000000U },
    {  41U, 0x003824U,   148U, 0xf9403808U, 0xb4000048U },
    {  42U, 0x0038b8U,   352U, 0xf81d0ff5U, 0xa9014ff4U },
    {  43U, 0x003a18U,   156U, 0xa9bd57f6U, 0xa9014ff4U },
    {  44U, 0x003ab4U,   168U, 0xa9be4ff4U, 0xa9017bfdU },
    {  45U, 0x003b5cU,   292U, 0xd10103ffU, 0xa90157f6U },
    {  46U, 0x003c80U,   216U, 0xf81e0ff3U, 0xa9017bfdU },
    {  47U, 0x003d58U,   216U, 0xa9bd57f6U, 0xa9014ff4U },
    {  48U, 0x003e30U,    80U, 0xa9be4ff4U, 0xa9017bfdU },
    {  49U, 0x003e80U,   272U, 0xf81b0ff9U, 0xa9015ff8U },
    {  50U, 0x003f90U,   140U, 0xf81e0ff3U, 0xa9017bfdU },
    {  51U, 0x00401cU,  2980U, 0xf81d0ff5U, 0xa9014ff4U },
    {  52U, 0x004bc0U,   308U, 0xa9bd57f6U, 0xa9014ff4U },
    {  53U, 0x004cf4U,  3200U, 0xd102c3ffU, 0xa9056ffcU },
    {  54U, 0x005974U,   196U, 0xf81e0ff3U, 0xa9017bfdU },
    {  55U, 0x005a38U,   636U, 0xf81e0ff3U, 0xa9017bfdU },
    {  56U, 0x005cb4U,   408U, 0xf81d0ff5U, 0xa9014ff4U },
    {  57U, 0x005e4cU,   108U, 0xf81e0ff3U, 0xa9017bfdU },
    {  58U, 0x005eb8U,   756U, 0xf81b0ff9U, 0xa9015ff8U },
    {  59U, 0x0061acU,  1192U, 0xa9bd57f6U, 0xa9014ff4U },
    {  60U, 0x006654U,   872U, 0xa9bc5ff8U, 0xa90157f6U },
    {  61U, 0x0069bcU,  2112U, 0xfc190fe8U, 0xa9016ffcU },
    {  62U, 0x0071fcU,   508U, 0xa9be4ff4U, 0xa9017bfdU },
    {  63U, 0x0073f8U,    60U, 0xf81e0ff3U, 0xa9017bfdU },
    {  64U, 0x007434U,   140U, 0xa9be4ff4U, 0xa9017bfdU },
    {  65U, 0x0074c0U,   520U, 0xf81e0ff3U, 0xa9017bfdU },
    {  66U, 0x0076c8U,   444U, 0xa9bd57f6U, 0xa9014ff4U },
    {  67U, 0x007884U,    80U, 0xf81e0ff3U, 0xa9017bfdU },
    {  68U, 0x0078d4U,    56U, 0xf81e0ff3U, 0xa9017bfdU },
    {  69U, 0x00790cU,    40U, 0xa9bf7bfdU, 0x910003fdU },
    {  70U, 0x007934U,    40U, 0xa9bf7bfdU, 0x910003fdU },
    {  71U, 0x00795cU,   392U, 0xf81d0ff5U, 0xa9014ff4U },
    {  72U, 0x007ae4U,    52U, 0x7100043fU, 0x1a9fc428U },
    {  73U, 0x007b18U,   400U, 0xf81d0ff5U, 0xa9014ff4U },
    {  74U, 0x007ca8U,   892U, 0xf81e0ff3U, 0xa9017bfdU },
    {  75U, 0x008024U,   796U, 0xa9be4ff4U, 0xa9017bfdU },
    {  76U, 0x008340U,   212U, 0xa9bd57f6U, 0xa9014ff4U },
    {  77U, 0x008414U,    88U, 0xf81e0ff3U, 0xa9017bfdU },
    {  78U, 0x00846cU,   444U, 0xf81a0ffbU, 0xa90167faU },
    {  79U, 0x008628U,   404U, 0xa9ba6ffcU, 0xa90167faU },
    {  80U, 0x0087bcU,   576U, 0xd101c3ffU, 0xa9016ffcU },
    {  81U, 0x0089fcU,   212U, 0xf81c0ff7U, 0xa90157f6U },
    {  82U, 0x008ad0U,   804U, 0xd10643ffU, 0xa9136ffcU },
    {  83U, 0x008df4U,   284U, 0xd10203ffU, 0xf90013fbU },
    {  84U, 0x008f10U,    88U, 0xa9be4ff4U, 0xa9017bfdU },
    {  85U, 0x008f68U,   320U, 0xf81d0ff5U, 0xa9014ff4U },
    {  86U, 0x0090a8U,   376U, 0xa9bc5ff8U, 0xa90157f6U },
    {  87U, 0x009220U,   240U, 0xf81d0ff5U, 0xa9014ff4U },
    {  88U, 0x009310U,   880U, 0xd10303ffU, 0xa9066ffcU },
    {  89U, 0x009680U,    84U, 0xa9be4ff4U, 0xa9017bfdU },
    {  90U, 0x0096d4U,   656U, 0xd10243ffU, 0xa9036ffcU },
    {  91U, 0x009964U,   620U, 0xd10243ffU, 0xa9036ffcU },
    {  92U, 0x009bd0U,   564U, 0xa9ba6ffcU, 0xa90167faU },
    {  93U, 0x009e04U,     4U, 0xd65f03c0U, 0x00000000U },
    {  94U, 0x009e08U,   160U, 0xa9bb67faU, 0xa9015ff8U },
    {  95U, 0x009ea8U,   428U, 0xf81a0ffbU, 0xa90167faU },
    {  96U, 0x00a054U,   148U, 0xa9bd57f6U, 0xa9014ff4U },
    {  97U, 0x00a0e8U,   248U, 0xa9bb67faU, 0xa9015ff8U },
    {  98U, 0x00a1e0U,   604U, 0xf81a0ffbU, 0xa90167faU },
    {  99U, 0x00a43cU,   284U, 0xa9bb67faU, 0xa9015ff8U },
    { 100U, 0x00a558U,   496U, 0xd101c3ffU, 0xa9016ffcU },
    { 101U, 0x00a748U,   408U, 0xf81d0ff5U, 0xa9014ff4U },
    { 102U, 0x00a8e0U,   784U, 0xa9ba6ffcU, 0xa90167faU },
    { 103U, 0x00abf0U,   140U, 0xa9be4ff4U, 0xa9017bfdU },
    { 104U, 0x00ac7cU,   864U, 0xd103c3ffU, 0xa9096ffcU },
    { 105U, 0x00afdcU,   304U, 0xf81d0ff5U, 0xa9014ff4U },
    { 106U, 0x00b10cU,     4U, 0x17fff1f2U, 0x00000000U },
    { 107U, 0x00b110U,   144U, 0xf81d0ff5U, 0xa9014ff4U },
    { 108U, 0x00b1a0U,   580U, 0xf81e0ff3U, 0xa9017bfdU },
    { 109U, 0x00b3e4U,   272U, 0xf81e0ff3U, 0xa9017bfdU },
    { 110U, 0x00b4f4U,   272U, 0xf81d0ff5U, 0xa9014ff4U },
    { 111U, 0x00b604U,   248U, 0xd10103ffU, 0xa90157f6U },
    { 112U, 0x00b6fcU,   112U, 0xf81e0ff3U, 0xa9017bfdU },
    { 113U, 0x00b76cU,   860U, 0xfc1c0fe8U, 0xf90007f7U },
    { 114U, 0x00bac8U,    88U, 0xf81e0ff3U, 0xa9017bfdU },
    { 115U, 0x00bb20U,   664U, 0xa9bc5ff8U, 0xa90157f6U },
    { 116U, 0x00bdb8U,    20U, 0xf9412c08U, 0x90000009U },
    { 117U, 0x00bdccU,   352U, 0xd101c3ffU, 0xa9016ffcU },
    { 118U, 0x00bf2cU,   260U, 0xf81c0ff7U, 0xa90157f6U },
    { 119U, 0x00c030U,   204U, 0xf81e0ff3U, 0xa9017bfdU },
    { 120U, 0x00c0fcU,    32U, 0xf9413008U, 0xf900981fU },
    { 121U, 0x00c11cU,  4140U, 0xd106c3ffU, 0xa9156ffcU },
    { 122U, 0x00d148U,   156U, 0xf81e0ff3U, 0xa9017bfdU },
    { 123U, 0x00d1e4U,   232U, 0xa9bc5ff8U, 0xa90157f6U },
    { 124U, 0x00d2ccU,   596U, 0xd10203ffU, 0xa9026ffcU },
    { 125U, 0x00d520U,   868U, 0xf81b0ff9U, 0xa9015ff8U },
    { 126U, 0x00d884U,   600U, 0xf81d0ff5U, 0xa9014ff4U },
    { 127U, 0x00dadcU,   904U, 0xa9be4ff4U, 0xa9017bfdU },
    { 128U, 0x00de64U,   456U, 0xf81d0ff5U, 0xa9014ff4U },
    { 129U, 0x00e02cU,   340U, 0xd10083ffU, 0xa9017bfdU },
    { 130U, 0x00e180U,  1136U, 0xf81d0ff5U, 0xa9014ff4U },
    { 131U, 0x00e5f0U,   456U, 0xa9be4ff4U, 0xa9017bfdU },
    { 132U, 0x00e7b8U,    60U, 0xf81e0ff3U, 0xa9017bfdU },
    { 133U, 0x00e7f4U,   808U, 0xa9be4ff4U, 0xa9017bfdU },
    { 134U, 0x00eb1cU,    20U, 0xf9413c08U, 0xb900491fU },
    { 135U, 0x00eb30U,   308U, 0xd10183ffU, 0xf90013f7U },
    { 136U, 0x00ec64U,  3208U, 0xf81e0ff5U, 0xa9014ff4U },
    { 137U, 0x00f8ecU,   736U, 0xa9ba6ffcU, 0xa90167faU },
    { 138U, 0x00fbccU,   544U, 0xf81d0ff7U, 0xa90157f6U },
    { 139U, 0x00fdecU,    80U, 0xa9be4ff4U, 0xa9017bfdU },
    { 140U, 0x00fe3cU,  1996U, 0xb9404008U, 0x51001908U },
    { 141U, 0x010608U,   416U, 0xf81e0ff5U, 0xa9014ff4U },
    { 142U, 0x0107a8U,   320U, 0xf81f0ff3U, 0xf9413c09U },
    { 143U, 0x0108e8U,   172U, 0xf81e0ff3U, 0xa9017bfdU },
    { 144U, 0x010994U,   652U, 0xf81a0ffbU, 0xa90167faU },
    { 145U, 0x010c20U,   676U, 0xd102c3ffU, 0xa9056ffcU },
    { 146U, 0x010ec4U,   720U, 0xd10243ffU, 0xa9036ffcU },
    { 147U, 0x011194U,   416U, 0xd10203ffU, 0xa90367faU },
    { 148U, 0x011334U,  1260U, 0xd10743ffU, 0xa9176ffcU },
    { 149U, 0x011820U,   200U, 0xa9bd57f6U, 0xa9014ff4U },
    { 150U, 0x0118e8U,   232U, 0xf81e0ff3U, 0xa9017bfdU },
    { 151U, 0x0119d0U,   188U, 0xd10143ffU, 0xf9000bf7U },
    { 152U, 0x011a8cU,   252U, 0xa9bb67faU, 0xa9015ff8U },
    { 153U, 0x011b88U,   228U, 0xf81c0ff7U, 0xa90157f6U },
    { 154U, 0x011c6cU,   796U, 0xa9ba6ffcU, 0xa90167faU },
    { 155U, 0x011f88U,    24U, 0xf9413c08U, 0xb9419c09U },
    { 156U, 0x011fa0U,   336U, 0xd101c3ffU, 0xa9016ffcU },
    { 157U, 0x0120f0U,     8U, 0xf900007fU, 0xd65f03c0U },
    { 158U, 0x0120f8U,     8U, 0xf9000062U, 0xd65f03c0U },
    { 159U, 0x012100U,   416U, 0xb9419c08U, 0x7100051fU },
    { 160U, 0x0122a0U,   260U, 0xb9419c0aU, 0x7100055fU },
    { 161U, 0x0123a4U,   204U, 0xb9419c08U, 0x7100051fU },
    { 162U, 0x012470U,   516U, 0xb9419c08U, 0x7100051fU },
    { 163U, 0x012674U,   336U, 0xf81c0ff7U, 0xa90157f6U },
    { 164U, 0x0127c4U,   356U, 0xd10203ffU, 0xa9026ffcU },
    { 165U, 0x012928U,   448U, 0xf81e0ff3U, 0xa9017bfdU },
    { 166U, 0x012ae8U,    88U, 0x90000008U, 0x90000009U },
    { 167U, 0x012b40U,    44U, 0xf81e0ff3U, 0xa9017bfdU },
    { 168U, 0x012b6cU,   100U, 0xf81e0ff3U, 0xa9017bfdU },
    { 169U, 0x012bd0U,   108U, 0xd103c3ffU, 0xf9006bf3U },
    { 170U, 0x012c3cU,   220U, 0xd100c3ffU, 0xa9027bfdU },
    { 171U, 0x012d18U,    16U, 0xf9400008U, 0xf900411fU },
    { 172U, 0x012d28U,   164U, 0xd10483ffU, 0xa9104ffcU },
    { 173U, 0x012dccU,  1296U, 0xd10183ffU, 0xa9025ff8U },
    { 174U, 0x0132dcU,   652U, 0xf81b0ff9U, 0xa9015ff8U },
    { 175U, 0x013568U,     4U, 0xd65f03c0U, 0x00000000U },
    { 176U, 0x01356cU,    20U, 0xf9400008U, 0x528005e9U },
    { 177U, 0x013580U,   344U, 0xf81d0ff5U, 0xa9014ff4U },
    { 178U, 0x0136d8U,   128U, 0x7100047fU, 0x540003cbU },
    { 179U, 0x013758U,   288U, 0xf81d0ff7U, 0xa90157f6U },
    { 180U, 0x013878U,   244U, 0xf81d0ff7U, 0xa90157f6U },
    { 181U, 0x01396cU,   260U, 0xa9bb67faU, 0xa9015ff8U },
    { 182U, 0x013a70U,   460U, 0xd101c3ffU, 0xa9016ffcU },
    { 183U, 0x013c3cU,   416U, 0xf81d0ff5U, 0xa9014ff4U },
    { 184U, 0x013ddcU,   340U, 0xa9bd57f6U, 0xa9014ff4U },
    { 185U, 0x013f30U,    16U, 0xf9414408U, 0x52800029U },
    { 186U, 0x013f40U,   240U, 0xf81e0ff3U, 0xa9017bfdU },
    { 187U, 0x014030U,   136U, 0x7100047fU, 0x5400040bU },
    { 188U, 0x0140b8U,  1400U, 0xd10343ffU, 0xa9076ffcU },
    { 189U, 0x014630U,   772U, 0xd10483ffU, 0xa90c6ffcU },
    { 190U, 0x014934U,   228U, 0xd101c3ffU, 0xa9016ffcU },
    { 191U, 0x014a18U,     4U, 0xd65f03c0U, 0x00000000U },
    { 192U, 0x014a1cU,  1312U, 0xf81c0ff9U, 0xa9015ff8U },
    { 193U, 0x014f3cU,  1944U, 0xa9ba6ffcU, 0xa90167faU },
    { 194U, 0x0156d4U,    16U, 0x8b010008U, 0xd1000508U },
    { 195U, 0x0156e4U,    20U, 0x8b010008U, 0xd1000508U },
    { 196U, 0x0156f8U,    84U, 0xa9bd57f6U, 0xa9014ff4U },
    { 197U, 0x01574cU,    24U, 0x2a0203e8U, 0xd379e102U },
    { 198U, 0x015764U,    12U, 0xaa0103e2U, 0x2a1f03e1U },
    { 199U, 0x015770U,   416U, 0xd10143ffU, 0xa90257f6U },
    { 200U, 0x015910U,   476U, 0xfc1a0fe8U, 0xa90167faU },
    { 201U, 0x015aecU,   300U, 0xa9bc5ff8U, 0xa90157f6U },
    { 202U, 0x015c18U,   296U, 0xf81b0ff9U, 0xa9015ff8U },
    { 203U, 0x015d40U,   248U, 0xf81b0ff9U, 0xa9015ff8U },
    { 204U, 0x015e38U,   160U, 0xf81b0ff9U, 0xa9015ff8U },
    { 205U, 0x015ed8U,   160U, 0xf81b0ff9U, 0xa9015ff8U },
    { 206U, 0x015f78U,  1068U, 0xd10283ffU, 0xfd0013eaU },
    { 207U, 0x0163a4U,   892U, 0xd101c3ffU, 0xa9016ffcU },
    { 208U, 0x016720U,   904U, 0xd101c3ffU, 0xa9016ffcU },
    { 209U, 0x016aa8U,   344U, 0xf81c0ff7U, 0xa90157f6U },
    { 210U, 0x016c00U,    72U, 0xf81e0ff3U, 0xa9017bfdU },
    { 211U, 0x016c48U,   144U, 0xf81e0ff3U, 0xa9017bfdU },
    { 212U, 0x016cd8U,   524U, 0xf81b0ff9U, 0xa9015ff8U },
    { 213U, 0x016ee4U,  1396U, 0xa9bd57f6U, 0xa9014ff4U },
    { 214U, 0x017458U,   560U, 0xd101c3ffU, 0xa9016ffcU },
    { 215U, 0x017688U,   700U, 0xd10203ffU, 0xa9026ffcU },
    { 216U, 0x017944U,   180U, 0xf81c0ff7U, 0xa90157f6U },
    { 217U, 0x0179f8U,   632U, 0xd101c3ffU, 0xa9016ffcU },
    { 218U, 0x017c70U,  1088U, 0xd10243ffU, 0xa9036ffcU },
    { 219U, 0x0180b0U,   404U, 0xf81d0ff5U, 0xa9014ff4U },
    { 220U, 0x018244U,  1068U, 0xa9bc5ff8U, 0xa90157f6U },
    { 221U, 0x018670U,   216U, 0xf81e0ff3U, 0xa9017bfdU },
    { 222U, 0x018748U,   940U, 0xa9bb67faU, 0xa9015ff8U },
    { 223U, 0x018af4U,   556U, 0xd101c3ffU, 0xa9016ffcU },
    { 224U, 0x018d20U,   552U, 0xd10203ffU, 0xa9026ffcU },
    { 225U, 0x018f48U,   180U, 0xf81c0ff7U, 0xa90157f6U },
    { 226U, 0x018ffcU,   480U, 0xd101c3ffU, 0xa9016ffcU },
    { 227U, 0x0191dcU,   908U, 0xd10203ffU, 0xa9026ffcU },
    { 228U, 0x019568U,   260U, 0xa9be4ff4U, 0xa9017bfdU },
    { 229U, 0x01966cU,   480U, 0xa9bc5ff8U, 0xa90157f6U },
    { 230U, 0x01984cU,  1636U, 0xa9bb67faU, 0xa9015ff8U },
    { 231U, 0x019eb0U,  1768U, 0xf81c0ff7U, 0xa90157f6U },
    { 232U, 0x01a598U,  7320U, 0xd10403ffU, 0xa90a6ffcU },
    { 233U, 0x01c230U,   252U, 0xa9be4ff4U, 0xa9017bfdU },
    { 234U, 0x01c32cU,     8U, 0xaa0103e0U, 0x17ff96f0U },
    { 235U, 0x01c334U,     8U, 0xaa0103e0U, 0x17ff96e6U },
    { 236U, 0x01c33cU,     8U, 0xaa0103e0U, 0x17ff96ecU },
    { 237U, 0x01c344U,     8U, 0xaa0103e0U, 0x17ff96e2U },
    { 238U, 0x01c34cU,    32U, 0xf9400408U, 0xf9402d08U },
    { 239U, 0x01c36cU,    20U, 0xf9400008U, 0x52800669U },
    { 240U, 0x01c380U,     8U, 0xaa1f03e0U, 0xd65f03c0U },
    { 241U, 0x01c388U,     4U, 0xd65f03c0U, 0x00000000U },
    { 242U, 0x01c38cU,     8U, 0x2a1f03e0U, 0xd65f03c0U },
    { 243U, 0x01c394U,     8U, 0x2a1f03e0U, 0xd65f03c0U },
    { 244U, 0x01c39cU,     8U, 0x2a1f03e0U, 0xd65f03c0U },
    { 245U, 0x01c3a4U,     8U, 0x2a1f03e0U, 0xd65f03c0U },
    { 246U, 0x01c3acU,     4U, 0xd65f03c0U, 0x00000000U },
    { 247U, 0x01c3b0U,     4U, 0xd65f03c0U, 0x00000000U },
    { 248U, 0x01c3b4U,     4U, 0xd65f03c0U, 0x00000000U },
    { 249U, 0x01c3b8U,     4U, 0xd65f03c0U, 0x00000000U },
    { 250U, 0x01c3bcU,     8U, 0x2a1f03e0U, 0xd65f03c0U },
    { 251U, 0x01c3c4U,     8U, 0x2a1f03e0U, 0xd65f03c0U },
    { 252U, 0x01c3ccU,     4U, 0xd65f03c0U, 0x00000000U },
    { 253U, 0x01c3d0U,     4U, 0xd65f03c0U, 0x00000000U },
    { 254U, 0x01c3d4U,     8U, 0x2a1f03e0U, 0xd65f03c0U },
    { 255U, 0x01c3dcU,     8U, 0x2a1f03e0U, 0xd65f03c0U },
    { 256U, 0x01c3e4U,     4U, 0xd65f03c0U, 0x00000000U },
    { 257U, 0x01c3e8U,     4U, 0xd65f03c0U, 0x00000000U },
    { 258U, 0x01c3ecU,     8U, 0x2a1f03e0U, 0xd65f03c0U },
    { 259U, 0x01c3f4U,     8U, 0x2a1f03e0U, 0xd65f03c0U },
    { 260U, 0x01c3fcU,     4U, 0xd65f03c0U, 0x00000000U },
    { 261U, 0x01c400U,     4U, 0xd65f03c0U, 0x00000000U },
    { 262U, 0x01c404U,     8U, 0x2a1f03e0U, 0xd65f03c0U },
    { 263U, 0x01c40cU,     8U, 0x2a1f03e0U, 0xd65f03c0U },
    { 264U, 0x01c414U,     4U, 0xd65f03c0U, 0x00000000U },
    { 265U, 0x01c418U,     4U, 0xd65f03c0U, 0x00000000U },
    { 266U, 0x01c41cU,     8U, 0x2a1f03e0U, 0xd65f03c0U },
    { 267U, 0x01c424U,     8U, 0x2a1f03e0U, 0xd65f03c0U },
    { 268U, 0x01c42cU,     4U, 0xd65f03c0U, 0x00000000U },
    { 269U, 0x01c430U,     4U, 0xd65f03c0U, 0x00000000U },
    { 270U, 0x01c434U,     8U, 0x2a1f03e0U, 0xd65f03c0U },
    { 271U, 0x01c43cU,     8U, 0x2a1f03e0U, 0xd65f03c0U },
    { 272U, 0x01c444U,     8U, 0x2a1f03e0U, 0xd65f03c0U },
    { 273U, 0x01c44cU,     4U, 0xd65f03c0U, 0x00000000U },
    { 274U, 0x01c450U,     4U, 0xd65f03c0U, 0x00000000U },
    { 275U, 0x01c454U,     4U, 0xd65f03c0U, 0x00000000U },
    { 276U, 0x01c458U,     8U, 0x2a1f03e0U, 0xd65f03c0U },
    { 277U, 0x01c460U,     8U, 0x2a1f03e0U, 0xd65f03c0U },
    { 278U, 0x01c468U,     4U, 0xd65f03c0U, 0x00000000U },
    { 279U, 0x01c46cU,     4U, 0xd65f03c0U, 0x00000000U },
    { 280U, 0x01c470U,     8U, 0x2a1f03e0U, 0xd65f03c0U },
    { 281U, 0x01c478U,     8U, 0x2a1f03e0U, 0xd65f03c0U },
    { 282U, 0x01c480U,     4U, 0xd65f03c0U, 0x00000000U },
    { 283U, 0x01c484U,     4U, 0xd65f03c0U, 0x00000000U },
    { 284U, 0x01c488U,     8U, 0x2a1f03e0U, 0xd65f03c0U },
    { 285U, 0x01c490U,     8U, 0x2a1f03e0U, 0xd65f03c0U },
    { 286U, 0x01c498U,     8U, 0x2a1f03e0U, 0xd65f03c0U },
    { 287U, 0x01c4a0U,     4U, 0xd65f03c0U, 0x00000000U },
    { 288U, 0x01c4a4U,     4U, 0xd65f03c0U, 0x00000000U },
    { 289U, 0x01c4a8U,     4U, 0xd65f03c0U, 0x00000000U },
    { 290U, 0x01c4acU,     8U, 0x2a1f03e0U, 0xd65f03c0U },
    { 291U, 0x01c4b4U,     8U, 0xaa1f03e0U, 0xd65f03c0U },
    { 292U, 0x01c4bcU,   320U, 0xa9bc5ff8U, 0xa90157f6U },
    { 293U, 0x01c5fcU,   256U, 0xf81e0ff3U, 0xa9017bfdU },
    { 294U, 0x01c6fcU,   736U, 0xd10243ffU, 0xa9036ffcU },
    { 295U, 0x01c9dcU,   784U, 0xd102c3ffU, 0xa9056ffcU },
    { 296U, 0x01ccecU,   676U, 0xd10203ffU, 0xa90367faU },
    { 297U, 0x01cf90U,   840U, 0xa9be4ff4U, 0xa9017bfdU },
    { 298U, 0x01d2d8U,     4U, 0xd65f03c0U, 0x00000000U },
    { 299U, 0x01d2dcU,    96U, 0x7100049fU, 0x540002cbU },
    { 300U, 0x01d33cU,   304U, 0xf81e0ff3U, 0xa9017bfdU },
    { 301U, 0x01d46cU,  1064U, 0xb9403c08U, 0x51001908U },
    { 302U, 0x01d894U,   716U, 0xf81c0ff9U, 0xa9015ff8U },
    { 303U, 0x01db60U,  3056U, 0xf81b0ffbU, 0xa90167faU },
    { 304U, 0x01e750U,  1968U, 0xa9bf4ff4U, 0xb9403c08U },
    { 305U, 0x01ef00U,   288U, 0xf81f0ff3U, 0x7100049fU },
    { 306U, 0x01f020U,   524U, 0xf81d0ff5U, 0xa9014ff4U },
    { 307U, 0x01f22cU,  1252U, 0xd10343ffU, 0xa9076ffcU },
    { 308U, 0x01f710U,   160U, 0xf81a0ffbU, 0xa90167faU },
    { 309U, 0x01f7b0U,   160U, 0xf81a0ffbU, 0xa90167faU },
    { 310U, 0x01f850U,   132U, 0xaa1f03e8U, 0x2a0103e9U },
    { 311U, 0x01f8d4U,   332U, 0x91020048U, 0x91020009U },
    { 312U, 0x01fa20U,   164U, 0xaa1f03e8U, 0x2a0103e9U },
    { 313U, 0x01fac4U,   532U, 0x3dc00042U, 0x3dc00023U },
    { 314U, 0x01fcd8U,   796U, 0xa9ba6ffcU, 0xa90167faU },
    { 315U, 0x01fff4U,   844U, 0xa9ba6ffcU, 0xa90167faU },
    { 316U, 0x020340U,   100U, 0xf81e0ff3U, 0xa9017bfdU },
    { 317U, 0x0203a4U,   432U, 0xf81a0ffbU, 0xa90167faU },
    { 318U, 0x020554U,   540U, 0xd10203ffU, 0xa9026ffcU },
    { 319U, 0x020770U,   300U, 0xd10243ffU, 0xa9036ffcU },
    { 320U, 0x02089cU,   836U, 0xd10703ffU, 0xa9166ffcU },
    { 321U, 0x020be0U,   176U, 0xd101c3ffU, 0xa90457f6U },
    { 322U, 0x020c90U, 30568U, 0xd10583ffU, 0xf9008bfcU },
    { 323U, 0x0283f8U,   364U, 0xd10583ffU, 0xf9008bfcU },
    { 324U, 0x028564U,   436U, 0xa9bb67faU, 0xa9015ff8U },
    { 325U, 0x028718U,    68U, 0xb941b809U, 0xf9412408U },
    { 326U, 0x02875cU,   344U, 0xa9be4ff4U, 0xa9017bfdU },
    { 327U, 0x0288b4U,   704U, 0xd10203ffU, 0xa90367faU },
    { 328U, 0x028b74U,   504U, 0xd10203ffU, 0xa9026ffcU },
    { 329U, 0x028d6cU,     8U, 0x2a1f03e0U, 0xd65f03c0U },
    { 330U, 0x028d74U,   760U, 0xd10283ffU, 0xa9046ffcU },
    { 331U, 0x02906cU,  1776U, 0xd10583ffU, 0xa9106ffcU },
    { 332U, 0x02975cU,  2992U, 0xa9be4ff4U, 0xa9017bfdU },
    { 333U, 0x02a30cU,     4U, 0xd65f03c0U, 0x00000000U },
    { 334U, 0x02a310U,    28U, 0xf9400028U, 0xb9408805U },
    { 335U, 0x02a32cU,   152U, 0x7100049fU, 0x5400048bU },
    { 336U, 0x02a3c4U,  1412U, 0xa9bf4ff4U, 0xb9404008U },
    { 337U, 0x02a948U,  1736U, 0xb9404008U, 0x51001908U },
    { 338U, 0x02b010U,   888U, 0xa9be57f6U, 0xa9014ff4U },
    { 339U, 0x02b388U,  2524U, 0xa9bf4ff4U, 0xb9404008U },
    { 340U, 0x02bd64U,   532U, 0xf81b0ffbU, 0xa90167faU },
    { 341U, 0x02bf78U,   428U, 0x7100049fU, 0x54000d2bU },
    { 342U, 0x02c124U,   284U, 0x7100049fU, 0x540008abU },
    { 343U, 0x02c240U,   636U, 0xf81b0ffbU, 0xa90167faU },
    { 344U, 0x02c4bcU,   292U, 0x7100049fU, 0x540008ebU },
    { 345U, 0x02c5e0U,   456U, 0xa9be57f6U, 0xa9014ff4U },
    { 346U, 0x02c7a8U,   216U, 0xa9bf4ff4U, 0x7100049fU },
    { 347U, 0x02c880U,   196U, 0xf81c0ff7U, 0xa90157f6U },
    { 348U, 0x02c944U,  1776U, 0xd10403ffU, 0x6d063befU },
    { 349U, 0x02d034U,  1268U, 0xa9ba6ffcU, 0xa90167faU },
    { 350U, 0x02d528U,   336U, 0xf81b0ff9U, 0xa9015ff8U },
    { 351U, 0x02d678U,   308U, 0xf81c0ff7U, 0xa90157f6U },
    { 352U, 0x02d7acU,   240U, 0xf81d0ff5U, 0xa9014ff4U },
    { 353U, 0x02d89cU,   372U, 0xf81c0ff7U, 0xa90157f6U },
    { 354U, 0x02da10U,  4032U, 0xd102c3ffU, 0xa9056ffcU },
    { 355U, 0x02e9d0U,   212U, 0xa9bd57f6U, 0xa9014ff4U },
    { 356U, 0x02eaa4U,   476U, 0xa9bb67faU, 0xa9015ff8U },
    { 357U, 0x02ec80U,   876U, 0xf81a0ffcU, 0xa9016bfbU },
    { 358U, 0x02efecU,   776U, 0xf81c0ff7U, 0xa90157f6U },
    { 359U, 0x02f2f4U,   160U, 0xa9bc5ff8U, 0xa90157f6U },
    { 360U, 0x02f394U,    36U, 0xf9412808U, 0x2a0303e6U },
    { 361U, 0x02f3b8U,  1284U, 0x6dbe2bebU, 0x6d0123e9U },
    { 362U, 0x02f8bcU,   764U, 0xaa1f03e8U, 0x5296a009U },
    { 363U, 0x02fbb8U,   980U, 0xd102c3ffU, 0x6d023befU },
    { 364U, 0x02ff8cU,  1036U, 0xd104c3ffU, 0xf9008bfcU },
    { 365U, 0x030398U,  1112U, 0xd10583ffU, 0xf9008bfcU },
    { 366U, 0x0307f0U,  1156U, 0xd10643ffU, 0xa9136ffcU },
    { 367U, 0x030c74U,   852U, 0xd10543ffU, 0xa90f6ffcU },
    { 368U, 0x030fc8U,   572U, 0xd10343ffU, 0xf90053f5U },
    { 369U, 0x031204U,   520U, 0xd10283ffU, 0xa90757f6U },
    { 370U, 0x03140cU,   584U, 0xd10103ffU, 0xa9037bfdU },
    { 371U, 0x031654U,  1780U, 0xd10703ffU, 0xa9166ffcU },
    { 372U, 0x031d48U,  1920U, 0x6db733edU, 0x6d012bebU },
    { 373U, 0x0324c8U,  2960U, 0x6db63befU, 0x6d0133edU },
    { 374U, 0x033058U,  2404U, 0x6db63befU, 0x6d0133edU },
    { 375U, 0x0339bcU,  3372U, 0x6db63befU, 0x6d0133edU },
    { 376U, 0x0346e8U,  2904U, 0x6db63befU, 0x6d0133edU },
    { 377U, 0x035240U,  3088U, 0x6db63befU, 0x6d0133edU },
    { 378U, 0x035e50U,  3628U, 0x6db63befU, 0x6d0133edU },
    { 379U, 0x036c7cU,   812U, 0xd103c3ffU, 0xa9096ffcU },
    { 380U, 0x036fa8U,   660U, 0xd10203ffU, 0xa90557f6U },
    { 381U, 0x03723cU,    48U, 0xf9402c28U, 0x79c00049U },
    { 382U, 0x03726cU,   164U, 0xf81e0ff3U, 0xa9017bfdU },
    { 383U, 0x037310U,   164U, 0xf81e0ff3U, 0xa9017bfdU },
    { 384U, 0x0373b4U,   672U, 0xd101c3ffU, 0xa90267faU },
    { 385U, 0x037654U,   108U, 0xf81e0ff3U, 0xa9017bfdU },
    { 386U, 0x0376c0U,   164U, 0xf81e0ff3U, 0xa9017bfdU },
    { 387U, 0x037764U,    76U, 0xf81e0ff3U, 0xa9017bfdU },
    { 388U, 0x0377b0U,     8U, 0xaa0203e0U, 0x17ff29c7U },
    { 389U, 0x0377b8U,    32U, 0xf9400008U, 0xaa0303e1U },
    { 390U, 0x0377d8U,    32U, 0xf9400008U, 0xaa0303e1U },
    { 391U, 0x0377f8U,    20U, 0x93407c88U, 0xaa0303e1U },
    { 392U, 0x03780cU,     8U, 0x39400040U, 0xd65f03c0U },
};

} // namespace imagepipeline
} // namespace opencut
} // namespace nextai
