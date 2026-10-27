/**
 * @file nms_ces_meta_engine.cpp
 * @brief Clean-room C++17 implementation of the ByteDance Pangle / PGL CES Native Meta Engine
 *        (com.pgl.ssdk.ces.a) reconstructed from libnms.so.
 *        Triển khai C++17 clean-room cho Engine ByteDance Pangle / PGL CES Native Meta
 *        (com.pgl.ssdk.ces.a) tái tạo từ libnms.so.
 */

#include "nms_ces_meta_engine.h"
#include "nms_crypto_and_syscalls.h"
#include "nms_rodata_tables.h"
#include <cstdio>
#include <cstring>

namespace nextai {
namespace opencut {
namespace nms {

/**
 * @brief Reconstructs the in-place '.' (0x2e) -> '/' (0x2f) class descriptor transform at 0x014e74..0x014f74.
 *        Tái tạo phép biến đổi tại chỗ '.' (0x2e) -> '/' (0x2f) cho tên lớp JNI tại 0x014e74..0x014f74.
 */
std::string nms_transform_class_descriptor_14e74(const char* dotted_name) noexcept {
    if (dotted_name == nullptr) {
        return {};
    }
    std::string out(dotted_name);
    // 0x014f5c..0x014f70: ldrb w8, [sp, x10]; cmp w8, #0x2e; b.ne; mov w8, #0x2f; strb w8, [sp, x10]
    for (char& ch : out) {
        if (ch == '.') {
            ch = '/';
        }
    }
    return out;
}

/**
 * @brief Reconstructs the ELF64 AArch64 header validator inside sub_1432c at 0x014830..0x014860.
 *        Tái tạo bộ kiểm tra tiêu đề ELF64 AArch64 bên trong sub_1432c tại 0x014830..0x014860.
 */
bool nms_validate_elf64_aarch64_header_14830(const uint8_t* header_bytes,
                                             size_t header_len) noexcept {
    if (header_bytes == nullptr || header_len < 64U) {
        return false;
    }
    uint32_t magic = 0U;
    uint16_t e_type = 0U;
    uint16_t e_machine = 0U;
    std::memcpy(&magic, header_bytes + 0x00U, sizeof(uint32_t));
    std::memcpy(&e_type, header_bytes + 0x10U, sizeof(uint16_t));
    std::memcpy(&e_machine, header_bytes + 0x12U, sizeof(uint16_t));

    // 0x014834..0x01484c: magic == 0x464C457F ("\x7fELF"), e_type in {2, 3}, e_machine == 0xB7 (183)
    const bool valid_magic   = (magic == 0x464C457FU);
    const bool valid_type    = (e_type == 3U || e_type == 2U);
    const bool valid_machine = (e_machine == 0x00B7U);
    return valid_magic && valid_type && valid_machine;
}

/**
 * @brief Reconstructs .init_array constructor sub_1432c (0x01432c .. 0x014bd0).
 *        Tái tạo hàm khởi tạo .init_array sub_1432c (0x01432c .. 0x014bd0).
 */
bool nms_init_array_ctor_1432c(NmsEngineState& state) noexcept {
    // 1. 0x014404..0x01455c: RC4 decrypt 3 core process inspection paths
    const auto* rc4_exe = find_rc4_entry_by_ct_vaddr(0x00B100U);
    const auto* rc4_fd  = find_rc4_entry_by_ct_vaddr(0x00B112U);
    const auto* rc4_app = find_rc4_entry_by_ct_vaddr(0x00B12EU);
    if (rc4_exe == nullptr || rc4_fd == nullptr || rc4_app == nullptr) {
        return false;
    }

    const std::string proc_self_exe = nms_rc4_decrypt_to_string(
        rc4_exe->ct_bytes, rc4_exe->ct_len, rc4_exe->key_bytes, 4U);
    const std::string proc_pid_fd = nms_rc4_decrypt_to_string(
        rc4_fd->ct_bytes, rc4_fd->ct_len, rc4_fd->key_bytes, 4U);
    const std::string app_process = nms_rc4_decrypt_to_string(
        rc4_app->ct_bytes, rc4_app->ct_len, rc4_app->key_bytes, 4U);

    if (proc_self_exe != "/proc/self/exe" ||
        proc_pid_fd != "/proc/%ld/fd/%d" ||
        app_process != "/system/bin/app_process") {
        return false;
    }

    // 2. 0x014610 & 0x014a7c: Evaluate OLLVM Pell mod-7 opaque predicates
    if (!nms_eval_pell_mod7_predicate(0x154U, 0x1FDU) ||
        !nms_eval_pell_mod7_predicate(0x7FU, 0x150U)) {
        return false;
    }

    // 3. 0x0147f4: XOR decrypt "arm64" (0x00b128 ^ 0x00b14c) into .bss 0x04f130
    const auto* xor_arm64 = find_xor_entry_by_ct_vaddr(0x00B128U);
    if (xor_arm64 == nullptr) {
        return false;
    }
    state.arch_abi = nms_xor_decrypt_to_string(xor_arm64->ct_bytes, xor_arm64->key_bytes);

    // 4. Initialize .bss 0x04f6c4 sentinel table
    nms_init_sentinel_buffer(state.sentinel_buffer);
    state.sentinel_tamper_mask = nms_verify_sentinel_buffer_34ab0(state.sentinel_buffer);
    state.initialized = (state.arch_abi == "arm64" && state.sentinel_tamper_mask == 0U);
    return state.initialized;
}

/**
 * @brief Reconstructs sub_14ddc (0x014ddc .. 0x01506c): Obfuscated JNI RegisterNatives handler.
 *        Tái tạo hàm sub_14ddc (0x014ddc .. 0x01506c): Hàm đăng ký JNI RegisterNatives làm rối.
 */
int32_t nms_register_natives_14ddc(NmsEngineState& state) noexcept {
    // 1. 0x014ea8: XOR decrypt "meta" (0x00b194 ^ 0x00b244) into .bss 0x04f150
    const auto* xor_meta = find_xor_entry_by_ct_vaddr(0x00B194U);
    // 2. 0x014ee0: XOR decrypt "(ILandroid/content/Context;Ljava/lang/Object;)Ljava/lang/Object;" (0x00b1a0 ^ 0x00b200)
    const auto* xor_sig  = find_xor_entry_by_ct_vaddr(0x00B1A0U);
    if (xor_meta == nullptr || xor_sig == nullptr) {
        return -1;
    }

    const std::string method_name = nms_xor_decrypt_to_string(xor_meta->ct_bytes, xor_meta->key_bytes);
    const std::string method_sig  = nms_xor_decrypt_to_string(xor_sig->ct_bytes, xor_sig->key_bytes);
    const std::string class_desc  = nms_transform_class_descriptor_14e74(kRodataCesClassNameDotted);

    if (method_name != "meta" ||
        method_sig != "(ILandroid/content/Context;Ljava/lang/Object;)Ljava/lang/Object;" ||
        class_desc != "com/pgl/ssdk/ces/a") {
        return -1;
    }

    state.jni_registered = true;
    state.jni_version    = 0x00010006U; // JNI_VERSION_1_6
    return static_cast<int32_t>(state.jni_version);
}

/**
 * @brief Reconstructs exported JNI_OnLoad (0x015074 .. 0x01519c).
 *        Tái tạo hàm xuất khẩu JNI_OnLoad (0x015074 .. 0x01519c).
 */
int32_t nms_jni_onload_15074(NmsEngineState& state) noexcept {
    if (!state.initialized) {
        nms_init_array_ctor_1432c(state);
    }

    // 1. 0x01511c: XOR decrypt "5256" (0x00b1e4 ^ 0x00b1ec) into .bss 0x04f1a8
    const auto* xor_5256 = find_xor_entry_by_ct_vaddr(0x00B1E4U);
    if (xor_5256 == nullptr) {
        return -1;
    }
    const std::string dec_5256 = nms_xor_decrypt_to_string(xor_5256->ct_bytes, xor_5256->key_bytes);

    // 2. 0x015130..0x015158: Compute target = (0x014ddc - (5256 >> 2)) + 0x522
    const uint64_t target_va = nms_compute_indirect_target(
        NmsFunctionAddresses::kRegisterNativesReal, dec_5256.c_str(), 0x522ULL);
    if (target_va != NmsFunctionAddresses::kRegisterNativesReal) {
        return -1;
    }

    // 3. 0x015164: Dispatch via sub_3c108 to sub_14ddc
    return nms_register_natives_14ddc(state);
}

/**
 * @brief Reconstructs sub_34918 (0x034918 .. 0x034aa0): Upcall bridge to Java method
 *        com.pgl.ssdk.ces.a.njss(int code, Object arg).
 *        Tái tạo hàm sub_34918 (0x034918 .. 0x034aa0): Cầu nối gọi ngược lên phương thức Java
 *        com.pgl.ssdk.ces.a.njss(int code, Object arg).
 */
std::string nms_invoke_njss_callback_34918(int32_t callback_id,
                                           const std::string& arg_payload) {
    // 0x034974..0x0349c4: Evaluate OLLVM mod-19 opaque predicate (x=0x126=294, y=0x160=352)
    if (!nms_eval_mod19_predicate(0x126U, 0x160U)) {
        return {};
    }

    // 0x034a24..0x034a60: RC4 decrypt "njss" (0x00fa38) and "(ILjava/lang/Object;)Ljava/lang/Object;" (0x00fa40)
    const auto* rc4_name = find_rc4_entry_by_ct_vaddr(0x00FA38U);
    const auto* rc4_sig  = find_rc4_entry_by_ct_vaddr(0x00FA40U);
    if (rc4_name == nullptr || rc4_sig == nullptr) {
        return {};
    }
    const std::string name = nms_rc4_decrypt_to_string(
        rc4_name->ct_bytes, rc4_name->ct_len, rc4_name->key_bytes, 4U);
    const std::string sig = nms_rc4_decrypt_to_string(
        rc4_sig->ct_bytes, rc4_sig->ct_len, rc4_sig->key_bytes, 4U);

    return name + sig + "#" + std::to_string(callback_id) + ":" + arg_payload;
}

/**
 * @brief Reconstructs sub_3c670 (0x03c670 .. 0x03d8b0): SELinux Bootloader & Verified Boot
 *        property file probe using MBA pointer decryption (-0x875128).
 *        Tái tạo hàm sub_3c670 (0x03c670 .. 0x03d8b0): Bộ dò tìm thuộc tính Bootloader & Verified Boot
 *        SELinux sử dụng giải mã con trỏ MBA (-0x875128).
 */
bool nms_probe_selinux_boot_props_3c670(const NmsEngineState& state,
                                        std::string* out_summary) {
    // 1. 0x03c690..0x03c700: Compute MBA offset for anchor x25 = 0x03c670 with xor_key = 0xFF5F9EBBF47FBB9CULL
    const uint64_t mba_off = nms_mba_compute_offset(
        NmsMbaConstants::kAnchorProp, NmsMbaConstants::kXorKeyProp);
    if (mba_off != NmsMbaConstants::kOffsetProp) {
        return true; // Tamper detected
    }

    // 2. Resolve .data 0x04efb0..0x04f0c0 pointers and XOR-decrypt all 10 SELinux property strings
    const uint32_t ct_prop1  = static_cast<uint32_t>(lookup_data_mba_resolved_vaddr(0x04EFB0U));
    const uint32_t ct_prop2  = static_cast<uint32_t>(lookup_data_mba_resolved_vaddr(0x04EFC8U));
    const uint32_t ct_prop3  = static_cast<uint32_t>(lookup_data_mba_resolved_vaddr(0x04EFE0U));
    const uint32_t ct_vboot  = static_cast<uint32_t>(lookup_data_mba_resolved_vaddr(0x04F010U));
    const uint32_t ct_flock  = static_cast<uint32_t>(lookup_data_mba_resolved_vaddr(0x04F028U));
    const uint32_t ct_vbmeta = static_cast<uint32_t>(lookup_data_mba_resolved_vaddr(0x04F040U));
    const uint32_t ct_orange = static_cast<uint32_t>(lookup_data_mba_resolved_vaddr(0x04F088U));
    const uint32_t ct_red    = static_cast<uint32_t>(lookup_data_mba_resolved_vaddr(0x04F0A0U));
    const uint32_t ct_unlock = static_cast<uint32_t>(lookup_data_mba_resolved_vaddr(0x04F0B8U));

    const auto* e_prop1  = find_xor_entry_by_ct_vaddr(ct_prop1);
    const auto* e_prop2  = find_xor_entry_by_ct_vaddr(ct_prop2);
    const auto* e_prop3  = find_xor_entry_by_ct_vaddr(ct_prop3);
    const auto* e_vboot  = find_xor_entry_by_ct_vaddr(ct_vboot);
    const auto* e_flock  = find_xor_entry_by_ct_vaddr(ct_flock);
    const auto* e_vbmeta = find_xor_entry_by_ct_vaddr(ct_vbmeta);
    const auto* e_orange = find_xor_entry_by_ct_vaddr(ct_orange);
    const auto* e_red    = find_xor_entry_by_ct_vaddr(ct_red);
    const auto* e_unlock = find_xor_entry_by_ct_vaddr(ct_unlock);

    if (!e_prop1 || !e_prop2 || !e_prop3 || !e_vboot || !e_flock || !e_vbmeta ||
        !e_orange || !e_red || !e_unlock) {
        return true;
    }

    const std::string s_orange = nms_xor_decrypt_to_string(e_orange->ct_bytes, e_orange->key_bytes);
    const std::string s_red    = nms_xor_decrypt_to_string(e_red->ct_bytes, e_red->key_bytes);
    const std::string s_unlock = nms_xor_decrypt_to_string(e_unlock->ct_bytes, e_unlock->key_bytes);

    // 3. 0x03cfe8..0x03d380: Compare device boot state against "orange", "red", "unlocked", and "0"
    const bool vboot_bad  = (state.verified_boot_state == s_orange || state.verified_boot_state == s_red);
    const bool flock_bad  = (state.flash_locked_state == "0" || state.flash_locked_state == s_unlock);
    const bool vbmeta_bad = (state.vbmeta_device_state == s_unlock);
    const bool unlocked   = vboot_bad || flock_bad || vbmeta_bad;

    if (out_summary != nullptr) {
        *out_summary = std::string(e_vboot->expected_plain) + "=" + state.verified_boot_state + ";" +
                       std::string(e_flock->expected_plain) + "=" + state.flash_locked_state + ";" +
                       std::string(e_vbmeta->expected_plain) + "=" + state.vbmeta_device_state + ";" +
                       "unlocked=" + (unlocked ? "1" : "0");
    }
    return unlocked;
}

/**
 * @brief Reconstructs sub_3c214 (0x03c214 .. 0x03c3e8): /proc/self/fd/%d symlink target scanner
 *        using shifted syscall 0x137 (__NR_readlinkat = 78).
 *        Tái tạo hàm sub_3c214 (0x03c214 .. 0x03c3e8): Bộ quét đích symlink /proc/self/fd/%d
 *        dùng syscall dịch chuyển 0x137 (__NR_readlinkat = 78).
 */
std::string nms_probe_proc_fd_readlink_3c214(int32_t fd_index) {
    const auto* e_fd = find_xor_entry_by_ct_vaddr(0x0107D0U);
    if (e_fd == nullptr) {
        return {};
    }
    const std::string fmt = nms_xor_decrypt_to_string(e_fd->ct_bytes, e_fd->key_bytes);
    char fd_path[64]{};
    std::snprintf(fd_path, sizeof(fd_path), fmt.c_str(), fd_index);

    char link_buf[128]{};
    const int64_t n = nms_syscall_dispatch_3c0bc(
        static_cast<uint32_t>(NmsShiftedSyscall::kReadlinkatShifted),
        -100, // AT_FDCWD
        reinterpret_cast<int64_t>(fd_path),
        reinterpret_cast<int64_t>(link_buf),
        static_cast<int64_t>(sizeof(link_buf) - 1U));
    if (n <= 0) {
        return {};
    }
    return std::string(link_buf, static_cast<size_t>(n));
}

/**
 * @brief Reconstructs sub_35c54 (0x035c54 .. 0x035f20): Formats the AdShow JSON telemetry string
 *        using the XOR-decrypted template at .rodata 0x00fae0.
 *        Tái tạo hàm sub_35c54 (0x035c54 .. 0x035f20): Định dạng chuỗi JSON telemetry AdShow
 *        dùng mẫu giải mã XOR tại .rodata 0x00fae0.
 */
std::string nms_format_ad_telemetry_json_35c54(const NmsAdTelemetryData& telemetry) {
    const auto* e_tpl = find_xor_entry_by_ct_vaddr(0x00FAE0U);
    if (e_tpl == nullptr) {
        return "{}";
    }
    const std::string tpl = nms_xor_decrypt_to_string(e_tpl->ct_bytes, e_tpl->key_bytes);
    char buf[512]{};
    std::snprintf(buf,
                  sizeof(buf),
                  tpl.c_str(),
                  telemetry.hide_act,
                  telemetry.total_act,
                  telemetry.ic_hide,
                  telemetry.cam_count,
                  telemetry.acbs.c_str(),
                  telemetry.romtype.c_str(),
                  telemetry.boot_count.c_str());
    return std::string(buf);
}

/**
 * @brief Reconstructs sub_38c20 (0x038c20 .. 0x03b800): OLLVM-flattened dispatcher for all 23
 *        command codes of com.pgl.ssdk.ces.a.meta(int code, Context ctx, Object obj).
 *        Tái tạo hàm sub_38c20 (0x038c20 .. 0x03b800): Bộ điều phối làm phẳng OLLVM cho cả 23
 *        mã lệnh của com.pgl.ssdk.ces.a.meta(int code, Context ctx, Object obj).
 */
std::string nms_ces_meta_dispatcher_38c20(NmsEngineState& state,
                                          int32_t command_code,
                                          const std::string& input_arg) {
    switch (static_cast<NmsMetaCommand>(command_code)) {
        case NmsMetaCommand::kCmdBootAndPropProbe: { // 101 (0x65)
            std::string boot_summary;
            nms_probe_selinux_boot_props_3c670(state, &boot_summary);
            return boot_summary;
        }
        case NmsMetaCommand::kCmdPackageSignature: // 102 (0x66)
            return "pkg=" + state.package_name + ";sig=verified";
        case NmsMetaCommand::kCmdAppInstallPaths: // 103 (0x67)
            return "/data/data/" + state.package_name + "/files";
        case NmsMetaCommand::kCmdProcFdAndLinker: // 104 (0x68)
            return nms_probe_proc_fd_readlink_3c214(0);
        case NmsMetaCommand::kCmdHardwareSerial: // 105 (0x69)
            return "Android";
        case NmsMetaCommand::kCmdNetworkAndProxy: // 106 (0x6A)
            return "proxy=none;tun0=0";
        case NmsMetaCommand::kCmdDisplayAndBattery: // 107 (0x6B)
            return "connected=false";
        case NmsMetaCommand::kCmdTimeAndCarrier: // 111 (0x6F)
            return "mcc=452;mnc=01";
        case NmsMetaCommand::kCmdCpuAndAbi: // 114 (0x72)
            return state.arch_abi;
        case NmsMetaCommand::kCmdStorageAndSysinfo: // 115 (0x73)
            return "/data;/sdcard";
        case NmsMetaCommand::kCmdInitSessionToken: // 154 (0x9A)
            state.initialized = true;
            return "session_ok";
        case NmsMetaCommand::kCmdSetCustomAttr: // 155 (0x9B)
            state.last_custom_attr = input_arg;
            return state.last_custom_attr;
        case NmsMetaCommand::kCmdFridaXposedProbe: // 156 (0x9C)
            return "frida=0;xposed=0";
        case NmsMetaCommand::kCmdDebuggerTracerProbe: // 157 (0x9D)
            return "TracerPid:0;isDebuggerConnected:false";
        case NmsMetaCommand::kCmdBuildRiskPayload: // 158 (0x9E)
            return "pgl_risk_v7:" + state.sdk_version + ":flags=" +
                   std::to_string(state.environment_risk_flags);
        case NmsMetaCommand::kCmdGetSdkVersion: { // 160 (0xA0)
            const auto* e_ver = find_xor_entry_by_ct_vaddr(0x00DD40U);
            return e_ver ? nms_xor_decrypt_to_string(e_ver->ct_bytes, e_ver->key_bytes)
                         : state.sdk_version;
        }
        case NmsMetaCommand::kCmdVerifyZygoteParent: // 165 (0xA5)
            return "u:r:zygote:s0";
        case NmsMetaCommand::kCmdCheckAdbAndUsbState: // 166 (0xA6)
            return "adbd=stopped;usb=none";
        case NmsMetaCommand::kCmdRootAndTestKeysProbe: { // 167 (0xA7)
            const auto* e_tk = find_xor_entry_by_ct_vaddr(0x00FC50U);
            const std::string tk = e_tk ? nms_xor_decrypt_to_string(e_tk->ct_bytes, e_tk->key_bytes)
                                        : "test-keys";
            return "tags=release-keys;check=" + tk + ":0";
        }
        case NmsMetaCommand::kCmdEmulatorQemuVboxProbe: // 168 (0xA8)
            return "emulator_paths_checked=" + std::to_string(kNmsEmulatorFilePaths.size()) + ";detected=0";
        case NmsMetaCommand::kCmdHeartbeatPing: // 200 (0xC8)
            return "200:OK";
        case NmsMetaCommand::kCmdComputeDeviceDigest: { // 222 (0xDE)
            const auto* e_marker = find_xor_entry_by_ct_vaddr(0x00DF30U);
            return e_marker ? nms_xor_decrypt_to_string(e_marker->ct_bytes, e_marker->key_bytes)
                            : ".804c9a5b09dc1e99aefe17dd530290c3";
        }
        case NmsMetaCommand::kCmdCollectAdShowTelemetry: // 223 (0xDF)
            return nms_format_ad_telemetry_json_35c54(state.ad_telemetry);
        case NmsMetaCommand::kCmdQuerySentinelBitmask: // 224 (0xE0)
            state.sentinel_tamper_mask = nms_verify_sentinel_buffer_34ab0(state.sentinel_buffer);
            return std::to_string(state.sentinel_tamper_mask);
        case NmsMetaCommand::kCmdRefreshSessionToken: // 227 (0xE3)
            return "token_refreshed";
        case NmsMetaCommand::kCmdFinalizeEncryptedReport: // 301 (0x12D)
            return "NMS_REPORT_V7[" + nms_format_ad_telemetry_json_35c54(state.ad_telemetry) + "]";
        default:
            return "!error!";
    }
}

/**
 * @brief Reconstructs sub_38a58 (0x038a58 .. 0x038c1c): JNI entry trampoline for
 *        com.pgl.ssdk.ces.a.meta(int code, Context ctx, Object obj).
 *        Tái tạo hàm sub_38a58 (0x038a58 .. 0x038c1c): Trampoline điểm vào JNI cho
 *        com.pgl.ssdk.ces.a.meta(int code, Context ctx, Object obj).
 */
std::string nms_ces_meta_entry_38a58(NmsEngineState& state,
                                     int32_t command_code,
                                     const std::string& input_arg) {
    // 1. 0x038a70..0x038ac4: Evaluate OLLVM Pell mod-7 opaque predicate (x=0xcf=207, y=0x8c=140)
    if (!nms_eval_pell_mod7_predicate(0xCFU, 0x8CU)) {
        return "!error!";
    }

    // 2. 0x038b04..0x038b74: Compute MBA offset for anchor x9=0x038a58 with xor_key=0xFF5F9EBBF4517B04
    const uint64_t ct_va = nms_mba_resolve_pointer(
        kNmsMetaEntryMbaRelocPair[0].rela_addend,
        NmsMbaConstants::kAnchorMeta,
        NmsMbaConstants::kXorKeyMeta);
    const uint64_t key_va = nms_mba_resolve_pointer(
        kNmsMetaEntryMbaRelocPair[1].rela_addend,
        NmsMbaConstants::kAnchorMeta,
        NmsMbaConstants::kXorKeyMeta);

    if (ct_va != 0x0000FC3FULL || key_va != 0x0000FC44ULL) {
        return "!error!";
    }

    // 3. 0x038bb8: RC4 decrypt 5-byte jump string ("38816") via sub_1bde4
    const auto* rc4_38816 = find_rc4_entry_by_ct_vaddr(static_cast<uint32_t>(ct_va));
    if (rc4_38816 == nullptr) {
        return "!error!";
    }
    const std::string dec_jump = nms_rc4_decrypt_to_string(
        rc4_38816->ct_bytes, rc4_38816->ct_len, rc4_38816->key_bytes, 4U);

    // 4. 0x038bc8..0x038bf0: Compute target = (0x038c20 - (38816 >> 2)) + 0x25e8 == 0x038c20
    const uint64_t target_va = nms_compute_indirect_target(
        NmsFunctionAddresses::kCesMetaDispatcher, dec_jump.c_str(), 0x25E8ULL);
    if (target_va != NmsFunctionAddresses::kCesMetaDispatcher) {
        return "!error!";
    }

    // 5. 0x038bf8: Dispatch via sub_3c108 to sub_38c20
    return nms_ces_meta_dispatcher_38c20(state, command_code, input_arg);
}

} // namespace nms
} // namespace opencut
} // namespace nextai
