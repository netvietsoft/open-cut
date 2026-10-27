/**
 * @file apk_cert_sha256_engine.h
 * @brief Clean-Room Header for Direct-Syscall APK Reader, ZIP/PKCS#7 ASN.1 Parser & SHA-256 Engine.
 *        Header tái tạo sạch cho Bộ đọc APK qua Syscall trực tiếp, Trình phân tích ZIP/PKCS#7 ASN.1 và SHA-256.
 *
 * Binary Target / Mục tiêu nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/libgodzilla-sysopt.so
 *   Addresses covered / Phạm vi địa chỉ:
 *     - 0x00abdc..0x00afc8 : calculateSHA256FromCert(const uint8_t* data, size_t len)
 *     - 0x00afcc..0x0141e8 : extractApkCertAndCalculateSha256(const char* apk_path)
 *     - 0x0141ec..0x0154a8 : findApkPathFromMaps(const std::string& package_hint)
 *     - 0x01579c..0x016188 : get_file_size_direct(const char* path, size_t* out_size)
 *     - 0x01618c..0x017874 : read_file_range_direct_alloc(const char* path, size_t offset, size_t size, size_t* out_read)
 *     - 0x017878..0x0178b0 : rawSyscall4(long sysno, long a1, long a2, long a3, long a4) (`svc #0` @ 0x01789c)
 *     - 0x017978..0x0180f0 : Java_com_bytedance_platform_godzilla_sysopt_ApkSha256_checkMyShit
 *     - 0x018374..0x0188e0 : ASN.1 DER PKCS#7 SignedData X.509 Certificate Extractor
 *     - 0x0188e4..0x0195ec : SHA-256 Context Init, Transform (NEON/Scalar), Update & Final
 */

#ifndef NEXTAI_OPENCUT_GODZILLA_SYSOPT_APK_CERT_SHA256_ENGINE_H_
#define NEXTAI_OPENCUT_GODZILLA_SYSOPT_APK_CERT_SHA256_ENGINE_H_

#include "godzilla_sysopt_types.h"

