/**
 * @file newep_interface.h
 * @brief Public C/C++17 & JNI interface for `libnewep.so` (`51,232 bytes`, 75 `.dynsym` entries:
 *        43 imported `[003]..[045]` + 29 exported `[046]..[074]`).
 *        Giao diện C/C++17 & JNI công khai cho `libnewep.so` (`51,232 byte`, 75 biểu tượng `.dynsym`:
 *        43 nhập khẩu `[003]..[045]` + 29 xuất khẩu `[046]..[074]`).
 */

#ifndef NEXTAI_OPENCUT_NEWEP_INTERFACE_H_
#define NEXTAI_OPENCUT_NEWEP_INTERFACE_H_

#include "newep_resource_finder_jni.h"
#include "newep_stl_unwind.h"
#include "newep_types.h"

namespace nextai {
namespace opencut {
namespace newep {

/**
 * @brief High-level verification & diagnostic facade for `libnewep.so`.
 *        Lớp mặt tiền xác minh & chẩn đoán cấp cao cho `libnewep.so`.
 */
class NewepEngine {
public:
    static NewepEngine& Instance() noexcept;

    bool InitializeJni(JavaVM* vm) noexcept;
    jlong GetNativeResourceFinderFunctionPtr() const noexcept;
    std::string ResolveModelUri(const char* dir_path, const char* model_name) const;
    bool ValidateEffectChildrenDirectory(const char* dir_path,
                                         std::vector<std::string>* out_children = nullptr) const;
    bool RunSelfTest() noexcept;
};

} // namespace newep
} // namespace opencut
} // namespace nextai

// ============================================================================
// Exported C / JNI Entry Points Matching `.dynsym` ([047]..[074])
// Các Điểm nhập C / JNI Xuất khẩu Khớp `.dynsym` ([047]..[074])
// ============================================================================

extern "C" {

// [058] val=0x001ebc size=480
nextai::opencut::newep::jint JNI_OnLoad(nextai::opencut::newep::JavaVM* vm, void* reserved);

// [072] val=0x00209c size=12
nextai::opencut::newep::jlong
Java_com_ss_ugc_effectplatform_algorithm_AlgorithmModelResourceFinder_nativeCreateResourceFinder(
    nextai::opencut::newep::JNIEnv* env,
    nextai::opencut::newep::jobject thiz,
    nextai::opencut::newep::jlong param);

// [070] val=0x0020a8 size=912
char* _Z40findResourceUri_DownloadableModelSupportPvPKcS1_(void* user_data,
                                                           const char* dir_path,
                                                           const char* model_name);

// [057] val=0x002438 size=156
nextai::opencut::newep::jobject
_ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz(
    nextai::opencut::newep::JNIEnv* env,
    nextai::opencut::newep::jclass clazz,
    nextai::opencut::newep::jmethodID method_id,
    ...);

// [049] val=0x0024d4 size=156
void _ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz(
    nextai::opencut::newep::JNIEnv* env,
    nextai::opencut::newep::jclass clazz,
    nextai::opencut::newep::jmethodID method_id,
    ...);

// [048] val=0x002570 size=3328
nextai::opencut::newep::jboolean
Java_com_ss_ugc_effectplatform_util_EffectUtilKt_nativeCheckEffectChildrenFile(
    nextai::opencut::newep::JNIEnv* env,
    nextai::opencut::newep::jclass clazz,
    nextai::opencut::newep::jstring dir_path_jstr);

} // extern "C"

#endif // NEXTAI_OPENCUT_NEWEP_INTERFACE_H_
