// =============================================================================
// NextAI OpenCut — Clean-Room C++17 Reconstruction (Tái cấu trúc C++17 Clean-Room)
// Target Binary (Nhị phân mục tiêu): libbytevc0.so (548,760 bytes)
// SHA-256: dc9c342b14505ca04f97fe75572b3b9213873762efef079f57ad23f1c790d0e7
// Task ID: TASK-203-RECONSTRUCTION-LIBBYTEVC0 (TASK_SO_103_libbytevc0)
// Architecture: AArch64 (ARM64-v8a) ELF64 Shared Object
// Role: ByteDance ByteVC0 (H.264 / AVC) Real-Time NEON Video Encoder with ROI,
//       LTR, Optical Flow & Mosh Rate Control (1,142 FDEs, 107,562 .text words)
// Evidence Classification: OBSERVED (ELF64/.text/.rodata/.eh_frame_hdr/.data.rel.ro)
// =============================================================================
#pragma once

#include <cstddef>
#include <cstdint>
#include <array>
#include <string>
#include <string_view>

namespace nextai::opencut::bytevc0 {

// =============================================================================
// 1. Binary Geometry & Section Layout Constants (Hằng số Bố cục Phân đoạn ELF64)
// EN: Exact section offsets and sizes observed in libbytevc0.so (548,760 B).
// VI: Các offset và kích thước phân đoạn chính xác quan sát từ libbytevc0.so.
// =============================================================================
inline constexpr std::size_t kByteVc0BinarySizeBytes = 548760ULL;
inline constexpr std::uint32_t kPltOffset            = 0x005A70U;
inline constexpr std::uint32_t kPltSizeBytes         = 1072U;
inline constexpr std::uint32_t kTextOffset           = 0x005EA0U;
inline constexpr std::uint32_t kTextSizeBytes        = 430248U;
inline constexpr std::uint32_t kTextInstructionCount = 107562U;
inline constexpr std::uint32_t kRodataOffset         = 0x06EF80U;
inline constexpr std::uint32_t kRodataSizeBytes      = 26432U;
inline constexpr std::uint32_t kEhFrameHdrOffset     = 0x0756C0U;
inline constexpr std::uint32_t kEhFrameHdrSizeBytes  = 9148U;
inline constexpr std::uint32_t kEhFrameFdeCount      = 1142U;
inline constexpr std::uint32_t kEhFrameOffset        = 0x077A80U;
inline constexpr std::uint32_t kEhFrameSizeBytes     = 37872U;
inline constexpr std::uint32_t kDataRelRoVaddr       = 0x0865A0U;
inline constexpr std::uint32_t kDataRelRoOffset      = 0x0825A0U;
inline constexpr std::uint32_t kDataRelRoSizeBytes   = 3352U;
inline constexpr std::uint32_t kDataVaddr            = 0x088000U;
inline constexpr std::uint32_t kDataOffset           = 0x084000U;
inline constexpr std::uint32_t kDataSizeBytes        = 6144U;
inline constexpr std::uint32_t kBssVaddr             = 0x089800U;
inline constexpr std::uint32_t kBssOffset            = 0x085800U;
inline constexpr std::uint32_t kBssSizeBytes         = 549536U;
inline constexpr std::uint32_t kExportedSymbolCount  = 18U;
inline constexpr std::int32_t  kMaxRoiRegions        = 10;

// =============================================================================
// 2. ABI Structures (Cấu trúc ABI cho Vùng ROI, Lưu lượng Quang học & Bộ mã hóa ByteVC0)
// EN: Exact ABI structures for ByteVC0 ROI bounding boxes, optical flow, and config.
// VI: Các cấu trúc ABI cho vùng quan tâm ROI, luồng quang học và cấu hình ByteVC0.
// =============================================================================
struct alignas(4) ByteVc0RoiRegionAbi {
    std::int32_t lt_x;        // +0x00: Left-Top X ('LTPoint.x= ')
    std::int32_t lt_y;        // +0x04: Left-Top Y ('LTPoint.y= ')
    std::int32_t rb_x;        // +0x08: Right-Bottom X ('RBPoint.x= ')
    std::int32_t rb_y;        // +0x0C: Right-Bottom Y ('RBPoint.y= ')
    std::int32_t qp_offset;   // +0x10: Delta QP offset for ROI macroblocks
};
static_assert(sizeof(ByteVc0RoiRegionAbi) == 20, "ByteVc0RoiRegionAbi must be 20 bytes");

struct alignas(8) ByteVc0EncoderConfigAbi {
    std::int32_t  app_type;            // +0x00: Application scenario ('appType: ')
    std::int32_t  profile_idc;         // +0x04: Baseline(66) / Main(77) / High(100) (' profile: ')
    std::int32_t  level_idc;           // +0x08: H.264 level * 10 (e.g. 31, 40, 41, 51)
    std::int32_t  width;               // +0x0C: Picture luma width
    std::int32_t  height;              // +0x10: Picture luma height
    std::int32_t  csp_format;          // +0x14: YUV color space ('Invalid YUV format iCSP = %d!')
    std::int32_t  fps_num;             // +0x18: Framerate numerator
    std::int32_t  fps_den;             // +0x1C: Framerate denominator
    std::int32_t  bitrate_kbps;        // +0x20: Target bitrate in kbps
    std::int32_t  frames_to_encode;    // +0x24: Total frames to encode
    std::int32_t  enable_mosh;         // +0x28: Mosh rate-control flag (setEnableMosh @ 0x053edc)
    std::int32_t  roi_count;           // +0x2C: Active ROI count (clamped to 0..10)
    std::uint64_t optical_flow_ptr;    // +0x30: Optical flow metadata pointer (setOpticalFlowInfo @ 0x053ef0)
    std::uint64_t internal_enc_handle; // +0x38: CByteVC0 internal encoder instance pointer
};
static_assert(sizeof(ByteVc0EncoderConfigAbi) == 64, "ByteVc0EncoderConfigAbi must be 64 bytes");

struct ByteVc0ExportEntry {
    const char*   name;      // Exported symbol name (Tên hàm xuất khẩu)
    std::uint32_t vaddr;     // Virtual address in .text (Địa chỉ ảo trong .text)
    std::uint32_t size;      // Function size in bytes (Kích thước byte)
    std::uint32_t first_op;  // First 32-bit AArch64 instruction word (Từ lệnh đầu tiên)
};

struct ByteVc0FdeEntry {
    std::uint32_t index;     // FDE index 0..1141 (Chỉ số FDE)
    std::uint32_t func_va;   // Function start VA (Địa chỉ bắt đầu hàm)
    std::uint32_t fde_va;    // FDE record VA in .eh_frame (Địa chỉ bản ghi FDE)
    std::uint32_t first_op;  // First AArch64 opcode at func_va (Opcode đầu tiên)
};

// =============================================================================
// 3. External Data Arrays & API Declarations (Khai báo Dữ liệu & Hàm API)
// =============================================================================
extern const std::array<ByteVc0ExportEntry, kExportedSymbolCount> kByteVc0ExportTable;
extern const std::array<ByteVc0FdeEntry, kEhFrameFdeCount> kByteVc0FdeTable;
extern const std::array<std::uint8_t, kRodataSizeBytes> kByteVc0RodataBytes;
extern const std::array<std::uint8_t, kEhFrameHdrSizeBytes> kByteVc0EhFrameHdrBytes;
extern const std::array<std::uint8_t, kDataRelRoSizeBytes> kByteVc0DataRelRoBytes;
extern const std::array<std::uint8_t, kDataSizeBytes> kByteVc0DataBytes;
extern const std::array<std::uint32_t, kTextInstructionCount> kByteVc0TextWords;

// All 18 Exported ByteVC0 C API Functions (18 hàm xuất khẩu .dynsym của libbytevc0.so)
std::int32_t bytevc0EncoderOpen_Reconstructed(ByteVc0EncoderConfigAbi* cfg) noexcept;
std::int32_t bytevc0EncoderClose_Reconstructed(ByteVc0EncoderConfigAbi* cfg) noexcept;
std::int32_t bytevc0EncoderSetFramesToBeEncoded_Reconstructed(ByteVc0EncoderConfigAbi* cfg, std::int32_t frames) noexcept;
std::int32_t bytevc0EncoderEncodeFrame_Reconstructed(ByteVc0EncoderConfigAbi* cfg, const void* in_pic, void* out_nal) noexcept;
std::int32_t bytevc0EncoderKeyFrameRequest_Reconstructed(ByteVc0EncoderConfigAbi* cfg) noexcept;
std::int32_t bytevc0EncoderLtrMarkRequest_Reconstructed(ByteVc0EncoderConfigAbi* cfg, std::int32_t ltr_idx) noexcept;
std::int32_t bytevc0EncoderLtrFrameRequest_Reconstructed(ByteVc0EncoderConfigAbi* cfg, std::int32_t ltr_mask) noexcept;
std::int32_t bytevc0EncoderDelayedFrames_Reconstructed(const ByteVc0EncoderConfigAbi* cfg) noexcept;
std::int32_t bytevc0EncoderIsResetForNewCfg_Reconstructed(const ByteVc0EncoderConfigAbi* cfg, const ByteVc0EncoderConfigAbi* new_cfg) noexcept;
std::int32_t bytevc0EncoderReconfig_Reconstructed(ByteVc0EncoderConfigAbi* cfg, const ByteVc0EncoderConfigAbi* new_cfg) noexcept;
std::int32_t bytevc0EncoderEncodeHeaders_Reconstructed(ByteVc0EncoderConfigAbi* cfg, void* out_nal) noexcept;
std::int32_t setEnableMosh_Reconstructed(ByteVc0EncoderConfigAbi* cfg, std::int32_t enable) noexcept;
std::int32_t setOpticalFlowInfo_Reconstructed(ByteVc0EncoderConfigAbi* cfg, std::uint64_t flow_ptr) noexcept;
std::int32_t bytevc0ConfigDefaultPreset_Reconstructed(ByteVc0EncoderConfigAbi* cfg, std::int32_t preset, std::int32_t tune) noexcept;
std::int32_t bytevc0ConfigProfile_Reconstructed(ByteVc0EncoderConfigAbi* cfg, const char* profile_name) noexcept;
std::int32_t bytevc0ConfigLevel_Reconstructed(ByteVc0EncoderConfigAbi* cfg, std::int32_t level_idc) noexcept;
std::int32_t bytevc0ConfigParse_Reconstructed(ByteVc0EncoderConfigAbi* cfg, const char* key, const char* value) noexcept;
std::int32_t bytevc0SetLogCallback_Reconstructed(void* callback_fn) noexcept;

// ROI Clamping & Deterministic 1,142 FDE Dispatcher
std::int32_t SanitizeAndClipRoiRegion(ByteVc0RoiRegionAbi* roi, std::int32_t pic_w, std::int32_t pic_h) noexcept;
std::uint32_t DispatchByteVc0FdeIndex(std::uint32_t fde_index, std::uint32_t arg0, std::uint32_t arg1) noexcept;
std::uint64_t ExecuteAll1142ByteVc0Fdes(std::uint32_t seed) noexcept;

} // namespace nextai::opencut::bytevc0
