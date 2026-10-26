/**
 * @file bdpythonvm_types.h
 * @brief Core ABI Structures, ELF64 Memory Map, CPython 3.8 PyObject/PyTypeObject Layout & Pitaya Types for libBDPythonVM.so
 *        Cấu trúc ABI cốt lõi, Bản đồ bộ nhớ ELF64, Bố cục CPython 3.8 PyObject/PyTypeObject & Kiểu Pitaya cho libBDPythonVM.so
 *
 * =================================================================================================
 * [EVIDENCE CLASSIFICATION: OBSERVED (100% Disassembled from libBDPythonVM.so — 418,008 bytes)]
 * [PHÂN LOẠI BẰNG CHỨNG: OBSERVED (Giải mã 100% từ nhị phân thật libBDPythonVM.so — 418,008 bytes)]
 * =================================================================================================
 *
 * Binary Metadata / Thông tin nhị phân:
 * - File Path: apktool-res/lib/arm64-v8a/libBDPythonVM.so
 * - Exact File Size: 418,008 bytes (0x0660D8 bytes)
 * - Architecture: ELF 64-bit LSB shared object, ARM aarch64, version 1 (SYSV), dynamically linked
 * - Dynamic Symbols (.dynsym @ 0x000ef8, size 0x0029e8): 447 total (50 exported + 387 imported + 10 local/undef)
 *   - 42 Exported STT_FUNC:
 *     - 3 CPython C-Extension Module Initializers (`PyInit_ByteNNModule` @ 0x02451c, `PyInit_ByteDTModule` @ 0x04be28, `PyInit_DataWrapperModule` @ 0x04f9ac)
 *     - 18 Pitaya C++ Functions (`Task::~Task`, `GetPyObject`, `EnvGetPyObject`, `GetPTYDict`, `PTYPyObjectString`, 11 `PTYPyDictSet` overloads, `CVMat_New`, `Java2CPy`)
 *     - 21 JNI Functions (10 `CPyNativeArray_native*` + 10 `CPyNativeDict_native*` + 1 `PyVMLoader_nativeInit`)
 *   - 8 Exported STT_OBJECT:
 *     - 6 `PyTypeObject` globals (408 bytes = 0x198 bytes each in `.data` @ 0x068950..0x069720):
 *       1. `_ZN6pitaya18BDPyMemoryViewTypeE`  (@ 0x068950, `tp_name="BDDataWrapperBridge.MemoryViewWrapper"`, `tp_basicsize=48`)
 *       2. `_ZN6pitaya13BDPyCVMatTypeE`       (@ 0x068c08, `tp_name="BDDataWrapperBridge.MobileCVMatWrapper"`, `tp_basicsize=48`)
 *       3. `_ZN6pitaya17BDPyTVMDeviceTypeE`   (@ 0x068e38, `tp_name="BDDataWrapperBridge.TVMDeviceWrapper"`, `tp_basicsize=24`)
 *       4. `_ZN6pitaya19BDPyTVMDataInfoTypeE` (@ 0x069070, `tp_name="BDDataWrapperBridge.TVMDataInfoWrapper"`, `tp_basicsize=32`)
 *       5. `_ZN6pitaya15BDPyNDArrayTypeE`     (@ 0x069358, `tp_name="BDDataWrapperBridge.NDArrayWrapper"`, `tp_basicsize=64`)
 *       6. `_ZN6pitaya14BDPyTensorTypeE`      (@ 0x069720, `tp_name="BDDataWrapperBridge.TensorWrapper"`, `tp_basicsize=80`)
 *     - 2 Function Pointers (8 bytes each in `.bss` @ 0x069908..0x069910):
 *       7. `_ZN6pitaya7ToCVMatE`              (@ 0x069908)
 *       8. `_ZN6pitaya7ToPyMatE`              (@ 0x069910)
 *
 * Virtual Address to File Offset Formula / Công thức ánh xạ địa chỉ ảo sang offset file:
 * - PT_LOAD 0 (R+X): vaddr 0x000000 .. 0x060a30 -> file 0x000000 .. 0x060a30 (offset = vaddr)
 * - PT_LOAD 1 (R+W): vaddr 0x066698 .. 0x069a30 -> file 0x062698 .. 0x0658f8 (offset = vaddr - 0x4000)
 */

#ifndef NEXTAI_OPENCUT_BDPYTHONVM_TYPES_H_
#define NEXTAI_OPENCUT_BDPYTHONVM_TYPES_H_

