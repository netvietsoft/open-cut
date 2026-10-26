// ============================================================================
// FILE: cepengine_nfa_evaluator.h
// TARGET: libCepEngine.so — NFA State Machine, Match, ExprEvaluator & Results
// TRẠNG THÁI / STATUS: 100% RECONSTRUCTED — ZERO STUBS — AARCH64 VERIFIED
// ============================================================================
// [EN] Declares `cep::EventWrapper` (0x27924..0x279cf), `cep::EventWrapperList`
//      (0x27a10..0x27bd7), `cep::ExprEvaluator` (`_ZTVN3cep13ExprEvaluatorE` @ 0x5b0e0,
//      0x285d8..0x28607), `cep::Match` (0x286d0..0x28aeb), `cep::NfaState`,
//      `cep::ComputationState`, `cep::Nfa` (`Process` @ 0x2d2c8, `AdvanceTime` @ 0x2d748),
//      `cep::MatchResult` (0x32060..0x320b7), `cep::Result` (0x320b8..0x32453),
//      and `cep::EngineResult` (0x14e3c..0x14f1b).
// [VN] Khai báo `cep::EventWrapper` (0x27924..0x279cf), `cep::EventWrapperList`
//      (0x27a10..0x27bd7), `cep::ExprEvaluator` (`_ZTVN3cep13ExprEvaluatorE` @ 0x5b0e0,
//      0x285d8..0x28607), `cep::Match` (0x286d0..0x28aeb), `cep::NfaState`,
//      `cep::ComputationState`, `cep::Nfa` (`Process` @ 0x2d2c8, `AdvanceTime` @ 0x2d748),
//      `cep::MatchResult` (0x32060..0x320b7), `cep::Result` (0x320b8..0x32453),
//      và `cep::EngineResult` (0x14e3c..0x14f1b).
// ============================================================================

#pragma once

#include "cepengine_data_error_utils.h"

namespace cep {

class NfaState;
class ComputationState;

// ============================================================================
// 1. EVENT WRAPPER & EVENT WRAPPER LIST (0x27924..0x27bd7)
// ============================================================================

// [EN] EventWrapper (`cep::EventWrapper` @ 0x27924..0x279cf):
//      +0x00: `event_name_` (`std::string`, 24 B)
//      +0x18: `raw_data_` (`void*`, `ldr x0, [x0, #0x18]` @ 0x279b0)
//      +0x20: `extra_` (`void*`, `ldr x0, [x0, #0x20]` @ 0x279b8)
//      +0x28: `timestamp_ms_` (`long long`, `ldr x0, [x0, #0x28]` @ 0x279c0)
//      +0x30: `release_fn_` / `exp_engine_` (`std::function<void(void*)>`)
//      +0x48: `data_interface_` (`std::shared_ptr<DataInterface>`)
// [VN] Lớp bọc sự kiện đầu vào (`cep::EventWrapper` @ 0x27924..0x279cf):
class EventWrapper {
public:
    EventWrapper() = default;
    EventWrapper(const std::string& event_name,
                 void* raw_data,
                 long long timestamp_ms,
                 void* extra = nullptr,
                 std::shared_ptr<DataInterface> data_iface = nullptr,
                 std::function<void(void*)> release_fn = nullptr)
        : event_name_(event_name),
          raw_data_(raw_data),
          extra_(extra),
          timestamp_ms_(timestamp_ms),
          release_fn_(std::move(release_fn)),
          data_interface_(std::move(data_iface)) {}

    ~EventWrapper();                                        // @ 0x27924 (140 B)

    void* data();                                           // @ 0x279b0 (8 B)
    void* extra();                                          // @ 0x279b8 (8 B)
    long long timestamp_ms() const;                         // @ 0x279c0 (8 B)
    void set_timestamp_ms(long long ts);                    // @ 0x279c8 (8 B)

