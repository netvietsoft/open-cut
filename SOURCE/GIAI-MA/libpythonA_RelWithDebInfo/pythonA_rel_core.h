// ============================================================================
// Clean-Room C++17 Core Interfaces for libpythonA_RelWithDebInfo.so (Target 119 / 169)
// Giao diện lõi C++17 sạch cho libpythonA_RelWithDebInfo.so (Mục tiêu 119 / 169)
// ============================================================================
#pragma once

#include "pythonA_rel_types.h"

extern "C" {

// Reconstructed from 0x1042a4..0x104430 (BDPythonVM Sub-Interpreter Pool Dispatcher)
void BDPythonVMDispatchCreateSubInterpreters(int32_t count);
PyInterpreterState* BDPythonVMDispatchGetInterperter();

// Reconstructed from 0x1320e0..0x132154 (BD_PyInterpreterState_SetStuckCallback & CheckStuckCallback)
void BD_PyInterpreterState_SetStuckCallback(PyInterpreterState* interp, BDStuckCallback cb) noexcept;
void BD_Py_CheckStuckCallback(PyThreadState* current_tstate) noexcept;

// Reconstructed from 0x13217c..0x13221c (PyPitayaPackage_InitLock & BDPythonVM_PyThreadStateSetPitayaPackage)
int32_t PyPitayaPackage_InitLock() noexcept;
void BDPythonVM_PyThreadStateSetPitayaPackage(PyThreadState* tstate, void* pkg) noexcept;

// Reconstructed from 0x12dbd4..0x12e1b0 (Frozen Import Modules & Unicode Index Setup)
void BDPythonVMDeallocFrozenImportModules() noexcept;
int32_t BDPythonVMSetupFrozenImportModules(const void* data, size_t size) noexcept;
int32_t BDPythonVMSetupUnicodeTypeRecords(const void* data, size_t size) noexcept;
int32_t BDPythonVMSetupUnicodeExtendedCase(const void* data, size_t size) noexcept;

// Reconstructed from 0x1192d4..0x119424 (BDPythonImportEncryptName)
char* BDPythonImportEncryptName(const char* name, size_t len) noexcept;

} // extern "C"

uint64_t execute_fde_shard_1(uint32_t fde_idx, uint64_t a0, uint64_t a1);
uint64_t execute_fde_shard_2(uint32_t fde_idx, uint64_t a0, uint64_t a1);
uint64_t execute_fde_shard_3(uint32_t fde_idx, uint64_t a0, uint64_t a1);
uint64_t execute_fde_shard_4(uint32_t fde_idx, uint64_t a0, uint64_t a1);
uint64_t execute_fde_shard_5(uint32_t fde_idx, uint64_t a0, uint64_t a1);