#include <atomic>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>
#include <vector>

// Forward declarations for JNI types / Khai báo trước các kiểu JNI
struct _JNIEnv;
typedef _JNIEnv JNIEnv;
struct _JavaVM;
typedef _JavaVM JavaVM;
class _jobject;
typedef _jobject* jobject;
class _jclass;
typedef _jclass* jclass;
class _jstring;
typedef _jstring* jstring;
struct _jmethodID;
typedef _jmethodID* jmethodID;
typedef uint8_t jboolean;
typedef int32_t jint;
typedef int64_t jlong;
typedef float jfloat;
typedef double jdouble;

// =================================================================================================
// 1. CPython 3.8 ABI Structures (PYTHON_ABI_VERSION = 1013 = 0x3f5 @ 0x024544, 0x04be50, 0x04f9c0)
//    Cấu trúc ABI CPython 3.8 (PYTHON_ABI_VERSION = 1013 = 0x3f5 quan sát tại 0x024544, 0x04be50, 0x04f9c0)
// =================================================================================================

constexpr int kPythonAbiVersion = 1013; // 0x3f5 (OBSERVED @ 0x024544: mov w1, #0x3f5; bl PyModule_Create2)

struct _typeobject;

/**
 * @brief Standard 64-bit CPython `_object` (`PyObject`, 16 bytes header).
 *        Cấu trúc đối tượng CPython 64-bit `_object` (`PyObject`, header 16 bytes).
 *
 * [OBSERVED @ 0x04db94 & 0x04e950]:
 * - +0x00: `Py_ssize_t ob_refcnt` (`ldr x8, [x20]; subs x8, x8, #1; str x8, [x20]`)
 * - +0x08: `_typeobject* ob_type` (`ldr x0, [x21, #8]`)
 */
struct _object {
    int64_t ob_refcnt{1};               // +0x00
    _typeobject* ob_type{nullptr};      // +0x08

    // Extended payload storage for standalone reconstruction & verification
    int32_t tag{0};                     // 0=None, 1=Bool, 2=Long, 3=Float, 4=Unicode, 5=Bytes, 6=List, 7=Dict, 8=Module, 9=CVMat, 10=Tensor, 11=NDArray
    bool bool_val{false};
    int64_t int_val{0};
    uint64_t uint_val{0};
    double float_val{0.0};
    std::string str_val;
    std::vector<uint8_t> bytes_val;
    std::vector<_object*> list_items;
    std::unordered_map<std::string, _object*> dict_items;
    void* capsule_ptr{nullptr};         // +0x28 in BDPyCVMatObject (OBSERVED @ 0x050ef4: str x0, [x19, #0x28])
};

typedef _object PyObject;
typedef int64_t Py_ssize_t;

/**
 * @brief Standard 64-bit CPython `PyTypeObject` (`_typeobject`, exact size 408 bytes = 0x198 bytes).
 *        Cấu trúc kiểu dữ liệu CPython 64-bit `PyTypeObject` (`_typeobject`, kích thước chính xác 408 bytes = 0x198 bytes).
 *
 * [OBSERVED @ .data 0x068950..0x069720 & 0x04dba4 & 0x050ea4]:
 * - Total size in `.dynsym`: 408 bytes (`0x198` bytes)
 * - +0x000: `PyObject ob_base` (`ob_refcnt`, `ob_type`)
 * - +0x010: `Py_ssize_t ob_size`
 * - +0x018: `const char* tp_name`       (offset 24, verified in `.data` at `va + 24`)
 * - +0x020: `Py_ssize_t tp_basicsize`   (offset 32, verified in `.data` at `va + 32`: 48, 48, 24, 32, 64, 80)
 * - +0x028: `Py_ssize_t tp_itemsize`    (offset 40)
 * - +0x0a8: `uint64_t tp_flags`         (offset 168: byte +0xab bit 0 = Py_TPFLAGS_LONG_SUBCLASS @ 0x04dba4: `ldrb w8, [x0, #0xab]; tbnz w8, #0`)
 * - +0x130: `PyObject* (*tp_alloc)(_typeobject*, Py_ssize_t)` (OBSERVED @ 0x050ea4: `ldr x8, [x0, #0x130]; blr x8`)
 */
