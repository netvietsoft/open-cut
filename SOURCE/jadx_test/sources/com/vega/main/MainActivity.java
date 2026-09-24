package com.vega.main;

import X.0Ob;
import X.0Oc;
import X.0es;
import X.1jZ;
import X.1ji;
import X.2FM;
import X.2JX;
import X.2JY;
import X.2JZ;
import android.R;
import android.animation.Animator;
import android.app.Application;
import android.app.Dialog;
import android.appwidget.AppWidgetManager;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.os.Build;
import android.os.Bundle;
import android.os.Looper;
import android.os.SystemClock;
import android.view.Choreographer;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewGroup;
import android.view.ViewStub;
import android.view.ViewTreeObserver;
import android.view.Window;
import androidx.activity.result.ActivityResult;
import androidx.core.view.ViewCompat;
import androidx.lifecycle.LifecycleOwnerKt;
import com.airbnb.lottie.LottieAnimationView;
import com.bytedance.bpea.transmit.delegate.BPEAHandler;
import com.bytedance.bpea.transmit.hook.HandlerHook;
import com.bytedance.helios.statichook.api.ExtraInfo;
import com.bytedance.helios.statichook.api.HeliosApiHook;
import com.bytedance.helios.statichook.lifecycle.ActivityLifecycleHook;
import com.bytedance.keva.Keva;
import com.bytedance.monitor.collector.DoFrameBooster;
import com.bytedance.otis.ultimate.inflater.UltimateInflater;
import com.bytedance.router.SmartRoute;
import com.bytedance.router.SmartRouter;
import com.bytedance.sysoptimizer.EnterTransitionCrashOptimizer;
import com.facebook.drawee.view.SimpleDraweeView;
import com.kanyun.kace.AndroidExtensionsBase;
import com.lemon.account.AccessConfig;
import com.lemon.account.IAccountService;
import com.lemon.account.VeryImportantConfig;
import com.lemon.cloud.ICloudService;
import com.lemon.config.business.IBusinessAccount;
import com.lemon.lv.config.InboxCreatorAssistantSetting;
import com.lemon.vega.ug.api.INewUserAcceptanceService;
import com.lemon.vega.ug.api.IPreinstallPhotoEditPromoService;
import com.lemon.youtube.IYoutubePopupService;
import com.lm.components.lynx.msgcenter.LynxMsgCenter;
import com.lm.components.report.ReportManager;
import com.lm.components.utils.ToastUtils;
import com.vega.ad.report.AdLaunchMonitor;
import com.vega.adeditorapi.IAdQuestionHelper;
import com.vega.business.ad.api.IAdService;
import com.vega.business.ad.data.report.AdInitTaskRecorder;
import com.vega.config.ConfigSettingsKt;
import com.vega.core.annotation.IPopCenterProvider;
import com.vega.core.api.LoginService;
import com.vega.core.api.PopContextService;
import com.vega.core.api.account.ILoginResultHandler;
import com.vega.core.api.account.LoginResultHandler;
import com.vega.core.context.ContextExtHelper;
import com.vega.core.context.ContextExtKt;
import com.vega.core.context.IHostEnv;
import com.vega.core.context.SPIService;
import com.vega.core.ext.ExtentionKt;
import com.vega.core.ext.FunctionKt;
import com.vega.core.ext.LiveDataExtKt;
import com.vega.core.popmanager.PopMock;
import com.vega.core.popmanager.popup.PopCenter;
import com.vega.core.popmanager.popup.PopStage;
import com.vega.core.utils.DirectoryUtil;
import com.vega.core.utils.FunctionsKt;
import com.vega.core.utils.LiveDataExKt;
import com.vega.core.utils.LocationUtils;
import com.vega.core.utils.SizeUtil;
import com.vega.cutsameapi.utils.OverseaCutSameTipsHelper;
import com.vega.edit.base.utils.ActivityForResultProxy;
import com.vega.feedx.Community;
import com.vega.feedx.api.IPrivacyDialog;
import com.vega.feedx.main.service.IMessageService;
import com.vega.feedx.util.home.FeedTabAnimationHelper;
import com.vega.gallery.export.GalleryManager;
import com.vega.homepage.utils.UserPageRedDotManager;
import com.vega.infrastructure.extensions.ActivityExtKt;
import com.vega.infrastructure.extensions.ThreadUtilKt;
import com.vega.infrastructure.extensions.ViewExtKt;
import com.vega.infrastructure.util.SystemUtils;
import com.vega.kv.KvStorage;
import com.vega.libdeveloper.aivideoagent.IAgentPlaybackHandler;
import com.vega.log.BLog;
import com.vega.lynx.IMainLynxSchemeCapCut;
import com.vega.lynx.handler.PendingActivityResultHandler;
import com.vega.main.appwidget.LargeWidgetProvider;
import com.vega.main.appwidget.MiddleWidgetProvider;
import com.vega.main.appwidget.RemoveBackgroundWidgetProvider;
import com.vega.main.appwidget.RetouchWidgetProvider;
import com.vega.main.appwidget.WidgetHelper;
import com.vega.main.appwidget.provider.MiddleTemplateWidgetProvider;
import com.vega.main.appwidget.provider.MiniTemplateWidgetProvider;
import com.vega.main.appwidget.provider.MiniToolWidgetProvider;
import com.vega.main.config.FlavorMainConfig;
import com.vega.main.home.ui.HomeTabRefreshViewContent;
import com.vega.main.home.viewmodel.BadgeType;
import com.vega.main.home.viewmodel.HomeViewModel;
import com.vega.main.precondition.PrivacyComponent;
import com.vega.main.questionnaire.ab.LocalQuestionnaireHelperV4;
import com.vega.main.questionnaire.ab.UserRoleUpdateListener;
import com.vega.main.ttdraft.TiktokDraftImportViewModel;
import com.vega.main.ui.IMainTabContent;
import com.vega.main.utils.TabTipsHelper;
import com.vega.main.utils.TipConfig;
import com.vega.main.widget.BottomBannerHelper;
import com.vega.main.widget.TikTokToEditDialog;
import com.vega.performance.BadParcelableExceptionOpt;
import com.vega.performance.DoFrameOptHelper;
import com.vega.performance.PerformanceManagerHelper;
import com.vega.property.optional.repo.CommonConfigRepository;
import com.vega.property.settings.AiLibraryAb;
import com.vega.property.usecase.common.ConfigUseCase;
import com.vega.report.IHybridReportForbiddenActivity;
import com.vega.report.ReportManagerWrapper;
import com.vega.share.ShareChannelManager;
import com.vega.shareapi.IShareApi;
import com.vega.start.MiddleBridgeLaunchOpt;
import com.vega.start.logic.StartLifeDispatcher;
import com.vega.start.statistic.AppLaunchTracker;
import com.vega.start.statistic.LaunchTracer;
import com.vega.start.statistic.StartLifeUsedTimeMonitor;
import com.vega.subscribe.SubscribeApi;
import com.vega.theme.ThemeUtils;
import com.vega.theme.config.IThemeProvider;
import com.vega.theme.config.LvThemeContext;
import com.vega.theme.config.Theme;
import com.vega.ui.BadgeButton;
import com.vega.ui.IImmerseActivity;
import com.vega.ui.activity.ActivitySystemBarExtensionsKt;
import com.vega.ui.activity.IActivityForResult;
import com.vega.ui.dialog.BaseDialog;
import com.vega.ui.dialog.ForceLogoutDialog;
import com.vega.ui.push.PushParams;
import com.vega.ui.start.IPopupRecorder;
import com.vega.ui.widget.OptXRadioGroup;
import com.vega.util.BoostSDK;
import com.vega.util.LoginResultCallback;
import com.vega.util.ToastUtilKt;
import com.vega.videoagentapi.unifyagent.save.IManualAssetSaveTipState;
import com.vega.videoagentapi.unifyagent.save.ManualAssetSaveTipRule;
import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;
import java.util.Objects;
import java.util.concurrent.CopyOnWriteArrayList;
import java.util.concurrent.CountDownLatch;
import kotlin.Lazy;
import kotlin.LazyKt__LazyJVMKt;
import kotlin.LazyThreadSafetyMode;
import kotlin.Pair;
import kotlin.Result;
import kotlin.ResultKt;
import kotlin.TuplesKt;
import kotlin.Unit;
import kotlin.collections.MapsKt__MapsKt;
import kotlin.coroutines.Continuation;
import kotlin.coroutines.CoroutineContext;
import kotlin.jvm.functions.Function0;
import kotlin.jvm.functions.Function1;
import kotlin.jvm.functions.Function3;
import kotlin.jvm.internal.Intrinsics;
import kotlin.jvm.internal.Reflection;
import kotlinx.coroutines.BuildersKt__Builders_commonKt;
import kotlinx.coroutines.CoroutineStart;
import kotlinx.coroutines.Dispatchers;
import org.json.JSONException;
import org.json.JSONObject;

