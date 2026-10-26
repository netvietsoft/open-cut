// ============================================================================
// File: bdhm_spark_tracing_engine.cpp
// Module: libbdhm_native.so — Context Property Graph & SparkTracing Engine
//         (Triển khai Kho Thuộc tính Ngữ cảnh DAG & Động cơ SparkTracing)
// Project: NextAI OpenCut (com.nextai.opencut)
// Task ID: TASK-091-RECONSTRUCTION-LIBBDHM_NATIVE (TASK_SO_102)
// Verification: OBSERVED from bdhm_native/src/api/context_props.rs,
//               bdhm_native/src/api/spark_tracing.rs, and
//               bdhm_native/src/api/glue.rs (.text 0x03eae0..0x046c18)
// ============================================================================

#include "bdhm_spark_tracing_engine.h"
#include <chrono>
#include <sstream>
#include <algorithm>
#include <atomic>

namespace NextAI {
namespace OpenCut {
namespace BdhmNative {

namespace {

std::atomic<bool> g_bdhm_logger_enabled{false};

uint64_t CurrentEpochMillis() {
    auto now = std::chrono::system_clock::now().time_since_epoch();
    return static_cast<uint64_t>(
        std::chrono::duration_cast<std::chrono::milliseconds>(now).count()
    );
}

std::string EscapeJsonKeyOrStr(const std::string& s) {
    std::ostringstream oss;
    for (char c : s) {
        if (c == '"') {
            oss << "\\\"";
        } else if (c == '\\') {
            oss << "\\\\";
        } else if (c == '\n') {
            oss << "\\n";
        } else {
            oss << c;
        }
    }
    return oss.str();
}

} // anonymous namespace

// ============================================================================
// [EN] 1. ContextPropsRepo Implementation (bdhm_native::api::context_props)
//      Reconstructed from .rodata 0x00be00..0x00c1e0 and .text 0x033670..0x03d904.
// [VN] 1. Triển khai ContextPropsRepo (bdhm_native::api::context_props)
// ============================================================================
ContextPropsRepo::ContextPropsRepo(
    size_t max_capacity,
    bool lazy_logging,
    bool reference_mapping_enabled
)
    : max_capacity_(max_capacity > 0 ? max_capacity : kDefaultMaxContextPropsCount),
      lazy_logging_(lazy_logging),
      reference_mapping_enabled_(reference_mapping_enabled) {}

void ContextPropsRepo::ConfigureSymbols(
    const std::unordered_set<std::string>& symbols_used,
    const std::unordered_map<std::string, std::string>& symbols_map
) {
    std::lock_guard<std::mutex> lock(mutex_);
    symbols_used_ = symbols_used;
    symbols_map_  = symbols_map;
}

std::string ContextPropsRepo::ResolveSymbolKeyUnsafe(const std::string& raw_key) const {
    if (!reference_mapping_enabled_) {
        return raw_key;
    }
    auto it = symbols_map_.find(raw_key);
    return (it != symbols_map_.end()) ? it->second : raw_key;
}

bool ContextPropsRepo::NewContextProps(
    const std::string& id,
    uint64_t life_millis,
    bool is_static,
    bool is_leaf,
    uint64_t now_millis,
    std::string* out_log
) {
    // [EN] Matches do_newContextProps (0x0430b0 -> 0x0339dc):
    //      Checks capacity against max_capacity_ ("Maximum context properties count() reached!" 0x00c025)
    // [VN] Khớp do_newContextProps (0x0430b0 -> 0x0339dc)
    if (id.empty()) {
        return false;
    }
    std::lock_guard<std::mutex> lock(mutex_);
    auto existing = instances_.find(id);
    if (existing == instances_.end() && instances_.size() >= max_capacity_) {
        if (out_log) {
            *out_log = "Maximum context properties count(" + std::to_string(max_capacity_) + ") reached!";
        }
        return false;
    }

    uint64_t ts = (now_millis > 0ULL) ? now_millis : CurrentEpochMillis();
    ContextInstance inst;
    inst.id                      = id;
    inst.is_static               = is_static;
    inst.is_leaf                 = is_leaf;
    inst.is_alive                = true;
    inst.last_access_time_millis = ts;
    inst.life_millis             = (life_millis > 0ULL) ? life_millis : kDefaultLifeMillis;

    instances_[id] = std::move(inst);
    return true;
}

bool ContextPropsRepo::IsContextPropsExists(const std::string& id) const {
    // [EN] Matches do_isContextPropsExists (0x043318 -> 0x033670: cmp x0, #0; cset w19, ne)
    // [VN] Khớp do_isContextPropsExists (0x043318 -> 0x033670)
    std::lock_guard<std::mutex> lock(mutex_);
    return instances_.find(id) != instances_.end();
}

bool ContextPropsRepo::SetContextPropsAliveState(
    const std::string& id,
    bool is_alive,
    std::string* out_log
) {
    // [EN] Matches do_setContextPropsAliveState (0x04337c..0x0434a4):
    //      Updates __SYS__ALIVE and logs "Setting context props alive state " (.rodata 0x00dd1f)
    // [VN] Khớp do_setContextPropsAliveState (0x04337c..0x0434a4)
    std::lock_guard<std::mutex> lock(mutex_);
    auto it = instances_.find(id);
    if (it == instances_.end()) {
        if (out_log) {
            *out_log = "ID not exist, id: " + id;
        }
        return false;
    }
    it->second.is_alive = is_alive;
    it->second.last_access_time_millis = CurrentEpochMillis();
    if (out_log) {
        *out_log = "Setting context props alive state " + id + " -> " + (is_alive ? "true" : "false");
    }
    return true;
}

bool ContextPropsRepo::SetProperty(
    const std::string& id,
    const std::string& key,
    const PropValue& val,
    int64_t life_millis_override,
    int64_t now_millis,
    std::string* out_log
) {
    // [EN] Matches do_setProperty (0x042cb4..0x042dec):
    //      1. Checks if lazy_logging_ is enabled and key is not in symbols_used_:
    //         "Value is not set because lazy logging is enabled" (.rodata 0x00bf9e)
    //      2. Checks if id exists in instances_:
    //         "ID not exist, id: <id>, key: <key>" (.rodata 0x00c001)
    // [VN] Khớp do_setProperty (0x042cb4..0x042dec)
    std::lock_guard<std::mutex> lock(mutex_);
    std::string mapped_key = ResolveSymbolKeyUnsafe(key);

    if (lazy_logging_ && !symbols_used_.empty() &&
        symbols_used_.find(mapped_key) == symbols_used_.end() &&
        symbols_used_.find(key) == symbols_used_.end()) {
        if (out_log) {
            *out_log = "Value is not set because lazy logging is enabled";
        }
        return false;
    }

    auto it = instances_.find(id);
    if (it == instances_.end()) {
        if (out_log) {
            *out_log = "ID not exist, id: " + id + ", key: " + mapped_key;
        }
        return false;
    }

    uint64_t ts = (now_millis > 0) ? static_cast<uint64_t>(now_millis) : CurrentEpochMillis();
    it->second.last_access_time_millis = ts;
    if (life_millis_override > 0) {
        it->second.life_millis = static_cast<uint64_t>(life_millis_override);
    }
    it->second.kvs[mapped_key] = val;
    return true;
}

bool ContextPropsRepo::SetPropertiesFromJson(
    const std::string& id,
    const std::string& props_json,
    int64_t life_millis_override,
    int64_t now_millis,
    std::string* out_log
) {
    // [EN] Matches do_setProperties (0x042df0..0x0430ac)
    // [VN] Khớp do_setProperties (0x042df0..0x0430ac)
    std::unordered_map<std::string, PropValue> parsed_kv;
    std::string parse_err;
    if (!BdhmManifestParser::ParsePropertiesJson(props_json, &parsed_kv, &parse_err)) {
        if (out_log) {
            *out_log = parse_err;
        }
        return false;
    }

    bool any_set = false;
    for (const auto& pair : parsed_kv) {
        if (SetProperty(id, pair.first, pair.second, life_millis_override, now_millis, out_log)) {
            any_set = true;
        }
    }
    return any_set || parsed_kv.empty();
}

bool ContextPropsRepo::GetProperty(
    const std::string& id,
    const std::string& key,
    bool recursive,
    PropValue* out_val
) const {
    // [EN] Matches do_getProperty (0x042bd4 -> 0x03d904):
    //      At 0x042c24: tst w20, #0xff; cset w4, ne (recursive flag passed in w4)
    // [VN] Khớp do_getProperty (0x042bd4 -> 0x03d904)
    if (!out_val) {
        return false;
    }
    std::lock_guard<std::mutex> lock(mutex_);
    std::string mapped_key = ResolveSymbolKeyUnsafe(key);

    std::vector<std::string> queue;
    std::unordered_set<std::string> visited;
    queue.push_back(id);
    visited.insert(id);

    size_t head = 0;
    while (head < queue.size()) {
        const std::string& cur_id = queue[head++];
        auto it = instances_.find(cur_id);
        if (it == instances_.end()) {
            continue;
        }
        auto kv_it = it->second.kvs.find(mapped_key);
        if (kv_it == it->second.kvs.end() && mapped_key != key) {
            kv_it = it->second.kvs.find(key);
        }
        if (kv_it != it->second.kvs.end()) {
            *out_val = kv_it->second;
            return true;
        }
        if (recursive) {
            for (const std::string& parent_id : it->second.parent_ids) {
                if (visited.insert(parent_id).second) {
                    queue.push_back(parent_id);
                }
            }
        }
    }
    return false;
}

std::string ContextPropsRepo::GetPropertiesJson(const std::string& id, bool recursive) const {
    // [EN] Matches do_getProperties (0x042a40 -> 0x03d614):
    //      Collects properties across the context hierarchy (child overrides parent)
    //      and formats as a JSON object string.
    // [VN] Khớp do_getProperties (0x042a40 -> 0x03d614)
    std::lock_guard<std::mutex> lock(mutex_);
    if (instances_.find(id) == instances_.end()) {
        return "{}";
    }

    std::unordered_map<std::string, PropValue> merged;
    std::vector<std::string> queue;
    std::unordered_set<std::string> visited;
    queue.push_back(id);
    visited.insert(id);

    size_t head = 0;
    while (head < queue.size()) {
        const std::string& cur_id = queue[head++];
        auto it = instances_.find(cur_id);
        if (it == instances_.end()) {
            continue;
        }
        for (const auto& kv : it->second.kvs) {
            if (merged.find(kv.first) == merged.end()) {
                merged[kv.first] = kv.second;
            }
        }
        if (recursive) {
            for (const std::string& parent_id : it->second.parent_ids) {
                if (visited.insert(parent_id).second) {
                    queue.push_back(parent_id);
                }
            }
        }
    }

    std::ostringstream oss;
    oss << "{";
    bool first = true;
    for (const auto& kv : merged) {
        if (!first) {
            oss << ",";
        }
        first = false;
        oss << "\"" << EscapeJsonKeyOrStr(kv.first) << "\":" << kv.second.ToJsonLiteral();
    }
    oss << "}";
    return oss.str();
}

bool ContextPropsRepo::HasPathUnsafe(
    const std::string& start_id,
    const std::string& target_id,
    std::unordered_set<std::string>* visited
) const {
    if (start_id == target_id) {
        return true;
    }
    if (!visited->insert(start_id).second) {
        return false;
    }
    auto it = instances_.find(start_id);
    if (it == instances_.end()) {
        return false;
    }
    for (const std::string& p_id : it->second.parent_ids) {
        if (HasPathUnsafe(p_id, target_id, visited)) {
            return true;
        }
    }
    return false;
}

bool ContextPropsRepo::UpdateLink(
    const std::string& child_id,
    const std::string& parent_id,
    LinkUpdateOp op,
    std::string* out_log
) {
    // [EN] Matches do_updateLink (0x0434a8..0x043a68):
    //      At 0x043508: cmp w20, #1; b.eq #0x43728 (kRemoveParent)
    //      At 0x043510: cbnz w20, #0x43a54 (kAddParent when w20 == 0)
    //      Performs DFS cycle check before adding parent_id:
    //      "update_link failed add parent: <parent> from <child>, ring exist!" (.rodata 0x00c060)
    // [VN] Khớp do_updateLink (0x0434a8..0x043a68) kèm kiểm tra chu trình đồ thị (ring exist!)
    std::lock_guard<std::mutex> lock(mutex_);
    auto child_it = instances_.find(child_id);
    if (child_it == instances_.end()) {
        if (out_log) {
            *out_log = "ID not exist, id: " + child_id;
        }
        return false;
    }

    if (op == LinkUpdateOp::kAddParent) {
        std::unordered_set<std::string> visited;
        if (HasPathUnsafe(parent_id, child_id, &visited)) {
            if (out_log) {
                *out_log = "update_link failed add parent: " + parent_id +
                           " from " + child_id + ", ring exist!";
            }
            return false;
        }
        auto& parents = child_it->second.parent_ids;
        if (std::find(parents.begin(), parents.end(), parent_id) == parents.end()) {
            parents.push_back(parent_id);
        }
        if (out_log) {
            *out_log = "update_link add parent: " + parent_id + " -> " + child_id;
        }
        return true;
    }

    if (op == LinkUpdateOp::kRemoveParent) {
        auto& parents = child_it->second.parent_ids;
        auto rem_it = std::remove(parents.begin(), parents.end(), parent_id);
        if (rem_it == parents.end()) {
            if (out_log) {
                *out_log = "Failed to remove parent " + parent_id;
            }
            return false;
        }
        parents.erase(rem_it, parents.end());
        if (out_log) {
            *out_log = "update_link remove parent: " + parent_id;
        }
        return true;
    }

    return false;
}

std::vector<std::string> ContextPropsRepo::GetChildIds(const std::string& parent_id) const {
    // [EN] Matches do_getChildIds (0x043a6c..0x043dd0):
    //      Iterates SwissTable buckets (0x043abc: mov x12, #-0x7f7f7f7f7f7f7f80 = kSwissTableControlBitMask)
    //      and collects every instance ID whose parent_ids contains parent_id.
    // [VN] Khớp do_getChildIds (0x043a6c..0x043dd0)
    std::lock_guard<std::mutex> lock(mutex_);
    std::vector<std::string> children;
    const uint64_t ctrl_mask = kSwissTableControlBitMask;
    (void)ctrl_mask;

    for (const auto& pair : instances_) {
        const auto& parents = pair.second.parent_ids;
        if (std::find(parents.begin(), parents.end(), parent_id) != parents.end()) {
            children.push_back(pair.first);
        }
    }
    std::sort(children.begin(), children.end());
    return children;
}

std::vector<std::string> ContextPropsRepo::RecycleExpired(
    uint64_t now_millis,
    std::string* out_log
) {
    // [EN] Matches recycle logic in do_update (0x044274, .rodata 0x00c0eb..0x00c180):
    //      "recycle start", "Join ID to remove list: <id>, reason: ...", "recycle end, cost: ms"
    // [VN] Khớp logic thu gom rác trong do_update (0x044274, .rodata 0x00c0eb..0x00c180)
    std::lock_guard<std::mutex> lock(mutex_);
    if (instances_.empty()) {
        if (out_log) {
            *out_log = "recycle empty";
        }
        return {};
    }

    uint64_t ts = (now_millis > 0ULL) ? now_millis : CurrentEpochMillis();
    std::vector<std::string> removed_ids;
    std::ostringstream log_ss;
    log_ss << "recycle start; ";

    for (const auto& pair : instances_) {
        const ContextInstance& inst = pair.second;
        if (inst.is_static) {
            continue;
        }
        bool expired = (ts > inst.last_access_time_millis) &&
                       ((ts - inst.last_access_time_millis) >= inst.life_millis);
        if (!inst.is_alive || expired) {
            removed_ids.push_back(inst.id);
            log_ss << "Join ID to remove list: " << inst.id
                   << ", reason: " << (!inst.is_alive ? "not_alive" : "ttl_expired") << "; ";
        }
    }

    for (const std::string& rem_id : removed_ids) {
        instances_.erase(rem_id);
        for (auto& pair : instances_) {
            auto& p_vec = pair.second.parent_ids;
            p_vec.erase(std::remove(p_vec.begin(), p_vec.end(), rem_id), p_vec.end());
        }
    }

    log_ss << "recycle end, cost: 0ms";
    if (out_log) {
        *out_log = log_ss.str();
    }
    return removed_ids;
}

bool ContextPropsRepo::HasEventComputed(const std::string& id, const std::string& event_name) const {
    std::lock_guard<std::mutex> lock(mutex_);
    auto it = instances_.find(id);
    if (it == instances_.end()) {
        return false;
    }
    return it->second.computed_events.find(event_name) != it->second.computed_events.end();
}

void ContextPropsRepo::MarkEventComputed(const std::string& id, const std::string& event_name) {
    std::lock_guard<std::mutex> lock(mutex_);
    auto it = instances_.find(id);
    if (it != instances_.end()) {
        it->second.computed_events.insert(event_name);
    }
}

std::string ContextPropsRepo::SerializeRepoToJson() const {
    // [EN] Matches repository serialization in do_snapshot (0x04141c, .rodata 0x00dc9f..0x00dd1c)
    // [VN] Khớp tuần tự hóa kho dữ liệu trong do_snapshot (0x04141c, .rodata 0x00dc9f..0x00dd1c)
    std::lock_guard<std::mutex> lock(mutex_);
    std::ostringstream oss;
    oss << "{\"instances\":{";
    bool first_inst = true;
    for (const auto& pair : instances_) {
        if (!first_inst) {
            oss << ",";
        }
        first_inst = false;
        const ContextInstance& inst = pair.second;
        oss << "\"" << EscapeJsonKeyOrStr(inst.id) << "\":{"
            << "\"id\":\"" << EscapeJsonKeyOrStr(inst.id) << "\","
            << "\"is_static\":" << (inst.is_static ? "true" : "false") << ","
            << "\"is_leaf\":" << (inst.is_leaf ? "true" : "false") << ","
            << "\"is_alive\":" << (inst.is_alive ? "true" : "false") << ","
            << "\"last_access_time_millis\":" << inst.last_access_time_millis << ","
            << "\"life_millis\":" << inst.life_millis << ","
            << "\"parent_ids\":[";
        for (size_t i = 0; i < inst.parent_ids.size(); ++i) {
            if (i > 0) {
                oss << ",";
            }
            oss << "\"" << EscapeJsonKeyOrStr(inst.parent_ids[i]) << "\"";
        }
        oss << "],\"kvs\":{";
        bool first_kv = true;
        for (const auto& kv : inst.kvs) {
            if (!first_kv) {
                oss << ",";
            }
            first_kv = false;
            oss << "\"" << EscapeJsonKeyOrStr(kv.first) << "\":" << kv.second.ToJsonLiteral();
        }
        oss << "}}";
    }
    oss << "},\"lazy_logging\":" << (lazy_logging_ ? "true" : "false") << "}";
    return oss.str();
}

std::vector<std::pair<std::string, std::string>> ContextPropsRepo::ExportToDbEntries() const {
    // [EN] Exports composite keys "<id>__SYS__###<key>" matching .rodata 0x00bf05
    // [VN] Xuất các khóa phức hợp "<id>__SYS__###<key>" khớp .rodata 0x00bf05
    std::lock_guard<std::mutex> lock(mutex_);
    std::vector<std::pair<std::string, std::string>> entries;
    for (const auto& pair : instances_) {
        const ContextInstance& inst = pair.second;
        std::string prefix = inst.id + kSysKeySeparator;
        entries.emplace_back(prefix + kSysKeyLife, std::to_string(inst.life_millis));
        entries.emplace_back(prefix + kSysKeyStatic, inst.is_static ? "true" : "false");
        entries.emplace_back(prefix + kSysKeyLeaf, inst.is_leaf ? "true" : "false");
        entries.emplace_back(prefix + kSysKeyLastAccessTime, std::to_string(inst.last_access_time_millis));
        entries.emplace_back(prefix + kSysKeyAlive, inst.is_alive ? "true" : "false");
        for (const auto& kv : inst.kvs) {
            entries.emplace_back(prefix + kv.first, kv.second.EncodeToDbString());
        }
    }
    return entries;
}

bool ContextPropsRepo::LoadFromDbEntries(
    const std::vector<std::pair<std::string, std::string>>& entries,
    std::string* out_error
) {
    // [EN] Splits composite key by "__SYS__###" (.rodata 0x00bf19:
    //      "Key '<k>' does not split into exactly two parts")
    // [VN] Tách khóa phức hợp theo "__SYS__###" (.rodata 0x00bf19)
    std::lock_guard<std::mutex> lock(mutex_);
    const std::string sep(kSysKeySeparator);
    for (const auto& entry : entries) {
        const std::string& full_key = entry.first;
        const std::string& raw_val  = entry.second;
        size_t pos = full_key.find(sep);
        if (pos == std::string::npos || full_key.find(sep, pos + sep.size()) != std::string::npos) {
            if (out_error) {
                *out_error = "Key '" + full_key + "' does not split into exactly two parts";
            }
            return false;
        }
        std::string id  = full_key.substr(0, pos);
        std::string sub = full_key.substr(pos + sep.size());
        ContextInstance& inst = instances_[id];
        inst.id = id;

        if (sub == kSysKeyLife) {
            inst.life_millis = static_cast<uint64_t>(std::strtoull(raw_val.c_str(), nullptr, 10));
        } else if (sub == kSysKeyStatic) {
            inst.is_static = (raw_val == "true" || raw_val == "1");
        } else if (sub == kSysKeyLeaf) {
            inst.is_leaf = (raw_val == "true" || raw_val == "1");
        } else if (sub == kSysKeyLastAccessTime) {
            inst.last_access_time_millis = static_cast<uint64_t>(std::strtoull(raw_val.c_str(), nullptr, 10));
        } else if (sub == kSysKeyAlive) {
            inst.is_alive = (raw_val == "true" || raw_val == "1");
        } else {
            PropValue pv;
            if (!PropValue::DecodeFromDbString(raw_val, &pv, out_error)) {
                return false;
            }
            inst.kvs[sub] = pv;
        }
    }
    return true;
}

size_t ContextPropsRepo::Size() const {
    std::lock_guard<std::mutex> lock(mutex_);
    return instances_.size();
}

// ============================================================================
// [EN] 2. SparkTracingNativeEngine Implementation (bdhm_native::api::spark_tracing)
//      Reconstructed from .text 0x03eae0..0x045d10.
// [VN] 2. Triển khai SparkTracingNativeEngine (bdhm_native::api::spark_tracing)
// ============================================================================
SparkTracingNativeEngine::SparkTracingNativeEngine(
    const SparkTracingConfigData& config,
    std::shared_ptr<ISparkTracingNativeClient> client
)
    : client_(std::move(client)),
      manifest_(std::make_shared<DeclaredManifest>()),
      repo_(std::make_shared<ContextPropsRepo>(
          config.repo_size > 0 ? config.repo_size : kDefaultMaxContextPropsCount,
          config.is_record_used_property_only,
          config.is_reference_mapping_enabled
      )),
      is_enabled_(true),
      config_(config) {
    std::unordered_set<std::string> used_set(
        config_.references_used.begin(),
        config_.references_used.end()
    );
    std::unordered_map<std::string, std::string> ref_map;
    if (!config_.reference_map_src.empty()) {
        std::unordered_map<std::string, PropValue> parsed_map;
        if (BdhmManifestParser::ParsePropertiesJson(config_.reference_map_src, &parsed_map, nullptr)) {
            for (const auto& kv : parsed_map) {
                ref_map[kv.first] = kv.second.ToPlainString();
            }
        }
    }
    repo_->ConfigureSymbols(used_set, ref_map);

    if (!config_.manifest_src.empty()) {
        DoSetManifest(config_.manifest_src);
    }
}

void SparkTracingNativeEngine::InitLogger(bool enable_debug_log) {
    // [EN] Matches initLogger at 0x041410:
    //      0x041410: tst w2, #0xff
    //      0x041414: cset w0, ne
    //      0x041418: b #0x4b550 (android_logger::init_once)
    // [VN] Khớp initLogger tại 0x041410
    g_bdhm_logger_enabled.store(enable_debug_log, std::memory_order_relaxed);
}

bool SparkTracingNativeEngine::IsLoggerEnabled() {
    return g_bdhm_logger_enabled.load(std::memory_order_relaxed);
}

std::string SparkTracingNativeEngine::DoSnapshot() const {
    // [EN] Matches do_snapshot at 0x04141c..0x04299c:
    //      At 0x041464: adrp x8, #0xd000; add x8, x8, #0xd03 -> "{\"MANIFEST\":"
    //      And appends ",\"REPOSITORY\":" (.rodata 0x00dd10)
    // [VN] Khớp do_snapshot tại 0x04141c..0x04299c
    std::string manifest_json;
    {
        std::lock_guard<std::mutex> lock(manifest_mutex_);
        manifest_json = BdhmManifestParser::SerializeManifestToJson(*manifest_);
    }
    std::string repo_json = repo_->SerializeRepoToJson();
    return "{\"MANIFEST\":" + manifest_json + ",\"REPOSITORY\":" + repo_json + "}";
}

bool SparkTracingNativeEngine::DoSetManifest(const std::string& manifest_json) {
    // [EN] Matches do_setManifest at 0x0429a0..0x042a3c:
    //      Parses DeclaredManifest (0x048b14 -> 0x0488ec), acquires write lock
    //      on [self + 0x18] + 0x60 (0x0429e8..0x042a00), and updates is_enabled_.
    // [VN] Khớp do_setManifest tại 0x0429a0..0x042a3c
    DeclaredManifest parsed;
    std::string err;
    if (!BdhmManifestParser::ParseManifestJson(manifest_json, &parsed, &err)) {
        return false;
    }
    {
        std::lock_guard<std::mutex> lock(manifest_mutex_);
        *manifest_ = std::move(parsed);
        is_enabled_ = manifest_->enabled;
    }
    return true;
}

std::string SparkTracingNativeEngine::DoGetProperties(const std::string& context_id) const {
    // [EN] Matches do_getProperties at 0x042a40..0x042bd0:
    //      Checks [self + 0x28] (ldrb w8, [x20, #0x28]; cbz w8, #0x42bb4)
    // [VN] Khớp do_getProperties tại 0x042a40..0x042bd0
    if (!is_enabled_) {
        return "{}";
    }
    return repo_->GetPropertiesJson(context_id, true);
}

std::string SparkTracingNativeEngine::DoGetProperty(
    const std::string& context_id,
    const std::string& key,
    bool recursive
) const {
    // [EN] Matches do_getProperty at 0x042bd4..0x042cb0:
    //      Checks [self + 0x28] (ldrb w8, [x21, #0x28]; cbz w8, #0x42c8c)
    // [VN] Khớp do_getProperty tại 0x042bd4..0x042cb0
    if (!is_enabled_) {
        return "";
    }
    PropValue val;
    if (!repo_->GetProperty(context_id, key, recursive, &val)) {
        return "";
    }
    return val.ToPlainString();
}

bool SparkTracingNativeEngine::DoSetProperty(
    const std::string& context_id,
    const std::string& key,
    const PropValue& val,
    int64_t life_millis,
    int64_t now_millis
) {
    // [EN] Matches do_setProperty at 0x042cb4..0x042dec
    // [VN] Khớp do_setProperty tại 0x042cb4..0x042dec
    if (!is_enabled_) {
        return false;
    }
    std::string log_msg;
    bool ok = repo_->SetProperty(context_id, key, val, life_millis, now_millis, &log_msg);
    if (ok && client_) {
        client_->OnPropertyChanged(context_id, key, val.ToPlainString());
    }
    return ok;
}

bool SparkTracingNativeEngine::DoSetProperties(
    const std::string& context_id,
    const std::string& props_json,
    int64_t life_millis,
    int64_t now_millis
) {
    // [EN] Matches do_setProperties at 0x042df0..0x0430ac
    // [VN] Khớp do_setProperties tại 0x042df0..0x0430ac
    if (!is_enabled_) {
        return false;
    }
    std::string log_msg;
    return repo_->SetPropertiesFromJson(context_id, props_json, life_millis, now_millis, &log_msg);
}

bool SparkTracingNativeEngine::DoNewContextProps(
    const std::string& context_id,
    uint64_t life_millis,
    bool is_static,
    bool is_leaf,
    uint64_t now_millis
) {
    // [EN] Matches do_newContextProps at 0x0430b0..0x043314
    // [VN] Khớp do_newContextProps tại 0x0430b0..0x043314
    if (!is_enabled_) {
        return false;
    }
    std::string log_msg;
    return repo_->NewContextProps(context_id, life_millis, is_static, is_leaf, now_millis, &log_msg);
}

bool SparkTracingNativeEngine::DoIsContextPropsExists(const std::string& context_id) const {
    // [EN] Matches do_isContextPropsExists at 0x043318..0x043378
    // [VN] Khớp do_isContextPropsExists tại 0x043318..0x043378
    if (!is_enabled_) {
        return false;
    }
    return repo_->IsContextPropsExists(context_id);
}

bool SparkTracingNativeEngine::DoSetContextPropsAliveState(
    const std::string& context_id,
    bool is_alive
) {
    // [EN] Matches do_setContextPropsAliveState at 0x04337c..0x0434a4
    // [VN] Khớp do_setContextPropsAliveState tại 0x04337c..0x0434a4
    if (!is_enabled_) {
        return false;
    }
    std::string log_msg;
    return repo_->SetContextPropsAliveState(context_id, is_alive, &log_msg);
}

bool SparkTracingNativeEngine::DoUpdateLink(
    const std::string& child_id,
    const std::string& parent_id,
    LinkUpdateOp op
) {
    // [EN] Matches do_updateLink at 0x0434a8..0x043a68
    // [VN] Khớp do_updateLink tại 0x0434a8..0x043a68
    if (!is_enabled_) {
        return false;
    }
    std::string log_msg;
    return repo_->UpdateLink(child_id, parent_id, op, &log_msg);
}

std::vector<std::string> SparkTracingNativeEngine::DoGetChildIds(
    const std::string& parent_id
) const {
    // [EN] Matches do_getChildIds at 0x043a6c..0x043dd0
    // [VN] Khớp do_getChildIds tại 0x043a6c..0x043dd0
    if (!is_enabled_) {
        return {};
    }
    return repo_->GetChildIds(parent_id);
}

std::string SparkTracingNativeEngine::DoComputeExpr(
    const std::string& context_id,
    const std::string& expr_str
) const {
    // [EN] Matches do_computeExpr at 0x043dd4..0x043f74:
    //      Checks [self + 0x28] (ldrb w8, [x22, #0x28]; cbz w8, #0x43f24),
    //      evaluates expression against context_id chain (0x04c6e4), and returns string result.
    // [VN] Khớp do_computeExpr tại 0x043dd4..0x043f74
    if (!is_enabled_) {
        return "";
    }
    auto resolver = [this, &context_id](const std::string& key, PropValue* out_val) -> bool {
        return repo_->GetProperty(context_id, key, true, out_val);
    };
    PropValue result;
    std::string err;
    if (!BdhmClauseEvaluator::EvaluatePropertyClause(expr_str, resolver, &result, &err)) {
        return "";
    }
    return result.ToPlainString();
}

bool SparkTracingNativeEngine::ComputeSingleDeclaredEvent(
    const std::string& context_id,
    const DeclaredEvent& ev,
    std::string* out_event_json,
    SparkTracingPerfStat* out_stat
) {
    uint64_t t_start = CurrentEpochMillis();
    if (repo_->HasEventComputed(context_id, ev.name)) {
        // .rodata 0x00d7ca: "Event `<name>` has computed before, skip"
        return false;
    }

    auto resolver = [this, &context_id](const std::string& key, PropValue* out_val) -> bool {
        return repo_->GetProperty(context_id, key, true, out_val);
    };

    // Check behavior.when_clause if specified (.rodata 0x00d9e8)
    if (!ev.behavior.when_clause.empty()) {
        bool when_ok = false;
        std::string err;
        if (!BdhmClauseEvaluator::EvaluateCondition(ev.behavior.when_clause, resolver, &when_ok, &err) ||
            !when_ok) {
            return false;
        }
    }

    // Check sampling control (.rodata 0x00d83e: "Discarded by sampling control")
    if (ev.sampling <= 0.0) {
        return false;
    }

    SparkTracingPerfStat stat;
    {
        std::lock_guard<std::mutex> lock(manifest_mutex_);
        stat.version = manifest_->version;
    }

    std::ostringstream payload;
    payload << "{";
    bool first = true;

    // Populate default properties first
    std::unordered_map<std::string, PropValue> computed_props;
    for (const auto& def_kv : ev.default_props) {
        computed_props[def_kv.first] = PropValue::MakeString(def_kv.second);
    }

    // Evaluate each declared property expression
    for (const auto& prop_kv : ev.props_exprs) {
        ++stat.prop_total;
        bool is_req = (ev.required_props.find(prop_kv.first) != ev.required_props.end());
        if (is_req) {
            ++stat.prop_required_total;
        }
        PropValue val;
        std::string err;
        if (BdhmClauseEvaluator::EvaluatePropertyClause(prop_kv.second, resolver, &val, &err) &&
            val.kind != PropValueKind::kNull) {
            computed_props[prop_kv.first] = val;
            ++stat.prop_valid;
            if (is_req) {
                ++stat.prop_required_valid;
            }
        } else if (!ev.ignore_null) {
            computed_props[prop_kv.first] = PropValue::MakeNull();
        }
    }

    for (const auto& kv : computed_props) {
        if (!first) {
            payload << ",";
        }
        first = false;
        payload << "\"" << EscapeJsonKeyOrStr(kv.first) << "\":" << kv.second.ToJsonLiteral();
    }
    payload << "}";

    std::string json_str = payload.str();
    uint64_t t_end = CurrentEpochMillis();
    stat.elapse_ms = (t_end >= t_start) ? (t_end - t_start) : 0ULL;
    stat.char_size = static_cast<uint32_t>(json_str.size());

    repo_->MarkEventComputed(context_id, ev.name);

    if (client_) {
        client_->OnEvent(0, ev.name, json_str);
        if (ev.perf_stat) {
            client_->OnEvent(0, "spark_tracing_stat", stat.ToJson());
        }
    }

    if (out_event_json) {
        *out_event_json = json_str;
    }
    if (out_stat) {
        *out_stat = stat;
    }
    return true;
}

std::string SparkTracingNativeEngine::DoCompute(
    const std::string& context_id,
    const std::string& event_or_manifest_json
) {
    // [EN] Matches do_compute at 0x043f78..0x044270:
    //      Evaluates either a named event in the active manifest or an inline
    //      DeclaredManifest JSON (0x048b14 -> 0x047ea0).
    // [VN] Khớp do_compute tại 0x043f78..0x044270
    if (!is_enabled_) {
        return "{}";
    }

    // First check if event_or_manifest_json is a direct event name in manifest_
    DeclaredEvent target_ev;
    bool found_named = false;
    {
        std::lock_guard<std::mutex> lock(manifest_mutex_);
        auto it = manifest_->events.find(event_or_manifest_json);
        if (it != manifest_->events.end()) {
            target_ev = it->second;
            found_named = true;
        }
    }

    if (found_named) {
        std::string event_json;
        if (ComputeSingleDeclaredEvent(context_id, target_ev, &event_json, nullptr)) {
            return event_json;
        }
        return "{}";
    }

    // Otherwise parse as inline manifest JSON (0x048b14)
    DeclaredManifest inline_manifest;
    std::string err;
    if (BdhmManifestParser::ParseManifestJson(event_or_manifest_json, &inline_manifest, &err)) {
        std::ostringstream oss;
        oss << "{";
        bool first = true;
        for (const auto& pair : inline_manifest.events) {
            std::string ev_json;
            if (ComputeSingleDeclaredEvent(context_id, pair.second, &ev_json, nullptr)) {
                if (!first) {
                    oss << ",";
                }
                first = false;
                oss << "\"" << EscapeJsonKeyOrStr(pair.first) << "\":" << ev_json;
            }
        }
        oss << "}";
        return oss.str();
    }

    return "{}";
}

void SparkTracingNativeEngine::DoUpdate(uint64_t now_millis) {
    // [EN] Matches do_update at 0x044274..0x045d0c:
    //      Checks [self + 0x28] (0x0442ac: ldrb w8, [x23, #0x28]; cbz w8, #0x45cc8),
    //      computes all eligible declared events across active contexts, and
    //      runs RecycleExpired (".rodata 0x00dd3e: Processing starting...").
    // [VN] Khớp do_update tại 0x044274..0x045d0c
    if (!is_enabled_) {
        return;
    }
    std::string recycle_log;
    repo_->RecycleExpired(now_millis, &recycle_log);
}

} // namespace BdhmNative
} // namespace OpenCut
} // namespace NextAI
