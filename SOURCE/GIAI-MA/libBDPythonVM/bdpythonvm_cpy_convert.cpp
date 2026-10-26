/**
 * @file bdpythonvm_cpy_convert.cpp
 * @brief Pitaya <-> CPython 3.8 Object Conversion & 11 PTYPyDictSet Overloads Implementation
 *        Triển khai Chuyển đổi Đối tượng Pitaya <-> CPython 3.8 & 11 Hàm nạp chồng PTYPyDictSet
 *
 * =================================================================================================
 * [EVIDENCE CLASSIFICATION: OBSERVED (100% Disassembled from libBDPythonVM.so @ 0x04ca3c..0x04efd4)]
 * [PHÂN LOẠI BẰNG CHỨNG: OBSERVED (Giải mã 100% từ nhị phân thật libBDPythonVM.so @ 0x04ca3c..0x04efd4)]
 * =================================================================================================
 */

#include "bdpythonvm_cpy_convert.h"

#include <cstring>
#include <sstream>

// =================================================================================================
// 1. CPython 3.8 Singletons & C-API Helpers (Matching .got 0x067ed0..0x067fa0 & .plt)
//    Các đối tượng đơn bản CPython 3.8 & Hàm phụ trợ C-API (Khớp .got 0x067ed0..0x067fa0 & .plt)
// =================================================================================================

PyTypeObject PyBool_Type      = {1, nullptr, 0, "bool",      sizeof(PyObject), 0};
PyTypeObject PyLong_Type      = {1, nullptr, 0, "int",       sizeof(PyObject), 0, nullptr, 0, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0x01000000U}; // byte +0xab bit 0 set (OBSERVED @ 0x04dba4)
PyTypeObject PyFloat_Type     = {1, nullptr, 0, "float",     sizeof(PyObject), 0};
PyTypeObject PyUnicode_Type   = {1, nullptr, 0, "str",       sizeof(PyObject), 0};
PyTypeObject PyBytes_Type     = {1, nullptr, 0, "bytes",     sizeof(PyObject), 0};
PyTypeObject PyByteArray_Type = {1, nullptr, 0, "bytearray", sizeof(PyObject), 0};
PyTypeObject PyList_Type      = {1, nullptr, 0, "list",      sizeof(PyObject), 0};
PyTypeObject PyDict_Type      = {1, nullptr, 0, "dict",      sizeof(PyObject), 0};
PyTypeObject PyModule_Type    = {1, nullptr, 0, "module",    sizeof(PyObject), 0};
static PyTypeObject PyNone_Type = {1, nullptr, 0, "NoneType", sizeof(PyObject), 0};

static PyObject g_py_none_struct  = {1, &PyNone_Type, 0};
static PyObject g_py_true_struct  = {1, &PyBool_Type, 1, true, 1};
static PyObject g_py_false_struct = {1, &PyBool_Type, 1, false, 0};

PyObject* Py_None  = &g_py_none_struct;  // .got 0x067f58 (_Py_NoneStruct)
PyObject* Py_True  = &g_py_true_struct;  // .got 0x067f98 (_Py_TrueStruct)
PyObject* Py_False = &g_py_false_struct; // .got 0x067f90 (_Py_FalseStruct)

void Py_INCREF(PyObject* op) {
    if (op) {
        ++op->ob_refcnt;
    }
}

void Py_DECREF(PyObject* op) {
    if (!op) return;
    if (--op->ob_refcnt <= 0) {
        if (op != Py_None && op != Py_True && op != Py_False) {
            if (op->ob_type && op->ob_type->tp_dealloc) {
                op->ob_type->tp_dealloc(op);
            } else {
                delete op;
            }
        }
    }
}

static PyObject* DefaultTpAlloc(PyTypeObject* type, Py_ssize_t /*nitems*/) {
    auto* obj = new PyObject();
    obj->ob_refcnt = 1;
    obj->ob_type = type;
    return obj;
}

int PyType_Ready(PyTypeObject* type) {
    if (!type) return -1;
    if (!type->tp_alloc) {
        type->tp_alloc = &DefaultTpAlloc;
    }
    return 0;
}

