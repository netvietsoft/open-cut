package com.vega.kmp.agent.core;

import com.vega.kmp.agent.core.internal.conversation.ConversationConfig;
import com.vega.kmp.agent.core.internal.conversation.SubConversationConfig;
import com.vega.kmp.agent.core.internal.fileupload.FileUploadConfig;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import kotlin.collections.CollectionsKt___CollectionsKt;
import kotlin.jvm.internal.Intrinsics;

/* JADX INFO: loaded from: D:\Decompiler\App\Video\Capcut\extracted\classes17.dex */
public final class AgentConfigs {
    public static final AgentConfigs a = new AgentConfigs();
    public static final Map<String, ConversationConfig> b;
    public static final Map<String, SubConversationConfig> c;
    public static final Map<String, FileUploadConfig> d;
    public static final List<String> e;

    static {
        LinkedHashMap linkedHashMap = new LinkedHashMap();
        b = linkedHashMap;
        c = new LinkedHashMap();
        d = new LinkedHashMap();
        e = CollectionsKt___CollectionsKt.toList(linkedHashMap.keySet());
    }

    public static ConversationConfig a(String str) {
        Intrinsics.checkNotNullParameter(str, "");
        ConversationConfig conversationConfig = (ConversationConfig) ((LinkedHashMap) b).get(str);
        if (conversationConfig != null) {
            return conversationConfig;
        }
        throw new IllegalStateException("AgentConfigs has not been initialized with scene [" + str + ']');
    }
}
