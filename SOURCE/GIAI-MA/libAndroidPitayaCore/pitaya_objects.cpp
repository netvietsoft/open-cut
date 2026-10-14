// ======================================================================
// IMPLEMENTATION: pitaya_objects.cpp
// Library: libAndroidPitayaCore.so (ByteDance Pitaya On-Device AI Core)
// Component: NextAI OpenCut AI & Computer Vision Core (CORE_02_AI_CV)
// Architecture: AArch64 (ARMv8-A / ARM64)
//
// Description (English):
//   Full implementation of Pitaya dynamic object model, JSON parser
//   and serializer, and thread-safe JNI native handle registry.
//
// Mô tả (Tiếng Việt):
//   Triển khai đầy đủ mô hình đối tượng động Pitaya, bộ phân tích và
//   tuần tự hóa JSON, cùng sổ đăng ký handle JNI native an toàn đa luồng.
// ======================================================================

#include "pitaya_objects.h"
#include <iomanip>
#include <sstream>
#include <iostream>

namespace NextAI::OpenCut::pitaya {

// ----------------------------------------------------------------------
// Helper: JSON String Escaping
// ----------------------------------------------------------------------
static std::string EscapeJSONString(const std::string& input) {
    std::ostringstream ss;
    ss << '"';
    for (char c : input) {
        switch (c) {
            case '"':  ss << "\\\""; break;
            case '\\': ss << "\\\\"; break;
            case '\b': ss << "\\b";  break;
            case '\f': ss << "\\f";  break;
            case '\n': ss << "\\n";  break;
            case '\r': ss << "\\r";  break;
            case '\t': ss << "\\t";  break;
            default:
                if (static_cast<unsigned char>(c) < 0x20) {
                    ss << "\\u" << std::hex << std::setw(4) << std::setfill('0') << static_cast<int>(c);
                } else {
                    ss << c;
                }
                break;
        }
    }
    ss << '"';
    return ss.str();
}

std::string PTYFloat::ToString() const {
    std::ostringstream ss;
    ss << val_;
    return ss.str();
}

std::string PTYFloat::ToJSON() const {
    return ToString();
}

std::string PTYDouble::ToString() const {
    std::ostringstream ss;
    ss << val_;
    return ss.str();
}

std::string PTYDouble::ToJSON() const {
    return ToString();
}

std::string PTYStr::ToJSON() const {
    return EscapeJSONString(val_);
}

// ----------------------------------------------------------------------
// PTYList Implementation
// ----------------------------------------------------------------------
std::string PTYList::ToString() const {
    return ToJSON();
}

std::string PTYList::ToJSON() const {
    std::lock_guard<std::mutex> lock(mutex_);
    std::ostringstream ss;
    ss << "[";
    for (size_t i = 0; i < items_.size(); ++i) {
        if (i > 0) ss << ",";
        if (items_[i]) {
            ss << items_[i]->ToJSON();
        } else {
            ss << "null";
        }
    }
    ss << "]";
    return ss.str();
}

std::shared_ptr<PTYObject> PTYList::Clone() const {
    std::lock_guard<std::mutex> lock(mutex_);
    auto copy = std::make_shared<PTYList>();
    for (const auto& item : items_) {
        if (item) {
            copy->items_.push_back(item->Clone());
        } else {
            copy->items_.push_back(std::make_shared<PTYNull>());
        }
    }
    return copy;
}

void PTYList::Append(const PTYObjectPtr& item) {
    std::lock_guard<std::mutex> lock(mutex_);
    items_.push_back(item ? item : std::make_shared<PTYNull>());
}

void PTYList::AppendBool(bool val) {
    Append(std::make_shared<PTYBool>(val));
}

void PTYList::AppendInt(int64_t val) {
    Append(std::make_shared<PTYInt>(val));
}

void PTYList::AppendFloat(float val) {
    Append(std::make_shared<PTYFloat>(val));
}

void PTYList::AppendDouble(double val) {
    Append(std::make_shared<PTYDouble>(val));
}

void PTYList::AppendStr(const std::string& val) {
    Append(std::make_shared<PTYStr>(val));
}

void PTYList::AppendDict(const PTYDictPtr& dict) {
    Append(dict);
}

void PTYList::AppendList(const PTYListPtr& list) {
    Append(list);
}

void PTYList::AppendNull() {
    Append(std::make_shared<PTYNull>());
}

size_t PTYList::Size() const noexcept {
    std::lock_guard<std::mutex> lock(mutex_);
    return items_.size();
}

bool PTYList::Empty() const noexcept {
    std::lock_guard<std::mutex> lock(mutex_);
    return items_.empty();
}

PTYObjectPtr PTYList::Get(size_t index) const {
    std::lock_guard<std::mutex> lock(mutex_);
    if (index < items_.size()) {
        return items_[index];
    }
    return nullptr;
}

void PTYList::Clear() {
    std::lock_guard<std::mutex> lock(mutex_);
    items_.clear();
}

// ----------------------------------------------------------------------
// PTYDict Implementation
// ----------------------------------------------------------------------
std::string PTYDict::ToString() const {
    return ToJSON();
}

std::string PTYDict::ToJSON() const {
    std::lock_guard<std::mutex> lock(mutex_);
    std::ostringstream ss;
    ss << "{";
    bool first = true;
    for (const auto& [k, v] : map_) {
        if (!first) ss << ",";
        first = false;
        ss << EscapeJSONString(k) << ":";
        if (v) {
            ss << v->ToJSON();
        } else {
            ss << "null";
        }
    }
    ss << "}";
    return ss.str();
}

std::shared_ptr<PTYObject> PTYDict::Clone() const {
    std::lock_guard<std::mutex> lock(mutex_);
    auto copy = std::make_shared<PTYDict>();
    for (const auto& [k, v] : map_) {
        if (v) {
            copy->map_[k] = v->Clone();
        } else {
            copy->map_[k] = std::make_shared<PTYNull>();
        }
    }
    return copy;
}

void PTYDict::Set(const std::string& key, const PTYObjectPtr& value) {
    std::lock_guard<std::mutex> lock(mutex_);
    map_[key] = value ? value : std::make_shared<PTYNull>();
}

void PTYDict::SetBool(const std::string& key, bool val) {
    Set(key, std::make_shared<PTYBool>(val));
}

void PTYDict::SetInt(const std::string& key, int64_t val) {
    Set(key, std::make_shared<PTYInt>(val));
}

void PTYDict::SetFloat(const std::string& key, float val) {
    Set(key, std::make_shared<PTYFloat>(val));
}

void PTYDict::SetDouble(const std::string& key, double val) {
    Set(key, std::make_shared<PTYDouble>(val));
}

void PTYDict::SetStr(const std::string& key, const std::string& val) {
    Set(key, std::make_shared<PTYStr>(val));
}

void PTYDict::SetDict(const std::string& key, const PTYDictPtr& dict) {
    Set(key, dict);
}

void PTYDict::SetList(const std::string& key, const PTYListPtr& list) {
    Set(key, list);
}

void PTYDict::SetNull(const std::string& key) {
    Set(key, std::make_shared<PTYNull>());
}

bool PTYDict::Contains(const std::string& key) const {
    std::lock_guard<std::mutex> lock(mutex_);
    return map_.find(key) != map_.end();
}

PTYObjectPtr PTYDict::Get(const std::string& key) const {
    std::lock_guard<std::mutex> lock(mutex_);
    auto it = map_.find(key);
    if (it != map_.end()) {
        return it->second;
    }
    return nullptr;
}

bool PTYDict::GetBool(const std::string& key, bool default_val) const {
    auto obj = Get(key);
    if (obj && obj->IsBool()) {
        return std::static_pointer_cast<PTYBool>(obj)->Value();
    }
    return default_val;
}

int64_t PTYDict::GetInt(const std::string& key, int64_t default_val) const {
    auto obj = Get(key);
    if (obj && obj->IsInt()) {
        return std::static_pointer_cast<PTYInt>(obj)->Value();
    }
    return default_val;
}

float PTYDict::GetFloat(const std::string& key, float default_val) const {
    auto obj = Get(key);
    if (obj) {
        if (obj->IsFloat()) return std::static_pointer_cast<PTYFloat>(obj)->Value();
        if (obj->IsDouble()) return static_cast<float>(std::static_pointer_cast<PTYDouble>(obj)->Value());
        if (obj->IsInt()) return static_cast<float>(std::static_pointer_cast<PTYInt>(obj)->Value());
    }
    return default_val;
}

double PTYDict::GetDouble(const std::string& key, double default_val) const {
    auto obj = Get(key);
    if (obj) {
        if (obj->IsDouble()) return std::static_pointer_cast<PTYDouble>(obj)->Value();
        if (obj->IsFloat()) return static_cast<double>(std::static_pointer_cast<PTYFloat>(obj)->Value());
        if (obj->IsInt()) return static_cast<double>(std::static_pointer_cast<PTYInt>(obj)->Value());
    }
    return default_val;
}

std::string PTYDict::GetStr(const std::string& key, const std::string& default_val) const {
    auto obj = Get(key);
    if (obj && obj->IsStr()) {
        return std::static_pointer_cast<PTYStr>(obj)->Value();
    }
    return default_val;
}

PTYDictPtr PTYDict::GetDict(const std::string& key) const {
    auto obj = Get(key);
    if (obj && obj->IsDict()) {
        return std::static_pointer_cast<PTYDict>(obj);
    }
    return nullptr;
}

PTYListPtr PTYDict::GetList(const std::string& key) const {
    auto obj = Get(key);
    if (obj && obj->IsList()) {
        return std::static_pointer_cast<PTYList>(obj);
    }
    return nullptr;
}

bool PTYDict::Remove(const std::string& key) {
    std::lock_guard<std::mutex> lock(mutex_);
    return map_.erase(key) > 0;
}

size_t PTYDict::Size() const noexcept {
    std::lock_guard<std::mutex> lock(mutex_);
    return map_.size();
}

bool PTYDict::Empty() const noexcept {
    std::lock_guard<std::mutex> lock(mutex_);
    return map_.empty();
}

void PTYDict::Clear() {
    std::lock_guard<std::mutex> lock(mutex_);
    map_.clear();
}

std::vector<std::string> PTYDict::Keys() const {
    std::lock_guard<std::mutex> lock(mutex_);
    std::vector<std::string> keys;
    keys.reserve(map_.size());
    for (const auto& [k, v] : map_) {
        keys.push_back(k);
    }
    return keys;
}

PTYDictPtr PTYDict::FromJSON(const std::string& json_str) {
    auto dict = std::make_shared<PTYDict>();
    // Bộ phân tích JSON đơn giản cho các cặp key-value
    size_t pos = 0;
    while (pos < json_str.size()) {
        size_t quote1 = json_str.find('"', pos);
        if (quote1 == std::string::npos) break;
        size_t quote2 = json_str.find('"', quote1 + 1);
        if (quote2 == std::string::npos) break;

        std::string key = json_str.substr(quote1 + 1, quote2 - quote1 - 1);
        size_t colon = json_str.find(':', quote2 + 1);
        if (colon == std::string::npos) break;

        // Bỏ qua khoảng trắng
        size_t val_start = json_str.find_first_not_of(" \t\r\n", colon + 1);
        if (val_start == std::string::npos) break;

        if (json_str[val_start] == '"') {
            size_t val_end = json_str.find('"', val_start + 1);
            if (val_end != std::string::npos) {
                std::string s_val = json_str.substr(val_start + 1, val_end - val_start - 1);
                dict->SetStr(key, s_val);
                pos = val_end + 1;
            } else {
                break;
            }
        } else if (json_str.substr(val_start, 4) == "true") {
            dict->SetBool(key, true);
            pos = val_start + 4;
        } else if (json_str.substr(val_start, 5) == "false") {
            dict->SetBool(key, false);
            pos = val_start + 5;
        } else if (json_str.substr(val_start, 4) == "null") {
            dict->SetNull(key);
            pos = val_start + 4;
        } else {
            size_t val_end = json_str.find_first_of(",}", val_start);
            std::string num_str = json_str.substr(val_start, (val_end == std::string::npos) ? std::string::npos : (val_end - val_start));
            if (num_str.find('.') != std::string::npos) {
                try { dict->SetDouble(key, std::stod(num_str)); } catch (...) {}
            } else {
                try { dict->SetInt(key, std::stoll(num_str)); } catch (...) {}
            }
            pos = (val_end == std::string::npos) ? json_str.size() : val_end;
        }
    }
    return dict;
}

// ----------------------------------------------------------------------
// PTYHandleManager Implementation
// ----------------------------------------------------------------------
PTYHandleManager& PTYHandleManager::Instance() {
    static PTYHandleManager instance;
    return instance;
}

int64_t PTYHandleManager::RegisterDict(const PTYDictPtr& dict) {
    if (!dict) return 0;
    std::lock_guard<std::mutex> lock(mutex_);
    int64_t handle = ++next_handle_;
    dict_map_[handle] = dict;
    return handle;
}

PTYDictPtr PTYHandleManager::GetDict(int64_t handle) {
    if (handle == 0) return nullptr;
    std::lock_guard<std::mutex> lock(mutex_);
    auto it = dict_map_.find(handle);
    if (it != dict_map_.end()) {
        return it->second;
    }
    return nullptr;
}

void PTYHandleManager::ReleaseDict(int64_t handle) {
    if (handle == 0) return;
    std::lock_guard<std::mutex> lock(mutex_);
    dict_map_.erase(handle);
}

int64_t PTYHandleManager::RegisterList(const PTYListPtr& list) {
    if (!list) return 0;
    std::lock_guard<std::mutex> lock(mutex_);
    int64_t handle = ++next_handle_;
    list_map_[handle] = list;
    return handle;
}

PTYListPtr PTYHandleManager::GetList(int64_t handle) {
    if (handle == 0) return nullptr;
    std::lock_guard<std::mutex> lock(mutex_);
    auto it = list_map_.find(handle);
    if (it != list_map_.end()) {
        return it->second;
    }
    return nullptr;
}

void PTYHandleManager::ReleaseList(int64_t handle) {
    if (handle == 0) return;
    std::lock_guard<std::mutex> lock(mutex_);
    list_map_.erase(handle);
}

} // namespace NextAI::OpenCut::pitaya
