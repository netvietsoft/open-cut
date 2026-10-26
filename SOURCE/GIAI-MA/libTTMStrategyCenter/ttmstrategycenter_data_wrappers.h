// ============================================================================
// File: ttmstrategycenter_data_wrappers.h
// Target: libTTMStrategyCenter.so (AArch64)
//
// Description (EN):
// Strategy Center data wrappers (`StrategyCenterBasicDataWrapper`,
// `ttm_sc_basic_data_wrapper`, `ttm_sc_dict_param_data`, `ttm_sc_map_vector_data`)
// and container converters (`covert_ttm_dict_to_cpp_dict`, `covert_ttm_list_to_cpp_list`).
//
// Mô tả (VI):
// Các lớp bọc dữ liệu của Strategy Center (`StrategyCenterBasicDataWrapper`,
// `ttm_sc_basic_data_wrapper`, `ttm_sc_dict_param_data`, `ttm_sc_map_vector_data`)
// và các hàm chuyển đổi container (`covert_ttm_dict_to_cpp_dict`, `covert_ttm_list_to_cpp_list`).
// ============================================================================

#pragma once

#include "ttmstrategycenter_types.h"

namespace nextai {
namespace ttm_strategy_center {

// ============================================================================
// 1. StrategyCenterBasicDataWrapper (0x280cc..0x29648, vtable @ 0x61ba8)
// Lớp bọc dữ liệu cơ bản có bộ nhớ đệm con tạm thời
// ============================================================================
class StrategyCenterBasicDataWrapper : public TTMExtDataInterface {
public:
    StrategyCenterBasicDataWrapper(void* origin_data, bool need_delete); // @ 0x29550
    ~StrategyCenterBasicDataWrapper() override;                          // @ 0x280cc

    int64_t GetArraySize(ElementValueType type, __TTMTransparentStruct* ctx) override;            // @ 0x282d0
    const char* GetStringValue(long index, __TTMTransparentStruct* ctx) override;                 // @ 0x28308
    int64_t GetIntValue(long index, __TTMTransparentStruct* ctx) override;                        // @ 0x28364
    double GetDoubleValue(long index, __TTMTransparentStruct* ctx) override;                      // @ 0x2839c
    std::vector<std::string> GetAllStringValues(__TTMTransparentStruct* ctx) override;            // @ 0x283d8
    std::vector<int64_t> GetAllIntValues(__TTMTransparentStruct* ctx) override;                   // @ 0x284a0
    std::vector<double> GetAllDoubleValues(__TTMTransparentStruct* ctx) override;                 // @ 0x28568
    std::vector<std::string> GetAllStringValues(const char* key, __TTMTransparentStruct* ctx) override; // @ 0x28630
    std::vector<int64_t> GetAllIntValues(const char* key, __TTMTransparentStruct* ctx) override;  // @ 0x286f8
    std::vector<double> GetAllDoubleValues(const char* key, __TTMTransparentStruct* ctx) override;// @ 0x287c0
    void* GetExtObjectForKey(const char* key, __TTMTransparentStruct* ctx) override;              // @ 0x28888
    void* GetExtObjectForIndex(long index, __TTMTransparentStruct* ctx) override;                 // @ 0x28b98
    void* GetExtObjectByKeyAndIndex(const char* key, long index, __TTMTransparentStruct* ctx) override; // @ 0x28de8
    const char* GetStringValue(const char* key, __TTMTransparentStruct* ctx) override;            // @ 0x29114
    int64_t GetIntValue(const char* key, __TTMTransparentStruct* ctx) override;                   // @ 0x29170
    double GetDoubleValue(const char* key, __TTMTransparentStruct* ctx) override;                 // @ 0x291a8
    void* GetOriginData(__TTMTransparentStruct* ctx) override;                                    // @ 0x291e4
    std::vector<std::string> GetDictAllValuesForString(__TTMTransparentStruct* ctx) override;     // @ 0x29240
    std::vector<int64_t> GetDictAllValuesForInt(__TTMTransparentStruct* ctx) override;            // @ 0x29304
    std::vector<double> GetDictAllValuesForDouble(__TTMTransparentStruct* ctx) override;          // @ 0x293c8
    std::vector<std::string> GetDictAllKeys(__TTMTransparentStruct* ctx) override;                // @ 0x2948c

