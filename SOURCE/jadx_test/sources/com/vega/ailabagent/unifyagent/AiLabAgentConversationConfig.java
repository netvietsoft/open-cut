package com.vega.ailabagent.unifyagent;

import X.4cM;
import com.bytedance.news.common.settings.SettingsManager;
import com.vega.ailabagent.common.utils.AgentGsonProvider;
import com.vega.ailabagent.unifyagent.chat.data.ChatMessageContentParser;
import com.vega.ailabagent.unifyagent.chat.data.CommonTagManager;
import com.vega.ailabagent.unifyagent.chat.data.MediaGenStatus;
import com.vega.ailabagent.unifyagent.chat.data.MediaListModel;
import com.vega.ailabagent.unifyagent.chat.data.MessageMediaItem;
import com.vega.ailabagent.unifyagent.chat.data.NormalMessage;
import com.vega.ailabagent.unifyagent.conversation.AiLabAgentConversationAbilityKt$firstMessageEnterFrom$1;
import com.vega.ailabagent.unifyagent.conversation.AiLabHostSseTransport;
import com.vega.ailabagent.unifyagent.credit.CreditBalanceChangedSystemEventHandler;
import com.vega.ailabagent.unifyagent.credit.CreditRoundSummarySystemEventHandler;
import com.vega.ailabagent.unifyagent.data.AiLabMessageExtras;
import com.vega.ailabagent.unifyagent.history.ConversationInfoUpdatedSystemEventHandler;
import com.vega.ailabagent.unifyagent.settings.AiLabAgentConfigSettings;
import com.vega.ailabagent.unifyagent.settings.AiLabAgentMessageRetryConfig;
import com.vega.ailabagent.unifyagent.settings.AiLabAgentMessageRetrySettings;
import com.vega.ailabagent.unifyagent.settings.AiLabAgentReadSyncConfigSettings;
import com.vega.ailabagent.unifyagent.settings.AiLabAgentSseRecoverConfigSettings;
import com.vega.ailabagent.unifyagent.settings.AiLabHistoryPageOptimizeSettings;
import com.vega.ailabagent.unifyagent.settings.AiLabHistoryRedDotSettings;
import com.vega.ailabagent.unifyagent.settings.AiLabHostSseSettings;
import com.vega.ailabagent.unifyagent.settings.AiLabProductToolSettings;
import com.vega.ailabagent.unifyagent.settings.SseRecoverSettingsConfig;
import com.vega.config.ConfigSettingsKt;
import com.vega.core.api.LoginService;
import com.vega.core.context.ContextExtKt;
import com.vega.core.context.SPIService;
import com.vega.core.ext.ExtentionKt;
import com.vega.core.utils.FunctionsKt;
import com.vega.costreport.aigc.BabiParams;
import com.vega.kmp.agent.core.Conversation;
import com.vega.kmp.agent.core.internal.conversation.ConversationConfig;
import com.vega.kmp.agent.core.internal.conversation.ConversationDeletionPolicy;
import com.vega.kmp.agent.core.internal.conversation.ConversationSortKey;
import com.vega.kmp.agent.core.internal.conversation.ProductCover;
import com.vega.kmp.agent.core.internal.conversation.ProductResult;
import com.vega.kmp.agent.core.internal.conversation.SubConversationConfig;
import com.vega.kmp.agent.core.message.AgentMessage;
import com.vega.kmp.agent.core.message.Asset;
import com.vega.kmp.agent.core.message.QuoteInfo;
import com.vega.kmp.agent.core.message.UserMessage;
import com.vega.kmp.agent.core.protocol.AgentSystemEventHandler;
import com.vega.kmp.agent.core.protocol.impl.conversation.ConversationProtocolConfig;
import com.vega.kmp.agent.core.protocol.impl.conversation.DefaultConversationProtocol;
import com.vega.kmp.agent.core.protocol.impl.message.AgentProtocolConfig;
import com.vega.kmp.agent.core.protocol.impl.message.DefaultMessagingProtocolFactory;
import com.vega.kmp.agent.core.protocol.impl.message.SendMessageRetryConfig;
import com.vega.kmp.agent.core.protocol.impl.message.SseWatchdogConfig;
import com.vega.kmp.agent.core.util.Extras;
import com.vega.kmp.agent.core.util.platform.DefaultSseTransport;
import com.vega.report.params.ReportParams;
import com.vega.videoagentapi.common.settings.AgentCommonConfig;
import com.vega.videoagentapi.common.settings.IVideoAgentCommonSettings;
import com.vega.videoagentapi.common.settings.SseWatchdogSettingsConfig;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Set;
import kotlin.Lazy;
import kotlin.LazyKt__LazyJVMKt;
import kotlin.Pair;
import kotlin.Result;
import kotlin.ResultKt;
import kotlin.TuplesKt;
import kotlin.collections.CollectionsKt;
import kotlin.collections.CollectionsKt__CollectionsKt;
import kotlin.collections.MapsKt__MapsKt;
import kotlin.jvm.functions.Function0;
import kotlin.jvm.functions.Function1;
import kotlin.jvm.functions.Function2;
import kotlin.jvm.internal.DefaultConstructorMarker;
import kotlin.jvm.internal.Intrinsics;
import kotlin.jvm.internal.Reflection;
import kotlin.text.StringsKt__StringsKt;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

