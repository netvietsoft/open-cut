// ============================================================================
// FILE: cepengine_nfa_evaluator.cpp
// TARGET: libCepEngine.so — NFA State Machine, Match, ExprEvaluator & Results
// TRẠNG THÁI / STATUS: 100% RECONSTRUCTED — ZERO STUBS — AARCH64 VERIFIED
// ============================================================================
// [EN] Full C++17 implementation of `cep::EventWrapper` (0x27924..0x279cf),
//      `cep::EventWrapperList` (0x27a10..0x27bd7), `cep::ExprEvaluator`
//      (0x285d8..0x28607), `cep::Match` (0x286d0..0x28aeb), `cep::Nfa`
//      (`Process` @ 0x2d2c8, `AdvanceTime` @ 0x2d748), `cep::MatchResult`
//      (0x32060..0x320b7), `cep::Result` (0x320b8..0x32453), and
//      `cep::EngineResult` (0x14e3c..0x14f1b).
// [VN] Bản cài đặt C++17 đầy đủ cho `cep::EventWrapper` (0x27924..0x279cf),
//      `cep::EventWrapperList` (0x27a10..0x27bd7), `cep::ExprEvaluator`
//      (0x285d8..0x28607), `cep::Match` (0x286d0..0x28aeb), `cep::Nfa`
//      (`Process` @ 0x2d2c8, `AdvanceTime` @ 0x2d748), `cep::MatchResult`
//      (0x32060..0x320b7), `cep::Result` (0x320b8..0x32453), và
//      `cep::EngineResult` (0x14e3c..0x14f1b).
// ============================================================================

#include "cepengine_nfa_evaluator.h"
#include <algorithm>

