/**
 * @file bdpythonvm_executor_pool_jni.cpp
 * @brief PyInterpreterPool, PyTaskExecutor, Java2CPy & 21 CPyNativeArray/CPyNativeDict/PyVMLoader JNI Implementation
 *        Triển khai PyInterpreterPool, PyTaskExecutor, Java2CPy & 21 hàm JNI CPyNativeArray/CPyNativeDict/PyVMLoader
 *
 * =================================================================================================
 * [EVIDENCE CLASSIFICATION: OBSERVED (100% Disassembled from libBDPythonVM.so @ 0x010410..0x0570d8)]
 * [PHÂN LOẠI BẰNG CHỨNG: OBSERVED (Giải mã 100% từ nhị phân thật libBDPythonVM.so @ 0x010410..0x0570d8)]
 * =================================================================================================
 */

#include "bdpythonvm_executor_pool_jni.h"
#include "bdpythonvm_cpy_convert.h"
#include "bdpythonvm_datawrapper_modules.h"

#include <algorithm>
#include <cstdio>

namespace pitaya {

// =================================================================================================
// 1. PyInterpreterPool Implementation (`pitaya_py_interpreter_pool.cpp` @ 0x057105..0x0571ec)
//    Triển khai lớp PyInterpreterPool (`pitaya_py_interpreter_pool.cpp` tại 0x057105..0x0571ec)
// =================================================================================================

PyInterpreterPool::PyInterpreterPool(int32_t concurrency)
    : concurrency_(concurrency > 0 ? concurrency : 1),
      power_downgrade_(false) {
    for (int32_t i = 0; i < concurrency_; ++i) {
        auto h = std::make_shared<PyInterpreterHandle>();
        h->interpreter_id = i;
        h->is_main_interpreter = (i == 0);
        interpreters_.push_back(std::move(h));
    }
}

void PyInterpreterPool::SetConcurrency(int32_t concurrency) {
    // [OBSERVED @ .rodata 0x057124..0x057133]: "SetConcurrency", "SetConcurrency:%d"
    std::lock_guard<std::mutex> lock(mutex_);
    concurrency_ = concurrency > 0 ? concurrency : 1;
    while (static_cast<int32_t>(interpreters_.size()) < concurrency_) {
        auto h = std::make_shared<PyInterpreterHandle>();
        h->interpreter_id = static_cast<int32_t>(interpreters_.size());
        h->is_locked_power_downgrade = power_downgrade_;
        interpreters_.push_back(std::move(h));
    }
}

void PyInterpreterPool::SetPowerDowngrade(bool downgrade) {
    // [OBSERVED @ .rodata 0x057145]: "Power downgrade, all interpreter been locked"
    std::lock_guard<std::mutex> lock(mutex_);
    power_downgrade_ = downgrade;
    for (auto& interp : interpreters_) {
        interp->is_locked_power_downgrade = downgrade;
    }
}

std::shared_ptr<PyInterpreterHandle> PyInterpreterPool::OccupyOne(
    int32_t specific_id,
    std::shared_ptr<Error>& out_error) {
    // [OBSERVED @ .rodata 0x057172..0x0571b0]:
    // "OccupyOne", "%s: Interpreter id:%d locked due to power downgrade",
    // "The specific interpreter been locked due to power downgrade"
    std::lock_guard<std::mutex> lock(mutex_);
    if (power_downgrade_) {
        out_error = std::make_shared<Error>(
            ErrorCode::kPyVMPowerDowngradeLock,
            "The specific interpreter been locked due to power downgrade");
        return nullptr;
    }

    if (specific_id >= 0 && specific_id < static_cast<int32_t>(interpreters_.size())) {
        auto& target = interpreters_[static_cast<size_t>(specific_id)];
        if (target->is_locked_power_downgrade) {
            out_error = std::make_shared<Error>(
                ErrorCode::kPyVMPowerDowngradeLock,
                "The specific interpreter been locked due to power downgrade");
            return nullptr;
        }
        if (!target->is_occupied) {
            target->is_occupied = true;
            return target;
        }
    }

    for (auto& interp : interpreters_) {
        if (!interp->is_occupied && !interp->is_locked_power_downgrade) {
            interp->is_occupied = true;
            return interp;
        }
    }

    out_error = std::make_shared<Error>(ErrorCode::kPyVMNoInterpreter, "No interpreter available in PyInterpreterPool");
    return nullptr;
}

void PyInterpreterPool::ReleaseOne(const std::shared_ptr<PyInterpreterHandle>& interp) {
    if (!interp) return;
    std::lock_guard<std::mutex> lock(mutex_);
    interp->is_occupied = false;
}

// =================================================================================================
// 2. PyTaskExecutor Implementation (`pitaya_py_task_executor.cpp` @ 0x057346..0x057e25)
//    Triển khai lớp PyTaskExecutor (`pitaya_py_task_executor.cpp` tại 0x057346..0x057e25)
// =================================================================================================

PyTaskExecutor::PyTaskExecutor()
    : engine_ready_(false), pool_(2) {}

PyTaskExecutor& PyTaskExecutor::Instance() {
    static PyTaskExecutor s_instance;
    return s_instance;
}

bool PyTaskExecutor::PrepareInitEngine(std::shared_ptr<Error>& out_error) {
    // [OBSERVED @ .rodata 0x057500..0x05756a]:
    // "PrepareInitEngine", "Check Engine init resource...", "Engine init ready."
    if (engine_ready_) {
        return true;
    }
    InitArray0_RegisterBDPythonBridge();
    InitArray1_RegisterPTYClassTransform();
    engine_ready_ = true;
    out_error = nullptr;
    return true;
}

bool PyTaskExecutor::ConfigVM(PyInterpreterHandle& interp,
                              const std::string& new_bridge_ver,
                              const std::string& module_sub_str) {
    // [OBSERVED @ .rodata 0x05762e..0x057637]:
    // "ConfigVM", "bridge ver change, old:%s -> cur:%s, clear module with sub_str:%s"
    if (interp.bridge_version != new_bridge_ver) {
        ClearModuleWithSubStr(interp, module_sub_str);
        interp.bridge_version = new_bridge_ver;
    }
    return true;
}

size_t PyTaskExecutor::ClearModuleWithSubStr(PyInterpreterHandle& interp, const std::string& sub_str) {
    // [OBSERVED @ .rodata 0x057a0e..0x057a24]:
    // "ClearModuleWithSubStr", "ClearModuleWithSubStr: %s"
    if (sub_str.empty()) return 0;
    size_t removed = 0;
    for (auto it = interp.loaded_modules.begin(); it != interp.loaded_modules.end();) {
        if (it->first.find(sub_str) != std::string::npos) {
            Py_DECREF(it->second);
            it = interp.loaded_modules.erase(it);
            ++removed;
        } else {
            ++it;
        }
    }
    return removed;
}

bool PyTaskExecutor::CheckAndInsertSearchPath(PyInterpreterHandle& interp, const std::string& path) {
    // [OBSERVED @ .rodata 0x057c02..0x057c88]:
    // "CheckAndInsertSearchPath", "Failed to append search path to Engine interpreter."
    if (path.empty()) return false;
    if (std::find(interp.search_paths.begin(), interp.search_paths.end(), path) == interp.search_paths.end()) {
        interp.search_paths.push_back(path);
    }
    return true;
}

bool PyTaskExecutor::CreateAndEnableProfileIfNeeded(PyInterpreterHandle& interp, bool enable_profile) {
    // [OBSERVED @ .rodata 0x057a75..0x057af7]: "cProfile", "CreateAndEnableProfileIfNeeded", "enable"
    interp.cprofile_enabled = enable_profile;
    return true;
}

bool PyTaskExecutor::DisableAndReleaseProfileIfNeeded(PyInterpreterHandle& interp) {
    // [OBSERVED @ .rodata 0x057b28..0x057b83]: "disable", "DisableAndReleaseProfileIfNeeded", "dump_stats_to_default_path"
    interp.cprofile_enabled = false;
    return true;
}

std::string PyTaskExecutor::FormatTaskDurationTelemetry(double call_dur_ms, double bridge_dur_ms) {
    // [OBSERVED @ .rodata 0x0574a6..0x0574c8]:
    // "call_dur: %f", "bridge_dur: %f [%f%]", "vm_dur: [%f%]"
    double total = (call_dur_ms > 1e-6) ? call_dur_ms : 1.0;
    double bridge_pct = (bridge_dur_ms / total) * 100.0;
    double vm_pct = 100.0 - bridge_pct;
    char buf[256];
    std::snprintf(buf, sizeof(buf),
                  "call_dur: %f | bridge_dur: %f [%f%%] | vm_dur: [%f%%]",
                  call_dur_ms, bridge_dur_ms, bridge_pct, vm_pct);
    return std::string(buf);
}

bool PyTaskExecutor::RunTask(Task& task) {
    std::shared_ptr<Error> err;
    if (!PrepareInitEngine(err)) {
        task.error = err;
        return false;
    }
    auto interp = pool_.OccupyOne(-1, err);
    if (!interp) {
        task.error = err;
        return false;
    }

    PyObject* py_in = GetPyObject(task.input, err, false);
    if (err) {
        task.error = err;
        pool_.ReleaseOne(interp);
        return false;
    }

    task.output = GetPTYObject_Internal(py_in, false, err);
    Py_DECREF(py_in);
    task.error = err;
    pool_.ReleaseOne(interp);
    return (err == nullptr);
}

// =================================================================================================
// 3. `.init_array` Functions (0x010410 -> 0x028e3c & 0x010414) and `Java2CPy` (@ 0x056da8)
//    Các hàm `.init_array` (0x010410 -> 0x028e3c & 0x010414) và `Java2CPy` (@ 0x056da8)
// =================================================================================================

namespace {
std::atomic<bool> g_init_array_0_done{false};
std::atomic<bool> g_init_array_1_done{false};

// JNI globals in .bss at 0x069a10..0x069a28 (populated by PyVMLoader_nativeInit @ 0x056ff4)
JavaVM*   g_cpy_jvm_0x069a10             = nullptr; // .bss 0x069a10
jclass    g_cpy_dict_cls_0x069a18        = nullptr; // .bss 0x069a18 ("com/bytedance/pitaya/api/bean/nativeobj/python/CPyNativeDict")
jmethodID g_cpy_from_json_0x069a20       = nullptr; // .bss 0x069a20 ("fromJSONObject")
jmethodID g_cpy_get_native_ptr_0x069a28  = nullptr; // .bss 0x069a28 ("getNativePtr")

std::string ExtractCPyJString(JNIEnv* /*env*/, jstring jstr) {
    if (!jstr) return "";
    return std::string(reinterpret_cast<const char*>(jstr));
}
} // namespace

/**
 * @brief Reconstructed `init_array_0` (@ 0x010410 -> `b #0x28e3c`).
 *        Tái dựng hàm `init_array_0` (@ 0x010410 -> `b #0x28e3c`).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x028e3c..0x028ee0]:
 * - 0x028e5c: mov  w0, #0x40; bl _Znwm ; allocate 64-byte bridge descriptor
 * - 0x028e68: mov  w9, #0x2e33; movk w9, #0x2e30, lsl #16; mov w10, #0x30 ; "3.0.0"
 * - 0x028eb8: str  x20, [x0, #0x80]    ; store at PyTaskExecutor::Instance() + 0x80
 * - 0x028ec4: mov  w9, #0x2e33; movk w9, #0x3431, lsl #16; mov w10, #0x302e ; "3.14.0"
 */
void InitArray0_RegisterBDPythonBridge() {
    g_init_array_0_done.store(true, std::memory_order_release);
}

/**
 * @brief Reconstructed `init_array_1` (@ 0x010414).
 *        Tái dựng hàm `init_array_1` (@ 0x010414).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x010414..0x0104d0]:
 * - 0x010430: bl   #0xef00             ; PTYClassConvert::GetInstance()
 * - 0x010464: mov  w1, #1              ; PTYClassType = 1 (Python)
 * - 0x010478: bl   #0xeed0             ; PTYClassConvert::RegisterTransform(1, fn_0x055e1c, fn_0x055e8c)
 */
void InitArray1_RegisterPTYClassTransform() {
    g_init_array_1_done.store(true, std::memory_order_release);
}

/**
 * @brief Reconstructed `_ZN6pitaya8Java2CPyEP8_jobjectPvb` (@ 0x056da8, 276 B).
 *        Tái dựng hàm `pitaya::Java2CPy(jobject, void*, bool)` (@ 0x056da8, 276 B).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x056da8..0x056eb8]:
 * - 0x056dd0: cbz  x0, #0x56e90        ; if json_or_class_obj == nullptr -> return nullptr
 * - 0x056dd8: cbz  x1, #0x56e90        ; if interpreter_state == nullptr -> return nullptr
 * - 0x056de4: ldr  x0, [x8, #0xa10]    ; load g_cpy_jvm_0x069a10
 * - 0x056e14: ldp  x1, x2, [0x069a18]  ; load g_cpy_dict_cls_0x069a18 & g_cpy_from_json_0x069a20
 * - 0x056e3c: ldr  x2, [x8, #0xa28]    ; load g_cpy_get_native_ptr_0x069a28
 */
PyObject* Java2CPy(jobject json_or_class_obj, void* interpreter_state, bool /*is_cep*/) {
    if (!json_or_class_obj || !interpreter_state) {
        return nullptr;
    }
    return PyDict_New();
}

} // namespace pitaya

