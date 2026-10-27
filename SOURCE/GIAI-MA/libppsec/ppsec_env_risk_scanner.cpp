/**
 * @file ppsec_env_risk_scanner.cpp
 * @brief Clean-Room Implementation of PIPO SecSDK Environment, Root, Magisk, Cloud-Phone & Clicker Scanner.
 *        Triển khai tái tạo sạch bộ quét môi trường, Root, Magisk, Cloud-Phone và Auto-Clicker của libppsec.so.
 *
 * Binary Target / Mục tiêu nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/libppsec.so (166,400 bytes)
 *
 * Disassembly Anchor Map / Bản đồ neo giải mã AArch64:
 *   - 0x010304..0x0103d4 : Region Code Mapper (`CN`, `SG`, `VA`, `TTP`, `Unknown`)
 *   - 0x012e38..0x013920 : UI Automation & Auto-Clicker Scanner (`/dev/input/event0`, `monkey`, `uiautomator`, 12 packages, `/proc/net/unix`)
 *   - 0x013aec..0x013ec8 : Debugger & `/proc/self/status` `TracerPid:` Scanner
 *   - 0x0142c0..0x0151d8 : Custom ROM (6 JARs) & Cloud-Phone / Docker / RedFinger / Haima Scanner (56 paths)
 *   - 0x0152f0..0x01649c : SELinux `u:r:zygote:s0` (`/proc/self/attr/prev`), Root (`su`), Magisk & `/proc/self/mounts` `.magisk/` Scanner
 *   - 0x0166c0..0x01675c : Regional Risk Host Table (`https://risk-sg.pipopay.com`, `https://risk-va.pipopay.com`, `https://fp.pipopayment.us`)
 *   - 0x01b428..0x01c2ec : 23 Android Build/System Property Collector & `/proc/%d/cmdline` Reader
 */

#include "ppsec_env_risk_scanner.h"

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <sstream>

