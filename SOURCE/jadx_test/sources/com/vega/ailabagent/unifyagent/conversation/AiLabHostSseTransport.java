package com.vega.ailabagent.unifyagent.conversation;

import X.4d1;
import android.util.Pair;
import com.bytedance.frameworks.baselib.network.http.BaseRequestContext;
import com.bytedance.frameworks.baselib.network.http.util.UrlUtils;
import com.bytedance.retrofit2.Call;
import com.bytedance.retrofit2.ExpandCallback;
import com.bytedance.retrofit2.RequestBuilder;
import com.bytedance.retrofit2.SsResponse;
import com.bytedance.retrofit2.client.Header;
import com.bytedance.retrofit2.mime.TypedByteArray;
import com.bytedance.retrofit2.mime.TypedInput;
import com.bytedance.services.apm.api.EnsureManager;
import com.bytedance.ttnet.http.RequestContext;
import com.bytedance.ttnet.utils.RetrofitUtils;
import com.ttnet.org.chromium.net.urlconnection.TTRequestCanceledException;
import com.vega.ailabagent.unifyagent.conversation.sse.AiLabHostSseApiService;
import com.vega.ailabagent.unifyagent.conversation.sse.AiLabHostSseRequestParams;
import com.vega.ailabagent.unifyagent.conversation.sse.AiLabHostSseRequester;
import com.vega.ailabagent.unifyagent.conversation.sse.AiLabHostSseRequesterKt;
import com.vega.kmp.agent.core.depends.BLog;
import com.vega.kmp.agent.core.util.platform.SseRequestHandle;
import com.vega.kmp.agent.core.util.platform.SseTransport;
import com.vega.kmp.agent.core.util.sse.SseConnection;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import kotlin.Result;
import kotlin.ResultKt;
import kotlin.TuplesKt;
import kotlin.collections.MapsKt__MapsJVMKt;
import kotlin.collections.MapsKt__MapsKt;
import kotlin.jvm.internal.Intrinsics;
import kotlin.jvm.internal.Ref;
import kotlin.text.Charsets;
import kotlin.text.StringsKt__StringNumberConversionsKt;
import org.json.JSONObject;