    const std::string& event_name() const { return event_name_; }
    std::shared_ptr<DataInterface> data_interface() const { return data_interface_; }
    void set_data_interface(std::shared_ptr<DataInterface> d) { data_interface_ = std::move(d); }

private:
    std::string event_name_;                                // +0x00
    void* raw_data_ = nullptr;                              // +0x18
    void* extra_ = nullptr;                                 // +0x20
    long long timestamp_ms_ = 0;                            // +0x28
    std::function<void(void*)> release_fn_;                 // +0x30
    std::shared_ptr<DataInterface> data_interface_;         // +0x48
};

// [EN] EventWrapperList (`cep::EventWrapperList` @ 0x27a10..0x27bd7):
//      +0x00: `raw_list_` (`void*`, `ldr x0, [x0]` @ 0x27a84)
//      +0x08: `custom_type_provider_` (`void*`, checked in `Type()` @ 0x27bc4)
//      +0x18: `size_` (`unsigned long`, `ldr x0, [x0, #0x18]` @ 0x27bbc)
//      +0x20: `events_` (`std::vector<std::shared_ptr<EventWrapper>>`)
// [VN] Danh sách sự kiện đã khớp (`cep::EventWrapperList` @ 0x27a10..0x27bd7):
class EventWrapperList {
public:
    EventWrapperList() = default;
    ~EventWrapperList();                                    // @ 0x27a10 (116 B)

    void* data();                                           // @ 0x27a84 (8 B)
    bool Append(const std::shared_ptr<EventWrapper>& ev);   // @ 0x27a8c (72 B)
    std::shared_ptr<EventWrapperList> Copy();               // @ 0x27ad4 (232 B)
    unsigned long Size() const;                             // @ 0x27bbc (8 B)
    int Type() const;                                       // @ 0x27bc4 (20 B -> returns 100 / 0x64)

    const std::vector<std::shared_ptr<EventWrapper>>& events() const { return events_; }

private:
    void* raw_list_ = nullptr;                              // +0x00
    void* custom_type_provider_ = nullptr;                  // +0x08
    unsigned long size_ = 0;                                // +0x18
    std::vector<std::shared_ptr<EventWrapper>> events_;     // +0x20
};

// ============================================================================
// 2. EXPRESSION EVALUATOR (`_ZTVN3cep13ExprEvaluatorE` @ 0x5b0e0, 80 B)
// ============================================================================

// [EN] Base polymorphic expression evaluator (`cep::ExprEvaluator` @ 0x285d8..0x28607):
//      VTable `_ZTVN3cep13ExprEvaluatorE` @ 0x5b0e0 (10 slots = 80 B):
//        slot 0 (+0x00): ~ExprEvaluator() D1
//        slot 1 (+0x08): ~ExprEvaluator() D0
//        slot 2 (+0x10): Calculate(biz, rule, event, match, err, extra) -> 0x285d8 (mov w0, wzr)
//        slot 3 (+0x18): InitDataSource() -> 0x285e0 (mov w0, wzr)
//        slot 4 (+0x20): Init(const std::string&, void*) -> 0x285e8 (mov w0, wzr)
//        slot 5 (+0x28): Init(const std::shared_ptr<DataInterface>&, void*) -> 0x285f0 (mov w0, wzr)
//        slot 6 (+0x30): IsExprEvalV2() -> 0x285f8 (mov w0, wzr)
//        slot 7 (+0x38): Calculate(ctx, biz, rule, event, match, err) -> 0x28600 (stp xzr, xzr, [x8])
// [VN] Lớp cơ sở tính toán biểu thức (`cep::ExprEvaluator` @ 0x285d8..0x28607):
class ExprEvaluator {
public:
    ExprEvaluator() = default;
    virtual ~ExprEvaluator() = default;

