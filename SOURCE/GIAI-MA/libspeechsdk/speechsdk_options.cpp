// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libspeechsdk.so (ByteDance AI Lab Speech Engine)
// File: speechsdk_options.cpp
// Description: Full implementation of OptionValue & thread-safe Options store
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#include "speechsdk_options.h"
#include <cmath>

namespace lab::speech::client {
namespace base {

OptionValue::OptionValue() = default;

OptionValue::OptionValue(int32_t val)
    : m_type(ValueType::TYPE_INT), m_int_val(val) {}

OptionValue::OptionValue(int64_t val)
    : m_type(ValueType::TYPE_INT64), m_int_val(val) {}

OptionValue::OptionValue(bool val)
    : m_type(ValueType::TYPE_BOOL), m_bool_val(val) {}

OptionValue::OptionValue(double val)
    : m_type(ValueType::TYPE_DOUBLE), m_double_val(val) {}

OptionValue::OptionValue(const std::string& val)
    : m_type(ValueType::TYPE_STRING), m_str_val(val) {}

OptionValue::OptionValue(const char* val)
    : m_type(ValueType::TYPE_STRING), m_str_val(val ? val : "") {}

int32_t OptionValue::getInt(int32_t default_val) const {
    if (m_type == ValueType::TYPE_INT || m_type == ValueType::TYPE_INT64) {
        return static_cast<int32_t>(m_int_val);
    }
    if (m_type == ValueType::TYPE_DOUBLE) {
        return static_cast<int32_t>(m_double_val);
    }
    if (m_type == ValueType::TYPE_BOOL) {
        return m_bool_val ? 1 : 0;
    }
    if (m_type == ValueType::TYPE_STRING && !m_str_val.empty()) {
        try { return std::stoi(m_str_val); } catch (...) {}
    }
    return default_val;
}

int64_t OptionValue::getInt64(int64_t default_val) const {
    if (m_type == ValueType::TYPE_INT || m_type == ValueType::TYPE_INT64) {
        return m_int_val;
    }
    if (m_type == ValueType::TYPE_DOUBLE) {
        return static_cast<int64_t>(m_double_val);
    }
    if (m_type == ValueType::TYPE_BOOL) {
        return m_bool_val ? 1 : 0;
    }
    if (m_type == ValueType::TYPE_STRING && !m_str_val.empty()) {
        try { return std::stoll(m_str_val); } catch (...) {}
    }
    return default_val;
}

bool OptionValue::getBool(bool default_val) const {
    if (m_type == ValueType::TYPE_BOOL) {
        return m_bool_val;
    }
    if (m_type == ValueType::TYPE_INT || m_type == ValueType::TYPE_INT64) {
        return m_int_val != 0;
    }
    if (m_type == ValueType::TYPE_STRING) {
        return (m_str_val == "true" || m_str_val == "1" || m_str_val == "True");
    }
    return default_val;
}

double OptionValue::getDouble(double default_val) const {
    if (m_type == ValueType::TYPE_DOUBLE) {
        return m_double_val;
    }
    if (m_type == ValueType::TYPE_INT || m_type == ValueType::TYPE_INT64) {
        return static_cast<double>(m_int_val);
    }
    if (m_type == ValueType::TYPE_STRING && !m_str_val.empty()) {
        try { return std::stod(m_str_val); } catch (...) {}
    }
    return default_val;
}

std::string OptionValue::getString(const std::string& default_val) const {
    if (m_type == ValueType::TYPE_STRING) {
        return m_str_val;
    }
    if (m_type != ValueType::TYPE_NONE) {
        return toString();
    }
    return default_val;
}

std::string OptionValue::toString() const {
    switch (m_type) {
        case ValueType::TYPE_INT:
        case ValueType::TYPE_INT64:
            return std::to_string(m_int_val);
        case ValueType::TYPE_BOOL:
            return m_bool_val ? "true" : "false";
        case ValueType::TYPE_DOUBLE:
            return std::to_string(m_double_val);
        case ValueType::TYPE_STRING:
            return m_str_val;
        default:
            return "";
    }
}

bool OptionValue::operator==(const OptionValue& other) const {
    if (m_type != other.m_type) return false;
    switch (m_type) {
        case ValueType::TYPE_INT:
        case ValueType::TYPE_INT64:
            return m_int_val == other.m_int_val;
        case ValueType::TYPE_BOOL:
            return m_bool_val == other.m_bool_val;
        case ValueType::TYPE_DOUBLE:
            return std::abs(m_double_val - other.m_double_val) < 1e-9;
        case ValueType::TYPE_STRING:
            return m_str_val == other.m_str_val;
        default:
            return true;
    }
}

} // namespace base

// ===================================================================================
// Options Class Implementation
// ===================================================================================

void Options::setOption(const std::string& key, const base::OptionValue& val) {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_options[key] = val;
    m_modified_keys.insert(key);
}

bool Options::getOption(const std::string& key, base::OptionValue* out_val) const {
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_options.find(key);
    if (it != m_options.end()) {
        if (out_val) *out_val = it->second;
        return true;
    }
    return false;
}

bool Options::hasOption(const std::string& key) const {
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_options.find(key) != m_options.end();
}

bool Options::isModified(const std::string& key) const {
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_modified_keys.find(key) != m_modified_keys.end();
}

void Options::setString(const std::string& key, const std::string& val) {
    setOption(key, base::OptionValue(val));
}

void Options::setInt(const std::string& key, int32_t val) {
    setOption(key, base::OptionValue(val));
}

void Options::setInt64(const std::string& key, int64_t val) {
    setOption(key, base::OptionValue(val));
}

void Options::setBool(const std::string& key, bool val) {
    setOption(key, base::OptionValue(val));
}

void Options::setDouble(const std::string& key, double val) {
    setOption(key, base::OptionValue(val));
}

std::string Options::getString(const std::string& key, const std::string& default_val) const {
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_options.find(key);
    return (it != m_options.end()) ? it->second.getString(default_val) : default_val;
}

int32_t Options::getInt(const std::string& key, int32_t default_val) const {
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_options.find(key);
    return (it != m_options.end()) ? it->second.getInt(default_val) : default_val;
}

int64_t Options::getInt64(const std::string& key, int64_t default_val) const {
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_options.find(key);
    return (it != m_options.end()) ? it->second.getInt64(default_val) : default_val;
}

bool Options::getBool(const std::string& key, bool default_val) const {
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_options.find(key);
    return (it != m_options.end()) ? it->second.getBool(default_val) : default_val;
}

double Options::getDouble(const std::string& key, double default_val) const {
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_options.find(key);
    return (it != m_options.end()) ? it->second.getDouble(default_val) : default_val;
}

void Options::clearModifiedFlags() {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_modified_keys.clear();
}

void Options::clear() {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_options.clear();
    m_modified_keys.clear();
}

std::map<std::string, base::OptionValue> Options::getAllOptions() const {
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_options;
}

bool Options::runSelfTest() {
    Options opt;
    // 1. Kiểm tra lưu và đọc String
    opt.setString(OptionsKey::APP_ID_STRING, "123456");
    if (opt.getString(OptionsKey::APP_ID_STRING) != "123456") return false;
    if (!opt.isModified(OptionsKey::APP_ID_STRING)) return false;

    // 2. Kiểm tra lưu và đọc Int (sample rate)
    opt.setInt(OptionsKey::SAMPLE_RATE_INT, 16000);
    if (opt.getInt(OptionsKey::SAMPLE_RATE_INT) != 16000) return false;

    // 3. Kiểm tra lưu và đọc Bool (show words)
    opt.setBool(OptionsKey::ASR_SHOW_WORDS_BOOL, true);
    if (!opt.getBool(OptionsKey::ASR_SHOW_WORDS_BOOL)) return false;

    // 4. Kiểm tra lưu và đọc Double (noise suppression)
    opt.setDouble(OptionsKey::SIGNAL_NS_RATIO_DOUBLE, 0.75);
    if (std::abs(opt.getDouble(OptionsKey::SIGNAL_NS_RATIO_DOUBLE) - 0.75) > 1e-6) return false;

    // 5. Kiểm tra xóa cờ modified
    opt.clearModifiedFlags();
    if (opt.isModified(OptionsKey::SAMPLE_RATE_INT)) return false;

    // 6. Kiểm tra giá trị mặc định khi khóa không tồn tại
    if (opt.getInt("non_existent_key", 99) != 99) return false;
    if (opt.getString("non_existent_str", "default") != "default") return false;

    return true;
}

} // namespace lab::speech::client
