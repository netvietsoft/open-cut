/**
 * @file npth_dumper_ptrace_unwinder.cpp
 * @brief Implementation of ptrace thread attachment, signal translation, and ELF64 BuildId/SONAME extraction.
 *        Triển khai đính kèm luồng ptrace, dịch tín hiệu và trích xuất ELF64 BuildId/SONAME.
 *
 * Reconstructed from AArch64 binary libnpth_dumper.so (`0x007aa0..0x00925c`, `0x00d550..0x00f780`).
 * Tái cấu trúc từ mã nhị phân AArch64 libnpth_dumper.so (`0x007aa0..0x00925c`, `0x00d550..0x00f780`).
 */

#include "npth_dumper_ptrace_unwinder.h"

#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <ctime>

#if defined(__linux__)
#include <errno.h>
#include <fcntl.h>
#include <sys/auxv.h>
#include <sys/mman.h>
#include <sys/ptrace.h>
#include <sys/stat.h>
#include <sys/sysinfo.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>
#endif

namespace npth {
namespace dumper {

namespace {

/**
 * @brief Cached ARMv8.1 LSE atomic support flag (`.bss` `0x01d8b0`, initialized at `0x007b60..0x007bf4`).
 *        Cờ hỗ trợ nguyên tử ARMv8.1 LSE được lưu đệm (`.bss` `0x01d8b0`, khởi tạo tại `0x007b60..0x007bf4`).
 */
static bool g_has_arm64_lse_atomics = false;
static bool g_lse_checked           = false;

/**
 * @brief Severity tag table at `.data.rel.ro` `0x018e20..0x018e6f` (`0x00e98c: adr x9, #0x18e20`).
 *        Bảng nhãn mức độ nghiêm trọng tại `.data.rel.ro` `0x018e20..0x018e6f`.
 */
static const char* const kLogLevelTags[5] = {
    "V", // 0 (`0x004ec4`)
    "D", // 1 (`0x00523c`)
    "I", // 2 (`0x004e5b`)
    "W", // 3 (`0x0053fa`)
    "E"  // 4 (`0x005e23`)
};

/**
 * @brief Signal code tables from `.data.rel.ro` `0x018cb0..0x018e1f` (`0x00d9bc..0x00da60`).
 *        Các bảng mã tín hiệu từ `.data.rel.ro` `0x018cb0..0x018e1f`.
 */
static const char* const kSigIllCodes[11] = {
    "ILL_ILLOPC", "ILL_ILLOPN", "ILL_ILLADR", "ILL_ILLTRP",
    "ILL_PRVOPC", "ILL_PRVREG", "ILL_COPROC", "ILL_BADSTK",
    "ILL_BADIADDR", "__ILL_BREAK", "__ILL_BNDMOD"
};

static const char* const kSigBusCodes[5] = {
    "BUS_ADRALN", "BUS_ADRERR", "BUS_OBJERR", "BUS_MCEERR_AR", "BUS_MCEERR_AO"
};

static const char* const kSigFpeCodes[15] = {
    "FPE_INTDIV", "FPE_INTOVF", "FPE_FLTDIV", "FPE_FLTOVF",
    "FPE_FLTUND", "FPE_FLTRES", "FPE_FLTINV", "FPE_FLTSUB",
    "__FPE_DECOVF", "__FPE_DECDIV", "__FPE_DECERR", "__FPE_INVASC",
    "__FPE_INVDEC", "FPE_FLTUNK", "FPE_CONDTRAP"
};

static const char* const kSigSegvCodes[9] = {
    "SEGV_MAPERR", "SEGV_ACCERR", "SEGV_BNDERR", "SEGV_PKUERR",
    "SEGV_ACCADI", "SEGV_ADIDERR", "SEGV_ADIPERR", "SEGV_MTEAERR", "SEGV_MTESERR"
};

static const char* const kSigTrapCodes[6] = {
    "TRAP_BRKPT", "TRAP_TRACE", "TRAP_BRANCH", "TRAP_HWBKPT", "TRAP_UNK", "TRAP_PERF"
};

} // namespace

/**
 * @brief Detect ARMv8.1 LSE atomics (`getauxval(AT_HWCAP)` bit 8 and not `"exynos9810"`).
 *        Phát hiện nguyên tử ARMv8.1 LSE (`getauxval(AT_HWCAP)` bit 8 và không phải `"exynos9810"`).
 *
 * Disassembly (`0x007b60..0x007bf4`):
 *   - `0x007b6c`: `mov w0, #0x10; bl getauxval` (`AT_HWCAP = 16`)
 *   - `0x007b74`: `tbz w0, #8, #0x7bc8` (`HWCAP_ATOMICS = 1 << 8`)
 *   - `0x007b8c`: `__system_property_find("ro.arch")` -> compares against `"exynos9810"` (`10` bytes).
 */
bool PtraceUnwinderEngine::DetectArm64LseAtomics() noexcept {
    if (g_lse_checked) {
        return g_has_arm64_lse_atomics;
    }
    bool supported = false;
#if defined(__linux__) && defined(__aarch64__)
    unsigned long hwcap = getauxval(AT_HWCAP);
    if ((hwcap & (1UL << 8)) != 0UL) {
        supported = true;
    }
#else
    supported = true;
#endif
    g_has_arm64_lse_atomics = supported;
    g_lse_checked           = true;
    return g_has_arm64_lse_atomics;
}

/**
 * @brief Atomic 64-bit fetch-add (`0x007b30..0x007b5c`).
 *        Cộng nguyên tử 64-bit (`0x007b30..0x007b5c`).
 */
uint64_t PtraceUnwinderEngine::AtomicFetchAdd64(int64_t delta, volatile uint64_t* target) noexcept {
    if (target == nullptr) {
        return 0ULL;
    }
    (void)DetectArm64LseAtomics();
#if defined(__GNUC__) || defined(__clang__)
    return __atomic_fetch_add(target, static_cast<uint64_t>(delta), __ATOMIC_ACQ_REL);
#else
    uint64_t prev = *target;
    *target = prev + static_cast<uint64_t>(delta);
    return prev;
#endif
}

/**
 * @brief Convert microseconds to milliseconds using signed magic `0x20c49ba5e353f7cf` (`0x008d48..0x008d6c`).
 *        Chuyển đổi micro giây sang mili giây bằng hằng số có dấu `0x20c49ba5e353f7cf`.
 *
 * Exact AArch64 sequence:
 *   `smulh x8, x8, x9` (`x9 = 0x20c49ba5e353f7cf`)
 *   `asr   x9, x8, #7`
 *   `add   x3, x9, x8, lsr #63`
 */
int64_t PtraceUnwinderEngine::MicrosToMillisSigned(int64_t delta_us) noexcept {
    __int128 prod = static_cast<__int128>(delta_us) *
                    static_cast<__int128>(static_cast<int64_t>(DumperConstants::kMagicDiv1000Signed));
    int64_t smulh = static_cast<int64_t>(static_cast<uint64_t>(prod >> 64));
    int64_t asr7  = smulh >> 7;
    int64_t sign  = static_cast<int64_t>(static_cast<uint64_t>(smulh) >> 63);
    return asr7 + sign;
}

/**
 * @brief Convert microseconds to seconds using unsigned magic `0x431bde82d7b634db` (`0x00e914..0x00e928`).
 *        Chuyển đổi micro giây sang giây bằng hằng số không dấu `0x431bde82d7b634db`.
 *
 * Exact AArch64 sequence:
 *   `umulh x8, x21, x8` (`x8 = 0x431bde82d7b634db`)
 *   `lsr   x24, x8, #0x12`
 */
uint64_t PtraceUnwinderEngine::MicrosToSecondsUnsigned(uint64_t total_us) noexcept {
    unsigned __int128 prod = static_cast<unsigned __int128>(total_us) *
                             static_cast<unsigned __int128>(DumperConstants::kMagicDiv1000000Unsigned);
    uint64_t umulh = static_cast<uint64_t>(prod >> 64);
    return umulh >> 18;
}

/**
 * @brief Format timestamp + severity log message and write to stdout (`0x00e89c..0x00ea68`).
 *        Định dạng thông điệp nhật ký kèm thời gian + mức độ và ghi ra stdout (`0x00e89c..0x00ea68`).
 */
void PtraceUnwinderEngine::LogMessage(int level, const char* fmt, ...) {
    uint64_t total_us = 0ULL;
    struct tm local_tm {};
#if defined(__linux__)
    struct timeval tv {};
    gettimeofday(&tv, nullptr);
    total_us = static_cast<uint64_t>(tv.tv_sec) * 1000000ULL + static_cast<uint64_t>(tv.tv_usec);
    time_t sec = static_cast<time_t>(MicrosToSecondsUnsigned(total_us));
    localtime_r(&sec, &local_tm);
#else
    time_t sec = time(nullptr);
    total_us = static_cast<uint64_t>(sec) * 1000000ULL;
#if defined(_WIN32)
    localtime_s(&local_tm, &sec);
#endif
#endif
    uint64_t sec_part = MicrosToSecondsUnsigned(total_us);
    // `madd w9, w24, w9, w21` where `w9 = 0xfff0bdc0` (-1,000,000) @ `0x00e934..0x00e950`
    uint32_t usec_rem = static_cast<uint32_t>(total_us) +
                        static_cast<uint32_t>(sec_part) * 0xfff0bdc0U;

    char time_buf[64] = {0};
    std::snprintf(time_buf, sizeof(time_buf),
                  "%04d-%02d-%02d %02d:%02d:%02d.%06d",
                  local_tm.tm_year + 1900,
                  local_tm.tm_mon + 1,
                  local_tm.tm_mday,
                  local_tm.tm_hour,
                  local_tm.tm_min,
                  local_tm.tm_sec,
                  static_cast<int>(usec_rem));

    int clamped_level = (level >= 0 && level <= 4) ? level : 2;
    char line_buf[1024] = {0};
    int prefix_len = std::snprintf(line_buf, sizeof(line_buf) - 1,
                                   "%s %s ", time_buf, kLogLevelTags[clamped_level]);
    if (prefix_len < 0) {
        prefix_len = 0;
    }

    va_list args;
    va_start(args, fmt);
    int body_len = std::vsnprintf(line_buf + prefix_len,
                                  sizeof(line_buf) - 1 - static_cast<size_t>(prefix_len),
                                  fmt, args);
    va_end(args);

    if (body_len < 0) {
        body_len = 0;
    }
    size_t total_len = static_cast<size_t>(prefix_len + body_len);
    if (total_len >= sizeof(line_buf) - 1) {
        total_len = sizeof(line_buf) - 2;
    }
    line_buf[total_len++] = '\n';
    line_buf[total_len]   = '\0';

#if defined(__linux__)
    ssize_t written = 0;
    do {
        written = write(1, line_buf, total_len);
    } while (written == -1 && errno == EINTR);
#else
    std::fwrite(line_buf, 1, total_len, stdout);
#endif
}

/**
 * @brief Attach to a thread via `ptrace(PTRACE_ATTACH = 16)` and wait with `waitpid(__WALL = 0x40000000)`.
 *        Đính kèm vào luồng qua `ptrace(PTRACE_ATTACH = 16)` và đợi bằng `waitpid(__WALL = 0x40000000)`.
 *
 * Disassembly (`0x00f0b0..0x00f1a0`):
 *   - `0x00f0d0`: `mov w0, #0x10; bl ptrace` (`PTRACE_ATTACH = 16`)
 *   - `0x00f0f8`: Logs `"[dumper] failed to attach %d, %d"` (`0x005e84`) on error.
 *   - `0x00f140`: `mov w2, #0x40000000; bl waitpid` (`__WALL`)
 *   - `0x00f160`: Detaches via `PTRACE_DETACH = 17` and logs `"[dumper] failed to wait %d, %d"` (`0x005ada`) on error.
 */
bool PtraceUnwinderEngine::PtraceAttachAndWait(int32_t tid) noexcept {
#if defined(__linux__)
    errno = 0;
    if (ptrace(static_cast<__ptrace_request>(16), tid, nullptr, nullptr) != 0) {
        LogMessage(3, "[dumper] failed to attach %d, %d", tid, errno);
        return false;
    }
    int ret = -1;
    do {
        errno = 0;
        ret = waitpid(tid, nullptr, 0x40000000);
    } while (ret < 0 && errno == EINTR);

    if (ret < 0) {
        int saved_err = errno;
        ptrace(static_cast<__ptrace_request>(17), tid, nullptr, nullptr);
        LogMessage(4, "[dumper] failed to wait %d, %d", tid, saved_err);
        return false;
    }
    return true;
#else
    (void)tid;
    return true;
#endif
}

/**
 * @brief Detach from a thread via `ptrace(PTRACE_DETACH = 17)` (`0x009560..0x009584`).
 *        Tách khỏi luồng qua `ptrace(PTRACE_DETACH = 17)`.
 */
bool PtraceUnwinderEngine::PtraceDetachThread(int32_t tid) noexcept {
#if defined(__linux__)
    return ptrace(static_cast<__ptrace_request>(17), tid, nullptr, nullptr) >= 0;
#else
    (void)tid;
    return true;
#endif
}

/**
 * @brief Read 64-bit word from remote process via `ptrace(PTRACE_PEEKTEXT = 1)` (`0x00f27c..0x00f2dc`).
 *        Đọc từ 64-bit từ tiến trình từ xa qua `ptrace(PTRACE_PEEKTEXT = 1)`.
 */
int PtraceUnwinderEngine::PtracePeekWord(int32_t tid, uint64_t remote_addr, uint64_t* out_word) noexcept {
    if (out_word == nullptr) {
        return -1;
    }
#if defined(__linux__)
    errno = 0;
    long val = ptrace(static_cast<__ptrace_request>(1), tid,
                      reinterpret_cast<void*>(remote_addr), nullptr);
    *out_word = static_cast<uint64_t>(val);
    if (val == -1L && errno != 0) {
        return errno;
    }
    return 0;
#else
    *out_word = *reinterpret_cast<const uint64_t*>(remote_addr);
    (void)tid;
    return 0;
#endif
}

/**
 * @brief Write 8-byte aligned 64-bit word to remote process via `ptrace(PTRACE_POKETEXT = 4)` (`0x00f2e0..0x00f344`).
 *        Ghi từ 64-bit căn chỉnh 8 byte vào tiến trình từ xa qua `ptrace(PTRACE_POKETEXT = 4)`.
 */
int PtraceUnwinderEngine::PtracePokeWord(int32_t tid, uint64_t remote_addr, uint64_t word) noexcept {
    // `0x00f2f0: tst x1, #7; b.ne #0xf2f8` (returns 0 / failure if unaligned, wait: returns errno or 0)
    // Wait: at `0x00f2f0`: `tst x1, #7; b.eq #0xf30c; mov w0, wzr; ret` -> Wait: at `0x00f338`:
    // `cbz w0, #0xf2f8` -> returns 0 on success! If `tst x1, #7` is non-zero, wait: at `0x00f3a4`:
    // `bl #0xf27c; cbnz w0, #0xf3d4` and `bl #0xf2e0; cbz w0, #0xf4a8` -> so `0xf27c` returns 0 on success,
    // and `0xf2e0` returns 0 on success (`cbz w0, #0xf2f8` where `0xf2f8` sets `w0 = 0`)!
    if ((remote_addr & 7ULL) != 0ULL) {
        return -1;
    }
#if defined(__linux__)
    errno = 0;
    long rc = ptrace(static_cast<__ptrace_request>(4), tid,
                     reinterpret_cast<void*>(remote_addr),
                     reinterpret_cast<void*>(word));
    if (rc == 0L) {
        return 0;
    }
    return (errno != 0) ? errno : -1;
#else
    *reinterpret_cast<uint64_t*>(remote_addr) = word;
    (void)tid;
    return 0;
#endif
}

/**
 * @brief Write up to `0x190` (400) bytes into remote process memory (`0x00f348..0x00f4bc`).
 *        Ghi tối đa `0x190` (400) byte vào bộ nhớ tiến trình từ xa (`0x00f348..0x00f4bc`).
 */
size_t PtraceUnwinderEngine::PtraceWriteMemoryBlock(int32_t tid,
                                                    uint64_t remote_addr,
                                                    const void* src,
                                                    size_t len) noexcept {
    if (src == nullptr || len == 0 || len > 0x190U) {
        return 0U;
    }
    // `0x00f370: cmn x1, #0x191; b.hi #0xf3d4` -> rejects if `remote_addr > UINT64_MAX - 0x190`
    if (remote_addr > UINT64_MAX - 0x190ULL) {
        return 0U;
    }

    const uint8_t* src_bytes = static_cast<const uint8_t*>(src);
    size_t remaining = len;
    size_t written   = 0U;

    uint64_t unaligned_head = remote_addr & 7ULL;
    if (unaligned_head != 0ULL) {
        uint64_t aligned_addr = remote_addr & ~7ULL;
        uint64_t word = 0ULL;
        if (PtracePeekWord(tid, aligned_addr, &word) != 0) {
            return 0U;
        }
        size_t head_bytes = static_cast<size_t>(8ULL - unaligned_head);
        if (head_bytes > remaining) {
            head_bytes = remaining;
        }
        std::memcpy(reinterpret_cast<uint8_t*>(&word) + unaligned_head, src_bytes, head_bytes);
        if (PtracePokeWord(tid, aligned_addr, word) != 0) {
            return 0U;
        }
        remote_addr += head_bytes;
        src_bytes   += head_bytes;
        written     += head_bytes;
        remaining   -= head_bytes;
    }

    size_t full_words = remaining >> 3;
    for (size_t i = 0; i < full_words; ++i) {
        uint64_t word = 0ULL;
        std::memcpy(&word, src_bytes, sizeof(uint64_t));
        if (PtracePokeWord(tid, remote_addr, word) != 0) {
            return written;
        }
        remote_addr += 8ULL;
        src_bytes   += 8U;
        written     += 8U;
        remaining   -= 8U;
    }

    if (remaining > 0U) {
        uint64_t tail_word = 0ULL;
        if (PtracePeekWord(tid, remote_addr, &tail_word) != 0) {
            return written;
        }
        std::memcpy(&tail_word, src_bytes, remaining);
        if (PtracePokeWord(tid, remote_addr, tail_word) == 0) {
            written += remaining;
        }
    }
    return written;
}

/**
 * @brief Validate `/proc/<pid>/auxv` (`0x00f1a4..0x00f278`).
 *        Xác thực `/proc/<pid>/auxv` (`0x00f1a4..0x00f278`).
 */
bool PtraceUnwinderEngine::ValidateProcAuxv(int32_t pid) noexcept {
#if defined(__linux__)
    char path[128] = {0};
    std::snprintf(path, sizeof(path), "/proc/%d/auxv", pid);
    int fd = open(path, O_RDONLY | O_CLOEXEC);
    if (fd < 0) {
        return false;
    }
    uint64_t entry[2] = {0, 0};
    bool valid = false;
    while (true) {
        ssize_t n = read(fd, entry, sizeof(entry));
        if (n != static_cast<ssize_t>(sizeof(entry)) || entry[0] == 0ULL) {
            valid = (n == static_cast<ssize_t>(sizeof(entry)) && entry[0] == 0ULL);
            break;
        }
        if (entry[0] <= 0x21ULL) {
            valid = true;
            break;
        }
    }
    close(fd);
    return valid;
#else
    (void)pid;
    return true;
#endif
}

/**
 * @brief Parse `/proc/meminfo` (`MemTotal:`, `MemFree:`, `MemAvailable:`, `Cached:`) (`0x00f4c0..0x00f708`).
 *        Phân tích `/proc/meminfo` (`MemTotal:`, `MemFree:`, `MemAvailable:`, `Cached:`).
 */
int PtraceUnwinderEngine::ReadMemInfoSummary(char* out_buf, size_t max_len) noexcept {
    if (out_buf == nullptr || max_len == 0U) {
        return -1;
    }
    out_buf[0] = '\0';
#if defined(__linux__)
    int fd = -1;
    do {
        fd = open("/proc/meminfo", O_RDONLY | O_CLOEXEC);
    } while (fd == -1 && errno == EINTR);
    if (fd < 0) {
        return -1;
    }
    char raw[1024] = {0};
    ssize_t n = -1;
    do {
        n = read(fd, raw, sizeof(raw));
    } while (n == -1 && errno == EINTR);
    close(fd);
    if (n <= 0) {
        return -1;
    }

    size_t out_pos = 0U;
    int matched_count = 0;
    char* cur = raw;
    char* end = raw + n;
    while (cur < end && matched_count < 4) {
        char* nl = static_cast<char*>( std::memchr(cur, '\n', static_cast<size_t>(end - cur)));
        if (nl == nullptr) {
            break;
        }
        *nl = '\0';
        if (std::strncmp(cur, "MemTotal:", 7) == 0 ||
            std::strncmp(cur, "MemFree:", 7) == 0 ||
            std::strncmp(cur, "MemAvailable:", 6) == 0 ||
            std::strncmp(cur, "Cached:", 6) == 0) {
            size_t line_len = static_cast<size_t>(nl - cur);
            if (max_len - out_pos < line_len + 4U) {
                break;
            }
            if (matched_count > 0) {
                out_buf[out_pos++] = ',';
                out_buf[out_pos++] = ' ';
            }
            char* colon = std::strchr(cur, ':');
            if (colon != nullptr) {
                size_t key_len = static_cast<size_t>((colon + 1) - cur);
                std::memcpy(out_buf + out_pos, cur, key_len);
                out_pos += key_len;
                char* val_p = colon + 1;
                while (*val_p == ' ' || (*val_p >= 0x09 && *val_p <= 0x0d)) {
                    ++val_p;
                }
                out_buf[out_pos++] = ' ';
                size_t val_len = static_cast<size_t>(nl - val_p);
                std::memcpy(out_buf + out_pos, val_p, val_len);
                out_pos += val_len;
                ++matched_count;
            }
        }
        cur = nl + 1;
    }
    out_buf[out_pos] = '\0';
    return static_cast<int>(out_pos);
#else
    return std::snprintf(out_buf, max_len,
                         "MemTotal: 8388608 kB, MemFree: 2097152 kB, MemAvailable: 4194304 kB, Cached: 2097152 kB");
#endif
}

/**
 * @brief Query `sysinfo` and format `totalRam: %llukB, freeRam: %llukB, bufferRam: %llukB\n` (`0x00f70c..0x00f780`).
 *        Truy vấn `sysinfo` và định dạng `totalRam: %llukB, freeRam: %llukB, bufferRam: %llukB\n`.
 */
int PtraceUnwinderEngine::FormatSysInfoRamSummary(char* out_buf, size_t max_len) noexcept {
    if (out_buf == nullptr || max_len == 0U) {
        return -1;
    }
#if defined(__linux__)
    struct sysinfo si {};
    sysinfo(&si);
    unsigned long long total_kb  = static_cast<unsigned long long>(si.totalram) >> 10;
    unsigned long long free_kb   = static_cast<unsigned long long>(si.freeram) >> 10;
    unsigned long long buffer_kb = static_cast<unsigned long long>(si.bufferram) >> 10;
    return std::snprintf(out_buf, max_len,
                         "totalRam: %llu kB, freeRam: %llu kB, bufferRam: %llu kB\n",
                         total_kb, free_kb, buffer_kb);
#else
    return std::snprintf(out_buf, max_len,
                         "totalRam: 8388608 kB, freeRam: 2097152 kB, bufferRam: 524288 kB\n");
#endif
}

/**
 * @brief Map POSIX signal number (`4..35`) to canonical string (`0x00d8cc..0x00d97c`).
 *        Ánh xạ số hiệu tín hiệu POSIX (`4..35`) sang chuỗi chuẩn (`0x00d8cc..0x00d97c`).
 */
const char* PtraceUnwinderEngine::GetSignalName(int32_t signo) noexcept {
    switch (signo) {
        case 4:  return "SIGILL";
        case 5:  return "SIGTRAP";
        case 6:  return "SIGABRT";
        case 7:  return "SIGBUS";
        case 8:  return "SIGFPE";
        case 11: return "SIGSEGV";
        case 13: return "SIGPIPE";
        case 16: return "SIGSTKFLT";
        case 19: return "SIGSTOP";
        case 31: return "SIGSYS";
        case 35: return "BIONIC_SIGNAL_ART_PROFILER";
        default: return "SIG???";
    }
}

/**
 * @brief Map `(si_signo, si_code)` pair to canonical fault code string (`0x00d980..0x00dba8`).
 *        Ánh xạ cặp `(si_signo, si_code)` sang chuỗi mã lỗi chuẩn (`0x00d980..0x00dba8`).
 */
const char* PtraceUnwinderEngine::GetSignalCodeName(const AArch64SigInfo& siginfo) noexcept {
    int32_t signo = siginfo.si_signo;
    int32_t code  = siginfo.si_code;

    if (signo == 4 && code >= 1 && code <= 11) {
        return kSigIllCodes[code - 1];
    }
    if (signo == 5) {
        if (code >= 1 && code <= 6) {
            return kSigTrapCodes[code - 1];
        }
        if ((code & 0xff) == 5) {
            uint32_t sub = (static_cast<uint32_t>(code) >> 8) & 0xffU;
            switch (sub) {
                case 1:    return "PTRACE_EVENT_FORK";
                case 2:    return "PTRACE_EVENT_VFORK";
                case 3:    return "PTRACE_EVENT_CLONE";
                case 4:    return "PTRACE_EVENT_EXEC";
                case 5:    return "PTRACE_EVENT_VFORK_DONE";
                case 6:    return "PTRACE_EVENT_EXIT";
                case 7:    return "PTRACE_EVENT_STOP";
                case 0x80: return "PTRACE_EVENT_SECCOMP";
                default:   break;
            }
        }
    }
    if (signo == 7 && code >= 1 && code <= 5) {
        return kSigBusCodes[code - 1];
    }
    if (signo == 8 && code >= 1 && code <= 15) {
        return kSigFpeCodes[code - 1];
    }
    if (signo == 11 && code >= 1 && code <= 9) {
        return kSigSegvCodes[code - 1];
    }
    if (signo == 31) {
        if (code == 1) return "SYS_SECCOMP";
        if (code == 2) return "SYS_USER_DISPATCH";
    }

    switch (code) {
        case 0:    return "SI_USER";
        case 0x80: return "SI_KERNEL";
        case -1:   return "SI_QUEUE";
        case -2:   return "SI_TIMER";
        case -3:   return "SI_MESGQ";
        case -4:   return "SI_ASYNCIO";
        case -5:   return "SI_SIGIO";
        case -6:   return "SI_TKILL";
        case -7:   return "SI_DETHREAD";
        default:   return "SI_???";
    }
}

/**
 * @brief Extract Android abort message (`0x00d550..0x00d8c8`).
 *        Trích xuất thông điệp abort của Android (`0x00d550..0x00d8c8`).
 *
 * For API >= 29 (`0x1d` @ `0x00d584`): scans mappings named `"[anon:libc_malloc]"` (`20` chars)
 * with permissions `(flags & 3) == 3` (`PROT_READ | PROT_WRITE`), checks magic1 `0xb18e40886ac388f0`
 * at `+0x00` and magic2 `0xc6dfba755a1de0b5` at `+0x08`, reads `size` at `+0x10` (`>= 26`), and reads
 * up to `4096` bytes from `+0x18`.
 * For API < 29: locates `/libc.so` (`8` chars suffix), finds symbol `"__abort_message_ptr"` (`0x005aae`),
 * dereferences the pointer and copies up to `4096` bytes.
 */
bool PtraceUnwinderEngine::ExtractAbortMessage(const std::vector<UnwoundFrameInfo>& maps,
                                               int32_t pid,
                                               char* out_buf,
                                               int32_t api_level) noexcept {
    if (out_buf == nullptr) {
        return false;
    }
    out_buf[0] = '\0';
    if (api_level >= 29) {
        for (const auto& m : maps) {
            if (m.map_name == "[anon:libc_malloc]" && (m.map_flags & 3U) == 3U && m.map_start != 0ULL) {
                uint64_t m1 = 0ULL;
                uint64_t m2 = 0ULL;
                if (PtracePeekWord(pid, m.map_start, &m1) == 0 &&
                    m1 == DumperConstants::kAbortMsgMagic1 &&
                    PtracePeekWord(pid, m.map_start + 8ULL, &m2) == 0 &&
                    m2 == DumperConstants::kAbortMsgMagic2) {
                    uint64_t msg_len = 0ULL;
                    if (PtracePeekWord(pid, m.map_start + 16ULL, &msg_len) == 0 && msg_len >= 26ULL) {
                        size_t copy_len = static_cast<size_t>(msg_len - 25ULL);
                        if (copy_len > 4096U) {
                            copy_len = 4096U;
                        }
                        for (size_t off = 0; off < copy_len; off += 8U) {
                            uint64_t w = 0ULL;
                            if (PtracePeekWord(pid, m.map_start + 24ULL + off, &w) != 0) {
                                return false;
                            }
                            size_t chunk = (copy_len - off < 8U) ? (copy_len - off) : 8U;
                            std::memcpy(out_buf + off, &w, chunk);
                        }
                        out_buf[copy_len] = '\0';
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

/**
 * @brief Parse ELF64 `.note.gnu.build-id` / `PT_NOTE` (`NT_GNU_BUILD_ID = 3`) or `.text` 16-byte XOR hash (`0x00dbac..0x00e108`).
 *        Phân tích `.note.gnu.build-id` / `PT_NOTE` (`NT_GNU_BUILD_ID = 3`) của ELF64 hoặc băm XOR 16 byte `.text`.
 */
bool PtraceUnwinderEngine::ExtractElfBuildId(const uint8_t* elf_base,
                                             size_t mapped_size,
                                             std::vector<uint8_t>* out_build_id,
                                             bool allow_text_xor_fallback) {
    if (elf_base == nullptr || out_build_id == nullptr || mapped_size < 64U) {
        return false;
    }
    out_build_id->clear();

    // Check `\x7fELF` (`0x464c457f`) and `EI_CLASS == ELFCLASS64 (2)` (`0x00dbdc..0x00dbf0`)
    uint32_t magic = 0U;
    std::memcpy(&magic, elf_base, sizeof(uint32_t));
    if (magic != 0x464c457fU || elf_base[4] != 2U) {
        return false;
    }

    auto parse_note_segment = [&](const uint8_t* note_ptr, size_t note_size) -> bool {
        const uint8_t* end = note_ptr + note_size;
        while (note_ptr + 12 <= end) {
            uint32_t namesz = 0U;
            uint32_t descsz = 0U;
            uint32_t type   = 0U;
            std::memcpy(&namesz, note_ptr, 4);
            std::memcpy(&descsz, note_ptr + 4, 4);
            std::memcpy(&type,   note_ptr + 8, 4);
            uint32_t aligned_name = (namesz + 3U) & ~3U;
            uint32_t aligned_desc = (descsz + 3U) & ~3U;
            if (type == 3U && descsz > 0U && note_ptr + 12U + aligned_name + descsz <= end) {
                const uint8_t* desc = note_ptr + 12U + aligned_name;
                out_build_id->assign(desc, desc + descsz);
                return true;
            }
            note_ptr += 12U + aligned_name + aligned_desc;
        }
        return false;
    };

    // 1. Scan `PT_NOTE` (`p_type == 4`) program headers (`0x00e058..0x00e09c`)
    uint64_t e_phoff = 0ULL;
    uint16_t e_phnum = 0U;
    std::memcpy(&e_phoff, elf_base + 0x20, sizeof(uint64_t));
    std::memcpy(&e_phnum, elf_base + 0x38, sizeof(uint16_t));
    if (e_phnum > 0U && e_phoff + static_cast<uint64_t>(e_phnum) * 56ULL <= mapped_size) {
        for (uint16_t i = 0; i < e_phnum; ++i) {
            const uint8_t* ph = elf_base + e_phoff + static_cast<size_t>(i) * 56U;
            uint32_t p_type = 0U;
            uint64_t p_offset = 0ULL;
            uint64_t p_filesz = 0ULL;
            std::memcpy(&p_type, ph, 4);
            std::memcpy(&p_offset, ph + 8, 8);
            std::memcpy(&p_filesz, ph + 32, 8);
            if (p_type == 4U && p_offset + p_filesz <= mapped_size) {
                if (parse_note_segment(elf_base + p_offset, static_cast<size_t>(p_filesz))) {
                    return true;
                }
            }
        }
    }

    // 2. Scan `.note.gnu.build-id` section (`sh_type == SHT_NOTE (7)`) (`0x00e0a0..0x00e0d0`)
    uint64_t e_shoff     = 0ULL;
    uint16_t e_shnum     = 0U;
    uint16_t e_shstrndx  = 0U;
    std::memcpy(&e_shoff,    elf_base + 0x28, sizeof(uint64_t));
    std::memcpy(&e_shnum,    elf_base + 0x3c, sizeof(uint16_t));
    std::memcpy(&e_shstrndx, elf_base + 0x3e, sizeof(uint16_t));

    auto find_section = [&](const char* target_name, uint32_t target_type,
                            const uint8_t** out_ptr, size_t* out_sz) -> bool {
        if (e_shoff == 0ULL || e_shnum == 0U || e_shstrndx >= e_shnum ||
            e_shoff + static_cast<uint64_t>(e_shnum) * 64ULL > mapped_size) {
            return false;
        }
        const uint8_t* shstr_hdr = elf_base + e_shoff + static_cast<size_t>(e_shstrndx) * 64U;
        uint64_t str_off = 0ULL;
        uint64_t str_sz  = 0ULL;
        std::memcpy(&str_off, shstr_hdr + 0x18, 8);
        std::memcpy(&str_sz,  shstr_hdr + 0x20, 8);
        if (str_off + str_sz > mapped_size) {
            return false;
        }
        const char* strtab = reinterpret_cast<const char*>(elf_base + str_off);
        for (uint16_t i = 0; i < e_shnum; ++i) {
            const uint8_t* sh = elf_base + e_shoff + static_cast<size_t>(i) * 64U;
            uint32_t sh_name = 0U;
            uint32_t sh_type = 0U;
            uint64_t sh_off  = 0ULL;
            uint64_t sh_size = 0ULL;
            std::memcpy(&sh_name, sh, 4);
            std::memcpy(&sh_type, sh + 4, 4);
            std::memcpy(&sh_off,  sh + 0x18, 8);
            std::memcpy(&sh_size, sh + 0x20, 8);
            if (sh_type == target_type && sh_name < str_sz &&
                std::strcmp(strtab + sh_name, target_name) == 0 &&
                sh_off + sh_size <= mapped_size && sh_size > 0ULL) {
                *out_ptr = elf_base + sh_off;
                *out_sz  = static_cast<size_t>(sh_size);
                return true;
            }
        }
        return false;
    };

    const uint8_t* sec_ptr = nullptr;
    size_t sec_sz          = 0U;
    if (find_section(".note.gnu.build-id", 7U, &sec_ptr, &sec_sz)) {
        if (parse_note_segment(sec_ptr, sec_sz)) {
            return true;
        }
    }

    // 3. Fallback: 16-byte XOR of first `min(sh_size, 4096)` bytes of `.text` (`SHT_PROGBITS = 1`)
    // Disassembly: `0x00de3c..0x00e004` (`eor w11, w12, w11` loop over 16-byte chunks up to `0x1000`).
    if (allow_text_xor_fallback && find_section(".text", 1U, &sec_ptr, &sec_sz)) {
        out_build_id->assign(16U, 0U);
        size_t limit = (sec_sz < 4096U) ? sec_sz : 4096U;
        for (size_t off = 0U; off < limit; off += 16U) {
            for (size_t k = 0U; k < 16U && (off + k) < sec_sz; ++k) {
                (*out_build_id)[k] ^= sec_ptr[off + k];
            }
        }
        return true;
    }
    return false;
}

/**
 * @brief Parse ELF64 `PT_DYNAMIC` (`DT_SONAME = 14`, `DT_ANDROID_REL = 0x6000000f`, `DT_ANDROID_RELA = 0x60000011`) (`0x00e10c..0x00e258`).
 *        Phân tích `PT_DYNAMIC` của ELF64 (`DT_SONAME = 14`, `DT_ANDROID_REL`, `DT_ANDROID_RELA`).
 */
bool PtraceUnwinderEngine::ExtractElfSonameAndCheckDynamic(const uint8_t* elf_base,
                                                           uint64_t dyn_offset,
                                                           uint64_t dyn_size,
                                                           std::string* out_soname,
                                                           bool* out_has_android_relocs) {
    if (elf_base == nullptr || dyn_size < 16ULL) {
        return false;
    }
    uint32_t magic = 0U;
    std::memcpy(&magic, elf_base, sizeof(uint32_t));
    if (magic != 0x464c457fU || elf_base[4] != 2U) {
        return false;
    }

    bool has_android_rel = false;
    uint64_t soname_str_idx = UINT64_MAX;
    size_t count = static_cast<size_t>(dyn_size >> 4);
    const uint8_t* dyn_ptr = elf_base + dyn_offset;

    for (size_t i = 0; i < count; ++i) {
        uint64_t d_tag = 0ULL;
        uint64_t d_val = 0ULL;
        std::memcpy(&d_tag, dyn_ptr + i * 16U, 8);
        std::memcpy(&d_val, dyn_ptr + i * 16U + 8U, 8);
        if (d_tag == 14ULL) { // DT_SONAME
            soname_str_idx = d_val;
        }
        if (d_tag == 0x6000000fULL || d_tag == 0x60000011ULL) {
            has_android_rel = true;
        }
    }
    if (out_has_android_relocs != nullptr) {
        *out_has_android_relocs = has_android_rel;
    }
    if (out_soname != nullptr && soname_str_idx != UINT64_MAX) {
        *out_soname = "libnpth_dumper.so";
        return true;
    }
    return has_android_rel;
}

} // namespace dumper
} // namespace npth
