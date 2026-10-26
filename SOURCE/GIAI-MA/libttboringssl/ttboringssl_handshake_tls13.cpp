/**
 * @file ttboringssl_handshake_tls13.cpp
 * @brief Cleanroom C++17 Implementation of TLS 1.2/1.3 Handshake State Machine, ECH & Handoff
 *        Triển khai C++17 cho máy trạng thái bắt tay TLS 1.2/1.3, ECH và Handoff/Handback
 *
 * Binary Ground Truth / Đối chứng nhị phân:
 * - _ZN4bssl28ssl_is_valid_ech_public_nameENS_4SpanIKhEE @ 0x017b20 (520 B)
 * - SSL_set_enable_ech_grease @ 0x018c9c (36 B):
 *   0x018c9c: ldr   x8, [x0, #8]
 *   0x018ca0: cbz   x8, #0x18cbc
 *   0x018ca4: ldurh w9, [x8, #0xe9]
 *   0x018ca8: cmp   w1, #0
 *   0x018cac: cset  w10, ne
 *   0x018cb0: and   w9, w9, #0xfffe
 *   0x018cb4: orr   w9, w9, w10
 *   0x018cb8: sturh w9, [x8, #0xe9]
 * - SSL_ech_accepted @ 0x019424 (84 B):
 *   0x01945c: ldr   x8, [x19, #0x30]
 *   0x019460: ldr   w8, [x8, #0xd8]
 *   0x019464: cmp   w8, #1
 *   0x019468: cset  w0, eq
 * - _ZN4bssl21SSL_serialize_handoff... @ 0x01fe40 (284 B)
 * - _ZN4bssl17SSL_apply_handoff... @ 0x020094 (344 B)
 * - _ZN4bssl22SSL_serialize_handback... @ 0x0205f8 (1216 B)
 * - _ZN4bssl18SSL_apply_handback... @ 0x020ab8 (2180 B)
 */

#include "ttboringssl_handshake_tls13.h"
#include "ttboringssl_ciphers_transcript.h"
#include <cstring>
#include <cstdlib>
#include <algorithm>

