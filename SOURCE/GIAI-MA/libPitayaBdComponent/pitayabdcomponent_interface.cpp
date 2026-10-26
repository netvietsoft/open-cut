/**
 * @file pitayabdcomponent_interface.cpp
 * @brief Master C++17 Implementation & 7-Stage Verification Suite for libPitayaBdComponent.so (Target 46).
 *        Triển khai C++17 tổng thể & Bộ kiểm thử xác minh 7 giai đoạn cho libPitayaBdComponent.so (Mục tiêu 46).
 *
 * Binary Ground Truth / Thực tế Nhị phân:
 * - Binary: extracted/lib/arm64-v8a/libPitayaBdComponent.so (100,176 bytes, ELF64 AArch64)
 * - Exported Functions:
 *   1. Java_com_bytedance_pitaya_bdcomponentimpl_crash_NpthStackReporter_nativeGenerateAllStack (@ 0x002780, 132 B)
 *   2. pitaya::PitayaNpthUtil::GenerteTombstone(std::string)                                   (@ 0x002898, 488 B)
 *   3. Java_com_bytedance_pitaya_bdcomponentimpl_monitor_ALogPrinter_nativeGetFuncAddr          (@ 0x004c54, 340 B)
 */

#include "PitayaBdComponent_interface.h"

#include <sstream>
#include <vector>

