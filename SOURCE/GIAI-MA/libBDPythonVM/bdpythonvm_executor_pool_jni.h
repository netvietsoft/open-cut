/**
 * @file bdpythonvm_executor_pool_jni.h
 * @brief PyInterpreterPool, PyTaskExecutor, Java2CPy & 21 CPyNativeArray/CPyNativeDict/PyVMLoader JNI Header
 *        Header PyInterpreterPool, PyTaskExecutor, Java2CPy & 21 hàm JNI CPyNativeArray/CPyNativeDict/PyVMLoader
 *
 * =================================================================================================
 * [EVIDENCE CLASSIFICATION: OBSERVED (100% Disassembled from libBDPythonVM.so @ 0x010410..0x0570d8)]
 * [PHÂN LOẠI BẰNG CHỨNG: OBSERVED (Giải mã 100% từ nhị phân thật libBDPythonVM.so @ 0x010410..0x0570d8)]
 * =================================================================================================
 *
 * Exported Functions Covered / Các hàm Export được tái dựng trong module này:
 * 1.  _ZN6pitaya8Java2CPyEP8_jobjectPvb                                                                     (@ 0x056da8, 276 B)
 * 2.  Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeArray_nativeCreateArray                  (@ 0x05603c,   8 B)
 * 3.  Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeArray_nativeAppendBool                   (@ 0x056044,  60 B)
 * 4.  Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeArray_nativeAppendLong                   (@ 0x056080,  60 B)
 * 5.  Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeArray_nativeAppendDouble                 (@ 0x0560bc,  56 B)
 * 6.  Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeArray_nativeAppendFloat                  (@ 0x0560f4,  60 B)
 * 7.  Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeArray_nativeAppendStr                    (@ 0x056130, 168 B)
 * 8.  Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeArray_nativeAppendDict                   (@ 0x0561d8, 116 B)
 * 9.  Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeArray_nativeAppendArray                  (@ 0x05624c, 116 B)
 * 10. Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeArray_nativeAppendPTYClass               (@ 0x0562c0, 612 B)
 * 11. Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeArray_nativeAppendNull                   (@ 0x056524,  76 B)
 * 12. Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeDict_nativeCreateDict                    (@ 0x056570,   4 B)
 * 13. Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeDict_nativeSetArray                      (@ 0x056574, 228 B)
 * 14. Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeDict_nativeSetDict                       (@ 0x056658, 212 B)
 * 15. Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeDict_nativeSetBool                       (@ 0x05672c, 152 B)
 * 16. Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeDict_nativeSetDouble                     (@ 0x0567c4, 156 B)
 * 17. Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeDict_nativeSetFloat                      (@ 0x056860, 156 B)
 * 18. Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeDict_nativeSetLong                       (@ 0x0568fc, 148 B)
 * 19. Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeDict_nativeSetStr                        (@ 0x056990, 192 B)
 * 20. Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeDict_nativeSetClass                      (@ 0x056a50, 696 B)
 * 21. Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeDict_nativeSetNull                       (@ 0x056d08, 160 B)
 * 22. Java_com_bytedance_pitaya_modules_PyVMLoader_nativeInit                                               (@ 0x056ff4, 228 B)
 */

#ifndef NEXTAI_OPENCUT_BDPYTHONVM_EXECUTOR_POOL_JNI_H_
#define NEXTAI_OPENCUT_BDPYTHONVM_EXECUTOR_POOL_JNI_H_

#include "bdpythonvm_types.h"

