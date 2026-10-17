// ==============================================================================
// NextAI OpenCut - Reconstructed Media & Animation Engine
// Target Library: libanimax_bytevc1.so (lynx::animax & libByteVC1_dec.so)
// Component: ByteVC1 (HEVC/H.265) Codec & AnimaX Frame Types
// Language: C++17 / Native Android NDK
// Bilingual Documentation: English & Vietnamese (Song ngữ Anh - Việt)
// ==============================================================================

#ifndef NEXTAI_OPENCUT_ANIMAX_BYTEVC1_TYPES_H
#define NEXTAI_OPENCUT_ANIMAX_BYTEVC1_TYPES_H

#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>
#include <memory>
#include <functional>

namespace NextAI {
namespace OpenCut {
namespace AnimaxByteVC1 {

/**
 * @brief Lynx AnimaX Pixel Format Definitions.
 * Định nghĩa định dạng điểm ảnh trong động cơ Lynx AnimaX.
 */
enum class YUVPixFmt : int32_t {
    PIX_FMT_NONE = -1,
    PIX_FMT_YUV420P = 0,   ///< Planar Y, U, V 4:2:0 8-bit / Ba mặt phẳng rời Y, U, V
    PIX_FMT_NV12 = 1,       ///< Semi-planar Y plane + interleaved UV
    PIX_FMT_NV21 = 2,       ///< Semi-planar Y plane + interleaved VU (Android Camera standard)
    PIX_FMT_P010 = 3,       ///< 10-bit HDR format (P010 High-Efficiency Video Coding)
    PIX_FMT_RGBA = 4        ///< Packed RGBA
};

/**
 * @brief Lynx AnimaX YUV Channels.
 * Các kênh mặt phẳng dữ liệu YUV.
 */
enum class YUVChannelType : uint32_t {
    CHANNEL_Y = 0, ///< Luma plane (Độ sáng)
    CHANNEL_U = 1, ///< Cb Chroma plane (Sắc độ xanh lam)
    CHANNEL_V = 2  ///< Cr Chroma plane (Sắc độ đỏ)
};

/**
 * @brief Lynx AnimaX Logging Level (offset 0x00de5).
 * Cấp độ ghi nhật ký Lynx AnimaX.
 */
enum class AnimaXLogLevel : int32_t {
    LOG_VERBOSE = 0,
    LOG_DEBUG = 1,
    LOG_INFO = 2,
    LOG_WARN = 3,
    LOG_ERROR = 4,
    LOG_FATAL = 5
};

/**
 * @brief Opaque types for ByteDance ByteVC1 native library.
 * Kiểu đối tượng nội bộ của thư viện ByteDance ByteVC1.
 */
typedef void* ByteVC1Handle;
typedef void* ByteVC1Param;
typedef void* ByteVC1Packet;
typedef void* ByteVC1Frame;

/**
 * @brief Function pointer signatures for libByteVC1_dec.so symbols.
 * Chữ ký con trỏ hàm cho 28 ký hiệu từ thư viện libByteVC1_dec.so.
 */
typedef const char* (*Fn_ByteVC1_get_version)();
typedef void (*Fn_ByteVC1_set_log_callback)(void (*callback)(int level, const char* msg));
typedef ByteVC1Param (*Fn_ByteVC1_alloc_default_param)();
typedef void (*Fn_ByteVC1_release_param)(ByteVC1Param param);
typedef void (*Fn_ByteVC1_free_param)(ByteVC1Param param);
typedef ByteVC1Handle (*Fn_ByteVC1_dec_create)(ByteVC1Param param);
typedef void (*Fn_ByteVC1_dec_destroy)(ByteVC1Handle handle);
typedef int32_t (*Fn_ByteVC1_dec_decode)(ByteVC1Handle handle, ByteVC1Packet packet);

typedef ByteVC1Packet (*Fn_ByteVC1_alloc_packet)();
typedef void (*Fn_ByteVC1_init_ttpacket)(ByteVC1Packet packet);
typedef void (*Fn_ByteVC1_release_ttpacket)(ByteVC1Packet packet);
typedef void (*Fn_ByteVC1_free_packet)(ByteVC1Packet packet);
typedef int32_t (*Fn_ByteVC1_send_packet)(ByteVC1Handle handle, ByteVC1Packet packet);
typedef void (*Fn_ByteVC1_set_packet_bs)(ByteVC1Packet packet, const uint8_t* data, size_t size);
typedef void (*Fn_ByteVC1_set_packet_bs_len)(ByteVC1Packet packet, size_t size);

typedef ByteVC1Frame (*Fn_ByteVC1_alloc_frame)();
typedef int32_t (*Fn_ByteVC1_get_frame)(ByteVC1Handle handle, ByteVC1Frame frame);
typedef void (*Fn_ByteVC1_return_frame)(ByteVC1Handle handle, ByteVC1Frame frame);
typedef int32_t (*Fn_ByteVC1_get_frame_got_frame)(ByteVC1Frame frame);
typedef int32_t (*Fn_ByteVC1_frame_got_frame)(ByteVC1Frame frame);

typedef uint32_t (*Fn_ByteVC1_get_frame_width)(ByteVC1Frame frame);
typedef uint32_t (*Fn_ByteVC1_get_frame_height)(ByteVC1Frame frame);
typedef int32_t (*Fn_ByteVC1_get_frame_pix_fmt)(ByteVC1Frame frame);
typedef uint32_t (*Fn_ByteVC1_get_frame_bit_depth)(ByteVC1Frame frame);
typedef uint32_t (*Fn_ByteVC1_get_frame_stride)(ByteVC1Frame frame, int32_t plane);
typedef uint32_t (*Fn_ByteVC1_get_frame_linesize)(ByteVC1Frame frame, int32_t plane);
typedef const uint8_t* (*Fn_ByteVC1_get_frame_data)(ByteVC1Frame frame, int32_t plane);

typedef int32_t (*Fn_ByteVC1_frame_get_img_property)(ByteVC1Frame frame, int32_t prop_id, void* out_val);
typedef int32_t (*Fn_ByteVC1_frame_get_buffer_property)(ByteVC1Frame frame, int32_t prop_id, void* out_val);

/**
 * @brief Table of resolved function pointers from libByteVC1_dec.so.
 * Bảng chứa các con trỏ hàm đã được phân giải từ libByteVC1_dec.so.
 */
struct ByteVC1SymbolsTable {
    Fn_ByteVC1_get_version get_version{nullptr};
    Fn_ByteVC1_set_log_callback set_log_callback{nullptr};
    Fn_ByteVC1_alloc_default_param alloc_default_param{nullptr};
    Fn_ByteVC1_release_param release_param{nullptr};
    Fn_ByteVC1_free_param free_param{nullptr};
    Fn_ByteVC1_dec_create dec_create{nullptr};
    Fn_ByteVC1_dec_destroy dec_destroy{nullptr};
    Fn_ByteVC1_dec_decode dec_decode{nullptr};
    Fn_ByteVC1_alloc_packet alloc_packet{nullptr};
    Fn_ByteVC1_init_ttpacket init_ttpacket{nullptr};
    Fn_ByteVC1_release_ttpacket release_ttpacket{nullptr};
    Fn_ByteVC1_free_packet free_packet{nullptr};
    Fn_ByteVC1_send_packet send_packet{nullptr};
    Fn_ByteVC1_set_packet_bs set_packet_bs{nullptr};
    Fn_ByteVC1_set_packet_bs_len set_packet_bs_len{nullptr};
    Fn_ByteVC1_alloc_frame alloc_frame{nullptr};
    Fn_ByteVC1_get_frame get_frame{nullptr};
    Fn_ByteVC1_return_frame return_frame{nullptr};
    Fn_ByteVC1_get_frame_got_frame get_frame_got_frame{nullptr};
    Fn_ByteVC1_frame_got_frame frame_got_frame{nullptr};
    Fn_ByteVC1_get_frame_width get_frame_width{nullptr};
    Fn_ByteVC1_get_frame_height get_frame_height{nullptr};
    Fn_ByteVC1_get_frame_pix_fmt get_frame_pix_fmt{nullptr};
    Fn_ByteVC1_get_frame_bit_depth get_frame_bit_depth{nullptr};
    Fn_ByteVC1_get_frame_stride get_frame_stride{nullptr};
    Fn_ByteVC1_get_frame_linesize get_frame_linesize{nullptr};
    Fn_ByteVC1_get_frame_data get_frame_data{nullptr};
    Fn_ByteVC1_frame_get_img_property frame_get_img_property{nullptr};
    Fn_ByteVC1_frame_get_buffer_property frame_get_buffer_property{nullptr};

