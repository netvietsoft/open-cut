package com.vega.ailabagent.service;

import X.2up;
import X.4cM;
import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.os.Parcelable;
import android.util.AttributeSet;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import androidx.core.app.ActivityOptionsCompat;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentActivity;
import androidx.fragment.app.FragmentManager;
import androidx.lifecycle.CoroutineLiveData;
import androidx.lifecycle.FlowLiveDataConversions;
import androidx.lifecycle.LifecycleCoroutineScopeImpl;
import androidx.lifecycle.LifecycleOwner;
import androidx.lifecycle.LifecycleOwnerKt;
import androidx.lifecycle.ViewModelStoreOwner;
import com.bytedance.helios.statichook.api.ExtraInfo;
import com.bytedance.helios.statichook.api.HeliosApiHook;
import com.bytedance.router.SmartRoute;
import com.bytedance.router.SmartRouter;
import com.google.gson.Gson;
import com.lm.components.permission.PermissionRequest;
import com.lm.components.permission.PermissionResult;
import com.lm.components.permission.PermissionUtil;
import com.vega.ailabagent.common.data.RefMessageInfo;
import com.vega.ailabagent.common.data.VideoRatio;
import com.vega.ailabagent.common.data.VisualStyle;
import com.vega.ailabagent.common.history.HistoryActivity;
import com.vega.ailabagent.common.utils.ViewUtils;
import com.vega.ailabagent.common.view.AgentChatInputBoxViewFixedShape;
import com.vega.ailabagent.common.view.AgentChatInputBoxViewParams;
import com.vega.ailabagent.common.view.AgentChatInputBoxViewUiListener;
import com.vega.ailabagent.common.view.InputBoxToolIconDecorator;
import com.vega.ailabagent.common.view.SpeechInputSessionResult;
import com.vega.ailabagent.debug.CreditDebugView;
import com.vega.ailabagent.trendsagent.TrendsAgent;
import com.vega.ailabagent.trendsagent.ability.AiTrendsMaterialUploadManager;
import com.vega.ailabagent.trendsagent.data.DynamicTabSubmissionData;
import com.vega.ailabagent.trendsagent.data.TrendsAgentModel;
import com.vega.ailabagent.trendsagent.util.TrendsModelCacheManager;
import com.vega.ailabagent.unifyagent.AiLabAgent;
import com.vega.ailabagent.unifyagent.ability.AiLabAgentReportAbility;
import com.vega.ailabagent.unifyagent.commercial.AiCreationCommercialManager;
import com.vega.ailabagent.unifyagent.conversation.mode.data.AiLabAgentModePrefetchManager;
import com.vega.ailabagent.unifyagent.data.AiLabAgentInputData;
import com.vega.ailabagent.unifyagent.history.AiLabHistoryButtonReportHelper;
import com.vega.ailabagent.unifyagent.history.AiLabHistoryEntryView;
import com.vega.ailabagent.unifyagent.input.AiLabAgentInputBoxManager;
import com.vega.ailabagent.unifyagent.input.AiLabAgentInputBoxManagerObserver;
import com.vega.ailabagent.unifyagent.input.InputBoxReviseHelper;
import com.vega.ailabagent.unifyagent.input.InputBoxReviseHelper$getSettingToolIconDecorator$1;
import com.vega.ailabagent.unifyagent.quickreply.EditorQuickReplyDialogFragment;
import com.vega.ailabagent.unifyagent.recall.ArtifactRecallManager;
import com.vega.ailabagent.unifyagent.settings.AiLabAgentConfigSettings;
import com.vega.ailabagent.unifyagent.settings.AiLabAgentInputOptConfigSettings;
import com.vega.ailabagent.unifyagent.settings.AiLabHistoryRedDotSettings;
import com.vega.ailabagent.unifyagent.sug.AITrendsTemplateSugPreloadManager;
import com.vega.ailabagent.unifyagent.sug.SugMaterialInfo;
import com.vega.bean.ToneInfo;
import com.vega.commonedit.digitalhuman.DigitalHumanPanelDataViewModel;
import com.vega.config.ConfigSettingsKt;
import com.vega.core.context.SPIService;
import com.vega.core.deeplink.DeeplinkIntentLancetImpl;
import com.vega.core.ext.ExtentionKt;
import com.vega.core.utils.FunctionsKt;
import com.vega.feedx.service.IAiLabReporterService;
import com.vega.gallery.GalleryData;
import com.vega.gallery.local.MediaData;
import com.vega.genaicommon.AiLabHistoryConversationPresence;
import com.vega.genaicommon.IAiLabHistoryConversationLookup;
import com.vega.infrastructure.base.ModuleCommonKt;
import com.vega.kmp.agent.core.Conversation;
import com.vega.kmp.agent.core.ConversationRepo;
import com.vega.log.BLog;
import com.vega.publishapi.template.config.MultiContentCreationTaskConfigSettingsKt;
import com.vega.publishapi.template.config.MultiContentCreationTaskTrackingPolicy;
import com.vega.subscription.view.AICreationCreditsBar;
import com.vega.subscriptionapi.biz.function.AICreationScene;
import com.vega.subscriptionapi.biz.function.LibraExpType;
import com.vega.textaihuman.model.DigitalHumanPresenterModel;
import com.vega.theme.config.LvThemeContextKt;
import com.vega.ui.accomponent.AcComponentActivity;
import com.vega.videoagentapi.AwaitConversationDecision;
import com.vega.videoagentapi.AwaitConversationResult;
import com.vega.videoagentapi.IAiLabAgentService;
import com.vega.videoagentapi.common.input.InputModalType;
import com.vega.videoagentapi.unifyagent.utils.UnifyAgentPerformanceMonitor;
import com.vega.videoagentapi.utils.EffectMetricsReporter;
import java.io.Serializable;
import java.lang.ref.SoftReference;
import java.lang.ref.WeakReference;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.Objects;
import java.util.concurrent.ConcurrentHashMap;
import kotlin.Lazy;
import kotlin.LazyKt__LazyJVMKt;
import kotlin.NoWhenBranchMatchedException;
import kotlin.Pair;
import kotlin.Result;
import kotlin.ResultKt;
import kotlin.Triple;
import kotlin.TuplesKt;
import kotlin.Unit;
import kotlin.collections.CollectionsKt;
import kotlin.collections.CollectionsKt__CollectionsJVMKt;
import kotlin.collections.CollectionsKt__CollectionsKt;
import kotlin.collections.CollectionsKt___CollectionsKt;
import kotlin.collections.MapsKt__MapsJVMKt;
import kotlin.collections.MapsKt__MapsKt;
import kotlin.coroutines.Continuation;
import kotlin.coroutines.CoroutineContext;
import kotlin.coroutines.intrinsics.IntrinsicsKt__IntrinsicsKt;
import kotlin.jvm.functions.Function0;
import kotlin.jvm.functions.Function1;
import kotlin.jvm.functions.Function2;
import kotlin.jvm.internal.Intrinsics;
import kotlin.jvm.internal.Ref;
import kotlin.jvm.internal.Reflection;
import kotlin.text.StringsKt__StringsKt;
import kotlinx.coroutines.BuildersKt__Builders_commonKt;
import kotlinx.coroutines.CoroutineStart;
import kotlinx.coroutines.DelayKt;
import kotlinx.coroutines.Dispatchers;
import kotlinx.coroutines.TimeoutKt;
import kotlinx.coroutines.flow.StateFlow;
import org.json.JSONException;
import org.json.JSONObject;

/* JADX INFO: loaded from: D:\Decompiler\App\Video\Capcut\extracted\classes17.dex */
public final class AiLabAgentServiceImpl implements IAiLabAgentService, IAiLabHistoryConversationLookup {
    public static final /* synthetic */ int c = 0;
    public final ConcurrentHashMap<Integer, CreatorTaskContext> a = new ConcurrentHashMap<>();
    public final Lazy b = LazyKt__LazyJVMKt.lazy(enableAutoCutToAILabAgent.2.e);

    public static final class Companion {
    }

    @Override // com.vega.videoagentapi.IAiLabAgentService
    public final View h(FragmentActivity fragmentActivity) {
        return null;
    }

    static {
        new Companion();
    }

    @Override // com.vega.videoagentapi.IAiLabAgentService
    public final InputModalType e() {
        return AiLabAgentInputBoxManager.t.d();
    }

    @Override // com.vega.videoagentapi.IAiLabAgentService
    public final void A() {
        ArtifactRecallManager.a.getClass();
        ArtifactRecallManager.g();
    }

    @Override // com.vega.videoagentapi.IAiLabAgentService
    public final void c() {
        AiCreationCommercialManager.a.getClass();
        if (AiCreationCommercialManager.c) {
            return;
        }
        AiCreationCommercialManager.c = true;
    }

    @Override // com.vega.videoagentapi.IAiLabAgentService
    public final void k() {
        AITrendsTemplateSugPreloadManager.a.getClass();
        AITrendsTemplateSugPreloadManager.a();
    }

    @Override // com.vega.videoagentapi.IAiLabAgentService
    public final void l() {
        AiLabAgentModePrefetchManager.a.getClass();
        AiLabAgentModePrefetchManager.a();
    }

    @Override // com.vega.videoagentapi.IAiLabAgentService
    public final LibraExpType B() {
        AICreationScene aICreationScene = AICreationScene.b;
        Intrinsics.checkNotNullParameter(aICreationScene, "");
        AiCreationCommercialManager.a.getClass();
        return AiCreationCommercialManager.a().F2(aICreationScene);
    }