namespace NextAI {
namespace OpenCut {
namespace PitayaBdComponent {

bool PitayaBdComponentEngine::RunSelfTest(std::string* out_report) {
    using namespace pitaya;
    using namespace pitaya::bdcomponent;

    std::ostringstream report;
    bool all_ok = true;

    // Stage 1: Verify 64-bit Multiplicative Inverse Division Math (0xaaaaaaaaaaaaaaabULL)
    // Giai đoạn 1: Xác minh toán học chia bằng nghịch đảo nhân 64-bit (0xaaaaaaaaaaaaaaabULL)
    //   - Div by 24 (sizeof(sub_match)): (byte_diff >> 3) * 0xaaaaaaaaaaaaaaabULL (@ 0x002e54..0x002e68)
    //   - Div by 96 (sizeof(ThreadStackInfo)): (byte_diff >> 5) * 0xaaaaaaaaaaaaaaabULL (@ 0x0048e0..0x00490c)
    for (uint64_t n = 0; n <= 64; ++n) {
        if (RegexStreamEngine::ComputeSubMatchCountDiv24(n * 24ULL) != n) {
            all_ok = false;
        }
        if (RegexStreamEngine::ComputeThreadInfoCountDiv96(n * 96ULL) != n) {
            all_ok = false;
        }
    }
    report << "[Stage 1] Multiplicative inverse division (24B sub_match & 96B ThreadStackInfo): "
           << (all_ok ? "PASS" : "FAIL") << "\n";

    // Stage 2: Verify ExtractSoPathFromFrame (@ 0x004568..0x0047d8) 4-space state machine
    // Giai đoạn 2: Xác minh máy trạng thái 4 khoảng trắng ExtractSoPathFromFrame (@ 0x004568..0x0047d8)
    const std::string frame1 =
        "  #00 pc 0000000000002898  /data/app/com.nextai.opencut/lib/arm64/libPitayaBdComponent.so (GenerteTombstone+120)  ";
    const std::string so1 = PitayaNpthUtil::ExtractSoPathFromFrame(frame1);
    const std::string frame2 =
        "  #01 pc 000000000002d2c8  /data/app/com.nextai.opencut/lib/arm64/libCepEngine.so";
    const std::string so2 = PitayaNpthUtil::ExtractSoPathFromFrame(frame2);
    if (so1 != "/data/app/com.nextai.opencut/lib/arm64/libPitayaBdComponent.so" ||
        so2 != "/data/app/com.nextai.opencut/lib/arm64/libCepEngine.so") {
        all_ok = false;
    }
    report << "[Stage 2] ExtractSoPathFromFrame 4-space state machine: "
           << (all_ok ? "PASS" : "FAIL") << "\n";

    // Stage 3: Verify NdkStringBuf seekoff/xsgetn/overflow (@ 0x005044..0x005dc0)
    // Giai đoạn 3: Xác minh NdkStringBuf seekoff/xsgetn/overflow (@ 0x005044..0x005dc0)
    NdkStringBuf sbuf("Line1\nLine2\nLine3", std::ios_base::in | std::ios_base::out);
    if (sbuf.SeekOff(0, std::ios_base::cur, std::ios_base::in | std::ios_base::out) != -1) {
        all_ok = false;  // Must fail on cur + (in|out) (@ 0x005064..0x005074)
    }
    if (sbuf.SeekOff(6, std::ios_base::beg, std::ios_base::in) != 6) {
        all_ok = false;
    }
    char read_buf[5] = {0};
    if (sbuf.Xsgetn(read_buf, 5) != 5 || std::string(read_buf, 5) != "Line2") {
        all_ok = false;
    }
    report << "[Stage 3] NdkStringBuf seekoff/xsgetn parity: "
           << (all_ok ? "PASS" : "FAIL") << "\n";

    // Stage 4: Verify ParseOriginStack (@ 0x002a80) & "pty-ord-t" priority front-insertion (@ 0x003258..0x003338)
    // Giai đoạn 4: Xác minh ParseOriginStack (@ 0x002a80) & chèn ưu tiên đầu danh sách cho "pty-ord-t"
    auto& util = PitayaNpthUtil::Instance();
    std::vector<ThreadStackInfo> parsed_threads;
    const std::string sample_dump =
        "----- pid 31337 at 2026-10-26 18:45:00 -----\n"
        "Cmd line: com.nextai.opencut\n"
        "\n"
        "\"main\" sysTid=31337\n"
        "  #00 pc 0000000000089a1c  /apex/com.android.runtime/lib64/bionic/libc.so (syscall+28)\n"
        "\n"
        "\"RenderThread\" sysTid=31350\n"
        "  #00 pc 0000000000050120  /system/lib64/libhwui.so\n"
        "\n"
        "\"pty-ord-t-0\" sysTid=31401\n"
        "  #00 pc 0000000000002898  /data/app/com.nextai.opencut/lib/arm64/libPitayaBdComponent.so (GenerteTombstone+120)\n"
        "  #01 pc 000000000002d2c8  /data/app/com.nextai.opencut/lib/arm64/libCepEngine.so (cep::Nfa::Process+312)\n"
        "\n";
    util->ParseOriginStack(sample_dump, &parsed_threads);
    if (util->pid() != "31337" ||
        util->process_name() != "com.nextai.opencut" ||
        parsed_threads.size() != 3 ||
        parsed_threads[0].thread_name != "pty-ord-t-0" ||
        parsed_threads[0].tid != "31401" ||
        parsed_threads[0].so_paths.count("/data/app/com.nextai.opencut/lib/arm64/libPitayaBdComponent.so") == 0) {
        all_ok = false;
    }
    report << "[Stage 4] ParseOriginStack & pty-ord-t front priority: "
           << (all_ok ? "PASS" : "FAIL") << "\n";

    // Stage 5: Verify Tombstone Formatting & BuildId Resolution (@ 0x004098..0x00447c)
    // Giai đoạn 5: Xác minh định dạng Tombstone & giải mã BuildId (@ 0x004098..0x00447c)
    const std::string formatted = util->FormatThreadTombstoneString(parsed_threads[0]);
    if (formatted.find("pid: 31337, tid: 31401, name: pty-ord-t-0  >>> com.nextai.opencut <<<\n") == std::string::npos ||
        formatted.find("backtrace:\n") == std::string::npos ||
        formatted.find("build id:\n") == std::string::npos ||
        formatted.find("(BuildId: f0e1d2c3b4a5968778695a4b3c2d1e0f)\n") == std::string::npos ||
        formatted.find(RodataStrings::kSectionSeparator) == std::string::npos) {
        all_ok = false;
    }
    report << "[Stage 5] WriteThreadTombstone & WriteBuildIds formatting: "
           << (all_ok ? "PASS" : "FAIL") << "\n";

    // Stage 6: Verify ALogPrinter_nativeGetFuncAddr (@ 0x004c54) Primary & Fallback Modes
    // Giai đoạn 6: Xác minh ALogPrinter_nativeGetFuncAddr (@ 0x004c54) ở cả chế độ chính và dự phòng
    ALogDynamicBridge::ClearDiagnosticLogs();
    ALogDynamicBridge::SetSimulationMode(ALogLoaderSimMode::kPrimaryDlopenSuccess);
    const jlong addr_primary =
        Java_com_bytedance_pitaya_bdcomponentimpl_monitor_ALogPrinter_nativeGetFuncAddr(nullptr, nullptr);

    ALogDynamicBridge::SetSimulationMode(ALogLoaderSimMode::kFallbackNpthSuccess);
    const jlong addr_fallback =
        Java_com_bytedance_pitaya_bdcomponentimpl_monitor_ALogPrinter_nativeGetFuncAddr(nullptr, nullptr);

    ALogDynamicBridge::SetSimulationMode(ALogLoaderSimMode::kFallbackNpthDlopenFail);
    const jlong addr_fail =
        Java_com_bytedance_pitaya_bdcomponentimpl_monitor_ALogPrinter_nativeGetFuncAddr(nullptr, nullptr);

    if (addr_primary == 0 || addr_fallback == 0 || addr_primary != addr_fallback || addr_fail != 0) {
        all_ok = false;
    }
    report << "[Stage 6] ALogPrinter_nativeGetFuncAddr dlopen/npth_dlopen two-tier fallback: "
           << (all_ok ? "PASS" : "FAIL") << "\n";

    // Stage 7: Verify NpthStackReporter_nativeGenerateAllStack (@ 0x002780) End-to-End
    // Giai đoạn 7: Xác minh NpthStackReporter_nativeGenerateAllStack (@ 0x002780) đầu-cuối
    PitayaNpthUtil::SetMockOriginStackDump(sample_dump);
    Java_com_bytedance_pitaya_bdcomponentimpl_crash_NpthStackReporter_nativeGenerateAllStack(
        nullptr, nullptr, reinterpret_cast<jstring>(const_cast<char*>(".")));
    if (PitayaNpthUtil::GetLastGeneratedTombstoneContent().find("pty-ord-t-0") == std::string::npos) {
        all_ok = false;
    }
    report << "[Stage 7] NpthStackReporter_nativeGenerateAllStack end-to-end: "
           << (all_ok ? "PASS" : "FAIL") << "\n";

    if (out_report != nullptr) {
        *out_report = report.str();
    }
    return all_ok;
}

}  // namespace PitayaBdComponent
}  // namespace OpenCut
}  // namespace NextAI
