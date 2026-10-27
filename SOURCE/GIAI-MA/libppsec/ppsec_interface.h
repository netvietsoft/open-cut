/**
 * @file ppsec_interface.h
 * @brief Top-Level Public C++/JNI Interface for Reconstructed libppsec.so (ByteDance PIPO SecSDK 2.0.3).
 *        Giao diện C++/JNI công khai cấp cao cho thư viện tái tạo sạch libppsec.so (ByteDance PIPO SecSDK 2.0.3).
 *
 * Binary Target / Mục tiêu nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/libppsec.so (166,400 bytes)
 *   SHA-256: 1815ed63470ca5e5f251f66730ca849e01ed3d1ccdbde9cb162e96d2ccfa7f2f
 *
 * Exported Symbols & JNI Entrypoints / Các biểu tượng xuất và điểm vào JNI:
 *   - `JNI_OnLoad` (`0x003188` -> `0x002dbc..0x003180`) -> returns `0x00010004` (`JNI_VERSION_1_4`)
 *   - Class 1: `com/bytedance/pipo/sec/IlIlllIiI` (`.data 0x02c000..0x02c08f`, 6 `JNINativeMethod` entries):
 *       [0] `IlIllLIiI(Ljava/lang/String;IZ)V`                -> `0x00318c` (`initAppIdAndRegion`)
 *       [1] `IlIllLIiI(Ljava/lang/String;Ljava/lang/String;)V` -> `0x003560` (`setDeviceAndInstallId`)
 *       [2] `IlIllLIiII(Ljava/lang/String;Ljava/lang/String;)V`-> `0x003960` (`setCustomRsaKeyAndKid`)
 *       [3] `IlIllLIiI(Ljava/lang/String;)V`                  -> `0x003f2c` (`reportRiskEvent`)
 *       [4] `IlIllLIiI()Ljava/lang/String;`                   -> `0x004288` (`getSecurityToken`)
 *       [5] `IlIllLIiII(Ljava/lang/String;)V`                 -> `0x004408` (`updateDidOrHost`)
 *   - Class 2: `com/bytedance/pipo/sec/CryptTool` (`.data 0x02c0d0..0x02c117`, 3 `JNINativeMethod` entries):
 *       [0] `encrypt([B)[B`                                   -> `0x0115ec` (`CryptTool_encrypt`)
 *       [1] `decrypt([B)[B`                                   -> `0x0117a0` (`CryptTool_decrypt`)
 *       [2] `getKid()Ljava/lang/String;`                      -> `0x011948` (`CryptTool_getKid`)
 */

#ifndef NEXTAI_OPENCUT_PPSEC_INTERFACE_H_
#define NEXTAI_OPENCUT_PPSEC_INTERFACE_H_

#include "ppsec_bpem_crypto.h"
#include "ppsec_env_risk_scanner.h"
#include "ppsec_string_deobfuscator.h"
#include "ppsec_types.h"

#include <cstdint>
#include <string>
#include <vector>

namespace nextai {
namespace opencut {
namespace ppsec {

/**
 * @brief Returns the reconstructed 6-entry `JNINativeMethod` table for `com/bytedance/pipo/sec/IlIlllIiI`
 *        (`.data 0x02c000..0x02c08f`) and 3-entry table for `com/bytedance/pipo/sec/CryptTool` (`.data 0x02c0d0..0x02c117`).
 *        Trả về bảng phương thức gốc JNI cho `IlIlllIiI` (6 mục) và `CryptTool` (3 mục).
 */
const std::vector<PpsecJniNativeMethod>& GetIlIlllIiIJniMethodTable() noexcept;
const std::vector<PpsecJniNativeMethod>& GetCryptToolJniMethodTable() noexcept;

/**
 * @brief Reconstructs `JNI_OnLoad` (`0x003188` -> `0x002dbc..0x003180`):
 *        Initializes static state (`.init_array[0]` `0x002a10` and `.init_array[1]` `0x0185fc`),
 *        decrypts JNI class/method descriptors, registers both native method tables, and returns `0x00010004`.
 *        Tái tạo hàm `JNI_OnLoad` (`0x003188` -> `0x002dbc..0x003180`).
 */
int32_t PpsecJniOnLoad(void* java_vm_opaque) noexcept;

/**
 * @brief Reconstructs the 6 JNI native methods of `com/bytedance/pipo/sec/IlIlllIiI`:
 *        Tái tạo 6 phương thức JNI của lớp `com/bytedance/pipo/sec/IlIlllIiI`:
 */
void PpsecNative_InitAppIdAndRegion(const std::string& app_id,
                                    int32_t region_code,
                                    bool enable_debug_log) noexcept;

void PpsecNative_SetDeviceAndInstallId(const std::string& did,
                                       const std::string& iid) noexcept;

void PpsecNative_SetCustomRsaKeyAndKid(const std::string& rsa_pub_key_b64,
                                       const std::string& kid) noexcept;

void PpsecNative_ReportRiskEvent(const std::string& event_scene) noexcept;

std::string PpsecNative_GetSecurityToken() noexcept;

void PpsecNative_UpdateDidOrHost(const std::string& custom_did_or_host) noexcept;

/**
 * @brief Reconstructs the 3 JNI native methods of `com/bytedance/pipo/sec/CryptTool`:
 *        Tái tạo 3 phương thức JNI của lớp `com/bytedance/pipo/sec/CryptTool`:
 */
std::vector<uint8_t> PpsecCryptTool_Encrypt(const std::vector<uint8_t>& plaintext) noexcept;
std::vector<uint8_t> PpsecCryptTool_Decrypt(const std::vector<uint8_t>& ciphertext_envelope) noexcept;
std::string          PpsecCryptTool_GetKid() noexcept;

/**
 * @brief Runs an end-to-end self-test verifying all OLLVM opaque predicates, pairwise-XOR decryption,
 *        CRC-16/XMODEM, MD5, Base64, AES-128-CBC, BPEM envelope round-trip, and risk scanner.
 *        Chạy kiểm thử tự động toàn trình cho toàn bộ các mô-đun của `libppsec.so`.
 */
bool RunPpsecSelfTest(std::string* out_diagnostic_report) noexcept;

}  // namespace ppsec
}  // namespace opencut
}  // namespace nextai

#endif  // NEXTAI_OPENCUT_PPSEC_INTERFACE_H_