    @Override // com.vega.videoagentapi.IAiLabAgentService
    public final boolean I() {
        AiCreationCommercialManager.a.getClass();
        LibraExpType libraExpTypeF2 = AiCreationCommercialManager.a().F2(AICreationScene.a);
        if (libraExpTypeF2 != LibraExpType.c && libraExpTypeF2 != LibraExpType.d) {
            return true;
        }
        return false;
    }

    @Override // com.vega.videoagentapi.IAiLabAgentService
    public final void a() {
        EffectMetricsReporter effectMetricsReporter = EffectMetricsReporter.a;
        AiLabAgent.a.getClass();
        String strG = AiLabAgent.b().g();
        effectMetricsReporter.getClass();
        EffectMetricsReporter.a(strG, "export", "video");
    }

    @Override // com.vega.videoagentapi.IAiLabAgentService
    public final void m(ViewModelStoreOwner viewModelStoreOwner) {
        Intrinsics.checkNotNullParameter(viewModelStoreOwner, "");
    }

    @Override // com.vega.videoagentapi.IAiLabAgentService
    public final View G(Context context) {
        Intrinsics.checkNotNullParameter(context, "");
        CreditDebugView.c.getClass();
        return null;
    }

    @Override // com.vega.videoagentapi.IAiLabAgentService
    public final void z(Fragment fragment) {
        ArtifactRecallManager.a.getClass();
        ArtifactRecallManager.h(fragment);
    }

    @Override // com.vega.videoagentapi.IAiLabAgentService
    public final String C(View view) {
        AgentChatInputBoxViewFixedShape agentChatInputBoxViewFixedShape;
        String currentLoopPlaceholder;
        if (!(view instanceof AgentChatInputBoxViewFixedShape) || (agentChatInputBoxViewFixedShape = (AgentChatInputBoxViewFixedShape) view) == null || (currentLoopPlaceholder = agentChatInputBoxViewFixedShape.getCurrentLoopPlaceholder()) == null) {
            return "";
        }
        return currentLoopPlaceholder;
    }

    @Override // com.vega.videoagentapi.IAiLabAgentService
    public final void i(View view) {
        AgentChatInputBoxViewFixedShape agentChatInputBoxViewFixedShape;
        if ((view instanceof AgentChatInputBoxViewFixedShape) && (agentChatInputBoxViewFixedShape = (AgentChatInputBoxViewFixedShape) view) != null && agentChatInputBoxViewFixedShape.e != null) {
            agentChatInputBoxViewFixedShape.getInputBoxManager().r();
        }
    }

    @Override // com.vega.videoagentapi.IAiLabAgentService
    public final String H(Activity activity) {
        Intrinsics.checkNotNullParameter(activity, "");
        CreatorTaskContext creatorTaskContext = this.a.get(Integer.valueOf(activity.getTaskId()));
        if (creatorTaskContext == null) {
            return null;
        }
        Activity activity2 = (Activity) creatorTaskContext.a.get();
        if (activity2 == null || activity2.isFinishing() || activity2.isDestroyed()) {
            this.a.remove(Integer.valueOf(activity.getTaskId()));
            return null;
        }
        return creatorTaskContext.b;
    }

    @Override // com.vega.videoagentapi.IAiLabAgentService
    public final void v(FragmentActivity fragmentActivity) {
        Intrinsics.checkNotNullParameter(fragmentActivity, "");
        CreatorTaskContext creatorTaskContext = this.a.get(Integer.valueOf(fragmentActivity.getTaskId()));
        if (creatorTaskContext == null) {
            return;
        }
        Object obj = creatorTaskContext.a.get();
        if (obj == null || obj == fragmentActivity) {
            this.a.remove(Integer.valueOf(fragmentActivity.getTaskId()));
        }
    }

    @Override // com.vega.videoagentapi.IAiLabAgentService
    public final Map<String, String> f(View view) {
        AgentChatInputBoxViewFixedShape agentChatInputBoxViewFixedShape;
        AiLabAgentInputData aiLabAgentInputData;
        String strA;
        if (!(view instanceof AgentChatInputBoxViewFixedShape) || (agentChatInputBoxViewFixedShape = (AgentChatInputBoxViewFixedShape) view) == null) {
            return MapsKt__MapsKt.emptyMap();
        }
        if (agentChatInputBoxViewFixedShape.e != null) {
            Object value = agentChatInputBoxViewFixedShape.getInputBoxManager().m().getValue();
            if (!(value instanceof AiLabAgentInputData) || (aiLabAgentInputData = (AiLabAgentInputData) value) == null) {
                return MapsKt__MapsKt.emptyMap();
            }
            LinkedHashMap linkedHashMap = new LinkedHashMap();
            String strP = aiLabAgentInputData.p();
            if (strP != null && strP.length() > 0 && !Intrinsics.areEqual(strP, "auto")) {
                linkedHashMap.put("mode", strP);
            }
            DynamicTabSubmissionData dynamicTabSubmissionDataV = aiLabAgentInputData.v();
            if (dynamicTabSubmissionDataV != null && (strA = dynamicTabSubmissionDataV.a()) != null && strA.length() > 0) {
                linkedHashMap.put("deeplink_target_model_id", strA);
            }
            return linkedHashMap;
        }
        return MapsKt__MapsKt.emptyMap();
    }

    /* JADX WARN: Code duplicated, block: B:17:0x004a  */
    public final Object K(Continuation<? super List<Conversation>> continuation) {
        fetchAllConversationsForSync.1 r6;
        StateFlow stateFlowB;
        if (continuation instanceof fetchAllConversationsForSync.1) {
            r6 = (fetchAllConversationsForSync.1) continuation;
            int i = r6.t;
            if ((i & Integer.MIN_VALUE) != 0) {
                r6.t = i - Integer.MIN_VALUE;
            } else {
                r6 = new fetchAllConversationsForSync.1(this, continuation);
            }
        } else {
            r6 = new fetchAllConversationsForSync.1(this, continuation);
        }
        Object obj = r6.r;
        Object coroutine_suspended = IntrinsicsKt__IntrinsicsKt.getCOROUTINE_SUSPENDED();
        int i2 = r6.t;
        if (i2 != 0) {
            if (i2 == 1) {
                stateFlowB = r6.q;
                ResultKt.throwOnFailure(obj);
            } else {
                throw new IllegalStateException("call to 'resume' before 'invoke' with coroutine");
            }
        } else {
            ResultKt.throwOnFailure(obj);
            stateFlowB = ConversationRepo.a.b("ailab_agent_v1.1");
            ConversationRepo.b.u("ailab_agent_v1.1");
        }
        while (ConversationRepo.a.h("ailab_agent_v1.1")) {
            r6.q = stateFlowB;
            r6.t = 1;
            if (DelayKt.delay(100L, r6) == coroutine_suspended) {
                return coroutine_suspended;
            }
        }
        Iterable iterable = (Iterable) stateFlowB.getValue();
        ArrayList arrayList = new ArrayList();
        for (Object obj2 : iterable) {
            if (!((Conversation) obj2).o()) {
                arrayList.add(obj2);
            }
        }
        HashSet hashSet = new HashSet();
        ArrayList arrayList2 = new ArrayList();
        for (Object obj3 : arrayList) {
            if (hashSet.add(((Conversation) obj3).c)) {
                arrayList2.add(obj3);
            }
        }
        return arrayList2;
    }

    @Override // com.vega.videoagentapi.IAiLabAgentService
    public final void t(InputModalType inputModalType) {
        Object objCreateFailure;
        Intrinsics.checkNotNullParameter(inputModalType, "");
        AiLabAgentInputBoxManager.Companion companion = AiLabAgentInputBoxManager.t;
        companion.getClass();
        try {
            Objects.toString(inputModalType);
            AiLabAgentInputData aiLabAgentInputData = (AiLabAgentInputData) AiLabAgentInputBoxManager.Companion.e().fromJson(companion.c(), AiLabAgentInputData.class);
            if (!Intrinsics.areEqual(aiLabAgentInputData.p(), inputModalType.a)) {
                Intrinsics.checkNotNull(aiLabAgentInputData);
                AiLabAgentInputData aiLabAgentInputDataK = AiLabAgentInputData.k(aiLabAgentInputData, null, null, null, null, null, null, null, null, null, null, null, inputModalType.a, null, false, 0L, null, null, null, false, false, null, null, null, null, 33552255);
                String json = AiLabAgentInputBoxManager.Companion.e().toJson(aiLabAgentInputDataK);
                Intrinsics.checkNotNullExpressionValue(json, "");
                AiLabAgentInputBoxManager.v.setValue(companion, AiLabAgentInputBoxManager.Companion.a[0], json);
                AiLabAgentInputBoxManager.Companion.f(aiLabAgentInputDataK, "");
            }
            objCreateFailure = Unit.INSTANCE;
            Result.constructor-impl(objCreateFailure);
        } catch (Throwable th) {
            objCreateFailure = ResultKt.createFailure(th);
            Result.constructor-impl(objCreateFailure);
        }
        Throwable th2 = Result.exceptionOrNull-impl(objCreateFailure);
        if (th2 != null) {
            BLog.e("AiLabAgent.AiLabAgentInputBoxManager", "updateCachedInputModalType: " + th2);
        }
    }

    @Override // com.vega.videoagentapi.IAiLabAgentService
    public final void d(View view, Function2<? super Integer, ? super String, Unit> function2) {
        AgentChatInputBoxViewFixedShape agentChatInputBoxViewFixedShape;
        if ((view instanceof AgentChatInputBoxViewFixedShape) && (agentChatInputBoxViewFixedShape = (AgentChatInputBoxViewFixedShape) view) != null) {
            agentChatInputBoxViewFixedShape.setLoopPlaceholderCurrentTextChangeListener(function2);
        }
    }