/* JADX INFO: loaded from: D:\Decompiler\App\Video\Capcut\extracted\classes17.dex */
public class AiLabAgentConversationConfig implements ConversationConfig {
    public final Lazy a = LazyKt__LazyJVMKt.lazy(new Function0<String>() { // from class: com.vega.ailabagent.unifyagent.AiLabAgentConversationConfig$baseUrl$2
        public final Object invoke() {
            return "https://" + ContextExtKt.hostEnv().developSettings().host().a;
        }
    });
    public final String b = "ailab_agent_v1.1";
    public final List<AgentSystemEventHandler> c = CollectionsKt__CollectionsKt.listOf(new AgentSystemEventHandler[]{CreditBalanceChangedSystemEventHandler.a, CreditRoundSummarySystemEventHandler.a, ConversationInfoUpdatedSystemEventHandler.a});
    public final int d = ConfigSettingsKt.a(Reflection.getOrCreateKotlinClass(AiLabAgentConfigSettings.class)).b();
    public final AgentCommonConfig e;
    public final DefaultMessagingProtocolFactory f;
    public final DefaultConversationProtocol g;
    public final AiLabMessageExtras h;
    public final AiLabProtocolOptionModifier i;
    public final AiLabAgentConversationConfig$toolCallConfig$1 j;
    public final LoginService k;
    public long l;

    public static final class Companion {
    }

    @Override // com.vega.kmp.agent.core.internal.conversation.ConversationConfig
    public final void c() {
    }

    @Override // com.vega.kmp.agent.core.internal.conversation.ConversationConfig
    public final void v() {
    }

    @Override // com.vega.kmp.agent.core.internal.conversation.ConversationConfig
    public String getScene() {
        return this.b;
    }

    @Override // com.vega.kmp.agent.core.internal.conversation.ConversationConfig
    public final AiLabMessageExtras m() {
        return this.h;
    }

    @Override // com.vega.kmp.agent.core.internal.conversation.ConversationConfig
    public final DefaultMessagingProtocolFactory o() {
        return this.f;
    }

    @Override // com.vega.kmp.agent.core.internal.conversation.ConversationConfig
    public final List<AgentSystemEventHandler> r() {
        return this.c;
    }

    @Override // com.vega.kmp.agent.core.internal.conversation.ConversationConfig
    public final DefaultConversationProtocol s() {
        return this.g;
    }

    @Override // com.vega.kmp.agent.core.internal.conversation.ConversationConfig
    public final AiLabProtocolOptionModifier t() {
        return this.i;
    }

    @Override // com.vega.kmp.agent.core.internal.conversation.ConversationConfig
    public final AiLabAgentConversationConfig$toolCallConfig$1 u() {
        return this.j;
    }

    static {
        new Companion();
    }

    @Override // com.vega.kmp.agent.core.internal.conversation.ConversationConfig
    public final boolean f() {
        return this.e.d();
    }

    @Override // com.vega.kmp.agent.core.internal.conversation.ConversationConfig
    public final List<SubConversationConfig> h() {
        return CollectionsKt__CollectionsKt.emptyList();
    }

    @Override // com.vega.kmp.agent.core.internal.conversation.ConversationConfig
    public final boolean d() {
        AiLabHistoryPageOptimizeSettings.Companion.getClass();
        return AiLabHistoryPageOptimizeSettings.Companion.a();
    }

    public final String y() {
        return (String) this.a.getValue();
    }

    @Override // com.vega.kmp.agent.core.internal.conversation.ConversationConfig
    public final ConversationSortKey a() {
        AiLabHistoryPageOptimizeSettings.Companion.getClass();
        if (AiLabHistoryPageOptimizeSettings.Companion.a()) {
            return ConversationSortKey.LastUpdateTime;
        }
        return ConversationSortKey.CreateTime;
    }