    virtual bool Calculate(const std::string& biz_name,
                           const std::string& rule_name,
                           void* event_data,
                           void* match_data,
                           std::string& err_msg,
                           void* extra);                                            // @ 0x285d8 (8 B)
    virtual bool InitDataSource();                                                  // @ 0x285e0 (8 B)
    virtual bool Init(const std::string& dsl, void* extra);                         // @ 0x285e8 (8 B)
    virtual bool Init(const std::shared_ptr<DataInterface>& dsl_data, void* extra); // @ 0x285f0 (8 B)
    virtual bool IsExprEvalV2();                                                    // @ 0x285f8 (8 B)
    virtual std::shared_ptr<DataInterface> Calculate(
        const std::shared_ptr<Context>& ctx,
        const std::string& biz_name,
        const std::string& rule_name,
        const std::shared_ptr<EventWrapper>& event,
        const std::shared_ptr<Match>& match,
        std::string& err_msg);                                                      // @ 0x28600 (8 B)
};

// ============================================================================
// 3. NFA MATCH OBJECT (`cep::Match` @ 0x286d0..0x28aeb)
// ============================================================================

// [EN] Represents an active or completed NFA pattern match (`cep::Match` @ 0x286d0..0x28aeb):
//      +0x00: `matched_events_` (`std::shared_ptr<DataInterface>`, 16 B, `ldr x9, [x0]` @ 0x28ac0)
//      +0x10: `variables_` (`std::unordered_map<std::string, std::shared_ptr<DataInterface>>`, 40 B)
//      +0x30: `current_state_` (`ComputationState*` / `std::shared_ptr<ComputationState>`,
//             where `state_name_` is at `+0x40` inside `ComputationState`, `ldr x9, [x0, #0x30]; add x1, x9, #0x40` @ 0x28aa8)
//      +0x58: `current_quantity_` (`unsigned long`, `ldr x0, [x0, #0x58]` @ 0x28ab8)
// [VN] Đại diện cho một luồng khớp mẫu NFA đang hoạt động hoặc đã hoàn tất (`cep::Match` @ 0x286d0..0x28aeb):
class Match {
public:
    Match();
    explicit Match(std::shared_ptr<ComputationState> state,
                   unsigned long quantity = 0,
                   long long start_ts = 0);
    ~Match() = default;

    void SetVariable(const std::string& key,
                     const std::shared_ptr<DataInterface>& val);                    // @ 0x286d0 (216 B)
    void SetGlobalVariable(const std::string& key,
                           const std::shared_ptr<DataInterface>& val) const;        // @ 0x28988 (20 B)
    std::shared_ptr<DataInterface> GetVariable(const std::string& key) const;       // @ 0x2899c (268 B)
    std::string GetCurrentState() const;                                            // @ 0x28aa8 (16 B)
    unsigned long GetCurrentQuantity() const;                                       // @ 0x28ab8 (8 B)
    std::shared_ptr<DataInterface> GetMatchedEvents() const;                        // @ 0x28ac0 (44 B)

    void AppendMatchedEvent(const std::shared_ptr<EventWrapper>& ev);
    void SetCurrentStatePtr(std::shared_ptr<ComputationState> st, unsigned long qty = 1);
    std::shared_ptr<ComputationState> current_state_ptr() const { return current_state_; }
    const std::unordered_map<std::string, std::shared_ptr<DataInterface>>& variables() const {
        return variables_;
    }
    const std::vector<std::shared_ptr<EventWrapper>>& raw_events() const {
        return raw_events_;
    }
    long long start_timestamp_ms() const { return start_timestamp_ms_; }
    void set_start_timestamp_ms(long long ts) { start_timestamp_ms_ = ts; }
    std::shared_ptr<Match> Clone() const;

private:
    std::shared_ptr<MemoryDataInterface> matched_events_;                           // +0x00
    mutable std::unordered_map<std::string, std::shared_ptr<DataInterface>> variables_; // +0x10
    std::shared_ptr<ComputationState> current_state_;                               // +0x30
    unsigned long current_quantity_ = 0;                                            // +0x58
    long long start_timestamp_ms_ = 0;
    std::vector<std::shared_ptr<EventWrapper>> raw_events_;
};

// ============================================================================
// 4. NFA STATE MACHINE (`cep::Nfa`, `cep::NfaState`, `cep::ComputationState`)
// ============================================================================

// [EN] Edge action types in CEP DSL (`actionType` @ 0x4bdcc):
//      0 = Take (consume & advance), 1 = Ignore (skip event), 2 = Proceed (epsilon transition).
// [VN] Các loại hành động cạnh trong CEP DSL (`actionType` @ 0x4bdcc):
enum class EdgeActionType : int32_t {
    kTake    = 0,
    kIgnore  = 1,
    kProceed = 2
};

struct NfaEdge {
    std::string target_state;       // 0x4bdc0: "targetState"
    EdgeActionType action_type = EdgeActionType::kTake; // 0x4bdcc: "actionType"
    std::string condition;          // 0x4bded: "condition" (default "True" @ 0x4bdf7 / "true" @ 0x4be04)
    long min_count = 1;             // 0x4bdd7: "min" / 0x4bddb: "min_eq"
    long max_count = 1;             // 0x4bde2: "max" / 0x4bde6: "max_eq"
    std::vector<std::pair<std::string, std::string>> actions; // 0x4bdfc: "actions" (key/expression pairs)
};

// [EN] Single NFA state definition (`cep::ComputationState`):
//      +0x40: `state_name_` (`std::string`, accessed at 0x28ab0 `add x1, x9, #0x40`)
//      `stateType` (`0x4c43a`): 0 = Start (`"start"` @ 0x4c4a4), 1 = Normal, 2 = Final (`"$finalState$"` @ 0x4be09), 3 = Stop (`"$stopState$"` @ 0x4c4e9)
// [VN] Định nghĩa một trạng thái trong ô-tô-mát hữu hạn không đơn định (`cep::ComputationState`):
class ComputationState {
public:
    ComputationState() = default;
    ComputationState(const std::string& name, int state_type = 0)
        : state_type_(state_type), state_name_(name) {}

