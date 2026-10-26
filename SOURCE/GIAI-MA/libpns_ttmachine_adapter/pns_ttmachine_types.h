/**
 * @file pns_ttmachine_types.h
 * @brief Exact ABI Structs, ELF64 Memory Map, JNI Cache Table & VTables for libpns_ttmachine_adapter.so
 *        Cấu trúc ABI chuẩn xác, Bản đồ bộ nhớ ELF64, Bảng đệm JNI & VTable cho libpns_ttmachine_adapter.so
 *
 * Binary Ground Truth / Bằng chứng nhị phân thực tế:
 *   - Path: apktool-res/lib/arm64-v8a/libpns_ttmachine_adapter.so (330,032 bytes)
 *   - Dynamic Symbols: 165 total (27 exported + 138 imported)
 *   - PT_LOAD 0 (R+X): vaddr 0x000000..0x04c448 -> file 0x000000..0x04c448
 *   - PT_LOAD 1 (R+W): vaddr 0x052410..0x0557f8 -> file 0x04e410..0x050128 (file_off = vaddr - 0x4000)
 *   - Sections:
 *       .dynsym      : 0x000798..0x001758 (size 0x000fc0)
 *       .plt         : 0x006c40..0x007460 (size 0x000820)
 *       .text        : 0x007460..0x043364 (size 0x03bf04 = 245,508 bytes)
 *       .rodata      : 0x043370..0x0459f8 (size 0x002688 = 9,864 bytes)
 *       .init_array  : 0x052410..0x052420 (size 0x000010, entries: 0x007460, 0x007498)
 *       .data.rel.ro : 0x052430..0x053938 (size 0x001508 = 5,384 bytes)
 *       .data        : 0x054000..0x054128 (size 0x000128 = 296 bytes)
 *       .bss         : 0x054130..0x0557f8 (size 0x0016c8 = 5,832 bytes)
 */

#ifndef NEXTAI_OPENCUT_PNS_TTMACHINE_TYPES_H_
#define NEXTAI_OPENCUT_PNS_TTMACHINE_TYPES_H_

#include <atomic>
#include <cstdint>
#include <cstddef>
#include <functional>
#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// Forward declarations for JNI types when building outside Android NDK
// Khai báo trước các kiểu JNI khi biên dịch ngoài môi trường Android NDK
#ifndef JNIEXPORT
#define JNIEXPORT __attribute__((visibility("default")))
#define JNICALL
typedef void* jobject;
typedef void* jclass;
typedef void* jstring;
typedef void* jmethodID;
typedef void* jfieldID;
typedef void* jobjectArray;
typedef uint8_t jboolean;
typedef int32_t jint;
typedef int64_t jlong;
typedef double jdouble;
struct _JNIEnv;
struct _JavaVM;
typedef _JNIEnv JNIEnv;
typedef _JavaVM JavaVM;
#endif

/**
 * Forward declaration of TTMachine transparent execution context (imported from libTTMachineCore.so).
 * Khai báo trước ngữ cảnh thực thi trong suốt của TTMachine (nhập từ libTTMachineCore.so).
 *
 * Disassembly layout verified at 0x036110..0x036138 and 0x036edc..0x036ee4:
 *   +0x00: void* vm_state
 *   +0x08: void* register_frame
 *   +0x10: void* ext_data_ctx
 *   +0x18: int32_t* error_code_ptr (checked via ldr x8, [x6, #0x18]; ldr w8, [x8]; cbnz w8)
 *   +0x20: void* allocator_pool_ptr (passed with +0x18 via ldp x3, x2, [x6, #0x18] to TTMListO_create)
 */
struct __TTMTransparentStruct {
    void* vm_state;            // +0x00: Pointer to TTM VM state / Con trỏ trạng thái máy ảo TTM
    void* register_frame;      // +0x08: Active register frame / Khung thanh ghi hiện hành
    void* ext_data_ctx;        // +0x10: External data context / Ngữ cảnh dữ liệu mở rộng
    int32_t* error_code_ptr;   // +0x18: Business error code pointer / Con trỏ mã lỗi nghiệp vụ
    void* allocator_pool_ptr;  // +0x20: Object pool allocator / Bộ cấp phát vùng nhớ đối tượng
};

