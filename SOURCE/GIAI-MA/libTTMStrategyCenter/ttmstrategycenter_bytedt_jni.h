// ============================================================================
// File: ttmstrategycenter_bytedt_jni.h
// Target: libTTMStrategyCenter.so (AArch64)
//
// Description (EN):
// ByteDT Decision Tree ML Engine Manager, Wrapper, Error/Output Transformers,
// `JNI_OnLoad` (`0x2e6cc`), and all 16 JNI methods across `TTMStrategyCenter`
// (11 methods @ `0x62050`) and `TTMStrategyCenterByteDTEngineManager` (5 methods
// @ `0x62158`).
//
// Mô tả (VI):
// Trình quản lý Động cơ Cây quyết định học máy ByteDT, Lớp bọc, Bộ chuyển đổi
// lỗi/đầu ra, `JNI_OnLoad` (`0x2e6cc`), và toàn bộ 16 phương thức JNI trên
// `TTMStrategyCenter` (11 hàm tại `0x62050`) và `TTMStrategyCenterByteDTEngineManager`
// (5 hàm tại `0x62158`).
// ============================================================================

#pragma once

#include "ttmstrategycenter_types.h"
#include "ttmstrategycenter_cep_engine.h"

namespace nextai {
namespace ttm_strategy_center {

// ============================================================================
// 1. ByteDT Error & Output Transformers (0x4ccf4..0x4d21c)
// ============================================================================
// Verified @ 0x4d21c (40 B): maps ByteDTErrorCode [0..6] via .rodata 0x523d8 -> [0, 401..406], else 407 (0x197)
TTMStateErrorCode transformByteDtErrorToTTMErrorCode(bytedt::ByteDTErrorCode err) noexcept;

// Verified @ 0x4cfa0 (516 B): converts raw float32 (type=1) or int32 (type=0) buffer into TTMListO*
TTMListO* transformOutputRawDataToTTMList(
    void* raw_data,
    long long byte_len,
    bytedt::ByteDTDataType data_type,
    __TTMTransparentStruct* ctx);

void ttmDictStoreIntValueForKey(
    _dictobject* dict_obj,
    const char* key,
    long long value,
    __TTMTransparentStruct* ctx); // @ 0x4cf0c

void ttmDictStoreTTMObjectWithKey(
    _dictobject* dict_obj,
    const char* key,
    _object* value_obj,
    __TTMTransparentStruct* ctx); // @ 0x4d1a4

// ============================================================================
// 2. TTMByteDTEngineWrapper (0x4ac30..0x4c4ec, size 0x68 = 104 bytes)
// Verified @ 0x4c4d0: _DTModelInfo stored at offset +0x50..+0x67
// ============================================================================
class TTMByteDTEngineWrapper {
public:
    TTMByteDTEngineWrapper(std::string biz_name, std::string key_name);
    ~TTMByteDTEngineWrapper(); // @ 0x4ac30

    bool LoadModel(const std::string& model_path, bool is_encrypt);

    // PredictRaw overloads (0x4ad38 & 0x4b784)
    TTMListO* PredictRaw(TTMListO* input_list, __TTMTransparentStruct* ctx);                  // @ 0x4ad38
    std::shared_ptr<std::vector<float>> PredictRaw(
        _TTMDTInputDataType& input, __TTMStateError* err);                                    // @ 0x4b784

    // Predict overloads (0x4b138 & 0x4b974)
    _dictobject* Predict(TTMListO* input_list, bool need_prob, __TTMTransparentStruct* ctx);  // @ 0x4b138
    std::shared_ptr<TTMDTPredictResult> Predict(_TTMDTInputDataType& input, bool need_prob);  // @ 0x4b974

    // GetDtModelInfo overloads (0x4c4d0 & 0x4c4ec)
    void GetDtModelInfo(_DTModelInfo& out_info) const noexcept;                               // @ 0x4c4d0
    void GetDtModelInfo(_dictobject* out_dict, __TTMTransparentStruct* ctx) const;            // @ 0x4c4ec

