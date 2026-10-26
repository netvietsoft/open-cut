/**
 * @file pns_ttmachine_adapter_pseudocode.cpp
 * @brief Opcode-Verified Export Symbol Dispatch Table & Binary Metadata for libpns_ttmachine_adapter.so
 *        Bảng điều phối ký hiệu xuất đã xác minh Opcode & Siêu dữ liệu nhị phân cho libpns_ttmachine_adapter.so
 *
 * Binary Ground Truth / Bằng chứng nhị phân thực tế:
 *   - Library: apktool-res/lib/arm64-v8a/libpns_ttmachine_adapter.so (330,032 bytes)
 *   - Dynamic Symbols: 165 total (27 exported + 138 imported)
 *   - Exported Functions (19 STT_FUNC):
 *       0x008868 ( 7012 B): Java_com_bytedance_pns_pns_1ttmachine_1adapter_TTMAdapter_init
 *       0x00c188 (  544 B): Java_com_bytedance_pns_pns_1ttmachine_1adapter_TTMAdapter_validate3
 *       0x00c3a8 (  844 B): Java_com_bytedance_pns_pns_1ttmachine_1adapter_TTMAdapter_attribution
 *       0x00d430 (  224 B): JNI_OnLoad
 *       0x00d510 ( 1644 B): active
 *       0x00e400 (  148 B): destroy
 *       0x00e494 ( 1332 B): validate
 *       0x00f8ec (  764 B): isInNameList
 *       0x00fc7c (    4 B): update
 *       0x00fc80 (   20 B): isActivated
 *       0x00fc94 (  192 B): getStrategyVersion
 *       0x00fd54 (    8 B): getGetConstPoolVersion
 *       0x00fd5c (  360 B): loadConstPoolExtra
 *       0x0360f0 (  332 B): _Z36calculate_network_sample_rate_resultPPvPdS1_S1_S1_S1_P22__TTMTransparentStruct
 *       0x03623c (  388 B): _Z5isHitPd
 *       0x0363c0 (  548 B): _Z12isInNameListPlPPvS1_S_P22__TTMTransparentStruct
 *       0x0365e4 (  768 B): _Z21isDomainPathMatchListPlPPvS1_S1_S_P22__TTMTransparentStruct
 *       0x0368e4 ( 1480 B): _Z26isDomainPathMatchConditionPlPPvS1_S1_S_P22__TTMTransparentStruct
 *       0x036eac (  484 B): _Z10randomSeedPlPPvPdP22__TTMTransparentStruct
 */

#include "pns_ttmachine_adapter_interface.h"

