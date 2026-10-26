// ============================================================================
// File: pl_droidsonroids_gif_renderer.h
// Target: libpl_droidsonroids_gif.so (42,464 bytes, ELF64 AArch64)
// Package: com.nextai.opencut (NextAI OpenCut Reconstruction)
// Task ID: TASK-096-RECONSTRUCTION-LIBPL_DROIDSONROIDS_GIF (TASK_SO_039)
// Evidence Classification: OBSERVED (Direct AArch64 Disassembly 0x004094..0x009680)
// Description (EN): Declarations for the ARGB8888 canvas renderer, GIF89a
//                   disposal engine (DISPOSE_DO_NOT, DISPOSE_BACKGROUND,
//                   DISPOSE_PREVIOUS), frame seeker, monotonic clock delay
//                   calculator, OpenGL ES 2.0 texture uploader, and
//                   ANativeWindow dual-thread surface rendering engine.
// Mô tả (VN): Khai báo cho bộ kết xuất khung vẽ ARGB8888, bộ xử lý xóa khung
//             hình GIF89a (DISPOSE_DO_NOT, DISPOSE_BACKGROUND, DISPOSE_PREVIOUS),
//             bộ tua khung hình, bộ tính độ trễ đồng hồ đơn điệu, bộ tải kết
//             cấu OpenGL ES 2.0 và bộ kết xuất bề mặt ANativeWindow hai luồng.
// ============================================================================

#pragma once

#include "pl_droidsonroids_gif_types.h"