    bool isModelLoaded() const noexcept { return model_loaded_; }

private:
    std::string  biz_name_;
    std::string  key_name_;
    bool         model_loaded_{false};
    _DTModelInfo model_info_{1, 1.0f, 8.0f, 4.0f, 4.0f, 0.25f}; // +0x50..+0x67
};

// Verified @ 0x4ccf4 (204 B): wraps shared_ptr<TTMByteDTEngineWrapper> in a 32-byte TTMByteDtO _object
_object* TTMByteDtO_create(
    const std::shared_ptr<TTMByteDTEngineWrapper>& engine,
    void* alloc_ctx,
    __TTMStateError* err);

// ============================================================================
// 3. TTMByteDTEngineManager Singleton (0x48e74..0x48efc)
// ============================================================================
class TTMByteDTEngineManager {
public:
    TTMByteDTEngineManager();  // @ 0x48e74 (20 B: zeroes 32B table, stores 1.0f @ +0x20)
    ~TTMByteDTEngineManager(); // @ 0x48efc (352 B)

    static TTMByteDTEngineManager* Instance(); // @ 0x48e88 (116 B: singleton @ 0x642a0, guard @ 0x642c8)

    std::shared_ptr<TTMByteDTEngineWrapper> GetOrCreateEngine(
        const std::string& biz_name, const std::string& key_name);
    bool ReleaseEngine(const std::string& biz_name, const std::string& key_name);

private:
    mutable std::mutex mtx_;
    std::unordered_map<std::string, std::shared_ptr<TTMByteDTEngineWrapper>> engines_;
};

// ============================================================================
// 4. JNI Registration Tables & 16 Native Methods (0x2cf7c..0x2f9c4)
// ============================================================================
struct JniNativeMethodDescriptor {
    const char* name;
    const char* signature;
    void*       fn_ptr;
    uint32_t    binary_vaddr;
};

const std::vector<JniNativeMethodDescriptor>& getTTMStrategyCenterJniMethods();            // 11 methods @ 0x62050
const std::vector<JniNativeMethodDescriptor>& getTTMStrategyCenterByteDTJniMethods();      // 5 methods @ 0x62158

// Simulated JNI_OnLoad (0x2e6cc, 488 B) returning 0x00010006 (JNI_VERSION_1_6) or -1
int32_t simulateJniOnLoad(bool env_valid = true) noexcept;

// 11 TTMStrategyCenter JNI methods (0x2cf7c..0x2e4c0)
bool nativeRegisterBizCepRule(
    const char* biz, const char* rule_name, const char* rule_str, bool is_async, long user_bdi); // @ 0x2cf7c
void nativeRunBizCepRule(
    const char* biz, const char* rule_name, const ttm_sc_dict& params, ttm_sc_cep_result* out_result); // @ 0x2d2b8
bool nativeRegisterBizCepCallback(const char* biz, const char* rule_name);                 // @ 0x2d898
bool nativeUnRegisterBizCepCallBack(const char* biz, const char* rule_name);               // @ 0x2da98
bool nativeCleanBizCepRule(const char* biz, const char* rule_name);                        // @ 0x2dc98
void initStrategyCenter(bool valid_managers);                                              // @ 0x2de34
bool nativeUnRegisterRule(const char* biz, const char* rule_name);                         // @ 0x2e258
int64_t nativeGetTTMStrategyCenterExtendFuncAddress() noexcept;                            // @ 0x2e3b8
void nativeRecordUserExtendFunAddress(int64_t fn_addr) noexcept;                           // @ 0x2e3c4
bool nativeRegisterSettingsCallBack(const char* biz);                                      // @ 0x2e3f0
int64_t nativeCreateByteDTManager(const char* biz, const char* key);                       // @ 0x2e4c0

// 5 TTMStrategyCenterByteDTEngineManager JNI methods (0x2eb70..0x2f9c4)
bool nativeReleaseByteDTManger(const char* biz, const char* key, int64_t handle);          // @ 0x2eb70
bool nativeLoadByteDTModelByPath(const char* path, bool is_encrypt, int64_t handle);       // @ 0x2ed38
std::shared_ptr<TTMDTPredictResult> nativePredictByteDT(
    const float* features, int32_t count, bool need_prob, int64_t handle);                 // @ 0x2ee44
std::vector<float> nativePredictByteDTRaw(
    const float* features, int32_t count, int64_t handle);                                 // @ 0x2f73c
_DTModelInfo nativeGetModelInfo(int64_t handle);                                           // @ 0x2f9c4

} // namespace ttm_strategy_center
} // namespace nextai
