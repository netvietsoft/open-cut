// ============================================================================
// Clean-Room C++17 Types, JNI Vtable Offsets & .rodata Strings for libflipped.so
// Định nghĩa kiểu dữ liệu, offset bảng ảo JNI & chuỗi .rodata cho libflipped.so
// Binary: 7,320 bytes | SHA-256: 30aabc89f03ef6f8659469596f8a7e8cd65a1950b3bcc853e4caddcc92eb56b0
// ============================================================================
#pragma once

#include <cstdint>
#include <cstddef>
#include <cstring>
#include <cstdarg>

// Minimal standalone JNI & pthread ABI definitions for portable clean-room compilation
struct _JNIEnv;
struct _JavaVM;
using JNIEnv = _JNIEnv;
using JavaVM = _JavaVM;
using jobject = void*;
using jclass = void*;
using jstring = void*;
using jobjectArray = void*;
using jmethodID = void*;
using jint = int32_t;
using jsize = int32_t;
using jboolean = uint8_t;

namespace flipped {

constexpr int32_t kAndroidLogError = 6;          // mov w0, #6 (@ 0x0cf0, 0x0d08)
constexpr int32_t kJniVersion1_6   = 0x00010006; // mov w2, #6; movk w2, #1, lsl #16 (@ 0x10b4..0x10bc)
constexpr int32_t kJniErr          = -1;         // mov w19, #-1 (@ 0x10e4, 0x1168)

// Exact .rodata String Constants (0x0880..0x0a65, 485 bytes):
// Các hằng chuỗi .rodata chuẩn xác tại 0x0880..0x0a65:
constexpr const char* kStrGetDeclaredMethod   = "getDeclaredMethod"; // 0x0880
constexpr const char* kStrLogTag              = "flipped";           // 0x0892
constexpr const char* kStrAttachThreadFmt     = "Attach current thread %d"; // 0x089a
constexpr const char* kStrDetachThreadFmt     = "Detach current thread %d"; // 0x08b3
constexpr const char* kStrEmpty               = "";                  // 0x08cc
constexpr const char* kStrInitSucceeded       = "init succeeded.";   // 0x08cd
constexpr const char* kStrErrRegWhenReg       = "Failed to register native method when registering Native method..."; // 0x08dd
constexpr const char* kStrErrRegNative        = "Failed to register Native method..."; // 0x0920
constexpr const char* kStrErrFindClassFmt     = "Failed to find '%s' class when registering Native method..."; // 0x0944
constexpr const char* kStrFlippedV2Class      = "com/bytedance/mira/plugin/hook/flipped/compat/FlippedV2Impl"; // 0x0980
constexpr const char* kStrClassGetDecMethSig  = "(Ljava/lang/String;[Ljava/lang/Class;)Ljava/lang/reflect/Method;"; // 0x09bc
constexpr const char* kStrNativeGetDecMethSig = "(Ljava/lang/Object;Ljava/lang/String;[Ljava/lang/Class;)Ljava/lang/reflect/Method;"; // 0x09fd
constexpr const char* kStrErrGetEnv           = "Failed to get env..."; // 0x0a50

// Exact AArch64 JNIInvokeInterface (`JavaVM*`) vtable byte offsets observed in .text:
//   +0x20 (slot  4): AttachCurrentThread (@ 0x0d4c: ldr x8, [x8, #0x20])
//   +0x28 (slot  5): DetachCurrentThread (@ 0x0da0: ldr x8, [x8, #0x28])
//   +0x30 (slot  6): GetEnv              (@ 0x10d8: ldr x8, [x8, #0x30])
constexpr size_t kVmOffAttachCurrentThread = 0x20;
constexpr size_t kVmOffDetachCurrentThread = 0x28;
constexpr size_t kVmOffGetEnv              = 0x30;

// Exact AArch64 JNINativeInterface (`JNIEnv*`) vtable byte offsets observed in .text:
//   +0x30  (slot   6): FindClass             (@ 0x1108: ldr x8, [x8, #0x30])
//   +0x80  (slot  16): ExceptionDescribe     (@ 0x0e54: ldr x8, [x8, #0x80])
//   +0x88  (slot  17): ExceptionClear        (@ 0x0e64: ldr x8, [x8, #0x88])
//   +0xa8  (slot  21): NewGlobalRef          (@ 0x1010, 0x11a4: ldr x8, [x8, #0xa8])
//   +0xf8  (slot  31): GetObjectClass        (@ 0x0dec: ldr x8, [x8, #0xf8])
//   +0x108 (slot  33): GetMethodID           (@ 0x0e0c: ldr x8, [x8, #0x108])
//   +0x118 (slot  35): CallObjectMethodV     (@ 0x0f10: ldr x8, [x8, #0x118])
//   +0x558 (slot 171): GetArrayLength        (@ 0x0fa8: ldr x8, [x8, #0x558])
//   +0x568 (slot 173): GetObjectArrayElement (@ 0x0fc8: ldr x8, [x8, #0x568])
//   +0x570 (slot 174): SetObjectArrayElement (@ 0x1000: ldr x8, [x8, #0x570])
//   +0x6b8 (slot 215): RegisterNatives       (@ 0x112c: ldr x8, [x8, #0x6b8])
//   +0x720 (slot 228): ExceptionCheck        (@ 0x0e3c: ldr x8, [x8, #0x720])
constexpr size_t kEnvOffFindClass             = 0x030;
constexpr size_t kEnvOffExceptionDescribe     = 0x080;
constexpr size_t kEnvOffExceptionClear        = 0x088;
constexpr size_t kEnvOffNewGlobalRef          = 0x0A8;
constexpr size_t kEnvOffGetObjectClass        = 0x0F8;
constexpr size_t kEnvOffGetMethodID           = 0x108;
constexpr size_t kEnvOffCallObjectMethodV     = 0x118;
constexpr size_t kEnvOffGetArrayLength        = 0x558;
constexpr size_t kEnvOffGetObjectArrayElement = 0x568;
constexpr size_t kEnvOffSetObjectArrayElement = 0x570;
constexpr size_t kEnvOffRegisterNatives       = 0x6B8;
constexpr size_t kEnvOffExceptionCheck        = 0x720;

// 24-Byte Thread Argument Struct passed from GetDeclaredMethod (sp + 0x10 @ 0x102c..0x1030)
// to GetDeclaredMethodInternal (unpacked via `ldp x20, x21, [x0]; ldr x22, [x0, #0x10]` @ 0x0dd4..0x0dd8):
// Cấu trúc tham số luồng 24 byte truyền từ GetDeclaredMethod sang GetDeclaredMethodInternal:
struct FlippedThreadArgs24B {
    jobject      target_class_global_ref; // +0x00 (x20)
    jstring      method_name_global_ref;  // +0x08 (x21)
    jobjectArray param_types_global_ref;  // +0x10 (x22)
};
static_assert(sizeof(FlippedThreadArgs24B) == 24, "FlippedThreadArgs24B must be exactly 24 bytes");

// 24-Byte JNINativeMethod entry stored in .data.rel.ro at 0x005288:
//   name      = 0x000880 ("getDeclaredMethod")
//   signature = 0x0009fd ("(Ljava/lang/Object;Ljava/lang/String;[Ljava/lang/Class;)Ljava/lang/reflect/Method;")
//   fnPtr     = 0x000f40 (&GetDeclaredMethod)
struct JniNativeMethodAbi {
    const char* name;      // +0x00
    const char* signature; // +0x08
    void*       fnPtr;     // +0x10
};
static_assert(sizeof(JniNativeMethodAbi) == 24, "JniNativeMethodAbi must be 24 bytes on AArch64");

} // namespace flipped
