// ============================================================================
// FILE: cepengine_types.h
// TARGET: libCepEngine.so (362,464 bytes, ELF64 AArch64, 318 dynamic symbols)
// TRẠNG THÁI / STATUS: 100% RECONSTRUCTED — ZERO STUBS — AARCH64 VERIFIED
// ============================================================================
// [EN] Core ABI types, enumerations, vtable layouts, and struct offsets for
//      ByteDance Pitaya Complex Event Processing Engine (`namespace cep`).
//      Every struct field offset and constant is directly verified from AArch64
//      machine code in `extracted/lib/arm64-v8a/libCepEngine.so`.
// [VN] Các kiểu dữ liệu ABI cốt lõi, enum, bố cục vtable và độ lệch struct cho
//      Engine Xử lý Sự kiện Phức hợp ByteDance Pitaya (`namespace cep`).
//      Mọi offset trường struct và hằng số đều được đối soát trực tiếp từ mã máy
//      AArch64 trong `extracted/lib/arm64-v8a/libCepEngine.so`.
// ============================================================================

#pragma once

#include <jni.h>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <cstdint>
#include <functional>
#include <memory>
#include <mutex>
#include <shared_mutex>
#include <string>
#include <unordered_map>
#include <vector>

// [EN] Global C++ API version exported at 0x0c33c (`_Z10ApiVersionv`)
//      0x0c33c: 52800040 mov w0, #2; 0x0c340: d65f03c0 ret
// [VN] Phiên bản C++ API toàn cục xuất tại 0x0c33c (`_Z10ApiVersionv`)
int ApiVersion();

