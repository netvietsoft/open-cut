/**
 * @file pitayabdcomponent_types.h
 * @brief Exact AArch64 ABI Types, .rodata String Offsets, VTable Layouts & Constants for libPitayaBdComponent.so (Target 46).
 *        Định nghĩa kiểu dữ liệu ABI AArch64 chính xác, độ lệch chuỗi .rodata, bố cục VTable và hằng số cho libPitayaBdComponent.so (Mục tiêu 46).
 *
 * Binary Ground Truth / Thực tế Nhị phân:
 * - File: extracted/lib/arm64-v8a/libPitayaBdComponent.so (100,176 bytes, ELF64 AArch64 LSB shared object)
 * - PT_LOAD[0] (R+X): vaddr 0x000000..0x014730 -> file offset 0x000000..0x014730
 * - PT_LOAD[1] (R+W): vaddr 0x01b5a8..0x01c018 -> file offset 0x0175a8..0x018000 (file_offset = vaddr - 0x4000)
 * - Dynamic Symbols: 60 total (14 exported + 46 imported), 2 JNI exported methods + 1 C++ exported method.
 */

#ifndef NEXTAI_OPENCUT_PITAYABDCOMPONENT_TYPES_H_
#define NEXTAI_OPENCUT_PITAYABDCOMPONENT_TYPES_H_

#include <cstddef>
#include <cstdint>
#include <set>
#include <string>
#include <vector>

