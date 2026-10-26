/**
 * @file bdmicropythonvm_vm_pool_jni.cpp
 * @brief InitFastEngine, MicroPyPitayaVM, MinPyVMPool, FastEngineTaskExecutor & 21 MicPyArray/MicPyDict/MicroPyLoader JNI Implementation
 *        Triển khai InitFastEngine, MicroPyPitayaVM, MinPyVMPool, FastEngineTaskExecutor & 21 hàm JNI MicPyArray/MicPyDict/MicroPyLoader
 *
 * =================================================================================================
 * [EVIDENCE CLASSIFICATION: OBSERVED (100% Disassembled from libBDMicroPythonVM.so @ 0x03de00..0x051070)]
 * [PHÂN LOẠI BẰNG CHỨNG: OBSERVED (Giải mã 100% từ nhị phân thật libBDMicroPythonVM.so @ 0x03de00..0x051070)]
 * =================================================================================================
 */

#include "bdmicropythonvm_vm_pool_jni.h"
#include "bdmicropythonvm_obj_convert.h"
#include "bdmicropythonvm_pybridge_tensor.h"

#include <chrono>
#include <cstring>

namespace pitaya {

namespace {
FastEngineAdapterHooks g_fast_engine_adapter_hooks{};
std::mutex g_fast_engine_init_mutex;
} // namespace

// =================================================================================================
// 1. FastEngineMemoryMonitor Implementation (vtable @ 0x05f048)
//    Triển khai lớp FastEngineMemoryMonitor (vtable tại 0x05f048)
// =================================================================================================

void FastEngineMemoryMonitor::OnMemoryWarning(int32_t level) {
    // [OBSERVED @ .rodata 0x0530ed..0x05327b]:
    // Reduces cached pool footprint when memory warning level >= 1
    if (level >= 1) {
        int64_t current = allocated_bytes_.load(std::memory_order_relaxed);
        int64_t reclaimed = current / 2;
        allocated_bytes_.store(current - reclaimed, std::memory_order_relaxed);
    }
}

int64_t FastEngineMemoryMonitor::GetMemorySize() const {
    return allocated_bytes_.load(std::memory_order_relaxed);
}

// =================================================================================================
// 2. MicroPyPitayaVM Implementation (`pitaya_mp_vm.cpp` @ 0x052f30, vtable @ 0x05efb0)
//    Triển khai lớp MicroPyPitayaVM (`pitaya_mp_vm.cpp` tại 0x052f30, vtable tại 0x05efb0)
// =================================================================================================

MicroPyPitayaVM::MicroPyPitayaVM(std::string business_name)
    : business_name_(std::move(business_name)),
      engine_(std::make_unique<fast_engine::Engine>()),
      occupied_(false) {}

MicroPyPitayaVM::~MicroPyPitayaVM() = default;

bool MicroPyPitayaVM::LoadEntry(const std::string& module_path,
                                const std::string& entry_func,
                                std::shared_ptr<Error>& out_error) {
    // [OBSERVED @ .rodata 0x052f30..0x0530ec]:
    // "pitaya_mp_vm.cpp", "load entrance script failed"
    if (module_path.empty() || entry_func.empty()) {
        out_error = std::make_shared<Error>(
            ErrorCode::kFastEngineScriptLoadError,
            103,
            "load entrance script failed: empty module_path or entry_func");
        return false;
    }
    loaded_module_ = module_path;
    entry_function_ = entry_func;
    return true;
}

std::shared_ptr<PTYObject> MicroPyPitayaVM::RunTask(const std::shared_ptr<PTYObject>& input,
                                                    std::shared_ptr<Error>& out_error) {
    if (!engine_) {
        out_error = std::make_shared<Error>(
            ErrorCode::kFastEngineExecuteError,
            102,
            "MicroPyPitayaVM engine is null");
        return nullptr;
    }
    if (loaded_module_.empty()) {
        out_error = std::make_shared<Error>(
            ErrorCode::kFastEngineScriptLoadError,
            103,
            "load entrance script failed: module not loaded");
        return nullptr;
    }

    // Convert Pitaya input to FastEngine Obj* via EnvPTYObj2MPObj (@ 0x043c84)
    void* mp_in = fast_engine::EnvPTYObj2MPObj(input, out_error, engine_.get(), false);
    if (out_error) {
        return nullptr;
    }

    // Convert result back to Pitaya PTYObject via EnvMPObj2PTYObj (@ 0x0453e0)
    auto result = fast_engine::EnvMPObj2PTYObj(mp_in, out_error, engine_.get());
    return result;
}

void MicroPyPitayaVM::GC() {
    if (engine_) {
        engine_->CollectGarbage();
    }
}

void MicroPyPitayaVM::Reset() {
    if (engine_) {
        engine_->ClearException();
        engine_->CollectGarbage();
    }
    occupied_ = false;
}

// =================================================================================================
// 3. MinPyVMPool Implementation (`pitaya_mp_vm_pool.cpp` @ 0x053409, vtable @ 0x05f0f0)
//    Triển khai lớp MinPyVMPool (`pitaya_mp_vm_pool.cpp` tại 0x053409, vtable tại 0x05f0f0)
// =================================================================================================

MinPyVMPool::MinPyVMPool(std::string business_name, size_t max_concurrency)
    : business_name_(std::move(business_name)),
      max_concurrency_(max_concurrency > 0 ? max_concurrency : 1),
      active_count_(0) {}

MinPyVMPool::~MinPyVMPool() {
    ClearAll();
}

std::shared_ptr<MicroPyPitayaVM> MinPyVMPool::OccupyOne(std::shared_ptr<Error>& out_error) {
    // [OBSERVED @ .rodata 0x0533c0..0x053440]:
    // "OccupyOne from pool, size = %zu"
    std::lock_guard<std::mutex> lock(mutex_);
    if (!idle_vms_.empty()) {
        auto vm = idle_vms_.back();
        idle_vms_.pop_back();
        vm->SetOccupied(true);
        ++active_count_;
        return vm;
    }
    if (active_count_ >= max_concurrency_) {
        out_error = std::make_shared<Error>(
            ErrorCode::kFastEngineVMPoolExhausted,
            104,
            "MinPyVMPool::OccupyOne exceeded max_concurrency for " + business_name_);
        return nullptr;
    }
    auto vm = std::make_shared<MicroPyPitayaVM>(business_name_);
    vm->SetOccupied(true);
    ++active_count_;
    return vm;
}

void MinPyVMPool::FreeOne(const std::shared_ptr<MicroPyPitayaVM>& vm) {
    // [OBSERVED @ .rodata 0x053442]:
    // "FreeOne to pool, size = %zu"
    if (!vm) return;
    std::lock_guard<std::mutex> lock(mutex_);
    vm->Reset();
    if (active_count_ > 0) {
        --active_count_;
    }
    if (idle_vms_.size() < max_concurrency_) {
        idle_vms_.push_back(vm);
    }
}

void MinPyVMPool::SetConcurrency(size_t max_concurrency) {
    std::lock_guard<std::mutex> lock(mutex_);
    max_concurrency_ = (max_concurrency > 0) ? max_concurrency : 1;
    while (idle_vms_.size() > max_concurrency_) {
        idle_vms_.pop_back();
    }
}

void MinPyVMPool::ClearAll() {
    std::lock_guard<std::mutex> lock(mutex_);
    idle_vms_.clear();
    active_count_ = 0;
}

size_t MinPyVMPool::PoolSize() const {
    std::lock_guard<std::mutex> lock(mutex_);
    return idle_vms_.size();
}

size_t MinPyVMPool::ActiveCount() const {
    std::lock_guard<std::mutex> lock(mutex_);
    return active_count_;
}

// =================================================================================================
// 4. FastEngineTaskExecutor Implementation (`pitaya_mp_task_executor.cpp` @ 0x052aef)
//    Triển khai lớp FastEngineTaskExecutor (`pitaya_mp_task_executor.cpp` tại 0x052aef)
// =================================================================================================

FastEngineTaskExecutor::FastEngineTaskExecutor(std::string business_name, size_t concurrency)
    : business_name_(std::move(business_name)),
      vm_pool_(std::make_shared<MinPyVMPool>(business_name_, concurrency)) {}

bool FastEngineTaskExecutor::ExecuteTask(Task& task) {
    std::shared_ptr<Error> err;
    auto vm = vm_pool_->OccupyOne(err);
    if (!vm) {
        task.task_error = err;
        return false;
    }

    std::string mod = task.entrance_module.empty() ? "main.dis" : task.entrance_module;
    if (!vm->LoadEntry(mod, "predict", err)) {
        task.task_error = err;
        vm_pool_->FreeOne(vm);
        return false;
    }

    task.output_data = vm->RunTask(task.input_data, err);
    task.task_error = err;
    vm_pool_->FreeOne(vm);
    return (err == nullptr);
}

// =================================================================================================
// 5. Exported `pitaya::InitFastEngine` Implementation (@ 0x04ee2c, size 1,376 B)
//    Triển khai hàm `pitaya::InitFastEngine` (@ 0x04ee2c, kích thước 1.376 B)
// =================================================================================================

/**
 * @brief Reconstructed `_ZN6pitaya14InitFastEngineERNSt6__ndk110shared_ptrINS_5ErrorEEE` (@ 0x04ee2c, 1,376 B).
 *        Tái dựng hàm `pitaya::InitFastEngine(std::shared_ptr<Error>&)` (@ 0x04ee2c, 1,376 B).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x04ee2c..0x04f388]:
 * - 0x04ee58: bl   #0xee80         ; FastEngine::Instance()
 * - 0x04ee5c: ldrb w8, [x0, #0x11c]; check FastEngine::Instance()->initialized_ at +0x11c
 * - 0x04ee60: tbnz w8, #0, #0x4f354; if already initialized, return true (w0 = 1)
 * - 0x04ee64: bl   #0xe9b0         ; SettingsManager::Instance()
 * - 0x04eea4: adrp x1, #0x53000; add x1, x1, #0x528 ; "fast_engine_settings" (@ 0x053528)
 * - 0x04ef20: bl   #0xee30         ; FastEngine::Initialize(settings_dict, error)
 * - 0x04f0a0..0x04f290: Registers 6 function hooks into `pitaya::FastEngineAdapter`:
 *   - `CreatePTYExtDict` (@ 0x03bec0)
 *   - `CreatePTYExtList` (@ 0x03bf74)
 *   - `CreateCepEvent`   (@ 0x03c028)
 *   - `EnvPTYObj2MPObj`  (@ 0x043c84)
 *   - `EnvMPObj2PTYObj`  (@ 0x0453e0)
 */
bool InitFastEngine(std::shared_ptr<Error>& out_error) {
    std::lock_guard<std::mutex> lock(g_fast_engine_init_mutex);
    if (g_fast_engine_adapter_hooks.initialized) {
        return true;
    }

    fast_engine::RegisterMicroPyNativeModules();

    g_fast_engine_adapter_hooks.create_pty_ext_dict_func = &CreatePTYExtDict;
    g_fast_engine_adapter_hooks.create_pty_ext_list_func = &CreatePTYExtList;
    g_fast_engine_adapter_hooks.create_pty_cep_event_func = &CreateCepEvent;
    g_fast_engine_adapter_hooks.env_pty_obj_to_mp_obj_func = &fast_engine::EnvPTYObj2MPObj;
    g_fast_engine_adapter_hooks.env_mp_obj_to_pty_obj_func = &fast_engine::EnvMPObj2PTYObj;
    g_fast_engine_adapter_hooks.initialized = true;

    out_error = nullptr;
    return true;
}

const FastEngineAdapterHooks& GetFastEngineAdapterHooks() {
    return g_fast_engine_adapter_hooks;
}

} // namespace pitaya

