// ======================================================================
// RECONSTRUCTED HEADER: pitaya_objects.h
// Library: libAndroidPitayaCore.so (ByteDance Pitaya On-Device AI Core)
// Component: NextAI OpenCut AI & Computer Vision Core (CORE_02_AI_CV)
// Architecture: AArch64 (ARMv8-A / ARM64)
//
// Description (English):
//   Dynamic typed object hierarchy (PTYObject, PTYDict, PTYList,
//   PTYInt, PTYFloat, PTYStr, PTYBool) with nested JSON serialization
//   and JNI native handle lifecycle management.
//
// Mô tả (Tiếng Việt):
//   Hệ thống đối tượng động đa kiểu (PTYObject, PTYDict, PTYList,
//   PTYInt, PTYFloat, PTYStr, PTYBool) với khả năng tuần tự hóa JSON
//   lồng nhau và quản lý vòng đời con trỏ JNI native.
// ======================================================================

#pragma once

#include "pitaya_types.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <sstream>
#include <mutex>

namespace NextAI::OpenCut::pitaya {

// ----------------------------------------------------------------------
// PTYObject: Lớp cơ sở trừu tượng cho mọi đối tượng động Pitaya
// ----------------------------------------------------------------------
class PTYObject : public std::enable_shared_from_this<PTYObject> {
public:
    virtual ~PTYObject() = default;

    virtual PTYType GetType() const noexcept = 0;
    virtual std::string ToString() const = 0;
    virtual std::string ToJSON() const = 0;
    virtual std::shared_ptr<PTYObject> Clone() const = 0;

    bool IsNull() const noexcept { return GetType() == PTYType::PTY_NULL; }
    bool IsBool() const noexcept { return GetType() == PTYType::PTY_BOOL; }
    bool IsInt() const noexcept { return GetType() == PTYType::PTY_INT; }
    bool IsFloat() const noexcept { return GetType() == PTYType::PTY_FLOAT; }
    bool IsDouble() const noexcept { return GetType() == PTYType::PTY_DOUBLE; }
    bool IsStr() const noexcept { return GetType() == PTYType::PTY_STR; }
    bool IsList() const noexcept { return GetType() == PTYType::PTY_LIST; }
    bool IsDict() const noexcept { return GetType() == PTYType::PTY_DICT; }
};

// ----------------------------------------------------------------------
// PTYNull / PTYBool / PTYInt / PTYFloat / PTYDouble / PTYStr
// ----------------------------------------------------------------------
class PTYNull : public PTYObject {
public:
    virtual PTYType GetType() const noexcept override { return PTYType::PTY_NULL; }
    virtual std::string ToString() const override { return "null"; }
    virtual std::string ToJSON() const override { return "null"; }
    virtual std::shared_ptr<PTYObject> Clone() const override { return std::make_shared<PTYNull>(); }
};

class PTYBool : public PTYObject {
public:
    explicit PTYBool(bool v) : val_(v) {}
    virtual PTYType GetType() const noexcept override { return PTYType::PTY_BOOL; }
    virtual std::string ToString() const override { return val_ ? "true" : "false"; }
    virtual std::string ToJSON() const override { return val_ ? "true" : "false"; }
    virtual std::shared_ptr<PTYObject> Clone() const override { return std::make_shared<PTYBool>(val_); }
    bool Value() const noexcept { return val_; }
    void SetValue(bool v) noexcept { val_ = v; }
private:
    bool val_{false};
};

class PTYInt : public PTYObject {
public:
    explicit PTYInt(int64_t v) : val_(v) {}
    virtual PTYType GetType() const noexcept override { return PTYType::PTY_INT; }
    virtual std::string ToString() const override { return std::to_string(val_); }
    virtual std::string ToJSON() const override { return std::to_string(val_); }
    virtual std::shared_ptr<PTYObject> Clone() const override { return std::make_shared<PTYInt>(val_); }
    int64_t Value() const noexcept { return val_; }
    void SetValue(int64_t v) noexcept { val_ = v; }
private:
    int64_t val_{0};
};

class PTYFloat : public PTYObject {
public:
    explicit PTYFloat(float v) : val_(v) {}
    virtual PTYType GetType() const noexcept override { return PTYType::PTY_FLOAT; }
    virtual std::string ToString() const override;
    virtual std::string ToJSON() const override;
    virtual std::shared_ptr<PTYObject> Clone() const override { return std::make_shared<PTYFloat>(val_); }
    float Value() const noexcept { return val_; }
    void SetValue(float v) noexcept { val_ = v; }
private:
    float val_{0.0f};
};

class PTYDouble : public PTYObject {
public:
    explicit PTYDouble(double v) : val_(v) {}
    virtual PTYType GetType() const noexcept override { return PTYType::PTY_DOUBLE; }
    virtual std::string ToString() const override;
    virtual std::string ToJSON() const override;
    virtual std::shared_ptr<PTYObject> Clone() const override { return std::make_shared<PTYDouble>(val_); }
    double Value() const noexcept { return val_; }
    void SetValue(double v) noexcept { val_ = v; }
private:
    double val_{0.0};
};

class PTYStr : public PTYObject {
public:
    explicit PTYStr(const std::string& v) : val_(v) {}
    virtual PTYType GetType() const noexcept override { return PTYType::PTY_STR; }
    virtual std::string ToString() const override { return val_; }
    virtual std::string ToJSON() const override;
    virtual std::shared_ptr<PTYObject> Clone() const override { return std::make_shared<PTYStr>(val_); }
    const std::string& Value() const noexcept { return val_; }
    void SetValue(const std::string& v) { val_ = v; }
private:
    std::string val_{""};
};

// ----------------------------------------------------------------------
// PTYList (Danh sách phần tử động)
// Demangled: pitaya::PTYList
// ----------------------------------------------------------------------
class PTYList : public PTYObject {
public:
    PTYList() = default;
    virtual ~PTYList() override = default;

