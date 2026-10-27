// ============================================================================
// Clean-Room C++17 Core Implementation for libpythonA.so (Target 118 / 169)
// Hiện thực C++17 sạch lõi cho libpythonA.so (PyToken, PyObject, BDPythonImportEncryptName)
// ============================================================================
#include "pythonA_core.h"
#include <cstdlib>
#include <cstring>

extern "C" {

// Reconstructed from 0x05db1c..0x05dbfc:
//   0x05db1c: 51009408 sub  w8, w0, #0x25
//   0x05db20: 7101651F cmp  w8, #0x59
//   0x05db24: 54000148 b.hi #0x5db4c (returns OP = 0x36 = 54)
int32_t PyToken_OneChar(int32_t c) noexcept {
    switch (c) {
        case '%': return 0x18; // PERCENT (24)
        case '&': return 0x13; // AMPER (19)
        case '(': return 0x07; // LPAR (7)
        case ')': return 0x08; // RPAR (8)
        case '*': return 0x10; // STAR (16)
        case '+': return 0x0e; // PLUS (14)
        case ',': return 0x0c; // COMMA (12)
        case '-': return 0x0f; // MINUS (15)
        case '.': return 0x17; // DOT (23)
        case '/': return 0x11; // SLASH (17)
        case ':': return 0x0b; // COLON (11)
        case ';': return 0x0d; // SEMI (13)
        case '<': return 0x14; // LESS (20)
        case '=': return 0x16; // EQUAL (22)
        case '>': return 0x15; // GREATER (21)
        case '@': return 0x31; // AT (49)
        case '[': return 0x09; // LSQB (9)
        case ']': return 0x0a; // RSQB (10)
        case '^': return 0x20; // CIRCUMFLEX (32)
        case '{': return 0x19; // LBRACE (25)
        case '|': return 0x12; // VBAR (18)
        case '}': return 0x1a; // RBRACE (26)
        case '~': return 0x1f; // TILDE (31)
        default:  return 0x36; // OP (54)
    }
}

int32_t PyToken_TwoChars(int32_t c1, int32_t c2) noexcept {
    if (c1 == '=' && c2 == '=') return 0x1b; // EQEQUAL
    if (c1 == '!' && c2 == '=') return 0x1c; // NOTEQUAL
    if (c1 == '<' && c2 == '=') return 0x1d; // LESSEQUAL
    if (c1 == '>' && c2 == '=') return 0x1e; // GREATEREQUAL
    if (c1 == '<' && c2 == '<') return 0x21; // LEFTSHIFT
    if (c1 == '>' && c2 == '>') return 0x22; // RIGHTSHIFT
    if (c1 == '*' && c2 == '*') return 0x23; // DOUBLESTAR
    return 0x36;
}

int32_t PyToken_ThreeChars(int32_t c1, int32_t c2, int32_t c3) noexcept {
    if (c1 == '.' && c2 == '.' && c3 == '.') return 0x34; // ELLIPSIS
    if (c1 == '<' && c2 == '<' && c3 == '=') return 0x2b; // LEFTSHIFTEQUAL
    if (c1 == '>' && c2 == '>' && c3 == '=') return 0x2c; // RIGHTSHIFTEQUAL
    return 0x36;
}

// Reconstructed from 0x05e130..0x05e160:
//   0x05e138: B40000C0 cbz x0, #0x5e150
//   0x05e13c: F9400400 ldr x0, [x0, #8]
//   0x05e140: F9400008 ldr x8, [x0]
//   0x05e144: 91000508 add x8, x8, #1
//   0x05e148: F9000008 str x8, [x0]
PyObject* PyObject_Type(PyObject* o) noexcept {
    if (!o || !o->ob_type) return nullptr;
    PyObject* type_obj = reinterpret_cast<PyObject*>(o->ob_type);
    type_obj->ob_refcnt += 1;
    return type_obj;
}

// Reconstructed from 0x05e198..0x05e1d8:
//   0x05e1a0: B4000100 cbz x0, #0x5e1c0
//   0x05e1a4: F9400408 ldr x8, [x0, #8]
//   0x05e1a8: F9403508 ldr x8, [x8, #0x68]
//   0x05e1b0: F9400101 ldr x1, [x8]
Py_ssize_t PyObject_Size(PyObject* o) noexcept {
    if (!o || !o->ob_type) return -1;
    PySequenceMethods* m = o->ob_type->tp_as_sequence;
    if (m && m->sq_length) {
        return m->sq_length(o);
    }
    return -1;
}

// 0x05e258: b #0x5b5d0
Py_ssize_t PyObject_Length(PyObject* o) noexcept {
    return PyObject_Size(o);
}

// Reconstructed from 0x080ba4..0x080bf0 (BDPythonVMPreInit)
//   0x080bb0: 3942A408 ldrb w8, [x0, #0xa9]
//   0x080bb4: 37200128 tbnz w8, #4, #0x80bd8
int32_t BDPythonVMPreInit(uint8_t* vm_state) noexcept {
    if (!vm_state) return -1;
    if ((vm_state[0xa9] & (1U << 4)) != 0) {
        return 0;
    }
    auto* ref_cnt = reinterpret_cast<uint64_t*>(vm_state);
    *ref_cnt += 1;
    return 0;
}

// Reconstructed from 0x1192d4..0x119424 (BDPythonImportEncryptName):
//   NEON loop (0x11936c..0x1193c0):
//     movi v0.16b, #7; movi v1.16b, #0x4f; movi v2.16b, #0x1a; movi v3.16b, #0x41
//     x = b ^ 7; q = (x * 0x4f) >> 11; r = x - q * 26
//     out[2*i] = r + 'A'; out[2*i+1] = q + 'A' (st2 {v6.16b, v7.16b}, [x14])
//   Scalar tail (0x1193cc..0x119414):
//     mov w11, #0xec4f; movk w11, #0x4ec4, lsl #16; mov w12, #0x1a
//     w13 = b ^ 7; w15 = ((w13 & 0xff) * 0x4ec4ec4fULL) >> 35
//     w13 = (w13 - w15 * 26) + 0x41 -> out[2*i]
//     w15 = w15 + 0x41             -> out[2*i+1]
char* BDPythonImportEncryptName(const char* name, size_t len) noexcept {
    size_t alloc_sz = (len << 1) | 1ULL; // 0x1192ec: bfi x1, x20, #1, #0x3f
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

// Exact inverse of BDPythonImportEncryptName:
// Given out[2*i] = lo + 'A' and out[2*i+1] = hi + 'A', recovers b = (hi * 26 + lo) ^ 7.
std::string BDPythonDecryptImportName(const char* enc, size_t enc_len) {
    if (!enc || (enc_len & 1U) != 0) return {};
    std::string out(enc_len >> 1, '\0');
    for (size_t i = 0; i < enc_len; i += 2) {
        uint8_t lo = static_cast<uint8_t>(enc[i] - 'A');
        uint8_t hi = static_cast<uint8_t>(enc[i + 1] - 'A');
        out[i >> 1] = static_cast<char>((hi * 26U + lo) ^ kBDPythonImportXorKey);
    }
    return out;
}
