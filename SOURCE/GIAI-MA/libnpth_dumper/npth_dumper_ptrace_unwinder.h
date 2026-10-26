/**
 * @file npth_dumper_ptrace_unwinder.h
 * @brief Out-of-process ptrace thread attacher, register reader/poker, and ELF/BuildId analyzer.
 *        Bộ đính kèm luồng ptrace ngoài tiến trình, đọc/ghi thanh ghi và phân tích ELF/BuildId.
 *
 * Reconstructed from AArch64 binary libnpth_dumper.so (`0x007aa0..0x00925c`, `0x00d550..0x00f780`).
 * Tái cấu trúc từ mã nhị phân AArch64 libnpth_dumper.so (`0x007aa0..0x00925c`, `0x00d550..0x00f780`).
 */

#ifndef OPENCUT_NPTH_DUMPER_PTRACE_UNWINDER_H_
#define OPENCUT_NPTH_DUMPER_PTRACE_UNWINDER_H_

#include "npth_dumper_types.h"
#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace npth {
namespace dumper {

/**
 * @brief Unwound frame representation (`80` bytes = `0x50` stride in `unwindstack::AndroidUnwinderData`).
 *        Biểu diễn khung ngăn xếp đã gỡ (`80` byte = bước nhảy `0x50` trong `unwindstack::AndroidUnwinderData`).
 */
struct UnwoundFrameInfo {
    uint64_t    num          = 0;       // +0x00: Frame index / Chỉ số khung
    uint64_t    rel_pc       = 0;       // +0x08: Relative PC inside mapping / PC tương đối trong vùng ánh xạ
    uint64_t    pc           = 0;       // +0x10: Absolute program counter / Bộ đếm chương trình tuyệt đối
    uint64_t    sp           = 0;       // +0x18: Stack pointer / Con trỏ ngăn xếp
    uint32_t    dex_Warning  = 0;       // +0x20: Frame flag (2=DEX, 3=JIT, 4=Error) / Cờ khung
    uint32_t    pad0         = 0;       // +0x24
    std::string function_name;          // +0x28: Demangled symbol name / Tên ký hiệu đã giải mã
    uint64_t    function_offset = 0;    // +0x38: Offset into function / Độ lệch trong hàm
    std::string map_name;               // +0x40: Backing ELF/OAT/DEX path / Đường dẫn file ánh xạ
    uint64_t    map_start    = 0;       // +0x48: Mapping start address / Địa chỉ bắt đầu ánh xạ
    uint64_t    map_end      = 0;       // +0x50: Mapping end address / Địa chỉ kết thúc ánh xạ
    uint64_t    map_offset   = 0;       // +0x58: File offset of mapping / Độ lệch file của ánh xạ
    uint64_t    elf_start_offset = 0;   // +0x60: Embedded ELF offset in APK / Độ lệch ELF nhúng trong APK
    uint16_t    map_flags    = 0;       // +0x68: Protection flags (`PROT_READ|PROT_EXEC`) / Cờ bảo vệ
};

/**
 * @brief Out-of-process ptrace controller, signal translator, and ELF note/soname parser.
 *        Bộ điều khiển ptrace ngoài tiến trình, bộ dịch tín hiệu và phân tích ELF note/soname.
 */
class PtraceUnwinderEngine {
public:
    /**
     * @brief Detect ARMv8.1 LSE atomics (`AT_HWCAP` bit 8, excluding `"exynos9810"`).
     *        Phát hiện nguyên tử ARMv8.1 LSE (`AT_HWCAP` bit 8, ngoại trừ `"exynos9810"`).
     *
     * Disassembly: `0x007b60..0x007bf4`.
     */
    static bool DetectArm64LseAtomics() noexcept;

    /**
     * @brief Atomic 64-bit fetch-add (`ldaddal` if LSE supported, else `ldaxr`/`stlxr`).
     *        Cộng nguyên tử 64-bit (`ldaddal` nếu hỗ trợ LSE, ngược lại dùng `ldaxr`/`stlxr`).
     *
     * Disassembly: `0x007b30..0x007b5c`.
     */
    static uint64_t AtomicFetchAdd64( int64_t delta, volatile uint64_t* target) noexcept;