    @Override // com.vega.videoagentapi.IAiLabAgentService
    public final void n(View view, Function2<? super Integer, ? super String, Unit> function2) {
        AgentChatInputBoxViewFixedShape agentChatInputBoxViewFixedShape;
        if ((view instanceof AgentChatInputBoxViewFixedShape) && (agentChatInputBoxViewFixedShape = (AgentChatInputBoxViewFixedShape) view) != null) {
            agentChatInputBoxViewFixedShape.setLoopPlaceholderTextShownListener(function2);
        }
    }

    @Override // com.vega.videoagentapi.IAiLabAgentService
    public final void q(View view, List<String> list) {
        AgentChatInputBoxViewFixedShape agentChatInputBoxViewFixedShape;
        Intrinsics.checkNotNullParameter(list, "");
        if ((view instanceof AgentChatInputBoxViewFixedShape) && (agentChatInputBoxViewFixedShape = (AgentChatInputBoxViewFixedShape) view) != null) {
            agentChatInputBoxViewFixedShape.setLoopPlaceholderTexts(list);
        }
    }

    @Override // com.vega.videoagentapi.IAiLabAgentService
    public final void g(FragmentActivity fragmentActivity, String str) {
        Intrinsics.checkNotNullParameter(fragmentActivity, "");
        if (str != null && str.length() > 0) {
            this.a.put(Integer.valueOf(fragmentActivity.getTaskId()), new CreatorTaskContext(new WeakReference(fragmentActivity), str));
        }
    }

    @Override // com.vega.videoagentapi.IAiLabAgentService
    public final View r(Context context, Integer num) {
        Intrinsics.checkNotNullParameter(context, "");
        AICreationCreditsBar aICreationCreditsBar = new AICreationCreditsBar(context, (AttributeSet) null, 6);
        aICreationCreditsBar.setFoldable(false);
        aICreationCreditsBar.setShowUpgradeEntry(false);
        aICreationCreditsBar.setOpenCreditRecords(true);
        if (num != null) {
            aICreationCreditsBar.setBarHeight(num.intValue());
        }
        return aICreationCreditsBar;
    }

    @Override // com.vega.videoagentapi.IAiLabAgentService
    public final void y(View view, boolean z) {
        AgentChatInputBoxViewFixedShape agentChatInputBoxViewFixedShape;
        if ((view instanceof AgentChatInputBoxViewFixedShape) && (agentChatInputBoxViewFixedShape = (AgentChatInputBoxViewFixedShape) view) != null) {
            if (z) {
                if (!(!agentChatInputBoxViewFixedShape.a.q.h.isEmpty())) {
                    return;
                }
                agentChatInputBoxViewFixedShape.a.q.l();
                return;
            }
            agentChatInputBoxViewFixedShape.a.q.k();
        }
    }

    public static void INVOKEVIRTUAL_com_vega_ailabagent_service_AiLabAgentServiceImpl_com_vega_core_deeplink_DeeplinkIntentLancet_startActivity(Activity activity, Intent intent) {
        DeeplinkIntentLancetImpl.a(intent);
        HeliosApiHook heliosApiHook = new HeliosApiHook();
        Object[] objArr = {intent};
        ExtraInfo extraInfo = new ExtraInfo(false, "(Landroid/content/Intent;)V", "dzBzEhQ/WMuSVF4tRBCFYZPyR8MFkLrZCQ5Y9ylNNTPhnmuCbicpgUatJewVaCF7Aw==");
        if (heliosApiHook.preInvoke(11098, "android/app/Activity", "startActivity", activity, objArr, "void", extraInfo).isIntercept()) {
            heliosApiHook.postInvoke((Object) null, 11098, "android/app/Activity", "startActivity", activity, objArr, extraInfo, false);
        } else {
            activity.startActivity(intent);
            heliosApiHook.postInvoke((Object) null, 11098, "android/app/Activity", "startActivity", activity, objArr, extraInfo, true);
        }
    }

    @Override // com.vega.videoagentapi.IAiLabAgentService
    public final View E(final Activity activity, String str) {
        final String str2;
        final String str3;
        boolean z;
        final String str4;
        View viewInflate;
        if (activity == null) {
            return null;
        }
        if (Intrinsics.areEqual(str, "home_tool")) {
            str2 = "trends_agent_v1.1";
        } else {
            str2 = "ailab_agent_v1.1";
        }
        if (Intrinsics.areEqual(str, "home_tool")) {
            str3 = "tool_ai_trends";
        } else if (Intrinsics.areEqual(str, "ai_trends")) {
            str3 = "ai_trends_template";
        } else {
            str3 = "ai_lab_homepage";
        }
        if (Intrinsics.areEqual(str, "home_tool") || Intrinsics.areEqual(str, "ai_trends")) {
            z = true;
            str4 = "trend_template";
        } else {
            z = false;
            str4 = "homepage";
        }
        AiLabHistoryRedDotSettings.Companion.getClass();
        if (ConfigSettingsKt.a(Reflection.getOrCreateKotlinClass(AiLabHistoryRedDotSettings.class)).a() > 0 && !z) {
            AiLabHistoryEntryView.a.getClass();
            viewInflate = AiLabHistoryEntryView.a(activity, str2);
        } else {
            viewInflate = LayoutInflater.from(activity).inflate(2131494496, (ViewGroup) null);
            ImageView imageView = (ImageView) viewInflate.findViewById(2131304451);
            ImageView imageView2 = (ImageView) viewInflate.findViewById(2131308329);
            imageView.setImageResource(2131238348);
            if (Intrinsics.areEqual("trends_agent_v1.1", str2)) {
                TrendsAgent.a.getClass();
                TrendsAgent.b();
            } else {
                AiLabAgent.a.getClass();
                AiLabAgent.c();
            }
            CoroutineLiveData coroutineLiveDataB = FlowLiveDataConversions.b(ConversationRepo.a.i(str2));
            Intrinsics.checkNotNull(activity, "");
            coroutineLiveDataB.observe((LifecycleOwner) activity, new sam.androidx_lifecycle_Observer.0(new initView.1.1(imageView2)));
            Intrinsics.checkNotNull(viewInflate);
        }
        viewInflate.addOnAttachStateChangeListener(new View.OnAttachStateChangeListener() { // from class: com.vega.ailabagent.service.AiLabAgentServiceImpl$getHistoryConversationView$1
            public final /* synthetic */ String c = "ai_lab";

            @Override // android.view.View.OnAttachStateChangeListener
            public final void onViewDetachedFromWindow(View view) {
                Intrinsics.checkNotNullParameter(view, "");
            }

            @Override // android.view.View.OnAttachStateChangeListener
            public final void onViewAttachedToWindow(View view) {
                Intrinsics.checkNotNullParameter(view, "");
                AiLabHistoryButtonReportHelper aiLabHistoryButtonReportHelper = AiLabHistoryButtonReportHelper.a;
                Activity activity2 = activity;
                String str5 = str2;
                String str6 = this.c;
                String str7 = str3;
                String str8 = str4;
                aiLabHistoryButtonReportHelper.getClass();
                AiLabHistoryButtonReportHelper.b(activity2, "show", str5, str6, str7, str8);
            }
        });
        viewInflate.setOnClickListener(new 2up(activity, str2, str3, str4, this, str));
        return viewInflate;
    }

    @Override // com.vega.videoagentapi.IAiLabAgentService
    public final Object p(List list, Continuation continuation, boolean z) {
        return AiTrendsMaterialUploadManager.a.e((String) null, (String) null, (String) null, list, continuation, z);
    }

    @Override // com.vega.videoagentapi.IAiLabAgentService
    public final boolean o(AcComponentActivity acComponentActivity, Uri uri, Intent intent) {
        String str = "";
        Intrinsics.checkNotNullParameter(acComponentActivity, "");
        Intrinsics.checkNotNullParameter(uri, "");
        Intrinsics.checkNotNullParameter(intent, "");
        String str2 = "//" + uri.getHost() + uri.getPath();
        String queryParameter = uri.getQueryParameter("channel");
        String queryParameter2 = uri.getQueryParameter("bundle");
        if (queryParameter2 != null) {
            str = queryParameter2;
        }
        if (!CollectionsKt__CollectionsKt.listOf(new String[]{"//main/lynx", "//main/lynx_trans"}).contains(str2) || !Intrinsics.areEqual("image_lynx_ai_creator", queryParameter) || !4cM.o(str, "story_editor")) {
            return false;
        }
        SmartRoute smartRouteBuildRoute = SmartRouter.buildRoute(acComponentActivity, "//main/ai_video_maker");
        smartRouteBuildRoute.withParam("agent_scene", "ai_video_maker");
        smartRouteBuildRoute.withParam("page_from", "anchor");
        smartRouteBuildRoute.withParam("enter_source", "ai_lab_anchor");
        smartRouteBuildRoute.open();
        return true;
    }

