/**
 * @file godzilla_sysopt_pseudocode.cpp
 * @brief Clean-Room Master Orchestrator, JNI Entry Points, DWARF Unwinder & Self-Verification Suite
 *        for libgodzilla-sysopt.so.
 *        Bộ điều phối trung tâm, 10 hàm xuất JNI, trình tháo gỡ DWARF EH-frame và bộ tự kiểm chứng
 *        cho libgodzilla-sysopt.so.
 *
 * Binary Target / Mục tiêu nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/libgodzilla-sysopt.so
 *   Size / Dung lượng: 164,440 bytes
 *   SHA-256: 28605f81e2c8d9d0fae96d52a70efc5192c90d93377ddadff09726874911d704
 */

#include "godzilla_sysopt_interface.h"

#include <cstdio>
#include <cstring>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

namespace nextai {
namespace opencut {
namespace godzilla_sysopt {

namespace {

GodzillaSysoptRuntime& GetGlobalRuntime() {
    static GodzillaSysoptRuntime instance;
    return instance;
}

std::string ExtractApkCertAndSha256FromFile(const char* apk_path) {
    if (apk_path == nullptr || apk_path[0] == '\0') {
        return {};
    }
    std::ifstream file(apk_path, std::ios::binary | std::ios::ate);
    if (!file.is_open()) {
        return {};
    }
    const std::streamsize sz = file.tellg();
    if (sz <= 0) {
        return {};
    }
    file.seekg(0, std::ios::beg);
    std::vector<uint8_t> bytes(static_cast<size_t>(sz));
    if (!file.read(reinterpret_cast<char*>(bytes.data()), sz)) {
        return {};
    }
    return ExtractApkCertAndCalculateSha256FromZipBytes(bytes.data(), bytes.size());
}

std::string FindApkPathFromProcSelfMaps(const std::string& package_hint) {
    std::ifstream file("/proc/self/maps");
    if (!file.is_open()) {
        return {};
    }
    std::ostringstream ss;
    ss << file.rdbuf();
    return FindApkPathFromMapsText(ss.str(), package_hint);
}

std::string ScanProcSelfMapsForHooks() {
    std::ifstream file("/proc/self/maps");
    if (!file.is_open()) {
        return {};
    }
    std::ostringstream ss;
    ss << file.rdbuf();
    return ScanMapsTextForHookFrameworks(ss.str());
}

/**
 * @brief Global Indirect Function Pointer Table in `.data` [OBSERVED at 0x02f818..0x02f940]
 *        Bảng con trỏ hàm gián tiếp toàn cục trong `.data` [QUAN SÁT ĐƯỢC tại 0x02f818..0x02f940]
 *
 * - `.data 0x02f818` (file offset `0x027818`) = `0x00abdc` (`calculateSHA256FromCert`)
 * - `.data 0x02f8a0` (file offset `0x0278a0`) = `0x0141ec` (`findApkPathFromMaps`)
 * - `.data 0x02f900` (file offset `0x027900`) = `0x00afcc` (`extractApkCertAndCalculateSha256`)
 * - `.data 0x02f940` (file offset `0x027940`) = `0x019fb4` (`scanMapsForHookFrameworks`)
 */
const GodzillaSysoptDispatchTable kGlobalDispatchTable = {
    &CalculateSha256FromCert,
    &FindApkPathFromProcSelfMaps,
    &ExtractApkCertAndSha256FromFile,
    &ScanProcSelfMapsForHooks
};

}  // namespace

/**
 * @brief Embedded DWARF EH-Frame ULEB128 / SLEB128 Decoder [OBSERVED at 0x0238b0..0x023a10]
 *        Bộ giải mã ULEB128 / SLEB128 trong trình tháo gỡ ngoại lệ DWARF (`getULEB128` @ `0x00469d`,
 *        `getSLEB128` @ `0x004732`).
 */
bool DecodeDwarfUleb128(const uint8_t** io_cursor,
                        const uint8_t* end,
                        uint64_t* out_val,
                        std::string* out_error = nullptr) noexcept {
    if (io_cursor == nullptr || *io_cursor == nullptr || out_val == nullptr) {
        return false;
    }
    uint64_t result = 0ULL;
    unsigned int shift = 0U;
    const uint8_t* p = *io_cursor;

    while (p < end) {
        const uint8_t byte = *p++;
        if (shift >= 64U && (byte & 0x7FU) != 0U) {
            if (out_error != nullptr) {
                *out_error = "malformed uleb128 expression";
            }
            return false;
        }
        result |= static_cast<uint64_t>(byte & 0x7FU) << shift;
        shift += 7U;
        if ((byte & 0x80U) == 0U) {
            *io_cursor = p;
            *out_val = result;
            return true;
        }
    }

    if (out_error != nullptr) {
        *out_error = "truncated uleb128 expression";
    }
    return false;
}

bool DecodeDwarfSleb128(const uint8_t** io_cursor,
                        const uint8_t* end,
                        int64_t* out_val,
                        std::string* out_error = nullptr) noexcept {
    if (io_cursor == nullptr || *io_cursor == nullptr || out_val == nullptr) {
        return false;
    }
    uint64_t result = 0ULL;
    unsigned int shift = 0U;
    const uint8_t* p = *io_cursor;
    uint8_t byte = 0U;

    while (p < end) {
        byte = *p++;
        result |= static_cast<uint64_t>(byte & 0x7FU) << shift;
        shift += 7U;
        if ((byte & 0x80U) == 0U) {
            if (shift < 64U && (byte & 0x40U) != 0U) {
                result |= (~0ULL << shift);
            }
            *io_cursor = p;
            *out_val = static_cast<int64_t>(result);
            return true;
        }
    }

    if (out_error != nullptr) {
        *out_error = "truncated sleb128 expression";
    }
    return false;
}

/**
 * @brief Runs a 6-part self-verification suite across all reconstructed subsystems of `libgodzilla-sysopt.so`.
 *        Chạy bộ tự kiểm chứng 6 phần trên toàn bộ các phân hệ tái tạo của `libgodzilla-sysopt.so`.
 */
bool RunGodzillaSysoptSelfTest() {
    // 1. Verify Opaque Predicate invariants (.data 0x02f988 / 0x02f99c)
    if (kDefaultOpaquePredicateBlock.EvaluateIntQuotientDelta() != 1) {
        return false;
    }
    if (kDefaultOpaquePredicateBlock.EvaluateFmaScale() != 1.0) {
        return false;
    }

    // 2. Verify all 12 MBA rolling-XOR hook framework keywords
    const auto& blobs = GetEncryptedHookKeywordBlobs();
    for (const auto& blob : blobs) {
        if (DecryptHookKeywordBlob(blob) != blob.expected_plaintext) {
            return false;
        }
    }

    // 3. Verify >39-bit VMA bitmask detector (0x01a448..0x01a450)
    if (HasMoreThan39BitsInVma(0x0000007000000000ULL, 0x0000007FFFFFFFFFULL)) {
        return false;
    }
    if (!HasMoreThan39BitsInVma(0x0000008000000000ULL, 0x0000008000001000ULL)) {
        return false;
    }

    // 4. Verify SHA-256 engine on NIST test vector "abc"
    const uint8_t abc[] = {'a', 'b', 'c'};
    const std::string sha_abc = ComputeSha256Hex(abc, sizeof(abc));
    if (sha_abc != "ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad") {
        return false;
    }

    // 5. Verify PthreadCreateHook stack size & SIGBUS BUS_ADRERR 3-retry state machine
    GodzillaSysoptRuntime rt;
    std::string log_out;
    rt.StartPthreadCreateHook(0, &log_out);
    if (rt.ApplyHookedPthreadStackSize(1048576U) != kDefaultPthreadStackSize) {
        return false;
    }
    rt.StartThreadSigbusHook(&log_out);
    if (!rt.HandleSigbusSignal(kSigbusSignalNumber, kSigbusAdrErrCode, 0x70001000ULL)) return false; // retry 1
    if (!rt.HandleSigbusSignal(kSigbusSignalNumber, kSigbusAdrErrCode, 0x70001000ULL)) return false; // retry 2
    if (!rt.HandleSigbusSignal(kSigbusSignalNumber, kSigbusAdrErrCode, 0x70001000ULL)) return false; // retry 3
    if (rt.HandleSigbusSignal(kSigbusSignalNumber, kSigbusAdrErrCode, 0x70001000ULL))  return false; // retry 4 -> chain!

    // 6. Verify /proc/self/maps scanner for both hook keyword + valid suffix and >39-bit VMA
    const std::string sample_maps =
        "7000000000-7000004000 r-xp 00000000 fd:00 1234 /data/app/libfrida-gadget.so\n";
    if (ScanMapsTextForHookFrameworks(sample_maps) !=
        "7000000000-7000004000 r-xp 00000000 fd:00 1234 /data/app/libfrida-gadget.so") {
        return false;
    }

    return true;
}

}  // namespace godzilla_sysopt
}  // namespace opencut
}  // namespace nextai

