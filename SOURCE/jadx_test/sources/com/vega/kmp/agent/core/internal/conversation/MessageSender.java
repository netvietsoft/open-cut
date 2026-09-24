package com.vega.kmp.agent.core.internal.conversation;

import com.vega.kmp.agent.core.Conversation;
import com.vega.kmp.agent.core.ConversationRepo;
import com.vega.kmp.agent.core.SendCanceled;
import com.vega.kmp.agent.core.SendFailed;
import com.vega.kmp.agent.core.SendMessageResult;
import com.vega.kmp.agent.core.SendSuccess;
import com.vega.kmp.agent.core.depends.BLog;
import com.vega.kmp.agent.core.depends.EnsureManager;
import com.vega.kmp.agent.core.internal.conversation.util.GlobalMessagingResultObservable;
import com.vega.kmp.agent.core.internal.conversation.util.MessagingResultListener;
import com.vega.kmp.agent.core.internal.conversation.util.MessagingResultObservable;
import com.vega.kmp.agent.core.internal.events.MessagingPerfEvent;
import com.vega.kmp.agent.core.internal.events.SseMessagingSummary;
import com.vega.kmp.agent.core.internal.events.SseStabilityTracker;
import com.vega.kmp.agent.core.internal.fileupload.FileUploadDispatcher;
import com.vega.kmp.agent.core.internal.fileupload.FileUploadResult;
import com.vega.kmp.agent.core.message.AgentMessage;
import com.vega.kmp.agent.core.message.MessageUpdateType;
import com.vega.kmp.agent.core.message.ToolCallMessage;
import com.vega.kmp.agent.core.message.UserMessage;
import com.vega.kmp.agent.core.message.modifier.ProtocolOptionModifier;
import com.vega.kmp.agent.core.protocol.AgentMessagingProtocol;
import com.vega.kmp.agent.core.protocol.impl.message.DefaultAgentMessagingProtocol;
import com.vega.kmp.agent.core.util.EnsureManagerWrapper;
import com.vega.kmp.agent.core.util.MutableJsonObject;
import com.vega.kmp.agent.core.util.ResultedTask;
import com.vega.kmp.agent.core.util.TaskQueue;
import com.vega.kmp.agent.core.util.collection.CopyOnWriteArrayList;
import com.vega.kmp.agent.core.util.platform.PlatformUtils_androidKt;
import com.vega.kmp.agent.core.util.platform.System;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Set;
import java.util.concurrent.locks.ReentrantLock;
import kotlin.Result;
import kotlin.ResultKt;
import kotlin.Unit;
import kotlin.collections.CollectionsKt__CollectionsKt;
import kotlin.collections.CollectionsKt___CollectionsKt;
import kotlin.coroutines.Continuation;
import kotlin.coroutines.CoroutineContext;
import kotlin.coroutines.intrinsics.IntrinsicsKt__IntrinsicsJvmKt;
import kotlin.coroutines.intrinsics.IntrinsicsKt__IntrinsicsKt;
import kotlin.coroutines.jvm.internal.DebugProbesKt;
import kotlin.jvm.functions.Function1;
import kotlin.jvm.functions.Function2;
import kotlin.jvm.internal.Intrinsics;
import kotlinx.atomicfu.AtomicBoolean;
import kotlinx.atomicfu.AtomicFU;
import kotlinx.coroutines.BuildersKt__Builders_commonKt;
import kotlinx.coroutines.CancellableContinuation;
import kotlinx.coroutines.CancellableContinuationImpl;
import kotlinx.coroutines.CoroutineScope;
import kotlinx.coroutines.CoroutineScopeKt;
import kotlinx.coroutines.CoroutineStart;
import kotlinx.coroutines.Dispatchers;
import kotlinx.coroutines.channels.ChannelResult;
import kotlinx.coroutines.flow.MutableStateFlow;

/* JADX INFO: loaded from: D:\Decompiler\App\Video\Capcut\extracted\classes17.dex */
public final class MessageSender {
    public final CoroutineScope a;
    public final Conversation b;
    public final ConversationStateHelper c;
    public final AgentMessagingProtocol d;
    public final TaskQueue e;
    public final AtomicBoolean f;
    public MessagingResultCallback g;

    public /* synthetic */ class WhenMappings {
        static {
            FileUploadResult.values();
        }
    }

    public final SseMessagingSummary c() {
        DefaultAgentMessagingProtocol defaultAgentMessagingProtocol;
        AgentMessagingProtocol agentMessagingProtocol = this.d;
        SseMessagingSummary sseMessagingSummary = null;
        if ((agentMessagingProtocol instanceof DefaultAgentMessagingProtocol) && (defaultAgentMessagingProtocol = (DefaultAgentMessagingProtocol) agentMessagingProtocol) != null) {
            SseStabilityTracker sseStabilityTracker = defaultAgentMessagingProtocol.g.o;
            ReentrantLock reentrantLock = sseStabilityTracker.f;
            reentrantLock.lock();
            try {
                sseMessagingSummary = new SseMessagingSummary(sseStabilityTracker.t, sseStabilityTracker.u, sseStabilityTracker.r, sseStabilityTracker.s);
            } finally {
                reentrantLock.unlock();
            }
        }
        return sseMessagingSummary;
    }

    public final void a() {
        MessagingResultCallback messagingResultCallback;
        BLog.Companion.d("EdwardAgent.MessageSender", "[UnifyAgentMessage] abortMessaging: conversationId=" + this.b.c);
        this.d.c();
        while (ChannelResult.isSuccess-impl(this.e.b.tryReceive-PtdJZtk())) {
        }
        ConversationStateHelper conversationStateHelper = this.c;
        conversationStateHelper.f.setValue(0);
        conversationStateHelper.b(false);
        if (this.f.compareAndSet(true, false) && (messagingResultCallback = this.g) != null) {
            messagingResultCallback.b();
        }
    }

