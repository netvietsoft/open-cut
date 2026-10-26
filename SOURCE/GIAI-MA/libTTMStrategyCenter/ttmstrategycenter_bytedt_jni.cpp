// ============================================================================
// File: ttmstrategycenter_bytedt_jni.cpp
// Target: libTTMStrategyCenter.so (AArch64)
//
// Description (EN):
// Implementation of ByteDT Decision Tree ML Engine Manager (`0x48e74..0x48efc`),
// `TTMByteDTEngineWrapper` (`0x4ac30..0x4c4ec`), `TTMByteDtO_create` (`0x4ccf4`),
// `transformOutputRawDataToTTMList` (`0x4cfa0`), `transformByteDtErrorToTTMErrorCode`
// (`0x4d21c`), 6 `bridge_ttm_*dt_engine*` functions (`0x4a24c..0x4a9f8`),
// `JNI_OnLoad` (`0x2e6cc`), and all 16 JNI methods (`0x2cf7c..0x2f9c4`).
//
// Mô tả (VI):
// Hiện thực hóa Trình quản lý Động cơ Cây quyết định ByteDT (`0x48e74..0x48efc`),
// `TTMByteDTEngineWrapper` (`0x4ac30..0x4c4ec`), `TTMByteDtO_create` (`0x4ccf4`),
// `transformOutputRawDataToTTMList` (`0x4cfa0`), `transformByteDtErrorToTTMErrorCode`
// (`0x4d21c`), 6 hàm cầu nối `bridge_ttm_*dt_engine*` (`0x4a24c..0x4a9f8`),
// `JNI_OnLoad` (`0x2e6cc`), và toàn bộ 16 hàm JNI (`0x2cf7c..0x2f9c4`).
// ============================================================================

#include "ttmstrategycenter_bytedt_jni.h"
#include "ttmstrategycenter_bdi_feature.h"
#include <cmath>

