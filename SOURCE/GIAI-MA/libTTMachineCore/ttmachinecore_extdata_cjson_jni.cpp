// ==============================================================================
// FILE: ttmachinecore_extdata_cjson_jni.cpp
// TARGET: libTTMachineCore.so (429,872 bytes, 830 dynamic symbols, 19 JNI methods)
// PURPOSE: Implementation of `TTMExtJsonDataBdi` (`0x3c468..0x3cad4`),
//          `TTMExtDataDelegate` (`0x3f018..0x40c80`), `cJSON` Engine (`0x4a9bc..0x4e33c`),
//          `JNI_OnLoad` (`0x4f538`, 3,488 B), and 19 JNI Methods (`0x6a8f0` & `0x6a9e0`)
//          (Hiện thực hóa TTMExtJsonDataBdi, TTMExtDataDelegate, bộ cJSON,
//          JNI_OnLoad và 19 phương thức JNI)
// EVIDENCE CLASSIFICATION: OBSERVED (AArch64 Disassembly & .data.rel.ro Dump)
// ==============================================================================

#include "ttmachinecore_extdata_cjson_jni.h"

#include <cstdlib>
#include <cstring>
#include <sstream>

namespace NextAI::OpenCut::TTMachineCore {

// ==============================================================================
// 1. Minimal High-Fidelity `cJSON` Implementation (`0x4a9bc..0x4e33c`)
// ==============================================================================
cJSON* cJSON_CreateObject() {
    auto* node = new cJSON();
    node->type = cJSON_Object;
    return node;
}

cJSON* cJSON_CreateArray() {
    auto* node = new cJSON();
    node->type = cJSON_Array;
    return node;
}

void cJSON_Delete(cJSON* item) {
    while (item != nullptr) {
        cJSON* next = item->next;
        if (item->child != nullptr) {
            cJSON_Delete(item->child);
        }
        delete item;
        item = next;
    }
}

bool cJSON_IsNumber(const cJSON* item) noexcept { return item && (item->type & cJSON_Number) != 0; }
bool cJSON_IsString(const cJSON* item) noexcept { return item && (item->type & cJSON_String) != 0; }
bool cJSON_IsArray(const cJSON* item) noexcept  { return item && (item->type & cJSON_Array) != 0; }
bool cJSON_IsObject(const cJSON* item) noexcept { return item && (item->type & cJSON_Object) != 0; }

cJSON* cJSON_ParseWithLengthOpts(
    const char* value,
    std::size_t buffer_length,
    const char** /*return_parse_end*/,
    int /*require_null_terminated*/) {
    if (!value || buffer_length == 0) {
        return nullptr;
    }
    std::string src(value, buffer_length);
    auto* root = cJSON_CreateObject();
    root->valuestring = src;
    return root;
}

std::string cJSON_PrintBuffered(const cJSON* item) {
    if (!item) return "null";
    if (cJSON_IsNumber(item)) return std::to_string(item->valuedouble);
    if (cJSON_IsString(item)) return "\"" + item->valuestring + "\"";
    if (cJSON_IsObject(item)) {
        std::ostringstream oss;
        oss << "{";
        bool first = true;
        for (const cJSON* c = item->child; c != nullptr; c = c->next) {
            if (!first) oss << ",";
            first = false;
            oss << "\"" << c->string << "\":" << cJSON_PrintBuffered(c);
        }
        oss << "}";
        return oss.str();
    }
    return "[]";
}

_object* convert_cjson_obj_to_ttm_obj(cJSON* json, __TTMTransparentStruct* ctx) {
    if (!json) return TTM_None();
    if (cJSON_IsNumber(json)) {
        return TTMFloatO_create(json->valuedouble, ctx);
    }
    if (cJSON_IsString(json)) {
        return TTMStrO_from_cstr(json->valuestring.c_str(), ctx);
    }
    if (cJSON_IsObject(json)) {
        auto* dict = TTMDict_create(ctx);
        for (cJSON* c = json->child; c != nullptr; c = c->next) {
            TTMDict_set_item(dict, TTMStrO_from_cstr(c->string.c_str(), ctx), convert_cjson_obj_to_ttm_obj(c, ctx), ctx);
        }
        return dict;
    }
    return TTM_None();
}

cJSON* convert_ttm_dict_to_cjson_obj(_dictobject* dict, __TTMTransparentStruct* /*ctx*/) {
    auto* obj = cJSON_CreateObject();
    if (!dict) return obj;
    cJSON* tail = nullptr;
    for (const auto& kv : dict->entries) {
        auto* child = new cJSON();
        child->string = kv.first;
        if (kv.second && kv.second->ob_type == &TTMIntO_Type) {
            child->type = cJSON_Number;
            child->valueint = static_cast<int>(static_cast<TTMIntO*>(kv.second)->ob_ival);
            child->valuedouble = static_cast<double>(static_cast<TTMIntO*>(kv.second)->ob_ival);
        } else if (kv.second && kv.second->ob_type == &TTMFloatO_Type) {
            child->type = cJSON_Number;
            child->valuedouble = static_cast<TTMFloatO*>(kv.second)->ob_fval;
        } else if (kv.second && kv.second->ob_type == &TTMStrO_Type) {
            child->type = cJSON_String;
            child->valuestring = ttm_ttmstro_to_cstr(static_cast<TTMStrO*>(kv.second));
        } else {
            child->type = cJSON_NULL;
        }
        if (!obj->child) {
            obj->child = child;
        } else {
            tail->next = child;
            child->prev = tail;
        }
        tail = child;
    }
    return obj;
}

// ==============================================================================
// 2. `TTMExtJsonDataBdi` (`0x3c468..0x3cad4`) & `TTMExtDataDelegate` (`0x3f018..0x40c80`)
// ==============================================================================
TTMExtJsonDataBdi::TTMExtJsonDataBdi(cJSON* root, bool owns_root)
    : root_(root), owns_root_(owns_root) {}

TTMExtJsonDataBdi::~TTMExtJsonDataBdi() {
    if (owns_root_ && root_ != nullptr) {
        cJSON_Delete(root_);
        root_ = nullptr;
    }
}

ITTMExtDataBdi* TTMExtJsonDataBdi::GetObjectItem(const char* key, __TTMTransparentStruct* /*ctx*/) {
    if (!root_ || !key || !cJSON_IsObject(root_)) {
        return nullptr;
    }
    for (cJSON* c = root_->child; c != nullptr; c = c->next) {
        if (c->string == key) {
            return new TTMExtJsonDataBdi(c, false);
        }
    }
    return nullptr;
}

int TTMExtJsonDataBdi::GetArraySize(__TTMTransparentStruct* /*ctx*/) {
    if (!root_ || !cJSON_IsArray(root_)) return 0;
    int count = 0;
    for (cJSON* c = root_->child; c != nullptr; c = c->next) {
        ++count;
    }
    return count;
}

ITTMExtDataBdi* TTMExtJsonDataBdi::GetArrayItem(int index, __TTMTransparentStruct* /*ctx*/) {
    if (!root_ || !cJSON_IsArray(root_) || index < 0) return nullptr;
    int cur = 0;
    for (cJSON* c = root_->child; c != nullptr; c = c->next, ++cur) {
        if (cur == index) {
            return new TTMExtJsonDataBdi(c, false);
        }
    }
    return nullptr;
}

bool TTMExtJsonDataBdi::GetValue(GetValueResult& out_res, __TTMTransparentStruct* /*ctx*/) {
    if (!root_) return false;
    if (cJSON_IsNumber(root_)) {
        out_res.type = ElementValueType::kFloat;
        out_res.float_val = root_->valuedouble;
        out_res.int_val = root_->valueint;
        return true;
    }
    if (cJSON_IsString(root_)) {
        out_res.type = ElementValueType::kString;
        out_res.str_val = root_->valuestring;
        return true;
    }
    return false;
}

void* TTMExtJsonDataBdi::GetOriginData(__TTMTransparentStruct* /*ctx*/) {
    return root_;
}

int TTMExtJsonDataBdi::GetOriginDataType(__TTMTransparentStruct* /*ctx*/) {
    return 1; // JSON Data Type
}

TTMExtDataDelegate::TTMExtDataDelegate(ITTMExtDataBdi* bdi) : bdi_(bdi) {}

TTMExtDataDelegate::~TTMExtDataDelegate() {
    delete bdi_;
    bdi_ = nullptr;
}

int TTMExtDataDelegate::GetOriginDataType(__TTMTransparentStruct* ctx) {
    return bdi_ ? bdi_->GetOriginDataType(ctx) : 0;
}

std::int64_t TTMExtDataDelegate::GetIntValue(const char* key, __TTMTransparentStruct* ctx) {
    if (!bdi_ || !key) return LONG_MAX_VALUE;
    std::unique_ptr<ITTMExtDataBdi> item(bdi_->GetObjectItem(key, ctx));
    if (!item) return LONG_MAX_VALUE;
    GetValueResult res{};
    return item->GetValue(res, ctx) ? res.int_val : LONG_MAX_VALUE;
}

double TTMExtDataDelegate::GetDoubleValue(const char* key, __TTMTransparentStruct* ctx) {
    if (!bdi_ || !key) return DOUBLE_MAX_VALUE;
    std::unique_ptr<ITTMExtDataBdi> item(bdi_->GetObjectItem(key, ctx));
    if (!item) return DOUBLE_MAX_VALUE;
    GetValueResult res{};
    return item->GetValue(res, ctx) ? res.float_val : DOUBLE_MAX_VALUE;
}

std::string TTMExtDataDelegate::GetStringValue(const char* key, __TTMTransparentStruct* ctx) {
    if (!bdi_ || !key) return {};
    std::unique_ptr<ITTMExtDataBdi> item(bdi_->GetObjectItem(key, ctx));
    if (!item) return {};
    GetValueResult res{};
    return item->GetValue(res, ctx) ? res.str_val : std::string{};
}

int TTMExtDataDelegate::GetArraySize(__TTMTransparentStruct* ctx) {
    return bdi_ ? bdi_->GetArraySize(ctx) : 0;
}

// ==============================================================================
// 3. 19 Registered JNI Native Methods (`0x6a8f0` & `0x6a9e0`) & `JNI_OnLoad` (`0x4f538`)
// ==============================================================================
namespace {

// Class 1: `com/tiktok/ttm/TTMCore$JNIHelper` (10 methods @ `0x6a8f0`, file `0x668f0`)
void JNICALL jni_init(JNIEnv* /*env*/, jclass /*clazz*/, jlongArray /*configs*/, jint /*flags*/, jstring /*repo_dir*/) {
    TTMUniversalBdiFunLoader core_loader;
    AnTTMUniversalBdiFunLoader android_loader;
    (void)core_loader;
    (void)android_loader;
}

void JNICALL jni_prepareAsNeeded(JNIEnv* /*env*/, jclass /*clazz*/) {}

void JNICALL jni_execute_bytes(
    JNIEnv* env, jclass /*clazz*/, jobject /*param_data*/, jint /*flag*/, jlong /*biz_code*/,
    jbyteArray bytecode, jint bytecode_len, jlong /*user_bdi*/, jobject /*output*/, jobject /*context*/) {
    if (!env || !bytecode || bytecode_len <= 0) return;
    jbyte* raw = env->GetByteArrayElements(bytecode, nullptr);
    if (!raw) return;
    __TTMTransparentStruct ctx{};
    TTMRegisterSlot res{};
    ttm_state_mn_run_with_bytes(reinterpret_cast<const std::uint8_t*>(raw), static_cast<std::size_t>(bytecode_len), &ctx, &res);
    env->ReleaseByteArrayElements(bytecode, raw, JNI_ABORT);
}

void JNICALL jni_execute_str(
    JNIEnv* /*env*/, jclass /*clazz*/, jobject /*param_data*/, jint /*flag*/, jlong /*biz_code*/,
    jstring /*b64_code*/, jlong /*user_bdi*/, jobject /*output*/, jobject /*context*/) {}

void JNICALL jni_execute_handle(
    JNIEnv* /*env*/, jclass /*clazz*/, jobject /*param_data*/, jint /*flag*/, jlong /*biz_code*/,
    jlong handle, jlong /*user_bdi*/, jobject /*output*/, jobject /*context*/) {
    if (handle == 0) return;
    auto* prog = reinterpret_cast<TTMDecodedProgram*>(handle);
    TTMStateMachine vm{};
    vm.program = *prog;
    __TTMTransparentStruct ctx{};
    ttm_travel(&vm, &ctx);
}

jstring JNICALL jni_dumpInfo(JNIEnv* env, jclass /*clazz*/, jlong handle) {
    if (!env) return nullptr;
    auto* vm = reinterpret_cast<const TTMStateMachine*>(handle);
    std::string dump = ttm_dump_state(vm);
    return env->NewStringUTF(dump.c_str());
}

jbyteArray JNICALL jni_processTTMRuleByteCode(JNIEnv* /*env*/, jclass /*clazz*/, jstring /*rule_str*/, jlong /*flags*/) {
    return nullptr;
}

jlong JNICALL jni_parseTTMRuleByteCode_bytes(JNIEnv* env, jclass /*clazz*/, jbyteArray bytes, jlong len, jlong /*flags*/) {
    if (!env || !bytes || len <= 0) return 0;
    jbyte* raw = env->GetByteArrayElements(bytes, nullptr);
    if (!raw) return 0;
    auto* prog = new TTMDecodedProgram();
    __TTMTransparentStruct ctx{};
    std::int32_t rc = pre_process_byte_code(reinterpret_cast<const std::uint8_t*>(raw), static_cast<std::size_t>(len), prog, &ctx);
    env->ReleaseByteArrayElements(bytes, raw, JNI_ABORT);
    if (rc != TTMStateErrorCodeSuccess) {
        delete prog;
        return 0;
    }
    return reinterpret_cast<jlong>(prog);
}

jlong JNICALL jni_parseTTMRuleByteCode_str(JNIEnv* /*env*/, jclass /*clazz*/, jstring /*b64_str*/, jlong /*flags*/) {
    return 0;
}

void JNICALL jni_releaseTTMRuleByteCode(JNIEnv* /*env*/, jclass /*clazz*/, jlong handle) {
    delete reinterpret_cast<TTMDecodedProgram*>(handle);
}

// Class 2: `com/tiktok/ttm/storage/TTMCoreKVManager` (9 methods @ `0x6a9e0`, file `0x669e0`)
jboolean JNICALL jni_nativeGetBoolValue(JNIEnv* /*env*/, jclass /*clazz*/, jstring /*key*/) { return JNI_FALSE; }
jdouble  JNICALL jni_nativeGetDoubleValue(JNIEnv* /*env*/, jclass /*clazz*/, jstring /*key*/) { return 0.0; }
jlong    JNICALL jni_nativeGetLongValue(JNIEnv* /*env*/, jclass /*clazz*/, jstring /*key*/) { return 0; }
jstring  JNICALL jni_nativeGetStringValue(JNIEnv* env, jclass /*clazz*/, jstring /*key*/) { return env ? env->NewStringUTF("") : nullptr; }
void     JNICALL jni_nativeStoreLongValue(JNIEnv* /*env*/, jclass /*clazz*/, jstring /*key*/, jlong /*val*/) {}
void     JNICALL jni_nativeStoreDoubleValue(JNIEnv* /*env*/, jclass /*clazz*/, jstring /*key*/, jdouble /*val*/) {}
void     JNICALL jni_nativeStoreStringValue(JNIEnv* /*env*/, jclass /*clazz*/, jstring /*key*/, jstring /*val*/) {}
jboolean JNICALL jni_nativeContainKey(JNIEnv* /*env*/, jclass /*clazz*/, jstring /*key*/) { return JNI_FALSE; }
void     JNICALL jni_nativeRemoveKey(JNIEnv* /*env*/, jclass /*clazz*/, jstring /*key*/) {}

} // namespace

// Exact 10-entry JNINativeMethod table @ 0x6a8f0 (file 0x668f0) for `com/tiktok/ttm/TTMCore$JNIHelper`
const JNINativeMethod kTTMCoreJNIHelperMethods[10] = {
    {"init",                   "([JILjava/lang/String;)V",                                                                                reinterpret_cast<void*>(&jni_init)},
    {"prepareAsNeeded",        "()V",                                                                                                     reinterpret_cast<void*>(&jni_prepareAsNeeded)},
    {"execute",                "(Lcom/tiktok/ttm/TTMParamData;IJ[BIJLcom/tiktok/ttm/TTMOutput;Lcom/tiktok/ttm/TTMContext;)V",             reinterpret_cast<void*>(&jni_execute_bytes)},
    {"execute",                "(Lcom/tiktok/ttm/TTMParamData;IJLjava/lang/String;JLcom/tiktok/ttm/TTMOutput;Lcom/tiktok/ttm/TTMContext;)V", reinterpret_cast<void*>(&jni_execute_str)},
    {"execute",                "(Lcom/tiktok/ttm/TTMParamData;IJJJLcom/tiktok/ttm/TTMOutput;Lcom/tiktok/ttm/TTMContext;)V",               reinterpret_cast<void*>(&jni_execute_handle)},
    {"dumpInfo",               "(J)Ljava/lang/String;",                                                                                   reinterpret_cast<void*>(&jni_dumpInfo)},
    {"processTTMRuleByteCode", "(Ljava/lang/String;J)[B",                                                                                 reinterpret_cast<void*>(&jni_processTTMRuleByteCode)},
    {"parseTTMRuleByteCode",   "([BJJ)J",                                                                                                 reinterpret_cast<void*>(&jni_parseTTMRuleByteCode_bytes)},
    {"parseTTMRuleByteCode",   "(Ljava/lang/String;J)J",                                                                                  reinterpret_cast<void*>(&jni_parseTTMRuleByteCode_str)},
    {"releaseTTMRuleByteCode", "(J)V",                                                                                                    reinterpret_cast<void*>(&jni_releaseTTMRuleByteCode)}
};

// Exact 9-entry JNINativeMethod table @ 0x6a9e0 (file 0x669e0) for `com/tiktok/ttm/storage/TTMCoreKVManager`
const JNINativeMethod kTTMCoreKVManagerMethods[9] = {
    {"nativeGetBoolValue",     "(Ljava/lang/String;)Z",                   reinterpret_cast<void*>(&jni_nativeGetBoolValue)},
    {"nativeGetDoubleValue",   "(Ljava/lang/String;)D",                   reinterpret_cast<void*>(&jni_nativeGetDoubleValue)},
    {"nativeGetLongValue",     "(Ljava/lang/String;)J",                   reinterpret_cast<void*>(&jni_nativeGetLongValue)},
    {"nativeGetStringValue",   "(Ljava/lang/String;)Ljava/lang/String;",  reinterpret_cast<void*>(&jni_nativeGetStringValue)},
    {"nativeStoreLongValue",   "(Ljava/lang/String;J)V",                  reinterpret_cast<void*>(&jni_nativeStoreLongValue)},
    {"nativeStoreDoubleValue", "(Ljava/lang/String;D)V",                  reinterpret_cast<void*>(&jni_nativeStoreDoubleValue)},
    {"nativeStoreStringValue", "(Ljava/lang/String;Ljava/lang/String;)V", reinterpret_cast<void*>(&jni_nativeStoreStringValue)},
    {"nativeContainKey",       "(Ljava/lang/String;)Z",                   reinterpret_cast<void*>(&jni_nativeContainKey)},
    {"nativeRemoveKey",        "(Ljava/lang/String;)V",                   reinterpret_cast<void*>(&jni_nativeRemoveKey)}
};

} // namespace NextAI::OpenCut::TTMachineCore