namespace pitaya {

/**
 * @brief CPython sub-interpreter handle managed by `pitaya::PyInterpreterPool` (`pitaya_py_interpreter_pool.cpp` @ 0x057105).
 *        Handle sub-interpreter CPython được quản lý bởi `pitaya::PyInterpreterPool` (`pitaya_py_interpreter_pool.cpp` tại 0x057105).
 */
struct PyInterpreterHandle {
    int32_t interpreter_id{0};
    bool is_main_interpreter{false};
    bool is_locked_power_downgrade{false};
    bool is_occupied{false};
    std::string bridge_version{"3.14.0"};
    std::vector<std::string> search_paths;
    std::unordered_map<std::string, PyObject*> loaded_modules;
    bool cprofile_enabled{false};
};

/**
 * @brief pitaya::PyInterpreterPool (`pitaya_py_interpreter_pool.cpp` @ .rodata 0x057105..0x0571ec).
 *        Hồ quản lý các sub-interpreter CPython (`pitaya_py_interpreter_pool.cpp` tại .rodata 0x057105..0x0571ec).
 *
 * [OBSERVED @ .rodata 0x057105..0x0571ec]:
 * - "SetConcurrency:%d"
 * - "Power downgrade, all interpreter been locked"
 * - "%s: Interpreter id:%d locked due to power downgrade"
 * - "The specific interpreter been locked due to power downgrade"
 * - "PTY-PyInterpreterPool"
 */
class PyInterpreterPool {
public:
    explicit PyInterpreterPool(int32_t concurrency = 2);
    ~PyInterpreterPool() = default;

    void SetConcurrency(int32_t concurrency);
    void SetPowerDowngrade(bool downgrade);

    std::shared_ptr<PyInterpreterHandle> OccupyOne(int32_t specific_id, std::shared_ptr<Error>& out_error);
    void ReleaseOne(const std::shared_ptr<PyInterpreterHandle>& interp);

    int32_t Concurrency() const { return concurrency_; }
    bool IsPowerDowngraded() const { return power_downgrade_; }

private:
    mutable std::mutex mutex_;
    int32_t concurrency_;
    bool power_downgrade_{false};
    std::vector<std::shared_ptr<PyInterpreterHandle>> interpreters_;
};

/**
 * @brief pitaya::PyTaskExecutor (`pitaya_py_task_executor.cpp` @ .rodata 0x057346..0x057e25).
 *        Bộ thực thi tác vụ CPython (`pitaya_py_task_executor.cpp` tại .rodata 0x057346..0x057e25).
 *
 * [OBSERVED @ .rodata 0x057346..0x057e25]:
 * - `PrepareInitEngine` (@ 0x057500)
 * - `ConfigVM` (@ 0x05762e: "bridge ver change, old:%s -> cur:%s, clear module with sub_str:%s")
 * - `ConfigAppInfo` (@ 0x057693: "Bridge.app_info", "get_app_info")
 * - `ClearModuleWithSubStr` (@ 0x057a0e)
 * - `CreateAndEnableProfileIfNeeded` (@ 0x057a7e: "cProfile", "enable")
 * - `DisableAndReleaseProfileIfNeeded` (@ 0x057b30: "disable", "dump_stats_to_default_path")
 * - `DistributeInterpreter` (@ 0x057bc0)
 * - `CheckAndInsertSearchPath` (@ 0x057c02)
 * - `ProcessVMExit` (@ 0x057954)
 */
class PyTaskExecutor {
public:
    static PyTaskExecutor& Instance();

    bool PrepareInitEngine(std::shared_ptr<Error>& out_error);
    bool ConfigVM(PyInterpreterHandle& interp, const std::string& new_bridge_ver, const std::string& module_sub_str);
    size_t ClearModuleWithSubStr(PyInterpreterHandle& interp, const std::string& sub_str);
    bool CheckAndInsertSearchPath(PyInterpreterHandle& interp, const std::string& path);
    bool CreateAndEnableProfileIfNeeded(PyInterpreterHandle& interp, bool enable_profile);
    bool DisableAndReleaseProfileIfNeeded(PyInterpreterHandle& interp);
    bool RunTask(Task& task);

    // Duration percentage telemetry formatter matching .rodata 0x0574a6..0x0574c8:
    // "call_dur: %f", "bridge_dur: %f [%f%]", "vm_dur: [%f%]"
    static std::string FormatTaskDurationTelemetry(double call_dur_ms, double bridge_dur_ms);

