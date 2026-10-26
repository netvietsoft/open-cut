// ============================================================================
// File: bdhm_spark_tracing_engine.h
// Module: libbdhm_native.so — Context Property Graph & SparkTracing Engine
//         (Kho Thuộc tính Ngữ cảnh DAG & Động cơ SparkTracing Native)
// Project: NextAI OpenCut (com.nextai.opencut)
// Task ID: TASK-091-RECONSTRUCTION-LIBBDHM_NATIVE (TASK_SO_102)
// Verification: OBSERVED from bdhm_native/src/api/context_props.rs,
//               bdhm_native/src/api/spark_tracing.rs, and
//               bdhm_native/src/api/glue.rs (.text 0x03eae0..0x046c18)
// ============================================================================

#pragma once

#include "bdhm_types.h"
#include "bdhm_expr_clause_engine.h"
#include <mutex>
#include <memory>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

namespace NextAI {
namespace OpenCut {
namespace BdhmNative {

// ============================================================================
// [EN] 1. Link Update Operation Enum (do_updateLink at 0x0434a8)
//      Verified at 0x043508..0x043510:
//        cmp w20, #1; b.eq #0x43728 (Remove parent)
//        cbnz w20, #0x43a54        (0 = Add parent, otherwise no-op)
// [VN] 1. Kiểu Thao tác Cập nhật Liên kết Cha-Con (do_updateLink tại 0x0434a8)
// ============================================================================
enum class LinkUpdateOp : int32_t {
    kAddParent    = 0,
    kRemoveParent = 1
};

// ============================================================================
// [EN] 2. Context Properties Repository (bdhm_native::api::context_props)
//      Reconstructed from .rodata 0x00be00..0x00c1e0 and .text 0x033670..0x03d904:
//        - Stores ContextInstance nodes keyed by context_id
//        - Enforces DAG topology on parent_ids (rejects rings/cycles)
//        - Supports lazy_logging (only records properties in symbols_used)
//        - Supports symbol alias mapping via symbols_map
//        - Performs TTL & dead-instance recycling during do_update (0x044274)
// [VN] 2. Kho Lưu trữ Thuộc tính Ngữ cảnh (bdhm_native::api::context_props)
// ============================================================================
class ContextPropsRepo {
public:
    explicit ContextPropsRepo(
        size_t max_capacity = kDefaultMaxContextPropsCount,
        bool lazy_logging = false,
        bool reference_mapping_enabled = false
    );

    void ConfigureSymbols(
        const std::unordered_set<std::string>& symbols_used,
        const std::unordered_map<std::string, std::string>& symbols_map
    );

    // [EN] Create or reset a ContextInstance (do_newContextProps 0x0430b0 -> 0x0339dc)
    // [VN] Tạo hoặc khởi tạo lại một ContextInstance (do_newContextProps 0x0430b0)
    bool NewContextProps(
        const std::string& id,
        uint64_t life_millis,
        bool is_static,
        bool is_leaf,
        uint64_t now_millis,
        std::string* out_log
    );

    // [EN] Check whether a context ID exists (do_isContextPropsExists 0x043318 -> 0x033670)
    // [VN] Kiểm tra sự tồn tại của ID ngữ cảnh (do_isContextPropsExists 0x043318)
    bool IsContextPropsExists(const std::string& id) const;

    // [EN] Update alive state of a context ID (do_setContextPropsAliveState 0x04337c)
    // [VN] Cập nhật trạng thái sống của ID ngữ cảnh (do_setContextPropsAliveState 0x04337c)
    bool SetContextPropsAliveState(const std::string& id, bool is_alive, std::string* out_log);

    // [EN] Set a single property on a context ID (do_setProperty 0x042cb4)
    // [VN] Thiết lập một thuộc tính đơn lẻ trên ID ngữ cảnh (do_setProperty 0x042cb4)
    bool SetProperty(
        const std::string& id,
        const std::string& key,
        const PropValue& val,
        int64_t life_millis_override,
        int64_t now_millis,
        std::string* out_log
    );