    void AddTemporaryExtWrapperData(const char* key, StrategyCenterBasicDataWrapper* wrapper);    // @ 0x29598
    void RemoveTemporaryExtWrapperDataAndDelete(const char* key);                                 // @ 0x29648

private:
    TTMExtDataInterface* inner_{nullptr}; // +0x08
    bool                 need_delete_{false}; // +0x10
    std::unordered_map<std::string, StrategyCenterBasicDataWrapper*> temp_wrappers_{};
};

// ============================================================================
// 2. ttm_sc_basic_data_wrapper & ttm_sc_dict_param_data (0x30f74..0x3fa7c)
// Lớp bọc dữ liệu cơ sở và tham số từ điển động của Strategy Center
// ============================================================================
class ttm_sc_basic_data_wrapper : public TTMExtDataInterface {
public:
    ttm_sc_basic_data_wrapper() = default;
    ~ttm_sc_basic_data_wrapper() override; // @ 0x3156c

    void* GetExtObjectForKey(const char* key, __TTMTransparentStruct* ctx) override;              // @ 0x30f74
    void* GetExtObjectForIndex(long index, __TTMTransparentStruct* ctx) override;                 // @ 0x310b4
    void* GetExtObjectByKeyAndIndex(const char* key, long index, __TTMTransparentStruct* ctx) override; // @ 0x31198

    void AddTemporaryExtWrapperData(const char* key, ttm_sc_basic_data_wrapper* wrapper);         // @ 0x313f4
    void RemoveTemporaryExtWrapperDataAndDelete(const char* key);                                 // @ 0x314a4

protected:
    std::unordered_map<std::string, ttm_sc_basic_data_wrapper*> temp_cache_{};
};

class ttm_sc_dict_param_data : public ttm_sc_basic_data_wrapper {
public:
    ttm_sc_dict_param_data();                                        // @ 0x3fa48
    explicit ttm_sc_dict_param_data(long val);                       // @ 0x3ad40 (tag=1)
    explicit ttm_sc_dict_param_data(double val);                     // @ 0x3ad74 (tag=2)
    explicit ttm_sc_dict_param_data(std::string val);                // tag=3
    explicit ttm_sc_dict_param_data(std::shared_ptr<ttm_sc_dict> d); // tag=4
    explicit ttm_sc_dict_param_data(std::shared_ptr<ttm_sc_list> l); // tag=5
    ~ttm_sc_dict_param_data() override;                              // @ 0x315e8

