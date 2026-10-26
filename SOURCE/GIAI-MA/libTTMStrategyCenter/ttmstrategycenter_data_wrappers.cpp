// ============================================================================
// File: ttmstrategycenter_data_wrappers.cpp
// Target: libTTMStrategyCenter.so (AArch64)
//
// Description (EN):
// Implementation of Strategy Center data wrappers (`0x280cc..0x29648`,
// `0x30f74..0x3fa7c`, `0x44a9c..0x45838`), `ttm_sc_dict` (`0x36d38..0x39d0c`),
// `ttm_sc_list` (`0x41170..0x448e4`, including `make_real_index` @ `0x41fa0`
// with reciprocal multiplication `0xcccccccccccccccd`), and container
// converters (`covert_ttm_dict_to_cpp_dict` @ `0x3481c` and
// `covert_ttm_list_to_cpp_list` @ `0x35220`).
//
// Mô tả (VI):
// Hiện thực hóa các lớp bọc dữ liệu của Strategy Center (`0x280cc..0x29648`,
// `0x30f74..0x3fa7c`, `0x44a9c..0x45838`), `ttm_sc_dict` (`0x36d38..0x39d0c`),
// `ttm_sc_list` (`0x41170..0x448e4`, bao gồm `make_real_index` tại `0x41fa0`
// sử dụng phép nhân nghịch đảo `0xcccccccccccccccd`), và các hàm chuyển đổi
// container (`covert_ttm_dict_to_cpp_dict` tại `0x3481c` và
// `covert_ttm_list_to_cpp_list` tại `0x35220`).
// ============================================================================

#include "ttmstrategycenter_data_wrappers.h"
#include <stdexcept>

