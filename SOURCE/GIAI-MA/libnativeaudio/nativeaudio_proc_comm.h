// ======================================================================
// RECONSTRUCTED C++ PROC COMM READER HEADER: libnativeaudio.so
// Project: com.nextai.opencut (Cleanroom Re-engineering)
// Module: Process & Thread Name Resolver via Linux ProcFS
// ----------------------------------------------------------------------
// Language: C++17 / Native ABI AArch64
// Bilingual Annotations: English + Tiếng Việt (Rule 12 AGENTS.md)
// Zero-Stub Policy: 100% Concrete Logic matching Disassembly
// ======================================================================

#pragma once

#include "nativeaudio_types.h"
#include <string>
#include <mutex>
#include <regex.h>

namespace com::bytedance::helios::nativeaudio {

// ======================================================================
// EN: ProcCommReader Class
// VN: Lớp ProcCommReader (Đọc định danh tiến trình và tên luồng qua ProcFS)
// ======================================================================
class ProcCommReader {
private:
    std::mutex m_mutex;
    regex_t m_filter_regex;
    bool m_regex_compiled{false};

public:
    ProcCommReader();
    ~ProcCommReader();

    // EN: Initialize thread name filter pattern
    // VN: Khởi tạo biểu thức chính quy lọc tên luồng
    bool initFilterPattern(const char* pattern = nullptr);

    // EN: Read thread command name from /proc/%ld/task/%ld/comm (Disassembly 0x826d)
    // VN: Đọc tên lệnh của luồng từ /proc/%ld/task/%ld/comm
    std::string getThreadComm(pid_t pid, pid_t tid);

    // EN: Format fallback synthetic thread identifier "n_audio_%d" (Disassembly 0x8285)
    // VN: Định dạng định danh luồng nhân tạo dự phòng "n_audio_%d"
    static std::string formatFallbackComm(int32_t index);

    // EN: Match thread name against privacy/security filter
    // VN: Kiểm tra tên luồng theo quy tắc lọc bảo mật
    bool isThreadMonitored(const std::string& comm_name);
};

} // namespace com::bytedance::helios::nativeaudio
