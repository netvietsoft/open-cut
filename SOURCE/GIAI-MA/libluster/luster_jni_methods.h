/**
 * @file luster_jni_methods.h
 * @brief Clean-Room C++17 Declarations for All 93 Virtualized JNI Methods in libluster.so
 *        Khai báo C++17 cho toàn bộ 93 phương thức gốc JNI ảo hóa trong libluster.so (0x050a0..0x1459c)
 */

#ifndef NEXTAI_OPENCUT_LUSTER_JNI_METHODS_H_
#define NEXTAI_OPENCUT_LUSTER_JNI_METHODS_H_

#include "luster_types.h"

namespace nextai {
namespace opencut {
namespace luster {

/**
 * @brief Returns the reconstructed C++17 function pointer for virtualized JNI method `method_index` (0..92).
 *        Trả về con trỏ hàm C++17 đã tái cấu trúc cho phương thức JNI ảo hóa `method_index` (0..92).
 */
void* GetLusterJniMethodFunctionPointer(uint32_t method_index) noexcept;

/**
 * @brief Dispatches virtualized JNI method `method_index` (0..92) through the Terrain VM bridge.
 *        Điều phối thực thi phương thức JNI ảo hóa `method_index` (0..92) qua cầu nối máy ảo Terrain.
 */
uint64_t InvokeLusterVirtualizedMethod(JNIEnv* env,
                                       jobject thiz_or_clazz,
                                       uint32_t method_index,
                                       const uint64_t* args,
                                       uint32_t arg_count) noexcept;

// Method [00] @ 0x050a0..0x05328 (648 B): com/bytedance/EnvGuard/Handler.handleUpdate(J)V
uint64_t LusterJniMethod_00_0x050a0(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [01] @ 0x05328..0x055dc (692 B): com/lemon/editor/proxy/SubscribeImpl.b(Lcom/lemon/lv/clipmonetize/data/UserLiteInfo;Lkotlin/jvm/functions/Function1;Lkotlin/jvm/functions/Function0;)V
uint64_t LusterJniMethod_01_0x05328(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [02] @ 0x055dc..0x058a8 (716 B): com/lemon/editor/proxy/SubscribeImpl.f(ZLjava/lang/String;Lkotlin/jvm/functions/Function1;Lkotlin/jvm/functions/Function1;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;
uint64_t LusterJniMethod_02_0x055dc(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [03] @ 0x058a8..0x05b20 (632 B): com/lemon/editor/proxy/SubscribeImpl.h(Lkotlin/jvm/functions/Function0;Lkotlin/jvm/functions/Function1;)V
uint64_t LusterJniMethod_03_0x058a8(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [04] @ 0x05b20..0x05d84 (612 B): com/lemon/editor/proxy/SubscribeImpl.isVip()Z
uint64_t LusterJniMethod_04_0x05b20(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [05] @ 0x05d84..0x06020 (668 B): com/vega/ad/credit/CreditRewardGlobalViewModel.b(Ljava/lang/String;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;
uint64_t LusterJniMethod_05_0x05d84(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [06] @ 0x06020..0x062e8 (712 B): com/vega/ad/credit/CreditRewardGlobalViewModel.c(JZLjava/util/List;Lkotlin/jvm/functions/Function3;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;
uint64_t LusterJniMethod_06_0x06020(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [07] @ 0x062e8..0x065a0 (696 B): com/vega/ad/credit/CreditRewardGlobalViewModel.d(JLjava/lang/String;Ljava/lang/String;ILorg/json/JSONObject;Lkotlin/jvm/functions/Function3;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;
uint64_t LusterJniMethod_07_0x062e8(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [08] @ 0x065a0..0x06880 (736 B): com/vega/ad/credit/CreditRewardGlobalViewModel.e(JLjava/lang/String;ILorg/json/JSONObject;Lkotlin/jvm/functions/Function3;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;
uint64_t LusterJniMethod_08_0x065a0(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [09] @ 0x06880..0x06b4c (716 B): com/vega/ad/credit/CreditRewardGlobalViewModel.g(JZLjava/lang/String;Ljava/lang/String;Lorg/json/JSONObject;Ljava/lang/String;Ljava/lang/String;Lkotlin/jvm/functions/Function3;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;
uint64_t LusterJniMethod_09_0x06880(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [10] @ 0x06b4c..0x06d6c (544 B): com/vega/ad/credit/CreditRewardGlobalViewModel.i(JZLjava/lang/String;Lcom/vega/adapi/data/credit/DoActionReq;Lkotlin/jvm/functions/Function3;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;
uint64_t LusterJniMethod_10_0x06b4c(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [11] @ 0x06d6c..0x06fcc (608 B): com/vega/ad/credit/CreditRewardGlobalViewModel.n()Z
uint64_t LusterJniMethod_11_0x06d6c(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [12] @ 0x06fcc..0x0727c (688 B): com/vega/ad/credit/data/CreditRewardRepository.a(Ljava/lang/String;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;
uint64_t LusterJniMethod_12_0x06fcc(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [13] @ 0x0727c..0x07510 (660 B): com/vega/ad/credit/data/CreditRewardRepository.b(Ljava/lang/Long;Lcom/vega/adapi/data/credit/DoActionReq;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;
uint64_t LusterJniMethod_13_0x0727c(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [14] @ 0x07510..0x07768 (600 B): com/vega/ad/credit/data/CreditRewardRepository.c(Ljava/lang/Long;Ljava/util/List;Lorg/json/JSONObject;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;
uint64_t LusterJniMethod_14_0x07510(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [15] @ 0x07768..0x079f4 (652 B): com/vega/ad/credit/data/CreditRewardRepository.d(Ljava/lang/Long;Lcom/vega/adapi/data/credit/DoRewardReq;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;
uint64_t LusterJniMethod_15_0x07768(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [16] @ 0x079f4..0x07c3c (584 B): com/vega/ad/credit/data/CreditRewardRepository.e(Ljava/lang/Long;Lcom/vega/adapi/data/credit/DoRewardCallBackReq;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;
uint64_t LusterJniMethod_16_0x079f4(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [17] @ 0x07c3c..0x07e6c (560 B): com/vega/ad/credit/data/CreditRewardRepository.g(Ljava/lang/Long;Lcom/vega/adapi/data/credit/DoActionReq;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;
uint64_t LusterJniMethod_17_0x07c3c(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [18] @ 0x07e6c..0x08130 (708 B): com/vega/ad/credit/data/CreditRewardRepository.h(Ljava/lang/Long;Lcom/vega/adapi/data/credit/DoRewardReq;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;
uint64_t LusterJniMethod_18_0x07e6c(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [19] @ 0x08130..0x083b0 (640 B): com/vega/ad/credit/data/CreditRewardRepository.i(Ljava/lang/Long;Lcom/vega/adapi/data/credit/DoRewardCallBackReq;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;
uint64_t LusterJniMethod_19_0x08130(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [20] @ 0x083b0..0x0863c (652 B): com/vega/ad/credit/data/CreditRewardRepository.j(Ljava/lang/Long;Ljava/util/List;Lorg/json/JSONObject;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;
uint64_t LusterJniMethod_20_0x083b0(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [21] @ 0x0863c..0x088a8 (620 B): com/vega/ad/credit/data/CreditRewardRepository.k(Ljava/util/List;Z)V
uint64_t LusterJniMethod_21_0x0863c(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [22] @ 0x088a8..0x08b50 (680 B): com/vega/ad/credit/data/CreditRewardRepository.m(Lcom/vega/ad/credit/data/ApiSource;Lcom/vega/adapi/data/credit/UserInfo;Ljava/lang/String;)V
uint64_t LusterJniMethod_22_0x088a8(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [23] @ 0x08b50..0x08da8 (600 B): com/vega/ad/credit/task/CreditActiveRewardTask.b(Ljava/lang/Long;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;
uint64_t LusterJniMethod_23_0x08b50(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [24] @ 0x08da8..0x08ff0 (584 B): com/vega/ad/credit/task/CreditLandingRewardTask.b(Ljava/lang/Long;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;
uint64_t LusterJniMethod_24_0x08da8(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [25] @ 0x08ff0..0x09290 (672 B): com/vega/ad/credit/task/CreditLandingRewardTask.f(Lcom/vega/adapi/credit/CreditTaskResult;)Z
uint64_t LusterJniMethod_25_0x08ff0(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [26] @ 0x09290..0x094e4 (596 B): com/vega/ad/credit/task/CreditTemplateExportCheckTask.i(Lcom/vega/adapi/data/credit/UserInfo;I)Lcom/vega/adapi/credit/CreditTaskResult;
uint64_t LusterJniMethod_26_0x09290(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [27] @ 0x094e4..0x09700 (540 B): com/vega/ad/credit/task/CreditTemplateExportCheckTask.b(Ljava/lang/Long;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;
uint64_t LusterJniMethod_27_0x094e4(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [28] @ 0x09700..0x09950 (592 B): com/vega/ad/credit/task/CreditTemplateExportCheckTask.f(Lcom/vega/adapi/credit/CreditTaskResult;)Z
uint64_t LusterJniMethod_28_0x09700(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [29] @ 0x09950..0x09c00 (688 B): com/vega/ad/credit/task/CreditWatchAdRewardTask.b(Ljava/lang/Long;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;
uint64_t LusterJniMethod_29_0x09950(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [30] @ 0x09c00..0x09e68 (616 B): com/vega/ad/credit/task/CreditWatchAdRewardTask.f(Lcom/vega/adapi/credit/CreditTaskResult;)Z
uint64_t LusterJniMethod_30_0x09c00(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [31] @ 0x09e68..0x0a090 (552 B): com/vega/ad/impl/adfree/AdFreeManager.a(Lcom/vega/adapi/constant/AdSceneTag;)Z
uint64_t LusterJniMethod_31_0x09e68(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [32] @ 0x0a090..0x0a2f0 (608 B): com/vega/ad/impl/multireward/MultiRewardAd.k(Ljava/lang/String;)Z
uint64_t LusterJniMethod_32_0x0a090(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [33] @ 0x0a2f0..0x0a53c (588 B): com/vega/ad/impl/multireward/MultiRewardAd.s(Ljava/lang/String;)V
uint64_t LusterJniMethod_33_0x0a2f0(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [34] @ 0x0a53c..0x0a7c0 (644 B): com/vega/adapi/credit/BaseAdCreditTask.f(Lcom/vega/adapi/credit/CreditTaskResult;)Z
uint64_t LusterJniMethod_34_0x0a53c(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [35] @ 0x0a7c0..0x0aa70 (688 B): com/vega/commonedit/dependencies/figure/LVFigureGlobalDependencyImpl$FigureOnItemApplyHook.c(Lcom/vega/container/session/core/ISession;Lcom/vega/edit/figure/model/FigureGroup;Lcom/ss/android/ugc/effectmanager/effect/model/Effect;Ljava/lang/String;Ljava/lang/String;Lcom/vega/middlebridge/swig/LVVEMetaType;Ljava/lang/String;Ljava/lang/Integer;)V
uint64_t LusterJniMethod_35_0x0a7c0(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [36] @ 0x0aa70..0x0acec (636 B): com/vega/commonedit/dependencies/figure/LVFigureGlobalDependencyImpl$FigureOnItemApplyHook.f(Lcom/vega/container/session/core/ISession;Ljava/util/Map;)V
uint64_t LusterJniMethod_36_0x0aa70(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [37] @ 0x0acec..0x0af6c (640 B): com/vega/draft/data/template/CommerceInfo.getCompatUnlockProductInfo()Lcom/vega/draft/data/template/ProductInfo;
uint64_t LusterJniMethod_37_0x0acec(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [38] @ 0x0af6c..0x0b214 (680 B): com/vega/draft/data/template/CommerceInfo.getProductInfo(Ljava/lang/String;)Lcom/vega/draft/data/template/ProductInfo;
uint64_t LusterJniMethod_38_0x0af6c(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [39] @ 0x0b214..0x0b4d4 (704 B): com/vega/draft/data/template/CommerceInfo.hasBoughtProductInfo(Ljava/lang/String;)Z
uint64_t LusterJniMethod_39_0x0b214(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [40] @ 0x0b4d4..0x0b780 (684 B): com/vega/draft/data/template/CommerceInfo.hasProductInfo(Ljava/lang/String;)Z
uint64_t LusterJniMethod_40_0x0b4d4(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [41] @ 0x0b780..0x0ba1c (668 B): com/vega/draft/data/template/CommerceInfo.isGeneralPaidExportTemplate()Z
uint64_t LusterJniMethod_41_0x0b780(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [42] @ 0x0ba1c..0x0bc08 (492 B): com/vega/draft/data/template/CommerceInfo.isPaidBusinessTemplateOnlyExport()Z
uint64_t LusterJniMethod_42_0x0ba1c(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [43] @ 0x0bc08..0x0be24 (540 B): com/vega/draft/data/template/CommerceInfo.isPaidExportBusinessTemplate()Z
uint64_t LusterJniMethod_43_0x0bc08(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [44] @ 0x0be24..0x0c08c (616 B): com/vega/draft/data/template/CommerceInfo.isPaidExportTemplate()Z
uint64_t LusterJniMethod_44_0x0be24(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [45] @ 0x0c08c..0x0c2e0 (596 B): com/vega/draft/data/template/CommerceInfo.isPaidUnlockBusinessTemplate()Z
uint64_t LusterJniMethod_45_0x0c08c(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [46] @ 0x0c2e0..0x0c500 (544 B): com/vega/draft/data/template/CommerceInfo.isPaidUnlockTemplate()Z
uint64_t LusterJniMethod_46_0x0c2e0(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [47] @ 0x0c500..0x0c720 (544 B): com/vega/edit/editpage/controller/EditExportController.Z(Lkotlin/jvm/functions/Function0;)V
uint64_t LusterJniMethod_47_0x0c500(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [48] @ 0x0c720..0x0c924 (516 B): com/vega/launcher/network/interceptors/CrackingInterceptor.d(Ljava/lang/String;)V
uint64_t LusterJniMethod_48_0x0c720(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [49] @ 0x0c924..0x0cb90 (620 B): com/vega/launcher/network/interceptors/CrackingInterceptor.intercept(Lcom/bytedance/retrofit2/intercept/Interceptor$Chain;)Lcom/bytedance/retrofit2/SsResponse;
uint64_t LusterJniMethod_49_0x0c924(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [50] @ 0x0cb90..0x0ce48 (696 B): com/vega/subscribe/SubscribeImpl.b(Lcom/lemon/lv/clipmonetize/data/UserLiteInfo;Lkotlin/jvm/functions/Function1;Lkotlin/jvm/functions/Function0;)V
uint64_t LusterJniMethod_50_0x0cb90(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [51] @ 0x0ce48..0x0d0c0 (632 B): com/vega/subscribe/SubscribeImpl.f(ZLjava/lang/String;Lkotlin/jvm/functions/Function1;Lkotlin/jvm/functions/Function1;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;
uint64_t LusterJniMethod_51_0x0ce48(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [52] @ 0x0d0c0..0x0d2dc (540 B): com/vega/subscribe/SubscribeImpl.h(Lkotlin/jvm/functions/Function0;Lkotlin/jvm/functions/Function1;)V
uint64_t LusterJniMethod_52_0x0d0c0(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [53] @ 0x0d2dc..0x0d57c (672 B): com/vega/subscribe/SubscriptionUserInfoExtKt.a(Lcom/vega/subscribe/api/SubscriptionUserInfo;)Lcom/vega/subscribe/VipSubscribeManager$VipStatus;
uint64_t LusterJniMethod_53_0x0d2dc(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [54] @ 0x0d57c..0x0d85c (736 B): com/vega/subscribe/VipSubscribeManager.b(Lcom/lemon/lv/clipmonetize/data/UserLiteInfo;Lkotlin/jvm/functions/Function1;Lkotlin/jvm/functions/Function0;)V
uint64_t LusterJniMethod_54_0x0d57c(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [55] @ 0x0d85c..0x0dae0 (644 B): com/vega/subscribe/VipSubscribeManager.g()Z
uint64_t LusterJniMethod_55_0x0d85c(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [56] @ 0x0dae0..0x0dd28 (584 B): com/vega/subscribe/api/SubscriptionUserInfo.f()Z
uint64_t LusterJniMethod_56_0x0dae0(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [57] @ 0x0dd28..0x0dfa8 (640 B): com/vega/subscription/biz/checker/BusinessTemplateExportChecker.e(Lcom/vega/subscription/core/checker/CheckerContext;ZLkotlin/coroutines/Continuation;)Ljava/lang/Object;
uint64_t LusterJniMethod_57_0x0dd28(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [58] @ 0x0dfa8..0x0e250 (680 B): com/vega/subscription/biz/checker/BusinessTemplateUnlockDraftChecker.e(Lcom/vega/subscription/core/checker/CheckerContext;ZLkotlin/coroutines/Continuation;)Ljava/lang/Object;
uint64_t LusterJniMethod_58_0x0dfa8(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [59] @ 0x0e250..0x0e4c0 (624 B): com/vega/subscription/biz/checker/ExportTrialStrategyChecker.e(Lcom/vega/subscription/core/checker/CheckerContext;ZLkotlin/coroutines/Continuation;)Ljava/lang/Object;
uint64_t LusterJniMethod_59_0x0e250(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [60] @ 0x0e4c0..0x0e7ac (748 B): com/vega/subscription/biz/checker/GeneralUnlockDraftChecker.e(Lcom/vega/subscription/core/checker/CheckerContext;ZLkotlin/coroutines/Continuation;)Ljava/lang/Object;
uint64_t LusterJniMethod_60_0x0e4c0(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [61] @ 0x0e7ac..0x0ea44 (664 B): com/vega/subscription/biz/checker/GeneralUnlockDraftChecker.g(Lcom/vega/subscription/core/checker/CheckerContext;Lcom/vega/subscription/core/checker/CheckResult;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;
uint64_t LusterJniMethod_61_0x0e7ac(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [62] @ 0x0ea44..0x0ec80 (572 B): com/vega/subscription/biz/checker/base/BaseGoodsAccessChecker.i(Lcom/vega/subscription/biz/checker/base/BaseGoodsAccessChecker;Lcom/vega/subscription/core/checker/CheckResult;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;
uint64_t LusterJniMethod_62_0x0ea44(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [63] @ 0x0ec80..0x0ef10 (656 B): com/vega/subscription/biz/checker/base/BaseGoodsAccessChecker.f(Lcom/vega/subscription/core/checker/CheckerContext;Lcom/vega/subscription/core/checker/CheckResult;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;
uint64_t LusterJniMethod_63_0x0ec80(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [64] @ 0x0ef10..0x0f15c (588 B): com/vega/subscription/biz/checker/base/BaseGoodsAccessChecker.l(Lcom/lemon/lv/clipmonetize/wrapper/BenefitResource;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;
uint64_t LusterJniMethod_64_0x0ef10(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [65] @ 0x0f15c..0x0f3a0 (580 B): com/vega/subscription/biz/checker/GoodsAccessChecker.e(Lcom/vega/subscription/core/checker/CheckerContext;ZLkotlin/coroutines/Continuation;)Ljava/lang/Object;
uint64_t LusterJniMethod_65_0x0f15c(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [66] @ 0x0f3a0..0x0f610 (624 B): com/vega/subscription/biz/checker/TemplateBreakWhenExpiredChecker.e(Lcom/vega/subscription/core/checker/CheckerContext;ZLkotlin/coroutines/Continuation;)Ljava/lang/Object;
uint64_t LusterJniMethod_66_0x0f3a0(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [67] @ 0x0f610..0x0f85c (588 B): com/vega/subscription/biz/checker/TemplateBreakWhenLaunchChecker.e(Lcom/vega/subscription/core/checker/CheckerContext;ZLkotlin/coroutines/Continuation;)Ljava/lang/Object;
uint64_t LusterJniMethod_67_0x0f610(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [68] @ 0x0f85c..0x0fac4 (616 B): com/vega/subscription/biz/checker/TemplateBreakWhenNormalChecker.e(Lcom/vega/subscription/core/checker/CheckerContext;ZLkotlin/coroutines/Continuation;)Ljava/lang/Object;
uint64_t LusterJniMethod_68_0x0f85c(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [69] @ 0x0fac4..0x0fd70 (684 B): com/vega/subscription/biz/checker/TemplateBreakWhenNormalChecker.k(Lcom/vega/subscription/core/checker/CheckerContext;Lcom/vega/feedx/main/bean/FeedItem;ZLkotlin/coroutines/Continuation;)Ljava/lang/Object;
uint64_t LusterJniMethod_69_0x0fac4(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [70] @ 0x0fd70..0x10044 (724 B): com/vega/subscription/biz/checker/VipExportChecker.e(Lcom/vega/subscription/core/checker/CheckerContext;ZLkotlin/coroutines/Continuation;)Ljava/lang/Object;
uint64_t LusterJniMethod_70_0x0fd70(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [71] @ 0x10044..0x102d0 (652 B): com/vega/subscription/biz/checker/VipExportChecker.f(Lcom/vega/subscription/core/checker/CheckerContext;Lcom/vega/subscription/core/checker/CheckResult;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;
uint64_t LusterJniMethod_71_0x10044(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [72] @ 0x102d0..0x1053c (620 B): com/vega/subscription/biz/checker/VipFeaturePayChecker.e(Lcom/vega/subscription/core/checker/CheckerContext;ZLkotlin/coroutines/Continuation;)Ljava/lang/Object;
uint64_t LusterJniMethod_72_0x102d0(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [73] @ 0x1053c..0x107fc (704 B): com/vega/subscription/biz/checker/VipFeatureUseChecker.e(Lcom/vega/subscription/core/checker/CheckerContext;ZLkotlin/coroutines/Continuation;)Ljava/lang/Object;
uint64_t LusterJniMethod_73_0x1053c(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [74] @ 0x107fc..0x10ab0 (692 B): com/vega/subscription/core/function/BaseBusinessFunction.O3(Lcom/vega/subscriptionapi/core/IBusinessFunctionParam;Lkotlin/jvm/functions/Function1;)Lkotlinx/coroutines/Job;
uint64_t LusterJniMethod_74_0x107fc(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [75] @ 0x10ab0..0x10d10 (608 B): com/vega/subscription/biz/function/base/BaseAIFeatureFunction.m4(Lcom/vega/subscriptionapi/biz/function/AIFeatureFunctionParam;Lkotlin/jvm/functions/Function1;)Lkotlinx/coroutines/Job;
uint64_t LusterJniMethod_75_0x10ab0(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [76] @ 0x10d10..0x10f5c (588 B): com/vega/subscription/biz/function/base/BaseMultiAIFeatureFunction.m4(Lcom/vega/subscriptionapi/biz/function/MultiAIFeatureFunctionParam;Lkotlin/jvm/functions/Function1;)Lkotlinx/coroutines/Job;
uint64_t LusterJniMethod_76_0x10d10(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [77] @ 0x10f5c..0x111cc (624 B): com/vega/subscription/core/checker/BusinessCheckerCollectionHelper.a(Lcom/vega/subscription/core/checker/CheckerContext;Ljava/util/List;Lkotlin/jvm/functions/Function1;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;
uint64_t LusterJniMethod_77_0x10f5c(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [78] @ 0x111cc..0x1143c (624 B): com/vega/subscription/core/function/BaseBusinessCheckerFunction.O3(Lcom/vega/subscriptionapi/core/IBusinessFunctionParam;Lkotlin/jvm/functions/Function1;)Lkotlinx/coroutines/Job;
uint64_t LusterJniMethod_78_0x111cc(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [79] @ 0x1143c..0x116b8 (636 B): com/vega/subscription/legacy/attachment/BaseNewBusinessImpl.E()Ljava/util/List;
uint64_t LusterJniMethod_79_0x1143c(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [80] @ 0x116b8..0x1194c (660 B): com/vega/subscription/legacy/attachment/BaseNewBusinessImpl.p(Z)Ljava/util/List;
uint64_t LusterJniMethod_80_0x116b8(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [81] @ 0x1194c..0x11bd4 (648 B): com/vega/subscription/legacy/attachment/BaseNewBusinessImpl.r(Lcom/vega/middlebridge/swig/AttachmentVipFeature;)V
uint64_t LusterJniMethod_81_0x1194c(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [82] @ 0x11bd4..0x11e0c (568 B): com/vega/subscriptionapi/core/Result.a(Lkotlin/jvm/functions/Function1;)V
uint64_t LusterJniMethod_82_0x11bd4(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [83] @ 0x11e0c..0x120c8 (700 B): com/vega/subscriptionapi/core/Result.b(Lkotlin/jvm/functions/Function1;)V
uint64_t LusterJniMethod_83_0x11e0c(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [84] @ 0x120c8..0x1236c (676 B): com/vega/subscriptionapi/core/Result.c(Lkotlin/jvm/functions/Function1;)V
uint64_t LusterJniMethod_84_0x120c8(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [85] @ 0x1236c..0x1263c (720 B): com/vega/subscriptionapi/core/Result.d(Lkotlin/jvm/functions/Function1;)V
uint64_t LusterJniMethod_85_0x1236c(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [86] @ 0x1263c..0x1289c (608 B): com/vega/subscriptionapi/core/Result.e(Lkotlin/jvm/functions/Function1;)V
uint64_t LusterJniMethod_86_0x1263c(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [87] @ 0x1289c..0x12b6c (720 B): com/vega/subscriptionapi/core/Result.f(Lkotlin/jvm/functions/Function2;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;
uint64_t LusterJniMethod_87_0x1289c(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [88] @ 0x12b6c..0x12e04 (664 B): com/vega/subscriptionapi/legacy/data/ResourceData.a()Ljava/lang/String;
uint64_t LusterJniMethod_88_0x12b6c(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [89] @ 0x12e04..0x140a0 (4764 B): com/vega/subscriptionapi/legacy/data/TemplateCombineIdsResponse.a()Ljava/util/List;
uint64_t LusterJniMethod_89_0x12e04(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [90] @ 0x140a0..0x1430c (620 B): com/vega/subscriptionapi/legacy/data/VipScene.b()Z
uint64_t LusterJniMethod_90_0x140a0(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [91] @ 0x1430c..0x1459c (656 B): com/vega/subscriptionapi/legacy/data/VipScene.c()Z
uint64_t LusterJniMethod_91_0x1430c(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;
// Method [92] @ 0x1459c..0x14838 (668 B): com/vega/util/WindowUtilsKt.a(Landroid/view/Window;Z)V
uint64_t LusterJniMethod_92_0x1459c(JNIEnv* env, jobject obj, uint64_t a0 = 0, uint64_t a1 = 0, uint64_t a2 = 0, uint64_t a3 = 0) noexcept;

} // namespace luster
} // namespace opencut
} // namespace nextai

#endif // NEXTAI_OPENCUT_LUSTER_JNI_METHODS_H_
