/**
 * @file apk_cert_sha256_engine.cpp
 * @brief Clean-Room Implementation of Direct-Syscall APK Reader, ZIP/PKCS#7 ASN.1 Parser & SHA-256 Engine.
 *        Triển khai tái tạo sạch cho Bộ đọc APK qua Syscall trực tiếp, Trình phân tích ZIP/PKCS#7 ASN.1 và SHA-256.
 *
 * Binary Target / Mục tiêu nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/libgodzilla-sysopt.so
 *   Addresses covered / Phạm vi địa chỉ: 0x00abdc..0x0195ec
 */

#include "apk_cert_sha256_engine.h"

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <sstream>

namespace nextai {
namespace opencut {
namespace godzilla_sysopt {

/**
 * @brief SHA-256 Round Constants K[0..63] [OBSERVED at .rodata 0x005308..0x005407]
 *        64 hằng số vòng SHA-256 K[0..63] [QUAN SÁT ĐƯỢC tại .rodata 0x005308..0x005407]
 */
const std::array<uint32_t, 64> kSha256RoundConstants = {
    0x428A2F98U, 0x71374491U, 0xB5C0FBCFU, 0xE9B5DBA5U,
    0x3956C25BU, 0x59F111F1U, 0x923F82A4U, 0xAB1C5ED5U,
    0xD807AA98U, 0x12835B01U, 0x243185BEU, 0x550C7DC3U,
    0x72BE5D74U, 0x80DEB1FEU, 0x9BDC06A7U, 0xC19BF174U,
    0xE49B69C1U, 0xEFBE4786U, 0x0FC19DC6U, 0x240CA1CCU,
    0x2DE92C6FU, 0x4A7484AAU, 0x5CB0A9DCU, 0x76F988DAU,
    0x983E5152U, 0xA831C66DU, 0xB00327C8U, 0xBF597FC7U,
    0xC6E00BF3U, 0xD5A79147U, 0x06CA6351U, 0x14292967U,
    0x27B70A85U, 0x2E1B2138U, 0x4D2C6DFCU, 0x53380D13U,
    0x650A7354U, 0x766A0ABBU, 0x81C2C92EU, 0x92722C85U,
    0xA2BFE8A1U, 0xA81A664BU, 0xC24B8B70U, 0xC76C51A3U,
    0xD192E819U, 0xD6990624U, 0xF40E3585U, 0x106AA070U,
    0x19A4C116U, 0x1E376C08U, 0x2748774CU, 0x34B0BCB5U,
    0x391C0CB3U, 0x4ED8AA4AU, 0x5B9CCA4FU, 0x682E6FF3U,
    0x748F82EEU, 0x78A5636FU, 0x84C87814U, 0x8CC70208U,
    0x90BEFFFAU, 0xA4506CEBU, 0xBEF9A3F7U, 0xC67178F2U
};

namespace {

inline constexpr uint32_t Rotr32(uint32_t x, uint32_t n) noexcept {
    return (x >> n) | (x << (32U - n));
}

inline constexpr uint32_t Ch(uint32_t x, uint32_t y, uint32_t z) noexcept {
    return (x & y) ^ (~x & z);
}

inline constexpr uint32_t Maj(uint32_t x, uint32_t y, uint32_t z) noexcept {
    return (x & y) ^ (x & z) ^ (y & z);
}

inline constexpr uint32_t BigSigma0(uint32_t x) noexcept {
    return Rotr32(x, 2U) ^ Rotr32(x, 13U) ^ Rotr32(x, 22U);
}

inline constexpr uint32_t BigSigma1(uint32_t x) noexcept {
    return Rotr32(x, 6U) ^ Rotr32(x, 11U) ^ Rotr32(x, 25U);
}

inline constexpr uint32_t SmallSigma0(uint32_t x) noexcept {
    // Vectorized in binary at 0x018a10..0x018abc via NEON `ushl v2.4s, v1.4s, v3.4s`
    // using shift constants at .rodata 0x0052f8 (-7, -18, -3, +25, +14)
    return Rotr32(x, 7U) ^ Rotr32(x, 18U) ^ (x >> 3U);
}

inline constexpr uint32_t SmallSigma1(uint32_t x) noexcept {
    // Vectorized in binary at 0x018a58..0x018ac0 via NEON shift constants at .rodata 0x0052e8 (-17, -19, -10, +15, +13)
    return Rotr32(x, 17U) ^ Rotr32(x, 19U) ^ (x >> 10U);
}

inline uint32_t ReadBe32(const uint8_t* p) noexcept {
    return (static_cast<uint32_t>(p[0]) << 24U) |
           (static_cast<uint32_t>(p[1]) << 16U) |
           (static_cast<uint32_t>(p[2]) << 8U)  |
           static_cast<uint32_t>(p[3]);
}

inline void WriteBe32(uint8_t* p, uint32_t v) noexcept {
    p[0] = static_cast<uint8_t>((v >> 24U) & 0xFFU);
    p[1] = static_cast<uint8_t>((v >> 16U) & 0xFFU);
    p[2] = static_cast<uint8_t>((v >> 8U) & 0xFFU);
    p[3] = static_cast<uint8_t>(v & 0xFFU);
}

inline uint16_t ReadLe16(const uint8_t* p) noexcept {
    return static_cast<uint16_t>(p[0]) | (static_cast<uint16_t>(p[1]) << 8U);
}

inline uint32_t ReadLe32(const uint8_t* p) noexcept {
    return static_cast<uint32_t>(p[0]) |
           (static_cast<uint32_t>(p[1]) << 8U) |
           (static_cast<uint32_t>(p[2]) << 16U) |
           (static_cast<uint32_t>(p[3]) << 24U);
}

bool EndsWithCaseInsensitive(const std::string& str, const char* suffix) noexcept {
    const size_t slen = std::strlen(suffix);
    if (str.size() < slen) {
        return false;
    }
    const size_t start = str.size() - slen;
    for (size_t i = 0; i < slen; ++i) {
        char c1 = str[start + i];
        char c2 = suffix[i];
        if (c1 >= 'a' && c1 <= 'z') c1 = static_cast<char>(c1 - 32);
        if (c2 >= 'a' && c2 <= 'z') c2 = static_cast<char>(c2 - 32);
        if (c1 != c2) {
            return false;
        }
    }
    return true;
}

}  // namespace

/**
 * @brief Reconstructs `sha256_init` (`0x0188e4..0x018908`):
 *        Loads `H0..H7` from `.rodata 0x005270` (`ldr q0, [x8]; ldr q1, [x8, #0x10]; stp q0, q1, [x0, #0x40]`),
 *        zeros `bit_count` (`str xzr, [x0, #0x60]`) and `buffer_len` (`str wzr, [x0, #0x68]`).
 *        Tái tạo hàm `sha256_init` (`0x0188e4..0x018908`).
 */
void Sha256Init(Sha256Context* ctx) noexcept {
    if (ctx == nullptr) {
        return;
    }
    std::memset(ctx->buffer, 0, sizeof(ctx->buffer));
    for (size_t i = 0; i < 8U; ++i) {
        ctx->state[i] = kSha256InitialState[i];
    }
    ctx->bit_count = 0ULL;
    ctx->buffer_len = 0U;
}

/**
 * @brief Reconstructs `sha256_transform` (`0x0189dc..0x0191f0`):
 *        Expands `W[0..63]` (using NEON `rev32` + vector shifts in binary) and executes 64 compression rounds.
 *        Tái tạo hàm `sha256_transform` (`0x0189dc..0x0191f0`).
 */
void Sha256TransformBlock(uint32_t state[8], const uint8_t block[64]) noexcept {
    uint32_t w[64];
    for (size_t i = 0; i < 16U; ++i) {
        w[i] = ReadBe32(block + (i * 4U));
    }
    for (size_t i = 16U; i < 64U; ++i) {
        w[i] = SmallSigma1(w[i - 2U]) + w[i - 7U] + SmallSigma0(w[i - 15U]) + w[i - 16U];
    }

    uint32_t a = state[0];
    uint32_t b = state[1];
    uint32_t c = state[2];
    uint32_t d = state[3];
    uint32_t e = state[4];
    uint32_t f = state[5];
    uint32_t g = state[6];
    uint32_t h = state[7];

    for (size_t i = 0; i < 64U; ++i) {
        const uint32_t t1 = h + BigSigma1(e) + Ch(e, f, g) + kSha256RoundConstants[i] + w[i];
        const uint32_t t2 = BigSigma0(a) + Maj(a, b, c);
        h = g;
        g = f;
        f = e;
        e = d + t1;
        d = c;
        c = b;
        b = a;
        a = t1 + t2;
    }

    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;
    state[4] += e;
    state[5] += f;
    state[6] += g;
    state[7] += h;
}

/**
 * @brief Reconstructs `sha256_update` (`0x01890c..0x0189d8`):
 *        Processes input bytes in 64-byte chunks and updates `ctx->bit_count` (`lsl x10, x2, #3`).
 *        Tái tạo hàm `sha256_update` (`0x01890c..0x0189d8`).
 */
void Sha256Update(Sha256Context* ctx, const uint8_t* data, size_t len) noexcept {
    if (ctx == nullptr || data == nullptr || len == 0U) {
        return;
    }
    for (size_t i = 0; i < len; ++i) {
        ctx->buffer[ctx->buffer_len++] = data[i];
        if (ctx->buffer_len == 64U) {
            Sha256TransformBlock(ctx->state, ctx->buffer);
            ctx->bit_count += 512ULL;
            ctx->buffer_len = 0U;
        }
    }
}

/**
 * @brief Reconstructs `sha256_final` (`0x0191f4..0x0195ec`):
 *        Appends `0x80` padding byte (`mov w10, #0x80`), pads to 56 bytes mod 64, appends 64-bit big-endian
 *        `bit_count`, runs final transform, and byte-swaps `state[0..7]` into `out_digest[0..31]`.
 *        Tái tạo hàm `sha256_final` (`0x0191f4..0x0195ec`).
 */
void Sha256Final(Sha256Context* ctx, uint8_t out_digest[32]) noexcept {
    if (ctx == nullptr || out_digest == nullptr) {
        return;
    }

    uint32_t idx = ctx->buffer_len;
    const uint64_t total_bits = ctx->bit_count + (static_cast<uint64_t>(idx) << 3U);

    // 0x01920c: mov w10, #0x80; strb w10, [x0, x8]
    ctx->buffer[idx++] = 0x80U;
    if (idx > 56U) {
        while (idx < 64U) {
            ctx->buffer[idx++] = 0x00U;
        }
        Sha256TransformBlock(ctx->state, ctx->buffer);
        idx = 0U;
    }
    while (idx < 56U) {
        ctx->buffer[idx++] = 0x00U;
    }

    // Write 64-bit big-endian total bit length at buffer[56..63]
    for (int i = 0; i < 8; ++i) {
        ctx->buffer[63 - i] = static_cast<uint8_t>((total_bits >> (i * 8)) & 0xFFU);
    }
    Sha256TransformBlock(ctx->state, ctx->buffer);

    for (size_t i = 0; i < 8U; ++i) {
        WriteBe32(out_digest + (i * 4U), ctx->state[i]);
    }
}

/**
 * @brief Computes lowercase 64-character SHA-256 hex digest (`0x00ac90..0x00af50`).
 *        Tính chuỗi hex SHA-256 64 ký tự chữ thường (`0x00ac90..0x00af50`).
 */
std::string ComputeSha256Hex(const uint8_t* data, size_t len) {
    Sha256Context ctx{};
    Sha256Init(&ctx);
    Sha256Update(&ctx, data, len);
    uint8_t digest[32]{};
    Sha256Final(&ctx, digest);

    char hex[65];
    for (size_t i = 0; i < 32U; ++i) {
        std::snprintf(hex + (i * 2U), 3U, "%02x", static_cast<unsigned int>(digest[i]));
    }
    hex[64] = '\0';
    return std::string(hex, 64U);
}

/**
 * @brief Reconstructs ASN.1 DER Length Parser (`0x018374..0x018510`):
 *        Handles short form (`len < 0x80`) and long form (`0x81..0x84` -> 1..4 big-endian length bytes).
 *        Tái tạo bộ đọc độ dài ASN.1 DER (`0x018374..0x018510`).
 */
bool ReadAsn1DerLength(const uint8_t* data,
                       size_t total_len,
                       size_t* io_offset,
                       size_t* out_length) noexcept {
    if (data == nullptr || io_offset == nullptr || out_length == nullptr || *io_offset >= total_len) {
        return false;
    }
    const uint8_t first = data[(*io_offset)++];
    if ((first & 0x80U) == 0U) {
        *out_length = static_cast<size_t>(first);
        return (*io_offset + *out_length) <= total_len;
    }
    const uint8_t num_bytes = first & 0x7FU;
    // 0x0183c8: sub w11, w10, #1; cmp w11, #4; b.hs (only 1..4 bytes allowed)
    if (num_bytes == 0U || num_bytes > 4U || (*io_offset + num_bytes) > total_len) {
        return false;
    }
    size_t val = 0U;
    for (uint8_t i = 0; i < num_bytes; ++i) {
        val = (val << 8U) | static_cast<size_t>(data[(*io_offset)++]);
    }
    *out_length = val;
    return (*io_offset + *out_length) <= total_len;
}

/**
 * @brief Reconstructs ASN.1 DER Element Reader (`0x018514..0x0186f0`):
 *        Verifies `data[*io_offset] == expected_tag`, reads DER length, and returns content pointer/length.
 *        Tái tạo bộ đọc phần tử ASN.1 DER (`0x018514..0x0186f0`).
 */
bool ReadAsn1DerElement(const uint8_t* data,
                        size_t total_len,
                        size_t* io_offset,
                        uint8_t expected_tag,
                        const uint8_t** out_content,
                        size_t* out_content_len) noexcept {
    if (data == nullptr || io_offset == nullptr || *io_offset >= total_len) {
        return false;
    }
    if (data[*io_offset] != expected_tag) {
        return false;
    }
    (*io_offset) += 1U;
    size_t content_len = 0U;
    if (!ReadAsn1DerLength(data, total_len, io_offset, &content_len)) {
        return false;
    }
    if (out_content != nullptr) {
        *out_content = data + *io_offset;
    }
    if (out_content_len != nullptr) {
        *out_content_len = content_len;
    }
    return true;
}

/**
 * @brief Reconstructs PKCS#7 SignedData X.509 Certificate Extractor (`0x0186f4..0x0188e0`):
 *        Walks the ASN.1 DER structure of an Android `META-INF/*.RSA` / `.DSA` / `.EC` file:
 *          1. ContentInfo `SEQUENCE (0x30)` (`0x018718: mov w3, #0x30`)
 *          2. contentType `OID (0x06)` (`0x018734: mov w3, #6`) -> `1.2.840.113549.1.7.2` (signedData)
 *          3. content `[0] EXPLICIT (0xA0)` (`0x018754: mov w3, #0xa0`)
 *          4. SignedData `SEQUENCE (0x30)` (`0x01876c: mov w3, #0x30`)
 *          5. version `INTEGER (0x02)` (`0x018788: mov w3, #2`)
 *          6. digestAlgorithms `SET (0x31)` (`0x0187a8: mov w3, #0x31`)
 *          7. encapContentInfo `SEQUENCE (0x30)` (`0x0187c8: mov w3, #0x30`)
 *          8. certificates `[0] IMPLICIT (0xA0)` (`0x0187f0: cmp w8, #0xa0`)
 *          9. First Certificate `SEQUENCE (0x30)`: returns full TLV slice (`tag 0x30 + length + body`,
 *             computed at `0x0188c4: add x8, x9, x8; sub x8, x8, x20; str x8, [x19]`).
 *        Tái tạo bộ trích xuất chứng chỉ X.509 từ PKCS#7 SignedData (`0x0186f4..0x0188e0`).
 */
bool ExtractX509CertFromPkcs7Der(const uint8_t* pkcs7_data,
                                 size_t pkcs7_len,
                                 const uint8_t** out_cert_der,
                                 size_t* out_cert_len) noexcept {
    if (pkcs7_data == nullptr || pkcs7_len < 16U || out_cert_der == nullptr || out_cert_len == nullptr) {
        return false;
    }

    size_t pos = 0U;
    const uint8_t* seq_content = nullptr;
    size_t seq_len = 0U;

    // 1. Outer ContentInfo SEQUENCE (0x30)
    if (!ReadAsn1DerElement(pkcs7_data, pkcs7_len, &pos, 0x30U, &seq_content, &seq_len)) {
        return false;
    }

    const size_t outer_end = pos + seq_len;
    const uint8_t* oid_content = nullptr;
    size_t oid_len = 0U;

    // 2. contentType OID (0x06) - skip over OID bytes
    if (!ReadAsn1DerElement(pkcs7_data, outer_end, &pos, 0x06U, &oid_content, &oid_len)) {
        return false;
    }
    pos += oid_len;

    // 3. content [0] EXPLICIT (0xA0)
    const uint8_t* a0_content = nullptr;
    size_t a0_len = 0U;
    if (!ReadAsn1DerElement(pkcs7_data, outer_end, &pos, 0xA0U, &a0_content, &a0_len)) {
        return false;
    }

    // 4. SignedData SEQUENCE (0x30)
    const uint8_t* sd_content = nullptr;
    size_t sd_len = 0U;
    if (!ReadAsn1DerElement(pkcs7_data, outer_end, &pos, 0x30U, &sd_content, &sd_len)) {
        return false;
    }
    const size_t sd_end = pos + sd_len;

    // 5. version INTEGER (0x02)
    const uint8_t* ver_content = nullptr;
    size_t ver_len = 0U;
    if (!ReadAsn1DerElement(pkcs7_data, sd_end, &pos, 0x02U, &ver_content, &ver_len)) {
        return false;
    }
    pos += ver_len;

    // 6. digestAlgorithms SET (0x31)
    const uint8_t* da_content = nullptr;
    size_t da_len = 0U;
    if (!ReadAsn1DerElement(pkcs7_data, sd_end, &pos, 0x31U, &da_content, &da_len)) {
        return false;
    }
    pos += da_len;

    // 7. encapContentInfo SEQUENCE (0x30)
    const uint8_t* eci_content = nullptr;
    size_t eci_len = 0U;
    if (!ReadAsn1DerElement(pkcs7_data, sd_end, &pos, 0x30U, &eci_content, &eci_len)) {
        return false;
    }
    pos += eci_len;

    // 8. certificates [0] IMPLICIT (0xA0) at 0x0187f0
    const uint8_t* certs_content = nullptr;
    size_t certs_len = 0U;
    if (!ReadAsn1DerElement(pkcs7_data, sd_end, &pos, 0xA0U, &certs_content, &certs_len)) {
        return false;
    }
    const size_t certs_end = pos + certs_len;

    // 9. First X.509 Certificate SEQUENCE (0x30): record start of tag 0x30!
    const size_t cert_tlv_start = pos;
    const uint8_t* cert_body = nullptr;
    size_t cert_body_len = 0U;
    if (!ReadAsn1DerElement(pkcs7_data, certs_end, &pos, 0x30U, &cert_body, &cert_body_len)) {
        return false;
    }

    // 0x0188c4: total certificate DER size = (pos - cert_tlv_start) + cert_body_len
    *out_cert_der = pkcs7_data + cert_tlv_start;
    *out_cert_len = (pos - cert_tlv_start) + cert_body_len;
    return true;
}

/**
 * @brief Reconstructs `calculateSHA256FromCert` (`0x00abdc..0x00afc8`, `.data 0x02f818`):
 *        First attempts `ExtractX509CertFromPkcs7Der` (`0x0186f4`); if valid, hashes the extracted
 *        X.509 DER certificate via `ComputeSha256Hex`.
 *        Tái tạo hàm `calculateSHA256FromCert` (`0x00abdc..0x00afc8`).
 */
std::string CalculateSha256FromCert(const uint8_t* cert_file_bytes, size_t cert_file_len) {
    if (cert_file_bytes == nullptr || cert_file_len == 0U) {
        return {};
    }
    const uint8_t* cert_der = nullptr;
    size_t cert_len = 0U;
    if (!ExtractX509CertFromPkcs7Der(cert_file_bytes, cert_file_len, &cert_der, &cert_len)) {
        return {};
    }
    return ComputeSha256Hex(cert_der, cert_len);
}

/**
 * @brief Reconstructs `findApkPathFromMaps` (`0x0141ec..0x0154a8`, `.data 0x02f8a0`):
 *        Scans `/proc/self/maps` lines using `sscanf(line, "%lx-%lx %4s ", &start, &end, perms)` (`0x004a33`),
 *        extracts the pathname column, and finds the APK path matching `package_hint` and `"/base.apk"` (`0x00426e`)
 *        or `".apk"`.
 *        Tái tạo hàm `findApkPathFromMaps` (`0x0141ec..0x0154a8`).
 */
std::string FindApkPathFromMapsText(const std::string& maps_content,
                                    const std::string& package_hint,
                                    std::string* out_log) {
    std::istringstream stream(maps_content);
    std::string line;
    std::string fallback_apk;

    while (std::getline(stream, line)) {
        unsigned long start_addr = 0UL;
        unsigned long end_addr = 0UL;
        char perms[8]{};
        if (std::sscanf(line.c_str(), "%lx-%lx %4s ", &start_addr, &end_addr, perms) != 3) {
            continue;
        }
        const size_t slash_pos = line.find('/');
        if (slash_pos == std::string::npos) {
            continue;
        }
        std::string path = line.substr(slash_pos);
        while (!path.empty() && (path.back() == '\r' || path.back() == '\n' || path.back() == ' ')) {
            path.pop_back();
        }
        if (!EndsWithCaseInsensitive(path, ".apk")) {
            continue;
        }
        if (!package_hint.empty() && path.find(package_hint) == std::string::npos) {
            continue;
        }
        if (path.find("/base.apk") != std::string::npos) {
            if (out_log != nullptr) {
                *out_log = "Found apk path: " + path;
            }
            return path;
        }
        if (fallback_apk.empty()) {
            fallback_apk = path;
        }
    }

    if (!fallback_apk.empty()) {
        if (out_log != nullptr) {
            *out_log = "Found apk path: " + fallback_apk;
        }
        return fallback_apk;
    }

    if (out_log != nullptr) {
        *out_log = "APK path not found in maps";
    }
    return {};
}

/**
 * @brief Reconstructs `extractApkCertAndCalculateSha256` (`0x00afcc..0x0141e8`, `.data 0x02f900`):
 *        1. Checks tail of ZIP/APK (`<= 0x10016` bytes) for End of Central Directory signature `0x06054b50`.
 *        2. Reads Central Directory (`cd_offset`, `cd_size`, `total_entries`) and iterates `0x02014b50` entries.
 *        3. Matches entry filename starting with `"META-INF/"` and ending with `".RSA"`, `".DSA"`, or `".EC"`.
 *        4. Reads Local File Header (`0x04034b50`), extracts certificate file payload, and calls `CalculateSha256FromCert`.
 *        Tái tạo hàm `extractApkCertAndCalculateSha256` (`0x00afcc..0x0141e8`).
 */
std::string ExtractApkCertAndCalculateSha256FromZipBytes(const uint8_t* zip_bytes,
                                                         size_t zip_len,
                                                         std::string* out_log) {
    if (zip_bytes == nullptr || zip_len < kZipEocdMinSize) {
        if (out_log != nullptr) {
            *out_log = "apk_path is null";
        }
        return {};
    }

    // 1. Search backwards in last min(zip_len, 0x10016) bytes for EOCD signature 0x06054b50
    const size_t tail_size = std::min(zip_len, kZipMaxTailReadSize);
    const size_t tail_start = zip_len - tail_size;
    ssize_t eocd_pos = -1;
    for (ssize_t pos = static_cast<ssize_t>(zip_len - kZipEocdMinSize);
         pos >= static_cast<ssize_t>(tail_start);
         --pos) {
        if (ReadLe32(zip_bytes + pos) == kZipEocdSignature) {
            eocd_pos = pos;
            break;
        }
    }

    if (eocd_pos < 0) {
        if (out_log != nullptr) {
            *out_log = "Failed to find APK EOCD";
        }
        return {};
    }

    const uint8_t* eocd = zip_bytes + eocd_pos;
    const uint16_t total_entries = ReadLe16(eocd + 10);
    const uint32_t cd_size       = ReadLe32(eocd + 12);
    const uint32_t cd_offset     = ReadLe32(eocd + 16);

    if (static_cast<size_t>(cd_offset) + static_cast<size_t>(cd_size) > zip_len) {
        if (out_log != nullptr) {
            *out_log = "Failed to read APK central directory";
        }
        return {};
    }

    // 2. Iterate Central Directory entries (signature 0x02014b50)
    size_t cd_cursor = cd_offset;
    const size_t cd_end = static_cast<size_t>(cd_offset) + static_cast<size_t>(cd_size);
    for (uint16_t i = 0; i < total_entries && (cd_cursor + 46U) <= cd_end; ++i) {
        const uint8_t* entry = zip_bytes + cd_cursor;
        if (ReadLe32(entry) != kZipCdFileHeaderSig) {
            break;
        }
        const uint16_t comp_method = ReadLe16(entry + 10);
        const uint32_t comp_size   = ReadLe32(entry + 20);
        const uint16_t name_len    = ReadLe16(entry + 28);
        const uint16_t extra_len   = ReadLe16(entry + 30);
        const uint16_t comment_len = ReadLe16(entry + 32);
        const uint32_t lfh_offset  = ReadLe32(entry + 42);

        if (cd_cursor + 46U + name_len > cd_end) {
            break;
        }
        const std::string filename(reinterpret_cast<const char*>(entry + 46U), name_len);
        cd_cursor += 46U + name_len + extra_len + comment_len;

        if (filename.compare(0, 9, "META-INF/") == 0 &&
            (EndsWithCaseInsensitive(filename, ".RSA") ||
             EndsWithCaseInsensitive(filename, ".DSA") ||
             EndsWithCaseInsensitive(filename, ".EC"))) {
            // 3. Parse Local File Header (0x04034b50) at lfh_offset
            if (static_cast<size_t>(lfh_offset) + 30U > zip_len) {
                break;
            }
            const uint8_t* lfh = zip_bytes + lfh_offset;
            if (ReadLe32(lfh) != kZipLocalFileHeaderSig) {
                break;
            }
            const uint16_t lfh_name_len  = ReadLe16(lfh + 26);
            const uint16_t lfh_extra_len = ReadLe16(lfh + 28);
            const size_t data_offset = static_cast<size_t>(lfh_offset) + 30U + lfh_name_len + lfh_extra_len;
            if (data_offset + comp_size > zip_len) {
                break;
            }

            if (comp_method == kZipCompressionStored) {
                const std::string sha256 = CalculateSha256FromCert(zip_bytes + data_offset, comp_size);
                if (sha256.empty() && out_log != nullptr) {
                    *out_log = "calculateSHA256FromCert returned empty";
                }
                return sha256;
            }
        }
    }

    if (out_log != nullptr) {
        *out_log = "Failed to find cert file in APK";
    }
    return {};
}

}  // namespace godzilla_sysopt
}  // namespace opencut
}  // namespace nextai
