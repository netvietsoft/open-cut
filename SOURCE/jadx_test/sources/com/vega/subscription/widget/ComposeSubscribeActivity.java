package com.vega.subscription.widget;

import X.4kA;
import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import androidx.appcompat.app.AppCompatActivity;
import com.bytedance.helios.statichook.lifecycle.ActivityLifecycleHook;
import com.bytedance.sysoptimizer.EnterTransitionCrashOptimizer;
import com.kanyun.kace.AndroidExtensions;
import com.kanyun.kace.AndroidExtensionsBase;
import com.kanyun.kace.AndroidExtensionsImpl;
import com.lemon.clipmonetize.Commerce;
import com.lemon.clipmonetize.biz.commerce_page.base.ui.api.ISubscribePageOpenTracer;
import com.lemon.clipmonetize.biz.commerce_page.lv_oversea.SubscribePageViewKt;
import com.lemon.clipmonetize.biz.commerce_page.lv_oversea.tracer.SubscribePageOpenTracer;
import com.vega.infrastructure.base.ModuleCommon;
import com.vega.infrastructure.extensions.ActivityExtKt;
import com.vega.kv.KvStorage;
import com.vega.performance.BadParcelableExceptionOpt;
import com.vega.subscriptionapi.report.BusinessReporter;
import com.vega.subscriptionapi.report.SubscribePageTracer;
import java.util.List;
import java.util.Map;
import kotlin.Result;
import kotlin.ResultKt;
import kotlin.TuplesKt;
import kotlin.Unit;
import kotlin.collections.CollectionsKt__CollectionsJVMKt;
import kotlin.collections.MapsKt__MapsJVMKt;
import kotlin.collections.MapsKt__MapsKt;
import kotlin.jvm.functions.Function0;
import kotlin.jvm.internal.CallableReference;
import kotlin.jvm.internal.Intrinsics;
import org.json.JSONObject;

/* JADX INFO: loaded from: D:\Decompiler\App\Video\Capcut\extracted\classes15.dex */
public final class ComposeSubscribeActivity extends AppCompatActivity implements AndroidExtensions {
    public final List<String> l = CollectionsKt__CollectionsJVMKt.listOf("image_lynx_subscription");
    public final AndroidExtensionsImpl m = new AndroidExtensionsImpl();

    public static final class Companion {
    }

    public final <T extends View> T findViewByIdCached(AndroidExtensionsBase androidExtensionsBase, int i, Class<T> cls) {
        Intrinsics.checkNotNullParameter(androidExtensionsBase, "");
        Intrinsics.checkNotNullParameter(cls, "");
        return (T) this.m.findViewByIdCached(androidExtensionsBase, i, cls);
    }

    /* JADX WARN: Multi-variable type inference failed */
    public final void onDestroy() {
        ActivityLifecycleHook.b(this);
        super.onDestroy();
    }

    /* JADX WARN: Multi-variable type inference failed */
    public final void onPause() {
        ActivityLifecycleHook.c(this);
        super/*androidx.fragment.app.FragmentActivity*/.onPause();
    }

    /* JADX WARN: Multi-variable type inference failed */
    public final void onResume() {
        ActivityLifecycleHook.d(this);
        super/*androidx.fragment.app.FragmentActivity*/.onResume();
    }

    /* JADX WARN: Multi-variable type inference failed */
    public final void onStart() {
        ActivityLifecycleHook.e(this);
        super.onStart();
    }

    /* JADX WARN: Multi-variable type inference failed */
    public final void onStop() {
        ActivityLifecycleHook.f(this);
        com_vega_subscription_widget_ComposeSubscribeActivity_com_bytedance_sysoptimizer_EnterTransitionLancet_onStop(this);
    }

    static {
        new Companion();
    }

    /* JADX INFO: renamed from: com.vega.subscription.widget.ComposeSubscribeActivity$onCreate$1, reason: invalid class name */
    public /* synthetic */ class AnonymousClass1 extends 4kA implements Function0<Unit> {
        public AnonymousClass1(Object obj) {
            super(0, obj, ComposeSubscribeActivity.class, "finish", "finish()V", 0);
        }

        public final Object invoke() {
            ((Activity) ((CallableReference) this).receiver).finish();
            return Unit.INSTANCE;
        }
    }

    /* JADX WARN: Multi-variable type inference failed */
    public static Intent INVOKEVIRTUAL_com_vega_subscription_widget_ComposeSubscribeActivity_com_vega_launcher_lancet_BadParcelableLancet_getInttent(ComposeSubscribeActivity composeSubscribeActivity) {
        Context context;
        Intent intent = composeSubscribeActivity.getIntent();
        if (intent != null && (context = BadParcelableExceptionOpt.a) != null) {
            intent.setExtrasClassLoader(context.getClassLoader());
        }
        return intent;
    }

