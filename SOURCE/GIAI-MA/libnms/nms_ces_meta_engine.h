/**
 * @file nms_ces_meta_engine.h
 * @brief Clean-room C++17 declarations for the ByteDance Pangle / PGL CES Native Meta Engine
 *        (com.pgl.ssdk.ces.a) reconstructed from libnms.so.
 *        Khai báo C++17 clean-room cho Engine ByteDance Pangle / PGL CES Native Meta
 *        (com.pgl.ssdk.ces.a) tái tạo từ libnms.so.
 */

#ifndef NEXTAI_OPENCUT_NMS_CES_META_ENGINE_H_
#define NEXTAI_OPENCUT_NMS_CES_META_ENGINE_H_

#include "nms_types.h"
#include <cstdint>
#include <string>
#include <vector>

namespace nextai {
namespace opencut {
namespace nms {

/**
 * @brief Reconstructs the in-place '.' (0x2e) -> '/' (0x2f) class descriptor transform at 0x014e74..0x014f74.
 *        Tái tạo phép biến đổi tại chỗ '.' (0x2e) -> '/' (0x2f) cho tên lớp JNI tại 0x014e74..0x014f74.
 *
 * Copies "com.pgl.ssdk.ces.a" (.rodata 0x00b152) to a stack buffer and replaces every '.' (0x2e)
 * with '/' (0x2f) to produce "com/pgl/ssdk/ces/a" for JNIEnv::FindClass.
 */
std::string nms_transform_class_descriptor_14e74(const char* dotted_name) noexcept;

/**
 * @brief Reconstructs the ELF64 AArch64 header validator inside sub_1432c at 0x014830..0x014860.
 *        Tái tạo bộ kiểm tra tiêu đề ELF64 AArch64 bên trong sub_1432c tại 0x014830..0x014860.
 *
 * AArch64 Disassembly at 0x014830..0x014850:
 *   ldr  w8, [x26]           // ELF magic == 0x464C457F ("\x7fELF")
 *   ldrh w9, [x26, #0x10]    // e_type == 3 (ET_DYN) or 2 (ET_EXEC)
 *   ldrh w10, [x26, #0x12]   // e_machine == 0xB7 (183 = EM_AARCH64)
 */
bool nms_validate_elf64_aarch64_header_14830(const uint8_t* header_bytes,
                                             size_t header_len) noexcept;

/**
 * @brief Reconstructs .init_array constructor sub_1432c (0x01432c .. 0x014bd0).
 *        Tái tạo hàm khởi tạo .init_array sub_1432c (0x01432c .. 0x014bd0).
 *
 * Performs:
 *   1. RC4 decryption of "/proc/self/exe" (0x00b100), "/proc/%ld/fd/%d" (0x00b112),
 *      and "/system/bin/app_process" (0x00b12e).
 *   2. XOR decryption of "arm64" (0x00b128 ^ 0x00b14c) into .bss 0x04f130.
 *   3. OLLVM Pell mod-7 (x=340, y=509) and (x=127, y=336) opaque predicate verification.
 *   4. Initialization of .bss 0x04f6c4 unaligned sentinel table.
 */
bool nms_init_array_ctor_1432c(NmsEngineState& state) noexcept;

/**
 * @brief Reconstructs sub_14ddc (0x014ddc .. 0x01506c): Obfuscated JNI RegisterNatives handler.
 *        Tái tạo hàm sub_14ddc (0x014ddc .. 0x01506c): Hàm đăng ký JNI RegisterNatives làm rối.
 *
 * Performs:
 *   1. XOR decryption of "meta" (0x00b194 ^ 0x00b244) into .bss 0x04f150.
 *   2. XOR decryption of "(ILandroid/content/Context;Ljava/lang/Object;)Ljava/lang/Object;"
 *      (0x00b1a0 ^ 0x00b200) into .bss 0x04f160.
 *   3. Class name transformation "com.pgl.ssdk.ces.a" -> "com/pgl/ssdk/ces/a".
 *   4. Returns JNI_VERSION_1_6 (0x00010006).
 */
int32_t nms_register_natives_14ddc(NmsEngineState& state) noexcept;

/**
 * @brief Reconstructs exported JNI_OnLoad (0x015074 .. 0x01519c).
 *        Tái tạo hàm xuất khẩu JNI_OnLoad (0x015074 .. 0x01519c).
 *
 * Decrypts "5256" (0x00b1e4 ^ 0x00b1ec), computes indirect target:
 *   target = (0x014ddc - (5256 >> 2)) + 0x522 == 0x014ddc
 * and dispatches via sub_3c108 to sub_14ddc.
 */
int32_t nms_jni_onload_15074(NmsEngineState& state) noexcept;

/**
 * @brief Reconstructs sub_34918 (0x034918 .. 0x034aa0): Upcall bridge to Java method
 *        com.pgl.ssdk.ces.a.njss(int code, Object arg).
 *        Tái tạo hàm sub_34918 (0x034918 .. 0x034aa0): Cầu nối gọi ngược lên phương thức Java
 *        com.pgl.ssdk.ces.a.njss(int code, Object arg).
 */
std::string nms_invoke_njss_callback_34918(int32_t callback_id,
                                           const std::string& arg_payload);

/**
 * @brief Reconstructs sub_3c670 (0x03c670 .. 0x03d8b0): SELinux Bootloader & Verified Boot
 *        property file probe using MBA pointer decryption (-0x875128).
 *        Tái tạo hàm sub_3c670 (0x03c670 .. 0x03d8b0): Bộ dò tìm thuộc tính Bootloader & Verified Boot
 *        SELinux sử dụng giải mã con trỏ MBA (-0x875128).
 *
 * Evaluates verifiedbootstate ("orange"/"red"), flash.locked, and vbmeta.device_state ("unlocked").
 * Returns true if bootloader is unlocked or tampered, false if locked/green.
 */
bool nms_probe_selinux_boot_props_3c670(const NmsEngineState& state,
                                        std::string* out_summary = nullptr);

/**
 * @brief Reconstructs sub_3c214 (0x03c214 .. 0x03c3e8): /proc/self/fd/%d symlink target scanner
 *        using shifted syscall 0x137 (__NR_readlinkat = 78).
 *        Tái tạo hàm sub_3c214 (0x03c214 .. 0x03c3e8): Bộ quét đích symlink /proc/self/fd/%d
 *        dùng syscall dịch chuyển 0x137 (__NR_readlinkat = 78).
 */
std::string nms_probe_proc_fd_readlink_3c214(int32_t fd_index);

/**
 * @brief Reconstructs sub_35c54 (0x035c54 .. 0x035f20): Formats the AdShow JSON telemetry string
 *        using the XOR-decrypted template at .rodata 0x00fae0.
 *        Tái tạo hàm sub_35c54 (0x035c54 .. 0x035f20): Định dạng chuỗi JSON telemetry AdShow
 *        dùng mẫu giải mã XOR tại .rodata 0x00fae0.
 */
std::string nms_format_ad_telemetry_json_35c54(const NmsAdTelemetryData& telemetry);

/**
 * @brief Reconstructs sub_38c20 (0x038c20 .. 0x03b800): OLLVM-flattened dispatcher for all 23
 *        command codes of com.pgl.ssdk.ces.a.meta(int code, Context ctx, Object obj).
 *        Tái tạo hàm sub_38c20 (0x038c20 .. 0x03b800): Bộ điều phối làm phẳng OLLVM cho cả 23
 *        mã lệnh của com.pgl.ssdk.ces.a.meta(int code, Context ctx, Object obj).
 */
std::string nms_ces_meta_dispatcher_38c20(NmsEngineState& state,
                                          int32_t command_code,
                                          const std::string& input_arg = "");

/**
 * @brief Reconstructs sub_38a58 (0x038a58 .. 0x038c1c): JNI entry trampoline for
 *        com.pgl.ssdk.ces.a.meta(int code, Context ctx, Object obj).
 *        Tái tạo hàm sub_38a58 (0x038a58 .. 0x038c1c): Trampoline điểm vào JNI cho
 *        com.pgl.ssdk.ces.a.meta(int code, Context ctx, Object obj).
 *
 * Performs:
 *   1. Pell mod-7 opaque predicate check (x=0xcf, y=0x8c).
 *   2. MBA offset calculation on x9=0x038a58 with xor_key=0xFF5F9EBBF4517B04 -> -0xA991C0.
 *   3. Resolves .data 0x04eea8/0x04eeb0 -> 0x00fc3f/0x00fc44 and RC4 decrypts "38816".
 *   4. Computes target (0x038c20 - (38816 >> 2)) + 0x25e8 == 0x038c20 and calls sub_38c20.
 */
std::string nms_ces_meta_entry_38a58(NmsEngineState& state,
                                     int32_t command_code,
                                     const std::string& input_arg = "");

} // namespace nms
} // namespace opencut
} // namespace nextai

#endif // NEXTAI_OPENCUT_NMS_CES_META_ENGINE_H_
