// ============================================================================
// Clean-Room C++17 ABI & Data Structures for libmetasec_ov.so (Target 117 / 169)
// Cấu trúc dữ liệu & ABI C++17 sạch cho libmetasec_ov.so (Mục tiêu 117 / 169)
// Binary Size: 1,932,896 bytes | SHA-256: 1b82fc11ad72e1afc99b5399ecf44c0e4dd055f715ed9c3dda9b716355e5581e
// .dynsym: 14 Exported Symbols @ 0x000df8 (JNI_OnLoad @ 0x04aae0, 4,776 B) | .eh_frame_hdr: 5,296 FDEs @ 0x18b288
// ============================================================================
#pragma once

#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>
#include <map>
#include <mutex>
#include <atomic>

namespace metasec {
namespace ov {

// Constants verified directly from AArch64 opcodes and .rodata in libmetasec_ov.so
// Các hằng số xác minh trực tiếp từ mã máy AArch64 và .rodata trong libmetasec_ov.so
constexpr const char* kMetaSecOvVersionFull = "v05.02.03-alpha.9"; // .rodata @ 0x16b848
constexpr const char* kMetaSecOvVersionShort = "v05.02.03";        // .rodata @ 0x16b862
constexpr const char* kMetaSecOvPlatform = "android";              // .rodata @ 0x16b85a
constexpr const char* kMetaSecBridgeDesc = "(IIJLjava/lang/String;Ljava/lang/Object;)Ljava/lang/Object;";
constexpr uint32_t kOllvmMagicRecipMod19 = 0xAF286BCBU;            // mov w9, #0x6bcb; movk w9, #0xaf28, lsl #16 @ 0x04bc44
constexpr uint32_t kOllvmMagicRecipMod81 = 0xCA4587E7U;            // mov w9, #0x87e7; movk w9, #0xca45, lsl #16 @ 0x04bcd4
constexpr uint32_t kOllvmStateToken0x77DF8B85 = 0x77DF8B85U;       // mov w8, #0x8b85; movk w8, #0x77df, lsl #16 @ 0x04bc10

// 13 Whitelisted Overseas & Global AppIDs reconstructed from 0x02ea00..0x02ebc0 (.rodata @ 0x16b790..0x16b7d8)
// 13 AppID Quốc tế được tái dựng từ hàm 0x02ea00..0x02ebc0 (.rodata @ 0x16b790..0x16b7d8)
constexpr const char* kMetaSecAllowedAppIds[13] = {
    "1180",   // 0x16b790
    "1233",   // 0x16b795
    "259",    // 0x16b79a (CapCut Overseas)
    "662155", // 0x16b79e
    "1340",   // 0x16b7a5
    "4082",   // 0x16b7aa
    "8660",   // 0x16b7af
    "385522", // 0x16b7b4
    "364225", // 0x16b7bb
    "310024", // 0x16b7c2
    "580589", // 0x16b7c9
    "3332",   // 0x16b7d0
    "214304"  // 0x16b7d5
};

struct MetaSecSettings {
    int64_t schedule_report_interval{300};
    int64_t task_pull_interval{600};
    int64_t seed_pull_interval{1800};
    int64_t msmodel_data_report_count{0};
    int64_t msmodel_data_report_tsp{0};
    int32_t captcha_app_status{0};
    int32_t captcha_app_status_count{0};
    std::string app_id{"259"};
    std::string version{kMetaSecOvVersionFull};
};

} // namespace ov
} // namespace metasec
