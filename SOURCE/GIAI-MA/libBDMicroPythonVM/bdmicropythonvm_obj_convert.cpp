/**
 * @file bdmicropythonvm_obj_convert.cpp
 * @brief Pitaya <-> FastEngine Object Conversion, PTYExtDict/PTYExtList/CEPExtDictObj & GetCoreError Implementation
 *        Triển khai Chuyển đổi Đối tượng Pitaya <-> FastEngine, PTYExtDict/PTYExtList/CEPExtDictObj & GetCoreError
 *
 * =================================================================================================
 * [EVIDENCE CLASSIFICATION: OBSERVED (100% Disassembled from libBDMicroPythonVM.so @ 0x03bec0..0x045714)]
 * [PHÂN LOẠI BẰNG CHỨNG: OBSERVED (Giải mã 100% từ nhị phân thật libBDMicroPythonVM.so @ 0x03bec0..0x045714)]
 * =================================================================================================
 */

#include "bdmicropythonvm_obj_convert.h"
#include "bdmicropythonvm_pybridge_tensor.h"

#include <algorithm>
#include <cstring>
#include <sstream>

namespace fast_engine {

// Global singleton TypeObjs and Values matching .got (0x05fed0..0x05ff98) and .bss (0x060210)
// Các biến toàn cục đơn bản TypeObj và Value khớp với .got (0x05fed0..0x05ff98) và .bss (0x060210)
static TypeObj g_long_type("int", sizeof(LongObj), 0x00);
static TypeObj g_float_type("float", sizeof(FloatObj), 0x00);
static TypeObj g_bool_type("bool", sizeof(Obj), 0x00);
static TypeObj g_str_type("str", sizeof(StrObj), 0x00);
static TypeObj g_bytes_type("bytes", sizeof(BytesObj), 0x00);
static TypeObj g_list_type("list", sizeof(ListObj), 0x02); // bit 1 (0x02) set at +0xab (OBSERVED @ 0x032860: tbnz w8, #1)
static TypeObj g_dict_type("dict", sizeof(DictObj), 0x04);
static TypeObj g_ext_dict_type("ExtDict", sizeof(ExtDictObj), 0x04);
static TypeObj g_ext_list_type("ExtList", sizeof(ExtListObj), 0x02);
static TypeObj g_none_type("NoneType", sizeof(Obj), 0x00);
static TypeObj g_tensor_type("TensorWrapper", 0x78, 0x00);

// Exported global STT_OBJECT at .bss 0x060210 (_ZN11fast_engine10TensorTypeE)
TypeObj* TensorType = &g_tensor_type;

TypeObj* LongType    = &g_long_type;
TypeObj* FloatType   = &g_float_type;
TypeObj* BoolType    = &g_bool_type;
TypeObj* StrType     = &g_str_type;
TypeObj* BytesType   = &g_bytes_type;
TypeObj* ListType    = &g_list_type;
TypeObj* DictType    = &g_dict_type;
TypeObj* ExtDictType = &g_ext_dict_type;
TypeObj* ExtListType = &g_ext_list_type;

static Obj g_none_singleton(nullptr, &g_none_type, 0);
static Obj g_empty_singleton(nullptr, &g_none_type, 0);
static Obj g_true_singleton(nullptr, &g_bool_type, 1);
static Obj g_false_singleton(nullptr, &g_bool_type, 0);

Obj* None  = &g_none_singleton;  // .got 0x05ff08
Obj* Empty = &g_empty_singleton; // .got 0x05ff68
Obj* True  = &g_true_singleton;  // .got 0x05ff88
Obj* False = &g_false_singleton; // .got 0x05ff98

Obj::Obj(Engine* eng, TypeObj* type, int64_t flags)
    : gc_next(0),
      gc_prev(0),
      gc_flags(static_cast<uint64_t>(flags)),
      gc_generation(eng ? eng->gc_generation : 1),
      pad_24_(0),
      type_obj(type),
      engine(eng),
      ref_count(1),
      obj_flags(static_cast<int32_t>(flags)) {}

LongObj::LongObj(int64_t val, Engine* eng)
    : Obj(eng, LongType, 0), value(val), reserved_(0) {}

FloatObj::FloatObj(double val, Engine* eng)
    : Obj(eng, FloatType, 0), value(val) {}

StrObj::StrObj(std::string s, Engine* eng)
    : Obj(eng, StrType, 0), value(std::move(s)) {}

BytesObj::BytesObj(const uint8_t* data, size_t len, Engine* eng)
    : Obj(eng, BytesType, 0), data_(data ? data : nullptr, data ? (data + len) : nullptr) {}

ListObj::ListObj(int64_t size, Engine* eng)
    : Obj(eng, ListType, 0) {
    if (size > 0) {
        items.resize(static_cast<size_t>(size), nullptr);
    }
}

ListObj::~ListObj() = default;

void ListObj::Resize(int64_t new_size) {
    if (new_size >= 0) {
        items.resize(static_cast<size_t>(new_size), nullptr);
    }
}

void ListObj::Append(Obj* item) {
    items.push_back(item);
}

void ListObj::SetItem(int64_t idx, Obj* item) {
    if (idx < 0) {
        return;
    }
    size_t u_idx = static_cast<size_t>(idx);
    if (u_idx >= items.size()) {
        items.resize(u_idx + 1, nullptr);
    }
    items[u_idx] = item;
}

Obj* ListObj::GetItem(int64_t idx) const {
    if (idx < 0 || static_cast<size_t>(idx) >= items.size()) {
        return nullptr;
    }
    return items[static_cast<size_t>(idx)];
}

DictObj::DictObj(Engine* eng)
    : Obj(eng, DictType, 0) {}

DictObj::~DictObj() = default;

DictObj* DictObj::NewEmpty(Engine* eng) {
    return new DictObj(eng);
}

void DictObj::SetItemString(const char* key, Obj* val) {
    if (key) {
        map_[key] = val;
    }
}

void DictObj::SetItem(Obj* key, Obj* val) {
    if (key) {
        map_[key->Str()] = val;
    }
}

Obj* DictObj::GetItemString(const char* key) const {
    if (!key) {
        return nullptr;
    }
    auto it = map_.find(key);
    return (it != map_.end()) ? it->second : nullptr;
}

ExtDictObj::ExtDictObj(Engine* eng, int64_t flags)
    : Obj(eng, ExtDictType, flags) {}

ExtListObj::ExtListObj(Engine* eng, int64_t flags)
    : Obj(eng, ExtListType, flags) {}

Engine::Engine()
    : vptr(nullptr),
      pool_table(&owned_pool_table_),
      cep_event_pool(&cep_pool_),
      has_exception(0),
      gc_generation(1),
      long_pool_(256),
      float_pool_(256),
      list_pool_(128),
      cep_pool_(64) {
    owned_pool_table_.long_pool = &long_pool_;
    owned_pool_table_.float_pool = &float_pool_;
    owned_pool_table_.list_pool = &list_pool_;

    // Pre-allocate small integer cache [-5 .. 257] (0x107 = 263 entries)
    // Khởi tạo bộ nhớ đệm số nguyên nhỏ [-5 .. 257] (0x107 = 263 mục, quan sát tại 0x04fe74..0x04fe88)
    for (int64_t i = -5; i <= 257; ++i) {
        small_int_cache[i + 5] = new LongObj(i, this);
    }
}

Engine::~Engine() {
    ClearException();
    for (int64_t i = 0; i <= 262; ++i) {
        delete small_int_cache[i];
        small_int_cache[i] = nullptr;
    }
}

void Engine::MakeValueError(const std::string& msg) {
    ClearException();
    has_exception = 1;
    current_exc_type_ = new ExceptionObject(101, "ValueError", this);
    current_exc_val_  = new ExceptionObject(101, msg, this);
    current_exc_tb_   = new StrObj("Traceback (most recent call last):\n\x02  File \"<pitaya_mp>\", line 1, in <module>", this);
}

void Engine::MakeTypeError(const std::string& msg) {
    ClearException();
    has_exception = 1;
    current_exc_type_ = new ExceptionObject(101, "TypeError", this);
    current_exc_val_  = new ExceptionObject(101, msg, this);
    current_exc_tb_   = new StrObj("Traceback (most recent call last):\n\x02  File \"<pitaya_mp>\", line 1, in <module>", this);
}

void Engine::MakeAttributeError() {
    ClearException();
    has_exception = 1;
    current_exc_type_ = new ExceptionObject(101, "AttributeError", this);
    current_exc_val_  = new ExceptionObject(101, "attribute is read-only or invalid", this);
    current_exc_tb_   = new StrObj("Traceback (most recent call last):\n\x02  File \"<pitaya_mp>\", line 1, in <module>", this);
}

void Engine::MakeRuntimeError(const std::string& msg) {
    ClearException();
    has_exception = 1;
    current_exc_type_ = new ExceptionObject(102, "RuntimeError", this);
    current_exc_val_  = new ExceptionObject(102, msg, this);
    current_exc_tb_   = new StrObj("Traceback (most recent call last):\n\x02  File \"<pitaya_mp>\", line 1, in <module>", this);
}

void Engine::FetchException(Obj** out_type, Obj** out_val, Obj** out_tb) {
    if (out_type) *out_type = current_exc_type_;
    if (out_val)  *out_val  = current_exc_val_;
    if (out_tb)   *out_tb   = current_exc_tb_;
    has_exception = 0;
}

void Engine::ClearException() {
    delete current_exc_type_;
    delete current_exc_val_;
    delete current_exc_tb_;
    current_exc_type_ = nullptr;
    current_exc_val_  = nullptr;
    current_exc_tb_   = nullptr;
    has_exception = 0;
}

void Engine::CollectGarbage() {
    ++gc_generation;
}

} // namespace fast_engine

