/**
 * @file ttboringssl_quic_dtls_alpn.cpp
 * @brief Cleanroom C++17 Implementation of QUIC Transport, DTLS Timer, SRTP & ALPN/SNI
 *        Triển khai C++17 cho giao vận QUIC, bộ định thời DTLS, cấu hình SRTP và ALPN/SNI
 *
 * Binary Ground Truth / Đối chứng nhị phân:
 * - DTLSv1_get_timeout @ 0x0162d4 (316 B)
 * - DTLSv1_set_initial_timeout_duration @ 0x0164fc (8 B):
 *   0x0164fc: str w1, [x0, #0x50]
 *   0x016500: ret
 * - DTLSv1_handle_timeout @ 0x016504 (164 B):
 *   0x01653c: ldr  x8, [x19, #0x38]
 *   0x016544: ldr  w9, [x8, #0x208]
 *   0x016548: lsl  w10, w9, #1
 *   0x01654c: ubfx w9, w9, #4, #0x1b
 *   0x016550: cmp  w9, #0x753
 *   0x016554: mov  w9, #0xea60
 *   0x016558: csel w9, w10, w9, lo
 *   0x01655c: str  w9, [x8, #0x208]
 * - SSL_quic_max_handshake_flight_len @ 0x032c98 (104 B):
 *   0x032c98: cmp  w1, #3
 *   0x032cb8: mov  w8, #0x4000 ; 16384 B for initial/early_data
 *   0x032cc8: ldrb w8, [x0, #0xa4]
 *   0x032cd0: ldr  w8, [x0, #0x88] ; max_cert_list
 *   0x032cd4: lsl  w8, w8, #1      ; client handshake flight limit = 2 * max_cert_list (or >= 16384)
 * - SSL_quic_read_level @ 0x032d00 (12 B): ldr x8, [x0, #0x30]; ldr w0, [x8, #0xc8]; ret
 * - SSL_quic_write_level @ 0x032d0c (12 B): ldr x8, [x0, #0x30]; ldr w0, [x8, #0xcc]; ret
 * - SSL_provide_quic_data @ 0x032d18 (168 B)
 * - SSL_set_quic_transport_params @ 0x033694 (44 B)
 * - SSL_get_peer_quic_transport_params @ 0x0336c0 (28 B)
 * - SSL_CTX_set_quic_method @ 0x0350d8 (24 B): str x1, [x0, #0x50]
 * - SSL_set_quic_method @ 0x0350f0 (24 B): str x1, [x0, #0x98]
 * - SSL_set_tlsext_host_name @ 0x0346d8 (128 B): sub x8, x0, #1; cmp x8, #0xff
 * - SSL_get_servername @ 0x034588 (36 B)
 * - SSL_CTX_set_alpn_protos @ 0x034880, SSL_set_alpn_protos @ 0x0348d4
 * - SSL_get0_alpn_selected @ 0x03493c (88 B)
 */

#include "ttboringssl_quic_dtls_alpn.h"
#include <cstring>
#include <algorithm>