/* JADX INFO: loaded from: D:\Decompiler\App\Video\Capcut\extracted\classes15.dex */
public final class MainActivity extends BaseMainActivity implements IThemeProvider, IImmerseActivity, IPopCenterProvider, ILoginResultHandler<MainActivity>, IActivityForResult, IHybridReportForbiddenActivity, PopCenter.IPopStageChangeListener, LoginResultCallback {
    public static final Companion K1 = new Companion();
    public static final Lazy<IAccountService> L1 = LazyKt__LazyJVMKt.lazy(new Function0<IAccountService>() { // from class: com.vega.main.MainActivity$Companion$accountService$2
        public final Object invoke() {
            return SPIService.INSTANCE.getImpl(Reflection.getOrCreateKotlinClass(IAccountService.class), (String) null);
        }
    });
    public static final Lazy<FlavorMainConfig> M1 = LazyKt__LazyJVMKt.lazy(Companion.flavorMainConfig.2.e);
    public TikTokToEditDialog C1;
    public boolean E1;
    public BadgeButton F1;
    public LoginResultHandler y1;
    public Function3<? super Integer, ? super Integer, ? super Intent, Unit> z1;
    public final Lazy s1 = LazyKt__LazyJVMKt.lazy(new Function0<OverseaCutSameTipsHelper>() { // from class: com.vega.main.MainActivity$cutSameTipsHelper$2
        {
            super(0);
        }

        public final Object invoke() {
            OverseaCutSameTipsHelper overseaCutSameTipsHelper = new OverseaCutSameTipsHelper();
            final MainActivity mainActivity = this.e;
            overseaCutSameTipsHelper.b = new Function0<Unit>() { // from class: com.vega.main.MainActivity$cutSameTipsHelper$2$1$1
                {
                    super(0);
                }

                public final Object invoke() {
                    AndroidExtensionsBase androidExtensionsBase = mainActivity;
                    Intrinsics.checkNotNull(androidExtensionsBase, "");
                    ((BadgeButton) androidExtensionsBase.findViewByIdCached(androidExtensionsBase, 2131310772, BadgeButton.class)).setChecked(true);
                    return Unit.INSTANCE;
                }
            };
            return overseaCutSameTipsHelper;
        }
    });
    public final Lazy t1 = LazyKt__LazyJVMKt.lazy(new Function0<TabTipsHelper>() { // from class: com.vega.main.MainActivity$tabTipsHelper$2
        public final Object invoke() {
            TabTipsHelper tabTipsHelper = new TabTipsHelper();
            MainActivity$tabTipsHelper$2$1$1 mainActivity$tabTipsHelper$2$1$1 = new Function0<Unit>() { // from class: com.vega.main.MainActivity$tabTipsHelper$2$1$1
                public final /* bridge */ /* synthetic */ Object invoke() {
                    return Unit.INSTANCE;
                }
            };
            Intrinsics.checkNotNullParameter(mainActivity$tabTipsHelper$2$1$1, "");
            tabTipsHelper.c = mainActivity$tabTipsHelper$2$1$1;
            MainActivity$tabTipsHelper$2$1$2 mainActivity$tabTipsHelper$2$1$2 = new Function0<Unit>() { // from class: com.vega.main.MainActivity$tabTipsHelper$2$1$2
                public final /* bridge */ /* synthetic */ Object invoke() {
                    return Unit.INSTANCE;
                }
            };
            Intrinsics.checkNotNullParameter(mainActivity$tabTipsHelper$2$1$2, "");
            tabTipsHelper.d = mainActivity$tabTipsHelper$2$1$2;
            return tabTipsHelper;
        }
    });
    public final MainActivity$configUpdateListener$1 u1 = new UserRoleUpdateListener() { // from class: com.vega.main.MainActivity$configUpdateListener$1
        @Override // com.vega.main.questionnaire.ab.UserRoleUpdateListener
        public final void onConfigUpdate() {
            this.a.h2().s.postValue(Boolean.TRUE);
        }
    };
    public final ActivityForResultProxy v1 = new ActivityForResultProxy(this);
    public final HomeTabRefreshViewContent w1 = new HomeTabRefreshViewContent();
    public final Lazy x1 = LazyKt__LazyJVMKt.lazy(new Function0<LvThemeContext>() { // from class: com.vega.main.MainActivity$themeContext$2
        {
            super(0);
        }

        public final Object invoke() {
            MainActivity mainActivity = this.e;
            ThemeUtils.a.getClass();
            LvThemeContext lvThemeContext = new LvThemeContext(mainActivity, ThemeUtils.b);
            lvThemeContext.b(true);
            return lvThemeContext;
        }
    });
    public final long A1 = 8000;
    public final Lazy B1 = LazyKt__LazyJVMKt.lazy(LazyThreadSafetyMode.NONE, new MainActivity$special$.inlined.koinViewModel.default.1(this));
    public boolean D1 = true;
    public final Lazy G1 = LazyKt__LazyJVMKt.lazy(new draftBuildingProgressDialog.2(this));
    public final MainActivity$lynxToNativeCallback$1 H1 = new Function3<String, JSONObject, Function1<? super Object, ? extends Unit>, Unit>() { // from class: com.vega.main.MainActivity$lynxToNativeCallback$1
        public final Object invoke(Object obj, Object obj2, Object obj3) {
            JSONObject jSONObjectOptJSONObject;
            String strOptString;
            JSONObject jSONObject = (JSONObject) obj2;
            Intrinsics.checkNotNullParameter(obj, "");
            Intrinsics.checkNotNullParameter(obj3, "");
            if (Intrinsics.areEqual(obj, "updateActivityBadgeStatus") && jSONObject != null && (jSONObjectOptJSONObject = jSONObject.optJSONObject("data")) != null && (strOptString = jSONObjectOptJSONObject.optString("key")) != null) {
                UserPageRedDotManager.a.getClass();
                ((Keva) UserPageRedDotManager.e.getValue()).storeString(UserPageRedDotManager.d, strOptString);
                BLog.i(UserPageRedDotManager.b, "saveHomePageMaterialKey = ".concat(strOptString));
                HomeViewModel homeViewModelH2 = this.a.h2();
                homeViewModelH2.A = false;
                homeViewModelH2.p6();
            }
            return Unit.INSTANCE;
        }
    };
    public final long I1 = 10000;
    public final CountDownLatch J1 = new CountDownLatch(1);

    public /* synthetic */ class WhenMappings {
        static {
            BadgeType.values();
        }
    }

    @Override // com.vega.main.BaseMainActivity
    public final void a3() {
    }

    @Override // com.vega.ui.start.BaseInfraActivity
    public final int m1() {
        return 0;
    }

    /* JADX WARN: Multi-variable type inference failed */
    @Override // com.vega.main.BaseMainActivity, com.vega.ui.accomponent.AcComponentActivity, com.vega.ui.start.BaseInfraActivity
    public final void onPause() {
        ActivityLifecycleHook.c(this);
        super.onPause();
    }

    /* JADX WARN: Multi-variable type inference failed */
    @Override // com.vega.ui.accomponent.AcComponentActivity, com.vega.ui.start.BaseInfraActivity
    public final void onStart() {
        ActivityLifecycleHook.e(this);
        super.onStart();
    }

    /* JADX WARN: Multi-variable type inference failed */
    @Override // com.vega.ui.accomponent.AcComponentActivity, com.vega.ui.start.BaseInfraActivity
    public final void onStop() {
        ActivityLifecycleHook.f(this);
        com_vega_main_MainActivity_com_bytedance_sysoptimizer_EnterTransitionLancet_onStop(this);
    }

    @Override // com.vega.theme.config.IThemeProvider
    public final Theme k2() {
        ThemeUtils.a.getClass();
        return ThemeUtils.b;
    }

    @Override // com.vega.main.BaseMainActivity
    public final void v2() {
        j3().o6(this);
    }

    public static final class Companion {
        public static IAccountService a() {
            return (IAccountService) MainActivity.L1.getValue();
        }
    }

    @Override // com.vega.main.BaseMainActivity
    public final TabTipsHelper.TabType R1() {
        return ((TabTipsHelper) this.t1.getValue()).b;
    }

    public final TiktokDraftImportViewModel j3() {
        return (TiktokDraftImportViewModel) this.B1.getValue();
    }

    public final int l0() {
        SystemUtils.a.getClass();
        return SystemUtils.c();
    }

    @Override // com.vega.main.BaseMainActivity
    public final LvThemeContext o2() {
        return (LvThemeContext) this.x1.getValue();
    }

    public final String Z() {
        return ((PopContextService) SPIService.INSTANCE.getImpl(Reflection.getOrCreateKotlinClass(PopContextService.class), (String) null)).b(this.v0.b);
    }

    /* JADX WARN: Multi-variable type inference failed */
    public final void r3() {
        IMainTabContent iMainTabContent;
        if (this.v0 == BaseMainActivity.Page.HOME) {
            IMainTabContent iMainTabContent2 = this.i0;
            if ((iMainTabContent2 instanceof IMainTabContent) && (iMainTabContent = iMainTabContent2) != null) {
                iMainTabContent.w0();
            }
        } else {
            ActivityExtKt.c(this, true);
        }
        ActivitySystemBarExtensionsKt.n(this, true);
    }

    @Override // com.vega.main.BaseMainActivity, com.vega.ui.start.BaseInfraActivity
    public final void y1() {
        if (PerformanceManagerHelper.blogEnable) {
            BLog.i(this.R, "realOnPause");
        }
        super.y1();
        StartLifeDispatcher.a.getClass();
        StartLifeDispatcher.h(5);
    }

    /* JADX WARN: Multi-variable type inference failed */
    @Override // com.vega.main.BaseMainActivity
    public final void M2() {
        super.M2();
        if (isDestroyed() || isFinishing()) {
            return;
        }
        HomeTabRefreshViewContent homeTabRefreshViewContent = this.w1;
        Intrinsics.checkNotNull(this, "");
        OptXRadioGroup optXRadioGroup = (OptXRadioGroup) findViewByIdCached(this, 2131305819, OptXRadioGroup.class);
        Intrinsics.checkNotNullExpressionValue(optXRadioGroup, "");
        homeTabRefreshViewContent.g(optXRadioGroup, this, l2());
    }

    @Override // com.vega.main.BaseMainActivity
    public final void V1() {
        MiddleBridgeLaunchOpt middleBridgeLaunchOpt = MiddleBridgeLaunchOpt.a;
        0es r2 = new 0es(this);
        middleBridgeLaunchOpt.getClass();
        BLog.i("sliver_launch_opt", "initDraftAttachment");
        if (MiddleBridgeLaunchOpt.c()) {
            MiddleBridgeLaunchOpt.b.add(r2);
        } else {
            r2.run();
        }
    }

    public final void h3() {
        LocalQuestionnaireHelperV4 localQuestionnaireHelperV4 = LocalQuestionnaireHelperV4.a;
        MainActivity$configUpdateListener$1 mainActivity$configUpdateListener$1 = this.u1;
        localQuestionnaireHelperV4.getClass();
        Intrinsics.checkNotNullParameter(mainActivity$configUpdateListener$1, "");
        if (PerformanceManagerHelper.blogEnable) {
            BLog.i("LocalQuestionnaireHelperV4", "registerConfigUpdateListener");
        }
        CopyOnWriteArrayList copyOnWriteArrayList = (CopyOnWriteArrayList) LocalQuestionnaireHelperV4.r;
        if (!copyOnWriteArrayList.contains(mainActivity$configUpdateListener$1)) {
            copyOnWriteArrayList.add(mainActivity$configUpdateListener$1);
        }
        localQuestionnaireHelperV4.a();
    }

    /* JADX WARN: Multi-variable type inference failed */
    public final void k3() {
        GalleryManager.a.getClass();
        if (GalleryManager.m()) {
            UltimateInflater.b(2131495884, getApplication().getBaseContext());
        } else {
            UltimateInflater.b(2131495883, getApplication().getBaseContext());
        }
    }

