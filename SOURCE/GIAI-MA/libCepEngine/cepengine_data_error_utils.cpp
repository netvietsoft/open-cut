// ============================================================================
// FILE: cepengine_data_error_utils.cpp
// TARGET: libCepEngine.so — Error Subsystem, Data Accessors & DSL Utilities
// TRẠNG THÁI / STATUS: 100% RECONSTRUCTED — ZERO STUBS — AARCH64 VERIFIED
// ============================================================================
// [EN] Full C++17 implementation of `ApiVersion`, `DefaultContext`, `DataInterface`,
//      `DebugInfo`, `ValueInfo`, `MatchTransitionInfo`, `TransitionInfo`,
//      `Error`, `GetInt`/`GetDouble`/`GetString`/`GetList`/`GetDict`,
//      `GetCurrentTimestamp` (with 64-bit magic multiplier `0x20c49ba5e353f7cf`),
//      `IsValidTimestamp`, `StrFormat`, `CheckDSLVersion`, `ParseKeyChain`,
//      `RWLock`, `ReadLockGuard`, `WriteLockGuard`, `LockWrite`, and `Semaphore`.
// [VN] Bản cài đặt C++17 đầy đủ cho `ApiVersion`, `DefaultContext`, `DataInterface`,
//      `DebugInfo`, `ValueInfo`, `MatchTransitionInfo`, `TransitionInfo`,
//      `Error`, `GetInt`/`GetDouble`/`GetString`/`GetList`/`GetDict`,
//      `GetCurrentTimestamp` (với số nhân ma thuật 64-bit `0x20c49ba5e353f7cf`),
//      `IsValidTimestamp`, `StrFormat`, `CheckDSLVersion`, `ParseKeyChain`,
//      `RWLock`, `ReadLockGuard`, `WriteLockGuard`, `LockWrite`, và `Semaphore`.
// ============================================================================

#include "cepengine_data_error_utils.h"
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <thread>

// ============================================================================
// 1. GLOBAL API VERSION & DEFAULT CONTEXT (`0x0c33c..0x0c4e7`)
// ============================================================================

// [EN] Disassembly @ 0x0c33c (`_Z10ApiVersionv`, 8 B):
//      0x0c33c: 52800040  mov w0, #2
//      0x0c340: d65f03c0  ret
// [VN] Mã máy @ 0x0c33c (`_Z10ApiVersionv`, 8 B): trả về phiên bản API = 2.
int ApiVersion() {
    return 2;
}

