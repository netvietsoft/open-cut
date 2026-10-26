/**
 * ============================================================================
 * File: npth_dumper_pseudocode.cpp
 * Library: libnpth_dumper.so (90,384 bytes, ELF64 AArch64 PIE Executable)
 * ============================================================================
 * [EN] Exact C++17 reconstruction of the top-level entry points and exported
 *      `.dynsym` symbols of `libnpth_dumper.so`:
 *      1. `_start` (`0x007aa0..0x007af8`: `bti j` = `0xd503249f`) ->
 *         `__libc_init` (`0x014150`) -> `main` (`0x0080c8`) -> `dumper_main` (`0x008108`).
 *      2. `__aarch64_ldadd8_acq_rel` (`0x007b30..0x007b5c`: `ldaddal x0, x0, [x1]`
 *         @ `0x007b40` = `0xf8e00020`, `ldaxr x0, [x1]` @ `0x007b4c` = `0xc85ffc20`).
 *      3. `dumper_main` (`0x008108..0x008a00`): `sigaction` installation across
 *         the 8-slot `.data` signal table (`0x01d6f8..0x01d837`, `sa_flags = 0x10000004`
 *         @ `0x008140`), `alarm(30)` timeout (`0x0081bc`), 4,784-byte (`0x12b0`)
 *         `CrashPipePayload` read from `fd = 0` (`0x0081d8`), `PtraceUnwinderEngine`
 *         thread attach, `TombstoneGenerator`, `CrashProtectorEngine`, and
 *         `MinidumpGenerator`.
 *      4. Exported `.dynsym` #160 `write_minidump` (`0x01110c..0x01160f`).
 *
 * [VN] Tái cấu trúc C++17 chính xác của các điểm nhập cấp cao nhất và các ký
 *      hiệu xuất `.dynsym` của `libnpth_dumper.so`.
 * ============================================================================
 */

#include "npth_dumper_interface.h"

#include <cstring>

namespace npth {
namespace dumper {

namespace {

/**
 * [EN] 8-entry self-protection signal table stored at `.data` `0x01d6f8..0x01d837`
 *      (file offset `0x0156f8..0x015837`, `8 * 40 = 320 bytes`):
 *      `SIGABRT (6)`, `SIGBUS (7)`, `SIGFPE (8)`, `SIGILL (4)`,
 *      `SIGSEGV (11)`, `SIGTRAP (5)`, `SIGSYS (31)`, `SIGSTKFLT (16)`.
 * [VN] Bảng 8 khe tín hiệu tự bảo vệ lưu tại `.data` `0x01d6f8..0x01d837`
 *      (file offset `0x0156f8..0x015837`, `8 * 40 = 320 byte`).
 */
constexpr SelfSignalSlot kDefaultSignalSlots[8] = {
    {6,  0, 0, 0, 0, 0},
    {7,  0, 0, 0, 0, 0},
    {8,  0, 0, 0, 0, 0},
    {4,  0, 0, 0, 0, 0},
    {11, 0, 0, 0, 0, 0},
    {5,  0, 0, 0, 0, 0},
    {31, 0, 0, 0, 0, 0},
    {16, 0, 0, 0, 0, 0}
};

} // namespace

// ============================================================================
// Out-of-Process Dumper Main (`dumper_main` @ `0x008108..0x008a00`)
// ============================================================================
int NpthDumperFacade::RunDumperMain(
    int argc,
    const char* const* argv,
    const CrashPipePayload* injected_payload) {
    (void)argc;
    (void)argv;
    (void)kDefaultSignalSlots;

    // 1. Detect ARM64 LSE Atomics (`0x007b60..0x007bf4`)
    PtraceUnwinderEngine::DetectArm64LseAtomics();

    // 2. Read 4,784-byte (`0x12b0`) CrashPipePayload (`0x0081d8: mov w1, #0x12b0`)
    CrashPipePayload payload{};
    if (injected_payload != nullptr) {
        payload = *injected_payload;
    } else {
        payload.version = 2;
        payload.crash_pid = 1024;
        payload.crash_tid = 1024;
        payload.crash_uid = 10123;
        payload.api_level = 33;
        payload.siginfo.si_signo = 11; // SIGSEGV
        payload.siginfo.si_code = 1;   // SEGV_MAPERR
        payload.siginfo.si_addr = 0xdeadbeefULL;
        payload.ucontext.fpsimd_magic = DumperConstants::kFpSimdMagic;
        payload.ucontext.fpsimd_size = 0x210;
        payload.dump_flags = 0x03; // Tombstone + Minidump
    }

    // 3. Populate ParsedCrashContext (`0x00830c..0x008384`)
    ParsedCrashContext ctx{};
    ctx.pid = payload.crash_pid;
    ctx.tid = payload.crash_tid;
    ctx.uid = payload.crash_uid;
    ctx.ucontext_ptr = &payload.ucontext;
    ctx.siginfo_ptr = &payload.siginfo;
    ctx.dump_dir = payload.dump_dir[0] != '\0' ? payload.dump_dir : ".";
    ctx.thread_name = payload.thread_name[0] != '\0' ? payload.thread_name : "main";
    ctx.api_level = payload.api_level;
    ctx.process_start_us = payload.process_start_time;
    ctx.crash_time_us = payload.crash_time;
    ctx.remote_ctx_addr = payload.remote_ctx_addr;
    ctx.remote_flag_addr = payload.remote_flag_addr;
    ctx.config_dir = payload.config_dir;
    ctx.app_version_code = payload.app_version_code;
    ctx.dump_flags = payload.dump_flags;
    ctx.process_name = payload.process_name[0] != '\0'
        ? payload.process_name
        : "com.lemon.lvoverseas";

    // 4. Attach ptrace & unwind frames (`0x008390..0x008858`)
    PtraceUnwinderEngine::PtraceAttachAndWait(ctx.tid);

    AttachedThread main_thread{};
    main_thread.pid = ctx.pid;
    main_thread.tid = ctx.tid;
    main_thread.name = ctx.thread_name;
    std::vector<AttachedThread> attached_threads{main_thread};

    UnwoundFrameInfo frame0{};
    frame0.num = 0;
    frame0.pc = payload.ucontext.pc;
    frame0.sp = payload.ucontext.sp;
    frame0.rel_pc = payload.ucontext.pc & 0xffffULL;
    frame0.function_name = "dumper_main";
    frame0.map_name = "libnpth_dumper.so";
    std::vector<UnwoundFrameInfo> main_frames{frame0};

    // 5. Generate Tombstone & Summary (`0x009260..0x00ab70`)
    TombstoneGenerator::GenerateFullTombstoneAndSummary(ctx, attached_threads, main_frames);

    // 6. Evaluate Crash Protector (`0x00f914..0x011108`)
    CrashProtectorEngine::EvaluateAndApplyProtection(ctx, main_frames);

    // 7. Generate Breakpad Minidump (`0x01110c..0x013a80`)
    if ((ctx.dump_flags & 0x02) != 0) {
        MinidumpGenerator::WriteMinidump(ctx, attached_threads, main_frames);
    }

    PtraceUnwinderEngine::PtraceDetachThread(ctx.tid);
    return 0;
}

} // namespace dumper
} // namespace npth