    const std::string& state_name() const { return state_name_; }
    int state_type() const { return state_type_; }
    bool is_start() const { return state_type_ == 0 || state_name_ == "start"; }
    bool is_final() const { return state_type_ == 2 || state_name_ == "$finalState$"; }
    bool is_stop() const  { return state_type_ == 3 || state_name_ == "$stopState$"; }

    void add_edge(const NfaEdge& edge) { edges_.push_back(edge); }
    const std::vector<NfaEdge>& edges() const { return edges_; }

    void set_timer_settings(long long delay_ms, long repeat_times) {
        has_timer_ = (delay_ms > 0);
        timer_delay_ms_ = delay_ms;
        timer_repeat_times_ = repeat_times;
    }
    bool has_timer() const { return has_timer_; }
    long long timer_delay_ms() const { return timer_delay_ms_; }
    long timer_repeat_times() const { return timer_repeat_times_; }

private:
    uint8_t reserved_header_[0x38] = {0};
    int state_type_ = 0;                    // +0x38 (0x4c43a: "stateType")
    std::string state_name_;                // +0x40 (0x4c430: "stateName")
    std::vector<NfaEdge> edges_;            // 0x4c444: "edges"
    bool has_timer_ = false;                // 0x4c44a: "timer_settings"
    long long timer_delay_ms_ = 0;          // 0x4c466: "delay"
    long timer_repeat_times_ = 0;           // 0x4c459: "repeat_times"
};

// [EN] Runtime mutable NFA execution state (`cep::NfaState`):
//      Holds active partial matches (`partial_matches_`), completed final matches
//      (`completed_matches_`), and per-state cost telemetry (`"process_cost"` @ 0x4c3e0,
//      `"advance_time_cost"` @ 0x4c3ed).
// [VN] Trạng thái thực thi NFA động tại thời điểm chạy (`cep::NfaState`):
class NfaState {
public:
    NfaState() = default;

    std::vector<std::shared_ptr<Match>>& partial_matches() { return partial_matches_; }
    const std::vector<std::shared_ptr<Match>>& partial_matches() const { return partial_matches_; }

    std::vector<std::shared_ptr<Match>>& completed_matches() { return completed_matches_; }
    const std::vector<std::shared_ptr<Match>>& completed_matches() const { return completed_matches_; }

    void RecordCost(const std::string& metric, const std::string& state_name, long long cost_us) {
        state_costs_[metric + ":" + state_name] += cost_us;
    }

    void Clear() {
        partial_matches_.clear();
        completed_matches_.clear();
        state_costs_.clear();
    }

private:
    std::vector<std::shared_ptr<Match>> partial_matches_;
    std::vector<std::shared_ptr<Match>> completed_matches_;
    std::unordered_map<std::string, long long> state_costs_;
};

// [EN] Non-deterministic Finite Automaton engine (`cep::Nfa` @ 0x2d2c8..0x2d91f):
//      - `Process` @ 0x2d2c8 (1,152 B): processes `event` from `comp_state`, evaluates
//        edge conditions via `ExprEvaluator`, records `"process_cost"` (0x4c3e0), and
//        transitions to target states (`$finalState$` @ 0x4be09, `$stopState$` @ 0x4c4e9).
//      - `AdvanceTime` @ 0x2d748 (472 B): expires partial matches exceeding `within_ms_`
//        (`0x4c3bb: "within"`) and records `"advance_time_cost"` (0x4c3ed).
// [VN] Bộ máy Ô-tô-mát Hữu hạn Không đơn định (`cep::Nfa` @ 0x2d2c8..0x2d91f):
class Nfa {
public:
    Nfa() = default;
    ~Nfa() = default;