    public final class MessagingResultCallback {
        public final AgentMessage a;
        public final CancellableContinuation<SendMessageResult> b;
        public final boolean c;
        public final boolean d;
        public final AtomicBoolean e;
        public final Set<String> f;
        public boolean g;
        public boolean h;
        public boolean i;
        public final Function2<MessageUpdateType, AgentMessage, Unit> j;
        public final /* synthetic */ MessageSender k;

        public final void b() {
            if (!this.e.compareAndSet(false, true)) {
                return;
            }
            BLog.Companion.w("EdwardAgent.MessageSender", "[UnifyAgentMessage] onCanceled: messageId=" + this.a.b + ", conversationId=" + this.k.b.c);
            if (this.d) {
                this.k.f.setValue(false);
            }
            CancellableContinuation<SendMessageResult> cancellableContinuation = this.b;
            SendCanceled sendCanceled = SendCanceled.a;
            Result.constructor-impl(sendCanceled);
            e(cancellableContinuation, sendCanceled);
            if (this.h) {
                MessagingPerfEvent messagingPerfEvent = MessagingPerfEvent.a;
                AgentMessage agentMessage = this.a;
                SseMessagingSummary sseMessagingSummaryC = this.k.c();
                messagingPerfEvent.getClass();
                Intrinsics.checkNotNullParameter(agentMessage, "");
                MessagingPerfEvent.j(messagingPerfEvent, agentMessage, "cancel", sseMessagingSummaryC, 380);
            } else {
                MessagingPerfEvent messagingPerfEvent2 = MessagingPerfEvent.a;
                AgentMessage agentMessage2 = this.a;
                messagingPerfEvent2.getClass();
                Intrinsics.checkNotNullParameter(agentMessage2, "");
                MessagingPerfEvent.j(messagingPerfEvent2, agentMessage2, "send_cancel", null, 508);
            }
            MessagingResultObservable messagingResultObservable = this.k.b.M;
            AgentMessage agentMessage3 = this.a;
            messagingResultObservable.getClass();
            Intrinsics.checkNotNullParameter(agentMessage3, "");
            GlobalMessagingResultObservable globalMessagingResultObservable = GlobalMessagingResultObservable.a;
            Conversation conversation = messagingResultObservable.a;
            globalMessagingResultObservable.getClass();
            Intrinsics.checkNotNullParameter(conversation, "");
            Iterator<GlobalMessagingResultObservable.Listener> it = GlobalMessagingResultObservable.b.iterator();
            while (it.hasNext()) {
                it.next().d(conversation);
            }
            Iterator<MessagingResultListener> it2 = messagingResultObservable.b.iterator();
            while (it2.hasNext()) {
                it2.next().c(agentMessage3);
            }
            this.k.b.y(this.j);
        }

        public final void d() {
            if (!this.e.compareAndSet(false, true)) {
                return;
            }
            BLog.Companion.d("EdwardAgent.MessageSender", "[UnifyAgentMessage] onSuccess: messageId=" + this.a.b + ", conversationId=" + this.k.b.c);
            if (this.d) {
                this.k.f.setValue(false);
            }
            List<AgentMessage> listD = this.k.b.L.d(this.a);
            ArrayList arrayList = new ArrayList();
            for (Object obj : (ArrayList) listD) {
                if (Intrinsics.areEqual(((AgentMessage) obj).c, this.a.c)) {
                    arrayList.add(obj);
                }
            }
            if (this.c) {
                CancellableContinuation<SendMessageResult> cancellableContinuation = this.b;
                SendSuccess sendSuccess = new SendSuccess(arrayList);
                Result.constructor-impl(sendSuccess);
                e(cancellableContinuation, sendSuccess);
            }
            MessagingPerfEvent messagingPerfEvent = MessagingPerfEvent.a;
            AgentMessage agentMessage = this.a;
            SseMessagingSummary sseMessagingSummaryC = this.k.c();
            CollectionsKt___CollectionsKt.firstOrNull(arrayList);
            messagingPerfEvent.getClass();
            Intrinsics.checkNotNullParameter(agentMessage, "");
            MessagingPerfEvent.j(messagingPerfEvent, agentMessage, "full_response_received", sseMessagingSummaryC, 380);
            MessagingResultObservable messagingResultObservable = this.k.b.M;
            AgentMessage agentMessage2 = this.a;
            messagingResultObservable.getClass();
            Intrinsics.checkNotNullParameter(agentMessage2, "");
            GlobalMessagingResultObservable globalMessagingResultObservable = GlobalMessagingResultObservable.a;
            Conversation conversation = messagingResultObservable.a;
            globalMessagingResultObservable.getClass();
            Intrinsics.checkNotNullParameter(conversation, "");
            Iterator<GlobalMessagingResultObservable.Listener> it = GlobalMessagingResultObservable.b.iterator();
            while (it.hasNext()) {
                it.next().a(conversation);
            }
            Iterator<MessagingResultListener> it2 = messagingResultObservable.b.iterator();
            while (it2.hasNext()) {
                it2.next().b(agentMessage2);
            }
            this.k.b.y(this.j);
        }

