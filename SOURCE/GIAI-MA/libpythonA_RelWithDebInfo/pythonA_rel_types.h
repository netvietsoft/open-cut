// ============================================================================
// Clean-Room C++17 ABI & Data Structures for libpythonA_RelWithDebInfo.so (Target 119 / 169)
// Cấu trúc dữ liệu & ABI C++17 sạch cho libpythonA_RelWithDebInfo.so (Mục tiêu 119 / 169)
// Binary Size: 2,229,160 bytes | SHA-256: adac15b692d2291567fdf9f43ae7d9f5e1d7cfec70c8db6c9b85109118cd92fe
// .dynsym: 1,998 Exported Symbols @ 0x007c58 | .eh_frame_hdr: 4,320 FDEs @ 0x1c9550
// ============================================================================
#pragma once

#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>
#include <atomic>
#include <mutex>

// Constants verified directly from AArch64 opcodes in libpythonA_RelWithDebInfo.so
// Các hằng số xác minh trực tiếp từ mã máy AArch64 trong libpythonA_RelWithDebInfo.so
constexpr size_t kPyInterpreterBusyFlagOffset = 0x278;     // add x8, x0, #0x278; ldar w8, [x8] @ 0x1043c4
constexpr size_t kPyInterpreterStuckCbOffset = 0x0001B508; // mov w8, #0xb508; movk w8, #1, lsl #16 @ 0x1320e0 (111,880 B)
constexpr size_t kPyThreadStateInterpOffset = 0x10;        // ldr x0, [x0, #0x10] @ 0x13210c
constexpr size_t kPyThreadStatePitayaPkgOffset = 0x178;    // BDPythonVM_PyThreadStateSetPitayaPackage @ 0x1321dc
constexpr uint8_t kBDPythonImportXorKey = 0x07U;           // eor w13, w13, #7 @ 0x1193ec
constexpr uint32_t kBDPythonImportScalarRecip26 = 0x4EC4EC4FU; // mov w11, #0xec4f; movk w11, #0x4ec4, lsl #16 @ 0x1193cc

struct PyInterpreterState;
struct PyThreadState;

using BDStuckCallback = void (*)(PyInterpreterState*);

// Reconstructed from 0x1042a4..0x104430 & 0x1320e0..0x132154 (PyInterpreterState ABI layout)
// Tái dựng từ 0x1042a4..0x104430 & 0x1320e0..0x132154 (Bố cục ABI của PyInterpreterState)
struct PyInterpreterState {
    PyInterpreterState* next{nullptr};            // +0x0000
    PyThreadState* tstate_head{nullptr};          // +0x0008
    uint8_t pad_0010[0x268]{0};
    std::atomic<int32_t> is_busy{0};              // +0x0278 (add x8, x0, #0x278; ldar w8, [x8] @ 0x1043c4)
    uint8_t pad_027c[0x1B508 - 0x27C]{0};
    BDStuckCallback stuck_callback{nullptr};      // +0x1B508 (mov w8, #0xb508; movk w8, #1, lsl #16 @ 0x1320e0)
};

// Reconstructed from 0x1320f0..0x13221c (PyThreadState ABI layout)
// Tái dựng từ 0x1320f0..0x13221c (Bố cục ABI của PyThreadState)
struct PyThreadState {
    PyThreadState* prev{nullptr};                 // +0x0000
    PyThreadState* next{nullptr};                 // +0x0008
    PyInterpreterState* interp{nullptr};          // +0x0010 (ldr x0, [x0, #0x10] @ 0x13210c)
    uint8_t pad_0018[0x160]{0};
    void* pitaya_package{nullptr};                // +0x0178 (BDPythonVM_PyThreadStateSetPitayaPackage @ 0x1321dc)
};

struct FrozenImportModuleEntry {
    const char* name{nullptr};
    const uint8_t* code{nullptr};
    int32_t size{0};
};
