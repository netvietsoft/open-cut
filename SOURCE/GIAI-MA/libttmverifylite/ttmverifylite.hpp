// ============================================================================
// File: ttmverifylite.hpp
// Target: libttmverifylite.so (34,672 bytes, SHA-256: 672829f9be725b6867d86d6e0e2620361626c87539784cb7b300b71bedf3e5b5)
// Architecture: AArch64 (ARM64-v8a), Little-Endian, ELF64 Shared Object
// Module: ByteDance TTFFmpeg Custom TLS X.509 Certificate Chain & Hostname Verifier
//         (custom_verify/source/custom_verify_android.c — Built Jun 26 2025 12:29:14)
// Clean-Room C++17 Reconstruction — Zero Stubs — Bilingual EN / VN
// ============================================================================

#pragma once

#include <cstddef>
#include <cstdint>
#include <array>

namespace nextai::opencut::ttmverifylite {

// ============================================================================
// 1. Binary Constants & ELF Layout Metadata
//    Hằng số nhị phân & Siêu dữ liệu bố cục ELF của libttmverifylite.so
// ============================================================================
inline constexpr std::size_t kBinarySizeBytes          = 34672U;
inline constexpr const char* kBinarySha256Hex          = "672829f9be725b6867d86d6e0e2620361626c87539784cb7b300b71bedf3e5b5";
inline constexpr std::uint64_t kEhFrameHdrVa           = 0x00004D1CULL;
inline constexpr std::size_t kEhFrameFdeCount          = 13U;
inline constexpr std::uint64_t kPltStartVa             = 0x00000FE0ULL;
inline constexpr std::size_t kPltSizeBytes             = 0x00000210ULL; // 528 bytes (31 PLT slots)
inline constexpr std::uint64_t kTextStartVa            = 0x000011F0ULL;
inline constexpr std::uint64_t kTextEndVa              = 0x00003CC8ULL;
inline constexpr std::size_t kTextSizeBytes            = 10968U;        // 2,742 AArch64 instructions
inline constexpr std::size_t kTextInstructionCount     = 2742U;
inline constexpr std::uint64_t kRodataStartVa          = 0x00003CC8ULL;
inline constexpr std::size_t kRodataSizeBytes          = 0x00001053ULL; // 4,179 bytes
inline constexpr std::uint64_t kDataRelRoStartVa       = 0x0000BC48ULL;
inline constexpr std::uint64_t kDataStartVa            = 0x0000C000ULL;
inline constexpr std::uint64_t kBssStartVa             = 0x0000C020ULL;
inline constexpr std::size_t kBssSizeBytes             = 0x00000048ULL; // 72 bytes (0xC020..0xC068)

// ============================================================================
// 2. X.509 & JNI Verification Constants / Hằng số xác minh X.509 & JNI
// ============================================================================
inline constexpr std::uint32_t kJniVersion1_4          = 0x00010004U;
inline constexpr std::int32_t  kJniEdinval             = -3;
inline constexpr std::int32_t  kJniEdetached           = -2;
inline constexpr std::int32_t  kJniOk                  = 0;

// BoringSSL / OpenSSL NIDs & GENERAL_NAME types used in validate_hostname (0x2e50)
// Định danh NID và kiểu GENERAL_NAME của BoringSSL/OpenSSL dùng trong validate_hostname (0x2e50)
inline constexpr std::int32_t  kNidCommonName          = 13;   // 0x0D (NID_commonName @ 0x2fb0)
inline constexpr std::int32_t  kNidSubjectAltName      = 85;   // 0x55 (NID_subject_alt_name @ 0x2ea8)
inline constexpr std::int32_t  kGenDns                 = 2;    // GEN_DNS (dNSName IA5String @ 0x2f10)
inline constexpr std::int32_t  kGenIpadd               = 7;    // GEN_IPADD (iPAddress OCTET STRING)

// CustomVerify return codes in com.ss.ttffmpeg.CustomVerify
// Mã trả về của phương thức Java com.ss.ttffmpeg.CustomVerify.doVerify
inline constexpr std::int32_t  kVerifyStatusOk                   = 0;
inline constexpr std::int32_t  kVerifyStatusNoTrustedRoot        = -1;
inline constexpr std::int32_t  kVerifyStatusUnableToExtractKey   = -2;
inline constexpr std::int32_t  kVerifyStatusFailed               = -3;

// ============================================================================
// 3. Exported .data / .bss Global State Layout (0xC000..0xC068)
//    Bố cục biến toàn cục xuất khẩu trong .data / .bss (0xC000..0xC068)
// ============================================================================
struct CustomVerifyJniMethodEntry {
    const char* name;       // +0x00: "_init" (@ 0x4b90)
    const char* signature;  // +0x08: "()V"   (@ 0x4b96)
    void*       fn_ptr;     // +0x10: 0x3cc0 (_init_3cc0 -> init_clsz)
};

struct CustomVerifyJniClassDesc {
    const char*                       class_name;   // +0x00: "com/ss/ttffmpeg/CustomVerify" (@ 0x4960)
    std::int32_t                      method_count; // +0x08: 1
    std::int32_t                      padding_0c;   // +0x0C: 0
    const CustomVerifyJniMethodEntry* methods;      // +0x10: 0xbc58 (.data.rel.ro method entry)
};

// Complete runtime mirror of .data (0xC000..0xC020) and .bss (0xC020..0xC068)
// Cấu trúc phản chiếu chính xác vùng nhớ .data (0xC000..0xC020) và .bss (0xC020..0xC068)
struct TtmVerifyLiteGlobalState {
    void*                    dso_handle_c000;      // 0xC000: __dso_handle
    CustomVerifyJniClassDesc gCustomVerify_c008;   // 0xC008: exported gCustomVerify (24 bytes)
    void*                    g_jvm_c020;           // 0xC020: exported JavaVM* g_jvm (8 bytes)
    void*                    g_verify_cls_c028;    // 0xC028: exported jclass g_verify_cls (8 bytes)
    std::int32_t             hasInit_c030;         // 0xC030: exported int hasInit (4 bytes)
    std::int32_t             pad_c034;             // 0xC034: alignment padding (4 bytes)
    void*                    g_verify_method_c038; // 0xC038: exported jmethodID g_verify_method (8 bytes)
    alignas(8) std::uint8_t  lock_c040[40];        // 0xC040: exported pthread_mutex_t lock (40 bytes)
};

// ============================================================================
// 4. FunctionDescriptor — Entry in the 13-FDE .eh_frame_hdr Table (0x4D1C)
//    Mô tả hàm trong bảng 13 FDE tại .eh_frame_hdr (0x4D1C)
// ============================================================================
struct FunctionDescriptor {
    std::uint32_t fde_index;
    std::uint64_t start_va;
    std::uint64_t end_va;
    std::uint32_t size_bytes;
    std::uint64_t fde_va;
    const char*   symbol_name;
    const char*   description;
};

extern const std::array<FunctionDescriptor, kEhFrameFdeCount> kFunctionTable;
extern const std::array<std::int32_t, 26> kUppercaseAsciiJumpOffsets_3cc8;
extern const std::array<std::uint32_t, kTextInstructionCount> kTextInstructionWords;
extern const std::array<std::uint8_t, kRodataSizeBytes> kRodataBytes_3cc8;
extern const std::array<std::uint8_t, kBinarySizeBytes> kFullElfImageBytes;

// ============================================================================
// 5. Clean-Room Reconstructed C/JNI API Declarations (All 13 FDEs)
//    Khai báo toàn bộ 13 hàm C/JNI được tái tạo phòng sạch
// ============================================================================
extern "C" {

// FDE[00] 0x11fc..0x2e50 (7,252 bytes) — Exported av_cert_hostcheck
int av_cert_hostcheck(const char* pattern, const char* hostname) noexcept;

// FDE[01] 0x2e50..0x319c (844 bytes) — Exported validate_hostname
int validate_hostname(const char* hostname, const void* server_cert_opaque) noexcept;

// FDE[02] 0x319c..0x3288 (236 bytes) — Internal variadic logger
int CustomVerifyLog_319c(
    int prio,
    const char* tag,
    const char* outer_fmt,
    const char* file_name,
    const char* func_name,
    int line_no,
    const char* inner_fmt,
    ...) noexcept;

// FDE[03] 0x3288..0x3298 (16 bytes) — Exported convertToVerifyRet
int convertToVerifyRet(int status) noexcept;

// FDE[04] 0x3298..0x337c (228 bytes) — Exported registerNativeMethods
int registerNativeMethods(void* jni_env, const CustomVerifyJniClassDesc* desc) noexcept;

// FDE[05] 0x337c..0x3578 (508 bytes) — Exported init_clsz
void init_clsz(void* thiz, void* jni_env) noexcept;

// FDE[06] 0x3578..0x35dc (100 bytes) — Exported ToJavaByteArray
void* ToJavaByteArray(void* jni_env, const std::uint8_t* data, std::size_t len) noexcept;

// FDE[07] 0x35dc..0x3794 (440 bytes) — Exported ToJavaArrayOfByteArray
void* ToJavaArrayOfByteArray(const void* x509_store_ctx, void* jni_env) noexcept;

// FDE[08] 0x3794..0x3b4c (952 bytes) — Exported vcn_internal_custom_verify_android
int vcn_internal_custom_verify_android(
    const void* x509_store_ctx,
    void* arg,
    const char* hostname) noexcept;

// FDE[09] 0x3b4c..0x3cb0 (356 bytes) — Exported JNI_OnLoad
int JNI_OnLoad(void* java_vm, void* reserved) noexcept;

// FDE[10] 0x3cb0..0x3cb4 (4 bytes) — Exported JNI_OnUnload
void JNI_OnUnload(void* java_vm, void* reserved) noexcept;

// FDE[11] 0x3cb4..0x3cc0 (12 bytes) — pthread_once indirect thunk
void pthread_once_thunk_3cb4(void (*fn)(void*), void* arg) noexcept;

// FDE[12] 0x3cc0..0x3cc8 (8 bytes) — JNI _init native method thunk
void _init_3cc0(void* jni_env, void* thiz) noexcept;

} // extern "C"

// Accessor to global runtime state mirror
// Hàm truy xuất trạng thái toàn cục của module ttmverifylite
TtmVerifyLiteGlobalState& GetGlobalState() noexcept;

} // namespace nextai::opencut::ttmverifylite