        public final void c(AgentMessage agentMessage) {
            if (!this.c) {
                CancellableContinuation<SendMessageResult> cancellableContinuation = this.b;
                SendSuccess sendSuccess = new SendSuccess(CollectionsKt__CollectionsKt.emptyList());
                Result.constructor-impl(sendSuccess);
                e(cancellableContinuation, sendSuccess);
            }
            if (agentMessage != null) {
                MessagingPerfEvent messagingPerfEvent = MessagingPerfEvent.a;
                AgentMessage agentMessage2 = this.a;
                messagingPerfEvent.getClass();
                Intrinsics.checkNotNullParameter(agentMessage2, "");
                synchronized (messagingPerfEvent) {
                    Long l = (Long) ((LinkedHashMap) MessagingPerfEvent.c).get(agentMessage2.b);
                    if (l != null) {
                        long jLongValue = l.longValue();
                        long jA = MessagingPerfEvent.a();
                        MessagingPerfEvent.b.b(jA, agentMessage2.c);
                        MessagingPerfEvent.h(messagingPerfEvent, agentMessage2, "first_chunk_received", jA - jLongValue, agentMessage, null, 16);
                    }
                }
            }
            MessagingResultObservable messagingResultObservable = this.k.b.M;
            AgentMessage agentMessage3 = this.a;
            messagingResultObservable.getClass();
            Intrinsics.checkNotNullParameter(agentMessage3, "");
            GlobalMessagingResultObservable globalMessagingResultObservable = GlobalMessagingResultObservable.a;
            Conversation conversation = messagingResultObservable.a;
            globalMessagingResultObservable.getClass();
            Intrinsics.checkNotNullParameter(conversation, "");
            Iterator<GlobalMessagingResultObservable.Listener> it = GlobalMessagingResultObservable.b.iterator();
            while (it.hasNext()) {
                it.next().e(conversation);
            }
            Iterator<MessagingResultListener> it2 = messagingResultObservable.b.iterator();
            while (it2.hasNext()) {
                it2.next().e(agentMessage3);
            }
        }

        public final void a(SendMessageResult sendMessageResult) {
            Intrinsics.checkNotNullParameter(sendMessageResult, "");
            if (sendMessageResult instanceof SendCanceled) {
                b();
                return;
            }
            Object obj = null;
            if (sendMessageResult instanceof SendFailed) {
                SendFailed sendFailed = (SendFailed) sendMessageResult;
                if (!this.e.compareAndSet(false, true)) {
                    return;
                }
                if (this.d) {
                    this.k.f.setValue(false);
                }
                BLog.Companion.e("EdwardAgent.MessageSender", "[UnifyAgentMessage] onFailed: messageId=" + this.a.b + ", errorCode=" + sendFailed.a + ", errorMsg=" + sendFailed.b + ", logId=" + sendFailed.c + ", conversationId=" + this.k.b.c);
                CancellableContinuation<SendMessageResult> cancellableContinuation = this.b;
                SendFailed sendFailedA = SendFailed.a(sendFailed, 0, 15);
                Result.constructor-impl(sendFailedA);
                e(cancellableContinuation, sendFailedA);
                for (Object obj2 : (ArrayList) this.k.b.L.d(this.a)) {
                    if (Intrinsics.areEqual(((AgentMessage) obj2).c, this.a.c)) {
                        obj = obj2;
                        break;
                    }
                }
                MessagingPerfEvent messagingPerfEvent = MessagingPerfEvent.a;
                AgentMessage agentMessage = this.a;
                int i = sendFailed.a;
                String str = sendFailed.b;
                String str2 = sendFailed.c;
                Integer numValueOf = Integer.valueOf(sendFailed.d);
                SseMessagingSummary sseMessagingSummaryC = this.k.c();
                messagingPerfEvent.getClass();
                Intrinsics.checkNotNullParameter(agentMessage, "");
                Intrinsics.checkNotNullParameter(str, "");
                Intrinsics.checkNotNullParameter(str2, "");
                messagingPerfEvent.i(agentMessage, "fail", Integer.valueOf(i), str, str2, numValueOf, "http_send", sseMessagingSummaryC, (AgentMessage) obj);
                MessagingResultObservable messagingResultObservable = this.k.b.M;
                AgentMessage agentMessage2 = this.a;
                int i2 = sendFailed.a;
                String str3 = sendFailed.b;
                String str4 = sendFailed.c;
                messagingResultObservable.getClass();
                Intrinsics.checkNotNullParameter(agentMessage2, "");
                Intrinsics.checkNotNullParameter(str3, "");
                GlobalMessagingResultObservable globalMessagingResultObservable = GlobalMessagingResultObservable.a;
                Conversation conversation = messagingResultObservable.a;
                globalMessagingResultObservable.getClass();
                Intrinsics.checkNotNullParameter(conversation, "");
                Iterator<GlobalMessagingResultObservable.Listener> it = GlobalMessagingResultObservable.b.iterator();
                while (it.hasNext()) {
                    it.next().c(conversation, i2, str3, str4);
                }
                Iterator<MessagingResultListener> it2 = messagingResultObservable.b.iterator();
                while (it2.hasNext()) {
                    it2.next().d(agentMessage2, i2, str3, str4);
                }
                this.k.b.y(this.j);
                return;
            }
            if (!(sendMessageResult instanceof SendSuccess)) {
                return;
            }
            this.a.n();
            AgentMessage agentMessage3 = this.a;
            if ((agentMessage3 instanceof UserMessage) && !this.d) {
                agentMessage3.o();
                c(null);
                d();
            } else {
                if (!(!((SendSuccess) sendMessageResult).a.isEmpty())) {
                    return;
                }
                d();
            }
        }

        public final void e(CancellableContinuation<? super SendMessageResult> cancellableContinuation, Object obj) {
            if (cancellableContinuation.isActive() && !this.g) {
                this.g = true;
                try {
                    cancellableContinuation.resumeWith(obj);
                } catch (Exception e) {
                    EnsureManager.Companion.a("Already resumed, error msg=" + e.getMessage(), null);
                }
            }
        }