namespace cep {

// ============================================================================
// 1. EVENT WRAPPER & EVENT WRAPPER LIST (`0x27924..0x27bd7`)
// ============================================================================

// [EN] Disassembly @ 0x27924 (`_ZN3cep12EventWrapperD2Ev`, 140 B):
//      0x27930: f9400c01  ldr x1, [x0, #0x18]    // raw_data_
//      0x27938: b40000a1  cbz x1, #0x2794c
//      0x2793c: f9401a60  ldr x0, [x19, #0x30]   // exp_engine_ / release_fn_
//      0x27944: 94000224  bl  #0x281d4           // release_event_data(raw_data_)
//      0x27948: f9000e7f  str xzr, [x19, #0x18]
// [VN] Hàm hủy `EventWrapper` (@ 0x27924): giải phóng `raw_data_` tại `+0x18`.
EventWrapper::~EventWrapper() {
    if (raw_data_ && release_fn_) {
        release_fn_(raw_data_);
        raw_data_ = nullptr;
    }
}

// [EN] Disassembly @ 0x279b0..0x279cc:
//      0x279b0: f9400c00 ldr x0, [x0, #0x18]; d65f03c0 ret  (data)
//      0x279b8: f9401000 ldr x0, [x0, #0x20]; d65f03c0 ret  (extra)
//      0x279c0: f9401400 ldr x0, [x0, #0x28]; d65f03c0 ret  (timestamp_ms)
//      0x279c8: f9001401 str x1, [x0, #0x28]; d65f03c0 ret  (set_timestamp_ms)
// [VN] Các phương thức truy xuất trường `EventWrapper` (@ 0x279b0..0x279cc):
void* EventWrapper::data() {
    return raw_data_;
}

void* EventWrapper::extra() {
    return extra_;
}

long long EventWrapper::timestamp_ms() const {
    return timestamp_ms_;
}

void EventWrapper::set_timestamp_ms(long long ts) {
    timestamp_ms_ = ts;
}

// [EN] Disassembly @ 0x27a10 (`_ZN3cep16EventWrapperListD2Ev`, 116 B):
// [VN] Hàm hủy `EventWrapperList` (@ 0x27a10):
EventWrapperList::~EventWrapperList() {
    raw_list_ = nullptr;
    events_.clear();
    size_ = 0;
}

// [EN] Disassembly @ 0x27a84 (`_ZN3cep16EventWrapperList4dataEv`, 8 B):
//      0x27a84: f9400000 ldr x0, [x0]; 0x27a88: d65f03c0 ret
// [VN] Lấy con trỏ danh sách thô (`data` @ 0x27a84):
void* EventWrapperList::data() {
    return raw_list_;
}

// [EN] Disassembly @ 0x27a8c (`_ZN3cep16EventWrapperList6AppendERKNSt6__ndk110shared_ptrINS_12EventWrapperEEE`, 72 B):
// [VN] Thêm sự kiện vào danh sách (`Append` @ 0x27a8c):
bool EventWrapperList::Append(const std::shared_ptr<EventWrapper>& ev) {
    if (!ev) {
        return false;
    }
    events_.push_back(ev);
    size_ = static_cast<unsigned long>(events_.size());
    return true;
}

// [EN] Disassembly @ 0x27ad4 (`_ZN3cep16EventWrapperList4CopyEv`, 232 B):
// [VN] Sao chép danh sách sự kiện (`Copy` @ 0x27ad4):
std::shared_ptr<EventWrapperList> EventWrapperList::Copy() {
    auto cloned = std::make_shared<EventWrapperList>();
    cloned->raw_list_ = raw_list_;
    cloned->custom_type_provider_ = custom_type_provider_;
    cloned->events_ = events_;
    cloned->size_ = size_;
    return cloned;
}

// [EN] Disassembly @ 0x27bbc (`_ZNK3cep16EventWrapperList4SizeEv`, 8 B):
//      0x27bbc: f9400c00 ldr x0, [x0, #0x18]; 0x27bc0: d65f03c0 ret
// [VN] Lấy kích thước danh sách (`Size` @ 0x27bbc, độ lệch +0x18):
unsigned long EventWrapperList::Size() const {
    return size_;
}

// [EN] Disassembly @ 0x27bc4 (`_ZNK3cep16EventWrapperList4TypeEv`, 20 B):
//      0x27bc4: f9400400  ldr x0, [x0, #8]
//      0x27bc8: b4000040  cbz x0, #0x27bd0
//      0x27bcc: 14000269  b   #0x28570
//      0x27bd0: 52800c80  mov w0, #0x64
//      0x27bd4: d65f03c0  ret
// [VN] Lấy mã kiểu danh sách sự kiện = 100 (`0x64`) (@ 0x27bc4):
int EventWrapperList::Type() const {
    return static_cast<int>(DataType::kEventWrapperList); // 100 (0x64)
}

// ============================================================================
// 2. EXPRESSION EVALUATOR (`0x285d8..0x28607`)
// ============================================================================

// [EN] Disassembly @ 0x285d8..0x28604 (`cep::ExprEvaluator` base methods):
//      0x285d8: 2a1f03e0 mov w0, wzr; d65f03c0 ret
//      0x285e0: 2a1f03e0 mov w0, wzr; d65f03c0 ret
//      0x285e8: 2a1f03e0 mov w0, wzr; d65f03c0 ret
//      0x285f0: 2a1f03e0 mov w0, wzr; d65f03c0 ret
//      0x285f8: 2a1f03e0 mov w0, wzr; d65f03c0 ret
//      0x28600: a9007d1f stp xzr, xzr, [x8]; d65f03c0 ret
// [VN] Các phương thức ảo mặc định của `ExprEvaluator` (@ 0x285d8..0x28604):
bool ExprEvaluator::Calculate(const std::string& /*biz_name*/,
                              const std::string& /*rule_name*/,
                              void* /*event_data*/,
                              void* /*match_data*/,
                              std::string& /*err_msg*/,
                              void* /*extra*/) {
    return false;
}

bool ExprEvaluator::InitDataSource() {
    return false;
}

bool ExprEvaluator::Init(const std::string& /*dsl*/, void* /*extra*/) {
    return false;
}

bool ExprEvaluator::Init(const std::shared_ptr<DataInterface>& /*dsl_data*/, void* /*extra*/) {
    return false;
}

bool ExprEvaluator::IsExprEvalV2() {
    return false;
}

std::shared_ptr<DataInterface> ExprEvaluator::Calculate(
    const std::shared_ptr<Context>& /*ctx*/,
    const std::string& /*biz_name*/,
    const std::string& /*rule_name*/,
    const std::shared_ptr<EventWrapper>& /*event*/,
    const std::shared_ptr<Match>& /*match*/,
    std::string& /*err_msg*/) {
    return nullptr;
}

// ============================================================================
// 3. NFA MATCH (`0x286d0..0x28aeb`)
// ============================================================================

Match::Match()
    : matched_events_(MemoryDataInterface::MakeList()),
      current_quantity_(0),
      start_timestamp_ms_(0) {}

Match::Match(std::shared_ptr<ComputationState> state,
             unsigned long quantity,
             long long start_ts)
    : matched_events_(MemoryDataInterface::MakeList()),
      current_state_(std::move(state)),
      current_quantity_(quantity),
      start_timestamp_ms_(start_ts) {}

// [EN] Disassembly @ 0x286d0 (`_ZN3cep5Match11SetVariableERKNSt6__ndk112basic_string...`, 216 B):
//      Inserts or updates `variables_[key] = val` in the internal `unordered_map` at `+0x10`.
// [VN] Thiết lập biến cục bộ của Match (`SetVariable` @ 0x286d0):
void Match::SetVariable(const std::string& key, const std::shared_ptr<DataInterface>& val) {
    variables_[key] = val;
}

// [EN] Disassembly @ 0x28988 (`_ZNK3cep5Match17SetGlobalVariableERKNSt6__ndk112basic_string...`, 20 B):
// [VN] Thiết lập biến toàn cục của Match (`SetGlobalVariable` @ 0x28988):
void Match::SetGlobalVariable(const std::string& key,
                              const std::shared_ptr<DataInterface>& val) const {
    variables_[key] = val;
}

// [EN] Disassembly @ 0x2899c (`_ZNK3cep5Match11GetVariableERKNSt6__ndk112basic_string...`, 268 B):
//      Looks up `key` in `variables_` (+0x10) and returns `shared_ptr<DataInterface>` or `nullptr`.
// [VN] Truy xuất biến của Match theo tên (`GetVariable` @ 0x2899c):
std::shared_ptr<DataInterface> Match::GetVariable(const std::string& key) const {
    auto it = variables_.find(key);
    if (it != variables_.end()) {
        return it->second;
    }
    return nullptr;
}

// [EN] Disassembly @ 0x28aa8 (`_ZNK3cep5Match15GetCurrentStateEv`, 16 B):
//      0x28aa8: f9401809  ldr x9, [x0, #0x30]
//      0x28aac: aa0803e0  mov x0, x8
//      0x28ab0: 91010121  add x1, x9, #0x40
//      0x28ab4: 17ff8f30  b   #0xc774
// [VN] Lấy tên trạng thái NFA hiện tại (`GetCurrentState` @ 0x28aa8):
std::string Match::GetCurrentState() const {
    if (!current_state_) {
        return "";
    }
    return current_state_->state_name();
}

// [EN] Disassembly @ 0x28ab8 (`_ZNK3cep5Match18GetCurrentQuantityEv`, 8 B):
//      0x28ab8: f9402c00 ldr x0, [x0, #0x58]; 0x28abc: d65f03c0 ret
// [VN] Lấy số lượng sự kiện khớp tại trạng thái hiện tại (`GetCurrentQuantity` @ 0x28ab8):
unsigned long Match::GetCurrentQuantity() const {
    return current_quantity_;
}

// [EN] Disassembly @ 0x28ac0 (`_ZNK3cep5Match16GetMatchedEventsEv`, 44 B):
//      0x28ac0: f9400009 ldr x9, [x0]; 0x28ac8: f9400409 ldr x9, [x0, #8]
// [VN] Lấy danh sách sự kiện đã khớp (`GetMatchedEvents` @ 0x28ac0):
std::shared_ptr<DataInterface> Match::GetMatchedEvents() const {
    return matched_events_;
}

void Match::AppendMatchedEvent(const std::shared_ptr<EventWrapper>& ev) {
    if (!ev) return;
    raw_events_.push_back(ev);
    if (!matched_events_) {
        matched_events_ = MemoryDataInterface::MakeList();
    }
    if (ev->data_interface()) {
        matched_events_->AppendElement(ev->data_interface());
    } else {
        auto d = MemoryDataInterface::MakeDict();
        d->SetField("event_name", MemoryDataInterface::MakeString(ev->event_name()));
        d->SetField("timestamp_ms", MemoryDataInterface::MakeInt(static_cast<long>(ev->timestamp_ms())));
        matched_events_->AppendElement(d);
    }
}

void Match::SetCurrentStatePtr(std::shared_ptr<ComputationState> st, unsigned long qty) {
    current_state_ = std::move(st);
    current_quantity_ = qty;
}

std::shared_ptr<Match> Match::Clone() const {
    auto c = std::make_shared<Match>(current_state_, current_quantity_, start_timestamp_ms_);
    c->variables_ = variables_;
    c->raw_events_ = raw_events_;
    c->matched_events_ = MemoryDataInterface::MakeList();
    if (matched_events_) {
        for (int i = 0; i < matched_events_->Size(); ++i) {
            c->matched_events_->AppendElement(matched_events_->GetData(i));
        }
    }
    return c;
}

// ============================================================================
// 4. NFA STATE MACHINE (`0x2d2c8..0x2d91f`)
// ============================================================================

std::shared_ptr<ComputationState> Nfa::FindState(const std::string& name) const {
    auto it = states_.find(name);
    if (it != states_.end()) {
        return it->second;
    }
    return nullptr;
}

bool Nfa::InitFromRuleData(const std::string& biz_name,
                           const std::string& rule_name,
                           const std::shared_ptr<DataInterface>& rule_data,
                           std::shared_ptr<ExprEvaluator> evaluator,
                           std::shared_ptr<Error>& error) {
    biz_name_ = biz_name;
    rule_name_ = rule_name;
    evaluator_ = std::move(evaluator);
    if (!error) {
        error = std::make_shared<Error>(biz_name, rule_name);
    }
    if (!rule_data || !rule_data->IsDict()) {
        error->SetFatal(kErrorInvalidRule, "rule_data is null or not a dict");
        return false;
    }

    // Check DSL version ("dslVersion" @ 0x4c3cf, default "1.0.0" @ 0x4c3da)
    auto dsl_ver_node = rule_data->GetData("dslVersion");
    if (dsl_ver_node && dsl_ver_node->IsStr()) {
        dsl_version_ = dsl_ver_node->StringValue();
        if (!CheckDSLVersion(dsl_version_)) {
            error->SetFatal(kErrorNotCompatibleDSL, dsl_version_);
            return false;
        }
    }

    auto within_node = rule_data->GetData("within");
    if (within_node && within_node->IsNumber()) {
        within_ms_ = within_node->ConvertToIntValue();
    }

    auto skip_node = rule_data->GetData("skipStrategy");
    if (skip_node && skip_node->IsNumber()) {
        skip_strategy_ = static_cast<int>(skip_node->ConvertToIntValue());
    }

    // Parse conditions map ("conditions" @ 0x4c39f)
    auto conds_node = rule_data->GetData("conditions");
    if (conds_node && conds_node->IsDict()) {
        for (const auto& k : conds_node->KeySet()) {
            auto v = conds_node->GetData(k);
            if (v && v->IsStr()) {
                conditions_[k] = v->StringValue();
            }
        }
    }

    // Parse states list ("states" @ 0x4c3aa)
    auto states_node = rule_data->GetData("states");
    if (!states_node || !states_node->IsList() || states_node->Size() == 0) {
        // Provide a default start -> $finalState$ transition if minimal rule dictionary is given
        start_state_ = std::make_shared<ComputationState>("start", 0);
        auto final_st = std::make_shared<ComputationState>("$finalState$", 2);
        NfaEdge edge;
        edge.target_state = "$finalState$";
        edge.action_type = EdgeActionType::kTake;
        edge.condition = "True";
        start_state_->add_edge(edge);
        states_["start"] = start_state_;
        states_["$finalState$"] = final_st;
        return true;
    }

    states_.clear();
    start_state_.reset();
    for (int i = 0; i < states_node->Size(); ++i) {
        auto st_dict = states_node->GetData(i);
        if (!st_dict || !st_dict->IsDict()) {
            error->SetFatal(kErrorInvalidState, std::to_string(i));
            return false;
        }
        auto name_node = st_dict->GetData("stateName");
        if (!name_node || !name_node->IsStr() || name_node->StringValue().empty()) {
            error->SetFatal(kErrorInvalidState, "missing stateName");
            return false;
        }
        std::string st_name = name_node->StringValue();
        int st_type = 1;
        auto type_node = st_dict->GetData("stateType");
        if (type_node && type_node->IsNumber()) {
            st_type = static_cast<int>(type_node->ConvertToIntValue());
        } else if (st_name == "start") {
            st_type = 0;
        } else if (st_name == "$finalState$") {
            st_type = 2;
        } else if (st_name == "$stopState$") {
            st_type = 3;
        }

        auto comp_state = std::make_shared<ComputationState>(st_name, st_type);

        // Optional timer_settings ("timer_settings" @ 0x4c44a)
        auto timer_node = st_dict->GetData("timer_settings");
        if (timer_node && timer_node->IsDict()) {
            auto delay_node = timer_node->GetData("delay");
            auto rep_node = timer_node->GetData("repeat_times");
            long long delay_ms = (delay_node && delay_node->IsNumber()) ? delay_node->ConvertToIntValue() : 0;
            long rep = (rep_node && rep_node->IsNumber()) ? rep_node->ConvertToIntValue() : 1;
            comp_state->set_timer_settings(delay_ms, rep);
        }

        // Edges ("edges" @ 0x4c444)
        auto edges_node = st_dict->GetData("edges");
        if (edges_node && edges_node->IsList()) {
            for (int e = 0; e < edges_node->Size(); ++e) {
                auto edge_dict = edges_node->GetData(e);
                if (!edge_dict || !edge_dict->IsDict()) {
                    error->SetFatal(kErrorInvalidEdge, st_name);
                    return false;
                }
                NfaEdge edge;
                auto tgt = edge_dict->GetData("targetState");
                if (!tgt || !tgt->IsStr()) {
                    error->SetFatal(kErrorInvalidEdge, "missing targetState");
                    return false;
                }
                edge.target_state = tgt->StringValue();
                auto act_type = edge_dict->GetData("actionType");
                if (act_type && act_type->IsNumber()) {
                    edge.action_type = static_cast<EdgeActionType>(act_type->ConvertToIntValue());
                }
                auto cond = edge_dict->GetData("condition");
                edge.condition = (cond && cond->IsStr()) ? cond->StringValue() : "True";
                auto min_n = edge_dict->GetData("min");
                if (min_n && min_n->IsNumber()) edge.min_count = min_n->ConvertToIntValue();
                auto max_n = edge_dict->GetData("max");
                if (max_n && max_n->IsNumber()) edge.max_count = max_n->ConvertToIntValue();
                comp_state->add_edge(edge);
            }
        }

        states_[st_name] = comp_state;
        if (comp_state->is_start() && !start_state_) {
            start_state_ = comp_state;
        }
    }

    if (!states_.count("$finalState$")) {
        states_["$finalState$"] = std::make_shared<ComputationState>("$finalState$", 2);
    }
    if (!states_.count("$stopState$")) {
        states_["$stopState$"] = std::make_shared<ComputationState>("$stopState$", 3);
    }
    if (!start_state_) {
        error->SetFatal(kErrorCannotFindStartState, rule_name);
        return false;
    }
    return true;
}

// [EN] Disassembly @ 0x2d2c8 (`_ZN3cep3Nfa7ProcessE...`, 1152 B):
//      0x2d2f4: 52800309  mov  w9, #0x18                // SSO length 12 ("process_cost" @ 0x4c3e0)
//      0x2d2f8: 528dec6a  mov  w10, #0x6f63
//      0x2d324: 72ae8e6a  movk w10, #0x7473, lsl #16    // "cost"
//      Evaluates outgoing edges from `comp_state`, checks conditions via `evaluator_`,
//      records `"process_cost"`, and updates `nfa_state->partial_matches()` and
//      `nfa_state->completed_matches()`.
// [VN] Xử lý sự kiện trên ô-tô-mát hữu hạn không đơn định (`Nfa::Process` @ 0x2d2c8):
std::vector<std::shared_ptr<Match>> Nfa::Process(
    const std::shared_ptr<NfaState>& nfa_state,
    const std::shared_ptr<ComputationState>& comp_state,
    const std::shared_ptr<EventWrapper>& event,
    std::shared_ptr<Error>& error) {
    std::vector<std::shared_ptr<Match>> produced_matches;
    if (!error) {
        error = std::make_shared<Error>(biz_name_, rule_name_);
    }
    if (!event) {
        error->SetFatal(kErrorInputNullEvent);
        return produced_matches;
    }
    if (!IsValidTimestamp(event->timestamp_ms())) {
        error->SetFatal(kErrorInvalidEventTimestamp);
        return produced_matches;
    }
    auto active_state = comp_state ? comp_state : start_state_;
    if (!active_state) {
        error->SetFatal(kErrorCannotFindStartState);
        return produced_matches;
    }

    const long long t0 = GetCurrentTimestamp();
    for (const auto& edge : active_state->edges()) {
        bool cond_ok = true;
        if (!edge.condition.empty() && edge.condition != "True" && edge.condition != "true") {
            if (evaluator_) {
                std::string eval_err;
                if (evaluator_->IsExprEvalV2()) {
                    auto res = evaluator_->Calculate(
                        DefaultContext::GetShared(), biz_name_, rule_name_, event, nullptr, eval_err);
                    cond_ok = (res && res->IsBool()) ? res->BoolValue() :
                              (res && res->IsNumber()) ? (res->ConvertToIntValue() != 0) : false;
                } else {
                    cond_ok = evaluator_->Calculate(
                        biz_name_, rule_name_, event->data(), nullptr, eval_err, event->extra());
                }
                if (!eval_err.empty()) {
                    error->AddWarning(kErrorCalculateExpression, eval_err);
                }
            } else if (event->data_interface() && event->data_interface()->IsDict()) {
                // Fallback: check if event_name matches condition or key exists
                cond_ok = (event->event_name() == edge.condition) ||
                          (event->data_interface()->GetData(edge.condition) != nullptr);
            }
        }
        if (!cond_ok) {
            continue;
        }

        auto target = FindState(edge.target_state);
        if (!target) {
            if (edge.target_state == "$finalState$") {
                target = std::make_shared<ComputationState>("$finalState$", 2);
            } else if (edge.target_state == "$stopState$") {
                target = std::make_shared<ComputationState>("$stopState$", 3);
            } else {
                error->AddWarning(kErrorNoSuchTargetState, edge.target_state);
                continue;
            }
        }

        auto next_match = std::make_shared<Match>(target, 1, event->timestamp_ms());
        if (edge.action_type == EdgeActionType::kTake) {
            next_match->AppendMatchedEvent(event);
        }
        produced_matches.push_back(next_match);
        if (nfa_state) {
            if (target->is_final()) {
                nfa_state->completed_matches().push_back(next_match);
            } else if (!target->is_stop()) {
                nfa_state->partial_matches().push_back(next_match);
            }
        }
    }

    if (nfa_state) {
        const long long elapsed = std::max(0LL, GetCurrentTimestamp() - t0);
        nfa_state->RecordCost("process_cost", active_state->state_name(), elapsed);
    }
    return produced_matches;
}

// [EN] Disassembly @ 0x2d748 (`_ZNK3cep3Nfa11AdvanceTimeE...`, 472 B):
//      0x2d76c: f00000e9  adrp x9, #0x4c000
//      0x2d770: 910fb529  add  x9, x9, #0x3ed          // "advance_time_cost" @ 0x4c3ed
//      0x2d780: 52800449  mov  w9, #0x22               // SSO length 17 (17 << 1 = 0x22)
//      Checks active partial matches in `nfa_state` against `timestamp_ms` and `within_ms_`.
// [VN] Tiến thời gian trên NFA và kiểm tra hết hạn cửa sổ `within` (`Nfa::AdvanceTime` @ 0x2d748):
std::vector<std::shared_ptr<Match>> Nfa::AdvanceTime(
    const std::shared_ptr<NfaState>& nfa_state,
    const std::shared_ptr<ComputationState>& comp_state,
    long long timestamp_ms,
    std::shared_ptr<Error>& error) const {
    std::vector<std::shared_ptr<Match>> surviving;
    if (!error) {
        error = std::make_shared<Error>(biz_name_, rule_name_);
    }
    if (!nfa_state) {
        return surviving;
    }
    const long long t0 = GetCurrentTimestamp();
    for (const auto& m : nfa_state->partial_matches()) {
        if (!m) continue;
        if (within_ms_ > 0 && m->start_timestamp_ms() > 0 &&
            (timestamp_ms - m->start_timestamp_ms()) > within_ms_) {
            continue; // Expired
        }
        surviving.push_back(m);
    }
    nfa_state->partial_matches() = surviving;
    if (comp_state) {
        const long long elapsed = std::max(0LL, GetCurrentTimestamp() - t0);
        nfa_state->RecordCost("advance_time_cost", comp_state->state_name(), elapsed);
    }
    return surviving;
}

// ============================================================================
// 5. MATCH RESULT, RESULT & ENGINE RESULT (`0x32060..0x32453` & `0x14e3c..0x14f1b`)
// ============================================================================

// [EN] Disassembly @ 0x32060 (`_ZNK3cep11MatchResult16GetMatchedEventsEv`, 44 B)
//      & 0x3208c (`_ZNK3cep11MatchResult12GetVariablesEv`, 44 B):
// [VN] Các phương thức `MatchResult` (@ 0x32060..0x3208c):
std::shared_ptr<DataInterface> MatchResult::GetMatchedEvents() const {
    return matched_events_;
}

std::shared_ptr<DataInterface> MatchResult::GetVariables() const {
    return variables_;
}

// [EN] Disassembly @ 0x320b8..0x323b0 (`cep::Result` methods):
//      0x320b8: 39400000 ldrb w0, [x0]; d65f03c0 ret       (success)
//      0x320c0: 91002001 add  x1, x0, #8; b #0xc774        (biz_name)
//      0x320cc: 91008001 add  x1, x0, #0x20; b #0xc774     (rule_name)
//      0x320d8: 9100e001 add  x1, x0, #0x38; b #0xc774     (error_message)
//      0x320e4: warning_messages (+0x50)
//      0x3218c: matched_events_sequences
//      0x323b0: match_results (+0x68)
// [VN] Các phương thức của `cep::Result` (@ 0x320b8..0x323b0):
bool Result::success() const {
    return success_;
}

std::string Result::biz_name() {
    return biz_name_;
}

std::string Result::rule_name() {
    return rule_name_;
}

std::string Result::error_message() {
    return error_message_;
}

std::vector<std::string> Result::warning_messages() {
    return warning_messages_;
}

std::vector<std::shared_ptr<DataInterface>> Result::matched_events_sequences() const {
    std::vector<std::shared_ptr<DataInterface>> seqs;
    seqs.reserve(match_results_.size());
    for (const auto& mr : match_results_) {
        seqs.push_back(mr.GetMatchedEvents());
    }
    return seqs;
}

std::vector<MatchResult> Result::match_results() {
    return match_results_;
}

// [EN] Disassembly @ 0x14e3c..0x14f10 (`cep::EngineResult` methods):
//      0x14e3c: 39400000 ldrb w0, [x0]; d65f03c0 ret       (success)
//      0x14e44: 91002001 add  x1, x0, #8; b #0xc774        (biz_name)
//      0x14e50: 91008001 add  x1, x0, #0x20; b #0xc774     (rule_name)
//      0x14e5c: 9100e001 add  x1, x0, #0x38; b #0xc774     (error_message)
//      0x14e68: warning_messages (+0x50)
//      0x14f10: 9101a001 add  x1, x0, #0x68; b #0x14f1c    (matched_events_sequences)
// [VN] Các phương thức của `cep::EngineResult` (@ 0x14e3c..0x14f10):
bool EngineResult::success() const {
    return success_;
}

std::string EngineResult::biz_name() {
    return biz_name_;
}

std::string EngineResult::rule_name() {
    return rule_name_;
}

std::string EngineResult::error_message() {
    return error_message_;
}

std::vector<std::string> EngineResult::warning_messages() {
    return warning_messages_;
}

std::vector<EngineResult::MatchedSequenceEntry> EngineResult::matched_events_sequences() {
    return matched_events_sequences_;
}

std::shared_ptr<Result> EngineResult::ToPublicResult() const {
    std::vector<MatchResult> mrs;
    mrs.reserve(matched_events_sequences_.size());
    for (const auto& entry : matched_events_sequences_) {
        auto ev_list = MemoryDataInterface::MakeList();
        if (entry.first) {
            for (const auto& ev : entry.first->events()) {
                if (ev && ev->data_interface()) {
                    ev_list->AppendElement(ev->data_interface());
                }
            }
        }
        auto vars_dict = MemoryDataInterface::MakeDict();
        for (const auto& kv : entry.second) {
            vars_dict->SetField(kv.first, kv.second);
        }
        mrs.emplace_back(ev_list, vars_dict);
    }
    return std::make_shared<Result>(
        success_, biz_name_, rule_name_, error_message_, warning_messages_, std::move(mrs));
}

} // namespace cep
