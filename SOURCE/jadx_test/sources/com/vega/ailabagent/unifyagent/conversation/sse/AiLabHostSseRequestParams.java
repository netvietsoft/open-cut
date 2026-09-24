package com.vega.ailabagent.unifyagent.conversation.sse;

import java.util.LinkedHashMap;
import java.util.Map;
import kotlin.jvm.internal.Intrinsics;
import org.json.JSONObject;

/* JADX INFO: loaded from: D:\Decompiler\App\Video\Capcut\extracted\classes20.dex */
public final class AiLabHostSseRequestParams {
    public final boolean a;
    public final long b;
    public final Map<String, String> c;
    public final JSONObject d;
    public final Map<String, String> e;

    public AiLabHostSseRequestParams() {
        this(null, null, null, 31);
    }

    public AiLabHostSseRequestParams(Map map, JSONObject jSONObject, Map map2, int i) {
        boolean z;
        long j;
        if ((i & 1) != 0) {
            z = true;
        } else {
            z = false;
        }
        if ((i & 2) != 0) {
            j = -1;
        } else {
            j = 0;
        }
        map = (i & 4) != 0 ? new LinkedHashMap() : map;
        jSONObject = (i & 8) != 0 ? new JSONObject() : jSONObject;
        map2 = (i & 16) != 0 ? new LinkedHashMap() : map2;
        Intrinsics.checkNotNullParameter(map, "");
        Intrinsics.checkNotNullParameter(jSONObject, "");
        Intrinsics.checkNotNullParameter(map2, "");
        this.a = z;
        this.b = j;
        this.c = map;
        this.d = jSONObject;
        this.e = map2;
    }
}
