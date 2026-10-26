// ==============================================================================
// FILE: ttmachinecore_extdata_cjson_jni.h
// TARGET: libTTMachineCore.so (429,872 bytes, 830 dynamic symbols, 19 JNI methods)
// PURPOSE: Polymorphic External Data Interfaces (`ITTMExtDataBdi`,
//          `TTMExtJsonDataBdi`, `TTMExtJavaDataBdi`, `TTMExtDataInterface`,
//          `TTMExtDataDelegate`, `TTMExtJavaBdi`), `cJSON` DOM Parser/Serializer,
//          and `JNI_OnLoad` (`0x4f538`) + 19 JNI Native Methods (`0x6a8f0` & `0x6a9e0`)
//          (Giao diện dữ liệu mở rộng đa hình, bộ phân tích cJSON, và JNI_OnLoad
//          cùng 19 phương thức JNI Native)
// EVIDENCE CLASSIFICATION: OBSERVED (AArch64 .text `0x3b308..0x52394` & .data.rel.ro `0x6a138..0x6aab8`)
// ==============================================================================

#pragma once

#include "ttmachinecore_types.h"
#include "ttmachinecore_objects_hashmap.h"
#include "ttmachinecore_vm_bytecode.h"
#include "ttmachinecore_bdi_bridges.h"

namespace NextAI::OpenCut::TTMachineCore {

// ==============================================================================
// 1. cJSON DOM Node & Operations (`0x4a9bc..0x4e33c`)
// ==============================================================================
enum cJSON_TypeFlags : int {
    cJSON_Invalid = 0,
    cJSON_False   = (1 << 0),
    cJSON_True    = (1 << 1),
    cJSON_NULL    = (1 << 2),
    cJSON_Number  = (1 << 3),
    cJSON_String  = (1 << 4),
    cJSON_Array   = (1 << 5),
    cJSON_Object  = (1 << 6),
    cJSON_Raw     = (1 << 7)
};

struct cJSON {
    cJSON*      next{nullptr};
    cJSON*      prev{nullptr};
    cJSON*      child{nullptr};
    int         type{cJSON_Invalid};
    std::string valuestring{};
    int         valueint{0};
    double      valuedouble{0.0};
    std::string string{};
};

cJSON*      cJSON_CreateObject();
cJSON*      cJSON_CreateArray();
void        cJSON_Delete(cJSON* item);
cJSON*      cJSON_ParseWithLengthOpts(const char* value, std::size_t buffer_length, const char** return_parse_end, int require_null_terminated);
std::string cJSON_PrintBuffered(const cJSON* item);
bool        cJSON_IsNumber(const cJSON* item) noexcept;
bool        cJSON_IsString(const cJSON* item) noexcept;
bool        cJSON_IsArray(const cJSON* item) noexcept;
bool        cJSON_IsObject(const cJSON* item) noexcept;

_object* convert_cjson_obj_to_ttm_obj(cJSON* json, __TTMTransparentStruct* ctx);
cJSON*   convert_ttm_dict_to_cjson_obj(_dictobject* dict, __TTMTransparentStruct* ctx);

// ==============================================================================
// 2. `ITTMExtDataBdi` (`vtable` @ `0x6a570`), `TTMExtJsonDataBdi` (`vtable` @ `0x6a4b0`),
//    `TTMExtJavaDataBdi` (`vtable` @ `0x6a510`), and `TTMExtDataDelegate` (`vtable` @ `0x6a610`)
// ==============================================================================
class ITTMExtDataBdi {
public:
    virtual ~ITTMExtDataBdi() = default;
    virtual ITTMExtDataBdi* GetObjectItem(const char* key, __TTMTransparentStruct* ctx) = 0;
    virtual int             GetArraySize(__TTMTransparentStruct* ctx) = 0;
    virtual ITTMExtDataBdi* GetArrayItem(int index, __TTMTransparentStruct* ctx) = 0;
    virtual bool            GetValue(GetValueResult& out_res, __TTMTransparentStruct* ctx) = 0;
    virtual void*           GetOriginData(__TTMTransparentStruct* ctx) = 0;
    virtual int             GetOriginDataType(__TTMTransparentStruct* ctx) { return 0; }
};

class TTMExtJsonDataBdi : public ITTMExtDataBdi {
public:
    explicit TTMExtJsonDataBdi(cJSON* root, bool owns_root = false);
    ~TTMExtJsonDataBdi() override;

    ITTMExtDataBdi* GetObjectItem(const char* key, __TTMTransparentStruct* ctx) override;
    int             GetArraySize(__TTMTransparentStruct* ctx) override;
    ITTMExtDataBdi* GetArrayItem(int index, __TTMTransparentStruct* ctx) override;
    bool            GetValue(GetValueResult& out_res, __TTMTransparentStruct* ctx) override;
    void*           GetOriginData(__TTMTransparentStruct* ctx) override;
    int             GetOriginDataType(__TTMTransparentStruct* ctx) override;

private:
    cJSON* root_{nullptr};
    bool   owns_root_{false};
};

class TTMExtDataInterface {
public:
    virtual ~TTMExtDataInterface() = default;
    virtual int         GetOriginDataType(__TTMTransparentStruct* ctx) { return 0; }
    virtual int         GetExtObjDataType(__TTMTransparentStruct* ctx) { return 0; }
    virtual std::int64_t GetIntValue(const char* key, __TTMTransparentStruct* ctx) { return LONG_MAX_VALUE; }
    virtual double      GetDoubleValue(const char* key, __TTMTransparentStruct* ctx) { return DOUBLE_MAX_VALUE; }
    virtual std::string GetStringValue(const char* key, __TTMTransparentStruct* ctx) { return {}; }
    virtual int         GetArraySize(__TTMTransparentStruct* ctx) { return 0; }
    virtual bool        ExtDictContainKey(const char* key, __TTMTransparentStruct* ctx) { return false; }
};

class TTMExtDataDelegate : public TTMExtDataInterface {
public:
    explicit TTMExtDataDelegate(ITTMExtDataBdi* bdi);
    ~TTMExtDataDelegate() override;

    int          GetOriginDataType(__TTMTransparentStruct* ctx) override;
    std::int64_t GetIntValue(const char* key, __TTMTransparentStruct* ctx) override;
    double       GetDoubleValue(const char* key, __TTMTransparentStruct* ctx) override;
    std::string  GetStringValue(const char* key, __TTMTransparentStruct* ctx) override;
    int          GetArraySize(__TTMTransparentStruct* ctx) override;

private:
    ITTMExtDataBdi* bdi_{nullptr};
};

// ==============================================================================
// 3. `JNI_OnLoad` (`0x4f538`) & 19 Registered JNI Methods (`0x6a8f0` & `0x6a9e0`)
// ==============================================================================
extern const JNINativeMethod kTTMCoreJNIHelperMethods[10];     // @ 0x6a8f0 (file 0x668f0)
extern const JNINativeMethod kTTMCoreKVManagerMethods[9];      // @ 0x6a9e0 (file 0x669e0)

} // namespace NextAI::OpenCut::TTMachineCore
