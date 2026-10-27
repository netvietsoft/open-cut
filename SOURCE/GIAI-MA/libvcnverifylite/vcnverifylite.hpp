// ============================================================================
// File: vcnverifylite.hpp
// Library: libvcnverifylite.so (34,640 bytes)
// SHA-256: 9c1a1617357a0b640d2b159060c9d927cfdb4b430d6da55da8664004049fe93f
// Task ID: TASK-179-RECONSTRUCTION-LIBVCNVERIFYLITE / TASK_SO_044_libvcnverifylite
// Architecture: AArch64 (arm64-v8a) - ByteDance VCN TLS X.509 Hostname & Certificate Chain Verifier
// Source Origin: custom_verify_android.c (Compiled Dec 20 2024 04:51:21)
// Clean-Room C++17 Header with Bilingual English + Vietnamese Annotations
// ============================================================================

#pragma once

#include <cstdint>
#include <cstddef>
#include <jni.h>
#include <pthread.h>

namespace vcn::verifylite {

// ============================================================================
// 1. Constants & X.509 / BoringSSL Types / Hằng số & Kiểu dữ liệu X.509
// ============================================================================

enum CertVerifyStatus : int32_t {
    kVerifyMatchFound          = 1,
    kVerifyMatchNotFound       = 0,
    kVerifyErrorMalformedCert  = -1,
    kVerifyStatusOk            = 0,
    kVerifyStatusFailed        = 1,
};

constexpr int kNidCommonName           = 13; // 0x0d (X509_NAME_get_index_by_NID)
constexpr int kNidSubjectAltName       = 85; // 0x55 (X509_get_ext_d2i)
constexpr int kGenDnsName              = 2;  // GENERAL_NAME::GEN_DNS

// Forward declarations for BoringSSL / OpenSSL structures imported via PLT
struct X509_st;
struct X509_NAME_st;
struct X509_NAME_ENTRY_st;
struct ASN1_STRING_st;
struct CRYPTO_BUFFER_st;
struct _STACK;
struct SSL_st;

struct GENERAL_NAME_st {
    int type;
    union {
        char*           ptr;
        ASN1_STRING_st* dNSName;
        ASN1_STRING_st* iPAddress;
    } d;
};

/**
 * EN: Global state layout in .bss 0x0c000..0x0c048 (72 bytes).
 * VN: Bố cục trạng thái toàn cục trong .bss 0x0c000..0x0c048 (72 bytes).
 */
struct VcnVerifyGlobalState {
    pthread_mutex_t lock;               // +0x00 (0x0c000, 40 bytes)
    uint8_t         has_init;           // +0x28 (0x0c028, 1 byte)
    uint8_t         pad_29[7];          // +0x29
    jclass          g_verify_cls;       // +0x30 (0x0c030, GlobalRef to com/ss/mediakit/vcnlib/CustomVerify)
    jmethodID       g_verify_method;    // +0x38 (0x0c038, static doVerify([[BLjava/lang/String;Ljava/lang/String;)I)
    JavaVM*         g_jvm;              // +0x40 (0x0c040, JavaVM*)
};
static_assert(sizeof(VcnVerifyGlobalState) == 0x48, "VcnVerifyGlobalState ABI must be 72 bytes");

// ============================================================================
// 2. Reconstructed Functions (All 8 FDEs: 0x104c..0x41f0)
// ============================================================================

int AvCertHostcheck_104c(const char* pattern, const char* hostname) noexcept;
int ValidateHostname_Inlined_104c(const char* hostname, X509_st* cert) noexcept;
void GeneralNameFreeTrampoline_3338(void (*free_fn)(void*), void* item) noexcept;
void VcnVerifyLogPrint_3344(const char* func_name, int line, const char* fmt, ...);
int InitCustomVerifyClass_3418(JNIEnv* env);
int VcnInternalCustomVerifyAndroid_35bc(SSL_st* ssl, const char* auth_type, const char* hostname);

extern "C" {
    JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved);      // 0x3fec (508 B)
    JNIEXPORT void JNICALL JNI_OnUnload(JavaVM* vm, void* reserved);    // 0x41ec (4 B)
}

// Raw ELF sections in vcnverifylite_elf_sections_and_image.cpp
extern const uint32_t kPltSectionWords_0e40[116];
extern const uint32_t kTextSectionWords_1010[3192];
extern const uint8_t  kRodataSection_41f0[2136];
extern const uint8_t  kEhFrameHdrSection_4a48[76];
extern const uint8_t  kEhFrameSection_4a98[304];
extern const uint8_t  kDataRelRoSection_bca0[32];

bool VerifyBinarySectionsIntegrity() noexcept;
uint32_t ReadTextInstructionWord(uint32_t va) noexcept;

} // namespace vcn::verifylite
