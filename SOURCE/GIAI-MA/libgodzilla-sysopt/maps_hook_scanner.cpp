/**
 * @file maps_hook_scanner.cpp
 * @brief Clean-Room Implementation of /proc/self/maps Hook Framework & >39-Bit VMA Detector.
 *        Triển khai tái tạo sạch cho Bộ quét Hook Framework trên /proc/self/maps và Phát hiện VMA >39-Bit.
 *
 * Binary Target / Mục tiêu nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/libgodzilla-sysopt.so
 *   Addresses covered / Phạm vi địa chỉ: 0x0180f4..0x01828c, 0x019fb4..0x022878
 */

#include "maps_hook_scanner.h"

#include <cstdio>
#include <cstring>
#include <sstream>

namespace nextai {
namespace opencut {
namespace godzilla_sysopt {

namespace {

/**
 * @brief 12 Encrypted Hook Keyword Byte Arrays [OBSERVED at 0x01b18c..0x022684]
 *        12 mảng byte từ khóa Hook Framework được mã hóa trong nhị phân [QUAN SÁT ĐƯỢC tại 0x01b18c..0x022684]
 *
 * Each byte `c[i]` is encrypted with rolling key `(base_key + i) & 0xFF`:
 *   1. `0x022108` (`base=0x87`): `f4 e9 e7 ee e3 e3 e2 e5 8f`       -> `"sandhook\0"`
 *   2. `0x01ba70` (`base=0x88`): `ed f9 e3 e8 8c`                   -> `"epic\0"`
 *   3. `0x01c330` (`base=0x89`): `ef f8 e2 e8 ec 8e`                -> `"frida\0"`
 *   4. `0x01cbf8` (`base=0x8b`): `f3 fc e2 fd ea f4 91`             -> `"xposed\0"`
 *   5. `0x02233c` (`base=0x8c`): `e9 e9 f6 ff ff e2 f7 f7 94`       -> `"edxposed\0"`
 *   6. `0x022404` (`base=0x8d`): `e1 fd ff ff e2 f7 f7 94`          -> `"lsposed\0"`
 *   7. `0x0224d0` (`base=0x8e`): `fd fa f2 e2 e6 e1 f5 e1 f3 97`    -> `"substrate\0"`
 *   8. `0x01ef58` (`base=0x8f`): `ec e9 f5 fb f2 94`                -> `"cydia\0"`
 *   9. `0x01f86c` (`base=0x90`): `e2 f8 e0 e6 94`                   -> `"riru\0"`
 *  10. `0x02017c` (`base=0x92`): `e8 ea f3 fc e5 fc 98`             -> `"zygisk\0"`
 *  11. `0x0225a0` (`base=0x93`): `f7 f1 ed e6 f8 eb fc fe 9b`       -> `"dexposed\0"`
 *  12. `0x02266c` (`base=0x94`): `fc fa e3 f3 f1 f7 f3 9b`          -> `"houdini\0"`
 */
constexpr uint8_t kEncSandhook[]  = {0xF4, 0xE9, 0xE7, 0xEE, 0xE3, 0xE3, 0xE2, 0xE5, 0x8F};
constexpr uint8_t kEncEpic[]      = {0xED, 0xF9, 0xE3, 0xE8, 0x8C};
constexpr uint8_t kEncFrida[]     = {0xEF, 0xF8, 0xE2, 0xE8, 0xEC, 0x8E};
constexpr uint8_t kEncXposed[]    = {0xF3, 0xFC, 0xE2, 0xFD, 0xEA, 0xF4, 0x91};
constexpr uint8_t kEncEdxposed[]  = {0xE9, 0xE9, 0xF6, 0xFF, 0xFF, 0xE2, 0xF7, 0xF7, 0x94};
constexpr uint8_t kEncLsposed[]   = {0xE1, 0xFD, 0xFF, 0xFF, 0xE2, 0xF7, 0xF7, 0x94};
constexpr uint8_t kEncSubstrate[] = {0xFD, 0xFA, 0xF2, 0xE2, 0xE6, 0xE1, 0xF5, 0xE1, 0xF3, 0x97};
constexpr uint8_t kEncCydia[]     = {0xEC, 0xE9, 0xF5, 0xFB, 0xF2, 0x94};
constexpr uint8_t kEncRiru[]      = {0xE2, 0xF8, 0xE0, 0xE6, 0x94};
constexpr uint8_t kEncZygisk[]    = {0xE8, 0xEA, 0xF3, 0xFC, 0xE5, 0xFC, 0x98};
constexpr uint8_t kEncDexposed[]  = {0xF7, 0xF1, 0xED, 0xE6, 0xF8, 0xEB, 0xFC, 0xFE, 0x9B};
constexpr uint8_t kEncHoudini[]   = {0xFC, 0xFA, 0xE3, 0xF3, 0xF1, 0xF7, 0xF3, 0x9B};

constexpr std::array<EncryptedKeywordBlob, 12> kEncryptedKeywordTable = {{
    {0x87U, sizeof(kEncSandhook),  kEncSandhook,  "sandhook"},
    {0x88U, sizeof(kEncEpic),      kEncEpic,      "epic"},
    {0x89U, sizeof(kEncFrida),     kEncFrida,     "frida"},
    {0x8BU, sizeof(kEncXposed),    kEncXposed,    "xposed"},
    {0x8CU, sizeof(kEncEdxposed),  kEncEdxposed,  "edxposed"},
    {0x8DU, sizeof(kEncLsposed),   kEncLsposed,   "lsposed"},
    {0x8EU, sizeof(kEncSubstrate), kEncSubstrate, "substrate"},
    {0x8FU, sizeof(kEncCydia),     kEncCydia,     "cydia"},
    {0x90U, sizeof(kEncRiru),      kEncRiru,      "riru"},
    {0x92U, sizeof(kEncZygisk),    kEncZygisk,    "zygisk"},
    {0x93U, sizeof(kEncDexposed),  kEncDexposed,  "dexposed"},
    {0x94U, sizeof(kEncHoudini),   kEncHoudini,   "houdini"},
}};

}  // namespace

const std::array<EncryptedKeywordBlob, 12>& GetEncryptedHookKeywordBlobs() noexcept {
    return kEncryptedKeywordTable;
}

/**
 * @brief Reconstructs the MBA rolling-XOR decryption loop (`0x01b210..0x01b260`):
 *        `d1 = (d2 * (-2.0) + d1) * double(key_i) * double(((p0 + 7) / p1) - p2)`
 *        `w3 = fcvtzs(d1)`
 *        `w0 = (enc_byte + w3) - ((enc_byte & w3) << 1)`
 *        Tái tạo vòng lặp giải mã XOR trượt bằng đồng nhất thức MBA tại `0x01b210..0x01b260`.
 */
std::string DecryptHookKeywordBlob(const EncryptedKeywordBlob& blob,
                                   const OpaquePredicateBlock& pred) {
    if (blob.enc_bytes == nullptr || blob.byte_len == 0U) {
        return {};
    }

    const double fma_scale = pred.EvaluateFmaScale();
    std::string out;
    out.reserve(blob.byte_len);

    for (uint8_t i = 0U; i < blob.byte_len; ++i) {
        const double raw_key = static_cast<double>((static_cast<uint32_t>(blob.base_key) + i) & 0xFFU);
        const auto scaled_key = static_cast<uint8_t>(static_cast<int32_t>(raw_key * fma_scale) & 0xFF);
        const uint8_t dec_byte = MbaXorByte(blob.enc_bytes[i], scaled_key);
        if (dec_byte == 0U) {
            break;
        }
        out.push_back(static_cast<char>(dec_byte));
    }
    return out;
}

/**
 * @brief Initializes the 12 hook framework keywords stored at `.bss 0x02fc40` (`0x021c08..0x021c18`).
 *        Khởi tạo vector 12 từ khóa hook framework lưu tại `.bss 0x02fc40`.
 */
std::vector<std::string> GetDecryptedHookKeywords() {
    std::vector<std::string> keywords;
    keywords.reserve(kEncryptedKeywordTable.size());
    for (const auto& blob : kEncryptedKeywordTable) {
        keywords.push_back(DecryptHookKeywordBlob(blob));
    }
    return keywords;
}

/**
 * @brief Reconstructs `endsWith` (`0x0227b8..0x022878`):
 *        Compares `full_str.size() >= suffix.size()` and `memcmp` on the trailing bytes.
 *        Tái tạo hàm `endsWith` (`0x0227b8..0x022878`).
 */
bool StringEndsWith(const std::string& full_str, const std::string& suffix) noexcept {
    if (full_str.size() < suffix.size()) {
        return false;
    }
    return std::memcmp(full_str.data() + (full_str.size() - suffix.size()),
                       suffix.data(),
                       suffix.size()) == 0;
}

/**
 * @brief Reconstructs `scanMapsForHookFrameworks` (`0x019fb4..0x02207c`, `.data 0x02f940`):
 *   - 0x01a344..0x01a34c: `sscanf(line, "%lx-%lx r", &start_addr, &end_addr)` (`0x004207`)
 *   - 0x01a448..0x01a458: `and x9, x9, #0xffffff8000000000; bfxil x9, x8, #0x27, #0x19; cmp x9, #0`
 *     If non-zero -> logs `"More than 39 bits in maps"` (`0x00448d`) and returns `"use_more_than_39_bits"` (`0x003fb9`).
 *   - 0x01a6d8..0x01a980: Iterates the 12 keywords in `.bss 0x02fc40`, checks `line.find(keyword) != npos`,
 *     and verifies that the trimmed line ends with one of the 5 suffixes constructed on the stack:
 *       1. `".so"`   (`0x01a928`: `0x732e`, `0x6f`)
 *       2. `".jar"`  (`0x01a964`: `0x72616a2e`)
 *       3. `".apk"`  (`0x01aedc`: `0x6b70612e`)
 *       4. `".odex"` (`0x01af1c`: `0x65646f2e`, `0x78`)
 *       5. `".vdex"` (`0x01af64`: `0x6564762e`, `0x78`)
 *   - If matched: logs `"Found hook framework keyword '%s' in maps: %s"` (`0x004a61`) and returns the line.
 *   - Otherwise: logs `"No hook frameworks found in maps"` (`0x004a8f`) and returns `""`.
 */
std::string ScanMapsTextForHookFrameworks(const std::string& maps_content,
                                          std::string* out_log) {
    const std::vector<std::string> keywords = GetDecryptedHookKeywords();
    std::istringstream stream(maps_content);
    std::string line;

    while (std::getline(stream, line)) {
        while (!line.empty() && (line.back() == '\r' || line.back() == '\n')) {
            line.pop_back();
        }
        if (line.empty()) {
            continue;
        }

        // 0x01a344..0x01a354: sscanf(line.c_str(), "%lx-%lx r", &start_addr, &end_addr) == 2
        unsigned long long start_addr = 0ULL;
        unsigned long long end_addr = 0ULL;
        if (std::sscanf(line.c_str(), "%llx-%llx r", &start_addr, &end_addr) == 2) {
            if (HasMoreThan39BitsInVma(static_cast<uint64_t>(start_addr),
                                       static_cast<uint64_t>(end_addr))) {
                if (out_log != nullptr) {
                    *out_log = "GODZILLA: More than 39 bits in maps";
                }
                return "use_more_than_39_bits";
            }
        }

        // 0x01a6d8..0x01afa0: Check each decrypted hook framework keyword
        for (const std::string& kw : keywords) {
            if (kw.empty() || line.find(kw) == std::string::npos) {
                continue;
            }
            const bool valid_ext =
                StringEndsWith(line, ".so")   ||
                StringEndsWith(line, ".jar")  ||
                StringEndsWith(line, ".apk")  ||
                StringEndsWith(line, ".odex") ||
                StringEndsWith(line, ".vdex");
            if (valid_ext) {
                if (out_log != nullptr) {
                    char buf[512];
                    std::snprintf(buf, sizeof(buf),
                                  "Found hook framework keyword '%s' in maps: %s",
                                  kw.c_str(), line.c_str());
                    *out_log = buf;
                }
                return line;
            }
        }
    }

    if (out_log != nullptr) {
        *out_log = "GODZILLA: No hook frameworks found in maps";
    }
    return {};
}

}  // namespace godzilla_sysopt
}  // namespace opencut
}  // namespace nextai