    // [EN] Set multiple properties from JSON object (do_setProperties 0x042df0)
    // [VN] Thiết lập nhiều thuộc tính từ chuỗi JSON (do_setProperties 0x042df0)
    bool SetPropertiesFromJson(
        const std::string& id,
        const std::string& props_json,
        int64_t life_millis_override,
        int64_t now_millis,
        std::string* out_log
    );

    // [EN] Get a single property, optionally traversing parent_ids recursively (do_getProperty 0x042bd4 -> 0x03d904)
    // [VN] Lấy một thuộc tính, tùy chọn duyệt đệ quy qua chuỗi cha parent_ids (do_getProperty 0x042bd4)
    bool GetProperty(
        const std::string& id,
        const std::string& key,
        bool recursive,
        PropValue* out_val
    ) const;

    // [EN] Get merged properties across context chain as JSON object (do_getProperties 0x042a40 -> 0x03d614)
    // [VN] Lấy toàn bộ thuộc tính hợp nhất trên chuỗi ngữ cảnh dưới dạng JSON (do_getProperties 0x042a40)
    std::string GetPropertiesJson(const std::string& id, bool recursive = true) const;

    // [EN] Add or remove parent link with ring/cycle detection (do_updateLink 0x0434a8)
    // [VN] Thêm hoặc xóa liên kết cha-con kèm phát hiện chu trình (do_updateLink 0x0434a8)
    bool UpdateLink(
        const std::string& child_id,
        const std::string& parent_id,
        LinkUpdateOp op,
        std::string* out_log
    );

    // [EN] Enumerate direct child context IDs of a parent (do_getChildIds 0x043a6c)
    // [VN] Liệt kê danh sách ID ngữ cảnh con trực tiếp của một nút cha (do_getChildIds 0x043a6c)
    std::vector<std::string> GetChildIds(const std::string& parent_id) const;

    // [EN] Garbage-collect dead / TTL-expired context instances (do_update 0x044274)
    // [VN] Thu gom rác các ngữ cảnh đã đóng hoặc hết hạn TTL (do_update 0x044274)
    std::vector<std::string> RecycleExpired(uint64_t now_millis, std::string* out_log);

    // [EN] Mark or check whether an event has already been computed for a context ID
    // [VN] Đánh dấu hoặc kiểm tra xem sự kiện đã được tính toán trên ID ngữ cảnh chưa
    bool HasEventComputed(const std::string& id, const std::string& event_name) const;
    void MarkEventComputed(const std::string& id, const std::string& event_name);

    // [EN] Serialize repository state to JSON for do_snapshot (0x04141c)
    // [VN] Tuần tự hóa trạng thái kho lưu trữ sang JSON cho do_snapshot (0x04141c)
    std::string SerializeRepoToJson() const;

    // [EN] Export/Import raw key-value lines using "__SYS__###" separator (0x00bf05)
    // [VN] Xuất/Nhập các dòng key-value thô sử dụng dấu phân cách "__SYS__###" (0x00bf05)
    std::vector<std::pair<std::string, std::string>> ExportToDbEntries() const;
    bool LoadFromDbEntries(
        const std::vector<std::pair<std::string, std::string>>& entries,
        std::string* out_error
    );

    size_t Size() const;

private:
    bool HasPathUnsafe(
        const std::string& start_id,
        const std::string& target_id,
        std::unordered_set<std::string>* visited
    ) const;

    std::string ResolveSymbolKeyUnsafe(const std::string& raw_key) const;

    mutable std::mutex mutex_;
    size_t max_capacity_;
    bool   lazy_logging_;
    bool   reference_mapping_enabled_;
    std::unordered_set<std::string> symbols_used_;
    std::unordered_map<std::string, std::string> symbols_map_;
    std::unordered_map<std::string, ContextInstance> instances_;
};

// ============================================================================
// [EN] 3. Top-Level SparkTracingNative Engine (bdhm_native::api::spark_tracing)
//      Matches the native object stored in SparkTracingNative.mNativeObj (J)
//      and passed as x2 (`jlong nativePtr`) to all 15 `do_*` JNI methods.
// [VN] 3. Động cơ SparkTracingNative Cấp Cao (bdhm_native::api::spark_tracing)
//      Khớp đối tượng native lưu trong SparkTracingNative.mNativeObj (J).
// ============================================================================
class SparkTracingNativeEngine {
public:
    SparkTracingNativeEngine(
        const SparkTracingConfigData& config,
        std::shared_ptr<ISparkTracingNativeClient> client
    );
    ~SparkTracingNativeEngine() = default;

