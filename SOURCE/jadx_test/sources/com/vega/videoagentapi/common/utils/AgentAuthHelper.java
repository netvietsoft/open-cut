package com.vega.videoagentapi.common.utils;

import androidx.fragment.app.FragmentActivity;
import com.vega.kv.KvStorageKt;
import com.vega.videoagentapi.VideoAgentConstant;
import kotlin.jvm.internal.MutablePropertyReference1Impl;
import kotlin.jvm.internal.Reflection;
import kotlin.properties.ReadWriteProperty;
import kotlin.reflect.KProperty;

/* JADX INFO: loaded from: D:\Decompiler\App\Video\Capcut\extracted\classes17.dex */
public final class AgentAuthHelper {
    public static final /* synthetic */ KProperty<Object>[] b;
    public final ReadWriteProperty a;

    static {
        MutablePropertyReference1Impl mutablePropertyReference1Impl = new MutablePropertyReference1Impl(AgentAuthHelper.class, "cutSameUnifiedPrivacyAuthorization", "getCutSameUnifiedPrivacyAuthorization()Z", 0);
        Reflection.mutableProperty1(mutablePropertyReference1Impl);
        b = new KProperty[]{mutablePropertyReference1Impl};
    }

    public AgentAuthHelper(FragmentActivity fragmentActivity) {
        VideoAgentConstant.a.getClass();
        this.a = KvStorageKt.e(VideoAgentConstant.a(), "is_show_ai_agent_auth_dialog", Boolean.FALSE, false);
    }
}