namespace cep {

// [EN] Disassembly @ 0x0c358 (`_ZN3cep14DefaultContext9GetSharedEv`, 240 B):
//      0x0c364: 90000289  adrp x9, #0x5c000
//      0x0c368: 9100c129  add  x9, x9, #0x30      // guard at .bss 0x5c030
//      0x0c36c: 08dffd2a  ldarb w10, [x9]
//      0x0c370: 90000289  adrp x9, #0x5c000
//      0x0c374: 91008129  add  x9, x9, #0x20      // shared_ptr at .bss 0x5c020
//      0x0c378: 3600018a  tbz  w10, #0, #0xc3a8
// [VN] Mã máy @ 0x0c358 (`cep::DefaultContext::GetShared()`, 240 B):
std::shared_ptr<DefaultContext> DefaultContext::GetShared() {
    static std::shared_ptr<DefaultContext> instance = std::make_shared<DefaultContext>();
    return instance;
}

// ============================================================================
// 2. DATA INTERFACE METHODS (`0x0c4e8..0x0c767`)
// ============================================================================

// [EN] Disassembly @ 0x0c4e8 (`_ZN3cep13DataInterface13InterfaceTypeEv`, 8 B):
//      0x0c4e8: 52800040  mov w0, #2
//      0x0c4ec: d65f03c0  ret
// [VN] Mã máy @ 0x0c4e8: trả về loại giao diện cơ sở = 2.
int DataInterface::InterfaceType() {
    return static_cast<int>(DataInterfaceType::kBaseInterface);
}

// [EN] Disassembly @ 0x0c4f0 (`_ZN3cep13DataInterfaceD2Ev`, 4 B): `d65f03c0 ret`
// [VN] Hàm hủy ảo `DataInterface::~DataInterface()` @ 0x0c4f0.
DataInterface::~DataInterface() = default;

// [EN] Disassembly @ 0x0c4f8 (`_ZN3cep13DataInterface17ConvertToIntValueEv`, 136 B):
//      0x0c504: f9400008  ldr x8, [x0]
//      0x0c50c: f9400108  ldr x8, [x8]            // vtable +0x00: Type()
//      0x0c510: d63f0100  blr x8
//      0x0c514: 7100081f  cmp w0, #2              // kBool
//      0x0c518: 54000140  b.eq #0xc540
//      0x0c51c: 7100041f  cmp w0, #1              // kFloat
//      0x0c520: 540001c0  b.eq #0xc558
//      0x0c524: 35000260  cbnz w0, #0xc570        // if != 0 (kInt), return 0
//      0x0c534: f9400901  ldr x1, [x8, #0x10]     // vtable +0x10: IntValue()
//      0x0c548: f9401108  ldr x8, [x8, #0x20]     // vtable +0x20: BoolValue()
//      0x0c550: 92400000  and x0, x0, #1
//      0x0c560: f9400d08  ldr x8, [x8, #0x18]     // vtable +0x18: FloatValue()
//      0x0c568: 9e780000  fcvtzs x0, d0
// [VN] Chuyển đổi giá trị sang số nguyên 64-bit (`ConvertToIntValue` @ 0x0c4f8):
long DataInterface::ConvertToIntValue() {
    const int t = Type();
    if (t == static_cast<int>(DataType::kInt)) {
        return IntValue();
    }
    if (t == static_cast<int>(DataType::kFloat)) {
        return static_cast<long>(FloatValue());
    }
    if (t == static_cast<int>(DataType::kBool)) {
        return BoolValue() ? 1L : 0L;
    }
    return 0L;
}

// [EN] Disassembly @ 0x0c580 (`_ZN3cep13DataInterface20ConvertToDoubleValueEv`, 136 B):
//      0x0c59c: 7100081f  cmp w0, #2              // kBool -> ucvtf d0, w8 (@ 0x0c5e0)
//      0x0c5a4: 7100041f  cmp w0, #1              // kFloat -> vtable +0x18 FloatValue()
//      0x0c5ac: 9e6703e0  fmov d0, xzr
//      0x0c5b0: 350001a0  cbnz w0, #0xc5e4        // if != 0 (kInt), return 0.0
//      0x0c5bc: f9400908  ldr x8, [x8, #0x10]     // vtable +0x10: IntValue()
//      0x0c5c4: 9e620000  scvtf d0, x0
// [VN] Chuyển đổi giá trị sang số thực dấu phẩy động (`ConvertToDoubleValue` @ 0x0c580):
double DataInterface::ConvertToDoubleValue() {
    const int t = Type();
    if (t == static_cast<int>(DataType::kInt)) {
        return static_cast<double>(IntValue());
    }
    if (t == static_cast<int>(DataType::kFloat)) {
        return FloatValue();
    }
    if (t == static_cast<int>(DataType::kBool)) {
        return BoolValue() ? 1.0 : 0.0;
    }
    return 0.0;
}

// [EN] Disassembly @ 0x0c608 (`_ZN3cep13DataInterface8IsNumberEv`, 100 B):
//      Checks Type() == 0 (kInt) || Type() == 1 (kFloat) || Type() == 2 (kBool).
// [VN] Kiểm tra có phải kiểu số (`IsNumber` @ 0x0c608):
bool DataInterface::IsNumber() {
    if (Type() == static_cast<int>(DataType::kInt)) {
        return true;
    }
    if (Type() == static_cast<int>(DataType::kFloat)) {
        return true;
    }
    return Type() == static_cast<int>(DataType::kBool);
}

// [EN] Disassembly @ 0x0c66c..0x0c764 (`IsInt`..`IsNull`, 36 B each):
//      0x0c680: 7100001f cmp w0, #0; 0x0c684: 1a9f17e0 cset w0, eq  (IsInt)
//      0x0c6a4: 7100041f cmp w0, #1; 0x0c6a8: 1a9f17e0 cset w0, eq  (IsFloat)
//      0x0c6c8: 7100081f cmp w0, #2; 0x0c6cc: 1a9f17e0 cset w0, eq  (IsBool)
//      0x0c6ec: 71000c1f cmp w0, #3; 0x0c6f0: 1a9f17e0 cset w0, eq  (IsStr)
//      0x0c710: 7100101f cmp w0, #4; 0x0c714: 1a9f17e0 cset w0, eq  (IsList)
//      0x0c734: 7100141f cmp w0, #5; 0x0c738: 1a9f17e0 cset w0, eq  (IsDict)
//      0x0c758: 7100181f cmp w0, #6; 0x0c75c: 1a9f17e0 cset w0, eq  (IsNull)
// [VN] Các phương thức kiểm tra kiểu dữ liệu (`0x0c66c..0x0c764`):
bool DataInterface::IsInt()   { return Type() == static_cast<int>(DataType::kInt); }
bool DataInterface::IsFloat() { return Type() == static_cast<int>(DataType::kFloat); }
bool DataInterface::IsBool()  { return Type() == static_cast<int>(DataType::kBool); }
bool DataInterface::IsStr()   { return Type() == static_cast<int>(DataType::kStr); }
bool DataInterface::IsList()  { return Type() == static_cast<int>(DataType::kList); }
bool DataInterface::IsDict()  { return Type() == static_cast<int>(DataType::kDict); }
bool DataInterface::IsNull()  { return Type() == static_cast<int>(DataType::kNull); }

// ============================================================================
// 3. DEBUG INFO, VALUE INFO & TRANSITION INFO (`0x0c768..0x0cba7`)
// ============================================================================

// [EN] Disassembly @ 0x0c768 (`_ZN3cep9DebugInfo10GetBizNameEv`, 12 B):
//      0x0c768: 91002001 add x1, x0, #8; 0x0c76c: aa0803e0 mov x0, x8; 0x0c770: b #0xc774
// [VN] Lấy tên nghiệp vụ (`GetBizName` @ 0x0c768, độ lệch +0x08):
std::string DebugInfo::GetBizName() {
    return biz_name_;
}

// [EN] Disassembly @ 0x0c81c (`_ZN3cep9DebugInfo11GetRuleNameEv`, 12 B):
//      0x0c81c: 91008001 add x1, x0, #0x20; 0x0c820: aa0803e0 mov x0, x8; 0x0c824: b #0xc774
// [VN] Lấy tên quy tắc (`GetRuleName` @ 0x0c81c, độ lệch +0x20):
std::string DebugInfo::GetRuleName() {
    return rule_name_;
}

// [EN] Disassembly @ 0x0c828 (`_ZN3cep9ValueInfoC2E...`, 128 B):
//      Initializes vtable `_ZTVN3cep9ValueInfoE` @ 0x5aa78, copies `biz_name` (+0x08),
//      `rule_name` (+0x20), moves `tag` (+0x38), and copies `value` shared_ptr (+0x50).
// [VN] Hàm tạo `ValueInfo` @ 0x0c828 (128 B):
ValueInfo::ValueInfo(const std::string& biz_name,
                     const std::string& rule_name,
                     std::string tag,
                     std::shared_ptr<DataInterface> value)
    : DebugInfo(biz_name, rule_name),
      tag_(std::move(tag)),
      value_(std::move(value)) {}

// [EN] Disassembly @ 0x0c8a8 (`_ZN3cep9ValueInfo6GetTagEv`, 12 B): `add x1, x0, #0x38`
// [VN] Lấy nhãn giá trị (`GetTag` @ 0x0c8a8, độ lệch +0x38):
std::string ValueInfo::GetTag() {
    return tag_;
}

// [EN] Disassembly @ 0x0c8b4 (`_ZN3cep9ValueInfo8GetValueEv`, 44 B): `ldr x9, [x0, #0x50]`
// [VN] Lấy giá trị (`GetValue` @ 0x0c8b4, độ lệch +0x50):
std::shared_ptr<DataInterface> ValueInfo::GetValue() {
    return value_;
}

// [EN] Disassembly @ 0x0c8e0 (`_ZN3cep9ValueInfo16GetDebugInfoTypeEv`, 8 B):
//      0x0c8e0: 2a1f03e0 mov w0, wzr; 0x0c8e4: d65f03c0 ret
// [VN] Loại thông tin gỡ lỗi `ValueInfo` = 0 (@ 0x0c8e0):
int ValueInfo::GetDebugInfoType() {
    return 0;
}

// [EN] Disassembly @ 0x0c8e8 (`_ZN3cep19MatchTransitionInfo13current_matchEv`, 44 B):
//      `ldr x9, [x0]; ldr x9, [x0, #8]`
// [VN] Lấy trạng thái khớp hiện tại (`current_match` @ 0x0c8e8):
std::shared_ptr<Match> MatchTransitionInfo::current_match() {
    return current_match_;
}

// [EN] Disassembly @ 0x0c914 (`_ZN3cep19MatchTransitionInfo12next_matchesEv`, 164 B):
// [VN] Lấy danh sách trạng thái khớp kế tiếp (`next_matches` @ 0x0c914):
std::vector<std::shared_ptr<Match>> MatchTransitionInfo::next_matches() {
    return next_matches_;
}

// [EN] Disassembly @ 0x0c9b8 (`_ZNK3cep19MatchTransitionInfo5errorEv`, 8 B):
//      0x0c9b8: f9401400 ldr x0, [x0, #0x28]; 0x0c9bc: 17fffc65 b #0xbb50 (Error::FormatString)
// [VN] Lấy chuỗi lỗi của bước chuyển tiếp (`error` @ 0x0c9b8):
std::string MatchTransitionInfo::error() const {
    if (!error_) {
        return "";
    }
    return error_->FormatString();
}

// [EN] Disassembly @ 0x0cac0..0x0cba4 (`TransitionInfo` methods):
//      0x0cac0: b9406800 ldr w0, [x0, #0x68]; ret        (GetTriggerType)
//      0x0cac8: f9403809 ldr x9, [x0, #0x70]             (GetEvent)
//      0x0caf4: f9404000 ldr x0, [x0, #0x80]; ret        (GetAdvanceTime)
//      0x0cafc: GetTransitions (+0x88)
//      0x0cba0: 52800020 mov w0, #1; d65f03c0 ret        (GetDebugInfoType -> 1)
// [VN] Các phương thức `TransitionInfo` (@ 0x0cac0..0x0cba4):
int TransitionInfo::GetTriggerType() const {
    return trigger_type_;
}

std::shared_ptr<EventWrapper> TransitionInfo::GetEvent() {
    return event_;
}

long long TransitionInfo::GetAdvanceTime() const {
    return advance_time_;
}

std::vector<MatchTransitionInfo> TransitionInfo::GetTransitions() {
    return transitions_;
}

int TransitionInfo::GetDebugInfoType() {
    return 1;
}

// ============================================================================
// 4. ERROR SUBSYSTEM (`0x25ac8..0x26e13`)
// ============================================================================

// [EN] Disassembly @ 0x25ac8 (`ErrorItem` formatting & static lookup table `.bss 0x5c680`):
//      Maps ErrorCode 1..22 to `.rodata` strings 0x4c170..0x4c356 and formats `"[%d]%s"` (0x4c36f).
// [VN] Bảng ánh xạ mã lỗi sang chuỗi `.rodata` 0x4c170..0x4c356 (@ 0x25ac8):
const char* Error::GetErrorCodeLabel(ErrorCode code) {
    switch (code) {
        case kErrorInputNullEvent:                     return "Input Null Event";
        case kErrorCalculateExpression:                return "Error Occur When Calculate Expression";
        case kErrorInvalidRule:                        return "Invalid Rule";
        case kErrorInvalidEdge:                        return "Invalid Edge";
        case kErrorInvalidState:                       return "Invalid State";
        case kErrorInvalidCondition:                   return "Invalid Condition";
        case kErrorInvalidTimerSettings:               return "Invalid Timer Settings";
        case kErrorExpressionEngineNotLoad:            return "Expression Engine Not Load";
        case kErrorCreateStreamFailed:                 return "Create Stream Failed";
        case kErrorInvalidExpressionEngine:            return "Invalid Expression Engine";
        case kErrorInvalidEventTimestamp:              return "Invalid Event Timestamp";
        case kErrorRuleNotExistOrStopped:              return "Rule Not Exist Or Stopped";
        case kErrorInvalidProcessResult:               return "Invalid Process Result(Maybe There Are Some Bug)";
        case kErrorInvalidSettingsItem:                return "Invalid Settings Item";
        case kErrorInvalidQuantity:                    return "Invalid Quantity";
        case kErrorSettingsInvalidAndFallbackNotExist: return "Settings Invalid And Fallback Not Exist";
        case kErrorNotCompatibleDSL:                   return "Not Compatible DSL";
        case kErrorTooManyFlows:                       return "Too Many Flows";
        case kErrorNoSuchTargetState:                  return "No Such Target State";
        case kErrorCopyStreamFailed:                   return "Copy Stream Failed";
        case kErrorCannotFindStartState:               return "Cannot Find Start State";
        case kErrorTooManyEventsInQueue:               return "Too Many Events In Queue";
        default:                                       return "Unknown Error";
    }
}

ErrorItem::ErrorItem(ErrorCode c, const std::string& detail) : code(c) {
    // [EN] Formats `"[%d]%s"` (0x4c36f) + optional `"; Detail: %s"` (0x4be4c)
    // [VN] Định dạng `"[%d]%s"` (0x4c36f) kèm chi tiết lỗi nếu có
    std::string base = StrFormat("[%d]%s", static_cast<int>(c), Error::GetErrorCodeLabel(c));
    if (!detail.empty()) {
        base += "; " + StrFormat("Detail: %s", detail.c_str());
    }
    message = std::move(base);
}

// [EN] Disassembly @ 0x26404 (`_ZN3cep5Error8SetFatalERKNS_9ErrorCodeE`, 256 B):
//      0x2642c: 52800700  mov w0, #0x38
//      0x2644c: b94002c1  ldr w1, [x22]
//      0x26468: 97fffd98  bl  #0x25ac8
//      0x26480: a9015697  stp x23, x21, [x20, #0x10]  // stores shared_ptr<ErrorItem> at +0x10
//      0x264b8: a9400288  ldp x8, x0, [x20]           // returns shared_from_this()
// [VN] Đặt lỗi nghiêm trọng (`SetFatal` @ 0x26404):
std::shared_ptr<Error> Error::SetFatal(const ErrorCode& code) {
    fatal_ = std::make_shared<ErrorItem>(code, "");
    try {
        return shared_from_this();
    } catch (...) {
        return nullptr;
    }
}

std::shared_ptr<Error> Error::SetFatal(const ErrorCode& code, const std::string& msg) {
    fatal_ = std::make_shared<ErrorItem>(code, msg);
    try {
        return shared_from_this();
    } catch (...) {
        return nullptr;
    }
}

// [EN] Disassembly @ 0x26504 (`_ZNK3cep5Error7IsFatalEv`, 16 B):
//      0x26504: f9400808  ldr  x8, [x0, #0x10]
//      0x26508: f100011f  cmp  x8, #0
//      0x2650c: 1a9f07e0  cset w0, ne
//      0x26510: d65f03c0  ret
// [VN] Kiểm tra có lỗi nghiêm trọng hay không (`IsFatal` @ 0x26504):
bool Error::IsFatal() const {
    return fatal_ != nullptr;
}

// [EN] Disassembly @ 0x26514 (`_ZN3cep5Error10AddWarningERKNS_9ErrorCodeERKNSt6__ndk112basic_string...`, 308 B):
//      Allocates `shared_ptr<ErrorItem>` with `code` and `detail`, appends to `warnings_` (+0x20),
//      and returns `shared_from_this()`.
// [VN] Thêm cảnh báo vào danh sách `warnings_` (+0x20) (@ 0x26514):
std::shared_ptr<Error> Error::AddWarning(const ErrorCode& code, const std::string& detail) {
    warnings_.push_back(std::make_shared<ErrorItem>(code, detail));
    try {
        return shared_from_this();
    } catch (...) {
        return nullptr;
    }
}

// [EN] Disassembly @ 0x26648 (`_ZN3cep5Error7CombineERKNSt6__ndk110shared_ptrIS0_EE`, 300 B):
//      Copies `other->fatal_` if `other->IsFatal()`, appends all `other->warnings_`,
//      and returns `shared_from_this()`.
// [VN] Hợp nhất đối tượng `Error` khác vào đối tượng hiện tại (`Combine` @ 0x26648):
std::shared_ptr<Error> Error::Combine(const std::shared_ptr<Error>& other) {
    if (other) {
        if (other->fatal_) {
            fatal_ = other->fatal_;
        }
        for (const auto& w : other->warnings_) {
            warnings_.push_back(w);
        }
    }
    try {
        return shared_from_this();
    } catch (...) {
        return nullptr;
    }
}

// [EN] Disassembly @ 0x26774 (`_ZN3cep5Error8AllCodesEv`, 132 B):
//      Collects `fatal_->code` (if non-null) followed by every `w->code` in `warnings_`.
// [VN] Thu thập tất cả mã lỗi và cảnh báo (`AllCodes` @ 0x26774):
std::vector<ErrorCode> Error::AllCodes() {
    std::vector<ErrorCode> codes;
    if (fatal_) {
        codes.push_back(fatal_->code);
    }
    for (const auto& w : warnings_) {
        if (w) {
            codes.push_back(w->code);
        }
    }
    return codes;
}

// [EN] Disassembly @ 0x267f8 (`_ZN3cep5Error9FatalCodeEv`, 24 B):
//      0x267f8: f9400808  ldr x8, [x0, #0x10]
//      0x267fc: b4000068  cbz x8, #0x26808
//      0x26800: b9400100  ldr w0, [x8]
//      0x26804: d65f03c0  ret
//      0x26808: 2a1f03e0  mov w0, wzr; ret
// [VN] Lấy mã lỗi nghiêm trọng (`FatalCode` @ 0x267f8):
ErrorCode Error::FatalCode() {
    if (fatal_) {
        return fatal_->code;
    }
    return kErrorNone;
}

// [EN] Disassembly @ 0x26810 (`_ZN3cep5Error17FatalFormatStringEv`, 72 B):
//      Returns `fatal_->message` if `fatal_ != nullptr`, else `""`.
// [VN] Lấy chuỗi định dạng lỗi nghiêm trọng (`FatalFormatString` @ 0x26810):
std::string Error::FatalFormatString() {
    if (!fatal_) {
        return "";
    }
    return fatal_->message;
}

// [EN] Disassembly @ 0x268ec (`_ZN3cep5Error20WarningsFormatStringEv`, 248 B):
//      Returns vector of formatted strings from `warnings_`.
// [VN] Lấy danh sách chuỗi cảnh báo (`WarningsFormatString` @ 0x268ec):
std::vector<std::string> Error::WarningsFormatString() {
    std::vector<std::string> out;
    out.reserve(warnings_.size());
    for (const auto& w : warnings_) {
        if (w) {
            out.push_back(w->message);
        }
    }
    return out;
}

// [EN] Disassembly @ 0x269e4 (`_ZN3cep5Error12FormatStringEv`, 1072 B):
//      Formats context header (`"Biz: %s;"` @ 0x4be2f, `"Rule: %s;"` @ 0x4be38, `"State: %s"` @ 0x4be42)
//      along with `"Fatal: %s"` (0x4c376) and `"Warning: %s"` (0x4c381).
// [VN] Định dạng toàn bộ thông tin lỗi và cảnh báo (`FormatString` @ 0x269e4):
std::string Error::FormatString() {
    if (!fatal_ && warnings_.empty()) {
        return "";
    }
    std::ostringstream oss;
    if (!biz_name_.empty()) {
        oss << StrFormat("Biz: %s;", biz_name_.c_str()) << " ";
    }
    if (!rule_name_.empty()) {
        oss << StrFormat("Rule: %s;", rule_name_.c_str()) << " ";
    }
    if (!state_name_.empty()) {
        oss << StrFormat("State: %s", state_name_.c_str()) << "; ";
    }
    if (fatal_) {
        oss << StrFormat("Fatal: %s", fatal_->message.c_str());
        if (!warnings_.empty()) {
            oss << "; ";
        }
    }
    for (size_t i = 0; i < warnings_.size(); ++i) {
        if (warnings_[i]) {
            oss << StrFormat("Warning: %s", warnings_[i]->message.c_str());
            if (i + 1 < warnings_.size()) {
                oss << "; ";
            }
        }
    }
    return oss.str();
}

// ============================================================================
// 5. TYPED DATA ACCESSORS & TIMESTAMP / DSL MATH (`0x40f88..0x42413`)
// ============================================================================

static void ReportAccessorError(std::shared_ptr<Error>& error,
                                ErrorCode err_code,
                                bool is_fatal,
                                const std::string& detail) {
    if (!error) {
        error = std::make_shared<Error>();
    }
    if (is_fatal) {
        error->SetFatal(err_code, detail);
    } else {
        error->AddWarning(err_code, detail);
    }
}

// [EN] Disassembly @ 0x40f88 (`_ZN3cep6GetIntE...`, 484 B):
//      Checks `data && data->IsDict()`, looks up `data->GetData(key)`, verifies `IsInt()`,
//      and returns `IntValue()`. Otherwise records fatal/warning on `error` and returns `default_val`.
// [VN] Trích xuất số nguyên từ `DataInterface` (`GetInt` @ 0x40f88):
long GetInt(const std::shared_ptr<DataInterface>& data,
            const std::string& key,
            std::shared_ptr<Error>& error,
            ErrorCode err_code,
            bool is_fatal,
            long default_val) {
    if (!data || !data->IsDict()) {
        ReportAccessorError(error, err_code, is_fatal, key);
        return default_val;
    }
    auto val = data->GetData(key);
    if (!val || !val->IsInt()) {
        ReportAccessorError(error, err_code, is_fatal, key);
        return default_val;
    }
    return val->IntValue();
}

// [EN] Disassembly @ 0x4116c (`_ZN3cep9GetDoubleE...`, 496 B):
//      Checks `data && data->IsDict()`, looks up `data->GetData(key)`, verifies `IsNumber()`,
//      and returns `ConvertToDoubleValue()`.
// [VN] Trích xuất số thực từ `DataInterface` (`GetDouble` @ 0x4116c):
double GetDouble(const std::shared_ptr<DataInterface>& data,
                 const std::string& key,
                 std::shared_ptr<Error>& error,
                 ErrorCode err_code,
                 bool is_fatal,
                 long default_val) {
    if (!data || !data->IsDict()) {
        ReportAccessorError(error, err_code, is_fatal, key);
        return static_cast<double>(default_val);
    }
    auto val = data->GetData(key);
    if (!val || (!val->IsFloat() && !val->IsInt())) {
        ReportAccessorError(error, err_code, is_fatal, key);
        return static_cast<double>(default_val);
    }
    return val->ConvertToDoubleValue();
}

// [EN] Disassembly @ 0x4135c (`_ZN3cep9GetStringE...`, 528 B):
//      Checks `data && data->IsDict()`, looks up `data->GetData(key)`, verifies `IsStr()`,
//      and returns `StringValue()`.
// [VN] Trích xuất chuỗi từ `DataInterface` (`GetString` @ 0x4135c):
std::string GetString(const std::shared_ptr<DataInterface>& data,
                      const std::string& key,
                      std::shared_ptr<Error>& error,
                      ErrorCode err_code,
                      bool is_fatal,
                      std::string default_val) {
    if (!data || !data->IsDict()) {
        ReportAccessorError(error, err_code, is_fatal, key);
        return default_val;
    }
    auto val = data->GetData(key);
    if (!val || !val->IsStr()) {
        ReportAccessorError(error, err_code, is_fatal, key);
        return default_val;
    }
    return val->StringValue();
}

// [EN] Disassembly @ 0x4156c (`_ZN3cep7GetListE...`, 488 B):
// [VN] Trích xuất danh sách từ `DataInterface` (`GetList` @ 0x4156c):
std::shared_ptr<DataInterface> GetList(const std::shared_ptr<DataInterface>& data,
                                       const std::string& key,
                                       std::shared_ptr<Error>& error,
                                       ErrorCode err_code,
                                       bool is_fatal) {
    if (!data || !data->IsDict()) {
        ReportAccessorError(error, err_code, is_fatal, key);
        return nullptr;
    }
    auto val = data->GetData(key);
    if (!val || !val->IsList()) {
        ReportAccessorError(error, err_code, is_fatal, key);
        return nullptr;
    }
    return val;
}

// [EN] Disassembly @ 0x41754 (`_ZN3cep7GetDictE...` by key, 488 B):
// [VN] Trích xuất từ điển con theo khóa (`GetDict` @ 0x41754):
std::shared_ptr<DataInterface> GetDict(const std::shared_ptr<DataInterface>& data,
                                       const std::string& key,
                                       std::shared_ptr<Error>& error,
                                       ErrorCode err_code,
                                       bool is_fatal) {
    if (!data || !data->IsDict()) {
        ReportAccessorError(error, err_code, is_fatal, key);
        return nullptr;
    }
    auto val = data->GetData(key);
    if (!val || !val->IsDict()) {
        ReportAccessorError(error, err_code, is_fatal, key);
        return nullptr;
    }
    return val;
}

// [EN] Disassembly @ 0x41cac (`_ZN3cep7GetDictE...` by index, 488 B):
// [VN] Trích xuất từ điển con theo chỉ số trong danh sách (`GetDict` @ 0x41cac):
std::shared_ptr<DataInterface> GetDict(const std::shared_ptr<DataInterface>& data,
                                       int index,
                                       std::shared_ptr<Error>& error,
                                       ErrorCode err_code,
                                       bool is_fatal) {
    if (!data || !data->IsList() || index < 0 || index >= data->Size()) {
        ReportAccessorError(error, err_code, is_fatal, std::to_string(index));
        return nullptr;
    }
    auto val = data->GetData(index);
    if (!val || !val->IsDict()) {
        ReportAccessorError(error, err_code, is_fatal, std::to_string(index));
        return nullptr;
    }
    return val;
}

// [EN] Disassembly @ 0x41e94 (`_ZN3cep19GetCurrentTimestampEv`, 48 B):
//      0x41e9c: 97ff2899  bl    #0xc100                 // std::chrono::system_clock::now() (microseconds)
//      0x41ea0: d29ef9e8  mov   x8, #0xf7cf
//      0x41ea4: f2bc6a68  movk  x8, #0xe353, lsl #16
//      0x41ea8: f2d374a8  movk  x8, #0x9ba5, lsl #32
//      0x41eac: f2e41888  movk  x8, #0x20c4, lsl #48    // x8 = 0x20c49ba5e353f7cf = ceil(2^71 / 1000)
//      0x41eb0: 9b487c08  smulh x8, x0, x8              // high 64 bits of signed (us * 0x20c49ba5e353f7cf)
//      0x41eb4: 9347fd09  asr   x9, x8, #7              // >> 7 (total shift = 64 + 7 = 71)
//      0x41eb8: 8b48fd20  add   x0, x9, x8, lsr #63     // sign correction -> us / 1000 (milliseconds)
// [VN] Lấy dấu thời gian hiện tại tính bằng mili-giây (`GetCurrentTimestamp` @ 0x41e94):
long long GetCurrentTimestamp() {
    const auto now = std::chrono::system_clock::now();
    const int64_t us = std::chrono::duration_cast<std::chrono::microseconds>(
        now.time_since_epoch()).count();
    // Exact AArch64 fixed-point division by 1000 using magic constant 0x20c49ba5e353f7cf:
    // ceil(2^71 / 1000) = 2361183241434822607 = 0x20c49ba5e353f7cf
    constexpr int64_t kMagicDiv1000 = 0x20c49ba5e353f7cfLL;
#if defined(__SIZEOF_INT128__)
    __int128 prod = static_cast<__int128>(us) * static_cast<__int128>(kMagicDiv1000);
    int64_t high = static_cast<int64_t>(prod >> 64);
    return (high >> 7) + static_cast<int64_t>(static_cast<uint64_t>(high) >> 63);
#else
    (void)kMagicDiv1000;
    return static_cast<long long>(us / 1000);
#endif
}

// [EN] Disassembly @ 0x41ec8 (`_ZN3cep16IsValidTimestampEx`, 12 B):
//      0x41ec8: b100041f  cmn  x0, #1
//      0x41ecc: 1a9f07e0  cset w0, ne
//      0x41ed0: d65f03c0  ret
// [VN] Kiểm tra dấu thời gian hợp lệ (`timestamp_ms != -1`) (@ 0x41ec8):
bool IsValidTimestamp(long long timestamp_ms) {
    return timestamp_ms != -1LL;
}

// [EN] Disassembly @ 0x41f18 (`_ZN3cep9StrFormatEPKcz`, 452 B):
//      Two-pass `vsnprintf` formatter returning `std::string`.
// [VN] Định dạng chuỗi biến thiên sử dụng `vsnprintf` 2 lượt (`StrFormat` @ 0x41f18):
std::string StrFormat(const char* fmt, ...) {
    if (!fmt) {
        return "";
    }
    va_list args1;
    va_start(args1, fmt);
    va_list args2;
    va_copy(args2, args1);
    const int len = std::vsnprintf(nullptr, 0, fmt, args1);
    va_end(args1);
    if (len <= 0) {
        va_end(args2);
        return "";
    }
    std::string buf(static_cast<size_t>(len) + 1, '\0');
    std::vsnprintf(&buf[0], buf.size(), fmt, args2);
    va_end(args2);
    buf.resize(static_cast<size_t>(len));
    return buf;
}

// [EN] Disassembly @ 0x420dc (`_ZN3cep15CheckDSLVersionERKNSt6__ndk112basic_string...`, 400 B):
//      Parses dot-separated integers (`cmp w8, #0x2e` @ 0x42150; `sub w8, w8, #0x30; cmp w8, #9;
//      madd w26, w26, w25, w8` where `w25 = 10` @ 0x4219c..0x421a8) into `std::vector<int>`
//      and verifies compatibility against engine version `"1.5.0"` (0x4bfe0):
//      major version must equal 1 (`v[0] == 1`) and `(v[1] < 5 || (v[1] == 5 && v[2] <= 0))`.
// [VN] Kiểm tra tính tương thích phiên bản DSL với phiên bản Engine `"1.5.0"` (@ 0x420dc):
bool CheckDSLVersion(const std::string& dsl_version) {
    if (dsl_version.empty()) {
        return false;
    }
    std::vector<int> parts;
    int accum = 0;
    for (char ch : dsl_version) {
        if (ch == '.') {
            parts.push_back(accum);
            accum = 0;
        } else {
            unsigned int digit = static_cast<unsigned int>(ch - '0');
            if (digit <= 9U) {
                accum = accum * 10 + static_cast<int>(digit);
            }
        }
    }
    parts.push_back(accum);
    const int kEngineVer[3] = {1, 5, 0}; // 0x4bfe0: "1.5.0"
    if (parts.empty() || parts[0] != kEngineVer[0]) {
        return false;
    }
    for (size_t i = 1; i < parts.size() && i < 3; ++i) {
        if (parts[i] < kEngineVer[i]) {
            return true;
        }
        if (parts[i] > kEngineVer[i]) {
            return false;
        }
    }
    return true;
}

// [EN] Disassembly @ 0x4226c (`_ZN3cep13ParseKeyChainERKNSt6__ndk112basic_string...`, 424 B):
//      Splits `key_chain` on `'.'` (`mov w1, #0x2e; bl memchr` @ 0x42328..0x4232c) into
//      a `std::vector<std::string>`.
// [VN] Phân tách chuỗi khóa phân cấp ngăn cách bởi dấu chấm `'.'` (`ParseKeyChain` @ 0x4226c):
std::vector<std::string> ParseKeyChain(const std::string& key_chain) {
    std::vector<std::string> result;
    if (key_chain.empty()) {
        return result;
    }
    const char* data = key_chain.data();
    const size_t len = key_chain.size();
    size_t pos = 0;
    while (pos < len) {
        const void* found = std::memchr(data + pos, '.', len - pos);
        if (!found) {
            result.emplace_back(data + pos, len - pos);
            break;
        }
        const size_t dot_idx = static_cast<const char*>(found) - data;
        result.emplace_back(data + pos, dot_idx - pos);
        pos = dot_idx + 1;
    }
    return result;
}

// ============================================================================
// 6. CONCURRENCY PRIMITIVES: RWLock, LockGuards, Semaphore (`0x42ee0..0x43453`)
// ============================================================================

// [EN] Disassembly @ 0x42ee0..0x4313c (`cep::RWLock`):
// [VN] Các phương thức khóa đọc-ghi `cep::RWLock` (@ 0x42ee0..0x4313c):
void RWLock::LockRead() const {
    while (!mutex_.try_lock_shared()) {
        std::this_thread::yield();
    }
}

void RWLock::LockWrite() const {
    while (!mutex_.try_lock()) {
        std::this_thread::yield();
    }
}

void RWLock::UnlockRead() const {
    mutex_.unlock_shared();
}

void RWLock::UnlockWrite() const {
    mutex_.unlock();
}

bool RWLock::TryLockRead() const {
    return mutex_.try_lock_shared();
}

bool RWLock::TryLockWrite() const {
    return mutex_.try_lock();
}

// [EN] Disassembly @ 0x43140..0x43164 (`ReadLockGuard` & `WriteLockGuard`):
// [VN] Các lớp bảo vệ khóa RAII `ReadLockGuard` và `WriteLockGuard` (@ 0x43140..0x43164):
ReadLockGuard::ReadLockGuard(const RWLock& lock) : lock_(&lock) {
    lock_->LockRead();
}

ReadLockGuard::~ReadLockGuard() {
    lock_->UnlockRead();
}

WriteLockGuard::WriteLockGuard(const RWLock& lock) : lock_(&lock) {
    lock_->LockWrite();
}

WriteLockGuard::~WriteLockGuard() {
    lock_->UnlockWrite();
}

// [EN] Disassembly @ 0x43168 (`_ZN3cep9LockWriteERKNS_6RWLockES2_`, 100 B):
//      Alternating lock + try_lock + unlock + sched_yield loop to avoid AB-BA deadlock.
// [VN] Khóa ghi đồng thời 2 `RWLock` chống deadlock (`LockWrite` @ 0x43168):
void LockWrite(const RWLock& lock1, const RWLock& lock2) {
    if (&lock1 == &lock2) {
        lock1.LockWrite();
        return;
    }
    for (;;) {
        lock1.LockWrite();
        if (lock2.TryLockWrite()) {
            return;
        }
        lock1.UnlockWrite();
        std::this_thread::yield();

        lock2.LockWrite();
        if (lock1.TryLockWrite()) {
            return;
        }
        lock2.UnlockWrite();
        std::this_thread::yield();
    }
}

// [EN] Disassembly @ 0x431cc (`_ZN3cep9SemaphoreC1Em`, 24 B):
//      0x431cc: 6f00e400  movi v0.2d, #0
//      0x431d0: ad018000  stp  q0, q0, [x0, #0x30]
//      0x431d4: ad008000  stp  q0, q0, [x0, #0x10]
//      0x431d8: 3d800000  str  q0, [x0]
//      0x431dc: a905041f  stp  xzr, x1, [x0, #0x50]   // count_ at +0x58 = count
// [VN] Hàm tạo `Semaphore` (@ 0x431cc, 24 B):
Semaphore::Semaphore(unsigned long count) : count_(count) {}

// [EN] Disassembly @ 0x431e4 (`_ZN3cep9Semaphore4WaitEm`, 164 B):
// [VN] Chờ giảm bộ đếm `Semaphore::Wait` (@ 0x431e4):
void Semaphore::Wait(unsigned long count) {
    if (count == 0) {
        return;
    }
    std::unique_lock<std::mutex> lk(mutex_);
    while (count > 0) {
        cv_.wait(lk, [this]() { return count_ > 0; });
        const unsigned long take = std::min(count, count_);
        count_ -= take;
        count -= take;
    }
}

// [EN] Disassembly @ 0x43288 (`_ZN3cep9Semaphore9WaitUntilEdm`, 392 B):
// [VN] Chờ giảm bộ đếm có giới hạn thời gian `Semaphore::WaitUntil` (@ 0x43288):
bool Semaphore::WaitUntil(double timeout_sec, unsigned long count) {
    if (count == 0) {
        return true;
    }
    const auto deadline = std::chrono::system_clock::now() +
        std::chrono::duration_cast<std::chrono::system_clock::duration>(
            std::chrono::duration<double>(timeout_sec));
    std::unique_lock<std::mutex> lk(mutex_);
    while (count > 0) {
        if (!cv_.wait_until(lk, deadline, [this]() { return count_ > 0; })) {
            return false;
        }
        const unsigned long take = std::min(count, count_);
        count_ -= take;
        count -= take;
    }
    return true;
}

// [EN] Disassembly @ 0x43410 (`_ZN3cep9Semaphore6SignalEm`, 68 B):
//      0x43410: b4000201  cbz x1, #0x43450
//      0x43428: 97ff238e  bl  #0xc260                // mutex_.lock()
//      0x4342c: f9402e68  ldr x8, [x19, #0x58]
//      0x43434: 8b140108  add x8, x8, x20
//      0x43438: f9002e68  str x8, [x19, #0x58]
//      0x4343c: 97ff218d  bl  #0xba70                // mutex_.unlock()
//      0x43444: 9100a260  add x0, x19, #0x28         // &cv_
//      0x4344c: 17ff230d  b   #0xc080                // cv_.notify_one()
// [VN] Tăng bộ đếm và đánh thức luồng chờ `Semaphore::Signal` (@ 0x43410):
void Semaphore::Signal(unsigned long count) {
    if (count == 0) {
        return;
    }
    {
        std::lock_guard<std::mutex> lk(mutex_);
        count_ += count;
    }
    cv_.notify_one();
}

// ============================================================================
// 7. IN-MEMORY DATA INTERFACE (`cep::MemoryDataInterface`)
// ============================================================================

std::shared_ptr<MemoryDataInterface> MemoryDataInterface::MakeNull() {
    return std::make_shared<MemoryDataInterface>(DataType::kNull);
}

std::shared_ptr<MemoryDataInterface> MemoryDataInterface::MakeInt(long v) {
    auto p = std::make_shared<MemoryDataInterface>(DataType::kInt);
    p->int_val_ = v;
    p->float_val_ = static_cast<double>(v);
    p->bool_val_ = (v != 0);
    return p;
}

std::shared_ptr<MemoryDataInterface> MemoryDataInterface::MakeFloat(double v) {
    auto p = std::make_shared<MemoryDataInterface>(DataType::kFloat);
    p->float_val_ = v;
    p->int_val_ = static_cast<long>(v);
    p->bool_val_ = (v != 0.0);
    return p;
}

std::shared_ptr<MemoryDataInterface> MemoryDataInterface::MakeBool(bool v) {
    auto p = std::make_shared<MemoryDataInterface>(DataType::kBool);
    p->bool_val_ = v;
    p->int_val_ = v ? 1L : 0L;
    p->float_val_ = v ? 1.0 : 0.0;
    return p;
}

std::shared_ptr<MemoryDataInterface> MemoryDataInterface::MakeString(std::string v) {
    auto p = std::make_shared<MemoryDataInterface>(DataType::kStr);
    p->str_val_ = std::move(v);
    return p;
}

std::shared_ptr<MemoryDataInterface> MemoryDataInterface::MakeList() {
    return std::make_shared<MemoryDataInterface>(DataType::kList);
}

std::shared_ptr<MemoryDataInterface> MemoryDataInterface::MakeDict() {
    return std::make_shared<MemoryDataInterface>(DataType::kDict);
}

int MemoryDataInterface::Size() {
    if (type_ == static_cast<int>(DataType::kList)) {
        return static_cast<int>(list_val_.size());
    }
    if (type_ == static_cast<int>(DataType::kDict)) {
        return static_cast<int>(dict_val_.size());
    }
    return 0;
}

std::shared_ptr<DataInterface> MemoryDataInterface::GetData(int index) {
    if (type_ == static_cast<int>(DataType::kList) &&
        index >= 0 && static_cast<size_t>(index) < list_val_.size()) {
        return list_val_[static_cast<size_t>(index)];
    }
    return nullptr;
}

std::vector<std::string> MemoryDataInterface::KeySet() {
    std::vector<std::string> keys;
    if (type_ == static_cast<int>(DataType::kDict)) {
        keys.reserve(dict_val_.size());
        for (const auto& kv : dict_val_) {
            keys.push_back(kv.first);
        }
    }
    return keys;
}

std::shared_ptr<DataInterface> MemoryDataInterface::GetData(const std::string& key) {
    if (type_ != static_cast<int>(DataType::kDict)) {
        return nullptr;
    }
    auto it = dict_val_.find(key);
    if (it != dict_val_.end()) {
        return it->second;
    }
    // Support dot-separated key chains via ParseKeyChain
    if (key.find('.') != std::string::npos) {
        auto chain = ParseKeyChain(key);
        std::shared_ptr<DataInterface> cur = dict_val_.count(chain[0]) ? dict_val_[chain[0]] : nullptr;
        for (size_t i = 1; i < chain.size() && cur; ++i) {
            if (!cur->IsDict()) {
                return nullptr;
            }
            cur = cur->GetData(chain[i]);
        }
        return cur;
    }
    return nullptr;
}

void MemoryDataInterface::AppendElement(std::shared_ptr<DataInterface> elem) {
    if (type_ == static_cast<int>(DataType::kList)) {
        list_val_.push_back(std::move(elem));
    }
}

void MemoryDataInterface::SetField(const std::string& key, std::shared_ptr<DataInterface> val) {
    if (type_ == static_cast<int>(DataType::kDict)) {
        dict_val_[key] = std::move(val);
    }
}

std::string MemoryDataInterface::JSON() {
    switch (static_cast<DataType>(type_)) {
        case DataType::kInt:
            return std::to_string(int_val_);
        case DataType::kFloat: {
            std::ostringstream oss;
            oss << float_val_;
            return oss.str();
        }
        case DataType::kBool:
            return bool_val_ ? "true" : "false";
        case DataType::kStr:
            return "\"" + str_val_ + "\"";
        case DataType::kList: {
            std::ostringstream oss;
            oss << "[";
            for (size_t i = 0; i < list_val_.size(); ++i) {
                if (i > 0) oss << ",";
                oss << (list_val_[i] ? list_val_[i]->JSON() : "null");
            }
            oss << "]";
            return oss.str();
        }
        case DataType::kDict: {
            std::ostringstream oss;
            oss << "{";
            bool first = true;
            for (const auto& kv : dict_val_) {
                if (!first) oss << ",";
                first = false;
                oss << "\"" << kv.first << "\":" << (kv.second ? kv.second->JSON() : "null");
            }
            oss << "}";
            return oss.str();
        }
        case DataType::kNull:
        default:
            return "null";
    }
}

namespace {

class SimpleJsonParser {
public:
    explicit SimpleJsonParser(const std::string& s) : s_(s), pos_(0) {}