    // [EN] Global logger initialization (initLogger at 0x041410: tst w2, #0xff; cset w0, ne)
    // [VN] Khởi tạo logger toàn cục (initLogger tại 0x041410)
    static void InitLogger(bool enable_debug_log);
    static bool IsLoggerEnabled();

    // [EN] 15 `do_*` operations corresponding 1:1 to exported JNI methods:
    // [VN] 15 hàm `do_*` tương ứng 1:1 với các phương thức JNI xuất khẩu:
    std::string DoSnapshot() const;                                       // 0x04141c
    bool        DoSetManifest(const std::string& manifest_json);          // 0x0429a0
    std::string DoGetProperties(const std::string& context_id) const;     // 0x042a40
    std::string DoGetProperty(                                            // 0x042bd4
        const std::string& context_id,
        const std::string& key,
        bool recursive
    ) const;
    bool        DoSetProperty(                                            // 0x042cb4
        const std::string& context_id,
        const std::string& key,
        const PropValue& val,
        int64_t life_millis,
        int64_t now_millis
    );
    bool        DoSetProperties(                                          // 0x042df0
        const std::string& context_id,
        const std::string& props_json,
        int64_t life_millis,
        int64_t now_millis
    );
    bool        DoNewContextProps(                                        // 0x0430b0
        const std::string& context_id,
        uint64_t life_millis,
        bool is_static,
        bool is_leaf,
        uint64_t now_millis = 0ULL
    );
    bool        DoIsContextPropsExists(const std::string& context_id) const; // 0x043318
    bool        DoSetContextPropsAliveState(                              // 0x04337c
        const std::string& context_id,
        bool is_alive
    );
    bool        DoUpdateLink(                                             // 0x0434a8
        const std::string& child_id,
        const std::string& parent_id,
        LinkUpdateOp op
    );
    std::vector<std::string> DoGetChildIds(const std::string& parent_id) const; // 0x043a6c
    std::string DoComputeExpr(                                            // 0x043dd4
        const std::string& context_id,
        const std::string& expr_str
    ) const;
    std::string DoCompute(                                                // 0x043f78
        const std::string& context_id,
        const std::string& event_or_manifest_json
    );
    void        DoUpdate(uint64_t now_millis = 0ULL);                     // 0x044274

    bool IsEnabled() const { return is_enabled_; }
    void SetEnabled(bool enabled) { is_enabled_ = enabled; }

    std::shared_ptr<ContextPropsRepo> GetRepo() const { return repo_; }

private:
    bool ComputeSingleDeclaredEvent(
        const std::string& context_id,
        const DeclaredEvent& ev,
        std::string* out_event_json,
        SparkTracingPerfStat* out_stat
    );

    // ABI layout mirrors SparkTracingNative in libbdhm_native.so:
    //   +0x00: client_ (JavaCallback / Box<dyn NativeClient>)
    //   +0x18: manifest_ (Arc<RwLock<DeclaredManifest>>)
    //   +0x20: repo_ (Arc<ContextPropsRepo>)
    //   +0x28: is_enabled_ (u8 boolean flag checked at [self + 0x28])
    std::shared_ptr<ISparkTracingNativeClient> client_;
    mutable std::mutex                         manifest_mutex_;
    std::shared_ptr<DeclaredManifest>          manifest_;
    std::shared_ptr<ContextPropsRepo>          repo_;
    bool                                       is_enabled_ = true;
    SparkTracingConfigData                     config_;
};

} // namespace BdhmNative
} // namespace OpenCut
} // namespace NextAI
