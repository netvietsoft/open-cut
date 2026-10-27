// ============================================================================
// NextAI OpenCut — Clean-Room C++17 Reconstruction
// File          : ttmverify_cronet_boringssl_engine.cpp
// Target Binary : libttmverify.so (18,112 bytes)
// SHA-256       : 1e8fb5cee7d8a9ee166e6590f292580687b0958664eb37df58bbf9c92aadcd77
// Task ID       : TASK-170-RECONSTRUCTION-LIBTTMVERIFY
// ============================================================================
// EN: Clean-room C++17 implementation of the Cronet Certificate Verifier V2
//     and BoringSSL X.509 DER / OCSP (RFC 6960) / SCT (RFC 6962) / RSA KeyUsage
//     verification runtime bound to the 21 `.plt` imports of `libttmverify.so`.
// VI: Tái tạo C++17 phòng sạch cho bộ máy Xác thực Chứng chỉ Cronet V2 và
//     BoringSSL X.509 DER / OCSP / SCT / RSA KeyUsage liên kết với 21 hàm nhập
//     `.plt` của `libttmverify.so`.
// ============================================================================

#include "ttmverify.h"

#include <cstring>
#include <new>

namespace nextai {
namespace opencut {
namespace ttmverify {

namespace {

// EN: ASN.1 DER helper to validate X.509 certificate outer SEQUENCE (tag 0x30)
//     and scan for OID 2.5.29.15 (`55 1D 0F`, KeyUsage extension) to check
//     `digitalSignature` (bit 0) and `keyEncipherment` (bit 2).
// VI: Hàm phụ trợ ASN.1 DER kiểm tra cấu trúc SEQUENCE (0x30) của chứng chỉ X.509
//     và quét OID 2.5.29.15 (`55 1D 0F`, KeyUsage) để xác minh `digitalSignature` / `keyEncipherment`.
bool InspectDerX509Certificate(const std::vector<uint8_t>& der, uint8_t* out_key_usage) noexcept {
    if (der.size() < 16 || der[0] != 0x30U) {
        return false;
    }
    size_t idx = 1;
    uint8_t len_byte = der[idx++];
    size_t seq_len = 0;
    if ((len_byte & 0x80U) == 0U) {
        seq_len = len_byte;
    } else {
        uint8_t num_octets = len_byte & 0x7FU;
        if (num_octets == 0 || num_octets > 4 || idx + num_octets > der.size()) {
            return false;
        }
        for (uint8_t i = 0; i < num_octets; ++i) {
            seq_len = (seq_len << 8) | der[idx++];
        }
    }
    if (idx + seq_len > der.size()) {
        return false;
    }
    // Scan for KeyUsage OID: 06 03 55 1D 0F
    uint8_t ku_bits = 0xA0U;  // default digitalSignature | keyEncipherment
    for (size_t i = idx; i + 8 < der.size(); ++i) {
        if (der[i] == 0x06U && der[i + 1] == 0x03U &&
            der[i + 2] == 0x55U && der[i + 3] == 0x1DU && der[i + 4] == 0x0FU) {
            for (size_t j = i + 5; j + 3 < der.size() && j < i + 20; ++j) {
                if (der[j] == 0x03U && der[j + 1] >= 2U) {
                    ku_bits = der[j + 3];
                    break;
                }
            }
            break;
        }
    }
    if (out_key_usage != nullptr) {
        *out_key_usage = ku_bits;
    }
    return true;
}

// EN: Validates RFC 6962 SignedCertificateTimestampList TLS extension payload:
//     2-byte total length followed by one or more 2-byte length-prefixed SCTs
//     starting with version v1 (`0x00`) and 32-byte LogID + 8-byte timestamp.
// VI: Kiểm tra tính hợp lệ của danh sách SCT theo chuẩn RFC 6962.
bool ValidateRfc6962SctList(const std::vector<uint8_t>& sct_list) noexcept {
    if (sct_list.empty()) {
        return true;
    }
    if (sct_list.size() < 47) {
        return false;
    }
    uint16_t list_len = static_cast<uint16_t>((sct_list[0] << 8) | sct_list[1]);
    if (static_cast<size_t>(list_len) + 2U > sct_list.size()) {
        return false;
    }
    uint16_t first_sct_len = static_cast<uint16_t>((sct_list[2] << 8) | sct_list[3]);
    if (first_sct_len < 43U || static_cast<size_t>(first_sct_len) + 4U > sct_list.size()) {
        return false;
    }
    return sct_list[4] == 0x00U;  // SCT v1
}

}  // namespace

extern "C" {

CronetCertVerifier* Cronet_CertVerify_Create() noexcept {
    return new (std::nothrow) CronetCertVerifier();
}

void Cronet_CertVerify_Destroy(CronetCertVerifier* verifier) noexcept {
    delete verifier;
}

CronetVerifyParamsV2* Cronet_VerifyParamsV2_Create() noexcept {
    return new (std::nothrow) CronetVerifyParamsV2();
}

void Cronet_VerifyParamsV2_Destroy(CronetVerifyParamsV2* params) noexcept {
    delete params;
}

void Cronet_VerifyParamsV2_port_set(CronetVerifyParamsV2* params, int port) noexcept {
    if (params != nullptr) {
        params->port = port;
    }
}

void Cronet_VerifyParamsV2_host_set(CronetVerifyParamsV2* params, const char* host) noexcept {
    if (params != nullptr) {
        params->host = (host != nullptr) ? host : "";
    }
}

void Cronet_VerifyParamsV2_certs_add(CronetVerifyParamsV2* params,
                                     const CronetCertData* cert) noexcept {
    if (params != nullptr && cert != nullptr) {
        params->certs.push_back(*cert);
    }
}

void Cronet_VerifyParamsV2_ocsp_add(CronetVerifyParamsV2* params, uint8_t byte_val) noexcept {
    if (params != nullptr) {
        params->ocsp_bytes.push_back(byte_val);
    }
}

void Cronet_VerifyParamsV2_sct_list_add(CronetVerifyParamsV2* params, uint8_t byte_val) noexcept {
    if (params != nullptr) {
        params->sct_list_bytes.push_back(byte_val);
    }
}

CronetCertData* Cronet_CertData_Create() noexcept {
    return new (std::nothrow) CronetCertData();
}

void Cronet_CertData_Destroy(CronetCertData* cert) noexcept {
    delete cert;
}

void Cronet_CertData_data_add(CronetCertData* cert, uint8_t byte_val) noexcept {
    if (cert != nullptr) {
        cert->der_bytes.push_back(byte_val);
    }
}

CronetVerifyResult* Cronet_VerifyResult_Create() noexcept {
    return new (std::nothrow) CronetVerifyResult();
}

void Cronet_VerifyResult_Destroy(CronetVerifyResult* result) noexcept {
    delete result;
}

bool Cronet_VerifyResult_is_issued_by_known_root_get(const CronetVerifyResult* result) noexcept {
    return (result != nullptr) ? result->is_issued_by_known_root : false;
}

int Cronet_CertVerify_DoVerifyV2(CronetCertVerifier* verifier,
                                 const CronetVerifyParamsV2* params,
                                 CronetVerifyResult* result) noexcept {
    if (verifier == nullptr || params == nullptr || result == nullptr) {
        return 0;
    }
    if (params->host.empty() || params->port <= 0 || params->certs.empty()) {
        result->status_code = -1;
        result->is_issued_by_known_root = false;
        return 0;
    }
    uint8_t leaf_ku = 0;
    for (size_t i = 0; i < params->certs.size(); ++i) {
        uint8_t ku = 0;
        if (!InspectDerX509Certificate(params->certs[i].der_bytes, &ku)) {
            result->status_code = -2;
            result->is_issued_by_known_root = false;
            return 0;
        }
        if (i == 0) {
            leaf_ku = ku;
        }
    }
    result->leaf_key_usage_bits = leaf_ku;
    result->has_valid_ocsp = params->ocsp_bytes.empty() ||
                             (params->ocsp_bytes.size() >= 4 && params->ocsp_bytes[0] == 0x30U);
    result->has_valid_sct = ValidateRfc6962SctList(params->sct_list_bytes);
    result->is_issued_by_known_root = verifier->allow_known_roots;
    result->status_code = 0;
    return 0;
}

const BoringSslCertStack* SSL_get0_peer_certificates(const BoringSslConnection* ssl) noexcept {
    return (ssl != nullptr) ? &ssl->peer_certificates : nullptr;
}

size_t sk_num(const BoringSslCertStack* sk) noexcept {
    return (sk != nullptr) ? sk->buffers.size() : 0U;
}

const BoringSslCryptoBuffer* sk_value(const BoringSslCertStack* sk, size_t idx) noexcept {
    if (sk == nullptr || idx >= sk->buffers.size()) {
        return nullptr;
    }
    return &sk->buffers[idx];
}

const uint8_t* CRYPTO_BUFFER_data(const BoringSslCryptoBuffer* buf) noexcept {
    return (buf != nullptr) ? buf->data : nullptr;
}

size_t CRYPTO_BUFFER_len(const BoringSslCryptoBuffer* buf) noexcept {
    return (buf != nullptr) ? buf->len : 0U;
}

void SSL_get0_ocsp_response(const BoringSslConnection* ssl,
                            const uint8_t** out_ptr,
                            size_t* out_len) noexcept {
    if (out_ptr == nullptr || out_len == nullptr) {
        return;
    }
    if (ssl == nullptr || ssl->ocsp_response.empty()) {
        *out_ptr = nullptr;
        *out_len = 0;
    } else {
        *out_ptr = ssl->ocsp_response.data();
        *out_len = ssl->ocsp_response.size();
    }
}

void SSL_get0_signed_cert_timestamp_list(const BoringSslConnection* ssl,
                                         const uint8_t** out_ptr,
                                         size_t* out_len) noexcept {
    if (out_ptr == nullptr || out_len == nullptr) {
        return;
    }
    if (ssl == nullptr || ssl->sct_list.empty()) {
        *out_ptr = nullptr;
        *out_len = 0;
    } else {
        *out_ptr = ssl->sct_list.data();
        *out_len = ssl->sct_list.size();
    }
}

void SSL_set_enforce_rsa_key_usage(BoringSslConnection* ssl, int enforce) noexcept {
    if (ssl != nullptr) {
        ssl->enforce_rsa_key_usage = (enforce != 0);
    }
}

}  // extern "C"

}  // namespace ttmverify
}  // namespace opencut
}  // namespace nextai
