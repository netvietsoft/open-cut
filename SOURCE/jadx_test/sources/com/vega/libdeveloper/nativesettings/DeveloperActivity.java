package com.vega.libdeveloper.nativesettings;

import X.0id;
import android.os.Bundle;
import android.view.View;
import android.view.ViewGroup;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;
import com.bytedance.helios.statichook.lifecycle.ActivityLifecycleHook;
import com.bytedance.sysoptimizer.EnterTransitionCrashOptimizer;
import com.vega.infrastructure.base.BaseActivity;
import com.vega.libdeveloper.nativesettings.config.ConfigPageAdapter;
import com.vega.libdeveloper.nativesettings.config.DeveloperConfigPage;
import java.util.ArrayList;
import java.util.List;
import kotlin.jvm.internal.Intrinsics;

/* JADX INFO: loaded from: D:\Decompiler\App\Video\Capcut\extracted\classes9.dex */
public final class DeveloperActivity extends BaseActivity {
    public static final /* synthetic */ int v = 0;

    public static final class Companion {
    }

    public final int m1() {
        return 2131493028;
    }

    /* JADX WARN: Multi-variable type inference failed */
    public final void onCreate(Bundle bundle) {
        ActivityLifecycleHook.a(this, bundle);
        super.onCreate(bundle);
    }

    /* JADX WARN: Multi-variable type inference failed */
    public final void onDestroy() {
        ActivityLifecycleHook.b(this);
        super.onDestroy();
    }

    /* JADX WARN: Multi-variable type inference failed */
    public final void onPause() {
        ActivityLifecycleHook.c(this);
        super.onPause();
    }

    /* JADX WARN: Multi-variable type inference failed */
    public final void onResume() {
        ActivityLifecycleHook.d(this);
        super/*androidx.fragment.app.FragmentActivity*/.onResume();
    }

    /* JADX WARN: Multi-variable type inference failed */
    public final void onStart() {
        ActivityLifecycleHook.e(this);
        super/*androidx.appcompat.app.AppCompatActivity*/.onStart();
    }

    /* JADX WARN: Multi-variable type inference failed */
    public final void onStop() {
        ActivityLifecycleHook.f(this);
        com_vega_libdeveloper_nativesettings_DeveloperActivity_com_bytedance_sysoptimizer_EnterTransitionLancet_onStop(this);
    }

    static {
        new Companion();
    }

    /* JADX WARN: Multi-variable type inference failed */
    public static void com_vega_libdeveloper_nativesettings_DeveloperActivity_com_bytedance_sysoptimizer_EnterTransitionLancet_onStop(DeveloperActivity developerActivity) {
        super.onStop();
        if (EnterTransitionCrashOptimizer.getContext() != null) {
            try {
                developerActivity.getWindow().getDecorView().getViewTreeObserver().dispatchOnPreDraw();
            } catch (Throwable unused) {
            }
        }
    }

    /* JADX WARN: Multi-variable type inference failed */
    public final void p1(ViewGroup viewGroup) {
        Intrinsics.checkNotNullParameter(viewGroup, "");
        View viewFindViewById = findViewById(2131299499);
        if (viewFindViewById != null) {
            viewFindViewById.setOnClickListener(new 0id(this));
        }
        RecyclerView recyclerViewFindViewById = findViewById(2131308870);
        ConfigPageAdapter configPageAdapter = new ConfigPageAdapter();
        recyclerViewFindViewById.setAdapter(configPageAdapter);
        recyclerViewFindViewById.setLayoutManager(new LinearLayoutManager(this));
        DeveloperConfigPage.e.getClass();
        List list = (List) DeveloperConfigPage.f.a.getValue();
        Intrinsics.checkNotNullParameter(list, "");
        ((ArrayList) configPageAdapter.i).clear();
        ((ArrayList) configPageAdapter.i).addAll(list);
        configPageAdapter.notifyDataSetChanged();
    }
}
