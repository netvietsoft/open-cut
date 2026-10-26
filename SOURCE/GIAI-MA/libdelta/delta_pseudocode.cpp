// ============================================================================
// File: delta_pseudocode.cpp
// Library: libdelta.so (ARM64-v8a, 18,256 bytes, 71 dynamic symbols)
// Task ID: TASK-090-RECONSTRUCTION-LIBDELTA (Target 51 / TASK_SO_159)
// Description:
//   EN: Complete ELF64 symbol & PLT dispatch registry for libdelta.so, mapping
//       all 19 exported JNI functions ([055]..[073]), all 4 internal .text
//       helpers (0x002d0c..0x003228), and all 43 .rela.plt / .plt entries
//       (0x001850..0x001af0 -> .got 0x007ea0..0x007ff0).
//   VN: Bảng đăng ký ký hiệu ELF64 & điều phối PLT hoàn chỉnh cho libdelta.so,
//       ánh xạ toàn bộ 19 hàm xuất JNI ([055]..[073]), 4 hàm nội bộ .text
//       (0x002d0c..0x003228), và 43 mục .rela.plt / .plt (0x001850..0x001af0).
// ============================================================================

#include "delta_interface.h"

namespace bytedance {
namespace zdplib {
namespace delta {

struct DeltaSymbolDescriptor {
    uint32_t    dynsym_idx;
    uint32_t    vaddr;
    uint32_t    size_bytes;
    const char* symbol_name;
    const void* fn_ptr;
};

static const DeltaSymbolDescriptor kExportedJniSymbols[19] = {
    {55, 0x001fb0, 220, "Java_net_bytedance_zdplib_Delta_initPubKey",                              reinterpret_cast<const void*>(&Java_net_bytedance_zdplib_Delta_initPubKey)},
    {56, 0x002438, 292, "Java_net_bytedance_zdplib_Delta_getPublicKey",                            reinterpret_cast<const void*>(&Java_net_bytedance_zdplib_Delta_getPublicKey)},
    {57, 0x002b84, 100, "Java_net_bytedance_zdplib_DeltaSignerVerifier_generatePrivateKey",        reinterpret_cast<const void*>(&Java_net_bytedance_zdplib_DeltaSignerVerifier_generatePrivateKey)},
    {58, 0x001c98, 708, "Java_net_bytedance_zdplib_Delta_encrypt",                                 reinterpret_cast<const void*>(&Java_net_bytedance_zdplib_Delta_encrypt)},
    {59, 0x002918, 292, "Java_net_bytedance_zdplib_DeltaSignerVerifier_getPublicKey",              reinterpret_cast<const void*>(&Java_net_bytedance_zdplib_DeltaSignerVerifier_getPublicKey)},
    {60, 0x002430,   8, "Java_net_bytedance_zdplib_Delta_getDecryptedLen",                         reinterpret_cast<const void*>(&Java_net_bytedance_zdplib_Delta_getDecryptedLen)},
    {61, 0x002b34,   4, "Java_net_bytedance_zdplib_DeltaSignerVerifier_verify",                    reinterpret_cast<const void*>(&Java_net_bytedance_zdplib_DeltaSignerVerifier_verify)},
    {62, 0x002be8, 292, "Java_net_bytedance_zdplib_DeltaSignerVerifier_getPublicKeyUncompressed",  reinterpret_cast<const void*>(&Java_net_bytedance_zdplib_DeltaSignerVerifier_getPublicKeyUncompressed)},
    {63, 0x002b38,  76, "Java_net_bytedance_zdplib_DeltaSignerVerifier_free",                      reinterpret_cast<const void*>(&Java_net_bytedance_zdplib_DeltaSignerVerifier_free)},
    {64, 0x00208c, 140, "Java_net_bytedance_zdplib_Delta_initPrivateKey",                          reinterpret_cast<const void*>(&Java_net_bytedance_zdplib_Delta_initPrivateKey)},
    {65, 0x001b3c, 348, "Java_net_bytedance_zdplib_Delta_generateAesKey",                          reinterpret_cast<const void*>(&Java_net_bytedance_zdplib_Delta_generateAesKey)},
    {66, 0x002118, 100, "Java_net_bytedance_zdplib_Delta_generatePrivateKey",                      reinterpret_cast<const void*>(&Java_net_bytedance_zdplib_Delta_generatePrivateKey)},
    {67, 0x002a3c, 248, "Java_net_bytedance_zdplib_DeltaSignerVerifier_sign",                      reinterpret_cast<const void*>(&Java_net_bytedance_zdplib_DeltaSignerVerifier_sign)},
    {68, 0x001f5c,   8, "Java_net_bytedance_zdplib_Delta_getEncryptedLen",                         reinterpret_cast<const void*>(&Java_net_bytedance_zdplib_Delta_getEncryptedLen)},
    {69, 0x001f64,  76, "Java_net_bytedance_zdplib_Delta_free",                                    reinterpret_cast<const void*>(&Java_net_bytedance_zdplib_Delta_free)},
    {70, 0x00217c, 692, "Java_net_bytedance_zdplib_Delta_decrypt",                                 reinterpret_cast<const void*>(&Java_net_bytedance_zdplib_Delta_decrypt)},
    {71, 0x00255c, 248, "Java_net_bytedance_zdplib_Delta_sign",                                    reinterpret_cast<const void*>(&Java_net_bytedance_zdplib_Delta_sign)},
    {72, 0x002654, 568, "Java_net_bytedance_zdplib_Delta_verify",                                  reinterpret_cast<const void*>(&Java_net_bytedance_zdplib_Delta_verify)},
    {73, 0x00288c, 140, "Java_net_bytedance_zdplib_DeltaSignerVerifier_initPrivateKey",            reinterpret_cast<const void*>(&Java_net_bytedance_zdplib_DeltaSignerVerifier_initPrivateKey)}
};

static const DeltaSymbolDescriptor kInternalTextHelpers[4] = {
    {0, 0x002d0c, 500, "create_EC_KEY_from_private_key_bin", reinterpret_cast<const void*>(&create_EC_KEY_from_private_key_bin)},
    {0, 0x002f00, 380, "create_EC_KEY_from_public_key_bin",  reinterpret_cast<const void*>(&create_EC_KEY_from_public_key_bin)},
    {0, 0x00307c, 216, "generate_keypair",                   reinterpret_cast<const void*>(&generate_keypair)},
    {0, 0x003154, 216, "sign",                               reinterpret_cast<const void*>(&sign_ecdsa_sha256)}
};

struct DeltaPltEntry {
    uint32_t    plt_vaddr;
    uint32_t    got_vaddr;
    uint32_t    dynsym_idx;
    const char* symbol_name;
};

static constexpr DeltaPltEntry kDeltaPltTable[43] = {
    {0x001850, 0x007ea0, 13, "EVP_DecryptFinal_ex"},
    {0x001860, 0x007ea8, 14, "ECDSA_sign"},
    {0x001870, 0x007eb0, 15, "EC_KEY_set_public_key"},
    {0x001880, 0x007eb8, 16, "HKDF"},
    {0x001890, 0x007ec0, 72, "Java_net_bytedance_zdplib_Delta_verify"},
    {0x0018a0, 0x007ec8, 17, "BN_bn2bin_padded"},
    {0x0018b0, 0x007ed0, 18, "EC_POINT_mul"},
    {0x0018c0, 0x007ed8, 19, "EC_KEY_get0_public_key"},
    {0x0018d0, 0x007ee0, 20, "BN_bin2bn"},
    {0x0018e0, 0x007ee8, 21, "RAND_bytes"},
    {0x0018f0, 0x007ef0, 22, "EC_KEY_get0_private_key"},
    {0x001900, 0x007ef8, 23, "EC_POINT_oct2point"},
    {0x001910, 0x007f00, 24, "SHA256_Init"},
    {0x001920, 0x007f08, 25, "BN_free"},
    {0x001930, 0x007f10, 26, "EC_KEY_generate_key"},
    {0x001940, 0x007f18, 27, "EVP_CIPHER_CTX_free"},
    {0x001950, 0x007f20, 28, "EC_KEY_set_private_key"},
    {0x001960, 0x007f28, 29, "__android_log_print"},
    {0x001970, 0x007f30, 30, "EC_GROUP_new_by_curve_name"},
    {0x001980, 0x007f38, 31, "EVP_EncryptUpdate"},
    {0x001990, 0x007f40, 32, "EC_KEY_get0_group"},
    {0x0019a0, 0x007f48, 33, "EVP_DecryptInit_ex"},
    {0x0019b0, 0x007f50, 34, "EVP_EncryptFinal_ex"},
    {0x0019c0, 0x007f58, 35, "EVP_EncryptInit_ex"},
    {0x0019d0, 0x007f60, 36, "EC_POINT_point2oct"},
    {0x0019e0, 0x007f68, 37, "EVP_CIPHER_CTX_ctrl"},
    {0x0019f0, 0x007f70, 38, "__cxa_atexit"},
    {0x001a00, 0x007f78, 39, "EVP_aes_256_gcm"},
    {0x001a10, 0x007f80, 40, "SHA256_Final"},
    {0x001a20, 0x007f88, 41, "EVP_CIPHER_CTX_new"},
    {0x001a30, 0x007f90, 42, "__android_log_assert"},
    {0x001a40, 0x007f98, 43, "EC_KEY_free"},
    {0x001a50, 0x007fa0, 44, "SHA256_Update"},
    {0x001a60, 0x007fa8, 45, "__cxa_finalize"},
    {0x001a70, 0x007fb0, 46, "EVP_DecryptUpdate"},
    {0x001a80, 0x007fb8, 47, "ECDSA_verify"},
    {0x001a90, 0x007fc0, 48, "__stack_chk_fail"},
    {0x001aa0, 0x007fc8, 49, "EC_KEY_set_conv_form"},
    {0x001ab0, 0x007fd0, 50, "EVP_sha256"},
    {0x001ac0, 0x007fd8, 51, "EC_POINT_free"},
    {0x001ad0, 0x007fe0, 52, "EC_POINT_new"},
    {0x001ae0, 0x007fe8, 53, "ECDH_compute_key"},
    {0x001af0, 0x007ff0, 54, "EC_KEY_new_by_curve_name"}
};

size_t GetLibDeltaExportedSymbolCount() noexcept {
    return sizeof(kExportedJniSymbols) / sizeof(kExportedJniSymbols[0]);
}

size_t GetLibDeltaInternalHelperCount() noexcept {
    return sizeof(kInternalTextHelpers) / sizeof(kInternalTextHelpers[0]);
}

size_t GetLibDeltaPltEntryCount() noexcept {
    return sizeof(kDeltaPltTable) / sizeof(kDeltaPltTable[0]);
}

} // namespace delta
} // namespace zdplib
} // namespace bytedance
