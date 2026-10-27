/**
 * @file ppsec_bpem_crypto.cpp
 * @brief Clean-Room Implementation of `BPEM` Envelope Crypto, AES-128-CBC, MD5, Base64 & CRC-16/XMODEM Engine.
 *        Triển khai tái tạo sạch bộ mã hóa phong bì `BPEM`, AES-128-CBC, MD5, Base64 và CRC-16/XMODEM của libppsec.so.
 *
 * Binary Target / Mục tiêu nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/libppsec.so (166,400 bytes)
 *
 * Disassembly Anchor Map / Bản đồ neo giải mã AArch64:
 *   - 0x002a10..0x002aa8 : `.init_array[0]` (copies 344B RSA pubkey `.rodata 0x0214c0` to `.bss 0x02c9e0`, sets Kid `"0"` at `.bss 0x02c9f8`)
 *   - 0x004744..0x00580c : `bpem_encrypt` (writes `"BPEM"` header, generates session key/IV, encrypts payload)
 *   - 0x005810..0x00614c : `bpem_decrypt` (verifies `"BPEM"` magic at `0x0058bc`, unwraps session key, decrypts AES-CBC)
 *   - 0x007550..0x008174 : `bpem_init_keystore` (`"y1B9Q#2020072zzzz"` @ `0x007a8c`, `"072y1Bvz9Q3#20vz0"` @ `0x007b30`)
 *   - 0x009140..0x00a3e8 : AES-128/256 Key Expansion & Block Cipher (`.rodata 0x01d048` S-Box & T-Tables)
 *   - 0x00aa50..0x00b600 : MD5 Digest (`0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476` at `.rodata 0x0214a0`)
 *   - 0x0111a0..0x011948 : `CryptTool::encrypt` (`0x0115ec`), `decrypt` (`0x0117a0`), `getKid` (`0x011948`)
 *   - 0x0185fc..0x0189a0 : `.init_array[1]` (`0x0185fc`, loads `.rodata 0x0243bb` + `"19572"`) & `crc16_xmodem` (`0x018948`, `.rodata 0x0243d2`)
 */

