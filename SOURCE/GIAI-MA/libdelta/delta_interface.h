// ============================================================================
// File: delta_interface.h
// Library: libdelta.so (ARM64-v8a)
// Task ID: TASK-090-RECONSTRUCTION-LIBDELTA (Target 51 / TASK_SO_159)
// Description:
//   EN: Public header aggregating all reconstructed headers of libdelta.so
//       and declaring the 7-stage standalone verification suite.
//   VN: Tệp tiêu đề công khai tổng hợp toàn bộ các header tái dựng của
//       libdelta.so và khai báo bộ kiểm thử tự kiểm chứng độc lập 7 giai đoạn.
// ============================================================================

#pragma once

#include "delta_types.h"
#include "delta_crypto_primitives.h"
#include "delta_jni_engine.h"

namespace bytedance {
namespace zdplib {
namespace delta {

// ============================================================================
// EN: VerifyLibDeltaSelfTest — 7-stage standalone verification of ECDH-HKDF,
//     AES-256-GCM 34B wire packet encryption/decryption (0x01bd header, 16B IV,
//     16B tag), NIST P-256 compressed (33B) & uncompressed (65B) SEC1 keys,
//     and ASN.1 DER ECDSA-SHA256 signing/verification.
// VN: Kiểm thử độc lập 7 giai đoạn cho ECDH-HKDF, mã hóa/giải mã gói tin
//     AES-256-GCM bù 34B (header 0x01bd, IV 16B, tag 16B), khóa SEC1 P-256
//     nén (33B) & không nén (65B), và ký/xác thực chữ ký ASN.1 DER ECDSA-SHA256.
// ============================================================================
bool VerifyLibDeltaSelfTest() noexcept;

} // namespace delta
} // namespace zdplib
} // namespace bytedance