    /* JADX INFO: Thrown type has an unknown type hierarchy: kotlin.NoWhenBranchMatchedException */
    /* JADX WARN: Code duplicated, block: B:23:0x0052  */
    public final Object s(long j, String str, Continuation continuation) throws NoWhenBranchMatchedException {
        AiLabAgentServiceImpl$awaitHistoryConversationPresence$1 aiLabAgentServiceImpl$awaitHistoryConversationPresence$1;
        AiLabHistoryConversationPresenceMapper aiLabHistoryConversationPresenceMapper;
        if (continuation instanceof AiLabAgentServiceImpl$awaitHistoryConversationPresence$1) {
            aiLabAgentServiceImpl$awaitHistoryConversationPresence$1 = (AiLabAgentServiceImpl$awaitHistoryConversationPresence$1) continuation;
            int i = aiLabAgentServiceImpl$awaitHistoryConversationPresence$1.t;
            if ((i & Integer.MIN_VALUE) != 0) {
                aiLabAgentServiceImpl$awaitHistoryConversationPresence$1.t = i - Integer.MIN_VALUE;
            } else {
                aiLabAgentServiceImpl$awaitHistoryConversationPresence$1 = new AiLabAgentServiceImpl$awaitHistoryConversationPresence$1(this, continuation);
            }
        } else {
            aiLabAgentServiceImpl$awaitHistoryConversationPresence$1 = new AiLabAgentServiceImpl$awaitHistoryConversationPresence$1(this, continuation);
        }
        Object objX = aiLabAgentServiceImpl$awaitHistoryConversationPresence$1.r;
        Object coroutine_suspended = IntrinsicsKt__IntrinsicsKt.getCOROUTINE_SUSPENDED();
        int i2 = aiLabAgentServiceImpl$awaitHistoryConversationPresence$1.t;
        if (i2 != 0) {
            if (i2 == 1) {
                aiLabHistoryConversationPresenceMapper = aiLabAgentServiceImpl$awaitHistoryConversationPresence$1.q;
                ResultKt.throwOnFailure(objX);
            } else {
                throw new IllegalStateException("call to 'resume' before 'invoke' with coroutine");
            }
        } else {
            ResultKt.throwOnFailure(objX);
            aiLabHistoryConversationPresenceMapper = AiLabHistoryConversationPresenceMapper.a;
            aiLabAgentServiceImpl$awaitHistoryConversationPresence$1.q = aiLabHistoryConversationPresenceMapper;
            aiLabAgentServiceImpl$awaitHistoryConversationPresence$1.t = 1;
            objX = x(j, str, aiLabAgentServiceImpl$awaitHistoryConversationPresence$1);
            if (objX == coroutine_suspended) {
                return coroutine_suspended;
            }
        }
        AwaitConversationResult awaitConversationResult = (AwaitConversationResult) objX;
        aiLabHistoryConversationPresenceMapper.getClass();
        Intrinsics.checkNotNullParameter(awaitConversationResult, "");
        int iOrdinal = awaitConversationResult.ordinal();
        if (iOrdinal != 0) {
            if (iOrdinal != 1) {
                if (iOrdinal == 2) {
                    return AiLabHistoryConversationPresence.c;
                }
                throw new NoWhenBranchMatchedException();
            }
            return AiLabHistoryConversationPresence.b;
        }
        return AiLabHistoryConversationPresence.a;
    }

    /* JADX WARN: Code duplicated, block: B:26:0x0055  */
    @Override // com.vega.videoagentapi.IAiLabAgentService
    public final Object x(long j, String str, Continuation continuation) {
        awaitHistoryConversation.1 r4;
        if (continuation instanceof awaitHistoryConversation.1) {
            r4 = (awaitHistoryConversation.1) continuation;
            int i = r4.s;
            if ((i & Integer.MIN_VALUE) != 0) {
                r4.s = i - Integer.MIN_VALUE;
            } else {
                r4 = new awaitHistoryConversation.1(this, continuation);
            }
        } else {
            r4 = new awaitHistoryConversation.1(this, continuation);
        }
        Object objWithTimeoutOrNull = r4.q;
        Object coroutine_suspended = IntrinsicsKt__IntrinsicsKt.getCOROUTINE_SUSPENDED();
        int i2 = r4.s;
        if (i2 != 0) {
            if (i2 == 1) {
                ResultKt.throwOnFailure(objWithTimeoutOrNull);
            } else {
                throw new IllegalStateException("call to 'resume' before 'invoke' with coroutine");
            }
        } else {
            ResultKt.throwOnFailure(objWithTimeoutOrNull);
            if (str.length() == 0) {
                return AwaitConversationResult.LOADED;
            }
            if (ConversationRepo.a.f(str) != null) {
                return AwaitConversationResult.LOADED;
            }
            awaitHistoryConversation.found.1 r1 = new awaitHistoryConversation.found.1(str, (Continuation) null);
            r4.s = 1;
            objWithTimeoutOrNull = TimeoutKt.withTimeoutOrNull(j, r1, r4);
            if (objWithTimeoutOrNull == coroutine_suspended) {
                return coroutine_suspended;
            }
        }
        if (Intrinsics.areEqual(objWithTimeoutOrNull, true)) {
            return AwaitConversationResult.LOADED;
        }
        AwaitConversationDecision awaitConversationDecision = AwaitConversationDecision.a;
        boolean zH = ConversationRepo.a.h("ailab_agent_v1.1");
        awaitConversationDecision.getClass();
        if (zH) {
            return AwaitConversationResult.TIMED_OUT;
        }
        return AwaitConversationResult.CONFIRMED_ABSENT;
    }

    public static void INVOKEVIRTUAL_com_vega_ailabagent_service_AiLabAgentServiceImpl_com_vega_core_deeplink_DeeplinkIntentLancet_startActivity(Activity activity, Intent intent, Bundle bundle) {
        DeeplinkIntentLancetImpl.a(intent);
        HeliosApiHook heliosApiHook = new HeliosApiHook();
        Object[] objArr = {intent, bundle};
        ExtraInfo extraInfo = new ExtraInfo(false, "(Landroid/content/Intent;Landroid/os/Bundle;)V", "dzBzEhQ/WMuSVF4tRBCFYZPyR8MFkLrZCQ5Y9ylNNTPhnmuCbicpgUatJewVaCF7Aw==");
        if (heliosApiHook.preInvoke(11098, "android/app/Activity", "startActivity", activity, objArr, "void", extraInfo).isIntercept()) {
            heliosApiHook.postInvoke((Object) null, 11098, "android/app/Activity", "startActivity", activity, objArr, extraInfo, false);
        } else {
            activity.startActivity(intent, bundle);
            heliosApiHook.postInvoke((Object) null, 11098, "android/app/Activity", "startActivity", activity, objArr, extraInfo, true);
        }
    }

    public static final void L(Activity activity, AiLabAgentServiceImpl aiLabAgentServiceImpl, String str) {
        if (Intrinsics.areEqual(str, "home_tool")) {
            Boolean bool = Boolean.TRUE;
            aiLabAgentServiceImpl.w(activity, null, "home_tool", "tool_ai_trends", MapsKt__MapsKt.mapOf(new Pair[]{TuplesKt.to("directly_open_history", bool), TuplesKt.to("input_has_setting_tool", bool), TuplesKt.to("history_enter_source", "tool_ai_trends")}));
        } else if (Intrinsics.areEqual(str, "ai_trends")) {
            Boolean bool2 = Boolean.TRUE;
            IAiLabAgentService.DefaultImpls.b(aiLabAgentServiceImpl, activity, null, null, MapsKt__MapsKt.mapOf(new Pair[]{TuplesKt.to("directly_open_history", bool2), TuplesKt.to("input_has_setting_tool", bool2), TuplesKt.to("tag_source", "ai_trends"), TuplesKt.to("history_enter_source", "ai_trends_template")}), null, 20);
        } else {
            IAiLabAgentService.DefaultImpls.b(aiLabAgentServiceImpl, activity, null, null, MapsKt__MapsKt.mapOf(new Pair[]{TuplesKt.to("directly_open_history", Boolean.TRUE), TuplesKt.to("history_enter_source", "ai_lab_homepage")}), null, 20);
        }
    }

    /* JADX WARN: Code duplicated, block: B:11:0x0025  */
    /* JADX WARN: Code duplicated, block: B:35:0x007e  */
    public final Object J(long j, Conversation conversation, Continuation continuation) throws Throwable {
        AiLabAgentServiceImpl$awaitHistoryMessagesLoaded$1 aiLabAgentServiceImpl$awaitHistoryMessagesLoaded$1;
        boolean z;
        if (continuation instanceof AiLabAgentServiceImpl$awaitHistoryMessagesLoaded$1) {
            aiLabAgentServiceImpl$awaitHistoryMessagesLoaded$1 = (AiLabAgentServiceImpl$awaitHistoryMessagesLoaded$1) continuation;
            int i = aiLabAgentServiceImpl$awaitHistoryMessagesLoaded$1.u;
            if ((i & Integer.MIN_VALUE) != 0) {
                aiLabAgentServiceImpl$awaitHistoryMessagesLoaded$1.u = i - Integer.MIN_VALUE;
            } else {
                aiLabAgentServiceImpl$awaitHistoryMessagesLoaded$1 = new AiLabAgentServiceImpl$awaitHistoryMessagesLoaded$1(this, continuation);
            }
        } else {
            aiLabAgentServiceImpl$awaitHistoryMessagesLoaded$1 = new AiLabAgentServiceImpl$awaitHistoryMessagesLoaded$1(this, continuation);
        }
        Object objWithTimeoutOrNull = aiLabAgentServiceImpl$awaitHistoryMessagesLoaded$1.s;
        Object coroutine_suspended = IntrinsicsKt__IntrinsicsKt.getCOROUTINE_SUSPENDED();
        int i2 = aiLabAgentServiceImpl$awaitHistoryMessagesLoaded$1.u;
        if (i2 != 0) {
            if (i2 == 1) {
                z = aiLabAgentServiceImpl$awaitHistoryMessagesLoaded$1.r;
                conversation = aiLabAgentServiceImpl$awaitHistoryMessagesLoaded$1.q;
                try {
                    ResultKt.throwOnFailure(objWithTimeoutOrNull);
                } catch (Throwable th) {
                    th = th;
                    if (!z) {
                        conversation.B(false);
                    }
                    throw th;
                }
            } else {
                throw new IllegalStateException("call to 'resume' before 'invoke' with coroutine");
            }
        } else {
            ResultKt.throwOnFailure(objWithTimeoutOrNull);
            if (Intrinsics.areEqual(conversation.B.getValue(), "loaded")) {
                return true;
            }
            z = conversation.E;
            if (!z) {
                conversation.B(true);
            }
            try {
                awaitHistoryMessagesLoaded.2 r1 = new awaitHistoryMessagesLoaded.2(conversation, (Continuation) null);
                aiLabAgentServiceImpl$awaitHistoryMessagesLoaded$1.q = conversation;
                aiLabAgentServiceImpl$awaitHistoryMessagesLoaded$1.r = z;
                aiLabAgentServiceImpl$awaitHistoryMessagesLoaded$1.u = 1;
                objWithTimeoutOrNull = TimeoutKt.withTimeoutOrNull(j, r1, aiLabAgentServiceImpl$awaitHistoryMessagesLoaded$1);
                if (objWithTimeoutOrNull == coroutine_suspended) {
                    return coroutine_suspended;
                }
            } catch (Throwable th2) {
                th = th2;
                if (!z) {
                    conversation.B(false);
                }
                throw th;
            }
        }
        boolean zAreEqual = Intrinsics.areEqual(objWithTimeoutOrNull, true);
        if (!z) {
            conversation.B(false);
        }
        return Boolean.valueOf(zAreEqual);
    }

