/**
 * @file pns_ttmachine_adapter_interface.h
 * @brief Master Public Interface Header for libpns_ttmachine_adapter.so (330,032 B, 165 Symbols)
 *        Header giao diện công khai tổng thể cho libpns_ttmachine_adapter.so (330.032 B, 165 ký hiệu)
 *
 * Subsystems unified / Các phân hệ hợp nhất:
 *   1. pns_ttmachine_types.h             : ELF64 Memory Map, JniCacheTable (0x248 B), ABI Structs
 *   2. pns_ttmachine_sampling_namelist.h : MT19937 Uniform Sampling, CityHash64, NameList & URL Engine
 *   3. pns_ttmachine_rule_engine.h       : RuleEngine Singleton (0xd0 B) & 9 RuleEngineService JNI Exports
 *   4. pns_ttmachine_cep_jni.h           : TTMAdapter JNI Bridge, CEP ExprEvaluator & TTM Bytecode Runner
 */

#ifndef NEXTAI_OPENCUT_PNS_TTMACHINE_ADAPTER_INTERFACE_H_
#define NEXTAI_OPENCUT_PNS_TTMACHINE_ADAPTER_INTERFACE_H_

#include "pns_ttmachine_types.h"
#include "pns_ttmachine_sampling_namelist.h"
#include "pns_ttmachine_rule_engine.h"
#include "pns_ttmachine_cep_jni.h"

namespace pns {
namespace ttmachine {

/**
 * Runs an end-to-end self-verification suite across all 5 subsystems of libpns_ttmachine_adapter.so:
 *   1. CityHash64 (0x007ed4) & MT19937 624-word uniform sampling (_Z5isHitPd 0x03623c & _Z10randomSeed 0x036eac)
 *   2. Network 5-field sample rate list builder (_Z36calculate_network_sample_rate_result 0x0360f0)
 *   3. NameListManager & 6-mode domain/path matching (_Z12isInNameList 0x0363c0, 0x0365e4, 0x0368e4)
 *   4. RuleEngine lifecycle (JNI_OnLoad 0x00d430, active 0x00d510, validate 0x00e494, destroy 0x00e400)
 *   5. TTMAdapter JNI bundle init, validate3 & attribution (0x008868, 0x00c188, 0x00c3a8)
 * Chạy bộ tự kiểm định đầu-cuối trên cả 5 phân hệ của libpns_ttmachine_adapter.so.
 */
bool RunPnsTtmachineAdapterSelfTest();

} // namespace ttmachine
} // namespace pns

#endif // NEXTAI_OPENCUT_PNS_TTMACHINE_ADAPTER_INTERFACE_H_
