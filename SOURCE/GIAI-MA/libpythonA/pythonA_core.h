// ============================================================================
// Clean-Room C++17 Core Interfaces for libpythonA.so (Target 118 / 169)
// Giao diện lõi C++17 sạch cho libpythonA.so (Mục tiêu 118 / 169)
// ============================================================================
#pragma once

#include "pythonA_types.h"

extern "C" {

// Reconstructed from 0x05db1c..0x05de00 (PyToken_OneChar, TwoChars, ThreeChars)
int32_t PyToken_OneChar(int32_t c) noexcept;
int32_t PyToken_TwoChars(int32_t c1, int32_t c2) noexcept;
int32_t PyToken_ThreeChars(int32_t c1, int32_t c2, int32_t c3) noexcept;

// Reconstructed from 0x05e130..0x05e260 (PyObject_Type, PyObject_Size, PyObject_Length)
PyObject* PyObject_Type(PyObject* o) noexcept;
Py_ssize_t PyObject_Size(PyObject* o) noexcept;
Py_ssize_t PyObject_Length(PyObject* o) noexcept;

// Reconstructed from 0x05fa34..0x0602a8 (PyNumber_* & Drogon_PyNumber_* JIT specialization helpers)
PyObject* PyNumber_Or(PyObject* v, PyObject* w) noexcept;
PyObject* PyNumber_Xor(PyObject* v, PyObject* w) noexcept;
PyObject* PyNumber_And(PyObject* v, PyObject* w) noexcept;
PyObject* PyNumber_Lshift(PyObject* v, PyObject* w) noexcept;
PyObject* PyNumber_Rshift(PyObject* v, PyObject* w) noexcept;
PyObject* PyNumber_Subtract(PyObject* v, PyObject* w) noexcept;
PyObject* PyNumber_Divmod(PyObject* v, PyObject* w) noexcept;

PyObject* Drogon_PyNumber_Or(PyObject* v, PyObject* w, int32_t* out_spec) noexcept;
PyObject* Drogon_PyNumber_Xor(PyObject* v, PyObject* w, int32_t* out_spec) noexcept;
PyObject* Drogon_PyNumber_And(PyObject* v, PyObject* w, int32_t* out_spec) noexcept;
PyObject* Drogon_PyNumber_Lshift(PyObject* v, PyObject* w, int32_t* out_spec) noexcept;
PyObject* Drogon_PyNumber_Rshift(PyObject* v, PyObject* w, int32_t* out_spec) noexcept;
PyObject* Drogon_PyNumber_Subtract(PyObject* v, PyObject* w, int32_t* out_spec) noexcept;
PyObject* Drogon_PyNumber_Divmod(PyObject* v, PyObject* w, int32_t* out_spec) noexcept;

// Reconstructed from 0x080ba4..0x080bf0 (BDPythonVMPreInit)
int32_t BDPythonVMPreInit(uint8_t* vm_state) noexcept;

// Reconstructed from 0x1192d4..0x119424 (BDPythonImportEncryptName — NEON/Scalar Base-26 XOR-7)
char* BDPythonImportEncryptName(const char* name, size_t len) noexcept;

// Reconstructed from 0x13217c..0x13221c (PyPitayaPackage_InitLock & BDPythonVM_PyThreadStateSetPitayaPackage)
int32_t PyPitayaPackage_InitLock() noexcept;
void BDPythonVM_PyThreadStateSetPitayaPackage(void* tstate, void* pkg) noexcept;

} // extern "C"

std::string BDPythonDecryptImportName(const char* enc, size_t enc_len);

uint64_t execute_fde_shard_1(uint32_t fde_idx, uint64_t a0, uint64_t a1);
uint64_t execute_fde_shard_2(uint32_t fde_idx, uint64_t a0, uint64_t a1);
uint64_t execute_fde_shard_3(uint32_t fde_idx, uint64_t a0, uint64_t a1);
uint64_t execute_fde_shard_4(uint32_t fde_idx, uint64_t a0, uint64_t a1);
uint64_t execute_fde_shard_5(uint32_t fde_idx, uint64_t a0, uint64_t a1);
