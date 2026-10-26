/**
 * @file pumbaa_network_interface.h
 * @brief Public C/C++/JNI entry points and complete `.dynsym` export directory (`[031]..[067]`,
 *        37 exported symbols) for `libpumbaa-network.so` (`51,232 bytes`).
 *        Các điểm nhập C/C++/JNI công khai và danh mục xuất khẩu `.dynsym` hoàn chỉnh
 *        (`[031]..[067]`, 37 ký hiệu xuất) cho `libpumbaa-network.so` (`51,232 byte`).
 */

#ifndef NEXTAI_OPENCUT_PUMBAA_NETWORK_INTERFACE_H_
#define NEXTAI_OPENCUT_PUMBAA_NETWORK_INTERFACE_H_

#include "pumbaa_network_rbtree_dwarf.h"
#include "pumbaa_network_sandbox_jni.h"
#include "pumbaa_network_types.h"

#include <array>
#include <cstdint>

namespace nextai {
namespace opencut {
namespace pumbaa_network {

struct ExportedDynSymDescriptor {
    uint32_t    dynsym_index;
    uint32_t    vaddr;
    uint32_t    size_bytes;
    const char* symbol_name;
    const char* role_en_vn;
};

extern const std::array<ExportedDynSymDescriptor, 37> kExportedDynSymTable;

bool RunLibPumbaaNetworkSelfTest();

} // namespace pumbaa_network
} // namespace opencut
} // namespace nextai

extern "C" {

// [038] JNI_OnLoad @ 0x001e9c (516 bytes)
nextai::opencut::pumbaa_network::jint JNI_OnLoad(
    nextai::opencut::pumbaa_network::JavaVM* vm,
    void* reserved);

// [036] jni_convertMap @ 0x0020a0 (540 bytes)
nextai::opencut::pumbaa_network::jobject jni_convertMap(
    nextai::opencut::pumbaa_network::JNIEnv* env,
    const nextai::opencut::pumbaa_network::LibcxxMapStringAbi* cpp_map);

// [047] domainIdentityRecognize @ 0x0025c8 (344 bytes)
const char* domainIdentityRecognize(const char* host);

// [062] handleByPumbaaForSandbox @ 0x0027bc (1008 bytes)
int handleByPumbaaForSandbox(
    const char* url,
    const char* method,
    const nextai::opencut::pumbaa_network::LibcxxMapStringAbi* req_headers,
    void* body_buf,
    int body_len,
    void* reserved_x5,
    const nextai::opencut::pumbaa_network::LibcxxMapStringAbi* extra_info);

// [061] matchAgSchema @ 0x002c48 (280 bytes)
bool matchAgSchema(const char* url);

// [052] _Z11monitorCostPKcx @ 0x0023f4 (312 bytes)
void _Z11monitorCostPKcx(const char* method_name, long long cost_ms);

// [032] _ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz @ 0x00252c (156 bytes)
void _ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz(
    nextai::opencut::pumbaa_network::JNIEnv* env,
    nextai::opencut::pumbaa_network::jclass clazz,
    nextai::opencut::pumbaa_network::jmethodID methodID,
    ...);

// [035] _ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz @ 0x002720 (156 bytes)
nextai::opencut::pumbaa_network::jobject _ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz(
    nextai::opencut::pumbaa_network::JNIEnv* env,
    nextai::opencut::pumbaa_network::jclass clazz,
    nextai::opencut::pumbaa_network::jmethodID methodID,
    ...);

// [042] _ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz @ 0x002bac (156 bytes)
nextai::opencut::pumbaa_network::jint _ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz(
    nextai::opencut::pumbaa_network::JNIEnv* env,
    nextai::opencut::pumbaa_network::jclass clazz,
    nextai::opencut::pumbaa_network::jmethodID methodID,
    ...);

// [043] _ZN7_JNIEnv9NewObjectEP7_jclassP10_jmethodIDz @ 0x0022bc (156 bytes)
nextai::opencut::pumbaa_network::jobject _ZN7_JNIEnv9NewObjectEP7_jclassP10_jmethodIDz(
    nextai::opencut::pumbaa_network::JNIEnv* env,
    nextai::opencut::pumbaa_network::jclass clazz,
    nextai::opencut::pumbaa_network::jmethodID methodID,
    ...);

// [045] _ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz @ 0x002358 (156 bytes)
nextai::opencut::pumbaa_network::jobject _ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz(
    nextai::opencut::pumbaa_network::JNIEnv* env,
    nextai::opencut::pumbaa_network::jobject obj,
    nextai::opencut::pumbaa_network::jmethodID methodID,
    ...);

// [060] _ZN7_JNIEnv23CallStaticBooleanMethodEP7_jclassP10_jmethodIDz @ 0x002d60 (156 bytes)
nextai::opencut::pumbaa_network::jboolean _ZN7_JNIEnv23CallStaticBooleanMethodEP7_jclassP10_jmethodIDz(
    nextai::opencut::pumbaa_network::JNIEnv* env,
    nextai::opencut::pumbaa_network::jclass clazz,
    nextai::opencut::pumbaa_network::jmethodID methodID,
    ...);

} // extern "C"

#endif // NEXTAI_OPENCUT_PUMBAA_NETWORK_INTERFACE_H_
