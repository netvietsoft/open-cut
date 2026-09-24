package com.vega.kmp.agent.core.protocol.impl.message;

import com.vega.kmp.agent.core.Conversation;
import com.vega.kmp.agent.core.depends.BLog;
import com.vega.kmp.agent.core.internal.events.SseStabilityTracker;
import com.vega.kmp.agent.core.internal.events.SseTrackerRuntimeSnapshot;
import com.vega.kmp.agent.core.message.AgentMessage;
import com.vega.kmp.agent.core.message.UserMessage;
import com.vega.kmp.agent.core.message.modifier.ProtocolOptionModifier;
import com.vega.kmp.agent.core.util.ConversationExKt$lastUserMessage$1;
import com.vega.kmp.agent.core.util.sse.SseConnection;
import com.vega.kmp.agent.core.util.sse.SseConnectionListener;
import com.vega.kmp.agent.core.util.sse.SseEventPatcher;
import java.util.concurrent.locks.ReentrantLock;
import kotlin.Unit;
import kotlin.jvm.functions.Function0;
import kotlin.jvm.functions.Function1;
import kotlin.jvm.internal.Intrinsics;

/* JADX INFO: loaded from: D:\Decompiler\App\Video\Capcut\extracted\classes17.dex */
public final class SseConnectionManager {
    public final Conversation a;
    public final AgentProtocolConfig b;
    public final Function1<String, Unit> c;
    public final ReentrantLock d;
    public boolean e;
    public boolean f;
    public String g;
    public AgentMessage h;
    public String i;
    public SseConnection j;
    public long k;
    public SseEventPatcher l;
    public String m;
    public volatile String n;
    public final SseStabilityTracker o;

    public final SseTrackerRuntimeSnapshot b() {
        boolean z;
        boolean z2 = this.e;
        boolean z3 = this.f;
        long j = this.k;
        String str = this.g;
        String str2 = this.i;
        if (this.j != null) {
            z = true;
        } else {
            z = false;
        }
        return new SseTrackerRuntimeSnapshot(j, str, str2, z2, z3, z);
    }

    public final void e() {
        SseConnection sseConnection;
        BLog.Companion.i("EdwardAgent.SseConnectionManager", "terminateConnectionIfNeeded: isForeground = " + this.f + ", latestSendingRoundId = " + this.g + ", latestRoundDoneId = " + this.i);
        if (this.g.length() != 0 && !this.f && Intrinsics.areEqual(this.g, this.i) && (sseConnection = this.j) != null) {
            this.n = "abort";
            this.j = null;
            sseConnection.a();
        }
    }

    /* JADX WARN: Code duplicated, block: B:6:0x001c A[Catch: all -> 0x004c, TryCatch #0 {all -> 0x004c, blocks: (B:4:0x0018, B:7:0x0026, B:6:0x001c), top: B:13:0x0018 }] */
    public final void f() {
        String str;
        AgentMessage agentMessageA = this.a.L.a(new Function1<AgentMessage, Boolean>() { // from class: com.vega.kmp.agent.core.protocol.impl.message.SseConnectionManager$tryRecoverConversationState$lastMessage$1
            {
                super(1);
            }

            public final Object invoke(Object obj) {
                AgentMessage agentMessage = (AgentMessage) obj;
                Intrinsics.checkNotNullParameter(agentMessage, "");
                boolean z = true;
                if (agentMessage.c.length() <= 0 || !this.e.c(agentMessage)) {
                    z = false;
                }
                return Boolean.valueOf(z);
            }
        });
        ReentrantLock reentrantLock = this.d;
        reentrantLock.lock();
        if (agentMessageA != null) {
            try {
                if (agentMessageA.l) {
                    this.h = null;
                    this.g = "";
                    this.i = "";
                    str = "ready_to_send";
                } else {
                    this.h = agentMessageA;
                    BLog.Companion.i("EdwardAgent.SseConnectionManager", "tryRecoverConversationState: last message not round-done, lastMessage = " + agentMessageA);
                    this.g = agentMessageA.c;
                    this.i = "";
                    str = "streaming_response";
                }
            } catch (Throwable th) {
                reentrantLock.unlock();
                throw th;
            }
        } else {
            this.h = null;
            this.g = "";
            this.i = "";
            str = "ready_to_send";
        }
        reentrantLock.unlock();
        this.c.invoke(str);
    }

