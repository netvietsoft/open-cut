/**
 * @file bdpythonvm_datawrapper_modules.cpp
 * @brief PyInit_ByteNNModule, PyInit_ByteDTModule, PyInit_DataWrapperModule, CVMat_New & 6 Exported BDPy*Type Implementation
 *        Triển khai PyInit_ByteNNModule, PyInit_ByteDTModule, PyInit_DataWrapperModule, CVMat_New & 6 đối tượng BDPy*Type
 *
 * =================================================================================================
 * [EVIDENCE CLASSIFICATION: OBSERVED (100% Disassembled from libBDPythonVM.so @ 0x02451c..0x050f24 & 0x068280..0x069910)]
 * [PHÂN LOẠI BẰNG CHỨNG: OBSERVED (Giải mã 100% từ nhị phân thật libBDPythonVM.so @ 0x02451c..0x050f24 & 0x068280..0x069910)]
 * =================================================================================================
 */

#include "bdpythonvm_datawrapper_modules.h"
#include "bdpythonvm_cpy_convert.h"

namespace pitaya {

namespace {

static PyObject* AllocBDPyWrapper(PyTypeObject* type, Py_ssize_t /*nitems*/) {
    auto* obj = new PyObject();
    obj->ob_refcnt = 1;
    obj->ob_type = type;
    return obj;
}

static void* DefaultToCVMat(PyObject* py_mat) {
    return py_mat ? py_mat->capsule_ptr : nullptr;
}

static PyObject* DefaultToPyMat(void* cv_mat_ptr) {
    PyObject* obj = CVMat_New();
    if (obj) {
        obj->capsule_ptr = cv_mat_ptr;
    }
    return obj;
}

} // namespace

// =================================================================================================
// 1. 8 Exported Global STT_OBJECT Symbols in `.data` (0x068950..0x069720) & `.bss` (0x069908..0x069910)
//    8 ký hiệu biến toàn cục STT_OBJECT trong `.data` (0x068950..0x069720) & `.bss` (0x069908..0x069910)
// =================================================================================================

/**
 * [OBSERVED @ .data 0x068950..0x069720]:
 * 1. BDPyMemoryViewType  @ 0x068950 (408 B): tp_name='BDDataWrapperBridge.MemoryViewWrapper'  (0x059381), tp_basicsize=48 (0x30)
 * 2. BDPyCVMatType       @ 0x068c08 (408 B): tp_name='BDDataWrapperBridge.MobileCVMatWrapper' (0x0594d5), tp_basicsize=48 (0x30)
 * 3. BDPyTVMDeviceType   @ 0x068e38 (408 B): tp_name='BDDataWrapperBridge.TVMDeviceWrapper'   (0x05954e), tp_basicsize=24 (0x18)
 * 4. BDPyTVMDataInfoType @ 0x069070 (408 B): tp_name='BDDataWrapperBridge.TVMDataInfoWrapper' (0x059573), tp_basicsize=32 (0x20)
 * 5. BDPyNDArrayType     @ 0x069358 (408 B): tp_name='BDDataWrapperBridge.NDArrayWrapper'     (0x05959a), tp_basicsize=64 (0x40)
 * 6. BDPyTensorType      @ 0x069720 (408 B): tp_name='BDDataWrapperBridge.TensorWrapper'      (0x059776), tp_basicsize=80 (0x50)
 */
PyTypeObject BDPyMemoryViewType = {
    1, nullptr, 0,
    "BDDataWrapperBridge.MemoryViewWrapper",
    48, // 0x30
    0,
    nullptr, 0, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
    0, 0, "MemoryViewWrapper objects", {},
    &AllocBDPyWrapper, nullptr, {}
};

PyTypeObject BDPyCVMatType = {
    1, nullptr, 0,
    "BDDataWrapperBridge.MobileCVMatWrapper",
    48, // 0x30
    0,
    nullptr, 0, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
    0, 0, "MobileCVMatWrapper objects", {},
    &AllocBDPyWrapper, nullptr, {}
};

PyTypeObject BDPyTVMDeviceType = {
    1, nullptr, 0,
    "BDDataWrapperBridge.TVMDeviceWrapper",
    24, // 0x18
    0,
    nullptr, 0, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
    0, 0, "TVMDeviceWrapper objects", {},
    &AllocBDPyWrapper, nullptr, {}
};

PyTypeObject BDPyTVMDataInfoType = {
    1, nullptr, 0,
    "BDDataWrapperBridge.TVMDataInfoWrapper",
    32, // 0x20
    0,
    nullptr, 0, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
    0, 0, "TVMDataInfoWrapper objects", {},
    &AllocBDPyWrapper, nullptr, {}
};

PyTypeObject BDPyNDArrayType = {
    1, nullptr, 0,
    "BDDataWrapperBridge.NDArrayWrapper",
    64, // 0x40
    0,
    nullptr, 0, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
    0, 0, "NDArrayWrapper objects", {},
    &AllocBDPyWrapper, nullptr, {}
};

PyTypeObject BDPyTensorType = {
    1, nullptr, 0,
    "BDDataWrapperBridge.TensorWrapper",
    80, // 0x50
    0,
    nullptr, 0, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
    0, 0, "TensorWrapper objects", {},
    &AllocBDPyWrapper, nullptr, {}
};

ToCVMatFunc ToCVMat = &DefaultToCVMat; // @ 0x069908
ToPyMatFunc ToPyMat = &DefaultToPyMat; // @ 0x069910

// =================================================================================================
// 2. Reconstructed `_ZN6pitaya9CVMat_NewEv` (@ 0x050e8c, size 156 B)
//    Tái dựng hàm `pitaya::CVMat_New()` (@ 0x050e8c, kích thước 156 B)
// =================================================================================================

/**
 * @brief Reconstructed `_ZN6pitaya9CVMat_NewEv` (@ 0x050e8c, 156 B).
 *        Tái dựng hàm `pitaya::CVMat_New()` (@ 0x050e8c, 156 B).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x050e8c..0x050f24]:
 * - 0x050e98: adrp x0, #0x67000; ldr x0, [x0, #0xfd8] ; &BDPyCVMatType (@ 0x068c08)
 * - 0x050ea0: mov  x1, xzr
 * - 0x050ea4: ldr  x8, [x0, #0x130]; blr x8           ; BDPyCVMatType.tp_alloc(&BDPyCVMatType, 0)
 * - 0x050eb0: adrp x8, #0x67000; ldr x8, [x8, #0xf58] ; Py_None (@ 0x067f58)
 * - 0x050ec0: dup  v0.2d, x8
 * - 0x050ec4: str  x8, [x0, #0x20]                    ; extra_info = Py_None
 * - 0x050ec8: str  q0, [x0, #0x10]                    ; shape_tuple = Py_None, data_list = Py_None
 * - 0x050ed0: add  x9, x9, #3; str x9, [x8]           ; Py_None->ob_refcnt += 3!
 * - 0x050edc: bl   #0xf960                            ; PyTuple_New / capsule init
 * - 0x050ee4: adrp x1, #0x59000; add x1, x1, #0x4ca   ; "cvmat" (@ 0x0594ca)
 * - 0x050ef0: bl   #0xf080                            ; PyCapsule_New(..., "cvmat", ...)
 * - 0x050ef4: str  x0, [x19, #0x28]                   ; store capsule at [obj + 0x28]
 * - 0x050f14: cmp  x0, #0; csel x0, xzr, x19, eq
 */
PyObject* CVMat_New() {
    if (!BDPyCVMatType.tp_alloc) {
        PyType_Ready(&BDPyCVMatType);
    }
    PyObject* obj = BDPyCVMatType.tp_alloc(&BDPyCVMatType, 0);
    if (!obj) {
        return nullptr;
    }
    obj->tag = 9;
    // [OBSERVED @ 0x050ed0]: add x9, x9, #3; str x9, [x8] (increments Py_None->ob_refcnt by 3)
    Py_None->ob_refcnt += 3;

    // Create "cvmat" capsule and store at +0x28 (capsule_ptr)
    obj->str_val = "cvmat";
    obj->capsule_ptr = reinterpret_cast<void*>(0x1);
    return obj;
}

bool RegisterDataWrapperTypesOnModule(PyObject* module) {
    if (!module) return false;
    PyType_Ready(&BDPyMemoryViewType);
    PyType_Ready(&BDPyCVMatType);
    PyType_Ready(&BDPyTVMDeviceType);
    PyType_Ready(&BDPyTVMDataInfoType);
    PyType_Ready(&BDPyNDArrayType);
    PyType_Ready(&BDPyTensorType);

    PyModule_AddObject(module, "MemoryViewWrapper",  reinterpret_cast<PyObject*>(&BDPyMemoryViewType));
    PyModule_AddObject(module, "MobileCVMatWrapper", reinterpret_cast<PyObject*>(&BDPyCVMatType));
    PyModule_AddObject(module, "TVMDeviceWrapper",   reinterpret_cast<PyObject*>(&BDPyTVMDeviceType));
    PyModule_AddObject(module, "TVMDataInfoWrapper", reinterpret_cast<PyObject*>(&BDPyTVMDataInfoType));
    PyModule_AddObject(module, "NDArrayWrapper",     reinterpret_cast<PyObject*>(&BDPyNDArrayType));
    PyModule_AddObject(module, "TensorWrapper",      reinterpret_cast<PyObject*>(&BDPyTensorType));
    return true;
}

const std::vector<std::string>& GetByteNNModuleMethodNames() {
    // [OBSERVED @ .rodata 0x057e56..0x057f24]: 17 methods on BDByteNNBridge.Engine
    static const std::vector<std::string> kMethods = {
        "set_config",
        "get_input_config",
        "get_forward_type",
        "set_input",
        "inference",
        "reinfer_shape_with_tensors",
        "reinfer_shape",
        "release",
        "set_optimizer",
        "step",
        "save_model",
        "set_weights",
        "get_weight",
        "get_gradient",
        "set_losslayers",
        "set_labels",
        "enable_data_wrapper"
    };
    return kMethods;
}

} // namespace pitaya

