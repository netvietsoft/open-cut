// ============================================================================
// File: cybertron_datacenter_core.h
// Target: libcybertron_base.so (509,816 bytes)
// Task ID: TASK-142-RECONSTRUCTION-LIBCYBERTRON-BASE / TASK_SO_105_libcybertron_base
// ============================================================================
// [EN] Declarations for DataCenter, DCJson, DCPlayRecord, DCPlayRecordHolder,
//      FeatureCenter, PlaybackFeatureProducer, AndroidFeatureProducer,
//      SettingsFeatureProducer, and AlgTaskRunnerImpl.
// [VN] Khai báo cho DataCenter, DCJson, DCPlayRecord, DCPlayRecordHolder,
//      FeatureCenter, PlaybackFeatureProducer, AndroidFeatureProducer,
//      SettingsFeatureProducer và AlgTaskRunnerImpl.
// ============================================================================

#pragma once

#include "cybertron_base_types.h"

namespace datacenter {

// [EN] DCPlayBufferTime & DCPlayRecord matching .rodata 0x066c41..0x066dfd.
// [VN] DCPlayBufferTime & DCPlayRecord khớp .rodata 0x066c41..0x066dfd.
struct DCPlayBufferTime {
    int64_t start_t{0};
    int64_t end_t{0};
    int64_t duration_ms{0};
    int32_t reason{0};
    std::string toString() const;
};

struct DCPlayRecord {
    std::string media_id;
    std::string scene_id;
    std::string brief_scene_id;
    std::string trace_id;
    int64_t prepare_t{0};
    int64_t prepared_t{0};
    int64_t play_t{0};
    int64_t first_frame_t{0};
    int64_t first_buffer_start_t{0};
    int64_t first_buffer_end_t{0};
    int64_t prepare_d{0};
    int64_t first_frame_d{0};
    int64_t play_d{0};
    int64_t buffering_d{0};
    double render_fps{0.0};
    int64_t out_sync_duration_ms{0};
    int32_t out_sync_count{0};
    std::vector<DCPlayBufferTime> buffers;

    std::shared_ptr<DCDict> toDict() const;
    std::string toString() const;
};

class DataCenterEventListener {
public:
    virtual ~DataCenterEventListener() = default;
    virtual void onEvent(DataCenterEvent event, int64_t arg1, int64_t arg2, const char* msg) = 0;
};

// [EN] DataCenter virtual interface & implementation matching vtable _ZTVN10datacenter10DataCenterE @ 0x07c880
//      and JNI thunks at 0x060000..0x0605d4:
//      vtable[+0x10]: setIntValue(int key, int val)       (called by _setIntValue @ 0x060018)
//      vtable[+0x18]: setLongValue(int key, int64_t val)  (called by _setLongValue @ 0x060054)
//      vtable[+0x20]: setFloatValue(int key, float val)   (called by _setFloatValue @ 0x060034)
//      vtable[+0x28]: setStrValue(int key, const std::string& val)
//      vtable[+0x30]: getIntValue(int key, int def_val)   (called by _getIntValue @ 0x060100)
//      vtable[+0x38]: getLongValue(int key, int64_t def)  (called by _getLongValue @ 0x060140)
//      vtable[+0x48]: getFloatValue(int key, float def)   (called by _getFloatValue @ 0x060120)
//      vtable[+0x68]: businessEvent(int ev, int v)        (called by _businessEvent__JII @ 0x06048c)
//      vtable[+0x80]: businessEvent(int sub, int ev, int v) (called by _businessEvent__JIII @ 0x060534)
// [VN] Giao diện ảo & thực thi DataCenter khớp vtable _ZTVN10datacenter10DataCenterE @ 0x07c880
//      và các thunk JNI tại 0x060000..0x0605d4.
class DataCenter {
public:
    DataCenter();
    virtual ~DataCenter();

    static DataCenter* Create(); // 0x040734 / 0x060000

