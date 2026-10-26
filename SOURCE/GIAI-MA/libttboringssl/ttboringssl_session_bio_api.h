/**
 * @file ttboringssl_session_bio_api.h
 * @brief Cleanroom C++17 SSL_SESSION Serialization, BIO Layer & SSL/SSL_CTX Core API
 *        Tuần tự hóa SSL_SESSION, tầng luồng BIO và các API cốt lõi của SSL/SSL_CTX
 *
 * Binary Ground Truth / Đối chứng nhị phân:
 * - BIO_f_ssl @ 0x014a5c (12 B), BIO_set_ssl @ 0x014a68 (16 B)
 * - _ZN4bssl17SSL_SESSION_parse... @ 0x02afb8 (2272 B)
 * - SSL_SESSION_to_bytes @ 0x02c1c8 (200 B):
 *   0x02c1f0: ldrb w8, [x0, #0x1b0]
 *   0x02c1f4: tbnz w8, #2, #0x2c230 ; if not_resumable, outputs 14-byte "NOT RESUMABLE\0"
 * - SSL_SESSION_to_bytes_for_ticket @ 0x02c290 (140 B)
 * - i2d_SSL_SESSION @ 0x02c31c (164 B)
 * - SSL_SESSION_from_bytes @ 0x02c3c0 (152 B)
 * - SSL_CTX_new @ 0x03249c (332 B), SSL_CTX_up_ref @ 0x03263c (28 B), SSL_CTX_free @ 0x032658 (64 B)
 * - SSL_new @ 0x032828 (704 B), SSL_free @ 0x032b8c (4 B)
 * - SSL_set_connect_state @ 0x032bbc (20 B), SSL_set_accept_state @ 0x032bd0 (20 B)
 * - SSL_set_bio @ 0x032bf4 (148 B), SSL_get_rbio @ 0x032c88 (8 B), SSL_get_wbio @ 0x032c90 (8 B)
 * - SSL_do_handshake @ 0x032dc0 (208 B), SSL_connect @ 0x032ee0 (32 B), SSL_accept @ 0x032f00 (32 B)
 * - SSL_read @ 0x0330ac (92 B), SSL_write @ 0x03335c (264 B), SSL_shutdown @ 0x03350c (276 B)
 * - SSL_get_error @ 0x0337e4 (276 B)
 */

#ifndef NEXTAI_OPENCUT_TTBORINGSSL_SESSION_BIO_API_H
#define NEXTAI_OPENCUT_TTBORINGSSL_SESSION_BIO_API_H

#include "ttboringssl_types.h"

