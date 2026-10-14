// ======================================================================
// RECONSTRUCTED HEADER: pitaya_types.h
// Library: libAndroidPitayaCore.so (ByteDance Pitaya On-Device AI Core)
// Component: NextAI OpenCut AI & Computer Vision Core (CORE_02_AI_CV)
// Architecture: AArch64 (ARMv8-A / ARM64)
//
// Description (English):
//   Fundamental type definitions, object types, clean strategies,
//   task configurations, and package metadata reverse-engineered from
//   ByteDance Pitaya On-Device AI & Feature Engineering Core.
//
// Mô tả (Tiếng Việt):
//   Định nghĩa các kiểu dữ liệu cơ bản, kiểu đối tượng động, chiến lược dọn dẹp,
//   cấu hình tác vụ và metadata gói thuật toán được dịch ngược từ
//   lõi AI trên thiết bị và kỹ nghệ đặc trưng ByteDance Pitaya.
// ======================================================================

#pragma once

#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>
#include <memory>
#include <functional>
#include <unordered_map>

namespace NextAI::OpenCut::pitaya {

// ----------------------------------------------------------------------
// PTY Object Type Enum (Kiểu đối tượng động PTY)
// ----------------------------------------------------------------------
enum class PTYType : int32_t {
    PTY_NULL    = 0,
    PTY_BOOL    = 1,
    PTY_INT     = 2,  // 64-bit integer
    PTY_FLOAT   = 3,  // 32-bit float
    PTY_DOUBLE  = 4,  // 64-bit double
    PTY_STR     = 5,  // UTF-8 string
    PTY_LIST    = 6,  // Dynamic heterogeneous array
    PTY_DICT    = 7,  // Key-value dictionary
    PTY_POINTER = 8   // Raw native handle / buffer
};

// ----------------------------------------------------------------------
// Task Types (Phân loại tác vụ thực thi)
// ----------------------------------------------------------------------
enum class TaskType : int32_t {
    TASK_NORMAL             = 0,  // Standard script / rule task
    TASK_INFERENCE          = 1,  // ByteNN / PNN neural inference
    TASK_FEATURE_EXTRACTION = 2,  // On-device feature transformation
    TASK_DECISION_TREE      = 3,  // ByteDT rule tree evaluation
    TASK_TRAINING           = 4,  // On-device federated / local training
    TASK_BACKGROUND_SYNC    = 5   // Background model sync & cache update
};

// ----------------------------------------------------------------------
// Clean Strategies (Chiến lược dọn dẹp bộ nhớ đệm và dữ liệu cũ)
// Demangled: pitaya::CleanStrategy
// ----------------------------------------------------------------------
enum class CleanStrategy : int32_t {
    CLEAN_ALL       = 0,  // Xóa toàn bộ dữ liệu tạm và mô hình
    CLEAN_EXPIRED   = 1,  // Chỉ xóa các đặc trưng và bản ghi hết hạn
    CLEAN_CACHE_DIR = 2,  // Dọn dẹp thư mục bộ nhớ đệm
    CLEAN_TEMP_DIR  = 3   // Dọn dẹp tệp tải dở
};

// ----------------------------------------------------------------------
// Query & Return Feature Types
// ----------------------------------------------------------------------
enum class QueryFeatureType : int32_t {
    QUERY_KV        = 0,
    QUERY_SEQUENCE  = 1,
    QUERY_SQL       = 2,
    QUERY_REALTIME  = 3
};

enum class ReturnFeatureType : int32_t {
    RETURN_RAW      = 0,
    RETURN_JSON     = 1,
    RETURN_FLOAT_VEC= 2,
    RETURN_DICT     = 3
};

// ----------------------------------------------------------------------
// Error Structure (Cấu trúc thông báo lỗi chuẩn Pitaya)
// Demangled: pitaya::Error
// ----------------------------------------------------------------------
struct Error {
    int32_t code{0};
    std::string domain{"pitaya.default"};
    std::string message{""};

    Error() = default;
    Error(int32_t c, const std::string& dom, const std::string& msg)
        : code(c), domain(dom), message(msg) {}

    bool IsSuccess() const noexcept { return code == 0; }
};

// ----------------------------------------------------------------------
// Setup & Boot Information
// Demangled: pitaya::SetupInfo & pitaya::BootConfig
// ----------------------------------------------------------------------
struct SetupInfo {
    std::string aid{"1388"};             // App ID (CapCut / Jianying)
    std::string app_version{"21.0.0"};
    std::string device_id{""};
    std::string channel{"googleplay"};
    std::string root_dir{""};
    std::string cache_dir{""};
    int32_t plugin_version{20261014};
};

struct BootConfig {
    bool enable_feature_store{true};
    bool enable_task_schedule{true};
    bool enable_yyjson{true};
    bool enable_socket_debug{false};
    int32_t socket_port{9999};
    int32_t max_concurrency{4};
};

// ----------------------------------------------------------------------
// Package Metadata (Thông tin gói giải thuật tải về máy)
// Demangled: pitaya::PackageInfo
// ----------------------------------------------------------------------
struct PackageInfo {
    std::string business_name{""};
    std::string package_name{""};
    std::string version{"1.0.0"};
    std::string md5{""};
    std::string local_path{""};
    std::string entry_point{""};
    std::string engine_type{"bytenn"}; // bytenn, bytedt, pnn, python
    size_t package_size{0};
    bool is_ready{false};
};

// ----------------------------------------------------------------------
// Forward declarations
// ----------------------------------------------------------------------
class PTYObject;
class PTYDict;
class PTYList;
class TaskTrace;
class TaskData;
class TaskConfig;

// Con trỏ dùng chung
using PTYObjectPtr = std::shared_ptr<PTYObject>;
using PTYDictPtr = std::shared_ptr<PTYDict>;
using PTYListPtr = std::shared_ptr<PTYList>;
using ErrorPtr = std::shared_ptr<Error>;
using PackageInfoPtr = std::shared_ptr<PackageInfo>;
using TaskTracePtr = std::shared_ptr<TaskTrace>;
using TaskDataPtr = std::shared_ptr<TaskData>;
using TaskConfigPtr = std::shared_ptr<TaskConfig>;

// Định nghĩa kiểu hàm gọi lại (Callbacks)
using SetupCallback = std::function<void(bool success, const ErrorPtr& error)>;
using PackageCallback = std::function<void(bool success, const ErrorPtr& error, const PackageInfoPtr& package)>;
using TaskCallback = std::function<void(bool success, const ErrorPtr& error, const TaskDataPtr& output_data, const PackageInfoPtr& package)>;

} // namespace NextAI::OpenCut::pitaya
