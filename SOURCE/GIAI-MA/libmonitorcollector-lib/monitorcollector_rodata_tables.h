/**
 * @file monitorcollector_rodata_tables.h
 * @brief Exact .rodata (0x038cf0..0x03d699), .data.rel.ro (0x04c928..0x04f388) & .data (0x050000..0x050138) Tables
 *        Các bảng hằng số .rodata, bảng JNI 46 mục trong .data.rel.ro và biến toàn cục khởi tạo sẵn trong .data
 */

#pragma once

#include "monitorcollector_types.h"

namespace bytedance {
namespace monitor {
namespace collector {

// .rodata @ 0x038cf4..0x038cfe (11 bytes): CollectStateValueFd (/proc/[pid]/stat fields 14..24) jump table
// Bảng nhảy 11-byte tại .rodata 0x038cf4 cho CollectStateValueFd (trường 14..24 của /proc/[pid]/stat)
extern const uint8_t kCollectStateFieldJumpTable_038cf4[11];

// .rodata @ 0x038cff..0x038d05 (7 bytes): a64_get_imm (0x01c044) instruction immediate decoder jump table
// Bảng nhảy 7-byte tại .rodata 0x038cff giải mã toán hạng tức thời lệnh AArch64 trong a64_get_imm (0x01c044)
extern const uint8_t kA64GetImmJumpTable_038cff[7];

// .rodata @ 0x038d06..0x038d49 (68 bytes): ARM32 / Thumb-16 / Thumb-32 instruction immediate & register jump tables
// Bảng nhảy 68-byte tại .rodata 0x038d06..0x038d49 giải mã lệnh ARM32 / Thumb-16 / Thumb-32
extern const uint8_t kArm32ThumbDecodeJumpTables_038d06[68];

// .rodata @ 0x03ac98 (8 bytes): kSecondNanos = 1,000,000,000ULL (0x3B9ACA00)
// Hằng số kSecondNanos = 1.000.000.000ULL (0x3B9ACA00) tại .rodata 0x03ac98
constexpr uint64_t kSecondNanos_03ac98 = 1000000000ULL;

// .rodata @ 0x03b038..0x03b050: Android packed relocation flags used by xhook ELF parser (0x01e47c)
// Các cờ relocation nén Android dùng bởi bộ phân tích ELF xhook (0x01e47c)
constexpr uint64_t RELOCATION_GROUPED_BY_INFO_FLAG_03b038         = 1ULL;
constexpr uint64_t RELOCATION_GROUPED_BY_OFFSET_DELTA_FLAG_03b040 = 2ULL;
constexpr uint64_t RELOCATION_GROUPED_BY_ADDEND_FLAG_03b048       = 4ULL;
constexpr uint64_t RELOCATION_GROUP_HAS_ADDEND_FLAG_03b050        = 8ULL;

// .data @ 0x050000..0x050058: Default initialized monitor parameters
// Các tham số giám sát mặc định khởi tạo sẵn trong .data 0x050000..0x050058
constexpr uint32_t kDefaultMainEventSize_050000       = 1000U;      // 0x000003e8
constexpr uint32_t kDefaultSubEventSize_050004        = 10000U;     // 0x00002710
constexpr int64_t  kDefaultLockFetchStackMinMs_050008 = 16LL;       // 0x10
constexpr int64_t  kDefaultLockFetchStackMaxMs_050020 = 5000LL;     // 0x1388
constexpr uint64_t kDefaultAtraceTags_050028          = 0x401AULL;  // 16410
constexpr int32_t  kDefaultProcBufferSize_050044      = 200;        // 0xc8
constexpr int32_t  kDefaultXhLogPriority_050054       = 5;          // ANDROID_LOG_WARN
constexpr int64_t  kBinderMainThreadThresholdNs       = 0x3D0900LL; // 4,000,000 ns (4 ms @ 0x01441c..0x014424)

// .data.rel.ro @ 0x04c948..0x04cd98: 46 JNINativeMethod entries for com/bytedance/monitor/collector/MonitorJni
// Bảng 46 phương thức gốc JNI cho lớp com/bytedance/monitor/collector/MonitorJni tại .data.rel.ro 0x04c948..0x04cd98
constexpr size_t kMonitorJniMethodCount = 46;
extern const JniMethodEntry kMonitorJniTable_04c948[kMonitorJniMethodCount];

} // namespace collector
} // namespace monitor
} // namespace bytedance
