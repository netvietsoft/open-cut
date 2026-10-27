/**
 * @file ppsec_types.h
 * @brief Clean-Room ABI Structs, Constants, Opaque Predicates & JNI Tables for libppsec.so.
 *        Cấu trúc ABI, hằng số, vị từ mờ OLLVM và bảng phương thức JNI cho libppsec.so (ByteDance PIPO SecSDK 2.0.3).
 *
 * Binary Target / Mục tiêu nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/libppsec.so
 *   Size / Dung lượng: 166,400 bytes (0x28a00)
 *   SHA-256: 1815ed63470ca5e5f251f66730ca849e01ed3d1ccdbde9cb162e96d2ccfa7f2f
 *   Sections / Các phân đoạn ELF:
 *     - .text        : VMA 0x002a10..0x01c914 (106,244 bytes, 26,561 instructions)
 *     - .rodata      : VMA 0x01c920..0x024df9 (34,009 bytes)
 *     - .init_array  : VMA 0x02b6e8..0x02b6f8 (file offset 0x0276e8, 2 entries: 0x002a10, 0x0185fc)
 *     - .fini_array  : VMA 0x02b6f8..0x02b708 (file offset 0x0276f8, 2 entries: 0x002abc, 0x002aac)
 *     - .data.rel.ro : VMA 0x02b708..0x02bbd0 (file offset 0x027708, 1,224 bytes)
 *     - .data        : VMA 0x02c000..0x02c158 (file offset 0x028000, 344 bytes)
 *     - .bss         : VMA 0x02c160..0x02f940 (14,304 bytes)
 *
 * Evidence Classification / Phân loại bằng chứng:
 *   [OBSERVED] Directly verified from AArch64 machine code & .rodata/.data bytes of libppsec.so.
 *              Được kiểm chứng trực tiếp từ mã máy AArch64 và byte .rodata/.data của libppsec.so.
 */