namespace nextai {
namespace opencut {
namespace ppsec {

/**
 * @brief Resolves the region name (`"CN"`, `"SG"`, `"VA"`, `"TTP"`, `"Unknown"`) (`0x010304..0x0103d4`).
 *        Phân giải tên khu vực từ mã số (`0x010304..0x0103d4`).
 */
std::string ResolvePpsecRegionName(int32_t region_code) noexcept {
    switch (region_code) {
        case PPSEC_REGION_CN:
            return "CN";
        case PPSEC_REGION_SG:
            return "SG";
        case PPSEC_REGION_VA:
            return "VA";
        case PPSEC_REGION_TTP_US:
            return "TTP";
        default:
            return "Unknown";
    }
}

/**
 * @brief Resolves the regional risk telemetry host (`0x0166c0..0x01675c` & `.data 0x02c138..0x02c148`).
 *        Phân giải địa chỉ máy chủ báo cáo rủi ro theo khu vực (`0x0166c0..0x01675c`).
 */
std::string ResolvePpsecRiskHost(int32_t region_code) noexcept {
    switch (region_code) {
        case PPSEC_REGION_SG:
            return kPpsecRiskHostSg;
        case PPSEC_REGION_VA:
            return kPpsecRiskHostVa;
        case PPSEC_REGION_TTP_US:
            return kPpsecRiskHostTtp;
        default:
            return kPpsecRiskHostSg;
    }
}

/**
 * @brief Reconstructs `/proc/self/status` `TracerPid:` parser (`0x013e2c..0x013ec8`).
 *        Tái tạo bộ phân tích `TracerPid:` trong `/proc/self/status` (`0x013e2c..0x013ec8`).
 */
int32_t ParseTracerPidFromProcStatus(const std::string& status_content) noexcept {
    std::istringstream iss(status_content);
    std::string line;
    while (std::getline(iss, line)) {
        if (line.compare(0U, 9U, "TracerPid") == 0) {
            const size_t colon = line.find(':');
            if (colon != std::string::npos) {
                return static_cast<int32_t>(std::atoi(line.c_str() + colon + 1U));
            }
        }
    }
    return 0;
}

/**
 * @brief Reconstructs `/proc/self/mounts` `.magisk/` line scanner (`0x015f90..0x01602c`).
 *        Tái tạo bộ quét `.magisk/` trong `/proc/self/mounts` (`0x015f90..0x01602c`).
 */
bool DetectMagiskInMountsContent(const std::string& mounts_content,
                                 std::vector<std::string>* out_matched_mounts) noexcept {
    if (out_matched_mounts != nullptr) {
        out_matched_mounts->clear();
    }
    bool detected = false;
    std::istringstream iss(mounts_content);
    std::string line;
    while (std::getline(iss, line)) {
        char dev[256]    = {0};
        char mnt[256]    = {0};
        char fstype[256] = {0};
        if (std::sscanf(line.c_str(), "%255[^' '] %255[^' '] %255[^' ']", dev, mnt, fstype) >= 2) {
            if (std::strstr(dev, ".magisk/") != nullptr ||
                std::strstr(mnt, ".magisk/") != nullptr ||
                std::strstr(fstype, ".magisk/") != nullptr) {
                detected = true;
                if (out_matched_mounts != nullptr) {
                    out_matched_mounts->emplace_back(mnt);
                }
            }
        }
    }
    return detected;
}

/**
 * @brief Reconstructs `/proc/self/attr/prev` SELinux domain verifier (`0x0152f0`, `0x016468..0x01649c`).
 *        Tái tạo bộ kiểm tra ngữ cảnh SELinux `/proc/self/attr/prev` với `"u:r:zygote:s0"`.
 */
bool VerifyZygoteSelinuxPrevContext(const std::string& attr_prev_content) noexcept {
    if (attr_prev_content.empty()) {
        return true;
    }
    return (attr_prev_content.find("u:r:zygote:s0") != std::string::npos);
}

/**
 * @brief Reconstructs `/proc/net/unix` `"event.localserver"` scanner (`0x0138b8..0x013920`).
 *        Tái tạo bộ quét socket `"event.localserver"` trong `/proc/net/unix` (`0x0138b8..0x013920`).
 */
bool DetectAutomationUnixSocket(const std::string& proc_net_unix_content) noexcept {
    return (proc_net_unix_content.find("event.localserver") != std::string::npos);
}

/**
 * @brief 26 UI Automation & Auto-Clicker Indicators (`0x012e38..0x013610`).
 *        26 Chỉ báo công cụ tự động hóa UI và Auto-Clicker (`0x012e38..0x013610`).
 */
const std::vector<std::string>& GetPpsecAutoClickerIndicators() noexcept {
    static const std::vector<std::string> kList = {
        "/dev/input/event0",
        "com.android.commands.monkey",
        "com.github.uiautomator",
        "/data/data/com.github.uiautomator",
        "/data/data/simplehat.clicker",
        "/data/data/com.zdanjian.zdanjian",
        "/data/data/com.touch.fairy",
        "/data/data/net.aisence.Touchelper",
        "/data/data/com.touchspriteent.android",
        "/data/data/com.touchsprite.android",
        "/data/data/com.cyjh.mobileanjianen",
        "/data/data/com.cyjh.mobileanjian",
        "/data/data/yk.juejin",
        "/data/data/org.autojs.autojspro",
        "/data/data/org.autojs.autojs",
        "/sdcard/Android/data/com.github.uiautomator",
        "/sdcard/Android/data/simplehat.clicker",
        "/sdcard/Android/data/com.zdanjian.zdanjian",
        "/sdcard/Android/data/com.touch.fairy",
        "/sdcard/Android/data/net.aisence.Touchelper",
        "/sdcard/Android/data/com.touchspriteent.android",
        "/sdcard/Android/data/com.touchsprite.android",
        "/sdcard/Android/data/com.cyjh.mobileanjianen",
        "/sdcard/Android/data/com.cyjh.mobileanjian",
        "/sdcard/Android/data/yk.juejin",
        "/sdcard/Android/data/org.autojs.autojs",
        "/sdcard/Android/data/org.autojs.autojspro",
    };
    return kList;
}

/**
 * @brief 6 Custom ROM Framework JAR Paths (`0x0142c0..0x0143c4`).
 *        6 Đường dẫn JAR nhận diện Custom ROM (`MoKee`, `CyanogenMod`, `LineageOS`).
 */
const std::vector<std::string>& GetPpsecCustomRomJars() noexcept {
    static const std::vector<std::string> kJars = {
        "/system/framework/org.mokee.hardware.jar",
        "/system/framework/org.mokee.platform.jar",
        "/system/framework/org.cyanogenmod.hardware.jar",
        "/system/framework/org.cyanogenmod.platform.jar",
        "/system/framework/org.lineageos.hardware.jar",
        "/system/framework/org.lineageos.platform.jar",
    };
    return kJars;
}

/**
 * @brief 56 Cloud-Phone, Container & Virtualization Paths (`0x0144d8..0x0151d8`).
 *        56 Đường dẫn nhận diện Cloud-Phone, Container và máy ảo (`0x0144d8..0x0151d8`).
 */
const std::vector<std::string>& GetPpsecCloudPhoneIndicators() noexcept {
    static const std::vector<std::string> kCloudPaths = {
        "/vendor/lib/hw/gps.tenc.so",
        "/vendor/lib/hw/gatekeeper.tenc.so",
        "/vendor/etc/fstab.tenc",
        "/vendor/bin/tenc-ethernet.sh",
        "/vendor/bin/tenc-apk-installer.sh",
        "/system/lib/libRkTeeGatekeeper.so",
        "/system/bin/lgserver",
        "/dev/lginput",
        "/sys/class/lginput/",
        "/system/bin/socat",
        "/system/bin/lzbaseband",
        "/system/bin/client",
        "/init.pscloud.rc",
        "/init.dundi.rc",
        "/fstab.pscloud",
        "/system/xbin/ysu",
        "/system/xbin/yp_init.sh",
        "/system/bin/ypremoteview",
        "/system/bin/yp_log",
        "/system/bin/iptables_yp",
        "/system/bin/vclusters_server",
        "/system/bin/vcDistributor",
        "/system/bin/eeprom_tools",
        "/system/bin/android_ttcp",
        "/lxc/lxcfs/",
        "/dev/sdc",
        "/dev/sdb",
        "/dev/cpuset/kube-proxy/",
        "/dev/memcg/docker",
        "/dev/cpuctl/docker",
        "/dev/cpuset/docker",
        "/sys/fs/cgroup/memory/docker",
        "/acct/docker",
        "/data/mac",
        "/data/android_info.conf",
        "/init.hi3660.rc",
        "anbox-init.sh",
        "/system/etc/permissions/monbox.xml",
        "/data/data/com.redfinger.filemanager",
        "/data/data/com.redfinger.monitor",
        "/data/data/com.migu.controller",
        "/data/data/com.migu.agent",
        "/data/data/com.longene.lglocation",
        "/data/data/com.longene.lglocations",
        "/data/data/org.appspot.apprtc",
        "/sdcard/Android/data/com.redfinger.filemanager",
        "/sdcard/Android/data/com.redfinger.monitor",
        "/sdcard/Android/data/com.migu.controller",
        "/sdcard/Android/data/com.migu.agent",
        "/sdcard/Android/data/com.longene.lglocation",
        "/sdcard/Android/data/com.longene.lglocations",
        "/sdcard/Android/data/org.appspot.apprtc",
        "/sys/devices/virtual/redfinger_audio",
        "/sys/class/redfinger_audio",
        "/sys/class/redfinger_camera",
        "/sys/devices/platform/ionfb_redfinger.0",
        "/sys/bus/platform/devices/ionfb_redfinger.0",
        "/system/priv-app/RedFingerFileManager",
        "/system/priv-app/RedFingerLauncher",
        "/system/priv-app/MonitorAppOEM",
        "/system/app/CloudLauncher",
        "/system/bin/ws-server",
        "/system/etc/haima.agent.d",
        "/dev/haima-wfifo",
        "/dev/haima-rfifo",
    };
    return kCloudPaths;
}

/**
 * @brief 42 Root, `su` & Magisk Paths (`0x015324..0x015bac`).
 *        42 Đường dẫn nhận diện Root, `su` và Magisk (`0x015324..0x015bac`).
 */
const std::vector<std::string>& GetPpsecRootAndMagiskPaths() noexcept {
    static const std::vector<std::string> kRootPaths = {
        "/data/data/com.mtk.user2root",
        "/data/data/com.shuame.rootgenius",
        "/data/data/hh.root",
        "/data/data/com.baidu.easyroot",
        "/data/data/com.rd.user2root",
        "/data/data/com.qihoo.permmgr",
        "/data/data/com.devadvance.rootcloak2",
        "/data/data/com.kingroot.kinguser",
        "/sdcard/Android/data/com.mtk.user2root",
        "/sdcard/Android/data/com.shuame.rootgenius",
        "/sdcard/Android/data/hh.root",
        "/sdcard/Android/data/com.baidu.easyroot",
        "/sdcard/Android/data/com.rd.user2root",
        "/sdcard/Android/data/com.qihoo.permmgr",
        "/sdcard/Android/data/com.devadvance.rootcloak2",
        "/sdcard/Android/data/com.kingroot.kinguser",
        "/system/app/Superuser/Superuser.apk",
        "/system/app/Supersupro/Supersupro.apk",
        "/system/app/longeneroot.apk",
        "/sbin/su",
        "/system/bin/sutemp",
        "/system/bin/sudo",
        "/system/xbin/bstk/su",
        "/system/xbin/ku.sud",
        "/system/bin/.su",
        "/su/bin/su",
        "/system/xbin/bdsu",
        "/system/bin/bdsu",
        "/system/xbin/daemonsu",
        "/system/bin/shuamesu",
        "/system/bin/su",
        "/system/xbin/su",
        "/data/magisk.apk",
        "/mnt/vendor/persist/magisk",
        "/data/adb/magisk",
        "/cache/magisk.log",
        "/system/bin/magisk",
        "/bin/.magisk",
        "/sbin/.magisk",
        "/dev/magisk/img",
        "/cache/.disable_magisk",
        "/data/data/com.topjohnwu.magisk",
        "/sdcard/Android/data/com.topjohnwu.magisk",
    };
    return kRootPaths;
}

/**
 * @brief 23 Android Build & System Property Keys (`0x01b428..0x01b93c`).
 *        23 Khóa thuộc tính hệ thống Android được thu thập tại `0x01b428..0x01b93c`.
 */
const std::vector<std::string>& GetPpsecSystemPropertyKeys() noexcept {
    static const std::vector<std::string> kProps = {
        "ro.product.brand",
        "ro.product.model",
        "ro.product.manufacturer",
        "ro.build.display.id",
        "ro.build.version.release",
        "ro.build.fingerprint",
        "ro.build.date.utc",
        "ro.product.board",
        "ro.product.device",
        "ro.product.name",
        "ro.serialno",
        "ro.vendor.serialno",
        "ro.build.version.sdk",
        "ro.bootloader",
        "ro.board.platform",
        "ro.secure",
        "ro.debuggable",
        "sys.usb.state",
        "gsm.sim.operator.numeric",
        "ro.build.tags",
        "ro.build.version.incremental",
        "ro.build.description",
        "ro.oem_unlock_supported",
        "sys.oem_unlock_allowed",
        "init.svc.adbd",
        "gsm.sim.state",
    };
    return kProps;
}

/**
 * @brief Evaluates a complete `PpsecRiskTelemetryReport` (`0x012a00..0x01c400`).
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
    bool jni_debugger_connected) noexcept {
    PpsecRiskTelemetryReport report{};
    report.app_id             = app_id;
    report.did                = did;
    report.iid                = iid;
    report.region             = ResolvePpsecRegionName(region_code);
    report.sdk_version        = kPpsecSdkVersion;
    report.env_version        = kPpsecEnvCollectorVersion;
    report.risk_host          = ResolvePpsecRiskHost(region_code);
    report.tracer_pid         = ParseTracerPidFromProcStatus(proc_status_content);
    report.debugger_connected = jni_debugger_connected || (report.tracer_pid > 0);
    report.selinux_tampered   = !VerifyZygoteSelinuxPrevContext(attr_prev_content);

    const std::set<std::string> path_set(existing_paths.begin(), existing_paths.end());

    for (const auto& ind : GetPpsecAutoClickerIndicators()) {
        if (path_set.count(ind) > 0U) {
            report.automation_detected = true;
            report.matched_indicators.push_back(ind);
        }
    }
    if (DetectAutomationUnixSocket(proc_net_unix_content)) {
        report.automation_detected = true;
        report.matched_indicators.emplace_back("event.localserver");
    }

    for (const auto& jar : GetPpsecCustomRomJars()) {
        if (path_set.count(jar) > 0U) {
            report.custom_rom_detected = true;
            report.matched_indicators.push_back(jar);
        }
    }

    for (const auto& cp : GetPpsecCloudPhoneIndicators()) {
        if (path_set.count(cp) > 0U) {
            report.cloud_phone_detected = true;
            report.matched_indicators.push_back(cp);
        }
    }

    for (const auto& rp : GetPpsecRootAndMagiskPaths()) {
        if (path_set.count(rp) > 0U) {
            if (rp.find("magisk") != std::string::npos) {
                report.magisk_detected = true;
            } else {
                report.root_su_detected = true;
            }
            report.matched_indicators.push_back(rp);
        }
    }

    std::vector<std::string> magisk_mounts;
    if (DetectMagiskInMountsContent(proc_mounts_content, &magisk_mounts)) {
        report.magisk_detected = true;
        report.matched_indicators.insert(
            report.matched_indicators.end(), magisk_mounts.begin(), magisk_mounts.end());
    }

    return report;
}

}  // namespace ppsec
}  // namespace opencut
}  // namespace nextai
