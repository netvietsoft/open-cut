// ======================================================================
// RECONSTRUCTED HEADER: pitaya_feature_store.h
// Library: libAndroidPitayaCore.so (ByteDance Pitaya On-Device AI Core)
// Component: NextAI OpenCut AI & Computer Vision Core (CORE_02_AI_CV)
// Architecture: AArch64 (ARMv8-A / ARM64)
//
// Description (English):
//   On-Device Feature Store & Feature Engineering pipeline:
//   time-series feature ingestion, schema generation, group queries,
//   and rolling stream aggregation reverse-engineered from
//   ByteDance Pitaya Core.
//
// Mô tả (Tiếng Việt):
//   Kho đặc trưng trên thiết bị & quy trình kỹ nghệ đặc trưng:
//   tiếp nhận đặc trưng chuỗi thời gian, sinh schema SQL, truy vấn
//   theo nhóm và tổng hợp luồng sự kiện dịch ngược từ Pitaya Core.
// ======================================================================

#pragma once

#include "pitaya_types.h"
#include "pitaya_objects.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <deque>
#include <mutex>

namespace NextAI::OpenCut::pitaya {

// ----------------------------------------------------------------------
// Bản ghi đặc trưng có dấu mốc thời gian (Timestamped Feature Item)
// ----------------------------------------------------------------------
struct FeatureItem {
    std::string name;
    std::string group;
    PTYObjectPtr value;
    double timestamp; // Unix timestamp tính bằng giây
};

// ----------------------------------------------------------------------
// Truy vấn nhóm đặc trưng (Feature Group Query)
// Demangled: pitaya::FeatureGroupQuery
// ----------------------------------------------------------------------
struct FeatureGroupQuery {
    std::string group_name;
    std::vector<std::string> feature_names;
    double start_time{0.0};
    double end_time{0.0};
    int32_t limit{100};
};

// ----------------------------------------------------------------------
// Cấu hình luồng sự kiện Schema (Schema Event Stream)
// Demangled: pitaya::SchemaEventStream
// ----------------------------------------------------------------------
struct SchemaEventStream {
    std::string stream_name;
    std::string table_name;
    std::vector<std::string> fields;
    std::string time_field{"timestamp"};
    std::string filter_condition{""};
};

// ----------------------------------------------------------------------
// FeatureStoreCore
// Demangled: pitaya::FeatureStoreCore
// ----------------------------------------------------------------------
class FeatureStoreCore {
public:
    static FeatureStoreCore& Instance();

    // Ghi nhận đặc trưng số thực (Opcode 0x2e4ccc)
    bool addFeature(const std::string& name, float val, const std::string& group = "default");
    
    // Ghi nhận đối tượng đặc trưng phức hợp
    bool addFeatureObject(const std::string& name, const PTYObjectPtr& obj, const std::string& group = "default");

    // Đóng phiên thu thập dữ liệu (Opcode 0x2e5b14)
    bool endSession(const std::string& session_id, const std::string& group = "default");

    // Tải lên nhật ký đặc trưng (nativeUpload)
    bool upload(const std::string& group = "");

    // Đọc đặc trưng theo nhóm
    PTYDictPtr getFeaturesByGroup(const std::string& group);

    // Xóa toàn bộ đặc trưng trong nhóm
    void clearGroup(const std::string& group);

private:
    FeatureStoreCore() = default;
    std::unordered_map<std::string, std::deque<FeatureItem>> group_store_;
    std::mutex mutex_;
};

// ----------------------------------------------------------------------
// FeatureEngineeringManager
// Demangled: pitaya::FeatureEngineeringManager
// ----------------------------------------------------------------------
class FeatureEngineeringManager {
public:
    static FeatureEngineeringManager& Instance();

    // Đăng ký nhóm đặc trưng (Opcode 0x1059d0)
    int32_t RegisterFeatureGroup(const PTYDictPtr& group_config);

    // Hủy đăng ký nhóm đặc trưng (Opcode 0x10ed08)
    int32_t UnRegisterFeatureGroup(const std::string& group_name);

    // Thêm đặc trưng (Opcode 0x105c6c & 0x105e08)
    int32_t AddFeature(const std::string& name, const PTYObjectPtr& value, const std::string& group);
    int32_t AddFeature(const std::string& name, float value, const std::string& group, const std::string& extra = "");

    // Đọc đặc trưng (Opcode 0x1063e8)
    PTYObjectPtr GetFeature(const std::string& name, QueryFeatureType q_type, 
                            ReturnFeatureType r_type, int32_t count, 
                            const std::string& group, const PTYDictPtr& params = nullptr);

    // Truy vấn hàng loạt nhóm đặc trưng (Opcode 0x10f4f8)
    PTYDictPtr GetGroupFeatures(const std::vector<FeatureGroupQuery>& queries);

    // Lọc đặc trưng cũ hơn ngưỡng thời gian (Opcode 0x1048f8)
    std::vector<FeatureItem> GetCacheOlderThan(const std::string& group, const std::string& name, double threshold_sec, bool remove = false);

    // Thời điểm khởi chạy Engine (Opcode 0x100b58)
    double GetLaunchTimestamp() const noexcept { return launch_timestamp_; }

private:
    FeatureEngineeringManager();
    double launch_timestamp_{0.0};
    std::unordered_map<std::string, PTYDictPtr> registered_groups_;
    std::mutex mutex_;
};

// ----------------------------------------------------------------------
// FeatureSchemaHandler
// Demangled: pitaya::FeatureSchemaHandler
// ----------------------------------------------------------------------
class FeatureSchemaHandler {
public:
    // Sinh câu truy vấn SQL từ cấu hình luồng (Opcode 0x26f220)
    static std::string GenerateSQLFromStreamConfig(
        const SchemaEventStream& stream, 
        const std::string& business, 
        const PTYDictPtr& params, 
        const std::string& table, 
        double duration_sec);

    // Đường dẫn thư viện toán tử (Opcode 0x276540)
    static std::string GetEngineOpPath();
};

} // namespace NextAI::OpenCut::pitaya