#include <array>
#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace nextai {
namespace opencut {
namespace godzilla_sysopt {

/**
 * @brief SHA-256 Context Layout [OBSERVED at 0x0188e4..0x0195ec]
 *        Bố cục bộ nhớ ngữ cảnh SHA-256 (112 bytes) [QUAN SÁT ĐƯỢC tại 0x0188e4..0x0195ec]
 *
 * Layout verified from `sha256_init` (`0x0188e4`: `ldr q0, [x8]; ldr q1, [x8, #0x10]; stp q0, q1, [x0, #0x40]; str xzr, [x0, #0x60]; str wzr, [x0, #0x68]`):
 *   - `+0x00..0x3f` : `uint8_t buffer[64]` (64-byte message block buffer)
 *   - `+0x40..0x5f` : `uint32_t state[8]`  (H0..H7 initialized from `.rodata 0x005270`)
 *   - `+0x60..0x67` : `uint64_t bit_count` (Total processed bits)
 *   - `+0x68..0x6b` : `uint32_t buffer_len` (Current bytes in `buffer`)
 */
struct Sha256Context {
    uint8_t  buffer[64];
    uint32_t state[8];
    uint64_t bit_count;
    uint32_t buffer_len;
};

/**
 * @brief SHA-256 Initial State Vector H0..H7 [OBSERVED at .rodata 0x005270..0x00528f]
 *        Vector trạng thái khởi tạo SHA-256 H0..H7 [QUAN SÁT ĐƯỢC tại .rodata 0x005270..0x00528f]
 */
constexpr std::array<uint32_t, 8> kSha256InitialState = {
    0x6A09E667U, 0xBB67AE85U, 0x3C6EF372U, 0xA54FF53AU,
    0x510E527FU, 0x9B05688CU, 0x1F83D9ABU, 0x5BE0CD19U
};

/**
 * @brief SHA-256 Round Constants K[0..63] [OBSERVED at .rodata 0x005308..0x005407]
 *        64 hằng số vòng SHA-256 K[0..63] [QUAN SÁT ĐƯỢC tại .rodata 0x005308..0x005407]
 */
extern const std::array<uint32_t, 64> kSha256RoundConstants;

void Sha256Init(Sha256Context* ctx) noexcept;
void Sha256TransformBlock(uint32_t state[8], const uint8_t block[64]) noexcept;
void Sha256Update(Sha256Context* ctx, const uint8_t* data, size_t len) noexcept;
void Sha256Final(Sha256Context* ctx, uint8_t out_digest[32]) noexcept;
std::string ComputeSha256Hex(const uint8_t* data, size_t len);

/**
 * @brief ASN.1 DER Tag-Length-Value (TLV) Reader [OBSERVED at 0x018374..0x0186f0]
 *        Bộ đọc Tag-Length-Value (TLV) chuẩn ASN.1 DER [QUAN SÁT ĐƯỢC tại 0x018374..0x0186f0]
 */
bool ReadAsn1DerLength(const uint8_t* data,
                       size_t total_len,
                       size_t* io_offset,
                       size_t* out_length) noexcept;

bool ReadAsn1DerElement(const uint8_t* data,
                        size_t total_len,
                        size_t* io_offset,
                        uint8_t expected_tag,
                        const uint8_t** out_content,
                        size_t* out_content_len) noexcept;

/**
 * @brief Extracts the raw X.509 DER Certificate (`SEQUENCE 0x30`) from a PKCS#7 `.RSA`/`.DSA`/`.EC`
 *        SignedData block (`0x0186f4..0x0188e0`).
 *        Trích xuất chứng chỉ X.509 DER nguyên bản từ khối PKCS#7 SignedData (`0x0186f4..0x0188e0`).
 */
bool ExtractX509CertFromPkcs7Der(const uint8_t* pkcs7_data,
                                 size_t pkcs7_len,
                                 const uint8_t** out_cert_der,
                                 size_t* out_cert_len) noexcept;

/**
 * @brief Reconstructs `calculateSHA256FromCert` (`0x00abdc..0x00afc8`, `.data 0x02f818`):
 *        Parses PKCS#7 SignedData (or raw DER X.509 cert) and returns its 64-char lowercase hex SHA-256.
 *        Tái tạo hàm `calculateSHA256FromCert` (`0x00abdc..0x00afc8`, `.data 0x02f818`).
 */
std::string CalculateSha256FromCert(const uint8_t* cert_file_bytes, size_t cert_file_len);

/**
 * @brief Reconstructs `findApkPathFromMaps` (`0x0141ec..0x0154a8`, `.data 0x02f8a0`):
 *        Scans `/proc/self/maps` lines using `sscanf(line, "%lx-%lx %4s ", &start, &end, perms)` (`0x004a33`)
 *        for mapped paths containing `package_hint` and ending with `"/base.apk"` (`0x00426e`) or `".apk"`.
 *        Tái tạo hàm `findApkPathFromMaps` (`0x0141ec..0x0154a8`, `.data 0x02f8a0`).
 */
std::string FindApkPathFromMapsText(const std::string& maps_content,
                                    const std::string& package_hint,
                                    std::string* out_log = nullptr);

/**
 * @brief Reconstructs `extractApkCertAndCalculateSha256` (`0x00afcc..0x0141e8`, `.data 0x02f900`):
 *        Locates EOCD (`0x06054b50`), walks Central Directory (`0x02014b50`) for `META-INF/*.RSA` / `.DSA` / `.EC`,
 *        extracts the Local File Header (`0x04034b50`) payload (Stored `0` or Deflated `8`), and computes
 *        its certificate SHA-256 via `CalculateSha256FromCert`.
 *        Tái tạo hàm `extractApkCertAndCalculateSha256` (`0x00afcc..0x0141e8`, `.data 0x02f900`).
 */
std::string ExtractApkCertAndCalculateSha256FromZipBytes(const uint8_t* zip_bytes,
                                                         size_t zip_len,
                                                         std::string* out_log = nullptr);

}  // namespace godzilla_sysopt
}  // namespace opencut
}  // namespace nextai

#endif  // NEXTAI_OPENCUT_GODZILLA_SYSOPT_APK_CERT_SHA256_ENGINE_H_
