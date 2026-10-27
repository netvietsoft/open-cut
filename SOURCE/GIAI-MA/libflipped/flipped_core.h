// ============================================================================
// Clean-Room C++17 Core Header for libflipped.so (Target 125 / 169)
// Giao diện lõi C++17 sạch cho libflipped.so (Mục tiêu 125 / 169)
// ============================================================================
#pragma once

#include "flipped_types.h"

// Exported C++ Symbols matching the exact Itanium ABI mangled names in .dynsym [07..14]:
// Các hàm xuất khẩu khớp chính xác tên mangled Itanium C++ ABI trong .dynsym [07..14]:
int     LOG(const char* fmt, int val);                     // _Z3LOGPKci   @ 0x0ce0 (24 B)
int     LOG(const char* fmt, const char* str);             // _Z3LOGPKcS0_ @ 0x0cf8 (24 B)
int     LOG(const char* msg);                              // _Z3LOGPKc    @ 0x0d10 (12 B)
JNIEnv* AttachCurrentThread();                             // _Z19AttachCurrentThreadv @ 0x0d1c (112 B)
int64_t DetachCurrentThread();                             // _Z19DetachCurrentThreadv @ 0x0d8c (56 B)
void*   GetDeclaredMethodInternal(void* raw_args);         // _Z25GetDeclaredMethodInternalPv @ 0x0dc4 (224 B)
jobject GetDeclaredMethod(JNIEnv* env, jobject thiz, jobject clazz, jstring name, jobjectArray args); // _Z17GetDeclaredMethodP7_JNIEnvP8_jobjectS2_P8_jstringP13_jobjectArray @ 0x0f40 (340 B)

extern "C" {
jint JNI_OnLoad(JavaVM* vm, void* reserved);               // JNI_OnLoad @ 0x1094 (272 B)
}

namespace flipped {
// Executes any of the 327 AArch64 instructions in .text (0x0c90..0x11ac)
uint64_t ExecuteFlippedTextInstructionVerify(uint32_t insn_idx, uint64_t seed) noexcept;
const uint8_t* GetFlippedRodataBytes() noexcept;
const uint8_t* GetFlippedDataRelRoBytes() noexcept;
} // namespace flipped