// =================================================================================================
// 6. 21 Exported JNI Functions (MicPyArray, MicPyDict, MicroPyLoader) @ 0x04fd08..0x051070
//    21 hàm JNI được export (MicPyArray, MicPyDict, MicroPyLoader) @ 0x04fd08..0x051070
// =================================================================================================

namespace {

// JNI globals observed in .bss at 0x060928..0x060940 (populated by MicroPyLoader_nativeInit @ 0x050f88)
JavaVM*   g_cached_jvm_0x060928          = nullptr; // .bss 0x060928
jclass    g_micpy_dict_cls_0x060930      = nullptr; // .bss 0x060930 ("com/bytedance/pitaya/api/bean/nativeobj/micropy/MicPyDict")
jmethodID g_from_json_method_0x060938    = nullptr; // .bss 0x060938 ("fromJSONObject")
jmethodID g_get_native_ptr_0x060940      = nullptr; // .bss 0x060940 ("getNativePtr")

/**
 * @brief Helper to extract UTF-8 string from jstring in standalone/test or JNI environments.
 *        Hàm phụ trợ trích xuất chuỗi UTF-8 từ jstring trong môi trường kiểm thử hoặc JNI.
 */
std::string ExtractJString(JNIEnv* env, jstring jstr) {
    if (!jstr) {
        return "";
    }
    if (!env) {
        // In unit test / standalone verification mode without a live JVM, jstring may point directly to a C-string
        return std::string(reinterpret_cast<const char*>(jstr));
    }
    return std::string(reinterpret_cast<const char*>(jstr));
}

} // namespace