    int64_t GetArraySize(ElementValueType type, __TTMTransparentStruct* ctx) override;            // @ 0x3adac
    const char* GetStringValue(long index, __TTMTransparentStruct* ctx) override;                 // @ 0x3adbc
    int64_t GetIntValue(long index, __TTMTransparentStruct* ctx) override;                        // @ 0x3aec8
    double GetDoubleValue(long index, __TTMTransparentStruct* ctx) override;                      // @ 0x3af28
    std::vector<std::string> GetAllStringValues(__TTMTransparentStruct* ctx) override;            // @ 0x3af88
    std::vector<int64_t> GetAllIntValues(__TTMTransparentStruct* ctx) override;                   // @ 0x3b27c
    std::vector<double> GetAllDoubleValues(__TTMTransparentStruct* ctx) override;                 // @ 0x3b4e0
    std::vector<std::string> GetAllStringValues(const char* key, __TTMTransparentStruct* ctx) override; // @ 0x3b744
    std::vector<int64_t> GetAllIntValues(const char* key, __TTMTransparentStruct* ctx) override;  // @ 0x3bb18
    std::vector<double> GetAllDoubleValues(const char* key, __TTMTransparentStruct* ctx) override;// @ 0x3be54
    void* GetExtObjectForKey(const char* key, __TTMTransparentStruct* ctx) override;              // @ 0x3c190
    void* GetExtObjectForIndex(long index, __TTMTransparentStruct* ctx) override;                 // @ 0x3cd70
    void* GetExtObjectByKeyAndIndex(const char* key, long index, __TTMTransparentStruct* ctx) override; // @ 0x3d85c
    const char* GetStringValue(const char* key, __TTMTransparentStruct* ctx) override;            // @ 0x3db74
    int64_t GetIntValue(const char* key, __TTMTransparentStruct* ctx) override;                   // @ 0x3dcc4
    double GetDoubleValue(const char* key, __TTMTransparentStruct* ctx) override;                 // @ 0x3dda4
    void* GetOriginData(__TTMTransparentStruct* ctx) override;                                    // @ 0x3de84
    std::vector<std::string> GetDictAllValuesForString(__TTMTransparentStruct* ctx) override;     // @ 0x3df00
    std::vector<int64_t> GetDictAllValuesForInt(__TTMTransparentStruct* ctx) override;            // @ 0x3e3f0
    std::vector<double> GetDictAllValuesForDouble(__TTMTransparentStruct* ctx) override;          // @ 0x3e740
    std::vector<std::string> GetDictAllKeys(__TTMTransparentStruct* ctx) override;                // @ 0x3ea8c
    int32_t GetOriginDataType(__TTMTransparentStruct* ctx) override;                              // @ 0x3eeac

    // Mutation extensions (0x3eeb4..0x3fa34)
    bool ModifyMutExtDictKeyValue(const char* key, void* val_obj, __TTMTransparentStruct* ctx);   // @ 0x3eeb4
    bool ModifyMutExtListValueByIndex(void* val_obj, long long index, __TTMTransparentStruct* ctx);// @ 0x3f2c0
    bool MutExtDictAddKeyValue(const char* key, void* val_obj, __TTMTransparentStruct* ctx);      // @ 0x3f5c4
    bool MutExtListAppendValue(void* val_obj, __TTMTransparentStruct* ctx);                       // @ 0x3f5d0
    bool MutExtDictRemoveKey(const char* key, __TTMTransparentStruct* ctx);                       // @ 0x3f8ac
    bool MutExtListRemoveValueByIndex(long index, __TTMTransparentStruct* ctx);                   // @ 0x3f93c
    bool ExtDictContainKey(const char* key, __TTMTransparentStruct* ctx);                         // @ 0x3f94c
    std::shared_ptr<ttm_sc_dict> get_origin_dict_value(__TTMTransparentStruct* ctx) const;        // @ 0x3f9dc
    std::shared_ptr<ttm_sc_list> get_origin_list_value(__TTMTransparentStruct* ctx) const;        // @ 0x3fa08
    int32_t GetExtObjDataType(__TTMTransparentStruct* ctx) const;                                 // @ 0x3fa34

private:
    std::shared_ptr<ttm_sc_dict> dict_val_{};     // +0x48 (when tag == 4)
    std::shared_ptr<ttm_sc_list> list_val_{};     // +0x48 (when tag == 5)
    int64_t                      int_val_{0};     // +0x50 (when tag == 1)
    double                       double_val_{0.0};// +0x50 (when tag == 2)
    std::string                  str_val_{};      // when tag == 3
    int32_t                      tag_{0};         // +0x58 (1=int, 2=double, 3=string, 4=dict, 5=list)
    mutable std::string          scratch_str_{};
};

// ============================================================================
// 3. ttm_sc_map_vector_data & CreateTTMAllocDataType (0x44a9c..0x45838)
// ============================================================================
TTMAllocDataTag* CreateTTMAllocDataType(uint32_t type, void* ptr); // @ 0x44d10
TTMAllocDataTag* TTMGetObjectForKey(TTMAllocDataTag* map_tag, const char* key, __TTMTransparentStruct* ctx); // @ 0x44a9c
TTMAllocDataTag* TTMGetObjectForIndex(TTMAllocDataTag* vec_tag, long index, __TTMTransparentStruct* ctx);    // @ 0x44b6c
TTMAllocDataTag* TTMGetObjectForKeyAndIndex(TTMAllocDataTag* map_tag, const char* key, long index, __TTMTransparentStruct* ctx); // @ 0x44bd8

class ttm_sc_map_vector_data : public TTMExtDataInterface {
public:
    explicit ttm_sc_map_vector_data(void* origin_tag); // @ 0x44d40
    ~ttm_sc_map_vector_data() override;                // @ 0x44d6c

