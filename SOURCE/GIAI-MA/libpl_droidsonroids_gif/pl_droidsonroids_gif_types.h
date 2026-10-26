// ============================================================================
// File: pl_droidsonroids_gif_types.h
// Target: libpl_droidsonroids_gif.so (42,464 bytes, ELF64 AArch64, 97 .dynsym)
// Package: com.nextai.opencut (NextAI OpenCut Reconstruction)
// Task ID: TASK-096-RECONSTRUCTION-LIBPL_DROIDSONROIDS_GIF (TASK_SO_039)
// Evidence Classification: OBSERVED (Direct AArch64 Disassembly & .rodata/.data)
// Description (EN): Exact ABI structures, ELF64 section geometry, .rodata
//                   constants, GIFLIB 5.1.4 LZW decoder state (0x6160 bytes),
//                   GifInfo (0xa8 bytes), TexImageDescriptor (0x40 bytes), and
//                   SurfaceDescriptor (0xd0 bytes) for android-gif-drawable.
// Mô tả (VN): Các cấu trúc ABI chuẩn xác, hình học phân đoạn ELF64, hằng số
//             .rodata, trạng thái giải mã LZW GIFLIB 5.1.4 (0x6160 byte),
//             GifInfo (0xa8 byte), TexImageDescriptor (0x40 byte) và
//             SurfaceDescriptor (0xd0 byte) của thư viện android-gif-drawable.
// ============================================================================

#pragma once

#include <cstddef>
#include <cstdint>
#include <cstdio>