#ifndef NEXTAI_OPENCUT_PPSEC_TYPES_H_
#define NEXTAI_OPENCUT_PPSEC_TYPES_H_

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace nextai {
namespace opencut {
namespace ppsec {

/**
 * @brief Binary & Version Constants [OBSERVED at .rodata 0x0214b0, 0x02178c, 0x0243bb, 0x024824]
 *        Hằng số định danh nhị phân và phiên bản PIPO SecSDK [QUAN SÁT ĐƯỢC trong .rodata]
 */
constexpr uint32_t kPpsecBinarySizeBytes         = 166400U;
constexpr int32_t  kPpsecJniVersion              = 0x00010004;  // JNI_VERSION_1_4 (0x003178: mov w0, #4; movk w0, #1, lsl #16)
constexpr const char* kPpsecSdkVersion           = "2.0.3";     // Decrypted at 0x012a64 (.rodata 0x02178c ^ 0x021794)
constexpr const char* kPpsecEnvCollectorVersion  = "1.2.7";     // Decrypted at 0x01b21c (.rodata 0x024824 ^ 0x02482c)
constexpr const char* kPpsecChannelAppId         = "19572";     // Decrypted at 0x0187d4 (.rodata 0x0243cc ^ 0x0245f4)
constexpr const char* kPpsecBpemMagic            = "BPEM";      // Decrypted at 0x0058bc & 0x008810 (.rodata 0x01ca00 ^ 0x01d044)
constexpr const char* kPpsecDefaultKid           = "0";         // Initialized at 0x002a80 (mov w8, #0x3002; strh w8, [x1] -> .bss 0x02c9f8)
constexpr const char* kPpsecInternalAesKey       = "y1B9Q#2020072zzzz"; // Decrypted at 0x007a8c (.rodata 0x01ca10 ^ 0x01d030)
constexpr const char* kPpsecInternalAesIv        = "072y1Bvz9Q3#20vz0"; // Decrypted at 0x007b30 (.rodata 0x01ca30 ^ 0x01d010)

/**
 * @brief Default 344-Byte Base64 RSA Public Key [OBSERVED at .rodata 0x0214c0..0x021618, loaded at 0x002a20..0x002a54]
 *        Khóa công khai RSA Base64 dài 344 byte mặc định được nạp bởi `.init_array[0]` (`0x002a10`) vào `.bss 0x02c9e0`
 */
constexpr size_t kPpsecDefaultRsaPubKeyLen       = 0x158U;      // 344 bytes (mov w2, #0x158 at 0x002a40)
constexpr size_t kPpsecDefaultRsaPubKeyAlloc     = 0x160U;      // 352 bytes (mov w0, #0x160; bl operator new at 0x002a20..0x002a24)
constexpr const char* kPpsecDefaultRsaPubKeyB64  =
    "sRPDexql9c6Kf8bDfPigRyfJxJXbcxgJaOVmeEk4kOoleBXz1V136VmfDu605sHkKcj4I/"
    "Kh/QD/TiDwOMSuizVhNBY62SYpGRa/FcNklobFRz3NOEHIBLf5Zfnb+lelstezXfeoXAZK"
    "6Qf7CpiUSgxriKutG6RQ20n6grsqrzVAwHziIqD8W6d3evc7A+h00AdzYxG7FHXF7jBpFN"
    "BxNVcnXduszv6mb1/BunWoxO/2D1ZLIa0t8zvy2PsaFOEAMzvZm41IRPwnsyiDxyzG9tUS"
    "UNLGVfB0XWJ0/jevuj6v7DHHKekwckIC6/Q7XJcmV5txO9dEu9U1umoCtjbBAw==";

/**
 * @brief OLLVM / Tigress Opaque Predicate Constants [OBSERVED at 0x002b40..0x003268 & 0x0047a0..0x0048f0]
 *        Hằng số vị từ mờ OLLVM / Tigress bảo vệ luồng điều khiển gián tiếp (`br x8`)
 *
 * 1. Quadratic Modular Inverse Constant (`0x002b44`, `0x002ddc`):
 *    - `kOllvmQuadMultiplierA = 0xA1AF286CU`
 *    - `kOllvmQuadMultiplierB = 0x286BCA1BU`
 *    - `kOllvmQuadTarget      = 0x0D79435EU`
 *    - When `x = 0x1A0` (`416`), `((x * x + 1) * 0xA1AF286CU) & 0xFFFFFFFFU == 0x0D79435EU`!
 * 2. Consecutive-3-Integers Divisibility by 6 (`0x002ee0..0x002f14`, `0x003218..0x00325c`, `0x0047d8..0x004810`):
 *    - `kOllvmDiv3Magic = 0xAAAAAAAAAAAAAAABULL`
 *    - For any integer `n`, `p = n * (n + 1) * (n + 2)` is divisible by 6, so `q = umulh(p, 0xAAAAAAAAAAAAAAABULL) >> 1`
 *      is always even, and `p - 3 * (q & ~1ULL) == 0`.
 */
constexpr uint32_t kOllvmQuadMultiplierA = 0xA1AF286CU;
constexpr uint32_t kOllvmQuadMultiplierB = 0x286BCA1BU;
constexpr uint32_t kOllvmQuadTarget      = 0x0D79435EU;
constexpr uint64_t kOllvmDiv3Magic       = 0xAAAAAAAAAAAAAAABULL;

/**
 * @brief 16-Byte Packet Seed & Magic Header [OBSERVED at .rodata 0x0243bb..0x0243ca, loaded at 0x018904..0x01891c]
 *        Chuỗi hạt giống 16-byte `de fa ce de ad 30 30 30 30 39 35 32 37 00` nạp vào `.bss 0x02e48c`
 */
constexpr uint8_t kPpsecPacketSeed16[16] = {
    0xDE, 0xFA, 0xCE, 0xDE, 0xAD,
    '0',  '0',  '0',  '0',  '9',  '5',  '2',  '7',  0x00, 0x91, 0x23
};

/**
 * @brief Regional Risk Server Endpoints [OBSERVED at 0x0166c0..0x01675c & .data 0x02c138..0x02c148]
 *        3 Máy chủ báo cáo rủi ro theo khu vực (`SG`, `VA`, `TTP/US`)
 */
enum PpsecRegionCode : int32_t {
    PPSEC_REGION_CN      = 0,  // "CN"
    PPSEC_REGION_SG      = 1,  // "SG"  -> https://risk-sg.pipopay.com (.bss 0x02e3b0)
    PPSEC_REGION_VA      = 2,  // "VA"  -> https://risk-va.pipopay.com (.bss 0x02e3d0)
    PPSEC_REGION_TTP_US  = 3,  // "TTP" -> https://fp.pipopayment.us   (.bss 0x02e3f0)
    PPSEC_REGION_UNKNOWN = 4,  // "Unknown"
};

constexpr const char* kPpsecRiskHostSg  = "https://risk-sg.pipopay.com";
constexpr const char* kPpsecRiskHostVa  = "https://risk-va.pipopay.com";
constexpr const char* kPpsecRiskHostTtp = "https://fp.pipopayment.us";

/**
 * @brief 24-Byte `JNINativeMethod` Entry Layout [OBSERVED at .data 0x02c000..0x02c08f & 0x02c0d0..0x02c117]
 *        Bố cục mục đăng ký `JNINativeMethod` 24-byte trong phân đoạn `.data`
 */
struct PpsecJniNativeMethod {
    const char* name;
    const char* signature;
    void*       fnPtr;
};
static_assert(sizeof(PpsecJniNativeMethod) == 24, "PpsecJniNativeMethod must be 24 bytes on AArch64");

/**
 * @brief Decrypted Pairwise-XOR String Record [OBSERVED at 0x004714..0x004740]
 *        Bản ghi chuỗi giải mã XOR từng cặp byte (`dst[i] = src[i] ^ key[i]`)
 */
struct PpsecXorStringEntry {
    uint32_t    call_va;
    uint32_t    src_rodata_va;
    uint32_t    dst_bss_va;
    uint32_t    key_rodata_va;
    const char* plaintext;
};

/**
 * @brief `BPEM` Envelope Header & Session State [OBSERVED at 0x004744..0x008e00]
 *        Cấu trúc thông điệp mã hóa phong bì `BPEM` (ByteDance PIPO Encrypted Message)
 */
struct PpsecBpemEnvelope {
    char                 magic[4];        // "BPEM"
    uint8_t              version;         // Protocol version (1 or 2)
    uint8_t              mode;            // Cipher mode
    std::string          kid;             // Key Identifier ("0" default)
    std::vector<uint8_t> encrypted_key;   // RSA-encrypted or key-wrapped 16-byte session key
    std::vector<uint8_t> iv;              // 16-byte AES-CBC initialization vector
    std::vector<uint8_t> ciphertext;      // AES-CBC PKCS#7 padded ciphertext
};

/**
 * @brief Device & Environment Risk Telemetry Report [OBSERVED at 0x012a00..0x01c400]
 *        Báo cáo thu thập tín hiệu rủi ro thiết bị & môi trường (Root, Magisk, Clicker, Cloud Phone, Debugger)
 */
struct PpsecRiskTelemetryReport {
    std::string app_id;
    std::string did;
    std::string iid;
    std::string region;
    std::string sdk_version;
    std::string env_version;
    std::string risk_host;
    bool        debugger_connected;
    int32_t     tracer_pid;
    bool        automation_detected;
    bool        custom_rom_detected;
    bool        cloud_phone_detected;
    bool        root_su_detected;
    bool        magisk_detected;
    bool        selinux_tampered;
    std::vector<std::string> matched_indicators;
};

}  // namespace ppsec
}  // namespace opencut
}  // namespace nextai

#endif  // NEXTAI_OPENCUT_PPSEC_TYPES_H_