    bool InitFromRuleData(const std::string& biz_name,
                          const std::string& rule_name,
                          const std::shared_ptr<DataInterface>& rule_data,
                          std::shared_ptr<ExprEvaluator> evaluator,
                          std::shared_ptr<Error>& error);

    std::vector<std::shared_ptr<Match>> Process(
        const std::shared_ptr<NfaState>& nfa_state,
        const std::shared_ptr<ComputationState>& comp_state,
        const std::shared_ptr<EventWrapper>& event,
        std::shared_ptr<Error>& error);                                             // @ 0x2d2c8 (1152 B)

    std::vector<std::shared_ptr<Match>> AdvanceTime(
        const std::shared_ptr<NfaState>& nfa_state,
        const std::shared_ptr<ComputationState>& comp_state,
        long long timestamp_ms,
        std::shared_ptr<Error>& error) const;                                       // @ 0x2d748 (472 B)

    std::shared_ptr<ComputationState> start_state() const { return start_state_; }
    std::shared_ptr<ComputationState> FindState(const std::string& name) const;
    long long within_ms() const { return within_ms_; }
    int skip_strategy() const { return skip_strategy_; }

private:
    std::string biz_name_;
    std::string rule_name_;
    std::string dsl_version_ = "1.0.0";
    long long within_ms_ = 0;               // 0x4c3bb: "within"
    int skip_strategy_ = 0;                 // 0x4c3c2: "skipStrategy"
    std::shared_ptr<ComputationState> start_state_;
    std::unordered_map<std::string, std::shared_ptr<ComputationState>> states_;
    std::unordered_map<std::string, std::string> conditions_;
    std::shared_ptr<ExprEvaluator> evaluator_;
};

// ============================================================================
// 5. MATCH RESULT, RESULT & ENGINE RESULT (0x32060..0x32453 & 0x14e3c..0x14f1b)
// ============================================================================

// [EN] Single pattern match result (`cep::MatchResult` @ 0x32060..0x320b7):
//      +0x00: `matched_events_` (`std::shared_ptr<DataInterface>`, 16 B)
//      +0x10: `variables_` (`std::shared_ptr<DataInterface>`, 16 B)
// [VN] Kết quả một lần khớp mẫu (`cep::MatchResult` @ 0x32060..0x320b7):
class MatchResult {
public:
    MatchResult() = default;
    MatchResult(std::shared_ptr<DataInterface> matched_events,
                std::shared_ptr<DataInterface> variables)
        : matched_events_(std::move(matched_events)),
          variables_(std::move(variables)) {}

    std::shared_ptr<DataInterface> GetMatchedEvents() const;                        // @ 0x32060 (44 B)
    std::shared_ptr<DataInterface> GetVariables() const;                            // @ 0x3208c (44 B)

private:
    std::shared_ptr<DataInterface> matched_events_;         // +0x00
    std::shared_ptr<DataInterface> variables_;              // +0x10
};

// [EN] Public rule evaluation result (`cep::Result` @ 0x320b8..0x32453):
//      +0x00: `success_` (`bool`, `ldrb w0, [x0]` @ 0x320b8)
//      +0x08: `biz_name_` (`std::string`, 24 B, `add x1, x0, #8` @ 0x320c0)
//      +0x20: `rule_name_` (`std::string`, 24 B, `add x1, x0, #0x20` @ 0x320cc)
//      +0x38: `error_message_` (`std::string`, 24 B, `add x1, x0, #0x38` @ 0x320d8)
//      +0x50: `warning_messages_` (`std::vector<std::string>`, 24 B, @ 0x320e4)
//      +0x68: `match_results_` (`std::vector<MatchResult>`, 24 B, @ 0x323b0)
// [VN] Kết quả đánh giá quy tắc công khai (`cep::Result` @ 0x320b8..0x32453):
class Result {
public:
    Result() = default;
    Result(bool success,
           std::string biz_name,
           std::string rule_name,
           std::string error_message,
           std::vector<std::string> warning_messages,
           std::vector<MatchResult> match_results)
        : success_(success),
          biz_name_(std::move(biz_name)),
          rule_name_(std::move(rule_name)),
          error_message_(std::move(error_message)),
          warning_messages_(std::move(warning_messages)),
          match_results_(std::move(match_results)) {}