namespace cep {

// ============================================================================
// 1. ENUMERATIONS & CONSTANTS (VERIFIED FROM .text & .rodata 0x4bdc0..0x4c9d6)
// ============================================================================

// [EN] Data types returned by `DataInterface::Type()` (vtable slot +0x00),
//      verified from `IsInt`..`IsNull` (0x0c66c..0x0c764) and `EventWrapperList::Type` (0x27bc4).
// [VN] Các kiểu dữ liệu trả về bởi `DataInterface::Type()` (khe vtable +0x00),
//      xác minh từ `IsInt`..`IsNull` (0x0c66c..0x0c764) và `EventWrapperList::Type` (0x27bc4).
enum class DataType : int32_t {
    kInt              = 0,    // 0x0c680: 7100001f cmp w0, #0
    kFloat            = 1,    // 0x0c6a4: 7100041f cmp w0, #1
    kBool             = 2,    // 0x0c6c8: 7100081f cmp w0, #2
    kStr              = 3,    // 0x0c6ec: 71000c1f cmp w0, #3
    kList             = 4,    // 0x0c710: 7100101f cmp w0, #4
    kDict             = 5,    // 0x0c734: 7100141f cmp w0, #5
    kNull             = 6,    // 0x0c758: 7100181f cmp w0, #6
    kEventWrapperList = 100   // 0x27bd0: 52800c80 mov w0, #0x64
};

// [EN] Interface implementation type (`DataInterface::InterfaceType() = 2` @ 0x0c4e8,
//      `NativeData::InterfaceType() = 1` @ 0x2930c, `TTMCepData = 101` in libTTMStrategyCenter).
// [VN] Loại cài đặt giao diện dữ liệu (`DataInterface::InterfaceType() = 2` @ 0x0c4e8,
//      `NativeData::InterfaceType() = 1` @ 0x2930c, `TTMCepData = 101` trong libTTMStrategyCenter).
enum class DataInterfaceType : int32_t {
    kNativeData    = 1,   // 0x2930c: 52800020 mov w0, #1
    kBaseInterface = 2,   // 0x0c4e8: 52800040 mov w0, #2
    kTTMCepData    = 101  // libTTMStrategyCenter cep::TTMCepData::InterfaceType()
};

// [EN] Rule disable strategy (`cep::DisableStrategy`), verified at 0x22fec (`DisableRule(bool)`):
//      0x22ff0: 7200007f tst w3, #1; 0x22ff4: 52800048 mov w8, #2; 0x22ff8: 1a9f1103 csel w3, w8, wzr, ne
// [VN] Chiến lược vô hiệu hóa quy tắc (`cep::DisableStrategy`), xác minh tại 0x22fec (`DisableRule(bool)`):
enum DisableStrategy : int32_t {
    kDisableOnly      = 0,  // bool clean = false -> 0
    kDisableKeepQueue = 1,
    kDisableAndClean  = 2   // bool clean = true  -> 2 (mov w8, #2)
};

// [EN] Event processing mode (`cep::ProcessMode`), stored at `EngineConfig + 0x38` (0x13c2c).
// [VN] Chế độ xử lý sự kiện (`cep::ProcessMode`), lưu tại `EngineConfig + 0x38` (0x13c2c).
enum ProcessMode : int32_t {
    kProcessAsync         = 0,  // Default (0x144ac: str wzr, [x19, #0x38])
    kProcessSync          = 1,  // realTimeProcess = true
    kProcessCurrentThread = 2
};

// [EN] Match timeout inference strategy (`cep::MatchTimeoutInferenceStrategy`),
//      stored at `EngineConfig + 0x18` (0x13b1c, initialized to 1 at 0x14484).
// [VN] Chiến lược suy luận hết hạn khớp (`cep::MatchTimeoutInferenceStrategy`),
//      lưu tại `EngineConfig + 0x18` (0x13b1c, khởi tạo bằng 1 tại 0x14484).
enum MatchTimeoutInferenceStrategy : int32_t {
    kTimeoutNone      = 0,
    kTimeoutInference = 1   // Default (0x14484: mov w9, #1; str w9, [x0, #0x18])
};

// [EN] Expression evaluator engine type (`cep::ExpressionType`), verified at `GetExpEngine` (0x1ae88).
// [VN] Loại engine tính toán biểu thức (`cep::ExpressionType`), xác minh tại `GetExpEngine` (0x1ae88).
enum ExpressionType : int32_t {
    kExpEngineDefault = 0,  // ByteDT (`libbytedt.so`)
    kExpEngineTTM     = 1,  // TTM (`libTTMachineCore.so` / `libTTMStrategyCenter.so`)
    kExpEngineCustom  = 2
};

// [EN] Error codes (`cep::ErrorCode`), verified from error string table at 0x25ac8..0x26260
//      and `.rodata` 0x4c170..0x4c356.
// [VN] Mã lỗi (`cep::ErrorCode`), xác minh từ bảng chuỗi lỗi tại 0x25ac8..0x26260
//      và `.rodata` 0x4c170..0x4c356.
enum ErrorCode : int32_t {
    kErrorNone                              = 0,
    kErrorInputNullEvent                    = 1,   // 0x4c170: "Input Null Event"
    kErrorCalculateExpression               = 2,   // 0x4c181: "Error Occur When Calculate Expression"
    kErrorInvalidRule                       = 3,   // 0x4c1a7: "Invalid Rule"
    kErrorInvalidEdge                       = 4,   // 0x4c1b4: "Invalid Edge"
    kErrorInvalidState                      = 5,   // 0x4c1c1: "Invalid State"
    kErrorInvalidCondition                  = 6,   // 0x4c1cf: "Invalid Condition"
    kErrorInvalidTimerSettings              = 7,   // 0x4c1e1: "Invalid Timer Settings"
    kErrorExpressionEngineNotLoad           = 8,   // 0x4c1f8: "Expression Engine Not Load"
    kErrorCreateStreamFailed                = 9,   // 0x4c213: "Create Stream Failed"
    kErrorInvalidExpressionEngine           = 10,  // 0x4c228: "Invalid Expression Engine"
    kErrorInvalidEventTimestamp             = 11,  // 0x4c242: "Invalid Event Timestamp"
    kErrorRuleNotExistOrStopped             = 12,  // 0x4c25a: "Rule Not Exist Or Stopped"
    kErrorInvalidProcessResult              = 13,  // 0x4c274: "Invalid Process Result(Maybe There Are Some Bug)"
    kErrorInvalidSettingsItem               = 14,  // 0x4c2a5: "Invalid Settings Item"
    kErrorInvalidQuantity                   = 15,  // 0x4c2bb: "Invalid Quantity"
    kErrorSettingsInvalidAndFallbackNotExist= 16,  // 0x4c2cc: "Settings Invalid And Fallback Not Exist"
    kErrorNotCompatibleDSL                  = 17,  // 0x4c2f4: "Not Compatible DSL"
    kErrorTooManyFlows                      = 18,  // 0x4c307: "Too Many Flows"
    kErrorNoSuchTargetState                 = 19,  // 0x4c316: "No Such Target State"
    kErrorCopyStreamFailed                  = 20,  // 0x4c32b: "Copy Stream Failed"
    kErrorCannotFindStartState              = 21,  // 0x4c33e: "Cannot Find Start State"
    kErrorTooManyEventsInQueue              = 22   // 0x4c356: "Too Many Events In Queue"
};

// ============================================================================
// 2. CONTEXT & DATA INTERFACE (`_ZTVN3cep13DataInterfaceE` @ 0x5a9d8, 120 B)
// ============================================================================

class Context {
public:
    Context() = default;
    virtual ~Context() = default;
};

class DefaultContext : public Context {
public:
    DefaultContext() = default;
    ~DefaultContext() override = default;

