/**
 * @file ttboringssl_types.h
 * @brief Cleanroom C++17 ABI Type Definitions & Struct Layouts for libttboringssl.so
 *        Định nghĩa kiểu dữ liệu C++17 và bố cục Struct chuẩn ABI cho libttboringssl.so
 *
 * Binary Ground Truth / Đối chứng nhị phân:
 * - Library: SOURCE/apktool-res/lib/arm64-v8a/libttboringssl.so (395,304 bytes)
 * - Architecture: AArch64 (ARM64-v8a), 558 exported functions (.text 0x014a20..0x0447e8)
 * - Upstream Source Paths in .rodata:
 *   - /Users/PBt115_v_jrmq/38753/boringssl/src/ssl/bio_ssl.cc
 *   - /Users/PBt115_v_jrmq/38753/boringssl/src/ssl/d1_both.cc
 *   - /Users/PBt115_v_jrmq/38753/boringssl/src/ssl/d1_pkt.cc
 *   - /Users/PBt115_v_jrmq/38753/boringssl/src/ssl/d1_srtp.cc
 *   - /Users/PBt115_v_jrmq/38753/boringssl/src/ssl/dtls_method.cc
 *   - /Users/PBt115_v_jrmq/38753/boringssl/src/ssl/dtls_record.cc
 *   - /Users/PBt115_v_jrmq/38753/boringssl/src/ssl/encrypted_client_hello.cc
 *   - /Users/PBt115_v_jrmq/38753/boringssl/src/ssl/extensions.cc
 *   - /Users/PBt115_v_jrmq/38753/boringssl/src/ssl/handoff.cc
 *   - /Users/PBt115_v_jrmq/38753/boringssl/src/ssl/handshake.cc
 *   - /Users/PBt115_v_jrmq/38753/boringssl/src/ssl/handshake_server.cc
 *   - /Users/PBt115_v_jrmq/38753/boringssl/src/ssl/ssl_aead_ctx.cc
 *   - /Users/PBt115_v_jrmq/38753/boringssl/src/ssl/ssl_asn1.cc
 *   - /Users/PBt115_v_jrmq/38753/boringssl/src/ssl/ssl_buffer.cc
 *   - /Users/PBt115_v_jrmq/38753/boringssl/src/ssl/ssl_cipher.cc
 *   - /Users/PBt115_v_jrmq/38753/boringssl/src/ssl/ssl_file.cc
 *   - /Users/PBt115_v_jrmq/38753/boringssl/src/ssl/ssl_key_share.cc
 *   - /Users/PBt115_v_jrmq/38753/boringssl/src/ssl/ssl_lib.cc
 *   - /Users/PBt115_v_jrmq/38753/boringssl/src/ssl/ssl_session.cc
 *   - /Users/PBt115_v_jrmq/38753/boringssl/src/ssl/ssl_transcript.cc
 *   - /Users/PBt115_v_jrmq/38753/boringssl/src/ssl/ssl_x509.cc
 *   - /Users/PBt115_v_jrmq/38753/boringssl/src/ssl/t1_enc.cc
 *   - /Users/PBt115_v_jrmq/38753/boringssl/src/ssl/tls_method.cc
 *   - /Users/PBt115_v_jrmq/38753/boringssl/src/ssl/tls_record.cc
 *   - /Users/PBt115_v_jrmq/38753/boringssl/src/ssl/tls13_client.cc
 *   - /Users/PBt115_v_jrmq/38753/boringssl/src/ssl/tls13_enc.cc
 *   - /Users/PBt115_v_jrmq/38753/boringssl/src/ssl/tls13_server.cc
 */

#ifndef NEXTAI_OPENCUT_TTBORINGSSL_TYPES_H
#define NEXTAI_OPENCUT_TTBORINGSSL_TYPES_H

#include <cstddef>
#include <cstdint>
#include <atomic>
#include <vector>
#include <string>
#include <memory>