namespace pns {
namespace ttmachine {

struct ExportedSymbolDescriptor {
    uint64_t vaddr;
    uint32_t size_bytes;
    const char* mangled_name;
    const char* demangled_signature;
    void* implementation_ptr;
};

static const ExportedSymbolDescriptor kExportedSymbolTable[19] = {
    {0x008868ULL, 7012U,
     "Java_com_bytedance_pns_pns_1ttmachine_1adapter_TTMAdapter_init",
     "Java_com_bytedance_pns_pns_1ttmachine_1adapter_TTMAdapter_init(JNIEnv*, jclass, jstring)",
     reinterpret_cast<void*>(&Java_com_bytedance_pns_pns_1ttmachine_1adapter_TTMAdapter_init)},
    {0x00c188ULL, 544U,
     "Java_com_bytedance_pns_pns_1ttmachine_1adapter_TTMAdapter_validate3",
     "Java_com_bytedance_pns_pns_1ttmachine_1adapter_TTMAdapter_validate3(JNIEnv*, jclass, jstring, jobject)",
     reinterpret_cast<void*>(&Java_com_bytedance_pns_pns_1ttmachine_1adapter_TTMAdapter_validate3)},
    {0x00c3a8ULL, 844U,
     "Java_com_bytedance_pns_pns_1ttmachine_1adapter_TTMAdapter_attribution",
     "Java_com_bytedance_pns_pns_1ttmachine_1adapter_TTMAdapter_attribution(JNIEnv*, jclass, jstring, jobjectArray)",
     reinterpret_cast<void*>(&Java_com_bytedance_pns_pns_1ttmachine_1adapter_TTMAdapter_attribution)},
    {0x00d430ULL, 224U,
     "JNI_OnLoad",
     "JNI_OnLoad(JavaVM*, void*)",
     reinterpret_cast<void*>(&JNI_OnLoad)},
    {0x00d510ULL, 1644U,
     "active",
     "active(JNIEnv*, jclass, jobject, jstring, jobject, jobject, jobject, jboolean, jlong, jint)",
     reinterpret_cast<void*>(&active)},
    {0x00e400ULL, 148U,
     "destroy",
     "destroy(JNIEnv*, jclass)",
     reinterpret_cast<void*>(&destroy)},
    {0x00e494ULL, 1332U,
     "validate",
     "validate(JNIEnv*, jclass, jstring, jstring, jobject, jobject)",
     reinterpret_cast<void*>(&validate)},
    {0x00f8ecULL, 764U,
     "isInNameList",
     "isInNameList(JNIEnv*, jclass, jstring, jstring, jboolean)",
     reinterpret_cast<void*>(&isInNameList)},
    {0x00fc7cULL, 4U,
     "update",
     "update(JNIEnv*, jclass, jstring)",
     reinterpret_cast<void*>(&update)},
    {0x00fc80ULL, 20U,
     "isActivated",
     "isActivated(JNIEnv*, jclass)",
     reinterpret_cast<void*>(&isActivated)},
    {0x00fc94ULL, 192U,
     "getStrategyVersion",
     "getStrategyVersion(JNIEnv*, jclass)",
     reinterpret_cast<void*>(&getStrategyVersion)},
    {0x00fd54ULL, 8U,
     "getGetConstPoolVersion",
     "getGetConstPoolVersion(JNIEnv*, jclass)",
     reinterpret_cast<void*>(&getGetConstPoolVersion)},
    {0x00fd5cULL, 360U,
     "loadConstPoolExtra",
     "loadConstPoolExtra(JNIEnv*, jclass, jobject)",
     reinterpret_cast<void*>(&loadConstPoolExtra)},
    {0x0360f0ULL, 332U,
     "_Z36calculate_network_sample_rate_resultPPvPdS1_S1_S1_S1_P22__TTMTransparentStruct",
     "calculate_network_sample_rate_result(void**, double*, double*, double*, double*, double*, __TTMTransparentStruct*)",
     reinterpret_cast<void*>(&_Z36calculate_network_sample_rate_resultPPvPdS1_S1_S1_S1_P22__TTMTransparentStruct)},
    {0x03623cULL, 388U,
     "_Z5isHitPd",
     "isHit(double*)",
     reinterpret_cast<void*>(&_Z5isHitPd)},
    {0x0363c0ULL, 548U,
     "_Z12isInNameListPlPPvS1_S_P22__TTMTransparentStruct",
     "isInNameList(long*, void**, void**, long*, __TTMTransparentStruct*)",
     reinterpret_cast<void*>(&_Z12isInNameListPlPPvS1_S_P22__TTMTransparentStruct)},
    {0x0365e4ULL, 768U,
     "_Z21isDomainPathMatchListPlPPvS1_S1_S_P22__TTMTransparentStruct",
     "isDomainPathMatchList(long*, void**, void**, void**, long*, __TTMTransparentStruct*)",
     reinterpret_cast<void*>(&_Z21isDomainPathMatchListPlPPvS1_S1_S_P22__TTMTransparentStruct)},
    {0x0368e4ULL, 1480U,
     "_Z26isDomainPathMatchConditionPlPPvS1_S1_S_P22__TTMTransparentStruct",
     "isDomainPathMatchCondition(long*, void**, void**, void**, long*, __TTMTransparentStruct*)",
     reinterpret_cast<void*>(&_Z26isDomainPathMatchConditionPlPPvS1_S1_S_P22__TTMTransparentStruct)},
    {0x036eacULL, 484U,
     "_Z10randomSeedPlPPvPdP22__TTMTransparentStruct",
     "randomSeed(long*, void**, double*, __TTMTransparentStruct*)",
     reinterpret_cast<void*>(&_Z10randomSeedPlPPvPdP22__TTMTransparentStruct)}
};

const ExportedSymbolDescriptor* GetPnsTtmachineExportTable(size_t* out_count) noexcept {
    if (out_count) {
        *out_count = 19;
    }
    return kExportedSymbolTable;
}

} // namespace ttmachine
} // namespace pns
