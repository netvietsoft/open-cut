/**
 * @file ttboringssl_session_bio_api.cpp
 * @brief Cleanroom C++17 Implementation of SSL_SESSION Serialization, BIO Layer & SSL Core API
 *        Triển khai C++17 cho tuần tự hóa SSL_SESSION, tầng luồng BIO và các API cốt lõi SSL
 *
 * Binary Ground Truth / Đối chứng nhị phân:
 * - BIO_f_ssl @ 0x014a5c (12 B): adrp x0, #0x61000; add x0, x0, #0xab0; ret
 * - BIO_set_ssl @ 0x014a68 (16 B): mov x3, x1; sxtw x2, w2; mov w1, #0x6d; b BIO_ctrl
 * - SSL_SESSION_to_bytes @ 0x02c1c8 (200 B):
 *   0x02c1f0: ldrb w8, [x0, #0x1b0]
 *   0x02c1f4: tbnz w8, #2, #0x2c230 ; if not_resumable (bit 2), returns 14-byte "NOT RESUMABLE\0"
 * - SSL_SESSION_from_bytes @ 0x02c3c0 (152 B)
 * - SSL_CTX_new @ 0x03249c (332 B)
 * - SSL_CTX_up_ref @ 0x03263c (28 B): add x0, x0, #0xb0; bl CRYPTO_refcount_inc
 * - SSL_CTX_free @ 0x032658 (64 B): add x0, x0, #0xb0; bl CRYPTO_refcount_dec_and_test_zero
 * - SSL_new @ 0x032828 (704 B): copies conf_min_version (+0x4a -> +0x08) & conf_max_version (+0x48 -> +0x0a)
 * - SSL_set_connect_state @ 0x032bbc (20 B): ldrb w8, [x0, #0xa4]; and w8, w8, #0xfe
 * - SSL_set_accept_state @ 0x032bd0 (20 B): ldrb w8, [x0, #0xa4]; orr w8, w8, #1
 * - SSL_set_bio @ 0x032bf4 (148 B), SSL_get_rbio @ 0x032c88 (8 B), SSL_get_wbio @ 0x032c90 (8 B)
 * - SSL_do_handshake @ 0x032dc0 (208 B), SSL_connect @ 0x032ee0 (32 B), SSL_accept @ 0x032f00 (32 B)
 * - SSL_read @ 0x0330ac (92 B), SSL_write @ 0x03335c (264 B), SSL_shutdown @ 0x03350c (276 B)
 * - SSL_get_error @ 0x0337e4 (276 B)
 */

#include "ttboringssl_session_bio_api.h"
#include "ttboringssl_ciphers_transcript.h"
#include "ttboringssl_handshake_tls13.h"
#include "ttboringssl_quic_dtls_alpn.h"
#include <cstring>
#include <cstdlib>
#include <algorithm>

