/**
 * @file bdmicropythonvm_vm_pool_jni.h
 * @brief InitFastEngine, MicroPyPitayaVM, MinPyVMPool, FastEngineTaskExecutor & 21 MicPyArray/MicPyDict/MicroPyLoader JNI Functions
 *        InitFastEngine, MicroPyPitayaVM, MinPyVMPool, FastEngineTaskExecutor & 21 hàm JNI MicPyArray/MicPyDict/MicroPyLoader
 *
 * =================================================================================================
 * [EVIDENCE CLASSIFICATION: OBSERVED (100% Disassembled from libBDMicroPythonVM.so @ 0x03de00..0x051070)]
 * [PHÂN LOẠI BẰNG CHỨNG: OBSERVED (Giải mã 100% từ nhị phân thật libBDMicroPythonVM.so @ 0x03de00..0x051070)]
 * =================================================================================================
 *
 * Exported Functions Covered / Các hàm Export được tái dựng trong module này:
 * 1. _ZN6pitaya14InitFastEngineERNSt6__ndk110shared_ptrINS_5ErrorEEE                           (@ 0x04ee2c, 1,376 B)
 * 2. Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeCreateArray         (@ 0x04fd08, 132 B)
 * 3. Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetArray            (@ 0x05033c, 92 B)
 * 4. Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetBool             (@ 0x04fd8c, 232 B)
 * 5. Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetClass            (@ 0x050040, 672 B)
 * 6. Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetDict             (@ 0x0502e0, 92 B)
 * 7. Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetDouble           (@ 0x04ff18, 168 B)
 * 8. Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetFloat            (@ 0x04ffc0, 4 B -> fcvt d0, s0; b #0x4ff18)
 * 9. Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetLong             (@ 0x04fe74, 164 B)
 * 10. Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetNull            (@ 0x050398, 72 B)
 * 11. Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetStr             (@ 0x04ffc8, 120 B)
 * 12. Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeCreateDict          (@ 0x0503e0, 84 B)
 * 13. Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetArray            (@ 0x0508c0, 148 B)
 * 14. Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetBoolean          (@ 0x050798, 148 B)
 * 15. Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetClass            (@ 0x050954, 724 B)
 * 16. Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetDict             (@ 0x05082c, 148 B)
 * 17. Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetDouble           (@ 0x050574, 212 B)
 * 18. Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetFloat            (@ 0x050648, 216 B)
 * 19. Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetLong             (@ 0x050434, 320 B)
 * 20. Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetNull             (@ 0x050c28, 256 B)
 * 21. Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetStr              (@ 0x050720, 120 B)
 * 22. Java_com_bytedance_pitaya_modules_MicroPyLoader_nativeInit                               (@ 0x050f88, 232 B)
 */

#ifndef NEXTAI_OPENCUT_BDMICROPYTHONVM_VM_POOL_JNI_H_
#define NEXTAI_OPENCUT_BDMICROPYTHONVM_VM_POOL_JNI_H_

#include "bdmicropythonvm_types.h"

namespace pitaya {

/**
 * @brief pitaya::FastEngineMemoryMonitor (vtable @ 0x05f048, RTTI `_ZTIN6pitaya23FastEngineMemoryMonitorE` @ 0x05f088).
 *        Bộ giám sát bộ nhớ pitaya::FastEngineMemoryMonitor (vtable tại 0x05f048).
 *
 * [OBSERVED @ .rodata 0x0530ed..0x05327b]:
 * - Monitors total heap & pool memory across active `MicroPyPitayaVM` instances
 * - Triggers `fast_engine::Engine::CollectGarbage()` when memory warning level >= 1
 */
class FastEngineMemoryMonitor {
public:
    FastEngineMemoryMonitor() = default;
    virtual ~FastEngineMemoryMonitor() = default;

    virtual void OnMemoryWarning(int32_t level);
    virtual int64_t GetMemorySize() const;

    void RecordAllocation(int64_t delta_bytes) {
        allocated_bytes_.fetch_add(delta_bytes, std::memory_order_relaxed);
    }

private:
    std::atomic<int64_t> allocated_bytes_{65536};
};

/**
 * @brief pitaya::MicroPyPitayaVM (`pitaya_mp_vm.cpp` @ 0x052f30, vtable @ 0x05efb0, RTTI `_ZTIN6pitaya15MicroPyPitayaVME` @ 0x05f018).
 *        Máy ảo MicroPython Pitaya (`pitaya_mp_vm.cpp` tại 0x052f30, vtable tại 0x05efb0).
 *
 * [OBSERVED @ 0x045718..0x049200 & .rodata 0x052f30..0x0530ec]:
 * - Wraps a `fast_engine::Engine*` instance
 * - Implements `LoadEntry` ("load entrance script failed"), `RunTask`, `GC`, `Reset`, `GetEnginePtr`
 */
class MicroPyPitayaVM {
public:
    explicit MicroPyPitayaVM(std::string business_name);
    virtual ~MicroPyPitayaVM();

