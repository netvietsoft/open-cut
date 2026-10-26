/**
 * @file iesapplogger_interface.cpp
 * @brief Exact Implementation of IESAppLogger::AppLogTracker & AppLogTracker::Impl
 *        Triển khai Chính xác IESAppLogger::AppLogTracker & AppLogTracker::Impl
 *
 * Reconstructed from .text addresses 0x005878..0x0083f0 (.dynsym [048..121]).
 * Tái dựng từ các địa chỉ .text 0x005878..0x0083f0 (.dynsym [048..121]).
 */

#include "iesapplogger_interface.h"
#include <cstring>
#include <string>

namespace IESAppLogger {

using iesapplogger::AppLogReporter;
using iesapplogger::RodataStrings;
using iesapplogger::sso_string_append;
using iesapplogger::sso_string_assign;
using iesapplogger::sso_string_data;
using iesapplogger::sso_string_destroy;
using iesapplogger::sso_string_init_empty;
using iesapplogger::sso_string_reserve;
using iesapplogger::sso_string_size;

// ============================================================================
// 1. AppLogTracker::Impl Constructors & Destructor (0x005878..0x005b4c)
//    Hàm khởi tạo & Hàm hủy của AppLogTracker::Impl (0x005878..0x005b4c)
// ============================================================================

AppLogTracker::Impl::Impl(const std::string& app_id,
                          const std::string& event_name,
                          bool check_sample) {
    // Disassembly trace at 0x005878..0x005950:
    //   1. Initializes app_id_ (+0x00), event_name_ (+0x18), json_buffer_ (+0x30)
    //   2. Sets is_reported_ (+0x48) = 0, report_to_business_ (+0x49) = 0 (`strh wzr, [x19, #0x48]`),
    //      is_enabled_ (+0x4A) = 1 (`mov w8, #1; strb w8, [x19, #0x4a]` @ 0x00590c)
    //   3. Calls `json_buffer_.reserve(0x200)` (`mov w1, #0x200; bl reserve` @ 0x005914..0x005918)
    //   4. Calls `json_buffer_.assign("{", 1)` (`0x00c48b` @ 0x00591c..0x005928)
    //   5. If `check_sample` (`tbz w20, #0, #0x5950`), calls
    //      `is_enabled_ = AppLogReporter::GetSingleton()->isSampled(event_name_)` (@ 0x005930..0x00594c)
    sso_string_init_empty(&abi_.app_id);
    sso_string_init_empty(&abi_.event_name);
    sso_string_init_empty(&abi_.json_buffer);
    abi_.is_reported = false;
    abi_.report_to_business = false;
    abi_.is_enabled = true;
    std::memset(abi_.pad_4b, 0, sizeof(abi_.pad_4b));

    sso_string_assign(&abi_.app_id, app_id.data(), app_id.size());
    sso_string_assign(&abi_.event_name, event_name.data(), event_name.size());
    sso_string_reserve(&abi_.json_buffer, 0x200ULL);
    sso_string_assign(&abi_.json_buffer, RodataStrings::kJsonOpenBrace, 1ULL);

    if (check_sample) {
        abi_.is_enabled = AppLogReporter::GetSingleton()->isSampled(event_name);
    }
}

AppLogTracker::Impl::Impl(const char* app_id,
                          const char* event_name,
                          bool check_sample) {
    // Disassembly trace at 0x0059d0..0x005b2c:
    //   Same 80-byte initialization from C-strings `app_id` and `event_name`
    sso_string_init_empty(&abi_.app_id);
    sso_string_init_empty(&abi_.event_name);
    sso_string_init_empty(&abi_.json_buffer);
    abi_.is_reported = false;
    abi_.report_to_business = false;
    abi_.is_enabled = true;
    std::memset(abi_.pad_4b, 0, sizeof(abi_.pad_4b));

    if (app_id != nullptr) {
        sso_string_assign(&abi_.app_id, app_id, std::strlen(app_id));
    }
    if (event_name != nullptr) {
        sso_string_assign(&abi_.event_name, event_name, std::strlen(event_name));
    }
    sso_string_reserve(&abi_.json_buffer, 0x200ULL);
    sso_string_assign(&abi_.json_buffer, RodataStrings::kJsonOpenBrace, 1ULL);

    if (check_sample) {
        abi_.is_enabled = AppLogReporter::GetSingleton()->isSampled(eventNameString());
    }
}

AppLogTracker::Impl::~Impl() {
    // Matches cleanup in `~AppLogTracker()` @ 0x005cd0..0x005d28:
    //   Destroys `json_buffer_` (+0x30), `event_name_` (+0x18), `app_id_` (+0x00)
    sso_string_destroy(&abi_.json_buffer);
    sso_string_destroy(&abi_.event_name);
    sso_string_destroy(&abi_.app_id);
}

std::string AppLogTracker::Impl::appIdString() const {
    return std::string(sso_string_data(&abi_.app_id), sso_string_size(&abi_.app_id));
}

std::string AppLogTracker::Impl::eventNameString() const {
    return std::string(sso_string_data(&abi_.event_name), sso_string_size(&abi_.event_name));
}

std::string AppLogTracker::Impl::jsonBufferString() const {
    return std::string(sso_string_data(&abi_.json_buffer), sso_string_size(&abi_.json_buffer));
}

void AppLogTracker::Impl::appendCommaIfNeeded() {
    // Matches `cmp x8, #2; b.lo skip; append(",", 1)` at:
    //   0x005dcc..0x005df4, 0x006048..0x006070, 0x0062c4..0x0062ec, etc.
    // Whenever `json_buffer_.size() >= 2` (i.e. already has at least one field after `"{"`),
    // appends `","` (`0x00c48f`).
    if (sso_string_size(&abi_.json_buffer) >= 2ULL) {
        sso_string_append(&abi_.json_buffer, RodataStrings::kJsonComma, 1ULL);
    }
}

// ============================================================================
// 2. AppLogTracker::Impl Scalar putVal Overloads (0x005da8..0x006ffb)
//    Các phương thức nạp chồng putVal vô hướng (0x005da8..0x006ffb)
// ============================================================================

void AppLogTracker::Impl::putVal(const std::string& key, int val) {
    // Matches `_ZN12IESAppLogger13AppLogTracker4Impl6putValERKNSt6__ndk112basic_string...Ei` @ 0x005da8..0x005fd4 (.dynsym [085]):
    //   Appends: `,` (if size >= 2) + `"` + key + `":` + std::to_string(val)
    appendCommaIfNeeded();
    std::string val_str = std::to_string(val);
    std::string entry = "\"" + key + RodataStrings::kJsonKeyValueSep + val_str;
    sso_string_append(&abi_.json_buffer, entry.data(), entry.size());
}

void AppLogTracker::Impl::putVal(const char* key, int val) {
    if (key != nullptr) {
        putVal(std::string(key), val);
    }
}

void AppLogTracker::Impl::putVal(const std::string& key, long val) {
    // Matches `_ZN12IESAppLogger13AppLogTracker4Impl6putValERK...El` @ 0x006024..0x006250 (.dynsym [074])
    appendCommaIfNeeded();
    std::string val_str = std::to_string(val);
    std::string entry = "\"" + key + RodataStrings::kJsonKeyValueSep + val_str;
    sso_string_append(&abi_.json_buffer, entry.data(), entry.size());
}

void AppLogTracker::Impl::putVal(const char* key, long val) {
    if (key != nullptr) {
        putVal(std::string(key), val);
    }
}

void AppLogTracker::Impl::putVal(const std::string& key, unsigned long val) {
    // Matches `_ZN12IESAppLogger13AppLogTracker4Impl6putValERK...Em` @ 0x0062a0..0x0064cc (.dynsym [089])
    appendCommaIfNeeded();
    std::string val_str = std::to_string(val);
    std::string entry = "\"" + key + RodataStrings::kJsonKeyValueSep + val_str;
    sso_string_append(&abi_.json_buffer, entry.data(), entry.size());
}

void AppLogTracker::Impl::putVal(const char* key, unsigned long val) {
    if (key != nullptr) {
        putVal(std::string(key), val);
    }
}

void AppLogTracker::Impl::putVal(const std::string& key, float val) {
    // Matches `_ZN12IESAppLogger13AppLogTracker4Impl6putValERK...Ef` @ 0x00651c..0x006748 (.dynsym [076])
    appendCommaIfNeeded();
    std::string val_str = std::to_string(val);
    std::string entry = "\"" + key + RodataStrings::kJsonKeyValueSep + val_str;
    sso_string_append(&abi_.json_buffer, entry.data(), entry.size());
}

void AppLogTracker::Impl::putVal(const char* key, float val) {
    if (key != nullptr) {
        putVal(std::string(key), val);
    }
}

void AppLogTracker::Impl::putVal(const std::string& key, double val) {
    // Matches `_ZN12IESAppLogger13AppLogTracker4Impl6putValERK...Ed` @ 0x006798..0x0069c4 (.dynsym [104])
    appendCommaIfNeeded();
    std::string val_str = std::to_string(val);
    std::string entry = "\"" + key + RodataStrings::kJsonKeyValueSep + val_str;
    sso_string_append(&abi_.json_buffer, entry.data(), entry.size());
}

void AppLogTracker::Impl::putVal(const char* key, double val) {
    if (key != nullptr) {
        putVal(std::string(key), val);
    }
}

void AppLogTracker::Impl::putVal(const std::string& key, const std::string& val) {
    // Matches `_ZN12IESAppLogger13AppLogTracker4Impl6putValERK...S5_` @ 0x006a14..0x006ce4 (.dynsym [106]):
    //   Appends: `,` (if size >= 2) + `"` + key + `":"` (`0x00c494`, 3 bytes) + val + `"` (`0x00c496`, 1 byte)
    appendCommaIfNeeded();
    std::string entry = "\"" + key + RodataStrings::kJsonKeyQuoteSep + val + "\"";
    sso_string_append(&abi_.json_buffer, entry.data(), entry.size());
}

void AppLogTracker::Impl::putVal(const char* key, const std::string& val) {
    if (key != nullptr) {
        putVal(std::string(key), val);
    }
}

void AppLogTracker::Impl::putVal(const std::string& key, const char* val) {
    // Matches `_ZN12IESAppLogger13AppLogTracker4Impl6putValERK...PKc` @ 0x006d34..0x006fb4 (.dynsym [088])
    if (val == nullptr) {
        return;
    }
    appendCommaIfNeeded();
    std::string entry = "\"" + key + RodataStrings::kJsonKeyQuoteSep + std::string(val) + "\"";
    sso_string_append(&abi_.json_buffer, entry.data(), entry.size());
}

void AppLogTracker::Impl::putVal(const char* key, const char* val) {
    if (key != nullptr && val != nullptr) {
        putVal(std::string(key), val);
    }
}

// ============================================================================
// 3. AppLogTracker::Impl Array/Vector putVals Overloads (0x006ffc..0x008388)
//    Các phương thức nạp chồng putVals mảng/vector (0x006ffc..0x008388)
// ============================================================================

namespace {

template <typename T>
void putNumericArrayHelper(iesapplogger::LibcppSsoStringAbi* json_buf,
                           const std::string& key,
                           int count,
                           const T* vals) {
    // Disassembly proof at 0x00701c (`cmp w2, #1; b.lt #0x7244`):
    //   1. If `count < 1`, returns immediately without modifying `json_buffer_`.
    //   2. Note how the binary formats arrays in `putVals` (0x007060..0x007240):
    //      - First element: `"` + key + `":"` (`0x00c494`, 3 bytes) + `std::to_string(vals[0])`
    //      - Subsequent elements (`i = 1..count-1` at 0x007170..0x00722c):
    //        `std::to_string(vals[i]).insert(0, ",", 1)` (`bl insert` @ 0x0071a8)
    //      - Closing quote: `append("\"", 1)` (`0x00c496` @ 0x007230..0x007240)!
    //   Notice that ByteDance's native `putVals` serializes arrays as a comma-separated string value
    //   enclosed in quotes `"key":"v0,v1,v2"`!
    if (count < 1 || vals == nullptr) {
        return;
    }
    if (sso_string_size(json_buf) >= 2ULL) {
        sso_string_append(json_buf, RodataStrings::kJsonComma, 1ULL);
    }
    std::string prefix = "\"" + key + RodataStrings::kJsonKeyQuoteSep + std::to_string(vals[0]);
    sso_string_append(json_buf, prefix.data(), prefix.size());

    for (int i = 1; i < count; ++i) {
        std::string item = std::to_string(vals[i]);
        item.insert(0, RodataStrings::kJsonComma, 1ULL);
        sso_string_append(json_buf, item.data(), item.size());
    }
    sso_string_append(json_buf, "\"", 1ULL);
}

}  // namespace

void AppLogTracker::Impl::putVals(const std::string& key, int count, int* vals) {
    // Matches `0x006ffc..0x0072b0` (.dynsym [108])
    putNumericArrayHelper(&abi_.json_buffer, key, count, vals);
}

void AppLogTracker::Impl::putVals(const std::string& key, int count, long* vals) {
    // Matches `0x0072e4..0x007628` (.dynsym [078])
    putNumericArrayHelper(&abi_.json_buffer, key, count, vals);
}

void AppLogTracker::Impl::putVals(const std::string& key, int count, unsigned long* vals) {
    // Matches `0x00765c..0x0079a0` (.dynsym [063])
    putNumericArrayHelper(&abi_.json_buffer, key, count, vals);
}

void AppLogTracker::Impl::putVals(const std::string& key, int count, float* vals) {
    // Matches `0x0079d4..0x007d18` (.dynsym [110])
    putNumericArrayHelper(&abi_.json_buffer, key, count, vals);
}

void AppLogTracker::Impl::putVals(const std::string& key, int count, double* vals) {
    // Matches `0x007d4c..0x008090` (.dynsym [118])
    putNumericArrayHelper(&abi_.json_buffer, key, count, vals);
}

void AppLogTracker::Impl::putVals(const std::string& key, const std::vector<std::string>& vals) {
    // Matches `_ZN12IESAppLogger13AppLogTracker4Impl7putValsERK...RKNS_6vector...` @ 0x0080c4..0x008384 (.dynsym [048]):
    //   0x0080ec..0x0080f4: `ldp x8, x9, [x2]; cmp x8, x9; b.eq #0x82b4` (if empty vector, return)
    //   0x008204..0x008214: `mov x23, #0xaaaaaaaaaaaaaab; sub x9, x9, x8; asr x9, x9, #3; mul x9, x9, x23`
    //                       (computes `vals.size() = (end - begin) / 24` via magic multiplier `0xaaaaaaaaaaaaaab`!)
    //   Formats `"key":"vals[0],vals[1],..."` using `operator+(",", vals[i])` (@ 0x008268) and closes with `"` (@ 0x0082b0).
    if (vals.empty()) {
        return;
    }
    appendCommaIfNeeded();
    std::string first = "\"" + key + RodataStrings::kJsonKeyQuoteSep + vals[0];
    sso_string_append(&abi_.json_buffer, first.data(), first.size());

    for (size_t i = 1; i < vals.size(); ++i) {
        std::string item = std::string(RodataStrings::kJsonComma) + vals[i];
        sso_string_append(&abi_.json_buffer, item.data(), item.size());
    }
    sso_string_append(&abi_.json_buffer, "\"", 1ULL);
}

// ============================================================================
// 4. AppLogTracker Wrapper Implementation (0x005b50..0x0083f0)
//    Triển khai lớp bọc AppLogTracker (0x005b50..0x0083f0)
// ============================================================================

AppLogTracker::AppLogTracker(const std::string& app_id,
                             const std::string& event_name,
                             bool check_sample)
    : impl_(new Impl(app_id, event_name, check_sample)) {}

AppLogTracker::AppLogTracker(const char* app_id,
                             const char* event_name,
                             bool check_sample)
    : impl_(new Impl(app_id, event_name, check_sample)) {}

AppLogTracker::~AppLogTracker() {
    // Disassembly trace at 0x005c28..0x005d40 (.dynsym [079, 086]):
    //   0x005c38: ldr  x20, [x0]          ; x20 = impl_
    //   0x005c3c: ldrb w8, [x20, #0x4a]   ; w8 = impl_->is_enabled_
    //   0x005c40: cbz  w8, #0x5cd0        ; if (!is_enabled_) skip report
    //   0x005c44: ldrb w8, [x20, #0x48]   ; w8 = impl_->is_reported_
    //   0x005c48: tbnz w8, #0, #0x5cd0    ; if (is_reported_) skip report
    //   0x005c4c..0x005c5c: impl_->json_buffer_.append("}", 1) (0x00c48d)
    //   0x005c60..0x005cc4: AppLogReporter::GetSingleton()->report(
    //                           impl_->app_id_.c_str(),
    //                           impl_->event_name_.c_str(),
    //                           impl_->json_buffer_.c_str(),
    //                           impl_->report_to_business_)
    //   0x005cc8: mov  w8, #1
    //   0x005ccc: strb w8, [x8, #0x48]    ; impl_->is_reported_ = true
    //   0x005cd0..0x005d2c: delete impl_
    if (impl_ != nullptr) {
        auto* raw = impl_->rawAbi();
        if (raw->is_enabled && !raw->is_reported) {
            sso_string_append(&raw->json_buffer, RodataStrings::kJsonCloseBrace, 1ULL);
            AppLogReporter::GetSingleton()->report(
                sso_string_data(&raw->app_id),
                sso_string_data(&raw->event_name),
                sso_string_data(&raw->json_buffer),
                raw->report_to_business);
            raw->is_reported = true;
        }
        delete impl_;
        impl_ = nullptr;
    }
}

// Each `AppLogTracker::putVal` & `putVals` checks `ldrb w8, [x0, #0x4a]; cbz w8, skip` (`impl_->is_enabled_`)
// before delegating to `Impl::putVal` / `Impl::putVals`, and returns `*this` (`mov x0, x19; ret`).
AppLogTracker& AppLogTracker::putVal(const std::string& key, int val) {
    if (impl_->rawAbi()->is_enabled) {
        impl_->putVal(key, val);
    }
    return *this;
}

AppLogTracker& AppLogTracker::putVal(const char* key, int val) {
    if (impl_->rawAbi()->is_enabled && key != nullptr) {
        impl_->putVal(std::string(key), val);
    }
    return *this;
}

AppLogTracker& AppLogTracker::putVal(const std::string& key, long val) {
    if (impl_->rawAbi()->is_enabled) {
        impl_->putVal(key, val);
    }
    return *this;
}

AppLogTracker& AppLogTracker::putVal(const char* key, long val) {
    if (impl_->rawAbi()->is_enabled && key != nullptr) {
        impl_->putVal(std::string(key), val);
    }
    return *this;
}

AppLogTracker& AppLogTracker::putVal(const std::string& key, unsigned long val) {
    if (impl_->rawAbi()->is_enabled) {
        impl_->putVal(key, val);
    }
    return *this;
}

AppLogTracker& AppLogTracker::putVal(const char* key, unsigned long val) {
    if (impl_->rawAbi()->is_enabled && key != nullptr) {
        impl_->putVal(std::string(key), val);
    }
    return *this;
}

AppLogTracker& AppLogTracker::putVal(const std::string& key, float val) {
    if (impl_->rawAbi()->is_enabled) {
        impl_->putVal(key, val);
    }
    return *this;
}

AppLogTracker& AppLogTracker::putVal(const char* key, float val) {
    if (impl_->rawAbi()->is_enabled && key != nullptr) {
        impl_->putVal(std::string(key), val);
    }
    return *this;
}

AppLogTracker& AppLogTracker::putVal(const std::string& key, double val) {
    if (impl_->rawAbi()->is_enabled) {
        impl_->putVal(key, val);
    }
    return *this;
}

AppLogTracker& AppLogTracker::putVal(const char* key, double val) {
    if (impl_->rawAbi()->is_enabled && key != nullptr) {
        impl_->putVal(std::string(key), val);
    }
    return *this;
}

AppLogTracker& AppLogTracker::putVal(const std::string& key, const std::string& val) {
    if (impl_->rawAbi()->is_enabled) {
        impl_->putVal(key, val);
    }
    return *this;
}

AppLogTracker& AppLogTracker::putVal(const char* key, const std::string& val) {
    if (impl_->rawAbi()->is_enabled && key != nullptr) {
        impl_->putVal(std::string(key), val);
    }
    return *this;
}

AppLogTracker& AppLogTracker::putVal(const std::string& key, const char* val) {
    if (impl_->rawAbi()->is_enabled) {
        impl_->putVal(key, val);
    }
    return *this;
}

AppLogTracker& AppLogTracker::putVal(const char* key, const char* val) {
    if (impl_->rawAbi()->is_enabled && key != nullptr && val != nullptr) {
        impl_->putVal(std::string(key), val);
    }
    return *this;
}

AppLogTracker& AppLogTracker::putVals(const std::string& key, int count, int* vals) {
    if (impl_->rawAbi()->is_enabled) {
        impl_->putVals(key, count, vals);
    }
    return *this;
}

AppLogTracker& AppLogTracker::putVals(const std::string& key, int count, long* vals) {
    if (impl_->rawAbi()->is_enabled) {
        impl_->putVals(key, count, vals);
    }
    return *this;
}

AppLogTracker& AppLogTracker::putVals(const std::string& key, int count, unsigned long* vals) {
    if (impl_->rawAbi()->is_enabled) {
        impl_->putVals(key, count, vals);
    }
    return *this;
}

AppLogTracker& AppLogTracker::putVals(const std::string& key, int count, float* vals) {
    if (impl_->rawAbi()->is_enabled) {
        impl_->putVals(key, count, vals);
    }
    return *this;
}

AppLogTracker& AppLogTracker::putVals(const std::string& key, int count, double* vals) {
    if (impl_->rawAbi()->is_enabled) {
        impl_->putVals(key, count, vals);
    }
    return *this;
}

AppLogTracker& AppLogTracker::putVals(const std::string& key, const std::vector<std::string>& vals) {
    if (impl_->rawAbi()->is_enabled) {
        impl_->putVals(key, vals);
    }
    return *this;
}

void AppLogTracker::enableAllReports() {
    // Matches `_ZN12IESAppLogger13AppLogTracker16enableAllReportsEv` @ 0x00838c..0x0083a4 (.dynsym [119]):
    //   0x008394: bl   _ZN14AppLogReporter12GetSingletonEv
    //   0x008398: mov  w8, #1
    //   0x00839c: strb w8, [x0, #0x30]
    AppLogReporter::GetSingleton()->setEnabled(true);
}

void AppLogTracker::disableAllReports() {
    // Matches `_ZN12IESAppLogger13AppLogTracker17disableAllReportsEv` @ 0x0083a8..0x0083bc (.dynsym [084]):
    //   0x0083b0: bl   _ZN14AppLogReporter12GetSingletonEv
    //   0x0083b4: strb wzr, [x0, #0x30]
    AppLogReporter::GetSingleton()->setEnabled(false);
}

void AppLogTracker::setReportToBusiness(bool to_business) noexcept {
    // Matches `_ZN12IESAppLogger13AppLogTracker19setReportToBusinessEb` @ 0x0083c0..0x0083cc (.dynsym [117]):
    //   0x0083c0: ldr  x8, [x0]
    //   0x0083c4: and  w9, w1, #1
    //   0x0083c8: strb w9, [x8, #0x49]
    //   0x0083cc: ret
    if (impl_ != nullptr) {
        impl_->rawAbi()->report_to_business = to_business;
    }
}

bool AppLogTracker::isSampled(const std::string& event_name) {
    // Matches `_ZN12IESAppLogger13AppLogTracker9isSampledERK...` @ 0x0083d0..0x0083f0 (.dynsym [101]):
    //   Calls `AppLogReporter::GetSingleton()->isSampled(event_name)` via tail-call `b #0x3a20`
    return AppLogReporter::GetSingleton()->isSampled(event_name);
}

}  // namespace IESAppLogger