namespace nextai {
namespace ttboringssl {

// ============================================================================
// 1. BIO SSL Method & Memory Pair API (bio_ssl.cc @ 0x014a5c..0x014a68)
//    API phương thức BIO SSL và cặp bộ đệm BIO (Đối chiếu tại 0x014a5c..0x014a68)
// ============================================================================
const BIO_METHOD* BIO_f_ssl();
long              BIO_set_ssl(BIO* bio, SSL* ssl, int close_flag);
BIO*              BIO_new_mem();
int               BIO_new_bio_pair(BIO** out1, BIO** out2);
int               BIO_up_ref(BIO* bio);
void              BIO_free(BIO* bio);

// ============================================================================
// 2. SSL_SESSION Lifecycle & Serialization API (0x02afb8..0x02c3c0)
//    Vòng đời và tuần tự hóa ASN.1/TLV của SSL_SESSION (Đối chiếu tại 0x02afb8..0x02c3c0)
// ============================================================================
SSL_SESSION* SSL_SESSION_new();
int          SSL_SESSION_up_ref(SSL_SESSION* session);
void         SSL_SESSION_free(SSL_SESSION* session);
int          SSL_SESSION_to_bytes(const SSL_SESSION* in, uint8_t** out_data, size_t* out_len);
int          SSL_SESSION_to_bytes_for_ticket(const SSL_SESSION* in, uint8_t** out_data, size_t* out_len);
int          i2d_SSL_SESSION(SSL_SESSION* in, uint8_t** pp);
SSL_SESSION* SSL_SESSION_from_bytes(const uint8_t* in, size_t in_len, const SSL_CTX* ctx);

// ============================================================================
// 3. SSL_CTX & SSL Lifecycle, Handshake, Record I/O & Error API (0x03249c..0x0341ac)
//    Vòng đời SSL_CTX & SSL, bắt tay, đọc/ghi bản ghi và kiểm tra lỗi (0x03249c..0x0341ac)
// ============================================================================
SSL_CTX* SSL_CTX_new(const SSL_METHOD* method);
int      SSL_CTX_up_ref(SSL_CTX* ctx);
void     SSL_CTX_free(SSL_CTX* ctx);

SSL*     SSL_new(SSL_CTX* ctx);
int      SSL_up_ref(SSL* ssl);
void     SSL_free(SSL* ssl);

void     SSL_set_connect_state(SSL* ssl);
void     SSL_set_accept_state(SSL* ssl);
void     SSL_set_bio(SSL* ssl, BIO* rbio, BIO* wbio);
BIO*     SSL_get_rbio(const SSL* ssl);
BIO*     SSL_get_wbio(const SSL* ssl);

int      SSL_do_handshake(SSL* ssl);
int      SSL_connect(SSL* ssl);
int      SSL_accept(SSL* ssl);
int      SSL_read(SSL* ssl, void* buf, int num);
int      SSL_write(SSL* ssl, const void* buf, int num);
int      SSL_shutdown(SSL* ssl);
int      SSL_get_error(const SSL* ssl, int ret_code);

// Options, Modes, FDs, Finished, OCSP & Certificate Setters (0x02df5c..0x0341ac)
uint32_t SSL_CTX_set_options(SSL_CTX* ctx, uint32_t options);
uint32_t SSL_CTX_clear_options(SSL_CTX* ctx, uint32_t options);
uint32_t SSL_CTX_get_options(const SSL_CTX* ctx);
uint32_t SSL_set_options(SSL* ssl, uint32_t options);
uint32_t SSL_get_options(const SSL* ssl);
uint32_t SSL_CTX_set_mode(SSL_CTX* ctx, uint32_t mode);
uint32_t SSL_CTX_clear_mode(SSL_CTX* ctx, uint32_t mode);
uint32_t SSL_CTX_get_mode(const SSL_CTX* ctx);
uint32_t SSL_set_mode(SSL* ssl, uint32_t mode);
uint32_t SSL_get_mode(const SSL* ssl);

int      SSL_set_fd(SSL* ssl, int fd);
int      SSL_set_rfd(SSL* ssl, int fd);
int      SSL_set_wfd(SSL* ssl, int fd);
int      SSL_get_fd(const SSL* ssl);
int      SSL_get_rfd(const SSL* ssl);
int      SSL_get_wfd(const SSL* ssl);

size_t   SSL_get_finished(const SSL* ssl, void* buf, size_t count);
size_t   SSL_get_peer_finished(const SSL* ssl, void* buf, size_t count);
int      SSL_get_extms_support(const SSL* ssl);
int      SSL_get_secure_renegotiation_support(const SSL* ssl);

int      SSL_CTX_use_certificate_ASN1(SSL_CTX* ctx, size_t der_len, const uint8_t* der);
int      SSL_use_certificate_ASN1(SSL* ssl, const uint8_t* der, size_t der_len);
int      SSL_CTX_set_ocsp_response(SSL_CTX* ctx, const uint8_t* response, size_t response_len);
int      SSL_set_ocsp_response(SSL* ssl, const uint8_t* response, size_t response_len);
int      SSL_CTX_set_signed_cert_timestamp_list(SSL_CTX* ctx, const uint8_t* list, size_t list_len);
int      SSL_set_signed_cert_timestamp_list(SSL* ssl, const uint8_t* list, size_t list_len);
int      SSL_set1_delegated_credential(SSL* ssl, const uint8_t* dc, size_t dc_len);
int      SSL_delegated_credential_used(const SSL* ssl);

size_t   SSL_CTX_get_max_cert_list(const SSL_CTX* ctx);
void     SSL_CTX_set_max_cert_list(SSL_CTX* ctx, size_t max_cert_list);
size_t   SSL_get_max_cert_list(const SSL* ssl);
void     SSL_set_max_cert_list(SSL* ssl, size_t max_cert_list);
int      SSL_set_mtu(SSL* ssl, unsigned int mtu);

} // namespace ttboringssl
} // namespace nextai

#endif // NEXTAI_OPENCUT_TTBORINGSSL_SESSION_BIO_API_H
