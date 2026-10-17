// ======================================================================
// RECONSTRUCTED C++ PROC COMM READER IMPLEMENTATION: libnativeaudio.so
// Project: com.nextai.opencut (Cleanroom Re-engineering)
// Module: Process & Thread Name Resolver via Linux ProcFS
// ----------------------------------------------------------------------
// Language: C++17 / Native ABI AArch64
// Bilingual Annotations: English + Tiếng Việt (Rule 12 AGENTS.md)
// Zero-Stub Policy: 100% Concrete Logic matching Disassembly
// ======================================================================

#include "nativeaudio_proc_comm.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

namespace com::bytedance::helios::nativeaudio {

ProcCommReader::ProcCommReader() {
    initFilterPattern(".*(audio|Audio|record|Record|mic|voice|render|player).*");
}

ProcCommReader::~ProcCommReader() {
    std::lock_guard<std::mutex> lock(m_mutex);
    if (m_regex_compiled) {
        regfree(&m_filter_regex);
        m_regex_compiled = false;
    }
}

bool ProcCommReader::initFilterPattern(const char* pattern) {
    std::lock_guard<std::mutex> lock(m_mutex);
    if (m_regex_compiled) {
        regfree(&m_filter_regex);
        m_regex_compiled = false;
    }
    const char* pat = pattern ? pattern : ".*(audio|Audio|record|Record).*";
    int ret = regcomp(&m_filter_regex, pat, REG_EXTENDED | REG_NOSUB);
    m_regex_compiled = (ret == 0);
    return m_regex_compiled;
}

// EN: Read thread command name from /proc/%ld/task/%ld/comm (Disassembly opcode offset 0x826d)
// VN: Đọc tên lệnh của thread từ ProcFS theo chuỗi định dạng "/proc/%ld/task/%ld/comm"
std::string ProcCommReader::getThreadComm(pid_t pid, pid_t tid) {
    char path[128];
    // Opcode rodata 0x826d: "/proc/%ld/task/%ld/comm"
    std::snprintf(path, sizeof(path), "/proc/%ld/task/%ld/comm", static_cast<long>(pid), static_cast<long>(tid));

    int fd = ::open(path, O_RDONLY);
    if (fd < 0) {
        // Fallback to formatted name if ProcFS is restricted or on simulated host
        return formatFallbackComm(static_cast<int32_t>(tid));
    }

    char buf[64];
    std::memset(buf, 0, sizeof(buf));
    ssize_t bytes_read = ::read(fd, buf, sizeof(buf) - 1);
    ::close(fd);

    if (bytes_read > 0) {
        // Strip trailing newline character
        if (buf[bytes_read - 1] == '\n') {
            buf[bytes_read - 1] = '\0';
        }
        return std::string(buf);
    }

    return formatFallbackComm(static_cast<int32_t>(tid));
}

// EN: Format synthetic thread identifier "n_audio_%d" (Disassembly opcode offset 0x8285)
// VN: Định dạng định danh nhân tạo "n_audio_%d" khớp địa chỉ rodata 0x8285
std::string ProcCommReader::formatFallbackComm(int32_t index) {
    char buf[32];
    std::snprintf(buf, sizeof(buf), "n_audio_%d", index);
    return std::string(buf);
}

// EN: Match thread name against privacy/security monitoring regex
// VN: Khớp tên thread với biểu thức chính quy giám sát quyền riêng tư
bool ProcCommReader::isThreadMonitored(const std::string& comm_name) {
    std::lock_guard<std::mutex> lock(m_mutex);
    if (!m_regex_compiled || comm_name.empty()) {
        return true; // Default monitor all if regex failed
    }
    int ret = regexec(&m_filter_regex, comm_name.c_str(), 0, nullptr, 0);
    return (ret == 0);
}

} // namespace com::bytedance::helios::nativeaudio