namespace pitaya {
namespace bdcomponent {

// ============================================================================
// 1. Exact .rodata String Constants & Tail-Shared Offsets (0x012309..0x0124c3)
//    Hằng số chuỗi .rodata chính xác & Độ lệch dùng chung đuôi (0x012309..0x0124c3)
// ============================================================================
struct RodataStrings {
    // 0x01230c: "%s/originstack.txt"
    static constexpr const char* kOriginStackPathFmt = "%s/originstack.txt";
    // 0x01231f: "  %s\n"
    static constexpr const char* kBacktraceLineFmt = "  %s\n";
    // 0x012325: "%s/tombstone.txt"
    static constexpr const char* kTombstonePathFmt = "%s/tombstone.txt";
    // 0x012336: "--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---\n" (64 bytes)
    static constexpr const char* kSectionSeparator =
        "--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---\n";
    // 0x012377: "pid: %s, tid: %s, name: %s  >>> %s <<<\n"
    static constexpr const char* kThreadHeaderFmt = "pid: %s, tid: %s, name: %s  >>> %s <<<\n";
    // 0x01239f: "backtrace:\n" (11 bytes)
    static constexpr const char* kBacktraceHeader = "backtrace:\n";
    // 0x0123ab: "build id:\n" (10 bytes)
    static constexpr const char* kBuildIdHeader = "build id:\n";
    // 0x0123b6: "    %s (BuildId: %s)\n"
    static constexpr const char* kBuildIdLineFmt = "    %s (BuildId: %s)\n";
    // 0x0123ca: "\n" (1 byte newline before "----- pid")
    static constexpr const char* kNewline = "\n";
    // 0x0123cc: "----- pid" (9 bytes)
    static constexpr const char* kPidMarker = "----- pid";
    // 0x0123d6: "pid (\\d+)" (9 bytes)
    static constexpr const char* kPidRegex = "pid (\\d+)";
    // 0x0123e0: "unknown" (7 bytes)
    static constexpr const char* kUnknown = "unknown";
    // 0x0123e8: "Cmd line: " (10 bytes)
    static constexpr const char* kCmdLineMarker = "Cmd line: ";
    // 0x0123f3: "Cmd line: (.+)" (14 bytes)
    static constexpr const char* kCmdLineRegex = "Cmd line: (.+)";
    // 0x012402: "sysTid=" (7 bytes)
    static constexpr const char* kSysTidMarker = "sysTid=";
    // 0x01240a: "\"([^\"]+)\"" (9 bytes)
    static constexpr const char* kThreadNameRegex = "\"([^\"]+)\"";
    // 0x012414: "sysTid=(\\d+)" (12 bytes)
    static constexpr const char* kSysTidRegex = "sysTid=(\\d+)";
    // 0x012421: "pty-ord-t" (9 bytes — Pitaya ordinary worker thread prefix)
    static constexpr const char* kPitayaThreadPrefix = "pty-ord-t";
    // 0x01242b: "libalog.so" (10 bytes)
    static constexpr const char* kLibALogSo = "libalog.so";
    // 0x012436: "PTY-" (4 bytes — Android log tag)
    static constexpr const char* kLogTag = "PTY-";
    // 0x01243b: "unknow error" (12 bytes — exact binary typo preserved!)
    static constexpr const char* kUnknownError = "unknow error";
    // 0x012448: "alog_write" (10 bytes)
    static constexpr const char* kALogWriteSym = "alog_write";
    // 0x012453: "npth_dlopen(\"libalog.so\") error, msg is :%s"
    static constexpr const char* kNpthDlopenErrFmt = "npth_dlopen(\"libalog.so\") error, msg is :%s";
    // 0x012458 (+5 tail-shared): "dlopen(\"libalog.so\") error, msg is :%s"
    static constexpr const char* kDlopenErrFmt = "dlopen(\"libalog.so\") error, msg is :%s";
    // 0x01247f: "npth_dlsym(handle, \"alog_write\"); error, msg is :%s"
    static constexpr const char* kNpthDlsymErrFmt = "npth_dlsym(handle, \"alog_write\"); error, msg is :%s";
    // 0x012484 (+5 tail-shared): "dlsym(handle, \"alog_write\"); error, msg is :%s"
    static constexpr const char* kDlsymErrFmt = "dlsym(handle, \"alog_write\"); error, msg is :%s";
    // 0x0124b3: "npth_dl success!"
    static constexpr const char* kNpthDlSuccess = "npth_dl success!";
    // 0x0124b8 (+5 tail-shared): "dl success!"
    static constexpr const char* kDlSuccess = "dl success!";
};

// ============================================================================
// 2. Exact AArch64 Binary Offsets & Magic Constants
//    Độ lệch nhị phân AArch64 và hằng số ma thuật chính xác
// ============================================================================
struct BinaryConstants {
    // Exported function VAddrs / Địa chỉ hàm xuất khẩu
    static constexpr uint64_t kVAddrJStringToStdString           = 0x00264c;
    static constexpr uint64_t kVAddrNativeGenerateAllStack       = 0x002780;
    static constexpr uint64_t kVAddrPitayaNpthUtilInstance       = 0x002804;
    static constexpr uint64_t kVAddrGenerteTombstone             = 0x002898;
    static constexpr uint64_t kVAddrParseOriginStack             = 0x002a80;
    static constexpr uint64_t kVAddrWriteThreadTombstone         = 0x004098;
    static constexpr uint64_t kVAddrWriteBuildIds                = 0x004258;
    static constexpr uint64_t kVAddrSnprintfWrapper              = 0x0043d8;
    static constexpr uint64_t kVAddrGetBuildIdForSo              = 0x00447c;
    static constexpr uint64_t kVAddrExtractSoPathFromFrame       = 0x004568;
    static constexpr uint64_t kVAddrStdStringAssign              = 0x0047dc;
    static constexpr uint64_t kVAddrVectorInsertThreadStackInfo  = 0x0048b8;
    static constexpr uint64_t kVAddrNativeGetFuncAddr            = 0x004c54;
    static constexpr uint64_t kVAddrStringBufSeekoff             = 0x005044;
    static constexpr uint64_t kVAddrStreamBufXsgetn              = 0x005190;
    static constexpr uint64_t kVAddrStringBufUnderflow           = 0x0052c0;
    static constexpr uint64_t kVAddrStringBufPbackfail           = 0x005370;
    static constexpr uint64_t kVAddrStringBufOverflow            = 0x005444;
    static constexpr uint64_t kVAddrThreadStackInfoDtor          = 0x005b90;
    static constexpr uint64_t kVAddrStringBufStrSet              = 0x005c50;
    static constexpr uint64_t kVAddrRbTreeDestroy                = 0x005dc4;
    static constexpr uint64_t kVAddrStdGetline                   = 0x005e14;
    static constexpr uint64_t kVAddrBasicRegexCtor               = 0x0060d4;
    static constexpr uint64_t kVAddrRegexSearch                  = 0x00de34;
    static constexpr uint64_t kVAddrMatchResultsSearch           = 0x00e080;