namespace nextai {
namespace ttboringssl {

// ============================================================================
// 1. TLS / DTLS Protocol Version Constants
//    Hằng số phiên bản giao thức TLS / DTLS
// ============================================================================
constexpr uint16_t SSL3_VERSION    = 0x0300;
constexpr uint16_t TLS1_VERSION    = 0x0301;
constexpr uint16_t TLS1_1_VERSION  = 0x0302;
constexpr uint16_t TLS1_2_VERSION  = 0x0303; // Checked at 0x03226c: cmp w0, #0x303
constexpr uint16_t TLS1_3_VERSION  = 0x0304;
constexpr uint16_t DTLS1_VERSION   = 0xfeff;
constexpr uint16_t DTLS1_2_VERSION = 0xfefd;

// ============================================================================
// 2. SSL Error Codes (SSL_get_error @ 0x0337e4)
//    Mã lỗi SSL (Đối chiếu hàm SSL_get_error tại 0x0337e4 và chuỗi .rodata)
// ============================================================================
enum SslErrorCode : int32_t {
    SSL_ERROR_NONE                         = 0,
    SSL_ERROR_SSL                          = 1,
    SSL_ERROR_WANT_READ                    = 2,
    SSL_ERROR_WANT_WRITE                   = 3,
    SSL_ERROR_WANT_X509_LOOKUP             = 4,
    SSL_ERROR_SYSCALL                      = 5,
    SSL_ERROR_ZERO_RETURN                  = 6,
    SSL_ERROR_WANT_CONNECT                 = 7,
    SSL_ERROR_WANT_ACCEPT                  = 8,
    SSL_ERROR_WANT_CHANNEL_ID_LOOKUP       = 9,
    SSL_ERROR_PENDING_SESSION              = 11,
    SSL_ERROR_PENDING_CERTIFICATE          = 12,
    SSL_ERROR_WANT_PRIVATE_KEY_OPERATION   = 13,
    SSL_ERROR_PENDING_TICKET               = 14,
    SSL_ERROR_EARLY_DATA_REJECTED          = 15,
    SSL_ERROR_WANT_CERTIFICATE_VERIFY      = 16,
    SSL_ERROR_HANDOFF                      = 17,
    SSL_ERROR_HANDBACK                     = 18,
    SSL_ERROR_WANT_RENEGOTIATE             = 19,
    SSL_ERROR_HANDSHAKE_HINTS_READY        = 20
};

// ============================================================================
// 3. QUIC Encryption Levels (SSL_quic_read_level @ 0x032d00)
//    Cấp độ mã hóa QUIC (Đối chiếu hàm SSL_quic_read_level tại 0x032d00)
// ============================================================================
enum ssl_encryption_level_t : int32_t {
    ssl_encryption_initial     = 0,
    ssl_encryption_early_data  = 1,
    ssl_encryption_handshake   = 2,
    ssl_encryption_application = 3
};

// ============================================================================
// 4. Early Data Reason Codes (.rodata strings at 0x045100)
//    Mã lý do dữ liệu sớm 0-RTT (Đối chiếu chuỗi .rodata tại 0x045100)
// ============================================================================
enum ssl_early_data_reason_t : int32_t {
    ssl_early_data_unknown                  = 0,
    ssl_early_data_disabled                 = 1,
    ssl_early_data_accepted                 = 2,
    ssl_early_data_protocol_version         = 3,
    ssl_early_data_peer_declined            = 4,
    ssl_early_data_no_session_offered       = 5,
    ssl_early_data_session_not_resumed      = 6,
    ssl_early_data_unsupported_for_session  = 7,
    ssl_early_data_hello_retry_request      = 8,
    ssl_early_data_alpn_mismatch            = 9,
    ssl_early_data_channel_id               = 10,
    ssl_early_data_token_binding            = 11,
    ssl_early_data_ticket_age_skew          = 12,
    ssl_early_data_quic_parameter_mismatch  = 13,
    ssl_early_data_alps_mismatch            = 14
};

// ============================================================================
// 5. BoringSSL NID Constants (SSL_CIPHER_get_cipher_nid @ 0x02fb7c)
//    Hằng số NID thuật toán mật mã (Khớp lệnh mov w0, #... tại 0x02fba8..0x02fbe0)
// ============================================================================
constexpr int32_t NID_undef                   = 0;
constexpr int32_t NID_des_ede3_cbc            = 0x02c; // 44  @ 0x02fba8: mov w0, #0x2c
constexpr int32_t NID_sha1                    = 0x040; // 64  @ 0x02fbf4: lsl w9, w9, #6
constexpr int32_t NID_aes_128_cbc             = 0x1a3; // 419 @ 0x02fbc8: mov w0, #0x1a3
constexpr int32_t NID_aes_256_cbc             = 0x1ab; // 427 @ 0x02fbd0: mov w0, #0x1ab
constexpr int32_t NID_aes_128_gcm             = 0x37f; // 895 @ 0x02fbd8: mov w0, #0x37f
constexpr int32_t NID_aes_256_gcm             = 0x385; // 901 @ 0x02fbe0: mov w0, #0x385
constexpr int32_t NID_chacha20_poly1305       = 0x3b6; // 950 @ 0x02fbc0: mov w0, #0x3b6
constexpr int32_t NID_kx_rsa                  = 1037;
constexpr int32_t NID_kx_ecdhe                = 1038;
constexpr int32_t NID_kx_psk                  = 1039;
constexpr int32_t NID_kx_ecdhe_psk            = 1040;
constexpr int32_t NID_kx_any                  = 1043;
constexpr int32_t NID_auth_rsa                = 1046;
constexpr int32_t NID_auth_ecdsa              = 1047;
constexpr int32_t NID_auth_psk                = 1048;
constexpr int32_t NID_auth_any                = 1050;
constexpr int32_t NID_md5_sha1                = 114;
constexpr int32_t NID_sha256                  = 672;
constexpr int32_t NID_sha384                  = 673;

// Cipher bitmasks stored in SSL_CIPHER
// Mặt nạ bit thuật toán lưu trong SSL_CIPHER
constexpr uint32_t SSL_kRSA                   = 0x00000001u;
constexpr uint32_t SSL_kECDHE                 = 0x00000002u;
constexpr uint32_t SSL_kPSK                   = 0x00000004u;
constexpr uint32_t SSL_kGENERIC               = 0x00000008u;

constexpr uint32_t SSL_aRSA                   = 0x00000001u;
constexpr uint32_t SSL_aECDSA                 = 0x00000002u;
constexpr uint32_t SSL_aPSK                   = 0x00000004u;
constexpr uint32_t SSL_aGENERIC               = 0x00000008u;

constexpr uint32_t SSL_3DES                   = 0x00000001u;
constexpr uint32_t SSL_AES128                 = 0x00000002u;
constexpr uint32_t SSL_AES256                 = 0x00000004u;
constexpr uint32_t SSL_AES128GCM              = 0x00000008u;
constexpr uint32_t SSL_AES256GCM              = 0x00000010u;
constexpr uint32_t SSL_eNULL                  = 0x00000020u;
constexpr uint32_t SSL_CHACHA20POLY1305       = 0x00000040u;

constexpr uint32_t SSL_SHA1                   = 0x00000001u;
constexpr uint32_t SSL_AEAD                   = 0x00000002u; // Bit 1 checked at 0x02fb70: ubfx w0, w8, #1, #1

constexpr uint32_t SSL_HANDSHAKE_MAC_DEFAULT  = 0x00000001u;
constexpr uint32_t SSL_HANDSHAKE_MAC_SHA256   = 0x00000002u;
constexpr uint32_t SSL_HANDSHAKE_MAC_SHA384   = 0x00000004u;

// ============================================================================
// 6. SSL_CIPHER ABI Structure (Matched to 0x02fb64..0x02fc44)
//    Cấu trúc ABI của SSL_CIPHER (Khớp địa chỉ 0x02fb64..0x02fc44)
// ============================================================================
struct SSL_CIPHER {
    const char* name;            // +0x00: OpenSSL name (e.g., "ECDHE-RSA-AES128-GCM-SHA256")
    const char* standard_name;   // +0x08: IETF RFC name (e.g., "TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256")
    uint32_t    id;              // +0x10: 0x03000000 | uint16_t(protocol_id)
    uint32_t    algorithm_mkey;  // +0x14: Key exchange mask (SSL_kECDHE, SSL_kRSA, ...)
    uint32_t    algorithm_auth;  // +0x18: Auth mask (SSL_aECDSA, SSL_aRSA, ...)
    uint32_t    algorithm_enc;   // +0x1c: Bulk cipher mask (ldr w8, [x0, #0x1c] @ 0x02fb7c)
    uint32_t    algorithm_mac;   // +0x20: MAC / AEAD mask (ldr w8, [x0, #0x20] @ 0x02fb70 & 0x02fbe8)
    uint32_t    algorithm_prf;   // +0x24: PRF digest mask (SSL_HANDSHAKE_MAC_SHA256, ...)
};

static_assert(offsetof(SSL_CIPHER, algorithm_enc) == 0x1c, "SSL_CIPHER::algorithm_enc must be at +0x1c");
static_assert(offsetof(SSL_CIPHER, algorithm_mac) == 0x20, "SSL_CIPHER::algorithm_mac must be at +0x20");

// ============================================================================
// 7. SRTP Protection Profile Structure (d1_srtp.cc @ 0x016a28..0x016c1c)
//    Cấu trúc cấu hình bảo vệ SRTP (Đối chiếu d1_srtp.cc tại 0x016a28..0x016c1c)
// ============================================================================
struct SRTP_PROTECTION_PROFILE {
    const char* name;
    uint16_t    id;
};

constexpr uint16_t SRTP_AES128_CM_SHA1_80 = 0x0001;
constexpr uint16_t SRTP_AES128_CM_SHA1_32 = 0x0002;
constexpr uint16_t SRTP_AEAD_AES_128_GCM  = 0x0007;
constexpr uint16_t SRTP_AEAD_AES_256_GCM  = 0x0008;

// ============================================================================
// 8. BIO Abstraction for TLS Record & Socket I/O (bio_ssl.cc @ 0x014a5c)
//    Lớp trừu tượng BIO cho luồng bản ghi TLS và Socket (bio_ssl.cc tại 0x014a5c)
// ============================================================================
struct ssl_st;

struct BIO_METHOD {
    int32_t     type;
    const char* name;
};

struct BIO {
    const BIO_METHOD*    method         = nullptr;
    std::atomic<int32_t> references{1};
    int32_t              fd             = -1;
    int32_t              close_flag     = 0;
    bool                 should_read    = false;
    bool                 should_write   = false;
    ssl_st*               attached_ssl   = nullptr;
    std::vector<uint8_t> rx_buffer;
    size_t               rx_read_offset = 0;
    std::vector<uint8_t> tx_buffer;
    BIO*                 pair_peer      = nullptr;
};

// ============================================================================
// 9. SSL_SESSION ABI Layout (ssl_session.cc & ssl_asn1.cc @ 0x02afb8..0x02c3c0)
//    Bố cục ABI của SSL_SESSION (Khớp lệnh ldrb w8, [x0, #0x1b0] tại 0x02c1f0)
// ============================================================================
struct alignas(8) SSL_SESSION {
    std::atomic<uint32_t> references{1};               // +0x00
    uint16_t              ssl_version = TLS1_3_VERSION;// +0x04
    uint16_t              master_key_length = 0;       // +0x06
    uint8_t               master_key[48]{};            // +0x08..0x37
    uint8_t               session_id[32]{};            // +0x38..0x57
    uint8_t               session_id_length = 0;       // +0x58
    uint8_t               sid_ctx[32]{};               // +0x59..0x78
    uint8_t               sid_ctx_length = 0;          // +0x79
    uint8_t               peer_sha256[32]{};           // +0x7a..0x99
    uint8_t               padding_align_0[6]{};        // +0x9a..0x9f
    const SSL_CIPHER*     cipher = nullptr;            // +0xa0
    uint64_t              time = 0;                    // +0xa8
    uint32_t              timeout = 7200;              // +0xb0
    uint32_t              auth_timeout = 7200;         // +0xb4
    uint32_t              ticket_lifetime_hint = 0;    // +0xb8
    uint32_t              ticket_age_add = 0;          // +0xbc
    uint32_t              ticket_max_early_data = 0;   // +0xc0
    uint32_t              verify_result = 0;           // +0xc4
    uint8_t               reserved_block[0xe8]{};      // +0xc8..0x1af
    // +0x1b0: Bitfield flags byte!
    // At 0x02c1f0 (SSL_SESSION_to_bytes): ldrb w8, [x0, #0x1b0]; tbnz w8, #2, #0x2c230
    // Bit 0 (0x01): is_server
    // Bit 1 (0x02): extended_master_secret
    // Bit 2 (0x04): not_resumable (when set, returns 14-byte "NOT RESUMABLE" sentinel!)
    // Bit 3 (0x08): ticket_age_add_valid
    // Bit 4 (0x10): peer_sha256_valid
    uint8_t               flags_1b0 = 0;               // +0x1b0
    uint8_t               padding_1b1[7]{};            // +0x1b1..0x1b7
    std::vector<uint8_t>  ticket;                      // Session ticket bytes
    std::vector<uint8_t>  ocsp_response;               // Stapled OCSP response
    std::vector<uint8_t>  signed_cert_timestamp_list;  // CT SCT list
    std::vector<uint8_t>  early_alpn;                  // Early data ALPN protocol
    std::vector<uint8_t>  quic_early_data_context;     // QUIC 0-RTT context
    std::string           psk_identity;                // PSK identity
};

static_assert(offsetof(SSL_SESSION, flags_1b0) == 0x1b0, "SSL_SESSION::flags_1b0 must be at +0x1b0");

// ============================================================================
// 10. SSL_QUIC_METHOD Callback Vtable (SSL_set_quic_method @ 0x0350f0)
//     Bảng hàm gọi lại QUIC (Đối chiếu hàm SSL_set_quic_method tại 0x0350f0)
// ============================================================================
struct SSL_QUIC_METHOD {
    int (*set_read_secret)(ssl_st* ssl, ssl_encryption_level_t level,
                           const SSL_CIPHER* cipher, const uint8_t* secret, size_t secret_len);
    int (*set_write_secret)(ssl_st* ssl, ssl_encryption_level_t level,
                            const SSL_CIPHER* cipher, const uint8_t* secret, size_t secret_len);
    int (*add_handshake_data)(ssl_st* ssl, ssl_encryption_level_t level,
                              const uint8_t* data, size_t len);
    int (*flush_flight)(ssl_st* ssl);
    int (*send_alert)(ssl_st* ssl, ssl_encryption_level_t level, uint8_t alert);
};

// ============================================================================
// 11. DTLS1_STATE ABI Structure (d1 at ssl + 0x38, 0x0162d4..0x016504)
//     Cấu trúc trạng thái DTLS1_STATE (Khớp offset +0x1f8, +0x200, +0x208)
// ============================================================================
struct alignas(8) DTLS1_STATE {
    uint8_t  reserved_header[0x1f8]{};      // +0x000..0x1f7: DTLS cookie, epoch, seq, flight buffers
    uint64_t next_timeout_tv_sec  = 0;      // +0x1f8: ldr x9, [x8, #0x1f8] @ 0x016308
    uint32_t next_timeout_tv_usec = 0;      // +0x200: ldr w8, [x8, #0x200] @ 0x016310
    uint32_t num_timeouts         = 0;      // +0x204: Retransmission timeout count
    uint32_t timeout_duration_ms  = 1000;   // +0x208: ldr w9, [x8, #0x208] @ 0x016544 (capped at 60000 ms = 0xea60)
    bool     timer_running        = false;
    uint16_t read_epoch           = 0;
    uint16_t write_epoch          = 0;
    uint16_t handshake_write_seq  = 0;
    uint16_t handshake_read_seq   = 0;
};

static_assert(offsetof(DTLS1_STATE, next_timeout_tv_sec) == 0x1f8, "DTLS1_STATE::next_timeout_tv_sec must be at +0x1f8");
static_assert(offsetof(DTLS1_STATE, next_timeout_tv_usec) == 0x200, "DTLS1_STATE::next_timeout_tv_usec must be at +0x200");
static_assert(offsetof(DTLS1_STATE, timeout_duration_ms) == 0x208, "DTLS1_STATE::timeout_duration_ms must be at +0x208");

// ============================================================================
// 12. Handshake State & Transcript Structures (handshake.cc & tls13_*.cc)
//     Cấu trúc trạng thái bắt tay và bản ghi Transcript TLS 1.2 / 1.3
// ============================================================================
enum TlsClientHsState : int32_t {
    TLS_ST_CLIENT_START_CONNECT                     = 0,
    TLS_ST_CLIENT_ENTER_EARLY_DATA                  = 1,
    TLS_ST_CLIENT_READ_HELLO_VERIFY_REQUEST         = 2,
    TLS_ST_CLIENT_READ_SERVER_HELLO                 = 3,
    TLS_ST_CLIENT_READ_SERVER_CERTIFICATE           = 4,
    TLS_ST_CLIENT_READ_CERTIFICATE_STATUS           = 5,
    TLS_ST_CLIENT_VERIFY_SERVER_CERTIFICATE         = 6,
    TLS_ST_CLIENT_READ_SERVER_KEY_EXCHANGE          = 7,
    TLS_ST_CLIENT_READ_CERTIFICATE_REQUEST          = 8,
    TLS_ST_CLIENT_READ_SERVER_HELLO_DONE            = 9,
    TLS_ST_CLIENT_SEND_CLIENT_CERTIFICATE           = 10,
    TLS_ST_CLIENT_SEND_CLIENT_KEY_EXCHANGE          = 11,
    TLS_ST_CLIENT_SEND_CLIENT_CERTIFICATE_VERIFY    = 12,
    TLS_ST_CLIENT_SEND_CLIENT_FINISHED              = 13,
    TLS_ST_CLIENT_FINISH_FLIGHT                     = 14,
    TLS_ST_CLIENT_READ_SESSION_TICKET               = 15,
    TLS_ST_CLIENT_PROCESS_CHANGE_CIPHER_SPEC        = 16,
    TLS_ST_CLIENT_READ_SERVER_FINISHED              = 17,
    TLS_ST_CLIENT_FINISH_CLIENT_HANDSHAKE           = 18,
    TLS_ST_CLIENT_DONE                              = 19,
    // TLS 1.3 Client States (tls13_client.cc)
    TLS13_ST_CLIENT_SEND_SECOND_CLIENT_HELLO        = 20,
    TLS13_ST_CLIENT_READ_SERVER_HELLO               = 21,
    TLS13_ST_CLIENT_READ_ENCRYPTED_EXTENSIONS       = 22,
    TLS13_ST_CLIENT_READ_CERTIFICATE_REQUEST        = 23,
    TLS13_ST_CLIENT_READ_SERVER_CERTIFICATE         = 24,
    TLS13_ST_CLIENT_READ_SERVER_CERTIFICATE_VERIFY  = 25,
    TLS13_ST_CLIENT_SERVER_CERTIFICATE_REVERIFY     = 26,
    TLS13_ST_CLIENT_READ_SERVER_FINISHED            = 27,
    TLS13_ST_CLIENT_SEND_END_OF_EARLY_DATA          = 28,
    TLS13_ST_CLIENT_SEND_CLIENT_ENCRYPTED_EXTS      = 29,
    TLS13_ST_CLIENT_SEND_CLIENT_CERTIFICATE         = 30,
    TLS13_ST_CLIENT_SEND_CLIENT_CERTIFICATE_VERIFY  = 31,
    TLS13_ST_CLIENT_COMPLETE_SECOND_FLIGHT          = 32,
    TLS13_ST_CLIENT_DONE                            = 33
};

enum TlsServerHsState : int32_t {
    TLS_ST_SERVER_READ_CLIENT_HELLO                 = 0,
    TLS_ST_SERVER_READ_CLIENT_HELLO_AFTER_ECH       = 1,
    TLS_ST_SERVER_SELECT_CERTIFICATE                = 2,
    TLS_ST_SERVER_SELECT_PARAMETERS                 = 3,
    TLS_ST_SERVER_SEND_SERVER_HELLO                 = 4,
    TLS_ST_SERVER_SEND_SERVER_CERTIFICATE           = 5,
    TLS_ST_SERVER_SEND_SERVER_KEY_EXCHANGE          = 6,
    TLS_ST_SERVER_SEND_SERVER_HELLO_DONE            = 7,
    TLS_ST_SERVER_READ_CLIENT_CERTIFICATE           = 8,
    TLS_ST_SERVER_VERIFY_CLIENT_CERTIFICATE         = 9,
    TLS_ST_SERVER_READ_CLIENT_KEY_EXCHANGE          = 10,
    TLS_ST_SERVER_READ_CLIENT_CERTIFICATE_VERIFY    = 11,
    TLS_ST_SERVER_READ_CHANGE_CIPHER_SPEC           = 12,
    TLS_ST_SERVER_PROCESS_CHANGE_CIPHER_SPEC        = 13,
    TLS_ST_SERVER_READ_NEXT_PROTO                   = 14,
    TLS_ST_SERVER_READ_CHANNEL_ID                   = 15,
    TLS_ST_SERVER_READ_CLIENT_FINISHED              = 16,
    TLS_ST_SERVER_SEND_SERVER_FINISHED              = 17,
    TLS_ST_SERVER_FINISH_SERVER_HANDSHAKE           = 18,
    TLS_ST_SERVER_DONE                              = 19,
    // TLS 1.3 Server States (tls13_server.cc)
    TLS13_ST_SERVER_SELECT_SESSION                  = 20,
    TLS13_ST_SERVER_SEND_HELLO_RETRY_REQUEST        = 21,
    TLS13_ST_SERVER_READ_SECOND_CLIENT_HELLO        = 22,
    TLS13_ST_SERVER_SEND_SERVER_HELLO               = 23,
    TLS13_ST_SERVER_SEND_SERVER_CERTIFICATE_VERIFY  = 24,
    TLS13_ST_SERVER_SEND_HALF_RTT_TICKET            = 25,
    TLS13_ST_SERVER_SEND_SERVER_FINISHED            = 26,
    TLS13_ST_SERVER_READ_SECOND_CLIENT_FLIGHT       = 27,
    TLS13_ST_SERVER_PROCESS_END_OF_EARLY_DATA       = 28,
    TLS13_ST_SERVER_READ_CLIENT_ENCRYPTED_EXTS      = 29,
    TLS13_ST_SERVER_READ_CLIENT_CERTIFICATE         = 30,
    TLS13_ST_SERVER_READ_CLIENT_CERTIFICATE_VERIFY  = 31,
    TLS13_ST_SERVER_READ_CHANNEL_ID                 = 32,
    TLS13_ST_SERVER_READ_CLIENT_FINISHED            = 33,
    TLS13_ST_SERVER_SEND_NEW_SESSION_TICKET         = 34,
    TLS13_ST_SERVER_DONE                            = 35
};

struct SSL_HANDSHAKE {
    ssl_st*               ssl = nullptr;
    int32_t               state = 0;
    int32_t               tls13_state = 0;
    uint16_t              min_version = TLS1_2_VERSION;
    uint16_t              max_version = TLS1_3_VERSION;
    const SSL_CIPHER*     new_cipher = nullptr;
    std::unique_ptr<SSL_SESSION> new_session;
    uint8_t               secret[48]{};
    uint8_t               early_traffic_secret[48]{};
    uint8_t               client_handshake_secret[48]{};
    uint8_t               server_handshake_secret[48]{};
    uint8_t               client_traffic_secret_0[48]{};
    uint8_t               server_traffic_secret_0[48]{};
    uint8_t               expected_client_finished[48]{};
    size_t                hash_len = 32;
    uint8_t               x25519_private_key[32]{};
    uint8_t               x25519_public_key[32]{};
    uint8_t               peer_x25519_public_key[32]{};
    std::vector<uint8_t>  transcript_bytes;
    bool                  in_early_data = false;
    bool                  early_data_offered = false;
    bool                  ech_authenticated = false;
    bool                  handoff_requested = false;
};

// ============================================================================
// 13. bssl::SSL3_STATE ABI Structure (s3 at ssl + 0x30)
//     Cấu trúc trạng thái SSL3_STATE (Khớp chính xác các offset trong .text)
// ============================================================================
struct alignas(8) SSL3_STATE {
    uint8_t              read_sequence[8]{};            // +0x000
    uint8_t              write_sequence[8]{};           // +0x008
    uint8_t              server_random[32]{};           // +0x010
    uint8_t              client_random[32]{};           // +0x030
    uint8_t              read_buffer_storage[0x30]{};   // +0x050: add x0, x8, #0x50 @ 0x0330f4
    const uint8_t*       pending_app_data_ptr = nullptr;// +0x080: stp x0, x1, [x8, #0x80] @ 0x0330e4
    size_t               pending_app_data_len = 0;      // +0x088: ldr x9, [x8, #0x88] @ 0x0330ec
    uint8_t              reserved_090[0x1c]{};          // +0x090..0x0ab
    int32_t              write_shutdown = 0;            // +0x0ac: ldr w9, [x8, #0xac] @ 0x033550
    int32_t              read_shutdown  = 0;            // +0x0b0: ldr w9, [x8, #0xb0] @ 0x03353c
    uint32_t             pad_0b4        = 0;            // +0x0b4
    void*                aead_write_ctx = nullptr;      // +0x0b8: ldr x0, [x8, #0xb8] @ 0x033570
    uint32_t             pad_0c0        = 0;            // +0x0c0
    int32_t              rwstate        = SSL_ERROR_NONE;// +0x0c4: ldr w0, [x8, #0xc4] @ 0x033828
    ssl_encryption_level_t quic_read_level  = ssl_encryption_initial; // +0x0c8: ldr w0, [x8, #0xc8] @ 0x032d04
    ssl_encryption_level_t quic_write_level = ssl_encryption_initial; // +0x0cc: ldr w0, [x8, #0xcc] @ 0x032d10
    ssl_early_data_reason_t early_data_reason = ssl_early_data_unknown; // +0x0d0
    uint32_t             pad_0d4        = 0;            // +0x0d4
    int32_t              ech_status     = 0;            // +0x0d8: ldr w8, [x8, #0xd8] @ 0x019460 (1 = accepted)
    // +0x0dc: Flags byte! Bit 5 (0x20) = initial_handshake_complete (checked at 0x032284: ldrb w9, [x8, #0xdc]; tbnz w9, #5)
    uint8_t              flags_dc       = 0;            // +0x0dc
    uint8_t              flags_dd       = 0;            // +0x0dd: Bit 4 = alert_dispatch (checked at 0x033548)
    uint8_t              pad_0de[2]{};                  // +0x0de..0x0df
    size_t*              quic_handshake_buf_len_ptr = nullptr; // +0x0e0: ldr x8, [x8, #0xe0] @ 0x032d44
    uint8_t              reserved_0e8[0x30]{};          // +0x0e8..0x117
    SSL_HANDSHAKE*       hs             = nullptr;      // +0x118: ldr x0, [x8, #0x118] @ 0x032e00
    uint8_t              write_traffic_secret[48]{};    // +0x120: add x8, x8, #0x120 @ 0x0322b8
    uint8_t              read_traffic_secret[48]{};     // +0x150: add x8, x8, #0x150 @ 0x0322a4
    uint8_t              exporter_secret[48]{};         // +0x180..0x1af
    uint8_t              write_traffic_secret_len = 0;  // +0x1b0: ldrb w9, [x8, #0x1b0] @ 0x0322b4
    uint8_t              read_traffic_secret_len  = 0;  // +0x1b1: ldrb w9, [x8, #0x1b1] @ 0x0322a0
    uint8_t              exporter_secret_len      = 0;  // +0x1b2
    uint8_t              previous_client_finished[48]{};// +0x1b3..0x1e2
    uint8_t              previous_client_finished_len = 0; // +0x1e3
    uint8_t              previous_server_finished[48]{};
    uint8_t              previous_server_finished_len = 0;
    const uint8_t*       alpn_selected_ptr = nullptr;   // +0x1e8 (logical): ldr x8, [x8, #0x1e8] @ 0x034978
    size_t               alpn_selected_len = 0;         // +0x1f0 (logical): add x8, x8, #0x1f0 @ 0x034984
    const char*          hostname_ptr      = nullptr;   // +0x1f8 (logical): ldr x0, [x8, #0x1f8] @ 0x0345a4
    const uint8_t*       peer_quic_params_ptr = nullptr;// +0x240 (logical): ldr x8, [x8, #0x240] @ 0x0336c4
    size_t               peer_quic_params_len = 0;      // +0x248 (logical): ldr x8, [x8, #0x248] @ 0x0336d0