/**
 * TTMachine String / Object wrapper layout verified at 0x0363dc..0x0363ec and 0x036f14..0x036f18:
 *   ldr x8, [x1]
 *   ldr x20, [x8, #0x28]  -> C-string pointer at offset +0x28!
 * Bố cục đối tượng chuỗi/tham số TTMachine xác minh tại 0x0363dc..0x0363ec và 0x036f14..0x036f18:
 *   Con trỏ chuỗi C nằm chính xác tại độ lệch +0x28!
 */
struct TTMObjectValue {
    uint64_t header_type;      // +0x00: Object tag & refcount / Nhãn kiểu & bộ đếm tham chiếu
    uint64_t reserved_08;      // +0x08: Reserved metadata / Siêu dữ liệu dự phòng
    uint64_t reserved_10;      // +0x10: Reserved flags / Cờ dự phòng
    uint64_t numeric_val;      // +0x18: Integer/Double payload / Giá trị số nguyên/thực
    uint64_t str_length;       // +0x20: String length / Độ dài chuỗi
    const char* c_str_ptr;     // +0x28: Null-terminated C-string pointer / Con trỏ chuỗi C kết thúc null
};

namespace pns {
namespace ttmachine {

// ============================================================================
// 1. ELF64 Binary Constants & Global .data / .bss Addresses
//    Hằng số nhị phân ELF64 & Địa chỉ toàn cục trên .data / .bss
// ============================================================================
struct BinaryLayout {
    // .init_array constructors (0x052410..0x052420)
    static constexpr uint64_t kInitArray0VA = 0x007460ULL; // Allocates 0x248-byte JniCacheTable -> 0x0541e8
    static constexpr uint64_t kInitArray1VA = 0x007498ULL; // Inits global maps at 0x054208 & 0x054230, jumps to 0x014598

    // .data section (0x054000..0x054128, file offset 0x050000..0x050128)
    static constexpr uint64_t kJniNativeMethodTableVA = 0x054000ULL; // 9 entries * 24 bytes = 0xD8 bytes (0x054000..0x0540d8)
    static constexpr uint64_t kDefaultSampleRateVA    = 0x0540d8ULL; // 0x0000006400000001 (version=1, sample_rate=100)
    static constexpr uint64_t kDefaultConstVersionVA  = 0x0540e0ULL; // 0x00000000ffffffff (-1)
    static constexpr uint64_t kTlsEnvSlotVA           = 0x0540e8ULL; // TLS JNIEnv slot #1 (TTMAdapter)
    static constexpr uint64_t kTlsEnvSlot2VA          = 0x054108ULL; // TLS JNIEnv slot #2 (CEP/RuleEngine)

    // .bss section (0x054130..0x0557f8)
    static constexpr uint64_t kJniCacheTablePtrVA     = 0x0541e8ULL; // JniCacheTable* (allocated 0x248 B at 0x00746c)
    static constexpr uint64_t kGlobalJavaVmPtrVA      = 0x0541f0ULL; // JavaVM* saved in JNI_OnLoad (0x00d45c)
    static constexpr uint64_t kIsActivatedFlagVA      = 0x0541f8ULL; // std::atomic<bool> g_is_activated (0x00fc80)
    static constexpr uint64_t kDebugLogEnabledVA      = 0x0541fcULL; // bool g_debug_log (0x00d594)
    static constexpr uint64_t kRuleEngineHolderPtrVA  = 0x054200ULL; // shared_ptr<RuleEngine>* (0x00d5ec)
    static constexpr uint64_t kTtmCustomFuncMapVA     = 0x054208ULL; // unordered_map<string, TTMCustomFunc> (0x0074b4)
    static constexpr uint64_t kCepCustomFuncMapVA     = 0x054230ULL; // unordered_map<string, CepCustomFunc> (0x0074dc)
    static constexpr uint64_t kTtmAdapterGuardVA      = 0x055608ULL; // __cxa_guard for TTMAdapter state (0x00c25c)
    static constexpr uint64_t kTtmAdapterBdiPtrVA     = 0x055610ULL; // Global BDI state pointer (0x00c26c)
    static constexpr uint64_t kTtmAdapterRwLockPtrVA  = 0x055618ULL; // pthread_rwlock_t* for TTMAdapter (0x008918)
    static constexpr uint64_t kRuleEngineGuardVA      = 0x055660ULL; // __cxa_guard for RuleEngine singleton (0x02b680)
    static constexpr uint64_t kRuleEngineSharedPtrVA  = 0x055670ULL; // shared_ptr<RuleEngine> (0x02b768)
    static constexpr uint64_t kRuleEngineRwLockPtrVA  = 0x055680ULL; // pthread_rwlock_t* for RuleEngine (0x00fcb0)
    static constexpr uint64_t kRuleEngineStrategyStVA = 0x055698ULL; // Strategy ready state (1 = ready at 0x00fcc0)
    static constexpr uint64_t kCoreDebugFlagVA        = 0x0556a0ULL; // PnsRuleEngine-Core debug flag (0x00d598)
    static constexpr uint64_t kNameListGuardVA        = 0x055768ULL; // __cxa_guard for NameListManager (0x0363f8)
    static constexpr uint64_t kNameListStateVA        = 0x055770ULL; // NameList status (0=init, 1=loading, 2=ready, 3=err)
    static constexpr uint64_t kNameListRwLockPtrVA    = 0x055778ULL; // pthread_rwlock_t* for NameListManager (0x039670)
    static constexpr uint64_t kNameListMapVA          = 0x055780ULL; // unordered_map<string, shared_ptr<NameListContainer>>

