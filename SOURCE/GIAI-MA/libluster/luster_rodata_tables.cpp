/**
 * @file luster_rodata_tables.cpp
 * @brief Clean-Room C++17 Implementation of libluster.so .rodata & .data.rel.ro Tables
 *        Hiện thực hóa C++17 các bảng .rodata (0x167d0..0x366be) & .data.rel.ro (0x3f730..0x3fd58)
 */

#include "luster_rodata_tables.h"

namespace nextai {
namespace opencut {
namespace luster {

namespace {

// S1_EffectUtilClass: cipher @ 0x167d0 ^ key @ 0x366a0 -> .bss 0x40b30 ("com/illusion/light/EffectUtil")
constexpr uint8_t kCipher_0[] = { 0xb9, 0x54, 0xb8, 0x81, 0xd0, 0x11, 0x14, 0x38, 0xbc, 0x0f, 0x2b, 0x8a, 0xa7, 0xb5, 0x09, 0x96, 0x12, 0xaf, 0x1f, 0x26, 0x72, 0x45, 0x18, 0x0a, 0xb1, 0x72, 0x4c, 0x50, 0x15, 0x00 };
constexpr uint8_t kKey_0[]    = { 0xda, 0x3b, 0xd5, 0xae, 0xb9, 0x7d, 0x78, 0x4d, 0xcf, 0x66, 0x44, 0xe4, 0x88, 0xd9, 0x60, 0xf1, 0x7a, 0xdb, 0x30, 0x63, 0x14, 0x23, 0x7d, 0x69, 0xc5, 0x27, 0x38, 0x39, 0x79, 0x00 };
uint8_t g_bss_xor_buf_0[34] = {0};

// S2_RegisterBootstrapSig: cipher @ 0x1680c ^ key @ 0x3668c -> .bss 0x40b7c ("(I)V")
constexpr uint8_t kCipher_1[] = { 0x5b, 0x1b, 0xc5, 0x94, 0x00 };
constexpr uint8_t kKey_1[]    = { 0x73, 0x52, 0xec, 0xc2, 0x00 };
uint8_t g_bss_xor_buf_1[9] = {0};

// S3_RegisterBootstrapName: cipher @ 0x167f0 ^ key @ 0x36670 -> .bss 0x40b60 ("Ew0PFxIIElcAXVdHWFpVCEM0")
constexpr uint8_t kCipher_2[] = { 0x96, 0x09, 0x97, 0x1a, 0xd4, 0x2a, 0xa4, 0x3e, 0xd0, 0x4d, 0x75, 0x3b, 0x31, 0x76, 0x9f, 0xf6, 0xbf, 0x7e, 0x81, 0xcc, 0x17, 0x66, 0xe5, 0xfe, 0x00 };
constexpr uint8_t kKey_2[]    = { 0xd3, 0x7e, 0xa7, 0x4a, 0x92, 0x52, 0xed, 0x77, 0x95, 0x21, 0x16, 0x7a, 0x69, 0x20, 0xfb, 0xbe, 0xe8, 0x38, 0xf1, 0x9a, 0x54, 0x23, 0xa8, 0xce, 0x00 };
uint8_t g_bss_xor_buf_2[29] = {0};

// S4_JavaLangStringClass: cipher @ 0x30210 ^ key @ 0x36650 -> .bss 0x46700 ("java/lang/String")
constexpr uint8_t kCipher_3[] = { 0xbe, 0x29, 0xcd, 0x52, 0x9e, 0xf0, 0xd0, 0xe0, 0x1e, 0xe0, 0x7a, 0x6a, 0x3d, 0x60, 0xa0, 0xf4, 0x00 };
constexpr uint8_t kKey_3[]    = { 0xd4, 0x48, 0xbb, 0x33, 0xb1, 0x9c, 0xb1, 0x8e, 0x79, 0xcf, 0x29, 0x1e, 0x4f, 0x09, 0xce, 0x93, 0x00 };
uint8_t g_bss_xor_buf_3[21] = {0};

// S5_StringInternName: cipher @ 0x30224 ^ key @ 0x36648 -> .bss 0x46720 ("intern")
constexpr uint8_t kCipher_4[] = { 0x5a, 0xf3, 0x11, 0xad, 0xf8, 0xef, 0x00 };
constexpr uint8_t kKey_4[]    = { 0x33, 0x9d, 0x65, 0xc8, 0x8a, 0x81, 0x00 };
uint8_t g_bss_xor_buf_4[11] = {0};

// S6_StringInternSig: cipher @ 0x30230 ^ key @ 0x36630 -> .bss 0x46748 ("()Ljava/lang/String;")
constexpr uint8_t kCipher_5[] = { 0x49, 0x54, 0x10, 0x37, 0xff, 0xec, 0xc2, 0xd1, 0xb2, 0xd1, 0xaa, 0x2c, 0x00, 0xc7, 0x02, 0xe6, 0xc3, 0x4a, 0x83, 0x79, 0x00 };
constexpr uint8_t kKey_5[]    = { 0x61, 0x7d, 0x5c, 0x5d, 0x9e, 0x9a, 0xa3, 0xfe, 0xde, 0xb0, 0xc4, 0x4b, 0x2f, 0x94, 0x76, 0x94, 0xaa, 0x24, 0xe4, 0x42, 0x00 };
uint8_t g_bss_xor_buf_5[25] = {0};

} // namespace

// ============================================================================
// 1. STREAM XOR DECRYPTOR (sub_16328 @ 0x16328..0x16354)
//    BỘ GIẢI MÃ DÒNG XOR (sub_16328 @ 0x16328..0x16354)
// ============================================================================

void sub_16328(const uint8_t* cipher_bytes, uint8_t* out_plaintext, const uint8_t* key_bytes) noexcept {
    if (cipher_bytes == nullptr || out_plaintext == nullptr || key_bytes == nullptr) {
        return;
    }
    uint8_t key_byte = key_bytes[0];
    if (key_byte == 0U) {
        return;
    }
    int64_t idx = 0;
    int32_t next_idx = 1;
    do {
        const uint8_t enc_byte = cipher_bytes[idx];
        out_plaintext[idx] = static_cast<uint8_t>(enc_byte ^ key_byte);
        idx = static_cast<int64_t>(next_idx);
        key_byte = key_bytes[idx];
        ++next_idx;
    } while (key_byte != 0U);
    out_plaintext[idx] = 0U;
}

const char* DecryptLusterCoreXorString(uint32_t slot_index) noexcept {
    switch (slot_index) {
        case 0U:
            sub_16328(kCipher_0, g_bss_xor_buf_0, kKey_0);
            return reinterpret_cast<const char*>(g_bss_xor_buf_0);
        case 1U:
            sub_16328(kCipher_1, g_bss_xor_buf_1, kKey_1);
            return reinterpret_cast<const char*>(g_bss_xor_buf_1);
        case 2U:
            sub_16328(kCipher_2, g_bss_xor_buf_2, kKey_2);
            return reinterpret_cast<const char*>(g_bss_xor_buf_2);
        case 3U:
            sub_16328(kCipher_3, g_bss_xor_buf_3, kKey_3);
            return reinterpret_cast<const char*>(g_bss_xor_buf_3);
        case 4U:
            sub_16328(kCipher_4, g_bss_xor_buf_4, kKey_4);
            return reinterpret_cast<const char*>(g_bss_xor_buf_4);
        case 5U:
            sub_16328(kCipher_5, g_bss_xor_buf_5, kKey_5);
            return reinterpret_cast<const char*>(g_bss_xor_buf_5);
        default:
            return "";
    }
}

// ============================================================================
// 2. 42 PROTECTED JAVA/KOTLIN CLASSES (.rodata 0x016814..0x016a0c)
//    BẢNG 42 LỚP JAVA/KOTLIN ĐƯỢC BẢO VỆ (.rodata 0x016814..0x016a0c)
// ============================================================================

const LusterClassRegEntry kLusterProtectedClasses[kLusterProtectedClassCount] = {

    {  13U,  0U,  1U, "com/bytedance/EnvGuard/Handler" }, // [00] str_idx=1106
    {  20U,  1U,  4U, "com/lemon/editor/proxy/SubscribeImpl" }, // [01] str_idx=1655
    {  62U,  5U,  7U, "com/vega/ad/credit/CreditRewardGlobalViewModel" }, // [02] str_idx=1371
    {  80U, 12U, 11U, "com/vega/ad/credit/data/CreditRewardRepository" }, // [03] str_idx=1730
    {  87U, 23U,  1U, "com/vega/ad/credit/task/CreditActiveRewardTask" }, // [04] str_idx=1284
    {  92U, 24U,  2U, "com/vega/ad/credit/task/CreditLandingRewardTask" }, // [05] str_idx=1190
    {  99U, 26U,  3U, "com/vega/ad/credit/task/CreditTemplateExportCheckTask" }, // [06] str_idx=1335
    { 101U, 29U,  2U, "com/vega/ad/credit/task/CreditWatchAdRewardTask" }, // [07] str_idx=1099
    { 104U, 31U,  1U, "com/vega/ad/impl/adfree/AdFreeManager" }, // [08] str_idx=1638
    { 105U, 32U,  2U, "com/vega/ad/impl/multireward/MultiRewardAd" }, // [09] str_idx=1752
    { 114U, 34U,  1U, "com/vega/adapi/credit/BaseAdCreditTask" }, // [10] str_idx=1295
    { 141U, 35U,  2U, "com/vega/commonedit/dependencies/figure/LVFigureGlobalDependencyImpl$FigureOnItemApplyHook" }, // [11] str_idx=1080
    { 162U, 37U, 10U, "com/vega/draft/data/template/CommerceInfo" }, // [12] str_idx=1134
    { 183U, 47U,  1U, "com/vega/edit/editpage/controller/EditExportController" }, // [13] str_idx=1120
    { 204U, 48U,  2U, "com/vega/launcher/network/interceptors/CrackingInterceptor" }, // [14] str_idx=1076
    { 221U, 50U,  3U, "com/vega/subscribe/SubscribeImpl" }, // [15] str_idx=1280
    { 223U, 53U,  1U, "com/vega/subscribe/SubscriptionUserInfoExtKt" }, // [16] str_idx=1508
    { 225U, 54U,  2U, "com/vega/subscribe/VipSubscribeManager" }, // [17] str_idx=1161
    { 226U, 56U,  1U, "com/vega/subscribe/api/SubscriptionUserInfo" }, // [18] str_idx=1533
    { 232U, 57U,  1U, "com/vega/subscription/biz/checker/BusinessTemplateExportChecker" }, // [19] str_idx=1560
    { 235U, 58U,  1U, "com/vega/subscription/biz/checker/BusinessTemplateUnlockDraftChecker" }, // [20] str_idx=1096
    { 239U, 59U,  1U, "com/vega/subscription/biz/checker/ExportTrialStrategyChecker" }, // [21] str_idx=1195
    { 244U, 60U,  2U, "com/vega/subscription/biz/checker/GeneralUnlockDraftChecker" }, // [22] str_idx=1365
    { 248U, 65U,  1U, "com/vega/subscription/biz/checker/GoodsAccessChecker" }, // [23] str_idx=1643
    { 250U, 66U,  1U, "com/vega/subscription/biz/checker/TemplateBreakWhenExpiredChecker" }, // [24] str_idx=1156
    { 252U, 67U,  1U, "com/vega/subscription/biz/checker/TemplateBreakWhenLaunchChecker" }, // [25] str_idx=1440
    { 255U, 68U,  2U, "com/vega/subscription/biz/checker/TemplateBreakWhenNormalChecker" }, // [26] str_idx=1556
    { 268U, 70U,  2U, "com/vega/subscription/biz/checker/VipExportChecker" }, // [27] str_idx=1621
    { 271U, 72U,  1U, "com/vega/subscription/biz/checker/VipFeaturePayChecker" }, // [28] str_idx=1103
    { 278U, 73U,  1U, "com/vega/subscription/biz/checker/VipFeatureUseChecker" }, // [29] str_idx=1431
    { 287U, 62U,  3U, "com/vega/subscription/biz/checker/base/BaseGoodsAccessChecker" }, // [30] str_idx=1210
    { 297U, 75U,  1U, "com/vega/subscription/biz/function/base/BaseAIFeatureFunction" }, // [31] str_idx=1668
    { 299U, 76U,  1U, "com/vega/subscription/biz/function/base/BaseMultiAIFeatureFunction" }, // [32] str_idx=1276
    { 306U, 77U,  1U, "com/vega/subscription/core/checker/BusinessCheckerCollectionHelper" }, // [33] str_idx=1088
    { 319U, 78U,  1U, "com/vega/subscription/core/function/BaseBusinessCheckerFunction" }, // [34] str_idx=1554
    { 321U, 74U,  1U, "com/vega/subscription/core/function/BaseBusinessFunction" }, // [35] str_idx=1398
    { 323U, 79U,  3U, "com/vega/subscription/legacy/attachment/BaseNewBusinessImpl" }, // [36] str_idx=1251
    { 356U, 82U,  6U, "com/vega/subscriptionapi/core/Result" }, // [37] str_idx=1683
    { 361U, 88U,  1U, "com/vega/subscriptionapi/legacy/data/ResourceData" }, // [38] str_idx=1454
    { 362U, 89U,  1U, "com/vega/subscriptionapi/legacy/data/TemplateCombineIdsResponse" }, // [39] str_idx=1751
    { 364U, 90U,  2U, "com/vega/subscriptionapi/legacy/data/VipScene" }, // [40] str_idx=1416
    { 376U, 92U,  1U, "com/vega/util/WindowUtilsKt" }, // [41] str_idx=1395
};

// ============================================================================
// 3. 93 VIRTUALIZED JNI NATIVE METHODS (.data.rel.ro 0x03f750..0x03fd18)
//    BẢNG 93 PHƯƠNG THỨC GỐC JNI ẢO HÓA (.data.rel.ro 0x03f750..0x03fd18)
// ============================================================================

const LusterMethodRegEntry kLusterVirtualizedMethods[kLusterVirtualizedMethodCount] = {

    {  0U,  804U, 1399U, 0x050a0ULL, "com/bytedance/EnvGuard/Handler", "handleUpdate", "(J)V" },
    {  1U,  647U, 1770U, 0x05328ULL, "com/lemon/editor/proxy/SubscribeImpl", "b", "(Lcom/lemon/lv/clipmonetize/data/UserLiteInfo;Lkotlin/jvm/functions/Function1;Lkotlin/jvm/functions/Function0;)V" },
    {  2U,  732U, 1112U, 0x055dcULL, "com/lemon/editor/proxy/SubscribeImpl", "f", "(ZLjava/lang/String;Lkotlin/jvm/functions/Function1;Lkotlin/jvm/functions/Function1;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;" },
    {  3U,  801U, 1788U, 0x058a8ULL, "com/lemon/editor/proxy/SubscribeImpl", "h", "(Lkotlin/jvm/functions/Function0;Lkotlin/jvm/functions/Function1;)V" },
    {  4U,  843U, 1694U, 0x05b20ULL, "com/lemon/editor/proxy/SubscribeImpl", "isVip", "()Z" },
    {  5U,  647U, 1155U, 0x05d84ULL, "com/vega/ad/credit/CreditRewardGlobalViewModel", "b", "(Ljava/lang/String;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;" },
    {  6U,  661U, 1641U, 0x06020ULL, "com/vega/ad/credit/CreditRewardGlobalViewModel", "c", "(JZLjava/util/List;Lkotlin/jvm/functions/Function3;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;" },
    {  7U,  696U, 1413U, 0x062e8ULL, "com/vega/ad/credit/CreditRewardGlobalViewModel", "d", "(JLjava/lang/String;Ljava/lang/String;ILorg/json/JSONObject;Lkotlin/jvm/functions/Function3;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;" },
    {  8U,  708U, 1053U, 0x065a0ULL, "com/vega/ad/credit/CreditRewardGlobalViewModel", "e", "(JLjava/lang/String;ILorg/json/JSONObject;Lkotlin/jvm/functions/Function3;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;" },
    {  9U,  743U, 1600U, 0x06880ULL, "com/vega/ad/credit/CreditRewardGlobalViewModel", "g", "(JZLjava/lang/String;Ljava/lang/String;Lorg/json/JSONObject;Ljava/lang/String;Ljava/lang/String;Lkotlin/jvm/functions/Function3;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;" },
    { 10U,  813U, 1127U, 0x06b4cULL, "com/vega/ad/credit/CreditRewardGlobalViewModel", "i", "(JZLjava/lang/String;Lcom/vega/adapi/data/credit/DoActionReq;Lkotlin/jvm/functions/Function3;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;" },
    { 11U,  876U, 1694U, 0x06d6cULL, "com/vega/ad/credit/CreditRewardGlobalViewModel", "n", "()Z" },
    { 12U,  624U, 1155U, 0x06fccULL, "com/vega/ad/credit/data/CreditRewardRepository", "a", "(Ljava/lang/String;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;" },
    { 13U,  647U, 1249U, 0x0727cULL, "com/vega/ad/credit/data/CreditRewardRepository", "b", "(Ljava/lang/Long;Lcom/vega/adapi/data/credit/DoActionReq;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;" },
    { 14U,  661U, 1677U, 0x07510ULL, "com/vega/ad/credit/data/CreditRewardRepository", "c", "(Ljava/lang/Long;Ljava/util/List;Lorg/json/JSONObject;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;" },
    { 15U,  696U, 1296U, 0x07768ULL, "com/vega/ad/credit/data/CreditRewardRepository", "d", "(Ljava/lang/Long;Lcom/vega/adapi/data/credit/DoRewardReq;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;" },
    { 16U,  708U, 1300U, 0x079f4ULL, "com/vega/ad/credit/data/CreditRewardRepository", "e", "(Ljava/lang/Long;Lcom/vega/adapi/data/credit/DoRewardCallBackReq;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;" },
    { 17U,  743U, 1249U, 0x07c3cULL, "com/vega/ad/credit/data/CreditRewardRepository", "g", "(Ljava/lang/Long;Lcom/vega/adapi/data/credit/DoActionReq;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;" },
    { 18U,  801U, 1296U, 0x07e6cULL, "com/vega/ad/credit/data/CreditRewardRepository", "h", "(Ljava/lang/Long;Lcom/vega/adapi/data/credit/DoRewardReq;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;" },
    { 19U,  813U, 1300U, 0x08130ULL, "com/vega/ad/credit/data/CreditRewardRepository", "i", "(Ljava/lang/Long;Lcom/vega/adapi/data/credit/DoRewardCallBackReq;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;" },
    { 20U,  848U, 1677U, 0x083b0ULL, "com/vega/ad/credit/data/CreditRewardRepository", "j", "(Ljava/lang/Long;Ljava/util/List;Lorg/json/JSONObject;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;" },
    { 21U,  850U, 1095U, 0x0863cULL, "com/vega/ad/credit/data/CreditRewardRepository", "k", "(Ljava/util/List;Z)V" },
    { 22U,  868U, 1327U, 0x088a8ULL, "com/vega/ad/credit/data/CreditRewardRepository", "m", "(Lcom/vega/ad/credit/data/ApiSource;Lcom/vega/adapi/data/credit/UserInfo;Ljava/lang/String;)V" },
    { 23U,  647U, 1083U, 0x08b50ULL, "com/vega/ad/credit/task/CreditActiveRewardTask", "b", "(Ljava/lang/Long;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;" },
    { 24U,  647U, 1083U, 0x08da8ULL, "com/vega/ad/credit/task/CreditLandingRewardTask", "b", "(Ljava/lang/Long;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;" },
    { 25U,  732U, 1601U, 0x08ff0ULL, "com/vega/ad/credit/task/CreditLandingRewardTask", "f", "(Lcom/vega/adapi/credit/CreditTaskResult;)Z" },
    { 26U,  813U, 1483U, 0x09290ULL, "com/vega/ad/credit/task/CreditTemplateExportCheckTask", "i", "(Lcom/vega/adapi/data/credit/UserInfo;I)Lcom/vega/adapi/credit/CreditTaskResult;" },
    { 27U,  647U, 1083U, 0x094e4ULL, "com/vega/ad/credit/task/CreditTemplateExportCheckTask", "b", "(Ljava/lang/Long;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;" },
    { 28U,  732U, 1601U, 0x09700ULL, "com/vega/ad/credit/task/CreditTemplateExportCheckTask", "f", "(Lcom/vega/adapi/credit/CreditTaskResult;)Z" },
    { 29U,  647U, 1083U, 0x09950ULL, "com/vega/ad/credit/task/CreditWatchAdRewardTask", "b", "(Ljava/lang/Long;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;" },
    { 30U,  732U, 1601U, 0x09c00ULL, "com/vega/ad/credit/task/CreditWatchAdRewardTask", "f", "(Lcom/vega/adapi/credit/CreditTaskResult;)Z" },
    { 31U,  624U, 1140U, 0x09e68ULL, "com/vega/ad/impl/adfree/AdFreeManager", "a", "(Lcom/vega/adapi/constant/AdSceneTag;)Z" },
    { 32U,  850U, 1199U, 0x0a090ULL, "com/vega/ad/impl/multireward/MultiRewardAd", "k", "(Ljava/lang/String;)Z" },
    { 33U,  939U, 1640U, 0x0a2f0ULL, "com/vega/ad/impl/multireward/MultiRewardAd", "s", "(Ljava/lang/String;)V" },
    { 34U,  732U, 1601U, 0x0a53cULL, "com/vega/adapi/credit/BaseAdCreditTask", "f", "(Lcom/vega/adapi/credit/CreditTaskResult;)Z" },
    { 35U,  661U, 1450U, 0x0a7c0ULL, "com/vega/commonedit/dependencies/figure/LVFigureGlobalDependencyImpl$FigureOnItemApplyHook", "c", "(Lcom/vega/container/session/core/ISession;Lcom/vega/edit/figure/model/FigureGroup;Lcom/ss/android/ugc/effectmanager/effect/model/Effect;Ljava/lang/String;Ljava/lang/String;Lcom/vega/middlebridge/swig/LVVEMetaType;Ljava/lang/String;Ljava/lang/Integer;)V" },
    { 36U,  732U, 1707U, 0x0aa70ULL, "com/vega/commonedit/dependencies/figure/LVFigureGlobalDependencyImpl$FigureOnItemApplyHook", "f", "(Lcom/vega/container/session/core/ISession;Ljava/util/Map;)V" },
    { 37U,  750U, 1628U, 0x0acecULL, "com/vega/draft/data/template/CommerceInfo", "getCompatUnlockProductInfo", "()Lcom/vega/draft/data/template/ProductInfo;" },
    { 38U,  775U, 1078U, 0x0af6cULL, "com/vega/draft/data/template/CommerceInfo", "getProductInfo", "(Ljava/lang/String;)Lcom/vega/draft/data/template/ProductInfo;" },
    { 39U,  806U, 1199U, 0x0b214ULL, "com/vega/draft/data/template/CommerceInfo", "hasBoughtProductInfo", "(Ljava/lang/String;)Z" },
    { 40U,  809U, 1199U, 0x0b4d4ULL, "com/vega/draft/data/template/CommerceInfo", "hasProductInfo", "(Ljava/lang/String;)Z" },
    { 41U,  831U, 1694U, 0x0b780ULL, "com/vega/draft/data/template/CommerceInfo", "isGeneralPaidExportTemplate", "()Z" },
    { 42U,  837U, 1694U, 0x0ba1cULL, "com/vega/draft/data/template/CommerceInfo", "isPaidBusinessTemplateOnlyExport", "()Z" },
    { 43U,  838U, 1694U, 0x0bc08ULL, "com/vega/draft/data/template/CommerceInfo", "isPaidExportBusinessTemplate", "()Z" },
    { 44U,  839U, 1694U, 0x0be24ULL, "com/vega/draft/data/template/CommerceInfo", "isPaidExportTemplate", "()Z" },
    { 45U,  840U, 1694U, 0x0c08cULL, "com/vega/draft/data/template/CommerceInfo", "isPaidUnlockBusinessTemplate", "()Z" },
    { 46U,  841U, 1694U, 0x0c2e0ULL, "com/vega/draft/data/template/CommerceInfo", "isPaidUnlockTemplate", "()Z" },
    { 47U,  607U, 1436U, 0x0c500ULL, "com/vega/edit/editpage/controller/EditExportController", "Z", "(Lkotlin/jvm/functions/Function0;)V" },
    { 48U,  696U, 1640U, 0x0c720ULL, "com/vega/launcher/network/interceptors/CrackingInterceptor", "d", "(Ljava/lang/String;)V" },
    { 49U,  821U, 1394U, 0x0c924ULL, "com/vega/launcher/network/interceptors/CrackingInterceptor", "intercept", "(Lcom/bytedance/retrofit2/intercept/Interceptor$Chain;)Lcom/bytedance/retrofit2/SsResponse;" },
    { 50U,  647U, 1770U, 0x0cb90ULL, "com/vega/subscribe/SubscribeImpl", "b", "(Lcom/lemon/lv/clipmonetize/data/UserLiteInfo;Lkotlin/jvm/functions/Function1;Lkotlin/jvm/functions/Function0;)V" },
    { 51U,  732U, 1112U, 0x0ce48ULL, "com/vega/subscribe/SubscribeImpl", "f", "(ZLjava/lang/String;Lkotlin/jvm/functions/Function1;Lkotlin/jvm/functions/Function1;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;" },
    { 52U,  801U, 1788U, 0x0d0c0ULL, "com/vega/subscribe/SubscribeImpl", "h", "(Lkotlin/jvm/functions/Function0;Lkotlin/jvm/functions/Function1;)V" },
    { 53U,  624U, 1614U, 0x0d2dcULL, "com/vega/subscribe/SubscriptionUserInfoExtKt", "a", "(Lcom/vega/subscribe/api/SubscriptionUserInfo;)Lcom/vega/subscribe/VipSubscribeManager$VipStatus;" },
    { 54U,  647U, 1770U, 0x0d57cULL, "com/vega/subscribe/VipSubscribeManager", "b", "(Lcom/lemon/lv/clipmonetize/data/UserLiteInfo;Lkotlin/jvm/functions/Function1;Lkotlin/jvm/functions/Function0;)V" },
    { 55U,  743U, 1694U, 0x0d85cULL, "com/vega/subscribe/VipSubscribeManager", "g", "()Z" },
    { 56U,  732U, 1694U, 0x0dae0ULL, "com/vega/subscribe/api/SubscriptionUserInfo", "f", "()Z" },
    { 57U,  708U, 1515U, 0x0dd28ULL, "com/vega/subscription/biz/checker/BusinessTemplateExportChecker", "e", "(Lcom/vega/subscription/core/checker/CheckerContext;ZLkotlin/coroutines/Continuation;)Ljava/lang/Object;" },
    { 58U,  708U, 1515U, 0x0dfa8ULL, "com/vega/subscription/biz/checker/BusinessTemplateUnlockDraftChecker", "e", "(Lcom/vega/subscription/core/checker/CheckerContext;ZLkotlin/coroutines/Continuation;)Ljava/lang/Object;" },
    { 59U,  708U, 1515U, 0x0e250ULL, "com/vega/subscription/biz/checker/ExportTrialStrategyChecker", "e", "(Lcom/vega/subscription/core/checker/CheckerContext;ZLkotlin/coroutines/Continuation;)Ljava/lang/Object;" },
    { 60U,  708U, 1515U, 0x0e4c0ULL, "com/vega/subscription/biz/checker/GeneralUnlockDraftChecker", "e", "(Lcom/vega/subscription/core/checker/CheckerContext;ZLkotlin/coroutines/Continuation;)Ljava/lang/Object;" },
    { 61U,  743U, 1217U, 0x0e7acULL, "com/vega/subscription/biz/checker/GeneralUnlockDraftChecker", "g", "(Lcom/vega/subscription/core/checker/CheckerContext;Lcom/vega/subscription/core/checker/CheckResult;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;" },
    { 62U,  813U, 1377U, 0x0ea44ULL, "com/vega/subscription/biz/checker/base/BaseGoodsAccessChecker", "i", "(Lcom/vega/subscription/biz/checker/base/BaseGoodsAccessChecker;Lcom/vega/subscription/core/checker/CheckResult;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;" },
    { 63U,  732U, 1217U, 0x0ec80ULL, "com/vega/subscription/biz/checker/base/BaseGoodsAccessChecker", "f", "(Lcom/vega/subscription/core/checker/CheckerContext;Lcom/vega/subscription/core/checker/CheckResult;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;" },
    { 64U,  852U, 1593U, 0x0ef10ULL, "com/vega/subscription/biz/checker/base/BaseGoodsAccessChecker", "l", "(Lcom/lemon/lv/clipmonetize/wrapper/BenefitResource;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;" },
    { 65U,  708U, 1515U, 0x0f15cULL, "com/vega/subscription/biz/checker/GoodsAccessChecker", "e", "(Lcom/vega/subscription/core/checker/CheckerContext;ZLkotlin/coroutines/Continuation;)Ljava/lang/Object;" },
    { 66U,  708U, 1515U, 0x0f3a0ULL, "com/vega/subscription/biz/checker/TemplateBreakWhenExpiredChecker", "e", "(Lcom/vega/subscription/core/checker/CheckerContext;ZLkotlin/coroutines/Continuation;)Ljava/lang/Object;" },
    { 67U,  708U, 1515U, 0x0f610ULL, "com/vega/subscription/biz/checker/TemplateBreakWhenLaunchChecker", "e", "(Lcom/vega/subscription/core/checker/CheckerContext;ZLkotlin/coroutines/Continuation;)Ljava/lang/Object;" },
    { 68U,  708U, 1515U, 0x0f85cULL, "com/vega/subscription/biz/checker/TemplateBreakWhenNormalChecker", "e", "(Lcom/vega/subscription/core/checker/CheckerContext;ZLkotlin/coroutines/Continuation;)Ljava/lang/Object;" },
    { 69U,  850U, 1183U, 0x0fac4ULL, "com/vega/subscription/biz/checker/TemplateBreakWhenNormalChecker", "k", "(Lcom/vega/subscription/core/checker/CheckerContext;Lcom/vega/feedx/main/bean/FeedItem;ZLkotlin/coroutines/Continuation;)Ljava/lang/Object;" },
    { 70U,  708U, 1515U, 0x0fd70ULL, "com/vega/subscription/biz/checker/VipExportChecker", "e", "(Lcom/vega/subscription/core/checker/CheckerContext;ZLkotlin/coroutines/Continuation;)Ljava/lang/Object;" },
    { 71U,  732U, 1217U, 0x10044ULL, "com/vega/subscription/biz/checker/VipExportChecker", "f", "(Lcom/vega/subscription/core/checker/CheckerContext;Lcom/vega/subscription/core/checker/CheckResult;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;" },
    { 72U,  708U, 1515U, 0x102d0ULL, "com/vega/subscription/biz/checker/VipFeaturePayChecker", "e", "(Lcom/vega/subscription/core/checker/CheckerContext;ZLkotlin/coroutines/Continuation;)Ljava/lang/Object;" },
    { 73U,  708U, 1515U, 0x1053cULL, "com/vega/subscription/biz/checker/VipFeatureUseChecker", "e", "(Lcom/vega/subscription/core/checker/CheckerContext;ZLkotlin/coroutines/Continuation;)Ljava/lang/Object;" },
    { 74U,  564U, 1439U, 0x107fcULL, "com/vega/subscription/core/function/BaseBusinessFunction", "O3", "(Lcom/vega/subscriptionapi/core/IBusinessFunctionParam;Lkotlin/jvm/functions/Function1;)Lkotlinx/coroutines/Job;" },
    { 75U,  870U, 1448U, 0x10ab0ULL, "com/vega/subscription/biz/function/base/BaseAIFeatureFunction", "m4", "(Lcom/vega/subscriptionapi/biz/function/AIFeatureFunctionParam;Lkotlin/jvm/functions/Function1;)Lkotlinx/coroutines/Job;" },
    { 76U,  870U, 1040U, 0x10d10ULL, "com/vega/subscription/biz/function/base/BaseMultiAIFeatureFunction", "m4", "(Lcom/vega/subscriptionapi/biz/function/MultiAIFeatureFunctionParam;Lkotlin/jvm/functions/Function1;)Lkotlinx/coroutines/Job;" },
    { 77U,  624U, 1607U, 0x10f5cULL, "com/vega/subscription/core/checker/BusinessCheckerCollectionHelper", "a", "(Lcom/vega/subscription/core/checker/CheckerContext;Ljava/util/List;Lkotlin/jvm/functions/Function1;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;" },
    { 78U,  564U, 1439U, 0x111ccULL, "com/vega/subscription/core/function/BaseBusinessCheckerFunction", "O3", "(Lcom/vega/subscriptionapi/core/IBusinessFunctionParam;Lkotlin/jvm/functions/Function1;)Lkotlinx/coroutines/Job;" },
    { 79U,   50U, 1742U, 0x1143cULL, "com/vega/subscription/legacy/attachment/BaseNewBusinessImpl", "E", "()Ljava/util/List;" },
    { 80U,  902U, 1569U, 0x116b8ULL, "com/vega/subscription/legacy/attachment/BaseNewBusinessImpl", "p", "(Z)Ljava/util/List;" },
    { 81U,  917U, 1402U, 0x1194cULL, "com/vega/subscription/legacy/attachment/BaseNewBusinessImpl", "r", "(Lcom/vega/middlebridge/swig/AttachmentVipFeature;)V" },
    { 82U,  624U, 1754U, 0x11bd4ULL, "com/vega/subscriptionapi/core/Result", "a", "(Lkotlin/jvm/functions/Function1;)V" },
    { 83U,  647U, 1754U, 0x11e0cULL, "com/vega/subscriptionapi/core/Result", "b", "(Lkotlin/jvm/functions/Function1;)V" },
    { 84U,  661U, 1754U, 0x120c8ULL, "com/vega/subscriptionapi/core/Result", "c", "(Lkotlin/jvm/functions/Function1;)V" },
    { 85U,  696U, 1754U, 0x1236cULL, "com/vega/subscriptionapi/core/Result", "d", "(Lkotlin/jvm/functions/Function1;)V" },
    { 86U,  708U, 1754U, 0x1263cULL, "com/vega/subscriptionapi/core/Result", "e", "(Lkotlin/jvm/functions/Function1;)V" },
    { 87U,  732U, 1376U, 0x1289cULL, "com/vega/subscriptionapi/core/Result", "f", "(Lkotlin/jvm/functions/Function2;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;" },
    { 88U,  624U, 1403U, 0x12b6cULL, "com/vega/subscriptionapi/legacy/data/ResourceData", "a", "()Ljava/lang/String;" },
    { 89U,  624U, 1742U, 0x12e04ULL, "com/vega/subscriptionapi/legacy/data/TemplateCombineIdsResponse", "a", "()Ljava/util/List;" },
    { 90U,  647U, 1694U, 0x140a0ULL, "com/vega/subscriptionapi/legacy/data/VipScene", "b", "()Z" },
    { 91U,  661U, 1694U, 0x1430cULL, "com/vega/subscriptionapi/legacy/data/VipScene", "c", "()Z" },
    { 92U,  624U, 1157U, 0x1459cULL, "com/vega/util/WindowUtilsKt", "a", "(Landroid/view/Window;Z)V" },
};

// ============================================================================
// 4. 220 HOT INTERNED STRING INDICES (.rodata 0x02fea0..0x030210)
//    BẢNG 220 CHỈ MỤC CHUỖI INTERNED NÓNG (.rodata 0x02fea0..0x030210)
// ============================================================================

const int32_t kLusterHotStringIndices[kLusterHotStringTableCapacity] = {

       0,    3,    4,    5,    6,    7,    8,    9,   10,   11,
      12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
      22,   23,   24,   25,   26,   27,   28,   29,   31,   32,
      33,   40,   41,   46,   47,   48,   51,   53,   56,   64,
     561,  562,  566,  568,  602,  603,  621,  622,  623,  627,
     631,  632,  633,  635,  636,  638,  639,  640,  641,  646,
     649,  650,  651,  658,  659,  660,  664,  666,  667,  668,
     669,  673,  674,  675,  677,  678,  691,  693,  698,  699,
     700,  702,  703,  704,  706,  707,  710,  711,  714,  717,
     718,  720,  722,  724,  726,  727,  728,  729,  734,  736,
     737,  742,  788,  797,  798,  799,  800,  807,  815,  816,
     817,  819,  820,  834,  836,  842,  844,  845,  847,  851,
     855,  856,  857,  859,  860,  861,  866,  871,  873,  874,
     877,  879,  880,  882,  883,  884,  885,  886,  887,  888,
     889,  890,  891,  892,  893,  896,  904,  907,  912,  921,
     922,  925,  927,  929,  930,  931,  932,  933,  934,  935,
     936,  937,  938,  941,  942,  945,  947,  948,  949,  951,
     954,  958,  959,  960,  961,  963,  965,  966,  967,  968,
     972,  973,  974,  975,  976,  977,  978,  984,  985,  986,
     987,  988,  989,  990,  991,  994,  995,  998,  999, 1002,
    1003, 1004, 1005, 1010, 1011, 1012, 1013, 1014, 1015, 1016,
    1017, 1018, 1019, 1020, 1021, 1022, 1023, 1024, 1027, 1030,
};

// ============================================================================
// 5. 344 FIELD DESCRIPTORS (.rodata 0x02b7fc..0x02cd80)
//    BẢNG 344 BỘ MÔ TẢ TRƯỜNG (.rodata 0x02b7fc..0x02cd80)
// ============================================================================

const LusterFieldDesc kLusterFieldDescriptors[kLusterFieldDescriptorCount] = {

    {  13U,   1U,  463U, 0x0000000dU }, // field[000]
    {  65U,  13U,   13U, 0x000002c1U }, // field[001]
    { 437U,  13U,  953U, 0x0000019dU }, // field[002]
    {  20U, 624U,  220U, 0x00000015U }, // field[003]
    { 483U,  21U,   27U, 0x00000287U }, // field[004]
    { 393U,  27U,  661U, 0x00000189U }, // field[005]
    {  29U, 732U,   28U, 0x0000001eU }, // field[006]
    { 743U, 430U,   30U, 0x00000321U }, // field[007]
    { 431U,  30U,  813U, 0x000001aeU }, // field[008]
    {  30U, 848U,  429U, 0x00000028U }, // field[009]
    { 696U,  40U,   45U, 0x00000270U }, // field[010]
    {  45U,  52U,  916U, 0x00000188U }, // field[011]
    {  52U, 939U,    1U, 0x00000035U }, // field[012]
    { 916U, 456U,   53U, 0x00000395U }, // field[013]
    { 392U,  53U,  939U, 0x0000007eU }, // field[014]
    {  53U, 962U,  432U, 0x00000035U }, // field[015]
    { 992U, 392U,   53U, 0x00000401U }, // field[016]
    {   1U,  56U,  916U, 0x00000002U }, // field[017]
    {  56U, 917U,  456U, 0x00000038U }, // field[018]
    { 939U, 432U,   56U, 0x000003c2U }, // field[019]
    { 129U,  56U,  992U, 0x00000188U }, // field[020]
    {  56U, 1025U,    1U, 0x0000003aU }, // field[021]
    { 916U,   2U,   58U, 0x00000395U }, // field[022]
    { 456U,  58U,  939U, 0x000001b0U }, // field[023]
    {  58U, 962U,  128U, 0x0000003aU }, // field[024]
    { 992U, 392U,   58U, 0x00000401U }, // field[025]
    {   1U,  60U,  916U, 0x00000002U }, // field[026]
    {  60U, 917U,  456U, 0x0000003cU }, // field[027]
    { 939U, 392U,   60U, 0x000003c2U }, // field[028]
    { 432U,  60U,  992U, 0x00000188U }, // field[029]
    {  60U, 1006U,  392U, 0x0000003cU }, // field[030]
    { 1031U,   1U,   62U, 0x00000270U }, // field[031]
    { 413U,  62U,  647U, 0x0000019dU }, // field[032]
    {  62U, 661U,  413U, 0x0000003eU }, // field[033]
    { 696U, 413U,   64U, 0x00000270U }, // field[034]
    {  64U,  65U,  624U, 0x00000041U }, // field[035]
    {  65U, 647U,   65U, 0x00000041U }, // field[036]
    { 661U,  65U,   65U, 0x000002b8U }, // field[037]
    {  65U,  67U,  916U, 0x00000188U }, // field[038]
    {  67U, 917U,  392U, 0x00000043U }, // field[039]
    { 962U,   1U,   68U, 0x00000394U }, // field[040]
    { 126U,  68U,  917U, 0x00000188U }, // field[041]
    {  68U, 962U,    1U, 0x00000045U }, // field[042]
    { 916U, 392U,   69U, 0x00000395U }, // field[043]
    { 392U,  69U,  962U, 0x00000001U }, // field[044]
    {  70U, 916U,  392U, 0x00000046U }, // field[045]
    { 939U,   1U,   71U, 0x00000394U }, // field[046]
    { 392U,  71U,  939U, 0x00000001U }, // field[047]
    {  72U, 916U,   80U, 0x00000048U }, // field[048]
    { 917U, 392U,   72U, 0x000003c2U }, // field[049]
    {   1U,  74U,  916U, 0x00000050U }, // field[050]
    {  74U, 917U,  392U, 0x0000004aU }, // field[051]
    { 962U,   1U,   76U, 0x00000394U }, // field[052]
    {  80U,  76U,  917U, 0x00000188U }, // field[053]
    {  76U, 962U,    1U, 0x0000004eU }, // field[054]
    { 916U,  80U,   78U, 0x00000395U }, // field[055]
    { 392U,  78U,  962U, 0x00000001U }, // field[056]
    {  80U, 624U,  413U, 0x00000050U }, // field[057]
    { 647U, 437U,   80U, 0x00000295U }, // field[058]
    { 136U,  80U,  696U, 0x0000000cU }, // field[059]
    {  80U, 708U,  443U, 0x00000050U }, // field[060]
    { 732U, 412U,   80U, 0x000002e7U }, // field[061]
    { 413U,  80U,  801U, 0x0000000cU }, // field[062]
    {  80U, 813U,   12U, 0x00000050U }, // field[063]
    { 848U,  12U,   80U, 0x00000352U }, // field[064]
    {  66U,  80U,  852U, 0x000001cfU }, // field[065]
    {  80U, 868U,   80U, 0x00000055U }, // field[066]
    { 916U, 392U,   85U, 0x00000395U }, // field[067]
    { 392U,  85U,  962U, 0x00000001U }, // field[068]
    {  86U, 708U,   86U, 0x00000059U }, // field[069]
    { 916U, 136U,   89U, 0x00000395U }, // field[070]
    { 392U,  89U,  962U, 0x00000001U }, // field[071]
    {  92U, 848U,  160U, 0x0000005dU }, // field[072]
    { 916U, 392U,   93U, 0x000003abU }, // field[073]
    {   1U,  99U,  848U, 0x000000a0U }, // field[074]
    {  99U, 850U,  371U, 0x00000063U }, // field[075]
    { 852U, 413U,   99U, 0x00000364U }, // field[076]
    { 413U, 101U,  848U, 0x0000019dU }, // field[077]
    { 101U, 850U,  413U, 0x00000066U }, // field[078]
    { 624U,   1U,  102U, 0x00000287U }, // field[079]
    { 393U, 103U,  624U, 0x0000008aU }, // field[080]
    { 103U, 647U,  456U, 0x00000068U }, // field[081]
    { 624U, 104U,  104U, 0x00000287U }, // field[082]
    { 413U, 105U,  624U, 0x0000006bU }, // field[083]
    { 105U, 647U,  112U, 0x00000069U }, // field[084]
    { 661U, 413U,  106U, 0x00000270U }, // field[085]
    { 106U, 111U,  634U, 0x00000196U }, // field[086]
    { 112U, 624U,  393U, 0x00000071U }, // field[087]
    { 647U, 113U,  113U, 0x00000295U }, // field[088]
    { 113U, 113U,  696U, 0x00000071U }, // field[089]
    { 114U, 624U,   10U, 0x00000072U }, // field[090]
    { 647U, 446U,  114U, 0x00000295U }, // field[091]
    { 429U, 114U,  696U, 0x000001aeU }, // field[092]
    { 114U, 708U,  446U, 0x00000072U }, // field[093]
    { 732U, 429U,  114U, 0x000002e7U }, // field[094]
    { 429U, 114U,  801U, 0x00000185U }, // field[095]
    { 114U, 813U,  413U, 0x00000074U }, // field[096]
    { 661U, 392U,  117U, 0x00000270U }, // field[097]
    { 117U, 117U,  661U, 0x00000075U }, // field[098]
    { 117U, 696U,  117U, 0x00000077U }, // field[099]
    { 624U, 392U,  119U, 0x00000287U }, // field[100]
    { 456U, 119U,  696U, 0x00000076U }, // field[101]
    { 120U, 647U,  138U, 0x00000089U }, // field[102]
    { 624U, 406U,  139U, 0x00000270U }, // field[103]
    { 139U, 139U,  801U, 0x00000189U }, // field[104]
    { 139U, 852U,  393U, 0x00000090U }, // field[105]
    {  44U, 143U,  148U, 0x00000041U }, // field[106]
    { 148U, 150U,  624U, 0x00000096U }, // field[107]
    { 150U, 647U,  199U, 0x00000096U }, // field[108]
    { 708U, 400U,  150U, 0x0000032dU }, // field[109]
    { 393U, 157U,  624U, 0x0000009dU }, // field[110]
    { 157U, 661U,  156U, 0x0000009eU }, // field[111]
    { 624U, 158U,  160U, 0x00000027U }, // field[112]
    { 393U, 160U,  876U, 0x00000189U }, // field[113]
    { 160U, 917U,   37U, 0x000000a0U }, // field[114]
    { 992U, 393U,  160U, 0x000003eeU }, // field[115]
    { 162U, 162U,    2U, 0x000001cdU }, // field[116]
    { 162U,  44U,  161U, 0x000000a2U }, // field[117]
    {  52U, 162U,  162U, 0x00000043U }, // field[118]
    { 162U, 162U,  641U, 0x00000001U }, // field[119]
    { 162U, 652U,  406U, 0x000000a2U }, // field[120]
    { 679U, 403U,  162U, 0x000002acU }, // field[121]
    { 393U, 162U,  692U, 0x00000189U }, // field[122]
    { 162U, 713U,  456U, 0x000000a2U }, // field[123]
    { 725U,   1U,  162U, 0x000002daU }, // field[124]
    { 406U, 162U,  731U, 0x00000196U }, // field[125]
    { 162U, 826U,  456U, 0x000000a2U }, // field[126]
    { 832U, 456U,  162U, 0x00000360U }, // field[127]
    { 393U, 162U,  878U, 0x000001c8U }, // field[128]
    { 162U, 897U,  165U, 0x000000a2U }, // field[129]
    { 906U, 393U,  162U, 0x0000038eU }, // field[130]
    { 393U, 162U,  911U, 0x00000198U }, // field[131]
    { 162U, 913U,    1U, 0x000000a2U }, // field[132]
    { 928U, 163U,  162U, 0x000003b2U }, // field[133]
    { 168U, 162U,  969U, 0x00000001U }, // field[134]
    { 162U, 971U,  403U, 0x000000a2U }, // field[135]
    { 996U, 456U,  162U, 0x000003e5U }, // field[136]
    { 393U, 162U, 1000U, 0x000001c8U }, // field[137]
    { 169U, 624U,  169U, 0x000000aaU }, // field[138]
    { 624U, 170U,  173U, 0x00000270U }, // field[139]
    { 173U, 174U,  661U, 0x00000189U }, // field[140]
    { 174U, 696U,  393U, 0x000000aeU }, // field[141]
    { 708U, 454U,  175U, 0x00000270U }, // field[142]
    { 175U, 176U,  647U, 0x000000b0U }, // field[143]
    { 177U, 813U,  176U, 0x000000b3U }, // field[144]
    { 647U, 140U,  179U, 0x0000032dU }, // field[145]
    { 347U, 183U,  605U, 0x000001adU }, // field[146]
    { 183U, 606U,  413U, 0x000000b7U }, // field[147]
    { 608U, 413U,  183U, 0x00000272U }, // field[148]
    { 413U, 183U,  648U, 0x0000019dU }, // field[149]
    { 183U, 662U,  413U, 0x000000b7U }, // field[150]
    { 697U, 413U,  183U, 0x000002c5U }, // field[151]
    { 413U, 183U,  733U, 0x000000b8U }, // field[152]
    { 183U, 744U,  456U, 0x000000b7U }, // field[153]
    { 803U, 180U,  183U, 0x0000032eU }, // field[154]
    { 403U, 185U,  624U, 0x000001c8U }, // field[155]
    { 187U, 624U,  393U, 0x000000bbU }, // field[156]
    { 647U, 191U,  187U, 0x000002b8U }, // field[157]
    { 456U, 187U,  868U, 0x000000bbU }, // field[158]
    { 189U, 624U,  189U, 0x000000bfU }, // field[159]
    { 624U, 393U,  194U, 0x00000041U }, // field[160]
    { 194U, 196U,   65U, 0x000000c4U }, // field[161]
    { 197U, 624U,  197U, 0x000000ccU }, // field[162]
    { 624U, 413U,  204U, 0x00000287U }, // field[163]
    { 456U, 204U,  661U, 0x0000019dU }, // field[164]
    { 204U, 696U,  200U, 0x000000ccU }, // field[165]
    { 708U, 456U,  206U, 0x00000270U }, // field[166]
    { 206U, 209U,  696U, 0x00000002U }, // field[167]
    { 212U, 624U,    2U, 0x000000d6U }, // field[168]
    { 647U, 214U,  214U, 0x00000295U }, // field[169]
    { 214U, 215U,  849U, 0x000000d7U }, // field[170]
    { 216U, 661U,  216U, 0x000000dbU }, // field[171]
    { 653U, 456U,  221U, 0x00000270U }, // field[172]
    { 222U, 224U,  647U, 0x000000e0U }, // field[173]
    { 224U, 696U,  224U, 0x000000e0U }, // field[174]
    { 708U, 224U,  224U, 0x000002dcU }, // field[175]
    { 224U, 225U,  624U, 0x000000e1U }, // field[176]
    { 225U, 647U,  463U, 0x000000e1U }, // field[177]
    { 661U, 457U,  225U, 0x000002b8U }, // field[178]
    { 413U, 225U,  708U, 0x0000019dU }, // field[179]
    { 225U, 732U,  224U, 0x000000e1U }, // field[180]
    { 743U, 412U,  225U, 0x00000321U }, // field[181]
    { 199U, 225U,  813U, 0x0000019dU }, // field[182]
    { 225U, 848U,  437U, 0x000000e1U }, // field[183]
    { 850U, 437U,  225U, 0x00000354U }, // field[184]
    { 226U, 225U,  868U, 0x00000189U }, // field[185]
    { 225U, 876U,  406U, 0x000000e1U }, // field[186]
    { 894U, 456U,  225U, 0x00000386U }, // field[187]
    { 413U, 225U,  916U, 0x0000019dU }, // field[188]
    { 225U, 917U,  199U, 0x000000e1U }, // field[189]
    { 939U, 456U,  226U, 0x0000027dU }, // field[190]
    { 456U, 226U,  644U, 0x00000189U }, // field[191]
    { 226U, 665U,  456U, 0x000000e2U }, // field[192]
    { 689U, 393U,  226U, 0x000002b2U }, // field[193]
    {   2U, 226U,  695U, 0x00000189U }, // field[194]
    { 226U, 715U,    2U, 0x000000e2U }, // field[195]
    { 740U, 456U,  226U, 0x0000032bU }, // field[196]
    { 456U, 226U,  824U, 0x000001c8U }, // field[197]
    { 226U, 830U,  456U, 0x000000e2U }, // field[198]
    { 910U, 393U,  226U, 0x000003b6U }, // field[199]
    {   2U, 226U,  955U, 0x00000001U }, // field[200]
    { 226U, 956U,  393U, 0x000000e2U }, // field[201]
    { 957U, 393U,  226U, 0x000003e1U }, // field[202]
    { 393U, 226U, 1029U, 0x000000e3U }, // field[203]
    { 229U, 916U,  456U, 0x000000e5U }, // field[204]
    { 917U, 392U,  229U, 0x000003abU }, // field[205]
    { 392U, 229U,  992U, 0x00000001U }, // field[206]
    { 232U, 661U,  233U, 0x000000e8U }, // field[207]
    { 696U, 393U,  233U, 0x00000270U }, // field[208]
    { 393U, 233U,  661U, 0x000000a6U }, // field[209]
    { 235U, 661U,  236U, 0x000000ebU }, // field[210]
    { 696U, 393U,  237U, 0x00000394U }, // field[211]
    { 238U, 237U,  917U, 0x00000188U }, // field[212]
    { 237U, 962U,    1U, 0x000000efU }, // field[213]
    { 661U, 393U,  244U, 0x00000295U }, // field[214]
    { 256U, 244U,  696U, 0x00000189U }, // field[215]
    { 245U, 916U,  456U, 0x000000f5U }, // field[216]
    { 917U, 392U,  245U, 0x000003abU }, // field[217]
    { 392U, 245U,  992U, 0x00000001U }, // field[218]
    { 248U, 708U,  289U, 0x000000f8U }, // field[219]
    { 732U, 413U,  248U, 0x000002e7U }, // field[220]
    { 413U, 250U,  696U, 0x00000196U }, // field[221]
    { 252U, 696U,  393U, 0x000000fcU }, // field[222]
    { 708U, 437U,  252U, 0x000002dcU }, // field[223]
    { 406U, 252U,  743U, 0x000001cfU }, // field[224]
    { 254U, 916U,  292U, 0x000000feU }, // field[225]
    { 917U, 301U,  254U, 0x000003abU }, // field[226]
    {   2U, 254U,  962U, 0x00000188U }, // field[227]
    { 254U, 1006U,    1U, 0x00000100U }, // field[228]
    { 647U, 393U,  256U, 0x000002dcU }, // field[229]
    { 162U, 256U,  743U, 0x00000198U }, // field[230]
    { 256U, 801U,  454U, 0x00000100U }, // field[231]
    { 813U, 393U,  257U, 0x00000394U }, // field[232]
    { 392U, 257U,  917U, 0x00000188U }, // field[233]
    { 257U, 939U,  392U, 0x00000101U }, // field[234]
    { 962U,   2U,  257U, 0x000003e0U }, // field[235]
    {   1U, 257U, 1006U, 0x000001c8U }, // field[236]
    { 257U, 1025U,  392U, 0x00000101U }, // field[237]
    { 1032U,   1U,  264U, 0x00000394U }, // field[238]
    { 443U, 264U,  917U, 0x00000188U }, // field[239]
    { 264U, 962U,    1U, 0x0000010cU }, // field[240]
    { 661U, 269U,  268U, 0x000002b8U }, // field[241]
    { 393U, 268U,  708U, 0x0000019dU }, // field[242]
    { 269U, 624U,  208U, 0x0000010dU }, // field[243]
    { 647U, 360U,  269U, 0x000002c4U }, // field[244]
    { 351U, 269U,  732U, 0x00000189U }, // field[245]
    { 269U, 801U,  431U, 0x0000010dU }, // field[246]
    { 848U, 393U,  269U, 0x00000352U }, // field[247]
    { 408U, 269U,  852U, 0x000001c6U }, // field[248]
    { 270U, 624U,  393U, 0x0000010eU }, // field[249]
    { 647U,  49U,  270U, 0x000002b8U }, // field[250]
    { 456U, 270U,  732U, 0x000001c8U }, // field[251]
    { 270U, 801U,   27U, 0x0000010fU }, // field[252]
    { 661U, 270U,  271U, 0x000002b8U }, // field[253]
    { 393U, 272U,  916U, 0x00000188U }, // field[254]
    { 272U, 939U,    1U, 0x00000116U }, // field[255]
    { 661U, 270U,  278U, 0x000002b8U }, // field[256]
    { 393U, 278U,  708U, 0x0000019dU }, // field[257]
    { 278U, 732U,  413U, 0x00000116U }, // field[258]
    { 743U, 413U,  280U, 0x00000394U }, // field[259]
    { 287U, 280U,  917U, 0x00000188U }, // field[260]
    { 280U, 939U,  443U, 0x00000118U }, // field[261]
    { 962U, 392U,  280U, 0x000003eeU }, // field[262]
    {   1U, 282U,  916U, 0x0000001bU }, // field[263]
    { 282U, 917U,  392U, 0x0000011aU }, // field[264]
    { 962U,   1U,  287U, 0x00000295U }, // field[265]
    { 289U, 287U,  696U, 0x00000189U }, // field[266]
    { 288U, 661U,  290U, 0x00000121U }, // field[267]
    { 624U, 393U,  289U, 0x00000287U }, // field[268]
    { 393U, 289U,  661U, 0x000000a6U }, // field[269]
    { 289U, 696U,  393U, 0x00000121U }, // field[270]
    { 708U, 408U,  289U, 0x000002dcU }, // field[271]
    { 454U, 289U,  813U, 0x00000189U }, // field[272]
    { 290U, 624U,  145U, 0x00000122U }, // field[273]
    { 647U, 393U,  290U, 0x000002c4U }, // field[274]
    { 393U, 290U,  801U, 0x00000198U }, // field[275]
    { 291U, 647U,  337U, 0x00000129U }, // field[276]
    { 624U, 426U,  297U, 0x00000287U }, // field[277]
    { 413U, 297U,  661U, 0x0000019dU }, // field[278]
    { 297U, 696U,  398U, 0x00000129U }, // field[279]
    { 708U, 398U,  297U, 0x000002dcU }, // field[280]
    {   0U, 297U,  743U, 0x00000189U }, // field[281]
    { 297U, 801U,  408U, 0x00000129U }, // field[282]
    { 813U, 456U,  299U, 0x00000270U }, // field[283]
    { 426U, 299U,  647U, 0x0000019dU }, // field[284]
    { 299U, 661U,  413U, 0x0000012bU }, // field[285]
    { 696U, 456U,  300U, 0x00000287U }, // field[286]
    { 300U, 302U,   49U, 0x0000001bU }, // field[287]
    { 302U, 1031U,   27U, 0x0000012fU }, // field[288]
    { 647U, 408U,  305U, 0x00000394U }, // field[289]
    { 310U, 305U,  917U, 0x000001aeU }, // field[290]
    { 305U, 939U,  392U, 0x00000131U }, // field[291]
    { 962U, 392U,  305U, 0x000003e0U }, // field[292]
    { 392U, 305U, 1006U, 0x00000188U }, // field[293]
    { 305U, 1025U,  311U, 0x00000131U }, // field[294]
    { 1031U, 392U,  305U, 0x00000409U }, // field[295]
    {   1U, 306U,  624U, 0x00000132U }, // field[296]
    { 308U, 624U,    1U, 0x00000134U }, // field[297]
    { 647U, 393U,  308U, 0x00000295U }, // field[298]
    { 408U, 308U,  696U, 0x000001c8U }, // field[299]
    { 308U, 708U,  307U, 0x00000135U }, // field[300]
    { 624U, 309U,  309U, 0x00000287U }, // field[301]
    { 309U, 309U,  661U, 0x00000135U }, // field[302]
    { 314U, 624U,  314U, 0x0000013aU }, // field[303]
    { 647U, 314U,  314U, 0x00000295U }, // field[304]
    { 314U, 315U,  647U, 0x00000198U }, // field[305]
    { 315U, 661U,  408U, 0x0000013cU }, // field[306]
    { 624U, 403U,  319U, 0x00000270U }, // field[307]
    { 316U, 319U,  647U, 0x000001aaU }, // field[308]
    { 319U, 661U,  413U, 0x00000142U }, // field[309]
    { 624U, 322U,  323U, 0x00000270U }, // field[310]
    { 456U, 323U,  647U, 0x00000196U }, // field[311]
    { 323U, 661U,  212U, 0x00000143U }, // field[312]
    { 696U, 208U,  323U, 0x000002c4U }, // field[313]
    { 443U, 323U,  732U, 0x0000019dU }, // field[314]
    { 323U, 743U,  406U, 0x00000143U }, // field[315]
    { 801U, 406U,  323U, 0x0000032dU }, // field[316]
    { 403U, 323U,  848U, 0x00000198U }, // field[317]
    { 323U, 850U,  456U, 0x00000143U }, // field[318]
    { 852U, 406U,  323U, 0x00000364U }, // field[319]
    { 406U, 323U,  876U, 0x0000019dU }, // field[320]
    { 323U, 894U,  413U, 0x00000143U }, // field[321]
    { 902U,   1U,  324U, 0x00000270U }, // field[322]
    { 324U, 326U,  624U, 0x00000146U }, // field[323]
    { 331U, 647U,  330U, 0x00000164U }, // field[324]
    { 624U,   1U,  356U, 0x00000287U }, // field[325]
    { 408U, 356U,  661U, 0x00000189U }, // field[326]
    { 356U, 696U,  355U, 0x00000167U }, // field[327]
    { 624U, 393U,  359U, 0x0000032dU }, // field[328]
    { 359U, 361U,  735U, 0x00000196U }, // field[329]
    { 361U, 872U,  406U, 0x00000169U }, // field[330]
    { 952U,   1U,  361U, 0x000003caU }, // field[331]
    { 393U, 362U,  926U, 0x00000196U }, // field[332]
    { 364U, 624U,  363U, 0x0000016cU }, // field[333]
    { 647U, 364U,  364U, 0x00000295U }, // field[334]
    { 364U, 364U,  696U, 0x0000016cU }, // field[335]
    { 364U, 708U,  364U, 0x0000016cU }, // field[336]
    { 732U, 364U,  364U, 0x000002e7U }, // field[337]
    { 459U, 373U,  624U, 0x00000175U }, // field[338]
    { 374U, 624U,  374U, 0x0000017bU }, // field[339]
    { 624U, 379U,  381U, 0x00000037U }, // field[340]
    { 381U, 415U,  560U, 0x0000019fU }, // field[341]
    { 420U,  65U,  420U, 0x000001b3U }, // field[342]
    { 712U, 392U,  450U, 0x00000041U }, // field[343]
};

// ============================================================================
// 6. 594 METHOD DESCRIPTORS (.rodata 0x02d4c0..0x02f9e0)
//    BẢNG 594 BỘ MÔ TẢ PHƯƠNG THỨC (.rodata 0x02d4c0..0x02f9e0)
// ============================================================================

const LusterMethodDesc kLusterMethodDescriptors[kLusterMethodDescriptorCount] = {

    {   4U,   0U,   58U,   91U, 254U }, // method_desc[000]
    {   4U,   0U,  559U,   89U, 201U }, // method_desc[001]
    {   4U,   0U,  567U,  611U, 252U }, // method_desc[002]
    {   4U,   0U,  604U,   87U, 250U }, // method_desc[003]
    {   4U,   0U,  894U,  611U, 200U }, // method_desc[004]
    {   5U,   0U,  825U,  607U,  61U }, // method_desc[005]
    {   5U,   0U,  829U,  607U,  61U }, // method_desc[006]
    {   8U,   0U,  784U,   80U, 236U }, // method_desc[007]
    {   9U,   0U,  630U,  570U,  67U }, // method_desc[008]
    {   9U,   0U,  676U,  570U,  67U }, // method_desc[009]
    {  11U,   0U,  795U,   71U,  48U }, // method_desc[010]
    {  13U,   0U,  804U,  574U,  75U }, // method_desc[011]
    {  13U,   0U,  943U,  578U, 238U }, // method_desc[012]
    {  15U,   0U,  654U,   71U,  48U }, // method_desc[013]
    {  16U,   0U,  774U,   71U,  49U }, // method_desc[014]
    {  17U,   0U,  909U,   80U,  94U }, // method_desc[015]
    {  17U,   0U,  924U,   71U,   6U }, // method_desc[016]
    {  19U,   0U,  716U,  578U, 268U }, // method_desc[017]
    {  20U,   0U,  647U,  585U,  97U }, // method_desc[018]
    {  20U,   0U,  732U,  107U, 302U }, // method_desc[019]
    {  20U,   0U,  801U,  583U, 282U }, // method_desc[020]
    {  20U,   0U,  843U,  607U,  61U }, // method_desc[021]
    {  22U,   0U,  778U,   68U,   1U }, // method_desc[022]
    {  22U,   0U,  779U,   68U,   1U }, // method_desc[023]
    {  23U,   0U,  755U,   68U,   1U }, // method_desc[024]
    {  24U,   0U,  786U,   71U,   8U }, // method_desc[025]
    {  24U,   0U,  796U,   71U,   8U }, // method_desc[026]
    {  25U,   0U,  758U,  607U,  61U }, // method_desc[027]
    {  25U,   0U,  767U,   71U,  49U }, // method_desc[028]
    {  28U,   0U,  624U,   71U,   9U }, // method_desc[029]
    {  29U,   0U,   57U,   87U, 263U }, // method_desc[030]
    {  29U,   0U,   58U,  578U,  98U }, // method_desc[031]
    {  29U,   0U,  569U,  578U, 103U }, // method_desc[032]
    {  29U,   0U,  624U,  578U,  98U }, // method_desc[033]
    {  29U,   0U,  732U,   63U, 100U }, // method_desc[034]
    {  29U,   0U,  848U,   87U, 102U }, // method_desc[035]
    {  29U,   0U,  939U,   71U,   7U }, // method_desc[036]
    {  30U,   0U,   30U,  578U,  99U }, // method_desc[037]
    {  30U,   0U,  624U,   71U,  10U }, // method_desc[038]
    {  32U,   0U,  776U,   71U,  11U }, // method_desc[039]
    {  32U,   0U,  777U,   71U,  12U }, // method_desc[040]
    {  32U,   0U,  793U,   71U,  13U }, // method_desc[041]
    {  34U,   0U,  624U,  607U,  61U }, // method_desc[042]
    {  35U,   0U,  624U,  607U,  61U }, // method_desc[043]
    {  36U,   0U,  624U,  607U,  61U }, // method_desc[044]
    {  37U,   0U,  752U,   71U,  49U }, // method_desc[045]
    {  37U,   0U,  756U,   71U,  49U }, // method_desc[046]
    {  37U,   0U,  783U,   71U,  49U }, // method_desc[047]
    {  37U,   0U,  785U,   71U,  49U }, // method_desc[048]
    {  37U,   0U,  790U,   71U,  49U }, // method_desc[049]
    {  38U,   0U,  624U,   71U,  16U }, // method_desc[050]
    {  39U,   0U,  746U,   71U,  15U }, // method_desc[051]
    {  41U,   0U,  794U,   68U,   1U }, // method_desc[052]
    {  41U,   0U,  833U,  607U,  61U }, // method_desc[053]
    {  42U,   0U,  624U,   92U, 104U }, // method_desc[054]
    {  43U,   0U,  647U,  585U,  97U }, // method_desc[055]
    {  43U,   0U,  801U,  583U, 282U }, // method_desc[056]
    {  43U,   0U,  813U,  607U,  61U }, // method_desc[057]
    {  43U,   0U,  843U,  607U,  61U }, // method_desc[058]
    {  44U,   0U,  708U,  583U, 251U }, // method_desc[059]
    {  44U,   0U,  813U,  583U, 251U }, // method_desc[060]
    {  45U,   0U,  624U,  610U,  95U }, // method_desc[061]
    {  46U,   0U,  647U,  610U,  91U }, // method_desc[062]
    {  48U,   0U,  792U,   71U,  53U }, // method_desc[063]
    {  50U,   0U,  761U,   71U,  17U }, // method_desc[064]
    {  51U,   0U,  753U,   71U,  49U }, // method_desc[065]
    {  51U,   0U,  757U,   71U,  49U }, // method_desc[066]
    {  51U,   0U,  781U,   71U,  49U }, // method_desc[067]
    {  52U,   0U,   30U,  583U, 109U }, // method_desc[068]
    {  53U,   0U,   30U,  583U, 109U }, // method_desc[069]
    {  54U,   0U,   30U,  583U, 109U }, // method_desc[070]
    {  55U,   0U,   30U,  601U, 300U }, // method_desc[071]
    {  56U,   0U,   30U,  583U, 109U }, // method_desc[072]
    {  57U,   0U,   30U,  599U, 298U }, // method_desc[073]
    {  58U,   0U,   30U,  583U, 109U }, // method_desc[074]
    {  59U,   0U,   30U,  599U, 297U }, // method_desc[075]
    {  60U,   0U,   30U,  583U, 109U }, // method_desc[076]
    {  61U,   0U,   30U,  600U, 299U }, // method_desc[077]
    {  62U,   0U,  647U,   87U, 263U }, // method_desc[078]
    {  62U,   0U,  661U,   77U,  86U }, // method_desc[079]
    {  62U,   0U,  696U,   76U,  82U }, // method_desc[080]
    {  62U,   0U,  708U,   74U,  80U }, // method_desc[081]
    {  62U,   0U,  743U,   79U,  85U }, // method_desc[082]
    {  62U,   0U,  813U,   78U,  84U }, // method_desc[083]
    {  62U,   0U,  876U,  607U,  61U }, // method_desc[084]
    {  62U,   0U,  894U,   71U,  18U }, // method_desc[085]
    {  63U,   0U,  647U,   85U, 141U }, // method_desc[086]
    {  64U,   0U,   54U,   71U,  49U }, // method_desc[087]
    {  67U,   0U,   30U,  583U, 112U }, // method_desc[088]
    {  68U,   0U,   30U,  583U, 112U }, // method_desc[089]
    {  69U,   0U,   30U,  583U, 112U }, // method_desc[090]
    {  70U,   0U,   30U,  583U, 112U }, // method_desc[091]
    {  71U,   0U,   30U,  583U, 112U }, // method_desc[092]
    {  72U,   0U,   30U,  583U, 112U }, // method_desc[093]
    {  73U,   0U,   30U,  587U, 206U }, // method_desc[094]
    {  74U,   0U,   30U,  583U, 112U }, // method_desc[095]
    {  75U,   0U,   30U,  587U, 208U }, // method_desc[096]
    {  76U,   0U,   30U,  583U, 112U }, // method_desc[097]
    {  77U,   0U,   30U,  587U, 207U }, // method_desc[098]
    {  78U,   0U,   30U,  583U, 112U }, // method_desc[099]
    {  79U,   0U,   30U,  590U, 111U }, // method_desc[100]
    {  80U,   0U,  624U,   87U, 263U }, // method_desc[101]
    {  80U,   0U,  647U,   91U, 209U }, // method_desc[102]
    {  80U,   0U,  661U,   93U, 212U }, // method_desc[103]
    {  80U,   0U,  696U,   91U, 211U }, // method_desc[104]
    {  80U,   0U,  708U,   91U, 210U }, // method_desc[105]
    {  80U,   0U,  732U,   91U, 205U }, // method_desc[106]
    {  80U,   0U,  743U,   91U, 209U }, // method_desc[107]
    {  80U,   0U,  801U,   91U, 211U }, // method_desc[108]
    {  80U,   0U,  813U,   91U, 210U }, // method_desc[109]
    {  80U,   0U,  848U,   93U, 212U }, // method_desc[110]
    {  80U,   0U,  850U,  596U, 274U }, // method_desc[111]
    {  80U,   0U,  852U,  578U, 140U }, // method_desc[112]
    {  80U,   0U,  868U,  585U, 110U }, // method_desc[113]
    {  81U,   0U,   30U,  585U, 110U }, // method_desc[114]
    {  82U,   0U,   30U,  598U, 301U }, // method_desc[115]
    {  84U,   0U,   30U,  585U, 203U }, // method_desc[116]
    {  85U,   0U,   30U,  583U, 113U }, // method_desc[117]
    {  87U,   0U,  647U,   87U, 213U }, // method_desc[118]
    {  88U,   0U,   30U,  581U, 115U }, // method_desc[119]
    {  89U,   0U,   30U,  583U, 116U }, // method_desc[120]
    {  90U,   0U,   30U,  578U, 114U }, // method_desc[121]
    {  91U,   0U,   30U,  578U, 114U }, // method_desc[122]
    {  92U,   0U,  647U,   87U, 213U }, // method_desc[123]
    {  92U,   0U,  732U,  610U, 124U }, // method_desc[124]
    {  93U,   0U,   30U,  583U, 118U }, // method_desc[125]
    {  94U,   0U,   30U,  583U, 118U }, // method_desc[126]
    {  95U,   0U,   30U,  583U, 119U }, // method_desc[127]
    {  96U,   0U,   30U,  583U, 119U }, // method_desc[128]
    {  97U,   0U,   30U,  578U, 117U }, // method_desc[129]
    {  98U,   0U,   30U,  578U, 145U }, // method_desc[130]
    {  99U,   0U,  647U,   87U, 213U }, // method_desc[131]
    {  99U,   0U,  732U,  610U, 124U }, // method_desc[132]
    {  99U,   0U,  813U,   81U, 132U }, // method_desc[133]
    {  99U,   0U,  848U,   80U, 278U }, // method_desc[134]
    { 100U,   0U,   30U,  585U, 120U }, // method_desc[135]
    { 101U,   0U,  647U,   87U, 213U }, // method_desc[136]
    { 101U,   0U,  732U,  610U, 124U }, // method_desc[137]
    { 102U,   0U,   30U,  572U,  70U }, // method_desc[138]
    { 103U,   0U,   30U,  596U, 134U }, // method_desc[139]
    { 104U,   0U,  624U,  610U, 121U }, // method_desc[140]
    { 105U,   0U,  850U,  610U, 239U }, // method_desc[141]
    { 105U,   0U,  939U,  578U, 238U }, // method_desc[142]
    { 106U,   0U,  624U,  578U, 238U }, // method_desc[143]
    { 106U,   0U,  647U,   80U, 236U }, // method_desc[144]
    { 108U,   0U,  685U,   80U, 127U }, // method_desc[145]
    { 108U,   0U,  686U,   80U, 129U }, // method_desc[146]
    { 108U,   0U,  687U,   80U, 128U }, // method_desc[147]
    { 108U,   0U,  688U,   80U, 131U }, // method_desc[148]
    { 110U,   0U,  563U,   71U,  19U }, // method_desc[149]
    { 114U,   0U,  624U,  578U, 123U }, // method_desc[150]
    { 114U,   0U,  696U,   71U,  21U }, // method_desc[151]
    { 114U,   0U,  732U,  610U, 124U }, // method_desc[152]
    { 118U,   0U,  624U,   80U, 230U }, // method_desc[153]
    { 118U,   0U,  647U,   80U, 122U }, // method_desc[154]
    { 119U,   0U,   30U,  578U, 220U }, // method_desc[155]
    { 121U,   0U,  624U,   80U, 292U }, // method_desc[156]
    { 122U,   0U,  624U,   97U, 126U }, // method_desc[157]
    { 122U,   0U,  647U,   86U, 125U }, // method_desc[158]
    { 123U,   0U,  732U,   71U,   5U }, // method_desc[159]
    { 123U,   0U,  801U,   71U,   5U }, // method_desc[160]
    { 123U,   0U,  852U,   71U,   4U }, // method_desc[161]
    { 123U,   0U,  876U,  607U,  61U }, // method_desc[162]
    { 124U,   0U,  848U,   71U,  59U }, // method_desc[163]
    { 125U,   0U,  919U,   71U,  49U }, // method_desc[164]
    { 125U,   0U, 1007U,   71U,  20U }, // method_desc[165]
    { 126U,   0U,   30U,  590U, 257U }, // method_desc[166]
    { 126U,   0U,  624U,   71U,  49U }, // method_desc[167]
    { 127U,   0U,   30U,  581U, 130U }, // method_desc[168]
    { 127U,   0U,  773U,   71U,  22U }, // method_desc[169]
    { 128U,   0U,   30U,  588U, 256U }, // method_desc[170]
    { 129U,   0U,   30U,  585U, 255U }, // method_desc[171]
    { 130U,   0U,  624U,   71U,  54U }, // method_desc[172]
    { 130U,   0U,  647U,   71U,  24U }, // method_desc[173]
    { 131U,   0U,   30U,  589U, 260U }, // method_desc[174]
    { 132U,   0U,   30U,  581U, 130U }, // method_desc[175]
    { 132U,   0U,  765U,   71U,  22U }, // method_desc[176]
    { 133U,   0U,   30U,  581U, 133U }, // method_desc[177]
    { 133U,   0U,  624U,   71U,  24U }, // method_desc[178]
    { 135U,   0U,  647U,   59U,   0U }, // method_desc[179]
    { 136U,   0U,   30U,  582U, 244U }, // method_desc[180]
    { 136U,   0U,  624U,   59U,   0U }, // method_desc[181]
    { 136U,   0U,  647U,   71U,  23U }, // method_desc[182]
    { 136U,   0U,  661U,   71U,  49U }, // method_desc[183]
    { 137U,   0U,   30U,  578U, 273U }, // method_desc[184]
    { 138U,   0U,  624U,   59U,   0U }, // method_desc[185]
    { 141U,   0U,  661U,  592U, 137U }, // method_desc[186]
    { 141U,   0U,  732U,  583U, 139U }, // method_desc[187]
    { 142U,   0U, 1026U,   71U,  14U }, // method_desc[188]
    { 143U,   0U,  661U,  607U,  61U }, // method_desc[189]
    { 143U,   0U,  696U,  607U,  61U }, // method_desc[190]
    { 145U,   0U,  647U,   71U,  32U }, // method_desc[191]
    { 146U,   0U,  812U,   71U,  27U }, // method_desc[192]
    { 147U,   0U,  701U,   71U,  28U }, // method_desc[193]
    { 148U,   0U,  764U,   87U, 286U }, // method_desc[194]
    { 149U,   0U,  759U,  607U,  61U }, // method_desc[195]
    { 151U,   0U,  780U,   80U, 198U }, // method_desc[196]
    { 151U,   0U,  835U,  610U, 239U }, // method_desc[197]
    { 151U,   0U,  964U,   80U, 236U }, // method_desc[198]
    { 151U,   0U,  981U,   80U, 215U }, // method_desc[199]
    { 152U,   0U,  743U,  595U, 293U }, // method_desc[200]
    { 153U,   0U,  894U,  583U,  93U }, // method_desc[201]
    { 154U,   0U,   30U,  586U, 253U }, // method_desc[202]
    { 154U,   0U,  751U,   71U,  48U }, // method_desc[203]
    { 154U,   0U,  782U,   71U,  49U }, // method_desc[204]
    { 154U,   0U,  958U,  607U,  61U }, // method_desc[205]
    { 155U,   0U,  782U,   71U,  49U }, // method_desc[206]
    { 156U,   0U,  771U,   71U,  53U }, // method_desc[207]
    { 157U,   0U,  902U,  611U, 252U }, // method_desc[208]
    { 158U,   0U,  732U,   71U,   2U }, // method_desc[209]
    { 159U,   0U,  647U,   72U,  65U }, // method_desc[210]
    { 161U,   0U,  647U,   80U, 142U }, // method_desc[211]
    { 162U,   0U,  750U,   71U,  29U }, // method_desc[212]
    { 162U,   0U,  754U,  607U,  61U }, // method_desc[213]
    { 162U,   0U,  775U,   80U, 231U }, // method_desc[214]
    { 162U,   0U,  787U,   59U,   0U }, // method_desc[215]
    { 162U,   0U,  791U,   71U,  46U }, // method_desc[216]
    { 162U,   0U,  806U,  610U, 239U }, // method_desc[217]
    { 162U,   0U,  809U,  610U, 239U }, // method_desc[218]
    { 162U,   0U,  831U,  607U,  61U }, // method_desc[219]
    { 162U,   0U,  837U,  607U,  61U }, // method_desc[220]
    { 162U,   0U,  838U,  607U,  61U }, // method_desc[221]
    { 162U,   0U,  839U,  607U,  61U }, // method_desc[222]
    { 162U,   0U,  840U,  607U,  61U }, // method_desc[223]
    { 162U,   0U,  841U,  607U,  61U }, // method_desc[224]
    { 162U,   0U, 1001U,   68U,   1U }, // method_desc[225]
    { 166U,   0U,  647U,   68U,   1U }, // method_desc[226]
    { 166U,   0U,  696U,   71U,  49U }, // method_desc[227]
    { 166U,   0U,  708U,  607U,  61U }, // method_desc[228]
    { 166U,   0U,  732U,   71U,  49U }, // method_desc[229]
    { 166U,   0U,  743U,   71U,  49U }, // method_desc[230]
    { 167U,   0U,  624U,  609U,  68U }, // method_desc[231]
    { 171U,   0U,  895U,   71U,  49U }, // method_desc[232]
    { 172U,   0U,  624U,   80U, 136U }, // method_desc[233]
    { 173U,   0U,  624U,   71U,  59U }, // method_desc[234]
    { 173U,   0U,  732U,   71U,  41U }, // method_desc[235]
    { 173U,   0U,  743U,  607U,  61U }, // method_desc[236]
    { 175U,   0U,  647U,  593U, 143U }, // method_desc[237]
    { 177U,   0U,   43U,   71U,  42U }, // method_desc[238]
    { 178U,   0U,  822U,   71U,  48U }, // method_desc[239]
    { 179U,   0U,  853U,   71U,  30U }, // method_desc[240]
    { 179U,   0U,  869U,   71U,  25U }, // method_desc[241]
    { 179U,   0U,  903U,   71U,  26U }, // method_desc[242]
    { 179U,   0U,  918U,   71U,  44U }, // method_desc[243]
    { 179U,   0U,  940U,   71U,  31U }, // method_desc[244]
    { 181U,   0U,   30U,  583U, 269U }, // method_desc[245]
    { 182U,   0U,   30U,  583U, 144U }, // method_desc[246]
    { 183U,   0U,   66U,   80U, 135U }, // method_desc[247]
    { 183U,   0U,  607U,  578U, 281U }, // method_desc[248]
    { 188U,   0U,   39U,   61U, 105U }, // method_desc[249]
    { 189U,   0U,  624U,   72U,  63U }, // method_desc[250]
    { 190U,   0U,  565U,   87U, 250U }, // method_desc[251]
    { 190U,   0U,  647U,   96U, 108U }, // method_desc[252]
    { 190U,   0U,  802U,  610U, 107U }, // method_desc[253]
    { 190U,   0U,  916U,   80U, 106U }, // method_desc[254]
    { 192U,   0U,  762U,   71U,  47U }, // method_desc[255]
    { 193U,   0U,  747U,   71U,   3U }, // method_desc[256]
    { 195U,   0U,  708U,  575U,  83U }, // method_desc[257]
    { 196U,   0U,  789U,   71U,  50U }, // method_desc[258]
    { 197U,   0U,  708U,  607U,  61U }, // method_desc[259]
    { 199U,   0U,  902U,  595U, 261U }, // method_desc[260]
    { 201U,   0U,   30U,  578U, 279U }, // method_desc[261]
    { 202U,   0U,   30U,  583U, 264U }, // method_desc[262]
    { 203U,   0U,   30U,  578U, 146U }, // method_desc[263]
    { 204U,   0U,  624U,   80U, 236U }, // method_desc[264]
    { 204U,   0U,  647U,  610U, 239U }, // method_desc[265]
    { 204U,   0U,  661U,  570U,  67U }, // method_desc[266]
    { 204U,   0U,  696U,  578U, 238U }, // method_desc[267]
    { 204U,   0U,  821U,   80U,  96U }, // method_desc[268]
    { 205U,   0U,  708U,  583U, 251U }, // method_desc[269]
    { 205U,   0U,  708U,  585U, 259U }, // method_desc[270]
    { 205U,   0U,  813U,  583U, 251U }, // method_desc[271]
    { 205U,   0U,  908U,  583U, 262U }, // method_desc[272]
    { 206U,   0U,  647U,   87U, 147U }, // method_desc[273]
    { 206U,   0U,  708U,  583U, 148U }, // method_desc[274]
    { 207U,   0U,  709U,   71U,  49U }, // method_desc[275]
    { 207U,   0U, 1031U,   71U,  49U }, // method_desc[276]
    { 209U,   0U,   30U,  569U,  60U }, // method_desc[277]
    { 209U,   0U,  696U,   69U, 151U }, // method_desc[278]
    { 209U,   0U,  708U,   71U,  49U }, // method_desc[279]
    { 209U,   0U,  732U,   71U,  49U }, // method_desc[280]
    { 209U,   0U,  813U,   71U,  35U }, // method_desc[281]
    { 209U,   0U,  852U,   71U,  33U }, // method_desc[282]
    { 209U,   0U,  868U,  578U, 238U }, // method_desc[283]
    { 210U,   0U,   34U,  577U,  77U }, // method_desc[284]
    { 210U,   0U,   35U,  577U,  77U }, // method_desc[285]
    { 210U,   0U,   36U,  577U,  77U }, // method_desc[286]
    { 210U,   0U,   37U,  577U,  77U }, // method_desc[287]
    { 210U,   0U,   38U,  576U,  76U }, // method_desc[288]
    { 211U,   0U,  876U,   71U,  33U }, // method_desc[289]
    { 212U,   0U,  647U,   71U,  34U }, // method_desc[290]
    { 212U,   0U,  661U,   71U,  35U }, // method_desc[291]
    { 213U,   0U,   42U,   60U,  78U }, // method_desc[292]
    { 218U,   0U,  624U,  578U, 153U }, // method_desc[293]
    { 220U,   0U,  647U,  585U,  97U }, // method_desc[294]
    { 220U,   0U,  732U,  107U, 302U }, // method_desc[295]
    { 220U,   0U,  801U,  583U, 282U }, // method_desc[296]
    { 220U,   0U,  843U,  607U,  61U }, // method_desc[297]
    { 221U,   0U,  647U,  585U,  97U }, // method_desc[298]
    { 221U,   0U,  732U,  107U, 302U }, // method_desc[299]
    { 221U,   0U,  801U,  583U, 282U }, // method_desc[300]
    { 223U,   0U,  624U,   80U, 157U }, // method_desc[301]
    { 225U,   0U,  647U,  585U,  97U }, // method_desc[302]
    { 225U,   0U,  743U,  607U,  61U }, // method_desc[303]
    { 225U,   0U,  850U,  569U,  60U }, // method_desc[304]
    { 225U,   0U,  916U,  107U, 302U }, // method_desc[305]
    { 226U,   0U,  647U,   71U,  49U }, // method_desc[306]
    { 226U,   0U,  661U,  607U,  61U }, // method_desc[307]
    { 226U,   0U,  708U,   71U,  36U }, // method_desc[308]
    { 226U,   0U,  732U,  607U,  61U }, // method_desc[309]
    { 227U,   0U,  758U,  607U,  61U }, // method_desc[310]
    { 229U,   0U,   30U,  583U, 158U }, // method_desc[311]
    { 230U,   0U,   30U,  583U, 158U }, // method_desc[312]
    { 231U,   0U,   30U,  583U, 158U }, // method_desc[313]
    { 232U,   0U,  708U,  103U, 187U }, // method_desc[314]
    { 234U,   0U,   30U,  597U, 159U }, // method_desc[315]
    { 235U,   0U,  708U,  103U, 187U }, // method_desc[316]
    { 237U,   0U,   30U,  583U, 160U }, // method_desc[317]
    { 238U,   0U,   30U,  578U, 287U }, // method_desc[318]
    { 239U,   0U,  708U,  103U, 187U }, // method_desc[319]
    { 240U,   0U,   30U,  583U, 161U }, // method_desc[320]
    { 241U,   0U,   30U,  583U, 162U }, // method_desc[321]
    { 242U,   0U,   30U,  583U, 162U }, // method_desc[322]
    { 243U,   0U,   30U,  583U, 162U }, // method_desc[323]
    { 244U,   0U,  708U,  103U, 187U }, // method_desc[324]
    { 244U,   0U,  743U,   91U, 184U }, // method_desc[325]
    { 245U,   0U,   30U,  583U, 163U }, // method_desc[326]
    { 246U,   0U,   30U,  583U, 163U }, // method_desc[327]
    { 247U,   0U,   30U,  583U, 163U }, // method_desc[328]
    { 248U,   0U,  708U,  103U, 187U }, // method_desc[329]
    { 248U,   0U,  868U,   80U, 278U }, // method_desc[330]
    { 248U,   0U,  876U,   80U, 278U }, // method_desc[331]
    { 249U,   0U,   30U,  585U, 164U }, // method_desc[332]
    { 250U,   0U,  708U,  103U, 187U }, // method_desc[333]
    { 250U,   0U,  850U,   87U, 186U }, // method_desc[334]
    { 251U,   0U,   30U,  585U, 165U }, // method_desc[335]
    { 252U,   0U,  708U,  103U, 187U }, // method_desc[336]
    { 252U,   0U,  850U,   87U, 186U }, // method_desc[337]
    { 253U,   0U,   30U,  584U, 166U }, // method_desc[338]
    { 254U,   0U,   30U,  583U, 167U }, // method_desc[339]
    { 255U,   0U,  708U,  103U, 187U }, // method_desc[340]
    { 255U,   0U,  850U,  100U, 182U }, // method_desc[341]
    { 257U,   0U,   30U,  583U, 169U }, // method_desc[342]
    { 258U,   0U,   30U,  583U, 169U }, // method_desc[343]
    { 259U,   0U,   30U,  596U, 288U }, // method_desc[344]
    { 260U,   0U,   30U,  578U, 287U }, // method_desc[345]
    { 261U,   0U,   30U,  596U, 288U }, // method_desc[346]
    { 262U,   0U,   30U,  578U, 287U }, // method_desc[347]
    { 263U,   0U,   30U,  583U, 169U }, // method_desc[348]
    { 264U,   0U,   30U,  583U, 169U }, // method_desc[349]
    { 265U,   0U,   30U,  578U, 168U }, // method_desc[350]
    { 266U,   0U,   30U,  578U, 287U }, // method_desc[351]
    { 267U,   0U,   30U,  578U, 287U }, // method_desc[352]
    { 268U,   0U,  708U,  103U, 187U }, // method_desc[353]
    { 268U,   0U,  732U,   91U, 184U }, // method_desc[354]
    { 268U,   0U,  813U,  607U,  61U }, // method_desc[355]
    { 268U,   0U,  848U,   90U, 183U }, // method_desc[356]
    { 271U,   0U,  708U,  103U, 187U }, // method_desc[357]
    { 272U,   0U,   30U,  583U, 171U }, // method_desc[358]
    { 273U,   0U,   30U,  578U, 170U }, // method_desc[359]
    { 274U,   0U,   30U,  578U, 287U }, // method_desc[360]
    { 275U,   0U,   30U,  578U, 287U }, // method_desc[361]
    { 276U,   0U,   30U,  578U, 170U }, // method_desc[362]
    { 277U,   0U,   30U,  583U, 171U }, // method_desc[363]
    { 278U,   0U,  708U,  103U, 187U }, // method_desc[364]
    { 280U,   0U,   30U,  583U, 173U }, // method_desc[365]
    { 281U,   0U,   30U,  583U, 174U }, // method_desc[366]
    { 282U,   0U,   30U,  583U, 173U }, // method_desc[367]
    { 283U,   0U,   30U,  583U, 174U }, // method_desc[368]
    { 284U,   0U,   30U,  583U, 174U }, // method_desc[369]
    { 285U,   0U,   30U,  583U, 174U }, // method_desc[370]
    { 286U,   0U,   30U,  583U, 174U }, // method_desc[371]
    { 287U,   0U,  732U,   91U, 184U }, // method_desc[372]
    { 287U,   0U,  813U,   91U, 172U }, // method_desc[373]
    { 287U,   0U,  848U,   71U,  37U }, // method_desc[374]
    { 287U,   0U,  852U,   87U, 101U }, // method_desc[375]
    { 291U,   0U,  732U,   71U,  38U }, // method_desc[376]
    { 292U,   0U,  661U,   80U, 232U }, // method_desc[377]
    { 292U,   0U,  894U,   96U, 138U }, // method_desc[378]
    { 292U,   0U,  902U,   75U,  79U }, // method_desc[379]
    { 293U,   0U,  624U,   59U,   0U }, // method_desc[380]
    { 294U,   0U,  647U,  583U, 175U }, // method_desc[381]
    { 295U,   0U,  624U,   80U, 278U }, // method_desc[382]
    { 296U,   0U,   30U,  587U, 176U }, // method_desc[383]
    { 297U,   0U,  870U,   87U, 191U }, // method_desc[384]
    { 298U,   0U,   30U,  587U, 192U }, // method_desc[385]
    { 299U,   0U,  870U,   87U, 193U }, // method_desc[386]
    { 300U,   0U,  902U,   93U, 258U }, // method_desc[387]
    { 301U,   0U,  661U,  607U,  61U }, // method_desc[388]
    { 301U,   0U,  732U,  607U,  61U }, // method_desc[389]
    { 305U,   0U,   30U,  583U, 177U }, // method_desc[390]
    { 306U,   0U,  624U,   93U, 185U }, // method_desc[391]
    { 307U,   0U,  624U,   88U, 179U }, // method_desc[392]
    { 307U,   0U,  647U,   83U, 178U }, // method_desc[393]
    { 307U,   0U,  661U,  101U, 180U }, // method_desc[394]
    { 310U,   0U,  624U,   80U, 235U }, // method_desc[395]
    { 311U,   0U,  624U,  578U, 181U }, // method_desc[396]
    { 311U,   0U,  647U,  578U, 181U }, // method_desc[397]
    { 311U,   0U,  661U,   87U, 186U }, // method_desc[398]
    { 311U,   0U,  770U,   71U,  49U }, // method_desc[399]
    { 312U,   0U,  624U,   80U, 188U }, // method_desc[400]
    { 313U,   0U,   30U,  596U, 189U }, // method_desc[401]
    { 318U,   0U,   30U,  584U, 190U }, // method_desc[402]
    { 319U,   0U,  564U,   87U, 194U }, // method_desc[403]
    { 320U,   0U,   30U,  583U, 284U }, // method_desc[404]
    { 321U,   0U,  564U,   87U, 194U }, // method_desc[405]
    { 321U,   0U,  854U,   87U, 194U }, // method_desc[406]
    { 322U,   0U,  696U,  578U, 238U }, // method_desc[407]
    { 323U,   0U,   50U,   71U,  53U }, // method_desc[408]
    { 323U,   0U,   68U,  578U, 238U }, // method_desc[409]
    { 323U,   0U,  563U,  595U, 155U }, // method_desc[410]
    { 323U,   0U,  902U,  106U, 296U }, // method_desc[411]
    { 323U,   0U,  917U,  578U, 152U }, // method_desc[412]
    { 324U,   0U,  624U,  577U,  81U }, // method_desc[413]
    { 325U,   0U,  624U,   71U,   2U }, // method_desc[414]
    { 326U,   0U,  624U,   93U, 247U }, // method_desc[415]
    { 327U,   0U,  624U,   99U, 197U }, // method_desc[416]
    { 327U,   0U,  647U,   91U, 196U }, // method_desc[417]
    { 328U,   0U,  624U,  590U,  88U }, // method_desc[418]
    { 329U,   0U,   30U,  583U, 276U }, // method_desc[419]
    { 330U,   0U,  624U,   93U, 265U }, // method_desc[420]
    { 332U,   0U,  624U,  591U,  87U }, // method_desc[421]
    { 333U,   0U,   30U,  580U, 243U }, // method_desc[422]
    { 334U,   0U,  743U,   98U, 149U }, // method_desc[423]
    { 335U,   0U,  624U,  607U,  61U }, // method_desc[424]
    { 335U,   0U,  647U,   59U,   0U }, // method_desc[425]
    { 336U,   0U,  661U,   59U,   0U }, // method_desc[426]
    { 336U,   0U,  696U,   59U,   0U }, // method_desc[427]
    { 337U,   0U,  661U,  607U,  61U }, // method_desc[428]
    { 337U,   0U,  696U,   71U,  39U }, // method_desc[429]
    { 337U,   0U,  708U,  607U,  61U }, // method_desc[430]
    { 338U,   0U,  624U,  607U,  61U }, // method_desc[431]
    { 338U,   0U,  647U,   71U,  49U }, // method_desc[432]
    { 340U,   0U,  848U,   71U,  40U }, // method_desc[433]
    { 341U,   0U,  624U,  607U,  61U }, // method_desc[434]
    { 346U,   0U,   59U,   71U,  59U }, // method_desc[435]
    { 347U,   0U,  625U,  607U,  61U }, // method_desc[436]
    { 348U,   0U,  663U,  607U,  61U }, // method_desc[437]
    { 350U,   0U,   30U,  594U, 150U }, // method_desc[438]
    { 351U,   0U,  647U,  610U, 154U }, // method_desc[439]
    { 353U,   0U,  564U,   87U, 194U }, // method_desc[440]
    { 353U,   0U,  770U,   71U,  49U }, // method_desc[441]
    { 355U,   0U,  647U,   83U, 195U }, // method_desc[442]
    { 356U,   0U,   30U,  573U,  71U }, // method_desc[443]
    { 356U,   0U,  624U,  578U, 283U }, // method_desc[444]
    { 356U,   0U,  647U,  578U, 283U }, // method_desc[445]
    { 356U,   0U,  661U,  578U, 283U }, // method_desc[446]
    { 356U,   0U,  696U,  578U, 283U }, // method_desc[447]
    { 356U,   0U,  708U,  578U, 283U }, // method_desc[448]
    { 356U,   0U,  732U,   87U, 285U }, // method_desc[449]
    { 357U,   0U,  708U,   80U, 272U }, // method_desc[450]
    { 358U,   0U,  696U,  610U, 156U }, // method_desc[451]
    { 359U,   0U, 1009U,   71U,  62U }, // method_desc[452]
    { 360U,   0U,   50U,   71U,  53U }, // method_desc[453]
    { 360U,   0U,   54U,  578U, 273U }, // method_desc[454]
    { 360U,   0U,  902U,  106U, 296U }, // method_desc[455]
    { 360U,   0U,  917U,  578U, 152U }, // method_desc[456]
    { 361U,   0U,  624U,   71U,  49U }, // method_desc[457]
    { 362U,   0U,  624U,   71U,  53U }, // method_desc[458]
    { 364U,   0U,  647U,  607U,  61U }, // method_desc[459]
    { 364U,   0U,  661U,  607U,  61U }, // method_desc[460]
    { 365U,   0U,  917U,   80U, 233U }, // method_desc[461]
    { 366U,   0U,  624U,   71U,  43U }, // method_desc[462]
    { 366U,   0U,  843U,  607U,  61U }, // method_desc[463]
    { 367U,   0U,   30U,  569U,  60U }, // method_desc[464]
    { 367U,   0U,  624U,  583U, 226U }, // method_desc[465]
    { 368U,   0U,  624U,  613U,  89U }, // method_desc[466]
    { 368U,   0U,  647U,  612U,  90U }, // method_desc[467]
    { 369U,   0U,   30U,  569U,  60U }, // method_desc[468]
    { 369U,   0U,  624U,  583U, 251U }, // method_desc[469]
    { 369U,   0U,  647U,  578U, 275U }, // method_desc[470]
    { 370U,   0U,  624U,  569U,  60U }, // method_desc[471]
    { 372U,   0U,  702U,  569U,  60U }, // method_desc[472]
    { 373U,   0U,  624U,  607U,  61U }, // method_desc[473]
    { 375U,   0U,  696U,  571U,  69U }, // method_desc[474]
    { 375U,   0U,  708U,  579U, 242U }, // method_desc[475]
    { 376U,   0U,  624U,  596U,  92U }, // method_desc[476]
    { 377U,   0U,  624U,   85U, 290U }, // method_desc[477]
    { 378U,   0U,  624U,  607U,  61U }, // method_desc[478]
    { 379U,   0U,  732U,  607U,  61U }, // method_desc[479]
    { 379U,   0U,  743U,  607U,  61U }, // method_desc[480]
    { 379U,   0U,  801U,  607U,  61U }, // method_desc[481]
    { 381U,   0U,  655U,  607U,  61U }, // method_desc[482]
    { 381U,   0U, 1008U,  106U, 294U }, // method_desc[483]
    { 384U,   0U,  901U,   59U,   0U }, // method_desc[484]
    { 386U,   0U,   30U,  578U, 238U }, // method_desc[485]
    { 387U,   0U,  818U,   59U,   0U }, // method_desc[486]
    { 387U,   0U,  905U,   61U, 228U }, // method_desc[487]
    { 387U,   0U,  983U,   71U,  49U }, // method_desc[488]
    { 387U,   0U, 1008U,   72U,  64U }, // method_desc[489]
    { 388U,   0U,  846U,   71U,  52U }, // method_desc[490]
    { 389U,   0U,  867U,   68U,   1U }, // method_desc[491]
    { 389U,   0U, 1008U,   73U,  72U }, // method_desc[492]
    { 390U,   0U,   30U,  578U, 238U }, // method_desc[493]
    { 392U,   0U,  749U,   71U,  45U }, // method_desc[494]
    { 393U,   0U,  721U,  610U, 221U }, // method_desc[495]
    { 393U,   0U,  810U,   59U,   0U }, // method_desc[496]
    { 393U,   0U,  863U,   59U,   0U }, // method_desc[497]
    { 393U,   0U, 1008U,   72U,  65U }, // method_desc[498]
    { 393U,   0U, 1008U,   73U,  73U }, // method_desc[499]
    { 393U,   0U, 1008U,   80U, 215U }, // method_desc[500]
    { 394U,   0U,   30U,  569U,  60U }, // method_desc[501]
    { 394U,   0U,   30U,  578U, 238U }, // method_desc[502]
    { 394U,   0U,  642U,   72U,  66U }, // method_desc[503]
    { 394U,   0U,  642U,   73U,  74U }, // method_desc[504]
    { 394U,   0U,  642U,   80U, 216U }, // method_desc[505]
    { 394U,   0U,  642U,   80U, 237U }, // method_desc[506]
    { 394U,   0U,  642U,  106U, 295U }, // method_desc[507]
    { 394U,   0U,  983U,   71U,  49U }, // method_desc[508]
    { 395U,   0U,  694U,   68U,   1U }, // method_desc[509]
    { 396U,   0U,  769U,   71U,  49U }, // method_desc[510]
    { 397U,   0U,  745U,   71U,  48U }, // method_desc[511]
    { 398U,   0U,   30U,  578U, 220U }, // method_desc[512]
    { 399U,   0U,  741U,   80U, 215U }, // method_desc[513]
    { 401U,   0U,   30U,  569U,  60U }, // method_desc[514]
    { 401U,   0U,   30U,  570U,  67U }, // method_desc[515]
    { 401U,   0U,  628U,  610U, 221U }, // method_desc[516]
    { 401U,   0U,  681U,  610U, 221U }, // method_desc[517]
    { 401U,   0U,  827U,  607U,  61U }, // method_desc[518]
    { 402U,   0U,  827U,  607U,  61U }, // method_desc[519]
    { 403U,   0U,  682U,  610U, 221U }, // method_desc[520]
    { 403U,   0U,  719U,   71U,  55U }, // method_desc[521]
    { 403U,   0U,  745U,   80U, 214U }, // method_desc[522]
    { 403U,   0U,  914U,   87U, 222U }, // method_desc[523]
    { 403U,   0U, 1009U,   71U,  51U }, // method_desc[524]
    { 404U,   0U,  808U,  607U,  61U }, // method_desc[525]
    { 404U,   0U,  881U,   71U,  48U }, // method_desc[526]
    { 405U,   0U,   30U,  569U,  60U }, // method_desc[527]
    { 405U,   0U,  745U,   80U, 214U }, // method_desc[528]
    { 406U,   0U,  629U,  610U, 270U }, // method_desc[529]
    { 406U,   0U,  681U,  610U, 221U }, // method_desc[530]
    { 406U,   0U,  827U,  607U,  61U }, // method_desc[531]
    { 406U,   0U,  846U,   71U,  52U }, // method_desc[532]
    { 407U,   0U,  766U,   71U,  48U }, // method_desc[533]
    { 407U,   0U,  795U,   71U,  48U }, // method_desc[534]
    { 408U,   0U,  745U,   80U, 214U }, // method_desc[535]
    { 408U,   0U,  914U,   87U, 222U }, // method_desc[536]
    { 408U,   0U,  915U,  578U, 275U }, // method_desc[537]
    { 409U,   0U,  983U,   80U, 215U }, // method_desc[538]
    { 410U,   0U,  846U,   71U,  52U }, // method_desc[539]
    { 411U,   0U,  920U,   71U,  56U }, // method_desc[540]
    { 411U,   0U,  983U,   71U,  49U }, // method_desc[541]
    { 413U,   0U,  795U,   71U,  48U }, // method_desc[542]
    { 414U,   0U,  862U,   87U, 277U }, // method_desc[543]
    { 417U,   0U,  680U,   80U, 214U }, // method_desc[544]
    { 417U,   0U,  723U,   80U, 217U }, // method_desc[545]
    { 417U,   0U,  828U,  610U, 221U }, // method_desc[546]
    { 418U,   0U,  683U,   80U, 267U }, // method_desc[547]
    { 418U,   0U,  979U,  578U, 220U }, // method_desc[548]
    { 419U,   0U,  980U,   87U, 223U }, // method_desc[549]
    { 421U,   0U,  848U,   95U, 204U }, // method_desc[550]
    { 422U,   0U,  865U,   80U, 218U }, // method_desc[551]
    { 423U,   0U,  738U,   80U, 271U }, // method_desc[552]
    { 423U,   0U,  739U,   80U, 271U }, // method_desc[553]
    { 424U,   0U,  875U,   80U, 303U }, // method_desc[554]
    { 427U,   0U,  748U,   71U,  48U }, // method_desc[555]
    { 428U,   0U,  656U,   72U,  64U }, // method_desc[556]
    { 428U,   0U,  657U,   73U,  72U }, // method_desc[557]
    { 429U,   0U,  822U,   71U,  48U }, // method_desc[558]
    { 430U,   0U,  822U,   80U, 214U }, // method_desc[559]
    { 431U,   0U,  822U,   87U, 222U }, // method_desc[560]
    { 432U,   0U,  822U,   91U, 225U }, // method_desc[561]
    { 434U,   0U,  643U,  611U, 224U }, // method_desc[562]
    { 434U,   0U,  670U,  578U, 220U }, // method_desc[563]
    { 434U,   0U,  671U,  583U, 226U }, // method_desc[564]
    { 434U,   0U,  672U,  583U, 226U }, // method_desc[565]
    { 435U,   0U,   30U,  569U,  60U }, // method_desc[566]
    { 436U,   0U,  772U,   80U, 202U }, // method_desc[567]
    { 437U,   0U,  944U,  585U, 227U }, // method_desc[568]
    { 440U,   0U,  982U,   80U, 234U }, // method_desc[569]
    { 441U,   0U,  823U,  610U, 199U }, // method_desc[570]
    { 441U,   0U,  923U,   87U, 248U }, // method_desc[571]
    { 442U,   0U,  858U,   94U, 289U }, // method_desc[572]
    { 442U,   0U, 1028U,   91U, 280U }, // method_desc[573]
    { 444U,   0U,   45U,   82U, 291U }, // method_desc[574]
    { 448U,   0U,  645U,   80U, 278U }, // method_desc[575]
    { 449U,   0U,  760U,   71U,  57U }, // method_desc[576]
    { 449U,   0U,  768U,   71U,  58U }, // method_desc[577]
    { 452U,   0U,  763U,   71U,  58U }, // method_desc[578]
    { 453U,   0U,   30U,  569U,  60U }, // method_desc[579]
    { 453U,   0U,   30U,  578U, 238U }, // method_desc[580]
    { 453U,   0U,  914U,   80U, 219U }, // method_desc[581]
    { 454U,   0U,   30U,  569U,  60U }, // method_desc[582]
    { 454U,   0U,   30U,  578U, 238U }, // method_desc[583]
    { 454U,   0U,  805U,  610U, 239U }, // method_desc[584]
    { 454U,   0U,  898U,   62U, 240U }, // method_desc[585]
    { 454U,   0U,  899U,   69U, 229U }, // method_desc[586]
    { 454U,   0U,  899U,   70U, 245U }, // method_desc[587]
    { 454U,   0U,  900U,   80U, 236U }, // method_desc[588]
    { 454U,   0U,  914U,   81U, 241U }, // method_desc[589]
    { 454U,   0U,  914U,   84U, 246U }, // method_desc[590]
    { 454U,   0U,  914U,   87U, 249U }, // method_desc[591]
    { 454U,   0U,  914U,  102U, 266U }, // method_desc[592]
    { 454U,   0U,  983U,   71U,  49U }, // method_desc[593]
};

// ============================================================================
// 7. 109 TERRAIN VM BYTECODE UNITS (.data 0x040718..0x040a78 -> .rodata 0x030246..0x0365e4)
//    BẢNG 109 ĐƠN VỊ MÃ BYTE TERRAIN VM (.data 0x040718..0x040a78 -> .rodata 0x030246..0x0365e4)
// ============================================================================

const LusterBytecodeUnitInfo kLusterBytecodeUnits[kLusterBytecodeUnitCount] = {

    {   0U, 0x40718ULL, 0x670b9eULL, 0x30246ULL, { 0xac, 0x00, 0x00, 0x00, 0x48, 0x20, 0x35, 0x02, 0x03, 0x00, 0x48, 0x20, 0x35, 0x02, 0x04, 0x00 } },
    {   1U, 0x40720ULL, 0x670bbaULL, 0x30262ULL, { 0xc9, 0x00, 0x04, 0x00, 0xa1, 0x71, 0x14, 0x82, 0x14, 0x93, 0x14, 0xa4, 0x14, 0xb5, 0xf2, 0x06 } },
    {   2U, 0x40728ULL, 0x670bd2ULL, 0x3027aULL, { 0xac, 0x00, 0x00, 0x00, 0x48, 0x20, 0x35, 0x02, 0x03, 0x00, 0x48, 0x20, 0x35, 0x02, 0x02, 0x00 } },
    {   3U, 0x40730ULL, 0x670beeULL, 0x30296ULL, { 0xc9, 0x00, 0x04, 0x00, 0x1e, 0x10, 0x29, 0x01, 0x00, 0x00, 0x94, 0x00, 0x06, 0x00, 0x36, 0x10 } },
    {   4U, 0x40738ULL, 0x670bfcULL, 0x302a4ULL, { 0x36, 0x10, 0x55, 0x00, 0x01, 0x00, 0xcf, 0x00, 0x36, 0x30, 0x65, 0x00, 0x20, 0x03, 0xcf, 0x00 } },
    {   5U, 0x40740ULL, 0x670c0eULL, 0x302b6ULL, { 0x44, 0x0b, 0x13, 0x00, 0x44, 0x03, 0x15, 0x00, 0x44, 0x0d, 0x14, 0x00, 0xb6, 0x09, 0x10, 0x00 } },
    {   6U, 0x40748ULL, 0x670dacULL, 0x30454ULL, { 0x44, 0x03, 0x1c, 0x00, 0x44, 0x0c, 0x1b, 0x00, 0xb6, 0x09, 0x15, 0x00, 0xad, 0x30, 0x3a, 0x00 } },
    {   7U, 0x40750ULL, 0x670f5eULL, 0x30606ULL, { 0x44, 0x04, 0x16, 0x00, 0x44, 0x0d, 0x15, 0x00, 0xb6, 0x0a, 0x10, 0x00, 0xad, 0x40, 0x38, 0x00 } },
    {   8U, 0x40758ULL, 0x671108ULL, 0x307b0ULL, { 0x44, 0x03, 0x1c, 0x00, 0xad, 0x30, 0x34, 0x00, 0x44, 0x04, 0x12, 0x00, 0x5a, 0x00, 0x77, 0x00 } },
    {   9U, 0x40760ULL, 0x67121eULL, 0x308c6ULL, { 0x44, 0x03, 0x17, 0x00, 0x44, 0x0d, 0x15, 0x00, 0x44, 0x0e, 0x16, 0x00, 0xed, 0x0b, 0x13, 0x00 } },
    {  10U, 0x40768ULL, 0x6713f4ULL, 0x30a9cULL, { 0x36, 0x10, 0x55, 0x00, 0x02, 0x00, 0xcf, 0x00, 0xfe, 0x00, 0x4f, 0x00, 0x36, 0x10, 0x0a, 0x00 } },
    {  11U, 0x40770ULL, 0x67144cULL, 0x30af4ULL, { 0x14, 0xda, 0xad, 0xe0, 0x43, 0x00, 0x5a, 0x00, 0x82, 0x00, 0x14, 0xe4, 0xec, 0x04, 0x43, 0x00 } },
    {  12U, 0x40778ULL, 0x671572ULL, 0x30c1aULL, { 0x44, 0x05, 0x12, 0x00, 0x44, 0x02, 0x11, 0x00, 0xad, 0x50, 0x44, 0x00, 0x5a, 0x00, 0xfc, 0x00 } },
    {  13U, 0x40780ULL, 0x671794ULL, 0x30e3cULL, { 0x44, 0x05, 0x17, 0x00, 0x44, 0x0f, 0x15, 0x00, 0xad, 0x51, 0x45, 0x00, 0x44, 0x00, 0x13, 0x00 } },
    {  14U, 0x40788ULL, 0x67198eULL, 0x31036ULL, { 0x44, 0x04, 0x11, 0x00, 0xad, 0x40, 0x46, 0x00, 0x5a, 0x00, 0x69, 0x00, 0x14, 0x43, 0xec, 0x03 } },
    {  15U, 0x40790ULL, 0x671a84ULL, 0x3112cULL, { 0x44, 0x04, 0x11, 0x00, 0xad, 0x40, 0x47, 0x00, 0x5a, 0x00, 0x69, 0x00, 0x14, 0x43, 0xec, 0x03 } },
    {  16U, 0x40798ULL, 0x671b7aULL, 0x31222ULL, { 0xad, 0x90, 0x48, 0x00, 0x5a, 0x00, 0x42, 0x00, 0x14, 0x95, 0xec, 0x05, 0x48, 0x00, 0x1a, 0x52 } },
    {  17U, 0x407a0ULL, 0x671c1eULL, 0x312c6ULL, { 0xad, 0x90, 0x4a, 0x00, 0x5a, 0x00, 0x42, 0x00, 0x14, 0x95, 0xec, 0x05, 0x4a, 0x00, 0x1a, 0x52 } },
    {  18U, 0x407a8ULL, 0x671cc2ULL, 0x3136aULL, { 0xad, 0x90, 0x4c, 0x00, 0x5a, 0x00, 0x42, 0x00, 0x14, 0x95, 0xec, 0x05, 0x4c, 0x00, 0x1a, 0x52 } },
    {  19U, 0x407b0ULL, 0x671d66ULL, 0x3140eULL, { 0xad, 0xa0, 0x4e, 0x00, 0x5a, 0x00, 0x42, 0x00, 0x14, 0xa4, 0xec, 0x04, 0x4e, 0x00, 0x1a, 0x42 } },
    {  20U, 0x407b8ULL, 0x671e0aULL, 0x314b2ULL, { 0x48, 0x10, 0xc7, 0x00, 0x09, 0x00, 0x48, 0x10, 0x29, 0x02, 0x09, 0x00, 0xcf, 0x00, 0xec, 0x00 } },
    {  21U, 0x407c0ULL, 0x671e9cULL, 0x31544ULL, { 0x01, 0x00, 0x00, 0x00, 0x17, 0x00, 0x00, 0x00, 0x29, 0x00, 0x01, 0x00, 0x01, 0x00, 0x40, 0x00 } },
    {  22U, 0x407c8ULL, 0x671eacULL, 0x31554ULL, { 0x48, 0x10, 0xc7, 0x00, 0x04, 0x00, 0x48, 0x10, 0x1a, 0x02, 0x03, 0x00, 0xfe, 0x21, 0x53, 0x00 } },
    {  23U, 0x407d0ULL, 0x671eceULL, 0x31576ULL, { 0x44, 0x04, 0x15, 0x00, 0xad, 0x40, 0x55, 0x00, 0x44, 0x05, 0x13, 0x00, 0x5a, 0x00, 0xb9, 0x01 } },
    {  24U, 0x407d8ULL, 0x6722c0ULL, 0x31968ULL, { 0x44, 0x03, 0x11, 0x00, 0xad, 0x30, 0x59, 0x00, 0x5a, 0x00, 0x9c, 0x01, 0x14, 0x3d, 0xec, 0x0d } },
    {  25U, 0x407e0ULL, 0x67261eULL, 0x31cc6ULL, { 0xac, 0x02, 0x00, 0x00, 0x48, 0x20, 0x35, 0x02, 0x2d, 0x00, 0x16, 0xd0, 0x86, 0x00, 0xb4, 0x04 } },
    {  26U, 0x407e8ULL, 0x67276aULL, 0x31e12ULL, { 0x7b, 0x01, 0x8a, 0x01, 0xac, 0x00, 0xdf, 0x03, 0x0c, 0x20, 0xf6, 0x01, 0x01, 0x00, 0xc9, 0x00 } },
    {  27U, 0x407f0ULL, 0x67282eULL, 0x31ed6ULL, { 0xad, 0xa0, 0x5d, 0x00, 0x5a, 0x00, 0x0e, 0x01, 0x14, 0xa4, 0xec, 0x04, 0x5d, 0x00, 0x1a, 0x42 } },
    {  28U, 0x407f8ULL, 0x672aaaULL, 0x32152ULL, { 0xac, 0x0f, 0x00, 0x00, 0x44, 0x09, 0x19, 0x00, 0x48, 0x20, 0x35, 0x02, 0xf9, 0x00, 0x44, 0x0a } },
    {  29U, 0x40800ULL, 0x672e8aULL, 0x32532ULL, { 0xac, 0x01, 0x20, 0x00, 0xac, 0x00, 0x5a, 0x02, 0x48, 0x20, 0x0f, 0x01, 0x01, 0x00, 0xfe, 0x40 } },
    {  30U, 0x40808ULL, 0x672ed6ULL, 0x3257eULL, { 0xac, 0x00, 0x00, 0x00, 0x48, 0x20, 0x35, 0x02, 0x07, 0x00, 0x7b, 0x01, 0x8a, 0x01, 0xac, 0x00 } },
    {  31U, 0x40810ULL, 0x672f2eULL, 0x325d6ULL, { 0xac, 0x00, 0x00, 0x00, 0x48, 0x20, 0x35, 0x02, 0x0b, 0x00, 0xb4, 0x0a, 0xfe, 0xb1, 0x74, 0x00 } },
    {  32U, 0x40818ULL, 0x67301aULL, 0x326c2ULL, { 0x02, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x01, 0x00, 0x24, 0x00, 0x00, 0x00 } },
    {  33U, 0x40820ULL, 0x673034ULL, 0x326dcULL, { 0xac, 0x08, 0x42, 0x03, 0xac, 0x00, 0x00, 0x00, 0x48, 0x20, 0x35, 0x02, 0x0a, 0x00, 0xb4, 0x05 } },
    {  34U, 0x40828ULL, 0x67314aULL, 0x327f2ULL, { 0x01, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x6b, 0x00, 0x01, 0x00, 0x01, 0x00, 0x73, 0x00 } },
    {  35U, 0x40830ULL, 0x67315aULL, 0x32802ULL, { 0xac, 0x03, 0x21, 0x00, 0xac, 0x04, 0xa3, 0x02, 0xac, 0x01, 0xa2, 0x02, 0xac, 0x00, 0x00, 0x00 } },
    {  36U, 0x40838ULL, 0x67321aULL, 0x328c2ULL, { 0x01, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x4c, 0x00, 0x01, 0x00, 0x01, 0x00, 0x57, 0x00 } },
    {  37U, 0x40840ULL, 0x67322aULL, 0x328d2ULL, { 0xac, 0x00, 0x00, 0x00, 0x48, 0x20, 0x35, 0x02, 0x02, 0x00, 0xb4, 0x00, 0x06, 0x00, 0xac, 0x03 } },
    {  38U, 0x40848ULL, 0x673238ULL, 0x328e0ULL, { 0xac, 0x03, 0x00, 0x00, 0x48, 0x20, 0x35, 0x02, 0x3f, 0x00, 0x44, 0x01, 0x10, 0x00, 0x48, 0x20 } },
    {  39U, 0x40850ULL, 0x673394ULL, 0x32a3cULL, { 0x44, 0x01, 0x10, 0x00, 0xac, 0x00, 0x00, 0x00, 0x48, 0x20, 0x35, 0x02, 0x0f, 0x00, 0x48, 0x20 } },
    {  40U, 0x40858ULL, 0x67344eULL, 0x32af6ULL, { 0xfe, 0x21, 0xaf, 0x00, 0x5a, 0x01, 0x0c, 0x00, 0xac, 0x00, 0xc7, 0x03, 0x1e, 0x20, 0x17, 0x02 } },
    {  41U, 0x40860ULL, 0x673488ULL, 0x32b30ULL, { 0xac, 0x00, 0x00, 0x00, 0x48, 0x20, 0x35, 0x02, 0x02, 0x00, 0xfe, 0x10, 0xaf, 0x00, 0x5a, 0x00 } },
    {  42U, 0x40868ULL, 0x6734acULL, 0x32b54ULL, { 0xac, 0x00, 0x00, 0x00, 0x48, 0x20, 0x35, 0x02, 0x04, 0x00, 0x36, 0x20, 0xd6, 0x00, 0x43, 0x00 } },
    {  43U, 0x40870ULL, 0x6734d6ULL, 0x32b7eULL, { 0xac, 0x00, 0x00, 0x00, 0x48, 0x20, 0x35, 0x02, 0x07, 0x00, 0x36, 0x20, 0xd6, 0x00, 0x76, 0x00 } },
    {  44U, 0x40878ULL, 0x673506ULL, 0x32baeULL, { 0xac, 0x00, 0xce, 0x03, 0x36, 0x20, 0xda, 0x00, 0x01, 0x00, 0x94, 0x00, 0x06, 0x00, 0xac, 0x00 } },
    {  45U, 0x40880ULL, 0x673514ULL, 0x32bbcULL, { 0xac, 0x00, 0x94, 0x02, 0x36, 0x20, 0xda, 0x00, 0x01, 0x00, 0x94, 0x00, 0x06, 0x00, 0xac, 0x00 } },
    {  46U, 0x40888ULL, 0x673522ULL, 0x32bcaULL, { 0xac, 0x00, 0x93, 0x02, 0x36, 0x20, 0xda, 0x00, 0x01, 0x00, 0x94, 0x00, 0x06, 0x00, 0xac, 0x00 } },
    {  47U, 0x40890ULL, 0x673530ULL, 0x32bd8ULL, { 0xac, 0x00, 0xce, 0x03, 0x36, 0x20, 0xda, 0x00, 0x01, 0x00, 0x94, 0x00, 0xa8, 0x00, 0x0a, 0x00 } },
    {  48U, 0x40898ULL, 0x673558ULL, 0x32c00ULL, { 0xac, 0x00, 0x93, 0x02, 0x36, 0x20, 0xda, 0x00, 0x01, 0x00, 0x94, 0x00, 0x06, 0x00, 0x16, 0x10 } },
    {  49U, 0x408a0ULL, 0x673566ULL, 0x32c0eULL, { 0x16, 0x10, 0xab, 0x00, 0x5a, 0x00, 0x06, 0x00, 0x1a, 0x10, 0x9f, 0x00, 0xef, 0x00, 0x0a, 0x00 } },
    {  50U, 0x408a8ULL, 0x67358eULL, 0x32c36ULL, { 0x44, 0x05, 0x18, 0x00, 0xac, 0x00, 0x00, 0x00, 0x48, 0x20, 0x35, 0x02, 0x05, 0x00, 0x44, 0x06 } },
    {  51U, 0x408b0ULL, 0x673848ULL, 0x32ef0ULL, { 0x36, 0x10, 0xf0, 0x01, 0x0b, 0x00, 0x94, 0x00, 0xac, 0x01, 0x0f, 0x00, 0x71, 0x00, 0x62, 0x00 } },
    {  52U, 0x408b8ULL, 0x67392cULL, 0x32fd4ULL, { 0xac, 0x05, 0x10, 0x00, 0xac, 0x01, 0x00, 0x00, 0x44, 0x03, 0x10, 0x00, 0x48, 0x20, 0x35, 0x02 } },
    {  53U, 0x408c0ULL, 0x673b22ULL, 0x331caULL, { 0x02, 0x00, 0x00, 0x00, 0x52, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x01, 0x00, 0x7f, 0x00, 0x00, 0x00 } },
    {  54U, 0x408c8ULL, 0x673b3eULL, 0x331e6ULL, { 0xac, 0x00, 0x00, 0x00, 0x48, 0x20, 0x35, 0x02, 0x03, 0x00, 0x48, 0x20, 0x35, 0x02, 0x04, 0x00 } },
    {  55U, 0x408d0ULL, 0x673b60ULL, 0x33208ULL, { 0xc9, 0x00, 0xeb, 0x00, 0x36, 0x10, 0xee, 0x01, 0x00, 0x00, 0x48, 0x56, 0x31, 0x01, 0x32, 0x54 } },
    {  56U, 0x408d8ULL, 0x673b74ULL, 0x3321cULL, { 0xac, 0x00, 0x00, 0x00, 0x48, 0x20, 0x35, 0x02, 0x04, 0x00, 0x48, 0x20, 0x35, 0x02, 0x03, 0x00 } },
    {  57U, 0x408e0ULL, 0x673bdcULL, 0x33284ULL, { 0xac, 0x00, 0x00, 0x00, 0x48, 0x20, 0x35, 0x02, 0x02, 0x00, 0xc9, 0x00, 0xc5, 0x01, 0x36, 0x10 } },
    {  58U, 0x408e8ULL, 0x673cc6ULL, 0x3336eULL, { 0xac, 0x00, 0x00, 0x00, 0x48, 0x20, 0x35, 0x02, 0x04, 0x00, 0x48, 0x20, 0x35, 0x02, 0x05, 0x00 } },
    {  59U, 0x408f0ULL, 0x673df6ULL, 0x3349eULL, { 0x01, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x82, 0x00, 0x01, 0x00, 0x01, 0x01, 0x81, 0x03 } },
    {  60U, 0x408f8ULL, 0x673e08ULL, 0x334b0ULL, { 0x36, 0x10, 0x30, 0x01, 0x02, 0x00, 0xc9, 0x01, 0xf0, 0x00, 0xc9, 0x00, 0xe8, 0x00, 0x0d, 0x01 } },
    {  61U, 0x40900ULL, 0x673e32ULL, 0x334daULL, { 0x16, 0x20, 0x05, 0x01, 0xb4, 0x11, 0xa8, 0x00, 0x0c, 0x00, 0xfe, 0x20, 0x0f, 0x01, 0x5a, 0x00 } },
    {  62U, 0x40908ULL, 0x673e56ULL, 0x334feULL, { 0xed, 0x0a, 0x11, 0x00, 0xac, 0x03, 0xe0, 0x02, 0x44, 0x04, 0x12, 0x00, 0xad, 0x40, 0xe5, 0x00 } },
    {  63U, 0x40910ULL, 0x67418eULL, 0x33836ULL, { 0x05, 0x00, 0x00, 0x00, 0x37, 0x00, 0x00, 0x00, 0x18, 0x00, 0x01, 0x00, 0x51, 0x00, 0x00, 0x00 } },
    {  64U, 0x40918ULL, 0x6741beULL, 0x33866ULL, { 0x48, 0x00, 0x41, 0x02, 0x00, 0x00, 0xcf, 0x00, 0x36, 0x10, 0x42, 0x02, 0x00, 0x00, 0xcf, 0x02 } },
    {  65U, 0x40920ULL, 0x6741e4ULL, 0x3388cULL, { 0xad, 0xd0, 0xed, 0x00, 0x5a, 0x00, 0xb9, 0x00, 0x14, 0xd7, 0xec, 0x07, 0xed, 0x00, 0x1a, 0x72 } },
    {  66U, 0x40928ULL, 0x674378ULL, 0x33a20ULL, { 0x48, 0x00, 0x41, 0x02, 0x00, 0x00, 0xcf, 0x00, 0x36, 0x10, 0x42, 0x02, 0x00, 0x00, 0xcf, 0x02 } },
    {  67U, 0x40930ULL, 0x67439eULL, 0x33a46ULL, { 0x44, 0x03, 0x1a, 0x00, 0xfe, 0x30, 0x1e, 0x01, 0xfe, 0x00, 0x31, 0x01, 0x48, 0x10, 0x27, 0x02 } },
    {  68U, 0x40938ULL, 0x6745f6ULL, 0x33c9eULL, { 0x01, 0x00, 0x00, 0x00, 0xba, 0x00, 0x00, 0x00, 0x1b, 0x00, 0x01, 0x00, 0x01, 0x00, 0xd5, 0x01 } },
    {  69U, 0x40940ULL, 0x674606ULL, 0x33caeULL, { 0x44, 0x03, 0x10, 0x00, 0xad, 0x30, 0x18, 0x01, 0x5a, 0x00, 0x5f, 0x02, 0x14, 0x36, 0xec, 0x06 } },
    {  70U, 0x40948ULL, 0x674b44ULL, 0x341ecULL, { 0x01, 0x00, 0x00, 0x00, 0xe4, 0x01, 0x00, 0x00, 0x19, 0x00, 0x01, 0x00, 0x01, 0x00, 0xfd, 0x03 } },
    {  71U, 0x40950ULL, 0x674b54ULL, 0x341fcULL, { 0x48, 0x30, 0x75, 0x01, 0x31, 0x04, 0xcf, 0x00, 0xfc, 0x00, 0xad, 0xa0, 0x1a, 0x01, 0x5a, 0x00 } },
    {  72U, 0x40958ULL, 0x674b5eULL, 0x34206ULL, { 0xad, 0xa0, 0x1a, 0x01, 0x5a, 0x00, 0x9b, 0x00, 0x14, 0xa6, 0xec, 0x06, 0x1a, 0x01, 0x1a, 0x62 } },
    {  73U, 0x40960ULL, 0x674cb6ULL, 0x3435eULL, { 0xac, 0x08, 0xd2, 0x02, 0xac, 0x03, 0x9c, 0x02, 0xad, 0xc0, 0xf5, 0x00, 0x5a, 0x00, 0x24, 0x00 } },
    {  74U, 0x40968ULL, 0x674edeULL, 0x34586ULL, { 0x03, 0x00, 0x00, 0x00, 0x33, 0x00, 0x00, 0x00, 0x19, 0x00, 0x01, 0x00, 0x4e, 0x00, 0x00, 0x00 } },
    {  75U, 0x40970ULL, 0x674f02ULL, 0x345aaULL, { 0x5a, 0x08, 0x07, 0x00, 0x36, 0x30, 0x4e, 0x01, 0x76, 0x09, 0xcf, 0x00, 0xfc, 0x00, 0xac, 0x00 } },
    {  76U, 0x40978ULL, 0x674feaULL, 0x34692ULL, { 0x01, 0x00, 0x00, 0x00, 0x15, 0x00, 0x00, 0x00, 0x35, 0x00, 0x01, 0x00, 0x01, 0x00, 0x71, 0x00 } },
    {  77U, 0x40980ULL, 0x674ffaULL, 0x346a2ULL, { 0x5a, 0x08, 0x07, 0x00, 0x36, 0x30, 0x51, 0x01, 0x76, 0x09, 0xcf, 0x00, 0xfc, 0x00, 0xac, 0x00 } },
    {  78U, 0x40988ULL, 0x675128ULL, 0x347d0ULL, { 0x01, 0x00, 0x00, 0x00, 0x15, 0x00, 0x00, 0x00, 0x35, 0x00, 0x01, 0x00, 0x01, 0x00, 0x94, 0x01 } },
    {  79U, 0x40990ULL, 0x675138ULL, 0x347e0ULL, { 0xb4, 0x04, 0x14, 0xc6, 0x14, 0xda, 0x5a, 0x0e, 0x89, 0x00, 0xac, 0x00, 0xa6, 0x02, 0x36, 0x20 } },
    {  80U, 0x40998ULL, 0x6752d0ULL, 0x34978ULL, { 0x01, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x34, 0x00, 0x01, 0x00, 0x01, 0x00, 0x89, 0x01 } },
    {  81U, 0x409a0ULL, 0x6752e0ULL, 0x34988ULL, { 0x44, 0x03, 0x19, 0x00, 0xad, 0x30, 0xfe, 0x00, 0x44, 0x0a, 0x15, 0x00, 0x5a, 0x00, 0xea, 0x01 } },
    {  82U, 0x409a8ULL, 0x67572aULL, 0x34dd2ULL, { 0x02, 0x00, 0x00, 0x00, 0xa8, 0x00, 0x00, 0x00, 0x2b, 0x00, 0x01, 0x00, 0xff, 0x01, 0x00, 0x00 } },
    {  83U, 0x409b0ULL, 0x675742ULL, 0x34deaULL, { 0x44, 0x03, 0x15, 0x00, 0x44, 0x09, 0x13, 0x00, 0xad, 0x30, 0x01, 0x01, 0x44, 0x08, 0x12, 0x00 } },
    {  84U, 0x409b8ULL, 0x6762d6ULL, 0x3597eULL, { 0x08, 0x00, 0x00, 0x00, 0xfb, 0x01, 0x00, 0x00, 0x17, 0x00, 0x01, 0x00, 0x19, 0x02, 0x00, 0x00 } },
    {  85U, 0x409c0ULL, 0x676326ULL, 0x359ceULL, { 0x44, 0x04, 0x1f, 0x00, 0xad, 0x40, 0x08, 0x01, 0x44, 0x02, 0x1c, 0x00, 0x5a, 0x00, 0x78, 0x01 } },
    {  86U, 0x409c8ULL, 0x676640ULL, 0x35ce8ULL, { 0xc9, 0x00, 0xc5, 0x01, 0x36, 0x10, 0xee, 0x01, 0x00, 0x00, 0x48, 0x00, 0xe1, 0x01, 0x00, 0x00 } },
    {  87U, 0x409d0ULL, 0x6766d6ULL, 0x35d7eULL, { 0xac, 0x0c, 0x44, 0x03, 0x44, 0x03, 0x15, 0x00, 0xad, 0x30, 0x10, 0x01, 0x44, 0x04, 0x12, 0x00 } },
    {  88U, 0x409d8ULL, 0x67693eULL, 0x35fe6ULL, { 0x02, 0x00, 0x00, 0x00, 0x56, 0x00, 0x00, 0x00, 0x58, 0x00, 0x01, 0x00, 0xbd, 0x00, 0x00, 0x00 } },
    {  89U, 0x409e0ULL, 0x676956ULL, 0x35ffeULL, { 0xac, 0x00, 0x00, 0x00, 0x48, 0x20, 0x35, 0x02, 0x03, 0x00, 0x48, 0x20, 0x35, 0x02, 0x04, 0x00 } },
    {  90U, 0x409e8ULL, 0x676992ULL, 0x3603aULL, { 0xac, 0x00, 0x00, 0x00, 0x48, 0x20, 0x35, 0x02, 0x07, 0x00, 0x48, 0x20, 0x35, 0x02, 0x08, 0x00 } },
    {  91U, 0x409f0ULL, 0x6769ceULL, 0x36076ULL, { 0xac, 0x00, 0x00, 0x00, 0x48, 0x20, 0x35, 0x02, 0x07, 0x00, 0x48, 0x20, 0x35, 0x02, 0x08, 0x00 } },
    {  92U, 0x409f8ULL, 0x676a0aULL, 0x360b2ULL, { 0x44, 0x04, 0x12, 0x00, 0x44, 0x03, 0x11, 0x00, 0xad, 0x40, 0x31, 0x01, 0x5a, 0x00, 0x36, 0x00 } },
    {  93U, 0x40a00ULL, 0x676caaULL, 0x36352ULL, { 0x03, 0x00, 0x00, 0x00, 0x42, 0x00, 0x00, 0x00, 0x04, 0x00, 0x01, 0x00, 0x86, 0x00, 0x00, 0x00 } },
    {  94U, 0x40a08ULL, 0x676cd0ULL, 0x36378ULL, { 0xac, 0x00, 0x00, 0x00, 0x14, 0xf3, 0x48, 0x20, 0x35, 0x02, 0x03, 0x00, 0x44, 0x06, 0x10, 0x00 } },
    {  95U, 0x40a10ULL, 0x676d38ULL, 0x363e0ULL, { 0xac, 0x00, 0x1d, 0x03, 0x36, 0x20, 0x99, 0x01, 0x03, 0x00, 0xfe, 0x30, 0xa0, 0x01, 0x5a, 0x00 } },
    {  96U, 0x40a18ULL, 0x676d7eULL, 0x36426ULL, { 0xac, 0x00, 0x1e, 0x03, 0x36, 0x20, 0x99, 0x01, 0x01, 0x00, 0x5a, 0x02, 0x12, 0x00, 0xfe, 0x10 } },
    {  97U, 0x40a20ULL, 0x676dd6ULL, 0x3647eULL, { 0xac, 0x00, 0x00, 0x00, 0x14, 0x75, 0x48, 0x20, 0x35, 0x02, 0x05, 0x00, 0xac, 0x00, 0x77, 0x02 } },
    {  98U, 0x40a28ULL, 0x676e48ULL, 0x364f0ULL, { 0xac, 0x00, 0x00, 0x00, 0x48, 0x20, 0x35, 0x02, 0x03, 0x00, 0x1a, 0x21, 0xb1, 0x01, 0xb4, 0x10 } },
    {  99U, 0x40a30ULL, 0x676e64ULL, 0x3650cULL, { 0xac, 0x00, 0x00, 0x00, 0x48, 0x20, 0x35, 0x02, 0x03, 0x00, 0x1a, 0x21, 0xb1, 0x01, 0xb4, 0x20 } },
    { 100U, 0x40a38ULL, 0x676e80ULL, 0x36528ULL, { 0xac, 0x00, 0x00, 0x00, 0x48, 0x20, 0x35, 0x02, 0x02, 0x00, 0x1a, 0x10, 0xb1, 0x01, 0x8f, 0x00 } },
    { 101U, 0x40a40ULL, 0x676e9aULL, 0x36542ULL, { 0xac, 0x00, 0x00, 0x00, 0x48, 0x20, 0x35, 0x02, 0x02, 0x00, 0x1a, 0x10, 0xb1, 0x01, 0x5a, 0x00 } },
    { 102U, 0x40a48ULL, 0x676eb4ULL, 0x3655cULL, { 0xac, 0x00, 0x00, 0x00, 0x48, 0x20, 0x35, 0x02, 0x02, 0x00, 0x1a, 0x10, 0xb1, 0x01, 0xa8, 0x00 } },
    { 103U, 0x40a50ULL, 0x676eceULL, 0x36576ULL, { 0x1a, 0x20, 0xb1, 0x01, 0xa8, 0x00, 0x10, 0x00, 0x1e, 0x30, 0x30, 0x02, 0x23, 0x04, 0xcf, 0x01 } },
    { 104U, 0x40a58ULL, 0x676ef8ULL, 0x365a0ULL, { 0xfe, 0x10, 0xba, 0x01, 0xfc, 0x00, 0xfe, 0x10, 0xbb, 0x01, 0xfc, 0x00, 0xc9, 0x00, 0xc0, 0x01 } },
    { 105U, 0x40a60ULL, 0x676efeULL, 0x365a6ULL, { 0xfe, 0x10, 0xbb, 0x01, 0xfc, 0x00, 0xc9, 0x00, 0xc0, 0x01, 0x0d, 0x01, 0x06, 0x00, 0xc9, 0x00 } },
    { 106U, 0x40a68ULL, 0x676f04ULL, 0x365acULL, { 0xc9, 0x00, 0xc0, 0x01, 0x0d, 0x01, 0x06, 0x00, 0xc9, 0x00, 0xc1, 0x01, 0xee, 0x01, 0x04, 0x00 } },
    { 107U, 0x40a70ULL, 0x676f1cULL, 0x365c4ULL, { 0xc9, 0x00, 0xbf, 0x01, 0x0d, 0x01, 0x0a, 0x00, 0xc9, 0x00, 0xc0, 0x01, 0x0d, 0x01, 0x06, 0x00 } },
    { 108U, 0x40a78ULL, 0x676f3cULL, 0x365e4ULL, { 0xac, 0x00, 0x00, 0x00, 0x48, 0x20, 0x35, 0x02, 0x02, 0x00, 0xdf, 0x01, 0x00, 0x20, 0x5a, 0x03 } },
};

const char* GetLusterPooledString(uint32_t str_idx) noexcept {
    for (uint32_t i = 0; i < kLusterVirtualizedMethodCount; ++i) {
        if (kLusterVirtualizedMethods[i].name_str_idx == str_idx) {
            return kLusterVirtualizedMethods[i].method_name;
        }
        if (kLusterVirtualizedMethods[i].sig_str_idx == str_idx) {
            return kLusterVirtualizedMethods[i].method_sig;
        }
    }
    return "com/vega/subscription/core/checker/IBusinessChecker";
}

const char* ResolveLusterClassNameById(uint32_t class_id) noexcept {
    for (uint32_t i = 0; i < kLusterProtectedClassCount; ++i) {
        if (kLusterProtectedClasses[i].class_id == class_id) {
            return kLusterProtectedClasses[i].resolved_class_name;
        }
    }
    return "com/illusion/light/EffectUtil";
}

} // namespace luster
} // namespace opencut
} // namespace nextai