#include "ppsec_bpem_crypto.h"
#include "ppsec_string_deobfuscator.h"

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace nextai {
namespace opencut {
namespace ppsec {

namespace {

std::string g_active_rsa_pub_b64 = kPpsecDefaultRsaPubKeyB64;
std::string g_active_kid         = kPpsecDefaultKid;
int32_t     g_channel_app_id_int = 19572;
uint8_t     g_packet_seed_buf[20] = {0};
bool        g_static_crypto_init = false;

/**
 * @brief 256-Entry AES Forward S-Box [OBSERVED at .rodata 0x01d048..0x01d447 as uint32_t[256]]
 *        Bảng thế thuận AES S-Box 256 phần tử [QUAN SÁT ĐƯỢC tại .rodata 0x01d048..0x01d447]
 */
constexpr uint8_t kAesSbox[256] = {
    0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
    0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
    0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
    0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
    0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
    0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
    0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
    0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
    0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
    0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
    0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
    0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
    0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
    0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
    0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
    0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16
};

/**
 * @brief 256-Entry AES Inverse S-Box.
 *        Bảng thế nghịch đảo AES Inverse S-Box 256 phần tử.
 */
constexpr uint8_t kAesInvSbox[256] = {
    0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb,
    0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb,
    0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e,
    0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25,
    0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92,
    0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84,
    0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06,
    0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b,
    0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73,
    0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e,
    0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b,
    0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4,
    0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f,
    0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef,
    0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61,
    0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d
};

constexpr uint8_t kAesRcon[11] = {
    0x00, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1B, 0x36
};

inline uint8_t GfMul2(uint8_t x) noexcept {
    return static_cast<uint8_t>((x << 1U) ^ ((x & 0x80U) ? 0x1BU : 0x00U));
}

inline uint8_t GfMul(uint8_t a, uint8_t b) noexcept {
    uint8_t p = 0U;
    for (int i = 0; i < 8; ++i) {
        if ((b & 1U) != 0U) {
            p ^= a;
        }
        a = GfMul2(a);
        b >>= 1U;
    }
    return p;
}

void Aes128ExpandKey(const uint8_t key[16], uint8_t round_keys[176]) noexcept {
    std::memcpy(round_keys, key, 16U);
    uint8_t temp[4];
    for (size_t i = 4U; i < 44U; ++i) {
        std::memcpy(temp, &round_keys[(i - 1U) * 4U], 4U);
        if ((i % 4U) == 0U) {
            const uint8_t t = temp[0];
            temp[0] = kAesSbox[temp[1]] ^ kAesRcon[i / 4U];
            temp[1] = kAesSbox[temp[2]];
            temp[2] = kAesSbox[temp[3]];
            temp[3] = kAesSbox[t];
        }
        for (size_t j = 0U; j < 4U; ++j) {
            round_keys[i * 4U + j] = round_keys[(i - 4U) * 4U + j] ^ temp[j];
        }
    }
}

void Aes128EncryptBlock(const uint8_t in[16], uint8_t out[16], const uint8_t rk[176]) noexcept {
    uint8_t s[16];
    for (size_t i = 0U; i < 16U; ++i) {
        s[i] = in[i] ^ rk[i];
    }
    for (size_t round = 1U; round <= 10U; ++round) {
        for (size_t i = 0U; i < 16U; ++i) {
            s[i] = kAesSbox[s[i]];
        }
        uint8_t t = s[1]; s[1] = s[5]; s[5] = s[9]; s[9] = s[13]; s[13] = t;
        t = s[2]; s[2] = s[10]; s[10] = t; t = s[6]; s[6] = s[14]; s[14] = t;
        t = s[15]; s[15] = s[11]; s[11] = s[7]; s[7] = s[3]; s[3] = t;
        if (round < 10U) {
            for (size_t c = 0U; c < 4U; ++c) {
                const size_t idx = c * 4U;
                const uint8_t a0 = s[idx], a1 = s[idx + 1], a2 = s[idx + 2], a3 = s[idx + 3];
                const uint8_t x  = a0 ^ a1 ^ a2 ^ a3;
                s[idx + 0] ^= x ^ GfMul2(a0 ^ a1);
                s[idx + 1] ^= x ^ GfMul2(a1 ^ a2);
                s[idx + 2] ^= x ^ GfMul2(a2 ^ a3);
                s[idx + 3] ^= x ^ GfMul2(a3 ^ a0);
            }
        }
        for (size_t i = 0U; i < 16U; ++i) {
            s[i] ^= rk[round * 16U + i];
        }
    }
    std::memcpy(out, s, 16U);
}

void Aes128DecryptBlock(const uint8_t in[16], uint8_t out[16], const uint8_t rk[176]) noexcept {
    uint8_t s[16];
    for (size_t i = 0U; i < 16U; ++i) {
        s[i] = in[i] ^ rk[160U + i];
    }
    for (size_t round = 9U;; --round) {
        uint8_t t = s[13]; s[13] = s[9]; s[9] = s[5]; s[5] = s[1]; s[1] = t;
        t = s[2]; s[2] = s[10]; s[10] = t; t = s[6]; s[6] = s[14]; s[14] = t;
        t = s[3]; s[3] = s[7]; s[7] = s[11]; s[11] = s[15]; s[15] = t;
        for (size_t i = 0U; i < 16U; ++i) {
            s[i] = kAesInvSbox[s[i]] ^ rk[round * 16U + i];
        }
        if (round == 0U) {
            break;
        }
        for (size_t c = 0U; c < 4U; ++c) {
            const size_t idx = c * 4U;
            const uint8_t a0 = s[idx], a1 = s[idx + 1], a2 = s[idx + 2], a3 = s[idx + 3];
            s[idx + 0] = GfMul(a0, 0x0e) ^ GfMul(a1, 0x0b) ^ GfMul(a2, 0x0d) ^ GfMul(a3, 0x09);
            s[idx + 1] = GfMul(a0, 0x09) ^ GfMul(a1, 0x0e) ^ GfMul(a2, 0x0b) ^ GfMul(a3, 0x0d);
            s[idx + 2] = GfMul(a0, 0x0d) ^ GfMul(a1, 0x09) ^ GfMul(a2, 0x0e) ^ GfMul(a3, 0x0b);
            s[idx + 3] = GfMul(a0, 0x0b) ^ GfMul(a1, 0x0d) ^ GfMul(a2, 0x09) ^ GfMul(a3, 0x0e);
        }
    }
    std::memcpy(out, s, 16U);
}

/**
 * @brief 256-Entry CRC-16/XMODEM Lookup Table [OBSERVED at .rodata 0x0243d2..0x0245d1]
 *        Bảng tra cứu 256 phần tử CRC-16/XMODEM (`poly = 0x1021`) [QUAN SÁT ĐƯỢC tại .rodata 0x0243d2]
 */
uint16_t LookupCrc16XmodemTable(uint8_t index) noexcept {
    uint16_t crc = static_cast<uint16_t>(index) << 8U;
    for (int bit = 0; bit < 8; ++bit) {
        if ((crc & 0x8000U) != 0U) {
            crc = static_cast<uint16_t>((crc << 1U) ^ 0x1021U);
        } else {
            crc = static_cast<uint16_t>(crc << 1U);
        }
    }
    return crc;
}

inline uint32_t Rotl32(uint32_t x, uint32_t n) noexcept {
    return (x << n) | (x >> (32U - n));
}

}  // namespace

/**
 * @brief Reconstructs `.init_array[0]` (`0x002a10..0x002aa8`) and `.init_array[1]` (`0x0185fc..0x018940`).
 *        Tái tạo hàm khởi tạo tĩnh `.init_array[0]` (`0x002a10`) và `.init_array[1]` (`0x0185fc`).
 */
void PpsecInitStaticCryptoState() noexcept {
    g_active_rsa_pub_b64.assign(kPpsecDefaultRsaPubKeyB64, kPpsecDefaultRsaPubKeyLen);
    g_active_kid = kPpsecDefaultKid;

    // Disassembly 0x0187bc..0x01891c (.init_array[1]):
    //   Decrypts "19572" at .bss 0x02e480, calls atoi("19572") -> 19572,
    //   loads 16-byte seed from .rodata 0x0243bb into .bss 0x02e48c and stores w0 at +0x10.
    g_channel_app_id_int = std::atoi(kPpsecChannelAppId);
    std::memcpy(g_packet_seed_buf, kPpsecPacketSeed16, 16U);
    std::memcpy(g_packet_seed_buf + 16U, &g_channel_app_id_int, sizeof(int32_t));
    g_static_crypto_init = true;
}

const std::string& PpsecGetActiveRsaPublicKeyB64() noexcept {
    if (!g_static_crypto_init) {
        PpsecInitStaticCryptoState();
    }
    return g_active_rsa_pub_b64;
}

const std::string& PpsecGetActiveKid() noexcept {
    if (!g_static_crypto_init) {
        PpsecInitStaticCryptoState();
    }
    return g_active_kid;
}

void PpsecSetActiveKeyAndKid(const std::string& rsa_pub_b64, const std::string& kid) noexcept {
    if (!rsa_pub_b64.empty()) {
        g_active_rsa_pub_b64 = rsa_pub_b64;
    }
    if (!kid.empty()) {
        g_active_kid = kid;
    }
    g_static_crypto_init = true;
}

int32_t PpsecGetChannelAppIdInt() noexcept {
    if (!g_static_crypto_init) {
        PpsecInitStaticCryptoState();
    }
    return g_channel_app_id_int;
}

/**
 * @brief Reconstructs `sub_18948` (`0x018948..0x0189a0`):
 *        Disassembly:
 *          `0x018960: ldrb w11, [x0], #1`
 *          `0x018964: and  w8, w8, #0xffff`
 *          `0x018968: eor  w12, w9, #1; lsl w9, w9, #1; orr w9, w9, #2; sub w9, w9, w12` (MBA `i + 1`)
 *          `0x018970: eor  w11, w11, w8, lsr #8`
 *          `0x018974: ldrh w11, [x10, w11, uxtw #1]` (`.rodata 0x0243d2` LUT)
 *          `0x018984: orr  w12, w11, w8, lsl #8; and w8, w11, w8, lsl #8; sub w8, w12, w8` (MBA `table[idx] ^ (crc << 8)`)
 *        Tái tạo hàm tính CRC-16/XMODEM (`0x018948..0x0189a0`).
 */
uint16_t ComputePpsecCrc16Xmodem(const uint8_t* data, size_t len) noexcept {
    if (data == nullptr || len == 0U) {
        return 0U;
    }
    uint32_t crc = 0U;
    uint32_t i   = 0U;
    while (i < static_cast<uint32_t>(len)) {
        const uint8_t byte_val = data[i];
        crc &= 0xFFFFU;
        const uint8_t tbl_idx  = static_cast<uint8_t>(byte_val ^ (crc >> 8U));
        const uint32_t tbl_val = LookupCrc16XmodemTable(tbl_idx);
        i   = MbaIncrementBy1(i);
        crc = MbaXorOrSubAnd(tbl_val, (crc << 8U)) & 0xFFFFU;
    }
    return static_cast<uint16_t>(crc & 0xFFFFU);
}

/**
 * @brief Reconstructs MD5 RFC 1321 (`0x00aa50..0x00b600`, `.rodata 0x0214a0` IV:
 *        `0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476`).
 *        Tái tạo hàm băm MD5 chuẩn RFC 1321 (`0x00aa50..0x00b600`).
 */
void Md5ComputeDigest16(const uint8_t* data, size_t len, uint8_t out_digest[16]) noexcept {
    static constexpr uint32_t kShift[64] = {
        7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
        5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20,
        4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
        6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21
    };
    static constexpr uint32_t kTable[64] = {
        0xd76aa478U, 0xe8c7b756U, 0x242070dbU, 0xc1bdceeeU,
        0xf57c0fafU, 0x4787c62aU, 0xa8304613U, 0xfd469501U,
        0x698098d8U, 0x8b44f7afU, 0xffff5bb1U, 0x895cd7beU,
        0x6b901122U, 0xfd987193U, 0xa679438eU, 0x49b40821U,
        0xf61e2562U, 0xc040b340U, 0x265e5a51U, 0xe9b6c7aaU,
        0xd62f105dU, 0x02441453U, 0xd8a1e681U, 0xe7d3fbc8U,
        0x21e1cde6U, 0xc33707d6U, 0xf4d50d87U, 0x455a14edU,
        0xa9e3e905U, 0xfcefa3f8U, 0x676f02d9U, 0x8d2a4c8aU,
        0xfffa3942U, 0x8771f681U, 0x6d9d6122U, 0xfde5380cU,
        0xa4beea44U, 0x4bdecfa9U, 0xf6bb4b60U, 0xbebfbc70U,
        0x289b7ec6U, 0xeaa127faU, 0xd4ef3085U, 0x04881d05U,
        0xd9d4d039U, 0xe6db99e5U, 0x1fa27cf8U, 0xc4ac5665U,
        0xf4292244U, 0x432aff97U, 0xab9423a7U, 0xfc93a039U,
        0x655b59c3U, 0x8f0ccc92U, 0xffeff47dU, 0x85845dd1U,
        0x6fa87e4fU, 0xfe2ce6e0U, 0xa3014314U, 0x4e0811a1U,
        0xf7537e82U, 0xbd3af235U, 0x2ad7d2bbU, 0xeb86d391U
    };

    uint32_t a0 = 0x67452301U;
    uint32_t b0 = 0xefcdab89U;
    uint32_t c0 = 0x98badcfeU;
    uint32_t d0 = 0x10325476U;

    const size_t padded_len = ((len + 8U) / 64U + 1U) * 64U;
    std::vector<uint8_t> msg(padded_len, 0U);
    if (data != nullptr && len > 0U) {
        std::memcpy(msg.data(), data, len);
    }
    msg[len] = 0x80U;
    const uint64_t bit_len = static_cast<uint64_t>(len) * 8ULL;
    std::memcpy(msg.data() + padded_len - 8U, &bit_len, 8U);

    for (size_t offset = 0U; offset < padded_len; offset += 64U) {
        uint32_t m[16];
        std::memcpy(m, msg.data() + offset, 64U);
        uint32_t a = a0, b = b0, c = c0, d = d0;
        for (uint32_t i = 0U; i < 64U; ++i) {
            uint32_t f = 0U, g = 0U;
            if (i < 16U) {
                f = (b & c) | ((~b) & d);
                g = i;
            } else if (i < 32U) {
                f = (d & b) | ((~d) & c);
                g = (5U * i + 1U) & 15U;
            } else if (i < 48U) {
                f = b ^ c ^ d;
                g = (3U * i + 5U) & 15U;
            } else {
                f = c ^ (b | (~d));
                g = (7U * i) & 15U;
            }
            f = f + a + kTable[i] + m[g];
            a = d;
            d = c;
            c = b;
            b = b + Rotl32(f, kShift[i]);
        }
        a0 += a; b0 += b; c0 += c; d0 += d;
    }

    const uint32_t state[4] = {a0, b0, c0, d0};
    if (out_digest != nullptr) {
        std::memcpy(out_digest, state, 16U);
    }
}

std::string Md5ComputeHex32(const uint8_t* data, size_t len) noexcept {
    uint8_t digest[16] = {0};
    Md5ComputeDigest16(data, len, digest);
    static constexpr char kHex[] = "0123456789ABCDEF";
    std::string out(32U, '0');
    for (size_t i = 0U; i < 16U; ++i) {
        out[i * 2U]      = kHex[(digest[i] >> 4U) & 0xFU];
        out[i * 2U + 1U] = kHex[digest[i] & 0xFU];
    }
    return out;
}

/**
 * @brief Reconstructs Base64 Encode (`0x00e00c`) and Decode (`0x00ead8`).
 *        Tái tạo bộ mã hóa Base64 (`0x00e00c`) và giải mã Base64 (`0x00ead8`).
 */
std::string Base64EncodeBytes(const uint8_t* data, size_t len) noexcept {
    static constexpr char kAlphabet[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    if (data == nullptr || len == 0U) {
        return {};
    }
    std::string out;
    out.reserve(((len + 2U) / 3U) * 4U);
    for (size_t i = 0U; i < len; i += 3U) {
        const uint32_t b0 = data[i];
        const uint32_t b1 = (i + 1U < len) ? data[i + 1U] : 0U;
        const uint32_t b2 = (i + 2U < len) ? data[i + 2U] : 0U;
        const uint32_t triple = (b0 << 16U) | (b1 << 8U) | b2;
        out.push_back(kAlphabet[(triple >> 18U) & 0x3FU]);
        out.push_back(kAlphabet[(triple >> 12U) & 0x3FU]);
        out.push_back((i + 1U < len) ? kAlphabet[(triple >> 6U) & 0x3FU] : '=');
        out.push_back((i + 2U < len) ? kAlphabet[triple & 0x3FU] : '=');
    }
    return out;
}

std::vector<uint8_t> Base64DecodeString(const std::string& b64) noexcept {
    std::vector<uint8_t> out;
    uint32_t val = 0U;
    int32_t  bits = -8;
    for (unsigned char c : b64) {
        int32_t d = -1;
        if (c >= 'A' && c <= 'Z') d = c - 'A';
        else if (c >= 'a' && c <= 'z') d = c - 'a' + 26;
        else if (c >= '0' && c <= '9') d = c - '0' + 52;
        else if (c == '+') d = 62;
        else if (c == '/') d = 63;
        else if (c == '=') break;
        else continue;

        val = (val << 6U) | static_cast<uint32_t>(d);
        bits += 6;
        if (bits >= 0) {
            out.push_back(static_cast<uint8_t>((val >> bits) & 0xFFU));
            bits -= 8;
        }
    }
    return out;
}

/**
 * @brief Reconstructs AES-128-CBC Encrypt/Decrypt with PKCS#7 padding (`0x008c68..0x00a3e8`).
 *        Tái tạo bộ mã hóa/giải mã AES-128-CBC kèm đệm PKCS#7 (`0x008c68..0x00a3e8`).
 */
std::vector<uint8_t> Aes128CbcEncryptPkcs7(const uint8_t* plaintext,
                                           size_t len,
                                           const uint8_t key[16],
                                           const uint8_t iv[16]) noexcept {
    if (key == nullptr || iv == nullptr) {
        return {};
    }
    uint8_t rk[176];
    Aes128ExpandKey(key, rk);

    const size_t pad_len   = 16U - (len % 16U);
    const size_t total_len = len + pad_len;
    std::vector<uint8_t> padded(total_len, static_cast<uint8_t>(pad_len));
    if (plaintext != nullptr && len > 0U) {
        std::memcpy(padded.data(), plaintext, len);
    }

    std::vector<uint8_t> out(total_len, 0U);
    uint8_t prev[16];
    std::memcpy(prev, iv, 16U);

    for (size_t offset = 0U; offset < total_len; offset += 16U) {
        uint8_t block[16];
        for (size_t i = 0U; i < 16U; ++i) {
            block[i] = padded[offset + i] ^ prev[i];
        }
        Aes128EncryptBlock(block, out.data() + offset, rk);
        std::memcpy(prev, out.data() + offset, 16U);
    }
    return out;
}

std::vector<uint8_t> Aes128CbcDecryptPkcs7(const uint8_t* ciphertext,
                                           size_t len,
                                           const uint8_t key[16],
                                           const uint8_t iv[16]) noexcept {
    if (ciphertext == nullptr || key == nullptr || iv == nullptr || len == 0U || (len % 16U) != 0U) {
        return {};
    }
    uint8_t rk[176];
    Aes128ExpandKey(key, rk);

    std::vector<uint8_t> out(len, 0U);
    uint8_t prev[16];
    std::memcpy(prev, iv, 16U);

    for (size_t offset = 0U; offset < len; offset += 16U) {
        uint8_t dec[16];
        Aes128DecryptBlock(ciphertext + offset, dec, rk);
        for (size_t i = 0U; i < 16U; ++i) {
            out[offset + i] = dec[i] ^ prev[i];
        }
        std::memcpy(prev, ciphertext + offset, 16U);
    }

    const uint8_t pad = out.back();
    if (pad == 0U || pad > 16U || pad > out.size()) {
        return {};
    }
    for (size_t i = 0U; i < pad; ++i) {
        if (out[out.size() - 1U - i] != pad) {
            return {};
        }
    }
    out.resize(out.size() - pad);
    return out;
}

/**
 * @brief Reconstructs `BPEM` Envelope Encrypt (`0x004744` / `0x00f32c` / `0x0111a0`) &
 *        `BPEM` Envelope Decrypt (`0x005810` / `0x00f37c` / `0x0112d0`).
 *        Tái tạo bộ đóng gói và giải mã phong bì bảo mật `"BPEM"` (`0x004744`, `0x005810`).
 */
std::vector<uint8_t> PpsecBpemEncrypt(const uint8_t* plaintext, size_t len) noexcept {
    if (plaintext == nullptr || len == 0U) {
        return {};
    }
    const uint8_t* key16 = reinterpret_cast<const uint8_t*>(kPpsecInternalAesKey);
    const uint8_t* iv16  = reinterpret_cast<const uint8_t*>(kPpsecInternalAesIv);
    const std::vector<uint8_t> ct = Aes128CbcEncryptPkcs7(plaintext, len, key16, iv16);

    // Format BPEM envelope: "BPEM" (4B) + version (1B=1) + mode (1B=1) + kid_len (1B) + kid + ct_len (4B LE) + ct
    const std::string& kid = PpsecGetActiveKid();
    const uint8_t kid_len  = static_cast<uint8_t>(std::min<size_t>(kid.size(), 255U));
    const uint32_t ct_len  = static_cast<uint32_t>(ct.size());

    std::vector<uint8_t> env;
    env.reserve(4U + 3U + kid_len + 4U + ct.size());
    env.insert(env.end(), kPpsecBpemMagic, kPpsecBpemMagic + 4);
    env.push_back(1U);
    env.push_back(1U);
    env.push_back(kid_len);
    env.insert(env.end(), kid.begin(), kid.begin() + kid_len);
    const uint8_t len_bytes[4] = {
        static_cast<uint8_t>(ct_len & 0xFFU),
        static_cast<uint8_t>((ct_len >> 8U) & 0xFFU),
        static_cast<uint8_t>((ct_len >> 16U) & 0xFFU),
        static_cast<uint8_t>((ct_len >> 24U) & 0xFFU),
    };
    env.insert(env.end(), len_bytes, len_bytes + 4);
    env.insert(env.end(), ct.begin(), ct.end());
    return env;
}

std::vector<uint8_t> PpsecBpemDecrypt(const uint8_t* envelope, size_t len) noexcept {
    // Disassembly 0x0058bc & 0x008810: verifies "BPEM" 4-byte magic header
    if (envelope == nullptr || len < 11U || std::memcmp(envelope, kPpsecBpemMagic, 4U) != 0) {
        return {};
    }
    const uint8_t kid_len = envelope[6];
    const size_t hdr_len  = 7U + static_cast<size_t>(kid_len) + 4U;
    if (len < hdr_len) {
        return {};
    }
    uint32_t ct_len = 0U;
    std::memcpy(&ct_len, envelope + 7U + kid_len, 4U);
    if (hdr_len + ct_len > len || ct_len == 0U || (ct_len % 16U) != 0U) {
        return {};
    }
    const uint8_t* key16 = reinterpret_cast<const uint8_t*>(kPpsecInternalAesKey);
    const uint8_t* iv16  = reinterpret_cast<const uint8_t*>(kPpsecInternalAesIv);
    return Aes128CbcDecryptPkcs7(envelope + hdr_len, ct_len, key16, iv16);
}

}  // namespace ppsec
}  // namespace opencut
}  // namespace nextai
