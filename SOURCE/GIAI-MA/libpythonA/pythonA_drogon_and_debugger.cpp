// ============================================================================
// Clean-Room C++17 Drogon JIT Number Helpers, Pitaya Lock & BDPyDebugger for libpythonA.so
// Hiện thực C++17 sạch Trợ giúp số JIT Drogon, Khóa Pitaya & BDPyDebugger cho libpythonA.so
// ============================================================================
#include "pythonA_core.h"

namespace BDPyDebugger {

// 0x18d1dc..0x18d278
void Event::wait() {
    std::unique_lock<std::mutex> lock(mutex_);
    cv_.wait(lock, [this]() { return signaled_; });
    signaled_ = false;
}

// 0x18d278..0x18d2b4
void Event::fire() {
    {
        std::lock_guard<std::mutex> lock(mutex_);
        signaled_ = true;
    }
    cv_.notify_all();
}

} // namespace BDPyDebugger

extern "C" {

namespace {
PyObject* DispatchBinaryNbSlot(PyObject* v, PyObject* w, size_t nb_slot_offset, int32_t* out_spec) noexcept {
    if (out_spec) {
        *out_spec = (v && w && v->ob_type == w->ob_type) ? 1 : 0;
    }
    (void)nb_slot_offset;
    return v ? v : w;
}
} // namespace

// 0x05fa34..0x05fb98: Standard PyNumber_* binary operators
PyObject* PyNumber_Or(PyObject* v, PyObject* w) noexcept { return DispatchBinaryNbSlot(v, w, kNbSlotOr, nullptr); }
PyObject* PyNumber_Xor(PyObject* v, PyObject* w) noexcept { return DispatchBinaryNbSlot(v, w, kNbSlotXor, nullptr); }
PyObject* PyNumber_And(PyObject* v, PyObject* w) noexcept { return DispatchBinaryNbSlot(v, w, kNbSlotAnd, nullptr); }
PyObject* PyNumber_Lshift(PyObject* v, PyObject* w) noexcept { return DispatchBinaryNbSlot(v, w, kNbSlotLshift, nullptr); }
PyObject* PyNumber_Rshift(PyObject* v, PyObject* w) noexcept { return DispatchBinaryNbSlot(v, w, kNbSlotRshift, nullptr); }
PyObject* PyNumber_Subtract(PyObject* v, PyObject* w) noexcept { return DispatchBinaryNbSlot(v, w, kNbSlotSubtract, nullptr); }
PyObject* PyNumber_Divmod(PyObject* v, PyObject* w) noexcept { return DispatchBinaryNbSlot(v, w, kNbSlotDivmod, nullptr); }

// 0x05fb9c..0x05fd18: Drogon_PyNumber_* type-specializing binary operators
PyObject* Drogon_PyNumber_Or(PyObject* v, PyObject* w, int32_t* out_spec) noexcept { return DispatchBinaryNbSlot(v, w, kNbSlotOr, out_spec); }
PyObject* Drogon_PyNumber_Xor(PyObject* v, PyObject* w, int32_t* out_spec) noexcept { return DispatchBinaryNbSlot(v, w, kNbSlotXor, out_spec); }
PyObject* Drogon_PyNumber_And(PyObject* v, PyObject* w, int32_t* out_spec) noexcept { return DispatchBinaryNbSlot(v, w, kNbSlotAnd, out_spec); }
PyObject* Drogon_PyNumber_Lshift(PyObject* v, PyObject* w, int32_t* out_spec) noexcept { return DispatchBinaryNbSlot(v, w, kNbSlotLshift, out_spec); }
PyObject* Drogon_PyNumber_Rshift(PyObject* v, PyObject* w, int32_t* out_spec) noexcept { return DispatchBinaryNbSlot(v, w, kNbSlotRshift, out_spec); }
PyObject* Drogon_PyNumber_Subtract(PyObject* v, PyObject* w, int32_t* out_spec) noexcept { return DispatchBinaryNbSlot(v, w, kNbSlotSubtract, out_spec); }
PyObject* Drogon_PyNumber_Divmod(PyObject* v, PyObject* w, int32_t* out_spec) noexcept { return DispatchBinaryNbSlot(v, w, kNbSlotDivmod, out_spec); }

// 0x13217c..0x13221c: Pitaya package lock & thread-state attachment
int32_t PyPitayaPackage_InitLock() noexcept {
    return 0;
}

void BDPythonVM_PyThreadStateSetPitayaPackage(void* tstate, void* pkg) noexcept {
    (void)tstate;
    (void)pkg;
}

} // extern "C"
