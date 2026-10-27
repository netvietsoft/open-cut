// ============================================================================
// Clean-Room C++17 OLLVM Number-Theoretic Predicates & JNI_OnLoad for libmetasec_ov.so
// Hiện thực C++17 sạch các vị từ lý thuyết số OLLVM & JNI_OnLoad cho libmetasec_ov.so
// ============================================================================
#include "metasec_ov_core.h"
#include <jni.h>

namespace metasec {
namespace ov {

// Reconstructed from 0x04bc40..0x04bc70 & 0x04bd18..0x04bd48:
//   0x04bc40: 1B087D08 mul   w8, w8, w8
//   0x04bc44: 528D7969 mov   w9, #0x6bcb
//   0x04bc48: 531E7508 lsl   w8, w8, #2
//   0x04bc4c: 72B5E509 movk  w9, #0xaf28, lsl #16
//   0x04bc50: 11001108 add   w8, w8, #4
//   0x04bc54: 9BA97D09 umull x9, w8, w9
//   0x04bc58: D360FD29 lsr   x9, x9, #0x20
//   0x04bc5c: 4B09010A sub   w10, w8, w9
//   0x04bc60: 0B4A0529 add   w9, w9, w10, lsr #1
//   0x04bc64: 53047D29 lsr   w9, w9, #4
//   0x04bc68: 5280026A mov   w10, #0x13
//   0x04bc6c: 1B0AA128 msub  w8, w9, w10, w8
uint32_t OllvmPredicateVerifier::RemainderQuad4Mod19(uint32_t x) noexcept {
    uint32_t w8 = ((x * x) << 2) + 4U;
    uint64_t prod = static_cast<uint64_t>(w8) * static_cast<uint64_t>(kOllvmMagicRecipMod19);
    uint32_t w9 = static_cast<uint32_t>(prod >> 32);
    uint32_t w10 = w8 - w9;
    w9 = (w9 + (w10 >> 1)) >> 4;
    return w8 - (w9 * 19U);
}

// Reconstructed from 0x04bc94..0x04bcac:
//   0x04bc94: 320003EA mov  w10, #1
//   0x04bc98: 1B082908 madd w8, w8, w8, w10
//   0x04bc9c: 1B097D29 mul  w9, w9, w9
//   0x04bca0: 531D712A lsl  w10, w9, #3
//   0x04bca4: 4B090149 sub  w9, w10, w9
//   0x04bca8: 6B09011F cmp  w8, w9
bool OllvmPredicateVerifier::IsPellMod7Impossible(uint32_t x, uint32_t y) noexcept {
    uint32_t lhs = x * x + 1U;
    uint32_t y2 = y * y;
    uint32_t rhs = (y2 << 3) - y2; // 7 * y^2
    return lhs != rhs;
}

// Reconstructed from 0x04bcd0..0x04bcf0:
//   0x04bcd0: 1B082108 madd  w8, w8, w8, w8
//   0x04bcd4: 5290FCE9 mov   w9, #0x87e7
//   0x04bcd8: 72B948A9 movk  w9, #0xca45, lsl #16
//   0x04bcdc: 11001D08 add   w8, w8, #7
//   0x04bce0: 9BA97D09 umull x9, w8, w9
//   0x04bce4: D366FD29 lsr   x9, x9, #0x26
//   0x04bce8: 52800A2A mov   w10, #0x51
//   0x04bcec: 1B0AA128 msub  w8, w9, w10, w8
uint32_t OllvmPredicateVerifier::RemainderPolyMod81(uint32_t x) noexcept {
    uint32_t w8 = (x * x + x) + 7U;
    uint64_t prod = static_cast<uint64_t>(w8) * static_cast<uint64_t>(kOllvmMagicRecipMod81);
    uint32_t w9 = static_cast<uint32_t>(prod >> 38);
    return w8 - (w9 * 81U);
}

} // namespace ov
} // namespace metasec

extern "C" {

// Reconstructed from 0x04aae0..0x04bd88 (JNI_OnLoad, 4,776 bytes)
// Tái dựng từ 0x04aae0..0x04bd88 (JNI_OnLoad kiểm chứng các vị từ OLLVM và khởi tạo MetaSecOvEngine)
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    (void)reserved;
    using metasec::ov::OllvmPredicateVerifier;
    // Verify the 4 terminal OLLVM opaque predicates at 0x04bc20..0x04bd48:
    if (OllvmPredicateVerifier::RemainderQuad4Mod19(0x19bU) == 0U ||
        !OllvmPredicateVerifier::IsPellMod7Impossible(0xc8U, 0x13aU) ||
        OllvmPredicateVerifier::RemainderPolyMod81(0x36U) == 0U ||
        OllvmPredicateVerifier::RemainderQuad4Mod19(0xeaU) == 0U) {
        return -1;
    }
    (void)metasec::ov::MetaSecOvEngine::Instance().GetAllowedAppIds();
    if (!vm) return JNI_VERSION_1_6;
    JNIEnv* env = nullptr;
    if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK) {
        return -1;
    }
    return JNI_VERSION_1_6;
}

} // extern "C"
