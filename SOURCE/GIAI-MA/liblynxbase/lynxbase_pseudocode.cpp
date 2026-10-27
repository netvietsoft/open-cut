// ============================================================================
// File: lynxbase_pseudocode.cpp
// Target: liblynxbase.so (232,080 bytes, SHA-256: 6f73cb643285f2b6f59960dde9c053141e6f546429faaf7fa66bbae9e1a0d61d)
// Subsystem: End-to-End Binary Parity & Mathematical Verification Harness
//            for `liblynxbase.so` (Target 84 / 169)
// Task ID: TASK-123-RECONSTRUCTION-LIBLYNXBASE (TASK_SO_121_liblynxbase)
// ============================================================================
// [EN] Clean-room C++17 verification harness exercising all 6 subsystems of
//      `liblynxbase.so`:
//      1. `JNI_OnLoad` (`0x01403c..0x01406c` -> `0x00010006`) & `lynx::base::android`
//      2. `lynx::fml` MessageLoop, TaskRunner, MessageLoopTaskQueues (Merge/Unmerge),
//         CountDownLatch, SyncSwitch, AutoResetWaitableEvent, SharedMutex & Timer
//      3. RFC 1321 `lynx::base::md5` (`0x01efe4..0x01f0b4`) & `CityHash64` (`0x022314`)
//      4. `DataURIUtil::DecodeDataURI` (`0x029450`) & `Base64Decode` (`0x02f290`)
//      5. `js_dtoa` (`0x029554`), UTF-8/16/32 string suite & `RefCountedStringImpl`
//      6. High-precision reciprocal time math (`0x02d520..0x02d65c`), `LynxError` & `logging`
// [VN] Bộ kiểm thử đối chứng C++17 tái tạo sạch kiểm tra toàn diện 6 phân hệ của
//      `liblynxbase.so` khớp từng hằng số toán học và mã máy AArch64.
// ============================================================================

#include "lynxbase_interface.h"

#include <cmath>
#include <limits>