    PyInterpreterPool& Pool() { return pool_; }

private:
    PyTaskExecutor();
    bool engine_ready_{false};
    PyInterpreterPool pool_;
};

// Exported C++ symbol at 0x056da8 (_ZN6pitaya8Java2CPyEP8_jobjectPvb)
PyObject* Java2CPy(jobject json_or_class_obj, void* interpreter_state, bool is_cep);

// .init_array functions at 0x010410 (-> 0x028e3c) and 0x010414
void InitArray0_RegisterBDPythonBridge();
void InitArray1_RegisterPTYClassTransform();

} // namespace pitaya

// =================================================================================================
// 21 Exported JNI C Symbols (CPyNativeArray, CPyNativeDict, PyVMLoader) @ 0x05603c..0x0570d8
// 21 ký hiệu C JNI được export (CPyNativeArray, CPyNativeDict, PyVMLoader) @ 0x05603c..0x0570d8
// =================================================================================================
extern "C" {

// CPyNativeArray JNI exports (10 functions @ 0x05603c..0x05656c)
jlong Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeArray_nativeCreateArray(
    JNIEnv* env, jclass clazz, jint size);

void Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeArray_nativeAppendBool(
    JNIEnv* env, jclass clazz, jboolean val, jint index, jlong array_ptr);

void Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeArray_nativeAppendLong(
    JNIEnv* env, jclass clazz, jlong val, jint index, jlong array_ptr);

void Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeArray_nativeAppendDouble(
    JNIEnv* env, jclass clazz, jdouble val, jint index, jlong array_ptr);

void Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeArray_nativeAppendFloat(
    JNIEnv* env, jclass clazz, jfloat val, jint index, jlong array_ptr);

void Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeArray_nativeAppendStr(
    JNIEnv* env, jclass clazz, jstring val, jint index, jlong array_ptr);

void Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeArray_nativeAppendDict(
    JNIEnv* env, jclass clazz, jlong dict_ptr, jint index, jlong array_ptr);

void Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeArray_nativeAppendArray(
    JNIEnv* env, jclass clazz, jlong sub_array_ptr, jint index, jlong array_ptr);

void Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeArray_nativeAppendPTYClass(
    JNIEnv* env, jclass clazz, jobject cls_obj, jint index, jboolean is_cep, jlong array_ptr);

void Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeArray_nativeAppendNull(
    JNIEnv* env, jclass clazz, jint index, jlong array_ptr);

// CPyNativeDict JNI exports (10 functions @ 0x056570..0x056da4)
jlong Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeDict_nativeCreateDict(
    JNIEnv* env, jclass clazz);

void Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeDict_nativeSetArray(
    JNIEnv* env, jclass clazz, jstring key, jlong array_ptr, jlong dict_ptr);

void Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeDict_nativeSetDict(
    JNIEnv* env, jclass clazz, jstring key, jlong sub_dict_ptr, jlong dict_ptr);

void Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeDict_nativeSetBool(
    JNIEnv* env, jclass clazz, jstring key, jboolean val, jlong dict_ptr);

void Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeDict_nativeSetDouble(
    JNIEnv* env, jclass clazz, jstring key, jdouble val, jlong dict_ptr);

void Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeDict_nativeSetFloat(
    JNIEnv* env, jclass clazz, jstring key, jfloat val, jlong dict_ptr);

void Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeDict_nativeSetLong(
    JNIEnv* env, jclass clazz, jstring key, jlong val, jlong dict_ptr);

void Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeDict_nativeSetStr(
    JNIEnv* env, jclass clazz, jstring key, jstring val, jlong dict_ptr);

void Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeDict_nativeSetClass(
    JNIEnv* env, jclass clazz, jstring key, jobject cls_obj, jboolean is_cep, jlong dict_ptr);

void Java_com_bytedance_pitaya_api_bean_nativeobj_python_CPyNativeDict_nativeSetNull(
    JNIEnv* env, jclass clazz, jstring key, jlong dict_ptr);

// PyVMLoader JNI export (1 function @ 0x056ff4)
void Java_com_bytedance_pitaya_modules_PyVMLoader_nativeInit(
    JNIEnv* env, jobject thiz);

} // extern "C"

#endif // NEXTAI_OPENCUT_BDPYTHONVM_EXECUTOR_POOL_JNI_H_
