package com.vega.kmp.agent.core.protocol.impl.message;

import com.vega.kmp.agent.core.Conversation;
import com.vega.kmp.agent.core.SendCanceled;
import com.vega.kmp.agent.core.SendFailed;
import com.vega.kmp.agent.core.SendMessageResult;
import com.vega.kmp.agent.core.SendSuccess;
import com.vega.kmp.agent.core.depends.BLog;
import com.vega.kmp.agent.core.internal.conversation.ChatMessageReadSnapshot;
import com.vega.kmp.agent.core.internal.conversation.MessageReadStatusUpdater;
import com.vega.kmp.agent.core.internal.conversation.MessageStatusUpdater;
import com.vega.kmp.agent.core.internal.events.MessagingPerfEvent;
import com.vega.kmp.agent.core.internal.events.SseStabilityTracker;
import com.vega.kmp.agent.core.internal.events.SseTrackerRuntimeSnapshot;
import com.vega.kmp.agent.core.message.AgentMessage;
import com.vega.kmp.agent.core.message.MessageUpdateType;
import com.vega.kmp.agent.core.message.ToolCallMessage;
import com.vega.kmp.agent.core.message.UserMessage;
import com.vega.kmp.agent.core.protocol.AgentMessagingProtocol;
import com.vega.kmp.agent.core.protocol.AgentProtocolCallback;
import com.vega.kmp.agent.core.protocol.AgentSystemEvent;
import com.vega.kmp.agent.core.protocol.AgentSystemEventHandlerKt;
import com.vega.kmp.agent.core.protocol.impl.db.ChatMessage;
import com.vega.kmp.agent.core.protocol.impl.db.ChatMessageExtKt;
import com.vega.kmp.agent.core.util.platform.FailResponse;
import com.vega.kmp.agent.core.util.platform.HttpResponse;
import com.vega.kmp.agent.core.util.platform.NetworkUtils;
import com.vega.kmp.agent.core.util.platform.PlatformUtilsKt;
import com.vega.kmp.agent.core.util.platform.SuccessResponse;
import com.vega.kmp.agent.core.util.sse.MessageEventChainManager;
import com.vega.kmp.agent.core.util.sse.SseConnection;
import com.vega.kmp.agent.core.util.sse.SseEventMetricsListener;
import com.vega.kmp.agent.core.util.sse.SseEventPatcher;
import com.vega.kmp.agent.core.util.sse.SsePatchEventListener;
import java.util.List;
import java.util.Map;
import java.util.concurrent.CancellationException;
import java.util.concurrent.locks.ReentrantLock;
import kotlin.NoWhenBranchMatchedException;
import kotlin.ResultKt;
import kotlin.Unit;
import kotlin.collections.CollectionsKt__CollectionsKt;
import kotlin.collections.MapsKt__MapsKt;
import kotlin.coroutines.Continuation;
import kotlin.coroutines.intrinsics.IntrinsicsKt__IntrinsicsKt;
import kotlin.jvm.functions.Function1;
import kotlin.jvm.internal.Intrinsics;
import kotlin.jvm.internal.Ref;
import kotlin.jvm.internal.Reflection;
import kotlin.random.Random;
import kotlin.random.RandomKt;
import kotlin.ranges.LongRange;
import kotlin.text.StringsKt__StringNumberConversionsKt;
import kotlinx.coroutines.BuildersKt__Builders_commonKt;
import kotlinx.coroutines.CoroutineStart;
import kotlinx.coroutines.DelayKt;
import kotlinx.coroutines.Dispatchers;
import kotlinx.coroutines.Job;
import kotlinx.serialization.KSerializer;
import kotlinx.serialization.SerializersKt__SerializersKt;
import kotlinx.serialization.json.Json;
import kotlinx.serialization.json.JsonElementBuildersKt;
import kotlinx.serialization.json.JsonObject;
import kotlinx.serialization.json.JsonObjectBuilder;

/* JADX INFO: loaded from: D:\Decompiler\App\Video\Capcut\extracted\classes17.dex */
public class DefaultAgentMessagingProtocol implements AgentMessagingProtocol {
    public final Conversation a;
    public final AgentProtocolConfig b;
    public volatile String c;
    public volatile boolean d;
    public AgentProtocolCallback e;
    public boolean f;
    public final SseConnectionManager g;
    public final SystemEventDispatcher h;
    public final MessageStorageManager i;
    public final SseEventPatcher j;
    public final HistoricMessageLoader k;

    public final void d() {
    }

    public final Object f(AgentMessage agentMessage, Continuation<? super Boolean> continuation) {
        return r(this, agentMessage, continuation);
    }

    public final Object k(AgentMessage agentMessage, Continuation<? super Boolean> continuation) {
        return q(this, agentMessage, continuation);
    }

    public final String e() {
        return this.c;
    }

    public final Unit h() {
        m();
        return Unit.INSTANCE;
    }

    public final Object i() {
        return true;
    }

    public final void g() {
        SseConnectionManager sseConnectionManager = this.g;
        ReentrantLock reentrantLock = sseConnectionManager.d;
        reentrantLock.lock();
        try {
            if (!sseConnectionManager.e) {
                sseConnectionManager.m = "reconnect";
                SseConnection sseConnection = sseConnectionManager.j;
                if (sseConnection != null) {
                    sseConnectionManager.n = "abort";
                    sseConnectionManager.j = null;
                    sseConnection.a();
                }
                sseConnectionManager.d();
            }
        } finally {
            reentrantLock.unlock();
        }
    }

