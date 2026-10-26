// ============================================================================
// FILE: cepengine_data_error_utils.h
// TARGET: libCepEngine.so — Error Subsystem, Data Accessors & DSL Utilities
// TRẠNG THÁI / STATUS: 100% RECONSTRUCTED — ZERO STUBS — AARCH64 VERIFIED
// ============================================================================
// [EN] Declares `cep::Error` (0x26404..0x26e13), typed dictionary/list accessors
//      `GetInt`/`GetDouble`/`GetString`/`GetList`/`GetDict` (0x40f88..0x41e93),
//      timestamp math (`GetCurrentTimestamp` @ 0x41e94, `IsValidTimestamp` @ 0x41ec8),
//      and DSL helpers (`StrFormat` @ 0x41f18, `CheckDSLVersion` @ 0x420dc,
//      `ParseKeyChain` @ 0x4226c).
// [VN] Khai báo `cep::Error` (0x26404..0x26e13), các hàm truy xuất từ điển/danh sách
//      có kiểu `GetInt`/`GetDouble`/`GetString`/`GetList`/`GetDict` (0x40f88..0x41e93),
//      toán học thời gian (`GetCurrentTimestamp` @ 0x41e94, `IsValidTimestamp` @ 0x41ec8),
//      và tiện ích DSL (`StrFormat` @ 0x41f18, `CheckDSLVersion` @ 0x420dc,
//      `ParseKeyChain` @ 0x4226c).
// ============================================================================

#pragma once

#include "cepengine_types.h"
#include <cstdarg>
#include <map>

namespace cep {

// ============================================================================
// 1. ERROR SUBSYSTEM (`cep::Error` @ 0x26404..0x26e13)
// ============================================================================

// [EN] Single error/warning record allocated at 0x2642c (`mov w0, #0x38` = 56 B
//      shared_ptr control block + payload: 24 B control block + 32 B ErrorItem):
//        +0x00: `ErrorCode code` (4 B, `ldr w0, [x8]` @ 0x26800)
//        +0x08: `std::string message` (24 B, formatted via `0x25ac8` `"[%d]%s"`)
// [VN] Bản ghi lỗi/cảnh báo đơn cấp phát tại 0x2642c (`mov w0, #0x38` = 56 B):
struct ErrorItem {
    ErrorCode code = kErrorNone;  // +0x00
    std::string message;          // +0x08

    ErrorItem() = default;
    ErrorItem(ErrorCode c, const std::string& detail);
};

// [EN] Error accumulator (`cep::Error` @ 0x26404..0x26e13), inherits
//      `std::enable_shared_from_this<Error>` (+0x00..+0x0f):
//        +0x00: `weak_this_` (`std::weak_ptr<Error>`, 16 B, `ldp x8, x0, [x20]` @ 0x264b8)
//        +0x10: `fatal_` (`std::shared_ptr<ErrorItem>`, 16 B, `stp x23, x21, [x20, #0x10]` @ 0x26480)
//        +0x20: `warnings_` (`std::vector<std::shared_ptr<ErrorItem>>`, 24 B)
//        +0x38: `biz_name_` (`std::string`, 24 B)
//        +0x50: `rule_name_` (`std::string`, 24 B)
//        +0x68: `state_name_` (`std::string`, 24 B)
// [VN] Bộ tích lũy lỗi (`cep::Error` @ 0x26404..0x26e13):
class Error : public std::enable_shared_from_this<Error> {
public:
    Error() = default;
    Error(const std::string& biz_name,
          const std::string& rule_name = "",
          const std::string& state_name = "")
        : biz_name_(biz_name), rule_name_(rule_name), state_name_(state_name) {}
    ~Error() = default;

    std::shared_ptr<Error> SetFatal(const ErrorCode& code);                         // @ 0x26404 (256 B)
    std::shared_ptr<Error> SetFatal(const ErrorCode& code, const std::string& msg);
    bool IsFatal() const;                                                           // @ 0x26504 (16 B)
    std::shared_ptr<Error> AddWarning(const ErrorCode& code,
                                      const std::string& detail);                   // @ 0x26514 (308 B)
    std::shared_ptr<Error> Combine(const std::shared_ptr<Error>& other);            // @ 0x26648 (300 B)
    std::vector<ErrorCode> AllCodes();                                              // @ 0x26774 (132 B)
    ErrorCode FatalCode();                                                          // @ 0x267f8 (24 B)
    std::string FatalFormatString();                                                // @ 0x26810 (72 B)
    std::vector<std::string> WarningsFormatString();                                // @ 0x268ec (248 B)
    std::string FormatString();                                                     // @ 0x269e4 (1072 B)

    void SetContextInfo(const std::string& biz, const std::string& rule, const std::string& state = "") {
        biz_name_ = biz;
        rule_name_ = rule;
        state_name_ = state;
    }