    virtual void setIntValue(int32_t key, int32_t value);                 // vtable +0x10
    virtual void setLongValue(int32_t key, int64_t value);                // vtable +0x18
    virtual void setFloatValue(int32_t key, float value);                 // vtable +0x20
    virtual void setStrValue(int32_t key, const std::string& value);      // vtable +0x28
    virtual int32_t getIntValue(int32_t key, int32_t default_val) const;  // vtable +0x30
    virtual int64_t getLongValue(int32_t key, int64_t default_val) const; // vtable +0x38
    virtual std::string getStrValue(int32_t key, const std::string& def) const; // vtable +0x40
    virtual float getFloatValue(int32_t key, float default_val) const;    // vtable +0x48
    virtual void addEventListener(std::shared_ptr<DataCenterEventListener> listener);
    virtual void businessEvent(int32_t event_id, int32_t val);            // vtable +0x68
    virtual void businessEventStr(int32_t event_id, const std::string& msg);
    virtual void businessEventSub(int32_t sub_type, int32_t event_id, int32_t val); // vtable +0x80
    virtual void businessEventSubStr(int32_t sub_type, int32_t event_id, const std::string& msg);

private:
    mutable std::mutex mutex_;
    std::unordered_map<int32_t, int32_t> int_store_;
    std::unordered_map<int32_t, int64_t> long_store_;
    std::unordered_map<int32_t, float> float_store_;
    std::unordered_map<int32_t, std::string> str_store_;
    std::vector<std::shared_ptr<DataCenterEventListener>> listeners_;
};

namespace featurecenter {

class FeatureProducer {
public:
    virtual ~FeatureProducer() = default;
    virtual std::shared_ptr<DCObject> getFeature(const std::string& name) = 0;
    virtual std::shared_ptr<DCObject> getFeature(
        const std::string& name,
        const std::string& sub_key,
        const DCDict& params) = 0;
    virtual std::shared_ptr<DCDict> getBatchFeatures(const std::string& config_json, DCKey key) = 0;
    virtual std::string getGroup() const = 0;
    virtual ProducerType getProducerType() const noexcept = 0;
};

class AndroidFeatureProducer final : public FeatureProducer {
public:
    AndroidFeatureProducer() = default;
    ~AndroidFeatureProducer() override = default;
    std::shared_ptr<DCObject> getFeature(const std::string& name) override;
    std::shared_ptr<DCObject> getFeature(
        const std::string& name,
        const std::string& sub_key,
        const DCDict& params) override;
    std::shared_ptr<DCDict> getBatchFeatures(const std::string& config_json, DCKey key) override;
    std::string getGroup() const override { return "ClientFeature"; } // .rodata 0x069839
    ProducerType getProducerType() const noexcept override {
        return ProducerType::kAndroidProducer; // 0x062fc8: mov w0, wzr; ret
    }
};

class PlaybackFeatureProducer final : public FeatureProducer {
public:
    PlaybackFeatureProducer() = default;
    ~PlaybackFeatureProducer() override = default;
    std::shared_ptr<DCObject> getFeature(const std::string& name) override;
    std::shared_ptr<DCObject> getFeature(
        const std::string& name,
        const std::string& sub_key,
        const DCDict& params) override;
    std::shared_ptr<DCDict> getBatchFeatures(const std::string& config_json, DCKey key) override;
    std::string getGroup() const override { return "playback"; }
    ProducerType getProducerType() const noexcept override {
        return ProducerType::kPlaybackProducer; // 0x053a6c: mov w0, #1; ret
    }
    void recordPlaySample(const DCPlayRecord& record);
private:
    mutable std::mutex mutex_;
    std::vector<DCPlayRecord> history_;
};

class SettingsFeatureProducer final : public FeatureProducer {
public:
    SettingsFeatureProducer();
    ~SettingsFeatureProducer() override = default;
    std::shared_ptr<DCObject> getFeature(const std::string& name) override;
    std::shared_ptr<DCObject> getFeature(
        const std::string& name,
        const std::string& sub_key,
        const DCDict& params) override;
    std::shared_ptr<DCDict> getBatchFeatures(const std::string& config_json, DCKey key) override;
    std::string getGroup() const override { return "settings"; }
    ProducerType getProducerType() const noexcept override {
        return ProducerType::kSettingsProducer; // 0x063cdc: mov w0, #2; ret
    }
    static const char* GetDefaultFeatureSchemaJson() noexcept; // .rodata 0x0686a3
private:
    std::unordered_map<std::string, std::string> settings_map_;
};

class AndroidFeatureConvertHelper {
public:
    static int32_t toInt(std::shared_ptr<DCObject>& obj) noexcept;       // 0x0635f8
    static int64_t toLong(std::shared_ptr<DCObject>& obj) noexcept;      // 0x06362c
    static float toFloat(std::shared_ptr<DCObject>& obj) noexcept;       // 0x063660
    static double toDouble(std::shared_ptr<DCObject>& obj) noexcept;     // 0x063694
    static bool toBoolean(std::shared_ptr<DCObject>& obj) noexcept;      // 0x0636c8
    static std::string toString(std::shared_ptr<DCObject>& obj);         // 0x0636fc
    static std::shared_ptr<DCObject> toAny(std::shared_ptr<DCObject>& obj) noexcept; // 0x063730
};

} // namespace featurecenter

namespace clientai {

struct AlgTaskConfig {
    std::string entrance;
    int64_t pending_timeout_ms{5000};
    int32_t call_type{0};
    bool is_async{true};
};

class AlgTaskRunnerImpl {
public:
    static AlgTaskRunnerImpl& instance();
    bool isReady() const noexcept;
    void postSmartTask(
        const std::string& business_name,
        std::shared_ptr<DCDict> input_params,
        std::shared_ptr<AlgTaskConfig> config,
        std::function<void(bool, int64_t, int64_t, const std::shared_ptr<DCDict>&)> callback);
};

} // namespace clientai

JavaVM* getJVM() noexcept;                                 // 0x05da88
JNIEnv* getEnv() noexcept;                                 // 0x05da94
jint loadRelativeClasses(JavaVM* vm) noexcept;             // 0x05dafc
jlong jlongFromPointer(void* ptr) noexcept;                // 0x05ddc0

} // namespace datacenter