    public final void c() {
        final SseConnectionManager sseConnectionManager = this.g;
        sseConnectionManager.getClass();
        Ref.ObjectRef objectRef = new Ref.ObjectRef();
        ReentrantLock reentrantLock = sseConnectionManager.d;
        reentrantLock.lock();
        try {
            AgentMessage agentMessage = sseConnectionManager.h;
            sseConnectionManager.h = null;
            reentrantLock.unlock();
            objectRef.element = agentMessage;
            if (agentMessage == null) {
                AgentMessage agentMessageA = sseConnectionManager.a.L.a(new Function1<AgentMessage, Boolean>() { // from class: com.vega.kmp.agent.core.protocol.impl.message.SseConnectionManager$abortMessaging$lastUserMessage$1
                    {
                        super(1);
                    }

                    public final Object invoke(Object obj) {
                        boolean z;
                        AgentMessage agentMessage2 = (AgentMessage) obj;
                        Intrinsics.checkNotNullParameter(agentMessage2, "");
                        if ((agentMessage2 instanceof UserMessage) && !agentMessage2.l && sseConnectionManager.c(agentMessage2)) {
                            z = true;
                        } else {
                            z = false;
                        }
                        return Boolean.valueOf(z);
                    }
                });
                if ((agentMessageA instanceof UserMessage) && agentMessageA != null && !agentMessageA.l) {
                    objectRef.element = agentMessageA;
                }
            }
            Object obj = objectRef.element;
            if (obj == null) {
                return;
            }
            sseConnectionManager.a(((AgentMessage) obj).c);
            if (!(objectRef.element instanceof UserMessage)) {
                return;
            }
            BuildersKt__Builders_commonKt.launch$default(sseConnectionManager.a.w, Dispatchers.getIO(), (CoroutineStart) null, new SseConnectionManager$abortMessaging$1(objectRef, sseConnectionManager, null), 2, (Object) null);
        } catch (Throwable th) {
            reentrantLock.unlock();
            throw th;
        }
    }

    public final void destroy() {
        SseConnectionManager sseConnectionManager = this.g;
        sseConnectionManager.getClass();
        BLog.Companion companion = BLog.Companion;
        companion.i("EdwardAgent.SseConnectionManager", "destroy: conversation.id = " + sseConnectionManager.a.c);
        ReentrantLock reentrantLock = sseConnectionManager.d;
        reentrantLock.lock();
        try {
            sseConnectionManager.e = true;
            SseConnection sseConnection = sseConnectionManager.j;
            if (sseConnection != null) {
                sseConnectionManager.n = "destroy";
                sseConnectionManager.j = null;
                sseConnection.a();
            }
            reentrantLock.unlock();
            SseStabilityTracker sseStabilityTracker = sseConnectionManager.o;
            sseStabilityTracker.getClass();
            companion.d("SseStabilityTracker", "stopWatchdog");
            Job job = sseStabilityTracker.A;
            if (job != null) {
                Job.DefaultImpls.cancel$default(job, (CancellationException) null, 1, (Object) null);
            }
            sseStabilityTracker.A = null;
        } catch (Throwable th) {
            reentrantLock.unlock();
            throw th;
        }
    }

    public final void m() {
        if (this.d) {
            return;
        }
        synchronized (this) {
            if (this.d) {
                return;
            }
            this.d = true;
            HistoricMessageLoader historicMessageLoader = this.k;
            if (historicMessageLoader.a.o()) {
                historicMessageLoader.f.d(0L);
                historicMessageLoader.f.b("loaded");
            } else {
                BuildersKt__Builders_commonKt.launch$default(historicMessageLoader.a.w, Dispatchers.getIO(), (CoroutineStart) null, new HistoricMessageLoader.init.1(historicMessageLoader, (Continuation) null), 2, (Object) null);
            }
            if (this.a.o() && !Intrinsics.areEqual("ready_to_send", this.c)) {
                this.c = "ready_to_send";
                AgentProtocolCallback agentProtocolCallback = this.e;
                if (agentProtocolCallback != null) {
                    agentProtocolCallback.e("ready_to_send");
                }
            }
        }
    }

    public final void p(Conversation.AnonymousClass1 anonymousClass1) {
        Intrinsics.checkNotNullParameter(anonymousClass1, "");
        this.e = anonymousClass1;
        if (this.f) {
            m();
        }
    }

    public final void l(boolean z) {
        this.f = z;
        if (z) {
            m();
        }
        SseConnectionManager sseConnectionManager = this.g;
        sseConnectionManager.getClass();
        BLog.Companion companion = BLog.Companion;
        companion.i("EdwardAgent.SseConnectionManager", "onForegroundChanged: isForeground = " + z);
        ReentrantLock reentrantLock = sseConnectionManager.d;
        reentrantLock.lock();
        try {
            sseConnectionManager.f = z;
            if (z) {
                sseConnectionManager.m = "foreground";
                sseConnectionManager.d();
                sseConnectionManager.o.p();
            } else {
                sseConnectionManager.e();
                SseStabilityTracker sseStabilityTracker = sseConnectionManager.o;
                sseStabilityTracker.getClass();
                companion.d("SseStabilityTracker", "stopWatchdog");
                Job job = sseStabilityTracker.A;
                if (job != null) {
                    Job.DefaultImpls.cancel$default(job, (CancellationException) null, 1, (Object) null);
                }
                sseStabilityTracker.A = null;
            }
        } finally {
            reentrantLock.unlock();
        }
    }

    public final Object a(ToolCallMessage toolCallMessage, Continuation<? super SendMessageResult> continuation) {
        return n(toolCallMessage, continuation);
    }

    public final Object b(UserMessage userMessage, Continuation<? super SendMessageResult> continuation) {
        return n(userMessage, continuation);
    }

    public final void j(UserMessage userMessage, MessageUpdateType messageUpdateType) {
        Intrinsics.checkNotNullParameter(userMessage, "");
        Intrinsics.checkNotNullParameter(messageUpdateType, "");
        AgentProtocolCallback agentProtocolCallback = this.e;
        if (agentProtocolCallback != null) {
            agentProtocolCallback.d(userMessage);
        }
    }

