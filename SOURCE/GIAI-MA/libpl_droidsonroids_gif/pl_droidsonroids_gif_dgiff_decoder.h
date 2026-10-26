// ============================================================================
// File: pl_droidsonroids_gif_dgiff_decoder.h
// Target: libpl_droidsonroids_gif.so (42,464 bytes, ELF64 AArch64)
// Package: com.nextai.opencut (NextAI OpenCut Reconstruction)
// Task ID: TASK-096-RECONSTRUCTION-LIBPL_DROIDSONROIDS_GIF (TASK_SO_039)
// Evidence Classification: OBSERVED (Direct AArch64 Disassembly 0x0048a4..0x007a2c)
// Description (EN): Declarations for the embedded GIFLIB 5.1.4 LZW decoder,
//                   color map allocator, 4-pass interlace slurper, GIF89a
//                   extension block parser, and 4 input source rewind/read
//                   callbacks in libpl_droidsonroids_gif.so.
// Mô tả (VN): Khai báo cho bộ giải mã LZW GIFLIB 5.1.4 nhúng, bộ cấp phát bảng
//             màu, bộ đọc đan xen 4 lượt, bộ phân tích khối mở rộng GIF89a và
//             4 hàm đọc/tua lại nguồn đầu vào trong libpl_droidsonroids_gif.so.
// ============================================================================

#pragma once

#include "pl_droidsonroids_gif_types.h"

