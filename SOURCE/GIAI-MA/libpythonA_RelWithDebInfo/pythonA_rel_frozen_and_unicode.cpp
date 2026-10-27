// ============================================================================
// Clean-Room C++17 Frozen Import Modules, Unicode Tables & Pitaya Package Lock
// Mô-đun Nhập Đóng Băng, Bảng Unicode & Khóa Gói Pitaya C++17 sạch cho libpythonA_RelWithDebInfo.so
// ============================================================================
#include "pythonA_rel_core.h"
#include <cstdlib>

namespace {
const void* g_unicode_type_records = nullptr;  // .bss @ 0x227150 (_PyUnicode_TypeRecords)
const void* g_unicode_extended_case = nullptr; // .bss @ 0x227148 (_PyUnicode_ExtendedCase)
bool g_pitaya_lock_initialized = false;        // .bss @ 0x227280 (_pitaya_package_lock)
} // namespace

extern "C" {

int32_t PyPitayaPackage_InitLock() noexcept {
    g_pitaya_lock_initialized = true;
    return 0;
}

void BDPythonVM_PyThreadStateSetPitayaPackage(PyThreadState* tstate, void* pkg) noexcept {
    if (tstate) {
        tstate->pitaya_package = pkg;
    }
}

void BDPythonVMDeallocFrozenImportModules() noexcept {}

int32_t BDPythonVMSetupFrozenImportModules(const void* data, size_t size) noexcept {
    return (data != nullptr && size > 0) ? 0 : -1;
}

int32_t BDPythonVMSetupUnicodeTypeRecords(const void* data, size_t size) noexcept {
    if (!data || size == 0) return -1;
    g_unicode_type_records = data;
    return 0;
}

int32_t BDPythonVMSetupUnicodeExtendedCase(const void* data, size_t size) noexcept {
    if (!data || size == 0) return -1;
    g_unicode_extended_case = data;
    return 0;
}

char* BDPythonImportEncryptName(const char* name, size_t len) noexcept {
    size_t alloc_sz = (len << 1) | 1ULL;
    char* out = static_cast<char*>(std::calloc(1, alloc_sz));
    if (!out || !name || len == 0) {
        return out;
    }
    for (size_t i = 0; i < len; ++i) {
        uint32_t w13 = static_cast<uint8_t>(name[i]) ^ kBDPythonImportXorKey;
        uint32_t w15 = static_cast<uint32_t>((static_cast<uint64_t>(w13 & 0xFFU) * kBDPythonImportScalarRecip26) >> 35);
        uint32_t lo = (w13 - (w15 * 26U)) + 0x41U;
        uint32_t hi = w15 + 0x41U;
        out[2 * i]     = static_cast<char>(lo);
        out[2 * i + 1] = static_cast<char>(hi);
    }
    return out;
}

} // extern "C"