    virtual bool LoadEntry(const std::string& module_path,
                           const std::string& entry_func,
                           std::shared_ptr<Error>& out_error);

    virtual std::shared_ptr<PTYObject> RunTask(const std::shared_ptr<PTYObject>& input,
                                               std::shared_ptr<Error>& out_error);

    virtual void GC();
    virtual void Reset();

    fast_engine::Engine* EnginePtr() const { return engine_.get(); }
    const std::string& BusinessName() const { return business_name_; }
    bool IsOccupied() const { return occupied_; }
    void SetOccupied(bool occ) { occupied_ = occ; }

private:
    std::string business_name_;
    std::string loaded_module_;
    std::string entry_function_;
    std::unique_ptr<fast_engine::Engine> engine_;
    bool occupied_{false};
};

/**
 * @brief pitaya::MinPyVMPool (`pitaya_mp_vm_pool.cpp` @ 0x053409, vtable @ 0x05f0f0, RTTI `_ZTIN6pitaya11MinPyVMPoolE` @ 0x05f170).
 *        Hồ quản lý máy ảo pitaya::MinPyVMPool (`pitaya_mp_vm_pool.cpp` tại 0x053409, vtable tại 0x05f0f0).
 *
 * [OBSERVED @ 0x04b800..0x04ee28 & .rodata 0x05327c..0x053480]:
 * - Logs: "OccupyOne from pool, size = %zu", "FreeOne to pool, size = %zu"
 * - Manages per-business concurrency limit (`max_concurrency_`) and idle VM reuse.
 */
class MinPyVMPool {
public:
    MinPyVMPool(std::string business_name, size_t max_concurrency = 2);
    virtual ~MinPyVMPool();

    virtual std::shared_ptr<MicroPyPitayaVM> OccupyOne(std::shared_ptr<Error>& out_error);
    virtual void FreeOne(const std::shared_ptr<MicroPyPitayaVM>& vm);
    virtual void SetConcurrency(size_t max_concurrency);
    virtual void ClearAll();

    size_t PoolSize() const;
    size_t ActiveCount() const;
    size_t MaxConcurrency() const { return max_concurrency_; }

private:
    mutable std::mutex mutex_;
    std::string business_name_;
    size_t max_concurrency_;
    size_t active_count_{0};
    std::vector<std::shared_ptr<MicroPyPitayaVM>> idle_vms_;
};

/**
 * @brief pitaya::FastEngineTaskExecutor (`pitaya_mp_task_executor.cpp` @ 0x052aef, vtable @ 0x05ef50).
 *        Bộ thực thi tác vụ pitaya::FastEngineTaskExecutor (`pitaya_mp_task_executor.cpp` tại 0x052aef, vtable tại 0x05ef50).
 */
class FastEngineTaskExecutor {
public:
    explicit FastEngineTaskExecutor(std::string business_name, size_t concurrency = 2);
    virtual ~FastEngineTaskExecutor() = default;

    virtual bool ExecuteTask(Task& task);

    std::shared_ptr<MinPyVMPool> Pool() const { return vm_pool_; }

private:
    std::string business_name_;
    std::shared_ptr<MinPyVMPool> vm_pool_;
};

/**
 * @brief FastEngineAdapter hook table registered by `pitaya::InitFastEngine` (@ 0x04ee2c..0x04f388).
 *        Bảng hàm callback FastEngineAdapter được đăng ký bởi `pitaya::InitFastEngine` (@ 0x04ee2c..0x04f388).
 *
 * [OBSERVED @ 0x04f0a0..0x04f290]:
 * Registers 6 function pointers into `pitaya::FastEngineAdapter`:
 * 1. `create_pty_ext_dict_func` -> `pitaya::CreatePTYExtDict` (@ 0x03bec0)
 * 2. `create_pty_ext_list_func` -> `pitaya::CreatePTYExtList` (@ 0x03bf74)
 * 3. `create_pty_cep_event_func`-> `pitaya::CreateCepEvent`   (@ 0x03c028)
 * 4. `env_pty_obj_to_mp_obj_func` -> `fast_engine::EnvPTYObj2MPObj` (@ 0x043c84)
 * 5. `env_mp_obj_to_pty_obj_func` -> `fast_engine::EnvMPObj2PTYObj` (@ 0x0453e0)
 * 6. `free_mp_obj_func`           -> `fast_engine::Obj::DecRef`
 */
struct FastEngineAdapterHooks {
    void* (*create_pty_ext_dict_func)(void*, const std::shared_ptr<PTYDict>&){nullptr};
    void* (*create_pty_ext_list_func)(void*, const std::shared_ptr<PTYList>&){nullptr};
    void* (*create_pty_cep_event_func)(void*, const std::shared_ptr<PTYDict>&){nullptr};
    void* (*env_pty_obj_to_mp_obj_func)(const std::shared_ptr<PTYObject>&, std::shared_ptr<Error>&, void*, bool){nullptr};
    std::shared_ptr<PTYObject> (*env_mp_obj_to_pty_obj_func)(void*, std::shared_ptr<Error>&, void*){nullptr};
    bool initialized{false};
};

// Exported C++ symbol at 0x04ee2c (_ZN6pitaya14InitFastEngineERNSt6__ndk110shared_ptrINS_5ErrorEEE)
bool InitFastEngine(std::shared_ptr<Error>& out_error);

const FastEngineAdapterHooks& GetFastEngineAdapterHooks();

} // namespace pitaya

