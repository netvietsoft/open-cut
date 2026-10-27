// ============================================================================
// NextAI OpenCut — Clean-Room C++17 Reconstruction
// Target Binary : libnpth_logcat.so (16,856 bytes)
// SHA-256       : 241f75ebe9208e680c0d0e77c6f23c2f87d7ba9c2d446ca5c75a9df2ab8319e8
// Task ID       : TASK-169-RECONSTRUCTION-LIBNPTH-LOGCAT
// Legacy Task   : TASK_SO_089_libnpth_logcat
// Architecture  : AArch64 (ARM64-v8a) ELF64 PIE Executable / Shared Object
// ============================================================================
// EN: Bilingual clean-room header for ByteDance NPTH Out-of-Process Logcat
//     Dumper (.interp "/system/bin/linker64" @ 0x0270, .text 0x16e8..0x31a8,
//     10 FDEs @ 0x1454, 1,712 AArch64 instructions).
// VI: File header C++17 phòng sạch song ngữ cho Bộ trích xuất Logcat độc lập
//     của ByteDance NPTH (.interp "/system/bin/linker64" @ 0x0270,
//     .text 0x16e8..0x31a8, 10 FDE @ 0x1454, 1.712 lệnh AArch64).
// ============================================================================

#ifndef NEXTAI_OPENCUT_NPTH_LOGCAT_H_
#define NEXTAI_OPENCUT_NPTH_LOGCAT_H_

#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <ctime>