    /* JADX WARN: Multi-variable type inference failed */
    @Override // com.vega.ui.accomponent.AcComponentActivity, com.vega.ui.start.BaseInfraActivity
    public final void onDestroy() {
        ActivityLifecycleHook.b(this);
        ((Dialog) this.G1.getValue()).cancel();
        LocalQuestionnaireHelperV4 localQuestionnaireHelperV4 = LocalQuestionnaireHelperV4.a;
        MainActivity$configUpdateListener$1 mainActivity$configUpdateListener$1 = this.u1;
        localQuestionnaireHelperV4.getClass();
        Intrinsics.checkNotNullParameter(mainActivity$configUpdateListener$1, "");
        ((CopyOnWriteArrayList) LocalQuestionnaireHelperV4.r).remove(mainActivity$configUpdateListener$1);
        super.onDestroy();
        PopCenter.a.getClass();
        PopCenter.l.remove(this);
        LynxMsgCenter lynxMsgCenter = LynxMsgCenter.a;
        MainActivity$lynxToNativeCallback$1 mainActivity$lynxToNativeCallback$1 = this.H1;
        lynxMsgCenter.getClass();
        LynxMsgCenter.f("updateActivityBadgeStatus", mainActivity$lynxToNativeCallback$1);
    }

    @Override // com.vega.main.BaseMainActivity
    public final void H2() {
        SPIService sPIService = SPIService.INSTANCE;
        if (((LoginService) sPIService.getImpl(Reflection.getOrCreateKotlinClass(LoginService.class), (String) null)).isLogin()) {
            VeryImportantConfig.l(VeryImportantConfig.a, true, 1);
            if (BaseMainActivity.D2()) {
                BuildersKt__Builders_commonKt.launch$default(LifecycleOwnerKt.a(this), Dispatchers.getIO(), (CoroutineStart) null, new onLoginStatusChanged.1(this, (Continuation) null), 2, (Object) null);
            }
        } else if (BaseMainActivity.D2()) {
            HomeViewModel homeViewModelH2 = h2();
            homeViewModelH2.A = false;
            homeViewModelH2.p6();
            HomeViewModel homeViewModelH3 = h2();
            homeViewModelH3.z = 0L;
            homeViewModelH3.p6();
        }
        ((IShareApi) sPIService.getImpl(Reflection.getOrCreateKotlinClass(IShareApi.class), (String) null)).d().getClass();
        ShareChannelManager.k = false;
        BuildersKt__Builders_commonKt.launch$default(LifecycleOwnerKt.a(this), Dispatchers.getIO(), (CoroutineStart) null, new onLoginStatusChanged.2((Continuation) null), 2, (Object) null);
    }

    public final BadgeButton i3() {
        Object objCreateFailure;
        Object obj = null;
        try {
            K1.getClass();
            if (((FlavorMainConfig) M1.getValue()).e()) {
                Intrinsics.checkNotNull(this, "");
                return (BadgeButton) findViewByIdCached(this, 2131310731, BadgeButton.class);
            }
            if (((AccessConfig) SPIService.INSTANCE.getImpl(Reflection.getOrCreateKotlinClass(AccessConfig.class), (String) null)).l()) {
                Intrinsics.checkNotNull(this, "");
                return (BadgeButton) findViewByIdCached(this, 2131310772, BadgeButton.class);
            }
            Result.constructor-impl((Object) null);
            objCreateFailure = null;
            Throwable th = Result.exceptionOrNull-impl(objCreateFailure);
            if (th != null) {
                BLog.e(this.R, "getRealTemplateTab " + th.getMessage());
            }
            if (!Result.isFailure-impl(objCreateFailure)) {
                obj = objCreateFailure;
            }
            return (BadgeButton) obj;
        } catch (Throwable th2) {
            objCreateFailure = ResultKt.createFailure(th2);
            Result.constructor-impl(objCreateFailure);
        }
    }

    /* JADX WARN: Multi-variable type inference failed */
    public final void m3() {
        Function0 function0;
        TemplateRegionSupplier templateRegionSupplier = TemplateRegionSupplier.a;
        if (!TemplateRegionSupplier.c) {
            templateRegionSupplier.getClass();
            if (!TemplateRegionSupplier.d && (function0 = TemplateRegionSupplier.b) != null) {
                function0.invoke();
                TemplateRegionSupplier.d = true;
            }
        } else {
            templateRegionSupplier.getClass();
        }
        TemplateRegionSupplier.c = true;
        if (PerformanceManagerHelper.blogEnable) {
            BLog.i(this.R, "LocationUtils.init");
        }
        LocationUtils locationUtils = LocationUtils.a;
        Intrinsics.checkNotNullExpressionValue(getApplicationContext(), "");
        refreshRegionAndConfig.1 r0 = new refreshRegionAndConfig.1(this);
        locationUtils.getClass();
        r0.invoke();
        new BPEAHandler(Looper.getMainLooper()).postDelayed(new 0Oc(this), this.A1);
    }

    @Override // com.vega.main.BaseMainActivity, com.vega.ui.start.BaseInfraActivity
    public final void z1() {
        StartLifeUsedTimeMonitor.a.getClass();
        if (StartLifeUsedTimeMonitor.m == 0) {
            LaunchTracer.c(LaunchTracer.a, LaunchTracer.Module.a, "ActivityRealOnResume");
            StartLifeUsedTimeMonitor.m("actRealOnResumeStart");
            StartLifeUsedTimeMonitor.m = SystemClock.uptimeMillis();
        }
        super.z1();
        if (StartLifeUsedTimeMonitor.n != 0) {
            return;
        }
        LaunchTracer launchTracer = LaunchTracer.a;
        LaunchTracer.Module module = LaunchTracer.Module.a;
        launchTracer.getClass();
        LaunchTracer.a(module, "ActivityRealOnResume");
        LaunchTracer.c(launchTracer, module, "ActivityResumeToFrame");
        StartLifeUsedTimeMonitor.m("actRealOnResumeEnd");
        StartLifeUsedTimeMonitor.n = SystemClock.uptimeMillis();
    }

    /* JADX WARN: Multi-variable type inference failed */
    @Override // com.vega.main.BaseMainActivity
    public final void W1() {
        super.W1();
        if (this.q0 != null && ContextExtKt.app().h()) {
            IPrivacyDialog iPrivacyDialog = this.q0;
            if (iPrivacyDialog != null) {
                iPrivacyDialog.a();
            }
            this.q0 = null;
        }
        if (INVOKEVIRTUAL_com_vega_main_MainActivity_com_vega_launcher_lancet_BadParcelableLancet_getInttent(this).getBooleanExtra("key_need_show_tt_enter_detail_dialog", false)) {
            Community.a.getClass();
            Community.d().e(this);
        }
        SPIService sPIService = SPIService.INSTANCE;
        ((IShareApi) sPIService.getImpl(Reflection.getOrCreateKotlinClass(IShareApi.class), (String) null)).m().k(this);
        Pair pairI = ((INewUserAcceptanceService) sPIService.getImpl(Reflection.getOrCreateKotlinClass(INewUserAcceptanceService.class), (String) null)).i();
        final int iIntValue = ((Number) pairI.getFirst()).intValue();
        final boolean zBooleanValue = ((Boolean) pairI.getSecond()).booleanValue();
        if (iIntValue != -1) {
            ThreadUtilKt.b(500L, new Function0<Unit>() { // from class: com.vega.main.MainActivity$doRealResumeAction$1
                /* JADX WARN: 'super' call moved to the top of the method (can break code semantics) */
                {
                    super(0);
                }

                public final Object invoke() {
                    final BadgeButton badgeButtonI3;
                    final int i;
                    final AndroidExtensionsBase androidExtensionsBase = this.e;
                    int i2 = iIntValue;
                    boolean z = zBooleanValue;
                    androidExtensionsBase.getClass();
                    if (i2 != -1 && (badgeButtonI3 = androidExtensionsBase.i3()) != null) {
                        Intrinsics.checkNotNull(androidExtensionsBase, "");
                        if (Intrinsics.areEqual(badgeButtonI3, androidExtensionsBase.findViewByIdCached(androidExtensionsBase, 2131310731, BadgeButton.class))) {
                            i = 2131308054;
                        } else {
                            Intrinsics.checkNotNull(androidExtensionsBase, "");
                            if (Intrinsics.areEqual(badgeButtonI3, androidExtensionsBase.findViewByIdCached(androidExtensionsBase, 2131310772, BadgeButton.class))) {
                                i = 2131308062;
                            }
                        }
                        if (i2 != 0) {
                            if (i2 == 1) {
                                if (z) {
                                    Intrinsics.checkNotNull(androidExtensionsBase, "");
                                    BadgeButton badgeButton = (BadgeButton) androidExtensionsBase.findViewByIdCached(androidExtensionsBase, 2131310738, BadgeButton.class);
                                    Intrinsics.checkNotNullExpressionValue(badgeButton, "");
                                    androidExtensionsBase.p3(badgeButton, TabTipsHelper.TabType.EDIT, 2131889590, new Function0<Unit>() { // from class: com.vega.main.MainActivity$handleTTOnelinkLanding$1
                                        /* JADX WARN: 'super' call moved to the top of the method (can break code semantics) */
                                        {
                                            super(0);
                                        }

                                        public final Object invoke() {
                                            androidExtensionsBase.f3(badgeButtonI3, i, TabTipsHelper.TabType.EDIT);
                                            return Unit.INSTANCE;
                                        }
                                    });
                                } else {
                                    androidExtensionsBase.f3(badgeButtonI3, i, null);
                                }
                            }
                        } else if (z) {
                            androidExtensionsBase.p3(badgeButtonI3, TabTipsHelper.TabType.TEMPLATE, 2131889591, new Function0<Unit>() { // from class: com.vega.main.MainActivity$handleTTOnelinkLanding$2
                                {
                                    super(0);
                                }

                                public final Object invoke() {
                                    AndroidExtensionsBase androidExtensionsBase2 = androidExtensionsBase;
                                    Intrinsics.checkNotNull(androidExtensionsBase2, "");
                                    BadgeButton badgeButton2 = (BadgeButton) androidExtensionsBase2.findViewByIdCached(androidExtensionsBase2, 2131310738, BadgeButton.class);
                                    Intrinsics.checkNotNullExpressionValue(badgeButton2, "");
                                    androidExtensionsBase2.f3(badgeButton2, 2131308057, TabTipsHelper.TabType.TEMPLATE);
                                    androidExtensionsBase.h2().v.postValue(Boolean.TRUE);
                                    return Unit.INSTANCE;
                                }
                            });
                        } else {
                            Intrinsics.checkNotNull(androidExtensionsBase, "");
                            BadgeButton badgeButton2 = (BadgeButton) androidExtensionsBase.findViewByIdCached(androidExtensionsBase, 2131310738, BadgeButton.class);
                            Intrinsics.checkNotNullExpressionValue(badgeButton2, "");
                            androidExtensionsBase.f3(badgeButton2, 2131308057, null);
                        }
                    }
                    return Unit.INSTANCE;
                }
            });
        }
        BadgeButton badgeButton = this.F1;
        if (badgeButton != null) {
            AiLibraryAb.a.getClass();
            if (AiLibraryAb.Companion.a()) {
                ConfigUseCase.a.getClass();
                CommonConfigRepository commonConfigRepository = ConfigUseCase.b;
                commonConfigRepository.getClass();
                KvStorage kvStorage = CommonConfigRepository.f;
                if (!kvStorage.d("has_show_property_tips", false)) {
                    p3(badgeButton, TabTipsHelper.TabType.PROPERTY, 2131894435, new Function0<Unit>() { // from class: com.vega.main.MainActivity$doRealResumeAction$2$1
                        public final /* bridge */ /* synthetic */ Object invoke() {
                            return Unit.INSTANCE;
                        }
                    });
                } else {
                    IManualAssetSaveTipState iManualAssetSaveTipState = (IManualAssetSaveTipState) sPIService.getOrNullImpl(Reflection.getOrCreateKotlinClass(IManualAssetSaveTipState.class));
                    ManualAssetSaveTipRule manualAssetSaveTipRule = ManualAssetSaveTipRule.a;
                    commonConfigRepository.getClass();
                    boolean zD = kvStorage.d("has_show_property_save_tips", false);
                    manualAssetSaveTipRule.getClass();
                    if (iManualAssetSaveTipState != null && iManualAssetSaveTipState.b() && iManualAssetSaveTipState.c() && !zD) {
                        p3(badgeButton, TabTipsHelper.TabType.PROPERTY_SAVE, 2131894450, new Function0<Unit>() { // from class: com.vega.main.MainActivity$doRealResumeAction$2$2
                            public final /* bridge */ /* synthetic */ Object invoke() {
                                return Unit.INSTANCE;
                            }
                        });
                    }
                }
            }
        }
        BuildersKt__Builders_commonKt.launch$default(this, (CoroutineContext) null, (CoroutineStart) null, new tryShowPropertyDraftGuide.1(this, (Continuation) null), 3, (Object) null);
        ((IAdService) sPIService.getImpl(Reflection.getOrCreateKotlinClass(IAdService.class), (String) null)).s().i();
    }

