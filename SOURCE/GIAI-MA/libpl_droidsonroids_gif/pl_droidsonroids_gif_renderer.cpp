// ============================================================================
// File: pl_droidsonroids_gif_renderer.cpp
// Target: libpl_droidsonroids_gif.so (42,464 bytes, ELF64 AArch64)
// Package: com.nextai.opencut (NextAI OpenCut Reconstruction)
// Task ID: TASK-096-RECONSTRUCTION-LIBPL_DROIDSONROIDS_GIF (TASK_SO_039)
// Evidence Classification: OBSERVED (Direct AArch64 Disassembly 0x004094..0x009680)
// Description (EN): Complete C++17 implementation of the ARGB8888 canvas
//                   renderer, GIF89a disposal engine, frame seeking/resetting,
//                   monotonic clock delay math (0x431bde82d7b634db magic
//                   multiplier), OpenGL ES 2.0 texture descriptor engine, and
//                   memory accounting methods.
// Mô tả (VN): Bản cài đặt C++17 đầy đủ của bộ kết xuất khung vẽ ARGB8888,
//             bộ xử lý xóa khung hình GIF89a, tua/đặt lại khung hình, toán học
//             tính độ trễ đồng hồ đơn điệu (hằng số nhân 0x431bde82d7b634db),
//             bộ mô tả kết cấu OpenGL ES 2.0 và các phương thức kiểm kê bộ nhớ.
// ============================================================================

#include "pl_droidsonroids_gif_renderer.h"
#include "pl_droidsonroids_gif_dgiff_decoder.h"

#include <chrono>
#include <cstdlib>
#include <cstring>