// ============================================================================
// 10 Exported JNI Entry Points (.dynsym 0x00819c..0x01828c)
// 10 Điểm vào JNI xuất khẩu (.dynsym 0x00819c..0x01828c)
// ============================================================================

extern "C" {

void Java_com_bytedance_platform_godzilla_sysopt_IvimageOpt_start(
    GodzillaJniEnvPtr /*env*/,
    GodzillaJClass /*clazz*/) {
    nextai::opencut::godzilla_sysopt::GetGlobalRuntime().StartIvimageOpt();
}

void Java_com_bytedance_platform_godzilla_sysopt_IvimageOpt_end(
    GodzillaJniEnvPtr /*env*/,
    GodzillaJClass /*clazz*/) {
    nextai::opencut::godzilla_sysopt::GetGlobalRuntime().EndIvimageOpt();
}

void Java_com_bytedance_platform_godzilla_sysopt_UbsanOpt_start(
    GodzillaJniEnvPtr /*env*/,
    GodzillaJClass /*clazz*/) {
    nextai::opencut::godzilla_sysopt::GetGlobalRuntime().StartUbsanOpt();
}

void Java_com_bytedance_platform_godzilla_sysopt_UbsanOpt_end(
    GodzillaJniEnvPtr /*env*/,
    GodzillaJClass /*clazz*/) {
    nextai::opencut::godzilla_sysopt::GetGlobalRuntime().EndUbsanOpt();
}

void Java_com_bytedance_platform_godzilla_sysopt_PthreadCreateHook_start(
    GodzillaJniEnvPtr /*env*/,
    GodzillaJClass /*clazz*/,
    GodzillaJInt stack_size_bytes) {
    nextai::opencut::godzilla_sysopt::GetGlobalRuntime().StartPthreadCreateHook(stack_size_bytes);
}

void Java_com_bytedance_platform_godzilla_sysopt_PthreadCreateHook_end(
    GodzillaJniEnvPtr /*env*/,
    GodzillaJClass /*clazz*/) {
    nextai::opencut::godzilla_sysopt::GetGlobalRuntime().EndPthreadCreateHook();
}

void Java_com_bytedance_platform_godzilla_sysopt_ThreadHook_start(
    GodzillaJniEnvPtr /*env*/,
    GodzillaJClass /*clazz*/) {
    nextai::opencut::godzilla_sysopt::GetGlobalRuntime().StartThreadSigbusHook();
}

void Java_com_bytedance_platform_godzilla_sysopt_ThreadHook_end(
    GodzillaJniEnvPtr /*env*/,
    GodzillaJClass /*clazz*/) {
    nextai::opencut::godzilla_sysopt::GetGlobalRuntime().EndThreadSigbusHook();
}

GodzillaJString Java_com_bytedance_platform_godzilla_sysopt_ApkSha256_checkMyShit(
    GodzillaJniEnvPtr /*env*/,
    GodzillaJClass /*clazz*/,
    GodzillaJString package_hint) {
    static thread_local std::string s_last_sha256;
    const char* hint_cstr = reinterpret_cast<const char*>(package_hint);
    const std::string hint = (hint_cstr != nullptr) ? hint_cstr : "";
    const std::string apk_path =
        nextai::opencut::godzilla_sysopt::kGlobalDispatchTable.find_apk_path_from_maps(hint);
    if (apk_path.empty()) {
        s_last_sha256.clear();
        return reinterpret_cast<GodzillaJString>(const_cast<char*>(s_last_sha256.c_str()));
    }
    s_last_sha256 =
        nextai::opencut::godzilla_sysopt::kGlobalDispatchTable.extract_apk_cert_and_sha256(apk_path.c_str());
    return reinterpret_cast<GodzillaJString>(const_cast<char*>(s_last_sha256.c_str()));
}

GodzillaJString Java_com_bytedance_platform_godzilla_sysopt_ApkSha256_checkHookFrameworks(
    GodzillaJniEnvPtr /*env*/,
    GodzillaJClass /*clazz*/) {
    static thread_local std::string s_last_hook_result;
    s_last_hook_result =
        nextai::opencut::godzilla_sysopt::kGlobalDispatchTable.scan_maps_for_hook_frameworks();
    return reinterpret_cast<GodzillaJString>(const_cast<char*>(s_last_hook_result.c_str()));
}

}  // extern "C"