        public MessagingResultCallback(MessageSender messageSender, AgentMessage agentMessage, CancellableContinuation<? super SendMessageResult> cancellableContinuation, boolean z, boolean z2) {
            Intrinsics.checkNotNullParameter(agentMessage, "");
            Intrinsics.checkNotNullParameter(cancellableContinuation, "");
            this.k = messageSender;
            this.a = agentMessage;
            this.b = cancellableContinuation;
            this.c = z;
            this.d = z2;
            this.e = AtomicFU.atomic(false);
            this.f = new LinkedHashSet();
            Function2<MessageUpdateType, AgentMessage, Unit> function2 = new Function2<MessageUpdateType, AgentMessage, Unit>() { // from class: com.vega.kmp.agent.core.internal.conversation.MessageSender$MessagingResultCallback$messageUpdateListener$1
                {
                    super(2);
                }

                public final Object invoke(Object obj, Object obj2) {
                    AgentMessage agentMessage2 = (AgentMessage) obj2;
                    Intrinsics.checkNotNullParameter(obj, "");
                    Intrinsics.checkNotNullParameter(agentMessage2, "");
                    MessageSender.MessagingResultCallback messagingResultCallback = this.e;
                    messagingResultCallback.getClass();
                    if (!agentMessage2.l() && Intrinsics.areEqual(agentMessage2.c, messagingResultCallback.a.c)) {
                        MessageUpdateType messageUpdateType = MessageUpdateType.Add;
                        if (obj == messageUpdateType && !messagingResultCallback.i) {
                            messagingResultCallback.i = true;
                            messagingResultCallback.c(agentMessage2);
                        }
                        if (obj == messageUpdateType && !messagingResultCallback.f.contains(agentMessage2.b)) {
                            messagingResultCallback.f.add(agentMessage2.b);
                            MessagingPerfEvent.a.b(messagingResultCallback.a, agentMessage2);
                        }
                        if ((obj == messageUpdateType || obj == MessageUpdateType.Update) && agentMessage2.l) {
                            messagingResultCallback.d();
                        }
                    }
                    return Unit.INSTANCE;
                }
            };
            this.j = function2;
            messageSender.g = this;
            if (z2) {
                messageSender.f.setValue(true);
            }
            messageSender.b.b(function2);
        }
    }

    public final void g(UserMessage userMessage) {
        Intrinsics.checkNotNullParameter(userMessage, "");
        BLog.Companion.d("EdwardAgent.MessageSender", "[UnifyAgentMessage] sendMessage: messageId=" + userMessage.b + ", contentType=" + userMessage.g + ", conversationId=" + this.b.c);
        this.b.e().t().getClass();
        if (ProtocolOptionModifier.b(userMessage)) {
            this.c.b(true);
        }
        i(userMessage);
        f(userMessage);
        BuildersKt__Builders_commonKt.launch$default(this.b.w, (CoroutineContext) null, (CoroutineStart) null, new sendMessage.1(this, userMessage, (Continuation) null), 3, (Object) null);
    }

    public final void i(UserMessage userMessage) {
        String str = this.b.c;
        userMessage.getClass();
        Intrinsics.checkNotNullParameter(str, "");
        userMessage.e = str;
        Conversation conversation = this.b;
        userMessage.a = conversation;
        String strG = conversation.e().g();
        Intrinsics.checkNotNullParameter(strG, "");
        userMessage.d = strG;
        userMessage.s(userMessage.b);
        if (userMessage.f == 0) {
            System.a.getClass();
            userMessage.f = System.currentTimeMillis();
        }
        Conversation conversation2 = this.b;
        MessageUpdateType messageUpdateType = MessageUpdateType.Add;
        conversation2.getClass();
        Intrinsics.checkNotNullParameter(messageUpdateType, "");
        conversation2.t(userMessage, messageUpdateType);
    }

    /* JADX WARN: Code duplicated, block: B:11:0x004b  */
    /* JADX WARN: Code duplicated, block: B:29:0x0010 A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:4:0x000f  */
    /* JADX WARN: Code duplicated, block: B:9:0x002f  */
    public final void f(AgentMessage agentMessage) {
        Conversation conversation;
        int size;
        MessagingPerfEvent messagingPerfEvent = MessagingPerfEvent.a;
        messagingPerfEvent.getClass();
        Intrinsics.checkNotNullParameter(agentMessage, "");
        if (!(agentMessage instanceof UserMessage) || (conversation = agentMessage.a) == null) {
            synchronized (messagingPerfEvent) {
                long jA = MessagingPerfEvent.a();
                MessagingPerfEvent.c.put(agentMessage.b, Long.valueOf(jA));
                MessagingPerfEvent.d.put(agentMessage.c, Long.valueOf(jA));
                if (agentMessage instanceof UserMessage) {
                    size = ((UserMessage) agentMessage).t.size();
                } else {
                    size = 0;
                }
                MessagingPerfEvent.b.d(size, jA, agentMessage.c);
                MessagingPerfEvent.h(messagingPerfEvent, agentMessage, "send", 0L, null, null, 24);
            }
        } else {
            conversation.e().t().getClass();
            if (ProtocolOptionModifier.b((UserMessage) agentMessage)) {
                synchronized (messagingPerfEvent) {
                    long jA2 = MessagingPerfEvent.a();
                    MessagingPerfEvent.c.put(agentMessage.b, Long.valueOf(jA2));
                    MessagingPerfEvent.d.put(agentMessage.c, Long.valueOf(jA2));
                }
                if (agentMessage instanceof UserMessage) {
                    size = ((UserMessage) agentMessage).t.size();
                } else {
                    size = 0;
                }
                MessagingPerfEvent.b.d(size, jA2, agentMessage.c);
                MessagingPerfEvent.h(messagingPerfEvent, agentMessage, "send", 0L, null, null, 24);
            }
        }
        this.b.e().j(this.b, agentMessage);
        MessagingResultObservable messagingResultObservable = this.b.M;
        messagingResultObservable.getClass();
        GlobalMessagingResultObservable globalMessagingResultObservable = GlobalMessagingResultObservable.a;
        Conversation conversation2 = messagingResultObservable.a;
        globalMessagingResultObservable.getClass();
        Intrinsics.checkNotNullParameter(conversation2, "");
        Iterator<GlobalMessagingResultObservable.Listener> it = GlobalMessagingResultObservable.b.iterator();
        while (it.hasNext()) {
            it.next().b(conversation2);
        }
        Iterator<MessagingResultListener> it2 = messagingResultObservable.b.iterator();
        while (it2.hasNext()) {
            it2.next().a(agentMessage);
        }
    }