namespace opencut {
namespace gif {

// ============================================================================
// 1. Monotonic Clock & Invalidation Delay Math (0x009548..0x009680)
//    Đồng hồ đơn điệu & Toán học tính độ trễ làm mới (0x009548..0x009680)
// ============================================================================

// Convert (tv_sec, tv_nsec) to milliseconds using AArch64 smulh 0x431bde82d7b634db >> 18 (@ 0x00964c..0x00966c)
// Chuyển đổi (tv_sec, tv_nsec) sang mili-giây bằng phép nhân smulh 0x431bde82d7b634db >> 18
int64_t timespecToMsExact(int64_t tv_sec, int64_t tv_nsec) noexcept;

// Read CLOCK_MONOTONIC_RAW (clockid = 4) and return milliseconds (@ 0x009610..0x009680)
// Đọc đồng hồ CLOCK_MONOTONIC_RAW (id = 4) và trả về mili-giây (@ 0x009610..0x009680)
int64_t getRealTime() noexcept;

// Calculate invalidation delay in ms scaled by info->speedFactor (@ 0x009548..0x00960c)
// Tính toán độ trễ làm mới khung hình (ms) chia theo hệ số tốc độ speedFactor (@ 0x009548..0x00960c)
int64_t calculateInvalidationDelay(GifInfo* info, int64_t renderStartTime, uint64_t frameDuration) noexcept;

// ============================================================================
// 2. ARGB8888 Canvas Preparation, Disposal & Blit Engine (0x005030..0x0055f4)
//    Chuẩn bị khung vẽ ARGB8888, Xóa khung hình & Vẽ điểm ảnh (0x005030..0x0055f4)
// ============================================================================

// Initialize frame 0 canvas with transparent black or SBackGroundColor (@ 0x005030..0x00511c)
// Khởi tạo khung vẽ ở khung hình 0 bằng màu đen trong suốt hoặc màu nền SBackGroundColor
void prepareCanvas(argb* bm, GifInfo* info) noexcept;

// Apply previous frame disposal (DISPOSE_BACKGROUND / DISPOSE_PREVIOUS), save backup if
// current frame is DISPOSE_PREVIOUS, and blit indexed pixels to ARGB8888 (@ 0x005120..0x0054b0)
// Áp dụng phương thức xóa của khung trước, sao lưu nếu khung hiện tại là DISPOSE_PREVIOUS
// và ánh xạ bảng màu sang ARGB8888 (@ 0x005120..0x0054b0)
void drawFrame(argb* bm, GifInfo* info) noexcept;

// Advance currentIndex / currentLoop and return current frame duration (@ 0x0054b4..0x005550)
// Tăng chỉ số khung hình / vòng lặp hiện tại và trả về thời lượng khung hình (@ 0x0054b4..0x005550)
uint64_t getFrameDuration(GifInfo* info) noexcept;

// Draw current frame and advance animation state (@ 0x005554..0x0055f4)
// Vẽ khung hình hiện tại và chuyển trạng thái hoạt ảnh (@ 0x005554..0x0055f4)
uint64_t drawNextBitmap(argb* bm, GifInfo* info) noexcept;

// ============================================================================
// 3. GifInfo Lifecycle, Seeking, Options & Memory Accounting
//    Vòng đời GifInfo, Tua khung hình, Tùy chọn & Kiểm kê bộ nhớ
// ============================================================================

// Allocate and initialize GifInfo from DecodeSource (@ 0x007a30..0x007c30)
// Cấp phát và khởi tạo GifInfo từ DecodeSource (@ 0x007a30..0x007c30)
GifInfo* createGifInfo(DecodeSource* source, void* jniEnv) noexcept;

// Free GifInfo internal buffers and close GifFileType (@ 0x004fd8..0x00502c)
// Giải phóng các bộ đệm nội bộ của GifInfo và đóng GifFileType (@ 0x004fd8..0x00502c)
void cleanUp(GifInfo* info) noexcept;

// Rewind stream and reset animation state to frame 0 (@ 0x004380..0x0043bc)
// Tua lại luồng dữ liệu và đặt trạng thái hoạt ảnh về khung hình 0 (@ 0x004380..0x0043bc)
bool reset(GifInfo* info) noexcept;

// Seek to desiredIndex by fast-forwarding or rewinding and rendering intermediate frames (@ 0x004418..0x0045b4)
// Tua tới khung hình desiredIndex bằng cách giải mã hoặc bỏ qua các khung trung gian (@ 0x004418..0x0045b4)
void seek(GifInfo* info, uint64_t desiredIndex, void* pixels) noexcept;

// Configure sampleSize (1..65535) and isOpaque flag, rescaling all SavedImages (@ 0x007c4c..0x007cec)
// Cấu hình hệ số thu nhỏ sampleSize và cờ isOpaque, tính lại kích thước các SavedImages (@ 0x007c4c..0x007cec)
void setOptions(GifInfo* info, uint16_t sampleSize, bool isOpaque) noexcept;

// Sum all frame durations (NEON-vectorized 8-way loop in binary @ 0x00810c..0x0081d4)
// Tính tổng thời lượng toàn bộ các khung hình (@ 0x00810c..0x0081d4)
int32_t getDuration(const GifInfo* info) noexcept;

// Compute elapsed playback position in current loop (@ 0x0081ec..0x008308)
// Tính vị trí thời gian phát hiện tại trong vòng lặp (@ 0x0081ec..0x008308)
int32_t getCurrentPosition(const GifInfo* info) noexcept;

// Compute metadata memory footprint: 0x120 + ImageCount * 0x48 + strlen(comment) (@ 0x00830c..0x008354)
// Tính dung lượng bộ nhớ siêu dữ liệu: 0x120 + ImageCount * 0x48 + strlen(comment) (@ 0x00830c..0x008354)
int64_t getMetadataByteCount(const GifInfo* info) noexcept;

// Compute pixel allocation byte count: rasterSize + backupPtr size (@ 0x008358..0x008420)
// Tính dung lượng bộ nhớ điểm ảnh cấp phát: rasterSize + kích thước backupPtr (@ 0x008358..0x008420)
int64_t getAllocationByteCount(const GifInfo* info) noexcept;

// Restore saved animation state array (4 x int64_t) into GifInfo and canvas (@ 0x008530..0x0086ac)
// Khôi phục mảng trạng thái hoạt ảnh đã lưu (4 phần tử int64_t) vào GifInfo và khung vẽ (@ 0x008530..0x0086ac)
int32_t restoreSavedState(GifInfo* info, const int64_t* savedState, size_t stateLen, void* pixels) noexcept;

// ============================================================================
// 4. OpenGL ES 2.0 & ANativeWindow Surface Helpers (0x0087d8..0x009544)
//    Hỗ trợ kết cấu OpenGL ES 2.0 & bề mặt ANativeWindow (0x0087d8..0x009544)
// ============================================================================

// Allocate TexImageDescriptor (0x40 bytes) and RGBA8888 frameBuffer (@ 0x008920..0x0089dc)
// Cấp phát TexImageDescriptor (64 byte) và bộ đệm khung hình RGBA8888 (@ 0x008920..0x0089dc)
int initTexImageDescriptor(GifInfo* info) noexcept;

// Release TexImageDescriptor and its frameBuffer (@ 0x008aa8..0x008b18)
// Giải phóng TexImageDescriptor và bộ đệm khung hình (@ 0x008aa8..0x008b18)
void releaseTexImageDescriptor(GifInfo* info, void* jniEnv) noexcept;

// Step one GL frame decode + draw into TexImageDescriptor->frameBuffer (@ 0x008b1c..0x008c08)
// Thực hiện một bước giải mã và vẽ khung hình GL vào TexImageDescriptor->frameBuffer (@ 0x008b1c..0x008c08)
int64_t stepTexImageFrame(GifInfo* info) noexcept;

} // namespace gif
} // namespace opencut