    @Override // com.vega.videoagentapi.IAiLabAgentService
    public final void F(Context context, String str, String str2, String str3) {
        String str4;
        Intrinsics.checkNotNullParameter(context, "");
        Intrinsics.checkNotNullParameter(str, "");
        Intrinsics.checkNotNullParameter(str2, "");
        Intrinsics.checkNotNullParameter(str3, "");
        if (Intrinsics.areEqual(str, "trends_agent_v1.1")) {
            str4 = "//ailab_trends_agent/chat";
        } else {
            str4 = "//ailab_agent/chat";
        }
        SmartRoute smartRouteBuildRoute = SmartRouter.buildRoute(context, str4);
        smartRouteBuildRoute.withParam("launch_message", str2);
        smartRouteBuildRoute.withParam("launch_message_type", str3);
        smartRouteBuildRoute.open();
    }

    @Override // com.vega.videoagentapi.IAiLabAgentService
    public final void b(FragmentActivity fragmentActivity, View view, View view2, Map map, String str) {
        Intrinsics.checkNotNullParameter(fragmentActivity, "");
        j(fragmentActivity, view, view2, map, str);
    }

    @Override // com.vega.videoagentapi.IAiLabAgentService
    public final void u(FragmentActivity fragmentActivity, String str, RefMessageInfo refMessageInfo, List<MediaData> list, String str2) {
        Intrinsics.checkNotNullParameter(fragmentActivity, "");
        Intrinsics.checkNotNullParameter(str, "");
        Intrinsics.checkNotNullParameter(list, "");
        EditorQuickReplyDialogFragment.o.getClass();
        FragmentManager supportFragmentManager = fragmentActivity.getSupportFragmentManager();
        Intrinsics.checkNotNullExpressionValue(supportFragmentManager, "");
        if (supportFragmentManager.findFragmentByTag("AiLabAgent.EditorQuickReplyDialogFragment") != null) {
            return;
        }
        EditorQuickReplyDialogFragment editorQuickReplyDialogFragment = new EditorQuickReplyDialogFragment();
        Bundle bundle = new Bundle();
        bundle.putString("action_location", str);
        if (refMessageInfo != null) {
            bundle.putString("quoted_asset", new Gson().toJson(refMessageInfo));
        }
        if (!list.isEmpty()) {
            bundle.putSerializable("selected_materials", new ArrayList(list));
        }
        if (str2 != null && str2.length() > 0) {
            bundle.putString("conversation_id", str2);
        }
        editorQuickReplyDialogFragment.setArguments(bundle);
        editorQuickReplyDialogFragment.show(supportFragmentManager, "AiLabAgent.EditorQuickReplyDialogFragment");
    }

    public static boolean M(Activity activity, String str, Map map, String str2, String str3) {
        String str4;
        if (map == null || !Intrinsics.areEqual(map.get("directly_open_history"), Boolean.TRUE)) {
            return false;
        }
        Map mapCreateMapBuilder = MapsKt__MapsJVMKt.createMapBuilder();
        LinkedHashMap linkedHashMap = new LinkedHashMap();
        for (Map.Entry entry : map.entrySet()) {
            Object key = entry.getKey();
            if (!Intrinsics.areEqual(key, "directly_open_history") && !Intrinsics.areEqual(key, "history_enter_source")) {
                linkedHashMap.put(entry.getKey(), entry.getValue());
            }
        }
        mapCreateMapBuilder.putAll(linkedHashMap);
        if (str2 != null && str2.length() > 0) {
            mapCreateMapBuilder.put("page_from", str2);
        }
        if (str3 != null && str3.length() > 0) {
            mapCreateMapBuilder.put("enter_source", str3);
        }
        Map mapBuild = MapsKt__MapsJVMKt.build(mapCreateMapBuilder);
        Object obj = map.get("history_enter_source");
        if (!(obj instanceof String) || (str4 = (String) obj) == null) {
            str4 = "";
        }
        HistoryActivity.Companion companion = HistoryActivity.B;
        HistoryActivity.HistoryLaunchMode historyLaunchMode = HistoryActivity.HistoryLaunchMode.STANDALONE;
        companion.getClass();
        INVOKEVIRTUAL_com_vega_ailabagent_service_AiLabAgentServiceImpl_com_vega_core_deeplink_DeeplinkIntentLancet_startActivity(activity, HistoryActivity.Companion.a(activity, str, 2, str4, historyLaunchMode, mapBuild));
        activity.overridePendingTransition(2130772051, 2130771980);
        return true;
    }

    /* JADX WARN: Code duplicated, block: B:16:0x0065  */
    @Override // com.vega.videoagentapi.IAiLabAgentService
    public final void j(Activity activity, View view, View view2, Map<String, ? extends Object> map, String str) {
        List list;
        Object objFirstOrNull;
        LifecycleOwner lifecycleOwner;
        String str2 = str;
        Intrinsics.checkNotNullParameter(activity, "");
        Bundle bundle = null;
        if (M(activity, "ailab_agent_v1.1", map, null, null)) {
            return;
        }
        SmartRoute smartRouteBuildRoute = SmartRouter.buildRoute(activity, "//ailab_agent/chat");
        smartRouteBuildRoute.withParam("tab_name", "ai_lab");
        if (map != null) {
            for (Map.Entry<String, ? extends Object> entry : map.entrySet()) {
                Object value = entry.getValue();
                if (value instanceof String) {
                    String key = entry.getKey();
                    Object value2 = entry.getValue();
                    Intrinsics.checkNotNull(value2, "");
                    smartRouteBuildRoute.withParam(key, (String) value2);
                } else if (value instanceof Integer) {
                    String key2 = entry.getKey();
                    Object value3 = entry.getValue();
                    Intrinsics.checkNotNull(value3, "");
                    smartRouteBuildRoute.withParam(key2, ((Integer) value3).intValue());
                } else if (value instanceof Long) {
                    String key3 = entry.getKey();
                    Object value4 = entry.getValue();
                    Intrinsics.checkNotNull(value4, "");
                    smartRouteBuildRoute.withParam(key3, ((Long) value4).longValue());
                } else if (value instanceof Boolean) {
                    String key4 = entry.getKey();
                    Object value5 = entry.getValue();
                    Intrinsics.checkNotNull(value5, "");
                    smartRouteBuildRoute.withParam(key4, ((Boolean) value5).booleanValue());
                } else if (value instanceof Float) {
                    String key5 = entry.getKey();
                    Object value6 = entry.getValue();
                    Intrinsics.checkNotNull(value6, "");
                    smartRouteBuildRoute.withParam(key5, ((Float) value6).floatValue());
                } else if (value instanceof Double) {
                    String key6 = entry.getKey();
                    Object value7 = entry.getValue();
                    Intrinsics.checkNotNull(value7, "");
                    smartRouteBuildRoute.withParam(key6, ((Double) value7).doubleValue());
                } else if (value instanceof Serializable) {
                    String key7 = entry.getKey();
                    Object value8 = entry.getValue();
                    Intrinsics.checkNotNull(value8, "");
                    smartRouteBuildRoute.withParam(key7, (Serializable) value8);
                } else if (value instanceof List) {
                    Object value9 = entry.getValue();
                    if ((value9 instanceof List) && (list = (List) value9) != null && (objFirstOrNull = CollectionsKt___CollectionsKt.firstOrNull(list)) != null) {
                        if (objFirstOrNull instanceof String) {
                            String key8 = entry.getKey();
                            ArrayList arrayList = new ArrayList();
                            for (Object obj : list) {
                                if (obj instanceof String) {
                                    arrayList.add(obj);
                                }
                            }
                            smartRouteBuildRoute.withParamStringList(key8, new ArrayList(arrayList));
                        } else if (objFirstOrNull instanceof Parcelable) {
                            String key9 = entry.getKey();
                            ArrayList arrayList2 = new ArrayList();
                            for (Object obj2 : list) {
                                if (obj2 instanceof Parcelable) {
                                    arrayList2.add(obj2);
                                }
                            }
                            smartRouteBuildRoute.withParamParcelableList(key9, new ArrayList(arrayList2));
                        }
                    }
                }
            }
        }
        smartRouteBuildRoute.withParam("agent_scene", "ailab_agent_v1.1");
        Intent intentBuildIntent = smartRouteBuildRoute.buildIntent();
        if (view != null) {
            bundle = ActivityOptionsCompat.makeSceneTransitionAnimation(activity, view, activity.getString(2131899095)).toBundle();
        } else {
            if (view2 != null) {
                bundle = ActivityOptionsCompat.makeSceneTransitionAnimation(activity, view2, activity.getString(2131899094)).toBundle();
            }
            UnifyAgentPerformanceMonitor.InputBox.c(UnifyAgentPerformanceMonitor.InputBox.a, "openUnifyAgentChatPage start");
            Ref.ObjectRef objectRef = new Ref.ObjectRef();
            if (str2 == null) {
                str2 = "tag_unified_agent_main_page";
            }
            objectRef.element = str2;
            if (!(activity instanceof LifecycleOwner) && (lifecycleOwner = (LifecycleOwner) activity) != null) {
                BuildersKt__Builders_commonKt.launch$default(LifecycleOwnerKt.a(lifecycleOwner), (CoroutineContext) null, (CoroutineStart) null, new openUnifyAgentChatPage.2(objectRef, activity, intentBuildIntent, bundle, (Continuation) null), 3, (Object) null);
                return;
            }
        }
        if (bundle != null) {
            if (view != null) {
                ViewUtils.a.getClass();
                intentBuildIntent.putExtra("shared_element_input_box_bottom", ViewUtils.a(view, activity));
            }
            intentBuildIntent.putExtra("has_shared_element_transition", true);
        }
        UnifyAgentPerformanceMonitor.InputBox.c(UnifyAgentPerformanceMonitor.InputBox.a, "openUnifyAgentChatPage start");
        Ref.ObjectRef objectRef2 = new Ref.ObjectRef();
        if (str2 == null) {
            str2 = "tag_unified_agent_main_page";
        }
        objectRef2.element = str2;
        if (!(activity instanceof LifecycleOwner)) {
        }
    }

