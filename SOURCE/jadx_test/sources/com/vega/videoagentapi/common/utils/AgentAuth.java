package com.vega.videoagentapi.common.utils;

import android.content.Context;
import android.text.Spanned;
import androidx.core.text.HtmlCompat;
import androidx.core.text.method.LinkMovementMethodCompat;
import androidx.fragment.app.FragmentActivity;
import androidx.lifecycle.LifecycleOwnerKt;
import com.bytedance.helios.statichook.api.ExtraInfo;
import com.bytedance.helios.statichook.api.HeliosApiHook;
import com.vega.core.ext.ContinuationExtKt;
import com.vega.core.utils.FunctionsKt;
import com.vega.infrastructure.base.ModuleCommonKt;
import com.vega.ui.ContentTextView;
import com.vega.ui.dialog.ConfirmCancelDialog;
import com.vega.ui.dialog.ConfirmCancelDialogWithScroll;
import kotlin.Unit;
import kotlin.coroutines.Continuation;
import kotlin.coroutines.CoroutineContext;
import kotlin.coroutines.intrinsics.IntrinsicsKt__IntrinsicsJvmKt;
import kotlin.coroutines.intrinsics.IntrinsicsKt__IntrinsicsKt;
import kotlin.coroutines.jvm.internal.DebugProbesKt;
import kotlin.jvm.functions.Function0;
import kotlin.jvm.internal.Intrinsics;
import kotlinx.coroutines.BuildersKt__Builders_commonKt;
import kotlinx.coroutines.CancellableContinuationImpl;
import kotlinx.coroutines.CoroutineStart;

/* JADX INFO: loaded from: D:\Decompiler\App\Video\Capcut\extracted\classes17.dex */
public final class AgentAuth {
    public static final AgentAuth a = new AgentAuth();

    public static void a(FragmentActivity fragmentActivity, Function0 function0) {
        Intrinsics.checkNotNullParameter(function0, "");
        if (fragmentActivity == null) {
            return;
        }
        BuildersKt__Builders_commonKt.launch$default(LifecycleOwnerKt.a(fragmentActivity), (CoroutineContext) null, (CoroutineStart) null, new AgentAuth$runActionEnsureAuth$1(fragmentActivity, function0, null), 3, (Object) null);
    }