    /* JADX WARN: Multi-variable type inference failed */
    @Override // com.vega.main.BaseMainActivity, com.vega.ui.accomponent.AcComponentActivity, com.vega.ui.start.BaseInfraActivity
    public final void onResume() {
        ActivityLifecycleHook.d(this);
        StartLifeUsedTimeMonitor.a.getClass();
        if (StartLifeUsedTimeMonitor.k == 0) {
            LaunchTracer.c(LaunchTracer.a, LaunchTracer.Module.a, "ActivityOnResume");
            StartLifeUsedTimeMonitor.m("actOnResumeStart");
            StartLifeUsedTimeMonitor.k = SystemClock.uptimeMillis();
        }
        super.onResume();
        DoFrameOptHelper.a.getClass();
        if (!DoFrameOptHelper.b) {
            synchronized (DoFrameBooster.class) {
                DoFrameBooster.a(Choreographer.getInstance());
            }
            DoFrameOptHelper.b = true;
        }
        DoFrameBooster.e = true;
        DoFrameBooster.f = 0;
        String stringExtra = INVOKEVIRTUAL_com_vega_main_MainActivity_com_vega_launcher_lancet_BadParcelableLancet_getInttent(this).getStringExtra("current_main_tab");
        if (ExtentionKt.isNotNullOrEmpty(stringExtra)) {
            if (Intrinsics.areEqual(stringExtra, "edit")) {
                Intrinsics.checkNotNull(this, "");
                OptXRadioGroup optXRadioGroup = (OptXRadioGroup) findViewByIdCached(this, 2131305819, OptXRadioGroup.class);
                int i = optXRadioGroup.a;
                if (2131308057 != i) {
                    if (i != -1) {
                        optXRadioGroup.R(i, false);
                    }
                    optXRadioGroup.R(2131308057, true);
                    optXRadioGroup.setCheckedId(2131308057);
                }
            }
            INVOKEVIRTUAL_com_vega_main_MainActivity_com_vega_launcher_lancet_BadParcelableLancet_getInttent(this).putExtra("current_main_tab", "");
        }
        StartLifeUsedTimeMonitor.b();
    }

    /* JADX WARN: Multi-variable type inference failed */
    @Override // com.vega.main.BaseMainActivity
    public final void A2() {
        String str;
        final View decorView;
        super.A2();
        LiveDataExKt.i(l2().v, this, new 2FM(this));
        LiveDataExKt.i(h2().y, this, new 1ji(this));
        SizeUtil.a.getClass();
        final int iA = SizeUtil.a(10.5f);
        Intrinsics.checkNotNull(this, "");
        ((BadgeButton) findViewByIdCached(this, 2131310738, BadgeButton.class)).s(2131234564, iA);
        Intrinsics.checkNotNull(this, "");
        ((BadgeButton) findViewByIdCached(this, 2131310731, BadgeButton.class)).s(BaseMainActivity.f2(), iA);
        Intrinsics.checkNotNull(this, "");
        ((BadgeButton) findViewByIdCached(this, 2131310761, BadgeButton.class)).s(2131234575, iA);
        Intrinsics.checkNotNull(this, "");
        ((BadgeButton) findViewByIdCached(this, 2131310779, BadgeButton.class)).s(2131234583, iA);
        Intrinsics.checkNotNull(this, "");
        ((BadgeButton) findViewByIdCached(this, 2131310772, BadgeButton.class)).s(BaseMainActivity.f2(), iA);
        Intrinsics.checkNotNull(this, "");
        ((BadgeButton) findViewByIdCached(this, 2131310719, BadgeButton.class)).s(2131234562, iA);
        m2().s(2131234577, iA);
        Window window = getWindow();
        if (window != null && (decorView = window.getDecorView()) != null) {
            if (ViewCompat.Api19Impl.b(decorView)) {
                ThreadUtilKt.d(new MainActivity$initMainTab$3$1(this, iA));
            } else {
                decorView.addOnAttachStateChangeListener(new View.OnAttachStateChangeListener() { // from class: com.vega.main.MainActivity$initMainTab$$inlined$doOnAttach$1
                    @Override // android.view.View.OnAttachStateChangeListener
                    public final void onViewDetachedFromWindow(View view) {
                    }

                    @Override // android.view.View.OnAttachStateChangeListener
                    public final void onViewAttachedToWindow(View view) {
                        decorView.removeOnAttachStateChangeListener(this);
                        ThreadUtilKt.d(new MainActivity$initMainTab$3$1(this, iA));
                    }
                });
            }
        }
        Intrinsics.checkNotNull(this, "");
        ((BadgeButton) findViewByIdCached(this, 2131310738, BadgeButton.class)).setRadioTextColor(2131235275);
        Intrinsics.checkNotNull(this, "");
        ((BadgeButton) findViewByIdCached(this, 2131310731, BadgeButton.class)).setRadioTextColor(2131235275);
        Intrinsics.checkNotNull(this, "");
        ((BadgeButton) findViewByIdCached(this, 2131310761, BadgeButton.class)).setRadioTextColor(2131235275);
        Intrinsics.checkNotNull(this, "");
        ((BadgeButton) findViewByIdCached(this, 2131310779, BadgeButton.class)).setRadioTextColor(2131235275);
        Intrinsics.checkNotNull(this, "");
        ((BadgeButton) findViewByIdCached(this, 2131310772, BadgeButton.class)).setRadioTextColor(2131235275);
        Intrinsics.checkNotNull(this, "");
        ((BadgeButton) findViewByIdCached(this, 2131310719, BadgeButton.class)).setRadioTextColor(2131235275);
        Intrinsics.checkNotNull(this, "");
        HandlerHook.viewPostDelay(findViewByIdCached(this, 2131310719, BadgeButton.class), new 1jZ(this), 1000L);
        m2().setRadioTextColor(2131235275);
        BadgeButton badgeButtonI3 = i3();
        if (badgeButtonI3 != null && badgeButtonI3.q()) {
            Community.a.getClass();
            if (Community.d().f() && (str = (String) e2().d.getValue()) != null) {
                int iHashCode = str.hashCode();
                if (iHashCode != 3075958) {
                    if (iHashCode == 102970646 && str.equals("light")) {
                        W2("initImmersiveConfig tabBarTheme default light");
                    }
                } else if (str.equals("dark")) {
                    V2("initImmersiveConfig tabBarTheme default dark");
                }
            }
        }
        Community.a.getClass();
        if (Community.d().E()) {
            e2().e.observe(this, new sam.androidx_lifecycle_Observer.0(new Function1<Boolean, Unit>() { // from class: com.vega.main.MainActivity$initImmersiveConfig$2
                {
                    super(1);
                }

                public final Object invoke(Object obj) {
                    LottieAnimationView lottieView;
                    LottieAnimationView lottieView2;
                    MainActivity mainActivity;
                    BaseMainActivity.Page page;
                    String str2;
                    final BadgeButton badgeButtonM2;
                    View viewInflate;
                    Boolean bool = (Boolean) obj;
                    Intrinsics.checkNotNull(bool);
                    if (bool.booleanValue() && ((page = (mainActivity = this.e).v0) == BaseMainActivity.Page.FEED || page == BaseMainActivity.Page.DISCOVER)) {
                        if (Intrinsics.areEqual(mainActivity.e2().d.getValue(), "light")) {
                            str2 = "immersive_tab_in_light.json";
                        } else {
                            str2 = "immersive_tab.json";
                        }
                        AndroidExtensionsBase androidExtensionsBase = this.e;
                        int iOrdinal = androidExtensionsBase.v0.ordinal();
                        if (iOrdinal != 0) {
                            if (iOrdinal != 1) {
                                if (iOrdinal != 3) {
                                    if (iOrdinal != 4) {
                                        if (iOrdinal != 7) {
                                            if (iOrdinal != 8) {
                                                if (iOrdinal != 9) {
                                                    Intrinsics.checkNotNull(androidExtensionsBase, "");
                                                    badgeButtonM2 = (BadgeButton) androidExtensionsBase.findViewByIdCached(androidExtensionsBase, 2131310738, BadgeButton.class);
                                                } else {
                                                    Intrinsics.checkNotNull(androidExtensionsBase, "");
                                                    badgeButtonM2 = (BadgeButton) androidExtensionsBase.findViewByIdCached(androidExtensionsBase, 2131310719, BadgeButton.class);
                                                }
                                            } else {
                                                badgeButtonM2 = androidExtensionsBase.m2();
                                            }
                                        } else {
                                            Intrinsics.checkNotNull(androidExtensionsBase, "");
                                            badgeButtonM2 = (BadgeButton) androidExtensionsBase.findViewByIdCached(androidExtensionsBase, 2131310731, BadgeButton.class);
                                        }
                                    } else {
                                        Intrinsics.checkNotNull(androidExtensionsBase, "");
                                        badgeButtonM2 = (BadgeButton) androidExtensionsBase.findViewByIdCached(androidExtensionsBase, 2131310779, BadgeButton.class);
                                    }
                                } else {
                                    Intrinsics.checkNotNull(androidExtensionsBase, "");
                                    badgeButtonM2 = (BadgeButton) androidExtensionsBase.findViewByIdCached(androidExtensionsBase, 2131310761, BadgeButton.class);
                                }
                            } else {
                                Intrinsics.checkNotNull(androidExtensionsBase, "");
                                badgeButtonM2 = (BadgeButton) androidExtensionsBase.findViewByIdCached(androidExtensionsBase, 2131310772, BadgeButton.class);
                            }
                        } else {
                            Intrinsics.checkNotNull(androidExtensionsBase, "");
                            badgeButtonM2 = (BadgeButton) androidExtensionsBase.findViewByIdCached(androidExtensionsBase, 2131310738, BadgeButton.class);
                        }
                        if (badgeButtonM2 != null) {
                            if (badgeButtonM2.x == null) {
                                ViewStub viewStub = badgeButtonM2.w;
                                LottieAnimationView lottieAnimationView = null;
                                if (viewStub != null) {
                                    viewInflate = viewStub.inflate();
                                } else {
                                    viewInflate = null;
                                }
                                if (viewInflate instanceof LottieAnimationView) {
                                    lottieAnimationView = (LottieAnimationView) viewInflate;
                                }
                                badgeButtonM2.x = lottieAnimationView;
                                if (lottieAnimationView != null) {
                                    int i = badgeButtonM2.B;
                                    lottieAnimationView.setPadding(i, i, i, i);
                                }
                            }
                            LottieAnimationView lottieAnimationView2 = badgeButtonM2.x;
                            if (lottieAnimationView2 != null) {
                                lottieAnimationView2.setAnimation(str2);
                                lottieAnimationView2.addAnimatorListener(new Animator.AnimatorListener() { // from class: com.vega.ui.BadgeButton$showLottieView$1$1
                                    @Override // android.animation.Animator.AnimatorListener
                                    public final void onAnimationRepeat(Animator animator) {
                                        Intrinsics.checkNotNullParameter(animator, "");
                                    }

                                    @Override // android.animation.Animator.AnimatorListener
                                    public final void onAnimationCancel(Animator animator) {
                                        Intrinsics.checkNotNullParameter(animator, "");
                                        badgeButtonM2.o();
                                    }

                                    @Override // android.animation.Animator.AnimatorListener
                                    public final void onAnimationEnd(Animator animator) {
                                        Intrinsics.checkNotNullParameter(animator, "");
                                        badgeButtonM2.o();
                                    }

                                    @Override // android.animation.Animator.AnimatorListener
                                    public final void onAnimationStart(Animator animator) {
                                        Intrinsics.checkNotNullParameter(animator, "");
                                        SimpleDraweeView simpleDraweeViewM125getImageView = badgeButtonM2.m125getImageView();
                                        if (simpleDraweeViewM125getImageView != null) {
                                            ViewExtKt.b(simpleDraweeViewM125getImageView);
                                        }
                                    }
                                });
                                ViewExtKt.e(lottieAnimationView2);
                                lottieAnimationView2.setOnTouchListener(new 2JX(badgeButtonM2));
                                lottieAnimationView2.setOnClickListener(new 2JY(badgeButtonM2));
                                lottieAnimationView2.playAnimation();
                            }
                        }
                        this.e.e2().getClass();
                        FeedTabAnimationHelper feedTabAnimationHelper = FeedTabAnimationHelper.a;
                        feedTabAnimationHelper.getClass();
                        BLog.i("FeedTabAnimationHelper", "record play time");
                        FeedTabAnimationHelper.i = true;
                        FeedTabAnimationHelper.j = 0;
                        FeedTabAnimationHelper.d.setValue(feedTabAnimationHelper, FeedTabAnimationHelper.b[0], Long.valueOf(System.currentTimeMillis()));
                    }
                    if (!bool.booleanValue()) {
                        AndroidExtensionsBase androidExtensionsBase2 = this.e;
                        Intrinsics.checkNotNull(androidExtensionsBase2, "");
                        BadgeButton badgeButton = (BadgeButton) androidExtensionsBase2.findViewByIdCached(androidExtensionsBase2, 2131310731, BadgeButton.class);
                        if (badgeButton != null && (lottieView2 = badgeButton.getLottieView()) != null) {
                            lottieView2.cancelAnimation();
                        }
                        AndroidExtensionsBase androidExtensionsBase3 = this.e;
                        Intrinsics.checkNotNull(androidExtensionsBase3, "");
                        BadgeButton badgeButton2 = (BadgeButton) androidExtensionsBase3.findViewByIdCached(androidExtensionsBase3, 2131310772, BadgeButton.class);
                        if (badgeButton2 != null && (lottieView = badgeButton2.getLottieView()) != null) {
                            lottieView.cancelAnimation();
                        }
                    }
                    return Unit.INSTANCE;
                }
            }));
        }
        Intrinsics.checkNotNull(this, "");
        View viewFindViewByIdCached = findViewByIdCached(this, 2131310754, View.class);
        Intrinsics.checkNotNullExpressionValue(viewFindViewByIdCached, "");
        ViewExtKt.d(viewFindViewByIdCached, true);
        j3().e.observe(this, new sam.androidx_lifecycle_Observer.0(new initMainTab.5(this)));
    }

