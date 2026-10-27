/**
 * @file ppsec_string_deobfuscator.cpp
 * @brief Clean-Room Implementation of Pairwise-XOR String Deobfuscator (`0x004714`) & OLLVM Opaque Predicates.
 *        Triển khai tái tạo sạch bộ giải mã chuỗi XOR (`0x004714`) và các vị từ mờ OLLVM/Tigress của libppsec.so.
 *
 * Binary Target / Mục tiêu nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/libppsec.so (166,400 bytes)
 *
 * Disassembly Anchor Map / Bản đồ neo giải mã AArch64:
 *   - 0x002b38..0x002bc4 : OLLVM Quadratic Modular Inverse (`0xa1af286c`, `0x0d79435e`) in `register_IlIlllIiI`
 *   - 0x002dd4..0x003160 : OLLVM Quadratic, Consecutive-3-Integer (`0xaaaaaaaaaaaaaaab`) & Pell's Equation (`x^2 + 1 == 7*y^2`) in `JNI_OnLoad`
 *   - 0x0031ac..0x003268 : OLLVM Bitwise-Transformed Quadratic (`0x286bca1b`) in `IlIllLIiI(String, int, boolean)`
 *   - 0x004714..0x004740 : Pairwise Byte-Array XOR String Decryptor (`sub_4714`, called 183 times across `.text`)
 *   - 0x018968..0x01898c : Mixed Boolean-Arithmetic (MBA) XOR `(a | b) - (a & b)` & Increment `((i << 1) | 2) - (i ^ 1)`
 */

#include "ppsec_string_deobfuscator.h"