    /* JADX WARN: Type inference failed for: r7v1, types: [com.vega.kmp.agent.core.protocol.impl.message.DefaultAgentMessagingProtocol$historicMessageLoader$1] */
    /* JADX WARN: Type inference failed for: r9v0, types: [com.vega.kmp.agent.core.protocol.impl.message.DefaultAgentMessagingProtocol$subscribingEventPatcher$2] */
    public DefaultAgentMessagingProtocol(Conversation conversation, AgentProtocolConfig agentProtocolConfig) {
        Intrinsics.checkNotNullParameter(conversation, "");
        Intrinsics.checkNotNullParameter(agentProtocolConfig, "");
        this.a = conversation;
        this.b = agentProtocolConfig;
        this.c = "preparing";
        SseConnectionManager sseConnectionManager = new SseConnectionManager(conversation, agentProtocolConfig, new Function1<String, Unit>() { // from class: com.vega.kmp.agent.core.protocol.impl.message.DefaultAgentMessagingProtocol$connectionManager$1
            {
                super(1);
            }

            public final Object invoke(Object obj) {
                String str = (String) obj;
                Intrinsics.checkNotNullParameter(str, "");
                DefaultAgentMessagingProtocol defaultAgentMessagingProtocol = this.e;
                defaultAgentMessagingProtocol.getClass();
                if (!Intrinsics.areEqual(str, defaultAgentMessagingProtocol.c)) {
                    defaultAgentMessagingProtocol.c = str;
                    AgentProtocolCallback agentProtocolCallback = defaultAgentMessagingProtocol.e;
                    if (agentProtocolCallback != null) {
                        agentProtocolCallback.e(str);
                    }
                }
                return Unit.INSTANCE;
            }
        });
        this.g = sseConnectionManager;
        this.h = new SystemEventDispatcher(conversation, sseConnectionManager);
        MessageStorageManager messageStorageManager = new MessageStorageManager(conversation);
        this.i = messageStorageManager;
        MessageEventChainManager messageEventChainManager = new MessageEventChainManager(conversation);
        SseEventPatcher sseEventPatcher = new SseEventPatcher(new SsePatchEventListener() { // from class: com.vega.kmp.agent.core.protocol.impl.message.DefaultAgentMessagingProtocol$subscribingEventPatcher$1
            @Override // com.vega.kmp.agent.core.util.sse.SsePatchEventListener
            public final void b(String str, JsonObject jsonObject) {
                Intrinsics.checkNotNullParameter(str, "");
                Intrinsics.checkNotNullParameter(jsonObject, "");
                this.a.h.onEvent(jsonObject);
                AgentSystemEventHandlerKt.b(this.a.a, new AgentSystemEvent(str, "live_sse", jsonObject));
            }

            @Override // com.vega.kmp.agent.core.util.sse.SsePatchEventListener
            public final void a(String str, JsonObject jsonObject) {
                long jLongValue;
                Intrinsics.checkNotNullParameter(str, "");
                Intrinsics.checkNotNullParameter(jsonObject, "");
                Long longOrNull = StringsKt__StringNumberConversionsKt.toLongOrNull(str);
                if (longOrNull != null) {
                    jLongValue = longOrNull.longValue();
                } else {
                    jLongValue = 0;
                }
                Json json = PlatformUtilsKt.a;
                KSerializer kSerializerSerializer = SerializersKt__SerializersKt.serializer(json.getSerializersModule(), Reflection.typeOf(ChatMessage.class));
                Intrinsics.checkNotNull(kSerializerSerializer, "");
                ChatMessage chatMessageA = ChatMessageExtKt.a((ChatMessage) json.decodeFromJsonElement(kSerializerSerializer, jsonObject), this.a.a.c);
                if (this.a.a.e().n()) {
                    MessageReadStatusUpdater messageReadStatusUpdater = this.a.a.I;
                    ChatMessageReadSnapshot.Companion.getClass();
                    messageReadStatusUpdater.o(ChatMessageReadSnapshot.Companion.b(chatMessageA, jLongValue, 0L), "sse");
                }
                AgentMessage agentMessageB = ChatMessageExtKt.b(chatMessageA);
                MessageStatusUpdater messageStatusUpdater = this.a.a.O;
                messageStatusUpdater.getClass();
                Intrinsics.checkNotNullParameter(agentMessageB, "");
                messageStatusUpdater.c(agentMessageB);
                AgentProtocolCallback agentProtocolCallback = this.a.e;
                if (agentProtocolCallback != null) {
                    agentProtocolCallback.d(agentMessageB);
                }
                if (jLongValue > 0) {
                    MessageStorageManager messageStorageManager2 = this.a.i;
                    messageStorageManager2.getClass();
                    Intrinsics.checkNotNullParameter(chatMessageA, "");
                    BuildersKt__Builders_commonKt.launch$default(messageStorageManager2.a.w, Dispatchers.getIO(), (CoroutineStart) null, new MessageStorageManager$saveReceivedMessage$1(messageStorageManager2, jLongValue, chatMessageA, null), 2, (Object) null);
                    SseConnectionManager sseConnectionManager2 = this.a.g;
                    ReentrantLock reentrantLock = sseConnectionManager2.d;
                    reentrantLock.lock();
                    try {
                        sseConnectionManager2.k = jLongValue;
                    } finally {
                        reentrantLock.unlock();
                    }
                }
            }
        }, new SseEventMetricsListener() { // from class: com.vega.kmp.agent.core.protocol.impl.message.DefaultAgentMessagingProtocol$subscribingEventPatcher$2
            @Override // com.vega.kmp.agent.core.util.sse.SseEventMetricsListener
            public final void a() {
                SseStabilityTracker sseStabilityTracker = this.a.g.o;
                ReentrantLock reentrantLock = sseStabilityTracker.f;
                reentrantLock.lock();
                try {
                    sseStabilityTracker.o = ((Number) sseStabilityTracker.e.invoke()).longValue();
                    sseStabilityTracker.k++;
                } finally {
                    reentrantLock.unlock();
                }
            }

            @Override // com.vega.kmp.agent.core.util.sse.SseEventMetricsListener
            public final void b() {
                SseStabilityTracker sseStabilityTracker = this.a.g.o;
                ReentrantLock reentrantLock = sseStabilityTracker.f;
                reentrantLock.lock();
                try {
                    long jLongValue = ((Number) sseStabilityTracker.e.invoke()).longValue();
                    sseStabilityTracker.s = Math.max(sseStabilityTracker.s, jLongValue - sseStabilityTracker.p);
                    sseStabilityTracker.o = jLongValue;
                    sseStabilityTracker.p = jLongValue;
                    sseStabilityTracker.q++;
                    sseStabilityTracker.m = true;
                    if (sseStabilityTracker.x) {
                        long jMax = Math.max(0L, jLongValue - sseStabilityTracker.y);
                        BLog.Companion.i("SseStabilityTracker", "stall recover success, stallType = " + sseStabilityTracker.w + ", time_to_first_business_ms = " + jMax);
                        SseTrackerRuntimeSnapshot sseTrackerRuntimeSnapshot = sseStabilityTracker.z;
                        if (sseTrackerRuntimeSnapshot != null) {
                            sseStabilityTracker.n(true, jMax, sseTrackerRuntimeSnapshot);
                        }
                        sseStabilityTracker.a();
                    }
                } finally {
                    reentrantLock.unlock();
                }
            }
        }, messageEventChainManager, null, 8);
        this.j = sseEventPatcher;
        this.k = new HistoricMessageLoader(conversation, agentProtocolConfig, sseEventPatcher, messageStorageManager, messageEventChainManager, new HistoricMessageLoader.Callback() { // from class: com.vega.kmp.agent.core.protocol.impl.message.DefaultAgentMessagingProtocol$historicMessageLoader$1
            public boolean a = true;

            @Override // com.vega.kmp.agent.core.protocol.impl.message.HistoricMessageLoader.Callback
            public final void a(List<? extends AgentMessage> list) {
                Intrinsics.checkNotNullParameter(list, "");
                AgentProtocolCallback agentProtocolCallback = this.b.e;
                if (agentProtocolCallback != null) {
                    agentProtocolCallback.a(list);
                }
                this.b.g.f();
            }

            @Override // com.vega.kmp.agent.core.protocol.impl.message.HistoricMessageLoader.Callback
            public final void c(List<? extends AgentMessage> list) {
                Intrinsics.checkNotNullParameter(list, "");
                AgentProtocolCallback agentProtocolCallback = this.b.e;
                if (agentProtocolCallback != null) {
                    agentProtocolCallback.c(list);
                }
                if (this.a) {
                    this.a = false;
                    this.b.g.f();
                }
            }

            @Override // com.vega.kmp.agent.core.protocol.impl.message.HistoricMessageLoader.Callback
            public final void b(String str) {
                Intrinsics.checkNotNullParameter(str, "");
                BLog.Companion.i("EdwardAgent.DefaultAgentMessagingProtocol", "onLoadingStateChanged: state = " + str + ", conversation.id = " + this.b.a.c);
                AgentProtocolCallback agentProtocolCallback = this.b.e;
                if (agentProtocolCallback != null) {
                    agentProtocolCallback.b(str);
                }
            }

            @Override // com.vega.kmp.agent.core.protocol.impl.message.HistoricMessageLoader.Callback
            public final void d(long j) {
                DefaultAgentMessagingProtocol defaultAgentMessagingProtocol = this.b;
                SseConnectionManager sseConnectionManager2 = defaultAgentMessagingProtocol.g;
                SseEventPatcher sseEventPatcher2 = defaultAgentMessagingProtocol.j;
                sseConnectionManager2.getClass();
                Intrinsics.checkNotNullParameter(sseEventPatcher2, "");
                BLog.Companion.i("EdwardAgent.SseConnectionManager", "onLatestEventIdFetched: latestEventId = " + j + ", conversation.id = " + sseConnectionManager2.a.c);
                ReentrantLock reentrantLock = sseConnectionManager2.d;
                reentrantLock.lock();
                try {
                    sseConnectionManager2.m = "event_id_ready";
                    sseConnectionManager2.k = j;
                    sseConnectionManager2.l = sseEventPatcher2;
                    sseConnectionManager2.d();
                } finally {
                    reentrantLock.unlock();
                }
            }
        });
    }