namespace opencut {
namespace gif {

// ============================================================================
// 1. Monotonic Clock & Invalidation Delay Math (0x009548..0x009680)
//    Đồng hồ đơn điệu & Toán học tính độ trễ làm mới (0x009548..0x009680)
// ============================================================================

// Reconstructed from 0x00964c..0x00966c (and 0x0095a4..0x0095cc):
// Exact AArch64 signed 64-bit high-multiply division by 1,000,000:
//   mov   x10, #0x34db
//   movk  x10, #0xd7b6, lsl #16
//   movk  x10, #0xde82, lsl #32
//   movk  x10, #0x431b, lsl #48   // x10 = 0x431bde82d7b634db
//   smulh x9, x9, x10
//   mov   w10, #0x3e8             // 1000
//   asr   x11, x9, #0x12          // >> 18
//   add   x9, x11, x9, lsr #63    // sign-bit rounding adjustment
//   madd  x0, x8, x10, x9         // tv_sec * 1000 + (tv_nsec / 1000000)
// Phục hồi từ 0x00964c..0x00966c: Phép chia có dấu 64-bit cho 1.000.000 bằng `smulh`.
int64_t timespecToMsExact(int64_t tv_sec, int64_t tv_nsec) noexcept {
#if defined(__SIZEOF_INT128__)
    const __int128 prod = static_cast<__int128>(tv_nsec) * static_cast<__int128>(kNsToMsMagicMultiplier);
    const int64_t  smulh_val = static_cast<int64_t>(prod >> 64);
    const int64_t  asr18     = smulh_val >> kNsToMsRightShift;
    const int64_t  sign_bit  = static_cast<int64_t>(static_cast<uint64_t>(smulh_val) >> 63U);
    const int64_t  nsec_ms   = asr18 + sign_bit;
    return tv_sec * kSecToMsMultiplier + nsec_ms;
#else
    return tv_sec * kSecToMsMultiplier + (tv_nsec / 1000000LL);
#endif
}

// Reconstructed from 0x009610..0x009680:
// Calls `clock_gettime(CLOCK_MONOTONIC_RAW = 4, &ts)` and converts to milliseconds.
// Phục hồi từ 0x009610..0x009680: Đọc đồng hồ đơn điệu và chuyển sang mili-giây.
int64_t getRealTime() noexcept {
    const auto now = std::chrono::steady_clock::now().time_since_epoch();
    const auto sec = std::chrono::duration_cast<std::chrono::seconds>(now);
    const auto nsec = std::chrono::duration_cast<std::chrono::nanoseconds>(now - sec);
    return timespecToMsExact(sec.count(), nsec.count());
}

// Reconstructed from 0x009548..0x00960c:
// If `frameDuration == 0`, returns `-1`.
// Scales `frameDuration` by `1.0f / info->speedFactor` (`fdiv s0, s1, s0; fcvtzs x21, s0` @ `0x00958c..0x009590`)
// when `info->speedFactor != 1.0f`, subtracts elapsed decoding time `(getRealTime() - renderStartTime)`,
// clamps to `0` if negative (`csel x0, x8, xzr, gt` @ `0x0095d4`), updates
// `info->nextStartTime = renderStartTime + delay` (`str x8, [x20, #0x30]` @ `0x0095dc`), and returns `delay`.
// Phục hồi từ 0x009548..0x00960c: Tính độ trễ hiển thị khung hình tiếp theo theo `speedFactor`.
int64_t calculateInvalidationDelay(
    GifInfo* info,
    int64_t renderStartTime,
    uint64_t frameDuration) noexcept {
    if (frameDuration == 0ULL) {
        return -1LL; // cbz x2, #0x95e4 -> mov x0, #-1
    }

    int64_t scaledDuration = static_cast<int64_t>(frameDuration);
    if (info->speedFactor != 1.0f && info->speedFactor > 0.0f) {
        scaledDuration = static_cast<int64_t>(static_cast<float>(scaledDuration) / info->speedFactor);
    }

    const int64_t currentTime = getRealTime();
    const int64_t elapsed     = currentTime - renderStartTime;
    int64_t       delay       = scaledDuration - elapsed;
    if (delay <= 0LL) {
        delay = 0LL;
    }

    info->nextStartTime = renderStartTime + delay;
    return delay;
}

// ============================================================================
// 2. ARGB8888 Canvas Preparation, Disposal & Blit Engine (0x005030..0x0055f4)
//    Chuẩn bị khung vẽ ARGB8888, Xóa khung hình & Vẽ điểm ảnh (0x005030..0x0055f4)
// ============================================================================

// Reconstructed from 0x005030..0x00511c:
// At frame 0 (`currentIndex == 0`), if `gifFilePtr->SColorMap != nullptr` and
// `info->infos[0].transColor == -1` (`cmn w11, #1; b.eq #0x5094`), fills the entire
// `stride * SHeight` canvas with `SColorMap->Colors[SBackGroundColor]` (alpha = `0xFF`).
// Otherwise zeroes the canvas via `memset(bm, 0, stride * SHeight * 4)` (`0x00507c..0x005090`).
// Phục hồi từ 0x005030..0x00511c: Khởi tạo khung vẽ ở khung hình đầu tiên.
void prepareCanvas(argb* bm, GifInfo* info) noexcept {
    GifFileType* gif = info->gifFilePtr;
    if (gif->SColorMap != nullptr && info->infos[0].transColor == -1) {
        const uint64_t bgIndex = gif->SBackGroundColor;
        const GifColorType bgRgb = gif->SColorMap->Colors[bgIndex];
        const uint64_t totalPixels = gif->SHeight * static_cast<uint64_t>(info->stride);
        for (uint64_t i = 0; i < totalPixels; ++i) {
            bm[i].r = bgRgb.Red;
            bm[i].g = bgRgb.Green;
            bm[i].b = bgRgb.Blue;
            bm[i].a = 0xFFU;
        }
    } else {
        const size_t totalBytes = static_cast<size_t>(gif->SHeight) *
                                  static_cast<size_t>(info->stride) * sizeof(argb);
        std::memset(bm, 0, totalBytes);
    }
}

// Reconstructed from 0x005120..0x0054b0:
// Performs 3-stage GIF89a frame compositing on `bm`:
// 1. Previous frame disposal (`currentIndex > 0` @ `0x005144..0x00527c`):
//    - Allocates `info->backupPtr` (`calloc(stride * SHeight, 4)`) if `prevDisposal == 3` or `currDisposal == 3`.
//    - Checks whether the current frame completely covers the previous frame with no transparency
//      (`currTransColor == -1 && curr.Left <= prev.Left && curr.Left + curr.Width >= prev.Left + prev.Width &&
//        curr.Top <= prev.Top && curr.Top + curr.Height >= prev.Top + prev.Height` @ `0x0051a0..0x0051fc`).
//    - If not covered:
//      - If `prevDisposal == DISPOSE_BACKGROUND (2)` or `(currentIndex == 1 && prevDisposal == DISPOSE_PREVIOUS (3))`,
//        clears the previous frame's sub-rectangle to transparent black (`memset(row, 0, prev.Width * 4)` @ `0x005240..0x00527c`).
//      - Else if `prevDisposal == DISPOSE_PREVIOUS (3)`, restores `bm` from `info->backupPtr` (`memcpy` @ `0x005220..0x00523c`).
// 2. Current frame backup (`currDisposal == DISPOSE_PREVIOUS (3)` @ `0x005280..0x0052a0`):
//    - Copies `bm` into `info->backupPtr` (`memcpy(backupPtr, bm, stride * SHeight * 4)`).
// 3. Palette lookup & Blit (`0x0052a4..0x0054b0`):
//    - Selects `ColorMap` from `SavedImages[currentIndex].ColorMap`, else `gif->SColorMap`, else `getDefColorMap()`.
//    - Blits `width * height` pixels from `info->rasterBits` into `bm` at `(Left, Top)` using one of 4 specialized loops
//      branched on `(info->isOpaque, currTransColor == -1)` (@ `0x005330..0x0054b0`).
// Phục hồi từ 0x005120..0x0054b0: Kết hợp khung hình GIF89a 3 giai đoạn (xóa khung cũ, sao lưu, vẽ điểm ảnh).
void drawFrame(argb* bm, GifInfo* info) noexcept {
    GifFileType*   gif          = info->gifFilePtr;
    const uint64_t currentIndex = info->currentIndex;

    if (currentIndex > 0ULL) {
        const FrameInfo& prevInfo = info->infos[currentIndex - 1ULL];
        const FrameInfo& currInfo = info->infos[currentIndex];
        const uint8_t prevDisposal = prevInfo.disposalMethod;
        const uint8_t currDisposal = currInfo.disposalMethod;

        if ((prevDisposal == DISPOSE_PREVIOUS || currDisposal == DISPOSE_PREVIOUS) &&
            info->backupPtr == nullptr) {
            info->backupPtr = static_cast<argb*>(
                std::calloc(gif->SHeight * static_cast<uint64_t>(info->stride), sizeof(argb)));
            if (info->backupPtr == nullptr) {
                gif->Error = D_GIF_ERR_NOT_ENOUGH_MEM; // mov w8, #0x6d @ 0x00544c
                return;
            }
        }

        const SavedImage& prevImage = gif->SavedImages[currentIndex - 1ULL];
        const SavedImage& currImage = gif->SavedImages[currentIndex];

        const bool currCoversPrev =
            (currInfo.transColor == -1) &&
            (currImage.Left <= prevImage.Left) &&
            (currImage.Left + currImage.Width >= prevImage.Left + prevImage.Width) &&
            (currImage.Top <= prevImage.Top) &&
            (currImage.Top + currImage.Height >= prevImage.Top + prevImage.Height);

        if (!currCoversPrev) {
            if (prevDisposal == DISPOSE_BACKGROUND ||
                (currentIndex == 1ULL && prevDisposal == DISPOSE_PREVIOUS)) {
                if (prevImage.Height > 0ULL) {
                    argb* dstRow = bm + (prevImage.Top * static_cast<uint64_t>(info->stride)) + prevImage.Left;
                    const size_t rowBytes = static_cast<size_t>(prevImage.Width) * sizeof(argb);
                    for (uint64_t row = 0; row < prevImage.Height; ++row) {
                        std::memset(dstRow, 0, rowBytes);
                        dstRow += info->stride;
                    }
                }
            } else if (prevDisposal == DISPOSE_PREVIOUS && info->backupPtr != nullptr) {
                const size_t canvasBytes = static_cast<size_t>(info->stride) *
                                           static_cast<size_t>(gif->SHeight) * sizeof(argb);
                std::memcpy(bm, info->backupPtr, canvasBytes);
            }
        }

        if (currDisposal == DISPOSE_PREVIOUS && info->backupPtr != nullptr) {
            const size_t canvasBytes = static_cast<size_t>(info->stride) *
                                       static_cast<size_t>(gif->SHeight) * sizeof(argb);
            std::memcpy(info->backupPtr, bm, canvasBytes);
        }
    }

    const SavedImage& curSaved = gif->SavedImages[info->currentIndex];
    ColorMapObject* colorMap = curSaved.ColorMap;
    if (colorMap == nullptr) {
        colorMap = gif->SColorMap;
        if (colorMap == nullptr) {
            colorMap = getDefColorMap(); // bl #0x8098 @ 0x0052cc
        }
    }

    const uint8_t* rasterBits = info->rasterBits;
    if (rasterBits == nullptr) {
        return;
    }

    const uint64_t width  = curSaved.Width;
    const uint64_t height = curSaved.Height;
    if (info->rasterSize < width * height) {
        return;
    }

    const uint64_t left       = curSaved.Left;
    const uint64_t top        = curSaved.Top;
    const uint32_t stride     = info->stride;
    const uint64_t rowPadding = static_cast<uint64_t>(stride) - width;
    const int32_t  transColor = info->infos[info->currentIndex].transColor;
    const GifColorType* colors = colorMap->Colors;

    argb* dst = bm + (top * static_cast<uint64_t>(stride)) + left;
    const uint8_t* src = rasterBits;

    if (info->isOpaque) {
        if (transColor == -1) {
            // Branch @ 0x005404..0x005448: Opaque, no transparent color
            for (uint64_t y = 0; y < height; ++y) {
                for (uint64_t x = 0; x < width; ++x) {
                    const uint8_t idx = *src++;
                    dst->r = colors[idx].Red;
                    dst->g = colors[idx].Green;
                    dst->b = colors[idx].Blue;
                    ++dst;
                }
                dst += rowPadding;
            }
        } else {
            // Branch @ 0x005340..0x005398: Opaque, skip transparent color
            for (uint64_t y = 0; y < height; ++y) {
                for (uint64_t x = 0; x < width; ++x) {
                    const uint8_t idx = *src++;
                    if (static_cast<int32_t>(idx) != transColor) {
                        dst->r = colors[idx].Red;
                        dst->g = colors[idx].Green;
                        dst->b = colors[idx].Blue;
                    }
                    ++dst;
                }
                dst += rowPadding;
            }
        }
    } else {
        if (transColor == -1) {
            // Branch @ 0x005458..0x0054b0: Non-opaque, no transparent color (memset row to 0xFF then write RGB)
            for (uint64_t y = 0; y < height; ++y) {
                std::memset(dst, 0xFF, static_cast<size_t>(width) * sizeof(argb));
                for (uint64_t x = 0; x < width; ++x) {
                    const uint8_t idx = *src++;
                    dst->r = colors[idx].Red;
                    dst->g = colors[idx].Green;
                    dst->b = colors[idx].Blue;
                    ++dst;
                }
                dst += rowPadding;
            }
        } else {
            // Branch @ 0x0053a0..0x005400: Non-opaque, with transparent color (alpha = 0xFF on non-transparent)
            for (uint64_t y = 0; y < height; ++y) {
                for (uint64_t x = 0; x < width; ++x) {
                    const uint8_t idx = *src++;
                    if (static_cast<int32_t>(idx) != transColor) {
                        dst->r = colors[idx].Red;
                        dst->g = colors[idx].Green;
                        dst->b = colors[idx].Blue;
                        dst->a = 0xFFU;
                    }
                    ++dst;
                }
                dst += rowPadding;
            }
        }
    }
}

// Reconstructed from 0x0054b4..0x005550:
// Reads `duration = info->infos[info->currentIndex].duration`, increments `info->currentIndex`,
// and if `currentIndex >= gif->ImageCount`, checks `loopCount` / `currentLoop`, rewinds stream
// via `info->rewindFunction(info)`, and wraps `currentIndex` back to `0`.
// Phục hồi từ 0x0054b4..0x005550: Trả về thời lượng khung hình hiện tại và cập nhật chỉ số khung/vòng lặp.
uint64_t getFrameDuration(GifInfo* info) noexcept {
    const uint64_t currentIndex = info->currentIndex;
    uint64_t duration = info->infos[currentIndex].duration;
    const uint64_t nextIndex = currentIndex + 1ULL;
    info->currentIndex = nextIndex;

    if (nextIndex >= info->gifFilePtr->ImageCount) {
        if (info->loopCount != 0ULL) {
            if (info->currentLoop + 1ULL >= info->loopCount) {
                info->currentLoop++;
                return 0ULL;
            }
        }
        if (info->rewindFunction(info) != 0) {
            return 0ULL;
        }
        if (info->loopCount != 0ULL) {
            info->currentLoop++;
        }
        info->currentIndex = 0ULL;
    }
    return duration;
}

// Reconstructed from 0x005554..0x0055f4:
// Calls `drawFrame(bm, info)` (`bl #0x5120`) followed by `getFrameDuration(info)`.
// Phục hồi từ 0x005554..0x0055f4: Vẽ khung hình hiện tại và trả về thời lượng khung hình.
uint64_t drawNextBitmap(argb* bm, GifInfo* info) noexcept {
    drawFrame(bm, info);
    return getFrameDuration(info);
}

// ============================================================================
// 3. GifInfo Lifecycle, Seeking, Options & Memory Accounting
//    Vòng đời GifInfo, Tua khung hình, Tùy chọn & Kiểm kê bộ nhớ
// ============================================================================

// Reconstructed from 0x007a30..0x007c30:
// Validates `source->startPos >= 0`, `source->error == 0`, `source->gifFileIn != nullptr`,
// allocates `GifInfo` (`0xa8` bytes) and initial `FrameInfo` (`0x18` bytes), initializes fields:
// - `sampleSize = 1`, `lastFrameRemainder = -1` (via `.rodata` `0x002970`)
// - `loopCount = 1`, `currentLoop = 0` (via `.rodata` `0x0029c0`)
// - `speedFactor = 1.0f` (`0x3f800000`)
// - `originalWidth = SWidth`, `originalHeight = SHeight`
// Runs metadata discovery pass `DDGifSlurp(info, false, false)`, frees temporary `rasterBits`,
// and validates `SWidth > 0 && SHeight > 0 && ImageCount > 0`.
// Phục hồi từ 0x007a30..0x007c30: Cấp phát và khởi tạo cấu trúc `GifInfo` (168 byte).
GifInfo* createGifInfo(DecodeSource* source, void* /*jniEnv*/) noexcept {
    if (source == nullptr) {
        return nullptr;
    }
    if (source->startPos < 0) {
        source->error = D_GIF_ERR_NOT_READABLE; // mov w0, #0x6f @ 0x007b28
    }
    if (source->error != 0 || source->gifFileIn == nullptr) {
        DGifCloseFile(source->gifFileIn);
        return nullptr;
    }

    auto* info = static_cast<GifInfo*>(std::malloc(sizeof(GifInfo)));
    if (info == nullptr) {
        DGifCloseFile(source->gifFileIn);
        return nullptr;
    }

    auto* infos = static_cast<FrameInfo*>(std::malloc(sizeof(FrameInfo)));
    if (infos == nullptr) {
        DGifCloseFile(source->gifFileIn);
        std::free(info);
        return nullptr;
    }

    std::memset(info, 0, sizeof(GifInfo));
    resetFrameInfo(infos);

    info->gifFilePtr         = source->gifFileIn;
    info->originalWidth      = source->gifFileIn->SWidth;
    info->originalHeight     = source->gifFileIn->SHeight;
    info->sampleSize         = 1ULL;
    info->lastFrameRemainder = -1LL;
    info->nextStartTime      = 0LL;
    info->currentIndex       = 0ULL;
    info->infos              = infos;
    info->backupPtr          = nullptr;
    info->startPos           = source->startPos;
    info->rasterBits         = nullptr;
    info->rasterSize         = 0ULL;
    info->comment            = nullptr;
    info->loopCount          = 1ULL;
    info->currentLoop        = 0ULL;
    info->rewindFunction     = source->rewindFunc;
    info->speedFactor        = 1.0f;
    info->stride             = 0U;
    info->sourceLength       = source->sourceLength;
    info->isOpaque           = false;
    info->frameBufferDescriptor = nullptr;

    DDGifSlurp(info, false, false);

    std::free(info->rasterBits);
    info->rasterBits = nullptr;
    info->rasterSize = 0ULL;

    GifFileType* gif = source->gifFileIn;
    if (gif->SWidth == 0ULL || gif->SHeight == 0ULL) {
        cleanUp(info);
        source->error = D_GIF_ERR_INVALID_SCR_DIMS; // mov w0, #0x3e9 @ 0x007bb8
        return nullptr;
    }
    if (gif->Error == D_GIF_ERR_NOT_ENOUGH_MEM) {
        cleanUp(info);
        source->error = D_GIF_ERR_NOT_ENOUGH_MEM;
        return nullptr;
    }
    if (gif->ImageCount == 0ULL) {
        source->error = D_GIF_ERR_NO_FRAMES; // mov w8, #0x3e8 @ 0x007c04
        cleanUp(info);
        return nullptr;
    }
    if (gif->Error == D_GIF_ERR_REWIND_FAILED) {
        source->error = D_GIF_ERR_REWIND_FAILED; // mov w8, #0x3ec @ 0x007bf8
        cleanUp(info);
        return nullptr;
    }
    if (source->error != 0) {
        cleanUp(info);
        return nullptr;
    }

    return info;
}

// Reconstructed from 0x004fd8..0x00502c:
// Frees `backupPtr` (+0x48), `infos` (+0x40), `rasterBits` (+0x58), `comment` (+0x68),
// closes `gifFilePtr` (+0x08) via `DGifCloseFile` (`0x007824`), and frees `info`.
// Phục hồi từ 0x004fd8..0x00502c: Giải phóng toàn bộ bộ đệm của `GifInfo` và đóng `GifFileType`.
void cleanUp(GifInfo* info) noexcept {
    if (info == nullptr) {
        return;
    }
    std::free(info->backupPtr);
    info->backupPtr = nullptr;
    std::free(info->infos);
    info->infos = nullptr;
    std::free(info->rasterBits);
    info->rasterBits = nullptr;
    std::free(info->comment);
    info->comment = nullptr;
    DGifCloseFile(info->gifFilePtr);
    std::free(info);
}

// Reconstructed from 0x004380..0x0043bc:
// Calls `info->rewindFunction(info)`. If 0, resets `nextStartTime = 0`, `currentLoop = 0`,
// `currentIndex = 0`, `lastFrameRemainder = -1`, and returns `true`.
// Phục hồi từ 0x004380..0x0043bc: Tua lại nguồn dữ liệu và đặt trạng thái hoạt ảnh về ban đầu.
bool reset(GifInfo* info) noexcept {
    if (info == nullptr || info->rewindFunction == nullptr) {
        return false;
    }
    if (info->rewindFunction(info) != 0) {
        return false;
    }
    info->nextStartTime      = 0LL;
    info->currentLoop        = 0ULL;
    info->currentIndex       = 0ULL;
    info->lastFrameRemainder = -1LL;
    return true;
}

// Reconstructed from 0x004418..0x0045b4:
// Seeks to `desiredIndex` on `pixels` canvas:
// - If `ImageCount <= 1`, returns immediately.
// - If `desiredIndex < currentIndex`, calls `reset(info)` (setting `D_GIF_ERR_REWIND_FAILED = 0x3ec` on failure).
// - Scans `infos[currentIndex..desiredIndex]` for `DISPOSE_PREVIOUS (3)` to pre-allocate `backupPtr` if needed.
// - If `currentIndex == 0`, calls `prepareCanvas(pixels, info)`, decodes and draws frames up to `desiredIndex`.
// Phục hồi từ 0x004418..0x0045b4: Tua tới khung hình `desiredIndex` trên khung vẽ `pixels`.
void seek(GifInfo* info, uint64_t desiredIndex, void* pixels) noexcept {
    GifFileType* gif = info->gifFilePtr;
    if (gif->ImageCount <= 1ULL) {
        return;
    }

    if (desiredIndex < info->currentIndex) {
        if (!reset(info)) {
            gif->Error = D_GIF_ERR_REWIND_FAILED; // mov w9, #0x3ec @ 0x0045a4
            return;
        }
    }

    if (info->backupPtr == nullptr) {
        for (uint64_t i = info->currentIndex; i <= desiredIndex; ++i) {
            if (info->infos[i].disposalMethod == DISPOSE_PREVIOUS) {
                info->backupPtr = static_cast<argb*>(
                    std::calloc(static_cast<uint64_t>(info->stride) * gif->SHeight, sizeof(argb)));
                if (info->backupPtr == nullptr) {
                    gif->Error = D_GIF_ERR_NOT_ENOUGH_MEM;
                    return;
                }
                break;
            }
        }
    }

    auto* bm = static_cast<argb*>(pixels);
    if (info->currentIndex == 0ULL) {
        if (info->stride == 0U) {
            info->stride = static_cast<uint32_t>(gif->SWidth);
        }
        prepareCanvas(bm, info);
        DDGifSlurp(info, true, true);
        drawFrame(bm, info);
        info->currentIndex++;
    }

    while (info->currentIndex < desiredIndex) {
        const uint8_t prevDisposal = info->infos[info->currentIndex - 1ULL].disposalMethod;
        const uint8_t currDisposal = info->infos[info->currentIndex].disposalMethod;
        const bool needDecode = (currDisposal != DISPOSE_BACKGROUND) &&
                                (currDisposal != DISPOSE_PREVIOUS || (info->currentIndex + 1ULL >= desiredIndex));
        (void)prevDisposal;
        DDGifSlurp(info, needDecode, true);
        drawFrame(bm, info);
        info->currentIndex++;
    }

    DDGifSlurp(info, true, true);
    drawFrame(bm, info);
    getFrameDuration(info);
}

// Reconstructed from 0x007c4c..0x007cec:
// Sets `info->sampleSize = sampleSize` and `info->isOpaque = isOpaque`, divides `gif->SWidth`
// and `gif->SHeight` by `sampleSize` (clamped to `>= 1`), and divides every `SavedImage`'s
// `Width`, `Height`, `Left`, and `Top` by `sampleSize`.
// Phục hồi từ 0x007c4c..0x007cec: Thiết lập `sampleSize` và `isOpaque`, chia tỷ lệ kích thước khung hình.
void setOptions(GifInfo* info, uint16_t sampleSize, bool isOpaque) noexcept {
    if (info == nullptr) {
        return;
    }
    GifFileType* gif = info->gifFilePtr;
    const uint64_t divisor = (sampleSize > 0U) ? static_cast<uint64_t>(sampleSize) : 1ULL;
    info->sampleSize = divisor;
    info->isOpaque   = isOpaque;

    gif->SWidth  = info->originalWidth / divisor;
    gif->SHeight = info->originalHeight / divisor;
    if (gif->SHeight == 0ULL) {
        gif->SHeight = 1ULL;
    }
    if (gif->SWidth == 0ULL) {
        gif->SWidth = 1ULL;
    }

    for (uint64_t i = 0; i < gif->ImageCount; ++i) {
        SavedImage& sp = gif->SavedImages[i];
        sp.Width  /= divisor;
        sp.Height /= divisor;
        sp.Left   /= divisor;
        sp.Top    /= divisor;
    }
}

// Reconstructed from 0x00810c..0x0081d4:
// Sums `info->infos[0..ImageCount-1].duration` (vectorized 8-at-a-time via NEON `addv s0, v0.4s` in binary).
// Phục hồi từ 0x00810c..0x0081d4: Tính tổng thời lượng của tất cả các khung hình trong GIF.
int32_t getDuration(const GifInfo* info) noexcept {
    if (info == nullptr || info->gifFilePtr == nullptr) {
        return 0;
    }
    const uint64_t imageCount = info->gifFilePtr->ImageCount;
    if (imageCount == 0ULL) {
        return 0;
    }
    uint32_t totalDuration = 0U;
    for (uint64_t i = 0; i < imageCount; ++i) {
        totalDuration += static_cast<uint32_t>(info->infos[i].duration);
    }
    return static_cast<int32_t>(totalDuration);
}

// Reconstructed from 0x0081ec..0x008308:
// Returns `0` if `ImageCount <= 1`. Sums durations of frames `0..idx-1` (where `idx = currentIndex == 0 ? ImageCount : currentIndex`)
// and subtracts the remaining time of the active frame (`lastFrameRemainder` if `!= -1`, else `max(0, nextStartTime - getRealTime())`).
// Phục hồi từ 0x0081ec..0x008308: Tính vị trí thời gian phát hiện tại trong vòng lặp.
int32_t getCurrentPosition(const GifInfo* info) noexcept {
    if (info == nullptr || info->gifFilePtr == nullptr) {
        return 0;
    }
    const uint64_t imageCount = info->gifFilePtr->ImageCount;
    if (imageCount <= 1ULL) {
        return 0;
    }
    const uint64_t idx = (info->currentIndex == 0ULL) ? imageCount : info->currentIndex;
    uint32_t sum = 0U;
    for (uint64_t i = 0; i < idx; ++i) {
        sum += static_cast<uint32_t>(info->infos[i].duration);
    }
    int64_t remainder = info->lastFrameRemainder;
    if (remainder == -1LL) {
        remainder = info->nextStartTime - getRealTime();
        if (remainder <= 0LL) {
            remainder = 0LL;
        }
    }
    return static_cast<int32_t>(sum) - static_cast<int32_t>(remainder);
}

// Reconstructed from 0x00830c..0x008354:
// Exact formula at 0x008320..0x008340:
//   mov  w9, #0x48               // sizeof(SavedImage) + sizeof(FrameInfo) = 48 + 24 = 72
//   mov  x10, #0x120             // sizeof(GifInfo) + sizeof(GifFileType) = 168 + 120 = 288
//   madd x19, x8, x9, x10        // 0x120 + ImageCount * 0x48
//   if (comment != nullptr) x19 += strlen(comment);
// Phục hồi từ 0x00830c..0x008354: Công thức tính bộ nhớ siêu dữ liệu `0x120 + ImageCount * 0x48 + strlen(comment)`.
int64_t getMetadataByteCount(const GifInfo* info) noexcept {
    if (info == nullptr) {
        return 0LL;
    }
    const uint64_t imageCount = info->gifFilePtr->ImageCount;
    uint64_t size = 0x120ULL + (imageCount * 0x48ULL);
    if (info->comment != nullptr) {
        size += std::strlen(info->comment);
    }
    return static_cast<int64_t>(size);
}

// Reconstructed from 0x008358..0x008420:
// Computes `rasterSize` (or max `Width * Height` across `SavedImages` if `rasterSize == 0`),
// and if `backupPtr != nullptr` (or any frame has `disposalMethod == DISPOSE_PREVIOUS (3)`),
// adds `(stride != 0 ? stride : SWidth) * SHeight * 4`.
// Phục hồi từ 0x008358..0x008420: Tính tổng bộ nhớ cấp phát cho `rasterBits` và `backupPtr`.
int64_t getAllocationByteCount(const GifInfo* info) noexcept {
    if (info == nullptr) {
        return 0LL;
    }
    GifFileType* gif = info->gifFilePtr;
    uint64_t totalBytes = info->rasterSize;

    if (totalBytes == 0ULL && gif->ImageCount > 0ULL) {
        uint64_t maxFramePixels = 0ULL;
        for (uint64_t i = 0; i < gif->ImageCount; ++i) {
            const SavedImage& sp = gif->SavedImages[i];
            const uint64_t framePixels = sp.Width * sp.Height;
            if ((sp.Height < info->originalHeight || sp.Width < info->originalWidth) &&
                framePixels > maxFramePixels) {
                maxFramePixels = framePixels;
            }
        }
        totalBytes = maxFramePixels;
    }

    bool hasBackup = (info->backupPtr != nullptr);
    if (!hasBackup && gif->ImageCount >= 2ULL) {
        for (uint64_t i = 1ULL; i < gif->ImageCount; ++i) {
            if (info->infos[i].disposalMethod == DISPOSE_PREVIOUS) {
                hasBackup = true;
                break;
            }
        }
    }

    if (hasBackup) {
        const uint64_t stride = (info->stride != 0U)
                                    ? static_cast<uint64_t>(info->stride)
                                    : gif->SWidth;
        totalBytes += (stride * gif->SHeight) << 2U;
    }

    return static_cast<int64_t>(totalBytes);
}

// Reconstructed from 0x008530..0x0086ac:
// Restores 4-element `savedState` array:
// - `savedState[0]`: `savedIndex` (`uint64_t`)
// - `savedState[1]`: `currentLoop` (`uint8_t` at `sp + 0x10` / `savedState[1]`)
// - `savedState[2]`: `lastFrameRemainder` (`int64_t`)
// - `savedState[3]`: `speedFactor` bits (`uint32_t` float bits)
// Rewinds if `savedIndex < currentIndex`, renders up to `savedIndex`, and computes invalidation delay.
// Phục hồi từ 0x008530..0x0086ac: Khôi phục trạng thái hoạt ảnh từ mảng `savedState` 4 phần tử.
int32_t restoreSavedState(
    GifInfo* info,
    const int64_t* savedState,
    size_t stateLen,
    void* pixels) noexcept {
    if (info == nullptr || savedState == nullptr || stateLen < 4U) {
        return -1;
    }
    GifFileType* gif = info->gifFilePtr;
    if (gif->ImageCount == 1ULL) {
        return -1;
    }

    const uint64_t savedIndex = static_cast<uint64_t>(savedState[0]);
    const uint64_t savedLoop  = static_cast<uint64_t>(static_cast<uint8_t>(savedState[1]));
    const int64_t  remainder  = savedState[2];
    const uint32_t speedBits  = static_cast<uint32_t>(savedState[3]);

    if (savedIndex >= gif->ImageCount || (info->loopCount != 0ULL && savedLoop > info->loopCount)) {
        return -1;
    }

    if (savedIndex < info->currentIndex) {
        if (!reset(info)) {
            gif->Error = D_GIF_ERR_REWIND_FAILED;
            return -1;
        }
    }

    uint64_t lastFrameDuration = info->infos[info->currentIndex].duration;
    if (info->currentIndex < savedIndex) {
        auto* bm = static_cast<argb*>(pixels);
        if (info->stride == 0U) {
            info->stride = static_cast<uint32_t>(gif->SWidth);
        }
        if (info->currentIndex == 0ULL) {
            prepareCanvas(bm, info);
        }
        while (info->currentIndex < savedIndex) {
            DDGifSlurp(info, true, true);
            lastFrameDuration = drawNextBitmap(bm, info);
        }
    }

    info->currentLoop        = savedLoop;
    info->lastFrameRemainder = remainder;
    std::memcpy(&info->speedFactor, &speedBits, sizeof(float));

    if (info->lastFrameRemainder == -1LL) {
        uint64_t scaledDuration = static_cast<uint64_t>(
            static_cast<float>(lastFrameDuration) * info->speedFactor);
        info->nextStartTime = getRealTime() + static_cast<int64_t>(scaledDuration);
        return static_cast<int32_t>(scaledDuration);
    }
    return -1;
}

// ============================================================================
// 4. OpenGL ES 2.0 Texture Descriptor Helpers (0x008920..0x008c08)
//    Các hàm hỗ trợ bộ mô tả kết cấu OpenGL ES 2.0 (0x008920..0x008c08)
// ============================================================================

// Reconstructed from 0x008920..0x0089dc:
// Allocates `TexImageDescriptor` (`0x40` bytes) and `frameBuffer` (`SWidth * SHeight * 4` bytes),
// sets `eventPollFd = -1`, `info->stride = SWidth`, and attaches to `info->frameBufferDescriptor`.
// Phục hồi từ 0x008920..0x0089dc: Khởi tạo `TexImageDescriptor` (64 byte) và bộ đệm kết cấu RGBA8888.
int initTexImageDescriptor(GifInfo* info) noexcept {
    if (info == nullptr) {
        return -1;
    }
    auto* descriptor = static_cast<TexImageDescriptor*>(std::calloc(1U, sizeof(TexImageDescriptor)));
    if (descriptor == nullptr) {
        return -1;
    }
    GifFileType* gif = info->gifFilePtr;
    descriptor->eventPollFd = -1;
    descriptor->pollEvents  = 1U; // POLLIN
    const size_t bufBytes   = static_cast<size_t>(gif->SWidth) *
                              static_cast<size_t>(gif->SHeight) * sizeof(argb);
    descriptor->frameBuffer = static_cast<argb*>(std::malloc(bufBytes));
    if (descriptor->frameBuffer == nullptr) {
        std::free(descriptor);
        return -1;
    }
    info->stride                = static_cast<uint32_t>(gif->SWidth);
    info->frameBufferDescriptor = descriptor;
    info->destructor            = &releaseTexImageDescriptor;
    return 0;
}

// Reconstructed from 0x008aa8..0x008b18:
// Releases `TexImageDescriptor::frameBuffer` and `TexImageDescriptor` at `info->frameBufferDescriptor`.
// Phục hồi từ 0x008aa8..0x008b18: Giải phóng `TexImageDescriptor` và bộ đệm kết cấu.
void releaseTexImageDescriptor(GifInfo* info, void* /*jniEnv*/) noexcept {
    if (info == nullptr || info->frameBufferDescriptor == nullptr) {
        return;
    }
    auto* descriptor = static_cast<TexImageDescriptor*>(info->frameBufferDescriptor);
    info->frameBufferDescriptor = nullptr;
    std::free(descriptor->frameBuffer);
    std::free(descriptor);
}

// Reconstructed from 0x008b1c..0x008c08:
// Executes one iteration of the OpenGL ES 2.0 slurp thread (`slurp` @ `0x008b1c`):
// records `getRealTime()`, calls `DDGifSlurp(info, true, true)`, prepares canvas if `currentIndex == 0`,
// calls `drawNextBitmap(descriptor->frameBuffer, info)`, and returns `calculateInvalidationDelay`.
// Phục hồi từ 0x008b1c..0x008c08: Thực thi một chu kỳ giải mã khung hình kết cấu OpenGL ES 2.0.
int64_t stepTexImageFrame(GifInfo* info) noexcept {
    if (info == nullptr || info->frameBufferDescriptor == nullptr) {
        return -1LL;
    }
    auto* descriptor = static_cast<TexImageDescriptor*>(info->frameBufferDescriptor);
    const int64_t renderStartTime = getRealTime();
    DDGifSlurp(info, true, true);
    if (info->currentIndex == 0ULL) {
        prepareCanvas(descriptor->frameBuffer, info);
    }
    const uint64_t frameDuration = drawNextBitmap(descriptor->frameBuffer, info);
    return calculateInvalidationDelay(info, renderStartTime, frameDuration);
}

} // namespace gif
} // namespace opencut