    public final void d() {
        SseEventPatcher sseEventPatcher;
        BLog.Companion companion = BLog.Companion;
        companion.i("EdwardAgent.SseConnectionManager", "startConnectionIfNeeded: latestEventId = " + this.k + ", isForeground = " + this.f + ", latestRoundDoneId = " + this.i + ", latestSendingRoundId = " + this.g);
        if (this.k == Long.MIN_VALUE) {
            return;
        }
        if ((!this.f && this.g.length() > 0 && Intrinsics.areEqual(this.i, this.g)) || (sseEventPatcher = this.l) == null) {
            return;
        }
        companion.i("EdwardAgent.SseConnectionManager", "subscribeNewEvent: isDestroyed = " + this.e + ", conversation = " + this.a);
        if (this.e || this.j != null) {
            return;
        }
        String str = this.m;
        AgentProtocolConfig agentProtocolConfig = this.b;
        SseConnection sseConnection = new SseConnection(sseEventPatcher, agentProtocolConfig.c, new Function0<String>() { // from class: com.vega.kmp.agent.core.protocol.impl.message.SseConnectionManager$subscribeNewEvent$connection$2
            {
                super(0);
            }

            public final Object invoke() {
                SseConnectionManager sseConnectionManager = this.e;
                return sseConnectionManager.b.d.invoke(sseConnectionManager.a, Long.valueOf(sseConnectionManager.k));
            }
        }, new SseConnectionListener() { // from class: com.vega.kmp.agent.core.protocol.impl.message.SseConnectionManager$subscribeNewEvent$connection$1
            @Override // com.vega.kmp.agent.core.util.sse.SseConnectionListener
            public final void b() {
                SseConnectionManager sseConnectionManager = this.a;
                ReentrantLock reentrantLock = sseConnectionManager.d;
                reentrantLock.lock();
                try {
                    SseStabilityTracker.f(sseConnectionManager.o, "response_finish", sseConnectionManager.b());
                } finally {
                    reentrantLock.unlock();
                }
            }

            @Override // com.vega.kmp.agent.core.util.sse.SseConnectionListener
            public final void onCancel() {
                SseConnectionManager sseConnectionManager = this.a;
                ReentrantLock reentrantLock = sseConnectionManager.d;
                reentrantLock.lock();
                try {
                    String str2 = sseConnectionManager.n;
                    sseConnectionManager.n = null;
                    if (!Intrinsics.areEqual(str2, "stall_recover_disconnect")) {
                        if (str2 == null) {
                            str2 = "cancel";
                        }
                        SseStabilityTracker.f(sseConnectionManager.o, str2, sseConnectionManager.b());
                    }
                } finally {
                    reentrantLock.unlock();
                }
            }

            @Override // com.vega.kmp.agent.core.util.sse.SseConnectionListener
            public final void a(String str2) {
                Intrinsics.checkNotNullParameter(str2, "");
                SseConnectionManager sseConnectionManager = this.a;
                ReentrantLock reentrantLock = sseConnectionManager.d;
                reentrantLock.lock();
                try {
                    sseConnectionManager.o.e(str2, sseConnectionManager.b());
                } finally {
                    reentrantLock.unlock();
                }
            }

            @Override // com.vega.kmp.agent.core.util.sse.SseConnectionListener
            public final void c(String str2) {
                Intrinsics.checkNotNullParameter(str2, "");
                SseConnectionManager sseConnectionManager = this.a;
                ReentrantLock reentrantLock = sseConnectionManager.d;
                reentrantLock.lock();
                try {
                    sseConnectionManager.o.c(str2, sseConnectionManager.b());
                } finally {
                    reentrantLock.unlock();
                }
            }

            @Override // com.vega.kmp.agent.core.util.sse.SseConnectionListener
            public final void d(int i, String str2, String str3, boolean z) {
                String str4 = "";
                Intrinsics.checkNotNullParameter(str2, "");
                BLog.Companion.e("EdwardAgent.SseConnectionManager", "onFail: errorCode = " + i + ", errorMsg = " + str2 + ", logId = " + str3);
                SseConnectionManager sseConnectionManager = this.a;
                ReentrantLock reentrantLock = sseConnectionManager.d;
                reentrantLock.lock();
                try {
                    SseStabilityTracker sseStabilityTracker = sseConnectionManager.o;
                    if (str3 != null) {
                        str4 = str3;
                    }
                    sseStabilityTracker.d(i, str2, str4, z, sseConnectionManager.b());
                } finally {
                    reentrantLock.unlock();
                }
            }

            @Override // com.vega.kmp.agent.core.util.sse.SseConnectionListener
            public final void e(int i, String str2, String str3, boolean z) {
                String str4 = "";
                Intrinsics.checkNotNullParameter(str2, "");
                BLog.Companion.e("EdwardAgent.SseConnectionManager", "onStreamFail: errorCode = " + i + ", errorMsg = " + str2 + ", logId = " + str3);
                SseConnectionManager sseConnectionManager = this.a;
                ReentrantLock reentrantLock = sseConnectionManager.d;
                reentrantLock.lock();
                try {
                    SseStabilityTracker sseStabilityTracker = sseConnectionManager.o;
                    if (str3 != null) {
                        str4 = str3;
                    }
                    sseStabilityTracker.j(i, str2, str4, z, sseConnectionManager.b());
                } finally {
                    reentrantLock.unlock();
                }
            }
        }, this.a.c, str, false, agentProtocolConfig.j, agentProtocolConfig.i, 64);
        this.j = sseConnection;
        sseConnection.b();
    }