    /* JADX INFO: Thrown type has an unknown type hierarchy: kotlin.NoWhenBranchMatchedException */
    /* JADX WARN: Code duplicated, block: B:11:0x002e  */
    public final Object o(AgentMessage agentMessage, Continuation<? super SendMessageResult> continuation) throws NoWhenBranchMatchedException {
        DefaultAgentMessagingProtocol$doSendMessageInner$1 defaultAgentMessagingProtocol$doSendMessageInner$1;
        AgentMessage agentMessage2 = agentMessage;
        if (continuation instanceof DefaultAgentMessagingProtocol$doSendMessageInner$1) {
            defaultAgentMessagingProtocol$doSendMessageInner$1 = (DefaultAgentMessagingProtocol$doSendMessageInner$1) continuation;
            int i = defaultAgentMessagingProtocol$doSendMessageInner$1.t;
            if ((i & Integer.MIN_VALUE) != 0) {
                defaultAgentMessagingProtocol$doSendMessageInner$1.t = i - Integer.MIN_VALUE;
            } else {
                defaultAgentMessagingProtocol$doSendMessageInner$1 = new DefaultAgentMessagingProtocol$doSendMessageInner$1(this, continuation);
            }
        } else {
            defaultAgentMessagingProtocol$doSendMessageInner$1 = new DefaultAgentMessagingProtocol$doSendMessageInner$1(this, continuation);
        }
        Object objB = defaultAgentMessagingProtocol$doSendMessageInner$1.r;
        Object coroutine_suspended = IntrinsicsKt__IntrinsicsKt.getCOROUTINE_SUSPENDED();
        int i2 = defaultAgentMessagingProtocol$doSendMessageInner$1.t;
        try {
            if (i2 != 0) {
                if (i2 == 1) {
                    agentMessage2 = defaultAgentMessagingProtocol$doSendMessageInner$1.q;
                    ResultKt.throwOnFailure(objB);
                } else {
                    throw new IllegalStateException("call to 'resume' before 'invoke' with coroutine");
                }
            } else {
                ResultKt.throwOnFailure(objB);
                BLog.Companion.d("EdwardAgent.DefaultAgentMessagingProtocol", "doSendMessageInner: message = " + agentMessage2.hashCode());
                NetworkUtils networkUtils = NetworkUtils.a;
                AgentProtocolConfig agentProtocolConfig = this.b;
                String str = agentProtocolConfig.a;
                Map<String, String> map = agentProtocolConfig.j;
                ChatMessage chatMessageC = ChatMessageExtKt.c(agentMessage2);
                Json json = PlatformUtilsKt.a;
                KSerializer kSerializerSerializer = SerializersKt__SerializersKt.serializer(json.getSerializersModule(), Reflection.typeOf(ChatMessage.class));
                Intrinsics.checkNotNull(kSerializerSerializer, "");
                String strEncodeToString = json.encodeToString(kSerializerSerializer, chatMessageC);
                defaultAgentMessagingProtocol$doSendMessageInner$1.q = agentMessage2;
                defaultAgentMessagingProtocol$doSendMessageInner$1.t = 1;
                objB = NetworkUtils.b(networkUtils, str, map, strEncodeToString, defaultAgentMessagingProtocol$doSendMessageInner$1, 2);
                if (objB == coroutine_suspended) {
                    return coroutine_suspended;
                }
            }
            HttpResponse httpResponse = (HttpResponse) objB;
            if (httpResponse instanceof SuccessResponse) {
                return new SendSuccess(CollectionsKt__CollectionsKt.emptyList());
            }
            if (httpResponse instanceof FailResponse) {
                BuildersKt__Builders_commonKt.launch$default(this.a.w, Dispatchers.getIO(), (CoroutineStart) null, new DefaultAgentMessagingProtocol$doSendMessageInner$2(this, httpResponse, agentMessage2, null), 2, (Object) null);
                return new SendFailed(((FailResponse) httpResponse).a, ((FailResponse) httpResponse).b, ((FailResponse) httpResponse).c, 0);
            }
            throw new NoWhenBranchMatchedException();
        } catch (Exception e) {
            BLog.Companion.e("EdwardAgent.DefaultAgentMessagingProtocol", "sendMessage: failed", e);
            BuildersKt__Builders_commonKt.launch$default(this.a.w, Dispatchers.getIO(), (CoroutineStart) null, new DefaultAgentMessagingProtocol$doSendMessageInner$3(this, e, agentMessage2, null), 2, (Object) null);
            if (e instanceof CancellationException) {
                return SendCanceled.a;
            }
            NetworkUtils.a.getClass();
            return new SendFailed(-1, "networkEnable: " + NetworkUtils.e() + ", exception: " + e, "", 0);
        }
    }

