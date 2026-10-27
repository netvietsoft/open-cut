// ============================================================================
// File: orbuculum_types.h
// Target: liborbuculum.so (412,176 bytes, SHA-256: 5f22a1ed255a53e0420ba6b8bcb36704673230d98a7e0e0ff619dfdd5cd5794f)
// Task ID: TASK-140-RECONSTRUCTION-LIBORBUCULUM / TASK_SO_108_liborbuculum
// Description:
//   [EN] Clean-room C++17 ABI structures, opcodes, return codes, SHA-256 state,
//        and JNI entry point declarations for TikTok Project Texas (TTP)
//        Orbu / Orbuculum Native Network Security & Bytecode Validator Engine.
//   [VN] Định nghĩa cấu trúc ABI C++17 sạch, mã lệnh OrbuCode, mã trả về,
//        trạng thái SHA-256 và điểm vào JNI cho bộ máy kiểm duyệt mạng Orbuculum.
// ============================================================================

#pragma once

#include <cstdint>
#include <cstddef>

#ifndef JNI_VERSION_1_6
typedef uint8_t jboolean;
typedef int8_t jbyte;
typedef uint16_t jchar;
typedef int16_t jshort;
typedef int32_t jint;
typedef int64_t jlong;
typedef float jfloat;
typedef double jdouble;
typedef jint jsize;
struct _jobject;
typedef _jobject* jobject;
typedef jobject jclass;
typedef jobject jstring;
typedef jobject jbyteArray;
struct _jmethodID;
typedef _jmethodID* jmethodID;
struct _JNIEnv { const void* functions; };
typedef _JNIEnv JNIEnv;
struct _JavaVM { const void* functions; };
typedef _JavaVM JavaVM;
#define JNI_VERSION_1_6 0x00010006
#endif

namespace ttp {
namespace orbuculum {

// ============================================================================
// [EN] OrbuStruct binary header (36 bytes = 0x24, verified in OrbuCodeEngine::init @ 0x0256fc):
//        +0x00: magic[8] ("ORBUCODE" @ .rodata 0x052b7d, checked at 0x02573c..0x025748)
//        +0x08: version / api_level (uint32_t)
//        +0x0c: entry_table_offset (uint32_t, 8-byte aligned @ 0x025784)
//        +0x10: entry_table_size (uint32_t, 8-byte aligned @ 0x0257a4, count = size >> 3 @ 0x0257a0)
//        +0x14: code_block_offset (uint32_t, 8-byte aligned @ 0x02575c)
//        +0x18: code_block_size (uint32_t)
//        +0x1c: data_table_offset (uint32_t, 8-byte aligned @ 0x0257b8)
//        +0x20: data_table_size (uint32_t)
// [VN] Cấu trúc đầu tệp nhị phân OrbuCodeStruct (36 byte = 0x24, kiểm tra tại 0x0256fc).
// ============================================================================
struct OrbuCodeStruct {
    char magic[8];               // +0x00
    uint32_t version;            // +0x08
    uint32_t entry_table_offset; // +0x0c
    uint32_t entry_table_size;   // +0x10
    uint32_t code_block_offset;  // +0x14
    uint32_t code_block_size;    // +0x18
    uint32_t data_table_offset;  // +0x1c
    uint32_t data_table_size;    // +0x20
};

// ============================================================================
// [EN] OrbuCodeInstructionStruct (24 bytes = 0x18, verified at 0x0259ec & 0x025d28..0x025d38):
//      Instruction count computed via unsigned reciprocal division by 24:
//      (umulh(byte_diff, 0xAAAAAAAAAAAAAAABULL) >> 4) @ 0x025d28..0x025d38.
// [VN] Cấu trúc lệnh OrbuCodeInstructionStruct (24 byte = 0x18, chia nghịch đảo cho 24 tại 0x025d28).
// ============================================================================
struct OrbuCodeInstructionStruct {
    uint32_t opcode_and_flags;   // +0x00 (bits 16..25 = OpCode: and w9, w11, #0x3ff0000 @ 0x0259e0)
    uint32_t operand_0;          // +0x04
    uint32_t operand_1;          // +0x08
    uint32_t operand_2;          // +0x0c
    uint32_t operand_3;          // +0x10
    uint32_t control_flow;       // +0x14
};
static_assert(sizeof(OrbuCodeInstructionStruct) == 24, "OrbuCodeInstructionStruct must be 24 bytes (0x18)");

// ============================================================================
// [EN] DataTableReference ABI layout (24 bytes = 0x18, allocated at 0x025800: mov w0, #0x18)
// [VN] Bố cục ABI DataTableReference (24 byte = 0x18, cấp phát tại 0x025800)
// ============================================================================
struct DataTableReferenceAbi {
    const uint8_t* base_ptr;     // +0x00 (0x025810: str x20, [x0])
    uint32_t byte_size;          // +0x08 (0x025814: str w25, [x0, #8])
    uint32_t pad;                // +0x0c
    const uint8_t* end_ptr;      // +0x10 (0x025818: str x8, [x0, #0x10])
};
static_assert(sizeof(DataTableReferenceAbi) == 24, "DataTableReferenceAbi must be 24 bytes (0x18)");

// ============================================================================
// [EN] SHA256 context ABI layout (168 bytes = 0xa8, verified in SHA256::init @ 0x03da20..0x03da3c):
//        +0x00: uint32_t m_tot_len; uint32_t m_len; (zeroed via str xzr, [x0] @ 0x03da30)
//        +0x08: uint8_t  m_block[128]; (2 * 64-byte blocks = 0x80 bytes)
//        +0x88: uint32_t m_h[8]; (initialized from .rodata 0x0535e0..0x0535ff via stur q0/q1 @ 0x03da34..0x03da38)
// [VN] Bố cục ABI ngữ cảnh SHA256 (168 byte = 0xa8, xác minh tại 0x03da20..0x03da3c).
// ============================================================================
struct Sha256ContextAbi {
    uint32_t m_tot_len;          // +0x00
    uint32_t m_len;              // +0x04
    uint8_t m_block[128];        // +0x08..+0x87
    uint32_t m_h[8];             // +0x88..+0xa7
};
static_assert(offsetof(Sha256ContextAbi, m_h) == 0x88, "SHA256::m_h must be at offset 0x88");
static_assert(sizeof(Sha256ContextAbi) == 0xA8, "Sha256ContextAbi must be 168 bytes (0xA8)");

} // namespace orbuculum
} // namespace ttp

extern "C" {
jint JNI_OnLoad(JavaVM* vm, void* reserved);
int32_t orbuculumProceedRequest(
    const char* url,
    const char* method,
    const char* headers_raw,
    const uint8_t* body,
    int32_t body_len,
    int32_t dataflow_id);
int32_t orbuculumIsProceedRequestImpl();
int32_t orbuculumIsProceedResponseImpl();
void registerLiveShutdownCallback(void* rtc_fn, void* rtc_opaque, void* rtmp_fn, void* rtmp_opaque);
}
