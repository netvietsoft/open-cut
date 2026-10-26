/**
 * @file ttboringssl_quic_dtls_alpn.h
 * @brief Cleanroom C++17 QUIC Transport Hooks, DTLS Retransmission Timer, SRTP & ALPN/SNI
 *        Tích hợp giao vận QUIC, bộ định thời phát lại DTLS, cấu hình SRTP và ALPN/SNI
 *
 * Binary Ground Truth / Đối chứng nhị phân:
 * - DTLSv1_get_timeout @ 0x0162d4 (316 B)
 * - DTLSv1_set_initial_timeout_duration @ 0x0164fc (8 B): str w1, [x0, #0x50]; ret
 * - DTLSv1_handle_timeout @ 0x016504 (164 B):
 *   0x016544: ldr  w9, [x8, #0x208]
 *   0x016548: lsl  w10, w9, #1
 *   0x01654c: ubfx w9, w9, #4, #0x1b
 *   0x016550: cmp  w9, #0x753
 *   0x016554: mov  w9, #0xea60
 *   0x016558: csel w9, w10, w9, lo
 *   0x01655c: str  w9, [x8, #0x208]
 * - SSL_CTX_set_srtp_profiles @ 0x016a28, SSL_set_srtp_profiles @ 0x016b80
 * - SSL_quic_max_handshake_flight_len @ 0x032c98 (104 B)
 * - SSL_quic_read_level @ 0x032d00 (12 B): ldr x8, [x0, #0x30]; ldr w0, [x8, #0xc8]; ret
 * - SSL_quic_write_level @ 0x032d0c (12 B): ldr x8, [x0, #0x30]; ldr w0, [x8, #0xcc]; ret
 * - SSL_provide_quic_data @ 0x032d18 (168 B)
 * - SSL_process_quic_post_handshake @ 0x032f20 (180 B)
 * - SSL_set_quic_transport_params @ 0x033694 (44 B)
 * - SSL_get_peer_quic_transport_params @ 0x0336c0 (28 B)
 * - SSL_CTX_set_quic_method @ 0x0350d8 (24 B): str x1, [x0, #0x50]
 * - SSL_set_quic_method @ 0x0350f0 (24 B): str x1, [x0, #0x98]
 * - SSL_set_tlsext_host_name @ 0x0346d8 (128 B): sub x8, x0, #1; cmp x8, #0xff
 * - SSL_get_servername @ 0x034588 (36 B): ldr x0, [x0, #0x90]
 * - SSL_CTX_set_alpn_protos @ 0x034880 (84 B), SSL_set_alpn_protos @ 0x0348d4 (96 B)
 * - SSL_get0_alpn_selected @ 0x03493c (88 B)
 */

#ifndef NEXTAI_OPENCUT_TTBORINGSSL_QUIC_DTLS_ALPN_H
#define NEXTAI_OPENCUT_TTBORINGSSL_QUIC_DTLS_ALPN_H

#include "ttboringssl_types.h"

namespace nextai {
namespace ttboringssl {

struct DtlsTimeval {
    uint64_t tv_sec  = 0;
    uint32_t tv_usec = 0;
};

// ============================================================================
// 1. DTLS Timer & SRTP Profile API (0x0162d4..0x016c84)
//    API bộ định thời DTLS và cấu hình SRTP (Đối chiếu tại 0x0162d4..0x016c84)
// ============================================================================
int  DTLSv1_get_timeout(const SSL* ssl, DtlsTimeval* out);
void DTLSv1_set_initial_timeout_duration(SSL* ssl, uint32_t duration_ms);
int  DTLSv1_handle_timeout(SSL* ssl);

int  SSL_CTX_set_srtp_profiles(SSL_CTX* ctx, const char* profiles);
int  SSL_set_srtp_profiles(SSL* ssl, const char* profiles);
int  SSL_CTX_set_tlsext_use_srtp(SSL_CTX* ctx, const char* profiles);
int  SSL_set_tlsext_use_srtp(SSL* ssl, const char* profiles);
const std::vector<const SRTP_PROTECTION_PROFILE*>* SSL_get_srtp_profiles(const SSL* ssl);
const SRTP_PROTECTION_PROFILE* SSL_get_selected_srtp_profile(SSL* ssl);

const SSL_METHOD* DTLS_method();
const SSL_METHOD* DTLS_with_buffers_method();
const SSL_METHOD* DTLSv1_2_method();
const SSL_METHOD* DTLSv1_method();
const SSL_METHOD* DTLS_client_method();
const SSL_METHOD* DTLS_server_method();
const SSL_METHOD* TLS_method();
const SSL_METHOD* TLS_client_method();
const SSL_METHOD* TLS_server_method();

// ============================================================================
// 2. QUIC Transport Integration API (0x032c98..0x0350f0)
//    API tích hợp giao vận QUIC (Đối chiếu tại 0x032c98..0x0350f0)
// ============================================================================
size_t                 SSL_quic_max_handshake_flight_len(const SSL* ssl, ssl_encryption_level_t level);
ssl_encryption_level_t SSL_quic_read_level(const SSL* ssl);
ssl_encryption_level_t SSL_quic_write_level(const SSL* ssl);
int                    SSL_provide_quic_data(SSL* ssl, ssl_encryption_level_t level,
                                             const uint8_t* data, size_t len);
int                    SSL_process_quic_post_handshake(SSL* ssl);
int                    SSL_set_quic_transport_params(SSL* ssl, const uint8_t* params, size_t params_len);
void                   SSL_get_peer_quic_transport_params(const SSL* ssl,
                                                          const uint8_t** out_params,
                                                          size_t* out_params_len);
int                    SSL_set_quic_early_data_context(SSL* ssl, const uint8_t* context, size_t context_len);
int                    SSL_CTX_set_quic_method(SSL_CTX* ctx, const SSL_QUIC_METHOD* quic_method);
int                    SSL_set_quic_method(SSL* ssl, const SSL_QUIC_METHOD* quic_method);
void                   SSL_CTX_set_early_data_enabled(SSL_CTX* ctx, int enabled);
void                   SSL_set_early_data_enabled(SSL* ssl, int enabled);
ssl_early_data_reason_t SSL_get_early_data_reason(const SSL* ssl);

// ============================================================================
// 3. ALPN & SNI Extension API (0x034588..0x03493c)
//    API phần mở rộng ALPN và SNI (Đối chiếu tại 0x034588..0x03493c)
// ============================================================================
int         SSL_set_tlsext_host_name(SSL* ssl, const char* name);
const char* SSL_get_servername(const SSL* ssl, int type);
int         SSL_CTX_set_alpn_protos(SSL_CTX* ctx, const uint8_t* protos, unsigned int protos_len);
int         SSL_set_alpn_protos(SSL* ssl, const uint8_t* protos, unsigned int protos_len);
void        SSL_get0_alpn_selected(const SSL* ssl, const uint8_t** out_data, unsigned int* out_len);
void        SSL_CTX_set_alpn_select_cb(SSL_CTX* ctx, SSL_CTX_alpn_select_cb_func cb, void* arg);
int         SSL_select_next_proto(uint8_t** out, uint8_t* out_len,
                                  const uint8_t* peer, unsigned int peer_len,
                                  const uint8_t* client, unsigned int client_len);

} // namespace ttboringssl
} // namespace nextai

#endif // NEXTAI_OPENCUT_TTBORINGSSL_QUIC_DTLS_ALPN_H