    // .bss Singleton addresses / Địa chỉ Singleton trong .bss
    static constexpr uint64_t kVAddrInstanceGuard                = 0x01c000;
    static constexpr uint64_t kVAddrInstanceSharedPtr            = 0x01c008;

    // Struct sizes & POSIX flags / Kích thước struct và cờ POSIX
    static constexpr size_t   kPitayaNpthUtilSize                = 0x48;     // 72 bytes (@ 0x002848: mov w0, #0x48)
    static constexpr size_t   kSharedPtrControlBlockSize         = 0x20;     // 32 bytes (@ 0x002870: mov w0, #0x20)
    static constexpr size_t   kThreadStackInfoSize               = 0x60;     // 96 bytes (@ 0x0029e0: add x21, x21, #0x60)
    static constexpr int      kTombstoneOpenFlags                = 0x80042;  // O_RDWR | O_CREAT | O_CLOEXEC (@ 0x0029a8..0x0029b0)
    static constexpr int      kTombstoneOpenMode                 = 0x180;    // 0600 octal (@ 0x0029b4: mov w2, #0x180)
    static constexpr int      kDlopenFlags                       = 0x102;    // RTLD_NOW | RTLD_GLOBAL (@ 0x004c68: mov w1, #0x102)
    static constexpr int      kAndroidLogDebug                   = 3;        // ANDROID_LOG_DEBUG (@ 0x004cc0: mov w0, #3)

    // 64-bit Multiplicative Inverse for dividing by 24 (sizeof(sub_match)) and 96 (sizeof(ThreadStackInfo)):
    // 0xaaaaaaaaaaaaaaab * 3 == 1 (mod 2^64).
    // Dividing byte_diff by 24: (byte_diff >> 3) * 0xaaaaaaaaaaaaaaabULL (@ 0x002e54..0x002e68)
    // Dividing byte_diff by 96: (byte_diff >> 5) * 0xaaaaaaaaaaaaaaabULL (@ 0x0048e0..0x00490c)
    static constexpr uint64_t kMagicMulInv3                      = 0xaaaaaaaaaaaaaaabULL;
};

// ============================================================================
// 3. ThreadStackInfo (96 bytes / 0x60 bytes ABI Layout)
//    Cấu trúc thông tin ngăn xếp luồng ThreadStackInfo (Bố cục ABI 96 byte / 0x60)
// ============================================================================
/**
 * Disassembly verification at 0x0029d0..0x002a24, 0x004098..0x004258, 0x0048b8..0x004ba8:
 * - +0x00..+0x17: std::string tid               (24 bytes, matched by "sysTid=(\\d+)")
 * - +0x18..+0x2f: std::string thread_name       (24 bytes, matched by "\"([^\"]+)\"")
 * - +0x30..+0x47: std::vector<std::string> backtrace_lines (24 bytes, lines starting with '#')
 * - +0x48..+0x5f: std::set<std::string> so_paths           (24 bytes, unique .so paths for BuildId lookup)
 * Total size on 64-bit Android NDK libc++ = 24 * 4 = 96 bytes (0x60).
 */
struct ThreadStackInfo {
    std::string tid;                            // +0x00 (24B on Android NDK libc++)
    std::string thread_name;                    // +0x18 (24B on Android NDK libc++)
    std::vector<std::string> backtrace_lines;   // +0x30 (24B on Android NDK libc++)
    std::set<std::string> so_paths;             // +0x48 (24B on Android NDK libc++)

    /**
     * Checks whether this thread is a Pitaya ordinary worker thread ("pty-ord-t").
     * Kiểm tra xem luồng này có phải là luồng công nhân Pitaya ("pty-ord-t") hay không.
     * Matches opcode at 0x003240..0x003288 (memchr 'p' + memcmp "pty-ord-t", 9).
     */
    bool IsPitayaWorkerThread() const noexcept {
        return thread_name.find(RodataStrings::kPitayaThreadPrefix) != std::string::npos;
    }
};

}  // namespace bdcomponent
}  // namespace pitaya

#endif  // NEXTAI_OPENCUT_PITAYABDCOMPONENT_TYPES_H_
