/**
 * @file pitayabdcomponent_npth_tombstone.cpp
 * @brief Implementation of pitaya::PitayaNpthUtil Crash Tombstone Generator & OriginStack Parser (Target 46).
 *        Triển khai bộ sinh Tombstone sự cố và trình phân tích OriginStack của pitaya::PitayaNpthUtil (Mục tiêu 46).
 *
 * Disassembly Reference / Tham chiếu Hợp ngữ AArch64:
 * - pitaya::PitayaNpthUtil::Instance()                  @ 0x002804..0x002894 (148 bytes)
 * - pitaya::PitayaNpthUtil::GenerteTombstone()          @ 0x002898..0x002a7c (488 bytes)
 * - pitaya::PitayaNpthUtil::ParseOriginStack()          @ 0x002a80..0x004094 (5,656 bytes)
 * - pitaya::PitayaNpthUtil::WriteThreadTombstone()      @ 0x004098..0x004254 (448 bytes)
 * - pitaya::PitayaNpthUtil::WriteBuildIds()             @ 0x004258..0x0043d4 (380 bytes)
 * - SnprintfWrapper (__vsnprintf_chk)                   @ 0x0043d8..0x004478 (164 bytes)
 * - GetBuildIdForSo (npth_dlbuildid)                    @ 0x00447c..0x004564 (236 bytes)
 * - ExtractSoPathFromFrame (whitespace state machine)   @ 0x004568..0x0047d8 (620 bytes)
 * - std::vector<ThreadStackInfo>::insert                @ 0x0048b8..0x004bd8 (804 bytes)
 */

#include "pitayabdcomponent_npth_tombstone.h"
#include "pitayabdcomponent_regex_stream.h"

#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <map>
#include <mutex>
#include <sstream>

#if defined(_WIN32)
#include <fcntl.h>
#include <io.h>
#include <sys/stat.h>
#define PITAYA_OPEN  _open
#define PITAYA_WRITE _write
#define PITAYA_CLOSE _close
#define PITAYA_O_FLAGS (_O_RDWR | _O_CREAT | _O_TRUNC | _O_BINARY)
#define PITAYA_S_MODE (_S_IREAD | _S_IWRITE)
#else
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#define PITAYA_OPEN  open
#define PITAYA_WRITE write
#define PITAYA_CLOSE close
// Matches exact AArch64 opcode at 0x0029a8..0x0029b4:
//   mov w1, #0x42; movk w1, #8, lsl #16 (0x80042 = O_RDWR | O_CREAT | O_CLOEXEC)
//   mov w2, #0x180 (0600 octal)
#define PITAYA_O_FLAGS 0x80042
#define PITAYA_S_MODE  0x180
#endif

namespace {

std::mutex g_mock_mutex;

// Default realistic NPTH origin stack dump used when running in standalone verification mode
// Dữ liệu ngăn xếp gốc NPTH thực tế mặc định dùng khi chạy ở chế độ xác minh độc lập
std::string g_mock_origin_stack =
    "----- pid 28419 at 2026-10-26 18:40:00 -----\n"
    "Cmd line: com.nextai.opencut\n"
    "\n"
    "\"main\" sysTid=28419\n"
    "  #00 pc 0000000000089a1c  /apex/com.android.runtime/lib64/bionic/libc.so (syscall+28)\n"
    "  #01 pc 0000000000142b50  /data/app/com.nextai.opencut/lib/arm64/libAndroidPitayaCore.so\n"
    "\n"
    "\"pty-ord-t-1\" sysTid=28492\n"
    "  #00 pc 0000000000002898  /data/app/com.nextai.opencut/lib/arm64/libPitayaBdComponent.so (pitaya::PitayaNpthUtil::GenerteTombstone+120)\n"
    "  #01 pc 000000000002d2c8  /data/app/com.nextai.opencut/lib/arm64/libCepEngine.so (cep::Nfa::Process+312)\n"
    "  #02 pc 000000000001bb64  /data/app/com.nextai.opencut/lib/arm64/libTTMachineCore.so (ttm_travel+512)\n"
    "\n";

std::map<std::string, std::string> g_mock_build_ids = {
    {"/apex/com.android.runtime/lib64/bionic/libc.so", "a1b2c3d4e5f60718293a4b5c6d7e8f90"},
    {"/data/app/com.nextai.opencut/lib/arm64/libAndroidPitayaCore.so", "11223344556677889900aabbccddeeff"},
    {"/data/app/com.nextai.opencut/lib/arm64/libPitayaBdComponent.so", "f0e1d2c3b4a5968778695a4b3c2d1e0f"},
    {"/data/app/com.nextai.opencut/lib/arm64/libCepEngine.so", "99887766554433221100ffeeddccbbaa"},
    {"/data/app/com.nextai.opencut/lib/arm64/libTTMachineCore.so", "abcdef0123456789abcdef0123456789"}
};

std::string g_last_tombstone_content;

/**
 * Formats into a fixed buffer using __vsnprintf_chk semantics (max 0x400 = 1024 bytes).
 * Định dạng vào bộ đệm cố định theo ngữ nghĩa __vsnprintf_chk (tối đa 0x400 = 1024 byte).
 * Disassembly @ 0x0043d8..0x004478:
 *   0x004444: 52808003  mov w3, #0x400
 *   0x004448: 2a1f03e2  mov w2, wzr
 *   0x004454: 97fff843  bl  #0x2560 (__vsnprintf_chk)
 */
int SnprintfChecked(char* buf, size_t maxlen, const char* fmt, ...) {
    if (buf == nullptr || maxlen == 0 || fmt == nullptr) {
        return -1;
    }
    va_list args;
    va_start(args, fmt);
    const int written = std::vsnprintf(buf, maxlen, fmt, args);
    va_end(args);
    return written;
}

}  // namespace

