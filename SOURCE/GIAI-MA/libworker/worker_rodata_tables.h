// ============================================================================
// File: worker_rodata_tables.h
// Target: libworker.so (313,400 bytes)
// Role: Exact .rodata (0x00d860..0x012902) & .data.rel.ro (0x048000..0x04a990)
//       Jump Tables, SIMD Constants, and JNI Registration Descriptors.
// Vai trò: Các bảng nhảy .rodata, hằng số SIMD và bảng đăng ký JNI trong .data.rel.ro.
// ============================================================================

#pragma once

#include <jni.h>
#include <cstdint>
#include <cstddef>

namespace vmsdk {
namespace tables {

// .rodata 0x00d860: 16-byte SIMD vector {1ULL, -1ULL} used in MessageLoop::PostTask / DoWork
// (0x01e0f0 & 0x01e444) and TaskRunner::Run (0x03380c).
// Vector SIMD 16-byte {1ULL, -1ULL} tại .rodata 0x00d860.
extern const uint64_t kMessageLoopDeltaVec[2];

// .rodata 0x00d870: 8-byte constant 2ULL loaded via ldr d0/d8, [x9, #0x870] at 0x023cfc & 0x0347f4.
// Hằng số 8-byte 2ULL tại .rodata 0x00d870.
extern const uint64_t kNapiPropCountTwo;

// .rodata 0x00d878..0x00d8d9 (98 bytes): Piper JSB MethodInvoker signature character validator
// jump-offset table (0x02a91c..0x02a940). 0x00 -> valid (returns 1), 0x01 -> invalid (returns 0).
// Bảng kiểm tra ký tự chữ ký kiểu dữ liệu Piper JSB MethodInvoker (98 byte) tại .rodata 0x00d878.
extern const uint8_t kPiperSigValidTable[98];

// .rodata 0x00d8da..0x00d913 (58 bytes): Piper JSB MethodInvoker signature char ('A'..'z')
// to human-readable type name jump table (0x02c22c..0x02c35c, base 0x02c24c).
// Bảng nhảy ánh xạ ký tự chữ ký ('A'..'z') sang tên kiểu dữ liệu tại .rodata 0x00d8da.
extern const uint8_t kPiperSigTypeNameJumpTable[58];

// .rodata 0x00d914..0x00d977 (50 uint16_t = 100 bytes): Piper JSB MethodInvoker::extractJSValue
// jump table (0x02c8ec..0x02c900, base 0x02c62c).
// Bảng nhảy uint16_t (50 mục) trích xuất giá trị JS sang đối số JNI tại .rodata 0x00d914.
extern const uint16_t kPiperExtractJSValueJumpTable[50];

// .rodata 0x00d978..0x00d9eb (58 uint16_t = 116 bytes): Piper JSB MethodInvoker return-type
// JNI invocation jump table (0x02ed84..0x02ed9c, base 0x02eda0).
// Bảng nhảy uint16_t (58 mục) điều phối kiểu trả về JNI sang N-API tại .rodata 0x00d978.
extern const uint16_t kPiperReturnDispatchJumpTable[58];

// .rodata 0x00d9ec..0x00da5f (58 uint16_t = 116 bytes): JsWorkerAndroid::InvokeJavaScriptModuleInner
// & InvokeJavaScriptFunctionInner return-type conversion jump table (0x030d88..0x030da4, base 0x030dc4).
// Bảng nhảy uint16_t (58 mục) chuyển đổi kết quả JS sang jobject JNI tại .rodata 0x00d9ec.
extern const uint16_t kWorkerReturnConvertJumpTable[58];

// CityHash64 constants embedded at 0x022d58..0x0231c4:
// Các hằng số băm 64-bit CityHash64 nhúng tại 0x022d58..0x0231c4:
constexpr uint64_t kCityHashK0  = 0xc3a5c85c97cb3127ULL;
constexpr uint64_t kCityHashK1  = 0xb492b66fbe98f273ULL;
constexpr uint64_t kCityHashK2  = 0x9ae16a3b2f90404fULL;
constexpr uint64_t kCityHashK3  = 0xc949d7c7509e6557ULL;
constexpr uint64_t kCityHashMul = 0x9ddfea08eb382d69ULL;

// JNI Native Method descriptor tables in .data.rel.ro:
// Các bảng mô tả phương thức gốc JNI trong .data.rel.ro:
struct JniMethodEntry {
    const char* name;
    const char* signature;
    uint64_t fn_vaddr;
};

extern const JniMethodEntry kSystemMessageHandlerJniTable[1]; // .data.rel.ro 0x048410
extern const JniMethodEntry kSystemThreadJniTable[1];         // .data.rel.ro 0x0486c0
extern const JniMethodEntry kCallbackImplJniTable[2];         // .data.rel.ro 0x048ab8
extern const JniMethodEntry kJsWorkerJniTable[28];            // .data.rel.ro 0x049d28..0x049fc0
extern const JniMethodEntry kResponseJniTable[1];             // .data.rel.ro 0x04a978

bool IsValidPiperSignatureChar(uint8_t ch) noexcept;
const char* GetPiperSignatureTypeName(char ch) noexcept;

} // namespace tables
} // namespace vmsdk