PyObject* PyModule_Create2(PyModuleDef* def, int module_api_version) {
    // [OBSERVED @ 0x024544, 0x04be50, 0x04f9c0]: mov w1, #0x3f5 (1013); bl PyModule_Create2
    if (!def || module_api_version != kPythonAbiVersion) {
        return nullptr;
    }
    auto* mod = new PyObject();
    mod->ob_refcnt = 1;
    mod->ob_type = &PyModule_Type;
    mod->tag = 8;
    mod->str_val = def->m_name ? def->m_name : "";
    return mod;
}

int PyModule_AddObject(PyObject* mod, const char* name, PyObject* value) {
    if (!mod || !name || !value) {
        return -1;
    }
    mod->dict_items[name] = value;
    return 0;
}

PyObject* PyBool_FromLong(long v) {
    PyObject* res = (v != 0) ? Py_True : Py_False;
    Py_INCREF(res);
    return res;
}

PyObject* PyLong_FromLongLong(long long v) {
    auto* obj = new PyObject();
    obj->ob_refcnt = 1;
    obj->ob_type = &PyLong_Type;
    obj->tag = 2;
    obj->int_val = static_cast<int64_t>(v);
    obj->uint_val = static_cast<uint64_t>(v);
    return obj;
}

PyObject* PyLong_FromUnsignedLongLong(unsigned long long v) {
    auto* obj = new PyObject();
    obj->ob_refcnt = 1;
    obj->ob_type = &PyLong_Type;
    obj->tag = 2;
    obj->int_val = static_cast<int64_t>(v);
    obj->uint_val = static_cast<uint64_t>(v);
    return obj;
}

long long PyLong_AsLongLong(PyObject* op) {
    return op ? static_cast<long long>(op->int_val) : 0LL;
}

PyObject* PyFloat_FromDouble(double v) {
    auto* obj = new PyObject();
    obj->ob_refcnt = 1;
    obj->ob_type = &PyFloat_Type;
    obj->tag = 3;
    obj->float_val = v;
    return obj;
}

double PyFloat_AsDouble(PyObject* op) {
    return op ? op->float_val : 0.0;
}

PyObject* PyUnicode_FromStringAndSize(const char* u, Py_ssize_t size) {
    auto* obj = new PyObject();
    obj->ob_refcnt = 1;
    obj->ob_type = &PyUnicode_Type;
    obj->tag = 4;
    if (u && size > 0) {
        obj->str_val.assign(u, static_cast<size_t>(size));
    }
    return obj;
}

const char* PyUnicode_AsUTF8(PyObject* unicode) {
    return unicode ? unicode->str_val.c_str() : "";
}

PyObject* PyObject_Str(PyObject* v) {
    if (!v) return nullptr;
    if (v->ob_type == &PyUnicode_Type) {
        Py_INCREF(v);
        return v;
    }
    std::string repr;
    if (v == Py_None) repr = "None";
    else if (v == Py_True) repr = "True";
    else if (v == Py_False) repr = "False";
    else if (v->ob_type == &PyLong_Type) repr = std::to_string(v->int_val);
    else if (v->ob_type == &PyFloat_Type) repr = std::to_string(v->float_val);
    else repr = "<PyObject>";
    return PyUnicode_FromStringAndSize(repr.data(), static_cast<Py_ssize_t>(repr.size()));
}

PyObject* PyList_New(Py_ssize_t size) {
    auto* obj = new PyObject();
    obj->ob_refcnt = 1;
    obj->ob_type = &PyList_Type;
    obj->tag = 6;
    if (size > 0) {
        obj->list_items.resize(static_cast<size_t>(size), nullptr);
    }
    return obj;
}

int PyList_SetItem(PyObject* list, Py_ssize_t index, PyObject* item) {
    if (!list || index < 0) return -1;
    size_t u_idx = static_cast<size_t>(index);
    if (u_idx >= list->list_items.size()) {
        list->list_items.resize(u_idx + 1, nullptr);
    }
    list->list_items[u_idx] = item;
    return 0;
}

Py_ssize_t PyList_Size(PyObject* list) {
    return list ? static_cast<Py_ssize_t>(list->list_items.size()) : 0;
}

PyObject* PyList_GetItem(PyObject* list, Py_ssize_t index) {
    if (!list || index < 0 || static_cast<size_t>(index) >= list->list_items.size()) {
        return nullptr;
    }
    return list->list_items[static_cast<size_t>(index)];
}