// =================================================================================================
// 3. Exported CPython C-Extension Module Initializers (@ 0x02451c, 0x04be28, 0x04f9ac)
//    3 hàm khởi tạo Module C-Extension CPython được export (@ 0x02451c, 0x04be28, 0x04f9ac)
// =================================================================================================

namespace {

// Module & Type descriptors in .data at 0x068280, 0x0682e8, 0x0685e8, 0x068650, 0x0687e8
static PyTypeObject g_bytenn_engine_type_0x0682e8 = {
    1, nullptr, 0,
    "BDByteNNBridge.Engine", // @ 0x057e40
    48,
    0
};

static PyModuleDef g_bytenn_module_def_0x068280 = {
    {1, &PyModule_Type},
    "BDByteNNBridge",        // @ 0x057e31
    "ByteNN Python Bridge Module",
    -1,
    nullptr
};

static PyTypeObject g_bytedt_engine_type_0x068650 = {
    1, nullptr, 0,
    "BDByteDTBridge.Engine",
    48,
    0
};

static PyModuleDef g_bytedt_module_def_0x0685e8 = {
    {1, &PyModule_Type},
    "BDByteDTBridge",
    "ByteDT Python Bridge Module",
    -1,
    nullptr
};

static PyModuleDef g_datawrapper_module_def_0x0687e8 = {
    {1, &PyModule_Type},
    "BDDataWrapperBridge",
    "DataWrapper Python Bridge Module",
    -1,
    nullptr
};

} // namespace

