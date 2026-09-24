package com.vega.ailabagent;

import X.2Oq;
import X.46j;
import X.46l;
import X.46o;
import X.46p;
import X.46q;
import X.46r;
import X.4qC;
import X.C1eB;
import com.vega.ailabagent.service.AiLabAgentServiceImpl;
import com.vega.ailabagent.service.AiLabImageShareServiceImpl;
import com.vega.ailabagent.service.ShareCodeServiceImpl;
import com.vega.ailabagent.unifyagent.preview.save.ManualAssetSaveTipStateImpl;
import com.vega.ailabagent.unifyagent.push.AgentInAppPushManager;
import com.vega.core.koin.IKoinModule;
import com.vega.cutsameedit.biz.agent.services.auto.AutoCutVideoAgentServiceImpl;
import com.vega.cutsameedit.gentemplate.agent.IAutoCutAgentMaterialService;
import com.vega.genaicommon.IAiLabHistoryConversationLookup;
import com.vega.videoagentapi.IAiLabAgentService;
import com.vega.videoagentapi.IAiLabImageShareService;
import com.vega.videoagentapi.IShareCodeService;
import com.vega.videoagentapi.push.IAgentInAppPushService;
import com.vega.videoagentapi.unifyagent.save.IManualAssetSaveTipState;
import java.util.List;
import kotlin.Unit;
import kotlin.collections.CollectionsKt__CollectionsJVMKt;
import kotlin.collections.CollectionsKt__CollectionsKt;
import kotlin.jvm.functions.Function1;
import kotlin.jvm.functions.Function2;
import kotlin.jvm.internal.Intrinsics;
import kotlin.jvm.internal.Reflection;
import kotlin.reflect.KClass;
import org.koin.core.definition.Kind;
import org.koin.core.qualifier.Qualifier;
import org.koin.core.registry.ScopeRegistry;
import org.koin.core.scope.Scope;

/* JADX INFO: loaded from: D:\Decompiler\App\Video\Capcut\extracted\classes13.dex */
public final class KoinAiLabAgentModule implements IKoinModule {
    public static final KoinAiLabAgentModule a = new KoinAiLabAgentModule();

    public final 46o b() {
        return IKoinModule.DefaultImpls.d();
    }

    public final List<46o> c() {
        return IKoinModule.DefaultImpls.a();
    }

    public final 46o g() {
        return C1eB.a(new Function1<46o, Unit>() { // from class: com.vega.ailabagent.KoinAiLabAgentModule$spiModule$1
            public final Object invoke(Object obj) {
                46o r0 = (46o) obj;
                Intrinsics.checkNotNullParameter(r0, "");
                KoinAiLabAgentModule$spiModule$1$invoke$.inlined.singleOf.default.1 r8 = new KoinAiLabAgentModule$spiModule$1$invoke$.inlined.singleOf.default.1();
                ScopeRegistry.Companion.getClass();
                2Oq r5 = ScopeRegistry.rootScopeQualifier;
                Kind kind = Kind.a;
                4qC r2 = new 4qC(new 46j(r5, Reflection.getOrCreateKotlinClass(AiLabAgentServiceImpl.class), (Qualifier) null, r8, kind, CollectionsKt__CollectionsKt.emptyList()));
                r0.c(r2);
                if (r0.a) {
                    r0.d(r2);
                }
                46r r4 = new 46r(r0, r2);
                46p.a(r4, (Function1) null);
                46q.b(r4, new KClass[]{Reflection.getOrCreateKotlinClass(IAiLabAgentService.class), Reflection.getOrCreateKotlinClass(IAiLabHistoryConversationLookup.class)});
                4qC r3 = new 4qC(new 46j(r5, Reflection.getOrCreateKotlinClass(AiLabImageShareServiceImpl.class), (Qualifier) null, new KoinAiLabAgentModule$spiModule$1$invoke$.inlined.singleOf.default.2(), kind, CollectionsKt__CollectionsKt.emptyList()));
                r0.c(r3);
                if (r0.a) {
                    r0.d(r3);
                }
                46r r6 = new 46r(r0, r3);
                46p.a(r6, (Function1) null);
                46q.a(r6, Reflection.getOrCreateKotlinClass(IAiLabImageShareService.class));
                4qC r7 = new 4qC(new 46j(r5, Reflection.getOrCreateKotlinClass(ShareCodeServiceImpl.class), (Qualifier) null, new Function2<Scope, 46l, ShareCodeServiceImpl>() { // from class: com.vega.ailabagent.KoinAiLabAgentModule$spiModule$1$invoke$$inlined$singleOf$default$3
                    public final Object invoke(Object obj2, Object obj3) {
                        Intrinsics.checkNotNullParameter(obj2, "");
                        Intrinsics.checkNotNullParameter(obj3, "");
                        return new ShareCodeServiceImpl();
                    }
                }, kind, CollectionsKt__CollectionsKt.emptyList()));
                r0.c(r7);
                if (r0.a) {
                    r0.d(r7);
                }
                46r r9 = new 46r(r0, r7);
                46p.a(r9, (Function1) null);
                46q.a(r9, Reflection.getOrCreateKotlinClass(IShareCodeService.class));
                4qC r10 = new 4qC(new 46j(r5, Reflection.getOrCreateKotlinClass(AutoCutVideoAgentServiceImpl.class), (Qualifier) null, new KoinAiLabAgentModule$spiModule$1$invoke$.inlined.singleOf.default.4(), kind, CollectionsKt__CollectionsKt.emptyList()));
                r0.c(r10);
                if (r0.a) {
                    r0.d(r10);
                }
                46r r11 = new 46r(r0, r10);
                46p.a(r11, (Function1) null);
                46q.a(r11, Reflection.getOrCreateKotlinClass(IAutoCutAgentMaterialService.class));
                4qC r12 = new 4qC(new 46j(r5, Reflection.getOrCreateKotlinClass(IAgentInAppPushService.class), (Qualifier) null, new Function2<Scope, 46l, IAgentInAppPushService>() { // from class: com.vega.ailabagent.KoinAiLabAgentModule$spiModule$1.5
                    public final Object invoke(Object obj2, Object obj3) {
                        Intrinsics.checkNotNullParameter(obj2, "");
                        Intrinsics.checkNotNullParameter(obj3, "");
                        return AgentInAppPushManager.a;
                    }
                }, kind, CollectionsKt__CollectionsKt.emptyList()));
                r0.c(r12);
                if (r0.a) {
                    r0.d(r12);
                }
                new 46r(r0, r12);
                4qC r13 = new 4qC(new 46j(r5, Reflection.getOrCreateKotlinClass(IManualAssetSaveTipState.class), (Qualifier) null, new Function2<Scope, 46l, IManualAssetSaveTipState>() { // from class: com.vega.ailabagent.KoinAiLabAgentModule$spiModule$1.6
                    public final Object invoke(Object obj2, Object obj3) {
                        Intrinsics.checkNotNullParameter(obj2, "");
                        Intrinsics.checkNotNullParameter(obj3, "");
                        return new ManualAssetSaveTipStateImpl(0);
                    }
                }, kind, CollectionsKt__CollectionsKt.emptyList()));
                r0.c(r13);
                if (r0.a) {
                    r0.d(r13);
                }
                new 46r(r0, r13);
                return Unit.INSTANCE;
            }
        });
    }

    public final List<46o> i() {
        return CollectionsKt__CollectionsJVMKt.listOf(C1eB.a(module.1.e));
    }
}