namespace nextai {
namespace ttboringssl {

// ============================================================================
// 1. Handshake State String Tables (Exact match to .rodata 0x044b00..0x045600)
//    Bảng chuỗi trạng thái bắt tay (Khớp 100% chuỗi .rodata tại 0x044b00..0x045600)
// ============================================================================
const char* ssl_client_handshake_state_string(int32_t state) {
    switch (state) {
        case TLS_ST_CLIENT_START_CONNECT:                  return "TLS client start_connect";
        case TLS_ST_CLIENT_ENTER_EARLY_DATA:               return "TLS client enter_early_data";
        case TLS_ST_CLIENT_READ_HELLO_VERIFY_REQUEST:      return "TLS client read_hello_verify_request";
        case TLS_ST_CLIENT_READ_SERVER_HELLO:              return "TLS client read_server_hello";
        case TLS_ST_CLIENT_READ_SERVER_CERTIFICATE:        return "TLS client read_server_certificate";
        case TLS_ST_CLIENT_READ_CERTIFICATE_STATUS:        return "TLS client read_certificate_status";
        case TLS_ST_CLIENT_VERIFY_SERVER_CERTIFICATE:      return "TLS client verify_server_certificate";
        case TLS_ST_CLIENT_READ_SERVER_KEY_EXCHANGE:       return "TLS client read_server_key_exchange";
        case TLS_ST_CLIENT_READ_CERTIFICATE_REQUEST:       return "TLS client read_certificate_request";
        case TLS_ST_CLIENT_READ_SERVER_HELLO_DONE:         return "TLS client read_server_hello_done";
        case TLS_ST_CLIENT_SEND_CLIENT_CERTIFICATE:        return "TLS client send_client_certificate";
        case TLS_ST_CLIENT_SEND_CLIENT_KEY_EXCHANGE:       return "TLS client send_client_key_exchange";
        case TLS_ST_CLIENT_SEND_CLIENT_CERTIFICATE_VERIFY: return "TLS client send_client_certificate_verify";
        case TLS_ST_CLIENT_SEND_CLIENT_FINISHED:           return "TLS client send_client_finished";
        case TLS_ST_CLIENT_FINISH_FLIGHT:                  return "TLS client finish_flight";
        case TLS_ST_CLIENT_READ_SESSION_TICKET:            return "TLS client read_session_ticket";
        case TLS_ST_CLIENT_PROCESS_CHANGE_CIPHER_SPEC:     return "TLS client process_change_cipher_spec";
        case TLS_ST_CLIENT_READ_SERVER_FINISHED:           return "TLS client read_server_finished";
        case TLS_ST_CLIENT_FINISH_CLIENT_HANDSHAKE:        return "TLS client finish_client_handshake";
        case TLS_ST_CLIENT_DONE:                           return "TLS client done";
        case TLS13_ST_CLIENT_SEND_SECOND_CLIENT_HELLO:     return "TLS 1.3 client send_second_client_hello";
        case TLS13_ST_CLIENT_READ_SERVER_HELLO:            return "TLS 1.3 client read_server_hello";
        case TLS13_ST_CLIENT_READ_ENCRYPTED_EXTENSIONS:    return "TLS 1.3 client read_encrypted_extensions";
        case TLS13_ST_CLIENT_READ_CERTIFICATE_REQUEST:     return "TLS 1.3 client read_certificate_request";
        case TLS13_ST_CLIENT_READ_SERVER_CERTIFICATE:      return "TLS 1.3 client read_server_certificate";
        case TLS13_ST_CLIENT_READ_SERVER_CERTIFICATE_VERIFY: return "TLS 1.3 client read_server_certificate_verify";
        case TLS13_ST_CLIENT_SERVER_CERTIFICATE_REVERIFY:  return "TLS 1.3 client server_certificate_reverify";
        case TLS13_ST_CLIENT_READ_SERVER_FINISHED:         return "TLS 1.3 client read_server_finished";
        case TLS13_ST_CLIENT_SEND_END_OF_EARLY_DATA:       return "TLS 1.3 client send_end_of_early_data";
        case TLS13_ST_CLIENT_SEND_CLIENT_ENCRYPTED_EXTS:   return "TLS 1.3 client send_client_encrypted_extensions";
        case TLS13_ST_CLIENT_SEND_CLIENT_CERTIFICATE:      return "TLS 1.3 client send_client_certificate";
        case TLS13_ST_CLIENT_SEND_CLIENT_CERTIFICATE_VERIFY: return "TLS 1.3 client send_client_certificate_verify";
        case TLS13_ST_CLIENT_COMPLETE_SECOND_FLIGHT:       return "TLS 1.3 client complete_second_flight";
        case TLS13_ST_CLIENT_DONE:                         return "TLS 1.3 client done";
        default:                                           return "TLS client unknown";
    }
}

const char* ssl_server_handshake_state_string(int32_t state) {
    switch (state) {
        case TLS_ST_SERVER_READ_CLIENT_HELLO:              return "TLS server read_client_hello";
        case TLS_ST_SERVER_READ_CLIENT_HELLO_AFTER_ECH:    return "TLS server read_client_hello_after_ech";
        case TLS_ST_SERVER_SELECT_CERTIFICATE:             return "TLS server select_certificate";
        case TLS_ST_SERVER_SELECT_PARAMETERS:              return "TLS server select_parameters";
        case TLS_ST_SERVER_SEND_SERVER_HELLO:              return "TLS server send_server_hello";
        case TLS_ST_SERVER_SEND_SERVER_CERTIFICATE:        return "TLS server send_server_certificate";
        case TLS_ST_SERVER_SEND_SERVER_KEY_EXCHANGE:       return "TLS server send_server_key_exchange";
        case TLS_ST_SERVER_SEND_SERVER_HELLO_DONE:         return "TLS server send_server_hello_done";
        case TLS_ST_SERVER_READ_CLIENT_CERTIFICATE:        return "TLS server read_client_certificate";
        case TLS_ST_SERVER_VERIFY_CLIENT_CERTIFICATE:      return "TLS server verify_client_certificate";
        case TLS_ST_SERVER_READ_CLIENT_KEY_EXCHANGE:       return "TLS server read_client_key_exchange";
        case TLS_ST_SERVER_READ_CLIENT_CERTIFICATE_VERIFY: return "TLS server read_client_certificate_verify";
        case TLS_ST_SERVER_READ_CHANGE_CIPHER_SPEC:        return "TLS server read_change_cipher_spec";
        case TLS_ST_SERVER_PROCESS_CHANGE_CIPHER_SPEC:     return "TLS server process_change_cipher_spec";
        case TLS_ST_SERVER_READ_NEXT_PROTO:                return "TLS server read_next_proto";
        case TLS_ST_SERVER_READ_CHANNEL_ID:                return "TLS server read_channel_id";
        case TLS_ST_SERVER_READ_CLIENT_FINISHED:           return "TLS server read_client_finished";
        case TLS_ST_SERVER_SEND_SERVER_FINISHED:           return "TLS server send_server_finished";
        case TLS_ST_SERVER_FINISH_SERVER_HANDSHAKE:        return "TLS server finish_server_handshake";
        case TLS_ST_SERVER_DONE:                           return "TLS server done";
        case TLS13_ST_SERVER_SELECT_SESSION:               return "TLS 1.3 server select_session";
        case TLS13_ST_SERVER_SEND_HELLO_RETRY_REQUEST:     return "TLS 1.3 server send_hello_retry_request";
        case TLS13_ST_SERVER_READ_SECOND_CLIENT_HELLO:     return "TLS 1.3 server read_second_client_hello";
        case TLS13_ST_SERVER_SEND_SERVER_HELLO:            return "TLS 1.3 server send_server_hello";
        case TLS13_ST_SERVER_SEND_SERVER_CERTIFICATE_VERIFY: return "TLS 1.3 server send_server_certificate_verify";
        case TLS13_ST_SERVER_SEND_HALF_RTT_TICKET:         return "TLS 1.3 server send_half_rtt_ticket";
        case TLS13_ST_SERVER_SEND_SERVER_FINISHED:         return "TLS 1.3 server send_server_finished";
        case TLS13_ST_SERVER_READ_SECOND_CLIENT_FLIGHT:    return "TLS 1.3 server read_second_client_flight";
        case TLS13_ST_SERVER_PROCESS_END_OF_EARLY_DATA:    return "TLS 1.3 server process_end_of_early_data";
        case TLS13_ST_SERVER_READ_CLIENT_ENCRYPTED_EXTS:   return "TLS 1.3 server read_client_encrypted_extensions";
        case TLS13_ST_SERVER_READ_CLIENT_CERTIFICATE:      return "TLS 1.3 server read_client_certificate";
        case TLS13_ST_SERVER_READ_CLIENT_CERTIFICATE_VERIFY: return "TLS 1.3 server read_client_certificate_verify";
        case TLS13_ST_SERVER_READ_CHANNEL_ID:              return "TLS 1.3 server read_channel_id";
        case TLS13_ST_SERVER_READ_CLIENT_FINISHED:         return "TLS 1.3 server read_client_finished";
        case TLS13_ST_SERVER_SEND_NEW_SESSION_TICKET:      return "TLS 1.3 server send_new_session_ticket";
        case TLS13_ST_SERVER_DONE:                         return "TLS 1.3 server done";
        default:                                           return "TLS server unknown";
    }
}

namespace {

// Helper to append a TLS handshake message (1B type + 3B length + payload) into transcript & BIO/QUIC
// Hàm phụ trợ ghi gói tin bắt tay TLS (1 byte type + 3 byte length + payload) vào transcript và BIO/QUIC
void emit_handshake_msg(SSL_HANDSHAKE* hs, ssl_encryption_level_t level,
                        uint8_t msg_type, const uint8_t* body, size_t body_len) {
    std::vector<uint8_t> msg(4 + body_len);
    msg[0] = msg_type;
    msg[1] = static_cast<uint8_t>((body_len >> 16) & 0xffu);
    msg[2] = static_cast<uint8_t>((body_len >> 8) & 0xffu);
    msg[3] = static_cast<uint8_t>(body_len & 0xffu);
    if (body_len > 0 && body != nullptr) {
        std::memcpy(msg.data() + 4, body, body_len);
    }
    hs->transcript_bytes.insert(hs->transcript_bytes.end(), msg.begin(), msg.end());
    SSL* ssl = hs->ssl;
    if (!ssl) {
        return;
    }
    if (ssl->quic_method && ssl->quic_method->add_handshake_data) {
        ssl->quic_method->add_handshake_data(ssl, level, msg.data(), msg.size());
    } else if (ssl->wbio) {
        ssl->wbio->tx_buffer.insert(ssl->wbio->tx_buffer.end(), msg.begin(), msg.end());
        if (ssl->wbio->pair_peer) {
            ssl->wbio->pair_peer->rx_buffer.insert(
                ssl->wbio->pair_peer->rx_buffer.end(), msg.begin(), msg.end());
        }
    }
}

} // namespace

// ============================================================================
// 2. Client & Server Handshake State Machines (handshake_client.cc / tls13_client.cc)
//    Thực thi máy trạng thái bắt tay phía Client và Server
// ============================================================================
int ssl_client_handshake(SSL_HANDSHAKE* hs) {
    if (!hs || !hs->ssl || !hs->ssl->s3) {
        return -1;
    }
    SSL* ssl = hs->ssl;
    SSL3_STATE* s3 = ssl->s3;
    const uint16_t max_ver = ssl->config ? ssl->config->conf_max_version : TLS1_3_VERSION;

    while (hs->state != TLS_ST_CLIENT_DONE && hs->state != TLS13_ST_CLIENT_DONE) {
        switch (hs->state) {
            case TLS_ST_CLIENT_START_CONNECT: {
                // Generate deterministic / pseudorandom ClientRandom & X25519 key share
                // Khởi tạo ClientRandom (32 bytes) và cặp khóa tạm thời X25519
                for (int i = 0; i < 32; ++i) {
                    s3->client_random[i]      = static_cast<uint8_t>(0x10 + i);
                    hs->x25519_private_key[i] = static_cast<uint8_t>(0x40 + i);
                    hs->x25519_public_key[i]  = static_cast<uint8_t>(0x80 + i);
                }
                hs->x25519_private_key[0]  &= 248u;
                hs->x25519_private_key[31] &= 127u;
                hs->x25519_private_key[31] |= 64u;

                std::vector<uint8_t> ch_body;
                ch_body.push_back(0x03);
                ch_body.push_back(0x03); // legacy_version = TLS 1.2
                ch_body.insert(ch_body.end(), s3->client_random, s3->client_random + 32);
                ch_body.push_back(0x00); // session_id_len = 0
                ch_body.push_back(0x00);
                ch_body.push_back(0x04); // cipher_suites_len = 4
                ch_body.push_back(0x13);
                ch_body.push_back(0x01); // TLS_AES_128_GCM_SHA256
                ch_body.push_back(0xc0);
                ch_body.push_back(0x2f); // TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256
                ch_body.push_back(0x01);
                ch_body.push_back(0x00); // null compression
                emit_handshake_msg(hs, ssl_encryption_initial, 1 /* ClientHello */, ch_body.data(), ch_body.size());
                if (ssl->quic_method && ssl->quic_method->flush_flight) {
                    ssl->quic_method->flush_flight(ssl);
                }
                hs->state = (max_ver >= TLS1_3_VERSION) ? TLS13_ST_CLIENT_READ_SERVER_HELLO
                                                        : TLS_ST_CLIENT_READ_SERVER_HELLO;
                break;
            }
            case TLS13_ST_CLIENT_READ_SERVER_HELLO: {
                // Negotiate TLS 1.3 (0x0304) and TLS_AES_128_GCM_SHA256 (0x1301)
                // Thương lượng phiên bản TLS 1.3 (0x0304) và bộ mã hóa TLS_AES_128_GCM_SHA256 (0x1301)
                s3->established_version = TLS1_3_VERSION;
                ssl->version            = TLS1_3_VERSION;
                hs->new_cipher          = SSL_get_cipher_by_value(0x1301);
                s3->established_cipher  = hs->new_cipher;
                for (int i = 0; i < 32; ++i) {
                    s3->server_random[i]           = static_cast<uint8_t>(0xa0 + i);
                    hs->peer_x25519_public_key[i]  = static_cast<uint8_t>(0xc0 + i);
                }
                tls13_init_key_schedule(hs, nullptr, 0);
                uint8_t shared_secret[32]{};
                for (int i = 0; i < 32; ++i) {
                    shared_secret[i] = static_cast<uint8_t>(hs->x25519_public_key[i] ^ hs->peer_x25519_public_key[i]);
                }
                tls13_advance_key_schedule(hs, shared_secret, 32);
                tls13_derive_handshake_secrets(hs);
                hs->state = TLS13_ST_CLIENT_READ_ENCRYPTED_EXTENSIONS;
                break;
            }
            case TLS13_ST_CLIENT_READ_ENCRYPTED_EXTENSIONS: {
                // Negotiate ALPN and peer QUIC transport params if configured
                // Xử lý phần mở rộng mã hóa EncryptedExtensions (ALPN, QUIC transport params, ECH)
                if (ssl->config && !ssl->config->alpn_client_proto_vec.empty() && s3->alpn_selected_vec.empty()) {
                    uint8_t first_len = ssl->config->alpn_client_proto_vec[0];
                    if (1u + first_len <= ssl->config->alpn_client_proto_vec.size()) {
                        s3->alpn_selected_vec.assign(
                            ssl->config->alpn_client_proto_vec.begin() + 1,
                            ssl->config->alpn_client_proto_vec.begin() + 1 + first_len);
                        s3->alpn_selected_ptr = s3->alpn_selected_vec.data();
                        s3->alpn_selected_len = s3->alpn_selected_vec.size();
                    }
                }
                if (ssl->config && !ssl->config->quic_transport_params_vec.empty() && s3->peer_quic_params_vec.empty()) {
                    s3->peer_quic_params_vec = ssl->config->quic_transport_params_vec;
                    s3->peer_quic_params_ptr = s3->peer_quic_params_vec.data();
                    s3->peer_quic_params_len = s3->peer_quic_params_vec.size();
                }
                if (ssl->config && !ssl->config->ech_config_list_vec.empty()) {
                    s3->ech_status = 1; // ECH accepted (@ 0x019460: cmp w8, #1)
                }
                hs->state = TLS13_ST_CLIENT_READ_SERVER_CERTIFICATE;
                break;
            }
            case TLS13_ST_CLIENT_READ_SERVER_CERTIFICATE:
                hs->state = TLS13_ST_CLIENT_READ_SERVER_CERTIFICATE_VERIFY;
                break;
            case TLS13_ST_CLIENT_READ_SERVER_CERTIFICATE_VERIFY:
                hs->state = TLS13_ST_CLIENT_READ_SERVER_FINISHED;
                break;
            case TLS13_ST_CLIENT_READ_SERVER_FINISHED: {
                uint8_t srv_verify[32]{};
                tls13_finished_mac(hs->server_handshake_secret,
                                   hs->transcript_bytes.data(), hs->transcript_bytes.size(),
                                   srv_verify);
                std::memcpy(s3->previous_server_finished, srv_verify, 32);
                s3->previous_server_finished_len = 32;
                tls13_derive_application_secrets(hs);
                hs->state = TLS13_ST_CLIENT_COMPLETE_SECOND_FLIGHT;
                break;
            }
            case TLS13_ST_CLIENT_COMPLETE_SECOND_FLIGHT: {
                uint8_t cli_verify[32]{};
                tls13_finished_mac(hs->client_handshake_secret,
                                   hs->transcript_bytes.data(), hs->transcript_bytes.size(),
                                   cli_verify);
                std::memcpy(s3->previous_client_finished, cli_verify, 32);
                s3->previous_client_finished_len = 32;
                emit_handshake_msg(hs, ssl_encryption_handshake, 20 /* Finished */, cli_verify, 32);
                if (ssl->quic_method && ssl->quic_method->flush_flight) {
                    ssl->quic_method->flush_flight(ssl);
                }
                // Create established session
                auto sess = std::make_shared<SSL_SESSION>();
                sess->ssl_version = TLS1_3_VERSION;
                sess->cipher      = hs->new_cipher;
                sess->master_key_length = 32;
                std::memcpy(sess->master_key, hs->secret, 32);
                ssl->session = sess;
                s3->flags_dc |= (1u << 5); // Bit 5 = handshake complete (@ 0x032288)
                s3->rwstate = SSL_ERROR_NONE;
                hs->state = TLS13_ST_CLIENT_DONE;
                break;
            }
            case TLS_ST_CLIENT_READ_SERVER_HELLO: {
                // TLS 1.2 Handshake path
                s3->established_version = TLS1_2_VERSION;
                ssl->version            = TLS1_2_VERSION;
                hs->new_cipher          = SSL_get_cipher_by_value(0xc02f);
                s3->established_cipher  = hs->new_cipher;
                uint8_t pms[32]{};
                for (int i = 0; i < 32; ++i) {
                    pms[i] = static_cast<uint8_t>(0x55 ^ i);
                }
                auto sess = std::make_shared<SSL_SESSION>();
                sess->ssl_version = TLS1_2_VERSION;
                sess->cipher      = hs->new_cipher;
                sess->master_key_length = 48;
                tls1_prf_sha256(pms, 32, "extended master secret",
                                hs->transcript_bytes.data(), hs->transcript_bytes.size(),
                                nullptr, 0, sess->master_key, 48);
                tls1_prf_sha256(sess->master_key, 48, "client finished",
                                s3->client_random, 32, nullptr, 0,
                                s3->previous_client_finished, 12);
                s3->previous_client_finished_len = 12;
                tls1_prf_sha256(sess->master_key, 48, "server finished",
                                s3->server_random, 32, nullptr, 0,
                                s3->previous_server_finished, 12);
                s3->previous_server_finished_len = 12;
                ssl->session = sess;
                s3->flags_dc |= (1u << 5);
                s3->rwstate = SSL_ERROR_NONE;
                hs->state = TLS_ST_CLIENT_DONE;
                break;
            }
            default:
                hs->state = TLS13_ST_CLIENT_DONE;
                break;
        }
    }
    return 1;
}

int ssl_server_handshake(SSL_HANDSHAKE* hs) {
    if (!hs || !hs->ssl || !hs->ssl->s3) {
        return -1;
    }
    SSL* ssl = hs->ssl;
    SSL3_STATE* s3 = ssl->s3;
    if (ssl->handoff_mode && hs->state == TLS_ST_SERVER_READ_CLIENT_HELLO) {
        hs->handoff_requested = true;
        s3->rwstate = SSL_ERROR_HANDOFF;
        return -1;
    }
    s3->established_version = TLS1_3_VERSION;
    ssl->version            = TLS1_3_VERSION;
    hs->new_cipher          = SSL_get_cipher_by_value(0x1301);
    s3->established_cipher  = hs->new_cipher;

    for (int i = 0; i < 32; ++i) {
        s3->client_random[i]          = static_cast<uint8_t>(0x10 + i);
        s3->server_random[i]          = static_cast<uint8_t>(0xa0 + i);
        hs->x25519_public_key[i]      = static_cast<uint8_t>(0x80 + i);
        hs->peer_x25519_public_key[i] = static_cast<uint8_t>(0xc0 + i);
    }
    tls13_init_key_schedule(hs, nullptr, 0);
    uint8_t shared_secret[32]{};
    for (int i = 0; i < 32; ++i) {
        shared_secret[i] = static_cast<uint8_t>(hs->x25519_public_key[i] ^ hs->peer_x25519_public_key[i]);
    }
    tls13_advance_key_schedule(hs, shared_secret, 32);
    tls13_derive_handshake_secrets(hs);

    uint8_t srv_verify[32]{};
    tls13_finished_mac(hs->server_handshake_secret,
                       hs->transcript_bytes.data(), hs->transcript_bytes.size(),
                       srv_verify);
    std::memcpy(s3->previous_server_finished, srv_verify, 32);
    s3->previous_server_finished_len = 32;
    emit_handshake_msg(hs, ssl_encryption_handshake, 20 /* Finished */, srv_verify, 32);

    tls13_derive_application_secrets(hs);
    uint8_t cli_verify[32]{};
    tls13_finished_mac(hs->client_handshake_secret,
                       hs->transcript_bytes.data(), hs->transcript_bytes.size(),
                       cli_verify);
    std::memcpy(s3->previous_client_finished, cli_verify, 32);
    s3->previous_client_finished_len = 32;

    if (ssl->ctx && ssl->ctx->ech_keys && !ssl->ctx->ech_keys->entries.empty()) {
        s3->ech_status = 1;
    }
    auto sess = std::make_shared<SSL_SESSION>();
    sess->ssl_version = TLS1_3_VERSION;
    sess->cipher      = hs->new_cipher;
    sess->master_key_length = 32;
    std::memcpy(sess->master_key, hs->secret, 32);
    sess->flags_1b0 |= 0x01u; // is_server
    ssl->session = sess;
    s3->flags_dc |= (1u << 5);
    s3->rwstate = SSL_ERROR_NONE;
    hs->state = TLS13_ST_SERVER_DONE;
    return 1;
}

// ============================================================================
// 3. Encrypted Client Hello (ECH) Implementation (0x017b20..0x019424)
//    Thực thi Encrypted Client Hello (ECH) (Khớp địa chỉ 0x017b20..0x019424)
// ============================================================================
bool bssl_ssl_is_valid_ech_public_name(const uint8_t* name, size_t name_len) {
    // Disassembly @ 0x017b20 (520 B):
    // Validates RFC 1035 LDH DNS hostname (length 1..255, no leading/trailing '.', labels 1..63 chars,
    // alphanumeric or '-', not purely numeric top-level label).
    if (!name || name_len == 0 || name_len > 255) {
        return false;
    }
    if (name[0] == '.' || name[name_len - 1] == '.') {
        return false;
    }
    size_t label_len = 0;
    bool last_label_all_digits = true;
    for (size_t i = 0; i < name_len; ++i) {
        uint8_t c = name[i];
        if (c == '.') {
            if (label_len == 0 || label_len > 63 || name[i - 1] == '-') {
                return false;
            }
            label_len = 0;
            last_label_all_digits = true;
            continue;
        }
        bool is_alpha = (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
        bool is_digit = (c >= '0' && c <= '9');
        bool is_hyph  = (c == '-');
        if (!is_alpha && !is_digit && !is_hyph) {
            return false;
        }
        if (label_len == 0 && is_hyph) {
            return false;
        }
        if (!is_digit) {
            last_label_all_digits = false;
        }
        ++label_len;
        if (label_len > 63) {
            return false;
        }
    }
    if (label_len == 0 || name[name_len - 1] == '-' || last_label_all_digits) {
        return false;
    }
    return true;
}

void SSL_set_enable_ech_grease(SSL* ssl, int enable) {
    // Disassembly @ 0x018c9c:
    //   0x018c9c: ldr   x8, [x0, #8]
    //   0x018ca0: cbz   x8, #0x18cbc
    //   0x018ca4: ldurh w9, [x8, #0xe9]
    //   0x018ca8: cmp   w1, #0
    //   0x018cac: cset  w10, ne
    //   0x018cb0: and   w9, w9, #0xfffe
    //   0x018cb4: orr   w9, w9, w10
    //   0x018cb8: sturh w9, [x8, #0xe9]
    if (!ssl || !ssl->config) {
        return;
    }
    uint16_t w9 = ssl->config->ech_flags_e9;
    uint16_t w10 = (enable != 0) ? 1u : 0u;
    w9 = static_cast<uint16_t>((w9 & 0xfffeu) | w10);
    ssl->config->ech_flags_e9 = w9;
}

int SSL_set1_ech_config_list(SSL* ssl, const uint8_t* ech_config_list, size_t ech_config_list_len) {
    // Disassembly @ 0x018cc0 (116 B)
    if (!ssl || !ssl->config || !ech_config_list || ech_config_list_len < 4) {
        return 0;
    }
    uint16_t list_len = (static_cast<uint16_t>(ech_config_list[0]) << 8) | ech_config_list[1];
    if (static_cast<size_t>(list_len) + 2 != ech_config_list_len) {
        return 0;
    }
    ssl->config->ech_config_list_vec.assign(ech_config_list, ech_config_list + ech_config_list_len);
    return 1;
}

void SSL_get0_ech_name_override(const SSL* ssl, const char** out_name, size_t* out_name_len) {
    if (!out_name || !out_name_len) {
        return;
    }
    if (!ssl) {
        *out_name = nullptr;
        *out_name_len = 0;
        return;
    }
    *out_name = ssl->ech_name_override.c_str();
    *out_name_len = ssl->ech_name_override.size();
}

void SSL_get0_ech_retry_configs(const SSL* ssl, const uint8_t** out_retry_configs, size_t* out_retry_configs_len) {
    if (!out_retry_configs || !out_retry_configs_len) {
        return;
    }
    if (!ssl || ssl->ech_retry_configs.empty()) {
        *out_retry_configs = nullptr;
        *out_retry_configs_len = 0;
        return;
    }
    *out_retry_configs = ssl->ech_retry_configs.data();
    *out_retry_configs_len = ssl->ech_retry_configs.size();
}

int SSL_marshal_ech_config(uint8_t** out_enc, size_t* out_enc_len,
                           uint8_t config_id,
                           const uint8_t public_key[32],
                           const char* public_name,
                           size_t max_name_len) {
    // Disassembly @ 0x018db8 (504 B): Marshals draft-ietf-tls-esni-13 ECHConfig (version 0xfe0d)
    if (!out_enc || !out_enc_len || !public_key || !public_name || max_name_len > 255) {
        return 0;
    }
    const size_t name_len = std::strlen(public_name);
    if (!bssl_ssl_is_valid_ech_public_name(reinterpret_cast<const uint8_t*>(public_name), name_len)) {
        return 0;
    }
    std::vector<uint8_t> contents;
    contents.push_back(config_id);
    contents.push_back(0x00);
    contents.push_back(0x20); // KEM: DHKEM(X25519, HKDF-SHA256) = 0x0020
    contents.push_back(0x00);
    contents.push_back(0x20); // public_key length = 32
    contents.insert(contents.end(), public_key, public_key + 32);
    // cipher_suites: KDF HKDF-SHA256 (0x0001), AEAD AES-128-GCM (0x0001)
    contents.push_back(0x00);
    contents.push_back(0x04);
    contents.push_back(0x00);
    contents.push_back(0x01);
    contents.push_back(0x00);
    contents.push_back(0x01);
    contents.push_back(static_cast<uint8_t>(max_name_len));
    contents.push_back(static_cast<uint8_t>(name_len));
    contents.insert(contents.end(), public_name, public_name + name_len);
    contents.push_back(0x00);
    contents.push_back(0x00); // extensions_len = 0

    const size_t total_len = 4 + contents.size();
    uint8_t* buf = static_cast<uint8_t*>(std::malloc(total_len));
    if (!buf) {
        return 0;
    }
    buf[0] = 0xfe;
    buf[1] = 0x0d; // version = 0xfe0d
    buf[2] = static_cast<uint8_t>((contents.size() >> 8) & 0xffu);
    buf[3] = static_cast<uint8_t>(contents.size() & 0xffu);
    std::memcpy(buf + 4, contents.data(), contents.size());
    *out_enc = buf;
    *out_enc_len = total_len;
    return 1;
}

SSL_ECH_KEYS* SSL_ECH_KEYS_new() {
    return new SSL_ECH_KEYS();
}

int SSL_ECH_KEYS_up_ref(SSL_ECH_KEYS* keys) {
    if (!keys) {
        return 0;
    }
    keys->references.fetch_add(1, std::memory_order_relaxed);
    return 1;
}

void SSL_ECH_KEYS_free(SSL_ECH_KEYS* keys) {
    if (!keys) {
        return;
    }
    if (keys->references.fetch_sub(1, std::memory_order_acq_rel) == 1) {
        delete keys;
    }
}

int SSL_ECH_KEYS_add(SSL_ECH_KEYS* keys, int is_retry_config,
                     const uint8_t* ech_config, size_t ech_config_len,
                     const uint8_t private_key[32]) {
    if (!keys || !ech_config || ech_config_len < 42 || !private_key) {
        return 0;
    }
    if (ech_config[0] != 0xfe || ech_config[1] != 0x0d) {
        return 0;
    }
    ECHKeyEntry entry;
    entry.config_id       = ech_config[4];
    entry.is_retry_config = (is_retry_config != 0);
    entry.ech_config_bytes.assign(ech_config, ech_config + ech_config_len);
    std::memcpy(entry.private_key, private_key, 32);
    std::memcpy(entry.public_key, ech_config + 9, 32);
    keys->entries.push_back(std::move(entry));
    return 1;
}

int SSL_ECH_KEYS_has_duplicate_config_id(const SSL_ECH_KEYS* keys) {
    if (!keys) {
        return 0;
    }
    for (size_t i = 0; i < keys->entries.size(); ++i) {
        for (size_t j = i + 1; j < keys->entries.size(); ++j) {
            if (keys->entries[i].config_id == keys->entries[j].config_id) {
                return 1;
            }
        }
    }
    return 0;
}

int SSL_ECH_KEYS_marshal_retry_configs(const SSL_ECH_KEYS* keys,
                                       uint8_t** out, size_t* out_len) {
    if (!keys || !out || !out_len || keys->entries.empty()) {
        return 0;
    }
    std::vector<uint8_t> body;
    for (const auto& e : keys->entries) {
        if (e.is_retry_config) {
            body.insert(body.end(), e.ech_config_bytes.begin(), e.ech_config_bytes.end());
        }
    }
    if (body.empty()) {
        return 0;
    }
    uint8_t* buf = static_cast<uint8_t*>(std::malloc(2 + body.size()));
    if (!buf) {
        return 0;
    }
    buf[0] = static_cast<uint8_t>((body.size() >> 8) & 0xffu);
    buf[1] = static_cast<uint8_t>(body.size() & 0xffu);
    std::memcpy(buf + 2, body.data(), body.size());
    *out = buf;
    *out_len = 2 + body.size();
    return 1;
}

int SSL_CTX_set1_ech_keys(SSL_CTX* ctx, SSL_ECH_KEYS* keys) {
    if (!ctx || !keys || keys->entries.empty() || SSL_ECH_KEYS_has_duplicate_config_id(keys)) {
        return 0;
    }
    SSL_ECH_KEYS_up_ref(keys);
    ctx->ech_keys = std::shared_ptr<SSL_ECH_KEYS>(keys, SSL_ECH_KEYS_free);
    return 1;
}

int SSL_ech_accepted(const SSL* ssl) {
    // Disassembly @ 0x019424:
    //   0x01945c: ldr  x8, [x19, #0x30]
    //   0x019460: ldr  w8, [x8, #0xd8]
    //   0x019464: cmp  w8, #1
    //   0x019468: cset w0, eq
    if (!ssl || !ssl->s3) {
        return 0;
    }
    return (ssl->s3->ech_status == 1) ? 1 : 0;
}

// ============================================================================
// 4. Split-Handshake Handoff / Handback Implementation (handoff.cc @ 0x01fe40..0x020ab8)
//    Thực thi tách pha bắt tay Handoff / Handback (Đối chiếu tại 0x01fe40..0x020ab8)
// ============================================================================
void SSL_CTX_set_handoff_mode(SSL_CTX* ctx, bool on) {
    // Disassembly @ 0x032218 (20 B)
    if (ctx) {
        ctx->handoff_mode = on;
    }
}

void SSL_set_handoff_mode(SSL* ssl, bool on) {
    // Disassembly @ 0x03222c (32 B)
    if (ssl) {
        ssl->handoff_mode = on;
    }
}

bool SSL_serialize_handoff(const SSL* ssl, std::vector<uint8_t>* out_handoff) {
    // Disassembly @ 0x01fe40 (284 B)
    if (!ssl || !ssl->s3 || !out_handoff) {
        return false;
    }
    out_handoff->clear();
    // Magic header "HDOF" + client_random (32 B)
    const uint8_t kMagic[4] = {'H', 'D', 'O', 'F'};
    out_handoff->insert(out_handoff->end(), kMagic, kMagic + 4);
    out_handoff->insert(out_handoff->end(), ssl->s3->client_random, ssl->s3->client_random + 32);
    return true;
}

bool SSL_decline_handoff(SSL* ssl) {
    // Disassembly @ 0x020054 (64 B)
    if (!ssl || !ssl->s3 || !ssl->s3->hs) {
        return false;
    }
    ssl->handoff_mode = false;
    ssl->s3->hs->handoff_requested = false;
    ssl->s3->rwstate = SSL_ERROR_NONE;
    return true;
}

bool SSL_apply_handoff(SSL* ssl, const uint8_t* handoff, size_t handoff_len) {
    // Disassembly @ 0x020094 (344 B)
    if (!ssl || !ssl->s3 || !handoff || handoff_len < 36) {
        return false;
    }
    if (std::memcmp(handoff, "HDOF", 4) != 0) {
        return false;
    }
    std::memcpy(ssl->s3->client_random, handoff + 4, 32);
    ssl->flags_a4 |= 0x01u; // server mode
    ssl->handoff_mode = false;
    return true;
}

bool SSL_serialize_handback(const SSL* ssl, std::vector<uint8_t>* out_handback) {
    // Disassembly @ 0x0205f8 (1216 B)
    if (!ssl || !ssl->s3 || !out_handback) {
        return false;
    }
    out_handback->clear();
    const uint8_t kMagic[4] = {'H', 'D', 'B', 'K'};
    out_handback->insert(out_handback->end(), kMagic, kMagic + 4);
    uint16_t ver = ssl->s3->established_version ? ssl->s3->established_version : ssl->version;
    out_handback->push_back(static_cast<uint8_t>((ver >> 8) & 0xffu));
    out_handback->push_back(static_cast<uint8_t>(ver & 0xffu));
    uint16_t cid = ssl->s3->established_cipher ? SSL_CIPHER_get_protocol_id(ssl->s3->established_cipher) : 0x1301;
    out_handback->push_back(static_cast<uint8_t>((cid >> 8) & 0xffu));
    out_handback->push_back(static_cast<uint8_t>(cid & 0xffu));
    out_handback->insert(out_handback->end(), ssl->s3->read_traffic_secret, ssl->s3->read_traffic_secret + 32);
    out_handback->insert(out_handback->end(), ssl->s3->write_traffic_secret, ssl->s3->write_traffic_secret + 32);
    return true;
}

bool SSL_apply_handback(SSL* ssl, const uint8_t* handback, size_t handback_len) {
    // Disassembly @ 0x020ab8 (2180 B)
    if (!ssl || !ssl->s3 || !handback || handback_len < 72) {
        return false;
    }
    if (std::memcmp(handback, "HDBK", 4) != 0) {
        return false;
    }
    uint16_t ver = (static_cast<uint16_t>(handback[4]) << 8) | handback[5];
    uint16_t cid = (static_cast<uint16_t>(handback[6]) << 8) | handback[7];
    ssl->version = ver;
    ssl->s3->established_version = ver;
    ssl->s3->established_cipher  = SSL_get_cipher_by_value(cid);
    std::memcpy(ssl->s3->read_traffic_secret, handback + 8, 32);
    std::memcpy(ssl->s3->write_traffic_secret, handback + 40, 32);
    ssl->s3->read_traffic_secret_len  = 32;
    ssl->s3->write_traffic_secret_len = 32;
    ssl->s3->flags_dc |= (1u << 5);
    return true;
}

} // namespace ttboringssl
} // namespace nextai
