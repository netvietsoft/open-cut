/**
 * @file pumbaa_network_interface.cpp
 * @brief Implementation of all exported `.dynsym` functions (`[031]..[067]`) and the
 *        37-entry `kExportedDynSymTable` directory for `libpumbaa-network.so`.
 *        Hiện thực hóa toàn bộ các hàm xuất `.dynsym` (`[031]..[067]`) và bảng
 *        danh mục 37 ký hiệu `kExportedDynSymTable` cho `libpumbaa-network.so`.
 */

#include "pumbaa_network_interface.h"

namespace nextai {
namespace opencut {
namespace pumbaa_network {

const std::array<ExportedDynSymDescriptor, 37> kExportedDynSymTable = {{
    {31u, 0x010010u, 8u,    "gClassNativeBridge", "Global jclass for com/bytedance/helios/network/SandboxBridge (.bss 0x010010)"},
    {32u, 0x00252cu, 156u,  "_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz", "JNIEnv::CallStaticVoidMethod variadic wrapper (vtable + 0x470)"},
    {33u, 0x010050u, 8u,    "gMethodHashMapConstructor", "Global jmethodID for java/util/HashMap.<init>(I)V (.bss 0x010050)"},
    {34u, 0x0102b0u, 0u,    "_bss_end__", "Linker symbol marking end of .bss (0x0102b0)"},
    {35u, 0x002720u, 156u,  "_ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz", "JNIEnv::CallStaticObjectMethod variadic wrapper (vtable + 0x398)"},
    {36u, 0x0020a0u, 540u,  "jni_convertMap", "Converts C++ std::map<string, string> to java.util.HashMap"},
    {37u, 0x010018u, 8u,    "gNetworkDomainRecognize", "Global jclass for NetworkDomainRecognize (.bss 0x010018)"},
    {38u, 0x001e9cu, 516u,  "JNI_OnLoad", "Caches JavaVM, 2 classes, and 4 static methods; returns 0x00010002"},
    {39u, 0x003430u, 20u,   "_ZNKSt6__ndk121__basic_string_commonILb1EE20__throw_length_errorEv", "Throws std::length_error(\"basic_string\")"},
    {40u, 0x002f08u, 732u,  "_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES7_EENS_19__map_value_compareIS7_S8_NS_4lessIS7_EELb1EEENS5_IS8_EEE12__find_equalIS7_EERPNS_16__tree_node_baseIPvEENS_21__tree_const_iteratorIS8_PNS_11__tree_nodeIS8_SH_EElEERPNS_15__tree_end_nodeISJ_EESK_RKT_", "RB-tree __find_equal with hint iterator"},
    {41u, 0x003444u, 416u,  "_ZNSt6__ndk127__tree_balance_after_insertIPNS_16__tree_node_baseIPvEEEEvT_S5_", "RB-tree rebalancing after node insertion"},
    {42u, 0x002bacu, 156u,  "_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz", "JNIEnv::CallStaticIntMethod variadic wrapper (vtable + 0x410)"},
    {43u, 0x0022bcu, 156u,  "_ZN7_JNIEnv9NewObjectEP7_jclassP10_jmethodIDz", "JNIEnv::NewObject variadic wrapper (vtable + 0xe8)"},
    {44u, 0x010058u, 8u,    "gMethodPut", "Global jmethodID for java/util/HashMap.put (.bss 0x010058)"},
    {45u, 0x002358u, 156u,  "_ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz", "JNIEnv::CallObjectMethod variadic wrapper (vtable + 0x118)"},
    {46u, 0x0102b0u, 0u,    "__end__", "Linker symbol marking end of image (0x0102b0)"},
    {47u, 0x0025c8u, 344u,  "domainIdentityRecognize", "Recognizes domain identity via NetworkDomainRecognize.domainIdentityRecognize"},
    {48u, 0x010060u, 8u,    "gJvm", "Global JavaVM* pointer (.bss 0x010060)"},
    {49u, 0x010038u, 8u,    "gMethodMatchAgSchema", "Global jmethodID for SandboxBridge.matchAgSchema (.bss 0x010038)"},
    {50u, 0x010010u, 0u,    "__bss_start", "Linker symbol marking start of .bss (0x010010)"},
    {51u, 0x0102b0u, 0u,    "_end", "Linker symbol marking end of .bss (0x0102b0)"},
    {52u, 0x0023f4u, 312u,  "_Z11monitorCostPKcx", "monitorCost(const char*, long long) reporting latency to SandboxBridge.monitorCost"},
    {53u, 0x010040u, 8u,    "gMethodMonitorCost", "Global jmethodID for SandboxBridge.monitorCost (.bss 0x010040)"},
    {54u, 0x010028u, 8u,    "gMethodHandleFromNativeSandboxJson", "Global jmethodID for SandboxBridge.handleByPumbaa2 (.bss 0x010028)"},
    {55u, 0x0035e4u, 96u,   "_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES7_EENS_19__map_value_compareIS7_S8_NS_4lessIS7_EELb1EEENS5_IS8_EEE7destroyEPNS_11__tree_nodeIS8_PvEE", "RB-tree recursive destroy"},
    {56u, 0x010048u, 8u,    "gClassHashMap", "Global jclass for java/util/HashMap (.bss 0x010048)"},
    {57u, 0x010010u, 0u,    "_edata", "Linker symbol marking end of .data (0x010010)"},
    {58u, 0x003384u, 172u,  "_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2ERKS5_", "std::string copy constructor (SSO & 16B aligned heap)"},
    {59u, 0x0031e4u, 288u,  "_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES7_EENS_19__map_value_compareIS7_S8_NS_4lessIS7_EELb1EEENS5_IS8_EEE12__find_equalIS7_EERPNS_16__tree_node_baseIPvEERPNS_15__tree_end_nodeISJ_EERKT_", "RB-tree __find_equal from root"},
    {60u, 0x002d60u, 156u,  "_ZN7_JNIEnv23CallStaticBooleanMethodEP7_jclassP10_jmethodIDz", "JNIEnv::CallStaticBooleanMethod variadic wrapper (vtable + 0x3b0)"},
    {61u, 0x002c48u, 280u,  "matchAgSchema", "Checks URL against SandboxBridge.matchAgSchema(String)Z"},
    {62u, 0x0027bcu, 1008u, "handleByPumbaaForSandbox", "Main Pumbaa network sandbox interceptor & latency monitor"},
    {63u, 0x002dfcu, 268u,  "_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES7_EENS_19__map_value_compareIS7_S8_NS_4lessIS7_EELb1EEENS5_IS8_EEE30__emplace_hint_unique_key_argsIS7_JRKNS_4pairIKS7_S7_EEEEENS_15__tree_iteratorIS8_PNS_11__tree_nodeIS8_PvEElEENS_21__tree_const_iteratorIS8_SP_lEERKT_DpOT0_", "RB-tree __emplace_hint_unique_key_args (allocates 80B = 0x50 node)"},
    {64u, 0x0102b0u, 0u,    "__bss_end__", "Linker symbol marking end of .bss (0x0102b0)"},
    {65u, 0x010020u, 8u,    "gMethodHandleFromNativeSandbox", "Global jmethodID for SandboxBridge.handleByPumbaa (.bss 0x010020)"},
    {66u, 0x010030u, 8u,    "gMethodDomainIdentityRecognize", "Global jmethodID for NetworkDomainRecognize.domainIdentityRecognize (.bss 0x010030)"},
    {67u, 0x010010u, 0u,    "__bss_start__", "Linker symbol marking start of .bss (0x010010)"},
}};

} // namespace pumbaa_network
} // namespace opencut
} // namespace nextai