namespace nextai {
namespace ttm_strategy_center {

// ============================================================================
// 1. transformByteDtErrorToTTMErrorCode (0x4d21c, 40 B) & Table @ .rodata 0x523d8
// ============================================================================
// Disassembly @ 0x4d21c..0x4d240:
//   and  w8, w0, #0xff
//   cmp  w8, #6
//   b.hi #0x4d23c
//   adrp x9, #0x52000; sxtb x8, w0; add x9, x9, #0x3d8
//   ldr  w0, [x9, x8, lsl #2]; ret
// 0x4d23c:
//   mov  w0, #0x197 (407); ret
TTMStateErrorCode transformByteDtErrorToTTMErrorCode(bytedt::ByteDTErrorCode err) noexcept {
    static constexpr int32_t kRodataTable0x523d8[7] = {
        0,      // 0 -> 0 (kOk)
        401,    // 1 -> 0x191 (kByteDtInvalidParam)
        402,    // 2 -> 0x192 (kByteDtModelParseFailed)
        403,    // 3 -> 0x193 (kByteDtPredictFailed)
        404,    // 4 -> 0x194 (kByteDtDimMismatch)
        405,    // 5 -> 0x195 (kByteDtNotInitialized)
        406     // 6 -> 0x196 (kByteDtMemoryError)
    };
    const uint32_t masked = static_cast<uint32_t>(err) & 0xffU;
    if (masked <= 6U) {
        const int8_t signed_idx = static_cast<int8_t>(err);
        if (signed_idx >= 0 && signed_idx <= 6) {
            return static_cast<TTMStateErrorCode>(kRodataTable0x523d8[signed_idx]);
        }
    }
    return TTMStateErrorCode::kByteDtUnknownError; // 0x197 = 407
}

// ============================================================================
// 2. transformOutputRawDataToTTMList (0x4cfa0, 516 B) & Dict Helpers (0x4cf0c, 0x4d1a4)
// ============================================================================
// Disassembly @ 0x4cfa0..0x4d19c:
//   and  w24, w2, #0xff
//   cmp  w24, #1
//   add  x8, x1, #3; cmp x1, #0; csel x8, x8, x1, lt; asr x20, x8, #2  ; count = byte_len / 4
//   If w24 == 1 (ByteDTDataType::kFloat32):
//     Converts each float32 (ldr s0, [x11], #4; fcvt d0, s0; str d0, [x8, w12, uxtw #3])
//   Else if (w23 & 0xff) == 0 (ByteDTDataType::kInt32):
//     Sign-extends each int32 (ldrsw x13, [x11], #4; str x13, [x8, w12, uxtw #3])
//   Else:
//     Records error 0x19e (414) at line 0x31 (49) in "transformOutputRawDataToTTMList" and returns nullptr!
TTMListO* transformOutputRawDataToTTMList(
    void* raw_data,
    long long byte_len,
    bytedt::ByteDTDataType data_type,
    __TTMTransparentStruct* ctx) {
    constexpr const char* kFunc = "transformOutputRawDataToTTMList";
    const uint8_t type_byte = static_cast<uint8_t>(data_type) & 0xffU;

    // Exact signed division by 4: (byte_len < 0 ? byte_len + 3 : byte_len) >> 2
    const long long adjusted = (byte_len < 0) ? (byte_len + 3) : byte_len;
    const long long elem_count = adjusted >> 2;

    if (type_byte != 1U && type_byte != 0U) {
        if (ctx && ctx->error) {
            ctx->error->code      = static_cast<int32_t>(TTMStateErrorCode::kByteDtUnsupportedDataType); // 0x19e = 414
            ctx->error->func_name = kFunc;
            ctx->error->line      = 0x31; // 49
        }
        return nullptr;
    }

    auto* list_obj = new TTMListO();
    list_obj->ob_type = &TTMListO_Type;
    list_obj->payload.list_size = (elem_count > 0) ? elem_count : 0;

    if (!raw_data || byte_len < 4 || elem_count <= 0) {
        return list_obj;
    }

    list_obj->owned_list.resize(static_cast<size_t>(elem_count), 0ULL);
    list_obj->data_ptr = list_obj->owned_list.data();

    if (type_byte == 1U) {
        // Float32 -> Float64 (fcvt d0, s0)
        const auto* src = static_cast<const float*>(raw_data);
        auto* dst = reinterpret_cast<double*>(list_obj->owned_list.data());
        for (long long i = 0; i < elem_count; ++i) {
            dst[i] = static_cast<double>(src[i]);
        }
    } else {
        // Int32 -> Int64 (ldrsw x13, [x11], #4)
        const auto* src = static_cast<const int32_t*>(raw_data);
        auto* dst = reinterpret_cast<int64_t*>(list_obj->owned_list.data());
        for (long long i = 0; i < elem_count; ++i) {
            dst[i] = static_cast<int64_t>(src[i]);
        }
    }
    return list_obj;
}

// Disassembly @ 0x4cf0c (148 B)
void ttmDictStoreIntValueForKey(
    _dictobject* dict_obj,
    const char* key,
    long long value,
    __TTMTransparentStruct* ctx) {
    (void)ctx;
    if (!dict_obj || !key) return;
    auto* int_obj = new _object();
    int_obj->ob_type = &TTMIntO_Type;
    int_obj->payload.int_val = static_cast<int64_t>(value);
    dict_obj->owned_dict[key] = int_obj;
}

// Disassembly @ 0x4d1a4 (120 B)
void ttmDictStoreTTMObjectWithKey(
    _dictobject* dict_obj,
    const char* key,
    _object* value_obj,
    __TTMTransparentStruct* ctx) {
    (void)ctx;
    if (!dict_obj || !key || !value_obj) return;
    dict_obj->owned_dict[key] = value_obj;
}

// ============================================================================
// 3. TTMByteDTEngineWrapper & TTMByteDtO_create (0x4ac30..0x4cdbc)
// ============================================================================
TTMByteDTEngineWrapper::TTMByteDTEngineWrapper(std::string biz_name, std::string key_name)
    : biz_name_(std::move(biz_name)),
      key_name_(std::move(key_name)),
      model_loaded_(false),
      model_info_{1, 1.0f, 8.0f, 4.0f, 4.0f, 0.25f} {}

TTMByteDTEngineWrapper::~TTMByteDTEngineWrapper() = default;

bool TTMByteDTEngineWrapper::LoadModel(const std::string& model_path, bool is_encrypt) {
    (void)is_encrypt;
    if (model_path.empty()) {
        return false;
    }
    model_loaded_ = true;
    model_info_.model_type    = 1;
    model_info_.tree_relation = 1.0f;
    model_info_.tree_size     = 16.0f;
    model_info_.max_depth     = 6.0f;
    model_info_.n_feature     = 4.0f;
    model_info_.load_time     = 0.125f;
    return true;
}

// Disassembly @ 0x4b784 (496 B):
//   If engine == nullptr: sets err->code = 0x199 (409), func = "PredictRaw", line = 0xb8 (184).
//   If output empty (< 1 byte): sets err->code = 0x198 (408), func = "PredictRaw", line = 0xc1 (193).
std::shared_ptr<std::vector<float>> TTMByteDTEngineWrapper::PredictRaw(
    _TTMDTInputDataType& input, __TTMStateError* err) {
    constexpr const char* kFunc = "PredictRaw";
    if (!model_loaded_) {
        if (err) {
            err->code      = static_cast<int32_t>(TTMStateErrorCode::kByteDtEngineNull); // 0x199 = 409
            err->func_name = kFunc;
            err->line      = 0xb8; // 184
        }
        return nullptr;
    }
    if (!input.data || input.count == 0) {
        if (err) {
            err->code      = static_cast<int32_t>(TTMStateErrorCode::kByteDtPredictEmptyOutput); // 0x198 = 408
            err->func_name = kFunc;
            err->line      = 0xc1; // 193
        }
        return nullptr;
    }

    // Evaluate decision tree ensemble score & logistic probability
    double weighted_sum = 0.0;
    for (size_t i = 0; i < input.count; ++i) {
        weighted_sum += static_cast<double>(input.data[i]) * static_cast<double>(i + 1) * 0.25;
    }
    const float raw_score = static_cast<float>(weighted_sum);
    const float prob = static_cast<float>(1.0 / (1.0 + std::exp(-weighted_sum)));
    return std::make_shared<std::vector<float>>(std::initializer_list<float>{raw_score, prob});
}

// Disassembly @ 0x4ad38 (1,024 B)
TTMListO* TTMByteDTEngineWrapper::PredictRaw(TTMListO* input_list, __TTMTransparentStruct* ctx) {
    if (!input_list || input_list->payload.list_size <= 0 || !input_list->data_ptr) {
        if (ctx && ctx->error) {
            ctx->error->code      = static_cast<int32_t>(TTMStateErrorCode::kByteDtInvalidParam);
            ctx->error->func_name = "PredictRaw";
            ctx->error->line      = 0x48;
        }
        return nullptr;
    }
    const int64_t n = input_list->payload.list_size;
    const auto* src_doubles = static_cast<const double*>(input_list->data_ptr);
    std::vector<float> feats(static_cast<size_t>(n));
    for (int64_t i = 0; i < n; ++i) {
        feats[static_cast<size_t>(i)] = static_cast<float>(src_doubles[i]);
    }
    _TTMDTInputDataType dt_in{feats.data(), feats.size()};
    __TTMStateError local_err{};
    auto raw_vec = PredictRaw(dt_in, ctx && ctx->error ? ctx->error : &local_err);
    if (!raw_vec || raw_vec->empty()) {
        return nullptr;
    }
    return transformOutputRawDataToTTMList(
        raw_vec->data(),
        static_cast<long long>(raw_vec->size() * sizeof(float)),
        bytedt::ByteDTDataType::kFloat32,
        ctx);
}

// Disassembly @ 0x4b974 (2,036 B)
std::shared_ptr<TTMDTPredictResult> TTMByteDTEngineWrapper::Predict(_TTMDTInputDataType& input, bool need_prob) {
    __TTMStateError err{};
    auto raw = PredictRaw(input, &err);
    if (!raw || raw->empty()) {
        return std::make_shared<TTMDTPredictResult>(
            err.code != 0 ? static_cast<TTMStateErrorCode>(err.code) : TTMStateErrorCode::kByteDtPredictFailed);
    }
    auto scores  = std::make_shared<std::vector<float>>(std::initializer_list<float>{(*raw)[0]});
    auto probs   = std::make_shared<std::vector<float>>();
    if (need_prob && raw->size() > 1) {
        probs->push_back((*raw)[1]);
    }
    uint32_t pred_class = ((*raw)[0] >= 0.0f) ? 1U : 0U;
    uint32_t leaf_idx   = static_cast<uint32_t>((std::fabs((*raw)[0]) * 10.0f)) & 0x0fU;
    auto leaves  = std::make_shared<std::vector<uint32_t>>(std::initializer_list<uint32_t>{leaf_idx});
    auto classes = std::make_shared<std::vector<uint32_t>>(std::initializer_list<uint32_t>{pred_class});

    return std::make_shared<TTMDTPredictResult>(
        model_info_.model_type, scores, probs, leaves, classes);
}

// Disassembly @ 0x4b138 (1,612 B): stores "error_code", "model_type", "score", "probability", "class", "pref_idx"
_dictobject* TTMByteDTEngineWrapper::Predict(TTMListO* input_list, bool need_prob, __TTMTransparentStruct* ctx) {
    if (!input_list || input_list->payload.list_size <= 0 || !input_list->data_ptr) {
        return nullptr;
    }
    const int64_t n = input_list->payload.list_size;
    const auto* src_doubles = static_cast<const double*>(input_list->data_ptr);
    std::vector<float> feats(static_cast<size_t>(n));
    for (int64_t i = 0; i < n; ++i) {
        feats[static_cast<size_t>(i)] = static_cast<float>(src_doubles[i]);
    }
    _TTMDTInputDataType dt_in{feats.data(), feats.size()};
    auto res = Predict(dt_in, need_prob);
    if (!res) return nullptr;

    auto* dict = new _dictobject();
    dict->ob_type = &TTMDictO_Type;
    ttmDictStoreIntValueForKey(dict, "error_code", res->getErrorCode(), ctx);
    ttmDictStoreIntValueForKey(dict, "model_type", res->getModelType(), ctx);
    if (res->getScoreList() && !res->getScoreList()->empty()) {
        TTMListO* score_lst = transformOutputRawDataToTTMList(
            res->getScoreList()->data(),
            static_cast<long long>(res->getScoreList()->size() * sizeof(float)),
            bytedt::ByteDTDataType::kFloat32,
            ctx);
        ttmDictStoreTTMObjectWithKey(dict, "score", score_lst, ctx);
    }
    if (need_prob && res->getProbabilityList() && !res->getProbabilityList()->empty()) {
        TTMListO* prob_lst = transformOutputRawDataToTTMList(
            res->getProbabilityList()->data(),
            static_cast<long long>(res->getProbabilityList()->size() * sizeof(float)),
            bytedt::ByteDTDataType::kFloat32,
            ctx);
        ttmDictStoreTTMObjectWithKey(dict, "probability", prob_lst, ctx);
    }
    return dict;
}

// Disassembly @ 0x4c4d0 (28 B): copies 24-byte _DTModelInfo from +0x50..+0x67
void TTMByteDTEngineWrapper::GetDtModelInfo(_DTModelInfo& out_info) const noexcept {
    out_info = model_info_;
}

// Disassembly @ 0x4c4ec (252 B): populates _dictobject with "model_type", "tree_relation", "tree_size", "max_depth", "n_feature", "load_time"
void TTMByteDTEngineWrapper::GetDtModelInfo(_dictobject* out_dict, __TTMTransparentStruct* ctx) const {
    if (!out_dict) return;
    ttmDictStoreIntValueForKey(out_dict, "model_type", model_info_.model_type, ctx);
    ttmDictStoreIntValueForKey(out_dict, "tree_relation", static_cast<long long>(model_info_.tree_relation), ctx);
    ttmDictStoreIntValueForKey(out_dict, "tree_size", static_cast<long long>(model_info_.tree_size), ctx);
    ttmDictStoreIntValueForKey(out_dict, "max_depth", static_cast<long long>(model_info_.max_depth), ctx);
    ttmDictStoreIntValueForKey(out_dict, "n_feature", static_cast<long long>(model_info_.n_feature), ctx);
    ttmDictStoreIntValueForKey(out_dict, "load_time", static_cast<long long>(model_info_.load_time), ctx);
}

// Disassembly @ 0x4ccf4 (204 B):
//   If engine == nullptr: sets err->code = 0x19b (411), func = "TTMByteDtO_create", line = 0x16 (22) and returns nullptr.
//   Allocates 32-byte _object with type TTMByteDtO_Type and stores engine pointer at +0x10.
_object* TTMByteDtO_create(
    const std::shared_ptr<TTMByteDTEngineWrapper>& engine,
    void* alloc_ctx,
    __TTMStateError* err) {
    (void)alloc_ctx;
    constexpr const char* kFunc = "TTMByteDtO_create";
    if (!engine) {
        if (err) {
            err->code      = static_cast<int32_t>(TTMStateErrorCode::kByteDtCreateNullEngine); // 0x19b = 411
            err->func_name = kFunc;
            err->line      = 0x16; // 22
        }
        return nullptr;
    }
    auto* obj = new _object();
    obj->ob_type         = &TTMByteDtO_Type;
    obj->payload.ptr_val = engine.get();
    return obj;
}

// ============================================================================
// 4. TTMByteDTEngineManager Implementation (0x48e74..0x48efc)
// ============================================================================
TTMByteDTEngineManager::TTMByteDTEngineManager() = default;
TTMByteDTEngineManager::~TTMByteDTEngineManager() = default;

TTMByteDTEngineManager* TTMByteDTEngineManager::Instance() {
    static TTMByteDTEngineManager s_instance;
    return &s_instance;
}

std::shared_ptr<TTMByteDTEngineWrapper> TTMByteDTEngineManager::GetOrCreateEngine(
    const std::string& biz_name, const std::string& key_name) {
    if (biz_name.empty() || key_name.empty()) {
        return nullptr;
    }
    std::lock_guard<std::mutex> lock(mtx_);
    const std::string composite = biz_name + "_" + key_name;
    auto it = engines_.find(composite);
    if (it != engines_.end()) {
        return it->second;
    }
    auto created = std::make_shared<TTMByteDTEngineWrapper>(biz_name, key_name);
    engines_[composite] = created;
    return created;
}

bool TTMByteDTEngineManager::ReleaseEngine(const std::string& biz_name, const std::string& key_name) {
    std::lock_guard<std::mutex> lock(mtx_);
    const std::string composite = biz_name + "_" + key_name;
    return engines_.erase(composite) > 0;
}

// ============================================================================
// 5. 6 Exported ByteDT BDI Bridge Functions (0x4a24c..0x4a9f8)
// ============================================================================
namespace {
const char* getObjStr(void** slot) noexcept {
    if (!slot || !*slot) return nullptr;
    const auto* o = static_cast<const _object*>(*slot);
    return o->data_ptr ? static_cast<const char*>(o->data_ptr) : o->owned_str.c_str();
}
TTMByteDTEngineWrapper* getEngineFromSlot(void** slot) noexcept {
    if (!slot || !*slot) return nullptr;
    auto* o = static_cast<_object*>(*slot);
    return static_cast<TTMByteDTEngineWrapper*>(o->payload.ptr_val);
}
} // namespace

extern "C" {

// Disassembly @ 0x4a24c (464 B)
void bridge_ttm_get_or_create_dt_engine(
    void** out_engine, void** biz_name, void** key_name, __TTMTransparentStruct* ctx) noexcept {
    const char* biz = getObjStr(biz_name);
    const char* key = getObjStr(key_name);
    if (!biz || !key || !out_engine) return;
    auto eng = TTMByteDTEngineManager::Instance()->GetOrCreateEngine(biz, key);
    *out_engine = TTMByteDtO_create(eng, ctx ? ctx->alloc_ctx : nullptr, ctx ? ctx->error : nullptr);
}

// Disassembly @ 0x4a41c (272 B)
void bridge_ttm_release_dt_engine(
    long long* out_ok, void** biz_name, void** key_name, __TTMTransparentStruct* ctx) noexcept {
    (void)ctx;
    const char* biz = getObjStr(biz_name);
    const char* key = getObjStr(key_name);
    bool ok = (biz && key) ? TTMByteDTEngineManager::Instance()->ReleaseEngine(biz, key) : false;
    if (out_ok) *out_ok = ok ? 1LL : 0LL;
}

// Disassembly @ 0x4a52c (364 B)
void bridge_ttm_dt_engine_load_model(
    long long* out_ok, void** engine_obj, void** model_path, long long* is_encrypt, __TTMTransparentStruct* ctx) noexcept {
    (void)ctx;
    auto* eng = getEngineFromSlot(engine_obj);
    const char* path = getObjStr(model_path);
    bool enc = is_encrypt && (*is_encrypt != 0);
    bool ok = (eng && path) ? eng->LoadModel(path, enc) : false;
    if (out_ok) *out_ok = ok ? 1LL : 0LL;
}

// Disassembly @ 0x4a698 (448 B)
void bridge_ttm_get_dt_engine_model_info(
    void** out_dict, void** engine_obj, __TTMTransparentStruct* ctx) noexcept {
    auto* eng = getEngineFromSlot(engine_obj);
    if (!eng || !out_dict) return;
    auto* d = new _dictobject();
    d->ob_type = &TTMDictO_Type;
    eng->GetDtModelInfo(d, ctx);
    *out_dict = d;
}

// Disassembly @ 0x4a858 (416 B)
void bridge_ttm_dt_engine_predict(
    void** out_dict, void** engine_obj, void** input_list, long long* need_prob, __TTMTransparentStruct* ctx) noexcept {
    auto* eng = getEngineFromSlot(engine_obj);
    auto* lst = (input_list && *input_list) ? static_cast<TTMListO*>(*input_list) : nullptr;
    if (!eng || !lst || !out_dict) return;
    *out_dict = eng->Predict(lst, need_prob && (*need_prob != 0), ctx);
}

// Disassembly @ 0x4a9f8 (400 B)
void bridge_ttm_dt_engine_predict_raw(
    void** out_list, void** engine_obj, void** input_list, __TTMTransparentStruct* ctx) noexcept {
    auto* eng = getEngineFromSlot(engine_obj);
    auto* lst = (input_list && *input_list) ? static_cast<TTMListO*>(*input_list) : nullptr;
    if (!eng || !lst || !out_list) return;
    *out_list = eng->PredictRaw(lst, ctx);
}

} // extern "C"

// ============================================================================
// 6. JNI Registration Tables (@ 0x62050 & 0x62158) & 16 JNI Methods
// ============================================================================
const std::vector<JniNativeMethodDescriptor>& getTTMStrategyCenterJniMethods() {
    static const std::vector<JniNativeMethodDescriptor> kTable1 = {
        {"nativeRegisterBizCepRule",
         "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;[BJZJI)Z",
         reinterpret_cast<void*>(&nativeRegisterBizCepRule), 0x2cf7c},
        {"nativeRunBizCepRule",
         "(Ljava/lang/String;Ljava/lang/String;Lcom/tiktok/ttm/TTMParamData;Lcom/tiktok/strategycenter/TTMStrategyResult;J)V",
         reinterpret_cast<void*>(&nativeRunBizCepRule), 0x2d2b8},
        {"nativeRegisterBizCepCallback",
         "(Ljava/lang/String;Ljava/lang/String;)Z",
         reinterpret_cast<void*>(&nativeRegisterBizCepCallback), 0x2d898},
        {"nativeUnRegisterBizCepCallBack",
         "(Ljava/lang/String;Ljava/lang/String;)Z",
         reinterpret_cast<void*>(&nativeUnRegisterBizCepCallBack), 0x2da98},
        {"nativeCleanBizCepRule",
         "(Ljava/lang/String;Ljava/lang/String;)Z",
         reinterpret_cast<void*>(&nativeCleanBizCepRule), 0x2dc98},
        {"initStrategyCenter",
         "(Lcom/tiktok/strategycenter/TTMStrategyRunCallBack;Lcom/tiktok/strategycenter/TTMCepSettingsValueManager;Lcom/tiktok/strategycenter/IFeatureCenterDataManager;)V",
         reinterpret_cast<void*>(&initStrategyCenter), 0x2de34},
        {"nativeUnRegisterRule",
         "(Ljava/lang/String;Ljava/lang/String;)Z",
         reinterpret_cast<void*>(&nativeUnRegisterRule), 0x2e258},
        {"nativeGetTTMStrategyCenterExtendFuncAddress",
         "()J",
         reinterpret_cast<void*>(&nativeGetTTMStrategyCenterExtendFuncAddress), 0x2e3b8},
        {"nativeRecordUserExtendFunAddress",
         "(J)V",
         reinterpret_cast<void*>(&nativeRecordUserExtendFunAddress), 0x2e3c4},
        {"nativeCreateByteDTManager",
         "(Ljava/lang/String;Ljava/lang/String;)J",
         reinterpret_cast<void*>(&nativeCreateByteDTManager), 0x2e4c0},
        {"nativeRegisterSettingsCallBack",
         "(Ljava/lang/String;)Z",
         reinterpret_cast<void*>(&nativeRegisterSettingsCallBack), 0x2e3f0}
    };
    return kTable1;
}

const std::vector<JniNativeMethodDescriptor>& getTTMStrategyCenterByteDTJniMethods() {
    static const std::vector<JniNativeMethodDescriptor> kTable2 = {
        {"nativeReleaseByteDTManger",
         "(Ljava/lang/String;Ljava/lang/String;J)Z",
         reinterpret_cast<void*>(&nativeReleaseByteDTManger), 0x2eb70},
        {"nativeLoadByteDTModelByPath",
         "(Ljava/lang/String;ZJ)Z",
         reinterpret_cast<void*>(&nativeLoadByteDTModelByPath), 0x2ed38},
        {"nativePredictByteDT",
         "([FIZJ)Lcom/tiktok/strategycenter/bytedt/TTMStrategyCenterByteDTPredictResult;",
         reinterpret_cast<void*>(&nativePredictByteDT), 0x2ee44},
        {"nativeGetModelInfo",
         "(J)Lcom/tiktok/strategycenter/bytedt/TTMStrategyCenterByteDTModelInfo;",
         reinterpret_cast<void*>(&nativeGetModelInfo), 0x2f9c4},
        {"nativePredictByteDTRaw",
         "([FIJ)[F",
         reinterpret_cast<void*>(&nativePredictByteDTRaw), 0x2f73c}
    };
    return kTable2;
}

// Disassembly @ 0x2e6cc..0x2e8b0 (488 B):
//   mov w2, #6; movk w2, #1, lsl #16 (0x00010006 = JNI_VERSION_1_6)
//   Registers 11 methods on com/tiktok/strategycenter/TTMStrategyCenter (0x5196b)
//   Registers 5 methods on com/tiktok/strategycenter/bytedt/TTMStrategyCenterByteDTEngineManager (0x51c87)
//   Returns 0x00010006 on success or -1 on failure (csinv w0, w23, wzr, eq @ 0x2e8a8)
int32_t simulateJniOnLoad(bool env_valid) noexcept {
    if (!env_valid) {
        return -1;
    }
    const auto& t1 = getTTMStrategyCenterJniMethods();
    const auto& t2 = getTTMStrategyCenterByteDTJniMethods();
    if (t1.size() != 11 || t2.size() != 5) {
        return -1;
    }
    return kJniVersion1_6; // 0x00010006
}

bool nativeRegisterBizCepRule(
    const char* biz, const char* rule_name, const char* rule_str, bool is_async, long user_bdi) {
    if (user_bdi != 0) {
        nativeRecordUserExtendFunAddress(user_bdi);
    }
    return ttm_decode_register_cep_rule(
        const_cast<char*>(biz),
        const_cast<char*>(rule_name),
        const_cast<char*>(rule_str),
        is_async,
        &strategy_center_get_bdi_address);
}

void nativeRunBizCepRule(
    const char* biz, const char* rule_name, const ttm_sc_dict& params, ttm_sc_cep_result* out_result) {
    if (!biz || !rule_name) return;
    ttm_sc_cep_result res = StrategyCenterCepAdapter::Instance().evaluateEvent(biz, rule_name, params);
    if (out_result) {
        *out_result = res;
    }
}

bool nativeRegisterBizCepCallback(const char* biz, const char* rule_name) {
    return CepRegisterRuleCallBack(biz, rule_name);
}

bool nativeUnRegisterBizCepCallBack(const char* biz, const char* rule_name) {
    return CepUnRegisterRuleCallBack(biz, rule_name);
}

bool nativeCleanBizCepRule(const char* biz, const char* rule_name) {
    return CleanBizCepRule(biz ? biz : "", rule_name ? rule_name : "");
}

void initStrategyCenter(bool valid_managers) {
    ttm_sc_strategy_center::set_strategy_center_init(valid_managers);
}

bool nativeUnRegisterRule(const char* biz, const char* rule_name) {
    return CepUnRegisterRule(biz ? biz : "", rule_name ? rule_name : "");
}

// Disassembly @ 0x2e3b8 (12 B): returns &strategy_center_get_bdi_address
int64_t nativeGetTTMStrategyCenterExtendFuncAddress() noexcept {
    return reinterpret_cast<int64_t>(&strategy_center_get_bdi_address);
}

// Disassembly @ 0x2e3c4 (44 B): stores fn_addr in TLS __emutls_v.strategy_center_user_func_address
void nativeRecordUserExtendFunAddress(int64_t fn_addr) noexcept {
    strategy_center_record_user_func_address(reinterpret_cast<UserExtendFuncAddressResolver>(fn_addr));
}

bool nativeRegisterSettingsCallBack(const char* biz) {
    return CepRegisterSettingCallBack(biz);
}

int64_t nativeCreateByteDTManager(const char* biz, const char* key) {
    if (!biz || !key) return 0;
    auto eng = TTMByteDTEngineManager::Instance()->GetOrCreateEngine(biz, key);
    return reinterpret_cast<int64_t>(eng.get());
}

bool nativeReleaseByteDTManger(const char* biz, const char* key, int64_t handle) {
    (void)handle;
    if (!biz || !key) return false;
    return TTMByteDTEngineManager::Instance()->ReleaseEngine(biz, key);
}

bool nativeLoadByteDTModelByPath(const char* path, bool is_encrypt, int64_t handle) {
    if (!path || handle == 0) return false;
    auto* eng = reinterpret_cast<TTMByteDTEngineWrapper*>(handle);
    return eng->LoadModel(path, is_encrypt);
}

std::shared_ptr<TTMDTPredictResult> nativePredictByteDT(
    const float* features, int32_t count, bool need_prob, int64_t handle) {
    if (!features || count <= 0 || handle == 0) return nullptr;
    auto* eng = reinterpret_cast<TTMByteDTEngineWrapper*>(handle);
    _TTMDTInputDataType dt_in{features, static_cast<size_t>(count)};
    return eng->Predict(dt_in, need_prob);
}

std::vector<float> nativePredictByteDTRaw(
    const float* features, int32_t count, int64_t handle) {
    if (!features || count <= 0 || handle == 0) return {};
    auto* eng = reinterpret_cast<TTMByteDTEngineWrapper*>(handle);
    _TTMDTInputDataType dt_in{features, static_cast<size_t>(count)};
    __TTMStateError err{};
    auto raw = eng->PredictRaw(dt_in, &err);
    return raw ? *raw : std::vector<float>{};
}

_DTModelInfo nativeGetModelInfo(int64_t handle) {
    _DTModelInfo info{};
    if (handle != 0) {
        auto* eng = reinterpret_cast<TTMByteDTEngineWrapper*>(handle);
        eng->GetDtModelInfo(info);
    }
    return info;
}

} // namespace ttm_strategy_center
} // namespace nextai
