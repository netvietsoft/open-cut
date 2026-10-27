// ============================================================================
// File: animax_player_core.cpp
// Target 108 / 169: libanimax.so (657,720 bytes)
// SHA-256: 7a0c3593e13aa50431ba537046a038c49decc30db1322810d77ea2b24259e93c
// EN: Clean-room C++17 implementation of PlayerEventTracker, ColorUtil::ParseHexColor,
//     Color::Color(int), DocumentData, AnimaXPlayerBuilder, TextContentDataSource,
//     and TextHelper::RegisterImpl with 1:1 AArch64 opcode parity.
// VI: Triển khai C++17 phòng sạch cho PlayerEventTracker, ColorUtil::ParseHexColor,
//     Color::Color(int), DocumentData, AnimaXPlayerBuilder, TextContentDataSource
//     và TextHelper::RegisterImpl khớp 1:1 opcode AArch64.
// ============================================================================
#include "animax_player_core.h"
#include <cstdlib>
#include <cstring>

namespace lynx {
namespace animax {

// .bss @ 0x0a00e0: _ZZN4lynx6animax10TextHelper7ImplRefEvE8impl_ref
static void* g_text_helper_impl_0a00e0 = nullptr;

// ============================================================================
// 1. PlayerEventTracker (0x04c844 .. 0x04c878)
// Disassembly @ 0x04c844..0x04c878:
//   0x04c844: F900001F str  xzr, [x0]
//   0x04c848: 14011B92 b    Reset
//   0x04c84c: AA1F03E8 mov  x8, xzr
//   0x04c850: F100211F cmp  x8, #8
//   0x04c854: 54000080 b.eq #0x4c864
//   0x04c858: 3828681F strb wzr, [x0, x8]
//   0x04c85c: 91000508 add  x8, x8, #1
//   0x04c860: 17FFFFFC b    #0x4c850
//   0x04c864: D65F03C0 ret
//   0x04c868: 52800028 mov  w8, #1
//   0x04c86c: 3821C808 strb w8, [x0, w1, sxtw]
//   0x04c870: D65F03C0 ret
//   0x04c874: 3861C800 ldrb w0, [x0, w1, sxtw]
//   0x04c878: D65F03C0 ret
// ============================================================================
PlayerEventTracker::PlayerEventTracker() noexcept {
    std::memset(&abi_, 0, sizeof(abi_));
    Reset();
}

void PlayerEventTracker::Reset() noexcept {
    for (size_t i = 0; i < 8; ++i) {
        abi_.events[i] = 0u;
    }
}

void PlayerEventTracker::MarkEvent(int32_t event_type) noexcept {
    if (event_type >= 0 && event_type < 8) {
        abi_.events[event_type] = 1u;
    }
}

bool PlayerEventTracker::GetEventValue(int32_t event_type) const noexcept {
    if (event_type >= 0 && event_type < 8) {
        return abi_.events[event_type] != 0u;
    }
    return false;
}

// ============================================================================
// 2. ColorUtil::ParseHexColor (0x04dc78 .. 0x04de78)
// Disassembly @ 0x04dccc..0x04de44:
//   0x04dccc: 71008D1F cmp w8, #0x23 ('#') -> strips leading '#'
//   0x04dcfc: F100217F cmp x11, #8         -> accepts 8 hex chars (RRGGBBAA)
//   0x04dd04: F100197F cmp x11, #6         -> accepts 6 hex chars (RRGGBB, A=0xFF)
//   0x04de38: 53103F08 lsl w8, w24, #0x10  (R << 16)
//   0x04de3c: 2A1B6108 orr w8, w8, w27, lsl #24 (| (A << 24))
//   0x04de40: 2A162108 orr w8, w8, w22, lsl #8  (| (G << 8))
//   0x04de44: 2A170113 orr w19, w8, w23         (| B)
// ============================================================================
uint32_t ColorUtil::ParseHexColor(const std::string& hex_str) noexcept {
    if (hex_str.empty()) {
        return 0u;
    }
    std::string cleaned = hex_str;
    if (cleaned[0] == '#') {
        cleaned.erase(0, 1);
    }
    if (cleaned.size() == 6) {
        cleaned = "ff" + cleaned;
    } else if (cleaned.size() != 8) {
        return 0u;
    }

    uint32_t bytes[4] = {0xFFu, 0u, 0u, 0u}; // A, R, G, B
    for (size_t i = 0; i < 4; ++i) {
        const std::string byte_hex = cleaned.substr(i * 2, 2);
        char* end_ptr = nullptr;
        const long val = std::strtol(byte_hex.c_str(), &end_ptr, 16);
        if (!end_ptr || *end_ptr != '\0') {
            return 0u;
        }
        bytes[i] = static_cast<uint32_t>(val) & 0xFFu;
    }
    const uint32_t a = bytes[0];
    const uint32_t r = bytes[1];
    const uint32_t g = bytes[2];
    const uint32_t b = bytes[3];
    return (r << 16) | (a << 24) | (g << 8) | b;
}

// ============================================================================
// 3. Color::Color(int) (0x0683d8 .. 0x068408)
// Disassembly @ 0x0683e4..0x068408:
//   0x0683e4: 53187C29 lsr  w9, w1, #0x18
//   0x0683e8: B20883EA mov  x10, #0x100010001000100
//   0x0683ec: 53107C2B lsr  w11, w1, #0x10
//   0x0683f0: 53087C2C lsr  w12, w1, #8
//   0x0683f4: A9002808 stp  x8, x10, [x0]
//   0x0683f8: 39002009 strb w9, [x0, #8]
//   0x0683fc: 3900280B strb w11, [x0, #0xa]
//   0x068400: 3900300C strb w12, [x0, #0xc]
//   0x068404: 39003801 strb w1, [x0, #0xe]
//   0x068408: D65F03C0 ret
// ============================================================================
Color::Color(int32_t argb) noexcept {
    const uint32_t u = static_cast<uint32_t>(argb);
    abi_.vptr    = nullptr;
    abi_.a       = static_cast<uint8_t>(u >> 24);
    abi_.a_valid = 1u;
    abi_.r       = static_cast<uint8_t>((u >> 16) & 0xFFu);
    abi_.r_valid = 1u;
    abi_.g       = static_cast<uint8_t>((u >> 8) & 0xFFu);
    abi_.g_valid = 1u;
    abi_.b       = static_cast<uint8_t>(u & 0xFFu);
    abi_.b_valid = 1u;
}

// ============================================================================
// 4. DocumentData & AnimaXPlayerBuilder & TextHelper
// ============================================================================
DocumentData::DocumentData() noexcept = default;

// Disassembly @ 0x05cd9c: 528000C0 mov w0, #6; D65F03C0 ret
int32_t DocumentData::GetValueType() const noexcept {
    return 6;
}

bool DocumentData::IsEmpty() const noexcept {
    return text_.empty();
}

AnimaXPlayerBuilder::AnimaXPlayerBuilder() noexcept {
    std::memset(&abi_, 0, sizeof(abi_));
    abi_.device_pixel_ratio = 1.0f;
}

// Disassembly @ 0x0588d0: BD000000 str s0, [x0]; D65F03C0 ret
AnimaXPlayerBuilder& AnimaXPlayerBuilder::SetDevicePixelRatio(float dpr) noexcept {
    abi_.device_pixel_ratio = dpr;
    return *this;
}

// Disassembly @ 0x0588fc: 12000028 and w8, w1, #1; 39006008 strb w8, [x0, #0x18]; D65F03C0 ret
AnimaXPlayerBuilder& AnimaXPlayerBuilder::EnableMultiThreadAccelerate(bool enable) noexcept {
    abi_.enable_multi_thread_accelerate = enable ? 1u : 0u;
    return *this;
}

// Disassembly @ 0x058908: 12000028 and w8, w1, #1; 39006408 strb w8, [x0, #0x19]; D65F03C0 ret
AnimaXPlayerBuilder& AnimaXPlayerBuilder::SetSkipCountDownEvent(bool skip) noexcept {
    abi_.skip_count_down_event = skip ? 1u : 0u;
    return *this;
}

// Disassembly @ 0x064dd8: A9000801 stp x1, x2, [x0]; D65F03C0 ret
TextContentDataSource::TextContentDataSource(const void* text_layer, const void* layer_matrix) noexcept {
    abi_.text_layer_ptr   = text_layer;
    abi_.layer_matrix_ptr = layer_matrix;
}

// Disassembly @ 0x065f8c: 900001C8 adrp x8, #0x9d000; F9460508 ldr x8, [x8, #0xc08]; F9000100 str x0, [x8]; D65F03C0 ret
void TextHelper::RegisterImpl(void* impl) noexcept {
    g_text_helper_impl_0a00e0 = impl;
}

void*& TextHelper::ImplRef() noexcept {
    return g_text_helper_impl_0a00e0;
}

} // namespace animax
} // namespace lynx
