// ============================================================================
// Clean-Room C++17 Core Header for libtobEmbedPagEncrypt.so (Target 127 / 169)
// Giao diện lõi C++17 sạch cho libtobEmbedPagEncrypt.so (Mục tiêu 127 / 169)
// ============================================================================
#pragma once

#include "tobEmbedPagEncrypt_types.h"

namespace tob_embed_pag_encrypt {

// Internal Key Schedule Function `sub_d0c` (`0x000d0c..0x000ea0`, 404 bytes):
// Expands `key[0..key_len-1]` to 16 bytes (padding via `sbox1` if `key_len < 16`),
// substitutes all 16 bytes through `sbox0`, and converts each 32-bit word via `ByteSwap32` (`rev`).
// Hàm mở rộng khóa nội bộ `sub_d0c` (0x0d0c..0x0ea0, 404 byte):
void DeriveRoundKeys128(const uint8_t* raw_key, int32_t key_len, uint32_t out_k[4]) noexcept;

// Returns pointer to the 20-byte `.bss` key buffer (`0x009830`)
const char* GetGlobalBssKeyBuffer() noexcept;

// Executes any of the 537 AArch64 instructions in .text (0x0a94..0x12f8)
uint64_t ExecuteTobEncryptTextInstructionVerify(uint32_t insn_idx, uint64_t seed) noexcept;

} // namespace tob_embed_pag_encrypt

extern "C" {
// 8 Exported Symbols in .dynsym (indices [10..17]):
// 8 biểu tượng xuất khẩu trong bảng .dynsym ([10..17]):
extern const uint8_t sbox0[256]; // [13] @ 0x009630 (256 B)
extern const uint8_t sbox1[256]; // [10] @ 0x009730 (256 B)

int32_t ss_encrypted_size(int32_t in_size); // [11] @ 0x000ad0 (116 B)
void    initKey();                          // [12] @ 0x001018 ( 88 B)
int32_t ss_encrypt(const uint8_t* in_buf, int32_t in_len, const uint8_t* key, int32_t key_len, uint8_t* out_buf); // [15] @ 0x000b44 (456 B)
int32_t ss_decrypt(uint8_t* buf, int32_t len, const uint8_t* key, int32_t key_len); // [14] @ 0x000ea0 (376 B)

jbyteArray Java_com_bytedance_sdk_component_embedapplog_PangleEncryptUtils_ttEncrypt(
    JNIEnv* env, jclass clazz, jbyteArray plain_array, jint plain_len); // [17] @ 0x001070 (344 B)

jbyteArray Java_com_bytedance_sdk_component_embedapplog_PangleEncryptUtils_ttDecrypt(
    JNIEnv* env, jclass clazz, jbyteArray cipher_array, jint cipher_len); // [16] @ 0x0011c8 (304 B)
}
