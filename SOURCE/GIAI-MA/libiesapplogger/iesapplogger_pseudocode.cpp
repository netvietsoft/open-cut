/**
 * @file iesapplogger_pseudocode.cpp
 * @brief Complete AArch64 Disassembly & Symbol Verification Trace for libiesapplogger.so
 *        Bản vết Giải mã AArch64 & Xác minh Biểu tượng Toàn diện cho libiesapplogger.so
 *
 * Binary: libiesapplogger.so (67,616 bytes, 25 ELF64 sections, 123 .dynsym entries)
 * Nhị phân: libiesapplogger.so (67.616 byte, 25 section ELF64, 123 mục .dynsym)
 */

#include "iesapplogger_interface.h"
#include "iesapplogger_reporter_jni.h"
#include "iesapplogger_rbtree_stl.h"
#include "iesapplogger_types.h"
#include <array>
#include <cstdint>
#include <cstring>

namespace iesapplogger {

// ============================================================================
// 1. Exported .dynsym Symbol Table Descriptor ([048..122], 75 Exports)
//    Bảng Mô tả 75 Biểu tượng Xuất trong .dynsym ([048..122])
// ============================================================================
struct ExportedSymbolEntry {
    uint32_t    dynsym_index;
    uint64_t    virtual_address;
    uint32_t    size_bytes;
    const char* mangled_name;
    const char* role_summary;
};

static constexpr std::array<ExportedSymbolEntry, 75> kExportedSymbols = {{
    {48,  0x0080c4ULL, 708U, "_ZN12IESAppLogger13AppLogTracker4Impl7putValsERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEERKNS2_6vectorIS8_NS6_IS8_EEEE", "Impl::putVals(key, const vector<string>&)"},
    {49,  0x00537cULL, 176U, "_ZNSt6__ndk16__treeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_4lessIS6_EENS4_IS6_EEE16__construct_nodeIJRKS6_EEEPNS_11__tree_nodeIS6_PvEEDpOT_", "__tree::__construct_node(const string&)"},
    {50,  0x004a70ULL, 100U, "_ZNSt6__ndk16__treeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_4lessIS6_EENS4_IS6_EEE19__copy_assign_allocERKSB_", "__tree::__copy_assign_alloc"},
    {51,  0x004c18ULL,  84U, "_ZNSt6__ndk16__treeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_4lessIS6_EENS4_IS6_EEE4findIS6_EENS_15__tree_iteratorIS6_PNS_11__tree_nodeIS6_PvEElEERKT_", "__tree::find(const string&)"},
    {52,  0x0055a4ULL,  92U, "_ZNSt6__ndk16__treeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_4lessIS6_EENS4_IS6_EEE16__insert_node_atEPNS_15__tree_end_nodeIPNS_16__tree_node_baseIPvEEEERSF_SF_", "__tree::__insert_node_at"},
    {53,  0x014010ULL,   8U, "gJvm", "Global JavaVM* pointer in .bss"},
    {54,  0x0083f4ULL, 364U, "_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7reserveEm", "basic_string::reserve(size_t)"},
    {55,  0x004ad4ULL, 192U, "_ZNSt6__ndk16__treeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_4lessIS6_EENS4_IS6_EEE14__assign_multiINS_21__tree_const_iteratorIS6_PNS_11__tree_nodeIS6_PvEElEEEEvT_SH_", "__tree::__assign_multi"},
    {56,  0x005804ULL, 116U, "_ZNSt6__ndk1ltIcNS_11char_traitsIcEENS_9allocatorIcEEEEbRKNS_12basic_stringIT_T0_T1_EESB_", "operator<(const string&, const string&)"},
    {57,  0x0054dcULL, 200U, "_ZNSt6__ndk16__treeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_4lessIS6_EENS4_IS6_EEE12__find_equalIS6_EERPNS_16__tree_node_baseIPvEERPNS_15__tree_end_nodeISE_EERKT_", "__tree::__find_equal"},
    {58,  0x004b94ULL,  68U, "_ZNSt6__ndk116__tree_next_iterIPNS_15__tree_end_nodeIPNS_16__tree_node_baseIPvEEEES5_EET_T0_", "__tree_next_iter"},
    {59,  0x005638ULL, 460U, "_ZNSt6__ndk127__tree_balance_after_insertIPNS_16__tree_node_baseIPvEEEEvT_S5_", "__tree_balance_after_insert"},
    {60,  0x004a1cULL,  84U, "_ZNSt6__ndk16__treeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_4lessIS6_EENS4_IS6_EEE7destroyEPNS_11__tree_nodeIS6_PvEE", "__tree::destroy"},
    {61,  0x005600ULL,  56U, "_ZNSt6__ndk16__treeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_4lessIS6_EENS4_IS6_EEE5clearEv", "__tree::clear"},
    {62,  0x008928ULL, 292U, "_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKcm", "basic_string::insert(pos, s, n)"},
    {63,  0x00765cULL, 840U, "_ZN12IESAppLogger13AppLogTracker4Impl7putValsERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEiPm", "Impl::putVals(key, count, unsigned long*)"},
    {64,  0x00674cULL,  48U, "_ZN12IESAppLogger13AppLogTracker6putValERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEf", "AppLogTracker::putVal(const string&, float)"},
    {65,  0x004440ULL, 248U, "_ZN14AppLogReporter6reportEPKcS1_S1_b", "AppLogReporter::report(appId, event, params, toBusiness)"},
    {66,  0x006254ULL,  48U, "_ZN12IESAppLogger13AppLogTracker6putValERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEl", "AppLogTracker::putVal(const string&, long)"},
    {67,  0x007d1cULL,  48U, "_ZN12IESAppLogger13AppLogTracker7putValsERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEiPf", "AppLogTracker::putVals(key, count, float*)"},
    {68,  0x008388ULL,   4U, "_ZN12IESAppLogger13AppLogTracker7putValsERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEERKNS1_6vectorIS7_NS5_IS7_EEEE", "AppLogTracker::putVals(key, const vector<string>&)"},
    {69,  0x005878ULL, 344U, "_ZN12IESAppLogger13AppLogTracker4ImplC2ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEESA_b", "Impl::Impl(const string&, const string&, bool) [C2]"},
    {70,  0x00677cULL,  28U, "_ZN12IESAppLogger13AppLogTracker6putValEPKcf", "AppLogTracker::putVal(const char*, float)"},
    {71,  0x0069c8ULL,  48U, "_ZN12IESAppLogger13AppLogTracker6putValERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEd", "AppLogTracker::putVal(const string&, double)"},
    {72,  0x006ce8ULL,  48U, "_ZN12IESAppLogger13AppLogTracker6putValERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_", "AppLogTracker::putVal(const string&, const string&)"},
    {73,  0x004bd8ULL,  64U, "_ZNSt6__ndk16__treeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_4lessIS6_EENS4_IS6_EEE21__remove_node_pointerEPNS_11__tree_nodeIS6_PvEE", "__tree::__remove_node_pointer"},
    {74,  0x006024ULL, 560U, "_ZN12IESAppLogger13AppLogTracker4Impl6putValERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEl", "Impl::putVal(const string&, long)"},
    {75,  0x0064d0ULL,  48U, "_ZN12IESAppLogger13AppLogTracker6putValERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEm", "AppLogTracker::putVal(const string&, unsigned long)"},
    {76,  0x00651cULL, 560U, "_ZN12IESAppLogger13AppLogTracker4Impl6putValERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEf", "Impl::putVal(const string&, float)"},
    {77,  0x005878ULL, 344U, "_ZN12IESAppLogger13AppLogTracker4ImplC1ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEESA_b", "Impl::Impl(const string&, const string&, bool) [C1]"},
    {78,  0x0072e4ULL, 840U, "_ZN12IESAppLogger13AppLogTracker4Impl7putValsERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEiPl", "Impl::putVals(key, count, long*)"},
    {79,  0x005c28ULL, 384U, "_ZN12IESAppLogger13AppLogTrackerD2Ev", "AppLogTracker::~AppLogTracker() [D2]"},
    {80,  0x0072b4ULL,  48U, "_ZN12IESAppLogger13AppLogTracker7putValsERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEiPi", "AppLogTracker::putVals(key, count, int*)"},
    {81,  0x006500ULL,  28U, "_ZN12IESAppLogger13AppLogTracker6putValEPKcm", "AppLogTracker::putVal(const char*, unsigned long)"},
    {82,  0x005bc0ULL, 104U, "_ZN12IESAppLogger13AppLogTrackerC2EPKcS2_b", "AppLogTracker::AppLogTracker(const char*, const char*, bool) [C2]"},
    {83,  0x006500ULL,  28U, "_ZN12IESAppLogger13AppLogTracker4Impl6putValEPKcm", "Impl::putVal(const char*, unsigned long)"},
    {84,  0x0083a8ULL,  24U, "_ZN12IESAppLogger13AppLogTracker17disableAllReportsEv", "AppLogTracker::disableAllReports()"},
    {85,  0x005da8ULL, 560U, "_ZN12IESAppLogger13AppLogTracker4Impl6putValERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEi", "Impl::putVal(const string&, int)"},
    {86,  0x005c28ULL, 384U, "_ZN12IESAppLogger13AppLogTrackerD1Ev", "AppLogTracker::~AppLogTracker() [D1]"},
    {87,  0x006fb8ULL,  40U, "_ZN12IESAppLogger13AppLogTracker6putValERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEPKc", "AppLogTracker::putVal(const string&, const char*)"},
    {88,  0x006d34ULL, 644U, "_ZN12IESAppLogger13AppLogTracker4Impl6putValERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEPKc", "Impl::putVal(const string&, const char*)"},
    {89,  0x0062a0ULL, 560U, "_ZN12IESAppLogger13AppLogTracker4Impl6putValERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEm", "Impl::putVal(const string&, unsigned long)"},
    {90,  0x0043c0ULL, 128U, "_ZN14AppLogReporter12GetSingletonEv", "AppLogReporter::GetSingleton()"},
    {91,  0x005bc0ULL, 104U, "_ZN12IESAppLogger13AppLogTrackerC1EPKcS2_b", "AppLogTracker::AppLogTracker(const char*, const char*, bool) [C1]"},
    {92,  0x008824ULL, 260U, "_ZNSt6__ndk1plIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_12basic_stringIT_T0_T1_EEPKS6_RKS9_", "operator+(const char*, const string&)"},
    {93,  0x005b50ULL, 112U, "_ZN12IESAppLogger13AppLogTrackerC1ERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_b", "AppLogTracker::AppLogTracker(const string&, const string&, bool) [C1]"},
    {94,  0x006d18ULL,  28U, "_ZN12IESAppLogger13AppLogTracker6putValEPKcRKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE", "AppLogTracker::putVal(const char*, const string&)"},
    {95,  0x0079a4ULL,  48U, "_ZN12IESAppLogger13AppLogTracker7putValsERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEiPm", "AppLogTracker::putVals(key, count, unsigned long*)"},
    {96,  0x0069f8ULL,  28U, "_ZN12IESAppLogger13AppLogTracker6putValEPKcd", "AppLogTracker::putVal(const char*, double)"},
    {97,  0x006284ULL,  28U, "_ZN12IESAppLogger13AppLogTracker6putValEPKcl", "AppLogTracker::putVal(const char*, long)"},
    {98,  0x005b50ULL, 112U, "_ZN12IESAppLogger13AppLogTrackerC2ERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_b", "AppLogTracker::AppLogTracker(const string&, const string&, bool) [C2]"},
    {99,  0x0046e8ULL, 820U, "Java_com_bytedance_ies_common_IESAppLogger_nativeSetSampler", "JNI nativeSetSampler(JNIEnv*, jobject, jobject)"},
    {100, 0x00762cULL,  48U, "_ZN12IESAppLogger13AppLogTracker7putValsERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEiPl", "AppLogTracker::putVals(key, count, long*)"},
    {101, 0x0083d0ULL,  36U, "_ZN12IESAppLogger13AppLogTracker9isSampledERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE", "AppLogTracker::isSampled(const string&)"},
    {102, 0x00542cULL, 176U, "_ZNSt6__ndk16__treeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_4lessIS6_EENS4_IS6_EEE25__emplace_unique_key_argsIS6_JRKS6_EEENS_4pairINS_15__tree_iteratorIS6_PNS_11__tree_nodeIS6_PvEElEEbEERKT_DpOT0_", "__tree::__emplace_unique_key_args"},
    {103, 0x0059d0ULL, 384U, "_ZN12IESAppLogger13AppLogTracker4ImplC2EPKcS3_b", "Impl::Impl(const char*, const char*, bool) [C2]"},
    {104, 0x006798ULL, 560U, "_ZN12IESAppLogger13AppLogTracker4Impl6putValERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEd", "Impl::putVal(const string&, double)"},
    {105, 0x006008ULL,  28U, "_ZN12IESAppLogger13AppLogTracker6putValEPKci", "AppLogTracker::putVal(const char*, int)"},
    {106, 0x006a14ULL, 724U, "_ZN12IESAppLogger13AppLogTracker4Impl6putValERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEESA_", "Impl::putVal(const string&, const string&)"},
    {107, 0x00875cULL, 200U, "_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKcm", "basic_string::assign(const char*, size_t)"},
    {108, 0x006ffcULL, 696U, "_ZN12IESAppLogger13AppLogTracker4Impl7putValsERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEiPi", "Impl::putVals(key, count, int*)"},
    {109, 0x003f60ULL, 460U, "JNI_OnLoad", "JNI_OnLoad(JavaVM*, void*)"},
    {110, 0x0079d4ULL, 840U, "_ZN12IESAppLogger13AppLogTracker4Impl7putValsERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEiPf", "Impl::putVals(key, count, float*)"},
    {111, 0x005fd8ULL,  48U, "_ZN12IESAppLogger13AppLogTracker6putValERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEi", "AppLogTracker::putVal(const string&, int)"},
    {112, 0x003eacULL, 180U, "_Z6getEnvPi", "getEnv(int* attached)"},
    {113, 0x006fe0ULL,  28U, "_ZN12IESAppLogger13AppLogTracker6putValEPKcS2_", "AppLogTracker::putVal(const char*, const char*)"},
    {114, 0x008560ULL, 196U, "_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm", "basic_string::append(const char*, size_t)"},
    {115, 0x008624ULL, 312U, "_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE21__grow_by_and_replaceEmmmmmmPKc", "basic_string::__grow_by_and_replace"},
    {116, 0x0045c8ULL,   8U, "_ZN14AppLogReporter13setReportFuncEPFiPKcS1_S1_bE", "AppLogReporter::setReportFunc(callback)"},
    {117, 0x0083c0ULL,  16U, "_ZN12IESAppLogger13AppLogTracker19setReportToBusinessEb", "AppLogTracker::setReportToBusiness(bool)"},
    {118, 0x007d4cULL, 840U, "_ZN12IESAppLogger13AppLogTracker4Impl7putValsERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEiPd", "Impl::putVals(key, count, double*)"},
    {119, 0x00838cULL,  28U, "_ZN12IESAppLogger13AppLogTracker16enableAllReportsEv", "AppLogTracker::enableAllReports()"},
    {120, 0x008094ULL,  48U, "_ZN12IESAppLogger13AppLogTracker7putValsERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEiPd", "AppLogTracker::putVals(key, count, double*)"},
    {121, 0x0059d0ULL, 384U, "_ZN12IESAppLogger13AppLogTracker4ImplC1EPKcS3_b", "Impl::Impl(const char*, const char*, bool) [C1]"},
    {122, 0x004538ULL, 144U, "_ZN14AppLogReporter9isSampledERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEE", "AppLogReporter::isSampled(const string&)"}
}};

// ============================================================================
// 2. Self-Verification Entry Point for Host/Target Parity Suite
//    Điểm nhập Tự xác minh cho Bộ kiểm thử Tương đương
// ============================================================================
bool run_iesapplogger_self_verification() {
    // 1. Verify symbol count & key offsets
    // 1. Xác minh số lượng biểu tượng xuất và các địa chỉ trọng yếu
    if (kExportedSymbols.size() != Elf64Geometry::kDynsymExportCount) {
        return false;
    }
    if (kExportedSymbols[0].virtual_address != 0x0080c4ULL ||
        kExportedSymbols[74].virtual_address != 0x004538ULL) {
        return false;
    }

    // 2. Verify AppLogReporter singleton & custom callback
    // 2. Xác minh singleton AppLogReporter & hàm callback tùy chỉnh
    static int s_captured_calls = 0;
    static std::string s_captured_app;
    static std::string s_captured_event;
    static std::string s_captured_json;
    static bool s_captured_business = false;

    auto* reporter = AppLogReporter::GetSingleton();
    reporter->setReportFunc([](const char* app, const char* ev, const char* json, bool biz) -> int {
        s_captured_calls += 1;
        s_captured_app = app ? app : "";
        s_captured_event = ev ? ev : "";
        s_captured_json = json ? json : "";
        s_captured_business = biz;
        return 1;
    });

    IESAppLogger::AppLogTracker::enableAllReports();
    reporter->setSampler({});

    {
        IESAppLogger::AppLogTracker tracker("capcut_aid", "video_export", false);
        tracker.setReportToBusiness(true);
        tracker.putVal("fps", 60)
               .putVal("codec", "h264");
        int res[2] = {1080, 1920};
        tracker.putVals("dims", 2, res);
    }

    if (s_captured_calls != 1 ||
        s_captured_app != "capcut_aid" ||
        s_captured_event != "video_export" ||
        s_captured_json != "{\"fps\":60,\"codec\":\"h264\",\"dims\":\"1080,1920\"}" ||
        !s_captured_business) {
        return false;
    }

    // 3. Verify sampler whitelist filtering
    // 3. Xác minh bộ lọc danh sách trắng lấy mẫu (sampler whitelist)
    reporter->setSampler({"allowed_event"});
    if (IESAppLogger::AppLogTracker::isSampled("blocked_event") ||
        !IESAppLogger::AppLogTracker::isSampled("allowed_event")) {
        return false;
    }

    return true;
}

}  // namespace iesapplogger