namespace nextai {
namespace ttm_strategy_center {

namespace {
void setErr(__TTMTransparentStruct* ctx, int32_t code, const char* fn, int32_t line) noexcept {
    if (ctx && ctx->error) {
        ctx->error->code      = code;
        ctx->error->func_name = fn;
        ctx->error->line      = line;
    }
}
} // namespace

// ============================================================================
// 1. ttm_sc_dict Implementation (0x36d38..0x39d0c)
// ============================================================================
// Disassembly @ 0x39d0c (88 B): allocates shared_ptr<unordered_map<string, std::any>>
ttm_sc_dict::ttm_sc_dict()
    : data_(std::make_shared<std::unordered_map<std::string, std::any>>()) {}

ttm_sc_dict::ttm_sc_dict(std::shared_ptr<std::unordered_map<std::string, std::any>> map_ptr)
    : data_(map_ptr ? std::move(map_ptr) : std::make_shared<std::unordered_map<std::string, std::any>>()) {}

// Disassembly @ 0x36d38 (44 B): copies shared_ptr with atomic ldxr/stxr increment on +8
std::shared_ptr<std::unordered_map<std::string, std::any>> ttm_sc_dict::getOriginValue() const {
    return data_;
}

// Disassembly @ 0x39458 (664 B): iterates bucket chain at data_->__table_.__p1_ and pushes keys
std::vector<std::string> ttm_sc_dict::getAllKeys() {
    std::vector<std::string> keys;
    if (!data_) {
        return keys;
    }
    keys.reserve(data_->size());
    for (const auto& kv : *data_) {
        keys.push_back(kv.first);
    }
    return keys;
}

void ttm_sc_dict::putInt(const std::string& key, int64_t val) {
    if (data_) (*data_)[key] = val;
}
void ttm_sc_dict::putDouble(const std::string& key, double val) {
    if (data_) (*data_)[key] = val;
}
void ttm_sc_dict::putBool(const std::string& key, bool val) {
    if (data_) (*data_)[key] = static_cast<int64_t>(val ? 1 : 0);
}
void ttm_sc_dict::putString(const std::string& key, const std::string& val) {
    if (data_) (*data_)[key] = val;
}
void ttm_sc_dict::putDict(const std::string& key, const ttm_sc_dict& val) {
    if (data_) (*data_)[key] = val;
}
void ttm_sc_dict::putList(const std::string& key, const ttm_sc_list& val) {
    if (data_) (*data_)[key] = val;
}

int64_t ttm_sc_dict::getInt(const std::string& key, int64_t default_val) const {
    if (!data_) return default_val;
    auto it = data_->find(key);
    if (it == data_->end()) return default_val;
    if (it->second.type() == typeid(int64_t)) return std::any_cast<int64_t>(it->second);
    if (it->second.type() == typeid(long)) return static_cast<int64_t>(std::any_cast<long>(it->second));
    if (it->second.type() == typeid(int)) return static_cast<int64_t>(std::any_cast<int>(it->second));
    return default_val;
}

double ttm_sc_dict::getDouble(const std::string& key, double default_val) const {
    if (!data_) return default_val;
    auto it = data_->find(key);
    if (it == data_->end()) return default_val;
    if (it->second.type() == typeid(double)) return std::any_cast<double>(it->second);
    if (it->second.type() == typeid(float)) return static_cast<double>(std::any_cast<float>(it->second));
    if (it->second.type() == typeid(int64_t)) return static_cast<double>(std::any_cast<int64_t>(it->second));
    return default_val;
}

std::string ttm_sc_dict::getString(const std::string& key) const {
    if (!data_) return {};
    auto it = data_->find(key);
    if (it == data_->end()) return {};
    if (it->second.type() == typeid(std::string)) return std::any_cast<std::string>(it->second);
    return {};
}

bool ttm_sc_dict::containsKey(const std::string& key) const {
    return data_ && (data_->find(key) != data_->end());
}

bool ttm_sc_dict::removeKey(const std::string& key) {
    return data_ && (data_->erase(key) > 0);
}

// ============================================================================
// 2. ttm_sc_list Implementation (0x41170..0x448e4)
// ============================================================================
// Disassembly @ 0x448e4 (76 B): allocates shared_ptr<vector<std::any>>
ttm_sc_list::ttm_sc_list()
    : data_(std::make_shared<std::vector<std::any>>()) {}

ttm_sc_list::ttm_sc_list(std::shared_ptr<std::vector<std::any>> vec_ptr)
    : data_(vec_ptr ? std::move(vec_ptr) : std::make_shared<std::vector<std::any>>()) {}

// Disassembly @ 0x41814 (44 B)
std::shared_ptr<std::vector<std::any>> ttm_sc_list::getOriginValue() const {
    return data_;
}

// Disassembly @ 0x41fa0 (648 B):
//   ldp x9, x8, [x8]               ; begin, end of vector<std::any> (each element = 40 bytes = 0x28)
//   sub x8, x8, x9                 ; byte_diff = end - begin
//   mov x9, #-0x3333333333333334   ; 0xcccccccccccccccd (modular inverse of 5 mod 2^64)
//   asr x8, x8, #3                 ; byte_diff >> 3 = byte_diff / 8
//   mul x8, x8, x9                 ; size = (byte_diff / 8) / 5 = byte_diff / 40
//   tbz x1, #0x3f, #0x41fec        ; if index >= 0 jump
//   adds x0, x8, x1                ; real_index = size + index (negative index wrap-around)
//   b.mi #0x41ff4                  ; if still < 0 -> throw out_of_range
// 0x41fec:
//   cmp x0, x8                     ; compare unsigned real_index vs size
//   b.ls #0x420fc                  ; Note: throws std::out_of_range("out of list size, index: ...") if >= size
long ttm_sc_list::make_real_index(long index) const {
    const uint64_t size = data_ ? static_cast<uint64_t>(data_->size()) : 0ULL;
    // Simulate exact AArch64 reciprocal multiplication on 40-byte stride:
    const uint64_t byte_span = size * 40ULL;
    const uint64_t computed_size = (byte_span >> 3) * 0xcccccccccccccccdULL;

    long real_idx = index;
    if (real_idx < 0) {
        real_idx = static_cast<long>(computed_size) + real_idx;
    }
    if (real_idx < 0 || static_cast<uint64_t>(real_idx) >= computed_size) {
        throw std::out_of_range(
            "out of list size, index: " + std::to_string(index) +
            "  list_size: " + std::to_string(computed_size));
    }
    return real_idx;
}

// Disassembly @ 0x4393c (44 B): uses same (end - begin) >> 3 * 0xcccccccccccccccd formula
long ttm_sc_list::getListSize() const {
    return data_ ? static_cast<long>(data_->size()) : 0L;
}

ElementValueType ttm_sc_list::getValueType(long index) const {
    if (!data_) return ElementValueType::kUnknown;
    long real_idx = make_real_index(index);
    const std::any& elem = (*data_)[static_cast<size_t>(real_idx)];
    if (elem.type() == typeid(int64_t) || elem.type() == typeid(long) || elem.type() == typeid(int)) {
        return ElementValueType::kInt;
    }
    if (elem.type() == typeid(double) || elem.type() == typeid(float)) {
        return ElementValueType::kFloat;
    }
    if (elem.type() == typeid(bool)) {
        return ElementValueType::kBool;
    }
    if (elem.type() == typeid(std::string)) {
        return ElementValueType::kString;
    }
    if (elem.type() == typeid(ttm_sc_list)) {
        return ElementValueType::kList;
    }
    if (elem.type() == typeid(ttm_sc_dict)) {
        return ElementValueType::kDict;
    }
    return ElementValueType::kUnknown;
}

void ttm_sc_list::putInt(long val) {
    if (data_) data_->emplace_back(static_cast<int64_t>(val));
}
void ttm_sc_list::putInt(int val) {
    if (data_) data_->emplace_back(static_cast<int64_t>(val));
}
void ttm_sc_list::putBool(bool val) {
    if (data_) data_->emplace_back(static_cast<int64_t>(val ? 1 : 0));
}
void ttm_sc_list::putDouble(double val) {
    if (data_) data_->emplace_back(val);
}
void ttm_sc_list::putFloat(float val) {
    if (data_) data_->emplace_back(static_cast<double>(val));
}
void ttm_sc_list::putString(const std::string& val) {
    if (data_) data_->emplace_back(val);
}
void ttm_sc_list::putDict(const ttm_sc_dict& val) {
    if (data_) data_->emplace_back(val);
}
void ttm_sc_list::putList(const ttm_sc_list& val) {
    if (data_) data_->emplace_back(val);
}

std::string ttm_sc_list::getString(long index) {
    long real_idx = make_real_index(index);
    const std::any& elem = (*data_)[static_cast<size_t>(real_idx)];
    if (elem.type() == typeid(std::string)) {
        return std::any_cast<std::string>(elem);
    }
    return {};
}

long ttm_sc_list::getInt(long index) {
    long real_idx = make_real_index(index);
    const std::any& elem = (*data_)[static_cast<size_t>(real_idx)];
    if (elem.type() == typeid(int64_t)) {
        return static_cast<long>(std::any_cast<int64_t>(elem));
    }
    if (elem.type() == typeid(long)) {
        return std::any_cast<long>(elem);
    }
    return static_cast<long>(kLongMaxValue);
}

double ttm_sc_list::getDouble(long index) {
    long real_idx = make_real_index(index);
    const std::any& elem = (*data_)[static_cast<size_t>(real_idx)];
    if (elem.type() == typeid(double)) {
        return std::any_cast<double>(elem);
    }
    return kDoubleMaxValue;
}

ttm_sc_dict ttm_sc_list::getDict(long index) {
    long real_idx = make_real_index(index);
    const std::any& elem = (*data_)[static_cast<size_t>(real_idx)];
    if (elem.type() == typeid(ttm_sc_dict)) {
        return std::any_cast<ttm_sc_dict>(elem);
    }
    return ttm_sc_dict();
}

ttm_sc_list ttm_sc_list::getList(long index) {
    long real_idx = make_real_index(index);
    const std::any& elem = (*data_)[static_cast<size_t>(real_idx)];
    if (elem.type() == typeid(ttm_sc_list)) {
        return std::any_cast<ttm_sc_list>(elem);
    }
    return ttm_sc_list();
}

void ttm_sc_list::modifyInt(long val, long index) {
    long real_idx = make_real_index(index);
    (*data_)[static_cast<size_t>(real_idx)] = static_cast<int64_t>(val);
}

void ttm_sc_list::modifyDouble(double val, long index) {
    long real_idx = make_real_index(index);
    (*data_)[static_cast<size_t>(real_idx)] = val;
}

void ttm_sc_list::modifyDict(const ttm_sc_dict& val, long index) {
    long real_idx = make_real_index(index);
    (*data_)[static_cast<size_t>(real_idx)] = val;
}

void ttm_sc_list::modifyList(const ttm_sc_list& val, long index) {
    long real_idx = make_real_index(index);
    (*data_)[static_cast<size_t>(real_idx)] = val;
}

void ttm_sc_list::removeValueByIndex(long index) {
    long real_idx = make_real_index(index);
    data_->erase(data_->begin() + real_idx);
}

// ============================================================================
// 3. StrategyCenterBasicDataWrapper Implementation (0x280cc..0x29648)
// ============================================================================
// Disassembly @ 0x29550 (72 B): stores inner at +0x08, (need_delete & 1) at +0x10, 1.0f at +0x98
StrategyCenterBasicDataWrapper::StrategyCenterBasicDataWrapper(void* origin_data, bool need_delete)
    : inner_(static_cast<TTMExtDataInterface*>(origin_data)),
      need_delete_(need_delete) {}

// Disassembly @ 0x280cc (480 B): deletes all cached temporary wrappers and optionally inner_
StrategyCenterBasicDataWrapper::~StrategyCenterBasicDataWrapper() {
    for (auto& kv : temp_wrappers_) {
        delete kv.second;
    }
    temp_wrappers_.clear();
    if (need_delete_ && inner_) {
        delete inner_;
        inner_ = nullptr;
    }
}

int64_t StrategyCenterBasicDataWrapper::GetArraySize(ElementValueType type, __TTMTransparentStruct* ctx) {
    if (inner_) return inner_->GetArraySize(type, ctx);
    setErr(ctx, 100, "GetArraySize", 0x2b);
    return 0;
}

const char* StrategyCenterBasicDataWrapper::GetStringValue(long index, __TTMTransparentStruct* ctx) {
    if (inner_) {
        const char* res = inner_->GetStringValue(index, ctx);
        if (res) return res;
        setErr(ctx, 100, "GetStringValue", 0x41);
        return nullptr;
    }
    setErr(ctx, 100, "GetStringValue", 0x38);
    return nullptr;
}

int64_t StrategyCenterBasicDataWrapper::GetIntValue(long index, __TTMTransparentStruct* ctx) {
    if (inner_) return inner_->GetIntValue(index, ctx);
    setErr(ctx, 100, "GetIntValue", 0x49);
    return 0;
}

double StrategyCenterBasicDataWrapper::GetDoubleValue(long index, __TTMTransparentStruct* ctx) {
    if (inner_) return inner_->GetDoubleValue(index, ctx);
    setErr(ctx, 100, "GetDoubleValue", 0x57);
    return 0.0;
}

std::vector<std::string> StrategyCenterBasicDataWrapper::GetAllStringValues(__TTMTransparentStruct* ctx) {
    if (inner_) return inner_->GetAllStringValues(ctx);
    setErr(ctx, 100, "GetAllStringValues", 0x65);
    return {};
}

std::vector<int64_t> StrategyCenterBasicDataWrapper::GetAllIntValues(__TTMTransparentStruct* ctx) {
    if (inner_) return inner_->GetAllIntValues(ctx);
    setErr(ctx, 100, "GetAllIntValues", 0x73);
    return {};
}

std::vector<double> StrategyCenterBasicDataWrapper::GetAllDoubleValues(__TTMTransparentStruct* ctx) {
    if (inner_) return inner_->GetAllDoubleValues(ctx);
    setErr(ctx, 100, "GetAllDoubleValues", 0x81);
    return {};
}

std::vector<std::string> StrategyCenterBasicDataWrapper::GetAllStringValues(const char* key, __TTMTransparentStruct* ctx) {
    if (inner_) return inner_->GetAllStringValues(key, ctx);
    setErr(ctx, 100, "GetAllStringValues", 0x8f);
    return {};
}

std::vector<int64_t> StrategyCenterBasicDataWrapper::GetAllIntValues(const char* key, __TTMTransparentStruct* ctx) {
    if (inner_) return inner_->GetAllIntValues(key, ctx);
    setErr(ctx, 100, "GetAllIntValues", 0x9d);
    return {};
}

std::vector<double> StrategyCenterBasicDataWrapper::GetAllDoubleValues(const char* key, __TTMTransparentStruct* ctx) {
    if (inner_) return inner_->GetAllDoubleValues(key, ctx);
    setErr(ctx, 100, "GetAllDoubleValues", 0xab);
    return {};
}

void* StrategyCenterBasicDataWrapper::GetExtObjectForKey(const char* key, __TTMTransparentStruct* ctx) {
    if (!key) return nullptr;
    auto it = temp_wrappers_.find(key);
    if (it != temp_wrappers_.end()) {
        return it->second;
    }
    if (inner_) {
        void* child = inner_->GetExtObjectForKey(key, ctx);
        if (child) {
            auto* wrapped = new StrategyCenterBasicDataWrapper(child, false);
            AddTemporaryExtWrapperData(key, wrapped);
            return wrapped;
        }
    }
    setErr(ctx, 100, "GetExtObjectForKey", 0xc0);
    return nullptr;
}

void* StrategyCenterBasicDataWrapper::GetExtObjectForIndex(long index, __TTMTransparentStruct* ctx) {
    std::string key = std::to_string(index);
    auto it = temp_wrappers_.find(key);
    if (it != temp_wrappers_.end()) {
        return it->second;
    }
    if (inner_) {
        void* child = inner_->GetExtObjectForIndex(index, ctx);
        if (child) {
            auto* wrapped = new StrategyCenterBasicDataWrapper(child, false);
            AddTemporaryExtWrapperData(key.c_str(), wrapped);
            return wrapped;
        }
    }
    setErr(ctx, 100, "GetExtObjectForIndex", 0xd8);
    return nullptr;
}

void* StrategyCenterBasicDataWrapper::GetExtObjectByKeyAndIndex(const char* key, long index, __TTMTransparentStruct* ctx) {
    if (!key) return nullptr;
    std::string composite = std::string(key) + std::to_string(index);
    auto it = temp_wrappers_.find(composite);
    if (it != temp_wrappers_.end()) {
        return it->second;
    }
    if (inner_) {
        void* child = inner_->GetExtObjectByKeyAndIndex(key, index, ctx);
        if (child) {
            auto* wrapped = new StrategyCenterBasicDataWrapper(child, false);
            AddTemporaryExtWrapperData(composite.c_str(), wrapped);
            return wrapped;
        }
    }
    setErr(ctx, 100, "GetExtObjectByKeyAndIndex", 0xf2);
    return nullptr;
}

const char* StrategyCenterBasicDataWrapper::GetStringValue(const char* key, __TTMTransparentStruct* ctx) {
    if (inner_) return inner_->GetStringValue(key, ctx);
    setErr(ctx, 100, "GetStringValue", 0x105);
    return nullptr;
}

int64_t StrategyCenterBasicDataWrapper::GetIntValue(const char* key, __TTMTransparentStruct* ctx) {
    if (inner_) return inner_->GetIntValue(key, ctx);
    setErr(ctx, 100, "GetIntValue", 0x110);
    return 0;
}

double StrategyCenterBasicDataWrapper::GetDoubleValue(const char* key, __TTMTransparentStruct* ctx) {
    if (inner_) return inner_->GetDoubleValue(key, ctx);
    setErr(ctx, 100, "GetDoubleValue", 0x11b);
    return 0.0;
}

void* StrategyCenterBasicDataWrapper::GetOriginData(__TTMTransparentStruct* ctx) {
    if (inner_) return inner_->GetOriginData(ctx);
    setErr(ctx, 100, "GetOriginData", 0x126);
    return nullptr;
}

std::vector<std::string> StrategyCenterBasicDataWrapper::GetDictAllValuesForString(__TTMTransparentStruct* ctx) {
    if (inner_) return inner_->GetDictAllValuesForString(ctx);
    setErr(ctx, 100, "GetDictAllValuesForString", 0x132);
    return {};
}

std::vector<int64_t> StrategyCenterBasicDataWrapper::GetDictAllValuesForInt(__TTMTransparentStruct* ctx) {
    if (inner_) return inner_->GetDictAllValuesForInt(ctx);
    setErr(ctx, 100, "GetDictAllValuesForInt", 0x13e);
    return {};
}

std::vector<double> StrategyCenterBasicDataWrapper::GetDictAllValuesForDouble(__TTMTransparentStruct* ctx) {
    if (inner_) return inner_->GetDictAllValuesForDouble(ctx);
    setErr(ctx, 100, "GetDictAllValuesForDouble", 0x14a);
    return {};
}

std::vector<std::string> StrategyCenterBasicDataWrapper::GetDictAllKeys(__TTMTransparentStruct* ctx) {
    if (inner_) return inner_->GetDictAllKeys(ctx);
    setErr(ctx, 100, "GetDictAllKeys", 0x156);
    return {};
}

void StrategyCenterBasicDataWrapper::AddTemporaryExtWrapperData(const char* key, StrategyCenterBasicDataWrapper* wrapper) {
    if (!key || !wrapper) return;
    RemoveTemporaryExtWrapperDataAndDelete(key);
    temp_wrappers_[key] = wrapper;
}

void StrategyCenterBasicDataWrapper::RemoveTemporaryExtWrapperDataAndDelete(const char* key) {
    if (!key) return;
    auto it = temp_wrappers_.find(key);
    if (it != temp_wrappers_.end()) {
        delete it->second;
        temp_wrappers_.erase(it);
    }
}

// ============================================================================
// 4. ttm_sc_basic_data_wrapper & ttm_sc_dict_param_data (0x30f74..0x3fa7c)
// ============================================================================
ttm_sc_basic_data_wrapper::~ttm_sc_basic_data_wrapper() {
    for (auto& kv : temp_cache_) {
        delete kv.second;
    }
    temp_cache_.clear();
}

void* ttm_sc_basic_data_wrapper::GetExtObjectForKey(const char* key, __TTMTransparentStruct* ctx) {
    (void)ctx;
    if (!key) return nullptr;
    auto it = temp_cache_.find(key);
    return (it != temp_cache_.end()) ? it->second : nullptr;
}

void* ttm_sc_basic_data_wrapper::GetExtObjectForIndex(long index, __TTMTransparentStruct* ctx) {
    (void)ctx;
    std::string k = std::to_string(index);
    auto it = temp_cache_.find(k);
    return (it != temp_cache_.end()) ? it->second : nullptr;
}

void* ttm_sc_basic_data_wrapper::GetExtObjectByKeyAndIndex(const char* key, long index, __TTMTransparentStruct* ctx) {
    (void)ctx;
    if (!key) return nullptr;
    std::string k = std::string(key) + std::to_string(index);
    auto it = temp_cache_.find(k);
    return (it != temp_cache_.end()) ? it->second : nullptr;
}

void ttm_sc_basic_data_wrapper::AddTemporaryExtWrapperData(const char* key, ttm_sc_basic_data_wrapper* wrapper) {
    if (!key || !wrapper) return;
    RemoveTemporaryExtWrapperDataAndDelete(key);
    temp_cache_[key] = wrapper;
}

void ttm_sc_basic_data_wrapper::RemoveTemporaryExtWrapperDataAndDelete(const char* key) {
    if (!key) return;
    auto it = temp_cache_.find(key);
    if (it != temp_cache_.end()) {
        delete it->second;
        temp_cache_.erase(it);
    }
}

// Disassembly @ 0x3fa48 (52 B): default ctor sets tag_ = 4 (dict) with fresh ttm_sc_dict
ttm_sc_dict_param_data::ttm_sc_dict_param_data()
    : dict_val_(std::make_shared<ttm_sc_dict>()), tag_(4) {}

// Disassembly @ 0x3ad40 (52 B): int ctor sets int_val_ = val (+0x50), tag_ = 1 (+0x58)
ttm_sc_dict_param_data::ttm_sc_dict_param_data(long val)
    : int_val_(val), tag_(1) {}

// Disassembly @ 0x3ad74 (56 B): double ctor sets double_val_ = val (+0x50), tag_ = 2 (+0x58)
ttm_sc_dict_param_data::ttm_sc_dict_param_data(double val)
    : double_val_(val), tag_(2) {}

ttm_sc_dict_param_data::ttm_sc_dict_param_data(std::string val)
    : str_val_(std::move(val)), tag_(3) {}

ttm_sc_dict_param_data::ttm_sc_dict_param_data(std::shared_ptr<ttm_sc_dict> d)
    : dict_val_(std::move(d)), tag_(4) {}

ttm_sc_dict_param_data::ttm_sc_dict_param_data(std::shared_ptr<ttm_sc_list> l)
    : list_val_(std::move(l)), tag_(5) {}

ttm_sc_dict_param_data::~ttm_sc_dict_param_data() = default;

int64_t ttm_sc_dict_param_data::GetArraySize(ElementValueType type, __TTMTransparentStruct* ctx) {
    (void)type;
    (void)ctx;
    if (tag_ == 5 && list_val_) {
        return list_val_->getListSize();
    }
    return 0;
}

const char* ttm_sc_dict_param_data::GetStringValue(long index, __TTMTransparentStruct* ctx) {
    (void)ctx;
    if (tag_ == 5 && list_val_) {
        scratch_str_ = list_val_->getString(index);
        return scratch_str_.c_str();
    }
    return nullptr;
}

int64_t ttm_sc_dict_param_data::GetIntValue(long index, __TTMTransparentStruct* ctx) {
    (void)ctx;
    if (tag_ == 5 && list_val_) {
        return list_val_->getInt(index);
    }
    return kLongMaxValue;
}

double ttm_sc_dict_param_data::GetDoubleValue(long index, __TTMTransparentStruct* ctx) {
    (void)ctx;
    if (tag_ == 5 && list_val_) {
        return list_val_->getDouble(index);
    }
    return kDoubleMaxValue;
}

std::vector<std::string> ttm_sc_dict_param_data::GetAllStringValues(__TTMTransparentStruct* ctx) {
    (void)ctx;
    std::vector<std::string> out;
    if (tag_ == 5 && list_val_) {
        long n = list_val_->getListSize();
        for (long i = 0; i < n; ++i) {
            out.push_back(list_val_->getString(i));
        }
    }
    return out;
}

std::vector<int64_t> ttm_sc_dict_param_data::GetAllIntValues(__TTMTransparentStruct* ctx) {
    (void)ctx;
    std::vector<int64_t> out;
    if (tag_ == 5 && list_val_) {
        long n = list_val_->getListSize();
        for (long i = 0; i < n; ++i) {
            out.push_back(list_val_->getInt(i));
        }
    }
    return out;
}

std::vector<double> ttm_sc_dict_param_data::GetAllDoubleValues(__TTMTransparentStruct* ctx) {
    (void)ctx;
    std::vector<double> out;
    if (tag_ == 5 && list_val_) {
        long n = list_val_->getListSize();
        for (long i = 0; i < n; ++i) {
            out.push_back(list_val_->getDouble(i));
        }
    }
    return out;
}

std::vector<std::string> ttm_sc_dict_param_data::GetAllStringValues(const char* key, __TTMTransparentStruct* ctx) {
    auto* sub = static_cast<ttm_sc_dict_param_data*>(GetExtObjectForKey(key, ctx));
    return sub ? sub->GetAllStringValues(ctx) : std::vector<std::string>{};
}

std::vector<int64_t> ttm_sc_dict_param_data::GetAllIntValues(const char* key, __TTMTransparentStruct* ctx) {
    auto* sub = static_cast<ttm_sc_dict_param_data*>(GetExtObjectForKey(key, ctx));
    return sub ? sub->GetAllIntValues(ctx) : std::vector<int64_t>{};
}

std::vector<double> ttm_sc_dict_param_data::GetAllDoubleValues(const char* key, __TTMTransparentStruct* ctx) {
    auto* sub = static_cast<ttm_sc_dict_param_data*>(GetExtObjectForKey(key, ctx));
    return sub ? sub->GetAllDoubleValues(ctx) : std::vector<double>{};
}

void* ttm_sc_dict_param_data::GetExtObjectForKey(const char* key, __TTMTransparentStruct* ctx) {
    if (!key) return nullptr;
    if (void* cached = ttm_sc_basic_data_wrapper::GetExtObjectForKey(key, ctx)) {
        return cached;
    }
    if (tag_ != 4 || !dict_val_ || !dict_val_->getOriginValue()) {
        return nullptr;
    }
    auto map = dict_val_->getOriginValue();
    auto it = map->find(key);
    if (it == map->end()) {
        return nullptr;
    }
    ttm_sc_dict_param_data* child = nullptr;
    if (it->second.type() == typeid(int64_t)) {
        child = new ttm_sc_dict_param_data(static_cast<long>(std::any_cast<int64_t>(it->second)));
    } else if (it->second.type() == typeid(double)) {
        child = new ttm_sc_dict_param_data(std::any_cast<double>(it->second));
    } else if (it->second.type() == typeid(std::string)) {
        child = new ttm_sc_dict_param_data(std::any_cast<std::string>(it->second));
    } else if (it->second.type() == typeid(ttm_sc_dict)) {
        child = new ttm_sc_dict_param_data(std::make_shared<ttm_sc_dict>(std::any_cast<ttm_sc_dict>(it->second)));
    } else if (it->second.type() == typeid(ttm_sc_list)) {
        child = new ttm_sc_dict_param_data(std::make_shared<ttm_sc_list>(std::any_cast<ttm_sc_list>(it->second)));
    }
    if (child) {
        AddTemporaryExtWrapperData(key, child);
    }
    return child;
}

void* ttm_sc_dict_param_data::GetExtObjectForIndex(long index, __TTMTransparentStruct* ctx) {
    if (void* cached = ttm_sc_basic_data_wrapper::GetExtObjectForIndex(index, ctx)) {
        return cached;
    }
    if (tag_ != 5 || !list_val_ || !list_val_->getOriginValue()) {
        return nullptr;
    }
    long real_idx = list_val_->make_real_index(index);
    const std::any& elem = (*list_val_->getOriginValue())[static_cast<size_t>(real_idx)];
    ttm_sc_dict_param_data* child = nullptr;
    if (elem.type() == typeid(int64_t)) {
        child = new ttm_sc_dict_param_data(static_cast<long>(std::any_cast<int64_t>(elem)));
    } else if (elem.type() == typeid(double)) {
        child = new ttm_sc_dict_param_data(std::any_cast<double>(elem));
    } else if (elem.type() == typeid(std::string)) {
        child = new ttm_sc_dict_param_data(std::any_cast<std::string>(elem));
    } else if (elem.type() == typeid(ttm_sc_dict)) {
        child = new ttm_sc_dict_param_data(std::make_shared<ttm_sc_dict>(std::any_cast<ttm_sc_dict>(elem)));
    } else if (elem.type() == typeid(ttm_sc_list)) {
        child = new ttm_sc_dict_param_data(std::make_shared<ttm_sc_list>(std::any_cast<ttm_sc_list>(elem)));
    }
    if (child) {
        std::string k = std::to_string(index);
        AddTemporaryExtWrapperData(k.c_str(), child);
    }
    return child;
}

void* ttm_sc_dict_param_data::GetExtObjectByKeyAndIndex(const char* key, long index, __TTMTransparentStruct* ctx) {
    auto* sub = static_cast<ttm_sc_dict_param_data*>(GetExtObjectForKey(key, ctx));
    return sub ? sub->GetExtObjectForIndex(index, ctx) : nullptr;
}

const char* ttm_sc_dict_param_data::GetStringValue(const char* key, __TTMTransparentStruct* ctx) {
    (void)ctx;
    if (tag_ == 3) return str_val_.c_str();
    if (tag_ == 4 && dict_val_ && key) {
        scratch_str_ = dict_val_->getString(key);
        return scratch_str_.c_str();
    }
    return nullptr;
}

int64_t ttm_sc_dict_param_data::GetIntValue(const char* key, __TTMTransparentStruct* ctx) {
    (void)ctx;
    if (tag_ == 1) return int_val_;
    if (tag_ == 4 && dict_val_ && key) return dict_val_->getInt(key);
    return kLongMaxValue;
}

double ttm_sc_dict_param_data::GetDoubleValue(const char* key, __TTMTransparentStruct* ctx) {
    (void)ctx;
    if (tag_ == 2) return double_val_;
    if (tag_ == 4 && dict_val_ && key) return dict_val_->getDouble(key);
    return kDoubleMaxValue;
}

void* ttm_sc_dict_param_data::GetOriginData(__TTMTransparentStruct* ctx) {
    (void)ctx;
    return this;
}

std::vector<std::string> ttm_sc_dict_param_data::GetDictAllValuesForString(__TTMTransparentStruct* ctx) {
    (void)ctx;
    std::vector<std::string> out;
    if (tag_ == 4 && dict_val_ && dict_val_->getOriginValue()) {
        for (const auto& kv : *dict_val_->getOriginValue()) {
            if (kv.second.type() == typeid(std::string)) {
                out.push_back(std::any_cast<std::string>(kv.second));
            }
        }
    }
    return out;
}

std::vector<int64_t> ttm_sc_dict_param_data::GetDictAllValuesForInt(__TTMTransparentStruct* ctx) {
    (void)ctx;
    std::vector<int64_t> out;
    if (tag_ == 4 && dict_val_ && dict_val_->getOriginValue()) {
        for (const auto& kv : *dict_val_->getOriginValue()) {
            if (kv.second.type() == typeid(int64_t)) {
                out.push_back(std::any_cast<int64_t>(kv.second));
            }
        }
    }
    return out;
}

std::vector<double> ttm_sc_dict_param_data::GetDictAllValuesForDouble(__TTMTransparentStruct* ctx) {
    (void)ctx;
    std::vector<double> out;
    if (tag_ == 4 && dict_val_ && dict_val_->getOriginValue()) {
        for (const auto& kv : *dict_val_->getOriginValue()) {
            if (kv.second.type() == typeid(double)) {
                out.push_back(std::any_cast<double>(kv.second));
            }
        }
    }
    return out;
}

std::vector<std::string> ttm_sc_dict_param_data::GetDictAllKeys(__TTMTransparentStruct* ctx) {
    (void)ctx;
    if (tag_ == 4 && dict_val_) {
        return dict_val_->getAllKeys();
    }
    return {};
}

// Disassembly @ 0x3eeac (8 B): mov w0, #1; ret
int32_t ttm_sc_dict_param_data::GetOriginDataType(__TTMTransparentStruct* ctx) {
    (void)ctx;
    return 1;
}

bool ttm_sc_dict_param_data::ModifyMutExtDictKeyValue(const char* key, void* val_obj, __TTMTransparentStruct* ctx) {
    (void)ctx;
    if (tag_ != 4 || !dict_val_ || !key || !val_obj) return false;
    auto* obj = static_cast<_object*>(val_obj);
    if (obj->ob_type == &TTMIntO_Type || obj->ob_type == &TTMBoolO_Type) {
        dict_val_->putInt(key, obj->payload.int_val);
        return true;
    }
    if (obj->ob_type == &TTMFloatO_Type) {
        dict_val_->putDouble(key, obj->payload.float_val);
        return true;
    }
    if (obj->ob_type == &TTMStringO_Type) {
        const char* s = obj->data_ptr ? static_cast<const char*>(obj->data_ptr) : obj->owned_str.c_str();
        dict_val_->putString(key, s ? s : "");
        return true;
    }
    return false;
}

bool ttm_sc_dict_param_data::ModifyMutExtListValueByIndex(void* val_obj, long long index, __TTMTransparentStruct* ctx) {
    (void)ctx;
    if (tag_ != 5 || !list_val_ || !val_obj) return false;
    auto* obj = static_cast<_object*>(val_obj);
    if (obj->ob_type == &TTMIntO_Type) {
        list_val_->modifyInt(static_cast<long>(obj->payload.int_val), static_cast<long>(index));
        return true;
    }
    if (obj->ob_type == &TTMFloatO_Type) {
        list_val_->modifyDouble(obj->payload.float_val, static_cast<long>(index));
        return true;
    }
    return false;
}

// Disassembly @ 0x3f5c4 (12 B): tail-calls ModifyMutExtDictKeyValue
bool ttm_sc_dict_param_data::MutExtDictAddKeyValue(const char* key, void* val_obj, __TTMTransparentStruct* ctx) {
    return ModifyMutExtDictKeyValue(key, val_obj, ctx);
}

bool ttm_sc_dict_param_data::MutExtListAppendValue(void* val_obj, __TTMTransparentStruct* ctx) {
    (void)ctx;
    if (tag_ != 5 || !list_val_ || !val_obj) return false;
    auto* obj = static_cast<_object*>(val_obj);
    if (obj->ob_type == &TTMIntO_Type) {
        list_val_->putInt(static_cast<long>(obj->payload.int_val));
        return true;
    }
    if (obj->ob_type == &TTMFloatO_Type) {
        list_val_->putDouble(obj->payload.float_val);
        return true;
    }
    if (obj->ob_type == &TTMStringO_Type) {
        const char* s = obj->data_ptr ? static_cast<const char*>(obj->data_ptr) : obj->owned_str.c_str();
        list_val_->putString(s ? s : "");
        return true;
    }
    return false;
}

bool ttm_sc_dict_param_data::MutExtDictRemoveKey(const char* key, __TTMTransparentStruct* ctx) {
    (void)ctx;
    if (tag_ != 4 || !dict_val_ || !key) return false;
    RemoveTemporaryExtWrapperDataAndDelete(key);
    return dict_val_->removeKey(key);
}

bool ttm_sc_dict_param_data::MutExtListRemoveValueByIndex(long index, __TTMTransparentStruct* ctx) {
    (void)ctx;
    if (tag_ != 5 || !list_val_) return false;
    list_val_->removeValueByIndex(index);
    return true;
}

bool ttm_sc_dict_param_data::ExtDictContainKey(const char* key, __TTMTransparentStruct* ctx) {
    (void)ctx;
    return (tag_ == 4 && dict_val_ && key) ? dict_val_->containsKey(key) : false;
}

std::shared_ptr<ttm_sc_dict> ttm_sc_dict_param_data::get_origin_dict_value(__TTMTransparentStruct* ctx) const {
    (void)ctx;
    return dict_val_;
}

std::shared_ptr<ttm_sc_list> ttm_sc_dict_param_data::get_origin_list_value(__TTMTransparentStruct* ctx) const {
    (void)ctx;
    return list_val_;
}

// Disassembly @ 0x3fa34 (20 B): ldr w8, [x0, #0x58]; ret
int32_t ttm_sc_dict_param_data::GetExtObjDataType(__TTMTransparentStruct* ctx) const {
    (void)ctx;
    return tag_;
}

// ============================================================================
// 5. CreateTTMAllocDataType & ttm_sc_map_vector_data (0x44a9c..0x45838)
// ============================================================================
// Disassembly @ 0x44d10 (48 B): allocates 0x10 (16) bytes, stores {uint32_t type @ +0x00, void* ptr @ +0x08}
TTMAllocDataTag* CreateTTMAllocDataType(uint32_t type, void* ptr) {
    auto* tag = new TTMAllocDataTag();
    tag->type = type;
    tag->ptr  = ptr;
    return tag;
}

TTMAllocDataTag* TTMGetObjectForKey(TTMAllocDataTag* map_tag, const char* key, __TTMTransparentStruct* ctx) {
    if (!map_tag || map_tag->type != 4 || !map_tag->ptr || !key) {
        setErr(ctx, 100, "TTMGetObjectForKey", 0x16);
        return nullptr;
    }
    auto* m = static_cast<std::unordered_map<std::string, TTMAllocDataTag*>*>(map_tag->ptr);
    auto it = m->find(key);
    return (it != m->end()) ? it->second : nullptr;
}

TTMAllocDataTag* TTMGetObjectForIndex(TTMAllocDataTag* vec_tag, long index, __TTMTransparentStruct* ctx) {
    if (!vec_tag || vec_tag->type != 5 || !vec_tag->ptr || index < 0) {
        setErr(ctx, 100, "TTMGetObjectForIndex", 0x24);
        return nullptr;
    }
    auto* v = static_cast<std::vector<TTMAllocDataTag*>*>(vec_tag->ptr);
    if (static_cast<size_t>(index) >= v->size()) {
        setErr(ctx, 100, "TTMGetObjectForIndex", 0x28);
        return nullptr;
    }
    return (*v)[static_cast<size_t>(index)];
}

TTMAllocDataTag* TTMGetObjectForKeyAndIndex(TTMAllocDataTag* map_tag, const char* key, long index, __TTMTransparentStruct* ctx) {
    TTMAllocDataTag* sub = TTMGetObjectForKey(map_tag, key, ctx);
    return sub ? TTMGetObjectForIndex(sub, index, ctx) : nullptr;
}

// Disassembly @ 0x44d40 (44 B)
ttm_sc_map_vector_data::ttm_sc_map_vector_data(void* origin_tag)
    : origin_(static_cast<TTMAllocDataTag*>(origin_tag)) {}

ttm_sc_map_vector_data::~ttm_sc_map_vector_data() {
    for (auto* child : child_wrappers_) {
        delete child;
    }
    child_wrappers_.clear();
}

int64_t ttm_sc_map_vector_data::GetArraySize(ElementValueType type, __TTMTransparentStruct* ctx) {
    (void)type;
    (void)ctx;
    if (!origin_ || !origin_->ptr) return 0;
    if (origin_->type == 1) return static_cast<int64_t>(static_cast<std::vector<int64_t>*>(origin_->ptr)->size());
    if (origin_->type == 2) return static_cast<int64_t>(static_cast<std::vector<double>*>(origin_->ptr)->size());
    if (origin_->type == 3) return static_cast<int64_t>(static_cast<std::vector<std::string>*>(origin_->ptr)->size());
    if (origin_->type == 5) return static_cast<int64_t>(static_cast<std::vector<TTMAllocDataTag*>*>(origin_->ptr)->size());
    return 0;
}

const char* ttm_sc_map_vector_data::GetStringValue(long index, __TTMTransparentStruct* ctx) {
    (void)ctx;
    if (origin_ && origin_->type == 3 && origin_->ptr && index >= 0) {
        auto* v = static_cast<std::vector<std::string>*>(origin_->ptr);
        if (static_cast<size_t>(index) < v->size()) return (*v)[static_cast<size_t>(index)].c_str();
    }
    return nullptr;
}

int64_t ttm_sc_map_vector_data::GetIntValue(long index, __TTMTransparentStruct* ctx) {
    (void)ctx;
    if (origin_ && origin_->type == 1 && origin_->ptr && index >= 0) {
        auto* v = static_cast<std::vector<int64_t>*>(origin_->ptr);
        if (static_cast<size_t>(index) < v->size()) return (*v)[static_cast<size_t>(index)];
    }
    return 0;
}

double ttm_sc_map_vector_data::GetDoubleValue(long index, __TTMTransparentStruct* ctx) {
    (void)ctx;
    if (origin_ && origin_->type == 2 && origin_->ptr && index >= 0) {
        auto* v = static_cast<std::vector<double>*>(origin_->ptr);
        if (static_cast<size_t>(index) < v->size()) return (*v)[static_cast<size_t>(index)];
    }
    return 0.0;
}

std::vector<std::string> ttm_sc_map_vector_data::GetAllStringValues(__TTMTransparentStruct* ctx) {
    (void)ctx;
    if (origin_ && origin_->type == 3 && origin_->ptr) {
        return *static_cast<std::vector<std::string>*>(origin_->ptr);
    }
    return {};
}

std::vector<int64_t> ttm_sc_map_vector_data::GetAllIntValues(__TTMTransparentStruct* ctx) {
    (void)ctx;
    if (origin_ && origin_->type == 1 && origin_->ptr) {
        return *static_cast<std::vector<int64_t>*>(origin_->ptr);
    }
    return {};
}

std::vector<double> ttm_sc_map_vector_data::GetAllDoubleValues(__TTMTransparentStruct* ctx) {
    (void)ctx;
    if (origin_ && origin_->type == 2 && origin_->ptr) {
        return *static_cast<std::vector<double>*>(origin_->ptr);
    }
    return {};
}

std::vector<std::string> ttm_sc_map_vector_data::GetAllStringValues(const char* key, __TTMTransparentStruct* ctx) {
    auto* sub = static_cast<ttm_sc_map_vector_data*>(GetExtObjectForKey(key, ctx));
    return sub ? sub->GetAllStringValues(ctx) : std::vector<std::string>{};
}

std::vector<int64_t> ttm_sc_map_vector_data::GetAllIntValues(const char* key, __TTMTransparentStruct* ctx) {
    auto* sub = static_cast<ttm_sc_map_vector_data*>(GetExtObjectForKey(key, ctx));
    return sub ? sub->GetAllIntValues(ctx) : std::vector<int64_t>{};
}

std::vector<double> ttm_sc_map_vector_data::GetAllDoubleValues(const char* key, __TTMTransparentStruct* ctx) {
    auto* sub = static_cast<ttm_sc_map_vector_data*>(GetExtObjectForKey(key, ctx));
    return sub ? sub->GetAllDoubleValues(ctx) : std::vector<double>{};
}

void* ttm_sc_map_vector_data::GetExtObjectForKey(const char* key, __TTMTransparentStruct* ctx) {
    TTMAllocDataTag* sub = TTMGetObjectForKey(origin_, key, ctx);
    if (!sub) return nullptr;
    auto* wrapper = new ttm_sc_map_vector_data(sub);
    child_wrappers_.push_back(wrapper);
    return wrapper;
}

void* ttm_sc_map_vector_data::GetExtObjectByKeyAndIndex(const char* key, long index, __TTMTransparentStruct* ctx) {
    TTMAllocDataTag* sub = TTMGetObjectForKeyAndIndex(origin_, key, index, ctx);
    if (!sub) return nullptr;
    auto* wrapper = new ttm_sc_map_vector_data(sub);
    child_wrappers_.push_back(wrapper);
    return wrapper;
}

void* ttm_sc_map_vector_data::GetExtObjectForIndex(long index, __TTMTransparentStruct* ctx) {
    TTMAllocDataTag* sub = TTMGetObjectForIndex(origin_, index, ctx);
    if (!sub) return nullptr;
    auto* wrapper = new ttm_sc_map_vector_data(sub);
    child_wrappers_.push_back(wrapper);
    return wrapper;
}

std::vector<std::string> ttm_sc_map_vector_data::GetDictAllValuesForString(__TTMTransparentStruct* ctx) {
    (void)ctx;
    return {};
}
std::vector<int64_t> ttm_sc_map_vector_data::GetDictAllValuesForInt(__TTMTransparentStruct* ctx) {
    (void)ctx;
    return {};
}
std::vector<double> ttm_sc_map_vector_data::GetDictAllValuesForDouble(__TTMTransparentStruct* ctx) {
    (void)ctx;
    return {};
}
std::vector<std::string> ttm_sc_map_vector_data::GetDictAllKeys(__TTMTransparentStruct* ctx) {
    (void)ctx;
    std::vector<std::string> keys;
    if (origin_ && origin_->type == 4 && origin_->ptr) {
        auto* m = static_cast<std::unordered_map<std::string, TTMAllocDataTag*>*>(origin_->ptr);
        for (const auto& kv : *m) keys.push_back(kv.first);
    }
    return keys;
}

const char* ttm_sc_map_vector_data::GetStringValue(const char* key, __TTMTransparentStruct* ctx) {
    auto* sub = static_cast<ttm_sc_map_vector_data*>(GetExtObjectForKey(key, ctx));
    return sub ? sub->GetStringValue(0L, ctx) : nullptr;
}
int64_t ttm_sc_map_vector_data::GetIntValue(const char* key, __TTMTransparentStruct* ctx) {
    auto* sub = static_cast<ttm_sc_map_vector_data*>(GetExtObjectForKey(key, ctx));
    return sub ? sub->GetIntValue(0L, ctx) : 0;
}
double ttm_sc_map_vector_data::GetDoubleValue(const char* key, __TTMTransparentStruct* ctx) {
    auto* sub = static_cast<ttm_sc_map_vector_data*>(GetExtObjectForKey(key, ctx));
    return sub ? sub->GetDoubleValue(0L, ctx) : 0.0;
}
void* ttm_sc_map_vector_data::GetOriginData(__TTMTransparentStruct* ctx) {
    (void)ctx;
    return origin_;
}

// ============================================================================
// 6. covert_ttm_dict_to_cpp_dict (0x3481c) & covert_ttm_list_to_cpp_list (0x35220)
// ============================================================================
ttm_sc_dict covert_ttm_dict_to_cpp_dict(_dictobject* dict_obj, __TTMTransparentStruct* ctx) {
    ttm_sc_dict out;
    if (!dict_obj) return out;
    for (const auto& kv : dict_obj->owned_dict) {
        _object* val = kv.second;
        if (!val) continue;
        if (val->ob_type == &TTMIntO_Type || val->ob_type == &TTMBoolO_Type) {
            out.putInt(kv.first, val->payload.int_val);
        } else if (val->ob_type == &TTMFloatO_Type) {
            out.putDouble(kv.first, val->payload.float_val);
        } else if (val->ob_type == &TTMStringO_Type) {
            const char* s = val->data_ptr ? static_cast<const char*>(val->data_ptr) : val->owned_str.c_str();
            out.putString(kv.first, s ? s : "");
        } else if (val->ob_type == &TTMDictO_Type) {
            out.putDict(kv.first, covert_ttm_dict_to_cpp_dict(val, ctx));
        } else if (val->ob_type == &TTMListO_Type) {
            out.putList(kv.first, covert_ttm_list_to_cpp_list(val, ctx));
        }
    }
    return out;
}

ttm_sc_list covert_ttm_list_to_cpp_list(TTMListO* list_obj, __TTMTransparentStruct* ctx) {
    (void)ctx;
    ttm_sc_list out;
    if (!list_obj) return out;
    const int64_t count = list_obj->payload.list_size;
    if (count > 0 && list_obj->data_ptr) {
        const auto* raw = static_cast<const double*>(list_obj->data_ptr);
        for (int64_t i = 0; i < count; ++i) {
            out.putDouble(raw[i]);
        }
    }
    return out;
}

} // namespace ttm_strategy_center
} // namespace nextai