namespace opencut {
namespace gif {

// ============================================================================
// 1. ELF64 Binary & Section Geometry Constants (OBSERVED)
//    Hằng số hình học nhị phân và phân đoạn ELF64 (QUAN SÁT TRỰC TIẾP)
// ============================================================================
constexpr uint32_t kBinaryFileSizeBytes       = 42464U;
constexpr uint32_t kDynsymTotalEntries        = 97U;
constexpr uint32_t kDynsymImportedEntries     = 51U; // [001]..[051]
constexpr uint32_t kDynsymExportedEntries     = 45U; // [052]..[096]
constexpr uint32_t kJniExportedMethodCount    = 43U; // Java_pl_droidsonroids_gif_GifInfoHandle_*

constexpr uint64_t kSectionDynsymVaddr        = 0x0002f8ULL;
constexpr uint64_t kSectionDynsymSize         = 0x000918ULL; // 2,328 bytes
constexpr uint64_t kSectionDynstrVaddr        = 0x001178ULL;
constexpr uint64_t kSectionDynstrSize         = 0x000c95ULL; // 3,221 bytes
constexpr uint64_t kSectionRelaDynVaddr       = 0x001e10ULL;
constexpr uint64_t kSectionRelaDynSize        = 0x0000d8ULL; // 216 bytes (9 relocs)
constexpr uint64_t kSectionRelaPltVaddr       = 0x001ee8ULL;
constexpr uint64_t kSectionRelaPltSize        = 0x0004c8ULL; // 1,224 bytes (51 relocs)
constexpr uint64_t kSectionRodataVaddr        = 0x0023b0ULL;
constexpr uint64_t kSectionRodataSize         = 0x0007daULL; // 2,010 bytes
constexpr uint64_t kSectionTextVaddr          = 0x004044ULL;
constexpr uint64_t kSectionTextSize           = 0x005640ULL; // 22,080 bytes
constexpr uint64_t kSectionPltVaddr           = 0x009690ULL;
constexpr uint64_t kSectionPltSize            = 0x000350ULL; // 848 bytes
constexpr uint64_t kSectionDataRelRoVaddr     = 0x00d9e0ULL;
constexpr uint64_t kSectionDataRelRoSize      = 0x000030ULL; // 48 bytes
constexpr uint64_t kSectionGotVaddr           = 0x00dc00ULL;
constexpr uint64_t kSectionGotSize            = 0x000020ULL; // 32 bytes
constexpr uint64_t kSectionGotPltVaddr        = 0x00dc20ULL;
constexpr uint64_t kSectionGotPltSize         = 0x0001b0ULL; // 432 bytes
constexpr uint64_t kSectionDataVaddr          = 0x011dd0ULL;
constexpr uint64_t kSectionDataSize           = 0x000018ULL; // 24 bytes
constexpr uint64_t kSectionBssVaddr           = 0x011de8ULL;
constexpr uint64_t kSectionBssSize            = 0x000018ULL; // 24 bytes

// ============================================================================
// 2. .rodata & .data Constants & Fixed-Point Multipliers (OBSERVED)
//    Hằng số .rodata, .data và hệ số nhân dấu phẩy tĩnh (QUAN SÁT TRỰC TIẾP)
// ============================================================================
// Fixed-point reciprocal for signed 64-bit division by 1,000,000 (ns -> ms):
// ceil(2^(64+18) / 10^6) = 0x431bde82d7b634db (used in getRealTime @ 0x00964c
// and calculateInvalidationDelay @ 0x0095a4 via smulh + asr #18).
// Hệ số nghịch đảo dấu phẩy tĩnh chia có dấu 64-bit cho 1.000.000 (ns -> ms).
constexpr int64_t  kNsToMsMagicMultiplier     = 0x431bde82d7b634dbLL;
constexpr uint32_t kNsToMsRightShift          = 18U;
constexpr int64_t  kSecToMsMultiplier         = 1000LL; // 0x3e8

// Default JNI version stored at .data 0x011dd0 (0x00010006 = JNI_VERSION_1_6)
// Phiên bản JNI mặc định lưu tại .data 0x011dd0
constexpr int32_t  kDefaultJniVersion         = 0x00010006;

// Maximum comment length enforced at 0x004dd0 (cmp w1, #0x800; b.ls #0x4e08)
// Độ dài chú thích GIF tối đa kiểm tra tại 0x004dd0 (2048 byte)
constexpr uint32_t kMaxGifCommentBytes        = 0x0800U;

// Stream buffer size used in openStream @ 0x005fb4 (mov w1, #0x100 = 256 bytes)
// Kích thước bộ đệm luồng Java InputStream trong openStream @ 0x005fb4
constexpr int32_t  kStreamBufferSizeBytes     = 256;

// Default frame duration in milliseconds when GCB duration <= 10ms (1 tick):
// Observed at 0x004d10..0x004d28: if (duration > 1) duration *= 10; else duration = 100;
// Thời lượng khung hình mặc định (100 ms) khi GCB duration <= 1 tick (10 ms).
constexpr uint64_t kDefaultFrameDurationMs    = 100ULL; // 0x64
constexpr uint32_t kNoTransparentColor        = 0xFFFFFFFFU; // -1 sentinel

// OpenGL ES 2.0 texture constants observed at 0x008828..0x00883c & 0x0088dc..0x0088e0
// Hằng số kết cấu OpenGL ES 2.0 quan sát tại 0x008828..0x00883c
constexpr uint32_t kGlRgbaFormat              = 0x1908U; // GL_RGBA
constexpr uint32_t kGlUnsignedByteType        = 0x1401U; // GL_UNSIGNED_BYTE

// ============================================================================
// 3. GIFLIB & GifIOException Error Codes (OBSERVED at 0x005800..0x005938)
//    Mã lỗi GIFLIB & GifIOException (QUAN SÁT TẠI 0x005800..0x005938)
// ============================================================================
enum GifErrorCode : int32_t {
    D_GIF_SUCCEEDED            = 0,
    D_GIF_ERR_OPEN_FAILED      = 101,  // 0x65 (observed @ 0x006520, 0x00663c)
    D_GIF_ERR_READ_FAILED      = 102,  // 0x66 (observed @ 0x006778, 0x0068b0)
    D_GIF_ERR_NOT_GIF_FILE     = 103,  // 0x67 (observed @ 0x006748)
    D_GIF_ERR_NO_SCRN_DSCR     = 104,  // 0x68 (observed @ 0x0067f0)
    D_GIF_ERR_NO_IMAG_DSCR     = 105,  // 0x69
    D_GIF_ERR_NO_COLOR_MAP     = 106,  // 0x6a
    D_GIF_ERR_WRONG_RECORD     = 107,  // 0x6b (observed @ 0x006a70)
    D_GIF_ERR_DATA_TOO_BIG     = 108,  // 0x6c (observed @ 0x006ea4)
    D_GIF_ERR_NOT_ENOUGH_MEM   = 109,  // 0x6d (observed @ 0x006754, 0x006988)
    D_GIF_ERR_CLOSE_FAILED     = 110,  // 0x6e
    D_GIF_ERR_NOT_READABLE     = 111,  // 0x6f (observed @ 0x007b28)
    D_GIF_ERR_IMAGE_DEFECT     = 112,  // 0x70 (observed @ 0x0074d8)
    D_GIF_ERR_EOF_TOO_SOON     = 113,  // 0x71 (observed @ 0x00753c)
    D_GIF_ERR_NO_FRAMES        = 1000, // 0x3e8 (observed @ 0x007c04)
    D_GIF_ERR_INVALID_SCR_DIMS = 1001, // 0x3e9 (observed @ 0x007bb8)
    D_GIF_ERR_INVALID_IMG_DIMS = 1002, // 0x3ea
    D_GIF_ERR_IMG_NOT_CONFINED = 1003, // 0x3eb (observed @ 0x006bb0)
    D_GIF_ERR_REWIND_FAILED    = 1004, // 0x3ec (observed @ 0x007bf8, 0x00869c)
    D_GIF_ERR_INVALID_BYTE_CNT = 1005  // 0x3ed (observed @ 0x005ebc)
};

// GIF89a Graphic Control Extension Disposal Methods (observed @ 0x005160..0x005280)
// Phương thức xóa khung hình GIF89a Graphic Control Extension
enum DisposalMethod : uint8_t {
    DISPOSE_DO_NOT       = 0,
    DISPOSE_LEAVE        = 1,
    DISPOSE_BACKGROUND   = 2,
    DISPOSE_PREVIOUS     = 3
};

// GIF Record Types returned by DGifGetRecordType (@ 0x0069bc..0x006a80)
// Loại bản ghi GIF trả về bởi DGifGetRecordType (@ 0x0069bc..0x006a80)
enum GifRecordType : int32_t {
    UNDEFINED_RECORD_TYPE = 0,
    SCREEN_DESC_RECORD_TYPE = 1,
    IMAGE_DESC_RECORD_TYPE = 2, // ',' (0x2c) -> mov w8, #2
    EXTENSION_RECORD_TYPE  = 3, // '!' (0x21) -> mov w8, #3
    TERMINATE_RECORD_TYPE  = 4  // ';' (0x3b) -> mov w8, #4
};

// GIF89a Extension Function Codes checked in readExtensions (@ 0x004cc8..0x004cdc)
// Mã chức năng phần mở rộng GIF89a kiểm tra trong readExtensions
constexpr int32_t kGraphicsExtFuncCode    = 0xf9; // Graphic Control Extension
constexpr int32_t kCommentExtFuncCode     = 0xfe; // Comment Extension
constexpr int32_t kApplicationExtFuncCode = 0xff; // Application Extension (NETSCAPE2.0 / ANIMEXTS1.0)

// ============================================================================
// 4. Pixel & Color Map ABI Structures (OBSERVED)
//    Cấu trúc ABI Điểm ảnh & Bảng màu (QUAN SÁT TRỰC TIẾP)
// ============================================================================

// RGBA_8888 pixel layout in AndroidBitmap / ANativeWindow_Buffer (4 bytes)
// Bố cục điểm ảnh RGBA_8888 trong AndroidBitmap / ANativeWindow_Buffer
struct argb {
    uint8_t r; // +0x00
    uint8_t g; // +0x01
    uint8_t b; // +0x02
    uint8_t a; // +0x03 (set to 0xFF at 0x0050d0, 0x0053f4, 0x005474)
};
static_assert(sizeof(argb) == 4, "argb must be 4 bytes");

// 3-byte RGB entry in GIF color table (observed @ 0x00696c..0x00697c, 0x0078c8)
// Phần tử màu RGB 3 byte trong bảng màu GIF
struct GifColorType {
    uint8_t Red;   // +0x00
    uint8_t Green; // +0x01
    uint8_t Blue;  // +0x02
};
static_assert(sizeof(GifColorType) == 3, "GifColorType must be 3 bytes");

// ColorMapObject (sizeof = 0x18 = 24 bytes, allocated in GifMakeMapObject @ 0x0078b0)
// Cấu trúc ColorMapObject (24 byte, cấp phát tại GifMakeMapObject @ 0x0078b0)
struct ColorMapObject {
    int64_t       ColorCount;   // +0x00: 1 << BitsPerPixel (str x8, [x19] @ 0x0078e8)
    uint8_t       BitsPerPixel; // +0x08: 1..8 (strb w21, [x19, #8] @ 0x0078dc)
    uint8_t       SortFlag;     // +0x09: padding / sort flag
    uint8_t       _pad[6];      // +0x0a..+0x0f: 8-byte alignment padding
    GifColorType* Colors;       // +0x10: calloc(256, 3) (str x0, [x19, #0x10] @ 0x0078d0)
};
static_assert(sizeof(ColorMapObject) == 0x18, "ColorMapObject must be 0x18 bytes");

// ============================================================================
// 5. GIFLIB Image Descriptor, SavedImage, Private LZW State & GifFileType
//    Cấu trúc GifImageDesc, SavedImage, Trạng thái LZW & GifFileType
// ============================================================================

// GifImageDesc / SavedImage (sizeof = 0x30 = 48 bytes, observed @ 0x006c48..0x006c98)
// Cấu trúc mô tả khung hình (48 byte, dùng chung cho Image và mảng SavedImages)
struct GifImageDesc {
    uint64_t        Left;       // +0x00: Image Left offset (str x8, [x19, #0x28] @ 0x006aec)
    uint64_t        Top;        // +0x08: Image Top offset  (str x8, [x19, #0x30] @ 0x006b18)
    uint64_t        Width;      // +0x10: Image Width       (str x8, [x19, #0x38] @ 0x006b44)
    uint64_t        Height;     // +0x18: Image Height      (str x8, [x19, #0x40] @ 0x006b70)
    bool            Interlace;  // +0x20: bit 6 of packed byte (strb w8, [x19, #0x48] @ 0x006c14)
    uint8_t         _pad[7];    // +0x21..+0x27
    ColorMapObject* ColorMap;   // +0x28: Local color map (str x0, [x19, #0x50] @ 0x006cd0)
};
static_assert(sizeof(GifImageDesc) == 0x30, "GifImageDesc must be 0x30 bytes");

using SavedImage = GifImageDesc;

struct GifFileType;

// Custom input read callback signature: int (*InputFunc)(GifFileType*, uint8_t*, int)
// Con trỏ hàm đọc luồng đầu vào tùy chỉnh
using InputFunc = int (*)(GifFileType* gif, uint8_t* buf, int count);

// LZW Decoder constants (observed in DGifSetupDecompress @ 0x006dbc..0x006e20)
// Hằng số bộ giải mã LZW (quan sát trong DGifSetupDecompress @ 0x006dbc..0x006e20)
constexpr int32_t  LZ_MAX_CODE     = 4095;   // 0x0fff (cmp w26, #0xfff @ 0x006eb8)
constexpr uint32_t LZ_BITS         = 12U;    // Max LZW code bit width
constexpr uint32_t NO_SUCH_CODE    = 4098U;  // 0x1002 (mov w9, #0x1002 @ 0x006df4)

// GifFilePrivateType (sizeof = 0x6160 = 24,928 bytes, calloc(1, 0x6160) @ 0x0066f0)
// Trạng thái nội bộ bộ giải mã LZW GIFLIB (24.928 byte, cấp phát tại 0x0066f0)
struct GifFilePrivateType {
    uint64_t  BitsPerPixel;        // +0x0000: Initial LZW code size (stp x8, x9, [x21] @ 0x006dd8)
    uint64_t  ClearCode;           // +0x0008: 1 << BitsPerPixel
    uint64_t  EOFCode;             // +0x0010: ClearCode + 1 (str q0, [x21, #0x10] @ 0x006e00)
    uint64_t  RunningCode;         // +0x0018: ClearCode + 2
    uint64_t  RunningBits;         // +0x0020: BitsPerPixel + 1 (stp x11, x8, [x21, #0x20] @ 0x006df8)
    uint64_t  MaxCode1;            // +0x0028: 1 << RunningBits
    int64_t   LastCode;            // +0x0030: NO_SUCH_CODE (0x1002) (str q1, [x21, #0x30] @ 0x006e08)
    int64_t   CrntShiftState;      // +0x0038: Number of stacked bytes in Stack (ldr x26, [x25, #0x38] @ 0x006eb4)
    uint64_t  CrntShiftDWord;      // +0x0040: Bit shift count (ldr x8, [x22, #0x40] @ 0x007084)
    uint64_t  CrntCodeBits;        // +0x0048: Bit accumulator (ldr x11, [x22, #0x48] @ 0x0070b4)
    uint64_t  PixelCount;          // +0x0050: Remaining pixels in image (str x8, [x24, #0x50] @ 0x006cb8)
    InputFunc Read;                // +0x0058: Custom InputFunc callback (str x22, [x0, #0x58] @ 0x006700)
    uint8_t   Buf[256];            // +0x0060..+0x015f: Sub-block read buffer (Buf[0] = byte count)
    uint8_t   Stack[4096];         // +0x0160..+0x115f: Decoded LZW pixel stack (add x10, x25, #0x160 @ 0x007020)
    uint8_t   Suffix[4096];        // +0x1160..+0x215f: LZW suffix table (base - 1 = +0x115f @ 0x007014)
    uint32_t  Prefix[4096];        // +0x2160..+0x615f: LZW prefix table (4096 * 4 = 0x4000 B, init to 0x1002 @ 0x006e14)
};
static_assert(sizeof(GifFilePrivateType) == 0x6160, "GifFilePrivateType must be 0x6160 bytes");

// GifFileType (sizeof = 0x78 = 120 bytes, calloc(1, 0x78) @ 0x0066d4)
// Cấu trúc tệp GIF chính của GIFLIB (120 byte, cấp phát tại 0x0066d4)
struct GifFileType {
    uint64_t            SWidth;           // +0x00: Logical screen width (str x9, [x19] @ 0x006858)
    uint64_t            SHeight;          // +0x08: Logical screen height (str x9, [x19, #8] @ 0x006884)
    uint64_t            SColorResolution; // +0x10: Color resolution
    uint64_t            SBackGroundColor; // +0x10/+0x18: Background color index / SColorMap
    ColorMapObject*     SColorMap;        // +0x18: Global ColorMapObject* (str x0, [x19, #0x18] @ 0x00690c)
    uint64_t            ImageCount;       // +0x20: Number of frames (ldr x8, [x19, #0x20] @ 0x006c44)
    GifImageDesc        Image;            // +0x28..+0x57: Current frame descriptor (48 bytes)
    SavedImage*         SavedImages;      // +0x58: Array of SavedImage (str x0, [x19, #0x58] @ 0x006c68)
    int32_t             Error;            // +0x60: GIFLIB error code (str w8, [x19, #0x60] @ 0x0068b8)
    int32_t             _pad;             // +0x64
    void*               UserData;         // +0x68: Source container / FILE* (stp x23, x0, [x19, #0x68] @ 0x006704)
    GifFilePrivateType* Private;          // +0x70: GifFilePrivateType* (0x6160 bytes)
};

// ============================================================================
// 6. android-gif-drawable Runtime & Rendering Structures (OBSERVED)
//    Cấu trúc thực thi và kết xuất android-gif-drawable (QUAN SÁT TRỰC TIẾP)
// ============================================================================

// Per-frame metadata (sizeof = 0x18 = 24 bytes, indexed via madd x, idx, #0x18 @ 0x004cf8)
// Siêu dữ liệu từng khung hình (24 byte mỗi phần tử trong mảng GifInfo::infos)
struct FrameInfo {
    uint8_t  disposalMethod; // +0x00: DisposalMethod (0..3, ubfx w8, w8, #2, #3 @ 0x0077ec)
    uint8_t  _pad0[7];       // +0x01..+0x07
    uint64_t duration;       // +0x08: Frame duration in ms (str x8, [x2, #8] @ 0x0077f8)
    int32_t  transColor;     // +0x10: Transparent color index or -1 (str w8, [x2, #0x10] @ 0x00781c)
    int32_t  _pad1;          // +0x14
};
static_assert(sizeof(FrameInfo) == 0x18, "FrameInfo must be 0x18 bytes");

struct GifInfo;

// Source rewind callback: int (*RewindFunc)(GifInfo*)
// Con trỏ hàm tua lại nguồn dữ liệu đầu vào:
// - fileRewind (0x00593c)
// - streamRewind (0x005980)
// - byteArrayRewind (0x005a14)
// - directByteBufferRewind (0x005a30)
using RewindFunc = int (*)(GifInfo* info);

// Destructor callback for surface/GL descriptor: void (*DestructorFunc)(GifInfo*, void* jniEnv)
// Con trỏ hàm hủy bộ mô tả kết cấu GL (`0x008aa8`) hoặc bề mặt ANativeWindow (`0x0092f4`)
using DestructorFunc = void (*)(GifInfo* info, void* jniEnv);

// Input source descriptor passed to createGifInfo (@ 0x007a30, sizeof = 0x28 = 40 bytes)
// Cấu trúc mô tả nguồn đầu vào truyền vào hàm createGifInfo (@ 0x007a30)
struct DecodeSource {
    GifFileType* gifFileIn;    // +0x00: Opened GifFileType*
    int32_t      error;        // +0x08: Error code from DGifOpen
    int32_t      _pad;         // +0x0c
    int64_t      startPos;     // +0x10: Initial stream offset (ftell / 0)
    RewindFunc   rewindFunc;   // +0x18: Rewind callback pointer
    int64_t      sourceLength; // +0x20: Total byte length from stat64/fstat64/arrayLen (-1 if unknown)
};
static_assert(sizeof(DecodeSource) == 0x28, "DecodeSource must be 0x28 bytes");

// Java InputStream wrapper (sizeof = 0x28 = 40 bytes, malloc(0x28) @ 0x005fec)
// Cấu trúc bọc luồng Java InputStream (40 byte, cấp phát tại 0x005fec)
struct StreamContainer {
    void*   streamObjGlobalRef; // +0x00: jobject InputStream global ref
    void*   streamClassRef;     // +0x08: jclass InputStream global ref
    void*   readMethodID;       // +0x10: jmethodID read([BII)I
    void*   resetMethodID;      // +0x18: jmethodID reset()V
    void*   bufferByteArrayRef; // +0x20: jbyteArray (256-byte global ref)
};
static_assert(sizeof(StreamContainer) == 0x28, "StreamContainer must be 0x28 bytes");

// Java byte[] wrapper (sizeof = 0x18 = 24 bytes, malloc(0x18) @ 0x005c04)
// Cấu trúc bọc mảng byte[] Java (24 byte, cấp phát tại 0x005c04)
struct ByteArrayContainer {
    uint32_t arrLen;       // +0x00: Array length (str w20, [x22] @ 0x005c40)
    uint32_t position;     // +0x04: Current read cursor (ldr w9, [x8, #4] @ 0x005d5c)
    void*    bufferGlobal; // +0x08: jbyteArray global ref (str x0, [x22, #8] @ 0x005c38)
};

// Direct ByteBuffer wrapper (sizeof = 0x20 = 32 bytes, malloc(0x20) @ 0x005ddc)
// Cấu trúc bọc DirectByteBuffer (32 byte, cấp phát tại 0x005ddc)
struct DirectByteBufferContainer {
    uint8_t* bytes;         // +0x00: GetDirectBufferAddress pointer
    int64_t  capacity;      // +0x08: GetDirectBufferCapacity
    int64_t  position;      // +0x10: Current read cursor
    void*    bufferRef;     // +0x18: jobject ByteBuffer global ref
};
static_assert(sizeof(DirectByteBufferContainer) == 0x20, "DirectByteBufferContainer must be 0x20 bytes");

// OpenGL ES 2.0 Texture Descriptor (sizeof = 0x40 = 64 bytes, malloc(0x40) @ 0x008938)
// Bộ mô tả kết cấu OpenGL ES 2.0 (64 byte, cấp phát tại initTexImageDescriptor @ 0x008938)
struct TexImageDescriptor {
    int32_t  eventPollFd;      // +0x00: eventfd descriptor (-1 when idle)
    uint16_t pollEvents;       // +0x04: POLLIN (1) (strh w8, [x21, #4] @ 0x008a28)
    uint16_t pollRevents;      // +0x06: poll revents
    argb*    frameBuffer;      // +0x08: RGBA8888 texture buffer (width * height * 4 bytes)
    uint8_t  renderMutex[40];  // +0x10..+0x37: pthread_mutex_t (add x0, x21, #0x10 @ 0x008970)
    uint64_t slurpThread;      // +0x38: pthread_t decoder thread (add x0, x21, #0x38 @ 0x008a3c)
};
static_assert(sizeof(TexImageDescriptor) == 0x40, "TexImageDescriptor must be 0x40 bytes");

// ANativeWindow Surface Descriptor (sizeof = 0xd0 = 208 bytes, malloc(0xd0) @ 0x008d20)
// Bộ mô tả bề mặt ANativeWindow (208 byte, cấp phát tại bindSurface @ 0x008d20)
struct SurfaceDescriptor {
    int32_t  eventPollFd;       // +0x00: pollfd.fd = eventfd(0, 0) (str w0, [x20] @ 0x008d48)
    uint16_t pollEvents;        // +0x04: pollfd.events = POLLIN (1) (strh w8, [x0, #4] @ 0x008d38)
    uint16_t pollRevents;       // +0x06: pollfd.revents
    void*    surfaceBackupPtr;  // +0x08: Saved canvas backup buffer (str x0, [x20, #8] @ 0x0092c4)
    uint8_t  slurpHelper;       // +0x10: Slurp thread command flag (0=wait, 1=decode, 2=stop @ 0x0091f8, 0x009274)
    uint8_t  _pad0[3];          // +0x11..+0x13
    uint8_t  slurpMutex[40];    // +0x14..+0x3b: pthread_mutex_t (add x0, x20, #0x14 @ 0x008dac)
    uint8_t  slurpCond[48];     // +0x3c..+0x6b: pthread_cond_t  (add x0, x20, #0x3c @ 0x008d50)
    uint8_t  renderHelper;      // +0x6c: Render ready flag (0=waiting, 1=frame ready @ 0x009028, 0x009484)
    uint8_t  _pad1[3];          // +0x6d..+0x6f
    uint8_t  renderMutex[40];   // +0x70..+0x97: pthread_mutex_t (add x0, x20, #0x70 @ 0x008dd4)
    uint8_t  renderCond[48];    // +0x98..+0xc7: pthread_cond_t  (add x0, x20, #0x98 @ 0x008d84)
    uint64_t slurpThread;       // +0xc8: pthread_t slurp thread (add x0, x20, #0xc8 @ 0x009080)
};
static_assert(sizeof(SurfaceDescriptor) == 0xd0, "SurfaceDescriptor must be 0xd0 bytes");

// Master GifInfo Handle Structure (sizeof = 0xa8 = 168 bytes, malloc(0xa8) @ 0x007a64)
// Cấu trúc điều khiển chính GifInfo (168 byte, cấp phát tại createGifInfo @ 0x007a64)
struct GifInfo {
    DestructorFunc destructor;         // +0x00: Optional cleanup hook for GL/Surface (ldr x8, [x2] @ 0x004e6c)
    GifFileType*   gifFilePtr;         // +0x08: Underlying GifFileType* (stp xzr, x22, [x21] @ 0x007ad0)
    uint64_t       originalWidth;      // +0x10: Original SWidth before downsampling (str q0, [x21, #0x10] @ 0x007af0)
    uint64_t       originalHeight;     // +0x18: Original SHeight before downsampling
    uint64_t       sampleSize;         // +0x20: Subsampling divisor >= 1 (init to 1 via .rodata 0x002970 @ 0x007ae0)
    int64_t        lastFrameRemainder; // +0x28: Remaining ms when paused (-1 sentinel, .rodata 0x002978 @ 0x007ae0)
    int64_t        nextStartTime;      // +0x30: Target CLOCK_MONOTONIC_RAW timestamp in ms (stp xzr, xzr, [x21, #0x30])
    uint64_t       currentIndex;       // +0x38: Current frame index (0..ImageCount-1)
    FrameInfo*     infos;              // +0x40: Array of FrameInfo (str x0, [x21, #0x40] @ 0x007a7c)
    argb*          backupPtr;          // +0x48: Canvas backup for DISPOSE_PREVIOUS (stp xzr, x23, [x21, #0x48] @ 0x007ad4)
    int64_t        startPos;           // +0x50: Stream start offset for rewind
    uint8_t*       rasterBits;         // +0x58: Decoded indexed pixel buffer (ldr x0, [x19, #0x58] @ 0x0048e8)
    uint64_t       rasterSize;         // +0x60: Allocated byte count of rasterBits (str x23, [x19, #0x60] @ 0x004900)
    char*          comment;            // +0x68: Optional GIF comment string (ldr x0, [x19, #0x68] @ 0x004d30)
    uint64_t       loopCount;          // +0x70: Netscape 2.0 loop count (init to 1 via .rodata 0x0029c0 @ 0x007ac4)
    uint64_t       currentLoop;        // +0x78: Completed loop counter (init to 0)
    RewindFunc     rewindFunction;     // +0x80: Input source rewind function (str x8, [x21, #0x80] @ 0x007ad8)
    float          speedFactor;        // +0x88: Playback speed multiplier (init to 1.0f = 0x3f800000 @ 0x007ab8)
    uint32_t       stride;             // +0x8c: Bitmap/Surface row stride in pixels (str w8, [x22, #0x8c] @ 0x004100)
    int64_t        sourceLength;       // +0x90: Source byte length (str x10, [x21, #0x90] @ 0x007adc)
    bool           isOpaque;           // +0x98: True if alpha channel is ignored (strb wzr, [x21, #0x98] @ 0x007aec)
    uint8_t        _pad[7];            // +0x99..+0x9f
    void*          frameBufferDescriptor; // +0xa0: TexImageDescriptor* or SurfaceDescriptor* (str xzr, [x21, #0xa0] @ 0x007ae8)
};
static_assert(sizeof(GifInfo) == 0xa8, "GifInfo must be 0xa8 bytes");

// ============================================================================
// 7. GIF89a 4-Pass Interlace Tables & LZW Bitmask Table (.rodata 0x002b60..0x002b89)
//    Bảng đan xen 4 lượt GIF89a & Bảng mặt nạ bit LZW (.rodata 0x002b60..0x002b89)
// ============================================================================
// Observed in DDGifSlurp (@ 0x004ab4..0x004b38):
// - Pass start rows at 0x002b60: {0, 4, 2, 1}
// - Pass row strides at 0x002b64: {8, 8, 4, 2}
constexpr uint8_t kInterlacedOffset[4] = {0U, 4U, 2U, 1U};
constexpr uint8_t kInterlacedJumps[4]  = {8U, 8U, 4U, 2U};

// LZW code bitmask table at .rodata 0x002b70 (loaded via ldrh w11, [x23, x9, lsl #1] @ 0x00717c)
// Bảng mặt nạ bit LZW tại .rodata 0x002b70
constexpr uint16_t kCodeMasks[13] = {
    0x0000U, 0x0001U, 0x0003U, 0x0007U,
    0x000FU, 0x001FU, 0x003FU, 0x007FU,
    0x00FFU, 0x01FFU, 0x03FFU, 0x07FFU,
    0x0FFFU
};

} // namespace gif
} // namespace opencut