    // Backing containers for variable buffers
    std::vector<uint8_t> alpn_selected_vec;
    std::vector<uint8_t> peer_quic_params_vec;
    std::vector<uint8_t> quic_input_buffer[4];
    std::vector<uint8_t> app_read_storage;
    std::unique_ptr<SSL_HANDSHAKE> hs_owned;
    uint16_t             established_version = 0;
    const SSL_CIPHER*    established_cipher  = nullptr;
    bool                 extms_neg           = true;
    bool                 secure_renegotiation = true;
};

static_assert(offsetof(SSL3_STATE, pending_app_data_ptr) == 0x80, "SSL3_STATE::pending_app_data_ptr must be at +0x80");
static_assert(offsetof(SSL3_STATE, write_shutdown) == 0xac, "SSL3_STATE::write_shutdown must be at +0xac");
static_assert(offsetof(SSL3_STATE, read_shutdown) == 0xb0, "SSL3_STATE::read_shutdown must be at +0xb0");
static_assert(offsetof(SSL3_STATE, rwstate) == 0xc4, "SSL3_STATE::rwstate must be at +0xc4");
static_assert(offsetof(SSL3_STATE, quic_read_level) == 0xc8, "SSL3_STATE::quic_read_level must be at +0xc8");
static_assert(offsetof(SSL3_STATE, quic_write_level) == 0xcc, "SSL3_STATE::quic_write_level must be at +0xcc");
static_assert(offsetof(SSL3_STATE, ech_status) == 0xd8, "SSL3_STATE::ech_status must be at +0xd8");
static_assert(offsetof(SSL3_STATE, flags_dc) == 0xdc, "SSL3_STATE::flags_dc must be at +0xdc");
static_assert(offsetof(SSL3_STATE, hs) == 0x118, "SSL3_STATE::hs must be at +0x118");
static_assert(offsetof(SSL3_STATE, write_traffic_secret) == 0x120, "SSL3_STATE::write_traffic_secret must be at +0x120");
static_assert(offsetof(SSL3_STATE, read_traffic_secret) == 0x150, "SSL3_STATE::read_traffic_secret must be at +0x150");
static_assert(offsetof(SSL3_STATE, write_traffic_secret_len) == 0x1b0, "SSL3_STATE::write_traffic_secret_len must be at +0x1b0");
static_assert(offsetof(SSL3_STATE, read_traffic_secret_len) == 0x1b1, "SSL3_STATE::read_traffic_secret_len must be at +0x1b1");

// ============================================================================
// 14. bssl::SSL_CONFIG ABI Structure (config at ssl + 0x08)
//     Cấu trúc cấu hình kết nối SSL_CONFIG (Khớp offset +0x08, +0x0a, +0x78, +0xa0, +0xe8, +0xe9)
// ============================================================================
struct alignas(8) SSL_CONFIG {
    ssl_st*              ssl = nullptr;                 // +0x00
    uint16_t             conf_min_version = TLS1_2_VERSION; // +0x08: strh w10, [x8, #8] @ 0x0328a0
    uint16_t             conf_max_version = TLS1_3_VERSION; // +0x0a: strh w10, [x8, #0xa] @ 0x032898
    uint32_t             pad_0c = 0;                    // +0x0c
    uint8_t              reserved_10[0x68]{};           // +0x10..0x77
    const uint8_t*       alpn_client_proto_ptr = nullptr; // +0x78: add x0, x8, #0x78 @ 0x034908
    size_t               alpn_client_proto_len = 0;     // +0x80
    uint8_t              reserved_88[0x18]{};           // +0x88..0x9f
    const uint8_t*       quic_transport_params_ptr = nullptr; // +0xa0: add x0, x8, #0xa0 @ 0x0336a4
    size_t               quic_transport_params_len = 0; // +0xa8
    uint8_t              reserved_b0[0x38]{};           // +0xb0..0xe7
    uint8_t              flags_e8 = 0x01;               // +0xe8: bit 0 = jdk11_workaround (checked at 0x032ce0)
    // +0xe9: ECH flags halfword! Checked in SSL_set_enable_ech_grease @ 0x018ca4: ldurh w9, [x8, #0xe9]
    uint16_t             ech_flags_e9 = 0;              // +0xe9..0xea (unaligned halfword supported; we also store cleanly)
    std::vector<uint8_t> alpn_client_proto_vec;
    std::vector<uint8_t> quic_transport_params_vec;
    std::vector<uint8_t> quic_early_data_context_vec;
    std::vector<uint8_t> ech_config_list_vec;
    std::vector<uint8_t> ocsp_response_vec;
    std::vector<uint8_t> sct_list_vec;
    int32_t              verify_mode = 0;
    int (*cert_cb)(ssl_st* s, void* arg) = nullptr;
    void*                cert_cb_arg = nullptr;
};

static_assert(offsetof(SSL_CONFIG, conf_min_version) == 0x08, "SSL_CONFIG::conf_min_version must be at +0x08");
static_assert(offsetof(SSL_CONFIG, conf_max_version) == 0x0a, "SSL_CONFIG::conf_max_version must be at +0x0a");
static_assert(offsetof(SSL_CONFIG, alpn_client_proto_ptr) == 0x78, "SSL_CONFIG::alpn_client_proto_ptr must be at +0x78");
static_assert(offsetof(SSL_CONFIG, quic_transport_params_ptr) == 0xa0, "SSL_CONFIG::quic_transport_params_ptr must be at +0xa0");
static_assert(offsetof(SSL_CONFIG, flags_e8) == 0xe8, "SSL_CONFIG::flags_e8 must be at +0xe8");

// ============================================================================
// 15. Protocol Method Descriptor (tls_method.cc & dtls_method.cc)
//     Cấu trúc mô tả phương thức giao thức TLS / DTLS
// ============================================================================
struct SSL_PROTOCOL_METHOD {
    bool     is_dtls;      // +0x00: Checked at 0x0350f4: ldr x8, [x0]; ldrb w8, [x8]; cbz w8
    uint8_t  pad[7]{};
    uint16_t min_version;
    uint16_t max_version;
};

struct SSL_METHOD {
    uint16_t                   version;
    const SSL_PROTOCOL_METHOD* method;
};

// ============================================================================
// 16. Encrypted Client Hello (ECH) Key Set (encrypted_client_hello.cc @ 0x018fb0)
//     Tập khóa Encrypted Client Hello (ECH) (Đối chiếu tại 0x018fb0..0x019318)
// ============================================================================
struct ECHKeyEntry {
    uint8_t              config_id = 0;
    bool                 is_retry_config = false;
    std::string          public_name;
    std::vector<uint8_t> ech_config_bytes;
    uint8_t              private_key[32]{};
    uint8_t              public_key[32]{};
};

struct SSL_ECH_KEYS {
    std::atomic<int32_t>     references{1};
    std::vector<ECHKeyEntry> entries;
};

// ============================================================================
// 17. ssl_ctx_st (SSL_CTX) ABI Structure (ssl_lib.cc @ 0x03249c)
//     Cấu trúc ngữ cảnh SSL_CTX (Khớp các offset +0x48, +0x4a, +0x50, +0xb0, +0x1d0)
// ============================================================================
typedef int (*SSL_CTX_alpn_select_cb_func)(ssl_st* ssl, const uint8_t** out, uint8_t* outlen,
                                           const uint8_t* in, unsigned int inlen, void* arg);
typedef int (*pem_password_cb)(char* buf, int size, int rwflag, void* userdata);

struct alignas(8) ssl_ctx_st {
    const SSL_PROTOCOL_METHOD* method = nullptr;        // +0x00: ldr x8, [x0]; ldrb w8, [x8] @ 0x0350d8
    uint8_t                    reserved_08[0x40]{};     // +0x08..0x47
    uint16_t                   conf_max_version = TLS1_3_VERSION; // +0x48: ldrh w10, [x9, #0x48] @ 0x03289c
    uint16_t                   conf_min_version = TLS1_2_VERSION; // +0x4a: ldrh w10, [x9, #0x4a] @ 0x032894
    uint32_t                   pad_4c = 0;              // +0x4c
    const SSL_QUIC_METHOD*     quic_method = nullptr;   // +0x50: str x1, [x0, #0x50] @ 0x0350e8
    uint8_t                    reserved_58[0x10]{};     // +0x58..0x67
    void*                      sessions = nullptr;      // +0x68: str x0, [x8, #0x68] @ 0x032510
    uint8_t                    reserved_70[0x40]{};     // +0x70..0xaf
    std::atomic<uint32_t>      references{1};           // +0xb0: add x0, x0, #0xb0 @ 0x032644
    uint32_t                   options = 0;             // +0xb4
    uint32_t                   mode = 0;                // +0xb8
    uint32_t                   max_cert_list = 102400;  // +0xbc (100 KB default)
    uint32_t                   max_send_fragment = 16384;// +0xc0
    int32_t                    read_ahead = 0;          // +0xc4
    bool                       early_data_enabled = false;
    bool                       handoff_mode = false;
    uint8_t                    sid_ctx[32]{};
    uint8_t                    sid_ctx_len = 0;
    size_t                     sess_cache_size = 1024;
    pem_password_cb            default_passwd_callback = nullptr;
    void*                      default_passwd_callback_userdata = nullptr;
    SSL_CTX_alpn_select_cb_func alpn_select_cb = nullptr;
    void*                      alpn_select_cb_arg = nullptr;
    int (*cert_cb)(ssl_st* s, void* arg) = nullptr;
    void*                      cert_cb_arg = nullptr;
    std::vector<const SSL_CIPHER*> cipher_list;
    std::vector<const SRTP_PROTECTION_PROFILE*> srtp_profiles;
    std::vector<uint8_t>       alpn_client_proto_list;
    std::vector<std::vector<uint8_t>> cert_chain_asn1;
    std::vector<uint8_t>       private_key_asn1;
    std::vector<uint8_t>       ocsp_response;
    std::vector<uint8_t>       signed_cert_timestamp_list;
    std::shared_ptr<SSL_ECH_KEYS> ech_keys;
    std::vector<std::shared_ptr<SSL_SESSION>> session_cache;
};

using SSL_CTX = ssl_ctx_st;

static_assert(offsetof(ssl_ctx_st, conf_max_version) == 0x48, "ssl_ctx_st::conf_max_version must be at +0x48");
static_assert(offsetof(ssl_ctx_st, conf_min_version) == 0x4a, "ssl_ctx_st::conf_min_version must be at +0x4a");
static_assert(offsetof(ssl_ctx_st, quic_method) == 0x50, "ssl_ctx_st::quic_method must be at +0x50");
static_assert(offsetof(ssl_ctx_st, references) == 0xb0, "ssl_ctx_st::references must be at +0xb0");

// ============================================================================
// 18. ssl_st (SSL) Connection ABI Structure (ssl_lib.cc @ 0x032828..0x0339ac)
//     Cấu trúc kết nối SSL (Khớp chính xác các offset trong .text)
// ============================================================================
struct alignas(8) ssl_st {
    const SSL_PROTOCOL_METHOD* method = nullptr;        // +0x00: ldr x8, [x0] @ 0x0350f0
    SSL_CONFIG*                config = nullptr;        // +0x08: ldr x8, [x0, #8] @ 0x032888
    uint16_t                   version = TLS1_3_VERSION;// +0x10
    uint16_t                   pad_12 = 0;              // +0x12
    uint32_t                   pad_14 = 0;              // +0x14
    BIO*                       rbio = nullptr;          // +0x18: ldr x0, [x0, #0x18] @ 0x032c88
    BIO*                       wbio = nullptr;          // +0x20: ldr x0, [x0, #0x20] @ 0x032c90
    int (*do_handshake)(SSL_HANDSHAKE* hs) = nullptr;   // +0x28: ldr x8, [x19, #0x28] @ 0x032de8
    SSL3_STATE*                s3 = nullptr;            // +0x30: ldr x8, [x0, #0x30] @ 0x032d00
    DTLS1_STATE*               d1 = nullptr;            // +0x38: ldr x8, [x20, #0x38] @ 0x016304
    SSL_CTX*                   ctx = nullptr;           // +0x40
    uint64_t                   pad_48 = 0;              // +0x48
    uint32_t                   initial_timeout_duration_ms = 1000; // +0x50: str w1, [x0, #0x50] @ 0x0164fc
    uint32_t                   options = 0;             // +0x54
    uint32_t                   mode = 0;                // +0x58
    uint32_t                   max_send_fragment = 16384;// +0x5c
    uint8_t                    reserved_60[0x28]{};     // +0x60..0x87
    uint32_t                   max_cert_list = 102400;  // +0x88: ldr w8, [x0, #0x88] @ 0x032cd0
    uint32_t                   mtu = 1400;              // +0x8c
    const char*                hostname = nullptr;      // +0x90: ldr x0, [x0, #0x90] @ 0x034594
    const SSL_QUIC_METHOD*     quic_method = nullptr;   // +0x98: str x1, [x0, #0x98] @ 0x035100
    std::atomic<uint32_t>      references{1};           // +0xa0
    // +0xa4: Bitfield flags byte!
    // Bit 0 (0x01): server (SSL_set_connect_state @ 0x032bbc clears bit 0; SSL_set_accept_state @ 0x032bd0 sets bit 0)
    // Bit 1 (0x02): quiet_shutdown (SSL_shutdown @ 0x033530 checks bit 1)
    // Bit 2 (0x04): early_data_enabled
    uint8_t                    flags_a4 = 0;            // +0xa4
    uint8_t                    pad_a5[3]{};             // +0xa5..0xa7
    int32_t                    read_ahead = 0;          // +0xa8
    uint32_t                   verify_mode = 0;         // +0xac

