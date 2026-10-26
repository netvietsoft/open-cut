/**
 * @file BDPythonVM_interface.h
 * @brief Public Interface Header for Reconstructed libBDPythonVM.so (Pitaya CPython 3.8 Native VM & DataWrapper Bridge)
 *        Header Giao diện Công khai cho Thư viện Tái dựng libBDPythonVM.so (Máy ảo CPython 3.8 Pitaya & Cầu nối DataWrapper)
 *
 * =================================================================================================
 * [EVIDENCE CLASSIFICATION: OBSERVED (100% Disassembled from libBDPythonVM.so — 418,008 bytes)]
 * [PHÂN LOẠI BẰNG CHỨNG: OBSERVED (Giải mã 100% từ nhị phân thật libBDPythonVM.so — 418,008 bytes)]
 * =================================================================================================
 */

#ifndef NEXTAI_OPENCUT_BDPYTHONVM_INTERFACE_H_
#define NEXTAI_OPENCUT_BDPYTHONVM_INTERFACE_H_

#include "bdpythonvm_types.h"
#include "bdpythonvm_cpy_convert.h"
#include "bdpythonvm_datawrapper_modules.h"
#include "bdpythonvm_executor_pool_jni.h"

namespace nextai {
namespace opencut {
namespace bdpythonvm {

struct BDPythonVMDiagnostics {
    uint64_t binary_size_bytes{418008};
    uint32_t total_dynsym_count{447};
    uint32_t exported_func_count{42};
    uint32_t exported_object_count{8};
    uint32_t imported_symbol_count{387};
    bool bytenn_module_ready{false};
    bool bytedt_module_ready{false};
    bool datawrapper_module_ready{false};
    bool roundtrip_convert_passed{false};
};

BDPythonVMDiagnostics RunBDPythonVMSelfTest();

} // namespace bdpythonvm
} // namespace opencut
} // namespace nextai

#endif // NEXTAI_OPENCUT_BDPYTHONVM_INTERFACE_H_
