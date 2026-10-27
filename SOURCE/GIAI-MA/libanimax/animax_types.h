// ============================================================================
// File: animax_types.h
// Target 108 / 169: libanimax.so (657,720 bytes)
// SHA-256: 7a0c3593e13aa50431ba537046a038c49decc30db1322810d77ea2b24259e93c
// EN: Exact AArch64 ABI struct layouts for lynx::animax::PlayerEventTracker,
//     lynx::animax::AnimaXPlayerBuilder, lynx::animax::Color,
//     lynx::animax::DocumentData, lynx::animax::YUVFrameInfo, and
//     lynx::animax::TextContentDataSource.
// VI: Bố cục struct ABI AArch64 chính xác cho lynx::animax::PlayerEventTracker,
//     lynx::animax::AnimaXPlayerBuilder, lynx::animax::Color,
//     lynx::animax::DocumentData, lynx::animax::YUVFrameInfo và
//     lynx::animax::TextContentDataSource.
// ============================================================================
#pragma once

#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>
#include <memory>
#include <functional>

namespace lynx {
namespace animax {

enum class YUVPixFmt : uint64_t {
    kYUV444P = 0,
    kYUV420P = 1,
    kNV12    = 2
};

enum class BitmapFormat : uint32_t {
    kUnknown  = 0,
    kRGBA8888 = 1,
    kBGRA8888 = 2,
    kRGB565   = 3
};

enum class BitmapAlphaType : uint32_t {
    kUnknown  = 0,
    kOpaque   = 1,
    kPremul   = 2,
    kUnpremul = 3
};

enum class DocumentJustification : uint32_t {
    kLeftJustify   = 0,
    kRightJustify  = 1,
    kCenterJustify = 2
};

enum class PropertyUpdateResult : uint32_t {
    kSuccess          = 0,
    kKeyPathNotFound  = 1,
    kTypeMismatch     = 2,
    kInvalidParameter = 3
};

struct PointF {
    float x{0.0f};
    float y{0.0f};
};

// EN: Exact 8-byte ABI layout of PlayerEventTracker verified at 0x04c844..0x04c878:
//     Ctor (`0x04c844`): `str xzr, [x0]; b Reset`
//     Reset (`0x04c84c..0x04c864`): zeroes `events[0..7]`
//     MarkEvent (`0x04c868..0x04c870`): `mov w8, #1; strb w8, [x0, w1, sxtw]; ret`
//     GetEventValue (`0x04c874..0x04c878`): `ldrb w0, [x0, w1, sxtw]; ret`
// VI: Bố cục ABI 8 byte chính xác của PlayerEventTracker xác minh tại 0x04c844..0x04c878:
struct PlayerEventTrackerAbiLayout {
    uint8_t events[8]; // +0x00..0x07
};
static_assert(sizeof(PlayerEventTrackerAbiLayout) == 8, "PlayerEventTrackerAbiLayout must be 8 bytes");

// EN: Exact 16-byte ABI layout of Color verified in Color::Color(int) @ 0x0683d8..0x068408:
//     0x0683e4: `lsr w9, w1, #0x18` (A)
//     0x0683e8: `mov x10, #0x100010001000100` (4 valid flags at +0x09, +0x0B, +0x0D, +0x0F)
//     0x0683ec: `lsr w11, w1, #0x10` (R)
//     0x0683f0: `lsr w12, w1, #8` (G)
//     0x0683f4..0x068404: `stp x8, x10, [x0]; strb w9, [x0, #8]; strb w11, [x0, #0xa]; strb w12, [x0, #0xc]; strb w1, [x0, #0xe]`
// VI: Bố cục ABI 16 byte chính xác của Color xác minh trong Color::Color(int) @ 0x0683d8..0x068408:
struct ColorAbiLayout {
    void*   vptr;    // +0x00
    uint8_t a;       // +0x08
    uint8_t a_valid; // +0x09 (1)
    uint8_t r;       // +0x0A
    uint8_t r_valid; // +0x0B (1)
    uint8_t g;       // +0x0C
    uint8_t g_valid; // +0x0D (1)
    uint8_t b;       // +0x0E
    uint8_t b_valid; // +0x0F (1)
};
static_assert(offsetof(ColorAbiLayout, a) == 0x08, "a must be at +0x08");
static_assert(offsetof(ColorAbiLayout, r) == 0x0A, "r must be at +0x0A");
static_assert(offsetof(ColorAbiLayout, g) == 0x0C, "g must be at +0x0C");
static_assert(offsetof(ColorAbiLayout, b) == 0x0E, "b must be at +0x0E");
static_assert(sizeof(ColorAbiLayout) == 16, "ColorAbiLayout must be 16 bytes");

// EN: Exact ABI layout of AnimaXPlayerBuilder verified from 0x0588d0..0x05898c:
//     +0x00: float device_pixel_ratio (`str s0, [x0]` @ 0x0588d0)
//     +0x08: shared_ptr<TaskRunner> ui_runner (`stp x8, x9, [x19, #8]` @ 0x0588e8)
//     +0x18: bool enable_multi_thread_accelerate (`strb w8, [x0, #0x18]` @ 0x058900)
//     +0x19: bool skip_count_down_event (`strb w8, [x0, #0x19]` @ 0x05890c)
//     +0x20: shared_ptr<VSyncMonitor> vsync_monitor (`stp x8, x9, [x19, #0x20]` @ 0x058924)
//     +0x30: ResourceLoaderHolder resource_loader (`add x0, x0, #0x30` @ 0x058940)
//     +0x40: EventListenerHolder event_listener (`add x0, x0, #0x40` @ 0x05895c)
//     +0x50: BasePathHolder base_path (`add x0, x0, #0x50` @ 0x058978)
// VI: Bố cục ABI chính xác của AnimaXPlayerBuilder xác minh từ 0x0588d0..0x05898c:
struct AnimaXPlayerBuilderAbiLayout {
    float    device_pixel_ratio;              // +0x00
    uint32_t pad_04;                          // +0x04
    void*    ui_task_runner_ptr;              // +0x08
    void*    ui_task_runner_ctrl;             // +0x10
    uint8_t  enable_multi_thread_accelerate;  // +0x18
    uint8_t  skip_count_down_event;           // +0x19
    uint8_t  pad_1a[6];                       // +0x1A..0x1F
    void*    vsync_monitor_ptr;               // +0x20
    void*    vsync_monitor_ctrl;              // +0x28
    void*    resource_loader_slot[2];         // +0x30..0x3F
    void*    event_listener_slot[2];          // +0x40..0x4F
    void*    base_path_slot[3];               // +0x50..0x67
};
static_assert(offsetof(AnimaXPlayerBuilderAbiLayout, device_pixel_ratio) == 0x00, "dpr must be at +0x00");
static_assert(offsetof(AnimaXPlayerBuilderAbiLayout, ui_task_runner_ptr) == 0x08, "ui_task_runner_ptr must be at +0x08");
static_assert(offsetof(AnimaXPlayerBuilderAbiLayout, enable_multi_thread_accelerate) == 0x18, "multi_thread must be at +0x18");
static_assert(offsetof(AnimaXPlayerBuilderAbiLayout, skip_count_down_event) == 0x19, "skip_countdown must be at +0x19");
static_assert(offsetof(AnimaXPlayerBuilderAbiLayout, vsync_monitor_ptr) == 0x20, "vsync_monitor must be at +0x20");
static_assert(offsetof(AnimaXPlayerBuilderAbiLayout, resource_loader_slot) == 0x30, "resource_loader must be at +0x30");
static_assert(offsetof(AnimaXPlayerBuilderAbiLayout, event_listener_slot) == 0x40, "event_listener must be at +0x40");
static_assert(offsetof(AnimaXPlayerBuilderAbiLayout, base_path_slot) == 0x50, "base_path must be at +0x50");

// EN: Exact ABI layout of YUVFrameInfo verified from 0x073f08..0x074000:
//     +0x00..0x0B: uint32_t line_size[3] (`str w2, [x0, w1, uxtw #2]` @ 0x073f20)
//     +0x0C:       uint32_t pad_0c
//     +0x10..0x1B: uint32_t line_width[3] (`str w2, [x8, #0x10]` @ 0x073f34)
//     +0x1C:       uint32_t pad_1c
//     +0x20:       uint32_t width (`ldr w0, [x0, #0x20]` @ 0x073f08)
//     +0x24:       uint32_t height (`ldr w0, [x0, #0x24]` @ 0x073f10)
//     +0x28:       uint32_t bit_depth (`str w1, [x0, #0x28]` @ 0x073f4c)
//     +0x2C:       uint32_t pad_2c
//     +0x30:       uint64_t yuv_pix_fmt (`str x1, [x0, #0x30]` @ 0x073f54)
//     +0x38:       void* channel_vectors_ptr (`ldr x8, [x0, #0x38]` @ 0x073f68)
// VI: Bố cục ABI chính xác của YUVFrameInfo xác minh từ 0x073f08..0x074000:
struct YUVFrameInfoAbiLayout {
    uint32_t line_size[3];        // +0x00..0x0B
    uint32_t pad_0c;              // +0x0C
    uint32_t line_width[3];       // +0x10..0x1B
    uint32_t pad_1c;              // +0x1C
    uint32_t width;               // +0x20
    uint32_t height;              // +0x24
    uint32_t bit_depth;           // +0x28
    uint32_t pad_2c;              // +0x2C
    uint64_t yuv_pix_fmt;         // +0x30
    void*    channel_vectors_ptr; // +0x38
};
static_assert(offsetof(YUVFrameInfoAbiLayout, line_size) == 0x00, "line_size must be at +0x00");
static_assert(offsetof(YUVFrameInfoAbiLayout, line_width) == 0x10, "line_width must be at +0x10");
static_assert(offsetof(YUVFrameInfoAbiLayout, width) == 0x20, "width must be at +0x20");
static_assert(offsetof(YUVFrameInfoAbiLayout, height) == 0x24, "height must be at +0x24");
static_assert(offsetof(YUVFrameInfoAbiLayout, bit_depth) == 0x28, "bit_depth must be at +0x28");
static_assert(offsetof(YUVFrameInfoAbiLayout, yuv_pix_fmt) == 0x30, "yuv_pix_fmt must be at +0x30");
static_assert(offsetof(YUVFrameInfoAbiLayout, channel_vectors_ptr) == 0x38, "channel_vectors_ptr must be at +0x38");

// EN: Exact 16-byte ABI layout of TextContentDataSource verified at 0x064dd8..0x064df0:
//     Ctor (`0x064dd8`): `stp x1, x2, [x0]; ret`
//     GetParagraphStyle (`0x064de0`): `ldr x8, [x0]; ldr x0, [x8]; b #0x92cfc`
//     GetLayerMatrix (`0x064dec`): `ldr x0, [x0, #8]; b #0x8e770`
// VI: Bố cục ABI 16 byte chính xác của TextContentDataSource xác minh tại 0x064dd8..0x064df0:
struct TextContentDataSourceAbiLayout {
    const void* text_layer_ptr;   // +0x00
    const void* layer_matrix_ptr; // +0x08
};
static_assert(sizeof(TextContentDataSourceAbiLayout) == 16, "TextContentDataSourceAbiLayout must be 16 bytes");

} // namespace animax
} // namespace lynx
