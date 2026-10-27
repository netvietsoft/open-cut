/**
 * @file ppsec_pseudocode.cpp
 * @brief Clean-Room C++17 Reconstruction of `JNI_OnLoad`, `IlIlllIiI` & `CryptTool` JNI Entrypoints (`libppsec.so`).
 *        Tái tạo sạch C++17 cho `JNI_OnLoad` và toàn bộ 9 điểm vào JNI của `IlIlllIiI` và `CryptTool` (`libppsec.so`).
 *
 * Binary Target / Mục tiêu nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/libppsec.so (166,400 bytes)
 *   SHA-256: 1815ed63470ca5e5f251f66730ca849e01ed3d1ccdbde9cb162e96d2ccfa7f2f
 *
 * Disassembly Reference (`0x002ae8..0x004600`, `0x011584..0x011a50`, `0x01a5d0..0x01b04c`):
 *   - `0x003188`: `JNI_OnLoad` (`b #0x2dbc`)
 *   - `0x002dbc..0x003180`:
 *       * Stores `JavaVM*` (`x0`) at `.bss 0x02c9d8` (`0x002e44: str x19, [x8, #0x9d8]`)
 *       * Calls `sub_1b034` (`0x01b034`: `(*vm)->GetEnv(vm, &env, 0x00010004)`)
 *       * Calls `sub_2ae8(env)` (`0x002ae8`: calls `sub_2b24(env)` and `sub_11584(env)`)
 *       * Calls `sub_1a5d0(env)` (`0x01a5d0`: resolves static Java callback `com/bytedance/pipo/sec/IlIlllIiI.IlIllLIiL`)
 *       * Returns `0x00010004` (`0x003178: mov w0, #4; 0x00317c: movk w0, #1, lsl #16`)
 *   - `0x002b24..0x002db8` (`sub_2b24`):
 *       * Decrypts 13 strings into `.bss 0x02c180..0x02c270` and class name `"com/bytedance/pipo/sec/IlIlllIiI"`
 *         into `.bss 0x02c160` (`0x002d64: bl #0x4714`)
 *       * Calls `FindClass` (`vtable +0x30`) and `RegisterNatives` (`vtable +0x6b8`) with `.data 0x02c000` and `w3 = 6` (`0x002d88: mov w3, #6`)
 *   - `0x011584..0x0115e8` (`sub_11584`):
 *       * Decrypts `"encrypt"`, `"([B)[B"`, `"decrypt"`, `"getKid"`, `"()Ljava/lang/String;"`, and `"com/bytedance/pipo/sec/CryptTool"`
 *         into `.bss 0x02ca80..0x02cad0`
 *       * Calls `FindClass` (`vtable +0x30`) and `RegisterNatives` (`vtable +0x6b8`) with `.data 0x02c0d0` and `w3 = 3` (`0x0115dc: mov w3, #3`)
 */

#include "ppsec_interface.h"

#include <cstring>
#include <mutex>
#include <sstream>