    int64_t GetArraySize(ElementValueType type, __TTMTransparentStruct* ctx) override;            // @ 0x44ef4
    const char* GetStringValue(long index, __TTMTransparentStruct* ctx) override;                 // @ 0x44f30
    int64_t GetIntValue(long index, __TTMTransparentStruct* ctx) override;                        // @ 0x44f5c
    double GetDoubleValue(long index, __TTMTransparentStruct* ctx) override;                      // @ 0x44f88
    std::vector<std::string> GetAllStringValues(__TTMTransparentStruct* ctx) override;            // @ 0x44fb4
    std::vector<int64_t> GetAllIntValues(__TTMTransparentStruct* ctx) override;                   // @ 0x44fbc
    std::vector<double> GetAllDoubleValues(__TTMTransparentStruct* ctx) override;                 // @ 0x44fc4
    std::vector<std::string> GetAllStringValues(const char* key, __TTMTransparentStruct* ctx) override; // @ 0x44fcc
    std::vector<int64_t> GetAllIntValues(const char* key, __TTMTransparentStruct* ctx) override;  // @ 0x44fd4
    std::vector<double> GetAllDoubleValues(const char* key, __TTMTransparentStruct* ctx) override;// @ 0x44fdc
    void* GetExtObjectForKey(const char* key, __TTMTransparentStruct* ctx) override;              // @ 0x44fe4
    void* GetExtObjectByKeyAndIndex(const char* key, long index, __TTMTransparentStruct* ctx) override; // @ 0x450ac
    void* GetExtObjectForIndex(long index, __TTMTransparentStruct* ctx) override;                 // @ 0x451f8
    std::vector<std::string> GetDictAllValuesForString(__TTMTransparentStruct* ctx) override;     // @ 0x4530c
    std::vector<int64_t> GetDictAllValuesForInt(__TTMTransparentStruct* ctx) override;            // @ 0x453f0
    std::vector<double> GetDictAllValuesForDouble(__TTMTransparentStruct* ctx) override;          // @ 0x454d4
    std::vector<std::string> GetDictAllKeys(__TTMTransparentStruct* ctx) override;                // @ 0x455b8
    const char* GetStringValue(const char* key, __TTMTransparentStruct* ctx) override;            // @ 0x456b4
    int64_t GetIntValue(const char* key, __TTMTransparentStruct* ctx) override;                   // @ 0x456bc
    double GetDoubleValue(const char* key, __TTMTransparentStruct* ctx) override;                 // @ 0x456d8
    void* GetOriginData(__TTMTransparentStruct* ctx) override;                                    // @ 0x45838

private:
    TTMAllocDataTag* origin_{nullptr}; // +0x08
    std::vector<ttm_sc_map_vector_data*> child_wrappers_{};
};

// ============================================================================
// 4. Container Converters (0x3481c & 0x35220)
// ============================================================================
ttm_sc_dict covert_ttm_dict_to_cpp_dict(_dictobject* dict_obj, __TTMTransparentStruct* ctx);
ttm_sc_list covert_ttm_list_to_cpp_list(TTMListO* list_obj, __TTMTransparentStruct* ctx);

} // namespace ttm_strategy_center
} // namespace nextai