    // Backing C++ objects owned by SSL
    std::unique_ptr<SSL_CONFIG>  config_owned;
    std::unique_ptr<SSL3_STATE>  s3_owned;
    std::unique_ptr<DTLS1_STATE> d1_owned;
    std::shared_ptr<SSL_SESSION> session;
    std::string                  hostname_str;
    std::string                  ech_name_override;
    std::vector<uint8_t>         ech_retry_configs;
    std::vector<const SRTP_PROTECTION_PROFILE*> srtp_profiles;
    const SRTP_PROTECTION_PROFILE* selected_srtp_profile = nullptr;
    std::vector<std::vector<uint8_t>> cert_chain_asn1;
    std::vector<std::vector<uint8_t>> peer_cert_chain_asn1;
    std::vector<uint8_t>         private_key_asn1;
    std::vector<uint8_t>         delegated_credential;
    bool                         delegated_credential_used = false;
    bool                         handoff_mode = false;
    uint8_t                      sid_ctx[32]{};
    uint8_t                      sid_ctx_len = 0;
};

using SSL = ssl_st;

static_assert(offsetof(ssl_st, config) == 0x08, "ssl_st::config must be at +0x08");
static_assert(offsetof(ssl_st, rbio) == 0x18, "ssl_st::rbio must be at +0x18");
static_assert(offsetof(ssl_st, wbio) == 0x20, "ssl_st::wbio must be at +0x20");
static_assert(offsetof(ssl_st, do_handshake) == 0x28, "ssl_st::do_handshake must be at +0x28");
static_assert(offsetof(ssl_st, s3) == 0x30, "ssl_st::s3 must be at +0x30");
static_assert(offsetof(ssl_st, d1) == 0x38, "ssl_st::d1 must be at +0x38");
static_assert(offsetof(ssl_st, initial_timeout_duration_ms) == 0x50, "ssl_st::initial_timeout_duration_ms must be at +0x50");
static_assert(offsetof(ssl_st, max_cert_list) == 0x88, "ssl_st::max_cert_list must be at +0x88");
static_assert(offsetof(ssl_st, hostname) == 0x90, "ssl_st::hostname must be at +0x90");
static_assert(offsetof(ssl_st, quic_method) == 0x98, "ssl_st::quic_method must be at +0x98");
static_assert(offsetof(ssl_st, flags_a4) == 0xa4, "ssl_st::flags_a4 must be at +0xa4");

} // namespace ttboringssl
} // namespace nextai

#endif // NEXTAI_OPENCUT_TTBORINGSSL_TYPES_H