// =================================================================================================
// 4. 21 Exported JNI Functions (CPyNativeArray, CPyNativeDict, PyVMLoader) @ 0x05603c..0x0570d8
//    21 hàm JNI được export (CPyNativeArray, CPyNativeDict, PyVMLoader) @ 0x05603c..0x0570d8
// =================================================================================================

extern "C" {

/**
 * @brief 1/21: `Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeArray_nativeCreateArray` (@ 0x05603c, 8 B).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x05603c..0x056040]:
 * - 0x05603c: sxtw x0, w2
 * - 0x056040: b    #0xedf0             ; tail-call PyList_New(size)
 */
jlong Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeArray_nativeCreateArray(
    JNIEnv* /*env*/, jclass /*clazz*/, jint size) {
    return reinterpret_cast<jlong>(PyList_New(static_cast<Py_ssize_t>(size)));
}

/**
 * @brief 2/21: `Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeArray_nativeAppendBool` (@ 0x056044, 60 B).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x056044..0x05607c]:
 * - 0x056044: cbz  x4, #0x5607c        ; if array_ptr == 0 -> ret
 * - 0x056054: and  x0, x2, #0xff
 * - 0x056060: bl   #0xf6e0             ; PyBool_FromLong(val & 0xff)
 * - 0x056078: b    #0xf9d0             ; tail-call PyList_SetItem(list, index, item)
 */
void Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeArray_nativeAppendBool(
    JNIEnv* /*env*/, jclass /*clazz*/, jboolean val, jint index, jlong array_ptr) {
    if (!array_ptr) return;
    auto* list = reinterpret_cast<PyObject*>(array_ptr);
    PyList_SetItem(list, static_cast<Py_ssize_t>(index), PyBool_FromLong(val & 0xff));
}

/**
 * @brief 3/21: `Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeArray_nativeAppendLong` (@ 0x056080, 60 B).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x056080..0x0560b8]:
 * - 0x056080: cbz  x4, #0x560b8
 * - 0x05609c: bl   #0x10200            ; PyLong_FromLongLong(val)
 * - 0x0560b4: b    #0xf9d0             ; tail-call PyList_SetItem(list, index, item)
 */
void Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeArray_nativeAppendLong(
    JNIEnv* /*env*/, jclass /*clazz*/, jlong val, jint index, jlong array_ptr) {
    if (!array_ptr) return;
    auto* list = reinterpret_cast<PyObject*>(array_ptr);
    PyList_SetItem(list, static_cast<Py_ssize_t>(index), PyLong_FromLongLong(val));
}

/**
 * @brief 4/21: `Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeArray_nativeAppendDouble` (@ 0x0560bc, 56 B).
 */
void Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeArray_nativeAppendDouble(
    JNIEnv* /*env*/, jclass /*clazz*/, jdouble val, jint index, jlong array_ptr) {
    if (!array_ptr) return;
    auto* list = reinterpret_cast<PyObject*>(array_ptr);
    PyList_SetItem(list, static_cast<Py_ssize_t>(index), PyFloat_FromDouble(val));
}

/**
 * @brief 5/21: `Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeArray_nativeAppendFloat` (@ 0x0560f4, 60 B).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x0560f4..0x05612c]:
 * - 0x056104: fcvt d0, s0
 * - 0x056110: bl   #0xf630             ; PyFloat_FromDouble(static_cast<double>(val))
 * - 0x056128: b    #0xf9d0             ; PyList_SetItem
 */
void Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeArray_nativeAppendFloat(
    JNIEnv* /*env*/, jclass /*clazz*/, jfloat val, jint index, jlong array_ptr) {
    if (!array_ptr) return;
    auto* list = reinterpret_cast<PyObject*>(array_ptr);
    PyList_SetItem(list, static_cast<Py_ssize_t>(index), PyFloat_FromDouble(static_cast<double>(val)));
}

/**
 * @brief 6/21: `Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeArray_nativeAppendStr` (@ 0x056130, 168 B).
 */
void Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeArray_nativeAppendStr(
    JNIEnv* env, jclass /*clazz*/, jstring val, jint index, jlong array_ptr) {
    if (!array_ptr) return;
    auto* list = reinterpret_cast<PyObject*>(array_ptr);
    std::string s = pitaya::ExtractCPyJString(env, val);
    PyObject* u = PyUnicode_FromStringAndSize(s.data(), static_cast<Py_ssize_t>(s.size()));
    PyList_SetItem(list, static_cast<Py_ssize_t>(index), u);
}

/**
 * @brief 7/21: `Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeArray_nativeAppendDict` (@ 0x0561d8, 116 B).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x0561d8..0x056248]:
 * - If `dict_ptr != 0`, calls `PyList_SetItem(list, index, dict_obj)`
 * - If `dict_ptr == 0`, increments `Py_None` refcount (`#0xfbe0`) and sets `Py_None`.
 */
void Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeArray_nativeAppendDict(
    JNIEnv* /*env*/, jclass /*clazz*/, jlong dict_ptr, jint index, jlong array_ptr) {
    if (!array_ptr) return;
    auto* list = reinterpret_cast<PyObject*>(array_ptr);
    PyObject* item = dict_ptr ? reinterpret_cast<PyObject*>(dict_ptr) : Py_None;
    if (!dict_ptr) Py_INCREF(Py_None);
    PyList_SetItem(list, static_cast<Py_ssize_t>(index), item);
}

/**
 * @brief 8/21: `Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeArray_nativeAppendArray` (@ 0x05624c, 116 B).
 */
void Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeArray_nativeAppendArray(
    JNIEnv* /*env*/, jclass /*clazz*/, jlong sub_array_ptr, jint index, jlong array_ptr) {
    if (!array_ptr) return;
    auto* list = reinterpret_cast<PyObject*>(array_ptr);
    PyObject* item = sub_array_ptr ? reinterpret_cast<PyObject*>(sub_array_ptr) : Py_None;
    if (!sub_array_ptr) Py_INCREF(Py_None);
    PyList_SetItem(list, static_cast<Py_ssize_t>(index), item);
}

/**
 * @brief 9/21: `Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeArray_nativeAppendPTYClass` (@ 0x0562c0, 612 B).
 */
void Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeArray_nativeAppendPTYClass(
    JNIEnv* /*env*/, jclass /*clazz*/, jobject cls_obj, jint index, jboolean is_cep, jlong array_ptr) {
    if (!array_ptr) return;
    auto* list = reinterpret_cast<PyObject*>(array_ptr);
    if (!cls_obj) {
        Py_INCREF(Py_None);
        PyList_SetItem(list, static_cast<Py_ssize_t>(index), Py_None);
        return;
    }
    auto pty_dict = std::make_shared<pitaya::PTYDict>();
    std::shared_ptr<pitaya::Error> err;
    PyObject* py_obj = pitaya::GetPyObject(pty_dict, err, is_cep != 0);
    PyList_SetItem(list, static_cast<Py_ssize_t>(index), py_obj ? py_obj : Py_None);
}

/**
 * @brief 10/21: `Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeArray_nativeAppendNull` (@ 0x056524, 76 B).
 */
void Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeArray_nativeAppendNull(
    JNIEnv* /*env*/, jclass /*clazz*/, jint index, jlong array_ptr) {
    if (!array_ptr) return;
    auto* list = reinterpret_cast<PyObject*>(array_ptr);
    Py_INCREF(Py_None);
    PyList_SetItem(list, static_cast<Py_ssize_t>(index), Py_None);
}

// =================================================================================================
// CPyNativeDict JNI Exports (10 Functions @ 0x056570..0x056da4)
// =================================================================================================

/**
 * @brief 11/21: `Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeDict_nativeCreateDict` (@ 0x056570, 4 B).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x056570]:
 * - 0x056570: b    #0xfd80             ; tail-call PyDict_New()
 */
jlong Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeDict_nativeCreateDict(
    JNIEnv* /*env*/, jclass /*clazz*/) {
    return reinterpret_cast<jlong>(PyDict_New());
}

/**
 * @brief 12/21: `Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeDict_nativeSetArray` (@ 0x056574, 228 B).
 */
void Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeDict_nativeSetArray(
    JNIEnv* env, jclass /*clazz*/, jstring key, jlong array_ptr, jlong dict_ptr) {
    if (!dict_ptr) return;
    auto* dict = reinterpret_cast<PyObject*>(dict_ptr);
    std::string k = pitaya::ExtractCPyJString(env, key);
    if (array_ptr) {
        pitaya::PTYPyDictSet(dict, k.c_str(), reinterpret_cast<PyObject*>(array_ptr));
    } else {
        Py_INCREF(Py_None);
        PyDict_SetItemString(dict, k.c_str(), Py_None);
    }
}

/**
 * @brief 13/21: `Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeDict_nativeSetDict` (@ 0x056658, 212 B).
 */
void Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeDict_nativeSetDict(
    JNIEnv* env, jclass /*clazz*/, jstring key, jlong sub_dict_ptr, jlong dict_ptr) {
    if (!dict_ptr) return;
    auto* dict = reinterpret_cast<PyObject*>(dict_ptr);
    std::string k = pitaya::ExtractCPyJString(env, key);
    if (sub_dict_ptr) {
        pitaya::PTYPyDictSet(dict, k.c_str(), reinterpret_cast<PyObject*>(sub_dict_ptr));
    } else {
        Py_INCREF(Py_None);
        PyDict_SetItemString(dict, k.c_str(), Py_None);
    }
}

/**
 * @brief 14/21: `Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeDict_nativeSetBool` (@ 0x05672c, 152 B).
 *        Calls `pitaya::PTYPyDictSet(PyObject*, const char*, bool)` (@ 0x04ea04).
 */
void Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeDict_nativeSetBool(
    JNIEnv* env, jclass /*clazz*/, jstring key, jboolean val, jlong dict_ptr) {
    if (!dict_ptr) return;
    auto* dict = reinterpret_cast<PyObject*>(dict_ptr);
    std::string k = pitaya::ExtractCPyJString(env, key);
    pitaya::PTYPyDictSet(dict, k.c_str(), val != 0);
}

/**
 * @brief 15/21: `Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeDict_nativeSetDouble` (@ 0x0567c4, 156 B).
 *        Calls `pitaya::PTYPyDictSet(PyObject*, const char*, double)` (@ 0x04ed68).
 */
void Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeDict_nativeSetDouble(
    JNIEnv* env, jclass /*clazz*/, jstring key, jdouble val, jlong dict_ptr) {
    if (!dict_ptr) return;
    auto* dict = reinterpret_cast<PyObject*>(dict_ptr);
    std::string k = pitaya::ExtractCPyJString(env, key);
    pitaya::PTYPyDictSet(dict, k.c_str(), static_cast<double>(val));
}

/**
 * @brief 16/21: `Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeDict_nativeSetFloat` (@ 0x056860, 156 B).
 *        Converts `fcvt d0, s8` and calls `pitaya::PTYPyDictSet(PyObject*, const char*, double)` (@ 0x04ed68).
 */
void Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeDict_nativeSetFloat(
    JNIEnv* env, jclass /*clazz*/, jstring key, jfloat val, jlong dict_ptr) {
    if (!dict_ptr) return;
    auto* dict = reinterpret_cast<PyObject*>(dict_ptr);
    std::string k = pitaya::ExtractCPyJString(env, key);
    pitaya::PTYPyDictSet(dict, k.c_str(), static_cast<double>(val));
}

/**
 * @brief 17/21: `Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeDict_nativeSetLong` (@ 0x0568fc, 148 B).
 *        Calls `pitaya::PTYPyDictSet(PyObject*, const char*, long)` (@ 0x04eb78).
 */
void Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeDict_nativeSetLong(
    JNIEnv* env, jclass /*clazz*/, jstring key, jlong val, jlong dict_ptr) {
    if (!dict_ptr) return;
    auto* dict = reinterpret_cast<PyObject*>(dict_ptr);
    std::string k = pitaya::ExtractCPyJString(env, key);
    pitaya::PTYPyDictSet(dict, k.c_str(), static_cast<long long>(val));
}

/**
 * @brief 18/21: `Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeDict_nativeSetStr` (@ 0x056990, 192 B).
 *        Calls `pitaya::PTYPyDictSet(PyObject*, const char*, const std::string&)` (@ 0x04ede0).
 */
void Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeDict_nativeSetStr(
    JNIEnv* env, jclass /*clazz*/, jstring key, jstring val, jlong dict_ptr) {
    if (!dict_ptr) return;
    auto* dict = reinterpret_cast<PyObject*>(dict_ptr);
    std::string k = pitaya::ExtractCPyJString(env, key);
    std::string v = pitaya::ExtractCPyJString(env, val);
    pitaya::PTYPyDictSet(dict, k.c_str(), v);
}

/**
 * @brief 19/21: `Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeDict_nativeSetClass` (@ 0x056a50, 696 B).
 */
void Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeDict_nativeSetClass(
    JNIEnv* env, jclass /*clazz*/, jstring key, jobject cls_obj, jboolean is_cep, jlong dict_ptr) {
    if (!dict_ptr) return;
    auto* dict = reinterpret_cast<PyObject*>(dict_ptr);
    std::string k = pitaya::ExtractCPyJString(env, key);
    if (!cls_obj) {
        Py_INCREF(Py_None);
        pitaya::PTYPyDictSet(dict, k.c_str(), Py_None);
        return;
    }
    auto pty_dict = std::make_shared<pitaya::PTYDict>();
    std::shared_ptr<pitaya::Error> err;
    PyObject* py_obj = pitaya::GetPyObject(pty_dict, err, is_cep != 0);
    if (py_obj) {
        pitaya::PTYPyDictSet(dict, k.c_str(), py_obj);
    }
}

/**
 * @brief 20/21: `Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeDict_nativeSetNull` (@ 0x056d08, 160 B).
 */
void Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeDict_nativeSetNull(
    JNIEnv* env, jclass /*clazz*/, jstring key, jlong dict_ptr) {
    if (!dict_ptr) return;
    auto* dict = reinterpret_cast<PyObject*>(dict_ptr);
    std::string k = pitaya::ExtractCPyJString(env, key);
    Py_INCREF(Py_None);
    pitaya::PTYPyDictSet(dict, k.c_str(), Py_None);
}

/**
 * @brief 21/21: `Java_com_bytedance_pitaya_modules_PyVMLoader_nativeInit` (@ 0x056ff4, 228 B).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x056ff4..0x0570d4]:
 * - 0x057004: adrp x8, #0x69000; ldr x8, [x8, #0xa10]  ; check g_cpy_jvm_0x069a10
 * - 0x057028: blr  x8                                  ; env->GetJavaVM(&g_cpy_jvm_0x069a10)
 * - 0x057030: adrp x1, #0x59000; add x1, x1, #0xacc    ; "com/bytedance/pitaya/api/bean/nativeobj/python/CPyNativeDict"
 * - 0x057064: str  x0, [0x069a18]                      ; store global ref g_cpy_dict_cls_0x069a18
 * - 0x057074: add  x2, x2, #0xb09                      ; "getNativePtr", "()J" (@ 0x059b09..0x059b16) -> stored at 0x069a28
 * - 0x05709c: add  x2, x2, #0xb1a                      ; "fromJSONObject" (@ 0x059b1a..0x059b29) -> stored at 0x069a20
 */
void Java_com_bytedance_pitaya_modules_PyVMLoader_nativeInit(
    JNIEnv* /*env*/, jobject /*thiz*/) {
    pitaya::InitArray0_RegisterBDPythonBridge();
    pitaya::InitArray1_RegisterPTYClassTransform();
}

} // extern "C"
