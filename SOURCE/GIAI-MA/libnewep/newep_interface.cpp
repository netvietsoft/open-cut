/**
 * @file newep_interface.cpp
 * @brief Implementation of the public C/C++17 & JNI entry points (`.dynsym [046]..[074]`)
 *        and self-test suite for `libnewep.so` (`51,232 bytes`).
 *        Triển khai các điểm nhập C/C++17 & JNI công khai (`.dynsym [046]..[074]`)
 *        và bộ tự kiểm thử cho `libnewep.so` (`51,232 byte`).
 */

#include "newep_interface.h"

#include <cstdlib>
#include <cstring>

namespace nextai {
namespace opencut {
namespace newep {

NewepEngine& NewepEngine::Instance() noexcept {
    static NewepEngine s_instance;
    return s_instance;
}

bool NewepEngine::InitializeJni(JavaVM* vm) noexcept {
    return NewepJniOnLoad(vm, nullptr) == kJniVersion1_6;
}

jlong NewepEngine::GetNativeResourceFinderFunctionPtr() const noexcept {
    return NativeCreateResourceFinder(nullptr, nullptr, 0);
}

std::string NewepEngine::ResolveModelUri(const char* dir_path, const char* model_name) const {
    char* raw = FindResourceUriDownloadableModelSupport(nullptr, dir_path, model_name);
    if (raw == nullptr) {
        return RodataConstants::kUriAssetNotFound;
    }
    std::string out(raw);
    std::free(raw);
    return out;
}

bool NewepEngine::ValidateEffectChildrenDirectory(const char* dir_path,
                                                  std::vector<std::string>* out_children) const {
    return CheckEffectChildrenFileFromPath(dir_path, out_children);
}

bool NewepEngine::RunSelfTest() noexcept {
    // Stage 1: Verify ELF64 & ABI struct sizes
    if (sizeof(NewepBssSegment) != 624u ||
        sizeof(LibcxxString24Abi) != 24u ||
        sizeof(LibcxxVectorString24Abi) != 24u ||
        sizeof(AArch64VaListAbi) != 32u) {
        return false;
    }

    // Stage 2: Verify division-by-24 modular inverse math (`0xaaaaaaaaaaaaaaab` @ `0x00356c` & `0x00377c`)
    for (uint64_t count = 0u; count <= 32u; ++count) {
        const int64_t byte_diff = static_cast<int64_t>(count * 24u);
        if (VectorStringCapacityMath::ExactBytesDiv24(byte_diff) != count) {
            return false;
        }
        if (VectorStringCapacityMath::ElementsToBytes24(count) != count * 24u) {
            return false;
        }
    }

    // Stage 3: Verify `JNI_OnLoad` (`0x001ebc`) & `nativeCreateResourceFinder` (`0x00209c`)
    JavaVM* dummy_vm = reinterpret_cast<JavaVM*>(0x1000);
    if (!InitializeJni(dummy_vm)) {
        return false;
    }
    const jlong fn_ptr = GetNativeResourceFinderFunctionPtr();
    if (fn_ptr != static_cast<jlong>(reinterpret_cast<uintptr_t>(&FindResourceUriDownloadableModelSupport))) {
        return false;
    }

    // Stage 4: Verify `LibcxxString24Abi` SSO & `BasicStringOperatorPlus` (`0x0033b4`)
    LibcxxString24Abi lhs{};
    LibcxxString24Abi rhs{};
    LibcxxString24Abi sum{};
    BasicStringConstructFromCStr(&lhs, "/data/effect");
    BasicStringConstructFromCStr(&rhs, "/effect_platform_children.tag");
    BasicStringOperatorPlus(&sum, &lhs, &rhs);
    const bool concat_ok = ((sum.short_repr.tag & 1u) != 0u) &&
                           (sum.long_repr.size == 41u) &&
                           (std::strcmp(sum.long_repr.data, "/data/effect/effect_platform_children.tag") == 0);
    BasicStringDestroy(&lhs);
    BasicStringDestroy(&rhs);
    BasicStringDestroy(&sum);
    if (!concat_ok) {
        return false;
    }

    // Stage 5: Verify DWARF LEB128 decoders (`0x003ae0..0x003b44`)
    const uint8_t uleb_sample[] = {0xe5u, 0x8eu, 0x26u}; // 624485
    uint64_t uleb_val = 0u;
    ReadULEB128(uleb_sample, &uleb_val);
    if (uleb_val != 624485ULL) {
        return false;
    }

    return true;
}

} // namespace newep
} // namespace opencut
} // namespace nextai

// ============================================================================
// Exported C / JNI Entry Points Matching `.dynsym` ([047]..[074])
// Các Điểm nhập C / JNI Xuất khẩu Khớp `.dynsym` ([047]..[074])
// ============================================================================

extern "C" {

nextai::opencut::newep::jint JNI_OnLoad(nextai::opencut::newep::JavaVM* vm, void* reserved) {
    return nextai::opencut::newep::NewepJniOnLoad(vm, reserved);
}

nextai::opencut::newep::jlong
Java_com_ss_ugc_effectplatform_algorithm_AlgorithmModelResourceFinder_nativeCreateResourceFinder(
    nextai::opencut::newep::JNIEnv* env,
    nextai::opencut::newep::jobject thiz,
    nextai::opencut::newep::jlong param) {
    return nextai::opencut::newep::NativeCreateResourceFinder(env, thiz, param);
}

char* _Z40findResourceUri_DownloadableModelSupportPvPKcS1_(void* user_data,
                                                           const char* dir_path,
                                                           const char* model_name) {
    return nextai::opencut::newep::FindResourceUriDownloadableModelSupport(
        user_data, dir_path, model_name);
}

nextai::opencut::newep::jobject
_ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz(
    nextai::opencut::newep::JNIEnv* env,
    nextai::opencut::newep::jclass clazz,
    nextai::opencut::newep::jmethodID method_id,
    ...) {
    return nextai::opencut::newep::JniEnvCallStaticObjectMethodVariadic(env, clazz, method_id);
}

void _ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz(
    nextai::opencut::newep::JNIEnv* env,
    nextai::opencut::newep::jclass clazz,
    nextai::opencut::newep::jmethodID method_id,
    ...) {
    nextai::opencut::newep::JniEnvCallStaticVoidMethodVariadic(env, clazz, method_id);
}

nextai::opencut::newep::jboolean
Java_com_ss_ugc_effectplatform_util_EffectUtilKt_nativeCheckEffectChildrenFile(
    nextai::opencut::newep::JNIEnv* env,
    nextai::opencut::newep::jclass clazz,
    nextai::opencut::newep::jstring dir_path_jstr) {
    return nextai::opencut::newep::NativeCheckEffectChildrenFile(env, clazz, dir_path_jstr);
}

} // extern "C"