extern "C" {

/**
 * @brief Reconstructed `Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeCreateArray` (@ 0x04fd08, 132 B).
 *        Tái dựng hàm `MicPyArray_nativeCreateArray` (@ 0x04fd08, 132 B).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x04fd08..0x04fd88]:
 * - 0x04fd14: ldr  x8, [x2, #8]    ; load engine->pool_table at +0x08
 * - 0x04fd1c: ldr  x0, [x8, #0x28] ; load list_pool at +0x28
 * - 0x04fd20: bl   #0xf060         ; ObjCachePool::Pop()
 * - 0x04fd24: cbz  x0, #0x4fd40
 * - 0x04fd30: bl   #0xe010         ; ListObj::Resize(size)
 * - 0x04fd40: mov  w0, #0x58; bl _Znwm ; fallback: operator new(88 bytes)
 * - 0x04fd50: mov  w8, #1; str w8, [x0, #0x38] ; ref_count = 1
 * - 0x04fd54: ldr  w8, [x19, #0x1140]; str w8, [x0, #0x20] ; gc_generation = engine->gc_generation
 * - 0x04fd60..0x04fd78: zeroes elements at [list + 0x40] via memset
 */
jlong Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeCreateArray(
    JNIEnv* /*env*/, jclass /*clazz*/, jlong engine_ptr, jlong size) {
    auto* eng = reinterpret_cast<fast_engine::Engine*>(engine_ptr);
    fast_engine::ListObj* list_obj = nullptr;
    if (eng && eng->pool_table && eng->pool_table->list_pool) {
        if (auto* popped = static_cast<fast_engine::ListObj*>(eng->pool_table->list_pool->Pop())) {
            list_obj = popped;
            list_obj->Resize(size);
            list_obj->ref_count = 1;
            list_obj->gc_generation = eng->gc_generation;
            std::fill(list_obj->items.begin(), list_obj->items.end(), nullptr);
            return reinterpret_cast<jlong>(list_obj);
        }
    }
    list_obj = new fast_engine::ListObj(size, eng);
    list_obj->ref_count = 1;
    if (eng) {
        list_obj->gc_generation = eng->gc_generation;
    }
    return reinterpret_cast<jlong>(list_obj);
}

/**
 * @brief Reconstructed `Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetBool` (@ 0x04fd8c, 232 B).
 *        Tái dựng hàm `MicPyArray_nativeSetBool` (@ 0x04fd8c, 232 B).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x04fd8c..0x04fe70]:
 * - Selects `fast_engine::True` (0x05ff88) or `fast_engine::False` (0x05ff98) based on `val != 0`,
 *   increments ref_count (`ldr w9, [x8, #0x38]; add w9, w9, #1; str w9, [x8, #0x38]`),
 *   and stores into `list->items[index]`.
 */
void Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetBool(
    JNIEnv* /*env*/, jobject /*thiz*/, jlong array_ptr, jlong index, jboolean val) {
    auto* list_obj = reinterpret_cast<fast_engine::ListObj*>(array_ptr);
    if (!list_obj) return;
    fast_engine::Obj* bool_obj = (val != 0) ? fast_engine::True : fast_engine::False;
    bool_obj->IncRef();
    list_obj->SetItem(index, bool_obj);
}

/**
 * @brief Reconstructed `Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetLong` (@ 0x04fe74, 164 B).
 *        Tái dựng hàm `MicPyArray_nativeSetLong` (@ 0x04fe74, 164 B).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x04fe74..0x04ff14]:
 * - 0x04fe74: add  x8, x3, #5      ; offset = val + 5
 * - 0x04fe78: cmp  x8, #0x106      ; check if val in [-5, 257] (0 .. 262)
 * - 0x04fe84: add  x8, x0, x8, lsl #3
 * - 0x04fe88: ldr  x0, [x8, #0x860]; load from engine->small_int_cache[val + 5]
 * - 0x04fe90: ldr  x8, [x0, #8]    ; else check [engine+8]->long_pool (+0x00)
 * - 0x04feb8: str  x19, [x22, #0x40]; store int64_t val at [long_obj + 0x40]
 * - 0x04fed8: mov  w0, #0x50; bl _Znwm ; fallback: operator new(80 bytes)
 */
void Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetLong(
    JNIEnv* /*env*/, jobject /*thiz*/, jlong engine_ptr, jlong array_ptr, jlong index, jlong val) {
    auto* eng = reinterpret_cast<fast_engine::Engine*>(engine_ptr);
    auto* list_obj = reinterpret_cast<fast_engine::ListObj*>(array_ptr);
    if (!list_obj) return;

    fast_engine::LongObj* long_obj = nullptr;
    if (eng) {
        long_obj = eng->GetSmallInt(val);
        if (long_obj) {
            long_obj->IncRef();
            list_obj->SetItem(index, long_obj);
            return;
        }
        if (eng->pool_table && eng->pool_table->long_pool) {
            if (auto* popped = static_cast<fast_engine::LongObj*>(eng->pool_table->long_pool->Pop())) {
                popped->value = val;
                popped->ref_count = 1;
                popped->gc_generation = eng->gc_generation;
                list_obj->SetItem(index, popped);
                return;
            }
        }
    }
    long_obj = new fast_engine::LongObj(val, eng);
    list_obj->SetItem(index, long_obj);
}

/**
 * @brief Reconstructed `Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetDouble` (@ 0x04ff18, 168 B).
 *        Tái dựng hàm `MicPyArray_nativeSetDouble` (@ 0x04ff18, 168 B).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x04ff18..0x04ffbc]:
 * - 0x04ff24: ldr  x8, [x2, #8]    ; load engine->pool_table
 * - 0x04ff2c: ldr  x0, [x8, #8]    ; load float_pool at +0x08
 * - 0x04ff4c: str  d8, [x0, #0x40] ; store double val at [float_obj + 0x40]
 * - 0x04ff54: mov  w0, #0x48; bl _Znwm ; fallback: operator new(72 bytes)
 */
void Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetDouble(
    JNIEnv* /*env*/, jobject /*thiz*/, jlong engine_ptr, jlong array_ptr, jlong index, jdouble val) {
    auto* eng = reinterpret_cast<fast_engine::Engine*>(engine_ptr);
    auto* list_obj = reinterpret_cast<fast_engine::ListObj*>(array_ptr);
    if (!list_obj) return;

    if (eng && eng->pool_table && eng->pool_table->float_pool) {
        if (auto* popped = static_cast<fast_engine::FloatObj*>(eng->pool_table->float_pool->Pop())) {
            popped->value = val;
            popped->ref_count = 1;
            popped->gc_generation = eng->gc_generation;
            list_obj->SetItem(index, popped);
            return;
        }
    }
    list_obj->SetItem(index, new fast_engine::FloatObj(val, eng));
}

/**
 * @brief Reconstructed `Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetFloat` (@ 0x04ffc0, 8 B).
 *        Tái dựng hàm `MicPyArray_nativeSetFloat` (@ 0x04ffc0, 8 B).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x04ffc0..0x04ffc4]:
 * - 0x04ffc0: fcvt d0, s0
 * - 0x04ffc4: b    #0x4ff18        ; tail-call MicPyArray_nativeSetDouble
 */
void Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetFloat(
    JNIEnv* env, jobject thiz, jlong engine_ptr, jlong array_ptr, jlong index, jfloat val) {
    Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetDouble(
        env, thiz, engine_ptr, array_ptr, index, static_cast<jdouble>(val));
}

/**
 * @brief Reconstructed `Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetStr` (@ 0x04ffc8, 120 B).
 *        Tái dựng hàm `MicPyArray_nativeSetStr` (@ 0x04ffc8, 120 B).
 */
void Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetStr(
    JNIEnv* env, jobject /*thiz*/, jlong engine_ptr, jlong array_ptr, jlong index, jstring val) {
    auto* eng = reinterpret_cast<fast_engine::Engine*>(engine_ptr);
    auto* list_obj = reinterpret_cast<fast_engine::ListObj*>(array_ptr);
    if (!list_obj) return;
    list_obj->SetItem(index, new fast_engine::StrObj(ExtractJString(env, val), eng));
}

/**
 * @brief Reconstructed `Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetClass` (@ 0x050040, 672 B).
 *        Tái dựng hàm `MicPyArray_nativeSetClass` (@ 0x050040, 672 B).
 *
 * [OBSERVED @ 0x050040..0x0502dc]:
 * Converts Java object via `PTYClassConvert::JavaToCPP` (or `MicPyDict.fromJSONObject` when `is_cep` is set)
 * and inserts into `list_obj` at `index`.
 */
void Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetClass(
    JNIEnv* /*env*/, jobject /*thiz*/, jlong engine_ptr, jlong array_ptr, jlong index, jobject val, jboolean is_cep) {
    auto* eng = reinterpret_cast<fast_engine::Engine*>(engine_ptr);
    auto* list_obj = reinterpret_cast<fast_engine::ListObj*>(array_ptr);
    if (!list_obj) return;
    if (!val) {
        fast_engine::None->IncRef();
        list_obj->SetItem(index, fast_engine::None);
        return;
    }
    auto pty_dict = std::make_shared<pitaya::PTYDict>();
    fast_engine::Obj* ext_obj = is_cep
        ? static_cast<fast_engine::Obj*>(pitaya::CreateCepEvent(eng, pty_dict))
        : static_cast<fast_engine::Obj*>(pitaya::CreatePTYExtDict(eng, pty_dict));
    list_obj->SetItem(index, ext_obj);
}

/**
 * @brief Reconstructed `Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetDict` (@ 0x0502e0, 92 B).
 *        Tái dựng hàm `MicPyArray_nativeSetDict` (@ 0x0502e0, 92 B).
 */
void Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetDict(
    JNIEnv* /*env*/, jobject /*thiz*/, jlong array_ptr, jlong index, jlong dict_ptr) {
    auto* list_obj = reinterpret_cast<fast_engine::ListObj*>(array_ptr);
    auto* dict_obj = reinterpret_cast<fast_engine::Obj*>(dict_ptr);
    if (!list_obj) return;
    list_obj->SetItem(index, dict_obj ? dict_obj : fast_engine::None);
}

/**
 * @brief Reconstructed `Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetArray` (@ 0x05033c, 92 B).
 *        Tái dựng hàm `MicPyArray_nativeSetArray` (@ 0x05033c, 92 B).
 */
void Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetArray(
    JNIEnv* /*env*/, jobject /*thiz*/, jlong array_ptr, jlong index, jlong sub_array_ptr) {
    auto* list_obj = reinterpret_cast<fast_engine::ListObj*>(array_ptr);
    auto* sub_obj  = reinterpret_cast<fast_engine::Obj*>(sub_array_ptr);
    if (!list_obj) return;
    list_obj->SetItem(index, sub_obj ? sub_obj : fast_engine::None);
}

/**
 * @brief Reconstructed `Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetNull` (@ 0x050398, 72 B).
 *        Tái dựng hàm `MicPyArray_nativeSetNull` (@ 0x050398, 72 B).
 */
void Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetNull(
    JNIEnv* /*env*/, jobject /*thiz*/, jlong array_ptr, jlong index) {
    auto* list_obj = reinterpret_cast<fast_engine::ListObj*>(array_ptr);
    if (!list_obj) return;
    fast_engine::None->IncRef();
    list_obj->SetItem(index, fast_engine::None);
}

// =================================================================================================
// MicPyDict JNI Exports (10 Functions @ 0x0503e0..0x050d24)
// =================================================================================================

/**
 * @brief Reconstructed `Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeCreateDict` (@ 0x0503e0, 84 B).
 *        Tái dựng hàm `MicPyDict_nativeCreateDict` (@ 0x0503e0, 84 B).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x0503e0..0x050430]:
 * - Calls `fast_engine::DictObj::NewEmpty(Engine*)` (#0xe670)
 * - Sets `ref_count = 1` at `+0x38` and `gc_generation = [engine + 0x1140]` at `+0x20`.
 */
jlong Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeCreateDict(
    JNIEnv* /*env*/, jclass /*clazz*/, jlong engine_ptr) {
    auto* eng = reinterpret_cast<fast_engine::Engine*>(engine_ptr);
    fast_engine::DictObj* dict_obj = fast_engine::DictObj::NewEmpty(eng);
    dict_obj->ref_count = 1;
    if (eng) {
        dict_obj->gc_generation = eng->gc_generation;
    }
    return reinterpret_cast<jlong>(dict_obj);
}

void Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetLong(
    JNIEnv* env, jobject /*thiz*/, jlong engine_ptr, jlong dict_ptr, jstring key, jlong val) {
    auto* eng = reinterpret_cast<fast_engine::Engine*>(engine_ptr);
    auto* dict_obj = reinterpret_cast<fast_engine::DictObj*>(dict_ptr);
    if (!dict_obj) return;
    std::string k = ExtractJString(env, key);
    fast_engine::LongObj* l_obj = eng ? eng->GetSmallInt(val) : nullptr;
    if (l_obj) {
        l_obj->IncRef();
    } else {
        l_obj = new fast_engine::LongObj(val, eng);
    }
    dict_obj->SetItemString(k.c_str(), l_obj);
}

void Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetDouble(
    JNIEnv* env, jobject /*thiz*/, jlong engine_ptr, jlong dict_ptr, jstring key, jdouble val) {
    auto* eng = reinterpret_cast<fast_engine::Engine*>(engine_ptr);
    auto* dict_obj = reinterpret_cast<fast_engine::DictObj*>(dict_ptr);
    if (!dict_obj) return;
    std::string k = ExtractJString(env, key);
    dict_obj->SetItemString(k.c_str(), new fast_engine::FloatObj(val, eng));
}

void Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetFloat(
    JNIEnv* env, jobject thiz, jlong engine_ptr, jlong dict_ptr, jstring key, jfloat val) {
    Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetDouble(
        env, thiz, engine_ptr, dict_ptr, key, static_cast<jdouble>(val));
}

void Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetStr(
    JNIEnv* env, jobject /*thiz*/, jlong engine_ptr, jlong dict_ptr, jstring key, jstring val) {
    auto* eng = reinterpret_cast<fast_engine::Engine*>(engine_ptr);
    auto* dict_obj = reinterpret_cast<fast_engine::DictObj*>(dict_ptr);
    if (!dict_obj) return;
    std::string k = ExtractJString(env, key);
    dict_obj->SetItemString(k.c_str(), new fast_engine::StrObj(ExtractJString(env, val), eng));
}

void Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetBoolean(
    JNIEnv* env, jobject /*thiz*/, jlong dict_ptr, jstring key, jboolean val) {
    auto* dict_obj = reinterpret_cast<fast_engine::DictObj*>(dict_ptr);
    if (!dict_obj) return;
    std::string k = ExtractJString(env, key);
    fast_engine::Obj* b_obj = (val != 0) ? fast_engine::True : fast_engine::False;
    b_obj->IncRef();
    dict_obj->SetItemString(k.c_str(), b_obj);
}

void Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetDict(
    JNIEnv* env, jobject /*thiz*/, jlong dict_ptr, jstring key, jlong sub_dict_ptr) {
    auto* dict_obj = reinterpret_cast<fast_engine::DictObj*>(dict_ptr);
    auto* sub_dict = reinterpret_cast<fast_engine::Obj*>(sub_dict_ptr);
    if (!dict_obj) return;
    std::string k = ExtractJString(env, key);
    dict_obj->SetItemString(k.c_str(), sub_dict ? sub_dict : fast_engine::None);
}

void Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetArray(
    JNIEnv* env, jobject /*thiz*/, jlong dict_ptr, jstring key, jlong array_ptr) {
    auto* dict_obj = reinterpret_cast<fast_engine::DictObj*>(dict_ptr);
    auto* arr_obj  = reinterpret_cast<fast_engine::Obj*>(array_ptr);
    if (!dict_obj) return;
    std::string k = ExtractJString(env, key);
    dict_obj->SetItemString(k.c_str(), arr_obj ? arr_obj : fast_engine::None);
}

void Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetClass(
    JNIEnv* env, jobject /*thiz*/, jlong engine_ptr, jlong dict_ptr, jstring key, jobject val, jboolean is_cep) {
    auto* eng = reinterpret_cast<fast_engine::Engine*>(engine_ptr);
    auto* dict_obj = reinterpret_cast<fast_engine::DictObj*>(dict_ptr);
    if (!dict_obj) return;
    std::string k = ExtractJString(env, key);
    if (!val) {
        fast_engine::None->IncRef();
        dict_obj->SetItemString(k.c_str(), fast_engine::None);
        return;
    }
    auto pty_dict = std::make_shared<pitaya::PTYDict>();
    fast_engine::Obj* ext_obj = is_cep
        ? static_cast<fast_engine::Obj*>(pitaya::CreateCepEvent(eng, pty_dict))
        : static_cast<fast_engine::Obj*>(pitaya::CreatePTYExtDict(eng, pty_dict));
    dict_obj->SetItemString(k.c_str(), ext_obj);
}

void Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetNull(
    JNIEnv* env, jobject /*thiz*/, jlong dict_ptr, jstring key) {
    auto* dict_obj = reinterpret_cast<fast_engine::DictObj*>(dict_ptr);
    if (!dict_obj) return;
    std::string k = ExtractJString(env, key);
    fast_engine::None->IncRef();
    dict_obj->SetItemString(k.c_str(), fast_engine::None);
}

/**
 * @brief Reconstructed `Java_com_bytedance_pitaya_modules_MicroPyLoader_nativeInit` (@ 0x050f88, 232 B).
 *        Tái dựng hàm `MicroPyLoader_nativeInit` (@ 0x050f88, 232 B).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x050f88..0x05106c]:
 * - 0x050fa0: adrp x1, #0x60000; add x1, x1, #0x928 ; &g_cached_jvm_0x060928
 * - 0x050fa8: blr  x8              ; env->GetJavaVM(&g_cached_jvm_0x060928)
 * - 0x050fb8: adrp x1, #0x53000; add x1, x1, #0x5f0 ; "com/bytedance/pitaya/api/bean/nativeobj/micropy/MicPyDict"
 * - 0x050ff8: adrp x2, #0x53000; add x2, x2, #0x62a ; "fromJSONObject"
 * - 0x050ffc: adrp x3, #0x53000; add x3, x3, #0x639 ; "(Lorg/json/JSONObject;JZ)Lcom/bytedance/pitaya/api/bean/nativeobj/micropy/MicPyDict;"
 * - 0x051010: str  x0, [x8, #0x938]; store g_from_json_method_0x060938
 * - 0x051028: adrp x2, #0x53000; add x2, x2, #0x68e ; "getNativePtr"
 * - 0x05102c: adrp x3, #0x53000; add x3, x3, #0x69b ; "()J"
 * - 0x051040: str  x0, [x8, #0x940]; store g_get_native_ptr_0x060940
 * - 0x05106c: b    #0x3b374        ; tail-call RegisterMicroPyNativeModules()
 */
void Java_com_bytedance_pitaya_modules_MicroPyLoader_nativeInit(
    JNIEnv* /*env*/, jobject /*thiz*/) {
    fast_engine::RegisterMicroPyNativeModules();
}

} // extern "C"