namespace nextai {
namespace opencut {
namespace npth_logcat {

// EN: Constants verified from AArch64 opcodes in `libnpth_logcat.so`:
//     - Maximum log file size before stopping: 0xAF000 (716,800 bytes) at 0x25d4 & 0x2a94.
//     - Android log buffer IDs passed to `dump_log_buffer` (FDE[06] @ 0x279c):
//       LOG_ID_MAIN = 0 (0x2590), LOG_ID_SYSTEM = 3 (0x2614), LOG_ID_CRASH = 4 (0x2690).
//     - Logger read mode: 0x800 (ANDROID_LOG_NONBLOCK) at 0x280c.
//     - Signal handler alarm timeout: 30 seconds (`mov w0, #0x1e; bl alarm` @ 0x3068..0x306c).
// VI: Các hằng số xác minh từ mã máy AArch64 trong `libnpth_logcat.so`:
//     - Kích thước tệp log tối đa trước khi dừng: 0xAF000 (716.800 byte) tại 0x25d4 & 0x2a94.
//     - Mã vùng nhớ đệm Android log truyền vào `dump_log_buffer` (FDE[06] @ 0x279c):
//       LOG_ID_MAIN = 0 (0x2590), LOG_ID_SYSTEM = 3 (0x2614), LOG_ID_CRASH = 4 (0x2690).
//     - Chế độ đọc logger: 0x800 (ANDROID_LOG_NONBLOCK) tại 0x280c.
//     - Thời gian chờ alarm trong trình xử lý tín hiệu: 30 giây (`mov w0, #0x1e` @ 0x3068).
constexpr uint64_t kMaxLogFileSizeBytes     = 0x000AF000ULL;  // 716,800 bytes
constexpr int32_t  kLogIdMain               = 0;
constexpr int32_t  kLogIdSystem             = 3;
constexpr int32_t  kLogIdCrash              = 4;
constexpr int32_t  kAndroidLogNonBlockMode  = 0x800;
constexpr uint32_t kFallbackAlarmSeconds    = 30U;

// EN: Multiplicative hash constants for 1-in-500 fstat sampling inside `dump_log_buffer`
//     (0x2a54..0x2a78):
//       `madd w8, w26, w10, w9` with w10 = 0x26E978D5, w9 = 0x010624DC
//       `ror w8, w8, #2`
//       `cmp w8, w11` with w11 = 0x0083126E (triggers when `(w26 % 500) == 499`).
// VI: Hằng số nhân băm để lấy mẫu `fstat` mỗi 500 dòng trong `dump_log_buffer`
//     (0x2a54..0x2a78):
//       `madd w8, w26, w10, w9` với w10 = 0x26E978D5, w9 = 0x010624DC
//       `ror w8, w8, #2; cmp w8, 0x0083126E` (kích hoạt khi `(w26 % 500) == 499`).
constexpr uint32_t kMod500MulInverse = 0x26E978D5U;
constexpr uint32_t kMod500AddOffset  = 0x010624DCU;
constexpr uint32_t kMod500Threshold  = 0x0083126EU;

// EN: Magic reciprocal constants for integer division by 1,000,000 (ns -> ms at 0x2a0c),
//     1,000 (us -> ms at 0x2c88), 3,600 (sec -> hours at 0x2cb0), and 86,400 (sec -> days at 0x2cbc).
// VI: Các hằng số nghịch đảo nhân dùng cho phép chia nguyên cho 1.000.000 (0x2a0c),
//     1.000 (0x2c88), 3.600 (0x2cb0) và 86.400 (0x2cbc).
constexpr uint32_t kRecipDiv1e6_32   = 0x431BDE83U;            // (x * 0x431BDE83) >> 50 == x / 1000000
constexpr uint64_t kRecipDiv1000_64  = 0x20C49BA5E353F7CFULL;  // smulh >> 7 == x / 1000
constexpr uint64_t kRecipDiv60_64    = 0x8888888888888889ULL;  // umulh >> 5 == x / 60 (or >> 11 for 3600)
constexpr uint64_t kRecipDiv86400_64 = 0x48D159E26AF37C05ULL;  // smulh >> 14 == x / 86400

// EN: Android `log_time` structure (8 bytes: tv_sec + tv_nsec) passed by value in X1 to
//     `android_logger_list_alloc_time(int mode, log_time start, pid_t pid)` at 0x2810.
// VI: Cấu trúc `log_time` (8 byte: tv_sec + tv_nsec) truyền qua thanh ghi X1 vào
//     `android_logger_list_alloc_time(int mode, log_time start, pid_t pid)` tại 0x2810.
struct AndroidLogTime {
    uint32_t tv_sec;   // +0x00
    uint32_t tv_nsec;  // +0x04
};
static_assert(sizeof(AndroidLogTime) == 8, "AndroidLogTime must be 8 bytes");

// EN: Android `logger_entry` v1..v4 header inside the 5,120-byte (`0x1400`) stack buffer
//     at `sp + 0xB8` in `dump_log_buffer` (`0x2854..0x2950`):
//       - `len`      (+0x00, uint16_t): payload length (`ldrh w9, [sp, #0xb8]`)
//       - `hdr_size` (+0x02, uint16_t): header size (`ldrh w11, [sp, #0xba]`, defaults to 24 if 0)
//       - `pid`      (+0x04, int32_t) : process ID (`ldr w11, [sp, #0xbc]`)
//       - `tid`      (+0x08, int32_t) : thread ID (`ldr w12, [sp, #0xc0]`)
//       - `sec`      (+0x0C, uint32_t): epoch seconds (`ldr w8, [sp, #0xc4]`)
//       - `nsec`     (+0x10, uint32_t): nanoseconds (`ldr w9, [sp, #0xc8]`)
// VI: Header `logger_entry` của Android trong vùng đệm ngăn xếp 5.120 byte (`0x1400`)
//     tại `sp + 0xB8` trong hàm `dump_log_buffer` (`0x2854..0x2950`).
struct AndroidLoggerEntryHeader {
    uint16_t len;       // +0x00
    uint16_t hdr_size;  // +0x02 (20 for v1, >= 24 for v2..v4)
    int32_t  pid;       // +0x04
    int32_t  tid;       // +0x08
    uint32_t sec;       // +0x0C
    uint32_t nsec;      // +0x10
    uint32_t lid_uid;   // +0x14
};
static_assert(sizeof(AndroidLoggerEntryHeader) == 24, "AndroidLoggerEntryHeader must be 24 bytes");

// EN: `AndroidLogEntry` (64 bytes at `sp + 0x60` in `dump_log_buffer`, populated by
//     `android_log_processBinaryLogBuffer` or parsed directly from text log payload at 0x2944..0x2974).
// VI: Cấu trúc `AndroidLogEntry` (64 byte tại `sp + 0x60` trong `dump_log_buffer`).
struct AndroidLogEntry {
    time_t      tv_sec;       // +0x00 (`sp + 0x60`)
    long        tv_nsec;      // +0x08 (`sp + 0x68`)
    int32_t     priority;     // +0x10 (`sp + 0x70`) -> indexed into "!.VDIWEFS" @ 0x1302
    int32_t     uid;          // +0x14 (`sp + 0x74`)
    int32_t     pid;          // +0x18 (`sp + 0x78`)
    int32_t     tid;          // +0x1C (`sp + 0x7C`)
    const char* tag;          // +0x20 (`sp + 0x80`)
    size_t      tag_len;      // +0x28 (`sp + 0x88`)
    size_t      message_len;  // +0x30 (`sp + 0x90`)
    const char* message;      // +0x38 (`sp + 0x98`)
};
static_assert(sizeof(AndroidLogEntry) == 0x40, "AndroidLogEntry must be 64 bytes");

// EN: 96-byte (0x60) `.bss` global state at 0x0b950..0x0b9b0 in `libnpth_logcat.so`.
// VI: Trạng thái toàn cục `.bss` 96 byte (0x60) tại 0x0b950..0x0b9b0 trong `libnpth_logcat.so`.
struct NpthLogcatBssState {
    char*    log_dir_arg;                         // 0x0b950: argv[1]
    int64_t  reserved_958;                        // 0x0b958
    char*    output_file_path;                    // 0x0b960: "<argv[1]>/logcat.txt"
    int32_t  api_level;                           // 0x0b968: atoi(argv[2])
    uint32_t start_tv_sec;                        // 0x0b96c: current time - atoi(argv[3])
    int32_t  output_fd;                           // 0x0b970: open(output_file_path, O_RDWR|O_CREAT, 0600)
    int32_t  status_log_fd;                       // 0x0b974: optional status log fd (initialized to -1 @ 0x0b810)
    int64_t  reserved_978;                        // 0x0b978
    void*    fn_android_logger_list_alloc_time;   // 0x0b980
    void*    fn_android_logger_list_read;         // 0x0b988
    void*    fn_android_logger_list_free;         // 0x0b990
    void*    fn_android_log_processBinaryLogBuf;  // 0x0b998
    void*    fn_create_android_logger;            // 0x0b9a0
    int64_t  reserved_9a8;                        // 0x0b9a8
};
static_assert(sizeof(NpthLogcatBssState) == 0x60, "NpthLogcatBssState must be 96 bytes");

// EN: Extern declarations for exact byte-for-byte .rodata (1,267 B), .data (320 B),
//     and .text instruction words (1,712 words).
// VI: Khai báo extern cho dữ liệu .rodata (1.267 B), .data (320 B) và .text (1.712 từ lệnh).
extern const uint8_t  kNpthLogcatRodata1267[1267];
extern const uint8_t  kNpthLogcatData320[320];
extern const uint32_t kNpthLogcatTextWords1712[1712];

// EN: Public reconstructed functions corresponding to the 10 FDEs in `.eh_frame_hdr` (0x1454).
// VI: Các hàm tái tạo tương ứng với 10 FDE trong `.eh_frame_hdr` (0x1454).
int NpthLogcatSafeVsnprintf(char* out_buf, size_t cap, const char* fmt, va_list ap) noexcept;
int NpthLogcatSafeSnprintf(char* out_buf, size_t cap, const char* fmt, ...) noexcept;
bool ShouldCheckLogFileSizeAtLine(uint32_t line_index) noexcept;
uint32_t NanosecondsToMilliseconds(uint32_t nsec) noexcept;
void FormatStatusTimestamp(int64_t tv_sec, int64_t tv_usec,
                           int32_t* out_hour, int32_t* out_min,
                           int32_t* out_sec, int32_t* out_ms) noexcept;
int ParseRawLoggerPacket(const uint8_t* packet, size_t bytes_read,
                         int32_t log_id, AndroidLogEntry* out_entry) noexcept;
int FormatLogcatThreadTimeLine(int out_fd, const AndroidLogEntry& entry,
                               char* scratch_buf, size_t scratch_cap) noexcept;
bool ResolveSiblingLibraryPath(const void* anchor_sym_addr, const char* lib_name,
                               char* out_path, size_t out_cap) noexcept;
int RunNpthLogcatMain(int argc, const char* const* argv) noexcept;

}  // namespace npth_logcat
}  // namespace opencut
}  // namespace nextai

#endif  // NEXTAI_OPENCUT_NPTH_LOGCAT_H_
