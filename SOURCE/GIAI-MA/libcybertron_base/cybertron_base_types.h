// ============================================================================
// File: cybertron_base_types.h
// Target: libcybertron_base.so (509,816 bytes)
// SHA-256: 0d969c7e981d68f46d81986a0f16881d1ff9605afb9e6e352f1ae88a5695c7e6
// Task ID: TASK-142-RECONSTRUCTION-LIBCYBERTRON-BASE / TASK_SO_105_libcybertron_base
// Architecture: AArch64 (ELF64 Little-Endian, .eh_frame_hdr @ 0x069c8c = 1,201 FDEs)
// ============================================================================
// [EN] Clean-room C++17 type definitions, ABI struct layouts, Pitaya dynamic bridge
//      declarations, and DataCenter / FeatureCenter / ClientAI core interfaces for
//      ByteDance Cybertron Base (com.ttkmedia.datacenter.*).
// [VN] Định nghĩa kiểu dữ liệu C++17 tái tạo sạch, bố cục struct chuẩn ABI, khai báo
//      cầu nối động Pitaya và giao diện lõi DataCenter / FeatureCenter / ClientAI cho
//      ByteDance Cybertron Base (com.ttkmedia.datacenter.*).
// ============================================================================

#pragma once

#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <memory>
#include <mutex>
#include <atomic>
#include <functional>
#include <jni.h>