    // Mersenne Twister MT19937 Constants verified at 0x036280..0x036388 & 0x036fd4..0x037004
    static constexpr uint32_t kMt19937N               = 624U;        // 0x270 state words (cmp x9, #0x270 at 0x037000)
    static constexpr uint32_t kMt19937M               = 397U;        // Offset 0xc68 / 8 = 397 (ldr x11, [sp, #0xc68] at 0x0362e0)
    static constexpr uint32_t kMt19937InitMult        = 0x6c078965U; // 1812433253 (mov w10, #0x8965; movk w10, #0x6c07, lsl #16)
    static constexpr uint32_t kMt19937MatrixA         = 0x9908b0dfU; // Twist polynomial (mov w14, #0xb0df; movk w14, #0x9908, lsl #16)
    static constexpr uint32_t kMt19937TemperMaskB     = 0x9d2c5680U; // Tempering mask B (mov w11, #0x5680; movk w11, #0x9d2c, lsl #16)
    static constexpr uint32_t kMt19937TemperMaskC     = 0xefc60000U; // Tempering mask C (mov w13, #-0x103a0000 at 0x036344)
};

// ============================================================================
// 2. JNI Class & Method ID Cache Table (0x248 = 584 bytes at 0x0541e8)
//    Bảng đệm Lớp & Phương thức JNI (0x248 = 584 byte tại 0x0541e8)
// ============================================================================
/**
 * Allocated in init_array_0 (0x007460..0x007494):
 *   mov w0, #0x248; bl _Znwm; mov w2, #0x248; mov w1, wzr; bl memset
 *   adrp x8, #0x54000; str x19, [x8, #0x1e8]
 * Populated in cache_jni_ids_part1 (0x00fec4) & cache_jni_ids_part2 (0x0103a0).
 */
struct JniCacheTable {
    // Class global references (0x000..0x090, populated in 0x00fec4..0x01039c)
    jclass cls_execute_result;         // +0x000: com/bytedance/pns/engine/ExecuteResult (0x0442c2)
    jclass cls_async_callback;         // +0x008: com/bytedance/pns/engine/AsyncCallback (0x0442e9)
    jclass cls_config_provider;        // +0x010: com/bytedance/pns/engine/ConfigProvider (0x044310)
    jclass cls_array_list;             // +0x018: java/util/ArrayList (0x044338)
    jclass cls_strategy_result;        // +0x020: com/bytedance/pns/engine/StrategyResult (0x04434c)
    jclass cls_action;                 // +0x028: com/bytedance/pns/engine/Action (0x044374)
    jclass cls_param_provider;         // +0x030: com/bytedance/pns/engine/ParamProvider (0x044394)
    jclass cls_double;                 // +0x038: java/lang/Double (0x0443bb)
    jclass cls_long;                   // +0x040: java/lang/Long (0x0443de)
    jclass cls_number;                 // +0x048: java/lang/Number (0x0443ed)
    jclass cls_decision_statistics;    // +0x050: com/bytedance/pns/engine/DecisionStatistics (0x0443fe)
    jclass cls_init_statistics;        // +0x058: com/bytedance/pns/engine/InitStatistics (0x04442a)
    jclass cls_boolean;                // +0x060: java/lang/Boolean (0x0443cc) — used at 0x00fafc!
    jclass cls_object;                 // +0x068: java/lang/Object (0x044452)
    jclass cls_string;                 // +0x070: java/lang/String (0x044463)
    jclass cls_file_kits;              // +0x078: com/bytedance/pns/engine/internal/FileKits (0x044474)
    jclass cls_map;                    // +0x080: java/util/Map (0x04449f)
    jclass cls_list;                   // +0x088: java/util/List (0x0444ad)
    jclass cls_object_array;           // +0x090: [Ljava/lang/Object; (0x0444bc)

