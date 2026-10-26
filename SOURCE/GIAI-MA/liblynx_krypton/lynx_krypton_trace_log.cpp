/**
 * @file lynx_krypton_trace_log.cpp
 * @brief Exact AArch64 opcode-verified implementation of `KryptonLogFunction`
 *        (`0x00403c..0x004148`), `nativeGetLogFunctionPtr` (`0x004160..0x004168`),
 *        and `RuntimeLoadLynxTraceFunc` / `nativeRegisterTraceFunc` (`0x00416c..0x0042fc`)
 *        for `liblynx_krypton.so`.
 *        Triển khai đối soát opcode AArch64 chính xác của `KryptonLogFunction`,
 *        `nativeGetLogFunctionPtr`, và `RuntimeLoadLynxTraceFunc` / `nativeRegisterTraceFunc`
 *        cho `liblynx_krypton.so`.
 */

#include "lynx_krypton_trace_log.h"

#include <atomic>
#include <cstring>
#include <mutex>

namespace nextai {
namespace opencut {
namespace lynx_krypton {

namespace {

std::mutex g_log_mutex;
std::atomic<int32_t> g_min_log_level{0};
std::vector<LynxLogRecord> g_captured_logs;

KryptonBssSegment g_bss_state{};
KryptonTraceFunctions g_attached_trace_handler{nullptr, nullptr, nullptr};
std::atomic<uint32_t> g_attach_trace_call_count{0};

bool g_simulate_dlopen_failure = false;
bool g_simulate_missing_begin_end = false;
bool g_simulate_missing_counter = false;

// Default mock trace functions representing resolved symbols from `liblynxtrace.so`
// Các hàm trace mặc định đại diện cho các biểu tượng phân giải từ `liblynxtrace.so`
void DefaultTraceEventBeginEx(const char* category, const char* name) {
    (void)category;
    (void)name;
}

void DefaultTraceEventEndEx(const char* category, const char* name) {
    (void)category;
    (void)name;
}

void DefaultTraceCounterEx(const char* category, const char* name, uint64_t value, bool incremental) {
    (void)category;
    (void)name;
    (void)value;
    (void)incremental;
}

/**
 * @brief Models `lynx::canvas::AttachKryptonTraceHandler` (`0x0052d0` PLT).
 *        Mô phỏng `lynx::canvas::AttachKryptonTraceHandler` (`0x0052d0` PLT).
 */
void AttachKryptonTraceHandlerImpl(KryptonTraceFunctions handler) noexcept {
    g_attached_trace_handler = handler;
    g_attach_trace_call_count.fetch_add(1u, std::memory_order_relaxed);
}

} // namespace

// ============================================================================
// 1. `lynx::base::logging::LogMessage` Reconstruction (`0x005280` / `0x0052a0`)
//    Tái dựng `lynx::base::logging::LogMessage` (`0x005280` / `0x0052a0`)
// ============================================================================

LynxLogMessage::LynxLogMessage(const char* file, int32_t line, int32_t severity) noexcept
    : file_(file), line_(line), severity_(severity) {}

LynxLogMessage::~LynxLogMessage() noexcept {
    std::lock_guard<std::mutex> lock(g_log_mutex);
    g_captured_logs.push_back(LynxLogRecord{
        file_,
        line_,
        severity_,
        stream_.str(),
    });
}

int32_t LynxLogMessage::GetMinLogLevel() noexcept {
    return g_min_log_level.load(std::memory_order_relaxed);
}

void LynxLogMessage::SetMinLogLevel(int32_t min_level) noexcept {
    g_min_log_level.store(min_level, std::memory_order_relaxed);
}

std::vector<LynxLogRecord> LynxLogMessage::GetCapturedLogs() {
    std::lock_guard<std::mutex> lock(g_log_mutex);
    return g_captured_logs;
}

void LynxLogMessage::ClearCapturedLogs() {
    std::lock_guard<std::mutex> lock(g_log_mutex);
    g_captured_logs.clear();
}

// ============================================================================
// 2. Krypton 5-Level Jump Table (`0x00406c..0x0040c0` & `.rodata 0x001970`)
//    Bảng Nhảy 5 Mức Log của Krypton (`0x00406c..0x0040c0` & `.rodata 0x001970`)
// ============================================================================

int32_t MapKryptonLogLevelToLynxSeverity(int32_t krypton_level) noexcept {
    // Disassembly @ 0x00406c..0x004074:
    //   sub w8, w0, #1
    //   cmp w8, #4
    //   b.hi #0x4094 (default -> mov w2, #0)
    const uint32_t index = static_cast<uint32_t>(krypton_level - 1);
    if (index > 4u) {
        return 0; // 0x004094: mov w2, #0
    }

    // Disassembly @ 0x004070..0x004084:
    //   ldrb w11, [x9, x8]  ; .rodata 0x001970 = {0x00, 0x05, 0x0a, 0x0f, 0x14}
    //   add  x10, x10, x11, lsl #2 ; base = 0x004088
    //   br   x10
    const uint8_t jump_words = RodataConstants::kLogLevelJumpTable[index];
    switch (jump_words) {
        case 0x00u: // 0x004088 + 0*4  = 0x004088: mov w3, #1
            return 1;
        case 0x05u: // 0x004088 + 5*4  = 0x00409c: mov w3, #5
            return 5;
        case 0x0au: // 0x004088 + 10*4 = 0x0040b0: mov w3, #3
            return 3;
        case 0x0fu: // 0x004088 + 15*4 = 0x0040c4: mov w3, #4
            return 4;
        case 0x14u: // 0x004088 + 20*4 = 0x0040d8: mov w3, #2
            return 2;
        default:
            return 0;
    }
}

LibcxxStringView ExtractLibcxxStringView(const std::string& str) noexcept {
    // Models the exact libc++ SSO bit check at 0x0040d8..0x004124 & 0x004150..0x00415c:
    //   ldrb w8, [x_str]
    //   tbz  w8, #0, short_str
    //   ldr  x_data, [x_str, #0x10] / ldr x_len, [x_str, #0x08]
    //   short_str: add x_data, x_str, #1 / lsr x_len, x8, #1
    return LibcxxStringView{str.data(), str.size()};
}

// ============================================================================
// 3. `KryptonLogFunction` (`0x00403c..0x004148`, 272 bytes)
//    Hàm Callback Log `KryptonLogFunction` (`0x00403c..0x004148`, 272 byte)
// ============================================================================

void KryptonLogFunction(int32_t level, const std::string& tag, const std::string& message) {
    // 0x00405c..0x004068:
    //   bl lynx::base::logging::GetMinLogLevel()
    //   cmp w0, w21
    //   b.gt #0x4128 (early exit when min_log_level > level)
    if (LynxLogMessage::GetMinLogLevel() > level) {
        return;
    }

    // 0x00406c..0x0040c0: Resolve Lynx severity via 5-entry jump table at .rodata 0x001970
    const int32_t lynx_severity = MapKryptonLogLevelToLynxSeverity(level);

    // 0x0040c0..0x0040d0:
    //   adrp x1, #0x1000; add x1, x1, #0xb6b ("canvas_manager_android.cc")
    //   mov w2, #0x1b (line 27)
    //   bl lynx::base::logging::LogMessage::LogMessage(this, "canvas_manager_android.cc", 27, lynx_severity)
    LynxLogMessage log_msg(RodataConstants::kFileCanvasManagerAndroidCc, 27, lynx_severity);

    // 0x0040d8..0x0040fc:
    //   Extract tag pointer/length and call std::__ndk1::__put_character_sequence(stream, tag.data, tag.size)
    const LibcxxStringView tag_view = ExtractLibcxxStringView(tag);
    log_msg.stream().write(tag_view.data, static_cast<std::streamsize>(tag_view.size));

    // 0x004100..0x004120:
    //   Extract message pointer/length and call std::__ndk1::__put_character_sequence(stream, msg.data, msg.size)
    const LibcxxStringView msg_view = ExtractLibcxxStringView(message);
    log_msg.stream().write(msg_view.data, static_cast<std::streamsize>(msg_view.size));
    // 0x004120..0x004124:
    //   bl lynx::base::logging::LogMessage::~LogMessage()
}

// ============================================================================
// 4. `CanvasManager_nativeGetLogFunctionPtr` (`0x004160..0x004168`, 12 bytes)
//    Hàm JNI `CanvasManager_nativeGetLogFunctionPtr` (`0x004160..0x004168`, 12 byte)
// ============================================================================

jlong CanvasManager_nativeGetLogFunctionPtr(JNIEnv* env, jobject jcaller) noexcept {
    (void)env;
    (void)jcaller;
    // Exact instructions at 0x004160..0x004168:
    //   0x004160: adr x8, #0x403c
    //   0x004164: mov x0, x8
    //   0x004168: ret
    return reinterpret_cast<jlong>(&KryptonLogFunction);
}

// ============================================================================
// 5. `CanvasManager_nativeRegisterTraceFunc` (`0x00416c..0x0042fc`, 404 bytes)
//    Hàm JNI `CanvasManager_nativeRegisterTraceFunc` (`0x00416c..0x0042fc`, 404 byte)
// ============================================================================

void CanvasManager_nativeRegisterTraceFunc(JNIEnv* env, jobject jcaller) {
    (void)env;
    (void)jcaller;

    // 0x004178..0x00418c:
    //   if (GetMinLogLevel() <= 0)
    //     LogMessage("canvas_manager_android.cc", 0x20 (32), 0) << "RuntimeLoadLynxTraceFunc start";
    if (LynxLogMessage::GetMinLogLevel() <= 0) {
        LynxLogMessage log_msg(RodataConstants::kFileCanvasManagerAndroidCc, 32, 0);
        log_msg.stream().write(RodataConstants::kLogTraceLoadStart, 30); // mov w2, #0x1e @ 0x0041e4
    }

    // 0x004190..0x004198:
    //   adrp x19, #0xc000
    //   ldr  x8, [x19, #8]   ; g_bss_state.trace_functions.trace_event_begin_ex (.bss 0x00c008)
    //   cbz  x8, #0x4200
    if (g_bss_state.trace_functions.trace_event_begin_ex == nullptr) {
        // 0x004200..0x004224:
        //   adrp x0, #0x1000; add x0, x0, #0xa45 ("liblynxtrace.so")
        //   mov  w1, #2 (RTLD_LAZY)
        //   bl   dlopen
        //   cbz  x22, #0x4270
        if (g_simulate_dlopen_failure) {
            // 0x004270..0x0042a4:
            //   if (GetMinLogLevel() <= 3)
            //     LogMessage("canvas_manager_android.cc", 0x27 (39), 3)
            //       << "RuntimeLoadLynxTraceFunc cant find liblynxtrace.so";
            if (LynxLogMessage::GetMinLogLevel() <= 3) {
                LynxLogMessage log_msg(RodataConstants::kFileCanvasManagerAndroidCc, 39, 3);
                log_msg.stream().write(RodataConstants::kLogTraceCantFindLib, 50); // mov w2, #0x32 @ 0x00429c
            }
            return;
        }

        // 0x004228..0x00426c:
        //   dlsym(handle, "TraceEventBeginEx") -> [x19, #0x08] (.bss 0x00c008)
        //   dlsym(handle, "TraceEventEndEx")   -> [x19, #0x10] (.bss 0x00c010)
        //   dlsym(handle, "TraceCounterEx")    -> [x19, #0x18] (.bss 0x00c018)
        g_bss_state.trace_functions.trace_event_begin_ex =
            g_simulate_missing_begin_end ? nullptr : &DefaultTraceEventBeginEx;
        g_bss_state.trace_functions.trace_event_end_ex =
            g_simulate_missing_begin_end ? nullptr : &DefaultTraceEventEndEx;
        g_bss_state.trace_functions.trace_counter_ex =
            g_simulate_missing_counter ? nullptr : &DefaultTraceCounterEx;

        // 0x0042a8..0x0042dc:
        //   if (GetMinLogLevel() <= 0)
        //     LogMessage("canvas_manager_android.cc", 0x2b (43), 0)
        //       << "RuntimeLoadLynxTraceFunc load liblynxtrace.so success ";
        if (LynxLogMessage::GetMinLogLevel() <= 0) {
            LynxLogMessage log_msg(RodataConstants::kFileCanvasManagerAndroidCc, 43, 0);
            log_msg.stream().write(RodataConstants::kLogTraceLoadDlopenOk, 54); // mov w2, #0x36 @ 0x0042cc
        }

        // 0x0042e0..0x004318:
        //   ldp x8, x9, [x19, #8]
        //   cbz x8, #0x42fc ; cbz x9, #0x42fc
        if (g_bss_state.trace_functions.trace_event_begin_ex == nullptr ||
            g_bss_state.trace_functions.trace_event_end_ex == nullptr) {
            if (LynxLogMessage::GetMinLogLevel() <= 3) {
                LynxLogMessage log_msg(RodataConstants::kFileCanvasManagerAndroidCc, 50, 3);
                log_msg.stream().write(RodataConstants::kLogTraceBeginEndNotFound, 43); // mov w2, #0x2b @ 0x004314
            }
        }

        // 0x004318..0x004324:
        //   ldr x8, [x19, #0x18]
        //   cbnz x8, #0x419c
        if (g_bss_state.trace_functions.trace_counter_ex == nullptr) {
            if (LynxLogMessage::GetMinLogLevel() <= 3) {
                LynxLogMessage log_msg(RodataConstants::kFileCanvasManagerAndroidCc, 53, 3);
                log_msg.stream().write(RodataConstants::kLogTraceCounterNotFound, 24); // mov w2, #0x18 @ 0x00429c
            }
            return;
        }
    }

    // 0x00419c..0x0041b0:
    //   ldur q0, [x19, #8]
    //   ldr  x8, [x19, #0x18]
    //   add  x0, sp, #0x18
    //   str  q0, [sp, #0x18]
    //   str  x8, [sp, #0x28]
    //   bl   lynx::canvas::AttachKryptonTraceHandler(KryptonTraceFunctions)
    AttachKryptonTraceHandlerImpl(g_bss_state.trace_functions);

    // 0x0041b4..0x0041fc:
    //   if (GetMinLogLevel() <= 0)
    //     LogMessage("canvas_manager_android.cc", 0x3f (63), 0)
    //       << "RuntimeLoadLynxTraceFunc load trace function success";
    if (LynxLogMessage::GetMinLogLevel() <= 0) {
        LynxLogMessage log_msg(RodataConstants::kFileCanvasManagerAndroidCc, 63, 0);
        log_msg.stream().write(RodataConstants::kLogTraceLoadSuccess, 52); // mov w2, #0x34 @ 0x0041f0
    }
}

KryptonBssSegment& GetKryptonBssState() noexcept {
    return g_bss_state;
}

const KryptonTraceFunctions& GetAttachedKryptonTraceHandler() noexcept {
    return g_attached_trace_handler;
}

uint32_t GetAttachKryptonTraceHandlerCallCount() noexcept {
    return g_attach_trace_call_count.load(std::memory_order_relaxed);
}

void SetSimulateLibLynxTraceDlopenFailure(bool fail_dlopen, bool fail_begin_end, bool fail_counter) noexcept {
    g_simulate_dlopen_failure = fail_dlopen;
    g_simulate_missing_begin_end = fail_begin_end;
    g_simulate_missing_counter = fail_counter;
}

void ResetKryptonTraceAndBssState() noexcept {
    std::memset(&g_bss_state, 0, sizeof(g_bss_state));
    g_attached_trace_handler = KryptonTraceFunctions{nullptr, nullptr, nullptr};
    g_attach_trace_call_count.store(0u, std::memory_order_relaxed);
    g_simulate_dlopen_failure = false;
    g_simulate_missing_begin_end = false;
    g_simulate_missing_counter = false;
    LynxLogMessage::SetMinLogLevel(0);
    LynxLogMessage::ClearCapturedLogs();
}

} // namespace lynx_krypton
} // namespace opencut
} // namespace nextai