    public final void a(String str) {
        Intrinsics.checkNotNullParameter(str, "");
        BLog.Companion.i("EdwardAgent.SseConnectionManager", "onRoundDone: roundId = " + str);
        ReentrantLock reentrantLock = this.d;
        reentrantLock.lock();
        try {
            if (!Intrinsics.areEqual(str, this.g)) {
                reentrantLock.unlock();
                return;
            }
            this.i = str;
            this.h = null;
            e();
            reentrantLock.unlock();
            this.c.invoke("ready_to_send");
        } catch (Throwable th) {
            reentrantLock.unlock();
            throw th;
        }
    }

    public final boolean c(AgentMessage agentMessage) {
        UserMessage userMessage;
        if (agentMessage instanceof UserMessage) {
            this.a.e().t().getClass();
            return ProtocolOptionModifier.b((UserMessage) agentMessage);
        }
        AgentMessage agentMessageA = this.a.L.a(ConversationExKt$lastUserMessage$1.e);
        if ((agentMessageA instanceof UserMessage) && (userMessage = (UserMessage) agentMessageA) != null && Intrinsics.areEqual(userMessage.c, agentMessage.c)) {
            this.a.e().t().getClass();
            if (!ProtocolOptionModifier.b(userMessage)) {
                return false;
            }
        }
        return true;
    }

    /* JADX WARN: Multi-variable type inference failed */
    public SseConnectionManager(Conversation conversation, AgentProtocolConfig agentProtocolConfig, Function1<? super String, Unit> function1) {
        Intrinsics.checkNotNullParameter(conversation, "");
        Intrinsics.checkNotNullParameter(agentProtocolConfig, "");
        Intrinsics.checkNotNullParameter(function1, "");
        this.a = conversation;
        this.b = agentProtocolConfig;
        this.c = function1;
        this.d = new ReentrantLock();
        this.g = "";
        this.i = "";
        this.k = Long.MIN_VALUE;
        this.m = "foreground";
        this.o = new SseStabilityTracker(conversation, agentProtocolConfig.h, new Function0<SseTrackerRuntimeSnapshot>() { // from class: com.vega.kmp.agent.core.protocol.impl.message.SseConnectionManager$stabilityTracker$1
            {
                super(0);
            }

            public final Object invoke() {
                SseConnectionManager sseConnectionManager = this.e;
                ReentrantLock reentrantLock = sseConnectionManager.d;
                reentrantLock.lock();
                try {
                    return sseConnectionManager.b();
                } finally {
                    reentrantLock.unlock();
                }
            }
        }, new Function1<String, Unit>() { // from class: com.vega.kmp.agent.core.protocol.impl.message.SseConnectionManager$stabilityTracker$2
            {
                super(1);
            }

            public final Object invoke(Object obj) {
                String str = (String) obj;
                Intrinsics.checkNotNullParameter(str, "");
                SseConnectionManager sseConnectionManager = this.e;
                ReentrantLock reentrantLock = sseConnectionManager.d;
                reentrantLock.lock();
                try {
                    if (sseConnectionManager.e) {
                        BLog.Companion.i("EdwardAgent.SseConnectionManager", "requestStallRecover, isDestroyed = true, return");
                        sseConnectionManager.o.h();
                    } else {
                        SseConnection sseConnection = sseConnectionManager.j;
                        if (sseConnection == null) {
                            BLog.Companion.i("EdwardAgent.SseConnectionManager", "requestStallRecover, connection is null, return");
                            sseConnectionManager.o.h();
                        } else {
                            BLog.Companion.i("EdwardAgent.SseConnectionManager", "requestStallRecover: stallType = " + str + ", conversation.id = " + sseConnectionManager.a.c);
                            sseConnectionManager.o.i(sseConnectionManager.b());
                            sseConnectionManager.m = "reconnect";
                            sseConnectionManager.n = "stall_recover_disconnect";
                            sseConnectionManager.j = null;
                            sseConnection.a();
                            sseConnectionManager.d();
                        }
                    }
                    return Unit.INSTANCE;
                } finally {
                    reentrantLock.unlock();
                }
            }
        });
    }
}
