// ============================================================================
// Clean-Room C++17 ABI & Data Structures for libpythonA.so (Target 118 / 169)
// Cấu trúc dữ liệu & ABI C++17 sạch cho libpythonA.so (Mục tiêu 118 / 169)
// Binary Size: 2,229,160 bytes | SHA-256: adac15b692d2291567fdf9f43ae7d9f5e1d7cfec70c8db6c9b85109118cd92fe
// .dynsym: 1,998 Exported Symbols @ 0x007c58 | .eh_frame_hdr: 4,320 FDEs @ 0x1c9550
// ============================================================================
#pragma once

#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>
#include <mutex>
#include <condition_variable>

// Constants verified directly from AArch64 opcodes in libpythonA.so
// Các hằng số xác minh trực tiếp từ mã máy AArch64 trong libpythonA.so
constexpr uint8_t kBDPythonImportXorKey = 0x07U;               // movi v0.16b, #7 @ 0x11936c; eor w13, w13, #7 @ 0x1193ec
constexpr uint8_t kBDPythonImportNeonRecip26 = 0x4FU;          // movi v1.16b, #0x4f @ 0x119370 ((x * 79) >> 11 == x / 26)
constexpr uint32_t kBDPythonImportScalarRecip26 = 0x4EC4EC4FU; // mov w11, #0xec4f; movk w11, #0x4ec4, lsl #16 @ 0x1193cc
constexpr size_t kPyTypeAsSequenceOffset = 0x68;               // ldr x8, [x8, #0x68] @ 0x05e1a8
constexpr size_t kNbSlotSubtract = 0x08;                       // mov w2, #8 @ 0x05fb84
constexpr size_t kNbSlotDivmod = 0x20;                         // mov w2, #0x20 @ 0x05fb94
constexpr size_t kNbSlotLshift = 0x58;                         // mov w2, #0x58 @ 0x05fb64
constexpr size_t kNbSlotRshift = 0x60;                         // mov w2, #0x60 @ 0x05fb74
constexpr size_t kNbSlotAnd = 0x68;                            // mov w2, #0x68 @ 0x05fb54
constexpr size_t kNbSlotXor = 0x70;                            // mov w2, #0x70 @ 0x05fb44
constexpr size_t kNbSlotOr = 0x78;                             // mov w2, #0x78 @ 0x05fba8

using Py_ssize_t = int64_t;

struct _typeobject;
struct _object;
using PyObject = _object;
using PyTypeObject = _typeobject;

using lenfunc = Py_ssize_t (*)(PyObject*);
using binaryfunc = PyObject* (*)(PyObject*, PyObject*);

struct PySequenceMethods {
    lenfunc sq_length{nullptr}; // +0x00 (ldr x1, [x8] @ 0x05e1b0)
    binaryfunc sq_concat{nullptr};
    void* sq_repeat{nullptr};
    void* sq_item{nullptr};
};

// Standard CPython 64-bit PyObject header verified at 0x05e130..0x05e1c0
// Tiêu đề PyObject 64-bit chuẩn xác minh tại 0x05e130..0x05e1c0
struct _object {
    Py_ssize_t ob_refcnt{1};       // +0x00 (ldr x8, [x0]; add x8, x8, #1; str x8, [x0] @ 0x05e140)
    PyTypeObject* ob_type{nullptr};// +0x08 (ldr x0, [x0, #8] @ 0x05e13c)
};

struct _typeobject {
    PyObject ob_base{};
    const char* tp_name{nullptr};  // +0x18 (ldr x3, [x8, #0x18] @ 0x05fae4)
    uint8_t pad_20[0x48]{0};
    PySequenceMethods* tp_as_sequence{nullptr}; // +0x68 (ldr x8, [x8, #0x68] @ 0x05e1a8)
};

// Reconstructed from 0x18d190..0x18d2b4 (BDPyDebugger::ExcInfo & Event)
// Tái dựng từ 0x18d190..0x18d2b4 (BDPyDebugger::ExcInfo & Event)
namespace BDPyDebugger {

struct ExcInfo {
    std::string exc_type;
    std::string exc_value;
    std::string exc_traceback;
    ~ExcInfo() = default;
};

class Event {
public:
    Event() = default;
    ~Event() = default;

    // 0x18d1dc..0x18d278
    void wait();
    // 0x18d278..0x18d2b4
    void fire();

private:
    std::mutex mutex_;
    std::condition_variable cv_;
    bool signaled_{false};
};

} // namespace BDPyDebugger