namespace nextai {
namespace opencut {
namespace ppsec {

namespace {

/**
 * @brief 64x64->128-bit unsigned high multiplication (`umulh` in AArch64).
 *        Phép nhân không dấu 64-bit trả về 64-bit cao tương ứng với lệnh `umulh` trên AArch64.
 */
uint64_t Umulh64(uint64_t a, uint64_t b) noexcept {
#if defined(__SIZEOF_INT128__)
    return static_cast<uint64_t>((static_cast<unsigned __int128>(a) * static_cast<unsigned __int128>(b)) >> 64U);
#else
    const uint64_t a_lo = a & 0xFFFFFFFFULL;
    const uint64_t a_hi = a >> 32U;
    const uint64_t b_lo = b & 0xFFFFFFFFULL;
    const uint64_t b_hi = b >> 32U;
    const uint64_t p0 = a_lo * b_lo;
    const uint64_t p1 = a_lo * b_hi;
    const uint64_t p2 = a_hi * b_lo;
    const uint64_t p3 = a_hi * b_hi;
    const uint64_t middle = p1 + (p0 >> 32U) + (p2 & 0xFFFFFFFFULL);
    return p3 + (middle >> 32U) + (p2 >> 32U);
#endif
}

}  // namespace

/**
 * @brief Reconstructs `sub_4714` (`0x004714..0x004740`):
 *        `dst[i] = src[i] ^ key[i]` while `key[i] != 0`.
 *        Tái tạo hàm giải mã chuỗi XOR từng cặp byte `sub_4714` (`0x004714..0x004740`).
 */
size_t XorDeobfuscateNullTerminated(const uint8_t* src,
                                    uint8_t* dst,
                                    const uint8_t* key,
                                    size_t max_len) noexcept {
    if (src == nullptr || dst == nullptr || key == nullptr || max_len == 0U) {
        return 0U;
    }

    uint8_t k = key[0];
    if (k == 0U) {
        return 0U;
    }

    size_t i = 0U;
    int32_t next_idx = 1;
    while (i < max_len) {
        dst[i] = static_cast<uint8_t>(src[i] ^ k);
        i = static_cast<size_t>(static_cast<int64_t>(next_idx));
        if (i >= max_len) {
            break;
        }
        k = key[i];
        next_idx += 1;
        if (k == 0U) {
            break;
        }
    }
    if (i < max_len) {
        dst[i] = 0U;
    }
    return i;
}

std::string XorDeobfuscateToString(const uint8_t* src,
                                   const uint8_t* key,
                                   size_t max_len) noexcept {
    if (src == nullptr || key == nullptr || max_len == 0U) {
        return {};
    }
    std::vector<uint8_t> buf(max_len + 1U, 0U);
    const size_t n = XorDeobfuscateNullTerminated(src, buf.data(), key, max_len);
    return std::string(reinterpret_cast<const char*>(buf.data()), n);
}

/**
 * @brief Reconstructs OLLVM Quadratic Modular Inverse Predicate (`0x002b40..0x002b70`, `0x002dd4..0x002e08`):
 *        `mul w8, w8, w8; madd w8, w8, w11, w11; cmp w8, w9` where `w11 = 0xA1AF286C`, `w9 = 0x0D79435E`.
 *        When `x = 0x1A0` (`416`), `(416^2 + 1) * 0xA1AF286C mod 2^32 = 0x0D79435E` (`true`).
 *        When `x = 0x42` (`66`), `(66^2 + 1) * 0xA1AF286C mod 2^32 = 0x9C69D708 != 0x0D79435E` (`false`).
 *        Tái tạo vị từ mờ bậc hai nghịch đảo modulo (`0x002b40..0x002b70`, `0x002dd4..0x002e08`).
 */
bool EvaluateQuadraticModInversePredicate(uint32_t x) noexcept {
    const uint32_t x_sq = x * x;
    const uint32_t lhs  = (x_sq * kOllvmQuadMultiplierA) + kOllvmQuadMultiplierA;
    return (lhs == kOllvmQuadTarget);
}

/**
 * @brief Reconstructs OLLVM Bitwise-Transformed Quadratic Predicate (`0x0031ac..0x00320c`):
 *        `mul w8, w8, w8; lsl w13, w8, #2; lsl w8, w8, #3; eor w13, w13, #4; orr w8, w8, #8; sub w8, w8, w13; mul w8, w8, w11`
 *        where `w11 = 0x286BCA1B`.
 *        Tái tạo vị từ mờ bậc hai biến đổi bit (`0x0031ac..0x00320c`).
 */
bool EvaluateBitwiseQuadraticPredicate(uint32_t x) noexcept {
    const uint32_t x_sq = x * x;
    const uint32_t w13  = (x_sq << 2U) ^ 4U;
    const uint32_t w8   = ((x_sq << 3U) | 8U) - w13;
    const uint32_t prod = w8 * kOllvmQuadMultiplierB;
    return (prod == kOllvmQuadTarget);
}

/**
 * @brief Reconstructs OLLVM 3-Consecutive-Integers Divisibility-by-6 Offset (`0x002ee0..0x002f14`, `0x003218..0x00325c`):
 *        `p = n * (n + 1) * (n + 2)`; `q = umulh(p, 0xAAAAAAAAAAAAAAABULL) >> 1`;
 *        `even_q = (q >> 1) << 1`; `three_even_q = (even_q << 1) + (q >> 1)`;
 *        returns `p - three_even_q == 0`.
 *        Tái tạo hằng đẳng thức chia hết cho 6 của tích 3 số nguyên liên tiếp (`0x002ee0..0x002f14`).
 */
uint64_t EvaluateConsecutiveTripleMod6Offset(uint64_t n) noexcept {
    const uint64_t p      = n * (n + 1ULL) * (n + 2ULL);
    const uint64_t u      = Umulh64(p, kOllvmDiv3Magic);
    const uint64_t half_q = u >> 2U;
    const uint64_t even_q = half_q << 1U;
    const uint64_t sub    = (even_q << 1U) + (u >> 1U);
    return p - sub;
}

/**
 * @brief Reconstructs OLLVM 2-Consecutive-Integers Parity Offset (`0x002fe4..0x002ff4`, `0x003210..0x003238`).
 *        Tái tạo hằng đẳng thức tính chẵn lẻ của tích 2 số nguyên liên tiếp (`(n * (n + 1)) & 1 == 0`).
 */
uint32_t EvaluateConsecutivePairParityOffset(uint32_t n) noexcept {
    return (n * (n + 1U)) & 1U;
}

/**
 * @brief Reconstructs OLLVM Pell's Equation Predicate (`0x003048..0x0030b4`):
 *        `x * x + 1 == 7 * y * y` (mod 2^32).
 *        Note: modulo 4, `x^2 + 1` is `1` or `2` (mod 4), whereas `7 * y^2 ≡ 3 * y^2` is `0` or `3` (mod 4),
 *        so `x^2 + 1 == 7*y^2 (mod 2^32)` has ZERO solutions for ANY 32-bit integers `(x, y)`!
 *        Tái tạo vị từ mờ phương trình Pell `x^2 + 1 == 7*y^2` (`0x003048..0x0030b4`, vô nghiệm modulo 4).
 */
bool EvaluatePell7Equation(uint32_t x, uint32_t y) noexcept {
    const uint32_t lhs = (x * x) + 1U;
    const uint32_t y2  = y * y;
    const uint32_t rhs = (y2 << 3U) - y2;
    return (lhs == rhs);
}

/**
 * @brief Reconstructs Mixed Boolean-Arithmetic (MBA) XOR & Increment Identities (`0x018968..0x01898c`).
 *        Tái tạo đồng nhất thức MBA XOR `(a | b) - (a & b)` và tăng 1 `((i << 1) | 2) - (i ^ 1)`.
 */
uint32_t MbaXorOrSubAnd(uint32_t a, uint32_t b) noexcept {
    return (a | b) - (a & b);
}

uint32_t MbaIncrementBy1(uint32_t i) noexcept {
    const uint32_t xor1 = i ^ 1U;
    const uint32_t shl  = (i << 1U) | 2U;
    return shl - xor1;
}

/**
 * @brief Complete catalog of decrypted `.rodata` string entries verified from `libppsec.so` (`0x002d64..0x01c2ec`).
 *        Danh mục đầy đủ các chuỗi `.rodata` đã giải mã từ `libppsec.so` (`0x002d64..0x01c2ec`).
 */
const std::vector<PpsecXorStringEntry>& GetPpsecDecryptedStringCatalog() noexcept {
    static const std::vector<PpsecXorStringEntry> kCatalog = {
        // 1. JNI Classes, Methods & Signatures (0x002d64, 0x0115bc, 0x01a130..0x01a6f0)
        {0x002D64U, 0x01C920U, 0x02C160U, 0x01C9D0U, "com/bytedance/pipo/sec/IlIlllIiI"},
        {0x0115BCU, 0x0216C0U, 0x02CAD0U, 0x021700U, "com/bytedance/pipo/sec/CryptTool"},
        {0x01A130U, 0x024610U, 0x02E4C0U, 0x024810U, "java/util/HashMap"},
        {0x01A164U, 0x024624U, 0x02E4D8U, 0x024808U, "<init>"},
        {0x01A198U, 0x02462CU, 0x02E4E4U, 0x024800U, "(I)V"},
        {0x01A1CCU, 0x024634U, 0x02E4F0U, 0x0247FCU, "put"},
        {0x01A200U, 0x024640U, 0x02E500U, 0x0247C0U, "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;"},
        {0x01A620U, 0x024680U, 0x02E560U, 0x024790U, "com/bytedance/pipo/sec/IlIlllIiI"},
        {0x01A654U, 0x0246A4U, 0x02E588U, 0x02477CU, "IlIllLIiL"},
        {0x01A688U, 0x0246B0U, 0x02E598U, 0x024774U, "([B)[B"},
        {0x01A6BCU, 0x0246B8U, 0x02E5A4U, 0x024768U, "(I[B[B[B)[B"},
        {0x01A6F0U, 0x0246D0U, 0x02E5C0U, 0x024720U, "(Ljava/lang/String;[BLjava/util/Map;Ljava/util/Map;)Ljava/lang/Object;"},

        // 2. Cryptographic Headers, Keys, Versions & Regional Endpoints (0x0058bc..0x018a38)
        {0x0058BCU, 0x01CA00U, 0x02C358U, 0x01D044U, "BPEM"},
        {0x007A8CU, 0x01CA10U, 0x02C6D0U, 0x01D030U, "y1B9Q#2020072zzzz"},
        {0x007B30U, 0x01CA30U, 0x02C6F0U, 0x01D010U, "072y1Bvz9Q3#20vz0"},
        {0x00FE20U, 0x02161CU, 0x02CA6CU, 0x0216B0U, "appid"},
        {0x00FFC4U, 0x021624U, 0x02CA78U, 0x0216A8U, "region"},
        {0x010304U, 0x02166CU, 0x02CAA8U, 0x02169CU, "TTP"},
        {0x010338U, 0x021668U, 0x02CAA4U, 0x021698U, "VA"},
        {0x01036CU, 0x021664U, 0x02CAA0U, 0x021694U, "SG"},
        {0x0103A0U, 0x021660U, 0x02CA9CU, 0x021690U, "CN"},
        {0x0103D4U, 0x021634U, 0x02CA94U, 0x021688U, "Unknown"},
        {0x0105C4U, 0x02162CU, 0x02CA84U, 0x0216A4U, "did"},
        {0x010810U, 0x021630U, 0x02CA8CU, 0x0216A0U, "iid"},
        {0x011414U, 0x021670U, 0x02CAC0U, 0x02167CU, "cold_start"},
        {0x011AF8U, 0x021724U, 0x02CAF8U, 0x02177CU, "pkgname"},
        {0x011B60U, 0x021734U, 0x02CB10U, 0x02176CU, "appver"},
        {0x011BC8U, 0x021744U, 0x02CB28U, 0x02175CU, "apppath"},
        {0x011BFCU, 0x02174CU, 0x02CB34U, 0x021754U, "sdkver"},
        {0x012A64U, 0x02178CU, 0x02CB4CU, 0x021794U, "2.0.3"},
        {0x0166C0U, 0x024220U, 0x02E3F0U, 0x0242A0U, "https://fp.pipopayment.us"},
        {0x0166F4U, 0x024200U, 0x02E3D0U, 0x024280U, "https://risk-va.pipopay.com"},
        {0x016728U, 0x0241E0U, 0x02E3B0U, 0x024260U, "https://risk-sg.pipopay.com"},
        {0x01675CU, 0x02423CU, 0x02E41CU, 0x024248U, "risk_host"},
        {0x0187D4U, 0x0243CCU, 0x02E480U, 0x0245F4U, "19572"},
        {0x01B21CU, 0x024824U, 0x02E618U, 0x02482CU, "1.2.7"},

        // 3. Automation, Auto-Clicker & Debugger Indicators (0x012e38..0x013ec8)
        {0x012E38U, 0x0217B0U, 0x02CC30U, 0x022120U, "/dev/input/event0"},
        {0x012F0CU, 0x0217D0U, 0x02CC50U, 0x022100U, "com.android.commands.monkey"},
        {0x013038U, 0x0217F0U, 0x02CC70U, 0x0220E0U, "com.github.uiautomator"},
        {0x013164U, 0x021C50U, 0x02D0F0U, 0x022070U, "/data/data/com.github.uiautomator"},
        {0x013198U, 0x021C30U, 0x02D0D0U, 0x022050U, "/data/data/simplehat.clicker"},
        {0x0131CCU, 0x021C00U, 0x02D0A0U, 0x022020U, "/data/data/com.zdanjian.zdanjian"},
        {0x013200U, 0x021BE0U, 0x02D080U, 0x022000U, "/data/data/com.touch.fairy"},
        {0x013234U, 0x021BB0U, 0x02D050U, 0x021FD0U, "/data/data/net.aisence.Touchelper"},
        {0x013268U, 0x021B80U, 0x02D020U, 0x021FA0U, "/data/data/com.touchspriteent.android"},
        {0x01329CU, 0x021B50U, 0x02CFF0U, 0x021F70U, "/data/data/com.touchsprite.android"},
        {0x0132D0U, 0x021B20U, 0x02CFC0U, 0x021F40U, "/data/data/com.cyjh.mobileanjianen"},
        {0x013304U, 0x021AF0U, 0x02CF90U, 0x021F10U, "/data/data/com.cyjh.mobileanjian"},
        {0x013338U, 0x021AD0U, 0x02CF70U, 0x021EF0U, "/data/data/yk.juejin"},
        {0x01336CU, 0x021AB0U, 0x02CF50U, 0x021ED0U, "/data/data/org.autojs.autojspro"},
        {0x0133A0U, 0x021A90U, 0x02CF30U, 0x021EB0U, "/data/data/org.autojs.autojs"},
        {0x0138B8U, 0x021820U, 0x02CCB8U, 0x0220B8U, "/proc/net/unix"},
        {0x013920U, 0x021840U, 0x02CCE0U, 0x0220A0U, "event.localserver"},
        {0x013AECU, 0x022140U, 0x02D180U, 0x022200U, "android/os/Debug"},
        {0x013B20U, 0x022160U, 0x02D1A0U, 0x0221E0U, "isDebuggerConnected"},
        {0x013E2CU, 0x022180U, 0x02D1C0U, 0x0221C0U, "/proc/self/status"},
        {0x013E94U, 0x022198U, 0x02D1E0U, 0x0221ACU, "TracerPid"},

        // 4. Custom ROM, Cloud Phone, Container, Root & Magisk Indicators (0x0142c0..0x01649c)
        {0x0142C0U, 0x022310U, 0x02D2F0U, 0x023590U, "/system/framework/org.mokee.hardware.jar"},
        {0x014328U, 0x0222B0U, 0x02D290U, 0x023530U, "/system/framework/org.cyanogenmod.hardware.jar"},
        {0x014390U, 0x022250U, 0x02D230U, 0x0234D0U, "/system/framework/org.lineageos.hardware.jar"},
        {0x014A88U, 0x022890U, 0x02D890U, 0x023140U, "/dev/memcg/docker"},
        {0x014C90U, 0x022770U, 0x02D770U, 0x023020U, "/data/data/com.redfinger.filemanager"},
        {0x0152F0U, 0x0235BCU, 0x02DCF0U, 0x0241C0U, "u:r:zygote:s0"},
        {0x015490U, 0x023960U, 0x02E0A0U, 0x024030U, "/data/data/com.kingroot.kinguser"},
        {0x015700U, 0x023764U, 0x02DEA4U, 0x023E34U, "/sbin/su"},
        {0x01593CU, 0x023648U, 0x02DD8CU, 0x023D14U, "/system/bin/su"},
        {0x015970U, 0x023638U, 0x02DD7CU, 0x023D04U, "/system/xbin/su"},
        {0x0159A4U, 0x023BB0U, 0x02E370U, 0x023CF0U, "/data/magisk.apk"},
        {0x015A0CU, 0x023B70U, 0x02E330U, 0x023CB0U, "/data/adb/magisk"},
        {0x015B78U, 0x023AC0U, 0x02E280U, 0x023C00U, "/data/data/com.topjohnwu.magisk"},
        {0x015F90U, 0x0235CCU, 0x02DD04U, 0x0241B4U, ".magisk/"},
        {0x015FC4U, 0x0235E0U, 0x02DD20U, 0x0241A0U, "/proc/self/mounts"},
        {0x01649CU, 0x023620U, 0x02DD60U, 0x024160U, "/proc/self/attr/prev"},

        // 5. 23 Android Build & System Properties (0x01b428..0x01c2ec)
        {0x01B428U, 0x024850U, 0x02E630U, 0x024D60U, "ro.product.brand"},
        {0x01B45CU, 0x024870U, 0x02E650U, 0x024D40U, "ro.product.model"},
        {0x01B490U, 0x024890U, 0x02E670U, 0x024D20U, "ro.product.manufacturer"},
        {0x01B4C4U, 0x0248B0U, 0x02E690U, 0x024D00U, "ro.build.display.id"},
        {0x01B4F8U, 0x0248D0U, 0x02E6B0U, 0x024CE0U, "ro.build.version.release"},
        {0x01B52CU, 0x0248F0U, 0x02E6D0U, 0x024CC0U, "ro.build.fingerprint"},
        {0x01B560U, 0x024910U, 0x02E6F0U, 0x024CA0U, "ro.build.date.utc"},
        {0x01B594U, 0x024930U, 0x02E710U, 0x024C80U, "ro.product.board"},
        {0x01B5C8U, 0x024950U, 0x02E730U, 0x024C60U, "ro.product.device"},
        {0x01B5FCU, 0x024964U, 0x02E748U, 0x024C50U, "ro.product.name"},
        {0x01B630U, 0x024974U, 0x02E75CU, 0x024C44U, "ro.serialno"},
        {0x01B664U, 0x024980U, 0x02E770U, 0x024C30U, "ro.vendor.serialno"},
        {0x01B698U, 0x0249A0U, 0x02E790U, 0x024C10U, "ro.build.version.sdk"},
        {0x01B6CCU, 0x0249B8U, 0x02E7ACU, 0x024BF4U, "ro.bootloader"},
        {0x01B700U, 0x0249D0U, 0x02E7C0U, 0x024BE0U, "ro.board.platform"},
        {0x01B734U, 0x0249E4U, 0x02E7D8U, 0x024BCCU, "ro.secure"},
        {0x01B768U, 0x0249F0U, 0x02E7E8U, 0x024BBCU, "ro.debuggable"},
        {0x01B79CU, 0x024A00U, 0x02E7FCU, 0x024BACU, "sys.usb.state"},
        {0x01B7D0U, 0x024A10U, 0x02E810U, 0x024B90U, "gsm.sim.operator.numeric"},
        {0x01B804U, 0x024A2CU, 0x02E830U, 0x024B80U, "ro.build.tags"},
        {0x01B838U, 0x024A40U, 0x02E850U, 0x024B60U, "ro.build.version.incremental"},
        {0x01B86CU, 0x024A60U, 0x02E880U, 0x024B40U, "ro.build.description"},
        {0x01B8A0U, 0x024A80U, 0x02E8A0U, 0x024B20U, "ro.oem_unlock_supported"},
        {0x01B8D4U, 0x024AA0U, 0x02E8C0U, 0x024B00U, "sys.oem_unlock_allowed"},
        {0x01B908U, 0x024AB8U, 0x02E8DCU, 0x024AE8U, "init.svc.adbd"},
        {0x01B93CU, 0x024AC8U, 0x02E8F0U, 0x024AD8U, "gsm.sim.state"},
        {0x01C0C8U, 0x024D90U, 0x02E910U, 0x024DC0U, "/proc/%d/cmdline"},
        {0x01C2ECU, 0x024DA8U, 0x02E930U, 0x024DB0U, "/proc"},
    };
    return kCatalog;
}

}  // namespace ppsec
}  // namespace opencut
}  // namespace nextai