    @Override // com.vega.kmp.agent.core.internal.conversation.ConversationConfig
    public String g() {
        String strA = ConfigSettingsKt.a(Reflection.getOrCreateKotlinClass(AiLabAgentConfigSettings.class)).a();
        if (!(!StringsKt__StringsKt.isBlank(strA)) || strA == null) {
            return "ai_lab_v2";
        }
        return strA;
    }

    @Override // com.vega.kmp.agent.core.internal.conversation.ConversationConfig
    public final boolean n() {
        return ConfigSettingsKt.a(Reflection.getOrCreateKotlinClass(AiLabAgentReadSyncConfigSettings.class)).a();
    }

    @Override // com.vega.kmp.agent.core.internal.conversation.ConversationConfig
    public final ConversationDeletionPolicy p() {
        AiLabHistoryPageOptimizeSettings.Companion.getClass();
        if (AiLabHistoryPageOptimizeSettings.Companion.a()) {
            return ConversationDeletionPolicy.b;
        }
        return ConversationDeletionPolicy.a;
    }

    @Override // com.vega.kmp.agent.core.internal.conversation.ConversationConfig
    public final boolean q() {
        AiLabHistoryRedDotSettings.Companion.getClass();
        return ConfigSettingsKt.a(Reflection.getOrCreateKotlinClass(AiLabHistoryRedDotSettings.class)).b();
    }

