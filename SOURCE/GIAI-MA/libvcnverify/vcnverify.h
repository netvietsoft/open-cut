// ============================================================================
// NextAI OpenCut — Clean-Room C++17 Reconstruction
// Target Binary : libvcnverify.so (18,184 bytes)
// SHA-256       : cb4928063eb3e668c4df210a200e8821a6da265e852ba86c968ac24371a8d1ef
// Task ID       : TASK-173-RECONSTRUCTION-LIBVCNVERIFY
// Legacy Task   : TASK_SO_045_libvcnverify
// Architecture  : AArch64 (ARM64-v8a) ELF64 Shared Library
// ============================================================================
// EN: Bilingual clean-room header for ByteDance VCN Network Custom TLS
//     Certificate Verifier (`libvcnverify.so`, .text 0x11b0..0x1704,
//     4 FDEs @ 0x1918, 341 AArch64 instructions, 2 exported JNI symbols).
// VI: File header C++17 phòng sạch song ngữ cho Bộ Xác thực Chứng chỉ TLS
//     Tùy chỉnh của Mạng VCN ByteDance (`libvcnverify.so`, .text 0x11b0..0x1704,
//     4 FDE @ 0x1918, 341 lệnh AArch64, 2 biểu tượng JNI xuất khẩu).
// ============================================================================

#ifndef NEXTAI_OPENCUT_VCNVERIFY_H_
#define NEXTAI_OPENCUT_VCNVERIFY_H_

#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace nextai {
namespace opencut {
namespace vcnverify {

// EN: Constants verified from AArch64 opcodes in `libvcnverify.so`:
//     - JNI version returned by `JNI_OnLoad` (0x12c0): 0x00010004 (JNI_VERSION_1_4)
//       at 0x131c..0x1328 and 0x134c..0x1350 (`mov w0, #4; movk w0, #1, lsl #16`).
//     - Error code when `Cronet_CertVerify_Create()` fails at 0x1518..0x1530:
//       `mov w23, #0x7962; movk w23, #0xfffe, lsl #16` -> `0xFFFE7962` (`-99998`).
//     - Error code when `Cronet_VerifyParamsV2_Create()` fails at 0x168c..0x1698:
//       `mov w8, #0x7962; movk w8, #0xfffe, lsl #16; orr w23, w8, #1` -> `0xFFFE7963` (`-99997`).
//     - Telemetry key passed to `vcn_av_net_info(ctx, 0x177a, status, nullptr)` at 0x16b8:
//       `mov w1, #0x177a` (`6010`).
// VI: Các hằng số xác minh từ mã máy AArch64 trong `libvcnverify.so`.
constexpr int32_t  kVcnVerifyJniVersion1_4       = 0x00010004;
constexpr size_t   kVcnVerifyLogBufSize          = 0x200U;      // 512 bytes (0x1254)
constexpr int32_t  kAndroidLogDebugPriority      = 3;           // 0x1288
constexpr int32_t  kVcnAvLogLevelDebug           = 0x30;        // 48 (0x13b0)
constexpr int32_t  kErrCreateVerifyPtrFailed     = -99998;      // 0xFFFE7962 (0x1518..0x1530)
constexpr int32_t  kErrCreateVerifyParamFailed   = -99997;      // 0xFFFE7963 (0x168c..0x1698)
constexpr int32_t  kVcnNetInfoCertVerifyResultId = 0x177A;      // 6010 (0x16b8)

// EN: Compile-time metadata in `.rodata` (0x1704..0x17e5):
//     - Tag: `"vcnnetwork"` (0x1714)
//     - Source file: `"custom_verify.c"` (0x171f)
//     - Build date: `"Dec 20 2024"` (0x1763), Build time: `"04:51:21"` (0x176f)
//     - Internal callback name: `"vcn_internal_custom_verify"` (0x17cb)
// VI: Siêu dữ liệu biên dịch nhúng trong `.rodata` (0x1704..0x17e5).
constexpr const char* kVcnNetworkLogTag        = "vcnnetwork";
constexpr const char* kVcnVerifySourceFile     = "custom_verify.c";
constexpr const char* kVcnVerifyBuildDate      = "Dec 20 2024";
constexpr const char* kVcnVerifyBuildTime      = "04:51:21";
constexpr const char* kVcnInternalFuncName     = "vcn_internal_custom_verify";

struct VcnSslCryptoBuffer {
    const uint8_t* data;
    size_t         len;
};

struct VcnSslCertStack {
    std::vector<VcnSslCryptoBuffer> buffers;
};

struct VcnSslConnection {
    VcnSslCertStack      peer_certificates;
    std::vector<uint8_t> ocsp_response;
    std::vector<uint8_t> sct_list;
    bool                 enforce_rsa_key_usage = false;
};

struct VcnVerifyInsnRecord {
    uint32_t    va;
    uint32_t    opcode_word;
    const char* mnemonic;
    const char* operands;
    int32_t     fde_index;
};

extern const uint8_t             kVcnVerifyRodata529[529];
extern const uint8_t             kVcnVerifyEhFrame208[208];
extern const uint32_t            kVcnVerifyPltWords136[136];
extern const uint32_t            kVcnVerifyTextWords341[341];
extern const VcnVerifyInsnRecord kVcnVerifyDisassemblyTable477[477];

using VcnCustomVerifyCallbackFn = int (*)(void* ctx, VcnSslConnection* ssl,
                                          const char* host, int port);

extern "C" {
void set_vcn_custom_verify_callback(VcnCustomVerifyCallbackFn cb) noexcept;
void vcn_av_ll(void* ctx, int level, const char* file, const char* func,
               int line, const char* fmt, ...) noexcept;
void vcn_av_net_info(void* ctx, int info_key, int64_t info_val, void* extra) noexcept;

// EN: Exported JNI symbols of `libvcnverify.so` (.dynsym indices 42 and 40).
// VI: 2 biểu tượng JNI xuất khẩu của `libvcnverify.so` (.dynsym chỉ mục 42 và 40).
int  JNI_OnLoad(void* vm, void* reserved) noexcept;
void JNI_OnUnload(void* vm, void* reserved) noexcept;
}  // extern "C"

void VcnVerifyLogPrint(int line, const char* fmt, ...) noexcept;
int VcnInternalCustomVerify(void* ctx, VcnSslConnection* ssl, const char* host, int port) noexcept;
int64_t GetLastReportedVcnNetInfoStatus() noexcept;

}  // namespace vcnverify
}  // namespace opencut
}  // namespace nextai

#endif  // NEXTAI_OPENCUT_VCNVERIFY_H_