    public final Object h(final ToolCallMessage toolCallMessage, final String str, Continuation<? super SendMessageResult> continuation) {
        return this.e.c(new ResultedTask() { // from class: com.vega.kmp.agent.core.internal.conversation.MessageSender$sendToolCallResultSync$2
            public final Object a(Continuation<Object> continuation2) {
                return this.a.b(toolCallMessage, str, continuation2);
            }
        }, continuation);
    }

    public MessageSender(CoroutineScope coroutineScope, Conversation conversation, ConversationStateHelper conversationStateHelper) {
        Intrinsics.checkNotNullParameter(coroutineScope, "");
        Intrinsics.checkNotNullParameter(conversation, "");
        Intrinsics.checkNotNullParameter(conversationStateHelper, "");
        this.a = coroutineScope;
        this.b = conversation;
        this.c = conversationStateHelper;
        this.d = conversation.C;
        this.e = new TaskQueue(CoroutineScopeKt.plus(coroutineScope, Dispatchers.getIO()));
        this.f = AtomicFU.atomic(false);
    }

    /* JADX WARN: Code duplicated, block: B:26:0x005b  */
    /* JADX WARN: Code duplicated, block: B:31:0x008f  */
    /* JADX WARN: Code duplicated, block: B:35:0x00be A[RETURN] */
    /* JADX WARN: Code duplicated, block: B:40:0x00d6  */
    /* JADX WARN: Code duplicated, block: B:43:0x0093 A[SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:46:? A[PHI: r2 r7 r11 r12
  PHI (r2v4 java.lang.Object) = (r2v2 java.lang.Object), (r2v9 java.lang.Object) binds: [B:22:0x0055, B:15:0x0035] A[DONT_GENERATE, DONT_INLINE]
  PHI (r7v1 int) = (r7v0 int), (r7v3 int) binds: [B:22:0x0055, B:15:0x0035] A[DONT_GENERATE, DONT_INLINE]
  PHI (r11v3 com.vega.kmp.agent.core.message.ToolCallMessage) = (r11v1 com.vega.kmp.agent.core.message.ToolCallMessage), (r11v4 com.vega.kmp.agent.core.message.ToolCallMessage) binds: [B:22:0x0055, B:15:0x0035] A[DONT_GENERATE, DONT_INLINE]
  PHI (r12v3 java.lang.String) = (r12v1 java.lang.String), (r12v4 java.lang.String) binds: [B:22:0x0055, B:15:0x0035] A[DONT_GENERATE, DONT_INLINE], SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:47:? A[LOOP:0: B:23:0x0056->B:47:?, LOOP_END, SYNTHETIC] */
    /* JADX WARN: Unsupported multi-entry loop pattern (BACK_EDGE: B:34:0x00bc -> B:14:0x0033). Please report as a decompilation issue!!! */
    /*  JADX ERROR: StackOverflowError in pass: RegionMakerVisitor
        java.lang.StackOverflowError
        	at jadx.core.utils.BlockUtils.traverseSuccessorsUntil(BlockUtils.java:731)
        	at jadx.core.utils.BlockUtils.traverseSuccessorsUntil(BlockUtils.java:749)
        */
    public final java.lang.Object b(com.vega.kmp.agent.core.message.ToolCallMessage r11, java.lang.String r12, kotlin.coroutines.Continuation<? super com.vega.kmp.agent.core.SendMessageResult> r13) {
        /*
            Method dump skipped, instruction units count: 229
            To view this dump add '--comments-level debug' option
        */
        throw new UnsupportedOperationException("Method not decompiled: com.vega.kmp.agent.core.internal.conversation.MessageSender.b(com.vega.kmp.agent.core.message.ToolCallMessage, java.lang.String, kotlin.coroutines.Continuation):java.lang.Object");
    }