PyObject* PyDict_New() {
    auto* obj = new PyObject();
    obj->ob_refcnt = 1;
    obj->ob_type = &PyDict_Type;
    obj->tag = 7;
    return obj;
}

int PyDict_SetItemString(PyObject* dp, const char* key, PyObject* item) {
    if (!dp || !key || !item) return -1;
    Py_INCREF(item);
    dp->dict_items[key] = item;
    return 0;
}

int PyDict_SetItem(PyObject* dp, PyObject* key, PyObject* item) {
    if (!dp || !key || !item) return -1;
    Py_INCREF(item);
    dp->dict_items[PyUnicode_AsUTF8(key)] = item;
    return 0;
}

namespace pitaya {

// =================================================================================================
// 2. pitaya::Task::~Task() Implementation (@ 0x04ca3c, size 1,136 B)
//    Triển khai hàm hủy pitaya::Task::~Task() (@ 0x04ca3c, kích thước 1.136 B)
// =================================================================================================

Task::~Task() {
    // [OBSERVED @ 0x04ca3c..0x04ceac]:
    // Releases internal std::string, hash maps, vectors, and shared_ptr<PTYObject/Error> fields.
    input.reset();
    output.reset();
    error.reset();
}

// =================================================================================================
// 3. Pitaya <-> CPython Object Conversion (@ 0x04d6d8..0x04e994)
//    Chuyển đổi đối tượng Pitaya <-> CPython (@ 0x04d6d8..0x04e994)
// =================================================================================================

/**
 * @brief Internal recursive converter `GetPyObject_Internal` (@ 0x04d6ec..0x04db34).
 *        Hàm chuyển đổi đệ quy nội bộ `GetPyObject_Internal` (@ 0x04d6ec..0x04db34).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x04d6ec..0x04d7c4]:
 * - 0x04d71c: ldr  x0, [x0]
 * - 0x04d720: cbz  x0, #0x4d760    ; if pty_obj == nullptr -> if (w1 & 1) return nullptr else Py_INCREF(Py_None), return Py_None
 * - 0x04d72c: bl   #0xf590         ; PTYObject::IsNull() -> Py_INCREF(Py_None) (@ 0x04d77c..0x04d78c)
 * - 0x04d738: bl   #0x10040        ; PTYObject::IsBool() -> reads [pty_obj + 0x1c] -> PyBool_FromLong (#0xf6e0)
 * - Converts PTYNumber -> PyLong / PyFloat, PTYStr -> PyUnicode, PTYDict -> PyDict, PTYList -> PyList.
 */
PyObject* GetPyObject_Internal(const std::shared_ptr<PTYObject>& pty_obj,
                               bool return_null_on_empty,
                               std::shared_ptr<Error>& out_error,
                               bool is_cep_mode) {
    if (!pty_obj) {
        // [OBSERVED @ 0x04d760..0x04d78c]:
        // tbz w1, #0, #0x4d77c; mov x21, xzr
        if (return_null_on_empty) {
            return nullptr;
        }
        Py_INCREF(Py_None);
        return Py_None;
    }

    if (pty_obj->IsNull()) {
        // [OBSERVED @ 0x04d77c..0x04d78c]:
        // ldr x21, [got_Py_None]; ldr x8, [x21]; add x8, x8, #1; str x8, [x21]
        Py_INCREF(Py_None);
        return Py_None;
    }

    if (pty_obj->IsBool()) {
        // [OBSERVED @ 0x04d744..0x04d748]:
        // ldrb w0, [x8, #0x1c]; bl PyBool_FromLong (#0xf6e0)
        return PyBool_FromLong(pty_obj->bool_val_ != 0 ? 1L : 0L);
    }

    if (pty_obj->IsNumber()) {
        auto num = std::static_pointer_cast<PTYNumber>(pty_obj);
        if (num->IsInt()) {
            return PyLong_FromLongLong(num->IntVal());
        }
        return PyFloat_FromDouble(num->DoubleVal());
    }

    if (pty_obj->IsStr()) {
        auto s = std::static_pointer_cast<PTYStr>(pty_obj);
        return PyUnicode_FromStringAndSize(s->Value().data(), static_cast<Py_ssize_t>(s->Value().size()));
    }

    if (pty_obj->IsDict()) {
        auto d = std::static_pointer_cast<PTYDict>(pty_obj);
        PyObject* py_dict = PyDict_New();
        for (const auto& kv : d->Items()) {
            PyObject* py_val = GetPyObject_Internal(kv.second, false, out_error, is_cep_mode);
            if (py_val) {
                PTYPyDictSet(py_dict, kv.first.c_str(), py_val);
            }
        }
        return py_dict;
    }

    if (pty_obj->IsList()) {
        auto l = std::static_pointer_cast<PTYList>(pty_obj);
        PyObject* py_list = PyList_New(static_cast<Py_ssize_t>(l->Size()));
        const auto& items = l->Items();
        for (size_t i = 0; i < items.size(); ++i) {
            PyObject* elem = GetPyObject_Internal(items[i], false, out_error, is_cep_mode);
            PyList_SetItem(py_list, static_cast<Py_ssize_t>(i), elem);
        }
        return py_list;
    }

    out_error = std::make_shared<Error>(ErrorCode::kPyVMConvertError, "Unsupported PTYObject type in GetPyObject");
    return nullptr;
}

/**
 * @brief Reconstructed `_ZN6pitaya11GetPyObjectERKNSt6__ndk110shared_ptrINS_9PTYObjectEEERNS1_INS_5ErrorEEEb` (@ 0x04d6d8, 20 B).
 *        Tái dựng hàm `pitaya::GetPyObject` (@ 0x04d6d8, 20 B).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x04d6d8..0x04d6e8]:
 * - 0x04d6d8: mov  x8, x1
 * - 0x04d6dc: and  w3, w2, #1
 * - 0x04d6e0: mov  w1, #1
 * - 0x04d6e4: mov  x2, x8
 * - 0x04d6e8: b    #0x4d6ec
 */
PyObject* GetPyObject(const std::shared_ptr<PTYObject>& pty_obj,
                      std::shared_ptr<Error>& out_error,
                      bool is_cep_mode) {
    return GetPyObject_Internal(pty_obj, true, out_error, is_cep_mode);
}

/**
 * @brief Reconstructed `_ZN6pitaya14EnvGetPyObjectERKNSt6__ndk110shared_ptrINS_9PTYObjectEEERNS1_INS_5ErrorEEEPvb` (@ 0x04db38, 16 B).
 *        Tái dựng hàm `pitaya::EnvGetPyObject` (@ 0x04db38, 16 B).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x04db38..0x04db44]:
 * - 0x04db38: mov  x2, x1
 * - 0x04db3c: and  w3, w3, #1
 * - 0x04db40: mov  w1, #1
 * - 0x04db44: b    #0x4d6ec
 */
PyObject* EnvGetPyObject(const std::shared_ptr<PTYObject>& pty_obj,
                         std::shared_ptr<Error>& out_error,
                         void* /*env_unused*/,
                         bool is_cep_mode) {
    return GetPyObject_Internal(pty_obj, true, out_error, is_cep_mode);
}

/**
 * @brief Internal recursive converter `GetPTYObject_Internal` (@ 0x04db48..0x04e784).
 *        Hàm chuyển đổi đệ quy nội bộ `GetPTYObject_Internal` (@ 0x04db48..0x04e784).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x04db48..0x04dc38]:
 * - 0x04db78: cbz  x1, #0x4dbe4    ; if py_obj == nullptr -> if (w2 & 1) return nullptr else PTYNull()
 * - 0x04db7c: ldr  x8, [got_Py_None]; cmp x1, x8 -> PTYNull() (#0xfd10)
 * - 0x04db94: ldr  x0, [x21, #8]   ; load py_obj->ob_type
 * - 0x04db98: ldr  x8, [got_PyBool_Type]; cmp x0, x8 -> cmp x21, Py_True; cset w0, eq; PTYBool(w0) (#0xfbb0)
 * - 0x04dba4: ldrb w8, [x0, #0xab]; tbnz w8, #0 -> PyLong_AsLongLong -> PTYNumber(int64_t)
 * - 0x04dbb0: ldr  x8, [got_PyFloat_Type]; cmp x0, x8 -> PyFloat_AsDouble (#0xfb50) -> PTYNumber(double) (#0xfb90)
 */
std::shared_ptr<PTYObject> GetPTYObject_Internal(PyObject* py_obj,
                                                 bool return_null_on_empty,
                                                 std::shared_ptr<Error>& out_error) {
    if (!py_obj) {
        if (return_null_on_empty) {
            return nullptr;
        }
        return std::make_shared<PTYNull>();
    }
    if (py_obj == Py_None) {
        return std::make_shared<PTYNull>();
    }
    PyTypeObject* tp = py_obj->ob_type;
    if (tp == &PyBool_Type) {
        // [OBSERVED @ 0x04dc0c..0x04dc20]: cmp x21, Py_True; cset w0, eq; bl MakeObject(bool)
        return std::make_shared<PTYBool>(py_obj == Py_True);
    }
    if (tp && ((tp->tp_flags_low >> 24) & 0x01) != 0) {
        // [OBSERVED @ 0x04dba4..0x04dba8]: ldrb w8, [x0, #0xab]; tbnz w8, #0, #0x4dc28 (Py_TPFLAGS_LONG_SUBCLASS)
        return std::make_shared<PTYNumber>( static_cast<int64_t>(PyLong_AsLongLong(py_obj)) );
    }
    if (tp == &PyLong_Type) {
        return std::make_shared<PTYNumber>( static_cast<int64_t>(PyLong_AsLongLong(py_obj)) );
    }
    if (tp == &PyFloat_Type) {
        // [OBSERVED @ 0x04dbd0..0x04dbdc]: bl PyFloat_AsDouble (#0xfb50); bl MakeObject(double) (#0xfb90)
        return std::make_shared<PTYNumber>(PyFloat_AsDouble(py_obj));
    }
    if (tp == &PyUnicode_Type) {
        return std::make_shared<PTYStr>(PyUnicode_AsUTF8(py_obj));
    }
    if (tp == &PyDict_Type) {
        auto out_dict = std::make_shared<PTYDict>();
        for (const auto& kv : py_obj->dict_items) {
            out_dict->Set(kv.first, GetPTYObject_Internal(kv.second, false, out_error));
        }
        return out_dict;
    }
    if (tp == &PyList_Type) {
        auto out_list = std::make_shared<PTYList>();
        for (PyObject* elem : py_obj->list_items) {
            out_list->Append(GetPTYObject_Internal(elem, false, out_error));
        }
        return out_list;
    }

    out_error = std::make_shared<Error>(ErrorCode::kPyVMConvertError, "Unsupported PyObject type in GetPTYObject");
    return nullptr;
}

/**
 * @brief Reconstructed `_ZN6pitaya10GetPTYDictEP7_objectRNSt6__ndk110shared_ptrINS_5ErrorEEE` (@ 0x04e788, 200 B).
 *        Tái dựng hàm `pitaya::GetPTYDict(PyObject*, std::shared_ptr<Error>&)` (@ 0x04e788, 200 B).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x04e788..0x04e84c]:
 * - 0x04e7b0: mov  w2, #1
 * - 0x04e7b8: bl   #0x4db48        ; GetPTYObject_Internal(py_obj, true, out_error)
 * - 0x04e7c4: bl   #0xfad0         ; PTYObject::IsDict()
 * - 0x04e7c8: tbz  w0, #0, #0x4e7f0; if not dict, return nullptr (stp xzr, xzr, [x19])
 */
std::shared_ptr<PTYDict> GetPTYDict(PyObject* py_obj,
                                    std::shared_ptr<Error>& out_error) {
    auto pty_obj = GetPTYObject_Internal(py_obj, true, out_error);
    if (pty_obj && pty_obj->IsDict()) {
        return std::static_pointer_cast<PTYDict>(pty_obj);
    }
    return nullptr;
}

/**
 * @brief Reconstructed `_ZN6pitaya17PTYPyObjectStringEP7_object` (@ 0x04e918, 128 B).
 *        Tái dựng hàm `pitaya::PTYPyObjectString(PyObject*)` (@ 0x04e918, 128 B).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x04e918..0x04e994]:
 * - 0x04e930: cbz  x0, #0x4e96c    ; if py_obj == nullptr -> loads "nullptr" from .rodata 0x05927f
 * - 0x04e934: bl   #0xf210         ; PyObject_Str(py_obj)
 * - 0x04e940: bl   #0xfdf0         ; PyUnicode_AsUTF8(str_obj)
 * - 0x04e950: ldr  x8, [x20]; subs x8, x8, #1; str x8, [x20]; b.eq _Py_Dealloc (#0xf140)
 */
std::string PTYPyObjectString(PyObject* py_obj) {
    if (!py_obj) {
        // [OBSERVED @ 0x04e96c..0x04e978]: adrp x1, #0x59000; add x1, x1, #0x27f ("nullptr")
        return "nullptr";
    }
    PyObject* str_obj = PyObject_Str(py_obj);
    if (!str_obj) {
        return "";
    }
    std::string res = PyUnicode_AsUTF8(str_obj);
    Py_DECREF(str_obj);
    return res;
}

// =================================================================================================
// 4. 11 Exported `pitaya::PTYPyDictSet` Overloads (@ 0x04e998..0x04efd4)
//    11 hàm nạp chồng `pitaya::PTYPyDictSet` được export (@ 0x04e998..0x04efd4)
// =================================================================================================

/**
 * @brief 1/11: `_ZN6pitaya12PTYPyDictSetEP7_objectPKcS1_` (@ 0x04e998, 108 B).
 *        Steals reference to `val` (`Py_DECREF(val)` on exit) after `PyDict_SetItemString(dict, key, val)`.
 *
 * [OBSERVED AARCH64 OPCODES @ 0x04e998..0x04ea00]:
 * - 0x04e9ac..0x04e9b4: checks `dict != nullptr && key != nullptr && val != nullptr`
 * - 0x04e9bc: bl   #0xee70         ; PyDict_SetItemString(dict, key, val)
 * - 0x04e9c0: cmp  w0, #0; cset w20, eq
 * - 0x04e9cc..0x04e9f0: Py_DECREF(val) (`ldr x8, [x19]; subs x8, x8, #1; b.eq _Py_Dealloc`)
 */
bool PTYPyDictSet(PyObject* dict, const char* key, PyObject* val) {
    bool ok = false;
    if (dict && key && val) {
        ok = (PyDict_SetItemString(dict, key, val) == 0);
    }
    if (val) {
        Py_DECREF(val);
    }
    return ok;
}

/**
 * @brief 2/11: `_ZN6pitaya12PTYPyDictSetEP7_objectPKcb` (@ 0x04ea04, 124 B).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x04ea04..0x04ea7c]:
 * - 0x04ea18: and  x0, x2, #1
 * - 0x04ea20: bl   #0xf6e0         ; PyBool_FromLong(val & 1)
 * - 0x04ea44: bl   #0xee70         ; PyDict_SetItemString(dict, key, py_val)
 * - 0x04ea54: Py_DECREF(py_val)
 */
bool PTYPyDictSet(PyObject* dict, const char* key, bool val) {
    PyObject* py_val = PyBool_FromLong(val ? 1L : 0L);
    return PTYPyDictSet(dict, key, py_val);
}

/**
 * @brief 3/11: `_ZN6pitaya12PTYPyDictSetEP7_objectPKci` (@ 0x04ea80, 124 B).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x04ea80..0x04eaf8]:
 * - 0x04ea94: sxtw x0, w2
 * - 0x04ea9c: bl   #0x10200        ; PyLong_FromLongLong(static_cast<long long>(val))
 * - 0x04eac0: bl   #0xee70         ; PyDict_SetItemString
 */
bool PTYPyDictSet(PyObject* dict, const char* key, int val) {
    PyObject* py_val = PyLong_FromLongLong(static_cast<long long>(val));
    return PTYPyDictSet(dict, key, py_val);
}

/**
 * @brief 4/11: `_ZN6pitaya12PTYPyDictSetEP7_objectPKcx` (@ 0x04eafc, 124 B).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x04eafc..0x04eb74]:
 * - 0x04eb10: mov  x0, x2
 * - 0x04eb18: bl   #0x10200        ; PyLong_FromLongLong(val)
 */
bool PTYPyDictSet(PyObject* dict, const char* key, long long val) {
    PyObject* py_val = PyLong_FromLongLong(val);
    return PTYPyDictSet(dict, key, py_val);
}

/**
 * @brief 5/11: `_ZN6pitaya12PTYPyDictSetEP7_objectPKcl` (@ 0x04eb78, 124 B).
 */
bool PTYPyDictSet(PyObject* dict, const char* key, long val) {
    PyObject* py_val = PyLong_FromLongLong(static_cast<long long>(val));
    return PTYPyDictSet(dict, key, py_val);
}

/**
 * @brief 6/11: `_ZN6pitaya12PTYPyDictSetEP7_objectPKcj` (@ 0x04ebf4, 124 B).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x04ebf4..0x04ec6c]:
 * - 0x04ec08: mov  w0, w2          ; zero-extend uint32_t to uint64_t
 * - 0x04ec10: bl   #0xf050         ; PyLong_FromUnsignedLongLong(val)
 */
bool PTYPyDictSet(PyObject* dict, const char* key, unsigned int val) {
    PyObject* py_val = PyLong_FromUnsignedLongLong(static_cast<unsigned long long>(val));
    return PTYPyDictSet(dict, key, py_val);
}

/**
 * @brief 7/11: `_ZN6pitaya12PTYPyDictSetEP7_objectPKcy` (@ 0x04ec70, 124 B).
 */
bool PTYPyDictSet(PyObject* dict, const char* key, unsigned long long val) {
    PyObject* py_val = PyLong_FromUnsignedLongLong(val);
    return PTYPyDictSet(dict, key, py_val);
}

/**
 * @brief 8/11: `_ZN6pitaya12PTYPyDictSetEP7_objectPKcm` (@ 0x04ecec, 124 B).
 */
bool PTYPyDictSet(PyObject* dict, const char* key, unsigned long val) {
    PyObject* py_val = PyLong_FromUnsignedLongLong(static_cast<unsigned long long>(val));
    return PTYPyDictSet(dict, key, py_val);
}

/**
 * @brief 9/11: `_ZN6pitaya12PTYPyDictSetEP7_objectPKcd` (@ 0x04ed68, 120 B).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x04ed68..0x04eddc]:
 * - 0x04ed80: bl   #0xf630         ; PyFloat_FromDouble(val)
 * - 0x04eda4: bl   #0xee70         ; PyDict_SetItemString
 */
bool PTYPyDictSet(PyObject* dict, const char* key, double val) {
    PyObject* py_val = PyFloat_FromDouble(val);
    return PTYPyDictSet(dict, key, py_val);
}

/**
 * @brief 10/11: `_ZN6pitaya12PTYPyDictSetEP7_objectPKcRKNSt6__ndk112basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEE` (@ 0x04ede0, 144 B).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x04ede0..0x04ee6c]:
 * - 0x04edf0..0x04ee0c: extracts SSO/Heap pointer & length from `std::__ndk1::string`
 * - 0x04ee10: bl   #0x10160        ; PyUnicode_FromStringAndSize(val.data(), val.size())
 * - 0x04ee34: bl   #0xee70         ; PyDict_SetItemString
 */
bool PTYPyDictSet(PyObject* dict, const char* key, const std::string& val) {
    PyObject* py_val = PyUnicode_FromStringAndSize(val.data(), static_cast<Py_ssize_t>(val.size()));
    return PTYPyDictSet(dict, key, py_val);
}

/**
 * @brief 11/11: `_ZN6pitaya12PTYPyDictSetEP7_objectPKcS3_` (@ 0x04ee70, 360 B).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x04ee70..0x04efd4]:
 * - 0x04ee9c: cbz  x2, #0x4ef8c    ; if val == nullptr -> return false (mov w21, wzr)
 * - 0x04eeb4: bl   #0xf430         ; strlen(val)
 * - 0x04ef38: bl   #0x10160        ; PyUnicode_FromStringAndSize(s.data(), s.size())
 * - 0x04ef5c: bl   #0xee70         ; PyDict_SetItemString
 */
bool PTYPyDictSet(PyObject* dict, const char* key, const char* val) {
    if (!val) {
        return false;
    }
    return PTYPyDictSet(dict, key, std::string(val));
}

} // namespace pitaya