/* JADX INFO: loaded from: D:\Decompiler\App\Video\Capcut\extracted\classes20.dex */
public final class AiLabHostSseTransport implements SseTransport {
    public final SseRequestHandle a(String str, Map map, Map map2, String str2, final SseConnection.doConnect.1 r20) {
        Object objCreateFailure;
        Intrinsics.checkNotNullParameter(str, "");
        Intrinsics.checkNotNullParameter(map, "");
        Intrinsics.checkNotNullParameter(map2, "");
        Intrinsics.checkNotNullParameter(str2, "");
        Intrinsics.checkNotNullParameter(r20, "");
        final AiLabHostSseRequester aiLabHostSseRequester = new AiLabHostSseRequester();
        try {
            objCreateFailure = new JSONObject(str2);
            Result.constructor-impl(objCreateFailure);
        } catch (Throwable th) {
            objCreateFailure = ResultKt.createFailure(th);
            Result.constructor-impl(objCreateFailure);
        }
        JSONObject jSONObject = new JSONObject();
        if (Result.isFailure-impl(objCreateFailure)) {
            objCreateFailure = jSONObject;
        }
        AiLabHostSseRequestParams aiLabHostSseRequestParams = new AiLabHostSseRequestParams(MapsKt__MapsKt.toMutableMap(MapsKt__MapsKt.plus(map, MapsKt__MapsJVMKt.mapOf(TuplesKt.to("dont_reset_timeout", "1")))), (JSONObject) objCreateFailure, MapsKt__MapsKt.toMutableMap(map2), 3);
        ExpandCallback<TypedInput> expandCallback = new ExpandCallback<TypedInput>() { // from class: com.vega.ailabagent.unifyagent.conversation.AiLabHostSseTransport$connect$call$1
            public final void onAsyncPreRequest(RequestBuilder requestBuilder) {
                Intrinsics.checkNotNullParameter(requestBuilder, "");
            }

            public final void onResponse(Call<TypedInput> call, SsResponse<TypedInput> ssResponse) {
                Intrinsics.checkNotNullParameter(call, "");
                Intrinsics.checkNotNullParameter(ssResponse, "");
            }

            public final void onFailure(Call<TypedInput> call, Throwable th2) {
                int iIntValue;
                Intrinsics.checkNotNullParameter(call, "");
                Intrinsics.checkNotNullParameter(th2, "");
                Integer intOrNull = StringsKt__StringNumberConversionsKt.toIntOrNull(AiLabHostSseRequesterKt.a(th2));
                if (intOrNull != null) {
                    iIntValue = intOrNull.intValue();
                } else {
                    iIntValue = -1;
                }
                String str3 = "onFailure " + AiLabHostSseRequesterKt.b(th2);
                if ((th2 instanceof TTRequestCanceledException) || (th2.getCause() instanceof TTRequestCanceledException)) {
                    r20.onCancel();
                } else {
                    r20.c(iIntValue, str3, (String) null);
                }
            }

            public final void onAsyncResponse(Call<TypedInput> call, SsResponse<TypedInput> ssResponse) {
                Object next;
                String value;
                String str3 = "";
                Intrinsics.checkNotNullParameter(call, "");
                Intrinsics.checkNotNullParameter(ssResponse, "");
                List listHeaders = ssResponse.headers();
                Intrinsics.checkNotNullExpressionValue(listHeaders, "");
                Iterator it = listHeaders.iterator();
                do {
                    next = null;
                    if (!it.hasNext()) {
                        break;
                    } else {
                        next = it.next();
                    }
                } while (!Intrinsics.areEqual(((Header) next).getName(), "x-tt-logid"));
                Header header = (Header) next;
                if (header != null && (value = header.getValue()) != null) {
                    str3 = value;
                }
                int iCode = ssResponse.code();
                String str4 = "onAsyncResponse " + ssResponse.message();
                if (!ssResponse.isSuccessful()) {
                    r20.c(iCode, str4, str3);
                    BLog.Companion.e("EdwardAgent.AiLabHostSseTransport", "Response error. code=" + iCode + ", message=" + str4);
                    return;
                }
                r20.a(str3);
                try {
                    BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(((TypedInput) ssResponse.body()).in(), Charsets.UTF_8));
                    while (true) {
                        String line = bufferedReader.readLine();
                        if (line == null) {
                            r20.b();
                            return;
                        }
                        r20.e(line);
                    }
                } catch (Throwable th2) {
                    if ((th2 instanceof TTRequestCanceledException) || (th2.getCause() instanceof TTRequestCanceledException)) {
                        r20.onCancel();
                    } else {
                        String str5 = "Fail when processing response, errorCode = " + AiLabHostSseRequesterKt.a(th2) + ", errorMsg = " + AiLabHostSseRequesterKt.b(th2) + ", stack = " + 4d1.b(th2);
                        try {
                            ((TypedInput) ssResponse.body()).in().close();
                        } catch (Exception unused) {
                        }
                        r20.d(str5, str3);
                        EnsureManager.ensureNotReachHere(th2);
                    }
                    BLog.Companion.e("EdwardAgent.AiLabHostSseTransport", "Fail when processing response", th2);
                }
            }
        };
        RequestContext requestContext = new RequestContext();
        ((BaseRequestContext) requestContext).timeout_connect = 300000L;
        ((BaseRequestContext) requestContext).timeout_read = 300000L;
        ((BaseRequestContext) requestContext).timeout_write = 300000L;
        ((BaseRequestContext) requestContext).protect_timeout = ((long) 2) * 300000;
        ((BaseRequestContext) requestContext).socket_connect_timeout = 300000L;
        ((BaseRequestContext) requestContext).socket_read_timeout = 300000L;
        ((BaseRequestContext) requestContext).socket_write_timeout = 300000L;
        Pair url = UrlUtils.parseUrl(str, aiLabHostSseRequestParams.c);
        String str3 = (String) url.first;
        String str4 = (String) url.second;
        String str5 = aiLabHostSseRequestParams.e.get("Content-Type");
        if (str5 == null || str5.length() == 0) {
            str5 = "application/json";
        }
        String string = aiLabHostSseRequestParams.d.toString();
        Intrinsics.checkNotNullExpressionValue(string, "");
        byte[] bytes = string.getBytes(Charsets.UTF_8);
        Intrinsics.checkNotNullExpressionValue(bytes, "");
        TypedByteArray typedByteArray = new TypedByteArray(str5, bytes, new String[0]);
        Map<String, String> map3 = aiLabHostSseRequestParams.e;
        ArrayList arrayList = new ArrayList(map3.size());
        for (Map.Entry<String, String> entry : map3.entrySet()) {
            arrayList.add(new Header(entry.getKey(), entry.getValue()));
        }
        Ref.ObjectRef objectRef = new Ref.ObjectRef();
        AiLabHostSseApiService aiLabHostSseApiService = (AiLabHostSseApiService) RetrofitUtils.createSsService(str3, AiLabHostSseApiService.class);
        if (aiLabHostSseApiService != null) {
            boolean z = aiLabHostSseRequestParams.a;
            long j = aiLabHostSseRequestParams.b;
            Intrinsics.checkNotNull(str4);
            Call callPostStream = aiLabHostSseApiService.postStream(z, j, str4, aiLabHostSseRequestParams.c, typedByteArray, arrayList, requestContext);
            callPostStream.enqueue(expandCallback);
            objectRef.element = callPostStream;
        }
        final Call call = (Call) objectRef.element;
        return new SseRequestHandle() { // from class: com.vega.ailabagent.unifyagent.conversation.AiLabHostSseTransport$connect$1
            public final void cancel() {
                Call<TypedInput> call2 = call;
                if (call2 != null) {
                    aiLabHostSseRequester.getClass();
                    call2.cancel();
                }
            }
        };
    }
}
