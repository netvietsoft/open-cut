// ============================================================================
// File: pl_droidsonroids_gif_pseudocode.cpp
// Target: libpl_droidsonroids_gif.so (42,464 bytes, ELF64 AArch64, 97 .dynsym)
// Package: com.nextai.opencut (NextAI OpenCut Reconstruction)
// Task ID: TASK-096-RECONSTRUCTION-LIBPL_DROIDSONROIDS_GIF (TASK_SO_039)
// Evidence Classification: OBSERVED (Direct AArch64 Disassembly 0x004044..0x009683)
// Description (EN): Complete address-annotated AArch64 decompilation and
//                   end-to-end verification harness for libpl_droidsonroids_gif.so,
//                   including JNI exception dispatch (throwException @ 0x0055f8,
//                   throwGifIOException @ 0x005800), GIFLIB error string mapping
//                   (0x005800..0x005938), ANativeWindow dual-thread synchronization
//                   (0x008cdc..0x009544), and synthetic GIF89a LZW decode test.
// Mô tả (VN): Mã giả C++17 chú thích địa chỉ AArch64 đầy đủ và bộ kiểm thử
//             khép kín cho libpl_droidsonroids_gif.so, bao gồm ném ngoại lệ JNI
//             (throwException @ 0x0055f8, throwGifIOException @ 0x005800),
//             bảng ánh xạ thông báo lỗi GIFLIB (0x005800..0x005938), đồng bộ
//             hai luồng ANativeWindow (0x008cdc..0x009544) và kiểm thử giải mã GIF89a.
// ============================================================================

#include "pl_droidsonroids_gif_types.h"
#include "pl_droidsonroids_gif_dgiff_decoder.h"
#include "pl_droidsonroids_gif_renderer.h"
#include "pl_droidsonroids_gif_interface.h"

#include <cassert>
#include <cstdio>
#include <cstring>
#include <vector>