    /* JADX WARN: Code duplicated, block: B:25:0x00ed  */
    public final Object e(ToolCallMessage toolCallMessage, String str, Continuation<? super SendMessageResult> continuation) {
        MessageSender$doSendToolCallResultSync$1 messageSender$doSendToolCallResultSync$1;
        ToolCallMessage toolCallMessage2 = toolCallMessage;
        String str2 = str;
        if (continuation instanceof MessageSender$doSendToolCallResultSync$1) {
            messageSender$doSendToolCallResultSync$1 = (MessageSender$doSendToolCallResultSync$1) continuation;
            int i = messageSender$doSendToolCallResultSync$1.u;
            if ((i & Integer.MIN_VALUE) != 0) {
                messageSender$doSendToolCallResultSync$1.u = i - Integer.MIN_VALUE;
            } else {
                messageSender$doSendToolCallResultSync$1 = new MessageSender$doSendToolCallResultSync$1(this, continuation);
            }
        } else {
            messageSender$doSendToolCallResultSync$1 = new MessageSender$doSendToolCallResultSync$1(this, continuation);
        }
        Object result = messageSender$doSendToolCallResultSync$1.s;
        Object coroutine_suspended = IntrinsicsKt__IntrinsicsKt.getCOROUTINE_SUSPENDED();
        int i2 = messageSender$doSendToolCallResultSync$1.u;
        if (i2 != 0) {
            if (i2 != 1) {
                if (i2 == 2) {
                    ResultKt.throwOnFailure(result);
                } else {
                    throw new IllegalStateException("call to 'resume' before 'invoke' with coroutine");
                }
            } else {
                str2 = (String) messageSender$doSendToolCallResultSync$1.r;
                toolCallMessage2 = messageSender$doSendToolCallResultSync$1.q;
                ResultKt.throwOnFailure(result);
            }
            return result;
        }
        ResultKt.throwOnFailure(result);
        Conversation conversation = this.b;
        messageSender$doSendToolCallResultSync$1.q = toolCallMessage2;
        messageSender$doSendToolCallResultSync$1.r = str2;
        messageSender$doSendToolCallResultSync$1.u = 1;
        if (conversation.i(messageSender$doSendToolCallResultSync$1) == coroutine_suspended) {
            return coroutine_suspended;
        }
        this.c.b(true);
        toolCallMessage2.a = this.b;
        f(toolCallMessage2);
        BLog.Companion.i("EdwardAgent.MessageSender", "sendToolCallResultSync: message.id = " + toolCallMessage2.b + ", result = " + toolCallMessage2.B);
        AgentMessage agentMessageB = toolCallMessage2.b();
        Intrinsics.checkNotNull(agentMessageB, "");
        ToolCallMessage toolCallMessage3 = (ToolCallMessage) agentMessageB;
        String strA = PlatformUtils_androidKt.a();
        Intrinsics.checkNotNullParameter(strA, "");
        toolCallMessage3.b = strA;
        toolCallMessage2.A(str2, strA, true);
        toolCallMessage3.s(toolCallMessage2.c);
        if (toolCallMessage3.B.length() <= 0) {
            EnsureManagerWrapper ensureManagerWrapper = EnsureManagerWrapper.a;
            String str3 = "tool result is empty, toolName = " + toolCallMessage2.u;
            ensureManagerWrapper.getClass();
            EnsureManagerWrapper.a(str3);
        }
        messageSender$doSendToolCallResultSync$1.q = toolCallMessage3;
        messageSender$doSendToolCallResultSync$1.r = null;
        messageSender$doSendToolCallResultSync$1.u = 2;
        CancellableContinuationImpl cancellableContinuationImpl = new CancellableContinuationImpl(IntrinsicsKt__IntrinsicsJvmKt.intercepted(messageSender$doSendToolCallResultSync$1), 1);
        cancellableContinuationImpl.initCancellability();
        BuildersKt__Builders_commonKt.launch$default(this.b.w, (CoroutineContext) null, (CoroutineStart) null, new doSendToolCallResultSync.2.1(this, toolCallMessage3, new MessagingResultCallback(this, toolCallMessage3, cancellableContinuationImpl, true, true), (Continuation) null), 3, (Object) null);
        result = cancellableContinuationImpl.getResult();
        if (result == IntrinsicsKt__IntrinsicsKt.getCOROUTINE_SUSPENDED()) {
            DebugProbesKt.probeCoroutineSuspended(messageSender$doSendToolCallResultSync$1);
        }
        if (result != coroutine_suspended) {
            return result;
        }
        return coroutine_suspended;
    }