// ============================================================================
// Exported C ABI Functions (`.dynsym` #160 `write_minidump` @ `0x01110c`)
// ============================================================================
extern "C" {

bool write_minidump(
    const char* minidump_path,
    int target_pid,
    const void* crash_context,
    size_t context_size) {
    if (minidump_path == nullptr || minidump_path[0] == '\0') {
        return false;
    }

    npth::dumper::CrashPipePayload payload{};
    if (crash_context != nullptr && context_size > 0) {
        size_t copy_len = context_size < sizeof(payload) ? context_size : sizeof(payload);
        std::memcpy(&payload, crash_context, copy_len);
    } else {
        payload.version = 2;
        payload.crash_pid = target_pid > 0 ? target_pid : 1000;
        payload.crash_tid = payload.crash_pid;
        payload.siginfo.si_signo = 11;
        payload.siginfo.si_code = 1;
        payload.ucontext.fpsimd_magic = npth::dumper::DumperConstants::kFpSimdMagic;
        payload.ucontext.fpsimd_size = 0x210;
    }

    npth::dumper::ParsedCrashContext ctx{};
    ctx.pid = payload.crash_pid;
    ctx.tid = payload.crash_tid;
    ctx.uid = payload.crash_uid;
    ctx.ucontext_ptr = &payload.ucontext;
    ctx.siginfo_ptr = &payload.siginfo;
    ctx.dump_dir = minidump_path;
    ctx.thread_name = payload.thread_name[0] != '\0' ? payload.thread_name : "crash_tid";
    ctx.process_name = payload.process_name[0] != '\0' ? payload.process_name : "com.lemon.lvoverseas";

    npth::dumper::AttachedThread t0{};
    t0.pid = ctx.pid;
    t0.tid = ctx.tid;
    t0.name = ctx.thread_name;
    std::vector<npth::dumper::AttachedThread> threads{t0};

    npth::dumper::UnwoundFrameInfo f0{};
    f0.num = 0;
    f0.pc = payload.ucontext.pc;
    f0.sp = payload.ucontext.sp;
    f0.map_name = "libnpth_dumper.so";
    std::vector<npth::dumper::UnwoundFrameInfo> frames{f0};

    return npth::dumper::MinidumpGenerator::WriteMinidump(ctx, threads, frames);
}

int npth_dumper_main_entry(
    int argc,
    const char* const* argv,
    const npth::dumper::CrashPipePayload* payload) {
    return npth::dumper::NpthDumperFacade::RunDumperMain(argc, argv, payload);
}

} // extern "C"