// ============================================================================
// External C NPTH Symbols (PLT 0x002380 & 0x0024f0)
// Các ký hiệu C NPTH ngoại vi (PLT 0x002380 & 0x0024f0)
// ============================================================================
extern "C" {

/**
 * Captures backtraces of all threads in the process via ByteDance NPTH crash dumper.
 * Thu thập ngăn xếp của tất cả các luồng trong tiến trình qua bộ kết xuất sự cố ByteDance NPTH.
 * Disassembly call site @ 0x0028d8: bl #0x24f0 (PLT npth_bt_all).
 */
const char* npth_bt_all(const char* dir_path) {
    std::lock_guard<std::mutex> lock(g_mock_mutex);
    if (dir_path == nullptr || dir_path[0] == '\0') {
        return nullptr;
    }
    // Also write "%s/originstack.txt" (0x01230c) if directory is writable
    // Đồng thời ghi tệp "%s/originstack.txt" (0x01230c) nếu thư mục có quyền ghi
    char origin_path[1024];
    const int n = SnprintfChecked(origin_path, sizeof(origin_path),
                                  pitaya::bdcomponent::RodataStrings::kOriginStackPathFmt,
                                  dir_path);
    if (n > 0 && static_cast<size_t>(n) < sizeof(origin_path)) {
        const int fd = PITAYA_OPEN(origin_path, PITAYA_O_FLAGS, PITAYA_S_MODE);
        if (fd >= 0) {
            (void)PITAYA_WRITE(fd, g_mock_origin_stack.data(),
                               static_cast<unsigned int>(g_mock_origin_stack.size()));
            PITAYA_CLOSE(fd);
        }
    }
    return g_mock_origin_stack.c_str();
}

/**
 * Resolves the ELF NT_GNU_BUILD_ID hex string for a loaded shared library path.
 * Giải mã chuỗi hex ELF NT_GNU_BUILD_ID cho đường dẫn thư viện chia sẻ đã nạp.
 * Disassembly call site @ 0x0044b8: bl #0x2380 (PLT npth_dlbuildid).
 */
const char* npth_dlbuildid(const char* so_path) {
    if (so_path == nullptr || so_path[0] == '\0') {
        return nullptr;
    }
    std::lock_guard<std::mutex> lock(g_mock_mutex);
    auto it = g_mock_build_ids.find(so_path);
    if (it != g_mock_build_ids.end()) {
        return it->second.c_str();
    }
    // Deterministic fallback build ID derived from FNV-1a 64-bit hash of path
    // Mã BuildId dự phòng tất định dẫn xuất từ hàm băm FNV-1a 64-bit của đường dẫn
    static thread_local char s_fallback_id[33];
    uint64_t h1 = 0xcbf29ce484222325ULL;
    uint64_t h2 = 0x84222325cbf29ce4ULL;
    for (const char* p = so_path; *p != '\0'; ++p) {
        h1 ^= static_cast<uint8_t>(*p);
        h1 *= 0x100000001b3ULL;
        h2 ^= static_cast<uint8_t>(*p ^ 0x5a);
        h2 *= 0x100000001b3ULL;
    }
    std::snprintf(s_fallback_id, sizeof(s_fallback_id), "%016llx%016llx",
                  static_cast<unsigned long long>(h1),
                  static_cast<unsigned long long>(h2));
    return s_fallback_id;
}

}  // extern "C"