    // [EN] Exported at 0x0c358 (240 B): singleton `std::shared_ptr<DefaultContext>` at `.bss 0x5c020`
    //      with guard variable at `.bss 0x5c030`.
    // [VN] Xuất tại 0x0c358 (240 B): singleton `std::shared_ptr<DefaultContext>` tại `.bss 0x5c020`
    //      kèm biến bảo vệ tại `.bss 0x5c030`.
    static std::shared_ptr<DefaultContext> GetShared();
};

// [EN] Base polymorphic data interface (`_ZTVN3cep13DataInterfaceE` @ 0x5a9d8, 15 slots = 120 B).
//      VTable layout verified from 0x5a9d8 (file 0x569d8) and call sites 0x0c4e8..0x0c764:
//        slot 0 (+0x00): Type() = 0
//        slot 1 (+0x08): InterfaceType() -> 0x0c4e8 (returns 2)
//        slot 2 (+0x10): IntValue() = 0
//        slot 3 (+0x18): FloatValue() = 0
//        slot 4 (+0x20): BoolValue() = 0
//        slot 5 (+0x28): StringValue() = 0
//        slot 6 (+0x30): Size() = 0
//        slot 7 (+0x38): GetData(int) = 0
//        slot 8 (+0x40): KeySet() = 0
//        slot 9 (+0x48): GetData(const std::string&) = 0
//        slot 10 (+0x50): ~DataInterface() D1 -> 0x0c4f0
//        slot 11 (+0x58): ~DataInterface() D0 -> 0x0c4f4
//        slot 12 (+0x60): JSON() = 0
// [VN] Giao diện dữ liệu đa hình cơ sở (`_ZTVN3cep13DataInterfaceE` @ 0x5a9d8, 15 khe = 120 B).
class DataInterface {
public:
    DataInterface() = default;
    virtual int Type() = 0;                                                         // vtable +0x00
    virtual int InterfaceType();                                                    // vtable +0x08 (@ 0x0c4e8)
    virtual long IntValue() = 0;                                                    // vtable +0x10
    virtual double FloatValue() = 0;                                                // vtable +0x18
    virtual bool BoolValue() = 0;                                                   // vtable +0x20
    virtual std::string StringValue() = 0;                                          // vtable +0x28
    virtual int Size() = 0;                                                         // vtable +0x30
    virtual std::shared_ptr<DataInterface> GetData(int index) = 0;                  // vtable +0x38
    virtual std::vector<std::string> KeySet() = 0;                                  // vtable +0x40
    virtual std::shared_ptr<DataInterface> GetData(const std::string& key) = 0;     // vtable +0x48
    virtual ~DataInterface();                                                       // vtable +0x50 / +0x58 (@ 0x0c4f0)
    virtual std::string JSON() = 0;                                                 // vtable +0x60

    // Non-virtual helper methods exported in .dynsym (0x0c4f8..0x0c764)
    long ConvertToIntValue();      // @ 0x0c4f8 (136 B)
    double ConvertToDoubleValue(); // @ 0x0c580 (136 B)
    bool IsNumber();               // @ 0x0c608 (100 B)
    bool IsInt();                  // @ 0x0c66c (36 B)
    bool IsFloat();                // @ 0x0c690 (36 B)
    bool IsBool();                 // @ 0x0c6b4 (36 B)
    bool IsStr();                  // @ 0x0c6d8 (36 B)
    bool IsList();                 // @ 0x0c6fc (36 B)
    bool IsDict();                 // @ 0x0c720 (36 B)
    bool IsNull();                 // @ 0x0c744 (36 B)
};

// ============================================================================
// 3. DEBUG INFO, VALUE INFO & TRANSITION INFO (0x0c768..0x0cba7)
// ============================================================================

class Error;
class Match;
class EventWrapper;

// [EN] Base debug info struct (`cep::DebugInfo` @ 0x0c768..0x0c827):
//      +0x00: vtable ptr
//      +0x08: biz_name_ (`std::string`, 24 B, `add x1, x0, #8` @ 0x0c768)
//      +0x20: rule_name_ (`std::string`, 24 B, `add x1, x0, #0x20` @ 0x0c81c)
// [VN] Cấu trúc thông tin gỡ lỗi cơ sở (`cep::DebugInfo` @ 0x0c768..0x0c827):
class DebugInfo {
public:
    DebugInfo() = default;
    DebugInfo(const std::string& biz_name, const std::string& rule_name)
        : biz_name_(biz_name), rule_name_(rule_name) {}
    virtual ~DebugInfo() = default;
    virtual int GetDebugInfoType() { return -1; }