// =================================================================================================
// 21 Exported JNI C Symbols (MicPyArray, MicPyDict, MicroPyLoader) @ 0x04fd08..0x051070
// 21 ký hiệu C JNI được export (MicPyArray, MicPyDict, MicroPyLoader) @ 0x04fd08..0x051070
// =================================================================================================
extern "C" {

// MicPyArray JNI exports (10 functions @ 0x04fd08..0x0503dc)
jlong Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeCreateArray(
    JNIEnv* env, jclass clazz, jlong engine_ptr, jlong size);

void Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetBool(
    JNIEnv* env, jobject thiz, jlong array_ptr, jlong index, jboolean val);

void Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetLong(
    JNIEnv* env, jobject thiz, jlong engine_ptr, jlong array_ptr, jlong index, jlong val);

void Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetDouble(
    JNIEnv* env, jobject thiz, jlong engine_ptr, jlong array_ptr, jlong index, jdouble val);

void Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetFloat(
    JNIEnv* env, jobject thiz, jlong engine_ptr, jlong array_ptr, jlong index, jfloat val);

void Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetStr(
    JNIEnv* env, jobject thiz, jlong engine_ptr, jlong array_ptr, jlong index, jstring val);

void Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetClass(
    JNIEnv* env, jobject thiz, jlong engine_ptr, jlong array_ptr, jlong index, jobject val, jboolean is_cep);

void Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetDict(
    JNIEnv* env, jobject thiz, jlong array_ptr, jlong index, jlong dict_ptr);

void Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetArray(
    JNIEnv* env, jobject thiz, jlong array_ptr, jlong index, jlong sub_array_ptr);

void Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetNull(
    JNIEnv* env, jobject thiz, jlong array_ptr, jlong index);

// MicPyDict JNI exports (10 functions @ 0x0503e0..0x050d24)
jlong Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeCreateDict(
    JNIEnv* env, jclass clazz, jlong engine_ptr);

void Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetLong(
    JNIEnv* env, jobject thiz, jlong engine_ptr, jlong dict_ptr, jstring key, jlong val);

void Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetDouble(
    JNIEnv* env, jobject thiz, jlong engine_ptr, jlong dict_ptr, jstring key, jdouble val);

void Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetFloat(
    JNIEnv* env, jobject thiz, jlong engine_ptr, jlong dict_ptr, jstring key, jfloat val);

void Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetStr(
    JNIEnv* env, jobject thiz, jlong engine_ptr, jlong dict_ptr, jstring key, jstring val);

void Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetBoolean(
    JNIEnv* env, jobject thiz, jlong dict_ptr, jstring key, jboolean val);

void Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetDict(
    JNIEnv* env, jobject thiz, jlong dict_ptr, jstring key, jlong sub_dict_ptr);

void Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetArray(
    JNIEnv* env, jobject thiz, jlong dict_ptr, jstring key, jlong array_ptr);

void Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetClass(
    JNIEnv* env, jobject thiz, jlong engine_ptr, jlong dict_ptr, jstring key, jobject val, jboolean is_cep);

void Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetNull(
    JNIEnv* env, jobject thiz, jlong dict_ptr, jstring key);

// MicroPyLoader JNI export (1 function @ 0x050f88)
void Java_com_bytedance_pitaya_modules_MicroPyLoader_nativeInit(
    JNIEnv* env, jobject thiz);

} // extern "C"

#endif // NEXTAI_OPENCUT_BDMICROPYTHONVM_VM_POOL_JNI_H_