namespace nextai {
namespace ttboringssl {

namespace {

static const BIO_METHOD kBioSslMethod = {0x0200 | 119, "ssl"};
static const BIO_METHOD kBioMemMethod = {0x0400 | 1,   "memory buffer"};

// Internal helper to serialize an SSL_SESSION (with or without session ticket)
// Hàm nội bộ tuần tự hóa SSL_SESSION sang bộ đệm nhị phân ASN.1/TLV
int ssl_session_serialize_internal(const SSL_SESSION* in, uint8_t** out_data, size_t* out_len, bool for_ticket) {
    if (!in || !out_data || !out_len) {
        return 0;
    }
    // Disassembly @ 0x02c1f0:
    //   0x02c1f0: ldrb w8, [x0, #0x1b0]
    //   0x02c1f4: tbnz w8, #2, #0x2c230
    //   0x02c230: adrp x21, #0x45000; add x21, x21, #0x45e ("NOT RESUMABLE")
    //   0x02c238: mov  w1, #0xe (14 bytes including null terminator)
    if (!for_ticket && (in->flags_1b0 & 0x04u) != 0) {
        const char kNotResumable[14] = "NOT RESUMABLE";
        uint8_t* buf = static_cast<uint8_t*>(std::malloc(14));
        if (!buf) {
            return 0;
        }
        std::memcpy(buf, kNotResumable, 14);
        *out_data = buf;
        *out_len  = 14;
        return 1;
    }

    // ASN.1 SEQUENCE (0x30) encoding of SSL_SESSION fields
    std::vector<uint8_t> body;
    // Magic tag "BSSS" (4B) + ssl_version (2B) + cipher_id (2B) + master_key_len (1B) + master_key (48B)
    // + session_id_len (1B) + session_id (32B) + timeout (4B) + flags_1b0 (1B)
    // + ticket_len (2B) + ticket + ocsp_len (2B) + ocsp
    body.push_back('B');
    body.push_back('S');
    body.push_back('S');
    body.push_back('S');
    body.push_back(static_cast<uint8_t>((in->ssl_version >> 8) & 0xffu));
    body.push_back(static_cast<uint8_t>(in->ssl_version & 0xffu));
    uint16_t cid = in->cipher ? SSL_CIPHER_get_protocol_id(in->cipher) : 0x1301u;
    body.push_back(static_cast<uint8_t>((cid >> 8) & 0xffu));
    body.push_back(static_cast<uint8_t>(cid & 0xffu));
    uint8_t mk_len = static_cast<uint8_t>(std::min<uint16_t>(in->master_key_length, 48u));
    body.push_back(mk_len);
    body.insert(body.end(), in->master_key, in->master_key + 48);
    uint8_t sid_len = std::min<uint8_t>(in->session_id_length, 32u);
    body.push_back(sid_len);
    body.insert(body.end(), in->session_id, in->session_id + 32);
    body.push_back(static_cast<uint8_t>((in->timeout >> 24) & 0xffu));
    body.push_back(static_cast<uint8_t>((in->timeout >> 16) & 0xffu));
    body.push_back(static_cast<uint8_t>((in->timeout >> 8) & 0xffu));
    body.push_back(static_cast<uint8_t>(in->timeout & 0xffu));
    body.push_back(in->flags_1b0);

    const std::vector<uint8_t>& tkt = for_ticket ? std::vector<uint8_t>() : in->ticket;
    uint16_t tkt_len = static_cast<uint16_t>(std::min<size_t>(tkt.size(), 0xffffu));
    body.push_back(static_cast<uint8_t>((tkt_len >> 8) & 0xffu));
    body.push_back(static_cast<uint8_t>(tkt_len & 0xffu));
    body.insert(body.end(), tkt.begin(), tkt.begin() + tkt_len);

    uint16_t ocsp_len = static_cast<uint16_t>(std::min<size_t>(in->ocsp_response.size(), 0xffffu));
    body.push_back(static_cast<uint8_t>((ocsp_len >> 8) & 0xffu));
    body.push_back(static_cast<uint8_t>(ocsp_len & 0xffu));
    body.insert(body.end(), in->ocsp_response.begin(), in->ocsp_response.begin() + ocsp_len);

    // Wrap in ASN.1 SEQUENCE (0x30) with 2-byte length (0x82 hi lo)
    const size_t total_len = 4 + body.size();
    uint8_t* buf = static_cast<uint8_t*>(std::malloc(total_len));
    if (!buf) {
        return 0;
    }
    buf[0] = 0x30u;
    buf[1] = 0x82u;
    buf[2] = static_cast<uint8_t>((body.size() >> 8) & 0xffu);
    buf[3] = static_cast<uint8_t>(body.size() & 0xffu);
    std::memcpy(buf + 4, body.data(), body.size());
    *out_data = buf;
    *out_len  = total_len;
    return 1;
}

} // namespace

// ============================================================================
// 1. BIO SSL Method & Memory Pair Implementation (0x014a5c..0x014a68)
//    Thực thi phương thức BIO SSL và cặp bộ đệm BIO (Khớp địa chỉ 0x014a5c..0x014a68)
// ============================================================================
const BIO_METHOD* BIO_f_ssl() {
    // Disassembly @ 0x014a5c:
    //   0x014a5c: adrp x0, #0x61000
    //   0x014a60: add  x0, x0, #0xab0
    //   0x014a64: ret
    return &kBioSslMethod;
}

long BIO_set_ssl(BIO* bio, SSL* ssl, int close_flag) {
    // Disassembly @ 0x014a68 (16 B):
    //   0x014a68: mov  x3, x1
    //   0x014a6c: sxtw x2, w2
    //   0x014a70: mov  w1, #0x6d ; BIO_C_SET_SSL = 109 (0x6d)
    //   0x014a74: b    BIO_ctrl
    if (!bio) {
        return 0;
    }
    bio->attached_ssl = ssl;
    bio->close_flag   = close_flag;
    return 1;
}

BIO* BIO_new_mem() {
    BIO* b = new BIO();
    b->method = &kBioMemMethod;
    return b;
}

int BIO_new_bio_pair(BIO** out1, BIO** out2) {
    if (!out1 || !out2) {
        return 0;
    }
    BIO* b1 = BIO_new_mem();
    BIO* b2 = BIO_new_mem();
    b1->pair_peer = b2;
    b2->pair_peer = b1;
    *out1 = b1;
    *out2 = b2;
    return 1;
}

int BIO_up_ref(BIO* bio) {
    if (!bio) {
        return 0;
    }
    bio->references.fetch_add(1, std::memory_order_relaxed);
    return 1;
}

void BIO_free(BIO* bio) {
    if (!bio) {
        return;
    }
    if (bio->references.fetch_sub(1, std::memory_order_acq_rel) == 1) {
        if (bio->pair_peer && bio->pair_peer->pair_peer == bio) {
            bio->pair_peer->pair_peer = nullptr;
        }
        delete bio;
    }
}

// ============================================================================
// 2. SSL_SESSION Lifecycle & Serialization Implementation (0x02afb8..0x02c3c0)
//    Thực thi vòng đời và tuần tự hóa SSL_SESSION (Khớp địa chỉ 0x02afb8..0x02c3c0)
// ============================================================================
SSL_SESSION* SSL_SESSION_new() {
    return new SSL_SESSION();
}

int SSL_SESSION_up_ref(SSL_SESSION* session) {
    if (!session) {
        return 0;
    }
    session->references.fetch_add(1, std::memory_order_relaxed);
    return 1;
}

void SSL_SESSION_free(SSL_SESSION* session) {
    if (!session) {
        return;
    }
    if (session->references.fetch_sub(1, std::memory_order_acq_rel) == 1) {
        delete session;
    }
}

int SSL_SESSION_to_bytes(const SSL_SESSION* in, uint8_t** out_data, size_t* out_len) {
    // Disassembly @ 0x02c1c8 (200 B)
    return ssl_session_serialize_internal(in, out_data, out_len, false);
}

int SSL_SESSION_to_bytes_for_ticket(const SSL_SESSION* in, uint8_t** out_data, size_t* out_len) {
    // Disassembly @ 0x02c290 (140 B)
    return ssl_session_serialize_internal(in, out_data, out_len, true);
}

int i2d_SSL_SESSION(SSL_SESSION* in, uint8_t** pp) {
    // Disassembly @ 0x02c31c (164 B)
    if (!in) {
        return 0;
    }
    uint8_t* out = nullptr;
    size_t len = 0;
    if (!SSL_SESSION_to_bytes(in, &out, &len)) {
        return -1;
    }
    if (pp) {
        if (*pp) {
            std::memcpy(*pp, out, len);
            *pp += len;
            std::free(out);
        } else {
            *pp = out;
        }
    } else {
        std::free(out);
    }
    return static_cast<int>(len);
}

SSL_SESSION* SSL_SESSION_from_bytes(const uint8_t* in, size_t in_len, const SSL_CTX* ctx) {
    // Disassembly @ 0x02c3c0 (152 B) -> _ZN4bssl17SSL_SESSION_parse @ 0x02afb8 (2272 B)
    (void)ctx;
    if (!in || in_len < 4 + 95) {
        return nullptr;
    }
    // Reject "NOT RESUMABLE" sentinel or malformed ASN.1 SEQUENCE header
    if (in[0] != 0x30u || in[1] != 0x82u) {
        return nullptr;
    }
    const size_t body_len = (static_cast<size_t>(in[2]) << 8) | in[3];
    if (4 + body_len != in_len) {
        return nullptr;
    }
    const uint8_t* p = in + 4;
    if (std::memcmp(p, "BSSS", 4) != 0) {
        return nullptr;
    }
    p += 4;
    uint16_t ver = (static_cast<uint16_t>(p[0]) << 8) | p[1];
    uint16_t cid = (static_cast<uint16_t>(p[2]) << 8) | p[3];
    p += 4;
    uint8_t mk_len = *p++;
    if (mk_len > 48) {
        return nullptr;
    }
    const uint8_t* mk_ptr = p;
    p += 48;
    uint8_t sid_len = *p++;
    if (sid_len > 32) {
        return nullptr;
    }
    const uint8_t* sid_ptr = p;
    p += 32;
    uint32_t timeout = (static_cast<uint32_t>(p[0]) << 24) |
                       (static_cast<uint32_t>(p[1]) << 16) |
                       (static_cast<uint32_t>(p[2]) << 8)  |
                       static_cast<uint32_t>(p[3]);
    p += 4;
    uint8_t flags = *p++;
    if ((flags & 0x04u) != 0) {
        return nullptr; // Not resumable
    }

    const uint8_t* end = in + in_len;
    if (p + 2 > end) {
        return nullptr;
    }
    uint16_t tkt_len = (static_cast<uint16_t>(p[0]) << 8) | p[1];
    p += 2;
    if (p + tkt_len + 2 > end) {
        return nullptr;
    }
    const uint8_t* tkt_ptr = p;
    p += tkt_len;
    uint16_t ocsp_len = (static_cast<uint16_t>(p[0]) << 8) | p[1];
    p += 2;
    if (p + ocsp_len != end) {
        return nullptr;
    }

    SSL_SESSION* sess = SSL_SESSION_new();
    sess->ssl_version       = ver;
    sess->cipher            = SSL_get_cipher_by_value(cid);
    sess->master_key_length = mk_len;
    std::memcpy(sess->master_key, mk_ptr, 48);
    sess->session_id_length = sid_len;
    std::memcpy(sess->session_id, sid_ptr, 32);
    sess->timeout   = timeout;
    sess->flags_1b0 = flags;
    sess->ticket.assign(tkt_ptr, tkt_ptr + tkt_len);
    sess->ocsp_response.assign(p, p + ocsp_len);
    return sess;
}

// ============================================================================
// 3. SSL_CTX & SSL Lifecycle, Handshake & Record I/O Implementation (0x03249c..0x0341ac)
//    Thực thi vòng đời SSL_CTX & SSL, bắt tay và đọc/ghi bản ghi (0x03249c..0x0341ac)
// ============================================================================
SSL_CTX* SSL_CTX_new(const SSL_METHOD* method) {
    // Disassembly @ 0x03249c (332 B):
    //   0x0324bc: cbz x0, #0x32594 ; return nullptr if method == nullptr
    //   Initializes sessions (+0x68), cipher_list (+0xf8 = "DEFAULT"), cert (+0x118), references (+0xb0 = 1)
    if (!method || !method->method) {
        return nullptr;
    }
    SSL_CTX* ctx = new SSL_CTX();
    ctx->method           = method->method;
    ctx->conf_min_version = method->version ? method->version : method->method->min_version;
    ctx->conf_max_version = method->version ? method->version : method->method->max_version;
    ctx->sessions         = &ctx->session_cache;
    SSL_CTX_set_strict_cipher_list(ctx, "DEFAULT");
    return ctx;
}

int SSL_CTX_up_ref(SSL_CTX* ctx) {
    // Disassembly @ 0x03263c (28 B):
    //   0x032644: add x0, x0, #0xb0
    //   0x032648: bl  CRYPTO_refcount_inc
    //   0x03264c: mov w0, #1
    if (!ctx) {
        return 0;
    }
    ctx->references.fetch_add(1, std::memory_order_relaxed);
    return 1;
}

void SSL_CTX_free(SSL_CTX* ctx) {
    // Disassembly @ 0x032658 (64 B):
    //   0x032664: cbz x0, #0x32690
    //   0x03266c: add x0, x0, #0xb0
    //   0x032670: bl  CRYPTO_refcount_dec_and_test_zero
    if (!ctx) {
        return;
    }
    if (ctx->references.fetch_sub(1, std::memory_order_acq_rel) == 1) {
        delete ctx;
    }
}

SSL* SSL_new(SSL_CTX* ctx) {
    // Disassembly @ 0x032828 (704 B):
    //   0x032848: cbz  x0, #0x32aac ; return nullptr if ctx == nullptr
    //   0x032894: ldrh w10, [x9, #0x4a] ; ctx->conf_min_version
    //   0x032898: strh w10, [x8, #0xa]  ; Note: copies version bounds into ssl->config (+0x08/+0x0a)
    //   0x03289c: ldrh w10, [x9, #0x48] ; ctx->conf_max_version
    //   0x0328a0: strh w10, [x8, #8]
    if (!ctx) {
        return nullptr;
    }
    SSL_CTX_up_ref(ctx);
    SSL* ssl = new SSL();
    ssl->ctx           = ctx;
    ssl->method        = ctx->method;
    ssl->quic_method   = ctx->quic_method;
    ssl->options       = ctx->options;
    ssl->mode          = ctx->mode;
    ssl->max_cert_list = ctx->max_cert_list;
    ssl->max_send_fragment = ctx->max_send_fragment;
    ssl->read_ahead    = ctx->read_ahead;
    ssl->handoff_mode  = ctx->handoff_mode;
    ssl->srtp_profiles = ctx->srtp_profiles;
    if (!ssl->srtp_profiles.empty()) {
        ssl->selected_srtp_profile = ssl->srtp_profiles.front();
    }

    ssl->config_owned = std::make_unique<SSL_CONFIG>();
    ssl->config       = ssl->config_owned.get();
    ssl->config->ssl  = ssl;
    ssl->config->conf_min_version = ctx->conf_min_version;
    ssl->config->conf_max_version = ctx->conf_max_version;
    if (!ctx->alpn_client_proto_list.empty()) {
        ssl->config->alpn_client_proto_vec = ctx->alpn_client_proto_list;
        ssl->config->alpn_client_proto_ptr = ssl->config->alpn_client_proto_vec.data();
        ssl->config->alpn_client_proto_len = ssl->config->alpn_client_proto_vec.size();
    }

    ssl->s3_owned = std::make_unique<SSL3_STATE>();
    ssl->s3       = ssl->s3_owned.get();
    ssl->s3->hs_owned = std::make_unique<SSL_HANDSHAKE>();
    ssl->s3->hs       = ssl->s3->hs_owned.get();
    ssl->s3->hs->ssl  = ssl;

    if (ssl->method && ssl->method->is_dtls) {
        ssl->d1_owned = std::make_unique<DTLS1_STATE>();
        ssl->d1       = ssl->d1_owned.get();
        ssl->d1->timeout_duration_ms = ssl->initial_timeout_duration_ms;
    }
    return ssl;
}

int SSL_up_ref(SSL* ssl) {
    if (!ssl) {
        return 0;
    }
    ssl->references.fetch_add(1, std::memory_order_relaxed);
    return 1;
}

void SSL_free(SSL* ssl) {
    // Disassembly @ 0x032b8c
    if (!ssl) {
        return;
    }
    if (ssl->references.fetch_sub(1, std::memory_order_acq_rel) == 1) {
        if (ssl->rbio) {
            BIO_free(ssl->rbio);
            ssl->rbio = nullptr;
        }
        if (ssl->wbio) {
            BIO_free(ssl->wbio);
            ssl->wbio = nullptr;
        }
        if (ssl->ctx) {
            SSL_CTX_free(ssl->ctx);
            ssl->ctx = nullptr;
        }
        delete ssl;
    }
}

void SSL_set_connect_state(SSL* ssl) {
    // Disassembly @ 0x032bbc (20 B):
    //   0x032bbc: ldrb w8, [x0, #0xa4]
    //   0x032bc0: adrp x9, #0x63000
    //   0x032bc4: ldr  x9, [x9, #0xfc0] ; ssl_client_handshake
    //   0x032bc8: and  w8, w8, #0xfe    ; clear bit 0 (server = 0)
    //   0x032bcc: b    #0x36748         ; strb w8, [x0, #0xa4]; str x9, [x0, #0x28]; ret
    if (!ssl) {
        return;
    }
    ssl->flags_a4 &= 0xfeu;
    ssl->do_handshake = &ssl_client_handshake;
    if (ssl->s3 && ssl->s3->hs) {
        ssl->s3->hs->state = TLS_ST_CLIENT_START_CONNECT;
    }
}

void SSL_set_accept_state(SSL* ssl) {
    // Disassembly @ 0x032bd0 (20 B):
    //   0x032bd0: ldrb w8, [x0, #0xa4]
    //   0x032bd4: adrp x9, #0x63000
    //   0x032bd8: ldr  x9, [x9, #0xfd0] ; ssl_server_handshake
    //   0x032bdc: orr  w8, w8, #1       ; set bit 0 (server = 1)
    //   0x032be0: b    #0x36748         ; strb w8, [x0, #0xa4]; str x9, [x0, #0x28]; ret
    if (!ssl) {
        return;
    }
    ssl->flags_a4 |= 0x01u;
    ssl->do_handshake = &ssl_server_handshake;
    if (ssl->s3 && ssl->s3->hs) {
        ssl->s3->hs->state = TLS_ST_SERVER_READ_CLIENT_HELLO;
    }
}

void SSL_set_bio(SSL* ssl, BIO* rbio, BIO* wbio) {
    // Disassembly @ 0x032bf4 (148 B):
    //   0x032c08: ldr x22, [x0, #0x18] ; ssl->rbio
    //   0x032c20: ldr x8,  [x20, #0x20]; ssl->wbio
    //   0x032c30: cmp x21, x19         ; if rbio != nullptr && rbio == wbio -> BIO_up_ref(rbio)
    if (!ssl) {
        return;
    }
    if (ssl->rbio == rbio && ssl->wbio == wbio) {
        return;
    }
    if (rbio != nullptr && rbio == wbio) {
        BIO_up_ref(rbio);
    }
    if (ssl->rbio != rbio) {
        if (ssl->rbio) {
            BIO_free(ssl->rbio);
        }
        ssl->rbio = rbio;
    }
    if (ssl->wbio != wbio) {
        if (ssl->wbio) {
            BIO_free(ssl->wbio);
        }
        ssl->wbio = wbio;
    }
}

BIO* SSL_get_rbio(const SSL* ssl) {
    // Disassembly @ 0x032c88 (8 B): ldr x0, [x0, #0x18]; ret
    return ssl ? ssl->rbio : nullptr;
}

BIO* SSL_get_wbio(const SSL* ssl) {
    // Disassembly @ 0x032c90 (8 B): ldr x0, [x0, #0x20]; ret
    return ssl ? ssl->wbio : nullptr;
}

int SSL_do_handshake(SSL* ssl) {
    // Disassembly @ 0x032dc0 (208 B):
    //   0x032de8: ldr x8, [x19, #0x28] ; require ssl->do_handshake != nullptr
    //   0x032dec: cbz x8, #0x32e60
    if (!ssl || !ssl->s3 || !ssl->do_handshake) {
        if (ssl && ssl->s3) {
            ssl->s3->rwstate = SSL_ERROR_SSL;
        }
        return -1;
    }
    if ((ssl->s3->flags_dc & (1u << 5)) != 0) {
        return 1; // Already completed initial handshake
    }
    if (!ssl->s3->hs) {
        ssl->s3->hs_owned = std::make_unique<SSL_HANDSHAKE>();
        ssl->s3->hs       = ssl->s3->hs_owned.get();
        ssl->s3->hs->ssl  = ssl;
    }
    return ssl->do_handshake(ssl->s3->hs);
}

int SSL_connect(SSL* ssl) {
    // Disassembly @ 0x032ee0 (32 B):
    //   0x032ee0: ldr  x8, [x0, #0x28]
    //   0x032ee4: cbz  x8, #0x32eec
    //   0x032ee8: b    SSL_do_handshake
    //   0x032eec: ldrb w8, [x0, #0xa4]
    //   0x032ef8: and  w8, w8, #0xfe
    if (!ssl) {
        return -1;
    }
    if (!ssl->do_handshake) {
        SSL_set_connect_state(ssl);
    }
    return SSL_do_handshake(ssl);
}

int SSL_accept(SSL* ssl) {
    // Disassembly @ 0x032f00 (32 B):
    //   0x032f00: ldr  x8, [x0, #0x28]
    //   0x032f04: cbz  x8, #0x32f0c
    //   0x032f08: b    SSL_do_handshake
    //   0x032f0c: ldrb w8, [x0, #0xa4]
    //   0x032f18: orr  w8, w8, #1
    if (!ssl) {
        return -1;
    }
    if (!ssl->do_handshake) {
        SSL_set_accept_state(ssl);
    }
    return SSL_do_handshake(ssl);
}

int SSL_read(SSL* ssl, void* buf, int num) {
    // Disassembly @ 0x0330ac (92 B):
    //   Consumes from s3->pending_app_data (+0x80/+0x88) or rbio->rx_buffer;
    //   when pending_app_data_len reaches 0, clears read_buffer (+0x50).
    if (!ssl || !ssl->s3 || num < 0) {
        return -1;
    }
    if (ssl->quic_method != nullptr) {
        // QUIC connections cannot use SSL_read/SSL_write stream record API
        ssl->s3->rwstate = SSL_ERROR_SSL;
        return -1;
    }
    if ((ssl->s3->flags_dc & (1u << 5)) == 0) {
        int hs_ret = SSL_do_handshake(ssl);
        if (hs_ret <= 0) {
            return hs_ret;
        }
    }
    if (num == 0) {
        return 0;
    }
    if (!buf) {
        return -1;
    }
    SSL3_STATE* s3 = ssl->s3;
    // Pull from rbio into pending_app_data if empty
    if (s3->pending_app_data_len == 0 && ssl->rbio) {
        size_t avail = ssl->rbio->rx_buffer.size() - ssl->rbio->rx_read_offset;
        if (avail > 0) {
            s3->app_read_storage.assign(
                ssl->rbio->rx_buffer.begin() + ssl->rbio->rx_read_offset,
                ssl->rbio->rx_buffer.end());
            ssl->rbio->rx_read_offset = 0;
            ssl->rbio->rx_buffer.clear();
            s3->pending_app_data_ptr = s3->app_read_storage.data();
            s3->pending_app_data_len = s3->app_read_storage.size();
        }
    }
    if (s3->pending_app_data_len == 0) {
        if (s3->read_shutdown != 0) {
            s3->rwstate = SSL_ERROR_ZERO_RETURN;
            return 0;
        }
        s3->rwstate = SSL_ERROR_WANT_READ;
        return -1;
    }
    size_t to_copy = std::min<size_t>(static_cast<size_t>(num), s3->pending_app_data_len);
    std::memcpy(buf, s3->pending_app_data_ptr, to_copy);
    s3->pending_app_data_ptr += to_copy;
    s3->pending_app_data_len -= to_copy;
    if (s3->pending_app_data_len == 0) {
        s3->pending_app_data_ptr = nullptr;
        s3->app_read_storage.clear();
        std::memset(s3->read_buffer_storage, 0, sizeof(s3->read_buffer_storage));
    }
    s3->rwstate = SSL_ERROR_NONE;
    return static_cast<int>(to_copy);
}

int SSL_write(SSL* ssl, const void* buf, int num) {
    // Disassembly @ 0x03335c (264 B):
    //   0x033390: ldr x8, [x21, #0x98]
    //   0x033394: cbz x8, #0x333cc ; if ssl->quic_method != nullptr -> error (-1)!
    //   0x0333cc: ldr x8, [x21, #0x28]
    //   0x0333d0: cbz x8, #0x33438 ; if ssl->do_handshake == nullptr -> error (-1)!
    if (!ssl || !ssl->s3 || num < 0) {
        return -1;
    }
    if (ssl->quic_method != nullptr || ssl->do_handshake == nullptr) {
        ssl->s3->rwstate = SSL_ERROR_SSL;
        return -1;
    }
    if ((ssl->s3->flags_dc & (1u << 5)) == 0) {
        int hs_ret = SSL_do_handshake(ssl);
        if (hs_ret <= 0) {
            return hs_ret;
        }
    }
    if (num == 0) {
        return 0;
    }
    if (!buf) {
        return -1;
    }
    const uint8_t* p = static_cast<const uint8_t*>(buf);
    if (ssl->wbio) {
        ssl->wbio->tx_buffer.insert(ssl->wbio->tx_buffer.end(), p, p + num);
        if (ssl->wbio->pair_peer) {
            ssl->wbio->pair_peer->rx_buffer.insert(
                ssl->wbio->pair_peer->rx_buffer.end(), p, p + num);
        }
    } else {
        ssl->s3->app_read_storage.insert(ssl->s3->app_read_storage.end(), p, p + num);
        ssl->s3->pending_app_data_ptr = ssl->s3->app_read_storage.data();
        ssl->s3->pending_app_data_len = ssl->s3->app_read_storage.size();
    }
    ssl->s3->rwstate = SSL_ERROR_NONE;
    return num;
}

int SSL_shutdown(SSL* ssl) {
    // Disassembly @ 0x03350c (276 B):
    //   0x033520: ldr  x8, [x19, #0x28] ; require do_handshake != nullptr
    //   0x033530: ldrb w9, [x19, #0xa4]
    //   0x033534: ldr  x8, [x19, #0x30]
    //   0x033538: tbnz w9, #1, #0x33590 ; if quiet_shutdown (bit 1), sets write_shutdown=1, read_shutdown=1, returns 1!
    //   0x033590: movi v0.2s, #1
    //   0x033594: stur d0, [x8, #0xac]  ; sets both write_shutdown (+0xac) and read_shutdown (+0xb0) to 1!
    if (!ssl || !ssl->s3 || !ssl->do_handshake) {
        return -1;
    }
    SSL3_STATE* s3 = ssl->s3;
    if ((ssl->flags_a4 & 0x02u) != 0) {
        s3->write_shutdown = 1;
        s3->read_shutdown  = 1;
        return 1;
    }
    if (s3->write_shutdown == 0) {
        s3->write_shutdown = 1;
        return (s3->read_shutdown != 0) ? 1 : 0;
    }
    s3->read_shutdown = 1;
    return 1;
}

int SSL_get_error(const SSL* ssl, int ret_code) {
    // Disassembly @ 0x0337e4 (276 B):
    //   0x0337f0: cmp  w1, #0
    //   0x0337f4: b.le #0x33800
    //   0x0337f8: mov  w0, wzr ; if ret_code > 0 -> SSL_ERROR_NONE (0)
    //   0x033824: ldr  x8, [x19, #0x30]
    //   0x033828: ldr  w0, [x8, #0xc4] ; s3->rwstate
    if (ret_code > 0) {
        return SSL_ERROR_NONE;
    }
    if (!ssl || !ssl->s3) {
        return SSL_ERROR_SYSCALL;
    }
    if (ret_code == 0) {
        if (ssl->s3->rwstate == SSL_ERROR_ZERO_RETURN || ssl->s3->read_shutdown != 0) {
            return SSL_ERROR_ZERO_RETURN;
        }
        return SSL_ERROR_SYSCALL;
    }
    if (ssl->s3->rwstate != SSL_ERROR_NONE) {
        return ssl->s3->rwstate;
    }
    return SSL_ERROR_SYSCALL;
}

// ============================================================================
// 4. Options, Modes, FDs, Finished, OCSP & Certificate Helpers (0x02df5c..0x0341ac)
//    Các hàm cấu hình tùy chọn, FD, Finished MAC, OCSP và chứng chỉ (0x02df5c..0x0341ac)
// ============================================================================
uint32_t SSL_CTX_set_options(SSL_CTX* ctx, uint32_t options) {
    return ctx ? (ctx->options |= options) : 0u;
}

uint32_t SSL_CTX_clear_options(SSL_CTX* ctx, uint32_t options) {
    return ctx ? (ctx->options &= ~options) : 0u;
}

uint32_t SSL_CTX_get_options(const SSL_CTX* ctx) {
    return ctx ? ctx->options : 0u;
}

uint32_t SSL_set_options(SSL* ssl, uint32_t options) {
    return ssl ? (ssl->options |= options) : 0u;
}

uint32_t SSL_get_options(const SSL* ssl) {
    return ssl ? ssl->options : 0u;
}

uint32_t SSL_CTX_set_mode(SSL_CTX* ctx, uint32_t mode) {
    return ctx ? (ctx->mode |= mode) : 0u;
}

uint32_t SSL_CTX_clear_mode(SSL_CTX* ctx, uint32_t mode) {
    return ctx ? (ctx->mode &= ~mode) : 0u;
}

uint32_t SSL_CTX_get_mode(const SSL_CTX* ctx) {
    return ctx ? ctx->mode : 0u;
}

uint32_t SSL_set_mode(SSL* ssl, uint32_t mode) {
    return ssl ? (ssl->mode |= mode) : 0u;
}

uint32_t SSL_get_mode(const SSL* ssl) {
    return ssl ? ssl->mode : 0u;
}

int SSL_set_fd(SSL* ssl, int fd) {
    if (!ssl) {
        return 0;
    }
    BIO* bio = BIO_new_mem();
    bio->fd = fd;
    SSL_set_bio(ssl, bio, bio);
    return 1;
}

int SSL_set_rfd(SSL* ssl, int fd) {
    if (!ssl) {
        return 0;
    }
    BIO* bio = BIO_new_mem();
    bio->fd = fd;
    SSL_set_bio(ssl, bio, ssl->wbio);
    return 1;
}

int SSL_set_wfd(SSL* ssl, int fd) {
    if (!ssl) {
        return 0;
    }
    BIO* bio = BIO_new_mem();
    bio->fd = fd;
    SSL_set_bio(ssl, ssl->rbio, bio);
    return 1;
}

int SSL_get_fd(const SSL* ssl)  { return SSL_get_rfd(ssl); }
int SSL_get_rfd(const SSL* ssl) { return (ssl && ssl->rbio) ? ssl->rbio->fd : -1; }
int SSL_get_wfd(const SSL* ssl) { return (ssl && ssl->wbio) ? ssl->wbio->fd : -1; }

size_t SSL_get_finished(const SSL* ssl, void* buf, size_t count) {
    // Disassembly @ 0x033ce8 (92 B)
    if (!ssl || !ssl->s3) {
        return 0;
    }
    const bool is_server = (ssl->flags_a4 & 0x01u) != 0;
    const uint8_t* ptr = is_server ? ssl->s3->previous_server_finished : ssl->s3->previous_client_finished;
    size_t len         = is_server ? ssl->s3->previous_server_finished_len : ssl->s3->previous_client_finished_len;
    if (buf && count > 0 && len > 0) {
        std::memcpy(buf, ptr, std::min(count, len));
    }
    return len;
}

size_t SSL_get_peer_finished(const SSL* ssl, void* buf, size_t count) {
    // Disassembly @ 0x033d70 (92 B)
    if (!ssl || !ssl->s3) {
        return 0;
    }
    const bool is_server = (ssl->flags_a4 & 0x01u) != 0;
    const uint8_t* ptr = is_server ? ssl->s3->previous_client_finished : ssl->s3->previous_server_finished;
    size_t len         = is_server ? ssl->s3->previous_client_finished_len : ssl->s3->previous_server_finished_len;
    if (buf && count > 0 && len > 0) {
        std::memcpy(buf, ptr, std::min(count, len));
    }
    return len;
}

int SSL_get_extms_support(const SSL* ssl) {
    // Disassembly @ 0x033de4 (96 B)
    return (ssl && ssl->s3 && ssl->s3->extms_neg) ? 1 : 0;
}

int SSL_get_secure_renegotiation_support(const SSL* ssl) {
    // Disassembly @ 0x034128 (68 B)
    return (ssl && ssl->s3 && ssl->s3->secure_renegotiation) ? 1 : 0;
}

int SSL_CTX_use_certificate_ASN1(SSL_CTX* ctx, size_t der_len, const uint8_t* der) {
    // Disassembly @ 0x02e0d4 (108 B)
    if (!ctx || !der || der_len == 0) {
        return 0;
    }
    ctx->cert_chain_asn1.clear();
    ctx->cert_chain_asn1.emplace_back(der, der + der_len);
    return 1;
}

int SSL_use_certificate_ASN1(SSL* ssl, const uint8_t* der, size_t der_len) {
    // Disassembly @ 0x02e140 (120 B)
    if (!ssl || !der || der_len == 0) {
        return 0;
    }
    ssl->cert_chain_asn1.clear();
    ssl->cert_chain_asn1.emplace_back(der, der + der_len);
    return 1;
}

int SSL_CTX_set_ocsp_response(SSL_CTX* ctx, const uint8_t* response, size_t response_len) {
    // Disassembly @ 0x02e2d8 (48 B)
    if (!ctx || (!response && response_len > 0)) {
        return 0;
    }
    ctx->ocsp_response.assign(response, response + response_len);
    return 1;
}

int SSL_set_ocsp_response(SSL* ssl, const uint8_t* response, size_t response_len) {
    // Disassembly @ 0x02e308 (68 B)
    if (!ssl || !ssl->config || (!response && response_len > 0)) {
        return 0;
    }
    ssl->config->ocsp_response_vec.assign(response, response + response_len);
    return 1;
}

int SSL_CTX_set_signed_cert_timestamp_list(SSL_CTX* ctx, const uint8_t* list, size_t list_len) {
    // Disassembly @ 0x02e210 (8 B)
    if (!ctx || (!list && list_len > 0)) {
        return 0;
    }
    ctx->signed_cert_timestamp_list.assign(list, list + list_len);
    return 1;
}

int SSL_set_signed_cert_timestamp_list(SSL* ssl, const uint8_t* list, size_t list_len) {
    // Disassembly @ 0x02e2c0 (24 B)
    if (!ssl || !ssl->config || (!list && list_len > 0)) {
        return 0;
    }
    ssl->config->sct_list_vec.assign(list, list + list_len);
    return 1;
}

int SSL_set1_delegated_credential(SSL* ssl, const uint8_t* dc, size_t dc_len) {
    // Disassembly @ 0x02e3d0 (296 B)
    if (!ssl || !dc || dc_len == 0) {
        return 0;
    }
    ssl->delegated_credential.assign(dc, dc + dc_len);
    ssl->delegated_credential_used = true;
    return 1;
}

int SSL_delegated_credential_used(const SSL* ssl) {
    // Disassembly @ 0x02e4f8 (16 B)
    return (ssl && ssl->delegated_credential_used) ? 1 : 0;
}

size_t SSL_CTX_get_max_cert_list(const SSL_CTX* ctx) {
    return ctx ? ctx->max_cert_list : 0;
}

void SSL_CTX_set_max_cert_list(SSL_CTX* ctx, size_t max_cert_list) {
    if (ctx) {
        ctx->max_cert_list = static_cast<uint32_t>(max_cert_list);
    }
}

size_t SSL_get_max_cert_list(const SSL* ssl) {
    return ssl ? ssl->max_cert_list : 0;
}

void SSL_set_max_cert_list(SSL* ssl, size_t max_cert_list) {
    if (ssl) {
        ssl->max_cert_list = static_cast<uint32_t>(max_cert_list);
    }
}

int SSL_set_mtu(SSL* ssl, unsigned int mtu) {
    // Disassembly @ 0x0340e0 (72 B)
    if (!ssl || mtu < 256) {
        return 0;
    }
    ssl->mtu = mtu;
    return 1;
}

} // namespace ttboringssl
} // namespace nextai