    /* JADX INFO: Thrown type has an unknown type hierarchy: kotlin.NoWhenBranchMatchedException */
    /* JADX WARN: Code duplicated, block: B:16:0x0044  */
    /* JADX WARN: Code duplicated, block: B:24:0x00c3 A[RETURN] */
    /* JADX WARN: Code duplicated, block: B:44:0x017b  */
    /* JADX WARN: Code duplicated, block: B:47:0x01a5 A[DONT_INVERT] */
    /* JADX WARN: Code duplicated, block: B:48:0x01a7  */
    /* JADX WARN: Code duplicated, block: B:50:0x01af A[DONT_INVERT] */
    /* JADX WARN: Code duplicated, block: B:51:0x01b1 A[DONT_INVERT] */
    /* JADX WARN: Code duplicated, block: B:52:0x01b3  */
    /* JADX WARN: Code duplicated, block: B:55:0x01d3  */
    /* JADX WARN: Code duplicated, block: B:58:0x01e2 A[Catch: all -> 0x01fd, TryCatch #1 {all -> 0x01fd, blocks: (B:56:0x01d8, B:58:0x01e2), top: B:74:0x01d8 }] */
    /* JADX WARN: Code duplicated, block: B:59:0x01ed  */
    /* JADX WARN: Code duplicated, block: B:63:0x01f5  */
    /* JADX WARN: Code duplicated, block: B:76:? A[RETURN, SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:77:? A[RETURN, SYNTHETIC] */
    /* JADX WARN: Multi-variable type inference failed */
    /* JADX WARN: Type inference failed for: r1v0 */
    /* JADX WARN: Type inference failed for: r1v1, types: [boolean, int] */
    /* JADX WARN: Type inference failed for: r1v7 */
    /* JADX WARN: Type inference fix 'apply assigned field type' failed
    java.lang.UnsupportedOperationException: ArgType.getObject(), call class: class jadx.core.dex.instructions.args.ArgType$PrimitiveArg
    	at jadx.core.dex.instructions.args.ArgType.getObject(ArgType.java:596)
    	at jadx.core.dex.attributes.nodes.ClassTypeVarsAttr.getTypeVarsMapFor(ClassTypeVarsAttr.java:35)
    	at jadx.core.dex.nodes.utils.TypeUtils.replaceClassGenerics(TypeUtils.java:177)
    	at jadx.core.dex.visitors.typeinference.FixTypesVisitor.insertExplicitUseCast(FixTypesVisitor.java:397)
    	at jadx.core.dex.visitors.typeinference.FixTypesVisitor.tryFieldTypeWithNewCasts(FixTypesVisitor.java:359)
    	at jadx.core.dex.visitors.typeinference.FixTypesVisitor.applyFieldType(FixTypesVisitor.java:309)
    	at jadx.core.dex.visitors.typeinference.FixTypesVisitor.visit(FixTypesVisitor.java:94)
     */
    /* JADX WARN: Unsupported multi-entry loop pattern (BACK_EDGE: B:23:0x00c1 -> B:13:0x003b). Please report as a decompilation issue!!! */
    public final Object n(AgentMessage agentMessage, Continuation<? super SendMessageResult> continuation) throws NoWhenBranchMatchedException {
        DefaultAgentMessagingProtocol$doSendMessage$1 defaultAgentMessagingProtocol$doSendMessage$1;
        boolean z;
        SendMessageRetryConfig sendMessageRetryConfig;
        int i;
        Ref.IntRef intRef;
        SendMessageResult sendMessageResult;
        boolean z2;
        SseConnectionManager sseConnectionManager;
        boolean z3;
        int i2;
        AgentMessage agentMessage2 = agentMessage;
        if (continuation instanceof DefaultAgentMessagingProtocol$doSendMessage$1) {
            defaultAgentMessagingProtocol$doSendMessage$1 = (DefaultAgentMessagingProtocol$doSendMessage$1) continuation;
            int i3 = defaultAgentMessagingProtocol$doSendMessage$1.x;
            if ((i3 & Integer.MIN_VALUE) != 0) {
                defaultAgentMessagingProtocol$doSendMessage$1.x = i3 - Integer.MIN_VALUE;
            } else {
                defaultAgentMessagingProtocol$doSendMessage$1 = new DefaultAgentMessagingProtocol$doSendMessage$1(this, continuation);
            }
        } else {
            defaultAgentMessagingProtocol$doSendMessage$1 = new DefaultAgentMessagingProtocol$doSendMessage$1(this, continuation);
        }
        Object objO = defaultAgentMessagingProtocol$doSendMessage$1.v;
        Object coroutine_suspended = IntrinsicsKt__IntrinsicsKt.getCOROUTINE_SUSPENDED();
        int i4 = defaultAgentMessagingProtocol$doSendMessage$1.x;
        ?? r1 = 1;
        if (i4 != 0) {
            if (i4 != 1) {
                if (i4 != 2) {
                    if (i4 == 3) {
                        i = defaultAgentMessagingProtocol$doSendMessage$1.u;
                        z = defaultAgentMessagingProtocol$doSendMessage$1.t;
                        intRef = defaultAgentMessagingProtocol$doSendMessage$1.s;
                        sendMessageRetryConfig = defaultAgentMessagingProtocol$doSendMessage$1.r;
                        agentMessage2 = defaultAgentMessagingProtocol$doSendMessage$1.q;
                        ResultKt.throwOnFailure(objO);
                    } else {
                        throw new IllegalStateException("call to 'resume' before 'invoke' with coroutine");
                    }
                } else {
                    i = defaultAgentMessagingProtocol$doSendMessage$1.u;
                    z = defaultAgentMessagingProtocol$doSendMessage$1.t;
                    intRef = defaultAgentMessagingProtocol$doSendMessage$1.s;
                    sendMessageRetryConfig = defaultAgentMessagingProtocol$doSendMessage$1.r;
                    agentMessage2 = defaultAgentMessagingProtocol$doSendMessage$1.q;
                    ResultKt.throwOnFailure(objO);
                    defaultAgentMessagingProtocol$doSendMessage$1.q = agentMessage2;
                    defaultAgentMessagingProtocol$doSendMessage$1.r = sendMessageRetryConfig;
                    defaultAgentMessagingProtocol$doSendMessage$1.s = intRef;
                    defaultAgentMessagingProtocol$doSendMessage$1.t = z;
                    defaultAgentMessagingProtocol$doSendMessage$1.u = i;
                    defaultAgentMessagingProtocol$doSendMessage$1.x = 3;
                    objO = o(agentMessage2, defaultAgentMessagingProtocol$doSendMessage$1);
                    if (objO == coroutine_suspended) {
                        return coroutine_suspended;
                    }
                }
            } else {
                i = defaultAgentMessagingProtocol$doSendMessage$1.u;
                z = defaultAgentMessagingProtocol$doSendMessage$1.t;
                intRef = defaultAgentMessagingProtocol$doSendMessage$1.s;
                sendMessageRetryConfig = defaultAgentMessagingProtocol$doSendMessage$1.r;
                agentMessage2 = defaultAgentMessagingProtocol$doSendMessage$1.q;
                ResultKt.throwOnFailure(objO);
            }
            sendMessageResult = (SendMessageResult) objO;
            r1 = 1;
            z2 = sendMessageResult instanceof SendFailed;
            if (!z2 && (i2 = intRef.element) < i) {
                int i5 = i2 + 1;
                intRef.element = i5;
                long j = sendMessageRetryConfig.b * ((long) (r1 << (i5 - 1)));
                Random.Default r16 = Random.Default;
                long j2 = sendMessageRetryConfig.c;
                long jMax = Math.max(Math.min(j + RandomKt.nextLong(r16, new LongRange(-j2, j2)), sendMessageRetryConfig.d), 0L);
                BLog.Companion.d("EdwardAgent.DefaultAgentMessagingProtocol", "doSendMessage: retryCount = " + intRef.element + ", delay = " + jMax);
                defaultAgentMessagingProtocol$doSendMessage$1.q = agentMessage2;
                defaultAgentMessagingProtocol$doSendMessage$1.r = sendMessageRetryConfig;
                defaultAgentMessagingProtocol$doSendMessage$1.s = intRef;
                defaultAgentMessagingProtocol$doSendMessage$1.t = z;
                defaultAgentMessagingProtocol$doSendMessage$1.u = i;
                defaultAgentMessagingProtocol$doSendMessage$1.x = 2;
                if (DelayKt.delay(jMax, defaultAgentMessagingProtocol$doSendMessage$1) == coroutine_suspended) {
                    return coroutine_suspended;
                }
                defaultAgentMessagingProtocol$doSendMessage$1.q = agentMessage2;
                defaultAgentMessagingProtocol$doSendMessage$1.r = sendMessageRetryConfig;
                defaultAgentMessagingProtocol$doSendMessage$1.s = intRef;
                defaultAgentMessagingProtocol$doSendMessage$1.t = z;
                defaultAgentMessagingProtocol$doSendMessage$1.u = i;
                defaultAgentMessagingProtocol$doSendMessage$1.x = 3;
                objO = o(agentMessage2, defaultAgentMessagingProtocol$doSendMessage$1);
                if (objO == coroutine_suspended) {
                    return coroutine_suspended;
                }
                sendMessageResult = (SendMessageResult) objO;
                r1 = 1;
                z2 = sendMessageResult instanceof SendFailed;
                if (!z2) {
                }
                BLog.Companion.d("EdwardAgent.DefaultAgentMessagingProtocol", "doSendMessage: result = " + sendMessageResult + ", retryCount = " + intRef.element);
                if (sendMessageResult instanceof SendSuccess) {
                    if (!z) {
                        MessagingPerfEvent.a.e(intRef.element, agentMessage2, r1);
                        return sendMessageResult;
                    }
                    return sendMessageResult;
                }
                if (!z2) {
                    return sendMessageResult;
                }
                if (!z) {
                    MessagingPerfEvent.a.e(intRef.element, agentMessage2, false);
                    sseConnectionManager = this.g;
                    sseConnectionManager.getClass();
                    Intrinsics.checkNotNullParameter(agentMessage2, "");
                    if (sseConnectionManager.c(agentMessage2)) {
                        ReentrantLock reentrantLock = sseConnectionManager.d;
                        reentrantLock.lock();
                        if (Intrinsics.areEqual(agentMessage2.c, sseConnectionManager.g)) {
                            sseConnectionManager.h = null;
                            sseConnectionManager.g = "";
                            sseConnectionManager.i = "";
                            sseConnectionManager.e();
                            z3 = true;
                        } else {
                            z3 = false;
                        }
                        if (z3) {
                            sseConnectionManager.c.invoke("ready_to_send");
                        }
                    }
                }
                return SendFailed.a((SendFailed) sendMessageResult, intRef.element, 7);
            }
            BLog.Companion.d("EdwardAgent.DefaultAgentMessagingProtocol", "doSendMessage: result = " + sendMessageResult + ", retryCount = " + intRef.element);
            if (sendMessageResult instanceof SendSuccess) {
                if (!z) {
                    MessagingPerfEvent.a.e(intRef.element, agentMessage2, r1);
                    return sendMessageResult;
                }
                return sendMessageResult;
            }
            if (!z2) {
                return sendMessageResult;
            }
            if (!z) {
                MessagingPerfEvent.a.e(intRef.element, agentMessage2, false);
                sseConnectionManager = this.g;
                sseConnectionManager.getClass();
                Intrinsics.checkNotNullParameter(agentMessage2, "");
                if (sseConnectionManager.c(agentMessage2)) {
                    ReentrantLock reentrantLock2 = sseConnectionManager.d;
                    reentrantLock2.lock();
                    try {
                        if (Intrinsics.areEqual(agentMessage2.c, sseConnectionManager.g)) {
                            sseConnectionManager.h = null;
                            sseConnectionManager.g = "";
                            sseConnectionManager.i = "";
                            sseConnectionManager.e();
                            z3 = true;
                        } else {
                            z3 = false;
                        }
                        if (z3) {
                            sseConnectionManager.c.invoke("ready_to_send");
                        }
                    } finally {
                        reentrantLock2.unlock();
                    }
                }
            }
            return SendFailed.a((SendFailed) sendMessageResult, intRef.element, 7);
        }
        ResultKt.throwOnFailure(objO);
        this.a.e().t().getClass();
        Intrinsics.checkNotNullParameter(agentMessage2, "");
        if (AgentMessage.g(agentMessage2, "__interrupt").length() > 0) {
            z = true;
        } else {
            z = false;
        }
        if (!z) {
            SseConnectionManager sseConnectionManager2 = this.g;
            sseConnectionManager2.getClass();
            BLog.Companion.i("EdwardAgent.SseConnectionManager", "onSendMessage: message.id = " + agentMessage2.b);
            if (sseConnectionManager2.c(agentMessage2)) {
                ReentrantLock reentrantLock3 = sseConnectionManager2.d;
                reentrantLock3.lock();
                try {
                    sseConnectionManager2.m = "send_message";
                    sseConnectionManager2.g = agentMessage2.c;
                    sseConnectionManager2.h = agentMessage2;
                    sseConnectionManager2.o.g();
                    sseConnectionManager2.d();
                    reentrantLock3.unlock();
                    sseConnectionManager2.c.invoke("streaming_response");
                } catch (Throwable th) {
                    reentrantLock3.unlock();
                    throw th;
                }
            }
            AgentProtocolCallback agentProtocolCallback = this.e;
            if (agentProtocolCallback != null) {
                agentProtocolCallback.d(agentMessage2);
            }
            BuildersKt__Builders_commonKt.launch$default(this.a.w, Dispatchers.getIO(), (CoroutineStart) null, new DefaultAgentMessagingProtocol$doSendMessage$2(this, null), 2, (Object) null);
        }
        sendMessageRetryConfig = this.b.b;
        i = sendMessageRetryConfig.a;
        intRef = new Ref.IntRef();
        defaultAgentMessagingProtocol$doSendMessage$1.q = agentMessage2;
        defaultAgentMessagingProtocol$doSendMessage$1.r = sendMessageRetryConfig;
        defaultAgentMessagingProtocol$doSendMessage$1.s = intRef;
        defaultAgentMessagingProtocol$doSendMessage$1.t = z;
        defaultAgentMessagingProtocol$doSendMessage$1.u = i;
        defaultAgentMessagingProtocol$doSendMessage$1.x = 1;
        objO = o(agentMessage2, defaultAgentMessagingProtocol$doSendMessage$1);
        if (objO == coroutine_suspended) {
            return coroutine_suspended;
        }
        sendMessageResult = (SendMessageResult) objO;
        z2 = sendMessageResult instanceof SendFailed;
        if (!z2) {
        }
        BLog.Companion.d("EdwardAgent.DefaultAgentMessagingProtocol", "doSendMessage: result = " + sendMessageResult + ", retryCount = " + intRef.element);
        if (sendMessageResult instanceof SendSuccess) {
            if (!z) {
                MessagingPerfEvent.a.e(intRef.element, agentMessage2, r1);
                return sendMessageResult;
            }
            return sendMessageResult;
        }
        if (!z2) {
            return sendMessageResult;
        }
        if (!z) {
            MessagingPerfEvent.a.e(intRef.element, agentMessage2, false);
            sseConnectionManager = this.g;
            sseConnectionManager.getClass();
            Intrinsics.checkNotNullParameter(agentMessage2, "");
            if (sseConnectionManager.c(agentMessage2)) {
                ReentrantLock reentrantLock4 = sseConnectionManager.d;
                reentrantLock4.lock();
                if (Intrinsics.areEqual(agentMessage2.c, sseConnectionManager.g)) {
                    sseConnectionManager.h = null;
                    sseConnectionManager.g = "";
                    sseConnectionManager.i = "";
                    sseConnectionManager.e();
                    z3 = true;
                } else {
                    z3 = false;
                }
                if (z3) {
                    sseConnectionManager.c.invoke("ready_to_send");
                }
            }
        }
        return SendFailed.a((SendFailed) sendMessageResult, intRef.element, 7);
    }