    /* JADX WARN: Type inference failed for: r10v0, types: [android.app.Dialog, com.vega.ui.dialog.ConfirmCancelDialog, com.vega.ui.dialog.ConfirmCancelDialogWithScroll, java.lang.Object] */
    /* JADX WARN: Type inference failed for: r4v0, types: [com.vega.videoagentapi.common.utils.AgentAuth$showAuthDialogIfNeed$2$1, kotlin.jvm.functions.Function0] */
    public static Object b(FragmentActivity fragmentActivity, Continuation continuation) {
        final CancellableContinuationImpl cancellableContinuationImpl = new CancellableContinuationImpl(IntrinsicsKt__IntrinsicsJvmKt.intercepted(continuation), 1);
        cancellableContinuationImpl.initCancellability();
        final AgentAuthHelper agentAuthHelper = new AgentAuthHelper(fragmentActivity);
        final ?? r4 = new Function0<Unit>() { // from class: com.vega.videoagentapi.common.utils.AgentAuth$showAuthDialogIfNeed$2$1
            /* JADX WARN: 'super' call moved to the top of the method (can break code semantics) */
            {
                super(0);
            }

            public final Object invoke() {
                ContinuationExtKt.a(cancellableContinuationImpl, Boolean.TRUE);
                return Unit.INSTANCE;
            }
        };
        final Function0<Unit> function0 = new Function0<Unit>() { // from class: com.vega.videoagentapi.common.utils.AgentAuth$showAuthDialogIfNeed$2$2
            /* JADX WARN: 'super' call moved to the top of the method (can break code semantics) */
            {
                super(0);
            }

            public final Object invoke() {
                ContinuationExtKt.a(cancellableContinuationImpl, Boolean.FALSE);
                return Unit.INSTANCE;
            }
        };
        if (!((Boolean) agentAuthHelper.a.getValue(agentAuthHelper, AgentAuthHelper.b[0])).booleanValue()) {
            final Function0<Unit> function1 = new Function0<Unit>() { // from class: com.vega.videoagentapi.common.utils.AgentAuthHelper$showAuthDialogIfNeed$1
                /* JADX WARN: 'super' call moved to the top of the method (can break code semantics) */
                {
                    super(0);
                }

                public final Object invoke() {
                    r4.invoke();
                    return Unit.INSTANCE;
                }
            };
            final Function0<Unit> function2 = new Function0<Unit>() { // from class: com.vega.videoagentapi.common.utils.AgentAuthHelper$showAuthDialogIfNeed$2
                /* JADX WARN: 'super' call moved to the top of the method (can break code semantics) */
                {
                    super(0);
                }

                public final Object invoke() {
                    Function0<Unit> function3 = function0;
                    if (function3 != null) {
                        function3.invoke();
                    }
                    return Unit.INSTANCE;
                }
            };
            if ((fragmentActivity instanceof Context) && fragmentActivity != null) {
                ?? confirmCancelDialogWithScroll = new ConfirmCancelDialogWithScroll(fragmentActivity, new Function0<Unit>() { // from class: com.vega.videoagentapi.common.utils.AgentAuthHelper$showAllowAccessDialog$1$1
                    /* JADX WARN: 'super' call moved to the top of the method (can break code semantics) */
                    {
                        super(0);
                    }

                    public final Object invoke() {
                        AgentAuthHelper agentAuthHelper2 = agentAuthHelper;
                        agentAuthHelper2.a.setValue(agentAuthHelper2, AgentAuthHelper.b[0], Boolean.TRUE);
                        function1.invoke();
                        return Unit.INSTANCE;
                    }
                }, new Function0<Unit>() { // from class: com.vega.videoagentapi.common.utils.AgentAuthHelper$showAllowAccessDialog$1$2
                    /* JADX WARN: 'super' call moved to the top of the method (can break code semantics) */
                    {
                        super(0);
                    }

                    public final Object invoke() {
                        function2.invoke();
                        return Unit.INSTANCE;
                    }
                });
                confirmCancelDialogWithScroll.s(FunctionsKt.b(2131886360));
                confirmCancelDialogWithScroll.t = 5;
                Spanned spannedFromHtml = HtmlCompat.fromHtml(FunctionsKt.b(2131886359), 0);
                Intrinsics.checkNotNullExpressionValue(spannedFromHtml, "");
                if (LinkMovementMethodCompat.a == null) {
                    LinkMovementMethodCompat.a = new LinkMovementMethodCompat();
                }
                ConfirmCancelDialog.o(confirmCancelDialogWithScroll, spannedFromHtml, null, LinkMovementMethodCompat.a, 2);
                confirmCancelDialogWithScroll.l = Float.valueOf(14.0f);
                ContentTextView contentTextView = confirmCancelDialogWithScroll.x;
                if (contentTextView != null) {
                    contentTextView.setTextSize(1, 14.0f);
                }
                confirmCancelDialogWithScroll.m(ModuleCommonKt.b(2131886357));
                confirmCancelDialogWithScroll.k(ModuleCommonKt.b(2131886358));
                confirmCancelDialogWithScroll.setCancelable(false);
                confirmCancelDialogWithScroll.setCanceledOnTouchOutside(false);
                if (!new HeliosApiHook().preInvoke(300000, "com/vega/ui/dialog/ConfirmCancelDialogWithScroll", "show", (Object) confirmCancelDialogWithScroll, new Object[0], "void", new ExtraInfo(false, "()V", "dzBzEhQ/WMuSQ14lQB2FYZzFEI76CzYZtVMCf8n6CO7U5BeHGSxDuigwnzmU62IjNGmo")).isIntercept()) {
                    confirmCancelDialogWithScroll.show();
                }
            }
        } else {
            r4.invoke();
        }
        Object result = cancellableContinuationImpl.getResult();
        if (result == IntrinsicsKt__IntrinsicsKt.getCOROUTINE_SUSPENDED()) {
            DebugProbesKt.probeCoroutineSuspended(continuation);
        }
        return result;
    }
}