    /* JADX WARN: Multi-variable type inference failed */
    @Override // com.vega.main.BaseMainActivity
    public final void onRestart() {
        Object objCreateFailure;
        boolean z;
        super.onRestart();
        ((IAdQuestionHelper) SPIService.INSTANCE.getImpl(Reflection.getOrCreateKotlinClass(IAdQuestionHelper.class), (String) null)).a(this);
        WidgetHelper.a.getClass();
        Intrinsics.checkNotNullParameter(this, "");
        BLog.i("Widget_Helper", "needCheck: " + WidgetHelper.c);
        if (WidgetHelper.c) {
            WidgetHelper.c = false;
            if (Build.VERSION.SDK_INT >= 26) {
                AppWidgetManager appWidgetManager = AppWidgetManager.getInstance(this);
                if (appWidgetManager.isRequestPinAppWidgetSupported()) {
                    try {
                        if (WidgetHelper.i().o()) {
                            BLog.i("Widget_Helper", "isInUgAppWidgetGuideExperiment: true");
                            return;
                        }
                        KvStorage kvStorage = WidgetHelper.b;
                        if (!kvStorage.d("widget_middle", false) && !kvStorage.d("widget_large", false) && !kvStorage.d("widget_small_retouch", false) && !kvStorage.d("widget_small_remove_bg", false)) {
                            z = false;
                        } else {
                            z = true;
                        }
                        BLog.i("Widget_Helper", "hasWidget: " + z);
                        if (z) {
                            return;
                        }
                        long jG = kvStorage.g("show_time", 0L);
                        long jCurrentTimeMillis = System.currentTimeMillis();
                        if (jCurrentTimeMillis - jG < 86400000) {
                            return;
                        }
                        int iF = kvStorage.f("show_count", 0);
                        BLog.i("Widget_Helper", "showCount: " + iF);
                        if (iF >= 3) {
                            return;
                        }
                        kvStorage.n(iF + 1, "show_count", false);
                        kvStorage.o(jCurrentTimeMillis, "show_time", false);
                        BLog.i("Widget_Helper", "requestPinAppWidget: " + appWidgetManager.requestPinAppWidget(new ComponentName((Context) this, (Class<?>) MiddleWidgetProvider.class), null, null));
                        WidgetHelper.s();
                        objCreateFailure = Unit.INSTANCE;
                        Result.constructor-impl(objCreateFailure);
                        Throwable th = Result.exceptionOrNull-impl(objCreateFailure);
                        if (th == null) {
                            return;
                        }
                        BLog.i("Widget_Helper", "requestPinAppWidget fail: " + th.getMessage());
                    } catch (Throwable th2) {
                        objCreateFailure = ResultKt.createFailure(th2);
                        Result.constructor-impl(objCreateFailure);
                    }
                }
            }
        }
    }

    @Override // com.vega.core.api.account.ILoginResultHandler
    public final void O(LoginResultHandler loginResultHandler) {
        this.y1 = loginResultHandler;
    }

    @Override // com.vega.util.LoginResultCallback
    public final void R(Function3<? super Integer, ? super Integer, ? super Intent, Unit> function3) {
        this.z1 = function3;
    }

    /* JADX WARN: Multi-variable type inference failed */
    public static Intent INVOKEVIRTUAL_com_vega_main_MainActivity_com_vega_launcher_lancet_BadParcelableLancet_getInttent(MainActivity mainActivity) {
        Context context;
        Intent intent = mainActivity.getIntent();
        if (intent != null && (context = BadParcelableExceptionOpt.a) != null) {
            intent.setExtrasClassLoader(context.getClassLoader());
        }
        return intent;
    }

    /* JADX WARN: Multi-variable type inference failed */
    public static void com_vega_main_MainActivity_com_bytedance_sysoptimizer_EnterTransitionLancet_onStop(MainActivity mainActivity) {
        super.onStop();
        if (EnterTransitionCrashOptimizer.getContext() != null) {
            try {
                mainActivity.getWindow().getDecorView().getViewTreeObserver().dispatchOnPreDraw();
            } catch (Throwable unused) {
            }
        }
    }

    /* JADX WARN: Multi-variable type inference failed */
    public final boolean dispatchTouchEvent(MotionEvent motionEvent) {
        if (motionEvent != null && (motionEvent.getAction() == 2 || motionEvent.getAction() == 1)) {
            e2().c = true;
        }
        return super/*android.app.Activity*/.dispatchTouchEvent(motionEvent);
    }

    public static void n3(String str) {
        HashMap map = new HashMap();
        map.put("action", str);
        BaseMainActivity.Companion companion = BaseMainActivity.o1;
        TimeOnTabMonitor.a.getClass();
        int i = TimeOnTabMonitor.c;
        companion.getClass();
        String strA = BaseMainActivity.Companion.a(i);
        if (strA == null) {
            strA = "other";
        }
        map.put("tab_name", strA);
        ReportManager.c.f("creator_message_remind_push", map);
    }

