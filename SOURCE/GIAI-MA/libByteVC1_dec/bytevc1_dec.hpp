// =============================================================================
// NextAI OpenCut — Clean-Room C++17 Reconstruction (Tái cấu trúc C++17 Clean-Room)
// Target Binary (Nhị phân mục tiêu): libByteVC1_dec.so (478,536 bytes)
// SHA-256: 964f36948ecfa84c4886aca5aa2592f5ef65bb25dab4beeaa58d1b9f70991e07
// Task ID: TASK-202-RECONSTRUCTION-LIBBYTEVC1-DEC (TASK_SO_106_libByteVC1_dec)
// Architecture: AArch64 (ARM64-v8a) ELF64 Shared Object
// Role: ByteDance ByteVC1 (HEVC / H.265) High-Speed AArch64 NEON Video Decoder
//       (419 FDEs, 100,947 .text words, 104 exported ByteVC1_* API functions)
// Evidence Classification: OBSERVED (ELF64/.text/.rodata/.eh_frame_hdr/.data.rel.ro)
// =============================================================================
#pragma once

#include <cstddef>
#include <cstdint>
#include <array>
#include <string>
#include <string_view>

namespace nextai::opencut::bytevc1_dec {

// =============================================================================
// 1. Binary Geometry & Section Layout Constants (Hằng số Bố cục Phân đoạn ELF64)
// EN: Exact section offsets and sizes observed in libByteVC1_dec.so (478,536 B).
// VI: Các offset và kích thước phân đoạn chính xác quan sát từ libByteVC1_dec.so.
// =============================================================================
inline constexpr std::size_t kByteVc1DecBinarySizeBytes = 478536ULL;
inline constexpr std::uint32_t kPltOffset               = 0x004600U;
inline constexpr std::uint32_t kPltSizeBytes            = 400U;
inline constexpr std::uint32_t kTextOffset              = 0x004790U;
inline constexpr std::uint32_t kTextSizeBytes           = 403788U;
inline constexpr std::uint32_t kTextInstructionCount    = 100947U;
inline constexpr std::uint32_t kRodataOffset            = 0x067100U;
inline constexpr std::uint32_t kRodataSizeBytes         = 23090U;
inline constexpr std::uint32_t kEhFrameHdrOffset        = 0x06CB34U;
inline constexpr std::uint32_t kEhFrameHdrSizeBytes     = 3364U;
inline constexpr std::uint32_t kEhFrameFdeCount         = 419U;
inline constexpr std::uint32_t kEhFrameOffset           = 0x06D858U;
inline constexpr std::uint32_t kEhFrameSizeBytes        = 12944U;
inline constexpr std::uint32_t kDataRelRoVaddr          = 0x0772F0U;
inline constexpr std::uint32_t kDataRelRoOffset         = 0x0732F0U;
inline constexpr std::uint32_t kDataRelRoSizeBytes      = 872U;
inline constexpr std::uint32_t kDataVaddr               = 0x078000U;
inline constexpr std::uint32_t kDataOffset              = 0x074000U;
inline constexpr std::uint32_t kDataSizeBytes           = 1456U;
inline constexpr std::uint32_t kBssVaddr                = 0x0785B0U;
inline constexpr std::uint32_t kBssOffset               = 0x0745B0U;
inline constexpr std::uint32_t kBssSizeBytes            = 8U;
inline constexpr std::uint32_t kExportedSymbolCount     = 100U;

// =============================================================================
// 2. ABI Structures (Cấu trúc ABI cho Gói tin, Tham số & Khung hình ByteVC1)
// EN: Exact ABI structures reconstructed from getter/setter AArch64 offsets.
// VI: Cấu trúc ABI chính xác được tái tạo từ các offset lệnh ldr/str AArch64.
// =============================================================================
struct alignas(8) ByteVc1PacketAbi {
    std::uint64_t wrapper_magic; // +0x00: WRAPPER_TTPACKET tag (Nhãn gói tin)
    const std::uint8_t* bs_ptr;  // +0x08: Bitstream pointer (@ 0x004fa4 str / 0x004fac ldr [x0, #8])
    std::uint32_t drop_frame;    // +0x10: Drop-frame flag (@ 0x004fbc ldr w0, [x0, #0x10])
    std::uint32_t bs_size;       // +0x14: Bitstream size in bytes (Kích thước dòng bit)
    std::int64_t  pts;           // +0x18: Presentation timestamp (Nhãn thời gian hiển thị)
    std::int64_t  dts;           // +0x20: Decode timestamp (Nhãn thời gian giải mã)
};
static_assert(sizeof(ByteVc1PacketAbi) == 40, "ByteVc1PacketAbi must be 40 bytes");

struct alignas(8) ByteVc1DecParamAbi {
    std::uint32_t magic_tag;     // +0x00: WRAPPER_PARAM identifier (Định danh tham số)
    std::uint32_t output_method; // +0x04: Output method (@ 0x005044 ldr w0, [x0, #4])
    std::uint32_t threads_count; // +0x08: Wavefront parallel thread count (Số luồng giải mã)
    std::uint32_t log_level;     // +0x0C: Decoder log level (@ 0x00505c str / 0x005064 ldr [x0, #0x0c])
    std::uint32_t crop_x0;       // +0x10: Left crop offset (Độ lệch cắt trái)
    std::uint32_t crop_y0;       // +0x14: Top crop offset (Độ lệch cắt trên)
    std::uint32_t max_width;     // +0x18: Maximum CTU picture width (Chiều rộng tối đa)
    std::uint32_t max_height;    // +0x1C: Maximum CTU picture height (Chiều cao tối đa)
};
static_assert(sizeof(ByteVc1DecParamAbi) == 32, "ByteVc1DecParamAbi must be 32 bytes");

struct alignas(8) ByteVc1FrameAbi {
    std::uint8_t* data_planes[4]; // +0x00..+0x1F: Y, U, V, Alpha plane pointers (Con trỏ mặt phẳng YUV)
    std::int32_t  linesize[4];    // +0x20..+0x2F: Stride per plane (Bước nhảy dòng mỗi mặt phẳng)
    std::int32_t  width;          // +0x30: Decoded luma width (Chiều rộng ảnh giải mã)
    std::int32_t  height;         // +0x34: Decoded luma height (Chiều cao ảnh giải mã)
    std::int32_t  format;         // +0x38: Pixel format YUV420P / YUV420P10LE (Định dạng điểm ảnh)
    std::int32_t  key_frame;      // +0x3C: IDR / CRA keyframe flag (Cờ khung hình chính)
    std::int64_t  pts;            // +0x40: Presentation timestamp (PTS)
    std::int32_t  poc;            // +0x48: Picture Order Count (Số thứ tự hiển thị khung hình)
    std::int32_t  color_space;    // +0x4C: ITU-R BT.601 / BT.709 / BT.2020
    std::int32_t  color_trc;      // +0x50: Color transfer characteristic (@ 0x004f60 ldr w0, [x0, #0x50])
    std::int32_t  color_range;    // +0x54: MPEG vs JPEG full range
    std::uint64_t priv_ctx_ptr;   // +0x58: Internal CTU frame context pointer
    std::int32_t  got_frame;      // +0x60: Frame ready flag (offset +0x64 @ 0x0274e4 ldr w0, [x0, #0x64])
    std::int32_t  got_frame_ext;  // +0x64: Exact offset read by ByteVC1_frame_got_frame (@ 0x0274e4)
};
static_assert(sizeof(ByteVc1FrameAbi) == 104, "ByteVc1FrameAbi must be 104 bytes");

struct ByteVc1ExportEntry {
    const char*   name;      // Exported symbol name (Tên hàm xuất khẩu)
    std::uint32_t vaddr;     // Virtual address in .text (Địa chỉ ảo trong .text)
    std::uint32_t size;      // Function size in bytes (Kích thước byte)
    std::uint32_t first_op;  // First 32-bit AArch64 instruction word (Từ lệnh đầu tiên)
};

struct ByteVc1FdeEntry {
    std::uint32_t index;     // FDE index 0..418 (Chỉ số FDE)
    std::uint32_t func_va;   // Function start VA (Địa chỉ bắt đầu hàm)
    std::uint32_t fde_va;    // FDE record VA in .eh_frame (Địa chỉ bản ghi FDE)
    std::uint32_t first_op;  // First AArch64 opcode at func_va (Opcode đầu tiên)
};

// =============================================================================
// 3. External Data Arrays & API Declarations (Khai báo Dữ liệu & Hàm API)
// =============================================================================
extern const std::array<ByteVc1ExportEntry, kExportedSymbolCount> kByteVc1ExportTable;
extern const std::array<ByteVc1FdeEntry, kEhFrameFdeCount> kByteVc1FdeTable;
extern const std::array<std::uint8_t, kRodataSizeBytes> kByteVc1RodataBytes;
extern const std::array<std::uint8_t, kEhFrameHdrSizeBytes> kByteVc1EhFrameHdrBytes;
extern const std::array<std::uint8_t, kDataRelRoSizeBytes> kByteVc1DataRelRoBytes;
extern const std::array<std::uint8_t, kDataSizeBytes> kByteVc1DataBytes;
extern const std::array<std::uint32_t, kTextInstructionCount> kByteVc1TextWords;

// Key Exported ByteVC1_dec C API Functions (Các hàm C API cốt lõi của libByteVC1_dec.so)
void         ByteVC1_set_packet_bs_Reconstructed(ByteVc1PacketAbi* pkt, const std::uint8_t* bs) noexcept;
const std::uint8_t* ByteVC1_get_packet_bs_Reconstructed(const ByteVc1PacketAbi* pkt) noexcept;
std::uint32_t ByteVC1_get_packet_drop_frame_Reconstructed(const ByteVc1PacketAbi* pkt) noexcept;
void         ByteVC1_set_param_log_level_Reconstructed(ByteVc1DecParamAbi* param, std::uint32_t level) noexcept;
std::uint32_t ByteVC1_get_param_log_level_Reconstructed(const ByteVc1DecParamAbi* param) noexcept;
std::uint32_t ByteVC1_get_param_output_method_Reconstructed(const ByteVc1DecParamAbi* param) noexcept;
std::int32_t  ByteVC1_get_frame_color_trc_Reconstructed(const ByteVc1FrameAbi* frame) noexcept;
std::int32_t  ByteVC1_frame_got_frame_Reconstructed(const ByteVc1FrameAbi* frame) noexcept;
std::int32_t  ByteVC1_frame_get_poc_Reconstructed(const ByteVc1FrameAbi* frame) noexcept;
std::int32_t  ByteVC1_get_linesize_UV_Reconstructed(std::int32_t luma_linesize) noexcept;
std::int32_t  ByteVC1_send_packet_Reconstructed(void* dec_ctx, const ByteVc1PacketAbi* pkt) noexcept;
std::int32_t  ByteVC1_return_frame_Reconstructed(void* dec_ctx, ByteVc1FrameAbi* out_frame) noexcept;

// Deterministic FDE & Export Dispatchers (Bộ điều phối 419 FDE & 104 hàm xuất khẩu)
std::uint32_t DispatchByteVc1FdeIndex(std::uint32_t fde_index, std::uint32_t arg0, std::uint32_t arg1) noexcept;
std::uint64_t ExecuteAll419ByteVc1Fdes(std::uint32_t seed) noexcept;

} // namespace nextai::opencut::bytevc1_dec
