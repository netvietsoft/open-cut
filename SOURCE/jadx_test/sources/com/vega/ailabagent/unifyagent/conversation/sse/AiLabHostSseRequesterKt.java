package com.vega.ailabagent.unifyagent.conversation.sse;

import com.bytedance.frameworks.baselib.network.http.cronet.impl.CronetIOException;
import com.bytedance.frameworks.baselib.network.http.exception.CdnCacheVerifyException;
import com.bytedance.frameworks.baselib.network.http.exception.ClientProtocolException;
import com.bytedance.frameworks.baselib.network.http.exception.HttpResponseException;
import com.bytedance.frameworks.baselib.network.http.exception.NetworkNotAvailabeException;
import com.bytedance.frameworks.baselib.network.http.exception.NoHttpResponseException;
import com.bytedance.frameworks.baselib.network.http.exception.NotAllowApiHttpException;
import com.bytedance.frameworks.baselib.network.http.exception.NotAllowUseNetworkException;
import kotlin.Result;
import kotlin.ResultKt;
import kotlin.jvm.internal.Intrinsics;

/* JADX INFO: loaded from: D:\Decompiler\App\Video\Capcut\extracted\classes15.dex */
public final class AiLabHostSseRequesterKt {
    public static final String a(Throwable th) {
        Object objCreateFailure;
        Object obj = "1000";
        Intrinsics.checkNotNullParameter(th, "");
        try {
            if (th instanceof NetworkNotAvailabeException) {
                return "1003";
            }
            if (th instanceof CronetIOException) {
                CronetIOException cronetIOException = (CronetIOException) th;
                try {
                    if (cronetIOException.getCause() instanceof HttpResponseException) {
                        objCreateFailure = String.valueOf(cronetIOException.getStatusCode());
                    } else {
                        objCreateFailure = String.valueOf(cronetIOException.getCronetInternalErrorCode());
                    }
                    Result.constructor-impl(objCreateFailure);
                } catch (Throwable th2) {
                    objCreateFailure = ResultKt.createFailure(th2);
                    Result.constructor-impl(objCreateFailure);
                }
                if (Result.isFailure-impl(objCreateFailure)) {
                    objCreateFailure = "1000";
                }
                return (String) objCreateFailure;
            }
            if (th instanceof CdnCacheVerifyException) {
                return "1001";
            }
            if (th instanceof ClientProtocolException) {
                return "1002";
            }
            if (th instanceof NoHttpResponseException) {
                return "1004";
            }
            if (th instanceof NotAllowApiHttpException) {
                return "1005";
            }
            if (!(th instanceof NotAllowUseNetworkException)) {
                return "1000";
            }
            return "1006";
        } catch (Throwable th3) {
            Object objCreateFailure2 = ResultKt.createFailure(th3);
            Result.constructor-impl(objCreateFailure2);
            if (!Result.isFailure-impl(objCreateFailure2)) {
                obj = objCreateFailure2;
            }
            return (String) obj;
        }
    }

    public static final String b(Throwable th) {
        Intrinsics.checkNotNullParameter(th, "");
        try {
            if (th instanceof NetworkNotAvailabeException) {
                return "network unavailable";
            }
            if (th instanceof CronetIOException) {
                return th.getMessage();
            }
            if (th instanceof CdnCacheVerifyException) {
                return th.getMessage();
            }
            if (th instanceof ClientProtocolException) {
                return th.getMessage();
            }
            if (th instanceof NoHttpResponseException) {
                return th.getMessage();
            }
            if (th instanceof NotAllowApiHttpException) {
                return th.getMessage();
            }
            if (th instanceof NotAllowUseNetworkException) {
                return th.getMessage();
            }
            return th.getMessage();
        } catch (Throwable th2) {
            Object objCreateFailure = ResultKt.createFailure(th2);
            Result.constructor-impl(objCreateFailure);
            if (Result.isFailure-impl(objCreateFailure)) {
                objCreateFailure = null;
            }
            return (String) objCreateFailure;
        }
    }
}