    @Override // com.vega.main.BaseMainActivity
    public final void c3(boolean z) {
        Intrinsics.checkNotNull(this, "");
        if (findViewByIdCached(this, 2131310772, BadgeButton.class).getMeasuredWidth() == 0) {
            Intrinsics.checkNotNull(this, "");
            findViewByIdCached(this, 2131310772, BadgeButton.class).getViewTreeObserver().addOnGlobalLayoutListener(new ViewTreeObserver.OnGlobalLayoutListener() { // from class: com.vega.main.MainActivity$showTemplateTips$1
                @Override // android.view.ViewTreeObserver.OnGlobalLayoutListener
                public final void onGlobalLayout() {
                    AndroidExtensionsBase androidExtensionsBase = this.a;
                    Intrinsics.checkNotNull(androidExtensionsBase, "");
                    androidExtensionsBase.findViewByIdCached(androidExtensionsBase, 2131310772, BadgeButton.class).getViewTreeObserver().removeOnGlobalLayoutListener(this);
                    this.a.o3(false);
                }
            });
        } else {
            o3(false);
        }
    }

    /* JADX WARN: Multi-variable type inference failed */
    @Override // com.vega.core.popmanager.popup.PopCenter.IPopStageChangeListener
    public final void I0(PopStage popStage) {
        Intrinsics.checkNotNullParameter(popStage, "");
        IPreinstallPhotoEditPromoService iPreinstallPhotoEditPromoService = (IPreinstallPhotoEditPromoService) SPIService.INSTANCE.getOrNullImpl(Reflection.getOrCreateKotlinClass(IPreinstallPhotoEditPromoService.class));
        if (iPreinstallPhotoEditPromoService != null) {
            iPreinstallPhotoEditPromoService.b(this, popStage);
        }
        if (Intrinsics.areEqual(popStage, PopStage.FirstFrame.b)) {
            K1.getClass();
            if (!Companion.a().x0()) {
                PopMock.a.getClass();
                return;
            }
            PopCenter popCenter = PopCenter.a;
            Function0<Unit> function0 = new Function0<Unit>() { // from class: com.vega.main.MainActivity$onStageChange$1
                {
                    super(0);
                }

                /* JADX WARN: Type inference failed for: r3v0, types: [android.content.Context, com.vega.main.MainActivity, java.lang.Object] */
                public final Object invoke() {
                    final ?? r3 = this.e;
                    r3.getClass();
                    MainActivity.K1.getClass();
                    MainActivity.Companion.a().U();
                    MainActivity.Companion.a().P("show");
                    ForceLogoutDialog forceLogoutDialog = new ForceLogoutDialog(r3, new Function0<Unit>() { // from class: com.vega.main.MainActivity$tryShowForceLogoutDialog$1
                        public final Object invoke() {
                            MainActivity.K1.getClass();
                            MainActivity.Companion.a().P("confirm");
                            return Unit.INSTANCE;
                        }
                    }, new Function0<Unit>() { // from class: com.vega.main.MainActivity$tryShowForceLogoutDialog$2
                        {
                            super(0);
                        }

                        public final Object invoke() {
                            PopCenter.a.getClass();
                            PopCenter.b("force_logout");
                            MainActivity.K1.getClass();
                            MainActivity.Companion.a().P("relogin");
                            SmartRoute smartRouteBuildRoute = SmartRouter.buildRoute(r3, "//login");
                            smartRouteBuildRoute.withParam("key_uc_enter_from", MainActivity.Companion.a().z0());
                            smartRouteBuildRoute.withParam("key_uc_enter_method", MainActivity.Companion.a().z0());
                            smartRouteBuildRoute.open();
                            return Unit.INSTANCE;
                        }
                    }, true);
                    ((BaseDialog) forceLogoutDialog).c = "force_logout";
                    if (!new HeliosApiHook().preInvoke(300000, "com/vega/ui/dialog/ForceLogoutDialog", "show", forceLogoutDialog, new Object[0], "void", new ExtraInfo(false, "()V", "dzBzEhQ/WMuSWFYoS1ypZygzPETd98ElVls=")).isIntercept()) {
                        forceLogoutDialog.show();
                    }
                    return Unit.INSTANCE;
                }
            };
            popCenter.getClass();
            PopCenter.o("force_logout", "", function0);
        }
    }

    @Override // com.vega.main.BaseMainActivity
    public final void L1(Intent intent) {
        String stringExtra;
        Object objCreateFailure;
        if (intent != null && (stringExtra = intent.getStringExtra("package_id")) != null) {
            if (PerformanceManagerHelper.blogEnable) {
                BLog.i(this.R, "autoDownloadFromDeeplink ".concat(stringExtra));
            }
            try {
                long j = Long.parseLong(stringExtra);
                SPIService sPIService = SPIService.INSTANCE;
                ((ICloudService) sPIService.getImpl(Reflection.getOrCreateKotlinClass(ICloudService.class), (String) null)).t(((ICloudService) sPIService.getImpl(Reflection.getOrCreateKotlinClass(ICloudService.class), (String) null)).F(), j, (Function1) null);
                objCreateFailure = Unit.INSTANCE;
                Result.constructor-impl(objCreateFailure);
            } catch (Throwable th) {
                objCreateFailure = ResultKt.createFailure(th);
                Result.constructor-impl(objCreateFailure);
            }
            Result.box-impl(objCreateFailure);
        }
    }

    /* JADX WARN: Multi-variable type inference failed */
    public final void o3(boolean z) {
        if (!isFinishing() && !isDestroyed() && !BottomBannerHelper.a.a() && this.v0 != BaseMainActivity.Page.FEED) {
            Intrinsics.checkNotNull(this, "");
            View viewFindViewByIdCached = findViewByIdCached(this, 2131305819, OptXRadioGroup.class);
            Intrinsics.checkNotNullExpressionValue(viewFindViewByIdCached, "");
            if (viewFindViewByIdCached.getVisibility() == 0) {
                Intrinsics.checkNotNull(this, "");
                View viewFindViewByIdCached2 = findViewByIdCached(this, 2131310772, BadgeButton.class);
                Intrinsics.checkNotNullExpressionValue(viewFindViewByIdCached2, "");
                if (viewFindViewByIdCached2.getVisibility() == 0) {
                    BuildersKt__Builders_commonKt.launch$default(this, (CoroutineContext) null, (CoroutineStart) null, new MainActivity$showTemplateTipsAndBadgeIfCan$1(this, z, null), 3, (Object) null);
                }
            }
        }
    }

    /* JADX WARN: Multi-variable type inference failed */
    @Override // com.vega.main.BaseMainActivity, com.vega.ui.start.BaseInfraActivity
    public final void x1(Intent intent) {
        Object objCreateFailure;
        if (PerformanceManagerHelper.blogEnable) {
            BLog.i(this.R, "realOnNewIntent called");
        }
        super.x1(intent);
        Community.a.getClass();
        Community.d().m(this);
        try {
            if (!ContextExtKt.hostEnv().developSettings().isOutBuild()) {
                Object obj = null;
                try {
                    objCreateFailure = (IAgentPlaybackHandler) SPIService.INSTANCE.getImpl(Reflection.getOrCreateKotlinClass(IAgentPlaybackHandler.class), (String) null);
                    Result.constructor-impl(objCreateFailure);
                } catch (Throwable th) {
                    objCreateFailure = ResultKt.createFailure(th);
                    Result.constructor-impl(objCreateFailure);
                }
                if (!Result.isFailure-impl(objCreateFailure)) {
                    obj = objCreateFailure;
                }
                IAgentPlaybackHandler iAgentPlaybackHandler = (IAgentPlaybackHandler) obj;
                if (iAgentPlaybackHandler != null) {
                    INVOKEVIRTUAL_com_vega_main_MainActivity_com_vega_launcher_lancet_BadParcelableLancet_getInttent(this);
                    iAgentPlaybackHandler.a();
                    INVOKEVIRTUAL_com_vega_main_MainActivity_com_vega_launcher_lancet_BadParcelableLancet_getInttent(this);
                    iAgentPlaybackHandler.c();
                }
            }
        } catch (Exception e) {
            BLog.e(this.R, "call AgentPlaybackHandler failed", e);
        }
    }

    /* JADX WARN: Multi-variable type inference failed */
    @Override // com.vega.ui.start.BaseInfraActivity
    public final void u1(Bundle bundle) {
        if (PerformanceManagerHelper.blogEnable) {
            BLog.i(this.R, "realOnCreate called");
        }
        StartLifeUsedTimeMonitor.a.getClass();
        if (StartLifeUsedTimeMonitor.i == 0) {
            LaunchTracer.c(LaunchTracer.a, LaunchTracer.Module.a, "ActivityRealOnCreate");
            StartLifeUsedTimeMonitor.m("actRealOnCreate");
            StartLifeUsedTimeMonitor.i = SystemClock.uptimeMillis();
        }
        super.u1(bundle);
        r3();
        boolean booleanExtra = INVOKEVIRTUAL_com_vega_main_MainActivity_com_vega_launcher_lancet_BadParcelableLancet_getInttent(this).getBooleanExtra("key_need_show_tt_enter_detail_dialog", false);
        SPIService sPIService = SPIService.INSTANCE;
        IPopupRecorder iPopupRecorder = (IPopupRecorder) sPIService.getImpl(Reflection.getOrCreateKotlinClass(IPopupRecorder.class), (String) null);
        boolean zJ = ContextExtKt.hostEnv().launchInfo().j();
        boolean zM = ((SubscribeApi) sPIService.getImpl(Reflection.getOrCreateKotlinClass(SubscribeApi.class), (String) null)).m();
        iPopupRecorder.i(this);
        iPopupRecorder.e(zM);
        iPopupRecorder.d(zJ);
        if (C2()) {
            iPopupRecorder.b();
        }
        LocalQuestionnaireHelperV4.a.getClass();
        LocalQuestionnaireHelperV4.c = true;
        if (!booleanExtra) {
            Community.a.getClass();
            Community.d().m(this);
        }
        if (StartLifeUsedTimeMonitor.j != 0) {
            return;
        }
        LaunchTracer launchTracer = LaunchTracer.a;
        LaunchTracer.Module module = LaunchTracer.Module.a;
        launchTracer.getClass();
        LaunchTracer.a(module, "ActivityRealOnCreate");
        StartLifeUsedTimeMonitor.m("actRealOnCreateEnd");
        StartLifeUsedTimeMonitor.j = SystemClock.uptimeMillis();
    }