    /* JADX WARN: Code duplicated, block: B:16:0x0035  */
    public static /* synthetic */ Object q(DefaultAgentMessagingProtocol defaultAgentMessagingProtocol, AgentMessage agentMessage, Continuation<? super Boolean> continuation) {
        DefaultAgentMessagingProtocol$updateLocalMessage$1 defaultAgentMessagingProtocol$updateLocalMessage$1;
        if (continuation instanceof DefaultAgentMessagingProtocol$updateLocalMessage$1) {
            defaultAgentMessagingProtocol$updateLocalMessage$1 = (DefaultAgentMessagingProtocol$updateLocalMessage$1) continuation;
            int i = defaultAgentMessagingProtocol$updateLocalMessage$1.s;
            if ((i & Integer.MIN_VALUE) != 0) {
                defaultAgentMessagingProtocol$updateLocalMessage$1.s = i - Integer.MIN_VALUE;
            } else {
                defaultAgentMessagingProtocol$updateLocalMessage$1 = new DefaultAgentMessagingProtocol$updateLocalMessage$1(defaultAgentMessagingProtocol, continuation);
            }
        } else {
            defaultAgentMessagingProtocol$updateLocalMessage$1 = new DefaultAgentMessagingProtocol$updateLocalMessage$1(defaultAgentMessagingProtocol, continuation);
        }
        Object obj = defaultAgentMessagingProtocol$updateLocalMessage$1.q;
        Object coroutine_suspended = IntrinsicsKt__IntrinsicsKt.getCOROUTINE_SUSPENDED();
        int i2 = defaultAgentMessagingProtocol$updateLocalMessage$1.s;
        if (i2 != 0) {
            if (i2 == 1) {
                ResultKt.throwOnFailure(obj);
            } else {
                throw new IllegalStateException("call to 'resume' before 'invoke' with coroutine");
            }
        } else {
            ResultKt.throwOnFailure(obj);
            MessageStorageManager messageStorageManager = defaultAgentMessagingProtocol.i;
            defaultAgentMessagingProtocol$updateLocalMessage$1.s = 1;
            if (messageStorageManager.c(agentMessage, defaultAgentMessagingProtocol$updateLocalMessage$1) == coroutine_suspended) {
                return coroutine_suspended;
            }
        }
        return true;
    }

