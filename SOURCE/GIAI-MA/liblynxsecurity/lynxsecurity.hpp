// ============================================================================
// File: lynxsecurity.hpp
// Project: NextAI OpenCut (com.nextai.opencut)
// Target Binary: liblynxsecurity.so (51,112 bytes)
// SHA-256: 2895aab91226bc7ece7795ff2d2aad3b2a947c346946347c454d32cfdabd8c15
// Task ID: TASK-188-RECONSTRUCTION-LIBLYNXSECURITY (TASK_SO_152_liblynxsecurity)
// Architecture: AArch64 (ARM64-v8a) — 106 FDEs (.eh_frame_hdr @ 0x12c4), 5 Exports
// Clean-Room C++17 Header: ByteDance Lynx Template Signature Block Parser &
// BoringSSL EVP RSA-SHA256 Public Key Verification Engine
// ============================================================================
// [EN] Bilingual architectural header defining exact ABI structures, Lynx
// template signature block framing, and RSA-SHA256 verification entrypoints.
// [VN] Tệp tiêu đề kiến trúc song ngữ định nghĩa chính xác các cấu trúc ABI,
// khung khối chữ ký mẫu Lynx và các điểm vào xác thực chữ ký RSA-SHA256.
// ============================================================================

#pragma once

#include <cstdint>
#include <cstddef>
#include <cstring>
#include <jni.h>

namespace bytedance {
namespace lynx {
namespace security {

// ============================================================================
// [EN] 1. Binary Constants & Section Geometry (Observed from ELF64)
// [VN] 1. Hằng số nhị phân & Hình học phân đoạn (Quan sát từ ELF64)
// ============================================================================
constexpr std::size_t kBinaryFileSizeBytes   = 51112ULL;
constexpr std::uint64_t kRodataSectionVaddr  = 0x0fa0ULL;
constexpr std::uint64_t kRodataSectionSize   = 0x0321ULL; // 801 bytes
constexpr std::uint64_t kEhFrameHdrVaddr     = 0x12c4ULL;
constexpr std::uint64_t kEhFrameHdrSize      = 0x035cULL; // 860 bytes (106 FDEs)
constexpr std::uint64_t kEhFrameVaddr        = 0x1620ULL;
constexpr std::uint64_t kEhFrameSize         = 0x0b84ULL; // 2,948 bytes
constexpr std::uint64_t kTextSectionVaddr    = 0x4000ULL;
constexpr std::uint64_t kTextSectionSize     = 0x34ccULL; // 13,516 bytes (3,379 insns)
constexpr std::uint64_t kPltSectionVaddr     = 0x74d0ULL;
constexpr std::uint64_t kPltSectionSize      = 0x01f0ULL; // 496 bytes
constexpr std::uint64_t kDataRelRoVaddr      = 0x8000ULL;
constexpr std::uint64_t kDataRelRoSize       = 0x00d0ULL; // 208 bytes
constexpr std::uint64_t kBssSectionVaddr     = 0xc000ULL;
constexpr std::uint64_t kBssSectionSize      = 0x0060ULL; // 96 bytes

// ============================================================================
// [EN] 2. Lynx Template Signature Block Framing & Keystore ABI Structures
//         Observed in FDE[25] ReadSignBlock (0x4c58..0x55e4) and
//         FDE[26] VerifyRsaSha256Signature (0x55e4..0x5974)
// [VN] 2. Cấu trúc ABI Khung Chữ Ký Mẫu Lynx & Kho Khóa Công Khai RSA
//         Quan sát tại FDE[25] ReadSignBlock (0x4c58..0x55e4) và
//         FDE[26] VerifyRsaSha256Signature (0x55e4..0x5974)
// ============================================================================
struct LynxSignBlockView {
    const std::uint8_t* data_ptr;      // +0x00: Pointer to template payload
    std::uint64_t       payload_len;   // +0x08: Length of unsigned template payload
    const std::uint8_t* sig_ptr;       // +0x10: Pointer to signature bytes
    std::uint32_t       sig_len;       // +0x18: Signature byte length
    std::uint32_t       key_id;        // +0x1c: Public key identifier / algorithm tag
};
static_assert(sizeof(LynxSignBlockView) == 0x20, "LynxSignBlockView ABI size must be 32 bytes");

struct LynxSecurityKeystoreSingleton {
    std::uint64_t mutex_word[5];       // +0x00..0x27: std::__ndk1::mutex (40 B @ .bss 0xc008)
    void*         bucket_list_ptr;     // +0x28: unordered_map bucket array
    std::size_t   bucket_count;        // +0x30: unordered_map bucket count
    void*         head_node_ptr;       // +0x38: intrusive hash node head
    std::size_t   element_count;       // +0x40: number of registered RSA public keys
    float         max_load_factor;     // +0x48: 1.0f (0x3f800000)
    std::uint32_t pad;                 // +0x4c
};
static_assert(sizeof(LynxSecurityKeystoreSingleton) == 0x50, "LynxSecurityKeystoreSingleton ABI size must be 80 bytes");

// ============================================================================
// [EN] 3. Core Clean-Room Function Declarations
// [VN] 3. Khai báo các hàm C++17 phòng sạch cốt lõi
// ============================================================================
bool ReadU32_le(const std::uint8_t* buf, std::size_t len, std::size_t& offset, std::uint32_t& out_val) noexcept;
bool ReadU64_le(const std::uint8_t* buf, std::size_t len, std::size_t& offset, std::uint64_t& out_val) noexcept;
int ParseLynxSignBlock_4c58(const std::uint8_t* buf, std::size_t len, LynxSignBlockView& out_view) noexcept;
bool VerifyEvpSha256Signature_55e4(const std::uint8_t* payload, std::size_t payload_len,
                                   const std::uint8_t* sig, std::size_t sig_len,
                                   const std::uint8_t* der_pubkey, std::size_t pubkey_len) noexcept;
std::uint32_t execute_all_fde_simulations() noexcept;

} // namespace security
} // namespace lynx
} // namespace bytedance

extern "C" {
JNIEXPORT jint JNICALL Java_com_bytedance_lynx_service_security_LynxSecurityService_nativeVerifySignBlock(
    JNIEnv* env, jobject thiz, jobject byte_buffer, jint length, jstring key_name, jobjectArray out_error_msg);
JNIEXPORT void JNICALL Java_com_bytedance_lynx_service_security_LynxSecurityService_nativeUpdateRsaPublicKeys(
    JNIEnv* env, jobject thiz, jobjectArray key_names, jobjectArray base64_pubkeys);
}
