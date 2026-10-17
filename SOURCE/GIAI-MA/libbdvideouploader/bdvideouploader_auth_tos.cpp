/**
 * @file bdvideouploader_auth_tos.cpp
 * @brief ByteDance Video Uploader - AWS S3 & ByteDance TOS Authentication Implementations.
 *        Cài đặt chi tiết thuật toán băm SHA256, HMAC-SHA256 và chữ ký số AWS SigV4.
 *
 * Rules: AGENTS.md Rule 12 (Bilingual EN/VN), Rule 14 & 20 (Zero stubs, exact binary parity).
 */

#include "bdvideouploader_auth_tos.h"
#include <iomanip>
#include <sstream>
#include <cstring>
#include <algorithm>

namespace com {
namespace ss {
namespace bduploader {

// ----------------------------------------------------------------------------
// Standalone Cryptographic SHA-256 Engine
// ----------------------------------------------------------------------------
static inline uint32_t ror(uint32_t val, uint32_t shift) {
    return (val >> shift) | (val << (32 - shift));
}

static const uint32_t K256[64] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

void BDAuthHelper::sha256Transform(uint32_t state[8], const uint8_t block[64]) {
    uint32_t w[64];
    for (int i = 0; i < 16; ++i) {
        w[i] = (static_cast<uint32_t>(block[i * 4]) << 24) |
               (static_cast<uint32_t>(block[i * 4 + 1]) << 16) |
               (static_cast<uint32_t>(block[i * 4 + 2]) << 8) |
               (static_cast<uint32_t>(block[i * 4 + 3]));
    }
    for (int i = 16; i < 64; ++i) {
        uint32_t s0 = ror(w[i - 15], 7) ^ ror(w[i - 15], 18) ^ (w[i - 15] >> 3);
        uint32_t s1 = ror(w[i - 2], 17) ^ ror(w[i - 2], 19) ^ (w[i - 2] >> 10);
        w[i] = w[i - 16] + s0 + w[i - 7] + s1;
    }

    uint32_t a = state[0], b = state[1], c = state[2], d = state[3];
    uint32_t e = state[4], f = state[5], g = state[6], h = state[7];

    for (int i = 0; i < 64; ++i) {
        uint32_t S1 = ror(e, 6) ^ ror(e, 11) ^ ror(e, 25);
        uint32_t ch = (e & f) ^ ((~e) & g);
        uint32_t temp1 = h + S1 + ch + K256[i] + w[i];
        uint32_t S0 = ror(a, 2) ^ ror(a, 13) ^ ror(a, 22);
        uint32_t maj = (a & b) ^ (a & c) ^ (b & c);
        uint32_t temp2 = S0 + maj;

        h = g;
        g = f;
        f = e;
        e = d + temp1;
        d = c;
        c = b;
        b = a;
        a = temp1 + temp2;
    }

    state[0] += a; state[1] += b; state[2] += c; state[3] += d;
    state[4] += e; state[5] += f; state[6] += g; state[7] += h;
}

void BDAuthHelper::sha256Hash(const uint8_t* data, size_t len, uint8_t digest[32]) {
    uint32_t state[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };

    uint8_t buffer[64];
    size_t offset = 0;
    while (offset + 64 <= len) {
        sha256Transform(state, data + offset);
        offset += 64;
    }

    size_t rem = len - offset;
    std::memcpy(buffer, data + offset, rem);
    buffer[rem] = 0x80;
    if (rem + 1 > 56) {
        std::memset(buffer + rem + 1, 0, 64 - rem - 1);
        sha256Transform(state, buffer);
        std::memset(buffer, 0, 56);
    } else {
        std::memset(buffer + rem + 1, 0, 56 - rem - 1);
    }

    uint64_t bitLen = static_cast<uint64_t>(len) * 8;
    for (int i = 0; i < 8; ++i) {
        buffer[63 - i] = static_cast<uint8_t>(bitLen >> (i * 8));
    }
    sha256Transform(state, buffer);

    for (int i = 0; i < 8; ++i) {
        digest[i * 4]     = static_cast<uint8_t>(state[i] >> 24);
        digest[i * 4 + 1] = static_cast<uint8_t>(state[i] >> 16);
        digest[i * 4 + 2] = static_cast<uint8_t>(state[i] >> 8);
        digest[i * 4 + 3] = static_cast<uint8_t>(state[i]);
    }
}

std::vector<uint8_t> BDAuthHelper::hmacSha256(
    const uint8_t* key, size_t keyLen,
    const uint8_t* data, size_t dataLen
) {
    uint8_t k0[64];
    std::memset(k0, 0, 64);
    if (keyLen > 64) {
        sha256Hash(key, keyLen, k0);
    } else {
        std::memcpy(k0, key, keyLen);
    }

    uint8_t ipad[64];
    uint8_t opad[64];
    for (int i = 0; i < 64; ++i) {
        ipad[i] = k0[i] ^ 0x36;
        opad[i] = k0[i] ^ 0x5C;
    }

    // Inner hash: sha256(ipad || data)
    std::vector<uint8_t> innerData(64 + dataLen);
    std::memcpy(innerData.data(), ipad, 64);
    if (data && dataLen > 0) {
        std::memcpy(innerData.data() + 64, data, dataLen);
    }
    uint8_t innerHash[32];
    sha256Hash(innerData.data(), innerData.size(), innerHash);

    // Outer hash: sha256(opad || innerHash)
    uint8_t outerData[64 + 32];
    std::memcpy(outerData, opad, 64);
    std::memcpy(outerData + 64, innerHash, 32);
    std::vector<uint8_t> result(32);
    sha256Hash(outerData, 64 + 32, result.data());

    return result;
}

std::string BDAuthHelper::toHex(const uint8_t* data, size_t len) {
    std::ostringstream ss;
    ss << std::hex << std::setfill('0');
    for (size_t i = 0; i < len; ++i) {
        ss << std::setw(2) << static_cast<int>(data[i]);
    }
    return ss.str();
}

std::string BDAuthHelper::sha256Hex(const std::string& input) {
    uint8_t digest[32];
    sha256Hash(reinterpret_cast<const uint8_t*>(input.data()), input.size(), digest);
    return toHex(digest, 32);
}

// ----------------------------------------------------------------------------
// AWS SigV4 & TOS Header Construction
// ----------------------------------------------------------------------------
std::string BDAuthHelper::generateAWSSignedHeaders(
    const BDAuthCredentials& creds,
    const std::string& httpMethod,
    const std::string& canonicalUri,
    const std::string& canonicalQuery,
    const std::map<std::string, std::string>& headers,
    const std::string& payloadHash,
    const std::string& dateTimeStr
) {
    std::string dateStr = dateTimeStr.substr(0, 8); // YYYYMMDD

    // 1. Canonical Headers & Signed Headers List
    std::string canonicalHeaders;
    std::string signedHeaders;
    for (const auto& kv : headers) {
        std::string lowerKey = kv.first;
        std::transform(lowerKey.begin(), lowerKey.end(), lowerKey.begin(), ::tolower);
        canonicalHeaders += lowerKey + ":" + kv.second + "\n";
        if (!signedHeaders.empty()) signedHeaders += ";";
        signedHeaders += lowerKey;
    }

    // 2. Canonical Request
    std::string canonicalRequest = httpMethod + "\n" +
                                   canonicalUri + "\n" +
                                   canonicalQuery + "\n" +
                                   canonicalHeaders + "\n" +
                                   signedHeaders + "\n" +
                                   payloadHash;

    std::string hashedCanonicalRequest = sha256Hex(canonicalRequest);

    // 3. String to Sign
    std::string credentialScope = dateStr + "/" + creds.region + "/" + creds.service + "/aws4_request";
    std::string stringToSign = "AWS4-HMAC-SHA256\n" +
                               dateTimeStr + "\n" +
                               credentialScope + "\n" +
                               hashedCanonicalRequest;

    // 4. Calculate Signature via HMAC-SHA256 cascade
    std::string kSecret = "AWS4" + creds.secretAccessKey;
    auto kDate    = hmacSha256(reinterpret_cast<const uint8_t*>(kSecret.data()), kSecret.size(),
                               reinterpret_cast<const uint8_t*>(dateStr.data()), dateStr.size());
    auto kRegion  = hmacSha256(kDate.data(), kDate.size(),
                               reinterpret_cast<const uint8_t*>(creds.region.data()), creds.region.size());
    auto kService = hmacSha256(kRegion.data(), kRegion.size(),
                               reinterpret_cast<const uint8_t*>(creds.service.data()), creds.service.size());
    const char reqStr[] = "aws4_request";
    auto kSigning = hmacSha256(kService.data(), kService.size(),
                               reinterpret_cast<const uint8_t*>(reqStr), 12);

    auto signatureBytes = hmacSha256(kSigning.data(), kSigning.size(),
                                     reinterpret_cast<const uint8_t*>(stringToSign.data()), stringToSign.size());
    std::string signatureHex = toHex(signatureBytes.data(), signatureBytes.size());

    // 5. Build Authorization Header
    std::string authHeader = "AWS4-HMAC-SHA256 Credential=" + creds.accessKeyId + "/" + credentialScope +
                             ", SignedHeaders=" + signedHeaders +
                             ", Signature=" + signatureHex;
    return authHeader;
}

bool BDAuthHelper::prepareEncInfo(
    const std::string& secretSeed,
    std::string& outKeyHex,
    std::string& outIvHex
) {
    if (secretSeed.empty()) return false;

    // Generate 32-byte AES key and 16-byte IV using SHA-256 derivations
    std::string keyInput = secretSeed + "_aes_key_derivation";
    std::string ivInput  = secretSeed + "_aes_iv_derivation";

    outKeyHex = sha256Hex(keyInput); // 32 bytes (64 hex characters)
    outIvHex  = sha256Hex(ivInput).substr(0, 32); // 16 bytes (32 hex characters)

    return (!outKeyHex.empty() && !outIvHex.empty());
}

} // namespace bduploader
} // namespace ss
} // namespace com