    /**
     * @brief Format timestamp + severity log message and write to stdout (`fd = 1`).
     *        Định dạng thông điệp nhật ký kèm thời gian + mức độ và ghi ra stdout (`fd = 1`).
     *
     * Disassembly: `0x00e89c..0x00ea68` & `0x00ea6c..0x00eb04`.
     */
    static void LogMessage(int level, const char* fmt, ...);

    /**
     * @brief Convert microseconds to milliseconds using signed magic `0x20c49ba5e353f7cf`.
     *        Chuyển đổi micro giây sang mili giây bằng hằng số có dấu `0x20c49ba5e353f7cf`.
     *
     * Disassembly: `0x008d48..0x008d6c`, `0x00a42c..0x00a45c`.
     */
    static int64_t MicrosToMillisSigned(int64_t delta_us) noexcept;

    /**
     * @brief Convert microseconds to seconds using unsigned magic `0x431bde82d7b634db`.
     *        Chuyển đổi micro giây sang giây bằng hằng số không dấu `0x431bde82d7b634db`.
     *
     * Disassembly: `0x00e914..0x00e928`.
     */
    static uint64_t MicrosToSecondsUnsigned(uint64_t total_us) noexcept;

    /**
     * @brief Attach to a thread via `ptrace(PTRACE_ATTACH = 16)` and wait with `waitpid(__WALL)`.
     *        Đính kèm vào luồng qua `ptrace(PTRACE_ATTACH = 16)` và đợi bằng `waitpid(__WALL)`.
     *
     * Disassembly: `0x00f0b0..0x00f118` (`ptrace_attach`) & `0x00f11c..0x00f1a0` (`ptrace_wait_for_signal`).
     */
    static bool PtraceAttachAndWait(int32_t tid) noexcept;

    /**
     * @brief Detach from a thread via `ptrace(PTRACE_DETACH = 17)`.
     *        Tách khỏi luồng qua `ptrace(PTRACE_DETACH = 17)`.
     *
     * Disassembly: `0x008d00..0x008d28`, `0x009560..0x009584`.
     */
    static bool PtraceDetachThread(int32_t tid) noexcept;

    /**
     * @brief Read 64-bit word from remote process via `ptrace(PTRACE_PEEKTEXT = 1)`.
     *        Đọc từ 64-bit từ tiến trình từ xa qua `ptrace(PTRACE_PEEKTEXT = 1)`.
     *
     * Disassembly: `0x00f27c..0x00f2dc`.
     */
    static int PtracePeekWord(int32_t tid, uint64_t remote_addr, uint64_t* out_word) noexcept;

    /**
     * @brief Write 8-byte aligned 64-bit word to remote process via `ptrace(PTRACE_POKETEXT = 4)`.
     *        Ghi từ 64-bit căn chỉnh 8 byte vào tiến trình từ xa qua `ptrace(PTRACE_POKETEXT = 4)`.
     *
     * Disassembly: `0x00f2e0..0x00f344`.
     */
    static int PtracePokeWord(int32_t tid, uint64_t remote_addr, uint64_t word) noexcept;

    /**
     * @brief Write up to `0x190` (400) bytes into remote process memory using `PTRACE_PEEKTEXT`/`PTRACE_POKETEXT`.
     *        Ghi tối đa `0x190` (400) byte vào bộ nhớ tiến trình từ xa bằng `PTRACE_PEEKTEXT`/`PTRACE_POKETEXT`.
     *
     * Disassembly: `0x00f348..0x00f4bc`.
     */
    static size_t PtraceWriteMemoryBlock(int32_t tid, uint64_t remote_addr, const void* src, size_t len) noexcept;

    /**
     * @brief Check whether `/proc/<pid>/auxv` contains valid non-zero entries (`AT_NULL..AT_SYSINFO_EHDR`).
     *        Kiểm tra xem `/proc/<pid>/auxv` có chứa các mục khác không hợp lệ hay không.
     *
     * Disassembly: `0x00f1a4..0x00f278`.
     */
    static bool ValidateProcAuxv(int32_t pid) noexcept;