    @Override // com.vega.videoagentapi.IAiLabAgentService
    public final void w(Activity activity, View view, String str, String str2, Map<String, ? extends Object> map) {
        List list;
        Object objFirstOrNull;
        Intrinsics.checkNotNullParameter(activity, "");
        if (M(activity, "trends_agent_v1.1", map, str, str2)) {
            return;
        }
        SmartRoute smartRouteBuildRoute = SmartRouter.buildRoute(activity, "//ailab_trends_agent/chat");
        smartRouteBuildRoute.withParam("agent_scene", "trends_agent_v1.1");
        if (str == null) {
            str = "";
        }
        smartRouteBuildRoute.withParam("page_from", str);
        if (str2 == null) {
            str2 = "";
        }
        smartRouteBuildRoute.withParam("enter_source", str2);
        smartRouteBuildRoute.withParam("tab_name", "edit");
        Bundle bundle = null;
        if (map != null) {
            for (Map.Entry<String, ? extends Object> entry : map.entrySet()) {
                Object value = entry.getValue();
                if (value instanceof String) {
                    String key = entry.getKey();
                    Object value2 = entry.getValue();
                    Intrinsics.checkNotNull(value2, "");
                    smartRouteBuildRoute.withParam(key, (String) value2);
                } else if (value instanceof Integer) {
                    String key2 = entry.getKey();
                    Object value3 = entry.getValue();
                    Intrinsics.checkNotNull(value3, "");
                    smartRouteBuildRoute.withParam(key2, ((Integer) value3).intValue());
                } else if (value instanceof Long) {
                    String key3 = entry.getKey();
                    Object value4 = entry.getValue();
                    Intrinsics.checkNotNull(value4, "");
                    smartRouteBuildRoute.withParam(key3, ((Long) value4).longValue());
                } else if (value instanceof Boolean) {
                    String key4 = entry.getKey();
                    Object value5 = entry.getValue();
                    Intrinsics.checkNotNull(value5, "");
                    smartRouteBuildRoute.withParam(key4, ((Boolean) value5).booleanValue());
                } else if (value instanceof Float) {
                    String key5 = entry.getKey();
                    Object value6 = entry.getValue();
                    Intrinsics.checkNotNull(value6, "");
                    smartRouteBuildRoute.withParam(key5, ((Float) value6).floatValue());
                } else if (value instanceof Double) {
                    String key6 = entry.getKey();
                    Object value7 = entry.getValue();
                    Intrinsics.checkNotNull(value7, "");
                    smartRouteBuildRoute.withParam(key6, ((Double) value7).doubleValue());
                } else if (value instanceof Serializable) {
                    String key7 = entry.getKey();
                    Object value8 = entry.getValue();
                    Intrinsics.checkNotNull(value8, "");
                    smartRouteBuildRoute.withParam(key7, (Serializable) value8);
                } else if (value instanceof List) {
                    Object value9 = entry.getValue();
                    if ((value9 instanceof List) && (list = (List) value9) != null && (objFirstOrNull = CollectionsKt___CollectionsKt.firstOrNull(list)) != null) {
                        if (objFirstOrNull instanceof String) {
                            String key8 = entry.getKey();
                            ArrayList arrayList = new ArrayList();
                            for (Object obj : list) {
                                if (obj instanceof String) {
                                    arrayList.add(obj);
                                }
                            }
                            smartRouteBuildRoute.withParamStringList(key8, new ArrayList(arrayList));
                        } else if (objFirstOrNull instanceof Parcelable) {
                            String key9 = entry.getKey();
                            ArrayList arrayList2 = new ArrayList();
                            for (Object obj2 : list) {
                                if (obj2 instanceof Parcelable) {
                                    arrayList2.add(obj2);
                                }
                            }
                            smartRouteBuildRoute.withParamParcelableList(key9, new ArrayList(arrayList2));
                        }
                    }
                }
            }
        }
        Intent intentBuildIntent = smartRouteBuildRoute.buildIntent();
        if (view != null && (bundle = ActivityOptionsCompat.makeSceneTransitionAnimation(activity, view, activity.getString(2131899095)).toBundle()) != null && view != null) {
            ViewUtils.a.getClass();
            intentBuildIntent.putExtra("shared_element_input_box_bottom", ViewUtils.a(view, activity));
        }
        if (!activity.isFinishing() && !activity.isDestroyed()) {
            try {
                INVOKEVIRTUAL_com_vega_ailabagent_service_AiLabAgentServiceImpl_com_vega_core_deeplink_DeeplinkIntentLancet_startActivity(activity, intentBuildIntent, bundle);
            } catch (Exception e) {
                BLog.e("AiLabAgent.VideoAgentServiceImpl", "openTrendsAgentChatPage: startActivity failed", e);
            }
        }
    }