namespace nextai {
namespace ttboringssl {

namespace {

// Static Protocol Method Tables (tls_method.cc & dtls_method.cc @ 0x016c58..0x016c84)
// Bảng tĩnh phương thức giao thức TLS và DTLS (Khớp địa chỉ 0x016c58..0x016c84)
static const SSL_PROTOCOL_METHOD kTlsProtocolMethod  = {false, {}, TLS1_VERSION, TLS1_3_VERSION};
static const SSL_PROTOCOL_METHOD kDtlsProtocolMethod = {true,  {}, DTLS1_VERSION, DTLS1_2_VERSION};

static const SSL_METHOD kTlsMethod       = {0,              &kTlsProtocolMethod};
static const SSL_METHOD kDtlsMethod      = {0,              &kDtlsProtocolMethod};
static const SSL_METHOD kDtls12Method    = {DTLS1_2_VERSION, &kDtlsProtocolMethod};
static const SSL_METHOD kDtls10Method    = {DTLS1_VERSION,   &kDtlsProtocolMethod};

// Static SRTP Profiles Table (d1_srtp.cc @ .rodata 0x0448a0)
// Bảng cấu hình SRTP chuẩn (.rodata d1_srtp.cc)
static const SRTP_PROTECTION_PROFILE kSrtpProfiles[] = {
    {"SRTP_AES128_CM_SHA1_80", SRTP_AES128_CM_SHA1_80},
    {"SRTP_AES128_CM_SHA1_32", SRTP_AES128_CM_SHA1_32},
    {"SRTP_AEAD_AES_128_GCM",  SRTP_AEAD_AES_128_GCM},
    {"SRTP_AEAD_AES_256_GCM",  SRTP_AEAD_AES_256_GCM}
};

// Validate wire-format ALPN protocol list (non-empty 8-bit length-prefixed strings)
// Kiểm tra định dạng danh sách giao thức ALPN (chuỗi có độ dài 1 byte đứng trước, không rỗng)
bool ssl_is_valid_alpn_list(const uint8_t* protos, unsigned int protos_len) {
    if (!protos || protos_len == 0) {
        return false;
    }
    unsigned int idx = 0;
    while (idx < protos_len) {
        uint8_t plen = protos[idx++];
        if (plen == 0 || idx + plen > protos_len) {
            return false;
        }
        idx += plen;
    }
    return idx == protos_len;
}

bool parse_srtp_profile_string(const char* profiles,
                               std::vector<const SRTP_PROTECTION_PROFILE*>* out_list) {
    if (!profiles || !out_list) {
        return false;
    }
    out_list->clear();
    std::string s(profiles);
    size_t pos = 0;
    while (pos <= s.size()) {
        size_t next = s.find(':', pos);
        std::string token = (next == std::string::npos) ? s.substr(pos) : s.substr(pos, next - pos);
        if (!token.empty()) {
            const SRTP_PROTECTION_PROFILE* found = nullptr;
            for (const auto& p : kSrtpProfiles) {
                if (token == p.name) {
                    found = &p;
                    break;
                }
            }
            if (!found) {
                return false;
            }
            out_list->push_back(found);
        }
        if (next == std::string::npos) {
            break;
        }
        pos = next + 1;
    }
    return !out_list->empty();
}

} // namespace

// ============================================================================
// 1. DTLS Timer & SRTP Profile Implementation (0x0162d4..0x016c84)
//    Thực thi bộ định thời DTLS và cấu hình SRTP (0x0162d4..0x016c84)
// ============================================================================
int DTLSv1_get_timeout(const SSL* ssl, DtlsTimeval* out) {
    // Disassembly @ 0x0162d4:
    //   0x0162fc: bl  #0x132f0 (SSL_is_dtls)
    //   0x016300: cbz w0, #0x163e0
    //   0x016304: ldr x8, [x20, #0x38] ; d1 = ssl->d1
    //   0x016308: ldr x9, [x8, #0x1f8] ; next_timeout_tv_sec
    //   0x016310: ldr w8, [x8, #0x200] ; next_timeout_tv_usec
    if (!ssl || !ssl->method || !ssl->method->is_dtls || !ssl->d1 || !out) {
        return 0;
    }
    const DTLS1_STATE* d1 = ssl->d1;
    if (d1->next_timeout_tv_sec == 0 && d1->next_timeout_tv_usec == 0) {
        return 0;
    }
    out->tv_sec  = d1->next_timeout_tv_sec;
    out->tv_usec = d1->next_timeout_tv_usec;
    return 1;
}

void DTLSv1_set_initial_timeout_duration(SSL* ssl, uint32_t duration_ms) {
    // Disassembly @ 0x0164fc:
    //   0x0164fc: str w1, [x0, #0x50]
    //   0x016500: ret
    if (!ssl) {
        return;
    }
    ssl->initial_timeout_duration_ms = duration_ms;
    if (ssl->d1) {
        ssl->d1->timeout_duration_ms = duration_ms;
    }
}

int DTLSv1_handle_timeout(SSL* ssl) {
    // Disassembly @ 0x016504 (164 B):
    //   0x01653c: ldr  x8, [x19, #0x38]      ; d1 = ssl->d1
    //   0x016544: ldr  w9, [x8, #0x208]      ; w9 = d1->timeout_duration_ms
    //   0x016548: lsl  w10, w9, #1           ; w10 = w9 * 2
    //   0x01654c: ubfx w9, w9, #4, #0x1b     ; w9 = w9 >> 4
    //   0x016550: cmp  w9, #0x753            ; compare with 1875 (1875 * 16 = 30000 ms)
    //   0x016554: mov  w9, #0xea60           ; 60000 ms cap
    //   0x016558: csel w9, w10, w9, lo       ; min(w9 * 2, 60000)
    //   0x01655c: str  w9, [x8, #0x208]      ; d1->timeout_duration_ms = w9
    if (!ssl || !ssl->method || !ssl->method->is_dtls || !ssl->d1) {
        return -1;
    }
    DTLS1_STATE* d1 = ssl->d1;
    if (!d1->timer_running && d1->next_timeout_tv_sec == 0 && d1->next_timeout_tv_usec == 0) {
        return 0; // No timeout active
    }
    uint32_t w9  = d1->timeout_duration_ms;
    uint32_t w10 = w9 << 1;
    uint32_t shifted = (w9 >> 4) & 0x07ffffffu;
    d1->timeout_duration_ms = (shifted < 0x753u) ? w10 : 0xea60u; // 0xea60 = 60000 ms
    d1->num_timeouts++;
    if (d1->num_timeouts > 12) {
        return -1; // Exceeded max DTLS retransmissions
    }
    d1->next_timeout_tv_sec  = d1->timeout_duration_ms / 1000u;
    d1->next_timeout_tv_usec = (d1->timeout_duration_ms % 1000u) * 1000u;
    return 1;
}

int SSL_CTX_set_srtp_profiles(SSL_CTX* ctx, const char* profiles) {
    // Disassembly @ 0x016a28: returns 0 on success in OpenSSL/BoringSSL SRTP API, or 1 in internal helper
    // Note: SSL_CTX_set_tlsext_use_srtp returns 0 on success; SSL_CTX_set_srtp_profiles returns 1 on success!
    // Look at 0x016bf4 (SSL_CTX_set_tlsext_use_srtp): calls SSL_CTX_set_srtp_profiles and inverts return!
    if (!ctx) {
        return 0;
    }
    return parse_srtp_profile_string(profiles, &ctx->srtp_profiles) ? 1 : 0;
}

int SSL_set_srtp_profiles(SSL* ssl, const char* profiles) {
    if (!ssl) {
        return 0;
    }
    if (!parse_srtp_profile_string(profiles, &ssl->srtp_profiles)) {
        return 0;
    }
    ssl->selected_srtp_profile = ssl->srtp_profiles.front();
    return 1;
}

int SSL_CTX_set_tlsext_use_srtp(SSL_CTX* ctx, const char* profiles) {
    // OpenSSL convention: 0 on success, 1 on error
    return SSL_CTX_set_srtp_profiles(ctx, profiles) ? 0 : 1;
}

int SSL_set_tlsext_use_srtp(SSL* ssl, const char* profiles) {
    return SSL_set_srtp_profiles(ssl, profiles) ? 0 : 1;
}

const std::vector<const SRTP_PROTECTION_PROFILE*>* SSL_get_srtp_profiles(const SSL* ssl) {
    if (!ssl) {
        return nullptr;
    }
    if (!ssl->srtp_profiles.empty()) {
        return &ssl->srtp_profiles;
    }
    if (ssl->ctx && !ssl->ctx->srtp_profiles.empty()) {
        return &ssl->ctx->srtp_profiles;
    }
    return nullptr;
}

const SRTP_PROTECTION_PROFILE* SSL_get_selected_srtp_profile(SSL* ssl) {
    // Disassembly @ 0x016be8 (12 B)
    return ssl ? ssl->selected_srtp_profile : nullptr;
}

const SSL_METHOD* DTLS_method()              { return &kDtlsMethod; }
const SSL_METHOD* DTLS_with_buffers_method() { return &kDtlsMethod; }
const SSL_METHOD* DTLSv1_2_method()          { return &kDtls12Method; }
const SSL_METHOD* DTLSv1_method()            { return &kDtls10Method; }
const SSL_METHOD* DTLS_client_method()       { return &kDtlsMethod; }
const SSL_METHOD* DTLS_server_method()       { return &kDtlsMethod; }
const SSL_METHOD* TLS_method()               { return &kTlsMethod; }
const SSL_METHOD* TLS_client_method()        { return &kTlsMethod; }
const SSL_METHOD* TLS_server_method()        { return &kTlsMethod; }

// ============================================================================
// 2. QUIC Transport Integration Implementation (0x032c98..0x0350f0)
//    Thực thi tích hợp giao vận QUIC (Khớp địa chỉ 0x032c98..0x0350f0)
// ============================================================================
size_t SSL_quic_max_handshake_flight_len(const SSL* ssl, ssl_encryption_level_t level) {
    // Disassembly @ 0x032c98 (104 B):
    //   0x032c98: cmp  w1, #3
    //   0x032c9c: b.hi #0x32cc0        ; > 3 -> return 0
    //   level == ssl_encryption_initial (0) or ssl_encryption_application (3) -> 0x4000 (16384)
    //   level == ssl_encryption_early_data (1) -> 0
    //   level == ssl_encryption_handshake (2):
    //     if (!ssl->server) { w8 = ssl->max_cert_list * 2; }
    //     else if (ssl->config->jdk11_workaround) { w8 = ssl->max_cert_list; }
    //     return max(w8, 0x4000);
    if (!ssl || static_cast<uint32_t>(level) > 3u) {
        return 0;
    }
    switch (level) {
        case ssl_encryption_initial:
        case ssl_encryption_application:
            return 0x4000u; // 16384
        case ssl_encryption_early_data:
            return 0u;
        case ssl_encryption_handshake: {
            uint32_t limit = 0x4000u;
            if ((ssl->flags_a4 & 0x01u) == 0) {
                // Client: 2 * max_cert_list (@ 0x032cd0: ldr w8, [x0, #0x88]; lsl w8, w8, #1)
                limit = ssl->max_cert_list << 1;
            } else if (ssl->config && (ssl->config->flags_e8 & 0x01u) != 0) {
                // Server with jdk11_workaround (@ 0x032ce0: ldrb w8, [x8, #0xe8]; tbz w8, #0)
                limit = ssl->max_cert_list;
            }
            return (limit > 0x4000u) ? static_cast<size_t>(limit) : 0x4000u;
        }
        default:
            return 0u;
    }
}

ssl_encryption_level_t SSL_quic_read_level(const SSL* ssl) {
    // Disassembly @ 0x032d00 (12 B):
    //   0x032d00: ldr x8, [x0, #0x30]
    //   0x032d04: ldr w0, [x8, #0xc8]
    //   0x032d08: ret
    return (ssl && ssl->s3) ? ssl->s3->quic_read_level : ssl_encryption_initial;
}

ssl_encryption_level_t SSL_quic_write_level(const SSL* ssl) {
    // Disassembly @ 0x032d0c (12 B):
    //   0x032d0c: ldr x8, [x0, #0x30]
    //   0x032d10: ldr w0, [x8, #0xcc]
    //   0x032d14: ret
    return (ssl && ssl->s3) ? ssl->s3->quic_write_level : ssl_encryption_initial;
}

int SSL_provide_quic_data(SSL* ssl, ssl_encryption_level_t level,
                          const uint8_t* data, size_t len) {
    // Disassembly @ 0x032d18 (168 B):
    //   0x032d28: ldr x8, [x0, #0x98] ; require ssl->quic_method != nullptr
    //   0x032d38: ldr w9, [x8, #0xc8] ; require level == ssl->s3->quic_read_level
    //   0x032d64: bl  #0x13a10        ; check buffered + len <= SSL_quic_max_handshake_flight_len
    if (!ssl || !ssl->quic_method || !ssl->s3) {
        return 0;
    }
    if (level != ssl->s3->quic_read_level) {
        return 0;
    }
    if (len == 0) {
        return 1;
    }
    if (!data) {
        return 0;
    }
    auto& buf = ssl->s3->quic_input_buffer[static_cast<size_t>(level)];
    const size_t max_flight = SSL_quic_max_handshake_flight_len(ssl, level);
    if (buf.size() + len > max_flight) {
        return 0;
    }
    buf.insert(buf.end(), data, data + len);
    return 1;
}

int SSL_process_quic_post_handshake(SSL* ssl) {
    // Disassembly @ 0x032f20 (180 B): processes post-handshake NewSessionTicket in QUIC mode
    if (!ssl || !ssl->quic_method || !ssl->s3) {
        return 0;
    }
    if ((ssl->s3->flags_dc & (1u << 5)) == 0) {
        return 0; // Handshake not yet complete
    }
    auto& app_buf = ssl->s3->quic_input_buffer[ssl_encryption_application];
    if (!app_buf.empty()) {
        if (ssl->session) {
            ssl->session->ticket.assign(app_buf.begin(), app_buf.end());
        }
        app_buf.clear();
    }
    return 1;
}

int SSL_set_quic_transport_params(SSL* ssl, const uint8_t* params, size_t params_len) {
    // Disassembly @ 0x033694 (44 B):
    //   0x03369c: ldr x8, [x0, #8]
    //   0x0336a0: cbz x8, #0x336b4
    //   0x0336a4: add x0, x8, #0xa0
    if (!ssl || !ssl->config || (!params && params_len > 0)) {
        return 0;
    }
    ssl->config->quic_transport_params_vec.assign(params, params + params_len);
    ssl->config->quic_transport_params_ptr = ssl->config->quic_transport_params_vec.data();
    ssl->config->quic_transport_params_len = ssl->config->quic_transport_params_vec.size();
    return 1;
}

void SSL_get_peer_quic_transport_params(const SSL* ssl,
                                        const uint8_t** out_params,
                                        size_t* out_params_len) {
    // Disassembly @ 0x0336c0 (28 B):
    //   0x0336c0: ldr x8, [x0, #0x30]
    //   0x0336c4: ldr x8, [x8, #0x240]
    //   0x0336c8: str x8, [x1]
    //   0x0336cc: ldr x8, [x0, #0x30]
    //   0x0336d0: ldr x8, [x8, #0x248]
    //   0x0336d4: str x8, [x2]
    //   0x0336d8: ret
    if (!out_params || !out_params_len) {
        return;
    }
    if (!ssl || !ssl->s3) {
        *out_params     = nullptr;
        *out_params_len = 0;
        return;
    }
    *out_params     = ssl->s3->peer_quic_params_ptr;
    *out_params_len = ssl->s3->peer_quic_params_len;
}

int SSL_set_quic_early_data_context(SSL* ssl, const uint8_t* context, size_t context_len) {
    // Disassembly @ 0x0336dc (44 B)
    if (!ssl || !ssl->config || (!context && context_len > 0)) {
        return 0;
    }
    ssl->config->quic_early_data_context_vec.assign(context, context + context_len);
    return 1;
}

int SSL_CTX_set_quic_method(SSL_CTX* ctx, const SSL_QUIC_METHOD* quic_method) {
    // Disassembly @ 0x0350d8 (24 B):
    //   0x0350d8: ldr  x8, [x0]
    //   0x0350dc: ldrb w8, [x8]
    //   0x0350e0: cbz  w8, #0x350e8 ; reject if is_dtls != 0
    //   0x0350e8: str  x1, [x0, #0x50]
    if (!ctx || !ctx->method || ctx->method->is_dtls) {
        return 0;
    }
    ctx->quic_method = quic_method;
    return 1;
}

int SSL_set_quic_method(SSL* ssl, const SSL_QUIC_METHOD* quic_method) {
    // Disassembly @ 0x0350f0 (24 B):
    //   0x0350f0: ldr  x8, [x0]
    //   0x0350f4: ldrb w8, [x8]
    //   0x0350f8: cbz  w8, #0x35100 ; reject if is_dtls != 0
    //   0x035100: str  x1, [x0, #0x98]
    if (!ssl || !ssl->method || ssl->method->is_dtls) {
        return 0;
    }
    ssl->quic_method = quic_method;
    return 1;
}

void SSL_CTX_set_early_data_enabled(SSL_CTX* ctx, int enabled) {
    if (ctx) {
        ctx->early_data_enabled = (enabled != 0);
    }
}

void SSL_set_early_data_enabled(SSL* ssl, int enabled) {
    if (ssl) {
        if (enabled) {
            ssl->flags_a4 |= 0x04u;
            if (ssl->s3) {
                ssl->s3->early_data_reason = ssl_early_data_accepted;
            }
        } else {
            ssl->flags_a4 &= ~0x04u;
            if (ssl->s3) {
                ssl->s3->early_data_reason = ssl_early_data_disabled;
            }
        }
    }
}

ssl_early_data_reason_t SSL_get_early_data_reason(const SSL* ssl) {
    // Disassembly @ 0x0337bc (12 B)
    return (ssl && ssl->s3) ? ssl->s3->early_data_reason : ssl_early_data_unknown;
}

// ============================================================================
// 3. ALPN & SNI Extension Implementation (0x034588..0x03493c)
//    Thực thi phần mở rộng ALPN và SNI (Khớp địa chỉ 0x034588..0x03493c)
// ============================================================================
int SSL_set_tlsext_host_name(SSL* ssl, const char* name) {
    // Disassembly @ 0x0346d8 (128 B):
    //   0x0346e4: add x19, x0, #0x90
    //   0x0346f0: cbz x20, #0x34734 ; if name == nullptr, clear & return 1
    //   0x0346f8: bl  strlen
    //   0x0346fc: sub x8, x0, #1
    //   0x034700: cmp x8, #0xff     ; require 1 <= strlen(name) <= 255
    //   0x034704: b.lo #0x34718
    if (!ssl) {
        return 0;
    }
    if (!name) {
        ssl->hostname_str.clear();
        ssl->hostname = nullptr;
        if (ssl->s3) {
            ssl->s3->hostname_ptr = nullptr;
        }
        return 1;
    }
    const size_t len = std::strlen(name);
    if (len - 1u >= 0xffu) { // Exact unsigned check: sub x8, x0, #1; cmp x8, #0xff; b.lo
        return 0;
    }
    ssl->hostname_str.assign(name, len);
    ssl->hostname = ssl->hostname_str.c_str();
    if (ssl->s3) {
        ssl->s3->hostname_ptr = ssl->hostname;
    }
    return 1;
}

const char* SSL_get_servername(const SSL* ssl, int type) {
    // Disassembly @ 0x034588 (36 B):
    //   0x034588: cbz w1, #0x34590 ; TLSEXT_NAMETYPE_host_name == 0
    //   0x034594: ldr x0, [x0, #0x90]
    //   0x034598: cbz x0, #0x345a0
    //   0x03459c: ret
    //   0x0345a0: ldr x8, [x8, #0x30]
    //   0x0345a4: ldr x0, [x8, #0x1f8]
    if (!ssl || type != 0) {
        return nullptr;
    }
    if (ssl->hostname) {
        return ssl->hostname;
    }
    return ssl->s3 ? ssl->s3->hostname_ptr : nullptr;
}

int SSL_CTX_set_alpn_protos(SSL_CTX* ctx, const uint8_t* protos, unsigned int protos_len) {
    // Disassembly @ 0x034880 (84 B):
    // Note OpenSSL/BoringSSL ALPN return convention: 0 on SUCCESS, 1 on FAILURE!
    // Look at 0x0348b0: mvn w8, w0; and w0, w8, #1 (inverts CBB_copy bool result!)
    if (!ctx) {
        return 1;
    }
    if (protos_len == 0) {
        ctx->alpn_client_proto_list.clear();
        return 0;
    }
    if (!ssl_is_valid_alpn_list(protos, protos_len)) {
        return 1;
    }
    ctx->alpn_client_proto_list.assign(protos, protos + protos_len);
    return 0;
}

int SSL_set_alpn_protos(SSL* ssl, const uint8_t* protos, unsigned int protos_len) {
    // Disassembly @ 0x0348d4 (96 B):
    //   0x0348e4: ldr x8, [x0, #8] ; ssl->config
    //   0x034908: add x0, x8, #0x78 ; &ssl->config->alpn_client_proto_list
    //   0x034910: mvn w8, w0; and w0, w8, #1 (returns 0 on success, 1 on failure)
    if (!ssl || !ssl->config) {
        return 1;
    }
    if (protos_len == 0) {
        ssl->config->alpn_client_proto_vec.clear();
        ssl->config->alpn_client_proto_ptr = nullptr;
        ssl->config->alpn_client_proto_len = 0;
        return 0;
    }
    if (!ssl_is_valid_alpn_list(protos, protos_len)) {
        return 1;
    }
    ssl->config->alpn_client_proto_vec.assign(protos, protos + protos_len);
    ssl->config->alpn_client_proto_ptr = ssl->config->alpn_client_proto_vec.data();
    ssl->config->alpn_client_proto_len = ssl->config->alpn_client_proto_vec.size();
    return 0;
}

void SSL_get0_alpn_selected(const SSL* ssl, const uint8_t** out_data, unsigned int* out_len) {
    // Disassembly @ 0x03493c (88 B):
    //   0x03493c: ldr x8, [x0, #0x30]
    //   0x034978: ldr x8, [x8, #0x1e8]
    //   0x03497c: str x8, [x1]
    //   0x034984: add x8, x8, #0x1f0
    //   0x034988: ldr x8, [x8]
    //   0x03498c: str w8, [x2]
    if (!out_data || !out_len) {
        return;
    }
    if (!ssl || !ssl->s3) {
        *out_data = nullptr;
        *out_len  = 0;
        return;
    }
    *out_data = ssl->s3->alpn_selected_ptr;
    *out_len  = static_cast<unsigned int>(ssl->s3->alpn_selected_len);
}

void SSL_CTX_set_alpn_select_cb(SSL_CTX* ctx, SSL_CTX_alpn_select_cb_func cb, void* arg) {
    if (ctx) {
        ctx->alpn_select_cb     = cb;
        ctx->alpn_select_cb_arg = arg;
    }
}

int SSL_select_next_proto(uint8_t** out, uint8_t* out_len,
                          const uint8_t* peer, unsigned int peer_len,
                          const uint8_t* client, unsigned int client_len) {
    if (!out || !out_len || !client || client_len == 0) {
        return 0;
    }
    if (peer && peer_len > 0) {
        unsigned int p_idx = 0;
        while (p_idx < peer_len) {
            uint8_t p_len = peer[p_idx++];
            if (p_len == 0 || p_idx + p_len > peer_len) {
                break;
            }
            unsigned int c_idx = 0;
            while (c_idx < client_len) {
                uint8_t c_len = client[c_idx++];
                if (c_len == 0 || c_idx + c_len > client_len) {
                    break;
                }
                if (p_len == c_len && std::memcmp(peer + p_idx, client + c_idx, p_len) == 0) {
                    *out     = const_cast<uint8_t*>(peer + p_idx);
                    *out_len = p_len;
                    return 1; // OPENSSL_NPN_NEGOTIATED
                }
                c_idx += c_len;
            }
            p_idx += p_len;
        }
    }
    // Fallback to first client protocol (OPENSSL_NPN_NO_OVERLAP = 2)
    *out     = const_cast<uint8_t*>(client + 1);
    *out_len = client[0];
    return 2;
}

} // namespace ttboringssl
} // namespace nextai