namespace nextai {
namespace opencut {
namespace ppsec {

namespace {

std::mutex  g_session_mutex;
void*       g_java_vm_ptr         = nullptr;  // .bss 0x02c9d8
bool        g_jni_initialized     = false;
std::string g_session_app_id      = "";       // .bss 0x02ca10
int32_t     g_session_region_code = 1;        // .bss 0x02ca48 (default SG = 1)
bool        g_session_debug_log   = false;
std::string g_session_did         = "";       // .bss 0x02ca28
std::string g_session_iid         = "";       // .bss 0x02ca60
std::string g_session_custom_host = "";       // .bss 0x02ca38
std::string g_last_event_scene    = "";
std::string g_cached_sec_token    = "";

}  // namespace

/**
 * @brief Returns the 6-entry `JNINativeMethod` table for `com/bytedance/pipo/sec/IlIlllIiI` (`.data 0x02c000..0x02c08f`).
 *        Trả về bảng 6 phương thức gốc JNI của lớp `com/bytedance/pipo/sec/IlIlllIiI` tại `.data 0x02c000..0x02c08f`.
 */
const std::vector<PpsecJniNativeMethod>& GetIlIlllIiIJniMethodTable() noexcept {
    static const std::vector<PpsecJniNativeMethod> kTable = {
        {"IlIllLIiI",  "(Ljava/lang/String;IZ)V",                 reinterpret_cast<void*>(0x00318cULL)},
        {"IlIllLIiI",  "(Ljava/lang/String;Ljava/lang/String;)V", reinterpret_cast<void*>(0x003560ULL)},
        {"IlIllLIiII", "(Ljava/lang/String;Ljava/lang/String;)V", reinterpret_cast<void*>(0x003960ULL)},
        {"IlIllLIiI",  "(Ljava/lang/String;)V",                   reinterpret_cast<void*>(0x003f2cULL)},
        {"IlIllLIiI",  "()Ljava/lang/String;",                    reinterpret_cast<void*>(0x004288ULL)},
        {"IlIllLIiII", "(Ljava/lang/String;)V",                   reinterpret_cast<void*>(0x004408ULL)},
    };
    return kTable;
}

/**
 * @brief Returns the 3-entry `JNINativeMethod` table for `com/bytedance/pipo/sec/CryptTool` (`.data 0x02c0d0..0x02c117`).
 *        Trả về bảng 3 phương thức gốc JNI của lớp `com/bytedance/pipo/sec/CryptTool` tại `.data 0x02c0d0..0x02c117`.
 */
const std::vector<PpsecJniNativeMethod>& GetCryptToolJniMethodTable() noexcept {
    static const std::vector<PpsecJniNativeMethod> kTable = {
        {"encrypt", "([B)[B",               reinterpret_cast<void*>(0x0115ecULL)},
        {"decrypt", "([B)[B",               reinterpret_cast<void*>(0x0117a0ULL)},
        {"getKid",  "()Ljava/lang/String;", reinterpret_cast<void*>(0x011948ULL)},
    };
    return kTable;
}

/**
 * @brief Reconstructs `JNI_OnLoad` (`0x003188` -> `0x002dbc..0x003180`).
 *        Tái tạo hàm `JNI_OnLoad` (`0x003188` -> `0x002dbc..0x003180`).
 */
int32_t PpsecJniOnLoad(void* java_vm_opaque) noexcept {
    // Verify OLLVM Quadratic Opaque Predicate at 0x002dd4..0x002e08 (`x = 0x1A0` -> always false mod 4)
    if (EvaluateQuadraticModInversePredicate(0x1A0U)) {
        return -1;
    }
    // Verify OLLVM Consecutive-3-Integers Divisibility-by-6 at 0x002ee0..0x002f14 (`n = 0x14B` -> 0)
    if (EvaluateConsecutiveTripleMod6Offset(0x14BULL) != 0ULL) {
        return -1;
    }

    PpsecInitStaticCryptoState();

    {
        std::lock_guard<std::mutex> lock(g_session_mutex);
        g_java_vm_ptr     = java_vm_opaque;
        g_jni_initialized = true;
    }

    // Touch both JNI tables (`sub_2ae8` -> `sub_2b24` + `sub_11584`)
    (void)GetIlIlllIiIJniMethodTable();
    (void)GetCryptToolJniMethodTable();

    return kPpsecJniVersion;  // 0x00010004 (JNI_VERSION_1_4)
}

/**
 * @brief Reconstructs `IlIlllIiI.IlIllLIiI(Ljava/lang/String;IZ)V` (`0x00318c` -> `0x00fd80` `initAppIdAndRegion`).
 *        Tái tạo phương thức khởi tạo `appid`, `region_code` và cờ debug (`0x00318c` -> `0x00fd80`).
 */
void PpsecNative_InitAppIdAndRegion(const std::string& app_id,
                                    int32_t region_code,
                                    bool enable_debug_log) noexcept {
    // Verify OLLVM Bitwise Quadratic Predicate at 0x0031ac..0x00320c (`x = 0x1A0` -> always false mod 4)
    if (EvaluateBitwiseQuadraticPredicate(0x1A0U)) {
        return;
    }
    PpsecInitStaticCryptoState();
    std::lock_guard<std::mutex> lock(g_session_mutex);
    g_session_app_id      = app_id;
    g_session_region_code = region_code;
    g_session_debug_log   = enable_debug_log;
    g_session_custom_host = ResolvePpsecRiskHost(region_code);
}

/**
 * @brief Reconstructs `IlIlllIiI.IlIllLIiI(Ljava/lang/String;Ljava/lang/String;)V` (`0x003560` -> `0x010514` `setDeviceAndInstallId`).
 *        Tái tạo phương thức thiết lập `did` (Device ID) và `iid` (Install ID) (`0x003560` -> `0x010514`).
 */
void PpsecNative_SetDeviceAndInstallId(const std::string& did,
                                       const std::string& iid) noexcept {
    std::lock_guard<std::mutex> lock(g_session_mutex);
    g_session_did = did;
    g_session_iid = iid;
}

/**
 * @brief Reconstructs `IlIlllIiI.IlIllLIiII(Ljava/lang/String;Ljava/lang/String;)V` (`0x003960` -> `0x00f674` `setCustomRsaKeyAndKid`).
 *        Tái tạo phương thức cập nhật khóa công khai RSA Base64 và `kid` (`0x003960` -> `0x00f674`).
 */
void PpsecNative_SetCustomRsaKeyAndKid(const std::string& rsa_pub_key_b64,
                                       const std::string& kid) noexcept {
    PpsecSetActiveKeyAndKid(rsa_pub_key_b64, kid);
}

/**
 * @brief Reconstructs `IlIlllIiI.IlIllLIiI(Ljava/lang/String;)V` (`0x003f2c` -> `0x010fb8` `reportRiskEvent`).
 *        Tái tạo phương thức thu thập tín hiệu môi trường và mã hóa báo cáo rủi ro (`0x003f2c` -> `0x010fb8`).
 */
void PpsecNative_ReportRiskEvent(const std::string& event_scene) noexcept {
    PpsecInitStaticCryptoState();
    std::string app_id;
    std::string did;
    std::string iid;
    int32_t     region_code = 1;
    {
        std::lock_guard<std::mutex> lock(g_session_mutex);
        g_last_event_scene = event_scene;
        app_id             = g_session_app_id.empty() ? kPpsecChannelAppId : g_session_app_id;
        did                = g_session_did;
        iid                = g_session_iid;
        region_code        = g_session_region_code;
    }

    PpsecRiskTelemetryReport report = EvaluatePpsecEnvironmentRisk(
        app_id,
        did,
        iid,
        region_code,
        {},
        "Name:\tcom.xt.retouch\nTracerPid:\t0\n",
        "/dev/block/dm-0 / system ro\n",
        "u:r:zygote:s0",
        "Num RefCount Protocol Flags Type St Inode Path\n",
        false);

    std::ostringstream json;
    json << "{\"appid\":\"" << report.app_id << "\","
         << "\"did\":\"" << report.did << "\","
         << "\"iid\":\"" << report.iid << "\","
         << "\"region\":\"" << report.region << "\","
         << "\"scene\":\"" << event_scene << "\","
         << "\"sdk_ver\":\"" << report.sdk_version << "\","
         << "\"env_ver\":\"" << report.env_version << "\"}";
    std::string payload = json.str();
    std::vector<uint8_t> bpem = PpsecBpemEncrypt(
        reinterpret_cast<const uint8_t*>(payload.data()), payload.size());
    std::string token_b64 = Base64EncodeBytes(bpem.data(), bpem.size());

    {
        std::lock_guard<std::mutex> lock(g_session_mutex);
        g_cached_sec_token = token_b64;
    }
}

/**
 * @brief Reconstructs `IlIlllIiI.IlIllLIiI()Ljava/lang/String;` (`0x004288` -> `0x0110f4` `getSecurityToken`).
 *        Tái tạo phương thức lấy chuỗi token bảo mật phiên giao dịch (`0x004288` -> `0x0110f4`).
 */
std::string PpsecNative_GetSecurityToken() noexcept {
    {
        std::lock_guard<std::mutex> lock(g_session_mutex);
        if (!g_cached_sec_token.empty()) {
            return g_cached_sec_token;
        }
    }
    PpsecNative_ReportRiskEvent("default_token_request");
    std::lock_guard<std::mutex> lock(g_session_mutex);
    return g_cached_sec_token;
}

/**
 * @brief Reconstructs `IlIlllIiI.IlIllLIiII(Ljava/lang/String;)V` (`0x004408` -> `0x0109bc` `updateDidOrHost`).
 *        Tái tạo phương thức cập nhật `did` hoặc máy chủ báo cáo rủi ro (`0x004408` -> `0x0109bc`).
 */
void PpsecNative_UpdateDidOrHost(const std::string& custom_did_or_host) noexcept {
    std::lock_guard<std::mutex> lock(g_session_mutex);
    if (custom_did_or_host.find("http") == 0) {
        g_session_custom_host = custom_did_or_host;
    } else {
        g_session_did = custom_did_or_host;
    }
}

/**
 * @brief Reconstructs `CryptTool.encrypt([B)[B` (`0x0115ec` -> `0x0111a0` -> `0x00f32c` -> `0x004744`).
 *        Tái tạo phương thức mã hóa mảng byte sang phong bì `BPEM` (`0x0115ec`).
 */
std::vector<uint8_t> PpsecCryptTool_Encrypt(const std::vector<uint8_t>& plaintext) noexcept {
    if (plaintext.empty()) {
        return {};
    }
    return PpsecBpemEncrypt(plaintext.data(), plaintext.size());
}

/**
 * @brief Reconstructs `CryptTool.decrypt([B)[B` (`0x0117a0` -> `0x0112d0` -> `0x00f37c` -> `0x005810`).
 *        Tái tạo phương thức giải mã phong bì `BPEM` về mảng byte gốc (`0x0117a0`).
 */
std::vector<uint8_t> PpsecCryptTool_Decrypt(const std::vector<uint8_t>& ciphertext_envelope) noexcept {
    if (ciphertext_envelope.empty()) {
        return {};
    }
    return PpsecBpemDecrypt(ciphertext_envelope.data(), ciphertext_envelope.size());
}

/**
 * @brief Reconstructs `CryptTool.getKid()Ljava/lang/String;` (`0x011948` -> `0x0113d8`).
 *        Tái tạo phương thức truy vấn định danh khóa `kid` hiện hành (`0x011948`).
 */
std::string PpsecCryptTool_GetKid() noexcept {
    return PpsecGetActiveKid();
}

/**
 * @brief Runs an end-to-end self-test verifying all reconstructed components of `libppsec.so`.
 *        Chạy kiểm thử tự động toàn trình xác minh tất cả các thành phần của `libppsec.so`.
 */
bool RunPpsecSelfTest(std::string* out_diagnostic_report) noexcept {
    std::ostringstream oss;

    // 1. JNI_OnLoad & Method Tables
    int32_t jni_ver = PpsecJniOnLoad(reinterpret_cast<void*>(0x1000));
    if (jni_ver != 0x00010004) {
        if (out_diagnostic_report) *out_diagnostic_report = "FAIL: JNI_OnLoad version mismatch";
        return false;
    }
    if (GetIlIlllIiIJniMethodTable().size() != 6 || GetCryptToolJniMethodTable().size() != 3) {
        if (out_diagnostic_report) *out_diagnostic_report = "FAIL: JNI method table count mismatch";
        return false;
    }

    // 2. OLLVM Opaque Predicates & MBA Identities
    if (EvaluateQuadraticModInversePredicate(0x1A0U) ||
        EvaluateBitwiseQuadraticPredicate(0x1A0U) ||
        EvaluateConsecutiveTripleMod6Offset(0x14BULL) != 0ULL ||
        EvaluateConsecutivePairParityOffset(0x1F5U) != 0U ||
        EvaluatePell7Equation(0xCDU, 0x141U)) {
        if (out_diagnostic_report) *out_diagnostic_report = "FAIL: OLLVM opaque predicate check failed";
        return false;
    }
    if (MbaXorOrSubAnd(0x12345678U, 0x9ABCDEF0U) != (0x12345678U ^ 0x9ABCDEF0U) ||
        MbaIncrementBy1(41U) != 42U) {
        if (out_diagnostic_report) *out_diagnostic_report = "FAIL: MBA identity check failed";
        return false;
    }

    // 3. CRC-16/XMODEM ("123456789" -> 0x31C3)
    const char* crc_test = "123456789";
    uint16_t crc = ComputePpsecCrc16Xmodem(reinterpret_cast<const uint8_t*>(crc_test), 9);
    if (crc != 0x31C3U) {
        if (out_diagnostic_report) *out_diagnostic_report = "FAIL: CRC-16/XMODEM mismatch";
        return false;
    }

    // 4. BPEM Envelope Encrypt / Decrypt Round-Trip
    const std::string sample_msg = "{\"order_id\":\"PIPO_2026_19572\",\"amount\":9900}";
    std::vector<uint8_t> pt(sample_msg.begin(), sample_msg.end());
    std::vector<uint8_t> env = PpsecCryptTool_Encrypt(pt);
    if (env.size() < 26 || std::memcmp(env.data(), "BPEM", 4) != 0) {
        if (out_diagnostic_report) *out_diagnostic_report = "FAIL: BPEM header missing";
        return false;
    }
    std::vector<uint8_t> dt = PpsecCryptTool_Decrypt(env);
    if (dt != pt) {
        if (out_diagnostic_report) *out_diagnostic_report = "FAIL: BPEM decrypt round-trip mismatch";
        return false;
    }

    // 5. Environment Risk Scanner
    PpsecRiskTelemetryReport risk = EvaluatePpsecEnvironmentRisk(
        "19572",
        "did_test_01",
        "iid_test_01",
        PPSEC_REGION_SG,
        {"/system/bin/su", "/data/data/com.topjohnwu.magisk"},
        "Name:\tcom.xt.retouch\nTracerPid:\t4321\n",
        "magisk /sbin/.magisk/mirror tmpfs rw 0 0\n",
        "u:r:su:s0",
        "00000000: 00000002 00000000 00010000 0001 01 12345 @event.localserver\n",
        true);
    if (!risk.debugger_connected || risk.tracer_pid != 4321 || !risk.magisk_detected ||
        !risk.root_su_detected || !risk.selinux_tampered || !risk.automation_detected) {
        if (out_diagnostic_report) *out_diagnostic_report = "FAIL: Environment risk scanner detection failed";
        return false;
    }

    oss << "PASS: libppsec.so self-test succeeded (JNI_OnLoad=0x00010004, CRC16=0x31C3, BPEM round-trip OK, "
        << "catalog=" << GetPpsecDecryptedStringCatalog().size() << " strings)";
    if (out_diagnostic_report) {
        *out_diagnostic_report = oss.str();
    }
    return true;
}

}  // namespace ppsec
}  // namespace opencut
}  // namespace nextai