    virtual PTYType GetType() const noexcept override { return PTYType::PTY_LIST; }
    virtual std::string ToString() const override;
    virtual std::string ToJSON() const override;
    virtual std::shared_ptr<PTYObject> Clone() const override;

    void Append(const PTYObjectPtr& item);
    void AppendBool(bool val);
    void AppendInt(int64_t val);
    void AppendFloat(float val);
    void AppendDouble(double val);
    void AppendStr(const std::string& val);
    void AppendDict(const PTYDictPtr& dict);
    void AppendList(const PTYListPtr& list);
    void AppendNull();

    size_t Size() const noexcept;
    bool Empty() const noexcept;
    PTYObjectPtr Get(size_t index) const;
    void Clear();

    const std::vector<PTYObjectPtr>& Elements() const noexcept { return items_; }

private:
    std::vector<PTYObjectPtr> items_;
    mutable std::mutex mutex_;
};

// ----------------------------------------------------------------------
// PTYDict (Bản đồ từ điển Key-Value)
// Demangled: pitaya::PTYDict
// ----------------------------------------------------------------------
class PTYDict : public PTYObject {
public:
    PTYDict() = default;
    virtual ~PTYDict() override = default;

    virtual PTYType GetType() const noexcept override { return PTYType::PTY_DICT; }
    virtual std::string ToString() const override;
    virtual std::string ToJSON() const override;
    virtual std::shared_ptr<PTYObject> Clone() const override;

    void Set(const std::string& key, const PTYObjectPtr& value);
    void SetBool(const std::string& key, bool val);
    void SetInt(const std::string& key, int64_t val);
    void SetFloat(const std::string& key, float val);
    void SetDouble(const std::string& key, double val);
    void SetStr(const std::string& key, const std::string& val);
    void SetDict(const std::string& key, const PTYDictPtr& dict);
    void SetList(const std::string& key, const PTYListPtr& list);
    void SetNull(const std::string& key);

    bool Contains(const std::string& key) const;
    PTYObjectPtr Get(const std::string& key) const;
    bool GetBool(const std::string& key, bool default_val = false) const;
    int64_t GetInt(const std::string& key, int64_t default_val = 0) const;
    float GetFloat(const std::string& key, float default_val = 0.0f) const;
    double GetDouble(const std::string& key, double default_val = 0.0) const;
    std::string GetStr(const std::string& key, const std::string& default_val = "") const;
    PTYDictPtr GetDict(const std::string& key) const;
    PTYListPtr GetList(const std::string& key) const;

    bool Remove(const std::string& key);
    size_t Size() const noexcept;
    bool Empty() const noexcept;
    void Clear();
    std::vector<std::string> Keys() const;

    const std::unordered_map<std::string, PTYObjectPtr>& Map() const noexcept { return map_; }

    // Phân tích cú pháp JSON đơn giản
    static PTYDictPtr FromJSON(const std::string& json_str);

private:
    std::unordered_map<std::string, PTYObjectPtr> map_;
    mutable std::mutex mutex_;
};

// ----------------------------------------------------------------------
// PTYHandleManager: Quản lý con trỏ Native cho các wrapper JNI
// ----------------------------------------------------------------------
class PTYHandleManager {
public:
    static PTYHandleManager& Instance();

    int64_t RegisterDict(const PTYDictPtr& dict);
    PTYDictPtr GetDict(int64_t handle);
    void ReleaseDict(int64_t handle);

    int64_t RegisterList(const PTYListPtr& list);
    PTYListPtr GetList(int64_t handle);
    void ReleaseList(int64_t handle);

private:
    PTYHandleManager() = default;
    int64_t next_handle_{1000};
    std::unordered_map<int64_t, PTYDictPtr> dict_map_;
    std::unordered_map<int64_t, PTYListPtr> list_map_;
    std::mutex mutex_;
};

} // namespace NextAI::OpenCut::pitaya
