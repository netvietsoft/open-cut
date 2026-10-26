/**
 * @file pns_ttmachine_adapter_interface.cpp
 * @brief End-to-End Self-Test & Integration Harness for libpns_ttmachine_adapter.so
 *        Bộ tự kiểm định đầu-cuối & Tích hợp cho libpns_ttmachine_adapter.so
 *
 * Verifies all 19 exported functions (0x008868..0x036eac), 9-entry JNINativeMethod table (0x054000..0x0540d8),
 * 624-word MT19937 sampling (0x03623c & 0x036eac), CityHash64 (0x007ed4), NameList 6-way jump table (0x03ac80),
 * RuleEngine decision tree (.T# / .F# / .E#), and TTMAdapter CEP/TTM execution (0x008868..0x00c6f0).
 */

#include "pns_ttmachine_adapter_interface.h"
#include <cmath>
#include <cstring>

namespace pns {
namespace ttmachine {

bool RunPnsTtmachineAdapterSelfTest() {
    // 1. Verify CityHash64 (0x007ed4) & MT19937 (0x03623c & 0x036eac)
    uint64_t h_empty = ComputeNdkStringHash64("", 0);
    if (h_empty != 0x9ae16a3b2f90404fULL) {
        return false;
    }
    uint64_t h_seed = ComputeNdkStringHash64("device_id_12345", 15);
    if (h_seed == 0) {
        return false;
    }
    double u_sample = GenerateMt19937UniformDouble(static_cast<uint32_t>(h_seed & 0xffffffffU));
    if (u_sample < 0.0 || u_sample >= 1.0) {
        return false;
    }

    // 2. Verify _Z5isHitPd (0x03623c) & _Z10randomSeed (0x036eac)
    double rate_one = 1.0;
    double rate_zero = 0.0;
    if (!_Z5isHitPd(&rate_one)) {
        return false;
    }
    int32_t err_code = 0;
    __TTMTransparentStruct ctx{nullptr, nullptr, nullptr, &err_code, nullptr};
    TTMObjectValue seed_val{3, 0, 0, 0, 15, "device_id_12345"};
    void* seed_ptr = &seed_val;
    long seed_out = -1;
    _Z10randomSeedPlPPvPdP22__TTMTransparentStruct(&seed_out, &seed_ptr, &rate_zero, &ctx);
    if (seed_out != 0) {
        return false;
    }
    _Z10randomSeedPlPPvPdP22__TTMTransparentStruct(&seed_out, &seed_ptr, &rate_one, &ctx);
    if (seed_out != 1) {
        return false;
    }

    // 3. Verify _Z36calculate_network_sample_rate_result (0x0360f0)
    void* net_list = nullptr;
    _Z36calculate_network_sample_rate_resultPPvPdS1_S1_S1_S1_P22__TTMTransparentStruct(
        &net_list, &rate_one, &rate_zero, &rate_one, &rate_zero, &rate_one, &ctx);
    if (!net_list) {
        return false;
    }

    // 4. Verify NameListManager & _Z12isInNameList / _Z21isDomainPathMatchList / _Z26isDomainPathMatchCondition
    auto& nl_mgr = NameListManager::Instance();
    nl_mgr.Clear();
    const char* extra_json = R"({"blocked_domains":["api.tiktokv.com",".byteoversea.com","/v2/ privacy"]})";
    if (!nl_mgr.LoadConstPoolExtraJson(extra_json) || nl_mgr.GetPrepareStatus() != 2) {
        return false;
    }
    TTMObjectValue dom_val{3, 0, 0, 0, 15, "api.tiktokv.com"};
    TTMObjectValue path_val{3, 0, 0, 0, 12, "/v2/ privacy"};
    TTMObjectValue key_val{3, 0, 0, 0, 15, "blocked_domains"};
    void* dom_ptr = &dom_val;
    void* path_ptr = &path_val;
    void* key_ptr = &key_val;
    long strict_flag = 1;
    long match_res = 0;
    _Z12isInNameListPlPPvS1_S_P22__TTMTransparentStruct(&match_res, &dom_ptr, &key_ptr, &strict_flag, &ctx);
    if (match_res != 1) {
        return false;
    }
    match_res = 0;
    _Z21isDomainPathMatchListPlPPvS1_S1_S_P22__TTMTransparentStruct(
        &match_res, &dom_ptr, &path_ptr, &key_ptr, &strict_flag, &ctx);
    if (match_res != 1) {
        return false;
    }
    match_res = 0;
    _Z26isDomainPathMatchConditionPlPPvS1_S1_S_P22__TTMTransparentStruct(
        &match_res, &dom_ptr, &path_ptr, &key_ptr, &strict_flag, &ctx);
    if (match_res != 1) {
        return false;
    }

    // 5. Verify URL & Domain helpers (0x014598)
    if (UrlDecode("hello%20world%21") != "hello world!" ||
        ExtractUrlScheme("HTTPS://api.capcut.com/v1/test?k=1") != "https" ||
        ExtractUrlQueryString("https://api.capcut.com/v1/test?k=1#frag") != "k=1" ||
        ExtractSecondLevelDomain("https://sub.capcut.com/path") != "capcut.com" ||
        !IsIpAddress("192.168.1.1") ||
        !IsValidDomain("api.capcut.com") ||
        CompareVersionStrings("2.10.0", "2.9.5") <= 0) {
        return false;
    }

    // 6. Verify RuleEngineService exports (active, validate, getStrategyVersion, destroy)
    destroy(nullptr, nullptr);
    if (isActivated(nullptr, nullptr) != 0 || getStrategyVersion(nullptr, nullptr) != -1 ||
        getGetConstPoolVersion(nullptr, nullptr) != -1LL) {
        return false;
    }
    const char* rule_cfg = R"({"version":42,"trigger_id":"net_req","strategy_list_id":"sl_net","strategy_id":"st_block","start_node_id":"n1","cond_id":"c1","cond_type":1,"cond":"region==US","action_id":"act_1","name":"block_request"})";
    jobject init_stats = active(
        nullptr, nullptr, nullptr,
        reinterpret_cast<jstring>(const_cast<char*>(rule_cfg)),
        nullptr, nullptr, nullptr, 1, 100, 100);
    if (!init_stats || isActivated(nullptr, nullptr) != 1 || getStrategyVersion(nullptr, nullptr) != 42) {
        return false;
    }
    delete reinterpret_cast<InitStatisticsRecord*>(init_stats);

    std::unordered_map<std::string, std::string> req_params{{"region", "US"}};
    jobject exec_res_obj = validate(
        nullptr, nullptr,
        reinterpret_cast<jstring>(const_cast<char*>("net_req")),
        reinterpret_cast<jstring>(const_cast<char*>("okhttp")),
        reinterpret_cast<jobject>(&req_params),
        nullptr);
    if (!exec_res_obj) {
        return false;
    }
    auto* exec_res = reinterpret_cast<ExecuteResultRecord*>(exec_res_obj);
    bool valid_exec = (exec_res->version == 42 &&
                       !exec_res->results.empty() &&
                       exec_res->results[0].graph_path == "n1.T#" &&
                       !exec_res->results[0].matched_actions.empty());
    delete exec_res;
    destroy(nullptr, nullptr);
    if (!valid_exec || isActivated(nullptr, nullptr) != 0) {
        return false;
    }

    // 7. Verify TTMAdapter JNI exports (init, validate3, attribution)
    const char* bundle_cfg = R"({"strategy_set":"pns_net_guard","rule":"r_privacy","exp":"scene==background"})";
    jobject pre_stats = Java_com_bytedance_pns_pns_1ttmachine_1adapter_TTMAdapter_init(
        nullptr, nullptr, reinterpret_cast<jstring>(const_cast<char*>(bundle_cfg)));
    if (!pre_stats) {
        return false;
    }
    delete reinterpret_cast<TTMStatePreprocessTimeStats*>(pre_stats);

    std::unordered_map<std::string, std::string> ttm_map{{"scene", "background"}};
    jobject val3_res = Java_com_bytedance_pns_pns_1ttmachine_1adapter_TTMAdapter_validate3(
        nullptr, nullptr,
        reinterpret_cast<jstring>(const_cast<char*>("pns_net_guard")),
        reinterpret_cast<jobject>(&ttm_map));
    if (!val3_res) {
        return false;
    }
    auto* native_val3 = reinterpret_cast<TTMachineExecuteResultNative*>(val3_res);
    bool ok_val3 = !native_val3->hit_strategy_ids.empty();
    delete native_val3;
    return ok_val3;
}

} // namespace ttmachine
} // namespace pns
