/**
 * @file bdvideouploader_auth_tos.h
 * @brief ByteDance Video Uploader - AWS S3 & ByteDance TOS Authentication Engine.
 *        Động cơ tạo chữ ký xác thực tiêu chuẩn AWS S3 và ByteDance TOS.
 *
 * Rules: AGENTS.md Rule 12 (Bilingual EN/VN), Rule 14 & 20 (Zero stubs, exact binary parity).
 */

#ifndef BDVIDEOUPLOADER_AUTH_TOS_H
#define BDVIDEOUPLOADER_AUTH_TOS_H

#include "bdvideouploader_types.h"
#include <string>
#include <map>
#include <vector>

namespace com {
namespace ss {
namespace bduploader {

/**
 * @brief AWS / ByteDance TOS Header Signer & AES Token Generator
 *        Bộ tạo chữ ký xác thực tiêu đề HTTP và mã hóa token
 */
class BDAuthHelper {
public:
    static std::string generateAWSSignedHeaders(
        const BDAuthCredentials& creds,
        const std::string& httpMethod,
        const std::string& canonicalUri,
        const std::string& canonicalQuery,
        const std::map<std::string, std::string>& headers,
        const std::string& payloadHash,
        const std::string& dateTimeStr
    );

    /**
     * @brief Prepare AES Encryption Initialization Vector and Key
     *        Chuẩn bị vector khởi tạo IV và khóa AES-128/256
     */
    static bool prepareEncInfo(
        const std::string& secretSeed,
        std::string& outKeyHex,
        std::string& outIvHex
    );

    /**
     * @brief HMAC-SHA256 Mathematical Implementation
     *        Giải thuật băm mật mã học HMAC-SHA256 độc lập
     */
    static std::vector<uint8_t> hmacSha256(
        const uint8_t* key, size_t keyLen,
        const uint8_t* data, size_t dataLen
    );

    static std::string toHex(const uint8_t* data, size_t len);
    static std::string sha256Hex(const std::string& input);

private:
    static void sha256Transform(uint32_t state[8], const uint8_t block[64]);
    static void sha256Hash(const uint8_t* data, size_t len, uint8_t digest[32]);
};

} // namespace bduploader
} // namespace ss
} // namespace com

#endif // BDVIDEOUPLOADER_AUTH_TOS_H
