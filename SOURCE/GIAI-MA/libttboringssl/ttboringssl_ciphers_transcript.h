/**
 * @file ttboringssl_ciphers_transcript.h
 * @brief Cleanroom C++17 Cipher Suite Registry, TLS 1.2 PRF & TLS 1.3 HKDF Key Schedule
 *        Bảng đăng ký Cipher Suite, hàm PRF TLS 1.2 và lịch sinh khóa HKDF TLS 1.3
 *
 * Binary Ground Truth / Đối chứng nhị phân:
 * - SSL_get_cipher_by_value @ 0x02fae0 (108 B)
 * - SSL_CIPHER_get_id @ 0x02fb64 (4 B -> 0x030320)
 * - SSL_CIPHER_get_protocol_id @ 0x02fb68 (4 B -> 0x030320)
 * - SSL_CIPHER_get_value @ 0x02fb6c (4 B -> 0x030320)
 * - SSL_CIPHER_is_aead @ 0x02fb70 (12 B): ldr w8, [x0, #0x20]; ubfx w0, w8, #1, #1
 * - SSL_CIPHER_get_cipher_nid @ 0x02fb7c (108 B): maps algorithm_enc (+0x1c) to NID_*
 * - SSL_CIPHER_get_digest_nid @ 0x02fbe8 (28 B): maps algorithm_mac (+0x20) to NID_sha1 (64) or NID_undef (0)
 * - SSL_CIPHER_get_kx_nid @ 0x02fc04 (32 B)
 * - SSL_CIPHER_get_auth_nid @ 0x02fc24 (32 B)
 * - SSL_CIPHER_get_prf_nid @ 0x02fc44 (32 B)
 * - _ZN4bssl23SSL_get_traffic_secretsEPK6ssl_stPNS_4SpanIKhEES6_ @ 0x03224c (124 B)
 */

#ifndef NEXTAI_OPENCUT_TTBORINGSSL_CIPHERS_TRANSCRIPT_H
#define NEXTAI_OPENCUT_TTBORINGSSL_CIPHERS_TRANSCRIPT_H

#include "ttboringssl_types.h"

namespace nextai {
namespace ttboringssl {

// ============================================================================
// 1. Cipher Suite Lookup & Inspection API (ssl_cipher.cc @ 0x02fae0..0x02fc44)
//    API tra cứu và kiểm tra Cipher Suite (Đối chiếu ssl_cipher.cc tại 0x02fae0..0x02fc44)
// ============================================================================
const SSL_CIPHER* SSL_get_cipher_by_value(uint16_t value);
uint32_t          SSL_CIPHER_get_id(const SSL_CIPHER* cipher);
uint16_t          SSL_CIPHER_get_protocol_id(const SSL_CIPHER* cipher);
uint16_t          SSL_CIPHER_get_value(const SSL_CIPHER* cipher);
int               SSL_CIPHER_is_aead(const SSL_CIPHER* cipher);
int               SSL_CIPHER_get_cipher_nid(const SSL_CIPHER* cipher);
int               SSL_CIPHER_get_digest_nid(const SSL_CIPHER* cipher);
int               SSL_CIPHER_get_kx_nid(const SSL_CIPHER* cipher);
int               SSL_CIPHER_get_auth_nid(const SSL_CIPHER* cipher);
int               SSL_CIPHER_get_prf_nid(const SSL_CIPHER* cipher);
const char*       SSL_CIPHER_get_name(const SSL_CIPHER* cipher);
const char*       SSL_CIPHER_standard_name(const SSL_CIPHER* cipher);
int               SSL_CTX_set_strict_cipher_list(SSL_CTX* ctx, const char* str);

// ============================================================================
// 2. Curve & Signature Algorithm Names (ssl_key_share.cc @ 0x031290)
//    Tên đường cong Eliptic và thuật toán chữ ký (Đối chiếu tại 0x031290)
// ============================================================================
const char* SSL_get_curve_name(uint16_t curve_id);

// ============================================================================
// 3. TLS 1.3 HKDF-Expand-Label & Key Schedule (tls13_enc.cc & ssl_transcript.cc)
//    Hàm mở rộng nhãn HKDF-Expand-Label và lịch trình khóa TLS 1.3 (RFC 8446)
// ============================================================================
void sha256_digest(const uint8_t* data, size_t len, uint8_t out_digest[32]);
void hmac_sha256_compute(const uint8_t* key, size_t key_len,
                         const uint8_t* data, size_t data_len,
                         uint8_t out_mac[32]);
void hkdf_extract_sha256(const uint8_t* salt, size_t salt_len,
                         const uint8_t* ikm, size_t ikm_len,
                         uint8_t out_prk[32]);
bool hkdf_expand_label_sha256(const uint8_t* secret, size_t secret_len,
                              const char* label,
                              const uint8_t* context, size_t context_len,
                              uint8_t* out, size_t out_len);
bool tls13_derive_secret_sha256(const uint8_t secret[32],
                                const char* label,
                                const uint8_t* transcript_bytes,
                                size_t transcript_len,
                                uint8_t out_secret[32]);
bool tls13_init_key_schedule(SSL_HANDSHAKE* hs, const uint8_t* psk, size_t psk_len);
bool tls13_advance_key_schedule(SSL_HANDSHAKE* hs, const uint8_t* ikm, size_t ikm_len);
bool tls13_derive_early_secret(SSL_HANDSHAKE* hs);
bool tls13_derive_handshake_secrets(SSL_HANDSHAKE* hs);
bool tls13_derive_application_secrets(SSL_HANDSHAKE* hs);
bool tls13_finished_mac(const uint8_t base_key[32],
                        const uint8_t* transcript_bytes,
                        size_t transcript_len,
                        uint8_t out_verify_data[32]);

// ============================================================================
// 4. TLS 1.2 PRF & Finished MAC (t1_enc.cc @ .rodata "master secret")
//    Hàm giả ngẫu nhiên PRF TLS 1.2 và tính toán Finished MAC
// ============================================================================
bool tls1_prf_sha256(const uint8_t* secret, size_t secret_len,
                     const char* label,
                     const uint8_t* seed1, size_t seed1_len,
                     const uint8_t* seed2, size_t seed2_len,
                     uint8_t* out, size_t out_len);

// ============================================================================
// 5. Traffic Secrets Accessor (_ZN4bssl23SSL_get_traffic_secrets... @ 0x03224c)
//    Trích xuất khóa luồng đọc/ghi TLS 1.3 (Đối chiếu tại 0x03224c)
// ============================================================================
bool bssl_SSL_get_traffic_secrets(const SSL* ssl,
                                  const uint8_t** out_read_traffic_secret,
                                  size_t* out_read_secret_len,
                                  const uint8_t** out_write_traffic_secret,
                                  size_t* out_write_secret_len);

} // namespace ttboringssl
} // namespace nextai

#endif // NEXTAI_OPENCUT_TTBORINGSSL_CIPHERS_TRANSCRIPT_H
