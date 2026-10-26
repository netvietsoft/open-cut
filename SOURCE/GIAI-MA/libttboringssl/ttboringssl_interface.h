/**
 * @file ttboringssl_interface.h
 * @brief Public Cleanroom C/C++17 Facade & Verification Suite for libttboringssl.so
 *        Giao diện C/C++17 công khai và bộ kiểm thử tự động cho libttboringssl.so
 *
 * Binary Ground Truth / Đối chứng nhị phân:
 * - Library: SOURCE/apktool-res/lib/arm64-v8a/libttboringssl.so (395,304 bytes)
 * - Exported Functions: 558 functions (.text 0x014a20..0x0447e8)
 */

#ifndef NEXTAI_OPENCUT_TTBORINGSSL_INTERFACE_H
#define NEXTAI_OPENCUT_TTBORINGSSL_INTERFACE_H

#include "ttboringssl_types.h"
#include "ttboringssl_ciphers_transcript.h"
#include "ttboringssl_handshake_tls13.h"
#include "ttboringssl_quic_dtls_alpn.h"
#include "ttboringssl_session_bio_api.h"

namespace nextai {
namespace ttboringssl {

/**
 * @brief Run all mathematical, ABI struct offset, handshake, QUIC, DTLS, ALPN/SNI, ECH & Session self-tests.
 *        Chạy toàn bộ bài kiểm thử toán học, offset ABI, bắt tay TLS 1.3, QUIC, DTLS, ALPN/SNI, ECH và Session.
 * @return true if 100% of self-tests pass, false otherwise.
 *         trả về true nếu 100% bài kiểm thử đạt, ngược lại trả về false.
 */
bool verify_ttboringssl_all();

} // namespace ttboringssl
} // namespace nextai

#endif // NEXTAI_OPENCUT_TTBORINGSSL_INTERFACE_H
