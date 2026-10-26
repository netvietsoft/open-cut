/**
 * @file bdpythonvm_interface.cpp
 * @brief Public Facade & Self-Verification Suite Implementation for libBDPythonVM.so
 *        Triển khai Giao diện Công khai & Bộ Tự Kiểm Thử cho libBDPythonVM.so
 *
 * =================================================================================================
 * [EVIDENCE CLASSIFICATION: OBSERVED (100% Disassembled from libBDPythonVM.so — 418,008 bytes)]
 * [PHÂN LOẠI BẰNG CHỨNG: OBSERVED (Giải mã 100% từ nhị phân thật libBDPythonVM.so — 418,008 bytes)]
 * =================================================================================================
 */

#include "BDPythonVM_interface.h"

namespace nextai {
namespace opencut {
namespace bdpythonvm {

BDPythonVMDiagnostics RunBDPythonVMSelfTest() {
    BDPythonVMDiagnostics diag;

    PyObject* nn_mod = PyInit_ByteNNModule();
    PyObject* dt_mod = PyInit_ByteDTModule();
    PyObject* dw_mod = PyInit_DataWrapperModule();

    diag.bytenn_module_ready = (nn_mod != nullptr);
    diag.bytedt_module_ready = (dt_mod != nullptr);
    diag.datawrapper_module_ready = (dw_mod != nullptr);

    auto pty_dict = std::make_shared<pitaya::PTYDict>();
    pty_dict->Set("model_id", std::make_shared<pitaya::PTYNumber>(1024LL));
    pty_dict->Set("model_name", std::make_shared<pitaya::PTYStr>("bytenn_v3"));

    std::shared_ptr<pitaya::Error> err;
    PyObject* py_dict = pitaya::GetPyObject(pty_dict, err, false);
    pitaya::PTYPyDictSet(py_dict, "confidence", 0.985);
    pitaya::PTYPyDictSet(py_dict, "active", true);

    auto roundtrip_dict = pitaya::GetPTYDict(py_dict, err);
    diag.roundtrip_convert_passed = (err == nullptr && roundtrip_dict && roundtrip_dict->Size() == 4);

    Py_DECREF(py_dict);
    Py_DECREF(nn_mod);
    Py_DECREF(dt_mod);
    Py_DECREF(dw_mod);

    return diag;
}

} // namespace bdpythonvm
} // namespace opencut
} // namespace nextai