namespace opencut {
namespace gif {

// ============================================================================
// 1. Memory & ColorMap Management (0x007824..0x007a2c, 0x008098)
//    Quản lý bộ nhớ và bảng màu ColorMap (0x007824..0x007a2c, 0x008098)
// ============================================================================

// Safe overflow-checked reallocarray (@ 0x0079dc..0x007a2c)
// Cấp phát lại mảng có kiểm tra tràn số nguyên 64-bit (@ 0x0079dc..0x007a2c)
void* openbsd_reallocarray(void* optr, size_t nmemb, size_t size) noexcept;

// Allocate a ColorMapObject with (1 << bitsPerPixel) RGB entries (@ 0x00789c..0x007920)
// Cấp phát đối tượng bảng màu ColorMapObject (@ 0x00789c..0x007920)
ColorMapObject* GifMakeMapObject(uint8_t bitsPerPixel, const GifColorType* colorMap) noexcept;

// Free a ColorMapObject and its 256-entry RGB array (@ 0x007924..0x007950)
// Giải phóng đối tượng bảng màu ColorMapObject (@ 0x007924..0x007950)
void GifFreeMapObject(ColorMapObject* object) noexcept;

// Free SavedImage array and local ColorMaps (@ 0x007954..0x0079d8)
// Giải phóng mảng SavedImage và các bảng màu cục bộ (@ 0x007954..0x0079d8)
void GifFreeSavedImages(GifFileType* gifFile) noexcept;

// Close GifFileType and release all GIFLIB structures (@ 0x007824..0x007898)
// Đóng GifFileType và giải phóng toàn bộ cấu trúc GIFLIB (@ 0x007824..0x007898)
int DGifCloseFile(GifFileType* gifFile) noexcept;

// Initialize and retrieve the 256-entry grayscale fallback ColorMapObject (@ 0x007dc0..0x0080a0)
// Khởi tạo và truy xuất bảng màu xám 256 mức mặc định (@ 0x007dc0..0x0080a0)
ColorMapObject* initDefaultColorMap() noexcept;
void freeDefaultColorMap() noexcept;
ColorMapObject* getDefColorMap() noexcept;

// ============================================================================
// 2. GIFLIB 5.1.4 Stream & LZW Decompression Core (0x0066a8..0x007820)
//    Lõi đọc luồng và giải nén LZW GIFLIB 5.1.4 (0x0066a8..0x007820)
// ============================================================================

// Open GIF stream, verify "GIF" magic, and parse Logical Screen Descriptor (@ 0x0066a8..0x0067f8)
// Mở luồng GIF, xác minh chữ ký "GIF" và phân tích Logical Screen Descriptor (@ 0x0066a8..0x0067f8)
GifFileType* DGifOpen(void* userPtr, InputFunc readFunc, int* error) noexcept;

// Read Logical Screen Descriptor and optional Global Color Table (@ 0x0067fc..0x0069b8)
// Đọc Logical Screen Descriptor và bảng màu toàn cục (@ 0x0067fc..0x0069b8)
int DGifGetScreenDesc(GifFileType* gifFile) noexcept;

// Peek next GIF record type (',' = IMAGE, '!' = EXTENSION, ';' = TERMINATE) (@ 0x0069bc..0x006a80)
// Đọc loại bản ghi GIF tiếp theo (@ 0x0069bc..0x006a80)
int DGifGetRecordType(GifFileType* gifFile, GifRecordType* type) noexcept;

// Read Image Descriptor, optional Local Color Table, and initialize LZW (@ 0x006a84..0x006d64)
// Đọc Image Descriptor, bảng màu cục bộ và khởi tạo bộ giải mã LZW (@ 0x006a84..0x006d64)
int DGifGetImageDesc(GifFileType* gifFile, bool changeImageCount, uint64_t originalWidth, uint64_t originalHeight) noexcept;

// Initialize LZW decompression tables and clear prefix table to 0x1002 (@ 0x006d68..0x006e48)
// Khởi tạo bảng giải nén LZW và đặt bảng Prefix về 0x1002 (@ 0x006d68..0x006e48)
int DGifSetupDecompress(GifFileType* gifFile) noexcept;

// Decode LZW scanline pixels with reverse-stack NEON burst copy (@ 0x006e4c..0x007544)
// Giải mã dòng điểm ảnh LZW kèm sao chép ngược ngăn xếp bằng NEON (@ 0x006e4c..0x007544)
int DGifGetLine(GifFileType* gifFile, uint8_t* line, int lineLen) noexcept;

// Skip remaining LZW code sub-blocks in fast-forward mode (@ 0x007548..0x007614)
// Bỏ qua các khối con mã LZW còn lại trong chế độ tua nhanh (@ 0x007548..0x007614)
int DGifGetCodeNext(GifFileType* gifFile, uint8_t** codeBlock) noexcept;

// Read GIF89a Extension header and first sub-block (@ 0x007618..0x007714)
// Đọc tiêu đề phần mở rộng GIF89a và khối con đầu tiên (@ 0x007618..0x007714)
int DGifGetExtension(GifFileType* gifFile, int* extCode, uint8_t** extBlock) noexcept;

// Read subsequent sub-block of an active GIF89a Extension (@ 0x007718..0x0077dc)
// Đọc khối con tiếp theo của phần mở rộng GIF89a (@ 0x007718..0x0077dc)
int DGifGetExtensionNext(GifFileType* gifFile, uint8_t** extBlock) noexcept;

// Parse 4-byte GIF89a Graphic Control Extension block into FrameInfo (@ 0x0077e0..0x007820)
// Phân tích khối Graphic Control Extension 4 byte vào FrameInfo (@ 0x0077e0..0x007820)
int DGifExtensionToGCB(size_t gifExtensionLength, const uint8_t* gifExtension, FrameInfo* gcb) noexcept;

// Reset FrameInfo to default values (disposal=0, duration=100ms, transColor=-1) (@ 0x007c34..0x007c48)
// Đặt lại FrameInfo về giá trị mặc định (@ 0x007c34..0x007c48)
void resetFrameInfo(FrameInfo* info) noexcept;

// ============================================================================
// 3. Extension Parser, 4-Pass Interlace Slurper & Input Callbacks
//    Bộ phân tích phần mở rộng, đọc đan xen 4 lượt & hàm đọc nguồn đầu vào
// ============================================================================

// Parse GCB (0xF9), Comment (0xFE), and NETSCAPE2.0/ANIMEXTS1.0 (0xFF) (@ 0x004c90..0x004e4c)
// Phân tích phần mở rộng GCB (0xF9), Comment (0xFE) và NETSCAPE2.0/ANIMEXTS1.0 (0xFF)
int readExtensions(int extFunction, uint8_t* extData, GifInfo* info) noexcept;

// Slurp GIF records, decode or skip frame raster, and apply sampleSize (@ 0x0048a4..0x004c8c)
// Đọc bản ghi GIF, giải mã hoặc bỏ qua dữ liệu khung hình và áp dụng tỷ lệ thu nhỏ
void DDGifSlurp(GifInfo* info, bool decode, bool exitAfterFrame) noexcept;

// Input read callbacks (fileRead @ 0x006684, byteArrayRead @ 0x005d54, directByteBufferRead @ 0x005f0c)
// Các hàm đọc dữ liệu từ tệp, mảng byte và vùng nhớ trực tiếp
int fileRead(GifFileType* gif, uint8_t* bytes, int size) noexcept;
int byteArrayRead(GifFileType* gif, uint8_t* bytes, int size) noexcept;
int directByteBufferRead(GifFileType* gif, uint8_t* bytes, int size) noexcept;

// Rewind callbacks (fileRewind @ 0x00593c, streamRewind @ 0x005980, byteArray @ 0x005a14, buffer @ 0x005a30)
// Các hàm tua lại con trỏ đọc đầu vào về vị trí bắt đầu
int fileRewind(GifInfo* info) noexcept;
int streamRewind(GifInfo* info) noexcept;
int byteArrayRewind(GifInfo* info) noexcept;
int directByteBufferRewind(GifInfo* info) noexcept;

} // namespace gif
} // namespace opencut