    /**
     * @brief Parse `/proc/meminfo` (`MemTotal:`, `MemFree:`, `MemAvailable:`, `Cached:`) into a single summary line.
     *        Phân tích `/proc/meminfo` (`MemTotal:`, `MemFree:`, `MemAvailable:`, `Cached:`) thành một dòng tóm tắt.
     *
     * Disassembly: `0x00f4c0..0x00f708`.
     */
    static int ReadMemInfoSummary(char* out_buf, size_t max_len) noexcept;

    /**
     * @brief Query `sysinfo` and format `totalRam: %llukB, freeRam: %llukB, bufferRam: %llukB\n`.
     *        Truy vấn `sysinfo` và định dạng `totalRam: %llukB, freeRam: %llukB, bufferRam: %llukB\n`.
     *
     * Disassembly: `0x00f70c..0x00f780`.
     */
    static int FormatSysInfoRamSummary(char* out_buf, size_t max_len) noexcept;

    /**
     * @brief Map POSIX signal number (`4..35`) to canonical string (`"SIGSEGV"`, `"SIGABRT"`, etc.).
     *        Ánh xạ số hiệu tín hiệu POSIX (`4..35`) sang chuỗi chuẩn (`"SIGSEGV"`, `"SIGABRT"`, v.v.).
     *
     * Disassembly: `0x00d8cc..0x00d97c`.
     */
    static const char* GetSignalName(int32_t signo) noexcept;

    /**
     * @brief Map `(si_signo, si_code)` pair to canonical fault code string (`"SEGV_MAPERR"`, `"SI_TKILL"`, etc.).
     *        Ánh xạ cặp `(si_signo, si_code)` sang chuỗi mã lỗi chuẩn (`"SEGV_MAPERR"`, `"SI_TKILL"`, v.v.).
     *
     * Disassembly: `0x00d980..0x00dba8`.
     */
    static const char* GetSignalCodeName(const AArch64SigInfo& siginfo) noexcept;

    /**
     * @brief Extract Android abort message from `[anon:libc_malloc]` (`0xb18e40886ac388f0`) or `libc.so` `__abort_message_ptr`.
     *        Trích xuất thông điệp abort của Android từ `[anon:libc_malloc]` hoặc `__abort_message_ptr` của `libc.so`.
     *
     * Disassembly: `0x00d550..0x00d8c8`.
     */
    static bool ExtractAbortMessage(const std::vector<UnwoundFrameInfo>& maps,
                                    int32_t pid,
                                    char* out_buf,
                                    int32_t api_level) noexcept;

    /**
     * @brief Parse ELF64 `.note.gnu.build-id` / `PT_NOTE` (`NT_GNU_BUILD_ID = 3`) or `.text` 16-byte XOR hash.
     *        Phân tích `.note.gnu.build-id` / `PT_NOTE` (`NT_GNU_BUILD_ID = 3`) của ELF64 hoặc băm XOR 16 byte `.text`.
     *
     * Disassembly: `0x00dbac..0x00e108`.
     */
    static bool ExtractElfBuildId(const uint8_t* elf_base,
                                  size_t mapped_size,
                                  std::vector<uint8_t>* out_build_id,
                                  bool allow_text_xor_fallback);

    /**
     * @brief Parse ELF64 `PT_DYNAMIC` (`DT_SONAME = 14`, `DT_HASH = 0x6ffffef5`, `DT_GNU_HASH = 0x6ffffef6`).
     *        Phân tích `PT_DYNAMIC` của ELF64 (`DT_SONAME = 14`, `DT_HASH`, `DT_GNU_HASH`).
     *
     * Disassembly: `0x00e10c..0x00e258`.
     */
    static bool ExtractElfSonameAndCheckDynamic(const uint8_t* elf_base,
                                                uint64_t dyn_offset,
                                                uint64_t dyn_size,
                                                std::string* out_soname,
                                                bool* out_has_Android_relocs);
};

} // namespace dumper
} // namespace npth

#endif // OPENCUT_NPTH_DUMPER_PTRACE_UNWINDER_H_