    public AiLabAgentConversationConfig() {
        AiLabHostSseTransport aiLabHostSseTransport;
        long jLongValue;
        AiLabAgentMessageRetryConfig aiLabAgentMessageRetryConfigA = ConfigSettingsKt.a(Reflection.getOrCreateKotlinClass(AiLabAgentMessageRetrySettings.class));
        AgentCommonConfig agentCommonConfigVideoAgentCommonConfig = ((IVideoAgentCommonSettings) SettingsManager.obtain(IVideoAgentCommonSettings.class)).videoAgentCommonConfig();
        this.e = agentCommonConfigVideoAgentCommonConfig;
        SseWatchdogSettingsConfig sseWatchdogSettingsConfigE = agentCommonConfigVideoAgentCommonConfig.e();
        SseRecoverSettingsConfig sseRecoverSettingsConfigA = ConfigSettingsKt.a(Reflection.getOrCreateKotlinClass(AiLabAgentSseRecoverConfigSettings.class));
        SendMessageRetryConfig sendMessageRetryConfig = new SendMessageRetryConfig(aiLabAgentMessageRetryConfigA.e(), aiLabAgentMessageRetryConfigA.b(), aiLabAgentMessageRetryConfigA.c(), aiLabAgentMessageRetryConfigA.d());
        AiLabHostSseSettings.Companion.getClass();
        if (ConfigSettingsKt.a(Reflection.getOrCreateKotlinClass(AiLabHostSseSettings.class)).a()) {
            aiLabHostSseTransport = new AiLabHostSseTransport();
        } else {
            aiLabHostSseTransport = DefaultSseTransport.a;
        }
        String str = y() + "/storyboard_agent/v1/ai_lab/get_conversation_details";
        String str2 = y() + "/storyboard_agent/v1/ai_lab/update_message_option";
        boolean zC = sseWatchdogSettingsConfigE.c();
        long jB = sseWatchdogSettingsConfigE.b();
        long jD = sseWatchdogSettingsConfigE.d();
        long jA = sseWatchdogSettingsConfigE.a();
        boolean zB = sseRecoverSettingsConfigA.b();
        Long lValueOf = Long.valueOf(sseRecoverSettingsConfigA.c());
        if (lValueOf.longValue() > 0) {
            jLongValue = lValueOf.longValue();
        } else {
            jLongValue = 60000;
        }
        this.f = new DefaultMessagingProtocolFactory(new AgentProtocolConfig(sendMessageRetryConfig, new Function2<Conversation, Long, String>() { // from class: com.vega.ailabagent.unifyagent.AiLabAgentConversationConfig$messagingProtocolFactory$2
            {
                super(2);
            }

            public final Object invoke(Object obj, Object obj2) throws JSONException {
                Conversation conversation = (Conversation) obj;
                long jLongValue2 = ((Number) obj2).longValue();
                Intrinsics.checkNotNullParameter(conversation, "");
                JSONObject jSONObject = new JSONObject();
                jSONObject.put("agent_scene", this.e.g());
                jSONObject.put("session_id", conversation.c);
                if (jLongValue2 > 0) {
                    jSONObject.put("event_id", String.valueOf(jLongValue2));
                } else {
                    jSONObject.put("event_id", "");
                }
                String string = jSONObject.toString();
                Intrinsics.checkNotNullExpressionValue(string, "");
                return string;
            }
        }, str, new Function2<Conversation, Integer, String>() { // from class: com.vega.ailabagent.unifyagent.AiLabAgentConversationConfig$messagingProtocolFactory$3
            {
                super(2);
            }

            public final Object invoke(Object obj, Object obj2) throws JSONException {
                Conversation conversation = (Conversation) obj;
                int iIntValue = ((Number) obj2).intValue();
                Intrinsics.checkNotNullParameter(conversation, "");
                JSONObject jSONObject = new JSONObject();
                AiLabAgentConversationConfig aiLabAgentConversationConfig = this.e;
                jSONObject.put("agent_scene", aiLabAgentConversationConfig.g());
                jSONObject.put("conversation_id", conversation.c);
                jSONObject.put("offset", iIntValue);
                jSONObject.put("limit", aiLabAgentConversationConfig.d);
                String string = jSONObject.toString();
                Intrinsics.checkNotNullExpressionValue(string, "");
                return string;
            }
        }, str2, new SseWatchdogConfig(zC, jB, jD, jA, zB, jLongValue), aiLabHostSseTransport));
        this.g = new DefaultConversationProtocol(new ConversationProtocolConfig(y() + "/storyboard_agent/v1/ai_lab/get_conversations", new Function2<Integer, Integer, String>() { // from class: com.vega.ailabagent.unifyagent.AiLabAgentConversationConfig$conversationProtocol$1
            {
                super(2);
            }

            public final Object invoke(Object obj, Object obj2) throws JSONException {
                int iIntValue = ((Number) obj).intValue();
                int iIntValue2 = ((Number) obj2).intValue();
                JSONObject jSONObject = new JSONObject();
                jSONObject.put("agent_scene", this.e.g());
                jSONObject.put("offset", iIntValue);
                jSONObject.put("limit", iIntValue2);
                Intrinsics.checkNotNullParameter(ConversationSortKey.CreateTime, "");
                jSONObject.put("sort_by", "create_time");
                String string = jSONObject.toString();
                Intrinsics.checkNotNullExpressionValue(string, "");
                return string;
            }
        }, y() + "/storyboard_agent/v1/ai_lab/delete_conversation", new Function1<List<? extends Conversation>, String>() { // from class: com.vega.ailabagent.unifyagent.AiLabAgentConversationConfig$conversationProtocol$2
            {
                super(1);
            }

            public final Object invoke(Object obj) throws JSONException {
                List list = (List) obj;
                Intrinsics.checkNotNullParameter(list, "");
                JSONObject jSONObject = new JSONObject();
                jSONObject.put("agent_scene", this.e.g());
                JSONArray jSONArray = new JSONArray();
                Iterator it = list.iterator();
                while (it.hasNext()) {
                    jSONArray.put(((Conversation) it.next()).c);
                }
                jSONObject.put("conversation_ids", jSONArray);
                String string = jSONObject.toString();
                Intrinsics.checkNotNullExpressionValue(string, "");
                return string;
            }
        }, y() + "/storyboard_agent/v1/ai_lab/update_last_read", new Function2<Conversation, AgentMessage, String>() { // from class: com.vega.ailabagent.unifyagent.AiLabAgentConversationConfig$conversationProtocol$3
            {
                super(2);
            }

            public final Object invoke(Object obj, Object obj2) {
                Conversation conversation = (Conversation) obj;
                AgentMessage agentMessage = (AgentMessage) obj2;
                Intrinsics.checkNotNullParameter(conversation, "");
                Intrinsics.checkNotNullParameter(agentMessage, "");
                return this.e.x(conversation, agentMessage.b);
            }
        }, new Function2<Conversation, String, String>() { // from class: com.vega.ailabagent.unifyagent.AiLabAgentConversationConfig$conversationProtocol$4
            {
                super(2);
            }

            public final Object invoke(Object obj, Object obj2) {
                Conversation conversation = (Conversation) obj;
                String str3 = (String) obj2;
                Intrinsics.checkNotNullParameter(conversation, "");
                Intrinsics.checkNotNullParameter(str3, "");
                return this.e.x(conversation, str3);
            }
        }, y() + "/storyboard_agent/v1/ai_lab/rename_conversation", new Function2<Conversation, String, String>() { // from class: com.vega.ailabagent.unifyagent.AiLabAgentConversationConfig$conversationProtocol$5
            {
                super(2);
            }

            public final Object invoke(Object obj, Object obj2) throws JSONException {
                Conversation conversation = (Conversation) obj;
                Intrinsics.checkNotNullParameter(conversation, "");
                Intrinsics.checkNotNullParameter(obj2, "");
                JSONObject jSONObject = new JSONObject();
                jSONObject.put("agent_scene", this.e.g());
                jSONObject.put("conversation_id", conversation.c);
                jSONObject.put("title", obj2);
                String string = jSONObject.toString();
                Intrinsics.checkNotNullExpressionValue(string, "");
                return string;
            }
        }));
        this.h = new AiLabMessageExtras();
        this.i = new AiLabProtocolOptionModifier();
        this.j = new AiLabAgentConversationConfig$toolCallConfig$1();
        this.k = (LoginService) SPIService.INSTANCE.getImpl(Reflection.getOrCreateKotlinClass(LoginService.class), (String) null);
        this.l = -1L;
    }