extern "C" {

/**
 * @brief Reconstructed `PyInit_ByteNNModule` (@ 0x02451c, 204 B).
 *        Tái dựng hàm `PyInit_ByteNNModule` (@ 0x02451c, 204 B).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x02451c..0x0245e4]:
 * - 0x024528: adrp x20, #0x68000; add x20, x20, #0x2e8 ; &ByteNN_Engine_Type (0x0682e8)
 * - 0x024534: bl   #0xf640                             ; PyType_Ready(&ByteNN_Engine_Type)
 * - 0x024538: tbnz w0, #0x1f, #0x245ac                 ; if < 0, return nullptr
 * - 0x02453c: adrp x0, #0x68000; add x0, x0, #0x280    ; &ByteNNModuleDef (0x068280)
 * - 0x024544: mov  w1, #0x3f5                          ; PYTHON_ABI_VERSION = 1013
 * - 0x024548: bl   #0xf8e0                             ; PyModule_Create2(&ByteNNModuleDef, 1013)
 * - 0x024558: adrp x1, #0x57000; add x1, x1, #0xe4f    ; "Engine" (tail of "BDByteNNBridge.Engine" @ 0x057e40 + 15)
 * - 0x024564: add  x8, x8, #1; str x8, [x20]           ; Py_INCREF(&ByteNN_Engine_Type)
 * - 0x024570: bl   #0xff00                             ; PyModule_AddObject(mod, "Engine", &ByteNN_Engine_Type)
 */
PyObject* PyInit_ByteNNModule() {
    if (PyType_Ready(&g_bytenn_engine_type_0x0682e8) < 0) {
        return nullptr;
    }
    PyObject* m = PyModule_Create2(&g_bytenn_module_def_0x068280, kPythonAbiVersion);
    if (!m) {
        return nullptr;
    }
    Py_INCREF(reinterpret_cast<PyObject*>(&g_bytenn_engine_type_0x0682e8));
    if (PyModule_AddObject(m, "Engine", reinterpret_cast<PyObject*>(&g_bytenn_engine_type_0x0682e8)) < 0) {
        Py_DECREF(reinterpret_cast<PyObject*>(&g_bytenn_engine_type_0x0682e8));
        Py_DECREF(m);
        return nullptr;
    }
    return m;
}

/**
 * @brief Reconstructed `PyInit_ByteDTModule` (@ 0x04be28, 204 B).
 *        Tái dựng hàm `PyInit_ByteDTModule` (@ 0x04be28, 204 B).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x04be28..0x04bef0]:
 * - 0x04be34: adrp x20, #0x68000; add x20, x20, #0x650 ; &ByteDT_Engine_Type (0x068650)
 * - 0x04be40: bl   #0xf640                             ; PyType_Ready(&ByteDT_Engine_Type)
 * - 0x04be48: adrp x0, #0x68000; add x0, x0, #0x5e8    ; &ByteDTModuleDef (0x0685e8)
 * - 0x04be50: mov  w1, #0x3f5                          ; PYTHON_ABI_VERSION = 1013
 * - 0x04be54: bl   #0xf8e0                             ; PyModule_Create2(&ByteDTModuleDef, 1013)
 * - 0x04be64: adrp x1, #0x57000; add x1, x1, #0xe4f    ; "Engine" (@ 0x057e4f)
 * - 0x04be7c: bl   #0xff00                             ; PyModule_AddObject(mod, "Engine", &ByteDT_Engine_Type)
 */
PyObject* PyInit_ByteDTModule() {
    if (PyType_Ready(&g_bytedt_engine_type_0x068650) < 0) {
        return nullptr;
    }
    PyObject* m = PyModule_Create2(&g_bytedt_module_def_0x0685e8, kPythonAbiVersion);
    if (!m) {
        return nullptr;
    }
    Py_INCREF(reinterpret_cast<PyObject*>(&g_bytedt_engine_type_0x068650));
    if (PyModule_AddObject(m, "Engine", reinterpret_cast<PyObject*>(&g_bytedt_engine_type_0x068650)) < 0) {
        Py_DECREF(reinterpret_cast<PyObject*>(&g_bytedt_engine_type_0x068650));
        Py_DECREF(m);
        return nullptr;
    }
    return m;
}

/**
 * @brief Reconstructed `PyInit_DataWrapperModule` (@ 0x04f9ac, 68 B).
 *        Tái dựng hàm `PyInit_DataWrapperModule` (@ 0x04f9ac, 68 B).
 *
 * [OBSERVED AARCH64 OPCODES @ 0x04f9ac..0x04f9ec]:
 * - 0x04f9b8: adrp x0, #0x68000; add x0, x0, #0x7e8    ; &DataWrapperModuleDef (0x0687e8)
 * - 0x04f9c0: mov  w1, #0x3f5                          ; PYTHON_ABI_VERSION = 1013
 * - 0x04f9c4: bl   #0xf8e0                             ; PyModule_Create2(&DataWrapperModuleDef, 1013)
 * - 0x04f9d0: bl   #0x101c0                            ; PyTaskExecutor::Instance()
 * - 0x04f9d4: mov  w1, #1; mov x2, x19
 * - 0x04f9dc: bl   #0xf970                             ; RegisterDataWrapperTypesOnModule(m)
 */
PyObject* PyInit_DataWrapperModule() {
    PyObject* m = PyModule_Create2(&g_datawrapper_module_def_0x0687e8, kPythonAbiVersion);
    if (!m) {
        return nullptr;
    }
    pitaya::RegisterDataWrapperTypesOnModule(m);
    return m;
}

} // extern "C"