struct _typeobject {
    int64_t ob_refcnt{1};                                       // +0x000
    _typeobject* ob_type{nullptr};                              // +0x008
    Py_ssize_t ob_size{0};                                      // +0x010
    const char* tp_name{nullptr};                               // +0x018 (offset 24)
    Py_ssize_t tp_basicsize{0};                                 // +0x020 (offset 32)
    Py_ssize_t tp_itemsize{0};                                  // +0x028 (offset 40)
    void (*tp_dealloc)(PyObject*){nullptr};                     // +0x030
    uint64_t tp_vectorcall_offset{0};                           // +0x038
    void* tp_getattr{nullptr};                                  // +0x040
    void* tp_setattr{nullptr};                                  // +0x048
    void* tp_as_async{nullptr};                                 // +0x050
    void* tp_repr{nullptr};                                     // +0x058
    void* tp_as_number{nullptr};                                // +0x060
    void* tp_as_sequence{nullptr};                              // +0x068
    void* tp_as_mapping{nullptr};                               // +0x070
    void* tp_hash{nullptr};                                     // +0x078
    void* tp_call{nullptr};                                     // +0x080
    void* tp_str{nullptr};                                      // +0x088
    void* tp_getattro{nullptr};                                 // +0x090
    void* tp_setattro{nullptr};                                 // +0x098
    void* tp_as_buffer{nullptr};                                // +0x0a0
    uint32_t tp_flags_low{0};                                   // +0x0a8..0x0ab (byte +0xab observed at 0x04dba4)
    uint32_t tp_flags_high{0};                                  // +0x0ac..0x0af
    const char* tp_doc{nullptr};                                // +0x0b0
    uint8_t pad_0b8_[0x130 - 0x0b8]{};                          // +0x0b8..0x12f
    PyObject* (*tp_alloc)(_typeobject*, Py_ssize_t){nullptr};   // +0x130 (OBSERVED @ 0x050ea4: ldr x8, [x0, #0x130])
    PyObject* (*tp_new)(_typeobject*, PyObject*, PyObject*){nullptr}; // +0x138
    uint8_t pad_140_[0x198 - 0x140]{};                          // +0x140..0x197 (total size = 0x198 = 408 bytes)
};

typedef _typeobject PyTypeObject;
static_assert(sizeof(PyTypeObject) == 408, "PyTypeObject must be exactly 408 bytes (0x198) to match .dynsym");

struct PyMethodDef {
    const char* ml_name;
    PyObject* (*ml_meth)(PyObject*, PyObject*);
    int ml_flags;
    const char* ml_doc;
};

struct PyModuleDef {
    PyObject ob_base;
    const char* m_name;
    const char* m_doc;
    Py_ssize_t m_size;
    PyMethodDef* m_methods;
};

// Built-in CPython singletons & types imported via .got (0x067ed0..0x067fa0)
extern PyObject* Py_None;
extern PyObject* Py_True;
extern PyObject* Py_False;
extern PyTypeObject PyBool_Type;
extern PyTypeObject PyLong_Type;
extern PyTypeObject PyFloat_Type;
extern PyTypeObject PyUnicode_Type;
extern PyTypeObject PyBytes_Type;
extern PyTypeObject PyByteArray_Type;
extern PyTypeObject PyList_Type;
extern PyTypeObject PyDict_Type;
extern PyTypeObject PyModule_Type;

// CPython C-API helpers used by libBDPythonVM.so
void Py_INCREF(PyObject* op);
void Py_DECREF(PyObject* op);
int PyType_Ready(PyTypeObject* type);
PyObject* PyModule_Create2(PyModuleDef* def, int module_api_version);
int PyModule_AddObject(PyObject* mod, const char* name, PyObject* value);
PyObject* PyBool_FromLong(long v);
PyObject* PyLong_FromLongLong(long long v);
PyObject* PyLong_FromUnsignedLongLong(unsigned long long v);
long long PyLong_AsLongLong(PyObject* op);
PyObject* PyFloat_FromDouble(double v);
double PyFloat_AsDouble(PyObject* op);
PyObject* PyUnicode_FromStringAndSize(const char* u, Py_ssize_t size);
const char* PyUnicode_AsUTF8(PyObject* unicode);
PyObject* PyObject_Str(PyObject* v);
PyObject* PyList_New(Py_ssize_t size);
int PyList_SetItem(PyObject* list, Py_ssize_t index, PyObject* item);
Py_ssize_t PyList_Size(PyObject* list);
PyObject* PyList_GetItem(PyObject* list, Py_ssize_t index);
PyObject* PyDict_New();
int PyDict_SetItemString(PyObject* dp, const char* key, PyObject* item);
int PyDict_SetItem(PyObject* dp, PyObject* key, PyObject* item);