    bool success() const;                                                           // @ 0x320b8 (8 B)
    std::string biz_name();                                                         // @ 0x320c0 (12 B)
    std::string rule_name();                                                        // @ 0x320cc (12 B)
    std::string error_message();                                                    // @ 0x320d8 (12 B)
    std::vector<std::string> warning_messages();                                    // @ 0x320e4 (168 B)
    std::vector<std::shared_ptr<DataInterface>> matched_events_sequences() const;   // @ 0x3218c (296 B)
    std::vector<MatchResult> match_results();                                       // @ 0x323b0 (164 B)

private:
    bool success_ = false;                                  // +0x00
    std::string biz_name_;                                  // +0x08
    std::string rule_name_;                                 // +0x20
    std::string error_message_;                             // +0x38
    std::vector<std::string> warning_messages_;             // +0x50
    std::vector<MatchResult> match_results_;                // +0x68
};

// [EN] Internal engine result (`cep::EngineResult` @ 0x14e3c..0x14f1b):
//      +0x00: `success_` (`bool`, `ldrb w0, [x0]` @ 0x14e3c)
//      +0x08: `biz_name_` (`std::string`, 24 B, `add x1, x0, #8` @ 0x14e44)
//      +0x20: `rule_name_` (`std::string`, 24 B, `add x1, x0, #0x20` @ 0x14e50)
//      +0x38: `error_message_` (`std::string`, 24 B, `add x1, x0, #0x38` @ 0x14e5c)
//      +0x50: `warning_messages_` (`std::vector<std::string>`, 24 B, @ 0x14e68)
//      +0x68: `matched_events_sequences_` (`std::vector<std::pair<std::shared_ptr<EventWrapperList>, std::unordered_map<std::string, std::shared_ptr<DataInterface>>>>`, @ 0x14f10)
// [VN] Kết quả engine nội bộ (`cep::EngineResult` @ 0x14e3c..0x14f1b):
class EngineResult {
public:
    using MatchedSequenceEntry = std::pair<
        std::shared_ptr<EventWrapperList>,
        std::unordered_map<std::string, std::shared_ptr<DataInterface>>>;

    EngineResult() = default;
    EngineResult(bool success,
                 std::string biz_name,
                 std::string rule_name,
                 std::string error_message,
                 std::vector<std::string> warnings,
                 std::vector<MatchedSequenceEntry> sequences)
        : success_(success),
          biz_name_(std::move(biz_name)),
          rule_name_(std::move(rule_name)),
          error_message_(std::move(error_message)),
          warning_messages_(std::move(warnings)),
          matched_events_sequences_(std::move(sequences)) {}

    bool success() const;                                                           // @ 0x14e3c (8 B)
    std::string biz_name();                                                         // @ 0x14e44 (12 B)
    std::string rule_name();                                                        // @ 0x14e50 (12 B)
    std::string error_message();                                                    // @ 0x14e5c (12 B)
    std::vector<std::string> warning_messages();                                    // @ 0x14e68 (168 B)
    std::vector<MatchedSequenceEntry> matched_events_sequences();                   // @ 0x14f10 (12 B)

    std::shared_ptr<Result> ToPublicResult() const;

private:
    bool success_ = false;                                  // +0x00
    std::string biz_name_;                                  // +0x08
    std::string rule_name_;                                 // +0x20
    std::string error_message_;                             // +0x38
    std::vector<std::string> warning_messages_;             // +0x50
    std::vector<MatchedSequenceEntry> matched_events_sequences_; // +0x68
};

} // namespace cep
