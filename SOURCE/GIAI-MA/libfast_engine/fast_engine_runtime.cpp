// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libfast_engine.so (ByteDance Embedded Bytecode Scripting Engine & VM)
// File: fast_engine_runtime.cpp
// Description: Implementation of FastEngine runtime singleton, Base64 loader, and modules
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#include "fast_engine_runtime.h"
#include <iostream>
#include <sstream>
#include <cmath>
#include <chrono>
#include <algorithm>

namespace fast_engine {

// ===================================================================================
// BASE64 DECODER IMPLEMENTATION
// ===================================================================================

static const std::string BASE64_CHARS =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/";

static inline bool IsBase64(uint8_t c) {
    return (isalnum(c) || (c == '+') || (c == '/'));
}

std::vector<uint8_t> Base64Decode(const std::string& input) {
    size_t in_len = input.size();
    size_t i = 0, j = 0, in_ = 0;
    uint8_t char_array_4[4], char_array_3[3];
    std::vector<uint8_t> ret;
    ret.reserve(in_len * 3 / 4);

    while (in_len-- && (input[in_] != '=') && IsBase64(static_cast<uint8_t>(input[in_]))) {
        char_array_4[i++] = static_cast<uint8_t>(input[in_]); in_++;
        if (i == 4) {
            for (i = 0; i < 4; i++) {
                char_array_4[i] = static_cast<uint8_t>(BASE64_CHARS.find(static_cast<char>(char_array_4[i])));
            }
            char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
            char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
            char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

            for (i = 0; i < 3; i++) ret.push_back(char_array_3[i]);
            i = 0;
        }
    }

    if (i) {
        for (j = i; j < 4; j++) char_array_4[j] = 0;
        for (j = 0; j < 4; j++) {
            char_array_4[j] = static_cast<uint8_t>(BASE64_CHARS.find(static_cast<char>(char_array_4[j])));
        }
        char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
        char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
        char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

        for (j = 0; j < i - 1; j++) ret.push_back(char_array_3[j]);
    }

    return ret;
}

// EN: Read object from Base64 string (Opcode 0x51e80: ReadObjectFromBase64)
// VN: Đọc đối tượng từ chuỗi Base64 (Opcode 0x51e80: ReadObjectFromBase64)
Obj* ReadObjectFromBase64(const char* b64_str, Engine* /*engine*/) {
    if (!b64_str) return NullObj::GetInstance();
    std::vector<uint8_t> decoded = Base64Decode(b64_str);
    return new BytesObj(decoded.data(), decoded.size());
}

// ===================================================================================
// MODULE OBJECT IMPLEMENTATION
// ===================================================================================

ModuleObj::ModuleObj(const std::string& n) : Obj(ObjTypeTag::TYPE_MODULE), name(n) {
    dict = new DictObj();
}

ModuleObj::~ModuleObj() {
    if (dict) dict->DecRef();
}

void ModuleObj::SetAttr(const std::string& key, Obj* val, Engine* engine) {
    if (dict) dict->SetItemStringRef(key, val, engine);
}

Obj* ModuleObj::GetAttr(const std::string& key) const {
    return dict ? dict->GetItemString(key) : nullptr;
}

// ===================================================================================
// ENGINE IMPLEMENTATION
// ===================================================================================

Engine::Engine(Error& /*err*/, bool debug, bool /*optimize*/) : is_debug(debug) {
    modules = new DictObj();
    builtins = new DictObj();
    InitBuiltins();
}

Engine::~Engine() {
    if (modules) modules->DecRef();
    if (builtins) builtins->DecRef();
}

// EN: Initialize built-in standard library functions
// VN: Khởi tạo các hàm thư viện chuẩn tích hợp sẵn
void Engine::InitBuiltins() {
    // 1. len(obj)
    builtins->SetItemStringRef("len", new CFuncObj("len", [](Engine* /*eng*/, TupleObj* args, DictObj* /*kw*/) -> Obj* {
        if (!args || args->Size() < 1) return new LongObj(0);
        Obj* o = args->GetItem(0);
        if (!o) return new LongObj(0);
        if (o->type_tag == ObjTypeTag::TYPE_STR) return new LongObj(static_cast<StrObj*>(o)->Length());
        if (o->type_tag == ObjTypeTag::TYPE_LIST) return new LongObj(static_cast<ListObj*>(o)->Size());
        if (o->type_tag == ObjTypeTag::TYPE_TUPLE) return new LongObj(static_cast<TupleObj*>(o)->Size());
        if (o->type_tag == ObjTypeTag::TYPE_DICT) return new LongObj(static_cast<DictObj*>(o)->Size());
        if (o->type_tag == ObjTypeTag::TYPE_SET) return new LongObj(static_cast<SetObj*>(o)->Size());
        return new LongObj(0);
    }), this);

    // 2. abs(x)
    builtins->SetItemStringRef("abs", new CFuncObj("abs", [](Engine* /*eng*/, TupleObj* args, DictObj* /*kw*/) -> Obj* {
        if (!args || args->Size() < 1) return new LongObj(0);
        Obj* o = args->GetItem(0);
        if (!o) return new LongObj(0);
        if (o->type_tag == ObjTypeTag::TYPE_INT) return new LongObj(std::abs(static_cast<LongObj*>(o)->val));
        if (o->type_tag == ObjTypeTag::TYPE_FLOAT) return new FloatObj(std::abs(static_cast<FloatObj*>(o)->val));
        return new LongObj(0);
    }), this);

    // 3. min(a, b)
    builtins->SetItemStringRef("min", new CFuncObj("min", [](Engine* /*eng*/, TupleObj* args, DictObj* /*kw*/) -> Obj* {
        if (!args || args->Size() < 2) return NullObj::GetInstance();
        Obj* a = args->GetItem(0);
        Obj* b = args->GetItem(1);
        if (VM::Compare(CompareOp::LT, a, b, nullptr)) {
            a->IncRef();
            return a;
        } else {
            b->IncRef();
            return b;
        }
    }), this);

    // 4. max(a, b)
    builtins->SetItemStringRef("max", new CFuncObj("max", [](Engine* /*eng*/, TupleObj* args, DictObj* /*kw*/) -> Obj* {
        if (!args || args->Size() < 2) return NullObj::GetInstance();
        Obj* a = args->GetItem(0);
        Obj* b = args->GetItem(1);
        if (VM::Compare(CompareOp::GT, a, b, nullptr)) {
            a->IncRef();
            return a;
        } else {
            b->IncRef();
            return b;
        }
    }), this);

    // 5. str(x)
    builtins->SetItemStringRef("str", new CFuncObj("str", [](Engine* /*eng*/, TupleObj* args, DictObj* /*kw*/) -> Obj* {
        if (!args || args->Size() < 1) return new StrObj("");
        Obj* o = args->GetItem(0);
        return new StrObj(o ? o->Repr() : "None");
    }), this);
}

// EN: Import module from Base64 encoded payload (Opcode 0x5e6cc: Engine::ImportBase64)
// VN: Nạp mô-đun từ chuỗi mã hóa Base64 (Opcode 0x5e6cc: Engine::ImportBase64)
ModuleObj* Engine::ImportBase64(const char* module_name, const char* b64_payload, bool /*execute*/) {
    if (!module_name) return nullptr;

    std::string mod_name(module_name);
    FastEngine::DecryptModuleName(mod_name);

    auto* mod = new ModuleObj(mod_name);
    if (b64_payload) {
        std::vector<uint8_t> decoded_bytes = Base64Decode(b64_payload);
        auto* raw_bytes_obj = new BytesObj(decoded_bytes.data(), decoded_bytes.size());
        mod->SetAttr("__bytecode__", raw_bytes_obj, this);
        raw_bytes_obj->DecRef();
    }

    if (modules) {
        modules->SetItemStringRef(mod_name, mod, this);
    }
    return mod;
}

// EN: Clear all loaded modules (Opcode 0x5e2e0: Engine::ClearModules)
// VN: Dọn sạch toàn bộ các mô-đun đã nạp (Opcode 0x5e2e0: Engine::ClearModules)
void Engine::ClearModules() {
    if (modules) {
        modules->ClearContent(this);
    }
}

// EN: Create attribute missing error (Opcode 0x69004: Engine::MakeNoAttrError)
// VN: Tạo thông báo lỗi thiếu thuộc tính (Opcode 0x69004: Engine::MakeNoAttrError)
void Engine::MakeNoAttrError(const char* attr_name) {
    last_error.code = 1;
    last_error.message = "AttributeError: 'Obj' object has no attribute '" + std::string(attr_name ? attr_name : "") + "'";
}

// EN: Reset execution memory statistics (Opcode 0x53470: ResetMemoryStats)
// VN: Đặt lại số liệu thống kê bộ nhớ (Opcode 0x53470: ResetMemoryStats)
void Engine::ResetMemoryStats() {
    allocated_bytes = 0;
    execution_count = 0;
}

// EN: Print memory statistics to output stream (Opcode 0x53494: PrintMemoryStats)
// VN: In số liệu thống kê bộ nhớ ra luồng xuất (Opcode 0x53494: PrintMemoryStats)
void Engine::PrintMemoryStats(const std::string& prefix, std::ostream& out) {
    out << prefix << " FastEngine Memory Stats:\n";
    out << prefix << "  Allocated Bytes: " << allocated_bytes << " B\n";
    out << prefix << "  Execution Count: " << execution_count << " calls\n";
    out << prefix << "  Modules Loaded:  " << (modules ? modules->Size() : 0) << "\n";
}

// ===================================================================================
// FASTENGINE SINGLETON IMPLEMENTATION
// ===================================================================================

// EN: Central singleton instance (Opcode 0x45cd4: FastEngine::Instance)
// VN: Thực thể trung tâm duy nhất (Opcode 0x45cd4: FastEngine::Instance)
FastEngine& FastEngine::Instance() {
    static FastEngine instance;
    return instance;
}

FastEngine::FastEngine() {
    Error err;
    m_default_engine = std::make_unique<Engine>(err);
}

FastEngine::~FastEngine() {
    for (ModuleObj* m : m_modules) {
        if (m) m->DecRef();
    }
}

// EN: Initialize runtime with configuration provider (Opcode 0x46198: FastEngine::Initialize)
// VN: Khởi tạo môi trường với nhà cung cấp cấu hình (Opcode 0x46198: FastEngine::Initialize)
bool FastEngine::Initialize(FastEngineConfigProvider* provider) {
    std::lock_guard<std::mutex> lock(m_mutex);
    if (provider) {
        m_max_memory_mb = provider->GetMaxMemoryMB();
        m_thread_pool_size = provider->GetVMThreadPoolSize();
    }

    InitDatetimeModule(m_default_engine.get());
    InitCollectionsModule(m_default_engine.get());

    m_initialized = true;
    return true;
}

// EN: Check if there is an idle VM worker thread available (Opcode 0x4632c: FastEngine::HasFreeVM)
// VN: Kiểm tra xem có luồng thực thi máy ảo rảnh rỗi hay không (Opcode 0x4632c: FastEngine::HasFreeVM)
bool FastEngine::HasFreeVM() const {
    // In mobile single-process multi-thread model, returns true if pool capacity > 0
    return m_thread_pool_size > 0;
}

// EN: Register a module into global runtime (Opcode 0x4682c: FastEngine::AddModule)
// VN: Đăng ký một mô-đun vào runtime toàn cục (Opcode 0x4682c: FastEngine::AddModule)
void FastEngine::AddModule(ModuleObj* mod, const std::string& name) {
    if (!mod) return;
    std::lock_guard<std::mutex> lock(m_mutex);

    mod->IncRef();
    m_modules.push_back(mod);

    if (m_default_engine && m_default_engine->modules) {
        m_default_engine->modules->SetItemStringRef(name, mod, m_default_engine.get());
    }
}

// EN: Decrypt obfuscated ByteDance module name (Opcode 0x46db0: FastEngine::DecryptModuleName)
// VN: Giải mã tên mô-đun bị làm rối của ByteDance (Opcode 0x46db0: FastEngine::DecryptModuleName)
void FastEngine::DecryptModuleName(std::string& name) {
    // ByteDance fast_engine uses prefix check and byte XOR cipher 0x5A
    const std::string enc_prefix = "__enc_";
    if (name.rfind(enc_prefix, 0) == 0) {
        std::string payload = name.substr(enc_prefix.length());
        for (char& c : payload) {
            c = static_cast<char>(static_cast<uint8_t>(c) ^ 0x5A);
        }
        name = payload;
    }
}

// EN: Initialize built-in datetime module (Opcode 0x73980: InitDatetimeModule)
// VN: Khởi tạo mô-đun thời gian datetime tích hợp sẵn (Opcode 0x73980: InitDatetimeModule)
void FastEngine::InitDatetimeModule(Engine* engine) {
    if (!engine) return;

    auto* dt_mod = new ModuleObj("datetime");

    // datetime.now_ms()
    dt_mod->SetAttr("now_ms", new CFuncObj("now_ms", [](Engine* /*eng*/, TupleObj* /*args*/, DictObj* /*kw*/) -> Obj* {
        auto now = std::chrono::system_clock::now();
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
        return new LongObj(static_cast<int64_t>(ms));
    }), engine);

    AddModule(dt_mod, "datetime");
    dt_mod->DecRef();
}

// EN: Initialize built-in collections module (Opcode 0x6ff64: InitCollectionsModule)
// VN: Khởi tạo mô-đun cấu trúc dữ liệu collections tích hợp sẵn (Opcode 0x6ff64: InitCollectionsModule)
void FastEngine::InitCollectionsModule(Engine* engine) {
    if (!engine) return;

    auto* col_mod = new ModuleObj("collections");

    // collections.defaultdict() returns a standard DictObj
    col_mod->SetAttr("defaultdict", new CFuncObj("defaultdict", [](Engine* /*eng*/, TupleObj* /*args*/, DictObj* /*kw*/) -> Obj* {
        return new DictObj();
    }), engine);

    AddModule(col_mod, "collections");
    col_mod->DecRef();
}

} // namespace fast_engine