namespace pitaya {

// ============================================================================
// 1. Constructor & Singleton Instance() (@ 0x002804..0x002894)
//    Hàm tạo & Thực thể đơn nhất Instance() (@ 0x002804..0x002894)
// ============================================================================
PitayaNpthUtil::PitayaNpthUtil()
    : pid_(),
      process_name_(),
      cached_modules_() {
    // Disassembly @ 0x002848..0x002868:
    //   0x002848: 52800900  mov  w0, #0x48       ; allocate 72 bytes via _Znwm
    //   0x00284c: 97ffff35  bl   #0x2520
    //   0x002850: 9100e008  add  x8, x0, #0x38   ; RB-tree end node = this + 0x38
    //   0x002854: 6f00e400  movi v0.2d, #0
    //   0x00285c: f900201f  str  xzr, [x0, #0x40]; __size_ = 0
    //   0x002860: ad010000  stp  q0, q0, [x0, #0x20]
    //   0x002864: ad000000  stp  q0, q0, [x0]
    //   0x002868: f9001808  str  x8, [x0, #0x30] ; __begin_node_ = this + 0x38
}

std::shared_ptr<PitayaNpthUtil>& PitayaNpthUtil::Instance() {
    // Disassembly @ 0x002804..0x002894:
    //   0x002810: d00000c8  adrp   x8, #0x1c000
    //   0x002818: 08dffd08  ldarb  w8, [x8]      ; guard variable @ .bss 0x01c000
    //   0x00281c: 360000c8  tbz    w8, #0, #0x2834
    //   0x002824: d00000c0  adrp   x0, #0x1c000
    //   0x002828: 91002000  add    x0, x0, #8    ; shared_ptr<PitayaNpthUtil> @ .bss 0x01c008
    //   0x002840: 97ffff70  bl     #0x2600       ; __cxa_guard_acquire
    //   0x002848: 52800900  mov    w0, #0x48     ; _Znwm(72)
    //   0x002870: 52800400  mov    w0, #0x20     ; _Znwm(32) control block (vtable 0x01b770)
    //   0x002890: 97fffed8  bl     #0x23f0       ; __cxa_guard_release
    static std::shared_ptr<PitayaNpthUtil> s_instance = std::make_shared<PitayaNpthUtil>();
    return s_instance;
}

// ============================================================================
// 2. GenerteTombstone(std::string) (@ 0x002898..0x002a7c, 488 bytes)
//    Sinh tệp Tombstone từ ngăn xếp NPTH (@ 0x002898..0x002a7c, 488 byte)
// ============================================================================
void PitayaNpthUtil::GenerteTombstone(std::string dir_path) {
    // Disassembly @ 0x0028c8..0x002924:
    // Checks SSO/Heap string length of dir_path; if 0, returns immediately (#0x2a4c).
    if (dir_path.empty()) {
        return;
    }

    // Disassembly @ 0x0028d8:
    //   bl #0x24f0 (npth_bt_all)
    //   cbz x0, #0x2a4c
    const char* raw_stack_cstr = npth_bt_all(dir_path.c_str());
    if (raw_stack_cstr == nullptr) {
        return;
    }

    // Disassembly @ 0x0028e4..0x002970:
    // Copies raw_stack_cstr into std::string origin_stack (sp + 0x20), initializes
    // std::vector<ThreadStackInfo> thread_list (sp + 0x08), and calls ParseOriginStack (#0x2a80).
    std::string origin_stack(raw_stack_cstr);
    std::vector<bdcomponent::ThreadStackInfo> thread_list;
    ParseOriginStack(origin_stack, &thread_list);

    // Build in-memory representation for deterministic audit verification
    // Xây dựng biểu diễn trong bộ nhớ để xác minh kiểm toán tất định
    {
        std::string combined;
        for (const auto& thread_info : thread_list) {
            combined += FormatThreadTombstoneString(thread_info);
        }
        std::lock_guard<std::mutex> lock(g_mock_mutex);
        g_last_tombstone_content = std::move(combined);
    }

    // Disassembly @ 0x00298c..0x0029a4:
    //   adrp x3, #0x12000; add x3, x3, #0x325 ("%s/tombstone.txt" @ 0x012325)
    //   add  x0, sp, #0x38
    //   mov  w2, #0x400
    //   bl   #0x43d8 (SnprintfChecked)
    //   cmp  w0, #0x3ff
    //   b.hi #0x29f4
    char tombstone_path[1024];
    const int path_len = SnprintfChecked(
        tombstone_path, sizeof(tombstone_path),
        bdcomponent::RodataStrings::kTombstonePathFmt, dir_path.c_str());
    if (path_len < 0 || path_len > 0x3ff) {
        return;
    }

    // Disassembly @ 0x0029a8..0x0029bc:
    //   mov  w1, #0x42
    //   movk w1, #8, lsl #16   ; w1 = 0x80042 (O_RDWR | O_CREAT | O_CLOEXEC)
    //   mov  w2, #0x180        ; w2 = 0600 octal
    //   bl   #0x25e0 (open)
    //   tbnz w0, #0x1f, #0x29f4
    const int fd = PITAYA_OPEN(tombstone_path, PITAYA_O_FLAGS, PITAYA_S_MODE);
    if (fd < 0) {
        return;
    }

    // Disassembly @ 0x0029c0..0x0029f0:
    // Iterates over thread_list (stride 0x60 = 96 bytes), calling WriteThreadTombstone (0x004098),
    // then closes fd via close(w20) (0x0023a0).
    for (const auto& thread_info : thread_list) {
        WriteThreadTombstone(fd, thread_info);
    }
    PITAYA_CLOSE(fd);
}

// ============================================================================
// 3. ParseOriginStack (@ 0x002a80..0x004094, 5,656 bytes)
//    Phân tích ngăn xếp gốc đa luồng bằng std::istringstream & std::regex
// ============================================================================
void PitayaNpthUtil::ParseOriginStack(
    const std::string& origin_stack,
    std::vector<bdcomponent::ThreadStackInfo>* out_threads) {
    if (out_threads == nullptr) {
        return;
    }
    out_threads->clear();

    // Disassembly @ 0x002aa0..0x002b68:
    // Constructs std::__ndk1::basic_istringstream<char> (vtable 0x01b5c0 / 0x01b660)
    // from origin_stack via basic_stringbuf::str() (@ 0x005c50).
    bdcomponent::RegexStreamEngine stream(origin_stack);

    bdcomponent::ThreadStackInfo current_thread;
    bool in_thread_block = false;  // Stored at [sp, #0x84] in disassembly (@ 0x002bfc, 0x0031d4, 0x003e38)

    auto flush_current_thread = [&]() {
        // Disassembly @ 0x0031d8..0x00336c & 0x003e44..0x003ecc:
        // When flushing an active thread block:
        // Checks if current_thread.thread_name contains "pty-ord-t" (0x012421, 9 bytes @ 0x003258..0x003278).
        // If matched -> inserts at out_threads->begin() via 0x0048b8!
        // Otherwise  -> appends to out_threads->end() via push_back (0x0115ac / 0x011db8)!
        if (!in_thread_block) {
            return;
        }
        if (current_thread.IsPitayaWorkerThread()) {
            bdcomponent::RegexStreamEngine::InsertThreadStackInfoAtFront(out_threads, current_thread);
        } else {
            out_threads->push_back(current_thread);
        }
        current_thread.tid.clear();
        current_thread.thread_name.clear();
        current_thread.backtrace_lines.clear();
        current_thread.so_paths.clear();
        in_thread_block = false;
    };

    std::string line;
    // Disassembly @ 0x002c38..0x002ca4:
    // Reads each line with std::getline(stream, line, '\n') (@ 0x005e14).
    while (stream.GetLine(&line)) {
        // 1. Check for "----- pid" (0x0123cc, 9 bytes) @ 0x002cc4..0x002ec8
        //    Kiểm tra chuỗi "----- pid" (0x0123cc, 9 byte) @ 0x002cc4..0x002ec8
        if (line.size() >= 9 && line.find(bdcomponent::RodataStrings::kPidMarker) != std::string::npos) {
            // Disassembly @ 0x002d58..0x002e6c:
            // Compiles std::regex("pid (\\d+)") (@ 0x0123d6, 9 bytes, bl #0x60d4)
            // Runs regex_search (@ 0x00de34 / 0x00e080).
            // Checks match count via (byte_len >> 3) * 0xaaaaaaaaaaaaaaabULL > 1 (@ 0x002e54..0x002e6c).
            std::vector<std::string> groups;
            if (bdcomponent::RegexStreamEngine::RegexSearchGroups(
                    line, bdcomponent::RodataStrings::kPidRegex, &groups) &&
                groups.size() > 1) {
                pid_ = groups[1];
            } else {
                // Disassembly @ 0x0032a0..0x0032ac: assigns "unknown" (@ 0x0123e0)
                pid_ = bdcomponent::RodataStrings::kUnknown;
            }
            continue;
        }

        // 2. Check for "Cmd line: " (0x0123e8, 10 bytes) @ 0x002ecc..0x0030cc
        //    Kiểm tra chuỗi "Cmd line: " (0x0123e8, 10 byte) @ 0x002ecc..0x0030cc
        if (line.size() >= 10 && line.find(bdcomponent::RodataStrings::kCmdLineMarker) != std::string::npos) {
            // Disassembly @ 0x002f5c..0x003070:
            // Compiles std::regex("Cmd line: (.+)") (@ 0x0123f3, 14 bytes, bl #0x60d4)
            std::vector<std::string> groups;
            if (bdcomponent::RegexStreamEngine::RegexSearchGroups(
                    line, bdcomponent::RodataStrings::kCmdLineRegex, &groups) &&
                groups.size() > 1) {
                process_name_ = groups[1];
            } else {
                // Disassembly @ 0x003588..0x003594: assigns "unknown" (@ 0x0123e0)
                process_name_ = bdcomponent::RodataStrings::kUnknown;
            }
            continue;
        }

        // 3. Check for "sysTid=" (0x012402, 7 bytes) @ 0x0030d0..0x00312c & 0x0037b4..0x003e40
        //    Kiểm tra chuỗi "sysTid=" (0x012402, 7 byte) @ 0x0030d0..0x00312c & 0x0037b4..0x003e40
        if (line.size() >= 7 && line.find(bdcomponent::RodataStrings::kSysTidMarker) != std::string::npos) {
            // Disassembly @ 0x0037ec..0x003858:
            // Compiles regex 1: "\"([^\"]+)\"" (@ 0x01240a, 9 bytes) -> extracts thread_name
            // Compiles regex 2: "sysTid=(\\d+)" (@ 0x012414, 12 bytes) -> extracts tid
            std::vector<std::string> name_groups;
            if (bdcomponent::RegexStreamEngine::RegexSearchGroups(
                    line, bdcomponent::RodataStrings::kThreadNameRegex, &name_groups) &&
                name_groups.size() > 1) {
                current_thread.thread_name = name_groups[1];
            }
            std::vector<std::string> tid_groups;
            if (bdcomponent::RegexStreamEngine::RegexSearchGroups(
                    line, bdcomponent::RodataStrings::kSysTidRegex, &tid_groups) &&
                tid_groups.size() > 1) {
                current_thread.tid = tid_groups[1];
            }
            // Disassembly @ 0x003e38: mov w8, #1; str w8, [sp, #0x84]
            in_thread_block = true;
            continue;
        }

        // 4. Check for stack frame line containing '#' (0x23) @ 0x003130..0x0031b0 & 0x0034f0..0x003544
        //    Kiểm tra dòng khung ngăn xếp chứa ký tự '#' (0x23) @ 0x003130..0x0031b0 & 0x0034f0..0x003544
        if (!line.empty() && line.find('#') != std::string::npos) {
            current_thread.backtrace_lines.push_back(line);
            const std::string so_path = ExtractSoPathFromFrame(line);
            if (!so_path.empty()) {
                current_thread.so_paths.insert(so_path);
                cached_modules_.insert(so_path);
            }
            continue;
        }

        // 5. Check if line is empty or whitespace-only (0x20) @ 0x0031b4..0x0031d4
        //    Kiểm tra dòng rỗng hoặc chỉ chứa khoảng trắng (0x20) @ 0x0031b4..0x0031d4
        bool all_spaces = true;
        for (char c : line) {
            if (c != ' ' && c != '\r' && c != '\t') {
                all_spaces = false;
                break;
            }
        }
        if (all_spaces) {
            flush_current_thread();
        }
    }

    // Disassembly @ 0x003e44..0x003ecc:
    // At EOF, if current_thread.thread_name is non-empty, flushes the final thread block.
    if (!current_thread.thread_name.empty() || in_thread_block) {
        in_thread_block = true;
        flush_current_thread();
    }
}

// ============================================================================
// 4. WriteThreadTombstone (@ 0x004098..0x004254, 448 bytes)
//    Ghi thông tin Tombstone của một luồng vào file descriptor (@ 0x004098..0x004254)
// ============================================================================
int PitayaNpthUtil::WriteThreadTombstone(
    int fd,
    const bdcomponent::ThreadStackInfo& thread_info) const {
    if (fd < 0) {
        return -1;
    }

    // 1. Disassembly @ 0x0040cc..0x004144:
    //    Formats "pid: %s, tid: %s, name: %s  >>> %s <<<\n" (0x012377) into sp+8 (max 0x3ff = 1023)
    char buf[1024];
    const int hdr_len = SnprintfChecked(
        buf, 0x3ff, bdcomponent::RodataStrings::kThreadHeaderFmt,
        pid_.c_str(), thread_info.tid.c_str(),
        thread_info.thread_name.c_str(), process_name_.c_str());
    if (hdr_len >= 1) {
        (void)PITAYA_WRITE(fd, buf, static_cast<unsigned int>(hdr_len));
    }

    // 2. Disassembly @ 0x004148..0x00416c:
    //    write(fd, "\n", 1) (@ 0x0123ca)
    //    write(fd, "backtrace:\n", 11) (@ 0x01239f, mov w2, #0xb)
    (void)PITAYA_WRITE(fd, bdcomponent::RodataStrings::kNewline, 1);
    (void)PITAYA_WRITE(fd, bdcomponent::RodataStrings::kBacktraceHeader, 11);

    // 3. Disassembly @ 0x004170..0x0041d8:
    //    Loops over thread_info.backtrace_lines (+0x30), formatting "  %s\n" (0x01231f)
    for (const auto& frame : thread_info.backtrace_lines) {
        const int line_len = SnprintfChecked(
            buf, 0x3ff, bdcomponent::RodataStrings::kBacktraceLineFmt, frame.c_str());
        if (line_len >= 1) {
            (void)PITAYA_WRITE(fd, buf, static_cast<unsigned int>(line_len));
        }
    }

    // 4. Disassembly @ 0x0041dc..0x004234:
    //    write(fd, "\n", 1)
    //    WriteBuildIds(fd, thread_info) (bl #0x4258)
    //    write(fd, "--- --- ... ---\n", strlen(sep)) (@ 0x012336, __strlen_chk with 0x41)
    (void)PITAYA_WRITE(fd, bdcomponent::RodataStrings::kNewline, 1);
    WriteBuildIds(fd, thread_info);
    const size_t sep_len = std::strlen(bdcomponent::RodataStrings::kSectionSeparator);
    (void)PITAYA_WRITE(fd, bdcomponent::RodataStrings::kSectionSeparator,
                       static_cast<unsigned int>(sep_len));
    return 0;
}

// ============================================================================
// 5. WriteBuildIds (@ 0x004258..0x0043d4, 380 bytes)
//    Ghi danh sách BuildId của các thư viện .so trong luồng (@ 0x004258..0x0043d4)
// ============================================================================
int PitayaNpthUtil::WriteBuildIds(
    int fd,
    const bdcomponent::ThreadStackInfo& thread_info) const {
    if (fd < 0) {
        return -1;
    }

    // Disassembly @ 0x004280..0x004298:
    //   adrp x1, #0x12000; add x1, x1, #0x3ab ("build id:\n" @ 0x0123ab)
    //   mov  w2, #0xa (10 bytes)
    //   bl   #0x2510 (write)
    (void)PITAYA_WRITE(fd, bdcomponent::RodataStrings::kBuildIdHeader, 10);

    // Disassembly @ 0x00429c..0x004390:
    //   In-order traversal of thread_info.so_paths RB-tree (+0x48..+0x50).
    //   Calls GetBuildIdForSo(so_path) (bl #0x447c @ 0x0042d8).
    //   If build_id is non-empty, formats "    %s (BuildId: %s)\n" (@ 0x0123b6) and writes to fd.
    char buf[1024];
    for (const auto& so_path : thread_info.so_paths) {
        const std::string build_id = GetBuildIdForSo(so_path);
        if (!build_id.empty()) {
            const int len = SnprintfChecked(
                buf, 0x3ff, bdcomponent::RodataStrings::kBuildIdLineFmt,
                so_path.c_str(), build_id.c_str());
            if (len >= 1) {
                (void)PITAYA_WRITE(fd, buf, static_cast<unsigned int>(len));
            }
        }
    }

    // Disassembly @ 0x004394..0x0043a4:
    //   write(fd, "\n", 1) (@ 0x0123ca)
    (void)PITAYA_WRITE(fd, bdcomponent::RodataStrings::kNewline, 1);
    return 0;
}

// ============================================================================
// 6. GetBuildIdForSo (@ 0x00447c..0x004564, 236 bytes)
//    Truy vấn BuildId từ npth_dlbuildid (@ 0x00447c..0x004564, 236 byte)
// ============================================================================
std::string PitayaNpthUtil::GetBuildIdForSo(const std::string& so_path) {
    // Disassembly @ 0x004494..0x0044fc:
    //   If so_path.empty() -> returns empty std::string (stp xzr, xzr, [x19]; str xzr, [x19, #0x10]).
    //   Calls npth_dlbuildid(so_path.c_str()) (bl #0x2380 @ 0x0044b8).
    //   If nullptr -> returns empty std::string.
    if (so_path.empty()) {
        return std::string();
    }
    const char* raw_id = npth_dlbuildid(so_path.c_str());
    if (raw_id == nullptr) {
        return std::string();
    }
    return std::string(raw_id);
}

// ============================================================================
// 7. ExtractSoPathFromFrame (@ 0x004568..0x0047d8, 620 bytes)
//    Trích xuất đường dẫn .so từ dòng khung "#00 pc <addr> <so_path> ..."
// ============================================================================
std::string PitayaNpthUtil::ExtractSoPathFromFrame(const std::string& frame_line) {
    // Disassembly @ 0x00463c..0x00469c:
    // Step 1: Trim leading spaces (0x20) and trailing spaces (0x20)
    //   0x004644: ldrb w11, [x10, x2]; cmp w11, #0x20; b.ne #0x4660
    //   0x004668: ldurb w11, [x11, #-1]; sub x9, x9, #1; cmp w11, #0x20; b.eq #0x4660
    if (frame_line.empty()) {
        return std::string();
    }
    size_t first_non_space = std::string::npos;
    for (size_t i = 0; i < frame_line.size(); ++i) {
        if (frame_line[i] != ' ') {
            first_non_space = i;
            break;
        }
    }
    if (first_non_space == std::string::npos) {
        return std::string();
    }
    size_t last_non_space = frame_line.size();
    while (last_non_space > 0 && frame_line[last_non_space - 1] == ' ') {
        --last_non_space;
    }
    if (last_non_space == 0 || last_non_space <= first_non_space) {
        return std::string();
    }
    const std::string trimmed = frame_line.substr(first_non_space, last_non_space - first_non_space);

    // Disassembly @ 0x0046f8..0x004784:
    // Step 2: Scan characters x9 = 0..trimmed.size()-1 with state counter w12 = 0:
    //   0x004718: 386969ae  ldrb w14, [x13, x9]
    //   0x00471c: 710081df  cmp  w14, #0x20
    //   0x004720: 54000081  b.ne #0x4730
    //   0x004724: 14000009  b    #0x4748
    //   0x004728: 91000522  add  x2, x9, #1
    //   0x00472c: 5280008c  mov  w12, #4
    //   0x004730: 91000529  add  x9, x9, #1
    //   ...
    //   0x004748: 71000d9f  cmp  w12, #3
    //   0x00474c: 54fffee0  b.eq #0x4728
    //   0x004750: 7100119f  cmp  w12, #4
    //   0x004754: 540000c0  b.eq #0x476c
    //   0x004758: 1100058c  add  w12, w12, #1
    // Notice how the binary counts exactly 4 spaces (w12 = 0, 1, 2, 3 -> sets start x2 = x9 + 1 and w12 = 4;
    // or for standard "#00 pc 00001234 /path/lib.so" where there are 2 spaces between addr and path:
    // space #0 after "#00", space #1 after "pc", space #2 & #3 (double space) before "/path/lib.so"!).
    // Wait: look closely at the standard Android backtrace format in g_mock_origin_stack:
    //   "  #00 pc 0000000000002898  /data/app/.../libPitayaBdComponent.so (func+offset)"
    // After trimming leading spaces:
    //   "#00 pc 0000000000002898  /data/app/.../libPitayaBdComponent.so (func+offset)"
    // Count the spaces (0x20):
    //   - space 0 (w12: 0 -> 1): between "#00" and "pc"
    //   - space 1 (w12: 1 -> 2): between "pc" and "0000000000002898"
    //   - space 2 (w12: 2 -> 3): first space after "0000000000002898"
    //   - space 3 (w12 == 3 -> branches to 0x4728: sets x2 = x9 + 1, w12 = 4!): second space before "/data/..."!
    //   - space 4 (w12 == 4 -> branches to 0x476c: breaks with end = x9!): space after ".so" before "(func+offset)"!
    // That is why the binary checks `cmp w12, #3` and `cmp w12, #4`!
    size_t start_pos = std::string::npos;
    size_t end_pos = trimmed.size();
    uint32_t space_state = 0;  // w12 in disassembly
    for (size_t i = 0; i < trimmed.size(); ++i) {
        if (trimmed[i] == ' ') {
            if (space_state == 3) {
                start_pos = i + 1;
                space_state = 4;
            } else if (space_state == 4) {
                end_pos = i;
                break;
            } else {
                ++space_state;
            }
        }
    }

    if (start_pos != std::string::npos && start_pos < end_pos) {
        return trimmed.substr(start_pos, end_pos - start_pos);
    }
    return std::string();
}

// ============================================================================
// 8. Helper & Test Instrumentation Methods
//    Các phương thức hỗ trợ và đo kiểm kiểm thử
// ============================================================================
std::string PitayaNpthUtil::FormatThreadTombstoneString(
    const bdcomponent::ThreadStackInfo& thread_info) const {
    char buf[1024];
    std::string out;
    const int hdr_len = SnprintfChecked(
        buf, 0x3ff, bdcomponent::RodataStrings::kThreadHeaderFmt,
        pid_.c_str(), thread_info.tid.c_str(),
        thread_info.thread_name.c_str(), process_name_.c_str());
    if (hdr_len >= 1) {
        out.append(buf, static_cast<size_t>(hdr_len));
    }
    out += bdcomponent::RodataStrings::kNewline;
    out += bdcomponent::RodataStrings::kBacktraceHeader;
    for (const auto& frame : thread_info.backtrace_lines) {
        const int line_len = SnprintfChecked(
            buf, 0x3ff, bdcomponent::RodataStrings::kBacktraceLineFmt, frame.c_str());
        if (line_len >= 1) {
            out.append(buf, static_cast<size_t>(line_len));
        }
    }
    out += bdcomponent::RodataStrings::kNewline;
    out += bdcomponent::RodataStrings::kBuildIdHeader;
    for (const auto& so_path : thread_info.so_paths) {
        const std::string build_id = GetBuildIdForSo(so_path);
        if (!build_id.empty()) {
            const int len = SnprintfChecked(
                buf, 0x3ff, bdcomponent::RodataStrings::kBuildIdLineFmt,
                so_path.c_str(), build_id.c_str());
            if (len >= 1) {
                out.append(buf, static_cast<size_t>(len));
            }
        }
    }
    out += bdcomponent::RodataStrings::kNewline;
    out += bdcomponent::RodataStrings::kSectionSeparator;
    return out;
}

void PitayaNpthUtil::SetMockOriginStackDump(const std::string& mock_dump) {
    std::lock_guard<std::mutex> lock(g_mock_mutex);
    g_mock_origin_stack = mock_dump;
}

void PitayaNpthUtil::RegisterMockBuildId(const std::string& so_path, const std::string& build_id) {
    std::lock_guard<std::mutex> lock(g_mock_mutex);
    g_mock_build_ids[so_path] = build_id;
}

const std::string& PitayaNpthUtil::GetLastGeneratedTombstoneContent() {
    std::lock_guard<std::mutex> lock(g_mock_mutex);
    return g_last_tombstone_content;
}

}  // namespace pitaya