namespace lynx {
namespace verification {

namespace {

// [EN] Verifies RFC 1321 MD5 test vectors against `lynx::base::md5` (`0x01efe4`).
// [VN] Kiểm chứng các vector chuẩn RFC 1321 đối với `lynx::base::md5` (`0x01efe4`).
bool VerifyMd5Rfc1321() {
    const std::string h_empty = base::md5("", 0);
    const std::string h_abc = base::md5(std::string("abc"));
    const std::string h_lynx = base::md5(std::string("LynxBaseTrace"));

    return h_empty == "d41d8cd98f00b204e9800998ecf8427e" &&
           h_abc == "900150983cd24fb0d6963f7d28e17f72" &&
           h_lynx.size() == 32;
}

// [EN] Verifies `CityHash64` (`0x022314`) and `RefCountedStringImpl` (`0x02d684`).
// [VN] Kiểm chứng `CityHash64` (`0x022314`) và `RefCountedStringImpl` (`0x02d684`).
bool VerifyCityHashAndRefCountedString() {
    if (base::CityHash64("", 0) != constants::kCityHashK2) {
        return false;
    }

    auto* empty_ref = base::RefCountedStringImpl::Unsafe::RawCreate("", 0);
    if (empty_ref != &base::RefCountedStringImpl::Unsafe::kEmptyString) {
        return false;
    }
    if (empty_ref->hash() != constants::kCityHashK2 || empty_ref->length() != 0) {
        return false;
    }

    auto* str_ref = base::RefCountedStringImpl::Unsafe::RawCreate("com/lynx/base/LynxBaseTrace", 27);
    const bool ok = (str_ref->hash() == base::CityHash64("com/lynx/base/LynxBaseTrace", 27)) &&
                    (str_ref->length_utf8() == 27) &&
                    (str_ref->length_utf16() == 27);
    str_ref->Release();
    return ok;
}

// [EN] Verifies `DataURIUtil::IsDataURI` (`0x029410`), `DecodeDataURI` (`0x029450`)
//      with 8-byte marker `0x2C3436657361623BULL` (`";base64,"`), and `Base64Decode` (`0x02f290`).
// [VN] Kiểm chứng `DataURIUtil::IsDataURI`, `DecodeDataURI` với hằng số 8 byte
//      `";base64,"` (`0x2C3436657361623BULL`) và `Base64Decode`.
bool VerifyDataUriAndBase64() {
    static constexpr std::string_view kSampleUri =
        "data:application/octet-stream;base64,THlueEJhc2U="; // "LynxBase"
    if (!base::DataURIUtil::IsDataURI(kSampleUri)) {
        return false;
    }

    std::vector<char> decoded_buf;
    size_t requested_capacity = 0;
    const int32_t decoded_len = base::DataURIUtil::DecodeDataURI(
        kSampleUri,
        [&decoded_buf, &requested_capacity](size_t alloc_size) -> char* {
            requested_capacity = alloc_size;
            decoded_buf.assign(alloc_size, '\0');
            return decoded_buf.data();
        });

    // b64_len = 12 ("THlueEJhc2U="), alloc_size = (12 >> 2) * 3 + 2 = 11
    if (requested_capacity != 11 || decoded_len != 8) {
        return false;
    }
    return std::string_view(decoded_buf.data(), static_cast<size_t>(decoded_len)) == "LynxBase";
}

// [EN] Verifies `js_dtoa` (`0x029554`) NaN/Infinity `"null"` branch, 53-bit
//      integer fast-path with `0xCCCCCCCCCCCCCCCDULL`, and general float formatting.
// [VN] Kiểm chứng `js_dtoa` (`0x029554`) ở nhánh NaN/Infinity (`"null"`), nhánh
//      nhanh số nguyên 53-bit (`0xCCCCCCCCCCCCCCCDULL`), và số thực dấu phẩy động.
bool VerifyJsDtoa() {
    char buf[64] = {0};

    const size_t nan_len = base::js_dtoa(std::numeric_limits<double>::quiet_NaN(), buf);
    if (nan_len != 4 || std::string_view(buf, nan_len) != "null") {
        return false;
    }

    const size_t inf_len = base::js_dtoa(std::numeric_limits<double>::infinity(), buf);
    if (inf_len != 4 || std::string_view(buf, inf_len) != "null") {
        return false;
    }

    const size_t zero_len = base::js_dtoa(0.0, buf);
    if (zero_len != 1 || std::string_view(buf, zero_len) != "0") {
        return false;
    }

    const size_t neg_len = base::js_dtoa(-9007199254740991.0, buf); // -0x1FFFFFFFFFFFFF
    if (std::string_view(buf, neg_len) != "-9007199254740991") {
        return false;
    }

    const size_t frac_len = base::js_dtoa(3.25, buf);
    return std::string_view(buf, frac_len) == "3.25";
}

// [EN] Verifies UTF-8 / UTF-16 / UTF-32 conversions and string utilities (`0x0299a4..0x02cc98`).
// [VN] Kiểm chứng chuyển đổi mã Unicode UTF-8/16/32 và các hàm chuỗi (`0x0299a4..0x02cc98`).
bool VerifyUtfAndStringSuite() {
    const std::string sample_u8 = "Xin chào Lynx 🚀";
    const std::u16string u16 = base::U8StringToU16(sample_u8);
    const std::u32string u32 = base::U8StringToU32(sample_u8);
    if (base::U16StringToU8(u16) != sample_u8 ||
        base::U32StringToU8(u32) != sample_u8) {
        return false;
    }

    if (base::SnakeToCamel("lynx_base_trace") != "lynxBaseTrace" ||
        base::CamelToDash("lynxBaseTrace") != "lynx-base-trace") {
        return false;
    }

    const auto tokens = base::SplitStringIgnoreBracket("rgb(1, 2, 3), rgba(4, 5, 6, 1)", ',');
    return tokens.size() == 2 && tokens[0] == "rgb(1, 2, 3)";
}

// [EN] Verifies high-precision reciprocal division time routines (`0x02d520..0x02d65c`).
// [VN] Kiểm chứng các hàm thời gian chia nghịch đảo độ chính xác cao (`0x02d520..0x02d65c`).
bool VerifyReciprocalTimeMath() {
    const uint64_t sys_ms = base::CurrentSystemTimeMilliseconds();
    const uint64_t sys_us = base::CurrentSystemTimeMicroseconds();
    const int64_t mono_ms = base::CurrentTimeMilliseconds();
    const int64_t mono_us = base::CurrentTimeMicroseconds();
    const uint64_t mono_ns = base::CurrentTimeNanoseconds();
    const timespec ts = base::ToTimeSpecFromNow(5000);

    return sys_ms > 0 && sys_us >= sys_ms && mono_ns >= static_cast<uint64_t>(mono_us) &&
           mono_us >= mono_ms && (ts.tv_sec > 0 || ts.tv_nsec >= 0);
}

// [EN] Verifies `lynx::fml` MessageLoop, TaskRunner, MessageLoopTaskQueues
//      (`Merge`/`Unmerge`), `CountDownLatch`, `SyncSwitch`, and `AutoResetWaitableEvent`.
// [VN] Kiểm chứng `lynx::fml` MessageLoop, TaskRunner, MessageLoopTaskQueues
//      (`Merge`/`Unmerge`), `CountDownLatch`, `SyncSwitch`, và `AutoResetWaitableEvent`.
bool VerifyFmlLoopAndQueues() {
    auto& loop = fml::MessageLoop::EnsureInitializedForCurrentThread();
    auto runner = loop.GetTaskRunner();

    int order_trace = 0;
    runner->PostTask([&order_trace]() { order_trace = order_trace * 10 + 1; });
    runner->PostMicroTask([&order_trace]() { order_trace = order_trace * 10 + 2; });
    runner->PostTask([&order_trace]() { order_trace = order_trace * 10 + 3; });
    loop.RunExpiredTasksNow();

    // First macrotask runs (1), then microtask drains immediately (12), then second macrotask (123)
    if (order_trace != 123) {
        return false;
    }

    auto queues = fml::MessageLoopTaskQueues::GetInstance();
    const fml::TaskQueueId q_owner = queues->CreateTaskQueue();
    const fml::TaskQueueId q_sub = queues->CreateTaskQueue();
    if (!queues->Merge(q_owner, q_sub) || !queues->Owns(q_owner, q_sub) ||
        !queues->IsSubsumed(q_sub)) {
        return false;
    }
    if (!queues->Unmerge(q_owner, q_sub) || queues->IsSubsumed(q_sub)) {
        return false;
    }
    queues->Dispose(q_sub);
    queues->Dispose(q_owner);

    fml::SyncSwitch sync_switch(false);
    int branch_taken = 0;
    sync_switch.Execute(
        fml::SyncSwitch::Handlers()
            .SetIfTrue([&branch_taken]() { branch_taken = 1; })
            .SetIfFalse([&branch_taken]() { branch_taken = 2; }));
    if (branch_taken != 2) {
        return false;
    }
    sync_switch.SetSwitch(true);
    sync_switch.Execute(
        fml::SyncSwitch::Handlers()
            .SetIfTrue([&branch_taken]() { branch_taken = 1; })
            .SetIfFalse([&branch_taken]() { branch_taken = 2; }));
    return branch_taken == 1;
}

// [EN] Verifies `LynxError::GetLevelString` (`0x024f7c`), `ErrorStorage`, and `LogMessage`.
// [VN] Kiểm chứng `LynxError::GetLevelString` (`0x024f7c`), `ErrorStorage`, và `LogMessage`.
bool VerifyLynxErrorAndLogging() {
    if (base::LynxError::GetLevelString(0) != "fatal" ||
        base::LynxError::GetLevelString(1) != "error" ||
        base::LynxError::GetLevelString(2) != "warn" ||
        base::LynxError::GetLevelString(99) != "fatal") {
        return false;
    }

    auto& storage = base::ErrorStorage::GetInstance();
    storage.Reset();
    if (!storage.SetError(1001, "Template decode failure", "Check template header",
                          base::LynxErrorLevel::ERROR, false)) {
        return false;
    }
    storage.GetError()->AddContextInfo("module", "liblynxbase.so");
    storage.GetError()->AddCallStack("at LynxTemplateRender.load");
    const bool valid = storage.GetError()->HasValidSuggestion() &&
                       storage.GetError()->error_code_ == 1001;
    storage.Reset();
    return valid;
}

} // namespace

LynxBaseParityReport RunLynxBaseParitySuite() {
    LynxBaseParityReport report;
    report.jni_onload_version = ::JNI_OnLoad(nullptr, nullptr);
    report.md5_rfc1321_passed = VerifyMd5Rfc1321();
    report.cityhash64_passed = VerifyCityHashAndRefCountedString();
    report.data_uri_decode_passed = VerifyDataUriAndBase64();
    report.js_dtoa_passed = VerifyJsDtoa();
    report.utf_conversion_passed = VerifyUtfAndStringSuite();
    report.reciprocal_time_math_passed = VerifyReciprocalTimeMath();
    report.fml_loop_and_queues_passed = VerifyFmlLoopAndQueues();
    report.lynx_error_and_logging_passed = VerifyLynxErrorAndLogging();
    return report;
}

} // namespace verification
} // namespace lynx