    @Override // com.vega.main.BaseMainActivity
    public final void K2(int i) throws JSONException {
        int i2;
        try {
            ((ViewGroup) findViewById(R.id.content)).setTag(2131305819, Integer.valueOf(i));
            Community.a.getClass();
            if (Community.d().E()) {
                e2().p6();
            }
            Result.constructor-impl(Unit.INSTANCE);
        } catch (Throwable th) {
            Result.constructor-impl(ResultKt.createFailure(th));
        }
        HomeTabRefreshViewContent homeTabRefreshViewContent = this.w1;
        BaseMainActivity.Page page = homeTabRefreshViewContent.b;
        if (page == null) {
            i2 = -1;
        } else {
            i2 = HomeTabRefreshViewContent.WhenMappings.a[page.ordinal()];
        }
        if (i2 != 1) {
            if (i2 != 2) {
                if (i2 == 3) {
                    homeTabRefreshViewContent.b(homeTabRefreshViewContent.d().getImageView());
                    homeTabRefreshViewContent.d().r();
                }
            } else {
                homeTabRefreshViewContent.b(homeTabRefreshViewContent.c().getImageView());
                homeTabRefreshViewContent.c().r();
            }
        } else {
            homeTabRefreshViewContent.b(homeTabRefreshViewContent.e().getImageView());
            homeTabRefreshViewContent.e().r();
        }
        super.K2(i);
        if (i == 2131308062) {
            ((OverseaCutSameTipsHelper) this.s1.getValue()).a();
        }
        r3();
        if (i == 2131308057) {
            k3();
        } else if (i == 2131308062) {
            Community.a.getClass();
            Community.a().getCapCutSorterConfig();
            Community.a().getSplitFeedDrawConfigAbTest();
            k3();
        } else if (i == 2131308063 && !BaseMainActivity.D2()) {
            Intrinsics.checkNotNull(this, "");
            BadgeButton badgeButton = (BadgeButton) findViewByIdCached(this, 2131310779, BadgeButton.class);
            Intrinsics.checkNotNullExpressionValue(badgeButton, "");
            BadgeButton.v(badgeButton, -1L, 2);
        }
        CharSequence charSequence = (CharSequence) e2().d.getValue();
        if ((charSequence == null || charSequence.length() == 0) && g2().d("onTabSelected")) {
            LiveDataExtKt.o(e2().d, "light");
        }
    }

    /* JADX WARN: Multi-variable type inference failed */
    @Override // com.vega.main.BaseMainActivity, com.vega.ui.start.BaseInfraActivity
    public final void onCreate(Bundle bundle) throws IllegalAccessException, NoSuchMethodException, InvocationTargetException {
        long j;
        String stringExtra;
        ActivityLifecycleHook.a(this, bundle);
        StartLifeUsedTimeMonitor.a.getClass();
        StartLifeUsedTimeMonitor.a();
        AppLaunchTracker.a.getClass();
        AppLaunchTracker.j = SystemClock.uptimeMillis();
        StartLifeDispatcher.a.getClass();
        StartLifeDispatcher.l(10);
        AdLaunchMonitor adLaunchMonitor = AdLaunchMonitor.a;
        if (AdLaunchMonitor.f == -1) {
            adLaunchMonitor.getClass();
            AdLaunchMonitor.f = AdLaunchMonitor.c();
        } else {
            adLaunchMonitor.getClass();
        }
        PopCenter.a.getClass();
        Intrinsics.checkNotNullParameter(this, "");
        PopCenter.l.add(this);
        super.onCreate(bundle);
        if (ActivityExtKt.a(this)) {
            return;
        }
        s2(INVOKEVIRTUAL_com_vega_main_MainActivity_com_vega_launcher_lancet_BadParcelableLancet_getInttent(this));
        PrivacyComponent privacyComponent = new PrivacyComponent(this);
        privacyComponent.b = INVOKEVIRTUAL_com_vega_main_MainActivity_com_vega_launcher_lancet_BadParcelableLancet_getInttent(this);
        H1(privacyComponent);
        ((ArrayList) this.W).add(new 0Ob(this));
        Intent intentINVOKEVIRTUAL_com_vega_main_MainActivity_com_vega_launcher_lancet_BadParcelableLancet_getInttent = INVOKEVIRTUAL_com_vega_main_MainActivity_com_vega_launcher_lancet_BadParcelableLancet_getInttent(this);
        if (intentINVOKEVIRTUAL_com_vega_main_MainActivity_com_vega_launcher_lancet_BadParcelableLancet_getInttent != null && intentINVOKEVIRTUAL_com_vega_main_MainActivity_com_vega_launcher_lancet_BadParcelableLancet_getInttent.getBooleanExtra("from_language_change", false)) {
            ToastUtilKt.d(2131894337, 0, 0, 0, 0, 254);
        }
        if (ContextExtKt.hostEnv().developSettings().isHyperTest()) {
            Method method = Class.forName("com.ss.android.hyper.Hyper").getMethod("init", String[].class, String.class);
            Intrinsics.checkNotNullExpressionValue(method, "");
            DirectoryUtil.a.getClass();
            ToastUtils.d(0, "hyper result =  " + method.invoke(null, new String[]{"libttvesdk.so", "libeffect.so"}, DirectoryUtil.L("hyper")), new Object[0]);
        }
        ThreadUtilKt.e(this.I1, new fixGoogleAdId.1(this));
        AdInitTaskRecorder.a.getClass();
        long j2 = AdInitTaskRecorder.c;
        if (j2 > 0) {
            j = j2 - AdInitTaskRecorder.b;
        } else {
            j = 0;
        }
        if (PerformanceManagerHelper.blogEnable) {
            BLog.i("AdInitTask", "AdInitTask run opt time=" + j + " , opt from network=" + (AdInitTaskRecorder.c - AdInitTaskRecorder.d) + " , original from network=" + (AdInitTaskRecorder.b - AdInitTaskRecorder.d));
        }
        if (AdLaunchMonitor.g == -1) {
            adLaunchMonitor.getClass();
            AdLaunchMonitor.g = AdLaunchMonitor.c();
        } else {
            adLaunchMonitor.getClass();
        }
        if (INVOKEVIRTUAL_com_vega_main_MainActivity_com_vega_launcher_lancet_BadParcelableLancet_getInttent(this).getBooleanExtra("show_share_draft_dialog", false)) {
            SmartRoute smartRouteBuildRoute = SmartRouter.buildRoute(this, "//clouddraft/share_draft");
            Intent intentINVOKEVIRTUAL_com_vega_main_MainActivity_com_vega_launcher_lancet_BadParcelableLancet_getInttent2 = INVOKEVIRTUAL_com_vega_main_MainActivity_com_vega_launcher_lancet_BadParcelableLancet_getInttent(this);
            if (intentINVOKEVIRTUAL_com_vega_main_MainActivity_com_vega_launcher_lancet_BadParcelableLancet_getInttent2 != null) {
                stringExtra = intentINVOKEVIRTUAL_com_vega_main_MainActivity_com_vega_launcher_lancet_BadParcelableLancet_getInttent2.getStringExtra("deeplink");
            } else {
                stringExtra = null;
            }
            smartRouteBuildRoute.withParam("deeplink", stringExtra);
            smartRouteBuildRoute.addFlags(67108864);
            smartRouteBuildRoute.addFlags(268435456);
            smartRouteBuildRoute.open();
        }
        LynxMsgCenter lynxMsgCenter = LynxMsgCenter.a;
        MainActivity$lynxToNativeCallback$1 mainActivity$lynxToNativeCallback$1 = this.H1;
        lynxMsgCenter.getClass();
        LynxMsgCenter.e("updateActivityBadgeStatus", "", mainActivity$lynxToNativeCallback$1);
        BoostSDK boostSDK = BoostSDK.a;
        Application application = getApplication();
        Intrinsics.checkNotNullExpressionValue(application, "");
        boostSDK.getClass();
        BoostSDK.c(application);
        BuildersKt__Builders_commonKt.launch$default(LifecycleOwnerKt.a(this), Dispatchers.getIO(), (CoroutineStart) null, new cleanLynxNetCache.1((Continuation) null), 2, (Object) null);
        StartLifeDispatcher.k();
        if (StartLifeUsedTimeMonitor.h == 0) {
            LaunchTracer launchTracer = LaunchTracer.a;
            LaunchTracer.Module module = LaunchTracer.Module.a;
            launchTracer.getClass();
            LaunchTracer.a(module, "ActivityOnCreate");
            StartLifeUsedTimeMonitor.m("actOnCreateEnd");
            StartLifeUsedTimeMonitor.h = SystemClock.uptimeMillis();
        }
        WidgetHelper.a.getClass();
        WidgetHelper.i().n(MapsKt__MapsKt.mapOf(new Pair[]{TuplesKt.to("HomeScreenTemplateWidget_small", MiniTemplateWidgetProvider.class), TuplesKt.to("HomeScreenTemplateWidget_medium", MiddleTemplateWidgetProvider.class), TuplesKt.to("HomeScreenToolWidget_small", MiniToolWidgetProvider.class), TuplesKt.to("HomeScreenToolWidget_medium", MiddleWidgetProvider.class), TuplesKt.to("HomeScreenToolWidget_large", LargeWidgetProvider.class), TuplesKt.to("HomeScreenRemoveBackgroundWidget_small", RemoveBackgroundWidgetProvider.class), TuplesKt.to("HomeScreenRetouchWidget_small", RetouchWidgetProvider.class)}));
        this.F1 = (BadgeButton) findViewById(2131310765);
    }

    public final void W(Intent intent, Function1<? super ActivityResult, Unit> function1) {
        Intrinsics.checkNotNullParameter(intent, "");
        Intrinsics.checkNotNullParameter(function1, "");
        this.v1.W(intent, function1);
    }

