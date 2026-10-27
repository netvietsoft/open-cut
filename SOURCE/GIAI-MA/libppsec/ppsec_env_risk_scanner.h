/**
 * @file ppsec_env_risk_scanner.h
 * @brief Clean-Room Header for PIPO SecSDK Environment, Root, Magisk, Cloud-Phone & Clicker Scanner.
 *        Header tái tạo sạch bộ quét môi trường, Root, Magisk, Cloud-Phone và Auto-Clicker của libppsec.so.
 *
 * Binary Target / Mục tiêu nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/libppsec.so
 *   Addresses covered / Phạm vi địa chỉ:
 *     - 0x00fd80..0x011190 : Session initialization (`appid`, `did`, `iid`, `region` `CN`/`SG`/`VA`/`TTP`)
 *     - 0x012e00..0x013a00 : UI Automation & Auto-Clicker Scanner (`monkey`, `uiautomator`, 12 clicker packages, `event.localserver`)
 *     - 0x013a80..0x014200 : Debugger & `/proc/self/status` `TracerPid:` Scanner
 *     - 0x014250..0x015250 : Custom ROM (`mokee`, `cyanogenmod`, `lineageos`) & Cloud-Phone (`redfinger`, `haima`, `docker`) Scanner
 *     - 0x015280..0x016600 : Root, `su`, Magisk & `/proc/self/mounts` (`.magisk/`) + SELinux (`u:r:zygote:s0`) Scanner
 *     - 0x016650..0x0185fb : Regional Risk Host Resolver & Zlib Deflate Telemetry Uploader
 *     - 0x01b3d0..0x01c350 : 23 Android Build/System Property Collector & `/proc/%d/cmdline` Reader
 */

#ifndef NEXTAI_OPENCUT_PPSEC_ENV_RISK_SCANNER_H_
#define NEXTAI_OPENCUT_PPSEC_ENV_RISK_SCANNER_H_

#include "ppsec_types.h"

#include <cstdint>
#include <map>
#include <string>
#include <vector>

namespace nextai {
namespace opencut {
namespace ppsec {

/**
 * @brief Resolves the region name (`"CN"`, `"SG"`, `"VA"`, `"TTP"`, `"Unknown"`) and default risk host
 *        (`0x010304..0x0103d4` & `0x0166c0..0x01675c`).
 *        Phân giải mã khu vực và máy chủ báo cáo rủi ro mặc định (`0x010304..0x01675c`).
 */
std::string ResolvePpsecRegionName(int32_t region_code) noexcept;
std::string ResolvePpsecRiskHost(int32_t region_code) noexcept;

/**
 * @brief Reconstructs the `/proc/self/status` `TracerPid:` parser (`0x013e2c..0x013ec8`).
 *        Tái tạo bộ phân tích trường `TracerPid:` trong `/proc/self/status` (`0x013e2c..0x013ec8`).
 */
int32_t ParseTracerPidFromProcStatus(const std::string& status_content) noexcept;

/**
 * @brief Reconstructs the `/proc/self/mounts` `.magisk/` line scanner (`0x015f90..0x01602c`):
 *        Uses `sscanf(line, "%[^' '] %[^' '] %[^' ']", dev, mnt, fstype)` and checks for `".magisk/"`.
 *        Tái tạo bộ quét dòng `.magisk/` trong `/proc/self/mounts` (`0x015f90..0x01602c`).
 */
bool DetectMagiskInMountsContent(const std::string& mounts_content,
                                 std::vector<std::string>* out_matched_mounts) noexcept;

/**
 * @brief Reconstructs the `/proc/self/attr/prev` SELinux domain verifier (`0x0152f0`, `0x016468..0x01649c`):
 *        Checks whether the previous SELinux context matches `"u:r:zygote:s0"`.
 *        Tái tạo bộ kiểm tra ngữ cảnh SELinux `/proc/self/attr/prev` với `"u:r:zygote:s0"` (`0x0152f0`).
 */
bool VerifyZygoteSelinuxPrevContext(const std::string& attr_prev_content) noexcept;

/**
 * @brief Reconstructs the `/proc/net/unix` local automation socket scanner (`0x0138b8..0x013920`):
 *        Checks for `"event.localserver"` UNIX domain socket.
 *        Tái tạo bộ quét socket tự động hóa `"event.localserver"` trong `/proc/net/unix` (`0x0138b8..0x013920`).
 */
bool DetectAutomationUnixSocket(const std::string& proc_net_unix_content) noexcept;

/**
 * @brief Returns the exact indicator lists decrypted inside `libppsec.so`:
 *        - 26 UI Automation / Auto-Clicker paths & package names (`0x012e38..0x0137ac`)
 *        - 6 Custom ROM framework JAR paths (`0x0142c0..0x0143c4`)
 *        - 56 Cloud-Phone, Container & Emulator paths (`0x0144d8..0x0151d8`)
 *        - 42 Root, `su` & Magisk paths (`0x015324..0x015bac`)
 *        - 23 Android System Property keys (`0x01b428..0x01b93c`)
 *        Trả về danh sách các chỉ báo bảo mật giải mã từ `libppsec.so`.
 */
const std::vector<std::string>& GetPpsecAutoClickerIndicators() noexcept;
const std::vector<std::string>& GetPpsecCustomRomJars() noexcept;
const std::vector<std::string>& GetPpsecCloudPhoneIndicators() noexcept;
const std::vector<std::string>& GetPpsecRootAndMagiskPaths() noexcept;
const std::vector<std::string>& GetPpsecSystemPropertyKeys() noexcept;

/**
 * @brief Evaluates a complete `PpsecRiskTelemetryReport` against a set of observed filesystem paths,
 *        `/proc/self/status`, `/proc/self/mounts`, `/proc/self/attr/prev`, and `/proc/net/unix`.
 *        Đánh giá báo cáo rủi ro thiết bị toàn diện `PpsecRiskTelemetryReport`.
 */
PpsecRiskTelemetryReport EvaluatePpsecEnvironmentRisk(
    const std::string& app_id,
    const std::string& did,
    const std::string& iid,
    int32_t region_code,
    const std::vector<std::string>& existing_paths,
    const std::string& proc_status_content,
    const std::string& proc_mounts_content,
    const std::string& attr_prev_content,
    const std::string& proc_net_unix_content,
    bool jni_debugger_connected) noexcept;

}  // namespace ppsec
}  // namespace opencut
}  // namespace nextai

#endif  // NEXTAI_OPENCUT_PPSEC_ENV_RISK_SCANNER_H_