    /* JADX WARN: Code duplicated, block: B:19:0x007e  */
    public static Object r(DefaultAgentMessagingProtocol defaultAgentMessagingProtocol, AgentMessage agentMessage, Continuation<? super Boolean> continuation) {
        DefaultAgentMessagingProtocol$updateRemoteMessage$1 defaultAgentMessagingProtocol$updateRemoteMessage$1;
        if (continuation instanceof DefaultAgentMessagingProtocol$updateRemoteMessage$1) {
            defaultAgentMessagingProtocol$updateRemoteMessage$1 = (DefaultAgentMessagingProtocol$updateRemoteMessage$1) continuation;
            int i = defaultAgentMessagingProtocol$updateRemoteMessage$1.s;
            if ((i & Integer.MIN_VALUE) != 0) {
                defaultAgentMessagingProtocol$updateRemoteMessage$1.s = i - Integer.MIN_VALUE;
            } else {
                defaultAgentMessagingProtocol$updateRemoteMessage$1 = new DefaultAgentMessagingProtocol$updateRemoteMessage$1(defaultAgentMessagingProtocol, continuation);
            }
        } else {
            defaultAgentMessagingProtocol$updateRemoteMessage$1 = new DefaultAgentMessagingProtocol$updateRemoteMessage$1(defaultAgentMessagingProtocol, continuation);
        }
        Object objB = defaultAgentMessagingProtocol$updateRemoteMessage$1.q;
        Object coroutine_suspended = IntrinsicsKt__IntrinsicsKt.getCOROUTINE_SUSPENDED();
        int i2 = defaultAgentMessagingProtocol$updateRemoteMessage$1.s;
        if (i2 != 0) {
            if (i2 == 1) {
                ResultKt.throwOnFailure(objB);
            } else {
                throw new IllegalStateException("call to 'resume' before 'invoke' with coroutine");
            }
        } else {
            ResultKt.throwOnFailure(objB);
            JsonObjectBuilder jsonObjectBuilder = new JsonObjectBuilder();
            JsonElementBuildersKt.put(jsonObjectBuilder, "agent_scene", defaultAgentMessagingProtocol.a.e().g());
            JsonElementBuildersKt.put(jsonObjectBuilder, "conversation_id", defaultAgentMessagingProtocol.a.c);
            JsonElementBuildersKt.put(jsonObjectBuilder, "message_id", agentMessage.b);
            JsonObject jsonObjectH = agentMessage.h();
            if (jsonObjectH == null) {
                jsonObjectH = new JsonObject(MapsKt__MapsKt.emptyMap());
            }
            jsonObjectBuilder.put("option", jsonObjectH);
            String string = jsonObjectBuilder.build().toString();
            NetworkUtils networkUtils = NetworkUtils.a;
            AgentProtocolConfig agentProtocolConfig = defaultAgentMessagingProtocol.b;
            String str = agentProtocolConfig.g;
            Map<String, String> map = agentProtocolConfig.j;
            defaultAgentMessagingProtocol$updateRemoteMessage$1.s = 1;
            objB = NetworkUtils.b(networkUtils, str, map, string, defaultAgentMessagingProtocol$updateRemoteMessage$1, 2);
            if (objB == coroutine_suspended) {
                return coroutine_suspended;
            }
        }
        return Boolean.valueOf(objB instanceof SuccessResponse);
    }
}