    /* JADX WARN: Code duplicated, block: B:39:0x00fe  */
    /* JADX WARN: Code duplicated, block: B:42:0x0118 A[RETURN] */
    /* JADX WARN: Code duplicated, block: B:46:0x012a A[DONT_INVERT] */
    /* JADX WARN: Code duplicated, block: B:47:0x012c A[DONT_INVERT] */
    /* JADX WARN: Code duplicated, block: B:50:0x017d  */
    /* JADX WARN: Code duplicated, block: B:52:0x0182 A[RETURN] */
    /* JADX WARN: Code duplicated, block: B:53:0x0183  */
    /* JADX WARN: Code duplicated, block: B:54:0x019b  */
    /* JADX WARN: Code duplicated, block: B:55:0x01a1  */
    /* JADX WARN: Code duplicated, block: B:61:0x01b3  */
    /* JADX WARN: Code duplicated, block: B:63:0x01c7  */
    /* JADX WARN: Instruction removed from duplicated block: B:53:0x0183, please report this as an issue */
    public final Object d(UserMessage userMessage, boolean z, Continuation continuation) {
        MessageSender$doSendMessage$1 messageSender$doSendMessage$1;
        boolean z2;
        boolean zB;
        int iOrdinal;
        UserMessage userMessage2 = userMessage;
        if (continuation instanceof MessageSender$doSendMessage$1) {
            messageSender$doSendMessage$1 = (MessageSender$doSendMessage$1) continuation;
            int i = messageSender$doSendMessage$1.v;
            if ((i & Integer.MIN_VALUE) != 0) {
                messageSender$doSendMessage$1.v = i - Integer.MIN_VALUE;
            } else {
                messageSender$doSendMessage$1 = new MessageSender$doSendMessage$1(this, continuation);
            }
        } else {
            messageSender$doSendMessage$1 = new MessageSender$doSendMessage$1(this, continuation);
        }
        Object objD = messageSender$doSendMessage$1.t;
        Object coroutine_suspended = IntrinsicsKt__IntrinsicsKt.getCOROUTINE_SUSPENDED();
        int i2 = messageSender$doSendMessage$1.v;
        if (i2 != 0) {
            if (i2 != 1) {
                if (i2 != 2) {
                    if (i2 != 3) {
                        if (i2 == 4) {
                            ResultKt.throwOnFailure(objD);
                        } else {
                            throw new IllegalStateException("call to 'resume' before 'invoke' with coroutine");
                        }
                    } else {
                        zB = messageSender$doSendMessage$1.s;
                        z2 = messageSender$doSendMessage$1.r;
                        userMessage2 = messageSender$doSendMessage$1.q;
                        ResultKt.throwOnFailure(objD);
                        iOrdinal = ((FileUploadResult) objD).ordinal();
                        if (iOrdinal != 0) {
                            if (iOrdinal != 1) {
                                if (iOrdinal == 2) {
                                    MessagingPerfEvent messagingPerfEvent = MessagingPerfEvent.a;
                                    messagingPerfEvent.getClass();
                                    Intrinsics.checkNotNullParameter(userMessage2, "");
                                    MessagingPerfEvent.j(messagingPerfEvent, userMessage2, "send_cancel", null, 508);
                                    if (zB) {
                                        this.c.b(false);
                                    }
                                    return SendCanceled.a;
                                }
                            } else {
                                BLog.Companion.w("EdwardAgent.MessageSender", "upload assets failed, messageId = " + userMessage2.b);
                            }
                        } else {
                            MessagingPerfEvent.a.c(userMessage2);
                        }
                        BLog.Companion.d("EdwardAgent.MessageSender", "[UnifyAgentMessage] sendMessage enqueue: messageId=" + userMessage2.b + ", contentType=" + userMessage2.g);
                        messageSender$doSendMessage$1.q = userMessage2;
                        messageSender$doSendMessage$1.r = z2;
                        messageSender$doSendMessage$1.s = zB;
                        messageSender$doSendMessage$1.v = 4;
                        CancellableContinuationImpl cancellableContinuationImpl = new CancellableContinuationImpl(IntrinsicsKt__IntrinsicsJvmKt.intercepted(messageSender$doSendMessage$1), 1);
                        cancellableContinuationImpl.initCancellability();
                        this.e.a(new MessageSender$doSendMessage$3$1(this, userMessage2, cancellableContinuationImpl, z2, zB));
                        objD = cancellableContinuationImpl.getResult();
                        if (objD == IntrinsicsKt__IntrinsicsKt.getCOROUTINE_SUSPENDED()) {
                            DebugProbesKt.probeCoroutineSuspended(messageSender$doSendMessage$1);
                        }
                        if (objD != coroutine_suspended) {
                            return coroutine_suspended;
                        }
                    }
                } else {
                    z2 = messageSender$doSendMessage$1.r;
                    userMessage2 = messageSender$doSendMessage$1.q;
                    ResultKt.throwOnFailure(objD);
                    this.b.e().t().getClass();
                    zB = ProtocolOptionModifier.b(userMessage2);
                    if (zB) {
                        this.c.b(true);
                    }
                    FileUploadDispatcher fileUploadDispatcher = FileUploadDispatcher.a;
                    Conversation conversation = this.b;
                    messageSender$doSendMessage$1.q = userMessage2;
                    messageSender$doSendMessage$1.r = z2;
                    messageSender$doSendMessage$1.s = zB;
                    messageSender$doSendMessage$1.v = 3;
                    fileUploadDispatcher.getClass();
                    objD = FileUploadDispatcher.d(conversation, userMessage2, messageSender$doSendMessage$1);
                    if (objD == coroutine_suspended) {
                        return coroutine_suspended;
                    }
                    iOrdinal = ((FileUploadResult) objD).ordinal();
                    if (iOrdinal != 0) {
                        if (iOrdinal != 1) {
                            if (iOrdinal == 2) {
                                MessagingPerfEvent messagingPerfEvent2 = MessagingPerfEvent.a;
                                messagingPerfEvent2.getClass();
                                Intrinsics.checkNotNullParameter(userMessage2, "");
                                MessagingPerfEvent.j(messagingPerfEvent2, userMessage2, "send_cancel", null, 508);
                                if (zB) {
                                    this.c.b(false);
                                }
                                return SendCanceled.a;
                            }
                        } else {
                            BLog.Companion.w("EdwardAgent.MessageSender", "upload assets failed, messageId = " + userMessage2.b);
                        }
                    } else {
                        MessagingPerfEvent.a.c(userMessage2);
                    }
                    BLog.Companion.d("EdwardAgent.MessageSender", "[UnifyAgentMessage] sendMessage enqueue: messageId=" + userMessage2.b + ", contentType=" + userMessage2.g);
                    messageSender$doSendMessage$1.q = userMessage2;
                    messageSender$doSendMessage$1.r = z2;
                    messageSender$doSendMessage$1.s = zB;
                    messageSender$doSendMessage$1.v = 4;
                    CancellableContinuationImpl cancellableContinuationImpl2 = new CancellableContinuationImpl(IntrinsicsKt__IntrinsicsJvmKt.intercepted(messageSender$doSendMessage$1), 1);
                    cancellableContinuationImpl2.initCancellability();
                    this.e.a(new MessageSender$doSendMessage$3$1(this, userMessage2, cancellableContinuationImpl2, z2, zB));
                    objD = cancellableContinuationImpl2.getResult();
                    if (objD == IntrinsicsKt__IntrinsicsKt.getCOROUTINE_SUSPENDED()) {
                        DebugProbesKt.probeCoroutineSuspended(messageSender$doSendMessage$1);
                    }
                    if (objD != coroutine_suspended) {
                        return coroutine_suspended;
                    }
                }
            } else {
                z2 = messageSender$doSendMessage$1.r;
                userMessage2 = messageSender$doSendMessage$1.q;
                ResultKt.throwOnFailure(objD);
            }
            return objD;
        }
        ResultKt.throwOnFailure(objD);
        BLog.Companion.d("EdwardAgent.MessageSender", "[UnifyAgentMessage] sendMessage: messageId=" + userMessage2.b + ", contentType=" + userMessage2.g + ", conversationId=" + this.b.c);
        if (z) {
            i(userMessage2);
            f(userMessage2);
        }
        AgentMessagingProtocol agentMessagingProtocol = this.d;
        messageSender$doSendMessage$1.q = userMessage2;
        messageSender$doSendMessage$1.r = false;
        messageSender$doSendMessage$1.v = 1;
        if (agentMessagingProtocol.h() == coroutine_suspended) {
            return coroutine_suspended;
        }
        z2 = false;
        Conversation conversation2 = this.b;
        if (conversation2.e == 0) {
            System.a.getClass();
            conversation2.e = System.currentTimeMillis();
            this.b.J.j(userMessage2);
            ConversationRepo conversationRepo = ConversationRepo.a;
            Conversation conversation3 = this.b;
            conversationRepo.getClass();
            Intrinsics.checkNotNullParameter(conversation3, "");
            ConversationRepoImpl conversationRepoImpl = ConversationRepo.b;
            conversationRepoImpl.getClass();
            String str = conversation3.a;
            synchronized (conversationRepoImpl.c) {
                CopyOnWriteArrayList<Conversation> copyOnWriteArrayListH = conversationRepoImpl.h(str);
                copyOnWriteArrayListH.remove(conversation3);
                copyOnWriteArrayListH.add(0, conversation3);
                MutableStateFlow mutableStateFlow = (MutableStateFlow) ((LinkedHashMap) conversationRepoImpl.h).get(str);
                if (mutableStateFlow != null) {
                    mutableStateFlow.setValue(copyOnWriteArrayListH);
                }
            }
            userMessage2.x(new Function1<MutableJsonObject, Unit>() { // from class: com.vega.kmp.agent.core.internal.conversation.MessageSender$doSendMessage$2
                public final Object invoke(Object obj) {
                    MutableJsonObject mutableJsonObject = (MutableJsonObject) obj;
                    Intrinsics.checkNotNullParameter(mutableJsonObject, "");
                    mutableJsonObject.j("__is_first_round", true);
                    return Unit.INSTANCE;
                }
            }, true);
        }
        Conversation conversation4 = this.b;
        messageSender$doSendMessage$1.q = userMessage2;
        messageSender$doSendMessage$1.r = z2;
        messageSender$doSendMessage$1.v = 2;
        if (conversation4.i(messageSender$doSendMessage$1) == coroutine_suspended) {
            return coroutine_suspended;
        }
        this.b.e().t().getClass();
        zB = ProtocolOptionModifier.b(userMessage2);
        if (zB) {
            this.c.b(true);
        }
        FileUploadDispatcher fileUploadDispatcher2 = FileUploadDispatcher.a;
        Conversation conversation5 = this.b;
        messageSender$doSendMessage$1.q = userMessage2;
        messageSender$doSendMessage$1.r = z2;
        messageSender$doSendMessage$1.s = zB;
        messageSender$doSendMessage$1.v = 3;
        fileUploadDispatcher2.getClass();
        objD = FileUploadDispatcher.d(conversation5, userMessage2, messageSender$doSendMessage$1);
        if (objD == coroutine_suspended) {
            return coroutine_suspended;
        }
        iOrdinal = ((FileUploadResult) objD).ordinal();
        if (iOrdinal != 0) {
            if (iOrdinal != 1) {
                if (iOrdinal == 2) {
                    MessagingPerfEvent messagingPerfEvent3 = MessagingPerfEvent.a;
                    messagingPerfEvent3.getClass();
                    Intrinsics.checkNotNullParameter(userMessage2, "");
                    MessagingPerfEvent.j(messagingPerfEvent3, userMessage2, "send_cancel", null, 508);
                    if (zB) {
                        this.c.b(false);
                    }
                    return SendCanceled.a;
                }
            } else {
                BLog.Companion.w("EdwardAgent.MessageSender", "upload assets failed, messageId = " + userMessage2.b);
            }
        } else {
            MessagingPerfEvent.a.c(userMessage2);
        }
        BLog.Companion.d("EdwardAgent.MessageSender", "[UnifyAgentMessage] sendMessage enqueue: messageId=" + userMessage2.b + ", contentType=" + userMessage2.g);
        messageSender$doSendMessage$1.q = userMessage2;
        messageSender$doSendMessage$1.r = z2;
        messageSender$doSendMessage$1.s = zB;
        messageSender$doSendMessage$1.v = 4;
        CancellableContinuationImpl cancellableContinuationImpl3 = new CancellableContinuationImpl(IntrinsicsKt__IntrinsicsJvmKt.intercepted(messageSender$doSendMessage$1), 1);
        cancellableContinuationImpl3.initCancellability();
        this.e.a(new MessageSender$doSendMessage$3$1(this, userMessage2, cancellableContinuationImpl3, z2, zB));
        objD = cancellableContinuationImpl3.getResult();
        if (objD == IntrinsicsKt__IntrinsicsKt.getCOROUTINE_SUSPENDED()) {
            DebugProbesKt.probeCoroutineSuspended(messageSender$doSendMessage$1);
        }
        if (objD != coroutine_suspended) {
            return objD;
        }
        return coroutine_suspended;
    }
}
