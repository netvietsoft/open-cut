package com.vega.ailabagent.unifyagent.conversation.sse;

import com.bytedance.retrofit2.Call;
import com.bytedance.retrofit2.client.Header;
import com.bytedance.retrofit2.http.AddCommonParam;
import com.bytedance.retrofit2.http.Body;
import com.bytedance.retrofit2.http.ExtraInfo;
import com.bytedance.retrofit2.http.HeaderList;
import com.bytedance.retrofit2.http.MaxLength;
import com.bytedance.retrofit2.http.POST;
import com.bytedance.retrofit2.http.QueryMap;
import com.bytedance.retrofit2.http.Streaming;
import com.bytedance.retrofit2.http.Url;
import com.bytedance.retrofit2.mime.TypedInput;
import com.bytedance.retrofit2.mime.TypedOutput;
import java.util.List;
import java.util.Map;

/* JADX INFO: loaded from: D:\Decompiler\App\Video\Capcut\extracted\classes9.dex */
public interface AiLabHostSseApiService {

    public static final class DefaultImpls {
    }

    @POST
    @Streaming
    Call<TypedInput> postStream(@AddCommonParam boolean z, @MaxLength long j, @Url String str, @QueryMap(encode = true) Map<String, String> map, @Body TypedOutput typedOutput, @HeaderList List<Header> list, @ExtraInfo Object obj);
}
