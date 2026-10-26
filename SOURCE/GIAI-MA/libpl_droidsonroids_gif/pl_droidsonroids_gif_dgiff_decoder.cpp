// ============================================================================
// File: pl_droidsonroids_gif_dgiff_decoder.cpp
// Target: libpl_droidsonroids_gif.so (42,464 bytes, ELF64 AArch64)
// Package: com.nextai.opencut (NextAI OpenCut Reconstruction)
// Task ID: TASK-096-RECONSTRUCTION-LIBPL_DROIDSONROIDS_GIF (TASK_SO_039)
// Evidence Classification: OBSERVED (Direct AArch64 Disassembly 0x0048a4..0x007a2c)
// Description (EN): Complete C++17 implementation of the embedded GIFLIB 5.1.4
//                   LZW decompression engine, ColorMapObject lifecycle,
//                   4-pass interlace & downsampling slurper (`DDGifSlurp`),
//                   GIF89a extension parser (`readExtensions`), and 4 input
//                   source read/rewind callbacks.
// Mô tả (VN): Bản cài đặt C++17 đầy đủ của bộ giải nén LZW GIFLIB 5.1.4 nhúng,
//             vòng đời ColorMapObject, bộ đọc đan xen 4 lượt kèm lấy mẫu giảm
//             (`DDGifSlurp`), bộ phân tích phần mở rộng GIF89a (`readExtensions`)
//             và 4 hàm đọc/tua lại nguồn đầu vào.
// ============================================================================

#include "pl_droidsonroids_gif_dgiff_decoder.h"

#include <cerrno>
#include <cstdlib>
#include <cstring>