    @Override // com.vega.kmp.agent.core.internal.conversation.ConversationConfig
    public final String l(UserMessage userMessage) {
        NormalMessage normalMessage;
        String text;
        String strI = "";
        Intrinsics.checkNotNullParameter(userMessage, "");
        if (Intrinsics.areEqual(userMessage.g, "main_text")) {
            ChatMessageContentParser chatMessageContentParser = ChatMessageContentParser.a;
            String str = userMessage.g;
            String str2 = userMessage.h;
            chatMessageContentParser.getClass();
            Object objA = ChatMessageContentParser.a(str, str2);
            if (objA instanceof NormalMessage) {
                normalMessage = (NormalMessage) objA;
            } else {
                normalMessage = null;
            }
            CommonTagManager commonTagManager = CommonTagManager.a;
            if (normalMessage != null && (text = normalMessage.getText()) != null) {
                strI = text;
            }
            strI = CommonTagManager.i(commonTagManager, strI);
        }
        if (strI.length() == 0) {
            return z(userMessage);
        }
        return strI;
    }

    @Override // com.vega.kmp.agent.core.internal.conversation.ConversationConfig
    public final boolean i(String str) {
        Intrinsics.checkNotNullParameter(str, "");
        AiLabProductToolSettings.Companion.getClass();
        Set<String> set = (Set) AiLabProductToolSettings.Companion.b.getValue();
        if ((set instanceof Collection) && set.isEmpty()) {
            return false;
        }
        for (String str2 : set) {
            if (!Intrinsics.areEqual(str, str2)) {
                if (!4cM.s(str, "_" + str2)) {
                    if (4cM.s(str, "/" + str2)) {
                    }
                }
            }
            return true;
        }
        return false;
    }

    public static String z(UserMessage userMessage) {
        int i;
        List<Asset> list = userMessage.t;
        if (list.isEmpty()) {
            return "";
        }
        Iterator<T> it = list.iterator();
        int i2 = 0;
        while (it.hasNext()) {
            i2 += Intrinsics.areEqual(((Asset) it.next()).a, "image") ? 1 : 0;
        }
        Iterator<T> it2 = list.iterator();
        int i3 = 0;
        while (it2.hasNext()) {
            i3 += Intrinsics.areEqual(((Asset) it2.next()).a, "video") ? 1 : 0;
        }
        if ((list instanceof Collection) && list.isEmpty()) {
            i = 0;
        } else {
            i = 0;
            for (Asset asset : list) {
                if (!Intrinsics.areEqual(asset.a, "image") && !Intrinsics.areEqual(asset.a, "video") && (i = i + 1) < 0) {
                    CollectionsKt__CollectionsKt.throwCountOverflow();
                }
            }
        }
        ArrayList arrayList = new ArrayList();
        if (i3 > 0) {
            arrayList.add(FunctionsKt.a(2131755044, i3, new Object[]{Integer.valueOf(i3)}));
        }
        if (i2 > 0) {
            arrayList.add(FunctionsKt.a(2131755043, i2, new Object[]{Integer.valueOf(i2)}));
        }
        if (i > 0) {
            arrayList.add(FunctionsKt.a(2131755011, i, new Object[]{Integer.valueOf(i)}));
        }
        return CollectionsKt.j(arrayList, "\n", (CharSequence) null, (CharSequence) null, 0, (Function1) null, 62);
    }