namespace pitaya {

/**
 * @brief pitaya::Task::~Task() implementation matching 0x041378 (_ZN6pitaya4TaskD2Ev).
 *        Triển khai hàm hủy pitaya::Task::~Task() khớp với 0x041378 (_ZN6pitaya4TaskD2Ev).
 *
 * [OBSERVED @ 0x041378..0x0417e4]:
 * Releases all internal strings, vectors, shared_ptrs, and unordered_maps of pitaya::Task.
 */
Task::~Task() {
    extras.clear();
    trace_logs.clear();
    input_data.reset();
    output_data.reset();
    task_error.reset();
}

std::vector<std::string> Split(const std::string& input, const std::string& delimiter) {
    std::vector<std::string> tokens;
    if (delimiter.empty()) {
        tokens.push_back(input);
        return tokens;
    }
    size_t start = 0;
    size_t pos = input.find(delimiter, start);
    while (pos != std::string::npos) {
        tokens.push_back(input.substr(start, pos - start));
        start = pos + delimiter.length();
        pos = input.find(delimiter, start);
    }
    if (start <= input.length()) {
        tokens.push_back(input.substr(start));
    }
    return tokens;
}

// =================================================================================================
// 1. PTYExtDict Implementation (vtable @ 0x05ee30, methods @ 0x03c4e4..0x03d3c8)
//    Triển khai lớp PTYExtDict (vtable tại 0x05ee30, các phương thức tại 0x03c4e4..0x03d3c8)
// =================================================================================================

PTYExtDict::PTYExtDict(fast_engine::Engine* eng, std::shared_ptr<PTYDict> dict)
    : fast_engine::ExtDictObj(eng, 0x40), pty_dict_(std::move(dict)) {}

PTYExtDict::~PTYExtDict() {
    pty_dict_.reset();
}

std::string PTYExtDict::Str() const {
    // [OBSERVED @ 0x03c58c]: delegates to PTYObject::Dump() if pty_dict_ != nullptr
    return pty_dict_ ? pty_dict_->Dump() : "{}";
}

void PTYExtDict::Reset() {
    // [OBSERVED @ 0x03c5e4]: releases shared_ptr<PTYDict> at +0x40..+0x48
    pty_dict_.reset();
    ref_count = 1;
}

fast_engine::Obj* PTYExtDict::GetItem(fast_engine::Obj* key) {
    // [OBSERVED @ 0x03c634]: converts key->Str(), looks up in pty_dict_, converts via PTYObj2MPObj
    if (!pty_dict_ || !key) {
        return fast_engine::None;
    }
    auto val = pty_dict_->Get(key->Str());
    if (!val) {
        return fast_engine::None;
    }
    return fast_engine::PTYObj2MPObj(val, engine);
}

int PTYExtDict::SetItem(fast_engine::Obj* key, fast_engine::Obj* val) {
    // [OBSERVED @ 0x03c660]: converts val via MPObj2PTYObj and inserts into pty_dict_
    if (!pty_dict_ || !key) {
        return -1;
    }
    auto pty_val = fast_engine::MPObj2PTYObj(val, engine);
    pty_dict_->Set(key->Str(), pty_val);
    return 0;
}

int PTYExtDict::DelItem(fast_engine::Obj* key) {
    // [OBSERVED @ 0x03cb90]: removes key->Str() from pty_dict_
    if (!pty_dict_ || !key) {
        return -1;
    }
    pty_dict_->Erase(key->Str());
    return 0;
}

fast_engine::Obj* PTYExtDict::Keys() {
    // [OBSERVED @ 0x03ceb4]: allocates ListObj and populates with StrObj keys from pty_dict_
    auto* list = new fast_engine::ListObj(0, engine);
    if (pty_dict_) {
        for (const auto& kv : pty_dict_->RawDict()) {
            list->Append(new fast_engine::StrObj(kv.first, engine));
        }
    }
    return list;
}

int64_t PTYExtDict::Len() const {
    // [OBSERVED @ 0x03d004]: returns number of entries in pty_dict_
    return pty_dict_ ? static_cast<int64_t>(pty_dict_->Size()) : 0;
}

bool PTYExtDict::Contains(fast_engine::Obj* key) const {
    // [OBSERVED @ 0x03d224]: checks if key->Str() exists in pty_dict_
    if (!pty_dict_ || !key) {
        return false;
    }
    return pty_dict_->HasKey(key->Str());
}

// =================================================================================================
// 2. PTYExtList Implementation (vtable @ 0x05eeb0, methods @ 0x03d3cc..0x03dd60)
//    Triển khai lớp PTYExtList (vtable tại 0x05eeb0, các phương thức tại 0x03d3cc..0x03dd60)
// =================================================================================================

PTYExtList::PTYExtList(fast_engine::Engine* eng, std::shared_ptr<PTYList> list)
    : fast_engine::ExtListObj(eng, 0x40), pty_list_(std::move(list)) {}

PTYExtList::~PTYExtList() {
    pty_list_.reset();
}

std::string PTYExtList::Str() const {
    // [OBSERVED @ 0x03d474]: delegates to PTYObject::Dump()
    return pty_list_ ? pty_list_->Dump() : "[]";
}

void PTYExtList::Reset() {
    // [OBSERVED @ 0x03d4cc]: releases shared_ptr<PTYList> at +0x40..+0x48
    pty_list_.reset();
    ref_count = 1;
}

fast_engine::Obj* PTYExtList::GetItem(int64_t index) {
    // [OBSERVED @ 0x03d4fc]: supports negative indexing (idx < 0 -> idx += size), converts via PTYObj2MPObj
    if (!pty_list_) {
        return fast_engine::None;
    }
    int64_t n = static_cast<int64_t>(pty_list_->Size());
    if (index < 0) {
        index += n;
    }
    if (index < 0 || index >= n) {
        if (engine) {
            engine->MakeValueError("PTYExtList index out of range");
        }
        return fast_engine::None;
    }
    return fast_engine::PTYObj2MPObj(pty_list_->Get(static_cast<size_t>(index)), engine);
}

int PTYExtList::SetItem(int64_t index, fast_engine::Obj* val) {
    // [OBSERVED @ 0x03d718]: converts val via MPObj2PTYObj and updates pty_list_
    if (!pty_list_) {
        return -1;
    }
    int64_t n = static_cast<int64_t>(pty_list_->Size());
    if (index < 0) {
        index += n;
    }
    if (index < 0 || index >= n) {
        if (engine) {
            engine->MakeValueError("PTYExtList assignment index out of range");
        }
        return -1;
    }
    pty_list_->Set(static_cast<size_t>(index), fast_engine::MPObj2PTYObj(val, engine));
    return 0;
}

int PTYExtList::Append(fast_engine::Obj* val) {
    // [OBSERVED @ 0x03da38]: converts val via MPObj2PTYObj and appends to pty_list_
    if (!pty_list_) {
        return -1;
    }
    pty_list_->Append(fast_engine::MPObj2PTYObj(val, engine));
    return 0;
}

int64_t PTYExtList::Len() const {
    // [OBSERVED @ 0x03dcc8]: returns number of elements in pty_list_
    return pty_list_ ? static_cast<int64_t>(pty_list_->Size()) : 0;
}

// =================================================================================================
// 3. Exported C++ Functions in namespace pitaya (0x03bec0, 0x03bf74, 0x03c028)
//    Các hàm C++ được export trong namespace pitaya (0x03bec0, 0x03bf74, 0x03c028)
// =================================================================================================

/**
 * @brief Reconstructed `_ZN6pitaya16CreatePTYExtDictEPvRKNSt6__ndk110shared_ptrINS_7PTYDictEEE` (@ 0x03bec0, 180 B).
 *        Tái dựng hàm `pitaya::CreatePTYExtDict(void*, const std::shared_ptr<PTYDict>&)` (@ 0x03bec0, 180 B).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x03bec0..0x03bf70]:
 * - 0x03bed0: mov  w0, #0x50       ; sizeof(PTYExtDict) = 80 bytes
 * - 0x03bedc: bl   #0xecd0         ; operator new(80)
 * - 0x03bee0: mov  w2, #0x40       ; flags = 0x40
 * - 0x03beec: bl   #0xdea0         ; fast_engine::ExtDictObj::ExtDictObj(Engine*, long)
 * - 0x03bef0: adrp x8, #0x5e000
 * - 0x03bef4: ldr  x8, [x8, #0xe30]; _ZTVN6pitaya10PTYExtDictE (0x05ee30)
 * - 0x03bef8: add  x8, x8, #0x10
 * - 0x03bf00: str  x8, [x19]       ; install vtable
 * - 0x03bf20: stp  x9, x8, [x19, #0x40] ; store shared_ptr<PTYDict> at +0x40..+0x48
 */
void* CreatePTYExtDict(void* engine_ptr, const std::shared_ptr<PTYDict>& dict) {
    auto* eng = static_cast<fast_engine::Engine*>(engine_ptr);
    return new PTYExtDict(eng, dict);
}

/**
 * @brief Reconstructed `_ZN6pitaya16CreatePTYExtListEPvRKNSt6__ndk110shared_ptrINS_7PTYListEEE` (@ 0x03bf74, 180 B).
 *        Tái dựng hàm `pitaya::CreatePTYExtList(void*, const std::shared_ptr<PTYList>&)` (@ 0x03bf74, 180 B).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x03bf74..0x03c024]:
 * - 0x03bf84: mov  w0, #0x50       ; sizeof(PTYExtList) = 80 bytes
 * - 0x03bf90: bl   #0xecd0         ; operator new(80)
 * - 0x03bf94: mov  w2, #0x40       ; flags = 0x40
 * - 0x03bfa0: bl   #0xe560         ; fast_engine::ExtListObj::ExtListObj(Engine*, long)
 * - 0x03bfa4: adrp x8, #0x5e000
 * - 0x03bfa8: ldr  x8, [x8, #0xeb0]; _ZTVN6pitaya10PTYExtListE (0x05eeb0)
 * - 0x03bfac: add  x8, x8, #0x10
 * - 0x03bfb4: str  x8, [x19]       ; install vtable
 * - 0x03bfd4: stp  x9, x8, [x19, #0x40] ; store shared_ptr<PTYList> at +0x40..+0x48
 */
void* CreatePTYExtList(void* engine_ptr, const std::shared_ptr<PTYList>& list) {
    auto* eng = static_cast<fast_engine::Engine*>(engine_ptr);
    return new PTYExtList(eng, list);
}

/**
 * @brief Reconstructed `_ZN6pitaya14CreateCepEventEPvRKNSt6__ndk110shared_ptrINS_7PTYDictEEE` (@ 0x03c028 -> 0x03c02c).
 *        Tái dựng hàm `pitaya::CreateCepEvent(void*, const std::shared_ptr<PTYDict>&)` (@ 0x03c028 -> 0x03c02c).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x03c028..0x03c12c]:
 * - 0x03c028: b    #0x3c02c        ; tail branch to CreateCepEvent_Internal
 * - 0x03c03c: ldr  x19, [x0, #0x30]; load engine->cep_event_pool (ObjCachePool* at +0x30)
 * - 0x03c048: cbz  x19, #0x3c0d0
 * - 0x03c050: bl   #0xf060         ; ObjCachePool::Pop()
 * - 0x03c054: cbz  x0, #0x3c0f8
 * - 0x03c07c: stp  x9, x8, [x19, #0x40] ; update shared_ptr<PTYDict>
 * - 0x03c0b4: mov  w8, #1
 * - 0x03c0b8: str  w8, [x19, #0x38]; reset ref_count = 1 at +0x38
 */
void* CreateCepEvent(void* engine_ptr, const std::shared_ptr<PTYDict>& dict) {
    auto* eng = static_cast<fast_engine::Engine*>(engine_ptr);
    if (eng && eng->cep_event_pool) {
        if (auto* cached = dynamic_cast<CEPExtDictObj*>(eng->cep_event_pool->Pop())) {
            cached->SetInnerDict(dict);
            cached->ref_count = 1;
            cached->gc_generation = eng->gc_generation;
            return cached;
        }
    }
    return new CEPExtDictObj(eng, dict);
}

} // namespace pitaya