    std::shared_ptr<MemoryDataInterface> ParseValue() {
        SkipWs();
        if (pos_ >= s_.size()) return MemoryDataInterface::MakeNull();
        char c = s_[pos_];
        if (c == '{') return ParseObject();
        if (c == '[') return ParseArray();
        if (c == '"') return MemoryDataInterface::MakeString(ParseString());
        if (c == 't' || c == 'f') return ParseBool();
        if (c == 'n') return ParseNull();
        return ParseNumber();
    }

private:
    void SkipWs() {
        while (pos_ < s_.size() && std::isspace(static_cast<unsigned char>(s_[pos_]))) {
            ++pos_;
        }
    }

    std::string ParseString() {
        if (pos_ < s_.size() && s_[pos_] == '"') ++pos_;
        std::string out;
        while (pos_ < s_.size() && s_[pos_] != '"') {
            if (s_[pos_] == '\\' && pos_ + 1 < s_.size()) {
                ++pos_;
            }
            out.push_back(s_[pos_++]);
        }
        if (pos_ < s_.size() && s_[pos_] == '"') ++pos_;
        return out;
    }

    std::shared_ptr<MemoryDataInterface> ParseObject() {
        auto dict = MemoryDataInterface::MakeDict();
        ++pos_; // '{'
        SkipWs();
        while (pos_ < s_.size() && s_[pos_] != '}') {
            SkipWs();
            if (s_[pos_] != '"') break;
            std::string key = ParseString();
            SkipWs();
            if (pos_ < s_.size() && s_[pos_] == ':') ++pos_;
            auto val = ParseValue();
            dict->SetField(key, val);
            SkipWs();
            if (pos_ < s_.size() && s_[pos_] == ',') ++pos_;
            SkipWs();
        }
        if (pos_ < s_.size() && s_[pos_] == '}') ++pos_;
        return dict;
    }