    // Method IDs (0x098..0x240, populated in 0x0103a0..0x010f80)
    jmethodID mid_exec_result_init;    // +0x098: ExecuteResult.<init>()V
    jmethodID mid_array_list_init;     // +0x0a0: ArrayList.<init>()V
    jmethodID mid_strategy_res_init;   // +0x0a8: StrategyResult.<init>()V
    jmethodID mid_action_init;         // +0x0b0: Action.<init>()V
    jmethodID mid_double_value_of;     // +0x0b8: Double.valueOf(D)Ljava/lang/Double;
    jmethodID mid_boolean_value_of;    // +0x0c0: Boolean.valueOf(Z)Ljava/lang/Boolean; (used at 0x00fb00!)
    jmethodID mid_long_value_of;       // +0x0c8: Long.valueOf(J)Ljava/lang/Long;
    jmethodID mid_decision_stat_init;  // +0x0d0: DecisionStatistics.<init>()V
    jmethodID mid_init_stat_init;      // +0x0d8: InitStatistics.<init>()V
    jmethodID mid_list_size;           // +0x0e0: List.size()I (used at 0x00fd9c!)
    jmethodID mid_list_get;            // +0x0e8: List.get(I)Ljava/lang/Object; (used at 0x00fe14!)
    jmethodID mid_array_list_add;      // +0x0f0: ArrayList.add(Ljava/lang/Object;)Z
    jmethodID mid_exec_set_trigger_id; // +0x0f8: ExecuteResult.setTriggerId(Ljava/lang/String;)V
    jmethodID mid_exec_set_results;    // +0x100: ExecuteResult.setResults(Ljava/util/List;)V
    jmethodID mid_exec_set_stats;      // +0x108: ExecuteResult.setStatistics(LDecisionStatistics;)V
    jmethodID mid_exec_set_error_msg;  // +0x110: ExecuteResult.setErrorMsg(Ljava/lang/String;)V
    jmethodID mid_strat_set_actions;   // +0x118: StrategyResult.setActions(Ljava/util/List;)V
    jmethodID mid_strat_set_sample;    // +0x120: StrategyResult.setSampleRate(Ljava/lang/Double;)V
    jmethodID mid_strat_set_graph;     // +0x128: StrategyResult.setGraphPath(Ljava/lang/String;)V
    jmethodID mid_strat_set_node_cnt;  // +0x130: StrategyResult.setExecuteNodeCount(Ljava/lang/Long;)V
    jmethodID mid_strat_set_id;        // +0x138: StrategyResult.setStrategyId(Ljava/lang/String;)V
    jmethodID mid_strat_set_name;      // +0x140: StrategyResult.setStrategyName(Ljava/lang/String;)V
    jmethodID mid_ strat_set_err;      // +0x148: StrategyResult.setErrorMsg(Ljava/lang/String;)V
    jmethodID mid_async_on_call;       // +0x150: AsyncCallback.onCall(LExecuteResult;)V
    jmethodID mid_action_set_name;     // +0x158: Action.setName(Ljava/lang/String;)V
    jmethodID mid_action_set_fixed;    // +0x160: Action.setConfigFixedParam(Ljava/util/Map;)V
    jmethodID mid_action_set_compute;  // +0x168: Action.setComputeResult(Ljava/util/Map;)V
    jmethodID mid_action_set_id;       // +0x170: Action.setActionId(Ljava/lang/String;)V
    jmethodID mid_param_provider_get;  // +0x178: ParamProvider.get(Ljava/lang/String;)Ljava/lang/Object; (0x0135f0)
    jmethodID mid_cfg_const_pool;      // +0x180: ConfigProvider.getConstPoolConfig()LConstPoolConfig;
    jmethodID mid_file_kits_load;      // +0x188: FileKits.loadAssets(LConfigProvider;)Ljava/util/List;
    jmethodID mid_dstat_set_version;   // +0x190: DecisionStatistics.setVersion(I)V
    jmethodID mid_dstat_set_total;     // +0x198: DecisionStatistics.setTotalCostTime(J)V
    jmethodID mid_dstat_set_jni;       // +0x1a0: DecisionStatistics.setJniCostTime(J)V
    jmethodID mid_dstat_set_core;      // +0x1a8: DecisionStatistics.setCoreCostTime(J)V
    jmethodID mid_dstat_set_slist_id;  // +0x1b0: DecisionStatistics.setStrategyListId(Ljava/lang/String;)V
    jmethodID mid_dstat_set_exec_cost; // +0x1b8: DecisionStatistics.setStrategyExecuteCostTime(J)V
    jmethodID mid_dstat_set_sel_cost;  // +0x1c0: DecisionStatistics.setStrategySelectCostTime(J)V
    jmethodID mid_dstat_set_sync;      // +0x1c8: DecisionStatistics.setSync(Z)V
    jmethodID mid_dstat_set_trig_id;   // +0x1d0: DecisionStatistics.setTriggerId(Ljava/lang/String;)V
    jmethodID mid_istat_set_total;     // +0x1d8: InitStatistics.setTotalCost(J)V
    jmethodID mid_istat_set_trigger;   // +0x1e0: InitStatistics.setParseTriggerCost(J)V
    jmethodID mid_istat_set_slist;     // +0x1e8: InitStatistics.setParseStrategyListCost(J)V
    jmethodID mid_istat_set_strategy;  // +0x1f0: InitStatistics.setParseStrategyCost(J)V
    jmethodID mid_istat_set_action;    // +0x1f8: InitStatistics.setParseActionCost(J)V
    jmethodID mid_istat_set_cpool;     // +0x200: InitStatistics.setParseConstPoolCost(J)V
    jmethodID mid_istat_set_json;      // +0x208: InitStatistics.setParseStrToJsonCost(J)V
    jmethodID mid_istat_set_cond;      // +0x210: InitStatistics.setParseConditionCost(J)V
    jmethodID mid_map_get;             // +0x218: Map.get(Ljava/lang/Object;)Ljava/lang/Object;
    jmethodID mid_obj_to_string;       // +0x220: Object.toString()Ljava/lang/String;
    jmethodID mid_num_double_value;    // +0x228: Number.doubleValue()D
    jmethodID mid_num_long_value;      // +0x230: Number.longValue()J
    jmethodID mid_bool_boolean_value;  // +0x238: Boolean.booleanValue()Z
    uint64_t  reserved_240;            // +0x240: Padding to 0x248 (584 bytes)
};
static_assert(sizeof(JniCacheTable) == 0x248, "JniCacheTable must be exactly 0x248 (584) bytes");

// ============================================================================
// 3. NameList Container & Matching Mode Structures
//    Cấu trúc NameListContainer & Chế độ khớp danh sách tên
// ============================================================================
/**
 * Disassembled jump table at 0x03adc4..0x03ade4 using .rodata offset table at 0x0437b6:
 *   0: Exact match (unordered_set<string>)
 *   1: Prefix match (starts_with / trie)
 *   2: Suffix match (ends_with)
 *   3: Substring / contains match (mat / val)
 *   4: Wildcard / regex match
 *   5: Domain & URL path tree match (mer / mat / val / _next / next_in)
 */
enum class NameListMatchWay : int32_t {
    kExactMatch     = 0,
    kPrefixMatch    = 1,
    kSuffixMatch    = 2,
    kContainsMatch  = 3,
    kRegexWildcard  = 4,
    kDomainPathTree = 5
};

struct DomainPathNode {
    std::string token;
    bool is_terminal = false;
    bool is_wildcard = false;
    std::unordered_map<std::string, std::shared_ptr<DomainPathNode>> next_segments;
    std::unordered_set<std::string> matched_paths;
};

struct NameListContainer {
    std::string list_key;
    NameListMatchWay default_match_way = NameListMatchWay::kExactMatch;
    std::unordered_set<std::string> exact_items;
    std::vector<std::string> prefix_items;
    std::vector<std::string> suffix_items;
    std::vector<std::string> contains_items;
    std::shared_ptr<DomainPathNode> domain_tree_root;