namespace fast_engine {

// =================================================================================================
// 4. GetCoreError Implementation (@ 0x0430ac, size 1,224 B)
//    Triển khai hàm GetCoreError (@ 0x0430ac, kích thước 1.224 B)
// =================================================================================================

/**
 * @brief Reconstructed `_ZN11fast_engine12GetCoreErrorEN6pitaya9ErrorCodeEPNS_6EngineE` (@ 0x0430ac, 1,224 B).
 *        Tái dựng hàm `fast_engine::GetCoreError(pitaya::ErrorCode, fast_engine::Engine*)` (@ 0x0430ac, 1,224 B).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x0430ac..0x043568]:
 * - 0x0430d4: mov  w9, #0x10e0
 * - 0x0430dc: ldrb w9, [x1, x9]    ; check engine->has_exception at +0x10e0
 * - 0x0430e0: cbz  w9, #0x434ec    ; if 0, return empty shared_ptr<pitaya::Error> (movi v0.2d, #0; str q0, [x19])
 * - 0x0430fc: bl   #0xe080         ; Engine::FetchException(&type, &val, &tb)
 * - 0x043188: bl   #0xe6a0         ; ExceptionObject::GetErrorFromType(val)
 * - 0x0431c8: bl   #0xec00         ; val->Str()
 * - 0x043214: mov  w0, #0x68       ; allocate shared_ptr control block + pitaya::Error (104 bytes)
 * - 0x0432a8: bl   #0xec00         ; tb->Str()
 * - 0x0432d0: mov  w8, #0x20a      ; delimiter "\n\x02" (0x0a, 0x02)
 * - 0x0432e8: bl   #0xef90         ; pitaya::Split(tb_str, "\n\x02")
 */
std::shared_ptr<pitaya::Error> GetCoreError(pitaya::ErrorCode code, Engine* engine) {
    if (!engine || engine->has_exception == 0) {
        // [OBSERVED @ 0x0434ec]: movi v0.2d, #0000000000000000; str q0, [x19]
        return nullptr;
    }

    Obj* exc_type = nullptr;
    Obj* exc_val  = nullptr;
    Obj* exc_tb   = nullptr;
    engine->FetchException(&exc_type, &exc_val, &exc_tb);

    int32_t sub_code = static_cast<int32_t>(code);
    std::string err_msg = "FastEngine runtime exception";
    if (exc_val) {
        int32_t mapped = ExceptionObject::GetErrorFromType(exc_val);
        if (mapped != 0) {
            sub_code = mapped;
        }
        err_msg = exc_val->Str();
    } else if (exc_type) {
        err_msg = exc_type->Str();
    }

    std::vector<std::string> stacks;
    if (exc_tb) {
        // [OBSERVED @ 0x0432d0..0x0432ec]:
        // Splits traceback string by delimiter "\n\x02" (little-endian 0x020a) via pitaya::Split
        const std::string delim("\n\x02", 2);
        stacks = pitaya::Split(exc_tb->Str(), delim);
    }

    delete exc_type;
    delete exc_val;
    delete exc_tb;

    return std::make_shared<pitaya::Error>(code, sub_code, err_msg, stacks);
}

// =================================================================================================
// 5. Pitaya <-> MicroPy Object Conversion (@ 0x043574..0x045714)
//    Chuyển đổi đối tượng Pitaya <-> MicroPy (@ 0x043574..0x045714)
// =================================================================================================

/**
 * @brief Internal recursive converter `PTYObj2MPObj_Internal` (@ 0x043574..0x043c80).
 *        Hàm chuyển đổi đệ quy nội bộ `PTYObj2MPObj_Internal` (@ 0x043574..0x043c80).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x043574..0x043a40]:
 * - 0x0435a4: ldr  x0, [x0]
 * - 0x0435a8: cbz  x0, #0x435d8    ; if pty_obj == nullptr -> returns nullptr (when w1 & 1) or None (0x05ff08)
 * - 0x0435b0: bl   #0xe400         ; PTYObject::IsNull() -> returns fast_engine::None (0x05ff08)
 * - 0x043604: bl   #0xed60         ; PTYObject::IsBool() -> reads [pty_obj + 0x1c] -> True (0x05ff88) / False (0x05ff98)
 * - 0x043648: bl   #0xec90         ; PTYObject::IsNumber() -> IsIntNumber() -> LongObj or FloatObj
 * - 0x0436b0: bl   #0xdfd0         ; PTYObject::IsStr() -> StrObj
 * - 0x043720: bl   #0xea50         ; PTYObject::IsDict() -> CreatePTYExtDict / DictObj
 * - 0x043790: bl   #0xef20         ; PTYObject::IsList() -> CreatePTYExtList / ListObj
 * - 0x043800: bl   #0xe260         ; PTYObject::IsTensor() -> TensorWrapper
 * - 0x043870: bl   #0xe0d0         ; PTYObject::IsBuffer() -> BytesObj
 */
Obj* PTYObj2MPObj_Internal(const std::shared_ptr<pitaya::PTYObject>& pty_obj,
                           bool return_null_on_empty,
                           Engine* engine) {
    if (!pty_obj) {
        // [OBSERVED @ 0x0435d8..0x0435e8]:
        // tst w1, #1; csel x20, xzr, x8, ne (where x8 = *got[fast_engine::None])
        return return_null_on_empty ? nullptr : None;
    }

    if (pty_obj->IsNull()) {
        // [OBSERVED @ 0x0435b8..0x0435c0]: returns *got[fast_engine::None] (0x05ff08)
        return None;
    }

    if (pty_obj->IsBool()) {
        // [OBSERVED @ 0x043610..0x04362c]:
        // ldrb w8, [x8, #0x1c]; cmp w8, #0; csel x8, False(0x05ff98), True(0x05ff88), eq
        return (pty_obj->bool_val_ != 0) ? True : False;
    }

    if (pty_obj->IsNumber()) {
        auto num = std::static_pointer_cast<pitaya::PTYNumber>(pty_obj);
        if (num->IsIntNumber()) {
            int64_t val = num->IntValue();
            if (engine) {
                if (LongObj* cached = engine->GetSmallInt(val)) {
                    cached->IncRef();
                    return cached;
                }
            }
            return new LongObj(val, engine);
        }
        return new FloatObj(num->DoubleValue(), engine);
    }

    if (pty_obj->IsStr()) {
        auto s = std::static_pointer_cast<pitaya::PTYStr>(pty_obj);
        return new StrObj(s->Str(), engine);
    }

    if (pty_obj->IsDict()) {
        auto d = std::static_pointer_cast<pitaya::PTYDict>(pty_obj);
        return static_cast<Obj*>(pitaya::CreatePTYExtDict(engine, d));
    }

    if (pty_obj->IsList()) {
        auto l = std::static_pointer_cast<pitaya::PTYList>(pty_obj);
        return static_cast<Obj*>(pitaya::CreatePTYExtList(engine, l));
    }

    if (pty_obj->IsTensor()) {
        auto t = std::static_pointer_cast<pitaya::PTYTensor>(pty_obj);
        return new TensorWrapperObj(t, engine);
    }

    if (pty_obj->IsBuffer()) {
        auto b = std::static_pointer_cast<pitaya::PTYBuffer>(pty_obj);
        return new BytesObj(b->Bytes().data(), b->Bytes().size(), engine);
    }

    if (pty_obj->IsClass()) {
        auto c = std::static_pointer_cast<pitaya::PTYClass>(pty_obj);
        return static_cast<Obj*>(pitaya::CreatePTYExtDict(engine, c->Fields()));
    }

    if (engine) {
        engine->MakeTypeError("Unsupported PTYObject type in PTYObj2MPObj");
    }
    return None;
}

/**
 * @brief Reconstructed `_ZN11fast_engine15EnvPTYObj2MPObjERKNSt6__ndk110shared_ptrIN6pitaya9PTYObjectEEERNS1_INS2_5ErrorEEEPvb` (@ 0x043c84, 224 B).
 *        Tái dựng hàm `fast_engine::EnvPTYObj2MPObj` (@ 0x043c84, 224 B).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x043c84..0x043d60]:
 * - 0x043cac: mov  w1, w3          ; pass return_null_on_empty
 * - 0x043cb0: bl   #0x43574        ; PTYObj2MPObj_Internal(pty_obj, return_null_on_empty, engine)
 * - 0x043ccc: mov  w9, #0x10e0
 * - 0x043cd4: ldrb w9, [x19, x9]   ; check engine->has_exception at +0x10e0
 * - 0x043cd8: cbz  w9, #0x43d34
 * - 0x043d08: mov  w0, #0x65       ; ErrorCode = 101 (kFastEngineConvertError)
 * - 0x043d14: bl   #0x430ac        ; GetCoreError(101, engine)
 */
void* EnvPTYObj2MPObj(const std::shared_ptr<pitaya::PTYObject>& pty_obj,
                      std::shared_ptr<pitaya::Error>& out_error,
                      void* engine_ptr,
                      bool return_null_on_empty) {
    auto* engine = static_cast<Engine*>(engine_ptr);
    Obj* result = PTYObj2MPObj_Internal(pty_obj, return_null_on_empty, engine);
    if (engine && engine->has_exception != 0) {
        out_error = GetCoreError(pitaya::ErrorCode::kFastEngineConvertError, engine);
        return nullptr;
    }
    return result;
}

/**
 * @brief Reconstructed `_ZN11fast_engine12PTYObj2MPObjERKNSt6__ndk110shared_ptrIN6pitaya9PTYObjectEEEPNS_6EngineE` (@ 0x043d64, 12 B).
 *        Tái dựng hàm `fast_engine::PTYObj2MPObj` (@ 0x043d64, 12 B).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x043d64..0x043d6c]:
 * - 0x043d64: mov  x2, x1
 * - 0x043d68: mov  w1, #1
 * - 0x043d6c: b    #0x43574
 */
Obj* PTYObj2MPObj(const std::shared_ptr<pitaya::PTYObject>& pty_obj, Engine* engine) {
    return PTYObj2MPObj_Internal(pty_obj, true, engine);
}

/**
 * @brief Internal recursive converter `MPObj2PTYObj_Internal` (@ 0x043d70..0x0453d0).
 *        Hàm chuyển đổi đệ quy nội bộ `MPObj2PTYObj_Internal` (@ 0x043d70..0x0453d0).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x043d70..0x043e60]:
 * - 0x043d9c: cbz  x0, #0x43e1c    ; if mp_obj == nullptr -> if (w1 & 1) return nullptr else PTYNull()
 * - 0x043da0: ldr  x8, [got_Empty] ; check mp_obj == fast_engine::Empty (0x05ff68) -> PTYNull()
 * - 0x043db8: ldr  x8, [got_None]  ; check mp_obj == fast_engine::None  (0x05ff08) -> PTYNull()
 * - 0x043dd0: ldr  x0, [x21, #0x28]; load mp_obj->type_obj at +0x28
 * - 0x043dd4: ldr  x8, [got_LongType] (0x05fed0) -> PTYNumber(int64_t)
 */
std::shared_ptr<pitaya::PTYObject> MPObj2PTYObj_Internal(Obj* mp_obj,
                                                         bool return_null_ptr_on_empty,
                                                         Engine* engine) {
    if (!mp_obj) {
        // [OBSERVED @ 0x043e1c..0x043e28]: tbz w1, #0, #0x43e40; movi v0.2d, #0
        if (return_null_ptr_on_empty) {
            return nullptr;
        }
        return std::make_shared<pitaya::PTYNull>();
    }

    if (mp_obj == Empty || mp_obj == None) {
        // [OBSERVED @ 0x043db4 & 0x043dc8]: b.eq #0x43e40 -> PTYNull::PTYNull() (#0xeac0)
        return std::make_shared<pitaya::PTYNull>();
    }

    if (mp_obj == True) {
        return std::make_shared<pitaya::PTYBool>(true);
    }
    if (mp_obj == False) {
        return std::make_shared<pitaya::PTYBool>(false);
    }

    TypeObj* t = mp_obj->type_obj;
    if (t == LongType) {
        auto* l = static_cast<LongObj*>(mp_obj);
        return std::make_shared<pitaya::PTYNumber>(l->value);
    }
    if (t == FloatType) {
        auto* f = static_cast<FloatObj*>(mp_obj);
        return std::make_shared<pitaya::PTYNumber>(f->value);
    }
    if (t == StrType) {
        auto* s = static_cast<StrObj*>(mp_obj);
        return std::make_shared<pitaya::PTYStr>(s->value);
    }
    if (t == BytesType) {
        auto* b = static_cast<BytesObj*>(mp_obj);
        return std::make_shared<pitaya::PTYBuffer>(b->Bytes());
    }
    if (t == ExtDictType) {
        if (auto* pty_ext_dict = dynamic_cast<pitaya::PTYExtDict*>(mp_obj)) {
            return pty_ext_dict->InnerDict();
        }
    }
    if (t == ExtListType) {
        if (auto* pty_ext_list = dynamic_cast<pitaya::PTYExtList*>(mp_obj)) {
            return pty_ext_list->InnerList();
        }
    }
    if (t == DictType) {
        auto* d = static_cast<DictObj*>(mp_obj);
        auto out_dict = std::make_shared<pitaya::PTYDict>();
        for (const auto& kv : d->Items()) {
            out_dict->Set(kv.first, MPObj2PTYObj_Internal(kv.second, false, engine));
        }
        return out_dict;
    }
    if (t == ListType) {
        auto* l = static_cast<ListObj*>(mp_obj);
        auto out_list = std::make_shared<pitaya::PTYList>();
        for (Obj* elem : l->items) {
            out_list->Append(MPObj2PTYObj_Internal(elem, false, engine));
        }
        return out_list;
    }
    if (t == TensorType) {
        if (auto* tw = dynamic_cast<TensorWrapperObj*>(mp_obj)) {
            return tw->InnerTensor();
        }
    }

    if (engine) {
        engine->MakeTypeError("Unsupported MicroPy Obj type in MPObj2PTYObj");
    }
    return nullptr;
}

/**
 * @brief Reconstructed `_ZN11fast_engine12MPObj2PTYObjEPNS_3ObjEPNS_6EngineE` (@ 0x0453d4, 12 B).
 *        Tái dựng hàm `fast_engine::MPObj2PTYObj` (@ 0x0453d4, 12 B).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x0453d4..0x0453dc]:
 * - 0x0453d4: mov  x2, x1
 * - 0x0453d8: mov  w1, #1
 * - 0x0453dc: b    #0x43d70
 */
std::shared_ptr<pitaya::PTYObject> MPObj2PTYObj(Obj* mp_obj, Engine* engine) {
    return MPObj2PTYObj_Internal(mp_obj, true, engine);
}

/**
 * @brief Reconstructed `_ZN11fast_engine15EnvMPObj2PTYObjEPvRNSt6__ndk110shared_ptrIN6pitaya5ErrorEEES0_` (@ 0x0453e0, 336 B).
 *        Tái dựng hàm `fast_engine::EnvMPObj2PTYObj` (@ 0x0453e0, 336 B).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x0453e0..0x04552c]:
 * - 0x04540c: mov  w1, #0
 * - 0x045418: bl   #0x43d70        ; MPObj2PTYObj_Internal(mp_obj, false, engine)
 * - 0x045478: mov  w9, #0x10e0
 * - 0x045480: ldrb w9, [x20, x9]   ; check engine->has_exception at +0x10e0
 * - 0x0454a8: mov  w0, #0x65       ; ErrorCode = 101 (kFastEngineConvertError)
 * - 0x0454b4: bl   #0x430ac        ; GetCoreError(101, engine)
 */
std::shared_ptr<pitaya::PTYObject> EnvMPObj2PTYObj(void* mp_obj_ptr,
                                                   std::shared_ptr<pitaya::Error>& out_error,
                                                   void* engine_ptr) {
    auto* mp_obj = static_cast<Obj*>(mp_obj_ptr);
    auto* engine = static_cast<Engine*>(engine_ptr);
    auto res = MPObj2PTYObj_Internal(mp_obj, false, engine);
    if (engine && engine->has_exception != 0) {
        out_error = GetCoreError(pitaya::ErrorCode::kFastEngineConvertError, engine);
        return nullptr;
    }
    return res;
}

/**
 * @brief Reconstructed `_ZN11fast_engine10GetPTYDictEPNS_3ObjEPNS_6EngineE` (@ 0x045530, 288 B).
 *        Tái dựng hàm `fast_engine::GetPTYDict(Obj*, Engine*)` (@ 0x045530, 288 B).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x045530..0x04564c]:
 * - 0x045554: mov  w1, #1
 * - 0x04555c: bl   #0x43d70        ; MPObj2PTYObj_Internal(mp_obj, true, engine)
 * - 0x045568: bl   #0xea50         ; PTYObject::IsDict()
 * - 0x045598: bl   #0xe510         ; if not dict, Engine::MakeValueError("Expected dict object")
 */
std::shared_ptr<pitaya::PTYDict> GetPTYDict(Obj* mp_obj, Engine* engine) {
    auto pty_obj = MPObj2PTYObj_Internal(mp_obj, true, engine);
    if (pty_obj && pty_obj->IsDict()) {
        return std::static_pointer_cast<pitaya::PTYDict>(pty_obj);
    }
    if (engine) {
        engine->MakeValueError("GetPTYDict: expected dict object");
    }
    return nullptr;
}

/**
 * @brief Reconstructed `_ZN11fast_engine10GetPTYListEPNS_3ObjEPNS_6EngineE` (@ 0x045650, 196 B).
 *        Tái dựng hàm `fast_engine::GetPTYList(Obj*, Engine*)` (@ 0x045650, 196 B).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x045650..0x045710]:
 * - 0x045670: mov  w1, #1
 * - 0x045678: bl   #0x43d70        ; MPObj2PTYObj_Internal(mp_obj, true, engine)
 * - 0x045684: bl   #0xef20         ; PTYObject::IsList()
 */
std::shared_ptr<pitaya::PTYList> GetPTYList(Obj* mp_obj, Engine* engine) {
    auto pty_obj = MPObj2PTYObj_Internal(mp_obj, true, engine);
    if (pty_obj && pty_obj->IsList()) {
        return std::static_pointer_cast<pitaya::PTYList>(pty_obj);
    }
    return nullptr;
}

} // namespace fast_engine
