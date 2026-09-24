package com.vega.kmp.agent.core.internal.conversation;

import com.vega.ailabagent.unifyagent.AiLabAgentConversationConfig$toolCallConfig$1;
import com.vega.ailabagent.unifyagent.AiLabProtocolOptionModifier;
import com.vega.ailabagent.unifyagent.data.AiLabMessageExtras;
import com.vega.kmp.agent.core.Conversation;
import com.vega.kmp.agent.core.message.AgentMessage;
import com.vega.kmp.agent.core.message.UserMessage;
import com.vega.kmp.agent.core.protocol.AgentSystemEventHandler;
import com.vega.kmp.agent.core.protocol.impl.conversation.DefaultConversationProtocol;
import com.vega.kmp.agent.core.protocol.impl.message.DefaultMessagingProtocolFactory;
import java.util.List;

/* JADX INFO: loaded from: D:\Decompiler\App\Video\Capcut\extracted\classes17.dex */
public interface ConversationConfig {

    public static final class DefaultImpls {
    }

    ConversationSortKey a();

    void c();

    boolean d();

    String e(AgentMessage agentMessage, String str);

    boolean f();

    String g();

    String getScene();

    List<SubConversationConfig> h();

    boolean i(String str);

    void j(Conversation conversation, AgentMessage agentMessage);

    boolean k(String str, String str2);

    String l(UserMessage userMessage);

    AiLabMessageExtras m();

    boolean n();

    DefaultMessagingProtocolFactory o();

    ConversationDeletionPolicy p();

    boolean q();

    List<AgentSystemEventHandler> r();

    DefaultConversationProtocol s();

    AiLabProtocolOptionModifier t();

    AiLabAgentConversationConfig$toolCallConfig$1 u();

    void v();

    ProductResult w(String str);
}
