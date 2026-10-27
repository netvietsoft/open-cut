// ============================================================================
// NextAI OpenCut — Clean-Room C++17 Reconstruction
// Target Binary : libttmverify.so (18,112 bytes)
// SHA-256       : 1e8fb5cee7d8a9ee166e6590f292580687b0958664eb37df58bbf9c92aadcd77
// Task ID       : TASK-170-RECONSTRUCTION-LIBTTMVERIFY
// Legacy Task   : TASK_SO_064_libttmverify
// Architecture  : AArch64 (ARM64-v8a) ELF64 Shared Library
// ============================================================================
// EN: Bilingual clean-room header for ByteDance TTMediaPlayer / VCN Custom TLS
//     Certificate Verifier Bridge (`libttmverify.so`, .text 0x10d0..0x1554,
//     4 FDEs @ 0x17c0, 289 AArch64 instructions, 3 exported symbols).
// VI: File header C++17 phòng sạch song ngữ cho Cầu nối Xác thực Chứng chỉ TLS
//     Tùy chỉnh của ByteDance TTMediaPlayer / VCN (`libttmverify.so`,
//     .text 0x10d0..0x1554, 4 FDE @ 0x17c0, 289 lệnh AArch64, 3 biểu tượng xuất).
// ============================================================================

#ifndef NEXTAI_OPENCUT_TTMVERIFY_H_
#define NEXTAI_OPENCUT_TTMVERIFY_H_

#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>

