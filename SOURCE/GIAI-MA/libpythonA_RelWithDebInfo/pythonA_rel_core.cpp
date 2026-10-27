// ============================================================================
// Clean-Room C++17 Core Implementation for libpythonA_RelWithDebInfo.so (Target 119 / 169)
// Hiện thực C++17 sạch lõi cho libpythonA_RelWithDebInfo.so (Sub-Interpreter Pool & Stuck Callback)
// ============================================================================
#include "pythonA_rel_core.h"
#include <cstdlib>
#include <cstring>

namespace {
int32_t g_subinterpreters_created = 0; // .bss @ 0x1ff8a8
int32_t g_subinterpreter_count = 0;    // .bss @ 0x1ffca0
std::vector<PyInterpreterState*> g_interpreters;
std::mutex g_interp_mutex;
} // namespace

extern "C" {

// Reconstructed from 0x1042a4..0x104358:
//   0x1042c0: B94002E8 ldr  w8, [x23]
//   0x1042c4: 7100051F cmp  w8, #1
//   0x1042c8: 54000400 b.eq #0x104348
//   0x1042d8: 7100041F cmp  w0, #1
//   0x1042dc: B9000100 str  w0, [x8]
void BDPythonVMDispatchCreateSubInterpreters(int32_t count) {
    std::lock_guard<std::mutex> lock(g_interp_mutex);
    if (g_subinterpreters_created == 1) {
        return;
    }
    g_subinterpreter_count = count;
    if (count >= 1) {
        for (int32_t i = 0; i < count; ++i) {
            auto* interp = new PyInterpreterState();
            if (!g_interpreters.empty()) {
                interp->next = g_interpreters.front();
            }
            g_interpreters.insert(g_interpreters.begin(), interp);
        }
    }
    g_subinterpreters_created = 1; // 0x104340: mov w8, #1; str w8, [x23]
}

// Reconstructed from 0x10435c..0x104430:
//   0x104390: 110006A8 add  w8, w21, #1
//   0x104394: 1AC80E69 sdiv w9, w19, w8
//   0x104398: 1B08CD28 msub w8, w9, w8, w19
//   0x1043c4: 9109E008 add  x8, x0, #0x278
//   0x1043c8: 88DFFD08 ldar w8, [x8]
//   0x1043cc: 340002A8 cbz  w8, #0x104420
PyInterpreterState* BDPythonVMDispatchGetInterperter() {
    std::lock_guard<std::mutex> lock(g_interp_mutex);
    if (g_interpreters.empty()) {
        return nullptr;
    }
    if (g_subinterpreter_count == 0) {
        return g_interpreters.front();
    }
    int32_t r = std::rand();
    int32_t mod = g_subinterpreter_count + 1;
    int32_t steps = (r % mod) + 1;
    PyInterpreterState* cur = g_interpreters.front();
    while (steps > 1 && cur && cur->next) {
        cur = cur->next;
        --steps;
    }
    if (cur && cur->is_busy.load(std::memory_order_acquire) == 0) {
        return cur;
    }
    for (PyInterpreterState* it : g_interpreters) {
        if (it->is_busy.load(std::memory_order_acquire) == 0) {
            return it;
        }
    }
    return g_interpreters.front();
}

// Reconstructed from 0x1320e0..0x1320ec:
//   0x1320e0: 5296A108 mov  w8, #0xb508
//   0x1320e4: 72A00028 movk w8, #1, lsl #16
//   0x1320e8: F8286801 str  x1, [x0, x8]
//   0x1320ec: D65F03C0 ret
void BD_PyInterpreterState_SetStuckCallback(PyInterpreterState* interp, BDStuckCallback cb) noexcept {
    if (!interp) return;
    interp->stuck_callback = cb;
}

// Reconstructed from 0x1320f0..0x132154:
//   0x13210c: F9400800 ldr  x0, [x0, #0x10]
//   0x132114: 5296A108 mov  w8, #0xb508
//   0x132118: 72A00028 movk w8, #1, lsl #16
//   0x13211c: F8686801 ldr  x1, [x0, x8]
//   0x132128: D61F0020 br   x1
void BD_Py_CheckStuckCallback(PyThreadState* current_tstate) noexcept {
    if (!current_tstate || !current_tstate->interp) return;
    PyInterpreterState* interp = current_tstate->interp;
    if (interp->stuck_callback) {
        interp->stuck_callback(interp);
    }
}

} // extern "C"
