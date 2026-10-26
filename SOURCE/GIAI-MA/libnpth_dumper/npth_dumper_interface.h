/**
 * ============================================================================
 * File: npth_dumper_interface.h
 * Library: libnpth_dumper.so (90,384 bytes, ELF64 AArch64 PIE Executable)
 * Dependencies: liblog.so, libdl.so, libc.so
 * ============================================================================
 * [EN] Public C++17 & C ABI interface for ByteDance NPTH Out-of-Process Crash
 *      Dumper (`libnpth_dumper.so` — `/system/bin/linker64`).
 *      Exposes all 10 exported `.dynsym` functions (`write_minidump` plus 9
 *      inline std::vector/std::string helpers) alongside the complete
 *      out-of-process `dumper_main` (`0x008108`), `PtraceUnwinderEngine`
 *      (`0x007aa0..0x00925c`, `0x00d550..0x00f780`), `TombstoneGenerator`
 *      (`0x009260..0x00d54c`), `CrashProtectorEngine` (`0x00f914..0x011108`),
 *      and `MinidumpGenerator` (`0x01110c..0x01412f`).
 *
 * [VN] Giao diện C++17 & C ABI công khai cho Trình kết xuất sự cố độc lập
 *      tiến trình ByteDance NPTH (`libnpth_dumper.so` — `/system/bin/linker64`).
 *      Cung cấp toàn bộ 10 hàm xuất `.dynsym` (`write_minidump` cùng 9 hàm
 *      trợ giúp nội tuyến std::vector/std::string) kết hợp đầy đủ các bộ máy
 *      `dumper_main` (`0x008108`), `PtraceUnwinderEngine`, `TombstoneGenerator`,
 *      `CrashProtectorEngine`, và `MinidumpGenerator`.
 * ============================================================================
 */

#ifndef OPENCUT_NPTH_DUMPER_INTERFACE_H_
#define OPENCUT_NPTH_DUMPER_INTERFACE_H_

#include "npth_dumper_types.h"
#include "npth_dumper_ptrace_unwinder.h"
#include "npth_dumper_tombstone.h"
#include "npth_dumper_minidump_protector.h"

namespace npth {
namespace dumper {

/**
 * [EN] Unified facade orchestrating the complete out-of-process NPTH crash
 *      dumper pipeline (`dumper_main` @ `0x008108..0x008a00`), LSE atomic
 *      dispatch (`0x007b30..0x007b5c`), signal trampoline (`0x00ab78`),
 *      crash protector verification (`0x00f914..0x011108`), and Breakpad MDMP
 *      generation (`write_minidump` @ `0x01110c`).
 * [VN] Lớp mặt tiền hợp nhất điều phối toàn bộ đường ống kết xuất sự cố độc lập
 *      tiến trình NPTH (`dumper_main` @ `0x008108..0x008a00`), điều phối nguyên
 *      tử LSE (`0x007b30..0x007b5c`), bàn đạp tín hiệu (`0x00ab78`), xác minh
 *      trình bảo vệ sự cố (`0x00f914..0x011108`), và sinh Breakpad MDMP
 *      (`write_minidump` @ `0x01110c`).
 */
class NpthDumperFacade {
public:
    /**
     * [EN] Executes the `dumper_main(argc, argv)` workflow (`0x008108..0x008a00`).
     *      Installs the 8-slot `.data` signal table (`0x01d6f8..0x01d837`) with
     *      `sa_flags = 0x10000004` (`0x008140`), sets a 30-second alarm
     *      (`0x0081bc`: `mov w0, #0x1e; bl alarm`), and reads the 4,784-byte
     *      (`0x12b0`) `CrashPipePayload` from standard input (`fd = 0`, `0x0081d8`).
     * [VN] Thực thi luồng `dumper_main(argc, argv)` (`0x008108..0x008a00`).
     *      Cài đặt bảng 8 khe tín hiệu `.data` (`0x01d6f8..0x01d837`) với
     *      `sa_flags = 0x10000004` (`0x008140`), đặt hẹn giờ 30 giây (`0x0081bc`),
     *      và đọc gói `CrashPipePayload` 4.784 byte (`0x12b0`) từ `fd = 0` (`0x0081d8`).
     */
    static int RunDumperMain(
        int argc,
        const char* const* argv,
        const CrashPipePayload* injected_payload);
};

} // namespace dumper
} // namespace npth

extern "C" {

/**
 * [EN] Exported `.dynsym` #160 (`0x01110c`, size `1284 bytes`):
 *      `write_minidump(const char* minidump_path, int target_pid, const void* crash_context, size_t context_size)`
 *      Generates a complete Google Breakpad `MDMP` (`0x504d444d`, version `0xa793`)
 *      minidump file for the crashed target process.
 * [VN] Hàm xuất `.dynsym` #160 (`0x01110c`, kích thước `1284 byte`):
 *      `write_minidump(const char* minidump_path, int target_pid, const void* crash_context, size_t context_size)`
 *      Sinh tệp minidump Google Breakpad `MDMP` (`0x504d444d`, phiên bản `0xa793`)
 *      hoàn chỉnh cho tiến trình đích gặp sự cố.
 */
bool write_minidump(
    const char* minidump_path,
    int target_pid,
    const void* crash_context,
    size_t context_size);

/**
 * [EN] C-ABI entry point mirroring `dumper_main(int argc, char** argv)` at `0x008108`.
 * [VN] Điểm nhập C-ABI phản ánh `dumper_main(int argc, char** argv)` tại `0x008108`.
 */
int npth_dumper_main_entry(
    int argc,
    const char* const* argv,
    const npth::dumper::CrashPipePayload* payload);

} // extern "C"

#endif // OPENCUT_NPTH_DUMPER_INTERFACE_H_
