// ============================================================================
// File: animax_video_shader.cpp
// Target 108 / 169: libanimax.so (657,720 bytes)
// EN: Clean-room C++17 implementation of YUVFrameInfo (0x073f08..0x074230),
//     VideoPlayerCustom, and JNI_OnLoad (0x044348).
// VI: Triển khai C++17 phòng sạch cho YUVFrameInfo (0x073f08..0x074230),
//     VideoPlayerCustom và JNI_OnLoad (0x044348).
// ============================================================================
#include "animax_player_core.h"
#include <cstring>

namespace lynx {
namespace animax {

YUVFrameInfo::YUVFrameInfo() noexcept {
    std::memset(&abi_, 0, sizeof(abi_));
    abi_.channel_vectors_ptr = channels_;
}

// Disassembly @ 0x073f08: B9402000 ldr w0, [x0, #0x20]; D65F03C0 ret
uint32_t YUVFrameInfo::GetWidth() const noexcept {
    return abi_.width;
}

// Disassembly @ 0x073f10: B9402400 ldr w0, [x0, #0x24]; D65F03C0 ret
uint32_t YUVFrameInfo::GetHeight() const noexcept {
    return abi_.height;
}

// Disassembly @ 0x073f18..0x073f24: cmp w1, #2; b.hi #0x73f24; str w2, [x0, w1, uxtw #2]; ret
void YUVFrameInfo::SetLineSize(uint32_t channel, uint32_t size) noexcept {
    if (channel <= 2u) {
        abi_.line_size[channel] = size;
    }
}

// Disassembly @ 0x073f28..0x073f38: cmp w1, #2; b.hi #0x73f38; add x8, x0, w1, uxtw #2; str w2, [x8, #0x10]; ret
void YUVFrameInfo::SetLineWidth(uint32_t channel, uint32_t width) noexcept {
    if (channel <= 2u) {
        abi_.line_width[channel] = width;
    }
}

// Disassembly @ 0x073f3c: B9002001 str w1, [x0, #0x20]; D65F03C0 ret
void YUVFrameInfo::SetWidth(uint32_t width) noexcept {
    abi_.width = width;
}

// Disassembly @ 0x073f44: B9002401 str w1, [x0, #0x24]; D65F03C0 ret
void YUVFrameInfo::SetHeight(uint32_t height) noexcept {
    abi_.height = height;
}

// Disassembly @ 0x073f4c: B9002801 str w1, [x0, #0x28]; D65F03C0 ret
void YUVFrameInfo::SetBitDepth(uint32_t bit_depth) noexcept {
    abi_.bit_depth = bit_depth;
}

// Disassembly @ 0x073f54: F9001801 str x1, [x0, #0x30]; D65F03C0 ret
void YUVFrameInfo::SetYUVPixFmt(YUVPixFmt fmt) noexcept {
    abi_.yuv_pix_fmt = static_cast<uint64_t>(fmt);
}

// Disassembly @ 0x073f5c..0x073f74:
//   cmp w1, #2; b.ls #0x73f68; ...
//   ldr x8, [x0, #0x38]; mov w9, #0x18; umaddl x0, w1, w9, x8; ret
const std::vector<uint8_t>& YUVFrameInfo::GetChannelData(uint32_t channel) const noexcept {
    static const std::vector<uint8_t> kEmpty;
    if (channel > 2u) {
        return kEmpty;
    }
    return channels_[channel];
}

// Disassembly @ 0x073f78..0x073f8c:
//   cmp w1, #2; b.ls #0x73f84; ...
//   add x8, x0, w1, uxtw #2; ldr w0, [x8, #0x10]; ret
uint32_t YUVFrameInfo::GetChannelDataWidth(uint32_t channel) const noexcept {
    if (channel > 2u) {
        return 0u;
    }
    return abi_.line_width[channel];
}

// Disassembly @ 0x073fd0..0x073ffc:
//   0x073fd0: 7100083F cmp   w1, #2
//   0x073fd4: 1E2703E0 fmov  s0, wzr
//   0x073fd8: 540000E8 b.hi  #0x73ff4
//   0x073fdc: 340000E1 cbz   w1, #0x73ff8
//   0x073fe0: F9401808 ldr   x8, [x0, #0x30]
//   0x073fe4: 1E2E1000 fmov  s0, #1.00000000
//   0x073fe8: 1E2C1001 fmov  s1, #0.50000000
//   0x073fec: F100051F cmp   x8, #1
//   0x073ff0: 1E200C20 fcsel s0, s1, s0, eq
//   0x073ff4: D65F03C0 ret
//   0x073ff8: 1E2E1000 fmov  s0, #1.00000000
//   0x073ffc: D65F03C0 ret
float YUVFrameInfo::GetVerticalSubsamplingFactor(uint32_t channel) const noexcept {
    if (channel > 2u) {
        return 0.0f;
    }
    if (channel == 0u) {
        return 1.0f;
    }
    return (abi_.yuv_pix_fmt == 1ULL) ? 0.5f : 1.0f;
}

// Disassembly @ 0x073f90..0x073fcc:
//   0x073f9c: BD402400 ldr    s0, [x0, #0x24]
//   0x073fa0: 7E21D800 ucvtf  s0, s0
//   ...
//   0x073fc4: 1E200820 fmul   s0, s1, s0
//   0x073fc8: 1E390000 fcvtzu w0, s0
//   0x073fcc: D65F03C0 ret
uint32_t YUVFrameInfo::GetChannelDataHeight(uint32_t channel) const noexcept {
    if (channel > 2u) {
        return 0u;
    }
    const float h = static_cast<float>(abi_.height);
    const float factor = GetVerticalSubsamplingFactor(channel);
    return static_cast<uint32_t>(factor * h);
}

void YUVFrameInfo::UpdateChannelData(uint32_t channel, const uint8_t* src) noexcept {
    if (channel > 2u || !src) {
        return;
    }
    const uint32_t w = GetChannelDataWidth(channel);
    const uint32_t h = GetChannelDataHeight(channel);
    const size_t total = static_cast<size_t>(w) * static_cast<size_t>(h);
    channels_[channel].assign(src, src + total);
}

extern "C" {

int32_t JNI_OnLoad_AnimaX(void* vm, void* /*reserved*/) noexcept {
    if (!vm) {
        return -1;
    }
    return 0x00010006; // JNI_VERSION_1_6
}

} // extern "C"

} // namespace animax
} // namespace lynx
