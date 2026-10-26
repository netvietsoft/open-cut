/**
 * @file bdpythonvm_datawrapper_modules.h
 * @brief PyInit_ByteNNModule, PyInit_ByteDTModule, PyInit_DataWrapperModule, CVMat_New & 6 Exported BDPy*Type Objects
 *        PyInit_ByteNNModule, PyInit_ByteDTModule, PyInit_DataWrapperModule, CVMat_New & 6 đối tượng BDPy*Type được export
 *
 * =================================================================================================
 * [EVIDENCE CLASSIFICATION: OBSERVED (100% Disassembled from libBDPythonVM.so @ 0x02451c..0x050f24 & 0x068280..0x069910)]
 * [PHÂN LOẠI BẰNG CHỨNG: OBSERVED (Giải mã 100% từ nhị phân thật libBDPythonVM.so @ 0x02451c..0x050f24 & 0x068280..0x069910)]
 * =================================================================================================
 *
 * Exported Functions & Objects Covered / Các hàm & đối tượng Export được tái dựng trong module này:
 * 1. PyInit_ByteNNModule               (@ 0x02451c, 204 B)
 * 2. PyInit_ByteDTModule               (@ 0x04be28, 204 B)
 * 3. PyInit_DataWrapperModule          (@ 0x04f9ac,  68 B)
 * 4. _ZN6pitaya9CVMat_NewEv            (@ 0x050e8c, 156 B)
 * 5. _ZN6pitaya18BDPyMemoryViewTypeE   (@ 0x068950, 408 B: tp_name="BDDataWrapperBridge.MemoryViewWrapper", tp_basicsize=48)
 * 6. _ZN6pitaya13BDPyCVMatTypeE        (@ 0x068c08, 408 B: tp_name="BDDataWrapperBridge.MobileCVMatWrapper", tp_basicsize=48)
 * 7. _ZN6pitaya17BDPyTVMDeviceTypeE    (@ 0x068e38, 408 B: tp_name="BDDataWrapperBridge.TVMDeviceWrapper", tp_basicsize=24)
 * 8. _ZN6pitaya19BDPyTVMDataInfoTypeE  (@ 0x069070, 408 B: tp_name="BDDataWrapperBridge.TVMDataInfoWrapper", tp_basicsize=32)
 * 9. _ZN6pitaya15BDPyNDArrayTypeE      (@ 0x069358, 408 B: tp_name="BDDataWrapperBridge.NDArrayWrapper", tp_basicsize=64)
 * 10. _ZN6pitaya14BDPyTensorTypeE      (@ 0x069720, 408 B: tp_name="BDDataWrapperBridge.TensorWrapper", tp_basicsize=80)
 * 11. _ZN6pitaya7ToCVMatE              (@ 0x069908,   8 B)
 * 12. _ZN6pitaya7ToPyMatE              (@ 0x069910,   8 B)
 */

#ifndef NEXTAI_OPENCUT_BDPYTHONVM_DATAWRAPPER_MODULES_H_
#define NEXTAI_OPENCUT_BDPYTHONVM_DATAWRAPPER_MODULES_H_

#include "bdpythonvm_types.h"

namespace pitaya {

// Exported C++ symbol at 0x050e8c (_ZN6pitaya9CVMat_NewEv)
PyObject* CVMat_New();

// Internal registration helper called by PyInit_DataWrapperModule (@ 0x04f9dc -> #0xf970)
bool RegisterDataWrapperTypesOnModule(PyObject* module);

const std::vector<std::string>& GetByteNNModuleMethodNames();

} // namespace pitaya

extern "C" {

// Exported CPython C-Extension Module Initializers (@ 0x02451c, 0x04be28, 0x04f9ac)
PyObject* PyInit_ByteNNModule();
PyObject* PyInit_ByteDTModule();
PyObject* PyInit_DataWrapperModule();

} // extern "C"

#endif // NEXTAI_OPENCUT_BDPYTHONVM_DATAWRAPPER_MODULES_H_
