// ============================================================================
// File: worker_rodata_tables.cpp
// Target: libworker.so (313,400 bytes)
// Role: Exact byte-for-byte .rodata (0x00d860..0x00da60) and .data.rel.ro
//       (0x048410..0x04a988) tables extracted from libworker.so.
// Vai trò: Dữ liệu nguyên bản từng byte của các bảng hằng số .rodata và .data.rel.ro.
// ============================================================================

#include "worker_rodata_tables.h"

namespace vmsdk {
namespace tables {

// .rodata 0x00d860..0x00d86f: {1ULL, 0xFFFFFFFFFFFFFFFFULL}
// Dùng tại 0x01e0f0 (ldr q0, [x10, #0x860]), 0x01e444 (ldr q1, [x8, #0x860]), 0x03380c.
const uint64_t kMessageLoopDeltaVec[2] = {
    0x0000000000000001ULL, 0xFFFFFFFFFFFFFFFFULL
};

// .rodata 0x00d870..0x00d877: 2ULL
// Dùng tại 0x023cfc & 0x0347f4.
const uint64_t kNapiPropCountTwo = 0x0000000000000002ULL;

// .rodata 0x00d878..0x00d8d9 (98 bytes):
// Disassembly @ 0x02a914..0x02a940:
//   0x02a914: cmp w8, #0x61; b.hi #0x2a940
//   0x02a91c: adrp x9, #0xd000; and x8, x0, #0xff; add x9, x9, #0x878
//   0x02a928: adr x10, #0x2a93c; ldrb w11, [x9, x8]; add x10, x10, x11, lsl #2
//   0x02a934: mov w0, #1; br x10
//   0x02a93c: ret (w0 = 1)
//   0x02a940: mov w0, wzr; ret (w0 = 0)
const uint8_t kPiperSigValidTable[98] = {
    0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01,
    0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x00,
};

// .rodata 0x00d8da..0x00d913 (58 bytes):
// Disassembly @ 0x02c224..0x02c248 (base 0x02c24c):
const uint8_t kPiperSigTypeNameJumpTable[58] = {
    0x00, 0x0F, 0x24, 0x12, 0x2D, 0x15, 0x2D, 0x2D, 0x27, 0x2D, 0x2D, 0x2A, 0x30, 0x2D, 0x2D, 0x33,
    0x2D, 0x2D, 0x06, 0x18, 0x2D, 0x2D, 0x2D, 0x1B, 0x09, 0x36, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D,
    0x39, 0x44, 0x3F, 0x3C, 0x2D, 0x03, 0x2D, 0x2D, 0x1E, 0x2D, 0x2D, 0x42, 0x2D, 0x2D, 0x2D, 0x2D,
    0x2D, 0x2D, 0x0C, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x21,
};

// .rodata 0x00d914..0x00d977 (50 uint16_t = 100 bytes):
// Disassembly @ 0x02c8e4..0x02c900 (base 0x02c62c):
const uint16_t kPiperExtractJSValueJumpTable[50] = {
    0x00B6, 0x0000, 0x00C4, 0x0000, 0x00D1, 0x0000, 0x0000, 0x00E3, 0x0000, 0x0000, 0x00F1, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0103, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0118, 0x0000, 0x011A, 0x0000,
    0x011E, 0x0000, 0x0000, 0x0123, 0x0000, 0x0000, 0x0128, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x012D,
};

// .rodata 0x00d978..0x00d9eb (58 uint16_t = 116 bytes):
// Disassembly @ 0x02ed80..0x02ed9c (base 0x02eda0):
const uint16_t kPiperReturnDispatchJumpTable[58] = {
    0x0000, 0x0000, 0x008C, 0x0000, 0x008C, 0x0000, 0x008C, 0x008C, 0x0000, 0x008C, 0x008C, 0x008C,
    0x0000, 0x008C, 0x008C, 0x008C, 0x008C, 0x008C, 0x0000, 0x0000, 0x008C, 0x008C, 0x008C, 0x008C,
    0x008C, 0x0000, 0x008C, 0x008C, 0x008C, 0x008C, 0x008C, 0x008C, 0x0000, 0x0030, 0x008C, 0x0146,
    0x008C, 0x0154, 0x008C, 0x008C, 0x0046, 0x008C, 0x008C, 0x0023, 0x008C, 0x008C, 0x008C, 0x008C,
    0x008C, 0x008C, 0x003B, 0x008C, 0x008C, 0x008C, 0x008C, 0x008C, 0x008C, 0x0052,
};

// .rodata 0x00d9ec..0x00da5f (58 uint16_t = 116 bytes):
// Disassembly @ 0x030d80..0x030da4 (base 0x030dc4):
const uint16_t kWorkerReturnConvertJumpTable[58] = {
    0x0000, 0x0015, 0x002F, 0x007F, 0x0099, 0x00AF, 0x0099, 0x0099, 0x00C9, 0x0099, 0x0099, 0x00E3,
    0x00F7, 0x0099, 0x0099, 0x0099, 0x0099, 0x0099, 0x0109, 0x012B, 0x0099, 0x0099, 0x0099, 0x0099,
    0x0099, 0x013D, 0x0099, 0x0099, 0x0099, 0x0099, 0x0099, 0x0099, 0x0158, 0x016C, 0x0179, 0x01AA,
    0x0099, 0x01B6, 0x0099, 0x0099, 0x01C2, 0x0099, 0x0099, 0x01CF, 0x0099, 0x0099, 0x0099, 0x0099,
    0x0099, 0x0099, 0x01E9, 0x0099, 0x0099, 0x01FA, 0x0099, 0x0099, 0x0099, 0x0202,
};

// .data.rel.ro 0x048410..0x048420 (1 entry for com/bytedance/vmsdk/jsbridge/utils/SystemMessageHandler)
const JniMethodEntry kSystemMessageHandlerJniTable[1] = {
    {"nativeRunWork", "(J)V", 0x020A70ULL},
};

// .data.rel.ro 0x0486c0..0x0486d0 (1 entry for com/bytedance/vmsdk/jsbridge/utils/SystemThread)
const JniMethodEntry kSystemThreadJniTable[1] = {
    {"nativeRun", "(J)V", 0x021AE8ULL},
};

// .data.rel.ro 0x048ab8..0x048ae0 (2 entries for com/bytedance/vmsdk/jsbridge/CallbackImpl)
const JniMethodEntry kCallbackImplJniTable[2] = {
    {"nativeInvoke", "(JLcom/bytedance/vmsdk/jsbridge/utils/WritableArray;)V", 0x0265E0ULL},
    {"nativeReleaseNativePtr", "(J)V", 0x026964ULL},
};

// .data.rel.ro 0x049d28..0x049fc0 (28 entries for com/bytedance/vmsdk/worker/JsWorker)
// Registered in JsWorkerAndroid::RegisterJni (0x03ba34..0x03bb18, mov w3, #0x1c @ 0x03bae8)
const JniMethodEntry kJsWorkerJniTable[28] = {
    {"nativeResolve", "(JLcom/bytedance/vmsdk/net/Response;J)V", 0x03BB1CULL},
    {"nativeReject", "(JLjava/lang/String;J)V", 0x03BD28ULL},
    {"nativeEvaluateJavaScript", "(JLjava/lang/String;Ljava/lang/String;Z)V", 0x03BF78ULL},
    {"nativeTerminate", "(J)V", 0x03C080ULL},
    {"nativePostMessage", "(JLjava/lang/String;)V", 0x03C150ULL},
    {"nativeCreateWorker", "(Lcom/bytedance/vmsdk/worker/JsWorker;JLcom/bytedance/vmsdk/jsbridge/JSModuleManager;Ljava/lang/String;ZLjava/lang/String;Z)J", 0x03C2A0ULL},
    {"nativeRegisterDelegateFunction", "(J)V", 0x03C4CCULL},
    {"nativeInitInspector", "(JJ)V", 0x01F8E0ULL},
    {"nativeInitInspectorFactory", "(J)V", 0x01F8E0ULL},
    {"nativeBind", "(JII)V", 0x01F8E0ULL},
    {"nativeV8PipeInit", "(J[J)V", 0x01F8E0ULL},
    {"nativeOnJSRunner", "(JLjava/lang/Runnable;)V", 0x03C550ULL},
    {"nativeOnJSRunnerDelay", "(JLjava/lang/Runnable;J)V", 0x03C6E8ULL},
    {"nativeOnJSRunnerAtFront", "(JLjava/lang/Runnable;)V", 0x03C900ULL},
    {"nativeOnWorkerRunner", "(JLjava/lang/Runnable;)V", 0x01F8E0ULL},
    {"nativeSetProperties", "(JLcom/bytedance/vmsdk/jsbridge/utils/JavaOnlyMap;)V", 0x03CA98ULL},
    {"nativeOnPlatformRunner", "(JLjava/lang/Runnable;)V", 0x01F8E0ULL},
    {"nativeInvokeJavaScriptModule", "(JLjava/lang/String;Ljava/lang/String;Lcom/bytedance/vmsdk/jsbridge/utils/JavaOnlyArray;C)Ljava/lang/Object;", 0x03CCA8ULL},
    {"nativeInvokeJavaScriptFunction", "(JLjava/lang/String;Lcom/bytedance/vmsdk/jsbridge/utils/JavaOnlyArray;C)Ljava/lang/Object;", 0x03D80CULL},
    {"nativeSetExceptionDelegate", "(JLcom/bytedance/vmsdk/worker/IWorkerExceptionDelegate;)V", 0x03E04CULL},
    {"nativeOnOpenInspectorSession", "(J)V", 0x03E1BCULL},
    {"nativeOnInspectorMessage", "(JLjava/lang/String;)V", 0x03E2E0ULL},
    {"nativeOnCloseInspectorSession", "(J)V", 0x03E55CULL},
    {"nativeGetNapiEnv", "(J)J", 0x03E7B8ULL},
    {"nativeGenCodeCache", "(Ljava/lang/String;J)[B", 0x03E8A0ULL},
    {"nativeEvaluateCodeCache", "(J[B)V", 0x03EA10ULL},
    {"nativeInitQJSWebAssembly", "(JJ)V", 0x01F8E0ULL},
    {"nativeSetupLoader", "(JLjava/lang/String;)V", 0x03EB34ULL},
};

// .data.rel.ro 0x04a978..0x04a988 (1 entry for com/bytedance/vmsdk/net/Response)
const JniMethodEntry kResponseJniTable[1] = {
    {"nativeCreateResponse", "(Lcom/bytedance/vmsdk/net/Response;)J", 0x0453B8ULL},
};

/**
 * EN: Exact implementation of signature validator at 0x02a910..0x02a944.
 *     Checks if ch <= 0x61 ('a') and kPiperSigValidTable[ch] == 0.
 * VN: Thực thi chính xác hàm kiểm tra ký tự chữ ký tại 0x02a910..0x02a944.
 */
bool IsValidPiperSignatureChar(uint8_t ch) noexcept {
    if (ch > 0x61u) {
        return false;
    }
    return kPiperSigValidTable[ch] == 0u;
}

/**
 * EN: Exact implementation of signature char to human-readable type name at 0x02c220..0x02c35c.
 *     Uses kPiperSigTypeNameJumpTable[ch - 'A'] for 'A' <= ch <= 'z'.
 * VN: Thực thi chính xác ánh xạ ký tự chữ ký sang tên kiểu dữ liệu tại 0x02c220..0x02c35c.
 */
const char* GetPiperSignatureTypeName(char ch) noexcept {
    uint32_t idx = static_cast<uint32_t>(static_cast<uint8_t>(ch)) - 0x41u;
    if (idx > 0x39u) {
        return "unknown type"; // 0x00fdeb
    }
    switch (kPiperSigTypeNameJumpTable[idx]) {
        case 0x00: return "ReadableArray"; // 'A' -> 0x00edb6
        case 0x03: return "boolean";       // 'z' -> 0x00decd
        case 0x06: return "ReadableMap";   // 'M' -> 0x00f007
        case 0x09: return "Promise";       // 'P' -> 0x00f013
        case 0x0C: return "short";         // 's' -> 0x00e9c5
        case 0x0F: return "Byte";          // 'B' -> 0x00db9a
        case 0x12: return "Character";     // 'C' -> 0x00db8b
        case 0x15: return "Double";        // 'D' -> 0x00f71b
        case 0x18: return "Long";          // 'L' -> 0x00e7b2
        case 0x1B: return "Short";         // 'S' -> 0x00f01b
        case 0x1E: return "float";         // 'f' -> 0x00f950
        case 0x21: return "long";          // 'l' -> 0x00db95
        case 0x24: return "Float";         // 'F' -> 0x00f4ca
        case 0x27: return "Int";           // 'I' -> 0x00eead
        case 0x2A: return "JByteArray";    // 'a' -> 0x00fd1d
        case 0x30: return "byte";          // 'b' -> 0x00e427
        case 0x33: return "char";          // 'c' -> 0x00e8b2
        case 0x36: return "String";        // 'T' -> 0x00f848
        case 0x39: return "Callback";      // 'X' -> 0x00e2d3
        case 0x3C: return "Boolean";       // 'Z' -> 0x00e9bd
        case 0x3F: return "Dynamic";       // 'Y' -> 0x00da6c
        case 0x42: return "int";           // 'i' -> 0x00e423
        case 0x44: return "double";        // 'd' -> 0x00f4d0
        default:   return "unknown type";  // 0x2D -> 0x00fdeb
    }
}

} // namespace tables
} // namespace vmsdk
