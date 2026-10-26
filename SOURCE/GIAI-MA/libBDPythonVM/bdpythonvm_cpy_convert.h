/**
 * @file bdpythonvm_cpy_convert.h
 * @brief Pitaya <-> CPython 3.8 Object Conversion & 11 PTYPyDictSet Overloads Header
 *        Header Chuyển đổi Đối tượng Pitaya <-> CPython 3.8 & 11 Hàm nạp chồng PTYPyDictSet
 *
 * =================================================================================================
 * [EVIDENCE CLASSIFICATION: OBSERVED (100% Disassembled from libBDPythonVM.so @ 0x04ca3c..0x04efd4)]
 * [PHÂN LOẠI BẰNG CHỨNG: OBSERVED (Giải mã 100% từ nhị phân thật libBDPythonVM.so @ 0x04ca3c..0x04efd4)]
 * =================================================================================================
 *
 * Exported Functions Covered / Các hàm Export được tái dựng trong module này:
 * 1.  _ZN6pitaya4TaskD2Ev                                                                    (@ 0x04ca3c, 1,136 B)
 * 2.  _ZN6pitaya11GetPyObjectERKNSt6__ndk110shared_ptrINS_9PTYObjectEEERNS1_INS_5ErrorEEEb    (@ 0x04d6d8, 20 B)
 * 3.  _ZN6pitaya14EnvGetPyObjectERKNSt6__ndk110shared_ptrINS_9PTYObjectEEERNS1_INS_5ErrorEEEPvb (@ 0x04db38, 16 B)
 * 4.  _ZN6pitaya10GetPTYDictEP7_objectRNSt6__ndk110shared_ptrINS_5ErrorEEE                   (@ 0x04e788, 200 B)
 * 5.  _ZN6pitaya17PTYPyObjectStringEP7_object                                                (@ 0x04e918, 128 B)
 * 6.  _ZN6pitaya12PTYPyDictSetEP7_objectPKcS1_                                               (@ 0x04e998, 108 B)
 * 7.  _ZN6pitaya12PTYPyDictSetEP7_objectPKcb                                                 (@ 0x04ea04, 124 B)
 * 8.  _ZN6pitaya12PTYPyDictSetEP7_objectPKci                                                 (@ 0x04ea80, 124 B)
 * 9.  _ZN6pitaya12PTYPyDictSetEP7_objectPKcx                                                 (@ 0x04eafc, 124 B)
 * 10. _ZN6pitaya12PTYPyDictSetEP7_objectPKcl                                                 (@ 0x04eb78, 124 B)
 * 11. _ZN6pitaya12PTYPyDictSetEP7_objectPKcj                                                 (@ 0x04ebf4, 124 B)
 * 12. _ZN6pitaya12PTYPyDictSetEP7_objectPKcy                                                 (@ 0x04ec70, 124 B)
 * 13. _ZN6pitaya12PTYPyDictSetEP7_objectPKcm                                                 (@ 0x04ecec, 124 B)
 * 14. _ZN6pitaya12PTYPyDictSetEP7_objectPKcd                                                 (@ 0x04ed68, 120 B)
 * 15. _ZN6pitaya12PTYPyDictSetEP7_objectPKcRKNSt6__ndk112basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEE (@ 0x04ede0, 144 B)
 * 16. _ZN6pitaya12PTYPyDictSetEP7_objectPKcS3_                                               (@ 0x04ee70, 360 B)
 */

#ifndef NEXTAI_OPENCUT_BDPYTHONVM_CPY_CONVERT_H_
#define NEXTAI_OPENCUT_BDPYTHONVM_CPY_CONVERT_H_

#include "bdpythonvm_types.h"

namespace pitaya {

// Internal conversion kernels disassembled at 0x04d6ec and 0x04db48
PyObject* GetPyObject_Internal(const std::shared_ptr<PTYObject>& pty_obj,
                               bool return_null_on_empty,
                               std::shared_ptr<Error>& out_error,
                               bool is_cep_mode);

std::shared_ptr<PTYObject> GetPTYObject_Internal(PyObject* py_obj,
                                                 bool return_null_on_empty,
                                                 std::shared_ptr<Error>& out_error);

// Exported C++ symbols in namespace pitaya (@ 0x04d6d8..0x04ee70)
PyObject* GetPyObject(const std::shared_ptr<PTYObject>& pty_obj,
                      std::shared_ptr<Error>& out_error,
                      bool is_cep_mode);

PyObject* EnvGetPyObject(const std::shared_ptr<PTYObject>& pty_obj,
                         std::shared_ptr<Error>& out_error,
                         void* env_unused,
                         bool is_cep_mode);

std::shared_ptr<PTYDict> GetPTYDict(PyObject* py_obj,
                                    std::shared_ptr<Error>& out_error);

std::string PTYPyObjectString(PyObject* py_obj);

// 11 overloaded PTYPyDictSet functions (@ 0x04e998..0x04ee70)
bool PTYPyDictSet(PyObject* dict, const char* key, PyObject* val);          // @ 0x04e998
bool PTYPyDictSet(PyObject* dict, const char* key, bool val);               // @ 0x04ea04
bool PTYPyDictSet(PyObject* dict, const char* key, int val);                // @ 0x04ea80
bool PTYPyDictSet(PyObject* dict, const char* key, long long val);          // @ 0x04eafc
bool PTYPyDictSet(PyObject* dict, const char* key, long val);               // @ 0x04eb78
bool PTYPyDictSet(PyObject* dict, const char* key, unsigned int val);       // @ 0x04ebf4
bool PTYPyDictSet(PyObject* dict, const char* key, unsigned long long val); // @ 0x04ec70
bool PTYPyDictSet(PyObject* dict, const char* key, unsigned long val);      // @ 0x04ecec
bool PTYPyDictSet(PyObject* dict, const char* key, double val);             // @ 0x04ed68
bool PTYPyDictSet(PyObject* dict, const char* key, const std::string& val); // @ 0x04ede0
bool PTYPyDictSet(PyObject* dict, const char* key, const char* val);        // @ 0x04ee70

} // namespace pitaya

#endif // NEXTAI_OPENCUT_BDPYTHONVM_CPY_CONVERT_H_
