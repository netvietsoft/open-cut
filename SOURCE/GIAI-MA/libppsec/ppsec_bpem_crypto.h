/**
 * @file ppsec_bpem_crypto.h
 * @brief Clean-Room Header for `BPEM` Envelope Crypto, AES-128-CBC, MD5, Base64 & CRC-16/XMODEM Engine.
 *        Header tái tạo sạch bộ mã hóa phong bì `BPEM`, AES-128-CBC, MD5, Base64 và CRC-16/XMODEM của libppsec.so.
 *
 * Binary Target / Mục tiêu nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/libppsec.so
 *   Addresses covered / Phạm vi địa chỉ:
 *     - 0x002a10..0x002aa8 : `.init_array[0]` (initializes 344-byte Base64 RSA public key & default Kid `"0"`)
 *     - 0x004744..0x008e20 : `BPEM` Envelope Encrypt (`0x004744`) & Decrypt (`0x005810`), Key Store (`0x007550`)
 *     - 0x009140..0x00a3e8 : AES-128/256 Key Schedule & CBC Encrypt/Decrypt (`.rodata 0x01d048` S-Box & T-Tables)
 *     - 0x00aa50..0x00b800 : MD5 Digest Engine (`.rodata 0x0214a0` IV: `0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476`)
 *     - 0x00e00c..0x00f0a8 : Base64 Encode (`0x00e00c`) & Decode (`0x00ead8`)
 *     - 0x00f1c8..0x00f3c8 : `CryptTool` C++ Singleton & `BPEM` Dispatch (`0x00f32c`, `0x00f37c`)
 *     - 0x0111a0..0x011948 : `CryptTool::encrypt` (`0x0115ec`), `decrypt` (`0x0117a0`), `getKid` (`0x011948`)
 *     - 0x0185fc..0x0189a0 : `.init_array[1]` (`0x0185fc`) & CRC-16/XMODEM (`0x018948`, `.rodata 0x0243d2`)
 */

#ifndef NEXTAI_OPENCUT_PPSEC_BPEM_CRYPTO_H_
#define NEXTAI_OPENCUT_PPSEC_BPEM_CRYPTO_H_

#include "ppsec_types.h"

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace nextai {
namespace opencut {
namespace ppsec {

/**
 * @brief Reconstructs `.init_array[0]` (`0x002a10..0x002aa8`) and `.init_array[1]` (`0x0185fc..0x018940`):
 *        Initializes `.bss 0x02c9e0` (344-byte Base64 RSA public key), `.bss 0x02c9f8` (Kid `"0"`),
 *        and `.bss 0x02e48c` (16-byte packet seed + `atoi("19572") = 19572`).
 *        Tái tạo hàm khởi tạo tĩnh `.init_array[0]` (`0x002a10`) và `.init_array[1]` (`0x0185fc`).
 */
void PpsecInitStaticCryptoState() noexcept;

const std::string& PpsecGetActiveRsaPublicKeyB64() noexcept;
const std::string& PpsecGetActiveKid() noexcept;
void               PpsecSetActiveKeyAndKid(const std::string& rsa_pub_b64, const std::string& kid) noexcept;
int32_t            PpsecGetChannelAppIdInt() noexcept;

/**
 * @brief Reconstructs `sub_18948` (`0x018948..0x0189a0`):
 *        Computes CRC-16/XMODEM (`poly = 0x1021`, `init = 0x0000`) over `data[0..len-1]`
 *        using the 256-entry lookup table at `.rodata 0x0243d2` and MBA XOR `(a | b) - (a & b)`.
 *        Tái tạo hàm tính mã kiểm tra dư thừa vòng CRC-16/XMODEM (`0x018948..0x0189a0`).
 */
uint16_t ComputePpsecCrc16Xmodem(const uint8_t* data, size_t len) noexcept;

/**
 * @brief Reconstructs MD5 RFC 1321 (`0x00aa50..0x00b600`, `.rodata 0x0214a0` IV:
 *        `0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476`).
 *        Tái tạo hàm băm MD5 chuẩn RFC 1321 (`0x00aa50..0x00b600`, vector khởi tạo `.rodata 0x0214a0`).
 */
void Md5ComputeDigest16(const uint8_t* data, size_t len, uint8_t out_digest[16]) noexcept;
std::string Md5ComputeHex32(const uint8_t* data, size_t len) noexcept;

/**
 * @brief Reconstructs Base64 Encode (`0x00e00c`) and Decode (`0x00ead8`).
 *        Tái tạo bộ mã hóa Base64 (`0x00e00c`) và giải mã Base64 (`0x00ead8`).
 */
std::string Base64EncodeBytes(const uint8_t* data, size_t len) noexcept;
std::vector<uint8_t> Base64DecodeString(const std::string& b64) noexcept;

/**
 * @brief Reconstructs AES-128-CBC Encrypt/Decrypt (`0x009140..0x00a3e8`, `.rodata 0x01d048` S-Box)
 *        with PKCS#7 padding (`0x008c68..0x008e20`).
 *        Tái tạo bộ mã hóa/giải mã khối AES-128-CBC (`0x009140..0x00a3e8`) kèm đệm PKCS#7.
 */
std::vector<uint8_t> Aes128CbcEncryptPkcs7(const uint8_t* plaintext,
                                           size_t len,
                                           const uint8_t key[16],
                                           const uint8_t iv[16]) noexcept;

std::vector<uint8_t> Aes128CbcDecryptPkcs7(const uint8_t* ciphertext,
                                           size_t len,
                                           const uint8_t key[16],
                                           const uint8_t iv[16]) noexcept;

/**
 * @brief Reconstructs `BPEM` Envelope Encrypt (`0x004744` / `0x00f32c` / `0x0111a0`) &
 *        `BPEM` Envelope Decrypt (`0x005810` / `0x00f37c` / `0x0112d0`):
 *        Produces and parses `"BPEM"` binary envelopes (`magic "BPEM"`, version, kid, IV, AES-128-CBC payload).
 *        Tái tạo bộ đóng gói và giải mã phong bì bảo mật `"BPEM"` (`0x004744`, `0x005810`, `0x0111a0`, `0x0112d0`).
 */
std::vector<uint8_t> PpsecBpemEncrypt(const uint8_t* plaintext, size_t len) noexcept;
std::vector<uint8_t> PpsecBpemDecrypt(const uint8_t* envelope, size_t len) noexcept;

}  // namespace ppsec
}  // namespace opencut
}  // namespace nextai

#endif  // NEXTAI_OPENCUT_PPSEC_BPEM_CRYPTO_H_