    bool is_loaded{false};
    std::string version;
    bool is_v2_abi{false};
};

/**
 * @brief Binary constants extracted from libanimax_bytevc1.so.
 * Các hằng số nhị phân trích xuất từ libanimax_bytevc1.so.
 */
namespace BinaryConstants {
    constexpr int32_t JNI_VERSION_1_6 = 0x00010006; ///< Return value of JNI_OnLoad (0x5acc)
    constexpr const char* LIB_BYTEVC1_DEC = "libByteVC1_dec.so"; ///< Dynamically loaded decoder (0x1e3b)
    constexpr const char* PROVIDER_NAME_BYTEVC1 = "bytevc1";     ///< Provider identifier (0x2039)
    constexpr const char* LOG_TAG = "AnimaxByteVC1";
    constexpr const char* MSG_REGISTER_SUCCESS = "animax bytevc1 loaded, register bytevc1 success."; // 0x206e
    constexpr const char* MSG_REGISTER_FAIL = "animax bytevc1 failed to register provider.";         // 0x2158
    constexpr const char* MSG_LOADER_FAIL = "ByteVC1LibLoader: Failed to load ByteVC1 library";      // 0x1d41
    constexpr const char* MSG_ALLOC_PACKET_FAIL = "ByteVC1LibLoader: Failed to allocate packet.";   // 0x2041
}

} // namespace AnimaxByteVC1
} // namespace OpenCut
} // namespace NextAI

#endif // NEXTAI_OPENCUT_ANIMAX_BYTEVC1_TYPES_H
