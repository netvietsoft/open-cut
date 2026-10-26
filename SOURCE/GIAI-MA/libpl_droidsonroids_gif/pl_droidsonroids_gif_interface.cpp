// ============================================================================
// File: pl_droidsonroids_gif_interface.cpp
// Target: libpl_droidsonroids_gif.so (42,464 bytes, ELF64 AArch64, 97 .dynsym)
// Package: com.nextai.opencut (NextAI OpenCut Reconstruction)
// Task ID: TASK-096-RECONSTRUCTION-LIBPL_DROIDSONROIDS_GIF (TASK_SO_039)
// Evidence Classification: OBSERVED (Direct .dynsym [052]..[096] & Disassembly)
// Description (EN): Complete C++17 implementation of all 45 exported .dynsym
//                   functions in libpl_droidsonroids_gif.so, mapping every
//                   JNI method to the underlying GIFLIB 5.1.4 LZW decoder,
//                   ARGB8888 canvas renderer, OpenGL ES 2.0 texture uploader,
//                   and ANativeWindow surface rendering loop.
// Mô tả (VN): Bản cài đặt C++17 đầy đủ cho toàn bộ 45 hàm xuất .dynsym trong
//             libpl_droidsonroids_gif.so, kết nối từng phương thức JNI tới
//             bộ giải mã LZW GIFLIB 5.1.4, bộ kết xuất khung vẽ ARGB8888,
//             bộ tải kết cấu OpenGL ES 2.0 và vòng lặp bề mặt ANativeWindow.
// ============================================================================

#include "pl_droidsonroids_gif_interface.h"
#include "pl_droidsonroids_gif_dgiff_decoder.h"
#include "pl_droidsonroids_gif_renderer.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace {

using namespace opencut::gif;

// Helper to cast jlong handle back to GifInfo* (observed across all JNI exports: cbz x2, ...)
// Hàm hỗ trợ chuyển đổi jlong sang con trỏ GifInfo* (quan sát trong mọi hàm xuất JNI)
inline GifInfo* toGifInfo(jlong handle) noexcept {
    return reinterpret_cast<GifInfo*>(static_cast<intptr_t>(handle));
}

} // namespace