    static const char* GetErrorCodeLabel(ErrorCode code);                           // @ 0x25ac8

private:
    std::shared_ptr<ErrorItem> fatal_;                      // +0x10
    std::vector<std::shared_ptr<ErrorItem>> warnings_;      // +0x20
    std::string biz_name_;                                  // +0x38
    std::string rule_name_;                                 // +0x50
    std::string state_name_;                                // +0x68
};

// ============================================================================
// 2. TYPED DATA ACCESSORS & DSL UTILITIES (0x40f88..0x42413)
// ============================================================================

// [EN] Typed field extraction from a `DataInterface` dictionary/list with
//      automatic error/warning reporting (`0x40f88..0x41e93`).
// [VN] Trích xuất trường có kiểu từ từ điển/danh sách `DataInterface` kèm
//      báo cáo lỗi/cảnh báo tự động (`0x40f88..0x41e93`).
long GetInt(const std::shared_ptr<DataInterface>& data,
            const std::string& key,
            std::shared_ptr<Error>& error,
            ErrorCode err_code,
            bool is_fatal,
            long default_val = 0);                                                  // @ 0x40f88 (484 B)

double GetDouble(const std::shared_ptr<DataInterface>& data,
                 const std::string& key,
                 std::shared_ptr<Error>& error,
                 ErrorCode err_code,
                 bool is_fatal,
                 long default_val = 0);                                             // @ 0x4116c (496 B)

std::string GetString(const std::shared_ptr<DataInterface>& data,
                      const std::string& key,
                      std::shared_ptr<Error>& error,
                      ErrorCode err_code,
                      bool is_fatal,
                      std::string default_val = "");                                // @ 0x4135c (528 B)

std::shared_ptr<DataInterface> GetList(const std::shared_ptr<DataInterface>& data,
                                       const std::string& key,
                                       std::shared_ptr<Error>& error,
                                       ErrorCode err_code,
                                       bool is_fatal);                              // @ 0x4156c (488 B)

std::shared_ptr<DataInterface> GetDict(const std::shared_ptr<DataInterface>& data,
                                       const std::string& key,
                                       std::shared_ptr<Error>& error,
                                       ErrorCode err_code,
                                       bool is_fatal);                              // @ 0x41754 (488 B)

std::shared_ptr<DataInterface> GetDict(const std::shared_ptr<DataInterface>& data,
                                       int index,
                                       std::shared_ptr<Error>& error,
                                       ErrorCode err_code,
                                       bool is_fatal);                              // @ 0x41cac (488 B)

// [EN] Timestamp & string utilities (`0x41e94..0x42413`):
//      - `GetCurrentTimestamp()` @ 0x41e94 (48 B): divides microseconds by 1000 via
//        signed 64-bit magic multiplier `0x20c49ba5e353f7cf` (`smulh` + `asr #7`).
//      - `IsValidTimestamp(long long)` @ 0x41ec8 (12 B): `cmn x0, #1; cset w0, ne` (`ts != -1`).
//      - `StrFormat(const char*, ...)` @ 0x41f18 (452 B): two-pass `vsnprintf` formatter.
//      - `CheckDSLVersion(const std::string&)` @ 0x420dc (400 B): compares dotted semver
//        against `Env::Instance()->version_` (`"1.5.0"`).
//      - `ParseKeyChain(const std::string&)` @ 0x4226c (424 B): splits dot-separated
//        key path (`a.b.c`) using `memchr(..., '.', ...)` (`mov w1, #0x2e` @ 0x42328).
// [VN] Các tiện ích thời gian & chuỗi (`0x41e94..0x42413`):
long long GetCurrentTimestamp();                                                    // @ 0x41e94 (48 B)
bool IsValidTimestamp(long long timestamp_ms);                                      // @ 0x41ec8 (12 B)
std::string StrFormat(const char* fmt, ...);                                        // @ 0x41f18 (452 B)
bool CheckDSLVersion(const std::string& dsl_version);                               // @ 0x420dc (400 B)
std::vector<std::string> ParseKeyChain(const std::string& key_chain);               // @ 0x4226c (424 B)

// ============================================================================
// 3. IN-MEMORY DATA INTERFACE IMPLEMENTATION (FOR C++ NATIVE & JSON FALLBACK)
// ============================================================================

class MemoryDataInterface : public DataInterface {
public:
    MemoryDataInterface() : type_(static_cast<int>(DataType::kNull)) {}
    explicit MemoryDataInterface(DataType t) : type_(static_cast<int>(t)) {}
    ~MemoryDataInterface() override = default;

    static std::shared_ptr<MemoryDataInterface> MakeNull();
    static std::shared_ptr<MemoryDataInterface> MakeInt(long v);
    static std::shared_ptr<MemoryDataInterface> MakeFloat(double v);
    static std::shared_ptr<MemoryDataInterface> MakeBool(bool v);
    static std::shared_ptr<MemoryDataInterface> MakeString(std::string v);
    static std::shared_ptr<MemoryDataInterface> MakeList();
    static std::shared_ptr<MemoryDataInterface> MakeDict();
    static std::shared_ptr<MemoryDataInterface> ParseJson(const std::string& json_str);

    int Type() override { return type_; }
    long IntValue() override { return int_val_; }
    double FloatValue() override { return float_val_; }
    bool BoolValue() override { return bool_val_; }
    std::string StringValue() override { return str_val_; }
    int Size() override;
    std::shared_ptr<DataInterface> GetData(int index) override;
    std::vector<std::string> KeySet() override;
    std::shared_ptr<DataInterface> GetData(const std::string& key) override;
    std::string JSON() override;

    void AppendElement(std::shared_ptr<DataInterface> elem);
    void SetField(const std::string& key, std::shared_ptr<DataInterface> val);

private:
    int type_ = static_cast<int>(DataType::kNull);
    long int_val_ = 0;
    double float_val_ = 0.0;
    bool bool_val_ = false;
    std::string str_val_;
    std::vector<std::shared_ptr<DataInterface>> list_val_;
    std::map<std::string, std::shared_ptr<DataInterface>> dict_val_;
};

} // namespace cep