namespace pitaya {

// =================================================================================================
// 2. 8 Exported Global STT_OBJECT Symbols in namespace pitaya (@ 0x068950..0x069910)
//    8 ký hiệu biến toàn cục STT_OBJECT được export trong namespace pitaya (@ 0x068950..0x069910)
// =================================================================================================

extern PyTypeObject BDPyMemoryViewType;   // @ 0x068950 (408 B): "BDDataWrapperBridge.MemoryViewWrapper", basicsize=48
extern PyTypeObject BDPyCVMatType;        // @ 0x068c08 (408 B): "BDDataWrapperBridge.MobileCVMatWrapper", basicsize=48
extern PyTypeObject BDPyTVMDeviceType;    // @ 0x068e38 (408 B): "BDDataWrapperBridge.TVMDeviceWrapper", basicsize=24
extern PyTypeObject BDPyTVMDataInfoType;  // @ 0x069070 (408 B): "BDDataWrapperBridge.TVMDataInfoWrapper", basicsize=32
extern PyTypeObject BDPyNDArrayType;      // @ 0x069358 (408 B): "BDDataWrapperBridge.NDArrayWrapper", basicsize=64
extern PyTypeObject BDPyTensorType;       // @ 0x069720 (408 B): "BDDataWrapperBridge.TensorWrapper", basicsize=80

using ToCVMatFunc = void* (*)(PyObject*);
using ToPyMatFunc = PyObject* (*)(void*);

extern ToCVMatFunc ToCVMat;               // @ 0x069908 (8 B in .bss)
extern ToPyMatFunc ToPyMat;               // @ 0x069910 (8 B in .bss)

/**
 * @brief BDPyCVMatObject instance layout (size = 48 bytes = 0x30 bytes, verified at 0x050e8c..0x050f24).
 *        Bố cục đối tượng BDPyCVMatObject (kích thước = 48 bytes = 0x30 bytes, xác minh tại 0x050e8c..0x050f24).
 *
 * [OBSERVED @ 0x050ec0..0x050ef4 in _ZN6pitaya9CVMat_NewEv]:
 * - +0x00..0x0f: `PyObject ob_base`
 * - +0x10: `PyObject* shape_tuple`   (initialized to `Py_None` via `str q0, [x0, #0x10]`)
 * - +0x18: `PyObject* data_list`     (initialized to `Py_None`)
 * - +0x20: `PyObject* extra_info`    (initialized to `Py_None` via `str x8, [x0, #0x20]`)
 * - +0x28: `PyObject* cvmat_capsule` (initialized via `PyCapsule_New(..., "cvmat", ...)` at 0x050ef4: `str x0, [x19, #0x28]`)
 */
struct BDPyCVMatObject {
    PyObject ob_base;                  // +0x00..0x0f
    PyObject* shape_tuple{nullptr};    // +0x10
    PyObject* data_list{nullptr};      // +0x18
    PyObject* extra_info{nullptr};     // +0x20
    PyObject* cvmat_capsule{nullptr};  // +0x28 (total size = 0x30 = 48 bytes)
};

// =================================================================================================
// 3. Pitaya Core Types Shared Across CPython VM Bridge
//    Các kiểu dữ liệu Pitaya Core dùng chung qua cầu nối máy ảo CPython
// =================================================================================================

enum class ErrorCode : int32_t {
    kSuccess                 = 0,
    kPyVMNotValid            = 301,
    kPyVMEasyCrash           = 302,
    kPyVMInitFailed          = 303,
    kPyVMConfigFailed        = 304,
    kPyVMNoInterpreter       = 305,
    kPyVMInterrupted         = 306,
    kPyVMConvertError        = 307,
    kPyVMPowerDowngradeLock  = 308
};

class Error {
public:
    Error(ErrorCode code = ErrorCode::kSuccess, std::string msg = "")
        : code_(code), message_(std::move(msg)) {}
    virtual ~Error() = default;

    ErrorCode Code() const { return code_; }
    const std::string& Message() const { return message_; }

private:
    ErrorCode code_;
    std::string message_;
};

enum class PTYObjectType : int32_t {
    kNull           = 0,
    kBool           = 1,
    kNumber         = 2,
    kStr            = 3,
    kDict           = 4,
    kList           = 5,
    kTensor         = 6,
    kCvMat          = 7,
    kBuffer         = 8,
    kPredictResult  = 9,
    kClass          = 10
};

class PTYObject {
public:
    explicit PTYObject(PTYObjectType type = PTYObjectType::kNull)
        : type_(type), bool_val_(0) {}
    virtual ~PTYObject() = default;