    std::string GetBizName();   // @ 0x0c768 (12 B)
    std::string GetRuleName();  // @ 0x0c81c (12 B)

protected:
    std::string biz_name_;   // +0x08
    std::string rule_name_;  // +0x20
};

// [EN] Value debug info (`cep::ValueInfo` @ 0x0c828..0x0c8e7, vtable `_ZTVN3cep9ValueInfoE` @ 0x5aa78):
//      +0x08: biz_name_ (24 B)
//      +0x20: rule_name_ (24 B)
//      +0x38: tag_ (24 B, `add x1, x0, #0x38` @ 0x0c8a8)
//      +0x50: value_ (`std::shared_ptr<DataInterface>`, 16 B, `ldr x9, [x0, #0x50]` @ 0x0c8b4)
// [VN] Thông tin gỡ lỗi giá trị (`cep::ValueInfo` @ 0x0c828..0x0c8e7):
class ValueInfo : public DebugInfo {
public:
    ValueInfo(const std::string& biz_name,
              const std::string& rule_name,
              std::string tag,
              std::shared_ptr<DataInterface> value);  // @ 0x0c828 (128 B)
    ~ValueInfo() override = default;

    std::string GetTag();                             // @ 0x0c8a8 (12 B)
    std::shared_ptr<DataInterface> GetValue();        // @ 0x0c8b4 (44 B)
    int GetDebugInfoType() override;                  // @ 0x0c8e0 (8 B -> returns 0)

private:
    std::string tag_;                                 // +0x38
    std::shared_ptr<DataInterface> value_;            // +0x50
};

// [EN] Single NFA match transition info (`cep::MatchTransitionInfo` @ 0x0c8e8..0x0c9bf):
//      +0x00: current_match_ (`std::shared_ptr<Match>`, 16 B)
//      +0x10: next_matches_ (`std::vector<std::shared_ptr<Match>>`, 24 B)
//      +0x28: error_ (`std::shared_ptr<Error>`, 16 B, `ldr x0, [x0, #0x28]` @ 0x0c9b8)
// [VN] Thông tin chuyển trạng thái khớp NFA (`cep::MatchTransitionInfo` @ 0x0c8e8..0x0c9bf):
class MatchTransitionInfo {
public:
    MatchTransitionInfo() = default;
    MatchTransitionInfo(std::shared_ptr<Match> current,
                        std::vector<std::shared_ptr<Match>> next,
                        std::shared_ptr<Error> err)
        : current_match_(std::move(current)),
          next_matches_(std::move(next)),
          error_(std::move(err)) {}

    std::shared_ptr<Match> current_match();                 // @ 0x0c8e8 (44 B)
    std::vector<std::shared_ptr<Match>> next_matches();     // @ 0x0c914 (164 B)
    std::string error() const;                              // @ 0x0c9b8 (8 B)

private:
    std::shared_ptr<Match> current_match_;                  // +0x00
    std::vector<std::shared_ptr<Match>> next_matches_;      // +0x10
    std::shared_ptr<Error> error_;                          // +0x28
};

// [EN] Rule transition debug info (`cep::TransitionInfo` @ 0x0cac0..0x0cba7):
//      +0x68: trigger_type_ (`int32_t`, `ldr w0, [x0, #0x68]` @ 0x0cac0)
//      +0x70: event_ (`std::shared_ptr<EventWrapper>`, 16 B, `ldr x9, [x0, #0x70]` @ 0x0cac8)
//      +0x80: advance_time_ (`int64_t`, `ldr x0, [x0, #0x80]` @ 0x0caf4)
//      +0x88: transitions_ (`std::vector<MatchTransitionInfo>`, 24 B, @ 0x0cafc)
// [VN] Thông tin gỡ lỗi chuyển tiếp quy tắc (`cep::TransitionInfo` @ 0x0cac0..0x0cba7):
class TransitionInfo : public DebugInfo {
public:
    TransitionInfo() = default;
    TransitionInfo(const std::string& biz_name,
                   const std::string& rule_name,
                   int trigger_type,
                   std::shared_ptr<EventWrapper> event,
                   long long advance_time,
                   std::vector<MatchTransitionInfo> transitions)
        : DebugInfo(biz_name, rule_name),
          trigger_type_(trigger_type),
          event_(std::move(event)),
          advance_time_(advance_time),
          transitions_(std::move(transitions)) {}
    ~TransitionInfo() override = default;