namespace nextai {
namespace opencut {
namespace ttmverify {

// EN: Constants verified from AArch64 opcodes in `libttmverify.so`:
//     - JNI version returned by `JNI_OnLoad` (0x10dc): 0x00010004 (JNI_VERSION_1_4)
//       at 0x1154..0x1160 and 0x118c..0x1190 (`mov w0, #4; movk w0, #1, lsl #16`).
//     - Stack buffer capacity in `ttmverify_log_print` (0x119c): 0x200 (512 bytes)
//       at 0x1210 (`mov w1, #0x200`).
//     - Android log priority in `ttmverify_log_print`: 3 (ANDROID_LOG_DEBUG)
//       at 0x1240 (`mov w0, #3`).
//     - FFmpeg `av_log` level in `vcn_custom_verify_2` (0x1280): 0x30 (48 = AV_LOG_DEBUG)
//       at 0x12bc, 0x12e0, 0x1300, 0x1320, 0x1454, 0x14a8, 0x14d4, 0x14ec.
// VI: Các hằng số xác minh từ mã máy AArch64 trong `libttmverify.so`:
//     - Phiên bản JNI trả về từ `JNI_OnLoad` (0x10dc): 0x00010004 (JNI_VERSION_1_4).
//     - Kích thước bộ đệm ngăn xếp trong `ttmverify_log_print` (0x119c): 0x200 (512 byte).
//     - Mức log Android: 3 (ANDROID_LOG_DEBUG) tại 0x1240.
//     - Mức log FFmpeg `av_log`: 0x30 (48 = AV_LOG_DEBUG) tại 0x12bc..0x14ec.
constexpr int32_t kTtmVerifyJniVersion1_4 = 0x00010004;
constexpr size_t  kTtmVerifyLogBufSize    = 0x200U;  // 512 bytes
constexpr int32_t kAndroidLogDebug        = 3;
constexpr int32_t kAvLogDebugLevel        = 0x30;    // 48 (AV_LOG_DEBUG)

// EN: Compile-time metadata embedded in `.rodata` (0x1554..0x162b):
//     - Tag: `"ttmverify"` (0x1554)
//     - Source path: `"/ws/228/bytebus/repositories/5c3c4a07427752e48f86fdc97044d046/441845f4fce963d1741e7f1549652ef4/custom_verify/source/custom_verify.c"` (0x155e)
//     - Build date: `"Jun 26 2025"` (0x1616), Build time: `"12:29:14"` (0x1622)
// VI: Siêu dữ liệu biên dịch nhúng trong `.rodata` (0x1554..0x162b).
constexpr const char* kTtmVerifyLogTag     = "ttmverify";
constexpr const char* kTtmVerifyBuildDate  = "Jun 26 2025";
constexpr const char* kTtmVerifyBuildTime  = "12:29:14";
constexpr const char* kTtmVerifySourceFile = "custom_verify.c";

// EN: Clean-room BoringSSL `CRYPTO_BUFFER` and `SSL` structures used by `vcn_custom_verify_2`
//     (0x1344..0x1494) via `SSL_get0_peer_certificates`, `sk_num`, `sk_value`,
//     `CRYPTO_BUFFER_data`, `CRYPTO_BUFFER_len`, `SSL_get0_ocsp_response`,
//     `SSL_get0_signed_cert_timestamp_list`, and `SSL_set_enforce_rsa_key_usage`.
// VI: Cấu trúc `CRYPTO_BUFFER` và `SSL` của BoringSSL được sử dụng bởi `vcn_custom_verify_2`.
struct BoringSslCryptoBuffer {
    const uint8_t* data;
    size_t         len;
};

struct BoringSslCertStack {
    std::vector<BoringSslCryptoBuffer> buffers;
};

struct BoringSslConnection {
    BoringSslCertStack   peer_certificates;
    std::vector<uint8_t> ocsp_response;
    std::vector<uint8_t> sct_list;
    bool                 enforce_rsa_key_usage = false;
};

// EN: Clean-room Cronet Certificate Verification V2 objects manipulated by
//     `vcn_custom_verify_2` (`0x12ec..0x1514`):
//       - `Cronet_CertData` (`0x138c..0x13bc`)
//       - `Cronet_VerifyParamsV2` (`0x130c..0x1514`)
//       - `Cronet_VerifyResult` (`0x1460..0x149c`)
//       - `Cronet_CertVerify` (`0x12ec..0x1508`)
// VI: Các đối tượng Xác thực Chứng chỉ Cronet V2 được thao tác trong `vcn_custom_verify_2`.
struct CronetCertData {
    std::vector<uint8_t> der_bytes;
};

struct CronetVerifyParamsV2 {
    std::string                 host;
    int32_t                     port = 0;
    std::vector<CronetCertData> certs;
    std::vector<uint8_t>        ocsp_bytes;
    std::vector<uint8_t>        sct_list_bytes;
};

struct CronetVerifyResult {
    int32_t status_code             = 0;
    bool    is_issued_by_known_root = false;
    bool    has_valid_ocsp          = false;
    bool    has_valid_sct           = false;
    uint8_t leaf_key_usage_bits     = 0;
};

struct CronetCertVerifier {
    uint32_t magic = 0x43524E54U;  // "CRNT"
    bool     allow_known_roots = true;
};

// EN: Instruction descriptor for the 289 AArch64 `.text` instructions (0x10d0..0x1554)
//     and 128 `.plt` instructions (0x0ed0..0x10d0).
// VI: Cấu trúc mô tả lệnh cho 289 lệnh AArch64 trong `.text` (0x10d0..0x1554)
//     và 128 lệnh trong `.plt` (0x0ed0..0x10d0).
struct TtmVerifyInsnRecord {
    uint32_t    va;
    uint32_t    opcode_word;
    const char* mnemonic;
    const char* operands;
    int32_t     fde_index;
};

extern const uint8_t             kTtmVerifyRodata617[617];
extern const uint8_t             kTtmVerifyEhFrame216[216];
extern const uint8_t             kTtmVerifyDynsym1032[1032];
extern const uint8_t             kTtmVerifyDynstr979[979];
extern const uint32_t            kTtmVerifyTextWords289[289];
extern const uint32_t            kTtmVerifyPltWords128[128];
extern const TtmVerifyInsnRecord kTtmVerifyDisassemblyTable289[289];

// EN: Custom verify callback signature registered via `tt_set_verify_callback` at 0x113c.
// VI: Chữ ký hàm callback xác thực tùy chỉnh đăng ký qua `tt_set_verify_callback` tại 0x113c.
using TtmCustomVerifyCallbackFn = int (*)(void* ctx, BoringSslConnection* ssl,
                                          const char* host, int port);

// EN: Reconstructed BoringSSL & Cronet V2 C ABI functions imported by `libttmverify.so`.
// VI: Các hàm C ABI của BoringSSL & Cronet V2 được nhập bởi `libttmverify.so`.
extern "C" {
CronetCertVerifier*   Cronet_CertVerify_Create() noexcept;
void                  Cronet_CertVerify_Destroy(CronetCertVerifier* verifier) noexcept;
int                   Cronet_CertVerify_DoVerifyV2(CronetCertVerifier* verifier,
                                                   const CronetVerifyParamsV2* params,
                                                   CronetVerifyResult* result) noexcept;

CronetVerifyParamsV2* Cronet_VerifyParamsV2_Create() noexcept;
void                  Cronet_VerifyParamsV2_Destroy(CronetVerifyParamsV2* params) noexcept;
void                  Cronet_VerifyParamsV2_port_set(CronetVerifyParamsV2* params, int port) noexcept;
void                  Cronet_VerifyParamsV2_host_set(CronetVerifyParamsV2* params, const char* host) noexcept;
void                  Cronet_VerifyParamsV2_certs_add(CronetVerifyParamsV2* params,
                                                      const CronetCertData* cert) noexcept;
void                  Cronet_VerifyParamsV2_ocsp_add(CronetVerifyParamsV2* params, uint8_t byte_val) noexcept;
void                  Cronet_VerifyParamsV2_sct_list_add(CronetVerifyParamsV2* params, uint8_t byte_val) noexcept;

CronetCertData*       Cronet_CertData_Create() noexcept;
void                  Cronet_CertData_Destroy(CronetCertData* cert) noexcept;
void                  Cronet_CertData_data_add(CronetCertData* cert, uint8_t byte_val) noexcept;

CronetVerifyResult*   Cronet_VerifyResult_Create() noexcept;
void                  Cronet_VerifyResult_Destroy(CronetVerifyResult* result) noexcept;
bool                  Cronet_VerifyResult_is_issued_by_known_root_get(const CronetVerifyResult* result) noexcept;

const BoringSslCertStack* SSL_get0_peer_certificates(const BoringSslConnection* ssl) noexcept;
size_t                    sk_num(const BoringSslCertStack* sk) noexcept;
const BoringSslCryptoBuffer* sk_value(const BoringSslCertStack* sk, size_t idx) noexcept;
const uint8_t*            CRYPTO_BUFFER_data(const BoringSslCryptoBuffer* buf) noexcept;
size_t                    CRYPTO_BUFFER_len(const BoringSslCryptoBuffer* buf) noexcept;
void                      SSL_get0_ocsp_response(const BoringSslConnection* ssl,
                                                 const uint8_t** out_ptr,
                                                 size_t* out_len) noexcept;
void                      SSL_get0_signed_cert_timestamp_list(const BoringSslConnection* ssl,
                                                              const uint8_t** out_ptr,
                                                              size_t* out_len) noexcept;
void                      SSL_set_enforce_rsa_key_usage(BoringSslConnection* ssl, int enforce) noexcept;
void                      tt_set_verify_callback(TtmCustomVerifyCallbackFn cb) noexcept;
void                      av_log(void* avcl, int level, const char* fmt, ...) noexcept;

// EN: 3 Exported symbols of `libttmverify.so` (.dynsym indices 20, 23, 41).
// VI: 3 biểu tượng xuất khẩu của `libttmverify.so` (.dynsym chỉ mục 20, 23, 41).
int  JNI_OnLoad(void* vm, void* reserved) noexcept;
int  vcn_custom_verify_2(void* ctx, BoringSslConnection* ssl, const char* host, int port) noexcept;
void JNI_OnUnload(void* vm, void* reserved) noexcept;
}  // extern "C"

void TtmVerifyFormattedLogPrint(void* ctx, const char* file, const char* func,
                                int line, const char* fmt, ...) noexcept;
TtmCustomVerifyCallbackFn GetRegisteredTtmVerifyCallback() noexcept;

}  // namespace ttmverify
}  // namespace opencut
}  // namespace nextai

#endif  // NEXTAI_OPENCUT_TTMVERIFY_H_