    // Matches token sequence against the container (0x03ac80)
    // Khớp chuỗi token với container danh sách tên (0x03ac80)
    bool MatchTokens(const std::vector<std::string>& tokens, int32_t match_mode_override) const;
};

// ============================================================================
// 4. Decision Tree, Condition, Action & Strategy Structures
//    Cấu trúc Cây quyết định, Điều kiện, Hành động & Chiến lược
// ============================================================================
enum class ConditionType : int32_t {
    kUndefined  = 0,
    kTtmRule    = 1, // TTM bytecode decoded via ttm_preprocess_sign_decode ("exp" / "rule")
    kCepRule    = 2  // CEP rule registered via cep::EngineManager::RegisterRule ("cep" / "rules")
};

struct RuleCondition {
    std::string cond_id;                // "cond_id" (0x0450f7)
    ConditionType cond_type = ConditionType::kTtmRule; // "cond_type" (0x0450ff)
    std::string raw_expr;               // "cond" (0x045109)
    std::vector<uint8_t> ttm_bytecode;  // Decoded TTM bytecode buffer
    bool cep_registered = false;        // Registered in cep::EngineManager
};

struct DecisionAction {
    std::string action_id;              // "action_id" (0x045331)
    std::string name;                   // "conf" / "name" (0x04536a)
    std::unordered_map<std::string, std::string> fixed_params;   // "fixed_params" (0x0453ae)
    std::unordered_map<std::string, std::string> runtime_params; // "runtime_params" (0x0453c3)
};

struct DecisionBranchEdge {
    bool is_leaf = false;               // "is_leaf" (0x0453d2)
    std::string next_node_id;           // "next_node_id" (0x04544d)
    std::vector<std::string> action_ids;// "action_ids" (0x0453fe)
    std::string saved_result_key;       // "saved_result_key" (0x0453da)
    std::string saved_result_value;     // "saved_result_value" (0x0453eb)
    bool stop_following_strategies = false; // "stop_following_strategies" (0x045433)
};

struct DecisionTreeNode {
    std::string node_id;
    std::string cond_id;                // "cond_id" (0x0450f7)
    ConditionType cond_type = ConditionType::kTtmRule;
    std::shared_ptr<RuleCondition> inline_condition;
    DecisionBranchEdge cond_true;       // "cond_true" (0x045137)
    DecisionBranchEdge cond_false;      // "cond_false" (0x045141)
};

struct StrategyDefinition {
    std::string strategy_id;            // "strategy_id" (0x045006)
    std::string strategy_name;
    std::string start_node_id;          // "start_node_id" (0x04504b) inside "root" (0x045046)
    std::string seed_key;               // "seed" (0x04509a)
    double sample_rate = 1.0;           // Strategy sampling rate [0.0, 1.0]
    std::unordered_map<std::string, DecisionTreeNode> decision_tree; // "decision_tree" (0x04509f)
};

struct StrategyListConfig {
    std::string strategy_list_id;       // "strategy_list_id" / "sl_id" (0x044e98)
    std::vector<std::string> sync_strategies;  // "strategies"
    std::vector<std::string> async_strategies; // "async_strategies" / "async" (0x044fbc)
};

struct InitStatisticsRecord {
    int64_t total_cost_us = 0;               // setTotalCost (0x044804)
    int64_t parse_trigger_cost_us = 0;       // setParseTriggerCost (0x044811)
    int64_t parse_strategy_list_cost_us = 0; // setParseStrategyListCost (0x044825)
    int64_t parse_strategy_cost_us = 0;      // setParseStrategyCost (0x04483e)
    int64_t parse_action_cost_us = 0;        // setParseActionCost (0x044853)
    int64_t parse_const_pool_cost_us = 0;    // setParseConstPoolCost (0x044866)
    int64_t parse_str_to_json_cost_us = 0;   // setParseStrToJsonCost (0x04487c)
    int64_t parse_condition_cost_us = 0;     // setParseConditionCost (0x044892)
};

struct StrategyExecutionRecord {
    std::string strategy_id;
    std::string strategy_name;
    std::string graph_path;                  // e.g. "node1.T#node2.F#" (.T# / .F# / .E# at 0x04554c..0x045554)
    int64_t execute_node_count = 0;
    double sample_rate = 1.0;
    std::string error_msg;
    std::vector<DecisionAction> matched_actions;
};

struct ExecuteResultRecord {
    std::string trigger_id;
    std::string strategy_list_id;
    std::string error_msg;
    int32_t version = -1;
    bool is_sync = true;
    int64_t total_cost_us = 0;
    int64_t jni_cost_us = 0;
    int64_t core_cost_us = 0;
    int64_t strategy_select_cost_us = 0;
    int64_t strategy_execute_cost_us = 0;
    std::vector<StrategyExecutionRecord> results;
};

} // namespace ttmachine
} // namespace pns

#endif // NEXTAI_OPENCUT_PNS_TTMACHINE_TYPES_H_