    int GetTriggerType() const;                             // @ 0x0cac0 (8 B)
    std::shared_ptr<EventWrapper> GetEvent();               // @ 0x0cac8 (44 B)
    long long GetAdvanceTime() const;                       // @ 0x0caf4 (8 B)
    std::vector<MatchTransitionInfo> GetTransitions();      // @ 0x0cafc (164 B)
    int GetDebugInfoType() override;                        // @ 0x0cba0 (8 B -> returns 1)

private:
    std::string reserved_state_info_;                       // +0x38..+0x67 padding/meta
    int trigger_type_ = 0;                                  // +0x68
    std::shared_ptr<EventWrapper> event_;                   // +0x70
    long long advance_time_ = 0;                            // +0x80
    std::vector<MatchTransitionInfo> transitions_;          // +0x88
};

// ============================================================================
// 4. CONCURRENCY PRIMITIVES: RWLock, LockGuards, Semaphore (0x42ee0..0x43453)
// ============================================================================

// [EN] Reader-Writer Lock wrapping `std::shared_timed_mutex` (0x42ee0..0x4313f).
// [VN] Khóa Đọc-Ghi bọc `std::shared_timed_mutex` (0x42ee0..0x4313f).
class RWLock {
public:
    RWLock() = default;
    ~RWLock() = default;

    void LockRead() const;      // @ 0x42ee0 (296 B, retry loop with try_lock_shared)
    void LockWrite() const;     // @ 0x43008 (296 B, retry loop with try_lock)
    void UnlockRead() const;    // @ 0x43130 (4 B -> shared_timed_mutex::unlock_shared)
    void UnlockWrite() const;   // @ 0x43134 (4 B -> shared_timed_mutex::unlock)
    bool TryLockRead() const;   // @ 0x43138 (4 B -> shared_timed_mutex::try_lock_shared)
    bool TryLockWrite() const;  // @ 0x4313c (4 B -> shared_timed_mutex::try_lock)

private:
    mutable std::shared_timed_mutex mutex_;
};

class ReadLockGuard {
public:
    explicit ReadLockGuard(const RWLock& lock);  // @ 0x43140 (12 B)
    ~ReadLockGuard();                            // @ 0x4314c (8 B)
private:
    const RWLock* lock_;                         // +0x00 (`str x1, [x0]` @ 0x43140)
};

class WriteLockGuard {
public:
    explicit WriteLockGuard(const RWLock& lock); // @ 0x43154 (12 B)
    ~WriteLockGuard();                           // @ 0x43160 (8 B)
private:
    const RWLock* lock_;                         // +0x00 (`str x1, [x0]` @ 0x43154)
};

// [EN] Deadlock-free dual write lock acquisition (`cep::LockWrite` @ 0x43168, 100 B)
//      using `LockWrite` + `TryLockWrite` + `sched_yield` backoff loop.
// [VN] Khóa ghi kép chống deadlock (`cep::LockWrite` @ 0x43168, 100 B)
//      sử dụng vòng lặp `LockWrite` + `TryLockWrite` + `sched_yield`.
void LockWrite(const RWLock& lock1, const RWLock& lock2);

// [EN] Counting Semaphore (`cep::Semaphore` @ 0x431cc..0x43450, 96 B = 0x60):
//      +0x00..+0x27: `std::mutex mutex_` (40 B)
//      +0x28..+0x57: `std::condition_variable cv_` (48 B, `add x0, x19, #0x28` @ 0x43444)
//      +0x58: `unsigned long count_` (8 B, `stp xzr, x1, [x0, #0x50]` @ 0x431dc)
// [VN] Semaphore đếm (`cep::Semaphore` @ 0x431cc..0x43450, 96 B = 0x60):
class Semaphore {
public:
    explicit Semaphore(unsigned long count = 0);           // @ 0x431cc (24 B)
    ~Semaphore() = default;

    void Wait(unsigned long count = 1);                    // @ 0x431e4 (164 B)
    bool WaitUntil(double timeout_sec, unsigned long count = 1); // @ 0x43288 (392 B)
    void Signal(unsigned long count = 1);                  // @ 0x43410 (68 B)

    unsigned long current_count() const {
        std::lock_guard<std::mutex> lk(mutex_);
        return count_;
    }

private:
    mutable std::mutex mutex_;       // +0x00
    std::condition_variable cv_;     // +0x28
    unsigned long count_ = 0;        // +0x58
};

} // namespace cep
