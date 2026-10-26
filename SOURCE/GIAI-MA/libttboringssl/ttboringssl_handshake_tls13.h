/**
 * @file ttboringssl_handshake_tls13.h
 * @brief Cleanroom C++17 TLS 1.2/1.3 Handshake State Machine, ECH & Split-Handshake Handoff
 *        Máy trạng thái bắt tay TLS 1.2/1.3, Encrypted Client Hello (ECH) và Handoff/Handback
 *
 * Binary Ground Truth / Đối chứng nhị phân:
 * - _ZN4bssl29ssl_decode_client_hello_innerEP6ssl_st... @ 0x01743c (1224 B)
 * - _ZN4bssl28ssl_is_valid_ech_public_nameENS_4SpanIKhEE @ 0x017b20 (520 B)
 * - SSL_set_enable_ech_grease @ 0x018c9c (36 B)
 * - SSL_set1_ech_config_list @ 0x018cc0 (116 B)
 * - SSL_marshal_ech_config @ 0x018db8 (504 B)
 * - SSL_ECH_KEYS_new @ 0x018fb0, SSL_ECH_KEYS_add @ 0x019050, SSL_ECH_KEYS_free @ 0x01900c
 * - SSL_ech_accepted @ 0x019424 (84 B)
 * - _ZN4bssl21SSL_serialize_handoff... @ 0x01fe40 (284 B)
 * - _ZN4bssl17SSL_apply_handoff... @ 0x020094 (344 B)
 * - _ZN4bssl22SSL_serialize_handback... @ 0x0205f8 (1216 B)
 * - _ZN4bssl18SSL_apply_handback... @ 0x020ab8 (2180 B)
 * - SSL_do_handshake @ 0x032dc0 (208 B)
 */

#ifndef NEXTAI_OPENCUT_TTBORINGSSL_HANDSHAKE_TLS13_H
#define NEXTAI_OPENCUT_TTBORINGSSL_HANDSHAKE_TLS13_H

#include "ttboringssl_types.h"

namespace nextai {
namespace ttboringssl {

// ============================================================================
// 1. Handshake State Machine Drivers & State String Tables
//    Bộ điều khiển máy trạng thái bắt tay và bảng chuỗi trạng thái (.rodata)
// ============================================================================
const char* ssl_client_handshake_state_string(int32_t state);
const char* ssl_server_handshake_state_string(int32_t state);
int         ssl_client_handshake(SSL_HANDSHAKE* hs);
int         ssl_server_handshake(SSL_HANDSHAKE* hs);

// ============================================================================
// 2. Encrypted Client Hello (ECH) API (encrypted_client_hello.cc @ 0x017b20..0x019424)
//    API Encrypted Client Hello (ECH) (Đối chiếu tại 0x017b20..0x019424)
// ============================================================================
bool          bssl_ssl_is_valid_ech_public_name(const uint8_t* name, size_t name_len);
void          SSL_set_enable_ech_grease(SSL* ssl, int enable);
int           SSL_set1_ech_config_list(SSL* ssl, const uint8_t* ech_config_list, size_t ech_config_list_len);
void          SSL_get0_ech_name_override(const SSL* ssl, const char** out_name, size_t* out_name_len);
void          SSL_get0_ech_retry_configs(const SSL* ssl, const uint8_t** out_retry_configs, size_t* out_retry_configs_len);
int           SSL_marshal_ech_config(uint8_t** out_enc, size_t* out_enc_len,
                                     uint8_t config_id,
                                     const uint8_t public_key[32],
                                     const char* public_name,
                                     size_t max_name_len);
SSL_ECH_KEYS* SSL_ECH_KEYS_new();
int           SSL_ECH_KEYS_up_ref(SSL_ECH_KEYS* keys);
void          SSL_ECH_KEYS_free(SSL_ECH_KEYS* keys);
int           SSL_ECH_KEYS_add(SSL_ECH_KEYS* keys, int is_retry_config,
                               const uint8_t* ech_config, size_t ech_config_len,
                               const uint8_t private_key[32]);
int           SSL_ECH_KEYS_has_duplicate_config_id(const SSL_ECH_KEYS* keys);
int           SSL_ECH_KEYS_marshal_retry_configs(const SSL_ECH_KEYS* keys,
                                                 uint8_t** out, size_t* out_len);
int           SSL_CTX_set1_ech_keys(SSL_CTX* ctx, SSL_ECH_KEYS* keys);
int           SSL_ech_accepted(const SSL* ssl);

// ============================================================================
// 3. Split-Handshake Handoff / Handback & Hints API (handoff.cc @ 0x01fe40..0x02186c)
//    API Handoff / Handback tách pha bắt tay (Đối chiếu handoff.cc tại 0x01fe40..0x02186c)
// ============================================================================
void SSL_CTX_set_handoff_mode(SSL_CTX* ctx, bool on);
void SSL_set_handoff_mode(SSL* ssl, bool on);
bool SSL_serialize_handoff(const SSL* ssl, std::vector<uint8_t>* out_handoff);
bool SSL_decline_handoff(SSL* ssl);
bool SSL_apply_handoff(SSL* ssl, const uint8_t* handoff, size_t handoff_len);
bool SSL_serialize_handback(const SSL* ssl, std::vector<uint8_t>* out_handback);
bool SSL_apply_handback(SSL* ssl, const uint8_t* handback, size_t handback_len);

} // namespace ttboringssl
} // namespace nextai

#endif // NEXTAI_OPENCUT_TTBORINGSSL_HANDSHAKE_TLS13_H