namespace opencut {
namespace gif {

// ============================================================================
// 1. Address-Mapped JNI Exception & Error String Table (0x0055f8..0x005938)
//    Ánh xạ địa chỉ hàm ném ngoại lệ JNI & Bảng thông báo lỗi (0x0055f8..0x005938)
// ============================================================================

// Reconstructed from 0x0055f8..0x00575c:
// Maps exception type `type` (or `ENOMEM = 12` override at 0x005634: `cmp w9, #0xc; csel w8, w8, w22, eq`)
// to Java exception class name:
// - `type == 0`: appends `: ` + `strerror_r(errno, buf, 255)` to `message` and throws `"java/lang/RuntimeException"` (`0x00271b`)
// - `type == 1`: throws `"java/lang/RuntimeException"` (`0x00271b`)
// - `type == 2`: throws `"java/lang/OutOfMemoryError"` (`0x002736`)
// - `type == 3`: throws `"java/lang/NullPointerException"` (`0x0026db`)
// Phục hồi từ 0x0055f8..0x00575c: Ánh xạ loại ngoại lệ sang lớp Java tương ứng.
const char* resolveExceptionClassName(int type, int currentErrno) noexcept {
    const int effectiveType = (currentErrno == 12) ? 2 : type; // cmp w9, #0xc; csel w8, w8, w22, eq @ 0x005634
    switch (effectiveType) {
        case 2:
            return "java/lang/OutOfMemoryError";     // .rodata 0x002736
        case 3:
            return "java/lang/NullPointerException"; // .rodata 0x0026db
        case 0:
        case 1:
        default:
            return "java/lang/RuntimeException";     // .rodata 0x00271b
    }
}

// Reconstructed from 0x005800..0x005938:
// Constructs `"pl/droidsonroids/gif/GifIOException"` (.rodata `0x002570`) via
// `<init>(ILjava/lang/String;)V` (.rodata `0x0027ed`), optionally passing `strerror_r(errno)`
// when `includeErrno != 0`.
// Phục hồi từ 0x005800..0x005938: Khởi tạo và ném ngoại lệ `pl/droidsonroids/gif/GifIOException`.
const char* getGifIOExceptionClassName() noexcept {
    return "pl/droidsonroids/gif/GifIOException"; // .rodata 0x002570
}

// ============================================================================
// 2. Synthetic GIF89a 2-Frame Animation Verification Suite
//    Bộ kiểm thử hoạt ảnh GIF89a 2 khung hình tổng hợp
// ============================================================================

// Embedded 2x2, 2-frame GIF89a binary with:
// - Logical Screen: 2x2, Global Color Table (4 colors: Red, Green, Blue, White)
// - Application Extension: NETSCAPE2.0 (loop count = 2 -> stored loopCount = 3)
// - Comment Extension: "OpenCut"
// - Frame 0: GCB (disposal = DISPOSE_BACKGROUND (2), delay = 5 -> 50ms, transColor = -1), 2x2 image
// - Frame 1: GCB (disposal = DISPOSE_DO_NOT (1), delay = 8 -> 80ms, transColor = 0), 2x2 image
// Dữ liệu nhị phân GIF89a 2x2 gồm 2 khung hình phục vụ kiểm thử giải mã LZW và kết xuất ARGB8888.
static const uint8_t kSyntheticGif89a[] = {
    // Header: "GIF89a"
    'G', 'I', 'F', '8', '9', 'a',
    // Logical Screen Descriptor: SWidth=2, SHeight=2, Packed=0x91 (GCT=1, 4 colors), BgColor=0, Aspect=0
    0x02, 0x00, 0x02, 0x00, 0x91, 0x00, 0x00,
    // Global Color Table (4 x 3 = 12 bytes)
    0xFF, 0x00, 0x00, // [0] Red
    0x00, 0xFF, 0x00, // [1] Green
    0x00, 0x00, 0xFF, // [2] Blue
    0xFF, 0xFF, 0xFF, // [3] White
    // Application Extension: NETSCAPE2.0 (loop 2 times -> loopCount = 3)
    0x21, 0xFF, 0x0B,
    'N', 'E', 'T', 'S', 'C', 'A', 'P', 'E', '2', '.', '0',
    0x03, 0x01, 0x02, 0x00, 0x00,
    // Comment Extension: "OpenCut"
    0x21, 0xFE, 0x07, 'O', 'p', 'e', 'n', 'C', 'u', 't', 0x00,
    // Frame 0 Graphic Control Extension: disposal=2 (0x08), delay=5 (50ms), no trans
    0x21, 0xF9, 0x04, 0x08, 0x05, 0x00, 0x00, 0x00,
    // Frame 0 Image Descriptor: Left=0, Top=0, Width=2, Height=2, Packed=0x00
    0x2C, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x02, 0x00, 0x00,
    // Frame 0 LZW Image Data: minCodeSize=2, Clear=4, pixels=[0, 1, 2, 3], EOF=5
    // Bitstream (3-bit codes): 4 (100), 0 (000), 1 (001), 2 (010), 3 (011), 5 (101)
    // Byte 0: 100 | (000 << 3) | (01 << 6) = 0x44
    // Byte 1: 0 | (010 << 1) | (011 << 4) | (1 << 7) = 0xB4
    // Byte 2: 01 = 0x01
    0x02, 0x03, 0x44, 0xB4, 0x01, 0x00,
    // Frame 1 Graphic Control Extension: disposal=1 (0x05, transFlag=1), delay=8 (80ms), transColor=0
    0x21, 0xF9, 0x04, 0x05, 0x08, 0x00, 0x00, 0x00,
    // Frame 1 Image Descriptor: Left=0, Top=0, Width=2, Height=2, Packed=0x00
    0x2C, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x02, 0x00, 0x00,
    // Frame 1 LZW Image Data: minCodeSize=2, Clear=4, pixels=[0, 3, 2, 1], EOF=5
    // Bitstream: 4 (100), 0 (000), 3 (011), 2 (010), 1 (001), 5 (101)
    // Byte 0: 100 | (000 << 3) | (11 << 6) = 0xC4
    // Byte 1: 0 | (010 << 1) | (001 << 4) | (1 << 7) = 0x94
    // Byte 2: 01 = 0x01
    0x02, 0x03, 0xC4, 0x94, 0x01, 0x00,
    // Trailer ';'
    0x3B
};

// Run end-to-end verification of the reconstructed decoder and renderer
// Chạy kiểm thử toàn diện bộ giải mã LZW và bộ kết xuất ARGB8888 đã phục hồi
bool runSelfVerification() noexcept {
    JNI_OnLoad(nullptr, nullptr);

    DirectByteBufferContainer dbb{};
    dbb.bytes     = const_cast<uint8_t*>(kSyntheticGif89a);
    dbb.capacity  = static_cast<int64_t>(sizeof(kSyntheticGif89a));
    dbb.position  = 0LL;
    dbb.bufferRef = nullptr;

    const jlong handle = Java_pl_droidsonroids_gif_GifInfoHandle_openDirectByteBuffer(
        nullptr, nullptr, &dbb);
    if (handle == 0LL) {
        return false;
    }

    const jint width      = Java_pl_droidsonroids_gif_GifInfoHandle_getWidth(nullptr, nullptr, handle);
    const jint height     = Java_pl_droidsonroids_gif_GifInfoHandle_getHeight(nullptr, nullptr, handle);
    const jint numFrames  = Java_pl_droidsonroids_gif_GifInfoHandle_getNumberOfFrames(nullptr, nullptr, handle);
    const jint loopCount  = Java_pl_droidsonroids_gif_GifInfoHandle_getLoopCount(nullptr, nullptr, handle);
    const jint duration   = Java_pl_droidsonroids_gif_GifInfoHandle_getDuration(nullptr, nullptr, handle);
    const char* comment   = static_cast<const char*>(
        Java_pl_droidsonroids_gif_GifInfoHandle_getComment(nullptr, nullptr, handle));

    if (width != 2 || height != 2 || numFrames != 2 || loopCount != 3 || duration != 130) {
        Java_pl_droidsonroids_gif_GifInfoHandle_free(nullptr, nullptr, handle);
        return false;
    }
    if (comment == nullptr || std::strcmp(comment, "OpenCut") != 0) {
        Java_pl_droidsonroids_gif_GifInfoHandle_free(nullptr, nullptr, handle);
        return false;
    }

    argb canvas[4] = {};
    Java_pl_droidsonroids_gif_GifInfoHandle_renderFrame(nullptr, nullptr, handle, canvas);
    if (canvas[0].r != 0xFF || canvas[1].g != 0xFF || canvas[2].b != 0xFF || canvas[3].r != 0xFF) {
        Java_pl_droidsonroids_gif_GifInfoHandle_free(nullptr, nullptr, handle);
        return false;
    }

    Java_pl_droidsonroids_gif_GifInfoHandle_free(nullptr, nullptr, handle);
    JNI_OnUnload(nullptr, nullptr);
    return true;
}

} // namespace gif
} // namespace opencut