extern "C" {

using namespace nextai::opencut::pumbaa_network;

jint JNI_OnLoad(JavaVM* vm, void* reserved) {
    return ExecutePumbaaJniOnLoad(vm, reserved);
}

jobject jni_convertMap(JNIEnv* env, const LibcxxMapStringAbi* cpp_map) {
    return ExecuteJniConvertMap(env, cpp_map);
}

const char* domainIdentityRecognize(const char* host) {
    return ExecuteDomainIdentityRecognize(host);
}

int handleByPumbaaForSandbox(
    const char* url,
    const char* method,
    const LibcxxMapStringAbi* req_headers,
    void* body_buf,
    int body_len,
    void* reserved_x5,
    const LibcxxMapStringAbi* extra_info) {
    return ExecuteHandleByPumbaaForSandbox(
        url, method, req_headers, body_buf, body_len, reserved_x5, extra_info);
}

bool matchAgSchema(const char* url) {
    return ExecuteMatchAgSchema(url);
}

void _Z11monitorCostPKcx(const char* method_name, long long cost_ms) {
    ExecuteMonitorCost(method_name, static_cast<int64_t>(cost_ms));
}

void _ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz(
    JNIEnv* env, jclass clazz, jmethodID methodID, ...) {
    JniEnv_CallStaticVoidMethod(env, clazz, methodID);
}

jobject _ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz(
    JNIEnv* env, jclass clazz, jmethodID methodID, ...) {
    return JniEnv_CallStaticObjectMethod(env, clazz, methodID);
}

jint _ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz(
    JNIEnv* env, jclass clazz, jmethodID methodID, ...) {
    return JniEnv_CallStaticIntMethod(env, clazz, methodID);
}

jobject _ZN7_JNIEnv9NewObjectEP7_jclassP10_jmethodIDz(
    JNIEnv* env, jclass clazz, jmethodID methodID, ...) {
    return JniEnv_NewObject(env, clazz, methodID);
}

jobject _ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz(
    JNIEnv* env, jobject obj, jmethodID methodID, ...) {
    return JniEnv_CallObjectMethod(env, obj, methodID);
}

jboolean _ZN7_JNIEnv23CallStaticBooleanMethodEP7_jclassP10_jmethodIDz(
    JNIEnv* env, jclass clazz, jmethodID methodID, ...) {
    return JniEnv_CallStaticBooleanMethod(env, clazz, methodID);
}

} // extern "C"
