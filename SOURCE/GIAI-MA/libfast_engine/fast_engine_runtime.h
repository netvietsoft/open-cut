// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libfast_engine.so (ByteDance Embedded Bytecode Scripting Engine & VM)
// File: fast_engine_runtime.h
// Description: FastEngine runtime singleton, Base64 loader, memory stats, built-in modules
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#pragma once

#include "fast_engine_types.h"
#include "fast_engine_obj.h"
#include "fast_engine_vm.h"
#include <string>
#include <vector>
#include <memory>
#include <mutex>
#include <iostream>

namespace fast_engine {

// EN: Script Module Object containing module dictionary and namespace
// VN: Đối tượng mô-đun kịch bản chứa từ điển biến và không gian tên mô-đun
class ModuleObj : public Obj {
public:
    std::string name;
    DictObj* dict = nullptr;

    explicit ModuleObj(const std::string& n);
    ~ModuleObj() override;

    void SetAttr(const std::string& key, Obj* val, Engine* engine);
    Obj* GetAttr(const std::string& key) const;
    std::string Repr() const override { return "<module '" + name + "'>"; }
};

// EN: FastEngine Execution Context & Module Manager (Opcode 0x5c504: Engine::Engine)
// VN: Ngữ cảnh thực thi và bộ quản lý mô-đun kịch bản (Opcode 0x5c504: Engine::Engine)
class Engine {
public:
    DictObj* modules = nullptr;
    DictObj* builtins = nullptr;
    Error last_error;
    bool is_debug = false;
    uint64_t allocated_bytes = 0;
    uint64_t execution_count = 0;

    Engine(Error& err, bool debug = false, bool optimize = true);
    ~Engine();

    // EN: Import module from Base64 encoded payload (Opcode 0x5e6cc: Engine::ImportBase64)
    // VN: Nạp mô-đun từ chuỗi mã hóa Base64 (Opcode 0x5e6cc: Engine::ImportBase64)
    ModuleObj* ImportBase64(const char* module_name, const char* b64_payload, bool execute);

    // EN: Clear all loaded modules (Opcode 0x5e2e0: Engine::ClearModules)
    // VN: Dọn sạch toàn bộ các mô-đun đã nạp (Opcode 0x5e2e0: Engine::ClearModules)
    void ClearModules();

    // EN: Create attribute missing error (Opcode 0x69004: Engine::MakeNoAttrError)
    // VN: Tạo thông báo lỗi thiếu thuộc tính (Opcode 0x69004: Engine::MakeNoAttrError)
    void MakeNoAttrError(const char* attr_name);

    // EN: Reset execution memory statistics (Opcode 0x53470: ResetMemoryStats)
    // VN: Đặt lại số liệu thống kê bộ nhớ (Opcode 0x53470: ResetMemoryStats)
    void ResetMemoryStats();

    // EN: Print memory statistics to output stream (Opcode 0x53494: PrintMemoryStats)
    // VN: In số liệu thống kê bộ nhớ ra luồng xuất (Opcode 0x53494: PrintMemoryStats)
    void PrintMemoryStats(const std::string& prefix, std::ostream& out);

private:
    void InitBuiltins();
};

// EN: FastEngine Central Engine Manager Singleton (Opcode 0x45cd4: FastEngine::Instance)
// VN: Thực thể quản lý trung tâm FastEngine duy nhất (Opcode 0x45cd4: FastEngine::Instance)
class FastEngine {
public:
    static FastEngine& Instance(); // Opcode 0x45cd4

    FastEngine();
    ~FastEngine();

    // EN: Initialize runtime with configuration provider (Opcode 0x46198: FastEngine::Initialize)
    // VN: Khởi tạo môi trường với nhà cung cấp cấu hình (Opcode 0x46198: FastEngine::Initialize)
    bool Initialize(FastEngineConfigProvider* provider);

    // EN: Check if there is an idle VM worker thread available (Opcode 0x4632c: FastEngine::HasFreeVM)
    // VN: Kiểm tra xem có luồng thực thi máy ảo rảnh rỗi hay không (Opcode 0x4632c: FastEngine::HasFreeVM)
    bool HasFreeVM() const;

    // EN: Register a module into global runtime (Opcode 0x4682c: FastEngine::AddModule)
    // VN: Đăng ký một mô-đun vào runtime toàn cục (Opcode 0x4682c: FastEngine::AddModule)
    void AddModule(ModuleObj* mod, const std::string& name);

    // EN: Decrypt obfuscated ByteDance module name (Opcode 0x46db0: FastEngine::DecryptModuleName)
    // VN: Giải mã tên mô-đun bị làm rối của ByteDance (Opcode 0x46db0: FastEngine::DecryptModuleName)
    static void DecryptModuleName(std::string& name);

    // Subsystem initializers
    void InitDatetimeModule(Engine* engine);   // Opcode 0x73980
    void InitCollectionsModule(Engine* engine);// Opcode 0x6ff64

    Engine* GetDefaultEngine() { return m_default_engine.get(); }

private:
    bool m_initialized = false;
    int32_t m_max_memory_mb = 64;
    int32_t m_thread_pool_size = 4;
    std::unique_ptr<Engine> m_default_engine;
    std::vector<ModuleObj*> m_modules;
    mutable std::mutex m_mutex;
};

// EN: Read object from Base64 string (Opcode 0x51e80: ReadObjectFromBase64)
// VN: Đọc đối tượng từ chuỗi Base64 (Opcode 0x51e80: ReadObjectFromBase64)
Obj* ReadObjectFromBase64(const char* b64_str, Engine* engine);

// EN: Base64 decode helper
// VN: Hàm trợ giúp giải mã Base64
std::vector<uint8_t> Base64Decode(const std::string& input);

} // namespace fast_engine
