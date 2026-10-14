// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libspeechsdk.so (ByteDance AI Lab Speech Engine)
// File: speechsdk_options.h
// Description: Type-safe OptionValue holder & Thread-safe Options configuration store
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#pragma once

#include <string>
#include <map>
#include <set>
#include <mutex>
#include <sstream>
#include "speechsdk_types.h"

namespace lab::speech::client {
namespace base {

/**
 * @brief Kiểu dữ liệu đa hình chứa giá trị tham số (Polymorphic Option Value)
 * Khôi phục từ lab::speech::client::base::OptionValue
 */
class OptionValue {
public:
    enum class ValueType : int32_t {
        TYPE_NONE = 0,
        TYPE_INT = 1,
        TYPE_INT64 = 2,
        TYPE_BOOL = 3,
        TYPE_DOUBLE = 4,
        TYPE_STRING = 5
    };

    OptionValue();
    explicit OptionValue(int32_t val);
    explicit OptionValue(int64_t val);
    explicit OptionValue(bool val);
    explicit OptionValue(double val);
    explicit OptionValue(const std::string& val);
    explicit OptionValue(const char* val);

    ValueType getType() const { return m_type; }

    int32_t getInt(int32_t default_val = 0) const;
    int64_t getInt64(int64_t default_val = 0) const;
    bool getBool(bool default_val = false) const;
    double getDouble(double default_val = 0.0) const;
    std::string getString(const std::string& default_val = "") const;

    std::string toString() const;

    bool operator==(const OptionValue& other) const;
    bool operator!=(const OptionValue& other) const { return !(*this == other); }

private:
    ValueType m_type{ValueType::TYPE_NONE};
    int64_t m_int_val{0};
    double m_double_val{0.0};
    bool m_bool_val{false};
    std::string m_str_val;
};

} // namespace base

/**
 * @brief Bảng cấu hình tham số động cơ Speech Engine
 * Khôi phục từ lab::speech::client::Options
 */
class Options {
public:
    Options() = default;
    ~Options() = default;

    void setOption(const std::string& key, const base::OptionValue& val);
    bool getOption(const std::string& key, base::OptionValue* out_val) const;
    bool hasOption(const std::string& key) const;
    bool isModified(const std::string& key) const;

    void setString(const std::string& key, const std::string& val);
    void setInt(const std::string& key, int32_t val);
    void setInt64(const std::string& key, int64_t val);
    void setBool(const std::string& key, bool val);
    void setDouble(const std::string& key, double val);

    std::string getString(const std::string& key, const std::string& default_val = "") const;
    int32_t getInt(const std::string& key, int32_t default_val = 0) const;
    int64_t getInt64(const std::string& key, int64_t default_val = 0) const;
    bool getBool(const std::string& key, bool default_val = false) const;
    double getDouble(const std::string& key, double default_val = 0.0) const;

    void clearModifiedFlags();
    void clear();

    std::map<std::string, base::OptionValue> getAllOptions() const;

    static bool runSelfTest();

private:
    mutable std::mutex m_mutex;
    std::map<std::string, base::OptionValue> m_options;
    std::set<std::string> m_modified_keys;
};

} // namespace lab::speech::client
