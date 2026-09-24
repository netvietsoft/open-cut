package com.vega.ailabagent.unifyagent.conversation;

import com.bytedance.retrofit2.http.Body;
import com.bytedance.retrofit2.http.Header;
import com.bytedance.retrofit2.http.Headers;
import com.bytedance.retrofit2.http.POST;
import com.google.gson.JsonObject;
import com.vega.core.net.TypedJson;
import com.vega.util.BaseResponse;
import kotlin.coroutines.Continuation;

/* JADX INFO: loaded from: D:\Decompiler\App\Video\Capcut\extracted\classes20.dex */
public interface UAgentApiService {
    @Headers({"Content-Type:application/json; charset=utf-8"})
    @POST("/storyboard_agent/v1/ai_lab/get_asset_draft")
    Object getAssetDraft(@Body GetAssetDraftRequestBody getAssetDraftRequestBody, Continuation<? super BaseResponse<GetAssetDraftResponse>> continuation);

    @Headers({"Content-Type:application/json; charset=utf-8"})
    @POST("/storyboard_agent/v1/ai_lab/get_conversation_details")
    Object getConversationDetailsRaw(@Header("Uid") String str, @Header("Debug-Uid") String str2, @Body TypedJson typedJson, Continuation<? super JsonObject> continuation);

    @Headers({"Content-Type:application/json; charset=utf-8"})
    @POST("/agent_eval_studio/v1/feedback/detail")
    Object getFeedbackDetail(@Body AILabFeedbackDetailRequest aILabFeedbackDetailRequest, Continuation<? super BaseResponse<AILabFeedbackDetailResponse>> continuation);

    @Headers({"Content-Type:application/json; charset=utf-8"})
    @POST("/storyboard_agent/v1/app/get_recommend_templates")
    Object getRecommendTemplates(@Body TypedJson typedJson, Continuation<? super BaseResponse<GetRecommendTemplatesResult>> continuation);

    @Headers({"Content-Type:application/json; charset=utf-8"})
    @POST("/storyboard_agent/v1/ai_lab/get_trace")
    Object getTraceRaw(@Body TypedJson typedJson, Continuation<? super JsonObject> continuation);

    @Headers({"Content-Type:application/json; charset=utf-8"})
    @POST("/agent_eval_studio/v1/feedback/list")
    Object listFeedback(@Body AILabFeedbackListRequest aILabFeedbackListRequest, Continuation<? super BaseResponse<AILabFeedbackListResponse>> continuation);

    @Headers({"Content-Type:application/json; charset=utf-8"})
    @POST("/storyboard_agent/v1/ai_lab/list_session_files")
    Object listSessionFiles(@Body ListSessionFilesRequestBody listSessionFilesRequestBody, Continuation<? super BaseResponse<ListSessionFilesResponse>> continuation);

    @Headers({"Content-Type:application/json; charset=utf-8"})
    @POST("/storyboard_agent/v1/save_task_record")
    Object saveTaskRecord(@Body TypedJson typedJson, Continuation<? super JsonObject> continuation);

    @Headers({"Content-Type:application/json; charset=utf-8"})
    @POST("/agent_eval_studio/v1/feedback/submit")
    Object submitFeedback(@Body AILabFeedbackSubmitRequest aILabFeedbackSubmitRequest, Continuation<? super BaseResponse<AILabFeedbackSubmitResponse>> continuation);

    @Headers({"Content-Type:application/json; charset=utf-8"})
    @POST("/storyboard_agent/v1/ai_lab/update_asset_resource")
    Object updateAssetResource(@Body TypedJson typedJson, Continuation<? super BaseResponse<Object>> continuation);

    @Headers({"Content-Type:application/json; charset=utf-8"})
    @POST("/storyboard_agent/v1/ai_lab/update_settings")
    Object updateSettings(@Body AILabUpdateSettingsRequestBody aILabUpdateSettingsRequestBody, Continuation<? super BaseResponse<Object>> continuation);

    @Headers({"Content-Type:application/json; charset=utf-8"})
    @POST("/storyboard/v1/resource_id_to_url")
    Object uriToUrl(@Body TypedJson typedJson, Continuation<? super BaseResponse<UriToUrlResult>> continuation);
}
