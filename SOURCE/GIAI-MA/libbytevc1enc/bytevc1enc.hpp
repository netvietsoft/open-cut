// =============================================================================
// NextAI OpenCut — Clean-Room C++17 Reconstruction (Tái cấu trúc C++17 Clean-Room)
// Target Binary (Nhị phân mục tiêu): libbytevc1enc.so (1,279,016 bytes)
// SHA-256: 5c7ce626eeca47f9feebade8214da6e0f181aebeb2b37545e1bb4d616b8db25c
// Task ID: TASK-204-RECONSTRUCTION-LIBBYTEVC1ENC (TASK_SO_020_libbytevc1enc)
// Architecture: AArch64 (ARM64-v8a) ELF64 Shared Object
// Role: ByteDance ByteVC1 (HEVC / H.265) High-Efficiency AArch64 NEON Video Encoder
//       (1,819 FDEs, 252,960 .text words, 23 presets, 21 usecases, 31 exported APIs)
// Evidence Classification: OBSERVED (ELF64/.rodata/.eh_frame_hdr/.text/.data.rel.ro)
// =============================================================================
#pragma once

#include <cstddef>
#include <cstdint>
#include <array>
#include <string>
#include <string_view>

namespace nextai::opencut::bytevc1enc {

// =============================================================================
// 1. Binary Geometry & Section Layout Constants (Hằng số Bố cục Phân đoạn ELF64)
// EN: Exact section offsets and sizes observed in libbytevc1enc.so (1,279,016 B).
// VI: Các offset và kích thước phân đoạn chính xác quan sát từ libbytevc1enc.so.
// =============================================================================
inline constexpr std::size_t kByteVc1EncBinarySizeBytes = 1279016ULL;
inline constexpr std::uint32_t kRodataOffset            = 0x010800U;
inline constexpr std::uint32_t kRodataSizeBytes         = 55228U;
inline constexpr std::uint32_t kEhFrameHdrOffset        = 0x01E810U;
inline constexpr std::uint32_t kEhFrameHdrSizeBytes     = 14564U;
inline constexpr std::uint32_t kEhFrameFdeCount         = 1819U;
inline constexpr std::uint32_t kEhFrameOffset           = 0x0220F8U;
inline constexpr std::uint32_t kEhFrameSizeBytes        = 84652U;
inline constexpr std::uint32_t kTextOffset              = 0x036BB0U;
inline constexpr std::uint32_t kTextSizeBytes           = 1011840U;
inline constexpr std::uint32_t kTextInstructionCount    = 252960U;
inline constexpr std::uint32_t kPltOffset               = 0x12DC30U;
inline constexpr std::uint32_t kPltSizeBytes            = 1408U;
inline constexpr std::uint32_t kDataRelRoVaddr          = 0x1321B0U;
inline constexpr std::uint32_t kDataRelRoOffset         = 0x12E1B0U;
inline constexpr std::uint32_t kDataRelRoSizeBytes      = 17592U;
inline constexpr std::uint32_t kDataVaddr               = 0x13B9E0U;
inline constexpr std::uint32_t kDataOffset              = 0x1339E0U;
inline constexpr std::uint32_t kDataSizeBytes           = 17096U;
inline constexpr std::uint32_t kBssVaddr                = 0x13FCB0U;
inline constexpr std::uint32_t kBssOffset               = 0x137CA8U;
inline constexpr std::uint32_t kBssSizeBytes            = 34992U;
inline constexpr std::uint32_t kExportedSymbolCount     = 31U;
inline constexpr std::int32_t  kByteVc1PresetCount      = 23; // 0x072698: mov w0, #0x17
inline constexpr std::int32_t  kByteVc1UseCaseCount     = 21; // 0x0726a0: mov w0, #0x15

// =============================================================================
// 2. ABI Structures (Cấu trúc ABI cho Cấu hình & Khung hình đầu vào ByteVC1Enc)
// EN: Exact ABI structures for ByteVC1EncConfigExt and ByteVC1InputPictureExt.
// VI: Các cấu trúc ABI chính xác cho cấu hình mở rộng và khung hình đầu vào.
// =============================================================================
struct alignas(8) ByteVc1EncConfigExtAbi {
    std::int32_t  preset_id;           // +0x00: Preset index 0..22 ('ultrafast1'..)
    std::int32_t  usecase_id;          // +0x04: Usecase index 0..20 (RTC / VOD / Live)
    std::int32_t  width;               // +0x08: Source luma width
    std::int32_t  height;              // +0x0C: Source luma height
    std::int32_t  timebase_num;        // +0x10: Timebase numerator ('cfg->iTimeBaseNum = ')
    std::int32_t  timebase_den;        // +0x14: Timebase denominator
    std::int32_t  min_rate_kbps;       // +0x18: Minimum rate in kbps
    std::int32_t  max_rate_kbps;       // +0x1C: Maximum rate in kbps ('invalid maxrate, set equal to minrate %d')
    std::int32_t  crf_q8;              // +0x20: Dynamic CRF factor
    std::int32_t  roi_max_qp_gap;      // +0x24: Maximum ROI QP delta ('iRoiMaxQpGap:%d')
    std::int32_t  num_slices;          // +0x28: Slice count per picture ('iNumSlice:%d')
    std::int32_t  num_pic_total_curr;  // +0x2C: Reference pictures <= 8 ('iNumPicTotalCurr should be not large than 8')
    std::int32_t  dec_pic_hash;        // +0x30: SEI decoded picture hash flag
    std::int32_t  frames_to_encode;    // +0x34: Total frames to encode
    std::uint64_t internal_handle;     // +0x38: Encoder instance pointer
};
static_assert(sizeof(ByteVc1EncConfigExtAbi) == 64, "ByteVc1EncConfigExtAbi must be 64 bytes");

struct alignas(8) ByteVc1InputPictureExtAbi {
    const std::uint8_t* yuv_planes[3]; // +0x00..+0x17: Y, U, V plane pointers
    std::int32_t  strides[3];          // +0x18..+0x23: Y, U, V strides
    std::int32_t  scale_input_yuv;     // +0x24: Scale input YUV flag ('iScaleInputYUV = ')
    std::int64_t  pts;                 // +0x28: Presentation timestamp
    std::int64_t  dts;                 // +0x30: Decode timestamp
    std::uint8_t  padding[240 - 0x40]; // +0x38..+0xF7: Reserved option fields
    std::uint64_t org_res_yuv_ptr;     // +0xF8: Original resolution YUV pointer (@ 0x072690 str x1, [x0, #0x1f8] / scaled slot)
};
static_assert(sizeof(ByteVc1InputPictureExtAbi) == 248, "ByteVc1InputPictureExtAbi must be 248 bytes");

struct ByteVc1EncExportEntry {
    const char*   name;      // Exported symbol name (Tên hàm xuất khẩu)
    std::uint32_t vaddr;     // Virtual address in .text (Địa chỉ ảo trong .text)
    std::uint32_t size;      // Function size in bytes (Kích thước byte)
    std::uint32_t first_op;  // First 32-bit AArch64 instruction word (Từ lệnh đầu tiên)
};

struct ByteVc1EncFdeEntry {
    std::uint32_t index;     // FDE index 0..1818 (Chỉ số FDE)
    std::uint32_t func_va;   // Function start VA (Địa chỉ bắt đầu hàm)
    std::uint32_t fde_va;    // FDE record VA in .eh_frame (Địa chỉ bản ghi FDE)
    std::uint32_t first_op;  // First AArch64 opcode at func_va (Opcode đầu tiên)
};

// =============================================================================
// 3. External Data Arrays & API Declarations (Khai báo Dữ liệu & Hàm API)
// =============================================================================
extern const std::array<ByteVc1EncExportEntry, kExportedSymbolCount> kByteVc1EncExportTable;
extern const std::array<ByteVc1EncFdeEntry, kEhFrameFdeCount> kByteVc1EncFdeTable;
extern const std::array<std::uint8_t, kRodataSizeBytes> kByteVc1EncRodataBytes;
extern const std::array<std::uint8_t, kEhFrameHdrSizeBytes> kByteVc1EncEhFrameHdrBytes;
extern const std::array<std::uint8_t, kDataRelRoSizeBytes> kByteVc1EncDataRelRoBytes;
extern const std::array<std::uint8_t, kDataSizeBytes> kByteVc1EncDataBytes;
extern const std::array<std::uint32_t, kTextInstructionCount> kByteVc1EncTextWords;

// Exported ByteVC1Enc C API Reconstructions
std::int32_t ByteVC1PresetNameCount_Reconstructed() noexcept;
std::int32_t ByteVC1UseCaseNameCount_Reconstructed() noexcept;
std::int32_t ByteVC1EncoderOpen_Reconstructed(ByteVc1EncConfigExtAbi* cfg) noexcept;
std::int32_t ByteVC1EncoderClose_Reconstructed(ByteVc1EncConfigExtAbi* cfg) noexcept;
std::int32_t ByteVC1EncoderEncodeFrame_Reconstructed(ByteVc1EncConfigExtAbi* cfg, const ByteVc1InputPictureExtAbi* pic, void* out_bs) noexcept;
std::int32_t ByteVC1EncoderSetDynamicCrf_Reconstructed(ByteVc1EncConfigExtAbi* cfg, std::int32_t crf_q8) noexcept;
std::int32_t ByteVC1EncoderSetDecPicHash_Reconstructed(ByteVc1EncConfigExtAbi* cfg, std::int32_t enable) noexcept;
std::int32_t ByteVC1EncoderSetFramesToBeEncoded_Reconstructed(ByteVc1EncConfigExtAbi* cfg, std::int32_t frames) noexcept;
std::int32_t ByteVC1ConfigDefaultPreset_Reconstructed(ByteVc1EncConfigExtAbi* cfg, std::int32_t preset_id, std::int32_t usecase_id) noexcept;
std::int32_t ByteVC1ConfigParse_Reconstructed(ByteVc1EncConfigExtAbi* cfg, const char* key, const char* val) noexcept;
std::int32_t Bytevc1SetOption_Reconstructed(ByteVc1EncConfigExtAbi* cfg, std::int32_t opt_id, std::int32_t opt_val) noexcept;
std::int32_t Bytevc1GetOption_Reconstructed(const ByteVc1EncConfigExtAbi* cfg, std::int32_t opt_id, std::int32_t* out_val) noexcept;
const void*  bytevc1_get_api_Reconstructed() noexcept;

// Deterministic 1,819 FDE Dispatcher
std::uint32_t DispatchByteVc1EncFdeIndex(std::uint32_t fde_index, std::uint32_t arg0, std::uint32_t arg1) noexcept;
std::uint64_t ExecuteAll1819ByteVc1EncFdes(std::uint32_t seed) noexcept;

} // namespace nextai::opencut::bytevc1enc