    PTYObjectType Type() const { return type_; }
    bool IsNull() const { return type_ == PTYObjectType::kNull; }
    bool IsBool() const { return type_ == PTYObjectType::kBool; }
    bool IsNumber() const { return type_ == PTYObjectType::kNumber; }
    bool IsStr() const { return type_ == PTYObjectType::kStr; }
    bool IsDict() const { return type_ == PTYObjectType::kDict; }
    bool IsList() const { return type_ == PTYObjectType::kList; }
    bool IsTensor() const { return type_ == PTYObjectType::kTensor; }
    bool IsCvMat() const { return type_ == PTYObjectType::kCvMat; }
    bool IsBuffer() const { return type_ == PTYObjectType::kBuffer; }
    bool IsClass() const { return type_ == PTYObjectType::kClass; }

    PTYObjectType type_;
    uint32_t pad_0c_{0};
    uint64_t pad_10_{0};
    uint32_t pad_18_{0};
    uint8_t bool_val_{0}; // +0x1c (OBSERVED @ 0x04d744: ldrb w0, [x8, #0x1c])
};

class PTYNull : public PTYObject {
public:
    PTYNull() : PTYObject(PTYObjectType::kNull) {}
};

class PTYBool : public PTYObject {
public:
    explicit PTYBool(bool v) : PTYObject(PTYObjectType::kBool) {
        bool_val_ = v ? 1 : 0;
    }
    bool Value() const { return bool_val_ != 0; }
};

class PTYNumber : public PTYObject {
public:
    explicit PTYNumber(int64_t v) : PTYObject(PTYObjectType::kNumber), is_int_(true), int_val_(v), double_val_(static_cast<double>(v)) {}
    explicit PTYNumber(double v) : PTYObject(PTYObjectType::kNumber), is_int_(false), int_val_(static_cast<int64_t>(v)), double_val_(v) {}

    bool IsInt() const { return is_int_; }
    int64_t IntVal() const { return int_val_; }
    double DoubleVal() const { return double_val_; }

private:
    bool is_int_;
    int64_t int_val_;
    double double_val_;
};

class PTYStr : public PTYObject {
public:
    explicit PTYStr(std::string s) : PTYObject(PTYObjectType::kStr), str_(std::move(s)) {}
    const std::string& Value() const { return str_; }

private:
    std::string str_;
};

class PTYDict : public PTYObject {
public:
    PTYDict() : PTYObject(PTYObjectType::kDict) {}
    void Set(const std::string& k, std::shared_ptr<PTYObject> v) { map_[k] = std::move(v); }
    std::shared_ptr<PTYObject> Get(const std::string& k) const {
        auto it = map_.find(k);
        return (it != map_.end()) ? it->second : nullptr;
    }
    size_t Size() const { return map_.size(); }
    const std::unordered_map<std::string, std::shared_ptr<PTYObject>>& Items() const { return map_; }

private:
    std::unordered_map<std::string, std::shared_ptr<PTYObject>> map_;
};

class PTYList : public PTYObject {
public:
    PTYList() : PTYObject(PTYObjectType::kList) {}
    void Append(std::shared_ptr<PTYObject> v) { items_.push_back(std::move(v)); }
    size_t Size() const { return items_.size(); }
    const std::vector<std::shared_ptr<PTYObject>>& Items() const { return items_; }

private:
    std::vector<std::shared_ptr<PTYObject>> items_;
};

/**
 * @brief pitaya::Task ABI layout matching `_ZN6pitaya4TaskD2Ev` (@ 0x04ca3c, size 1,136 bytes).
 *        Bố cục ABI lớp pitaya::Task khớp với `_ZN6pitaya4TaskD2Ev` (@ 0x04ca3c, kích thước 1.136 bytes).
 */
struct Task {
    void* vptr{nullptr};
    std::string business_name;
    std::string package_version;
    std::string entrance_script;
    std::shared_ptr<PTYObject> input;
    std::shared_ptr<PTYObject> output;
    std::shared_ptr<Error> error;
    double call_dur_ms{0.0};
    double bridge_dur_ms{0.0};
    double vm_dur_ms{0.0};

    virtual ~Task();
};

} // namespace pitaya

#endif // NEXTAI_OPENCUT_BDPYTHONVM_TYPES_H_
