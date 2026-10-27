// ============================================================================
// Clean-Room C++17 Types & Constants for libtobEmbedPagEncrypt.so (Target 127 / 169)
// Định nghĩa kiểu dữ liệu & hằng số C++17 cho libtobEmbedPagEncrypt.so (Mục tiêu 127 / 169)
// Binary: 8,304 bytes | SHA-256: d1a8cbbcd4982679b44c5e8cb5480526c8f50b484f744f4e18b49585792bc255
// ============================================================================
#pragma once

#include <cstdint>
#include <cstddef>
#include <cstring>
#include <cstdlib>
#include <cstdio>

struct _JNIEnv;
using JNIEnv = _JNIEnv;
using jclass = void*;
using jbyteArray = void*;
using jint = int32_t;
using jsize = int32_t;
using jbyte = int8_t;

namespace tob_embed_pag_encrypt {

// Header & Block Constants observed in ss_encrypt (0x0b44..0x0d0c) & ss_decrypt (0x0ea0..0x1018):
constexpr uint16_t kTcHeaderMagic16  = 0x6374U;      // 't' (0x74), 'c' (0x63) in LE (`mov w8, #0x6374` @ 0x0bd0)
constexpr uint8_t  kTcHeaderVersion  = 0x03U;        // `mov w9, #3` (@ 0x0bd4)
constexpr uint16_t kTcHeaderFlags16  = 0x0100U;      // `mov w10, #0x100` (@ 0x0bd8)
constexpr int32_t  kTcHeaderBytes    = 6;            // 6-byte header (`add x20, x19, #6` @ 0x0bb0)
constexpr int32_t  kBlockSizeBytes   = 16;           // 16-byte block (`cmp w24, #0x10` @ 0x0c18)
constexpr uint32_t kTeaLogSentinelBE = 0x01000000U;  // `mov w27, #0x1000000` (@ 0x0c34)

// Error Codes returned by ss_encrypt / ss_decrypt:
constexpr int32_t kErrInvalidArgs    = -1; // `mov w0, #-1` (@ 0x0b74, 0x0ec4)
constexpr int32_t kErrInvalidMagic   = -2; // `mov w0, #-2` (@ 0x0f34)
constexpr int32_t kErrInvalidPadding = -3; // `mov w0, #-3` (@ 0x0f2c)

// Default 20-byte EmbedAppLog key initialized by initKey() (0x1018..0x1070):
//   .rodata 0x0900..0x0910: "UK*@3oKpFlVVnads" (16 bytes loaded via `ldr q0, [x11, #0x900]` @ 0x1030)
//   Immediate 0x41646654:   "Tfda" (4 bytes via `mov w11, #0x6654; movk w11, #0x4164, lsl #16` @ 0x1038..0x1040)
//   Stored in .bss 0x009830..0x009844 (20 bytes)
constexpr const char* kDefaultEmbedPagKey20B = "UK*@3oKpFlVVnadsTfda";
constexpr uint32_t    kDefaultKeyTailLe32    = 0x41646654U; // 'T', 'f', 'd', 'a'
constexpr const char* kTeaLogFormatStr       = "TeaLog: after ntohl: %u"; // .rodata 0x08e0

// Exact JNINativeInterface (`JNIEnv*`) vtable byte offsets observed in ttEncrypt (0x1070) & ttDecrypt (0x11c8):
//   +0x580 (slot 176): NewByteArray       (`ldr x8, [x8, #0x580]` @ 0x1148, 0x1288)
//   +0x640 (slot 200): GetByteArrayRegion (`ldr x8, [x8, #0x640]` @ 0x1104, 0x1240)
//   +0x680 (slot 208): SetByteArrayRegion (`ldr x8, [x8, #0x680]` @ 0x1160, 0x12a0)
constexpr size_t kEnvOffNewByteArray       = 0x580;
constexpr size_t kEnvOffGetByteArrayRegion = 0x640;
constexpr size_t kEnvOffSetByteArrayRegion = 0x680;

// Bitwise Byte-Order & Rotation Intrinsics matching AArch64 `rev`, `rev16`, and `ror`:
inline constexpr uint32_t ByteSwap32(uint32_t v) noexcept {
    return ((v & 0x000000FFU) << 24) |
           ((v & 0x0000FF00U) <<  8) |
           ((v & 0x00FF0000U) >>  8) |
           ((v & 0xFF000000U) >> 24);
}

inline constexpr uint32_t Rev16_32(uint32_t v) noexcept {
    return ((v & 0x00FF00FFU) << 8) | ((v & 0xFF00FF00U) >> 8);
}

inline constexpr uint32_t Ror32(uint32_t v, uint32_t shift) noexcept {
    shift &= 31U;
    return (shift == 0U) ? v : ((v >> shift) | (v << (32U - shift)));
}

} // namespace tob_embed_pag_encrypt
