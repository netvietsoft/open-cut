/**
 * @file npth_dumper_minidump_protector.h
 * @brief Crash Protector (`PROT004\x02`, `V002\n`) and Breakpad Minidump (`MDMP`) generator.
 *        Bộ bảo vệ lỗi (`PROT004\x02`, `V002\n`) và bộ tạo Breakpad Minidump (`MDMP`).
 *
 * Reconstructed from AArch64 binary libnpth_dumper.so (`0x00f914..0x01412f`).
 * Tái cấu trúc từ mã nhị phân AArch64 libnpth_dumper.so (`0x00f914..0x01412f`).
 */

#ifndef OPENCUT_NPTH_DUMPER_MINIDUMP_PROTECTOR_H_
#define OPENCUT_NPTH_DUMPER_MINIDUMP_PROTECTOR_H_

#include "npth_dumper_ptrace_unwinder.h"
#include "npth_dumper_types.h"
#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace npth {
namespace dumper {

/**
 * @brief Binary header of `/configs/crash_protector.config` (`0x00fb3c..0x00fbc4`).
 *        Header nhị phân của `/configs/crash_protector.config` (`0x00fb3c..0x00fbc4`).
 */
struct ProtectorConfigHeader {
    uint64_t magic;        // +0x00: `0x02343030544f5250ULL` (`"PROT004\x02"`)
    uint32_t sub_magic;    // +0x08: `0x12345678U`
    uint32_t rule_count;   // +0x0c: Number of protection rules (`[x9, #0xc]`)
    uint32_t payload_size; // +0x10: `payload_size + 0x20 == file_size`
    uint32_t reserved;     // +0x14
};
static_assert(sizeof(ProtectorConfigHeader) == 24, "ProtectorConfigHeader must be 24 bytes");

/**
 * @brief Breakpad Minidump 32-byte header (`MDRawHeader`, `.rodata` `0x005fc0`, `0x01177c`, `0x0119a8`).
 *        Header Breakpad Minidump 32 byte (`MDRawHeader`).
 */
struct MDRawHeader {
    uint32_t signature;            // +0x00: `0x504d444d` (`"MDMP"`)
    uint32_t version;              // +0x04: `0x0000a793`
    uint32_t stream_count;         // +0x08: `13` (`0x0d` @ `0x0119a8`)
    uint32_t stream_directory_rva; // +0x0c: `0x20` (`32` @ `0x0119b0`)
    uint32_t checksum;             // +0x10: `0`
    uint32_t time_date_stamp;      // +0x14: `time(nullptr)` (`0x0119a0`)
    uint64_t flags;                // +0x18: `0`
};
static_assert(sizeof(MDRawHeader) == 32, "MDRawHeader must be 32 bytes");

/**
 * @brief Breakpad `MDLocationDescriptor` (8 bytes: `data_size` + `rva`).
 *        Cấu trúc `MDLocationDescriptor` của Breakpad (8 byte: `data_size` + `rva`).
 */
struct MDLocationDescriptor {
    uint32_t data_size; // +0x00
    uint32_t rva;       // +0x04
};

/**
 * @brief Breakpad `MDRawDirectory` (12 bytes: `stream_type` + `location`).
 *        Cấu trúc `MDRawDirectory` của Breakpad (12 byte: `stream_type` + `location`).
 */
struct MDRawDirectory {
    uint32_t             stream_type; // +0x00
    MDLocationDescriptor location;    // +0x04
};
static_assert(sizeof(MDRawDirectory) == 12, "MDRawDirectory must be 12 bytes");

/**
 * @brief Crash Protector engine (`[protector]`, `0x00f914..0x011108`).
 *        Bộ máy bảo vệ lỗi (`[protector]`, `0x00f914..0x011108`).
 */
class CrashProtectorEngine {
public:
    /**
     * @brief Decode unsigned LEB128 integer from byte stream (`0x010da4..0x010e10`).
     *        Giải mã số nguyên không dấu LEB128 từ luồng byte (`0x010da4..0x010e10`).
     */
    static uint32_t DecodeUleb128(const uint8_t** io_cursor) noexcept;

    /**
     * @brief Validate `/configs/crash_protector.config` magic (`PROT004\x02`), size, and 64-bit XOR checksum (`0x00fa44..0x00fbfc`).
     *        Xác thực magic (`PROT004\x02`), kích thước và tổng kiểm XOR 64-bit của `/configs/crash_protector.config`.
     */
    static bool ValidateProtectorConfigBlob(const uint8_t* data, size_t size) noexcept;

    /**
     * @brief Evaluate crash rules, check `/protector_history.txt` (`V002\n`), write `/protector.inf`, and poke registers (`0x00f914..0x010c1c`).
     *        Đánh giá quy tắc lỗi, kiểm tra `/protector_history.txt` (`V002\n`), ghi `/protector.inf` và sửa thanh ghi.
     */
    static bool EvaluateAndApplyProtection(const ParsedCrashContext& ctx,
                                           const std::vector<UnwoundFrameInfo>& frames);
};

/**
 * @brief Breakpad Minidump (`MDMP`) writer (`0x01110c..0x01412f`).
 *        Bộ ghi Breakpad Minidump (`MDMP`) (`0x01110c..0x01412f`).
 */
class MinidumpGenerator {
public:
    /**
     * @brief Convert UTF-8 string to UTF-16LE and write `MDString` into minidump (`0x0112dc..0x0115c4`).
     *        Chuyển đổi chuỗi UTF-8 sang UTF-16LE và ghi `MDString` vào minidump (`0x0112dc..0x0115c4`).
     */
    static bool ConvertUtf8ToUtf16Le(const char* utf8_str,
                                     size_t utf8_len,
                                     std::vector<uint16_t>* out_utf16);

    /**
     * @brief Parse CPU range string (e.g., `"0-7\n"`) into a 1024-bit CPU mask and count active cores via NEON (`0x013af8..0x013ce4`, `0x013728..0x013788`).
     *        Phân tích chuỗi dải CPU (ví dụ: `"0-7\n"`) thành mặt nạ 1024-bit và đếm số lõi hoạt động.
     */
    static uint8_t ParseCpuMaskAndCountCores(const char* present_str,
                                             const char* possible_str,
                                             uint32_t out_mask[32]) noexcept;

    /**
     * @brief Generate `<dump_dir>/mini.dmp` if free disk space `>= 0xb00000` (11 MB) and `/proc/<pid>/auxv` is valid (`0x00a468..0x00a5d0`, `0x01110c..0x013a80`).
     *        Tạo `<dump_dir>/mini.dmp` nếu dung lượng trống `>= 0xb00000` (11 MB) và `/proc/<pid>/auxv` hợp lệ.
     */
    static bool WriteMinidump(const ParsedCrashContext& ctx,
                              const std::vector<AttachedThread>& attached_threads,
                              const std::vector<UnwoundFrameInfo>& frames);
};

} // namespace dumper
} // namespace npth

#endif // OPENCUT_NPTH_DUMPER_MINIDUMP_PROTECTOR_H_
