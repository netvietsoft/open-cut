/**
 * @file ttboringssl_ciphers_transcript.cpp
 * @brief Cleanroom C++17 Implementation of Cipher Registry, TLS 1.2 PRF & TLS 1.3 Key Schedule
 *        Triển khai C++17 cho bảng Cipher Suite, PRF TLS 1.2 và lịch trình khóa HKDF TLS 1.3
 *
 * Binary Ground Truth / Đối chứng nhị phân:
 * - SSL_get_cipher_by_value @ 0x02fae0 (108 B)
 * - SSL_CIPHER_get_id @ 0x02fb64 (4 B -> 0x030320)
 * - SSL_CIPHER_get_protocol_id @ 0x02fb68 (4 B -> 0x030320)
 * - SSL_CIPHER_get_value @ 0x02fb6c (4 B -> 0x030320)
 * - SSL_CIPHER_is_aead @ 0x02fb70 (12 B):
 *   0x02fb70: ldr  w8, [x0, #0x20]
 *   0x02fb74: ubfx w0, w8, #1, #1
 *   0x02fb78: ret
 * - SSL_CIPHER_get_cipher_nid @ 0x02fb7c (108 B):
 *   0x02fb7c: ldr  w8, [x0, #0x1c]
 *   0x02fba8: mov  w0, #0x2c   ; NID_des_ede3_cbc (44)
 *   0x02fbc0: mov  w0, #0x3b6  ; NID_chacha20_poly1305 (950)
 *   0x02fbc8: mov  w0, #0x1a3  ; NID_aes_128_cbc (419)
 *   0x02fbd0: mov  w0, #0x1ab  ; NID_aes_256_cbc (427)
 *   0x02fbd8: mov  w0, #0x37f  ; NID_aes_128_gcm (895)
 *   0x02fbe0: mov  w0, #0x385  ; NID_aes_256_gcm (901)
 * - SSL_CIPHER_get_digest_nid @ 0x02fbe8 (28 B):
 *   0x02fbe8: ldr  w8, [x0, #0x20]
 *   0x02fbec: cmp  w8, #1
 *   0x02fbf0: cset w9, eq
 *   0x02fbf4: lsl  w9, w9, #6  ; NID_sha1 = 64
 *   0x02fbf8: cmp  w8, #2
 *   0x02fbfc: csel w0, wzr, w9, eq
 * - _ZN4bssl23SSL_get_traffic_secretsEPK6ssl_stPNS_4SpanIKhEES6_ @ 0x03224c (124 B)
 */

#include "ttboringssl_ciphers_transcript.h"
#include <cstring>
#include <algorithm>