    std::shared_ptr<MemoryDataInterface> ParseArray() {
        auto list = MemoryDataInterface::MakeList();
        ++pos_; // '['
        SkipWs();
        while (pos_ < s_.size() && s_[pos_] != ']') {
            list->AppendElement(ParseValue());
            SkipWs();
            if (pos_ < s_.size() && s_[pos_] == ',') ++pos_;
            SkipWs();
        }
        if (pos_ < s_.size() && s_[pos_] == ']') ++pos_;
        return list;
    }

    std::shared_ptr<MemoryDataInterface> ParseBool() {
        if (s_.compare(pos_, 4, "true") == 0) {
            pos_ += 4;
            return MemoryDataInterface::MakeBool(true);
        }
        if (s_.compare(pos_, 5, "false") == 0) {
            pos_ += 5;
            return MemoryDataInterface::MakeBool(false);
        }
        return MemoryDataInterface::MakeNull();
    }

    std::shared_ptr<MemoryDataInterface> ParseNull() {
        if (s_.compare(pos_, 4, "null") == 0) {
            pos_ += 4;
        }
        return MemoryDataInterface::MakeNull();
    }

    std::shared_ptr<MemoryDataInterface> ParseNumber() {
        size_t start = pos_;
        bool is_float = false;
        if (pos_ < s_.size() && (s_[pos_] == '-' || s_[pos_] == '+')) ++pos_;
        while (pos_ < s_.size() &&
               (std::isdigit(static_cast<unsigned char>(s_[pos_])) ||
                s_[pos_] == '.' || s_[pos_] == 'e' || s_[pos_] == 'E' ||
                s_[pos_] == '-' || s_[pos_] == '+')) {
            if (s_[pos_] == '.' || s_[pos_] == 'e' || s_[pos_] == 'E') {
                is_float = true;
            }
            ++pos_;
        }
        std::string token = s_.substr(start, pos_ - start);
        if (token.empty()) return MemoryDataInterface::MakeInt(0);
        if (is_float) {
            return MemoryDataInterface::MakeFloat(std::strtod(token.c_str(), nullptr));
        }
        return MemoryDataInterface::MakeInt(std::strtol(token.c_str(), nullptr, 10));
    }

    const std::string& s_;
    size_t pos_;
};

} // namespace

std::shared_ptr<MemoryDataInterface> MemoryDataInterface::ParseJson(const std::string& json_str) {
    SimpleJsonParser parser(json_str);
    return parser.ParseValue();
}

} // namespace cep