    /* JADX WARN: Code duplicated, block: B:25:0x0051  */
    /* JADX WARN: Code duplicated, block: B:27:0x005a  */
    /* JADX WARN: Code duplicated, block: B:29:0x0063 A[EDGE_INSN: B:29:0x0063->B:30:0x0065 BREAK  A[LOOP:1: B:66:0x00fd->B:84:?]] */
    /* JADX WARN: Code duplicated, block: B:57:0x00d9  */
    /* JADX WARN: Code duplicated, block: B:60:0x00e3  */
    /* JADX WARN: Code duplicated, block: B:65:0x00f9  */
    /* JADX WARN: Code duplicated, block: B:68:0x0103  */
    /* JADX WARN: Code duplicated, block: B:82:0x0063 A[SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:83:0x0112 A[SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:84:? A[LOOP:1: B:66:0x00fd->B:84:?, LOOP_END, SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:85:0x00f5 A[SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:86:0x00f1 A[SYNTHETIC] */
    /* JADX WARN: Code duplicated, block: B:87:? A[LOOP:2: B:58:0x00dd->B:87:?, LOOP_END, SYNTHETIC] */
    @Override // com.vega.kmp.agent.core.internal.conversation.ConversationConfig
    public final ProductResult w(String str) {
        boolean z;
        Object objCreateFailure;
        List listC;
        String str2;
        Iterator it;
        Iterator it2;
        Object next;
        Intrinsics.checkNotNullParameter(str, "");
        if (str.length() == 0) {
            z = true;
        } else {
            z = false;
        }
        ProductCover productCover = null;
        if (z) {
            return null;
        }
        try {
            AgentGsonProvider.a.getClass();
            objCreateFailure = (MediaListModel) AgentGsonProvider.a(str, MediaListModel.class);
            Result.constructor-impl(objCreateFailure);
        } catch (Throwable th) {
            objCreateFailure = ResultKt.createFailure(th);
            Result.constructor-impl(objCreateFailure);
        }
        if (Result.isFailure-impl(objCreateFailure)) {
            objCreateFailure = null;
        }
        MediaListModel mediaListModel = (MediaListModel) objCreateFailure;
        if (mediaListModel == null || (listC = mediaListModel.c()) == null || !(!listC.isEmpty())) {
            return null;
        }
        boolean z2 = listC instanceof Collection;
        if (z2 && listC.isEmpty()) {
            if (listC.isEmpty()) {
                if (listC.isEmpty()) {
                    str2 = "failed";
                    break;
                }
                it2 = listC.iterator();
                while (true) {
                    if (it2.hasNext()) {
                        str2 = "failed";
                        break;
                    }
                    if (((MessageMediaItem) it2.next()).getGenStatus() == MediaGenStatus.FAILED) {
                        str2 = "succeed";
                        break;
                    }
                }
            } else {
                it = listC.iterator();
                while (true) {
                    if (it.hasNext()) {
                        if (((MessageMediaItem) it.next()).getGenStatus() == MediaGenStatus.INTERRUPTED) {
                            str2 = "interrupted";
                        }
                    } else if (z2) {
                        if (listC.isEmpty()) {
                            str2 = "failed";
                            break;
                        }
                        it2 = listC.iterator();
                        while (true) {
                            if (it2.hasNext()) {
                                str2 = "failed";
                                break;
                            }
                            if (((MessageMediaItem) it2.next()).getGenStatus() == MediaGenStatus.FAILED) {
                                str2 = "succeed";
                                break;
                            }
                        }
                    } else {
                        it2 = listC.iterator();
                        while (true) {
                            if (it2.hasNext()) {
                                str2 = "failed";
                                break;
                            }
                            if (((MessageMediaItem) it2.next()).getGenStatus() == MediaGenStatus.FAILED) {
                                str2 = "succeed";
                                break;
                            }
                        }
                    }
                }
            }
        } else {
            Iterator it3 = listC.iterator();
            while (true) {
                if (it3.hasNext()) {
                    if (((MessageMediaItem) it3.next()).getGenStatus() == MediaGenStatus.PROGRESS) {
                        str2 = "progress";
                    }
                } else if (z2) {
                    if (listC.isEmpty()) {
                        if (listC.isEmpty()) {
                            str2 = "failed";
                            break;
                        }
                        it2 = listC.iterator();
                        while (true) {
                            if (it2.hasNext()) {
                                str2 = "failed";
                                break;
                            }
                            if (((MessageMediaItem) it2.next()).getGenStatus() == MediaGenStatus.FAILED) {
                                str2 = "succeed";
                                break;
                            }
                        }
                    } else {
                        it = listC.iterator();
                        while (true) {
                            if (it.hasNext()) {
                                if (((MessageMediaItem) it.next()).getGenStatus() == MediaGenStatus.INTERRUPTED) {
                                    str2 = "interrupted";
                                }
                            } else if (z2) {
                                if (listC.isEmpty()) {
                                    str2 = "failed";
                                    break;
                                }
                                it2 = listC.iterator();
                                while (true) {
                                    if (it2.hasNext()) {
                                        str2 = "failed";
                                        break;
                                    }
                                    if (((MessageMediaItem) it2.next()).getGenStatus() == MediaGenStatus.FAILED) {
                                        str2 = "succeed";
                                        break;
                                    }
                                }
                            } else {
                                it2 = listC.iterator();
                                while (true) {
                                    if (it2.hasNext()) {
                                        str2 = "failed";
                                        break;
                                    }
                                    if (((MessageMediaItem) it2.next()).getGenStatus() == MediaGenStatus.FAILED) {
                                        str2 = "succeed";
                                        break;
                                    }
                                }
                            }
                        }
                    }
                } else {
                    it = listC.iterator();
                    while (true) {
                        if (it.hasNext()) {
                            if (((MessageMediaItem) it.next()).getGenStatus() == MediaGenStatus.INTERRUPTED) {
                                str2 = "interrupted";
                            }
                        } else if (z2) {
                            if (listC.isEmpty()) {
                                str2 = "failed";
                                break;
                            }
                            it2 = listC.iterator();
                            while (true) {
                                if (it2.hasNext()) {
                                    str2 = "failed";
                                    break;
                                }
                                if (((MessageMediaItem) it2.next()).getGenStatus() == MediaGenStatus.FAILED) {
                                    str2 = "succeed";
                                    break;
                                }
                            }
                        } else {
                            it2 = listC.iterator();
                            while (true) {
                                if (it2.hasNext()) {
                                    str2 = "failed";
                                    break;
                                }
                                if (((MessageMediaItem) it2.next()).getGenStatus() == MediaGenStatus.FAILED) {
                                    str2 = "succeed";
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        Iterator it4 = listC.iterator();
        while (true) {
            if (it4.hasNext()) {
                next = it4.next();
                MessageMediaItem messageMediaItem = (MessageMediaItem) next;
                if (messageMediaItem.getGenStatus() == MediaGenStatus.SUCCEED && (messageMediaItem.getCoverUrl().length() > 0 || messageMediaItem.getUrl().length() > 0)) {
                    break;
                }
            } else {
                next = null;
                break;
            }
        }
        MessageMediaItem messageMediaItem2 = (MessageMediaItem) next;
        if (messageMediaItem2 != null) {
            String coverUrl = messageMediaItem2.getCoverUrl();
            if (coverUrl.length() == 0) {
                coverUrl = messageMediaItem2.getUrl();
            }
            productCover = new ProductCover(coverUrl, (int) (messageMediaItem2.getDuration() / 1000));
        }
        return new ProductResult(str2, productCover);
    }

    @Override // com.vega.kmp.agent.core.internal.conversation.ConversationConfig
    public final boolean k(String str, String str2) {
        Intrinsics.checkNotNullParameter(str, "");
        Intrinsics.checkNotNullParameter(str2, "");
        if (i(str)) {
            AiLabProductToolSettings.Companion.getClass();
            if (((Set) AiLabProductToolSettings.Companion.c.getValue()).contains(str2)) {
                return true;
            }
        }
        return false;
    }

    public final String x(Conversation conversation, String str) throws JSONException {
        JSONObject jSONObject = new JSONObject();
        jSONObject.put("agent_scene", g());
        jSONObject.put("conversation_id", conversation.c);
        jSONObject.put("last_read_message_id", str);
        String string = jSONObject.toString();
        Intrinsics.checkNotNullExpressionValue(string, "");
        return string;
    }

    @Override // com.vega.kmp.agent.core.internal.conversation.ConversationConfig
    public final String e(AgentMessage agentMessage, String str) {
        NormalMessage normalMessage;
        String text;
        String strI = "";
        Intrinsics.checkNotNullParameter(str, "");
        Intrinsics.checkNotNullParameter(agentMessage, "");
        if (str.length() > 0) {
            return str;
        }
        if (agentMessage instanceof UserMessage) {
            if (Intrinsics.areEqual(agentMessage.g, "main_text")) {
                ChatMessageContentParser chatMessageContentParser = ChatMessageContentParser.a;
                String str2 = agentMessage.g;
                String str3 = agentMessage.h;
                chatMessageContentParser.getClass();
                Object objA = ChatMessageContentParser.a(str2, str3);
                if ((objA instanceof NormalMessage) && (normalMessage = (NormalMessage) objA) != null && (text = normalMessage.getText()) != null) {
                    strI = text;
                }
                strI = CommonTagManager.i(CommonTagManager.a, strI);
            }
            if (strI.length() == 0) {
                return z((UserMessage) agentMessage);
            }
        }
        return strI;
    }

    @Override // com.vega.kmp.agent.core.internal.conversation.ConversationConfig
    public final void j(Conversation conversation, AgentMessage agentMessage) {
        boolean z;
        BabiParams babiParams;
        UserMessage userMessage;
        List<QuoteInfo> list;
        Intrinsics.checkNotNullParameter(conversation, "");
        Intrinsics.checkNotNullParameter(agentMessage, "");
        String strB = Extras.b(conversation.x, "first_message_enter_from");
        if (strB.length() > 0) {
            z = true;
        } else {
            z = false;
        }
        if (z) {
            AiLabProtocolOptionModifier aiLabProtocolOptionModifier = this.i;
            aiLabProtocolOptionModifier.getClass();
            aiLabProtocolOptionModifier.a(agentMessage, "enter_from", strB);
            conversation.x.c(new AiLabAgentConversationAbilityKt$firstMessageEnterFrom$1(""), true);
        } else {
            AiLabProtocolOptionModifier aiLabProtocolOptionModifier2 = this.i;
            String strB2 = Extras.b(conversation.x, "enter_from");
            aiLabProtocolOptionModifier2.getClass();
            Intrinsics.checkNotNullParameter(strB2, "");
            aiLabProtocolOptionModifier2.a(agentMessage, "enter_from", strB2);
        }
        AiLabProtocolOptionModifier aiLabProtocolOptionModifier3 = this.i;
        aiLabProtocolOptionModifier3.getClass();
        boolean zAreEqual = Intrinsics.areEqual(conversation.e().getScene(), "trends_agent_v1.1");
        String strB3 = Extras.b(conversation.x, "source_template_id");
        Map mapMapOf = MapsKt__MapsKt.mapOf(new Pair[]{TuplesKt.to("chat_session_id", conversation.c), TuplesKt.to("round_id", agentMessage.c)});
        if (zAreEqual) {
            if (strB3.length() > 0) {
                Map mapPlus = MapsKt__MapsKt.plus(mapMapOf, TuplesKt.to("template_id", strB3));
                ReportParams.c.getClass();
                babiParams = new BabiParams("template_solution", "ai_trends_v1.1", "tool", "edit-ai_generator-template", mapPlus, "ai_agent", "conversation", ReportParams.Companion.a().a, "ailab_agent", "ai_trends", strB3, "ailab_agent", (String) null, (String) null, 12288, (DefaultConstructorMarker) null);
            } else {
                ReportParams.c.getClass();
                babiParams = new BabiParams("video_intelliedit", "ai_trends_v1.1", "tool", "edit-ai_generator-tool", mapMapOf, "ai_agent", "conversation", ReportParams.Companion.a().a, "ailab_agent", "ai_trends", (String) null, "ailab_agent", (String) null, (String) null, 12288, (DefaultConstructorMarker) null);
            }
        } else if (strB3.length() > 0) {
            Map mapPlus2 = MapsKt__MapsKt.plus(mapMapOf, TuplesKt.to("template_id", strB3));
            ReportParams.c.getClass();
            babiParams = new BabiParams("template_solution", "ailab_agent_v1.1", "AIlab", "ai_lab-ai_agent_template", mapPlus2, "ai_agent", "conversation", ReportParams.Companion.a().a, "ailab_agent", "ai_lab", strB3, "ailab_agent", (String) null, (String) null, 12288, (DefaultConstructorMarker) null);
        } else {
            ReportParams.c.getClass();
            babiParams = new BabiParams("video_intelliedit", "ailab_agent_v1.1", "AIlab", "ai_lab-ailab_agent", mapMapOf, "ai_agent", "conversation", ReportParams.Companion.a().a, "ailab_agent", "ai_lab", (String) null, "ailab_agent", (String) null, (String) null, 12288, (DefaultConstructorMarker) null);
        }
        aiLabProtocolOptionModifier3.a(agentMessage, "babi", ExtentionKt.toJson(babiParams));
        AiLabProtocolOptionModifier aiLabProtocolOptionModifier4 = this.i;
        AiLabHistoryPageOptimizeSettings.Companion.getClass();
        boolean zA = AiLabHistoryPageOptimizeSettings.Companion.a();
        aiLabProtocolOptionModifier4.getClass();
        aiLabProtocolOptionModifier4.a(agentMessage, "generate_smart_title", String.valueOf(zA));
        if ((agentMessage instanceof UserMessage) && (userMessage = (UserMessage) agentMessage) != null && (list = userMessage.u) != null) {
            for (Object obj : list) {
                if (Intrinsics.areEqual(((QuoteInfo) obj).a, "trends_template")) {
                    if (obj != null) {
                        AiLabProtocolOptionModifier aiLabProtocolOptionModifier5 = this.i;
                        aiLabProtocolOptionModifier5.getClass();
                        aiLabProtocolOptionModifier5.a(agentMessage, "shortcut_id", "ailab_trend_template");
                        return;
                    }
                    return;
                }
            }
        }
    }
}