namespace datacenter {

// [EN] Binary forensic constants verified directly against libcybertron_base.so ELF64 image.
// [VN] Các hằng số pháp y nhị phân đã đối chiếu trực tiếp với ảnh ELF64 libcybertron_base.so.
constexpr uint32_t kCybertronBinarySizeBytes  = 509816U;
constexpr uint32_t kCybertronEhFrameHdrVa     = 0x069c8cU;
constexpr uint32_t kCybertronTotalFdeCount    = 1201U;
constexpr uint32_t kCybertronExportCount      = 1443U;
constexpr uint32_t kCybertronImportCount      = 131U;
constexpr uint32_t kCybertronTextSectionVa    = 0x03b220U;
constexpr uint32_t kCybertronTextSectionSize  = 0x02a88cU;
constexpr uint32_t kCybertronRodataSectionVa  = 0x065ab0U;
constexpr uint32_t kCybertronRodataSize       = 0x0041daU;
constexpr uint32_t kCybertronDataRelRoVa      = 0x07c1f8U;
constexpr uint32_t kCybertronBssSectionVa     = 0x080000U;
constexpr uint32_t kCybertronJniVersion16     = 0x00010006U;

// [EN] Reciprocal multiplication constants used in DCTime* functions (0x05d0ec..0x05d1b4).
// [VN] Các hằng số nhân nghịch đảo dùng trong nhóm hàm DCTime* (0x05d0ec..0x05d1b4).
constexpr uint64_t kReciprocalDiv1e9Multiplier = 0x431BDE82D7B634DBULL; // umulh(x, M) >> 18 == x / 1,000,000,000
constexpr uint32_t kReciprocalDiv1e9Shift      = 18U;
constexpr uint64_t kReciprocalDiv1e3Multiplier = 0x20C49BA5E353F7CFULL; // umulh(x >> 3, M) >> 4 == x / 1,000
constexpr uint32_t kReciprocalDiv1e3PreShift   = 3U;
constexpr uint32_t kReciprocalDiv1e3PostShift  = 4U;

// [EN] ProducerType enumeration returned by FeatureProducer subclasses:
//      AndroidFeatureProducer::getProducerType() @ 0x062fc8 -> 0 (mov w0, wzr)
//      PlaybackFeatureProducer::getProducerType() @ 0x053a6c -> 1 (mov w0, #1)
//      SettingsFeatureProducer::getProducerType() @ 0x063cdc -> 2 (mov w0, #2)
// [VN] Kiểu liệt kê ProducerType trả về bởi các lớp con FeatureProducer:
//      AndroidFeatureProducer::getProducerType() @ 0x062fc8 -> 0 (mov w0, wzr)
//      PlaybackFeatureProducer::getProducerType() @ 0x053a6c -> 1 (mov w0, #1)
//      SettingsFeatureProducer::getProducerType() @ 0x063cdc -> 2 (mov w0, #2)
enum class ProducerType : int32_t {
    kAndroidProducer  = 0,
    kPlaybackProducer = 1,
    kSettingsProducer = 2,
};

// [EN] DCObject runtime value type tag (verified from DCObject / DCNull / DCBool / DCInt / DCFloat / DCString / DCDict / DCList).
// [VN] Nhãn kiểu giá trị thời gian chạy của DCObject (xác minh từ DCObject / DCNull / DCBool / DCInt / DCFloat / DCString / DCDict / DCList).
enum class DCObjectType : int32_t {
    kNull   = 0,
    kBool   = 1,
    kInt    = 2,
    kFloat  = 3,
    kString = 4,
    kList   = 5,
    kDict   = 6,
};

enum class DataCenterEvent : int32_t {
    kEventUnknown        = 0,
    kEventPlayStart      = 1,
    kEventPlayStop       = 2,
    kEventBufferingStart = 3,
    kEventBufferingEnd   = 4,
    kEventFirstFrame     = 5,
    kEventAlgTaskFinish  = 6,
    kEventCustomBusiness = 100,
};

enum class DCMsgWhat : int32_t {
    kMsgNone            = 0,
    kMsgBusinessEvent   = 1,
    kMsgIOStrategy      = 2,
    kMsgLiveStrategy    = 3,
    kMsgPlayerEvent     = 4,
    kMsgAlgTaskResult   = 5,
    kMsgPersistRecords  = 6,
};

enum class MessageTaskType : int32_t {
    kTaskNormal = 0,
    kTaskSmart  = 1,
    kTaskDelay  = 2,
    kTaskLoop   = 3,
};

using DCKey = int32_t;
using DCTimeDuration = int64_t;

// [EN] AutoWaitEvent ABI layout (96 bytes = 0x60), verified from AutoWaitEvent::AutoWaitEvent() @ 0x05d1d4:
//      0x00..0x2F: pthread_mutex_t (48 bytes on AArch64 Bionic)
//      0x30..0x57: pthread_cond_t  (40 bytes on AArch64 Bionic, initialized via +0x30 @ 0x05d200)
//      0x58:       bool mSignaled  (strb wzr, [x0, #0x58] @ 0x05d1e8; strb w8, [x19, #0x58] @ 0x05d23c)
// [VN] Bố cục ABI của AutoWaitEvent (96 byte = 0x60), xác minh từ AutoWaitEvent::AutoWaitEvent() @ 0x05d1d4:
//      0x00..0x2F: pthread_mutex_t (48 byte trên AArch64 Bionic)
//      0x30..0x57: pthread_cond_t  (40 byte trên AArch64 Bionic, khởi tạo qua +0x30 @ 0x05d200)
//      0x58:       bool mSignaled  (strb wzr, [x0, #0x58] @ 0x05d1e8; strb w8, [x19, #0x58] @ 0x05d23c)
struct alignas(8) AutoWaitEventAbiLayout {
    uint8_t mutex_storage[0x30]; // +0x00 (48 bytes)
    uint8_t cond_storage[0x28];  // +0x30 (40 bytes)
    uint8_t is_signaled;         // +0x58 (1 byte)
    uint8_t reserved_pad[7];     // +0x59..0x5F
};
static_assert(sizeof(AutoWaitEventAbiLayout) == 0x60, "AutoWaitEventAbiLayout must be 0x60 bytes");
static_assert(offsetof(AutoWaitEventAbiLayout, cond_storage) == 0x30, "cond_storage must be at +0x30");
static_assert(offsetof(AutoWaitEventAbiLayout, is_signaled) == 0x58, "is_signaled must be at +0x58");

// [EN] Base DCObject hierarchy matching RTTI (_ZTVN10datacenter8DCObjectE @ 0x07c3b0).
// [VN] Cây phân cấp DCObject cơ sở khớp RTTI (_ZTVN10datacenter8DCObjectE @ 0x07c3b0).
class DCObject {
public:
    explicit DCObject(DCObjectType type) noexcept : type_(type) {}
    virtual ~DCObject() = default;
    DCObjectType type() const noexcept { return type_; }
    virtual std::string toJsonString() const = 0;
private:
    DCObjectType type_;
};

class DCNull final : public DCObject {
public:
    DCNull() noexcept : DCObject(DCObjectType::kNull) {}
    std::string toJsonString() const override { return "null"; }
};

class DCBool final : public DCObject {
public:
    explicit DCBool(bool v) noexcept : DCObject(DCObjectType::kBool), value_(v) {}
    bool value() const noexcept { return value_; }
    std::string toJsonString() const override { return value_ ? "true" : "false"; }
private:
    bool value_;
};

class DCInt final : public DCObject {
public:
    explicit DCInt(int64_t v) noexcept : DCObject(DCObjectType::kInt), value_(v) {}
    int64_t value() const noexcept { return value_; }
    std::string toJsonString() const override { return std::to_string(value_); }
private:
    int64_t value_;
};

class DCFloat final : public DCObject {
public:
    explicit DCFloat(double v) noexcept : DCObject(DCObjectType::kFloat), value_(v) {}
    double value() const noexcept { return value_; }
    std::string toJsonString() const override;
private:
    double value_;
};

class DCString final : public DCObject {
public:
    explicit DCString(std::string v) noexcept : DCObject(DCObjectType::kString), value_(std::move(v)) {}
    const std::string& value() const noexcept { return value_; }
    std::string toJsonString() const override;
private:
    std::string value_;
};

class DCList final : public DCObject {
public:
    DCList() : DCObject(DCObjectType::kList) {}
    void append(std::shared_ptr<DCObject> item) { items_.push_back(std::move(item)); }
    size_t size() const noexcept { return items_.size(); }
    std::shared_ptr<DCObject> at(size_t idx) const {
        return idx < items_.size() ? items_[idx] : nullptr;
    }
    const std::vector<std::shared_ptr<DCObject>>& items() const noexcept { return items_; }
    std::string toJsonString() const override;
private:
    std::vector<std::shared_ptr<DCObject>> items_;
};

class DCDict final : public DCObject {
public:
    DCDict() : DCObject(DCObjectType::kDict) {}
    void set(const std::string& key, std::shared_ptr<DCObject> val) { entries_[key] = std::move(val); }
    std::shared_ptr<DCObject> get(const std::string& key) const {
        auto it = entries_.find(key);
        return it != entries_.end() ? it->second : nullptr;
    }
    size_t size() const noexcept { return entries_.size(); }
    const std::map<std::string, std::shared_ptr<DCObject>>& entries() const noexcept { return entries_; }
    std::string toJsonString() const override;
private:
    std::map<std::string, std::shared_ptr<DCObject>> entries_;
};

// [EN] Pitaya Dynamic C-API Function Pointer Table (.bss 0x080178..0x0802c8, 43 pointers).
// [VN] Bảng con trỏ hàm C-API động Pitaya (.bss 0x080178..0x0802c8, 43 con trỏ).
struct PitayaDynamicApiTable {
    void* pty_start_call;                        // 0x080178 ("PTYStartCall" @ 0x067cbd)
    void* pty_end_call;                          // 0x080180 ("PTYEndCall" @ 0x067cca)
    void* pty_retain;                            // 0x080188
    void* pty_release;                           // 0x080190
    void* pty_create_bool;                       // 0x080198 ("PTYCreateBool" @ 0x067cd5)
    void* pty_create_int;                        // 0x0801a0 ("PTYCreateInt" @ 0x067ce3)
    void* pty_create_float;                      // 0x0801a8 ("PTYCreateFloat" @ 0x067cf0)
    void* pty_create_string;                     // 0x0801b0 ("PTYCreateString" @ 0x067cff)
    void* pty_create_list;                       // 0x0801b8 ("PTYCreateList" @ 0x067d0f)
    void* pty_create_dict;                       // 0x0801c0 ("PTYCreateDict" @ 0x067d1d)
    void* pty_create_callback;                   // 0x0801c8 ("PTYCreateCallback" @ 0x067d2b)
    void* pty_create_callback_with_custom_params;// 0x0801d0 ("PTYCreateCallbackWithCustomParams" @ 0x067d3d)
    void* pty_list_append;                       // 0x0801d8 ("PTYListAppend" @ 0x067d5f)
    void* pty_list_set_value;                    // 0x0801e0
    void* pty_dict_set_value;                    // 0x0801e8 ("PTYDictSetValue" @ 0x067d6d)
    void* pty_get_object_type;                   // 0x0801f0 ("PTYGetObjectType" @ 0x067d7d)
    void* pty_get_bool;                          // 0x0801f8 ("PTYGetBool" @ 0x067d8e)
    void* pty_get_int;                           // 0x080200 ("PTYGetInt" @ 0x067d99)
    void* pty_get_float;                         // 0x080208 ("PTYGetFloat" @ 0x067da3)
    void* pty_get_string;                        // 0x080210 ("PTYGetString" @ 0x067daf)
    void* pty_list_get_value;                    // 0x080218
    void* pty_list_for_each;                     // 0x080220 ("PTYListForEach" @ 0x067dbc)
    void* pty_dict_get_value;                    // 0x080228 ("PTYDictGetValue" @ 0x067dcb)
    void* pty_dict_for_each;                     // 0x080230 ("PTYDictForEach" @ 0x067ddb)
    void* pty_object_from_json;                  // 0x080238
    void* pty_has_api_use_error;                 // 0x080240 ("PTYHasApiUseError" @ 0x067dea)
    void* pty_get_api_use_error_message;         // 0x080248 ("PTYGetApiUseErrorMessage" @ 0x067dfc)
    void* pty_get_api_use_error_code;            // 0x080250 ("PTYGetApiUseErrorCode" @ 0x067e15)
    void* pty_get_api_use_error_sub_code;        // 0x080258 ("PTYGetApiUseErrorSubCode" @ 0x067e2b)
    void* pty_clear_api_use_error;               // 0x080260 ("PTYClearApiUseError" @ 0x067e44)
    void* pty_setup;                             // 0x080268
    void* pty_is_host_ready;                     // 0x080270 ("PTYIsHostReady" @ 0x067e58)
    void* pty_is_ready;                          // 0x080278
    void* pty_run_task;                          // 0x080280 ("PTYRunTask" @ 0x067e67)
    void* pty_request_update;                    // 0x080288 ("PTYRequestUpdate" @ 0x067e72)
    void* pty_request_update_all;                // 0x080290
    void* pty_query_package;                     // 0x080298
    void* pty_download_package;                  // 0x0802a0
    void* pty_get_host_aid;                      // 0x0802a8 ("PTYGetHostAid" @ 0x067e83)
    void* pty_get_bool_with_default_value;       // 0x0802b0 ("PTYGetBoolWithDefaultValue" @ 0x067e91)
    void* pty_get_int_with_default_value;        // 0x0802b8
    void* pty_get_float_with_default_value;      // 0x0802c0
    void* pty_get_string_with_default_value;     // 0x0802c8 ("PTYGetStringWithDefaultValue" @ 0x067eac)
};
static_assert(sizeof(PitayaDynamicApiTable) == 43 * sizeof(void*), "PitayaDynamicApiTable must hold 43 pointers");

struct FdeDescriptor {
    uint32_t index;
    uint32_t start_va;
    uint32_t fde_va;
    uint32_t insn0;
    uint32_t insn1;
    uint32_t insn2;
    uint32_t insn3;
};

struct ExportSymbolDescriptor {
    uint32_t dynsym_index;
    uint32_t virtual_address;
    uint32_t size_bytes;
    const char* symbol_name;
};

// [EN] Core time and Pitaya functions verified at exact AArch64 virtual addresses.
// [VN] Các hàm thời gian và Pitaya cốt lõi đã xác minh tại địa chỉ ảo AArch64 chính xác.
bool DCTimeIsLater(uint32_t t1, uint32_t t2) noexcept;          // 0x05d0dc
int64_t DCTimeAfter(int32_t delay_ms) noexcept;                 // 0x05d0ec
uint64_t DCNowTimeMillis() noexcept;                            // 0x05d130
uint64_t DCTimeDiff(uint64_t later, uint64_t earlier) noexcept; // 0x05d164
uint64_t DCNowTimeNanos() noexcept;                             // 0x05d16c
uint64_t DCNowTimeMicros() noexcept;                            // 0x05d188
bool DCTimeIsLaterOrEqual(uint32_t t1, uint32_t t2) noexcept;   // 0x05d1c0

uint32_t SimulateCybertronFdeEntry(uint32_t fde_index, uint32_t arg0, uint32_t arg1) noexcept;

} // namespace datacenter

extern "C" {
bool TryLoadAllApi() noexcept;                                  // 0x05bb84
bool PitayaIsReady() noexcept;                                  // 0x05bf90
void dc_log(int level, const char* tag, const char* file, const char* func, int line, const char* fmt, ...) noexcept; // 0x063cec
}