    /* JADX WARN: Multi-variable type inference failed */
    @Override // com.vega.videoagentapi.IAiLabAgentService
    public final View D(final Context context, final Function0<Unit> function0, final Function0<Unit> function1, final Function1<? super Boolean, Unit> function2, final Function1<? super JSONObject, Unit> function3, boolean z, String str, final Function0<Unit> function4, final Function0<Unit> function5, final Function0<Unit> function6, final InputModalType inputModalType, String str2, String str3, final Function0<Triple<String, String, Integer>> function7) {
        final boolean z2;
        String strC;
        LifecycleOwner lifecycleOwner;
        LifecycleCoroutineScopeImpl lifecycleCoroutineScopeImplA;
        String str4 = str2;
        Intrinsics.checkNotNullParameter(context, "");
        Intrinsics.checkNotNullParameter(function0, "");
        Intrinsics.checkNotNullParameter(str, "");
        InputBoxReviseHelper.a.getClass();
        AgentChatInputBoxViewFixedShape agentChatInputBoxViewFixedShapeA = InputBoxReviseHelper.a(context);
        String strB = InputBoxReviseHelper.b();
        Intrinsics.checkNotNull(agentChatInputBoxViewFixedShapeA, "");
        boolean z3 = true;
        if (str4 != null && str4.length() > 0) {
            z2 = true;
        } else {
            str4 = null;
            z2 = false;
        }
        Objects.toString(inputModalType);
        agentChatInputBoxViewFixedShapeA.setTransitionName(context.getString(2131899095));
        AiLabAgentInputBoxManager.t.getClass();
        final AiLabAgentInputBoxManagerObserver aiLabAgentInputBoxManagerObserver = new AiLabAgentInputBoxManagerObserver(str);
        ((List) AiLabAgentInputBoxManager.z.getValue()).add(new SoftReference(aiLabAgentInputBoxManagerObserver));
        if (strB == null) {
            strB = FunctionsKt.b(2131887956);
        }
        agentChatInputBoxViewFixedShapeA.d(InputBoxReviseHelper.c(new AgentChatInputBoxViewParams(z3, 2131240238, false, 0 == true ? 1 : 0, 0 == true ? 1 : 0, 0 == true ? 1 : 0, ConfigSettingsKt.a(Reflection.getOrCreateKotlinClass(AiLabAgentInputOptConfigSettings.class)).b(), 0 == true ? 1 : 0, z3, 2131239820, 2131239822, 2131239827, 2131239665, z3, strB, 0 == true ? 1 : 0, null, 0 == true ? 1 : 0, 2, 0 == true ? 1 : 0, 0 == true ? 1 : 0, z, 0 == true ? 1 : 0, 0 == true ? 1 : 0, 1068958076), true), aiLabAgentInputBoxManagerObserver, new AgentChatInputBoxViewUiListener() { // from class: com.vega.ailabagent.service.AiLabAgentServiceImpl$getInputBoxView$1$1
            @Override // com.vega.ailabagent.common.view.AgentChatInputBoxViewUiListener
            public final boolean f() {
                return false;
            }

            @Override // com.vega.ailabagent.common.view.AgentChatInputBoxViewUiListener
            public final void g() {
            }

            @Override // com.vega.ailabagent.common.view.AgentChatInputBoxViewUiListener
            public final boolean e() {
                Function0<Unit> function8 = function5;
                if (function8 != null) {
                    function8.invoke();
                    return true;
                }
                return true;
            }

            @Override // com.vega.ailabagent.common.view.AgentChatInputBoxViewUiListener
            public final boolean k() {
                Function0<Unit> function8 = function6;
                if (function8 != null) {
                    function8.invoke();
                    return true;
                }
                return true;
            }

            @Override // com.vega.ailabagent.common.view.AgentChatInputBoxViewUiListener
            public final boolean a() {
                Function0<Unit> function8 = function4;
                if (function8 != null) {
                    function8.invoke();
                }
                aiLabAgentInputBoxManagerObserver.p(9, null);
                return true;
            }

            @Override // com.vega.ailabagent.common.view.AgentChatInputBoxViewUiListener
            public final InputBoxToolIconDecorator l() {
                InputBoxReviseHelper inputBoxReviseHelper = InputBoxReviseHelper.a;
                Context context2 = context;
                AiLabAgentInputBoxManagerObserver aiLabAgentInputBoxManagerObserver2 = aiLabAgentInputBoxManagerObserver;
                inputBoxReviseHelper.getClass();
                Intrinsics.checkNotNullParameter(context2, "");
                Intrinsics.checkNotNullParameter(aiLabAgentInputBoxManagerObserver2, "");
                return new InputBoxReviseHelper$getSettingToolIconDecorator$1(context2, aiLabAgentInputBoxManagerObserver2);
            }

            @Override // com.vega.ailabagent.common.view.AgentChatInputBoxViewUiListener
            public final boolean c() {
                Triple triple;
                String strH;
                String str5;
                String str6;
                Function0<Triple<String, String, Integer>> function8 = function7;
                Integer num = null;
                if (function8 != null) {
                    triple = (Triple) function8.invoke();
                } else {
                    triple = null;
                }
                IAiLabReporterService iAiLabReporterService = (IAiLabReporterService) SPIService.INSTANCE.getOrNullImpl(Reflection.getOrCreateKotlinClass(IAiLabReporterService.class));
                if (iAiLabReporterService != null) {
                    MultiContentCreationTaskTrackingPolicy multiContentCreationTaskTrackingPolicy = MultiContentCreationTaskTrackingPolicy.a;
                    boolean zA = MultiContentCreationTaskConfigSettingsKt.a();
                    Activity activityA = LvThemeContextKt.a(context);
                    if (activityA != null) {
                        strH = this.H(activityA);
                    } else {
                        strH = null;
                    }
                    multiContentCreationTaskTrackingPolicy.getClass();
                    String strA = MultiContentCreationTaskTrackingPolicy.a(strH, zA);
                    if (triple != null) {
                        str5 = (String) triple.getFirst();
                        str6 = (String) triple.getSecond();
                        num = (Integer) triple.getThird();
                    } else {
                        str5 = null;
                        str6 = null;
                    }
                    IAiLabReporterService.DefaultImpls.a(iAiLabReporterService, "click_expansion", strA, str5, str6, num, 4);
                }
                Function0<Unit> function9 = function1;
                if (function9 != null) {
                    function9.invoke();
                    return true;
                }
                return true;
            }

            @Override // com.vega.ailabagent.common.view.AgentChatInputBoxViewUiListener
            public final boolean j() {
                Triple triple;
                String str5;
                String str6;
                Function0<Triple<String, String, Integer>> function8 = function7;
                Integer num = null;
                if (function8 != null) {
                    triple = (Triple) function8.invoke();
                } else {
                    triple = null;
                }
                IAiLabReporterService iAiLabReporterService = (IAiLabReporterService) SPIService.INSTANCE.getOrNullImpl(Reflection.getOrCreateKotlinClass(IAiLabReporterService.class));
                if (iAiLabReporterService != null) {
                    if (triple != null) {
                        str5 = (String) triple.getFirst();
                        str6 = (String) triple.getSecond();
                        num = (Integer) triple.getThird();
                    } else {
                        str5 = null;
                        str6 = null;
                    }
                    IAiLabReporterService.DefaultImpls.a(iAiLabReporterService, "click_input", null, str5, str6, num, 6);
                }
                function0.invoke();
                return true;
            }

            @Override // com.vega.ailabagent.common.view.AgentChatInputBoxViewUiListener
            public final void b() {
                Object objCreateFailure;
                AiLabAgentInputBoxManager.Companion companion = AiLabAgentInputBoxManager.t;
                companion.getClass();
                try {
                    AiLabAgentInputData aiLabAgentInputData = (AiLabAgentInputData) AiLabAgentInputBoxManager.Companion.e().fromJson(companion.c(), AiLabAgentInputData.class);
                    Intrinsics.checkNotNull(aiLabAgentInputData);
                    AiLabAgentInputData aiLabAgentInputDataK = AiLabAgentInputData.k(aiLabAgentInputData, null, null, null, null, null, null, null, null, null, null, null, null, CollectionsKt__CollectionsKt.emptyList(), false, 0L, null, null, null, false, false, null, null, null, null, 33550335);
                    String json = AiLabAgentInputBoxManager.Companion.e().toJson(aiLabAgentInputDataK);
                    Intrinsics.checkNotNullExpressionValue(json, "");
                    AiLabAgentInputBoxManager.v.setValue(companion, AiLabAgentInputBoxManager.Companion.a[0], json);
                    AiLabAgentInputBoxManager.Companion.f(aiLabAgentInputDataK, "");
                    objCreateFailure = Unit.INSTANCE;
                    Result.constructor-impl(objCreateFailure);
                } catch (Throwable th) {
                    objCreateFailure = ResultKt.createFailure(th);
                    Result.constructor-impl(objCreateFailure);
                }
                Throwable th2 = Result.exceptionOrNull-impl(objCreateFailure);
                if (th2 != null) {
                    BLog.e("AiLabAgent.AiLabAgentInputBoxManager", "deleteSkill: " + th2);
                }
            }

            @Override // com.vega.ailabagent.common.view.AgentChatInputBoxViewUiListener
            public final boolean h() {
                Triple triple;
                String str5;
                String str6;
                Integer num;
                Function0<Triple<String, String, Integer>> function8 = function7;
                final Function0 function9 = null;
                if (function8 != null) {
                    triple = (Triple) function8.invoke();
                } else {
                    triple = null;
                }
                IAiLabReporterService iAiLabReporterService = (IAiLabReporterService) SPIService.INSTANCE.getOrNullImpl(Reflection.getOrCreateKotlinClass(IAiLabReporterService.class));
                if (iAiLabReporterService != null) {
                    if (triple != null) {
                        str5 = (String) triple.getFirst();
                        str6 = (String) triple.getSecond();
                        num = (Integer) triple.getThird();
                    } else {
                        str5 = null;
                        str6 = null;
                        num = null;
                    }
                    IAiLabReporterService.DefaultImpls.a(iAiLabReporterService, "click_voice", null, str5, str6, num, 6);
                }
                AiLabAgentServiceImpl aiLabAgentServiceImpl = this;
                Context context2 = context;
                final Function1<Boolean, Unit> function10 = function2;
                final Function0<Unit> function11 = new Function0<Unit>() { // from class: com.vega.ailabagent.service.AiLabAgentServiceImpl$getInputBoxView$1$1$onSpeechClick$1
                    /* JADX WARN: 'super' call moved to the top of the method (can break code semantics) */
                    /* JADX WARN: Multi-variable type inference failed */
                    {
                        super(0);
                    }

                    public final Object invoke() {
                        Function1<Boolean, Unit> function12 = function10;
                        if (function12 != null) {
                            function12.invoke(Boolean.TRUE);
                        }
                        return Unit.INSTANCE;
                    }
                };
                aiLabAgentServiceImpl.getClass();
                PermissionUtil permissionUtil = PermissionUtil.a;
                List listListOf = CollectionsKt__CollectionsJVMKt.listOf("android.permission.RECORD_AUDIO");
                permissionUtil.getClass();
                if (!PermissionUtil.j(context2, listListOf)) {
                    PermissionRequest.Companion companion = PermissionRequest.h;
                    Activity activityA = LvThemeContextKt.a(context2);
                    if (activityA != null) {
                        String strB2 = ModuleCommonKt.b(2131897998);
                        List listListOf2 = CollectionsKt__CollectionsJVMKt.listOf("android.permission.RECORD_AUDIO");
                        companion.getClass();
                        PermissionUtil.p(permissionUtil, PermissionRequest.Companion.a(activityA, strB2, listListOf2), new Function1<PermissionResult, Unit>() { // from class: com.vega.ailabagent.service.AiLabAgentServiceImpl$checkRecordPermission$1
                            public final /* synthetic */ String e = "android.permission.RECORD_AUDIO";

                            /* JADX WARN: 'super' call moved to the top of the method (can break code semantics) */
                            {
                                super(1);
                            }

                            public final Object invoke(Object obj) {
                                PermissionResult permissionResult = (PermissionResult) obj;
                                Intrinsics.checkNotNullParameter(permissionResult, "");
                                BLog.i("AiLabAgent.VideoAgentServiceImpl", "checkRecordPermission callback ");
                                if (permissionResult.a.containsAll(CollectionsKt__CollectionsJVMKt.listOf(this.e))) {
                                    BLog.i("AiLabAgent.VideoAgentServiceImpl", "checkRecordPermission  has permission ");
                                    Function0<Unit> function12 = function11;
                                    if (function12 != null) {
                                        function12.invoke();
                                    }
                                } else {
                                    Function0<Unit> function13 = function9;
                                    if (function13 != null) {
                                        function13.invoke();
                                    }
                                    BLog.i("AiLabAgent.VideoAgentServiceImpl", "checkRecordPermission  has reject ");
                                }
                                return Unit.INSTANCE;
                            }
                        }, 2);
                    }
                    Function1<Boolean, Unit> function12 = function2;
                    if (function12 != null) {
                        function12.invoke(Boolean.FALSE);
                    }
                } else {
                    Function1<Boolean, Unit> function13 = function2;
                    if (function13 != null) {
                        function13.invoke(Boolean.TRUE);
                    }
                }
                return true;
            }

            /* JADX WARN: Code duplicated, block: B:54:0x011b  */
            /* JADX WARN: Multi-variable type inference failed */
            @Override // com.vega.ailabagent.common.view.AgentChatInputBoxViewUiListener
            public final boolean i() throws JSONException {
                String toneEffectId;
                Object[] objArr;
                AiLabAgentInputData aiLabAgentInputData = (AiLabAgentInputData) aiLabAgentInputBoxManagerObserver.m().getValue();
                JSONObject jSONObject = null;
                visualStyle = null;
                VisualStyle visualStyle = null;
                if (aiLabAgentInputData != null) {
                    AiLabAgentReportAbility.c0.getClass();
                    JSONObject jSONObject2 = new JSONObject();
                    ArrayList arrayList = new ArrayList();
                    Iterator<T> it = aiLabAgentInputData.t().iterator();
                    while (true) {
                        String str5 = "image";
                        if (!it.hasNext()) {
                            break;
                        }
                        if (((SugMaterialInfo) it.next()).a != 0) {
                            str5 = "video";
                        }
                        arrayList.add(str5);
                    }
                    Iterator<T> it2 = aiLabAgentInputData.l().iterator();
                    while (it2.hasNext()) {
                        if (((GalleryData) it2.next()).getType() == 0) {
                            objArr = "image";
                        } else {
                            objArr = "video";
                        }
                        arrayList.add(objArr);
                    }
                    if (!arrayList.isEmpty()) {
                        jSONObject2.put("material_num", arrayList.size());
                        jSONObject2.put("material_type", CollectionsKt.j(arrayList, ",", (CharSequence) null, (CharSequence) null, 0, (Function1) null, 62));
                    }
                    ToneInfo toneInfoU = aiLabAgentInputData.u();
                    if (toneInfoU == null || (toneEffectId = toneInfoU.getToneEffectId()) == null || !ExtentionKt.isNotNullOrEmpty(toneEffectId)) {
                        toneInfoU = null;
                    }
                    VideoRatio videoRatioR = aiLabAgentInputData.r();
                    if (videoRatioR == null || Intrinsics.areEqual(videoRatioR.b(), "unselect")) {
                        videoRatioR = null;
                    }
                    DigitalHumanPresenterModel digitalHumanPresenterModelM = aiLabAgentInputData.m();
                    if (digitalHumanPresenterModelM != null) {
                        DigitalHumanPanelDataViewModel.c0.getClass();
                        if (Intrinsics.areEqual(digitalHumanPresenterModelM, DigitalHumanPanelDataViewModel.e0)) {
                            digitalHumanPresenterModelM = null;
                        }
                    } else {
                        digitalHumanPresenterModelM = null;
                    }
                    VisualStyle visualStyleX = aiLabAgentInputData.x();
                    if (visualStyleX != null && !Intrinsics.areEqual(visualStyleX.b(), "unselect")) {
                        visualStyle = visualStyleX;
                    }
                    if (videoRatioR != null) {
                        jSONObject2.put("aspect_ratio", videoRatioR.d());
                    }
                    if (visualStyle != null) {
                        jSONObject2.put("effect_name", visualStyle.e());
                        jSONObject2.put("effect_id", visualStyle.a());
                    }
                    if (toneInfoU != null) {
                        jSONObject2.put("voiceover_id", toneInfoU.getItemId());
                        jSONObject2.put("voiceover_name", toneInfoU.getToneEffectName());
                    }
                    if (digitalHumanPresenterModelM != null) {
                        jSONObject2.put("avatar_id", digitalHumanPresenterModelM.l());
                        jSONObject2.put("avatar_name", digitalHumanPresenterModelM.j());
                    }
                    jSONObject = jSONObject2;
                }
                Function1<JSONObject, Unit> function8 = function3;
                if (function8 != null) {
                    function8.invoke(jSONObject);
                }
                return true;
            }

            @Override // com.vega.ailabagent.common.view.AgentChatInputBoxViewUiListener
            public final void d(SpeechInputSessionResult speechInputSessionResult) {
                Intrinsics.checkNotNullParameter(speechInputSessionResult, "");
            }
        });
        if (inputModalType != null) {
            aiLabAgentInputBoxManagerObserver.w(new Function1<AiLabAgentInputData, AiLabAgentInputData>() { // from class: com.vega.ailabagent.service.AiLabAgentServiceImpl$getInputBoxView$1$2$1
                /* JADX WARN: 'super' call moved to the top of the method (can break code semantics) */
                {
                    super(1);
                }

                public final Object invoke(Object obj) {
                    AiLabAgentInputData aiLabAgentInputData = (AiLabAgentInputData) obj;
                    Intrinsics.checkNotNullParameter(aiLabAgentInputData, "");
                    if (z2) {
                        return AiLabAgentInputData.k(aiLabAgentInputData, null, null, null, null, null, null, null, null, null, null, null, inputModalType.a, null, false, 0L, null, null, null, false, false, null, null, null, null, 33552383);
                    }
                    return AiLabAgentInputData.k(aiLabAgentInputData, null, null, null, null, null, null, null, null, null, null, null, inputModalType.a, null, false, 0L, null, null, null, false, false, null, null, null, null, 33552255);
                }
            });
        }
        if (str4 != null) {
            if (Intrinsics.areEqual(str3, "seedance2.0")) {
                strC = "seedance2_v2";
            } else {
                strC = ConfigSettingsKt.a(Reflection.getOrCreateKotlinClass(AiLabAgentConfigSettings.class)).c();
                if (!(!StringsKt__StringsKt.isBlank(strC)) || strC == null) {
                    strC = "ai_trend_v2";
                }
            }
            TrendsModelCacheManager.a.getClass();
            TrendsAgentModel trendsAgentModelC = TrendsModelCacheManager.c(strC, str4);
            if (trendsAgentModelC != null) {
                aiLabAgentInputBoxManagerObserver.w(new AiLabAgentServiceImpl$writeTargetModelToInputData$1(trendsAgentModelC));
            } else {
                LifecycleOwner lifecycleOwnerA = LvThemeContextKt.a(context);
                if (!(lifecycleOwnerA instanceof LifecycleOwner) || (lifecycleOwner = lifecycleOwnerA) == null || (lifecycleCoroutineScopeImplA = LifecycleOwnerKt.a(lifecycleOwner)) == null) {
                    BLog.w("AiLabAgent.VideoAgentServiceImpl", "applyDeeplinkTargetModel: no LifecycleOwner from context, skip async fetch");
                } else {
                    BuildersKt__Builders_commonKt.launch$default(lifecycleCoroutineScopeImplA, Dispatchers.getIO(), (CoroutineStart) null, new AiLabAgentServiceImpl$applyDeeplinkTargetModel$2(strC, str4, this, aiLabAgentInputBoxManagerObserver, null), 2, (Object) null);
                }
            }
        }
        agentChatInputBoxViewFixedShapeA.addOnAttachStateChangeListener(new View.OnAttachStateChangeListener() { // from class: com.vega.ailabagent.service.AiLabAgentServiceImpl$getInputBoxView$1$4
            @Override // android.view.View.OnAttachStateChangeListener
            public final void onViewAttachedToWindow(View view) {
                Intrinsics.checkNotNullParameter(view, "");
            }

            @Override // android.view.View.OnAttachStateChangeListener
            public final void onViewDetachedFromWindow(View view) {
                Intrinsics.checkNotNullParameter(view, "");
                AiLabAgentInputBoxManager.Companion companion = AiLabAgentInputBoxManager.t;
                AiLabAgentInputBoxManagerObserver aiLabAgentInputBoxManagerObserver2 = aiLabAgentInputBoxManagerObserver;
                companion.getClass();
                Intrinsics.checkNotNullParameter(aiLabAgentInputBoxManagerObserver2, "");
                for (SoftReference softReference : (List) AiLabAgentInputBoxManager.z.getValue()) {
                    if (Intrinsics.areEqual(softReference.get(), aiLabAgentInputBoxManagerObserver2)) {
                        AiLabAgentInputBoxManager.t.getClass();
                        ((List) AiLabAgentInputBoxManager.z.getValue()).remove(softReference);
                        Objects.toString(softReference);
                    }
                }
                softReference = null;
                Objects.toString(softReference);
            }
        });
        return agentChatInputBoxViewFixedShapeA;
    }
}