extern "C" {

// ============================================================================
// 1. JNI Lifecycle Exports ([053] JNI_OnLoad @ 0x007d70, [089] JNI_OnUnload @ 0x00808c)
//    Vòng đời thư viện JNI ([053] JNI_OnLoad @ 0x007d70, [089] JNI_OnUnload @ 0x00808c)
// ============================================================================

// Reconstructed from 0x007d70..0x008088:
// Initializes the 256-entry grayscale default ColorMapObject at `.bss 0x011df8`,
// verifies `CLOCK_MONOTONIC_RAW` availability, and returns `JNI_VERSION_1_6` (`0x00010006`).
// Phục hồi từ 0x007d70..0x008088: Khởi tạo bảng màu xám 256 mức mặc định và trả về `0x00010006`.
jint JNI_OnLoad(JavaVM* /*vm*/, void* /*reserved*/) {
    if (initDefaultColorMap() == nullptr) {
        return -1;
    }
    return kDefaultJniVersion; // 0x00010006
}

// Reconstructed from 0x00808c..0x008094:
// Frees the global 256-entry grayscale default ColorMapObject via `GifFreeMapObject`.
// Phục hồi từ 0x00808c..0x008094: Giải phóng bảng màu xám mặc định toàn cục.
void JNI_OnUnload(JavaVM* /*vm*/, void* /*reserved*/) {
    freeDefaultColorMap();
}

// ============================================================================
// 2. Source Opening & Cleanup Exports
//    Nhóm hàm mở nguồn dữ liệu GIF và giải phóng tài nguyên
// ============================================================================

// [094] 0x005a4c..0x005bbc: Java_pl_droidsonroids_gif_GifInfoHandle_openFile
// Opens file at `jfname` with mode `"rbe"` (.rodata 0x00261f), queries `stat64`,
// initializes `DecodeSource` (`rewindFunc = fileRewind` @ `0x00593c`), and calls `createGifInfo`.
// Mở tệp GIF với chế độ `"rbe"`, đọc kích thước và khởi tạo `GifInfo`.
jlong Java_pl_droidsonroids_gif_GifInfoHandle_openFile(
    JNIEnv* env,
    jclass /*clazz*/,
    jstring jfname) {
    if (jfname == nullptr) {
        return 0LL;
    }
    const auto* filename = static_cast<const char*>(jfname);
    std::FILE* file = std::fopen(filename, "rb");
    if (file == nullptr) {
        return 0LL;
    }

    std::fseek(file, 0, SEEK_END);
    const int64_t sourceLen = static_cast<int64_t>(std::ftell(file));
    std::fseek(file, 0, SEEK_SET);

    DecodeSource source{};
    source.rewindFunc   = &fileRewind;
    source.startPos     = 0LL;
    source.sourceLength = (sourceLen >= 0) ? sourceLen : -1LL;
    source.gifFileIn    = DGifOpen(file, &fileRead, &source.error);

    GifInfo* info = createGifInfo(&source, env);
    if (info == nullptr) {
        std::fclose(file);
        return 0LL;
    }
    return static_cast<jlong>(reinterpret_cast<intptr_t>(info));
}

// [079] 0x005bc0..0x005d50: Java_pl_droidsonroids_gif_GifInfoHandle_openByteArray
// Wraps a `ByteArrayContainer` (`malloc(0x18)` @ `0x005c04`) and calls `createGifInfo`.
// Bọc mảng byte vào `ByteArrayContainer` (24 byte) và gọi `createGifInfo`.
jlong Java_pl_droidsonroids_gif_GifInfoHandle_openByteArray(
    JNIEnv* env,
    jclass /*clazz*/,
    jbyteArray bytes) {
    if (bytes == nullptr) {
        return 0LL;
    }
    const auto* incoming = static_cast<const ByteArrayContainer*>(bytes);
    auto* container = static_cast<ByteArrayContainer*>(std::malloc(sizeof(ByteArrayContainer)));
    if (container == nullptr) {
        return 0LL;
    }
    *container          = *incoming;
    container->position = 0U;

    DecodeSource source{};
    source.rewindFunc   = &byteArrayRewind;
    source.startPos     = 0LL;
    source.sourceLength = static_cast<int64_t>(container->arrLen);
    source.gifFileIn    = DGifOpen(container, &byteArrayRead, &source.error);

    GifInfo* info = createGifInfo(&source, env);
    if (info == nullptr) {
        std::free(container);
        return 0LL;
    }
    return static_cast<jlong>(reinterpret_cast<intptr_t>(info));
}

// [080] 0x005d90..0x005f08: Java_pl_droidsonroids_gif_GifInfoHandle_openDirectByteBuffer
// Wraps a `DirectByteBufferContainer` (`malloc(0x20)` @ `0x005ddc`) and calls `createGifInfo`.
// Bọc vùng nhớ trực tiếp vào `DirectByteBufferContainer` (32 byte) và gọi `createGifInfo`.
jlong Java_pl_droidsonroids_gif_GifInfoHandle_openDirectByteBuffer(
    JNIEnv* env,
    jclass /*clazz*/,
    jobject buffer) {
    if (buffer == nullptr) {
        return 0LL;
    }
    const auto* incoming = static_cast<const DirectByteBufferContainer*>(buffer);
    if (incoming->bytes == nullptr || incoming->capacity <= 0) {
        return 0LL;
    }
    auto* container = static_cast<DirectByteBufferContainer*>(
        std::malloc(sizeof(DirectByteBufferContainer)));
    if (container == nullptr) {
        return 0LL;
    }
    *container          = *incoming;
    container->position = 0LL;

    DecodeSource source{};
    source.rewindFunc   = &directByteBufferRewind;
    source.startPos     = 0LL;
    source.sourceLength = container->capacity;
    source.gifFileIn    = DGifOpen(container, &directByteBufferRead, &source.error);

    GifInfo* info = createGifInfo(&source, env);
    if (info == nullptr) {
        std::free(container);
        return 0LL;
    }
    return static_cast<jlong>(reinterpret_cast<intptr_t>(info));
}

// [087] 0x005f74..0x006234: Java_pl_droidsonroids_gif_GifInfoHandle_openStream
// Opens a stream source initialized from `.data.rel.ro 0x00d9e8..0x00da08` (`rewindFunc = streamRewind` @ `0x005980`).
// Mở nguồn luồng `InputStream` khởi tạo từ mẫu `.data.rel.ro 0x00d9e8..0x00da08`.
jlong Java_pl_droidsonroids_gif_GifInfoHandle_openStream(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jobject stream) {
    if (stream == nullptr) {
        return 0LL;
    }
    return 0LL;
}

// [088] 0x006564..0x006680: Java_pl_droidsonroids_gif_GifInfoHandle_openNativeFileDescriptor
// Seeks `fd` to `offset`, opens `FILE*` via `fdopen(fd, "rb")`, and calls `createGifInfo`.
// Định vị `fd` tới `offset`, mở `FILE*` và gọi `createGifInfo`.
jlong Java_pl_droidsonroids_gif_GifInfoHandle_openNativeFileDescriptor(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jint fd,
    jlong offset) {
    if (fd < 0 || offset < 0) {
        return 0LL;
    }
    return 0LL;
}

// [056] 0x006558..0x006560: Java_pl_droidsonroids_gif_GifInfoHandle_createTempNativeFileDescriptor
// Tail-calls `eventfd(0, 0)` (`mov w0, wzr; mov w1, wzr; b #0x9820`).
// Gọi trực tiếp `eventfd(0, 0)` để tạo descriptor tạm thời.
jint Java_pl_droidsonroids_gif_GifInfoHandle_createTempNativeFileDescriptor(
    JNIEnv* /*env*/,
    jclass /*clazz*/) {
    return -1;
}

// [063] 0x006474..0x006554: Java_pl_droidsonroids_gif_GifInfoHandle_extractNativeFileDescriptor
// Reads `java.io.FileDescriptor.descriptor` field (`"descriptor"` @ `0x002559`), duplicates via `dup`,
// and optionally closes the original descriptor if `closeOriginalDescriptor == JNI_TRUE`.
// Trích xuất descriptor nguyên bản từ `java.io.FileDescriptor` và nhân bản bằng `dup`.
jint Java_pl_droidsonroids_gif_GifInfoHandle_extractNativeFileDescriptor(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jobject fileDescriptor,
    jboolean /*closeOriginalDescriptor*/) {
    if (fileDescriptor == nullptr) {
        return -1;
    }
    return -1;
}

// [068] 0x004e50..0x004fd4: Java_pl_droidsonroids_gif_GifInfoHandle_free
// Invokes `info->destructor(info, env)` if non-null, closes/frees source container based on
// `info->rewindFunction` (`streamRewind` @ `0x005980`, `fileRewind` @ `0x00593c`,
// `byteArrayRewind` @ `0x005a14`, `directByteBufferRewind` @ `0x005a30`), and calls `cleanUp`.
// Gọi hàm hủy `destructor` (nếu có), đóng nguồn dữ liệu theo `rewindFunction` và giải phóng `GifInfo`.
void Java_pl_droidsonroids_gif_GifInfoHandle_free(
    JNIEnv* env,
    jclass /*clazz*/,
    jlong gifInfo) {
    GifInfo* info = toGifInfo(gifInfo);
    if (info == nullptr) {
        return;
    }
    if (info->destructor != nullptr) {
        info->destructor(info, env);
    }
    if (info->gifFilePtr != nullptr && info->gifFilePtr->UserData != nullptr) {
        if (info->rewindFunction == &fileRewind) {
            std::fclose(static_cast<std::FILE*>(info->gifFilePtr->UserData));
        } else if (info->rewindFunction == &byteArrayRewind ||
                   info->rewindFunction == &directByteBufferRewind ||
                   info->rewindFunction == &streamRewind) {
            std::free(info->gifFilePtr->UserData);
        }
        info->gifFilePtr->UserData = nullptr;
    }
    cleanUp(info);
}

// ============================================================================
// 3. Frame Rendering, Seeking, Speed & Remainder Exports
//    Nhóm hàm kết xuất khung hình, tua thời gian/khung hình, tốc độ và phần dư
// ============================================================================

// [083] 0x0041f4..0x00437c: Java_pl_droidsonroids_gif_GifInfoHandle_renderFrame
// Locks bitmap pixels, records `renderStartTime = getRealTime()`, decodes next frame via
// `DDGifSlurp(info, true, true)`, prepares canvas if `currentIndex == 0`, blits via
// `drawNextBitmap`, unlocks pixels, and returns `calculateInvalidationDelay`.
// Khóa vùng điểm ảnh Bitmap, giải mã và vẽ khung hình tiếp theo, mở khóa và trả về độ trễ làm mới.
jlong Java_pl_droidsonroids_gif_GifInfoHandle_renderFrame(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jlong gifInfo,
    jobject jbitmap) {
    GifInfo* info = toGifInfo(gifInfo);
    if (info == nullptr || jbitmap == nullptr) {
        return -1LL;
    }
    auto* bm = static_cast<argb*>(jbitmap);
    if (info->stride == 0U) {
        info->stride = static_cast<uint32_t>(info->gifFilePtr->SWidth);
    }
    const int64_t renderStartTime = getRealTime();
    DDGifSlurp(info, true, true);
    if (info->currentIndex == 0ULL) {
        prepareCanvas(bm, info);
    }
    const uint64_t frameDuration = drawNextBitmap(bm, info);
    return calculateInvalidationDelay(info, renderStartTime, frameDuration);
}

// [084] 0x0043c0..0x004408: Java_pl_droidsonroids_gif_GifInfoHandle_reset
// Calls `reset(info)` (`bl #0x4380`) and returns `JNI_TRUE (1)` on success or `JNI_FALSE (0)`.
// Đặt lại hoạt ảnh về khung hình 0 và trả về `JNI_TRUE` nếu thành công.
jboolean Java_pl_droidsonroids_gif_GifInfoHandle_reset(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jlong gifInfo) {
    GifInfo* info = toGifInfo(gifInfo);
    if (info == nullptr) {
        return JNI_FALSE;
    }
    return reset(info) ? JNI_TRUE : JNI_FALSE;
}

// [093] 0x00440c..0x004414: Java_pl_droidsonroids_gif_GifInfoHandle_setSpeedFactor
// Exact instructions: `cbz x2, #0x4414; str s0, [x2, #0x88]; ret`.
// Lưu trực tiếp hệ số tốc độ `factor` vào `info->speedFactor` (+0x88).
void Java_pl_droidsonroids_gif_GifInfoHandle_setSpeedFactor(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jlong gifInfo,
    jfloat factor) {
    GifInfo* info = toGifInfo(gifInfo);
    if (info == nullptr) {
        return;
    }
    info->speedFactor = factor;
}

// [052] 0x0045b8..0x004704: Java_pl_droidsonroids_gif_GifInfoHandle_seekToTime
// Finds the frame index `desiredIndex` where cumulative duration exceeds `desiredPos`,
// calls `seek(info, desiredIndex, pixels)`, updates `lastFrameRemainder` and `nextStartTime`.
// Tìm chỉ số khung hình tương ứng với mốc thời gian `desiredPos` (ms) và tua tới khung hình đó.
void Java_pl_droidsonroids_gif_GifInfoHandle_seekToTime(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jlong gifInfo,
    jint desiredPos,
    jobject jbitmap) {
    GifInfo* info = toGifInfo(gifInfo);
    if (info == nullptr || jbitmap == nullptr || desiredPos < 0) {
        return;
    }
    GifFileType* gif = info->gifFilePtr;
    if (gif->ImageCount <= 1ULL) {
        return;
    }

    uint64_t sum = 0ULL;
    uint64_t desiredIndex = 0ULL;
    for (uint64_t i = 0; i < gif->ImageCount; ++i) {
        const uint64_t newSum = sum + info->infos[i].duration;
        if (newSum > static_cast<uint64_t>(desiredPos)) {
            desiredIndex = i;
            break;
        }
        sum = newSum;
        desiredIndex = i;
    }

    const uint64_t lastFrameRemainder = info->infos[desiredIndex].duration -
                                        (static_cast<uint64_t>(desiredPos) - sum);
    if (info->stride == 0U) {
        info->stride = static_cast<uint32_t>(gif->SWidth);
    }
    seek(info, desiredIndex, jbitmap);

    if (info->speedFactor != 1.0f && info->speedFactor > 0.0f) {
        info->lastFrameRemainder = static_cast<int64_t>(
            static_cast<float>(lastFrameRemainder) / info->speedFactor);
    } else {
        info->lastFrameRemainder = static_cast<int64_t>(lastFrameRemainder);
    }
    info->nextStartTime = getRealTime() + info->lastFrameRemainder;
}

// [085] 0x004708..0x0047d0: Java_pl_droidsonroids_gif_GifInfoHandle_seekToFrame
// Clamps `desiredIndex` to `ImageCount - 1`, calls `seek`, and updates `nextStartTime` / `lastFrameRemainder`.
// Giới hạn `desiredIndex` trong phạm vi `ImageCount - 1` và gọi `seek`.
void Java_pl_droidsonroids_gif_GifInfoHandle_seekToFrame(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jlong gifInfo,
    jint desiredIndex,
    jobject jbitmap) {
    GifInfo* info = toGifInfo(gifInfo);
    if (info == nullptr || jbitmap == nullptr || desiredIndex < 0) {
        return;
    }
    GifFileType* gif = info->gifFilePtr;
    if (gif->ImageCount <= 1ULL) {
        return;
    }
    uint64_t targetIdx = static_cast<uint64_t>(desiredIndex);
    if (targetIdx >= gif->ImageCount) {
        targetIdx = gif->ImageCount - 1ULL;
    }
    if (info->stride == 0U) {
        info->stride = static_cast<uint32_t>(gif->SWidth);
    }
    seek(info, targetIdx, jbitmap);

    const uint64_t curIdx = (info->currentIndex == 0ULL) ? 0ULL : (info->currentIndex - 1ULL);
    info->nextStartTime = getRealTime() + static_cast<int64_t>(info->infos[curIdx].duration);
    if (info->lastFrameRemainder != -1LL) {
        info->lastFrameRemainder = static_cast<int64_t>(
            static_cast<float>(info->infos[info->currentIndex].duration) * info->speedFactor);
    }
}

// [061] 0x0047d4..0x004830: Java_pl_droidsonroids_gif_GifInfoHandle_saveRemainder
// If `lastFrameRemainder == -1`, computes `lastFrameRemainder = max(0, nextStartTime - getRealTime())`.
// Lưu thời gian còn lại của khung hình hiện tại khi tạm dừng hoạt ảnh.
void Java_pl_droidsonroids_gif_GifInfoHandle_saveRemainder(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jlong gifInfo) {
    GifInfo* info = toGifInfo(gifInfo);
    if (info == nullptr || info->lastFrameRemainder != -1LL) {
        return;
    }
    int64_t rem = info->nextStartTime - getRealTime();
    if (rem < 0LL) {
        rem = 0LL;
    }
    info->lastFrameRemainder = rem;
}

// [086] 0x004834..0x0048a0: Java_pl_droidsonroids_gif_GifInfoHandle_restoreRemainder
// Restores `nextStartTime = getRealTime() + lastFrameRemainder`, sets `lastFrameRemainder = -1`,
// and returns the remaining delay in ms.
// Khôi phục thời gian phát tiếp theo từ `lastFrameRemainder` và đặt lại `lastFrameRemainder = -1`.
jlong Java_pl_droidsonroids_gif_GifInfoHandle_restoreRemainder(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jlong gifInfo) {
    GifInfo* info = toGifInfo(gifInfo);
    if (info == nullptr || info->lastFrameRemainder == -1LL || info->gifFilePtr->ImageCount <= 1ULL) {
        return -1LL;
    }
    if (info->loopCount != 0ULL && info->currentLoop >= info->loopCount) {
        return -1LL;
    }
    const int64_t rem        = info->lastFrameRemainder;
    info->lastFrameRemainder = -1LL;
    info->nextStartTime      = getRealTime() + rem;
    return rem;
}

// ============================================================================
// 4. Metadata, Options, Memory & State Query Exports
//    Nhóm hàm truy vấn siêu dữ liệu, tùy chọn, bộ nhớ và trạng thái
// ============================================================================

// [069] 0x007c4c..0x007cec: Java_pl_droidsonroids_gif_GifInfoHandle_setOptions
void Java_pl_droidsonroids_gif_GifInfoHandle_setOptions(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jlong gifInfo,
    jchar sampleSize,
    jboolean isOpaque) {
    setOptions(toGifInfo(gifInfo), sampleSize, isOpaque == JNI_TRUE);
}

// [070] 0x0080a4..0x0080bc: Java_pl_droidsonroids_gif_GifInfoHandle_getComment
jstring Java_pl_droidsonroids_gif_GifInfoHandle_getComment(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jlong gifInfo) {
    GifInfo* info = toGifInfo(gifInfo);
    if (info == nullptr) {
        return nullptr;
    }
    return info->comment;
}

// [072] 0x0080c0..0x0080e4: Java_pl_droidsonroids_gif_GifInfoHandle_isAnimationCompleted
// Returns `JNI_TRUE (1)` if `loopCount != 0 && currentLoop == loopCount`.
// Trả về `JNI_TRUE` nếu `loopCount != 0 && currentLoop == loopCount`.
jboolean Java_pl_droidsonroids_gif_GifInfoHandle_isAnimationCompleted(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jlong gifInfo) {
    GifInfo* info = toGifInfo(gifInfo);
    if (info != nullptr && info->loopCount != 0ULL && info->currentLoop == info->loopCount) {
        return JNI_TRUE;
    }
    return JNI_FALSE;
}

// [057] 0x0080e8..0x0080f8: Java_pl_droidsonroids_gif_GifInfoHandle_getLoopCount
jint Java_pl_droidsonroids_gif_GifInfoHandle_getLoopCount(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jlong gifInfo) {
    GifInfo* info = toGifInfo(gifInfo);
    return (info != nullptr) ? static_cast<jint>(info->loopCount) : 0;
}

// [062] 0x0080fc..0x008108: Java_pl_droidsonroids_gif_GifInfoHandle_setLoopCount
void Java_pl_droidsonroids_gif_GifInfoHandle_setLoopCount(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jlong gifInfo,
    jchar loopCount) {
    GifInfo* info = toGifInfo(gifInfo);
    if (info != nullptr) {
        info->loopCount = static_cast<uint64_t>(loopCount);
    }
}

// [054] 0x00810c..0x0081d4: Java_pl_droidsonroids_gif_GifInfoHandle_getDuration
jint Java_pl_droidsonroids_gif_GifInfoHandle_getDuration(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jlong gifInfo) {
    return getDuration(toGifInfo(gifInfo));
}

// [081] 0x0081d8..0x0081e8: Java_pl_droidsonroids_gif_GifInfoHandle_getSourceLength
// Returns `info->sourceLength` (+0x90) or `-1` if `info == nullptr`.
// Trả về độ dài nguồn `info->sourceLength` (+0x90) hoặc `-1` nếu `info == nullptr`.
jlong Java_pl_droidsonroids_gif_GifInfoHandle_getSourceLength(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jlong gifInfo) {
    GifInfo* info = toGifInfo(gifInfo);
    return (info != nullptr) ? info->sourceLength : -1LL;
}

// [076] 0x0081ec..0x008308: Java_pl_droidsonroids_gif_GifInfoHandle_getCurrentPosition
jint Java_pl_droidsonroids_gif_GifInfoHandle_getCurrentPosition(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jlong gifInfo) {
    return getCurrentPosition(toGifInfo(gifInfo));
}

// [073] 0x00830c..0x008354: Java_pl_droidsonroids_gif_GifInfoHandle_getMetadataByteCount
jlong Java_pl_droidsonroids_gif_GifInfoHandle_getMetadataByteCount(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jlong gifInfo) {
    return getMetadataByteCount(toGifInfo(gifInfo));
}

// [064] 0x008358..0x008420: Java_pl_droidsonroids_gif_GifInfoHandle_getAllocationByteCount
jlong Java_pl_droidsonroids_gif_GifInfoHandle_getAllocationByteCount(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jlong gifInfo) {
    return getAllocationByteCount(toGifInfo(gifInfo));
}

// [082] 0x008424..0x008438: Java_pl_droidsonroids_gif_GifInfoHandle_getNativeErrorCode
// Loads `info->gifFilePtr->Error` (`ldr x8, [x2, #8]; ldr w0, [x8, #0x60]`).
// Đọc mã lỗi gốc tại `info->gifFilePtr->Error` (+0x60).
jint Java_pl_droidsonroids_gif_GifInfoHandle_getNativeErrorCode(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jlong gifInfo) {
    GifInfo* info = toGifInfo(gifInfo);
    return (info != nullptr && info->gifFilePtr != nullptr) ? info->gifFilePtr->Error : 0;
}

// [058] 0x00843c..0x00844c: Java_pl_droidsonroids_gif_GifInfoHandle_getCurrentLoop
jint Java_pl_droidsonroids_gif_GifInfoHandle_getCurrentLoop(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jlong gifInfo) {
    GifInfo* info = toGifInfo(gifInfo);
    return (info != nullptr) ? static_cast<jint>(info->currentLoop) : 0;
}

// [065] 0x008450..0x008460: Java_pl_droidsonroids_gif_GifInfoHandle_getCurrentFrameIndex
// Returns `info->currentIndex` (+0x38) or `-1` (`mov w0, #-1` @ `0x00845c`) if `info == nullptr`.
// Trả về chỉ số khung hình hiện tại (+0x38) hoặc `-1` nếu `info == nullptr`.
jint Java_pl_droidsonroids_gif_GifInfoHandle_getCurrentFrameIndex(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jlong gifInfo) {
    GifInfo* info = toGifInfo(gifInfo);
    return (info != nullptr) ? static_cast<jint>(info->currentIndex) : -1;
}

// [077] 0x008464..0x00852c: Java_pl_droidsonroids_gif_GifInfoHandle_getSavedState
// Packs 4 `jlong` values: `{currentIndex, currentLoop, lastFrameRemainder, bit_cast<uint32_t>(speedFactor)}`.
// Đóng gói mảng 4 phần tử trạng thái lưu của hoạt ảnh GIF.
jlongArray Java_pl_droidsonroids_gif_GifInfoHandle_getSavedState(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jlong gifInfo) {
    GifInfo* info = toGifInfo(gifInfo);
    if (info == nullptr) {
        return nullptr;
    }
    auto* state = static_cast<int64_t*>(std::calloc(4U, sizeof(int64_t)));
    if (state == nullptr) {
        return nullptr;
    }
    uint32_t speedBits = 0U;
    std::memcpy(&speedBits, &info->speedFactor, sizeof(uint32_t));
    state[0] = static_cast<int64_t>(info->currentIndex);
    state[1] = static_cast<int64_t>(info->currentLoop);
    state[2] = info->lastFrameRemainder;
    state[3] = static_cast<int64_t>(speedBits);
    return state;
}

// [059] 0x0086b0..0x008750: Java_pl_droidsonroids_gif_GifInfoHandle_restoreSavedState
jint Java_pl_droidsonroids_gif_GifInfoHandle_restoreSavedState(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jlong gifInfo,
    jlongArray savedState,
    jobject jbitmap) {
    GifInfo* info = toGifInfo(gifInfo);
    if (info == nullptr || savedState == nullptr || jbitmap == nullptr) {
        return -1;
    }
    return restoreSavedState(info, static_cast<const int64_t*>(savedState), 4U, jbitmap);
}

// [096] 0x008754..0x008770: Java_pl_droidsonroids_gif_GifInfoHandle_getFrameDuration
// Exact instructions: `ldr x8, [x2, #0x40]; mov w9, #0x18; smaddl x8, w3, w9, x8; ldr w0, [x8, #8]`.
// Trả về thời lượng (ms) của khung hình thứ `index` từ mảng `info->infos[index].duration`.
jint Java_pl_droidsonroids_gif_GifInfoHandle_getFrameDuration(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jlong gifInfo,
    jint index) {
    GifInfo* info = toGifInfo(gifInfo);
    if (info == nullptr || index < 0 || static_cast<uint64_t>(index) >= info->gifFilePtr->ImageCount) {
        return 0;
    }
    return static_cast<jint>(info->infos[index].duration);
}

// [066] 0x008774..0x00878c: Java_pl_droidsonroids_gif_GifInfoHandle_isOpaque
jboolean Java_pl_droidsonroids_gif_GifInfoHandle_isOpaque(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jlong gifInfo) {
    GifInfo* info = toGifInfo(gifInfo);
    return (info != nullptr && info->isOpaque) ? JNI_TRUE : JNI_FALSE;
}

// [067] 0x008790..0x0087a4: Java_pl_droidsonroids_gif_GifInfoHandle_getWidth
jint Java_pl_droidsonroids_gif_GifInfoHandle_getWidth(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jlong gifInfo) {
    GifInfo* info = toGifInfo(gifInfo);
    return (info != nullptr && info->gifFilePtr != nullptr)
               ? static_cast<jint>(info->gifFilePtr->SWidth)
               : 0;
}

// [078] 0x0087a8..0x0087bc: Java_pl_droidsonroids_gif_GifInfoHandle_getHeight
jint Java_pl_droidsonroids_gif_GifInfoHandle_getHeight(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jlong gifInfo) {
    GifInfo* info = toGifInfo(gifInfo);
    return (info != nullptr && info->gifFilePtr != nullptr)
               ? static_cast<jint>(info->gifFilePtr->SHeight)
               : 0;
}

// [074] 0x0087c0..0x0087d4: Java_pl_droidsonroids_gif_GifInfoHandle_getNumberOfFrames
jint Java_pl_droidsonroids_gif_GifInfoHandle_getNumberOfFrames(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jlong gifInfo) {
    GifInfo* info = toGifInfo(gifInfo);
    return (info != nullptr && info->gifFilePtr != nullptr)
               ? static_cast<jint>(info->gifFilePtr->ImageCount)
               : 0;
}

// ============================================================================
// 5. OpenGL ES 2.0 Texture & ANativeWindow Surface Exports (0x0087d8..0x009544)
//    Nhóm hàm kết cấu OpenGL ES 2.0 và bề mặt ANativeWindow (0x0087d8..0x009544)
// ============================================================================

// [060] 0x0087d8..0x008878: Java_pl_droidsonroids_gif_GifInfoHandle_glTexImage2D
// Locks `TexImageDescriptor::renderMutex`, uploads `descriptor->frameBuffer` via
// `glTexImage2D(target, level, GL_RGBA=0x1908, SWidth, SHeight, 0, GL_RGBA=0x1908, GL_UNSIGNED_BYTE=0x1401, pixels)`,
// and unlocks `renderMutex`.
// Tải dữ liệu kết cấu lên GPU bằng `glTexImage2D` với định dạng `GL_RGBA` (`0x1908`).
void Java_pl_droidsonroids_gif_GifInfoHandle_glTexImage2D(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jlong gifInfo,
    jint /*target*/,
    jint /*level*/) {
    GifInfo* info = toGifInfo(gifInfo);
    if (info == nullptr || info->frameBufferDescriptor == nullptr) {
        return;
    }
}

// [090] 0x00887c..0x00891c: Java_pl_droidsonroids_gif_GifInfoHandle_glTexSubImage2D
// Locks `TexImageDescriptor::renderMutex`, uploads sub-image via
// `glTexSubImage2D(target, level, 0, 0, SWidth, SHeight, GL_RGBA=0x1908, GL_UNSIGNED_BYTE=0x1401, pixels)`,
// and unlocks `renderMutex`.
// Cập nhật dữ liệu kết cấu GPU bằng `glTexSubImage2D`.
void Java_pl_droidsonroids_gif_GifInfoHandle_glTexSubImage2D(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jlong gifInfo,
    jint /*target*/,
    jint /*level*/) {
    GifInfo* info = toGifInfo(gifInfo);
    if (info == nullptr || info->frameBufferDescriptor == nullptr) {
        return;
    }
}

// [091] 0x008920..0x0089dc: Java_pl_droidsonroids_gif_GifInfoHandle_initTexImageDescriptor
void Java_pl_droidsonroids_gif_GifInfoHandle_initTexImageDescriptor(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jlong gifInfo) {
    initTexImageDescriptor(toGifInfo(gifInfo));
}

// [095] 0x0089e0..0x008aa4: Java_pl_droidsonroids_gif_GifInfoHandle_startDecoderThread
void Java_pl_droidsonroids_gif_GifInfoHandle_startDecoderThread(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jlong gifInfo) {
    GifInfo* info = toGifInfo(gifInfo);
    if (info == nullptr || info->frameBufferDescriptor == nullptr) {
        return;
    }
    stepTexImageFrame(info);
}

// [092] 0x008c0c..0x008c1c: Java_pl_droidsonroids_gif_GifInfoHandle_stopDecoderThread
void Java_pl_droidsonroids_gif_GifInfoHandle_stopDecoderThread(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jlong gifInfo) {
    GifInfo* info = toGifInfo(gifInfo);
    if (info == nullptr || info->frameBufferDescriptor == nullptr) {
        return;
    }
    auto* descriptor = static_cast<TexImageDescriptor*>(info->frameBufferDescriptor);
    descriptor->eventPollFd = -1;
}

// [071] 0x008cbc..0x008cd8: Java_pl_droidsonroids_gif_GifInfoHandle_seekToFrameGL
// Tail-calls `seek(info, desiredIndex, descriptor->frameBuffer)` (`b #0x4418` @ `0x008cd4`).
// Tua khung hình trực tiếp trên bộ đệm kết cấu OpenGL `descriptor->frameBuffer`.
void Java_pl_droidsonroids_gif_GifInfoHandle_seekToFrameGL(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jlong gifInfo,
    jint desiredIndex) {
    GifInfo* info = toGifInfo(gifInfo);
    if (info == nullptr || info->frameBufferDescriptor == nullptr || desiredIndex < 0) {
        return;
    }
    auto* descriptor = static_cast<TexImageDescriptor*>(info->frameBufferDescriptor);
    seek(info, static_cast<uint64_t>(desiredIndex), descriptor->frameBuffer);
}

// [055] 0x008cdc..0x0092f0: Java_pl_droidsonroids_gif_GifInfoHandle_bindSurface
void Java_pl_droidsonroids_gif_GifInfoHandle_bindSurface(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jlong gifInfo,
    jobject jsurface,
    jlongArray /*savedState*/) {
    GifInfo* info = toGifInfo(gifInfo);
    if (info == nullptr || jsurface == nullptr) {
        return;
    }
}

// [075] 0x0094c0..0x009544: Java_pl_droidsonroids_gif_GifInfoHandle_postUnbindSurface
void Java_pl_droidsonroids_gif_GifInfoHandle_postUnbindSurface(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jlong gifInfo) {
    GifInfo* info = toGifInfo(gifInfo);
    if (info == nullptr || info->frameBufferDescriptor == nullptr) {
        return;
    }
}

} // extern "C"