namespace nextai {
namespace ttboringssl {

namespace {

// ============================================================================
// 1. Static BoringSSL Cipher Suite Table (Matches .rodata strings in ssl_cipher.cc)
//    Bảng tĩnh các bộ mã hóa BoringSSL (Khớp toàn bộ chuỗi .rodata trong ssl_cipher.cc)
// ============================================================================
static const SSL_CIPHER kCiphers[] = {
    // Cipher 0x000a: TLS_RSA_WITH_3DES_EDE_CBC_SHA
    {
        "DES-CBC3-SHA",
        "TLS_RSA_WITH_3DES_EDE_CBC_SHA",
        0x0300000au,
        SSL_kRSA,
        SSL_aRSA,
        SSL_3DES,
        SSL_SHA1,
        SSL_HANDSHAKE_MAC_DEFAULT
    },
    // Cipher 0x002f: TLS_RSA_WITH_AES_128_CBC_SHA
    {
        "AES128-SHA",
        "TLS_RSA_WITH_AES_128_CBC_SHA",
        0x0300002fu,
        SSL_kRSA,
        SSL_aRSA,
        SSL_AES128,
        SSL_SHA1,
        SSL_HANDSHAKE_MAC_DEFAULT
    },
    // Cipher 0x0035: TLS_RSA_WITH_AES_256_CBC_SHA
    {
        "AES256-SHA",
        "TLS_RSA_WITH_AES_256_CBC_SHA",
        0x03000035u,
        SSL_kRSA,
        SSL_aRSA,
        SSL_AES256,
        SSL_SHA1,
        SSL_HANDSHAKE_MAC_DEFAULT
    },
    // Cipher 0x008c: TLS_PSK_WITH_AES_128_CBC_SHA
    {
        "PSK-AES128-CBC-SHA",
        "TLS_PSK_WITH_AES_128_CBC_SHA",
        0x0300008cu,
        SSL_kPSK,
        SSL_aPSK,
        SSL_AES128,
        SSL_SHA1,
        SSL_HANDSHAKE_MAC_DEFAULT
    },
    // Cipher 0x008d: TLS_PSK_WITH_AES_256_CBC_SHA
    {
        "PSK-AES256-CBC-SHA",
        "TLS_PSK_WITH_AES_256_CBC_SHA",
        0x0300008du,
        SSL_kPSK,
        SSL_aPSK,
        SSL_AES256,
        SSL_SHA1,
        SSL_HANDSHAKE_MAC_DEFAULT
    },
    // Cipher 0x009c: TLS_RSA_WITH_AES_128_GCM_SHA256
    {
        "AES128-GCM-SHA256",
        "TLS_RSA_WITH_AES_128_GCM_SHA256",
        0x0300009cu,
        SSL_kRSA,
        SSL_aRSA,
        SSL_AES128GCM,
        SSL_AEAD,
        SSL_HANDSHAKE_MAC_SHA256
    },
    // Cipher 0x009d: TLS_RSA_WITH_AES_256_GCM_SHA384
    {
        "AES256-GCM-SHA384",
        "TLS_RSA_WITH_AES_256_GCM_SHA384",
        0x0300009du,
        SSL_kRSA,
        SSL_aRSA,
        SSL_AES256GCM,
        SSL_AEAD,
        SSL_HANDSHAKE_MAC_SHA384
    },
    // Cipher 0x1301: TLS_AES_128_GCM_SHA256 (TLS 1.3)
    {
        "TLS_AES_128_GCM_SHA256",
        "TLS_AES_128_GCM_SHA256",
        0x03001301u,
        SSL_kGENERIC,
        SSL_aGENERIC,
        SSL_AES128GCM,
        SSL_AEAD,
        SSL_HANDSHAKE_MAC_SHA256
    },
    // Cipher 0x1302: TLS_AES_256_GCM_SHA384 (TLS 1.3)
    {
        "TLS_AES_256_GCM_SHA384",
        "TLS_AES_256_GCM_SHA384",
        0x03001302u,
        SSL_kGENERIC,
        SSL_aGENERIC,
        SSL_AES256GCM,
        SSL_AEAD,
        SSL_HANDSHAKE_MAC_SHA384
    },
    // Cipher 0x1303: TLS_CHACHA20_POLY1305_SHA256 (TLS 1.3)
    {
        "TLS_CHACHA20_POLY1305_SHA256",
        "TLS_CHACHA20_POLY1305_SHA256",
        0x03001303u,
        SSL_kGENERIC,
        SSL_aGENERIC,
        SSL_CHACHA20POLY1305,
        SSL_AEAD,
        SSL_HANDSHAKE_MAC_SHA256
    },
    // Cipher 0xc009: TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA
    {
        "ECDHE-ECDSA-AES128-SHA",
        "TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA",
        0x0300c009u,
        SSL_kECDHE,
        SSL_aECDSA,
        SSL_AES128,
        SSL_SHA1,
        SSL_HANDSHAKE_MAC_DEFAULT
    },
    // Cipher 0xc00a: TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA
    {
        "ECDHE-ECDSA-AES256-SHA",
        "TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA",
        0x0300c00au,
        SSL_kECDHE,
        SSL_aECDSA,
        SSL_AES256,
        SSL_SHA1,
        SSL_HANDSHAKE_MAC_DEFAULT
    },
    // Cipher 0xc013: TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA
    {
        "ECDHE-RSA-AES128-SHA",
        "TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA",
        0x0300c013u,
        SSL_kECDHE,
        SSL_aRSA,
        SSL_AES128,
        SSL_SHA1,
        SSL_HANDSHAKE_MAC_DEFAULT
    },
    // Cipher 0xc014: TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA
    {
        "ECDHE-RSA-AES256-SHA",
        "TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA",
        0x0300c014u,
        SSL_kECDHE,
        SSL_aRSA,
        SSL_AES256,
        SSL_SHA1,
        SSL_HANDSHAKE_MAC_DEFAULT
    },
    // Cipher 0xc02b: TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256
    {
        "ECDHE-ECDSA-AES128-GCM-SHA256",
        "TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256",
        0x0300c02bu,
        SSL_kECDHE,
        SSL_aECDSA,
        SSL_AES128GCM,
        SSL_AEAD,
        SSL_HANDSHAKE_MAC_SHA256
    },
    // Cipher 0xc02c: TLS_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384
    {
        "ECDHE-ECDSA-AES256-GCM-SHA384",
        "TLS_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384",
        0x0300c02cu,
        SSL_kECDHE,
        SSL_aECDSA,
        SSL_AES256GCM,
        SSL_AEAD,
        SSL_HANDSHAKE_MAC_SHA384
    },
    // Cipher 0xc02f: TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256
    {
        "ECDHE-RSA-AES128-GCM-SHA256",
        "TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256",
        0x0300c02fu,
        SSL_kECDHE,
        SSL_aRSA,
        SSL_AES128GCM,
        SSL_AEAD,
        SSL_HANDSHAKE_MAC_SHA256
    },
    // Cipher 0xc030: TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384
    {
        "ECDHE-RSA-AES256-GCM-SHA384",
        "TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384",
        0x0300c030u,
        SSL_kECDHE,
        SSL_aRSA,
        SSL_AES256GCM,
        SSL_AEAD,
        SSL_HANDSHAKE_MAC_SHA384
    },
    // Cipher 0xc035: TLS_ECDHE_PSK_WITH_AES_128_CBC_SHA
    {
        "ECDHE-PSK-AES128-CBC-SHA",
        "TLS_ECDHE_PSK_WITH_AES_128_CBC_SHA",
        0x0300c035u,
        SSL_kECDHE | SSL_kPSK,
        SSL_aPSK,
        SSL_AES128,
        SSL_SHA1,
        SSL_HANDSHAKE_MAC_DEFAULT
    },
    // Cipher 0xc036: TLS_ECDHE_PSK_WITH_AES_256_CBC_SHA
    {
        "ECDHE-PSK-AES256-CBC-SHA",
        "TLS_ECDHE_PSK_WITH_AES_256_CBC_SHA",
        0x0300c036u,
        SSL_kECDHE | SSL_kPSK,
        SSL_aPSK,
        SSL_AES256,
        SSL_SHA1,
        SSL_HANDSHAKE_MAC_DEFAULT
    },
    // Cipher 0xcca8: TLS_ECDHE_RSA_WITH_CHACHA20_POLY1305_SHA256
    {
        "ECDHE-RSA-CHACHA20-POLY1305",
        "TLS_ECDHE_RSA_WITH_CHACHA20_POLY1305_SHA256",
        0x0300cca8u,
        SSL_kECDHE,
        SSL_aRSA,
        SSL_CHACHA20POLY1305,
        SSL_AEAD,
        SSL_HANDSHAKE_MAC_SHA256
    },
    // Cipher 0xcca9: TLS_ECDHE_ECDSA_WITH_CHACHA20_POLY1305_SHA256
    {
        "ECDHE-ECDSA-CHACHA20-POLY1305",
        "TLS_ECDHE_ECDSA_WITH_CHACHA20_POLY1305_SHA256",
        0x0300cca9u,
        SSL_kECDHE,
        SSL_aECDSA,
        SSL_CHACHA20POLY1305,
        SSL_AEAD,
        SSL_HANDSHAKE_MAC_SHA256
    },
    // Cipher 0xccac: TLS_ECDHE_PSK_WITH_CHACHA20_POLY1305_SHA256
    {
        "ECDHE-PSK-CHACHA20-POLY1305",
        "TLS_ECDHE_PSK_WITH_CHACHA20_POLY1305_SHA256",
        0x0300ccacu,
        SSL_kECDHE | SSL_kPSK,
        SSL_aPSK,
        SSL_CHACHA20POLY1305,
        SSL_AEAD,
        SSL_HANDSHAKE_MAC_SHA256
    }
};

// FIPS 180-4 SHA-256 Round Constants
// Hằng số vòng SHA-256 chuẩn FIPS 180-4
static const uint32_t kSha256K[64] = {
    0x428a2f98u, 0x71374491u, 0xb5c0fbcfu, 0xe9b5dba5u,
    0x3956c25bu, 0x59f111f1u, 0x923f82a4u, 0xab1c5ed5u,
    0xd807aa98u, 0x12835b01u, 0x243185beu, 0x550c7dc3u,
    0x72be5d74u, 0x80deb1feu, 0x9bdc06a7u, 0xc19bf174u,
    0xe49b69c1u, 0xefbe4786u, 0x0fc19dc6u, 0x240ca1ccu,
    0x2de92c6fu, 0x4a7484aau, 0x5cb0a9dcu, 0x76f988dau,
    0x983e5152u, 0xa831c66du, 0xb00327c8u, 0xbf597fc7u,
    0xc6e00bf3u, 0xd5a79147u, 0x06ca6351u, 0x14292967u,
    0x27b70a85u, 0x2e1b2138u, 0x4d2c6dfcU, 0x53380d13u,
    0x650a7354u, 0x766a0abbu, 0x81c2c92eu, 0x92722c85u,
    0xa2bfe8a1u, 0xa81a664bu, 0xc24b8b70u, 0xc76c51a3u,
    0xd192e819u, 0xd6990624u, 0xf40e3585u, 0x106aa070u,
    0x19a4c116u, 0x1e376c08u, 0x2748774cu, 0x34b0bcb5u,
    0x391c0cb3u, 0x4ed8aa4au, 0x5b9cca4fu, 0x682e6ff3u,
    0x748f82eeu, 0x78a5636fu, 0x84c87814u, 0x8cc70208u,
    0x90befffaU, 0xa4506cebu, 0xbef9a3f7u, 0xc67178f2u
};

inline uint32_t rotr32(uint32_t x, uint32_t n) {
    return (x >> n) | (x << (32u - n));
}

} // namespace

// ============================================================================
// 2. Cipher Suite Lookup & Accessors (0x02fae0..0x02fc44)
//    Thực thi các hàm tra cứu và truy xuất Cipher Suite (0x02fae0..0x02fc44)
// ============================================================================
const SSL_CIPHER* SSL_get_cipher_by_value(uint16_t value) {
    // Binary search in kCiphers by lower 16 bits of id (0x03000000 | value)
    // Tìm kiếm nhị phân trong bảng kCiphers theo 16 bit thấp của id
    const uint32_t target_id = 0x03000000u | static_cast<uint32_t>(value);
    for (const auto& c : kCiphers) {
        if (c.id == target_id) {
            return &c;
        }
    }
    return nullptr;
}

uint32_t SSL_CIPHER_get_id(const SSL_CIPHER* cipher) {
    return cipher ? cipher->id : 0u;
}

uint16_t SSL_CIPHER_get_protocol_id(const SSL_CIPHER* cipher) {
    // @ 0x02fb68 -> 0x030320: returns uint16_t(cipher->id & 0xffff)
    // Trả về 16 bit thấp của cipher->id (mã giao thức IANA)
    return cipher ? static_cast<uint16_t>(cipher->id & 0xffffu) : 0u;
}

uint16_t SSL_CIPHER_get_value(const SSL_CIPHER* cipher) {
    return SSL_CIPHER_get_protocol_id(cipher);
}

int SSL_CIPHER_is_aead(const SSL_CIPHER* cipher) {
    // Disassembly @ 0x02fb70:
    //   ldr  w8, [x0, #0x20]
    //   ubfx w0, w8, #1, #1
    //   ret
    if (!cipher) {
        return 0;
    }
    return static_cast<int>((cipher->algorithm_mac >> 1) & 1u);
}

int SSL_CIPHER_get_cipher_nid(const SSL_CIPHER* cipher) {
    // Disassembly @ 0x02fb7c:
    //   ldr w8, [x0, #0x1c]
    //   Maps SSL_3DES(1)->0x2c, SSL_AES128(2)->0x1a3, SSL_AES256(4)->0x1ab,
    //   SSL_AES128GCM(8)->0x37f, SSL_AES256GCM(0x10)->0x385, SSL_CHACHA20POLY1305(0x40)->0x3b6
    if (!cipher) {
        return NID_undef;
    }
    switch (cipher->algorithm_enc) {
        case SSL_3DES:             return NID_des_ede3_cbc;      // 0x2c  (44)
        case SSL_AES128:           return NID_aes_128_cbc;       // 0x1a3 (419)
        case SSL_AES256:           return NID_aes_256_cbc;       // 0x1ab (427)
        case SSL_AES128GCM:        return NID_aes_128_gcm;       // 0x37f (895)
        case SSL_AES256GCM:        return NID_aes_256_gcm;       // 0x385 (901)
        case SSL_CHACHA20POLY1305: return NID_chacha20_poly1305; // 0x3b6 (950)
        default:                   return NID_undef;
    }
}

int SSL_CIPHER_get_digest_nid(const SSL_CIPHER* cipher) {
    // Disassembly @ 0x02fbe8:
    //   ldr  w8, [x0, #0x20]
    //   cmp  w8, #1
    //   cset w9, eq
    //   lsl  w9, w9, #6
    //   cmp  w8, #2
    //   csel w0, wzr, w9, eq
    //   ret
    if (!cipher) {
        return NID_undef;
    }
    if (cipher->algorithm_mac == SSL_AEAD) {
        return NID_undef; // 0
    }
    if (cipher->algorithm_mac == SSL_SHA1) {
        return NID_sha1;  // 1 << 6 = 64
    }
    return NID_undef;
}

int SSL_CIPHER_get_kx_nid(const SSL_CIPHER* cipher) {
    // Disassembly @ 0x02fc04
    if (!cipher) {
        return NID_undef;
    }
    switch (cipher->algorithm_mkey) {
        case SSL_kRSA:              return NID_kx_rsa;
        case SSL_kECDHE:            return NID_kx_ecdhe;
        case SSL_kPSK:              return NID_kx_psk;
        case SSL_kECDHE | SSL_kPSK: return NID_kx_ecdhe_psk;
        case SSL_kGENERIC:          return NID_kx_any;
        default:                    return NID_undef;
    }
}

int SSL_CIPHER_get_auth_nid(const SSL_CIPHER* cipher) {
    // Disassembly @ 0x02fc24
    if (!cipher) {
        return NID_undef;
    }
    switch (cipher->algorithm_auth) {
        case SSL_aRSA:     return NID_auth_rsa;
        case SSL_aECDSA:   return NID_auth_ecdsa;
        case SSL_aPSK:     return NID_auth_psk;
        case SSL_aGENERIC: return NID_auth_any;
        default:           return NID_undef;
    }
}

int SSL_CIPHER_get_prf_nid(const SSL_CIPHER* cipher) {
    // Disassembly @ 0x02fc44
    if (!cipher) {
        return NID_undef;
    }
    switch (cipher->algorithm_prf) {
        case SSL_HANDSHAKE_MAC_DEFAULT: return NID_md5_sha1;
        case SSL_HANDSHAKE_MAC_SHA256:  return NID_sha256;
        case SSL_HANDSHAKE_MAC_SHA384:  return NID_sha384;
        default:                        return NID_undef;
    }
}

const char* SSL_CIPHER_get_name(const SSL_CIPHER* cipher) {
    return cipher ? cipher->name : "(NONE)";
}

const char* SSL_CIPHER_standard_name(const SSL_CIPHER* cipher) {
    return cipher ? cipher->standard_name : "(NONE)";
}

int SSL_CTX_set_strict_cipher_list(SSL_CTX* ctx, const char* str) {
    // Disassembly @ 0x032614: parses colon-separated cipher list string
    // Phân tích chuỗi danh sách cipher phân tách bởi dấu ':' hoặc từ khóa DEFAULT / HIGH / AEAD
    if (!ctx || !str || str[0] == '\0') {
        return 0;
    }
    ctx->cipher_list.clear();
    std::string spec(str);
    size_t pos = 0;
    while (pos <= spec.size()) {
        size_t next = spec.find(':', pos);
        std::string token = (next == std::string::npos) ? spec.substr(pos) : spec.substr(pos, next - pos);
        if (!token.empty()) {
            bool matched_any = false;
            for (const auto& c : kCiphers) {
                bool match = (token == "DEFAULT" || token == "ALL" || token == "HIGH" ||
                              token == c.name || token == c.standard_name ||
                              (token == "AEAD" && SSL_CIPHER_is_aead(&c)));
                if (match) {
                    if (std::find(ctx->cipher_list.begin(), ctx->cipher_list.end(), &c) == ctx->cipher_list.end()) {
                        ctx->cipher_list.push_back(&c);
                    }
                    matched_any = true;
                }
            }
            if (!matched_any) {
                return 0;
            }
        }
        if (next == std::string::npos) {
            break;
        }
        pos = next + 1;
    }
    return ctx->cipher_list.empty() ? 0 : 1;
}

const char* SSL_get_curve_name(uint16_t curve_id) {
    // Disassembly @ 0x031290 (ssl_key_share.cc .rodata strings: P-224, P-256, P-384, P-521, X25519, CECPQ2)
    switch (curve_id) {
        case 21:     return "P-224";
        case 23:     return "P-256";
        case 24:     return "P-384";
        case 25:     return "P-521";
        case 29:     return "X25519";
        case 0x419b: return "CECPQ2";
        default:     return nullptr;
    }
}

// ============================================================================
// 3. SHA-256, HMAC-SHA256 & HKDF-Expand-Label (tls13_enc.cc & ssl_transcript.cc)
//    Thực thi SHA-256, HMAC-SHA256 và HKDF-Expand-Label chuẩn RFC 8446
// ============================================================================
void sha256_digest(const uint8_t* data, size_t len, uint8_t out_digest[32]) {
    uint32_t h[8] = {
        0x6a09e667u, 0xbb67ae85u, 0x3c6ef372u, 0xa54ff53au,
        0x510e527fu, 0x9b05688cu, 0x1f83d9abu, 0x5be0cd19u
    };
    size_t padded_len = ((len + 9 + 63) / 64) * 64;
    std::vector<uint8_t> buf(padded_len, 0);
    if (len > 0 && data != nullptr) {
        std::memcpy(buf.data(), data, len);
    }
    buf[len] = 0x80u;
    uint64_t bit_len = static_cast<uint64_t>(len) * 8u;
    for (int i = 0; i < 8; ++i) {
        buf[padded_len - 1 - i] = static_cast<uint8_t>((bit_len >> (i * 8)) & 0xffu);
    }

    for (size_t chunk = 0; chunk < padded_len; chunk += 64) {
        uint32_t w[64]{};
        for (int i = 0; i < 16; ++i) {
            const uint8_t* p = buf.data() + chunk + i * 4;
            w[i] = (static_cast<uint32_t>(p[0]) << 24) |
                   (static_cast<uint32_t>(p[1]) << 16) |
                   (static_cast<uint32_t>(p[2]) << 8)  |
                   static_cast<uint32_t>(p[3]);
        }
        for (int i = 16; i < 64; ++i) {
            uint32_t s0 = rotr32(w[i - 15], 7) ^ rotr32(w[i - 15], 18) ^ (w[i - 15] >> 3);
            uint32_t s1 = rotr32(w[i - 2], 17) ^ rotr32(w[i - 2], 19) ^ (w[i - 2] >> 10);
            w[i] = w[i - 16] + s0 + w[i - 7] + s1;
        }
        uint32_t a = h[0], b = h[1], c = h[2], d = h[3];
        uint32_t e = h[4], f = h[5], g = h[6], hh = h[7];
        for (int i = 0; i < 64; ++i) {
            uint32_t S1 = rotr32(e, 6) ^ rotr32(e, 11) ^ rotr32(e, 25);
            uint32_t ch = (e & f) ^ ((~e) & g);
            uint32_t temp1 = hh + S1 + ch + kSha256K[i] + w[i];
            uint32_t S0 = rotr32(a, 2) ^ rotr32(a, 13) ^ rotr32(a, 22);
            uint32_t maj = (a & b) ^ (a & c) ^ (b & c);
            uint32_t temp2 = S0 + maj;
            hh = g;
            g = f;
            f = e;
            e = d + temp1;
            d = c;
            c = b;
            b = a;
            a = temp1 + temp2;
        }
        h[0] += a; h[1] += b; h[2] += c; h[3] += d;
        h[4] += e; h[5] += f; h[6] += g; h[7] += hh;
    }

    for (int i = 0; i < 8; ++i) {
        out_digest[i * 4 + 0] = static_cast<uint8_t>((h[i] >> 24) & 0xffu);
        out_digest[i * 4 + 1] = static_cast<uint8_t>((h[i] >> 16) & 0xffu);
        out_digest[i * 4 + 2] = static_cast<uint8_t>((h[i] >> 8) & 0xffu);
        out_digest[i * 4 + 3] = static_cast<uint8_t>(h[i] & 0xffu);
    }
}

void hmac_sha256_compute(const uint8_t* key, size_t key_len,
                         const uint8_t* data, size_t data_len,
                         uint8_t out_mac[32]) {
    uint8_t k_block[64]{};
    if (key_len > 64) {
        sha256_digest(key, key_len, k_block);
    } else if (key_len > 0 && key != nullptr) {
        std::memcpy(k_block, key, key_len);
    }
    uint8_t ipad[64]{};
    uint8_t opad[64]{};
    for (int i = 0; i < 64; ++i) {
        ipad[i] = k_block[i] ^ 0x36u;
        opad[i] = k_block[i] ^ 0x5cu;
    }
    std::vector<uint8_t> inner(64 + data_len);
    std::memcpy(inner.data(), ipad, 64);
    if (data_len > 0 && data != nullptr) {
        std::memcpy(inner.data() + 64, data, data_len);
    }
    uint8_t inner_hash[32]{};
    sha256_digest(inner.data(), inner.size(), inner_hash);

    uint8_t outer[64 + 32]{};
    std::memcpy(outer, opad, 64);
    std::memcpy(outer + 64, inner_hash, 32);
    sha256_digest(outer, sizeof(outer), out_mac);
}

void hkdf_extract_sha256(const uint8_t* salt, size_t salt_len,
                         const uint8_t* ikm, size_t ikm_len,
                         uint8_t out_prk[32]) {
    uint8_t zero_salt[32]{};
    if (!salt || salt_len == 0) {
        salt = zero_salt;
        salt_len = 32;
    }
    hmac_sha256_compute(salt, salt_len, ikm, ikm_len, out_prk);
}

bool hkdf_expand_label_sha256(const uint8_t* secret, size_t secret_len,
                              const char* label,
                              const uint8_t* context, size_t context_len,
                              uint8_t* out, size_t out_len) {
    // Matches .rodata string "tls13 " in tls13_enc.cc!
    // Structure of HkdfLabel (RFC 8446 Section 7.1):
    //   uint16 length = out_len;
    //   opaque label<7..255> = "tls13 " + label;
    //   opaque context<0..255> = context;
    if (!secret || !label || !out || out_len == 0 || out_len > 255 * 32) {
        return false;
    }
    const size_t label_len = std::strlen(label);
    const size_t full_label_len = 6 + label_len; // "tls13 " is 6 bytes
    if (full_label_len > 255 || context_len > 255) {
        return false;
    }
    std::vector<uint8_t> hkdf_label;
    hkdf_label.reserve(2 + 1 + full_label_len + 1 + context_len);
    hkdf_label.push_back(static_cast<uint8_t>((out_len >> 8) & 0xffu));
    hkdf_label.push_back(static_cast<uint8_t>(out_len & 0xffu));
    hkdf_label.push_back(static_cast<uint8_t>(full_label_len));
    const char* kPrefix = "tls13 ";
    hkdf_label.insert(hkdf_label.end(), kPrefix, kPrefix + 6);
    hkdf_label.insert(hkdf_label.end(), label, label + label_len);
    hkdf_label.push_back(static_cast<uint8_t>(context_len));
    if (context_len > 0 && context != nullptr) {
        hkdf_label.insert(hkdf_label.end(), context, context + context_len);
    }

    uint8_t prev_block[32]{};
    size_t generated = 0;
    uint8_t counter = 1;
    while (generated < out_len) {
        std::vector<uint8_t> info_input;
        if (counter > 1) {
            info_input.insert(info_input.end(), prev_block, prev_block + 32);
        }
        info_input.insert(info_input.end(), hkdf_label.begin(), hkdf_label.end());
        info_input.push_back(counter);
        hmac_sha256_compute(secret, secret_len, info_input.data(), info_input.size(), prev_block);
        size_t copy_len = std::min<size_t>(32, out_len - generated);
        std::memcpy(out + generated, prev_block, copy_len);
        generated += copy_len;
        ++counter;
    }
    return true;
}

bool tls13_derive_secret_sha256(const uint8_t secret[32],
                                const char* label,
                                const uint8_t* transcript_bytes,
                                size_t transcript_len,
                                uint8_t out_secret[32]) {
    uint8_t transcript_hash[32]{};
    sha256_digest(transcript_bytes, transcript_len, transcript_hash);
    return hkdf_expand_label_sha256(secret, 32, label, transcript_hash, 32, out_secret, 32);
}

bool tls13_init_key_schedule(SSL_HANDSHAKE* hs, const uint8_t* psk, size_t psk_len) {
    if (!hs) {
        return false;
    }
    hs->hash_len = 32;
    uint8_t zero_ikm[32]{};
    if (!psk || psk_len == 0) {
        psk = zero_ikm;
        psk_len = 32;
    }
    hkdf_extract_sha256(nullptr, 0, psk, psk_len, hs->secret);
    return true;
}

bool tls13_advance_key_schedule(SSL_HANDSHAKE* hs, const uint8_t* ikm, size_t ikm_len) {
    // Derives "derived" with empty transcript, then HKDF-Extract(derived_secret, ikm)
    // Sinh khóa trung gian "derived" với transcript rỗng, sau đó HKDF-Extract với IKM mới
    if (!hs || !ikm || ikm_len == 0) {
        return false;
    }
    uint8_t derived_secret[32]{};
    if (!tls13_derive_secret_sha256(hs->secret, "derived", nullptr, 0, derived_secret)) {
        return false;
    }
    hkdf_extract_sha256(derived_secret, 32, ikm, ikm_len, hs->secret);
    return true;
}

bool tls13_derive_early_secret(SSL_HANDSHAKE* hs) {
    // Matches .rodata string "c e traffic" in tls13_enc.cc
    if (!hs) {
        return false;
    }
    return tls13_derive_secret_sha256(
        hs->secret, "c e traffic",
        hs->transcript_bytes.data(), hs->transcript_bytes.size(),
        hs->early_traffic_secret);
}

bool tls13_derive_handshake_secrets(SSL_HANDSHAKE* hs) {
    // Matches .rodata strings "c hs traffic" and "s hs traffic" in tls13_enc.cc
    if (!hs || !hs->ssl || !hs->ssl->s3) {
        return false;
    }
    if (!tls13_derive_secret_sha256(
            hs->secret, "c hs traffic",
            hs->transcript_bytes.data(), hs->transcript_bytes.size(),
            hs->client_handshake_secret)) {
        return false;
    }
    if (!tls13_derive_secret_sha256(
            hs->secret, "s hs traffic",
            hs->transcript_bytes.data(), hs->transcript_bytes.size(),
            hs->server_handshake_secret)) {
        return false;
    }
    SSL* ssl = hs->ssl;
    SSL3_STATE* s3 = ssl->s3;
    const bool is_server = (ssl->flags_a4 & 0x01u) != 0;
    const uint8_t* read_sec  = is_server ? hs->client_handshake_secret : hs->server_handshake_secret;
    const uint8_t* write_sec = is_server ? hs->server_handshake_secret : hs->client_handshake_secret;
    std::memcpy(s3->read_traffic_secret, read_sec, 32);
    std::memcpy(s3->write_traffic_secret, write_sec, 32);
    s3->read_traffic_secret_len  = 32;
    s3->write_traffic_secret_len = 32;
    s3->quic_read_level  = ssl_encryption_handshake;
    s3->quic_write_level = ssl_encryption_handshake;
    if (ssl->quic_method) {
        const SSL_CIPHER* cipher = hs->new_cipher ? hs->new_cipher : SSL_get_cipher_by_value(0x1301);
        if (ssl->quic_method->set_read_secret) {
            ssl->quic_method->set_read_secret(ssl, ssl_encryption_handshake, cipher, read_sec, 32);
        }
        if (ssl->quic_method->set_write_secret) {
            ssl->quic_method->set_write_secret(ssl, ssl_encryption_handshake, cipher, write_sec, 32);
        }
    }
    return true;
}

bool tls13_derive_application_secrets(SSL_HANDSHAKE* hs) {
    // Matches .rodata strings "c ap traffic", "s ap traffic", "exp master" in tls13_enc.cc
    if (!hs || !hs->ssl || !hs->ssl->s3) {
        return false;
    }
    uint8_t zero_ikm[32]{};
    if (!tls13_advance_key_schedule(hs, zero_ikm, 32)) {
        return false;
    }
    if (!tls13_derive_secret_sha256(
            hs->secret, "c ap traffic",
            hs->transcript_bytes.data(), hs->transcript_bytes.size(),
            hs->client_traffic_secret_0)) {
        return false;
    }
    if (!tls13_derive_secret_sha256(
            hs->secret, "s ap traffic",
            hs->transcript_bytes.data(), hs->transcript_bytes.size(),
            hs->server_traffic_secret_0)) {
        return false;
    }
    SSL* ssl = hs->ssl;
    SSL3_STATE* s3 = ssl->s3;
    if (!tls13_derive_secret_sha256(
            hs->secret, "exp master",
            hs->transcript_bytes.data(), hs->transcript_bytes.size(),
            s3->exporter_secret)) {
        return false;
    }
    s3->exporter_secret_len = 32;
    const bool is_server = (ssl->flags_a4 & 0x01u) != 0;
    const uint8_t* read_sec  = is_server ? hs->client_traffic_secret_0 : hs->server_traffic_secret_0;
    const uint8_t* write_sec = is_server ? hs->server_traffic_secret_0 : hs->client_traffic_secret_0;
    std::memcpy(s3->read_traffic_secret, read_sec, 32);
    std::memcpy(s3->write_traffic_secret, write_sec, 32);
    s3->read_traffic_secret_len  = 32;
    s3->write_traffic_secret_len = 32;
    s3->quic_read_level  = ssl_encryption_application;
    s3->quic_write_level = ssl_encryption_application;
    if (ssl->quic_method) {
        const SSL_CIPHER* cipher = hs->new_cipher ? hs->new_cipher : SSL_get_cipher_by_value(0x1301);
        if (ssl->quic_method->set_read_secret) {
            ssl->quic_method->set_read_secret(ssl, ssl_encryption_application, cipher, read_sec, 32);
        }
        if (ssl->quic_method->set_write_secret) {
            ssl->quic_method->set_write_secret(ssl, ssl_encryption_application, cipher, write_sec, 32);
        }
    }
    return true;
}

bool tls13_finished_mac(const uint8_t base_key[32],
                        const uint8_t* transcript_bytes,
                        size_t transcript_len,
                        uint8_t out_verify_data[32]) {
    // Matches .rodata string "finished" in tls13_enc.cc (RFC 8446 Section 4.4.4)
    uint8_t finished_key[32]{};
    if (!hkdf_expand_label_sha256(base_key, 32, "finished", nullptr, 0, finished_key, 32)) {
        return false;
    }
    uint8_t transcript_hash[32]{};
    sha256_digest(transcript_bytes, transcript_len, transcript_hash);
    hmac_sha256_compute(finished_key, 32, transcript_hash, 32, out_verify_data);
    return true;
}

// ============================================================================
// 4. TLS 1.2 PRF (t1_enc.cc @ .rodata "master secret", "key expansion")
//    Hàm PRF TLS 1.2 dựa trên HMAC-SHA256 (RFC 5246 Section 5)
// ============================================================================
bool tls1_prf_sha256(const uint8_t* secret, size_t secret_len,
                     const char* label,
                     const uint8_t* seed1, size_t seed1_len,
                     const uint8_t* seed2, size_t seed2_len,
                     uint8_t* out, size_t out_len) {
    if (!secret || !label || !out || out_len == 0) {
        return false;
    }
    const size_t label_len = std::strlen(label);
    std::vector<uint8_t> seed(label_len + seed1_len + seed2_len);
    std::memcpy(seed.data(), label, label_len);
    if (seed1_len > 0 && seed1 != nullptr) {
        std::memcpy(seed.data() + label_len, seed1, seed1_len);
    }
    if (seed2_len > 0 && seed2 != nullptr) {
        std::memcpy(seed.data() + label_len + seed1_len, seed2, seed2_len);
    }

    uint8_t a_block[32]{};
    // A(1) = HMAC(secret, seed)
    hmac_sha256_compute(secret, secret_len, seed.data(), seed.size(), a_block);

    size_t generated = 0;
    while (generated < out_len) {
        std::vector<uint8_t> hmac_in(32 + seed.size());
        std::memcpy(hmac_in.data(), a_block, 32);
        std::memcpy(hmac_in.data() + 32, seed.data(), seed.size());
        uint8_t p_block[32]{};
        hmac_sha256_compute(secret, secret_len, hmac_in.data(), hmac_in.size(), p_block);
        size_t copy_len = std::min<size_t>(32, out_len - generated);
        std::memcpy(out + generated, p_block, copy_len);
        generated += copy_len;
        // A(i+1) = HMAC(secret, A(i))
        uint8_t next_a[32]{};
        hmac_sha256_compute(secret, secret_len, a_block, 32, next_a);
        std::memcpy(a_block, next_a, 32);
    }
    return true;
}

// ============================================================================
// 5. bssl::SSL_get_traffic_secrets (@ 0x03224c, 124 B)
//    Trích xuất khóa traffic đọc/ghi từ s3 (+0x120 / +0x150) khi version > 0x0303
// ============================================================================
bool bssl_SSL_get_traffic_secrets(const SSL* ssl,
                                  const uint8_t** out_read_traffic_secret,
                                  size_t* out_read_secret_len,
                                  const uint8_t** out_write_traffic_secret,
                                  size_t* out_write_secret_len) {
    // Disassembly @ 0x03224c:
    //   0x03226c: cmp  w0, #0x303          ; require TLS 1.3 (> 0x0303)
    //   0x032270: b.gt #0x32280
    //   0x032280: ldr  x8, [x20, #0x30]    ; s3 = ssl->s3
    //   0x032284: ldrb w9, [x8, #0xdc]     ; s3->flags_dc
    //   0x032288: tbnz w9, #5, #0x322a0    ; require bit 5 (handshake complete)
    //   0x0322a0: ldrb w9, [x8, #0x1b1]    ; read_traffic_secret_len
    //   0x0322a4: add  x8, x8, #0x150      ; read_traffic_secret
    //   0x0322b4: ldrb w9, [x8, #0x1b0]    ; write_traffic_secret_len
    //   0x0322b8: add  x8, x8, #0x120      ; write_traffic_secret
    if (!ssl || !ssl->s3 || !out_read_traffic_secret || !out_read_secret_len ||
        !out_write_traffic_secret || !out_write_secret_len) {
        return false;
    }
    const uint16_t ver = ssl->s3->established_version ? ssl->s3->established_version : ssl->version;
    if (ver <= TLS1_2_VERSION) {
        return false;
    }
    const SSL3_STATE* s3 = ssl->s3;
    if ((s3->flags_dc & (1u << 5)) == 0) {
        return false;
    }
    *out_read_traffic_secret  = s3->read_traffic_secret;
    *out_read_secret_len      = s3->read_traffic_secret_len;
    *out_write_traffic_secret = s3->write_traffic_secret;
    *out_write_secret_len     = s3->write_traffic_secret_len;
    return true;
}

} // namespace ttboringssl
} // namespace nextai