    /* JADX WARN: Multi-variable type inference failed */
    public static void com_vega_subscription_widget_ComposeSubscribeActivity_com_bytedance_sysoptimizer_EnterTransitionLancet_onStop(ComposeSubscribeActivity composeSubscribeActivity) {
        super.onStop();
        if (EnterTransitionCrashOptimizer.getContext() != null) {
            try {
                composeSubscribeActivity.getWindow().getDecorView().getViewTreeObserver().dispatchOnPreDraw();
            } catch (Throwable unused) {
            }
        }
    }

    /* JADX WARN: Code duplicated, block: B:19:0x007d  */
    /* JADX WARN: Multi-variable type inference failed */
    public final void onCreate(Bundle bundle) {
        Object objCreateFailure;
        Map mapEmptyMap;
        ActivityLifecycleHook.a(this, bundle);
        overridePendingTransition(0, 0);
        super/*androidx.fragment.app.FragmentActivity*/.onCreate(bundle);
        String stringExtra = INVOKEVIRTUAL_com_vega_subscription_widget_ComposeSubscribeActivity_com_vega_launcher_lancet_BadParcelableLancet_getInttent(this).getStringExtra("channel");
        String str = "";
        if (stringExtra == null) {
            stringExtra = "";
        }
        long longExtra = INVOKEVIRTUAL_com_vega_subscription_widget_ComposeSubscribeActivity_com_vega_launcher_lancet_BadParcelableLancet_getInttent(this).getLongExtra("instance_id", 0L);
        String stringExtra2 = INVOKEVIRTUAL_com_vega_subscription_widget_ComposeSubscribeActivity_com_vega_launcher_lancet_BadParcelableLancet_getInttent(this).getStringExtra("launch_id");
        if (stringExtra2 != null) {
            str = stringExtra2;
        }
        long longExtra2 = INVOKEVIRTUAL_com_vega_subscription_widget_ComposeSubscribeActivity_com_vega_launcher_lancet_BadParcelableLancet_getInttent(this).getLongExtra("click_time", 0L);
        long longExtra3 = INVOKEVIRTUAL_com_vega_subscription_widget_ComposeSubscribeActivity_com_vega_launcher_lancet_BadParcelableLancet_getInttent(this).getLongExtra("jsb_click_time", 0L);
        String stringExtra3 = INVOKEVIRTUAL_com_vega_subscription_widget_ComposeSubscribeActivity_com_vega_launcher_lancet_BadParcelableLancet_getInttent(this).getStringExtra("business_extra");
        Unit unit = null;
        if (stringExtra3 != null) {
            try {
                objCreateFailure = MapsKt__MapsJVMKt.mapOf(TuplesKt.to("business_extra", new JSONObject(stringExtra3)));
                Result.constructor-impl(objCreateFailure);
            } catch (Throwable th) {
                objCreateFailure = ResultKt.createFailure(th);
                Result.constructor-impl(objCreateFailure);
            }
            if (Result.isFailure-impl(objCreateFailure)) {
                objCreateFailure = null;
            }
            mapEmptyMap = (Map) objCreateFailure;
            if (mapEmptyMap == null) {
                mapEmptyMap = MapsKt__MapsKt.emptyMap();
            }
        } else {
            mapEmptyMap = MapsKt__MapsKt.emptyMap();
        }
        BusinessReporter.o(BusinessReporter.a, "compose_create", str, longExtra2, longExtra3, mapEmptyMap, 16);
        SubscribePageTracer.a.getClass();
        try {
            SubscribePageOpenTracer subscribePageOpenTracerE = Commerce.p.a().e();
            if (subscribePageOpenTracerE != null) {
                ISubscribePageOpenTracer.DefaultImpls.a(subscribePageOpenTracerE, longExtra, ISubscribePageOpenTracer.Step.n, (Long) null, (Map) null, false, 28);
                unit = Unit.INSTANCE;
            }
            Result.constructor-impl(unit);
        } catch (Throwable th2) {
            Result.constructor-impl(ResultKt.createFailure(th2));
        }
        if (this.l.contains(stringExtra)) {
            getWindow().setSoftInputMode(48);
        }
        ModuleCommon moduleCommon = ModuleCommon.INSTANCE;
        setContentView(SubscribePageViewKt.a(this, stringExtra, longExtra, new KvStorage(moduleCommon.getApplication(), moduleCommon.getApplication().getPackageName() + "_preferences").d("lv_pref_key_lynx_debug", false), new AnonymousClass1(this)));
        ActivityExtKt.a(this);
        ActivityExtKt.d(this);
    }
}
