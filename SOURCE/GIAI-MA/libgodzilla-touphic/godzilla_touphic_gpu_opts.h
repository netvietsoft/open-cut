/**
 * @file godzilla_touphic_gpu_opts.h
 * @brief GPU, HWUI, Skia, EGL, ARM Mali, and Qualcomm Adreno Crash-Mitigation Subsystems
 *        Các phân hệ Giảm thiểu Sập GPU, HWUI, Skia, EGL, ARM Mali và Qualcomm Adreno
 *
 * Binary Verified Addresses / Địa chỉ nhị phân đã xác minh:
 *   - `MaxTextureOpt`: `0x0076c4..0x007a90`
 *   - `MakeFromTextureOptS`: `0x007a94..0x008524`
 *   - `SurfaceUpdateOpt`: `0x008528..0x008928` (`_Z23updateTexImageByteProxyPv` @ `0x008528`, `_Z19updateTexImageProxyPv` @ `0x008640`)
 *   - `CreateLayerOpt`: `0x009538..0x0098f0`
 *   - `GLESMaliOpt`: `0x0098f4..0x00a2c0`
 *   - `EglNotInitOpt`: `0x00a888..0x00aab4`
 *   - `GLESAdrenoOpt`: `0x00aab8..0x00d3f0` (`nativeInitDoubleFreeOpt` @ `0x00aab8`, `nativeInitUafOpt` @ `0x00ba0c`)
 */

#ifndef OPENCUT_GODZILLA_TOUPHIC_GPU_OPTS_H_
#define OPENCUT_GODZILLA_TOUPHIC_GPU_OPTS_H_

#include "godzilla_touphic_types.h"

namespace bytedance {
namespace platform {
namespace godzilla {
namespace touphic {

// 1. MaxTextureOpt (`0x0076c4..0x007a90`)
jint max_texture_opt_start(JNIEnv* env, jclass clazz, jint sdk_int);
jint max_texture_opt_safe_max_size(JNIEnv* env, jclass clazz);

// 2. MakeFromTextureOptS (`0x007a94..0x008524`)
jboolean make_from_texture_opt_s_start_hook(JNIEnv* env, jobject thiz);
void make_from_texture_opt_s_create_crash(JNIEnv* env, jobject thiz);

// 3. SurfaceUpdateOpt (`0x008528..0x008928`)
jint surface_update_opt_start(JNIEnv* env, jobject thiz, jint sdk_int);
int update_tex_image_byte_proxy_impl(void* surface_texture);
int update_tex_image_proxy_impl(void* surface_texture);

// 4. CreateLayerOpt (`0x009538..0x0098f0`)
jint create_layer_opt_init(JNIEnv* env, jclass clazz, jint sdk_int, jint max_texture_size, jboolean is_debug);

// 5. GLESMaliOpt (`0x0098f4..0x00a2c0`)
jint gles_mali_opt_init(JNIEnv* env, jclass clazz, jstring build_id, jstring target_sym, jlong offset, jboolean is_debug);

// 6. EglNotInitOpt (`0x00a888..0x00aab4`)
jboolean egl_not_init_opt_wait(JNIEnv* env, jclass clazz, jint delay_ms);

// 7. GLESAdrenoOpt (`0x00aab8..0x00d3f0`)
jint gles_adreno_opt_init_double_free(JNIEnv* env, jclass clazz, jint size, jint slot_size, jboolean need_timing, jboolean is_debug);
jint gles_adreno_opt_init_uaf(JNIEnv* env, jclass clazz, jint mode, jobject config_obj);

}  // namespace touphic
}  // namespace godzilla
}  // namespace platform
}  // namespace bytedance

#endif  // OPENCUT_GODZILLA_TOUPHIC_GPU_OPTS_H_