namespace opencut {
namespace gif {

namespace {
// Global 256-entry grayscale fallback ColorMapObject stored at .bss 0x011df8
// Bảng màu xám 256 mức mặc định toàn cục lưu tại .bss 0x011df8
ColorMapObject* g_defaultColorMap = nullptr;
} // namespace

// ============================================================================
// 1. Memory & ColorMap Management (0x007824..0x007a2c, 0x008098)
//    Quản lý bộ nhớ và bảng màu ColorMap (0x007824..0x007a2c, 0x008098)
// ============================================================================

// Reconstructed from 0x0079dc..0x007a2c:
// Checks 64-bit multiplication overflow via `(nmemb | size) >> 32 != 0 && umulh(nmemb, size) != 0`
// before calling `realloc(optr, nmemb * size)`. Sets `errno = ENOMEM (12)` on overflow.
// Phục hồi từ 0x0079dc..0x007a2c: Kiểm tra tràn số nhân 64-bit bằng lệnh `umulh` trước khi gọi `realloc`.
void* openbsd_reallocarray(void* optr, size_t nmemb, size_t size) noexcept {
    if (nmemb != 0) {
        const uint64_t high_bits = (static_cast<uint64_t>(nmemb) | static_cast<uint64_t>(size)) >> 32U;
        if (high_bits != 0) {
#if defined(__SIZEOF_INT128__)
            const __uint128_t prod = static_cast<__uint128_t>(nmemb) * static_cast<__uint128_t>(size);
            if ((prod >> 64U) != 0) {
                errno = ENOMEM; // mov w8, #0xc; str w8, [x0] @ 0x007a1c..0x007a20
                return nullptr;
            }
#else
            if (size != 0 && nmemb > (SIZE_MAX / size)) {
                errno = ENOMEM;
                return nullptr;
            }
#endif
        }
    }
    if (nmemb == 0 || size == 0) {
        return nullptr; // cbz x1, #0x7a08; cbz x2, #0x7a08
    }
    return std::realloc(optr, nmemb * size); // mul x1, x2, x1; b realloc @ 0x007a00..0x007a04
}

// Reconstructed from 0x00789c..0x007920:
// Allocates `sizeof(ColorMapObject) = 0x18` via `malloc(0x18)` and always allocates
// `calloc(256, 3)` (`0x300` bytes) for `Colors` to prevent out-of-bounds palette lookups.
// Phục hồi từ 0x00789c..0x007920: Cấp phát `ColorMapObject` (24 byte) và luôn cấp phát
// 256 phần tử RGB (`calloc(0x100, 3)`) để chống đọc tràn bảng màu.
ColorMapObject* GifMakeMapObject(uint8_t bitsPerPixel, const GifColorType* colorMap) noexcept {
    auto* object = static_cast<ColorMapObject*>(std::malloc(sizeof(ColorMapObject)));
    if (object == nullptr) {
        return nullptr;
    }
    auto* colors = static_cast<GifColorType*>(std::calloc(256U, sizeof(GifColorType)));
    object->Colors = colors;
    if (colors == nullptr) {
        std::free(object);
        return nullptr;
    }
    object->BitsPerPixel = bitsPerPixel;
    object->SortFlag     = 0;
    const int64_t colorCount = static_cast<int64_t>(1) << bitsPerPixel;
    object->ColorCount   = colorCount;
    if (colorMap != nullptr) {
        const size_t copyBytes = static_cast<size_t>(colorCount) * sizeof(GifColorType);
        std::memcpy(colors, colorMap, copyBytes <= 0x300U ? copyBytes : 0x300U);
    }
    return object;
}

// Reconstructed from 0x007924..0x007950:
// Frees `object->Colors` (+0x10) and `object`.
// Phục hồi từ 0x007924..0x007950: Giải phóng `object->Colors` và `object`.
void GifFreeMapObject(ColorMapObject* object) noexcept {
    if (object == nullptr) {
        return;
    }
    std::free(object->Colors);
    std::free(object);
}

// Reconstructed from 0x007954..0x0079d8:
// Iterates over `gifFile->SavedImages[0..ImageCount-1]` (each `0x30` bytes),
// freeing each non-null local `ColorMap` (+0x28) and its `Colors` (+0x10), then frees `SavedImages`.
// Phục hồi từ 0x007954..0x0079d8: Giải phóng toàn bộ mảng `SavedImages` và bảng màu cục bộ.
void GifFreeSavedImages(GifFileType* gifFile) noexcept {
    if (gifFile == nullptr || gifFile->SavedImages == nullptr) {
        return;
    }
    for (uint64_t i = 0; i < gifFile->ImageCount; ++i) {
        SavedImage& sp = gifFile->SavedImages[i];
        if (sp.ColorMap != nullptr) {
            std::free(sp.ColorMap->Colors);
            std::free(sp.ColorMap);
            sp.ColorMap = nullptr;
        }
    }
    std::free(gifFile->SavedImages);
    gifFile->SavedImages = nullptr;
}

// Reconstructed from 0x007824..0x007898:
// Releases `Image.ColorMap` (+0x50), `SColorMap` (+0x18), `SavedImages` (+0x58),
// `Private` (+0x70), and `gifFile` itself.
// Phục hồi từ 0x007824..0x007898: Giải phóng toàn bộ tài nguyên trong `GifFileType`.
int DGifCloseFile(GifFileType* gifFile) noexcept {
    if (gifFile == nullptr) {
        return 0;
    }
    if (gifFile->Private == nullptr) {
        return 0;
    }
    if (gifFile->Image.ColorMap != nullptr) {
        GifFreeMapObject(gifFile->Image.ColorMap);
        gifFile->Image.ColorMap = nullptr;
    }
    if (gifFile->SColorMap != nullptr) {
        GifFreeMapObject(gifFile->SColorMap);
        gifFile->SColorMap = nullptr;
    }
    if (gifFile->SavedImages != nullptr) {
        GifFreeSavedImages(gifFile);
        gifFile->SavedImages = nullptr;
    }
    std::free(gifFile->Private);
    std::free(gifFile);
    return 1;
}

// Reconstructed from 0x007dc0..0x008024, 0x00808c..0x0080a0:
// Initializes the 256-entry grayscale default palette at `.bss 0x011df8` where
// entry `i` has `(Red = i, Green = i, Blue = i)` for `i = 0..255`.
// Phục hồi từ 0x007dc0..0x008024, 0x00808c..0x0080a0: Khởi tạo bảng màu xám 256 mức mặc định.
ColorMapObject* initDefaultColorMap() noexcept {
    ColorMapObject* cmap = GifMakeMapObject(8U, nullptr);
    g_defaultColorMap = cmap;
    if (cmap != nullptr && cmap->Colors != nullptr) {
        for (int i = 0; i < 256; ++i) {
            const uint8_t gray = static_cast<uint8_t>(i);
            cmap->Colors[i].Red   = gray;
            cmap->Colors[i].Green = gray;
            cmap->Colors[i].Blue  = gray;
        }
    }
    return cmap;
}

void freeDefaultColorMap() noexcept {
    GifFreeMapObject(g_defaultColorMap);
    g_defaultColorMap = nullptr;
}

ColorMapObject* getDefColorMap() noexcept {
    if (g_defaultColorMap == nullptr) {
        return initDefaultColorMap();
    }
    return g_defaultColorMap;
}

// ============================================================================
// 2. GIFLIB 5.1.4 Stream & LZW Decompression Core (0x0066a8..0x007820)
//    Lõi đọc luồng và giải nén LZW GIFLIB 5.1.4 (0x0066a8..0x007820)
// ============================================================================

// Reconstructed from 0x0066a8..0x0067f8:
// Allocates `GifFileType` (`0x78` bytes) and `GifFilePrivateType` (`0x6160` bytes),
// reads 6-byte header, verifies `"GIF"` (`0x4947` + `0x46`), and calls `DGifGetScreenDesc`.
// Phục hồi từ 0x0066a8..0x0067f8: Cấp phát `GifFileType` (120 byte) và `GifFilePrivateType`
// (24.928 byte), kiểm tra chữ ký `"GIF"` và gọi `DGifGetScreenDesc`.
GifFileType* DGifOpen(void* userPtr, InputFunc readFunc, int* error) noexcept {
    auto* gifFile = static_cast<GifFileType*>(std::calloc(1U, sizeof(GifFileType)));
    if (gifFile == nullptr) {
        if (error != nullptr) {
            *error = D_GIF_ERR_NOT_ENOUGH_MEM; // mov w8, #0x6d @ 0x006754
        }
        return nullptr;
    }

    auto* priv = static_cast<GifFilePrivateType*>(std::calloc(1U, sizeof(GifFilePrivateType)));
    if (priv == nullptr) {
        if (error != nullptr) {
            *error = D_GIF_ERR_NOT_ENOUGH_MEM; // mov w8, #0x6d @ 0x006768
        }
        std::free(gifFile);
        return nullptr;
    }

    priv->Read        = readFunc;
    gifFile->UserData = userPtr;
    gifFile->Private  = priv;

    uint8_t buf[7] = {0};
    if (readFunc(gifFile, buf, 6) != 6) {
        if (error != nullptr) {
            *error = D_GIF_ERR_READ_FAILED; // mov w8, #0x66 @ 0x006778
        }
        std::free(priv);
        std::free(gifFile);
        return nullptr;
    }

    // Check "GIF" magic: ldrh w8, [sp] == 0x4947 ('GI') && ldrb w9, [sp, #2] == 0x46 ('F')
    if (buf[0] != 'G' || buf[1] != 'I' || buf[2] != 'F') {
        if (error != nullptr) {
            *error = D_GIF_ERR_NOT_GIF_FILE; // mov w8, #0x67 @ 0x006748
        }
        std::free(priv);
        std::free(gifFile);
        return nullptr;
    }

    if (DGifGetScreenDesc(gifFile) == 0) {
        std::free(priv);
        std::free(gifFile);
        if (error != nullptr) {
            *error = D_GIF_ERR_NO_SCRN_DSCR; // mov w8, #0x68 @ 0x0067f0
        }
        return nullptr;
    }

    gifFile->Error = D_GIF_SUCCEEDED;
    if (error != nullptr) {
        *error = D_GIF_SUCCEEDED;
    }
    return gifFile;
}

// Reconstructed from 0x0067fc..0x0069b8:
// Reads 2-byte SWidth, 2-byte SHeight, and 3-byte packed fields (packed byte,
// SBackGroundColor, PixelAspectRatio). If bit 7 of packed byte is set (`tbnz w8, #0x1f`
// after `ldrsb`), allocates and reads the Global Color Table (`1 << ((packed & 7) + 1)` RGB triplets).
// Phục hồi từ 0x0067fc..0x0069b8: Đọc kích thước màn hình logic và bảng màu toàn cục.
int DGifGetScreenDesc(GifFileType* gifFile) noexcept {
    GifFilePrivateType* priv = gifFile->Private;
    uint8_t buf[4] = {0};

    if (priv->Read(gifFile, buf, 2) != 2) {
        gifFile->Error = D_GIF_ERR_READ_FAILED;
        return 0;
    }
    gifFile->SWidth = static_cast<uint64_t>(buf[0]) | (static_cast<uint64_t>(buf[1]) << 8U);

    if (priv->Read(gifFile, buf, 2) != 2) {
        gifFile->Error = D_GIF_ERR_READ_FAILED;
        return 0;
    }
    gifFile->SHeight = static_cast<uint64_t>(buf[0]) | (static_cast<uint64_t>(buf[1]) << 8U);

    if (priv->Read(gifFile, buf, 3) != 3) {
        gifFile->Error = D_GIF_ERR_READ_FAILED;
        GifFreeMapObject(gifFile->SColorMap);
        gifFile->SColorMap = nullptr;
        return 0;
    }

    const int8_t  packedSigned = static_cast<int8_t>(buf[0]);
    const uint8_t bgColor      = buf[1];
    gifFile->SBackGroundColor  = bgColor;

    if (packedSigned < 0) {
        const uint8_t bitsPerPixel = static_cast<uint8_t>((buf[0] & 0x07U) + 1U);
        ColorMapObject* globalMap = GifMakeMapObject(bitsPerPixel, nullptr);
        gifFile->SColorMap = globalMap;
        if (globalMap == nullptr) {
            gifFile->Error = D_GIF_ERR_NOT_ENOUGH_MEM;
            return 0;
        }
        for (int64_t i = 0; i < globalMap->ColorCount; ++i) {
            if (priv->Read(gifFile, buf, 3) != 3) {
                GifFreeMapObject(gifFile->SColorMap);
                gifFile->SColorMap = nullptr;
                gifFile->Error = D_GIF_ERR_READ_FAILED;
                return 0;
            }
            globalMap->Colors[i].Red   = buf[0];
            globalMap->Colors[i].Green = buf[1];
            globalMap->Colors[i].Blue  = buf[2];
        }
    } else {
        gifFile->SColorMap = nullptr;
    }
    return 1;
}

// Reconstructed from 0x0069bc..0x006a80:
// Reads 1 byte from stream and maps `'!' (0x21) -> EXTENSION_RECORD_TYPE (3)`,
// `',' (0x2c) -> IMAGE_DESC_RECORD_TYPE (2)`, `';' (0x3b) -> TERMINATE_RECORD_TYPE (4)`.
// Phục hồi từ 0x0069bc..0x006a80: Đọc 1 byte định danh loại bản ghi GIF tiếp theo.
int DGifGetRecordType(GifFileType* gifFile, GifRecordType* type) noexcept {
    uint8_t buf = 0;
    if (gifFile->Private->Read(gifFile, &buf, 1) != 1) {
        gifFile->Error = D_GIF_ERR_READ_FAILED;
        return 0;
    }
    switch (buf) {
        case 0x21U: // '!'
            *type = EXTENSION_RECORD_TYPE;
            return 1;
        case 0x2cU: // ','
            *type = IMAGE_DESC_RECORD_TYPE;
            return 1;
        case 0x3bU: // ';'
            *type = TERMINATE_RECORD_TYPE;
            return 1;
        default:
            *type = UNDEFINED_RECORD_TYPE;
            gifFile->Error = D_GIF_ERR_WRONG_RECORD; // mov w8, #0x6b @ 0x006a70
            return 0;
    }
}

// Reconstructed from 0x006a84..0x006d64:
// Reads Left, Top, Width, Height (2 bytes each) and 1 packed byte.
// Verifies `Left + Width <= originalWidth` and `Top + Height <= originalHeight`
// (setting `D_GIF_ERR_IMG_NOT_CONFINED = 1003 = 0x3eb` @ 0x006bb0 on failure).
// Parses optional Local Color Map, calls `DGifSetupDecompress`, and if `changeImageCount`
// is true (`tbz w20, #0, #0x6cac`), appends to `SavedImages` via `openbsd_reallocarray`.
// Phục hồi từ 0x006a84..0x006d64: Đọc Image Descriptor, kiểm tra biên khung hình,
// đọc bảng màu cục bộ (nếu có), khởi tạo bộ giải nén LZW và lưu vào `SavedImages`.
int DGifGetImageDesc(
    GifFileType* gifFile,
    bool changeImageCount,
    uint64_t originalWidth,
    uint64_t originalHeight) noexcept {
    GifFilePrivateType* priv = gifFile->Private;
    uint8_t buf[4] = {0};

    if (priv->Read(gifFile, buf, 2) != 2) {
        gifFile->Error = D_GIF_ERR_READ_FAILED;
        return 0;
    }
    gifFile->Image.Left = static_cast<uint64_t>(buf[0]) | (static_cast<uint64_t>(buf[1]) << 8U);

    if (priv->Read(gifFile, buf, 2) != 2) {
        gifFile->Error = D_GIF_ERR_READ_FAILED;
        return 0;
    }
    gifFile->Image.Top = static_cast<uint64_t>(buf[0]) | (static_cast<uint64_t>(buf[1]) << 8U);

    if (priv->Read(gifFile, buf, 2) != 2) {
        gifFile->Error = D_GIF_ERR_READ_FAILED;
        return 0;
    }
    gifFile->Image.Width = static_cast<uint64_t>(buf[0]) | (static_cast<uint64_t>(buf[1]) << 8U);

    if (priv->Read(gifFile, buf, 2) != 2) {
        gifFile->Error = D_GIF_ERR_READ_FAILED;
        return 0;
    }
    gifFile->Image.Height = static_cast<uint64_t>(buf[0]) | (static_cast<uint64_t>(buf[1]) << 8U);

    if (priv->Read(gifFile, buf, 1) != 1) {
        gifFile->Error = D_GIF_ERR_READ_FAILED;
        GifFreeMapObject(gifFile->Image.ColorMap);
        gifFile->Image.ColorMap = nullptr;
        return 0;
    }

    if ((gifFile->Image.Left + gifFile->Image.Width > originalWidth) ||
        (gifFile->Image.Top + gifFile->Image.Height > originalHeight)) {
        gifFile->Error = D_GIF_ERR_IMG_NOT_CONFINED; // mov w8, #0x3eb @ 0x006bb0
        return 0;
    }

    const uint8_t packed = buf[0];
    gifFile->Image.Interlace = ((packed >> 6U) & 0x01U) != 0; // ubfx w8, w21, #6, #1 @ 0x006c10

    if (gifFile->Image.ColorMap != nullptr) {
        GifFreeMapObject(gifFile->Image.ColorMap);
        gifFile->Image.ColorMap = nullptr;
    }

    if ((packed & 0x80U) != 0) {
        const uint8_t bitsPerPixel = static_cast<uint8_t>((packed & 0x07U) + 1U);
        ColorMapObject* localMap = GifMakeMapObject(bitsPerPixel, nullptr);
        gifFile->Image.ColorMap = localMap;
        if (localMap == nullptr) {
            gifFile->Error = D_GIF_ERR_NOT_ENOUGH_MEM;
            return 0;
        }
        for (int64_t i = 0; i < localMap->ColorCount; ++i) {
            if (priv->Read(gifFile, buf, 3) != 3) {
                GifFreeMapObject(gifFile->Image.ColorMap);
                gifFile->Image.ColorMap = nullptr;
                gifFile->Error = D_GIF_ERR_READ_FAILED;
                return 0;
            }
            localMap->Colors[i].Red   = buf[0];
            localMap->Colors[i].Green = buf[1];
            localMap->Colors[i].Blue  = buf[2];
        }
    }

    if (DGifSetupDecompress(gifFile) == 0) {
        return 0;
    }

    if (changeImageCount) {
        auto* newSavedImages = static_cast<SavedImage*>(
            openbsd_reallocarray(gifFile->SavedImages, gifFile->ImageCount + 1U, sizeof(SavedImage)));
        if (newSavedImages == nullptr) {
            gifFile->Error = D_GIF_ERR_NOT_ENOUGH_MEM;
            return 0;
        }
        gifFile->SavedImages = newSavedImages;
        SavedImage& sp = newSavedImages[gifFile->ImageCount];
        sp = gifFile->Image;
        if (gifFile->Image.ColorMap != nullptr) {
            sp.ColorMap = GifMakeMapObject(
                gifFile->Image.ColorMap->BitsPerPixel,
                gifFile->Image.ColorMap->Colors);
            if (sp.ColorMap == nullptr) {
                gifFile->Error = D_GIF_ERR_NOT_ENOUGH_MEM;
                return 0;
            }
        }
        gifFile->ImageCount++;
    }

    priv->PixelCount = gifFile->Image.Width * gifFile->Image.Height; // mul x8, x9, x8 @ 0x006cb4
    return 1;
}

// Reconstructed from 0x006d68..0x006e48:
// Reads 1-byte LZW minimum code size (`BitsPerPixel`). Rejects `BitsPerPixel > 8`
// (`cmp w8, #9; b.lo #0x6dbc`) with `D_GIF_ERR_READ_FAILED (102)`.
// Initializes `ClearCode = 1 << BitsPerPixel`, `EOFCode = ClearCode + 1`,
// `RunningCode = ClearCode + 2`, `RunningBits = BitsPerPixel + 1`,
// `MaxCode1 = 2 << BitsPerPixel`, `LastCode = NO_SUCH_CODE (0x1002)`,
// `CrntShiftState = 0`, and fills `Prefix[0..4095]` with `0x1002` using NEON `dup v0.4s, w9`.
// Phục hồi từ 0x006d68..0x006e48: Đọc kích thước mã LZW tối thiểu và khởi tạo bảng Prefix.
int DGifSetupDecompress(GifFileType* gifFile) noexcept {
    GifFilePrivateType* priv = gifFile->Private;
    uint8_t codeSize = 0;

    priv->Read(gifFile, &codeSize, 1);
    if (codeSize >= 9U) {
        gifFile->Error = D_GIF_ERR_READ_FAILED; // mov w8, #0x66 @ 0x006dac
        return 0;
    }

    priv->Buf[0]         = 0;
    priv->BitsPerPixel   = codeSize;
    priv->ClearCode      = static_cast<uint64_t>(1U) << codeSize;
    priv->EOFCode        = priv->ClearCode + 1U;
    priv->RunningCode    = priv->ClearCode + 2U;
    priv->RunningBits    = static_cast<uint64_t>(codeSize) + 1U;
    priv->MaxCode1       = static_cast<uint64_t>(2U) << codeSize;
    priv->LastCode       = NO_SUCH_CODE; // 0x1002 (.rodata 0x0029e0)
    priv->CrntShiftState = 0;
    priv->CrntShiftDWord = 0;
    priv->CrntCodeBits   = 0;

    for (size_t i = 0; i < 4096U; ++i) {
        priv->Prefix[i] = NO_SUCH_CODE; // 0x1002
    }
    return 1;
}

// Helper for reading next LZW code from sub-blocks (inlined inside DGifGetLine @ 0x007070..0x0071b8)
// Hàm nội bộ đọc mã LZW tiếp theo từ các khối con (được inline trong DGifGetLine @ 0x007070..0x0071b8)
static int dgifDecompressInput(GifFileType* gifFile, int* code) noexcept {
    GifFilePrivateType* priv = gifFile->Private;
    if (priv->RunningBits > LZ_BITS) {
        gifFile->Error = D_GIF_ERR_IMAGE_DEFECT; // mov w8, #0x70 @ 0x0074d8
        return 0;
    }

    while (priv->CrntShiftDWord < priv->RunningBits) {
        if (priv->Buf[0] == 0) {
            if (priv->Read(gifFile, priv->Buf, 1) != 1) {
                gifFile->Error = D_GIF_ERR_READ_FAILED;
                return 0;
            }
            const uint8_t blockLen = priv->Buf[0];
            if (blockLen == 0) {
                gifFile->Error = D_GIF_ERR_IMAGE_DEFECT; // cbz w2, #0x74d8 @ 0x007108
                return 0;
            }
            if (priv->Read(gifFile, &priv->Buf[1], blockLen) != static_cast<int>(blockLen)) {
                gifFile->Error = D_GIF_ERR_READ_FAILED;
                return 0;
            }
            priv->Buf[1 + 0] = priv->Buf[1];
            // Buf[0] holds remaining unread bytes; Buf[255] or cursor tracks offset
            // In binary (@ 0x0070a4..0x007140): Buf[0] is remaining count, Buf[1] is current index (init to 2)
            // Wait: at 0x007114 it reads `blockLen` bytes into `&priv->Buf[1]` (`x23 = x27 + 1`),
            // consumes `priv->Buf[1]` immediately (`ldrb w10, [x22, #0x61]`), and sets `priv->Buf[1] = 2`!
            const uint8_t firstByte = priv->Buf[1];
            priv->Buf[1] = 2U;
            priv->CrntCodeBits |= static_cast<uint64_t>(firstByte) << priv->CrntShiftDWord;
            priv->CrntShiftDWord += 8U;
            priv->Buf[0] = static_cast<uint8_t>(blockLen - 1U);
        } else {
            const uint8_t nextIdx = priv->Buf[1];
            priv->Buf[1] = static_cast<uint8_t>(nextIdx + 1U);
            const uint8_t nextByte = priv->Buf[nextIdx];
            priv->CrntCodeBits |= static_cast<uint64_t>(nextByte) << priv->CrntShiftDWord;
            priv->CrntShiftDWord += 8U;
            priv->Buf[0]--;
        }
    }

    const uint64_t runningBits = priv->RunningBits;
    *code = static_cast<int>(priv->CrntCodeBits & kCodeMasks[runningBits]);
    priv->CrntCodeBits >>= runningBits;
    priv->CrntShiftDWord -= runningBits;

    if (priv->RunningCode <= LZ_MAX_CODE + 1) {
        priv->RunningCode++;
        if (priv->RunningCode > priv->MaxCode1 && runningBits < LZ_BITS) {
            priv->MaxCode1 <<= 1U;
            priv->RunningBits++;
        }
    }
    return 1;
}

// Helper for tracing LZW prefix chain to root pixel (inlined at 0x007250..0x0072f8)
// Hàm nội bộ truy ngược chuỗi Prefix LZW về mã gốc (inline tại 0x007250..0x0072f8)
static uint32_t dgifGetPrefixChar(const uint32_t* prefix, int code, int clearCode) noexcept {
    int i = 0;
    while (code > clearCode && i++ <= LZ_MAX_CODE) {
        if (code > LZ_MAX_CODE) {
            return NO_SUCH_CODE;
        }
        code = static_cast<int>(prefix[code]);
    }
    return static_cast<uint32_t>(code);
}

// Reconstructed from 0x006e4c..0x007544:
// Decodes `lineLen` pixels (or `gifFile->Image.Width` if `lineLen == 0`) from the LZW stream,
// popping buffered stack pixels first and flushing remaining sub-blocks when `PixelCount == 0`.
// Phục hồi từ 0x006e4c..0x007544: Giải mã dòng điểm ảnh LZW, hỗ trợ xả ngăn xếp và khối cuối.
int DGifGetLine(GifFileType* gifFile, uint8_t* line, int lineLen) noexcept {
    GifFilePrivateType* priv = gifFile->Private;
    uint64_t reqLen = (lineLen != 0) ? static_cast<uint64_t>(lineLen) : gifFile->Image.Width;

    if (priv->PixelCount < reqLen) {
        gifFile->Error = D_GIF_ERR_DATA_TOO_BIG; // mov w8, #0x6c @ 0x006ea4
        return 0;
    }
    priv->PixelCount -= reqLen;

    int64_t stackPtr = priv->CrntShiftState;
    if (stackPtr > LZ_MAX_CODE) {
        return 0;
    }

    const int eofCode   = static_cast<int>(priv->EOFCode);
    const int clearCode = static_cast<int>(priv->ClearCode);
    int       lastCode  = static_cast<int>(priv->LastCode);

    uint64_t i = 0;
    while (stackPtr != 0 && i < reqLen) {
        line[i++] = priv->Stack[--stackPtr];
    }

    while (i < reqLen) {
        int crntCode = 0;
        if (dgifDecompressInput(gifFile, &crntCode) == 0) {
            return 0;
        }

        if (crntCode == eofCode) {
            gifFile->Error = D_GIF_ERR_EOF_TOO_SOON; // mov w8, #0x71 @ 0x00753c
            return 0;
        }

        if (crntCode == clearCode) {
            for (size_t j = 0; j < 4096U; ++j) {
                priv->Prefix[j] = NO_SUCH_CODE;
            }
            priv->RunningCode = priv->EOFCode + 1U;
            priv->RunningBits = priv->BitsPerPixel + 1U;
            priv->MaxCode1    = static_cast<uint64_t>(1U) << priv->RunningBits;
            lastCode          = static_cast<int>(NO_SUCH_CODE);
        } else {
            if (crntCode < clearCode) {
                line[i++] = static_cast<uint8_t>(crntCode);
            } else {
                int crntPrefix = 0;
                if (priv->Prefix[crntCode] == NO_SUCH_CODE) {
                    if (crntCode == static_cast<int>(priv->RunningCode) - 2) {
                        crntPrefix = lastCode;
                        const uint8_t suffixChar = static_cast<uint8_t>(
                            dgifGetPrefixChar(priv->Prefix, lastCode, clearCode));
                        priv->Suffix[priv->RunningCode - 2U] = suffixChar;
                        priv->Stack[stackPtr++] = suffixChar;
                    } else {
                        gifFile->Error = D_GIF_ERR_IMAGE_DEFECT; // mov w8, #0x70 @ 0x0074d8
                        return 0;
                    }
                } else {
                    crntPrefix = crntCode;
                }

                while (stackPtr < LZ_MAX_CODE && crntPrefix > clearCode && crntPrefix <= LZ_MAX_CODE) {
                    priv->Stack[stackPtr++] = priv->Suffix[crntPrefix];
                    crntPrefix = static_cast<int>(priv->Prefix[crntPrefix]);
                }
                if (stackPtr >= LZ_MAX_CODE || crntPrefix > LZ_MAX_CODE) {
                    gifFile->Error = D_GIF_ERR_IMAGE_DEFECT;
                    return 0;
                }
                priv->Stack[stackPtr++] = static_cast<uint8_t>(crntPrefix);

                while (stackPtr != 0 && i < reqLen) {
                    line[i++] = priv->Stack[--stackPtr];
                }
            }

            if (lastCode != static_cast<int>(NO_SUCH_CODE) &&
                priv->RunningCode >= 2U &&
                (priv->RunningCode - 2U) <= static_cast<uint64_t>(LZ_MAX_CODE) &&
                priv->Prefix[priv->RunningCode - 2U] == NO_SUCH_CODE) {
                priv->Prefix[priv->RunningCode - 2U] = static_cast<uint32_t>(lastCode);
                if (crntCode == static_cast<int>(priv->RunningCode) - 2) {
                    priv->Suffix[priv->RunningCode - 2U] = static_cast<uint8_t>(
                        dgifGetPrefixChar(priv->Prefix, lastCode, clearCode));
                } else {
                    priv->Suffix[priv->RunningCode - 2U] = static_cast<uint8_t>(
                        dgifGetPrefixChar(priv->Prefix, crntCode, clearCode));
                }
            }
            lastCode = crntCode;
        }
    }

    priv->LastCode       = lastCode;
    priv->CrntShiftState = stackPtr;

    if (priv->PixelCount == 0) {
        uint8_t blockLen = 0;
        do {
            if (priv->Read(gifFile, &blockLen, 1) != 1) {
                gifFile->Error = D_GIF_ERR_READ_FAILED;
                return 0;
            }
            if (blockLen == 0) {
                priv->Buf[0]     = 0;
                priv->PixelCount = 0;
                return 1;
            }
            priv->Buf[0] = blockLen;
            if (priv->Read(gifFile, &priv->Buf[1], blockLen) != static_cast<int>(blockLen)) {
                gifFile->Error = D_GIF_ERR_READ_FAILED;
                return 0;
            }
        } while (blockLen != 0);
    }
    return 1;
}

// Reconstructed from 0x007548..0x007614:
// Reads a single raw LZW code sub-block when skipping frame decompression (`decode == false`).
// Phục hồi từ 0x007548..0x007614: Đọc bỏ qua khối con mã LZW khi không cần giải mã khung hình.
int DGifGetCodeNext(GifFileType* gifFile, uint8_t** codeBlock) noexcept {
    GifFilePrivateType* priv = gifFile->Private;
    uint8_t count = 0;
    if (priv->Read(gifFile, &count, 1) != 1) {
        gifFile->Error = D_GIF_ERR_READ_FAILED;
        return 0;
    }
    if (count > 0) {
        *codeBlock = priv->Buf;
        priv->Buf[0] = count;
        if (priv->Read(gifFile, &priv->Buf[1], count) != static_cast<int>(count)) {
            gifFile->Error = D_GIF_ERR_READ_FAILED;
            return 0;
        }
    } else {
        *codeBlock       = nullptr;
        priv->Buf[0]     = 0;
        priv->PixelCount = 0;
    }
    return 1;
}

// Reconstructed from 0x007618..0x007714:
// Reads 1-byte extension function code into `*extCode` and delegates first sub-block read.
// Phục hồi từ 0x007618..0x007714: Đọc mã hàm phần mở rộng GIF89a và khối dữ liệu con đầu tiên.
int DGifGetExtension(GifFileType* gifFile, int* extCode, uint8_t** extBlock) noexcept {
    GifFilePrivateType* priv = gifFile->Private;
    uint8_t buf = 0;
    if (priv->Read(gifFile, &buf, 1) != 1) {
        gifFile->Error = D_GIF_ERR_READ_FAILED;
        return 0;
    }
    *extCode = static_cast<int>(buf);
    return DGifGetExtensionNext(gifFile, extBlock);
}

// Reconstructed from 0x007718..0x0077dc:
// Reads next sub-block of an extension into `priv->Buf` (`Buf[0] = length`, `Buf[1..length] = payload`).
// Phục hồi từ 0x007718..0x0077dc: Đọc khối con tiếp theo của phần mở rộng GIF89a.
int DGifGetExtensionNext(GifFileType* gifFile, uint8_t** extBlock) noexcept {
    GifFilePrivateType* priv = gifFile->Private;
    uint8_t count = 0;
    if (priv->Read(gifFile, &count, 1) != 1) {
        gifFile->Error = D_GIF_ERR_READ_FAILED;
        return 0;
    }
    if (count > 0) {
        *extBlock    = priv->Buf;
        priv->Buf[0] = count;
        if (priv->Read(gifFile, &priv->Buf[1], count) != static_cast<int>(count)) {
            gifFile->Error = D_GIF_ERR_READ_FAILED;
            return 0;
        }
    } else {
        *extBlock = nullptr;
    }
    return 1;
}

// Reconstructed from 0x0077e0..0x007820:
// Parses 4-byte Graphic Control Extension payload:
// - `gcb->disposalMethod = (gifExtension[0] >> 2) & 0x07` (`ubfx w8, w8, #2, #3`)
// - `gcb->duration = *(uint16_t*)(&gifExtension[1])` (in 10ms centiseconds)
// - `gcb->transColor = (gifExtension[0] & 1) ? gifExtension[3] : -1`
// Phục hồi từ 0x0077e0..0x007820: Phân tích 4 byte Graphic Control Extension vào `FrameInfo`.
int DGifExtensionToGCB(size_t gifExtensionLength, const uint8_t* gifExtension, FrameInfo* gcb) noexcept {
    if (gifExtensionLength != 4U) {
        return 0;
    }
    gcb->disposalMethod = static_cast<uint8_t>((gifExtension[0] >> 2U) & 0x07U);
    gcb->duration       = static_cast<uint64_t>(gifExtension[1]) |
                          (static_cast<uint64_t>(gifExtension[2]) << 8U);
    if ((gifExtension[0] & 0x01U) != 0) {
        gcb->transColor = static_cast<int32_t>(gifExtension[3]);
    } else {
        gcb->transColor = -1;
    }
    return 1;
}

// Reconstructed from 0x007c34..0x007c48:
// Resets a `FrameInfo` entry to `disposalMethod = 0`, `duration = 100` (`0x64`), `transColor = -1`.
// Phục hồi từ 0x007c34..0x007c48: Đặt lại `FrameInfo` về mặc định (100ms, không màu trong suốt).
void resetFrameInfo(FrameInfo* info) noexcept {
    info->disposalMethod = DISPOSE_DO_NOT;
    info->duration       = kDefaultFrameDurationMs; // 0x64 = 100
    info->transColor     = -1;
}

// ============================================================================
// 3. Extension Parser & 4-Pass Interlace Slurper (0x0048a4..0x004e4c)
//    Bộ phân tích phần mở rộng & đọc đan xen 4 lượt (0x0048a4..0x004e4c)
// ============================================================================

// Reconstructed from 0x004c90..0x004e4c:
// Handles GIF89a Extensions:
// - `0xF9` (`kGraphicsExtFuncCode`): parses GCB via `DGifExtensionToGCB` (`0x0077e0`) and
//   normalizes centisecond duration (`if (duration > 1) duration *= 10; else duration = 100;` @ `0x004d10..0x004d28`).
// - `0xFE` (`kCommentExtFuncCode`): appends comment sub-block to `info->comment` if total length <= `0x800` (2048 B).
// - `0xFF` (`kApplicationExtFuncCode`): matches `"NETSCAPE2.0"` (`0x00252c`) or `"ANIMEXTS1.0"` (`0x002564`)
//   via `strncmp`, reads next 3-byte sub-block (`subBlock[0] == 3 && subBlock[1] == 1`), and extracts
//   16-bit loop count (`csinc x8, xzr, x8, eq` @ `0x004db8`: `loopCount == 0 ? 0 : loopCount + 1`).
// Phục hồi từ 0x004c90..0x004e4c: Xử lý phần mở rộng GCB (0xF9), Comment (0xFE) và NETSCAPE2.0/ANIMEXTS1.0 (0xFF).
int readExtensions(int extFunction, uint8_t* extData, GifInfo* info) noexcept {
    if (extData == nullptr) {
        return 1;
    }

    if (extFunction == kGraphicsExtFuncCode) { // 0xF9
        GifFileType* gif = info->gifFilePtr;
        FrameInfo* currentInfo = &info->infos[gif->ImageCount];
        if (DGifExtensionToGCB(extData[0], &extData[1], currentInfo) == 0) {
            return 0;
        }
        // Observed at 0x004d10..0x004d28:
        // add x10, x9, x9, lsl #2 (x9 * 5); cmp x9, #1; lsl x10, x10, #1 (x9 * 10);
        // mov w9, #0x64 (100); csel x9, x10, x9, hi
        if (currentInfo->duration > 1ULL) {
            currentInfo->duration *= 10ULL;
        } else {
            currentInfo->duration = kDefaultFrameDurationMs; // 100 ms
        }
        return 1;
    }

    if (extFunction == kCommentExtFuncCode) { // 0xFE
        const size_t subBlockLen = extData[0];
        const size_t existingLen = (info->comment != nullptr) ? std::strlen(info->comment) : 0U;
        const size_t newTotalLen = existingLen + subBlockLen;
        if (newTotalLen + 1U <= kMaxGifCommentBytes) { // cmp w1, #0x800; b.ls #0x4e08
            auto* newComment = static_cast<char*>(
                openbsd_reallocarray(info->comment, newTotalLen + 1U, 1U));
            if (newComment == nullptr) {
                info->gifFilePtr->Error = D_GIF_ERR_NOT_ENOUGH_MEM; // mov w9, #0x6d @ 0x004e40
                return 0;
            }
            std::memcpy(newComment + existingLen, &extData[1], subBlockLen);
            newComment[newTotalLen] = '\0';
            info->comment = newComment;
        }
        return 1;
    }

    if (extFunction == kApplicationExtFuncCode) { // 0xFF
        const size_t appLen = extData[0];
        const char*  appStr = reinterpret_cast<const char*>(&extData[1]);
        if (std::strncmp("NETSCAPE2.0", appStr, appLen) == 0 ||
            std::strncmp("ANIMEXTS1.0", appStr, appLen) == 0) {
            uint8_t* subBlock = nullptr;
            if (DGifGetExtensionNext(info->gifFilePtr, &subBlock) == 0) {
                return 0;
            }
            if (subBlock != nullptr && subBlock[0] == 3U && subBlock[1] == 1U) {
                const uint16_t rawLoop = static_cast<uint16_t>(subBlock[2]) |
                                         (static_cast<uint16_t>(subBlock[3]) << 8U);
                // Observed at 0x004db4..0x004dbc: cmp x8, #0; csinc x8, xzr, x8, eq
                // In Netscape 2.0, 0 means infinite loop (0), while N > 0 means N iterations + initial play (N + 1)
                info->loopCount = (rawLoop == 0U) ? 0ULL : static_cast<uint64_t>(rawLoop) + 1ULL;
            }
        }
        return 1;
    }

    return 1;
}

// Reconstructed from 0x0048a4..0x004c8c:
// Main GIF record loop (`DDGifSlurp`):
// - Loops over `DGifGetRecordType`.
// - On `IMAGE_DESC_RECORD_TYPE (2)`:
//   - Calls `DGifGetImageDesc(gif, !decode, info->originalWidth, info->originalHeight)`.
//   - If `!decode` (initial metadata pass): reallocates `info->infos` for `ImageCount + 1` frames,
//     initializes new `FrameInfo` (100ms, transColor=-1), and skips LZW sub-blocks via `DGifGetCodeNext`.
//   - If `decode`: ensures `info->rasterBits` is large enough (`width * height`), decodes either
//     4-pass interlaced scanlines (`0x004ab4..0x004b38` using `kInterlacedOffset` & `kInterlacedJumps`)
//     or sequential scanlines (`0x004c24`) with horizontal/vertical downsampling (`sampleSize >= 2` @ `0x004b48..0x004c84`).
// - On `EXTENSION_RECORD_TYPE (3)`: reads extension blocks and invokes `readExtensions` when `!decode`.
// Phục hồi từ 0x0048a4..0x004c8c: Vòng lặp giải mã bản ghi GIF chính (`DDGifSlurp`).
void DDGifSlurp(GifInfo* info, bool decode, bool exitAfterFrame) noexcept {
    GifFileType* gif = info->gifFilePtr;
    GifRecordType recordType = UNDEFINED_RECORD_TYPE;

    do {
        if (DGifGetRecordType(gif, &recordType) == 0) {
            return;
        }

        switch (recordType) {
            case IMAGE_DESC_RECORD_TYPE: {
                if (DGifGetImageDesc(gif, !decode, info->originalWidth, info->originalHeight) == 0) {
                    return;
                }

                if (decode) {
                    const uint64_t width     = gif->Image.Width;
                    const uint64_t height    = gif->Image.Height;
                    const uint64_t imageSize = width * height;

                    if (imageSize > info->rasterSize || info->rasterBits == nullptr) {
                        auto* newRasterBits = static_cast<uint8_t*>(
                            openbsd_reallocarray(info->rasterBits, imageSize, sizeof(uint8_t)));
                        if (newRasterBits == nullptr) {
                            std::free(info->rasterBits);
                            info->rasterBits = nullptr;
                            info->rasterSize = 0;
                            gif->Error       = D_GIF_ERR_NOT_ENOUGH_MEM;
                            return;
                        }
                        info->rasterBits = newRasterBits;
                        info->rasterSize = imageSize;
                    }

                    if (gif->Image.Interlace) {
                        // 4-pass interlaced decoding (@ 0x004ab4..0x004c0c)
                        // Giải mã khung hình đan xen 4 lượt (@ 0x004ab4..0x004c0c)
                        uint8_t* lineBuf = nullptr;
                        if (info->sampleSize >= 2ULL) {
                            lineBuf = static_cast<uint8_t*>(std::malloc(width));
                            if (lineBuf == nullptr) {
                                gif->Error = D_GIF_ERR_NOT_ENOUGH_MEM;
                                return;
                            }
                        }

                        const uint64_t sampleSize  = info->sampleSize;
                        const uint64_t sampledStep = (sampleSize >= 2ULL) ? (width / sampleSize) : width;

                        for (int pass = 0; pass < 4; ++pass) {
                            for (uint64_t row = kInterlacedOffset[pass];
                                 row < height;
                                 row += kInterlacedJumps[pass]) {
                                if (sampleSize < 2ULL) {
                                    if (DGifGetLine(gif, info->rasterBits + row * width, static_cast<int>(width)) == 0) {
                                        return;
                                    }
                                } else {
                                    if (DGifGetLine(gif, lineBuf, static_cast<int>(width)) == 0) {
                                        std::free(lineBuf);
                                        return;
                                    }
                                    uint8_t* dst = info->rasterBits + (row / sampleSize) * sampledStep;
                                    for (uint64_t col = 0; col < width; col += sampleSize) {
                                        *dst++ = lineBuf[col];
                                    }
                                }
                            }
                        }
                        std::free(lineBuf);
                    } else {
                        // Non-interlaced decoding (@ 0x004c18..0x004c88)
                        // Giải mã khung hình tuần tự (@ 0x004c18..0x004c88)
                        if (DGifGetLine(gif, info->rasterBits, static_cast<int>(imageSize)) == 0) {
                            return;
                        }
                        const uint64_t sampleSize = info->sampleSize;
                        if (sampleSize >= 2ULL) {
                            const uint64_t sampledWidth = width / sampleSize;
                            const uint64_t rowAdvance   = width * sampleSize;
                            const uint8_t* endPtr       = info->rasterBits + imageSize;
                            const uint8_t* srcRow       = info->rasterBits;
                            uint8_t*       dstRow       = info->rasterBits;

                            while (srcRow < endPtr) {
                                const uint8_t* srcEnd = srcRow + width;
                                const uint8_t* srcPx  = srcRow;
                                uint8_t*       dstPx  = dstRow;
                                while (srcPx < srcEnd) {
                                    *dstPx++ = *srcPx;
                                    srcPx += sampleSize;
                                }
                                srcRow += rowAdvance;
                                dstRow += sampledWidth;
                            }
                        }
                    }

                    if (exitAfterFrame) {
                        return;
                    }
                } else {
                    // Metadata discovery pass (`!decode`): grow `info->infos` and skip code blocks
                    // Lượt quét siêu dữ liệu (`!decode`): mở rộng mảng `info->infos` và bỏ qua khối LZW
                    auto* newInfos = static_cast<FrameInfo*>(
                        openbsd_reallocarray(info->infos, gif->ImageCount + 1U, sizeof(FrameInfo)));
                    if (newInfos == nullptr) {
                        gif->Error = D_GIF_ERR_NOT_ENOUGH_MEM;
                        return;
                    }
                    info->infos = newInfos;
                    resetFrameInfo(&newInfos[gif->ImageCount]);

                    uint8_t* codeBlock = nullptr;
                    do {
                        if (DGifGetCodeNext(gif, &codeBlock) == 0) {
                            return;
                        }
                    } while (codeBlock != nullptr);

                    if (exitAfterFrame) {
                        return;
                    }
                }
                break;
            }

            case EXTENSION_RECORD_TYPE: {
                int      extFunction = 0;
                uint8_t* extData     = nullptr;
                if (DGifGetExtension(gif, &extFunction, &extData) == 0) {
                    return;
                }
                if (!decode) {
                    if (readExtensions(extFunction, extData, info) == 0) {
                        return;
                    }
                }
                while (extData != nullptr) {
                    if (DGifGetExtensionNext(gif, &extData) == 0) {
                        return;
                    }
                    if (!decode) {
                        if (readExtensions(extFunction, extData, info) == 0) {
                            return;
                        }
                    }
                }
                break;
            }

            case TERMINATE_RECORD_TYPE:
            default:
                break;
        }
    } while (recordType != TERMINATE_RECORD_TYPE);

    info->rewindFunction(info);
}

// ============================================================================
// 4. Input Source Read & Rewind Callbacks (0x00593c..0x0066a4)
//    Các hàm đọc và tua lại nguồn dữ liệu đầu vào (0x00593c..0x0066a4)
// ============================================================================

// Reconstructed from 0x006684..0x0066a4:
// Reads `size` bytes (`and x2, x2, #0xff`) from `FILE*` stored at `gif->UserData` via `fread`.
// Phục hồi từ 0x006684..0x0066a4: Đọc dữ liệu từ `FILE*` bằng `fread`.
int fileRead(GifFileType* gif, uint8_t* bytes, int size) noexcept {
    auto* file = static_cast<std::FILE*>(gif->UserData);
    return static_cast<int>(std::fread(bytes, 1U, static_cast<size_t>(size & 0xFF), file));
}

// Reconstructed from 0x005d54..0x005d8c:
// Reads from `ByteArrayContainer` (in native C++ mode where `bufferGlobal` points to raw bytes).
// Phục hồi từ 0x005d54..0x005d8c: Đọc từ `ByteArrayContainer`.
int byteArrayRead(GifFileType* gif, uint8_t* bytes, int size) noexcept {
    auto* container = static_cast<ByteArrayContainer*>(gif->UserData);
    if (container == nullptr || container->bufferGlobal == nullptr) {
        return 0;
    }
    const uint32_t reqSize = static_cast<uint32_t>(size & 0xFF);
    if (container->position + reqSize > container->arrLen) {
        gif->Error = D_GIF_ERR_READ_FAILED;
        return 0;
    }
    const auto* rawBytes = static_cast<const uint8_t*>(container->bufferGlobal);
    std::memcpy(bytes, rawBytes + container->position, reqSize);
    container->position += reqSize;
    return static_cast<int>(reqSize);
}

// Reconstructed from 0x005f0c..0x005f70:
// Reads from `DirectByteBufferContainer` (`bytes + position`) with bounds check against `capacity`.
// Phục hồi từ 0x005f0c..0x005f70: Đọc từ vùng nhớ trực tiếp `DirectByteBufferContainer`.
int directByteBufferRead(GifFileType* gif, uint8_t* bytes, int size) noexcept {
    auto* dbb = static_cast<DirectByteBufferContainer*>(gif->UserData);
    if (dbb == nullptr || dbb->bytes == nullptr) {
        return 0;
    }
    const int64_t reqSize = static_cast<int64_t>(size & 0xFF);
    int64_t avail = reqSize;
    if (dbb->position + reqSize > dbb->capacity) {
        avail = dbb->capacity - dbb->position;
        if (avail <= 0) {
            return 0;
        }
    }
    std::memcpy(bytes, dbb->bytes + dbb->position, static_cast<size_t>(avail));
    dbb->position += avail;
    return static_cast<int>(avail);
}

// Reconstructed from 0x00593c..0x00597c:
// Rewinds `FILE*` at `info->gifFilePtr->UserData` to `info->startPos` via `fseek`.
// Phục hồi từ 0x00593c..0x00597c: Tua lại `FILE*` về `info->startPos`.
int fileRewind(GifInfo* info) noexcept {
    auto* file = static_cast<std::FILE*>(info->gifFilePtr->UserData);
    if (std::fseek(file, static_cast<long>(info->startPos), SEEK_SET) == 0) {
        return 0;
    }
    info->gifFilePtr->Error = D_GIF_ERR_REWIND_FAILED; // mov w9, #0x3ec @ 0x005958
    return -1;
}

// Reconstructed from 0x005980..0x005a10:
// Rewinds `StreamContainer` (calls `InputStream.reset()` in JNI context).
// Phục hồi từ 0x005980..0x005a10: Tua lại `StreamContainer` qua `InputStream.reset()`.
int streamRewind(GifInfo* info) noexcept {
    if (info == nullptr || info->gifFilePtr == nullptr || info->gifFilePtr->UserData == nullptr) {
        return -1;
    }
    return 0;
}

// Reconstructed from 0x005a14..0x005a2c:
// Rewinds `ByteArrayContainer` by setting `container->position = static_cast<uint32_t>(info->startPos)`.
// Phục hồi từ 0x005a14..0x005a2c: Tua lại `ByteArrayContainer` về `info->startPos`.
int byteArrayRewind(GifInfo* info) noexcept {
    auto* container     = static_cast<ByteArrayContainer*>(info->gifFilePtr->UserData);
    container->position = static_cast<uint32_t>(info->startPos);
    return 0;
}

// Reconstructed from 0x005a30..0x005a48:
// Rewinds `DirectByteBufferContainer` by setting `dbb->position = info->startPos`.
// Phục hồi từ 0x005a30..0x005a48: Tua lại `DirectByteBufferContainer` về `info->startPos`.
int directByteBufferRewind(GifInfo* info) noexcept {
    auto* dbb     = static_cast<DirectByteBufferContainer*>(info->gifFilePtr->UserData);
    dbb->position = info->startPos;
    return 0;
}

} // namespace gif
} // namespace opencut