    /* JADX WARN: Code duplicated, block: B:32:0x0172  */
    @Override // com.vega.main.BaseMainActivity
    public final void I2(long j, boolean z) {
        if (PerformanceManagerHelper.blogEnable) {
            BLog.i(this.R, "onMessageCountChange " + j);
        }
        Intrinsics.checkNotNull(this, "");
        boolean zP = ((BadgeButton) findViewByIdCached(this, 2131310761, BadgeButton.class)).p();
        Intrinsics.checkNotNull(this, "");
        ((BadgeButton) findViewByIdCached(this, 2131310761, BadgeButton.class)).u(j, z);
        if (!zP) {
            Intrinsics.checkNotNull(this, "");
            if (((BadgeButton) findViewByIdCached(this, 2131310761, BadgeButton.class)).p()) {
                ReportManagerWrapper.INSTANCE.onEvent("new_noti_show", "show_page", "home_msg");
            }
        }
        SPIService sPIService = SPIService.INSTANCE;
        final long jA = ((IMessageService) sPIService.getImpl(Reflection.getOrCreateKotlinClass(IMessageService.class), (String) null)).a();
        if (ConfigSettingsKt.a(Reflection.getOrCreateKotlinClass(InboxCreatorAssistantSetting.class)).b()) {
            long jLongValue = ((Number) this.V.getValue()).longValue();
            Calendar calendar = Calendar.getInstance();
            calendar.setTime(new Date(System.currentTimeMillis()));
            calendar.set(11, 0);
            calendar.set(12, 0);
            calendar.set(13, 0);
            calendar.set(14, 0);
            Calendar calendar2 = Calendar.getInstance();
            calendar2.setTime(new Date(jLongValue));
            calendar2.set(11, 0);
            calendar2.set(12, 0);
            calendar2.set(13, 0);
            calendar2.set(14, 0);
            if ((calendar.getTimeInMillis() - calendar2.getTimeInMillis()) / ((long) 86400000) >= 3 && jA > 0 && !this.E1) {
                PopCenter.n(PopCenter.a, "cc_local_push_task", null, null, new Function0<Unit>() { // from class: com.vega.main.MainActivity$onMessageCountChange$1
                    /* JADX WARN: 'super' call moved to the top of the method (can break code semantics) */
                    {
                        super(0);
                    }

                    /* JADX WARN: Type inference failed for: r5v0, types: [android.app.Activity, com.vega.main.MainActivity, java.lang.Object] */
                    public final Object invoke() {
                        final ?? r5 = this.e;
                        long j2 = jA;
                        r5.getClass();
                        PushParams pushParams = new PushParams();
                        int i = (int) j2;
                        pushParams.a(FunctionsKt.a(2131755071, i, new Object[]{Integer.valueOf(i)}));
                        pushParams.c = 2131240725;
                        pushParams.e = FunctionsKt.b(2131888288);
                        pushParams.j = "cc_local_push_task";
                        pushParams.f = new Function0<Unit>() { // from class: com.vega.main.MainActivity$showAuthorHelperPush$params$1$1
                            {
                                super(0);
                            }

                            public final Object invoke() {
                                FunctionKt.k(r5, ((IMainLynxSchemeCapCut) SPIService.INSTANCE.getImpl(Reflection.getOrCreateKotlinClass(IMainLynxSchemeCapCut.class), (String) null)).F(), false, (JSONObject) null, (Intent) null, (Bundle) null, 60);
                                r5.getClass();
                                MainActivity.n3("click");
                                return Unit.INSTANCE;
                            }
                        };
                        r5.runOnUiThread(new 2JZ((MainActivity) r5, pushParams));
                        this.e.E1 = true;
                        return Unit.INSTANCE;
                    }
                }, 6);
            } else {
                PopMock.a.getClass();
            }
        } else {
            PopMock.a.getClass();
        }
        if (!BaseMainActivity.D2()) {
            if (Intrinsics.areEqual(l2().s.getValue(), Boolean.FALSE) && ((LoginService) sPIService.getImpl(Reflection.getOrCreateKotlinClass(LoginService.class), (String) null)).isLogin() && this.v0 != BaseMainActivity.Page.USER && j > ((KvStorage) this.Z.getValue()).g(this.a0, 0L)) {
                Intrinsics.checkNotNull(this, "");
                ((BadgeButton) findViewByIdCached(this, 2131310779, BadgeButton.class)).u(-1L, true);
                ((KvStorage) this.Z.getValue()).o(j, this.a0, false);
                return;
            }
            return;
        }
        HomeViewModel homeViewModelH2 = h2();
        homeViewModelH2.z = j;
        homeViewModelH2.p6();
    }

    public final void f3(BadgeButton badgeButton, int i, TabTipsHelper.TabType tabType) {
        Object obj;
        Objects.toString(tabType);
        Pair[] pairArr = new Pair[3];
        pairArr[0] = TuplesKt.to("entrance_from", "temp_onelink");
        IHostEnv iHostEnv = ContextExtHelper.a;
        String str = "1";
        if (iHostEnv.launchInfo().j()) {
            obj = "1";
        } else {
            obj = "0";
        }
        pairArr[1] = TuplesKt.to("is_first_launch", obj);
        if (!iHostEnv.launchInfo().b()) {
            str = "0";
        }
        pairArr[2] = TuplesKt.to("is_cold_launch", str);
        Map<String, String> mapMutableMapOf = MapsKt__MapsKt.mutableMapOf(pairArr);
        if (tabType == TabTipsHelper.TabType.EDIT) {
            mapMutableMapOf.put("pop_type", "edit_guide_pop");
        } else if (tabType == TabTipsHelper.TabType.TEMPLATE) {
            mapMutableMapOf.put("pop_type", "template_guide_pop");
        }
        this.W0 = mapMutableMapOf;
        Intrinsics.checkNotNull(this, "");
        if (((OptXRadioGroup) findViewByIdCached(this, 2131305819, OptXRadioGroup.class)).getCheckedRadioButtonId() == i) {
            P2(null, i);
        }
        badgeButton.setChecked(true);
        ((INewUserAcceptanceService) SPIService.INSTANCE.getImpl(Reflection.getOrCreateKotlinClass(INewUserAcceptanceService.class), (String) null)).b();
    }

    /* JADX WARN: Multi-variable type inference failed */
    @Override // com.vega.main.BaseMainActivity
    public final void onActivityResult(int i, int i2, Intent intent) throws IOException {
        String stringExtra;
        super.onActivityResult(i, i2, intent);
        LoginResultHandler loginResultHandler = this.y1;
        if (loginResultHandler != null) {
            loginResultHandler.a(i, i2, intent);
        }
        Function3<? super Integer, ? super Integer, ? super Intent, Unit> function3 = this.z1;
        if (function3 != null) {
            function3.invoke(Integer.valueOf(i), Integer.valueOf(i2), intent);
        }
        boolean z = false;
        if (i2 == -1 && i == 1003 && intent != null && intent.getBooleanExtra("is_login_suc", false) && (stringExtra = intent.getStringExtra("key_uc_enter_method")) != null) {
            int iHashCode = stringExtra.hashCode();
            if (iHashCode != 906452911) {
                if (iHashCode == 1675953423 && stringExtra.equals("click_inbox")) {
                    T2(BaseMainActivity.Page.MESSAGE);
                }
            } else if (stringExtra.equals("click_me")) {
                T2(BaseMainActivity.Page.USER);
            }
        }
        if (i == 1026) {
            IBusinessAccount iBusinessAccount = (IBusinessAccount) SPIService.INSTANCE.getImpl(Reflection.getOrCreateKotlinClass(IBusinessAccount.class), (String) null);
            if (i2 == -1) {
                z = true;
            }
            iBusinessAccount.t(z);
        }
        PendingActivityResultHandler.b.getClass();
        PendingActivityResultHandler.Companion.a(i, i2, this, intent);
        ((IYoutubePopupService) SPIService.INSTANCE.getImpl(Reflection.getOrCreateKotlinClass(IYoutubePopupService.class), (String) null)).a();
    }

    /* JADX WARN: Multi-variable type inference failed */
    public final void p3(final BadgeButton badgeButton, final TabTipsHelper.TabType tabType, final int i, final Function0<Unit> function0) {
        Objects.toString(badgeButton);
        Objects.toString(tabType);
        PopCenter.a.getClass();
        if (PopCenter.h("tab_bar_bubble")) {
            BLog.i(this.R, "showTips " + badgeButton + ' ' + tabType + " popCenter disable");
            function0.invoke();
            return;
        }
        if (badgeButton.getMeasuredWidth() == 0) {
            badgeButton.getViewTreeObserver().addOnGlobalLayoutListener(new ViewTreeObserver.OnGlobalLayoutListener() { // from class: com.vega.main.MainActivity$showTips$1
                @Override // android.view.ViewTreeObserver.OnGlobalLayoutListener
                public final void onGlobalLayout() {
                    badgeButton.getViewTreeObserver().removeOnGlobalLayoutListener(this);
                    this.q3(badgeButton, tabType, i, function0);
                }
            });
        } else {
            q3(badgeButton, tabType, i, function0);
        }
    }

    /* JADX WARN: Multi-variable type inference failed */
    public final void q3(BadgeButton badgeButton, TabTipsHelper.TabType tabType, int i, Function0<Unit> function0) {
        TipConfig tipConfig;
        long j;
        if (!isFinishing() && !isDestroyed()) {
            Intrinsics.checkNotNull(this, "");
            View viewFindViewByIdCached = findViewByIdCached(this, 2131305819, OptXRadioGroup.class);
            Intrinsics.checkNotNullExpressionValue(viewFindViewByIdCached, "");
            int iA = 0;
            if (viewFindViewByIdCached.getVisibility() == 0) {
                TabTipsHelper tabTipsHelper = (TabTipsHelper) this.t1.getValue();
                if (tabType == TabTipsHelper.TabType.PROPERTY || tabType == TabTipsHelper.TabType.PROPERTY_SAVE) {
                    String string = getResources().getString(i);
                    Intrinsics.checkNotNullExpressionValue(string, "");
                    SizeUtil.a.getClass();
                    int iA2 = SizeUtil.a(240.0f);
                    int iA3 = SizeUtil.a(12.0f);
                    int iA4 = SizeUtil.a(12.0f);
                    if (tabType == TabTipsHelper.TabType.PROPERTY_SAVE) {
                        j = 3000;
                    } else {
                        j = 5000;
                    }
                    tipConfig = new TipConfig(false, string, 0L, 0L, 0L, true, 0, 0, 14.0f, iA2, iA3, iA4, 2, 2131241728, 2131241729, true, j, 29);
                } else {
                    String string2 = getResources().getString(i);
                    Intrinsics.checkNotNullExpressionValue(string2, "");
                    if (tabType == TabTipsHelper.TabType.EDIT) {
                        SizeUtil.a.getClass();
                        iA = SizeUtil.a(15.0f);
                    }
                    SizeUtil.a.getClass();
                    tipConfig = new TipConfig(false, string2, 0L, 0L, 0L, true, iA, SizeUtil.a(2.0f), 12.0f, SizeUtil.a(280.0f), SizeUtil.a(16.0f), SizeUtil.a(12.0f), 2, 2131242762, 2131242765, false, 0L, 196637);
                }
                tabTipsHelper.b(this, badgeButton, tabType, tipConfig);
                function0.invoke();
            }
        }
    }
}
