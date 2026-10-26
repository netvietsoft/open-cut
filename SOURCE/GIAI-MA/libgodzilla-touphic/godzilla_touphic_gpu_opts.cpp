/**
 * @file godzilla_touphic_gpu_opts.cpp
 * @brief Implementation of GPU, HWUI, Skia, EGL, ARM Mali, and Qualcomm Adreno Crash-Mitigation Subsystems
 *        Triển khai các phân hệ Giảm thiểu Sập GPU, HWUI, Skia, EGL, ARM Mali và Qualcomm Adreno
 *
 * Binary Target / Đích nhị phân:
 *   apktool-res/lib/arm64-v8a/libgodzilla-touphic.so (65,304 bytes)
 * Verification Scope / Phạm vi xác minh:
 *   .text 0x0076c4..0x008928, 0x009538..0x00a2c0, 0x00a888..0x00d3f0
 */

#include "godzilla_touphic_gpu_opts.h"
#include "godzilla_touphic_core_infra.h"

#include <android/log.h>
#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <atomic>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace bytedance {
namespace platform {
namespace godzilla {
namespace touphic {

namespace {

static constexpr const char* kLogTag = "TOUPHIC";

// ============================================================================
// SUBSYSTEM 3 STATE: MaxTextureOpt (.data 0x0175d0, .bss 0x0176f8..0x017710)
// ============================================================================
uint8_t   g_max_tex_first_call = 1;        // .data 0x0175d0 = 1
int     (*g_max_tex_orig_fn)() = nullptr;  // .bss  0x0176f8
JavaVM*   g_max_tex_jvm        = nullptr;  // .bss  0x017700
jclass    g_max_tex_clazz      = nullptr;  // .bss  0x017708
jmethodID g_max_tex_method_id  = nullptr;  // .bss  0x017710

int max_texture_size_proxy() {
    // 0x00783c..0x0079f0
    if (g_max_tex_first_call != 0) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "enter first call MaxTextureSize");
        JNIEnv* env = nullptr;
        jint get_env_rc = g_max_tex_jvm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6);
        int result = 0;
        if (get_env_rc == JNI_EDETACHED) {
            __android_log_print(ANDROID_LOG_ERROR, kLogTag, "thread not attached");
            result = g_max_tex_orig_fn();
        } else if (env == nullptr) {
            __android_log_print(ANDROID_LOG_ERROR, kLogTag, "sEnv is null");
            result = g_max_tex_orig_fn();
        } else {
            g_max_tex_method_id = env->GetStaticMethodID(g_max_tex_clazz, "nSafeMaxTextureSize", "()I");
            if (g_max_tex_method_id == nullptr) {
                env->ExceptionClear();
                __android_log_print(ANDROID_LOG_ERROR, kLogTag, "can not find SafeMaxTextureSize static method");
                result = g_max_tex_orig_fn();
            } else {
                result = env->CallStaticIntMethod(g_max_tex_clazz, g_max_tex_method_id);
                if (env->ExceptionCheck()) {
                    env->ExceptionClear();
                    __android_log_print(ANDROID_LOG_ERROR, kLogTag, "call SafeMaxTextureSize failed");
                    result = g_max_tex_orig_fn();
                }
                __android_log_print(ANDROID_LOG_ERROR, kLogTag, "call SafeMaxTextureSize end, result %d", result);
            }
        }
        g_max_tex_first_call = 0;
        shadowhook_pop_stack(__builtin_return_address(0));
        return result;
    }

    int result = g_max_tex_orig_fn();
    shadowhook_pop_stack(__builtin_return_address(0));
    return result;
}

// ============================================================================
// SUBSYSTEM 4 STATE: MakeFromTextureOptS (.data 0x0175d8..0x0175f8, .bss 0x017718..0x017730)
// ============================================================================
std::unordered_map<void*, bool> g_make_image_active_map;  // .data 0x0175d8..0x0175f8 (max_load_factor = 1.0f @ 0x0175f8)
uint8_t g_make_tex_create_crash = 0;                      // .bss  0x017718
void*   g_unref_orig_fn         = nullptr;                // .bss  0x017720
void*   g_make_image_orig_fn    = nullptr;                // .bss  0x017728
pid_t   g_render_thread_tid     = 0;                      // .bss  0x017730

/**
 * @brief CityHash64 / MurmurHash64A pointer hash (`0x007c58..0x007c9c`, `0x008090..0x0080d4`).
 *        Hàm băm con trỏ CityHash64 / MurmurHash64A (`kMul = 0x9ddfea08eb382d69ULL`).
 */
inline uint64_t hash_pointer_city64(const void* ptr) {
    uint64_t val = reinterpret_cast<uint64_t>(ptr);
    uint64_t low_shifted = ((val & 0xffffffffULL) << 3) + 8ULL;
    uint64_t high = val >> 32;
    uint64_t x8 = (low_shifted ^ high) * kCityHash64Mul;
    uint64_t x10 = high ^ (x8 >> 47);
    x8 = (x10 ^ x8) * kCityHash64Mul;
    x8 = (x8 ^ (x8 >> 47)) * kCityHash64Mul;
    return x8;
}

void proxy_unref_fun(void* thiz, bool release_image) {
    // 0x007c18..0x007dcc
    if (gettid() == g_render_thread_tid && !g_make_image_active_map.empty()) {
        auto it = g_make_image_active_map.find(thiz);
        if (it != g_make_image_active_map.end() && it->second && !release_image) {
            __android_log_print(ANDROID_LOG_ERROR, kLogTag, "ProxyUnrefFun(), skip unref, thiz = %p", thiz);
            shadowhook_pop_stack(__builtin_return_address(0));
            return;
        }
    }
    using UnrefFn = void (*)(void*, bool);
    auto orig_fn = reinterpret_cast<UnrefFn>(shadowhook_get_prev_func(reinterpret_cast<void*>(proxy_unref_fun)));
    orig_fn(thiz, release_image);
    shadowhook_pop_stack(__builtin_return_address(0));
}

void proxy_make_image_fun(void* thiz, void* hardware_buffer, int32_t dataspace, void* gr_context) {
    // 0x007dd0..0x008074
    g_render_thread_tid = gettid();
    g_make_image_active_map[thiz] = true;

    using MakeImageFn = void (*)(void*, void*, int32_t, void*);
    auto orig_fn = reinterpret_cast<MakeImageFn>(shadowhook_get_prev_func(reinterpret_cast<void*>(proxy_make_image_fun)));
    orig_fn(thiz, hardware_buffer, dataspace, gr_context);

    g_make_image_active_map.erase(thiz);
    shadowhook_pop_stack(__builtin_return_address(0));
}

// ============================================================================
// SUBSYSTEM 5 STATE: SurfaceUpdateOpt (.bss 0x017738..0x017748)
// ============================================================================
int (*g_update_tex_image_orig)(void*) = nullptr;  // .bss 0x017738
int32_t g_update_tex_err_counter      = 0;        // .bss 0x017740
const char* g_update_tex_so_name      = nullptr;  // .bss 0x017748

uint64_t call_update_tex_image_byte_orig(void* surface_texture) {
    // 0x008604..0x008630
    using UpdateTexFn = int (*)(void*);
    auto prev_fn = reinterpret_cast<UpdateTexFn>(
        bytehook_get_prev_func(reinterpret_cast<void*>(update_tex_image_byte_proxy_impl)));
    return static_cast<uint64_t>(prev_fn(surface_texture));
}

uint64_t call_update_tex_image_shadow_orig(void* surface_texture) {
    // 0x008634..0x00863c
    return static_cast<uint64_t>(g_update_tex_image_orig(surface_texture));
}

// ============================================================================
// SUBSYSTEM 9 STATE: CreateLayerOpt (.rodata 0x00553c..0x005563, .data.rel.ro 0x012e98..0x012ee0, .bss 0x0177a0..0x0177d0)
// ============================================================================
// Verified from .rodata 0x00553c and 0x005550 (5 x uint32_t for API 31..35):
static constexpr uint32_t kRenderNodeWidthOffsets[5]  = {0x48, 0x48, 0x48, 0x48, 0x40};
static constexpr uint32_t kRenderNodeHeightOffsets[5] = {0x4c, 0x4c, 0x4c, 0x4c, 0x44};

// Verified from .data.rel.ro 0x012e98..0x012eb8:
static constexpr const char* kCreateOrUpdateLayerSymbols[5] = {
    "_ZN7android10uirenderer12skiapipeline12SkiaPipeline19createOrUpdateLayerEPNS0_10RenderNodeERKNS0_17DamageAccumulatorEPNS0_12ErrorHandlerE",
    "_ZN7android10uirenderer12skiapipeline12SkiaPipeline19createOrUpdateLayerEPNS0_10RenderNodeERKNS0_17DamageAccumulatorEPNS0_12ErrorHandlerE",
    "_ZN7android10uirenderer12skiapipeline12SkiaPipeline19createOrUpdateLayerEPNS0_10RenderNodeERKNS0_17DamageAccumulatorEPNS0_12ErrorHandlerE",
    "_ZN7android10uirenderer12skiapipeline12SkiaPipeline19createOrUpdateLayerEPNS0_10RenderNodeERKNS0_17DamageAccumulatorEPNS0_12ErrorHandlerE",
    "_ZN7android10uirenderer12skiapipeline15SkiaGpuPipeline19createOrUpdateLayerEPNS0_10RenderNodeERKNS0_17DamageAccumulatorEPNS0_12ErrorHandlerE"
};

// Verified from .data.rel.ro 0x012ec0..0x012ee0:
static constexpr const char* kMakeRenderTargetSymbols[5] = {
    "_ZN9SkSurface16MakeRenderTargetEP18GrRecordingContext10SkBudgetedRK11SkImageInfoi15GrSurfaceOriginPK14SkSurfacePropsb",
    "_ZN7android10uirenderer12skiapipeline12SkiaPipeline19createOrUpdateLayerEPNS0_10RenderNodeERKNS0_17DamageAccumulatorEPNS0_12ErrorHandlerE",
    "_ZN7android10uirenderer12skiapipeline12SkiaPipeline19createOrUpdateLayerEPNS0_10RenderNodeERKNS0_17DamageAccumulatorEPNS0_12ErrorHandlerE",
    "_ZN9SkSurface16MakeRenderTargetEP18GrRecordingContextN5skgpu8BudgetedERK11SkImageInfoi15GrSurfaceOriginPK14SkSurfacePropsb",
    "_ZN10SkSurfaces12RenderTargetEP18GrRecordingContextN5skgpu8BudgetedERK11SkImageInfoi15GrSurfaceOriginPK14SkSurfacePropsbb"
};

int32_t       g_create_layer_max_tex_size = 0;        // .bss 0x0177a0
pthread_key_t g_create_layer_tls_key      = 0;        // .bss 0x0177a4
const char*   g_create_layer_sym          = nullptr;  // .bss 0x0177a8
void*         g_create_layer_hook_stub    = nullptr;  // .bss 0x0177b0
const char*   g_make_render_target_sym    = nullptr;  // .bss 0x0177b8
void*         g_make_render_target_stub   = nullptr;  // .bss 0x0177c0
uint8_t       g_create_layer_is_debug     = 0;        // .bss 0x0177c8
uint32_t      g_render_node_width_offset  = 0;        // .bss 0x0177cc
uint32_t      g_render_node_height_offset = 0;        // .bss 0x0177d0

bool create_or_update_layer_proxy(void* pipeline, uint8_t* render_node, void* damage_accum, void* error_handler) {
    // 0x00971c..0x009800
    int32_t width  = *reinterpret_cast<int32_t*>(render_node + g_render_node_width_offset);
    int32_t height = *reinterpret_cast<int32_t*>(render_node + g_render_node_height_offset);
    int32_t threshold = g_create_layer_max_tex_size - kHwuiLayerSizeMask;  // sub w8, w8, #0x3f

    if (width >= threshold || height >= threshold) {
        uint64_t packed_wh = static_cast<uint32_t>(width) | (static_cast<uint64_t>(static_cast<uint32_t>(height)) << 32);
        if (g_create_layer_is_debug != 0) {
            __android_log_print(ANDROID_LOG_ERROR, kLogTag,
                                "createOrUpdateLayer_proxy width: %d, height: %d, width_height: 0x%lx",
                                width, height, static_cast<unsigned long>(packed_wh));
        }
        pthread_setspecific(g_create_layer_tls_key, reinterpret_cast<void*>(packed_wh));
    }

    using CreateLayerFn = bool (*)(void*, uint8_t*, void*, void*);
    auto prev_fn = reinterpret_cast<CreateLayerFn>(
        shadowhook_get_prev_func(reinterpret_cast<void*>(create_or_update_layer_proxy)));
    bool ret = prev_fn(pipeline, render_node, damage_accum, error_handler);
    shadowhook_pop_stack(__builtin_return_address(0));
    return ret;
}

void make_render_target_interceptor(ShadowHookCpuContext* cpu_ctx, void* /*data*/) {
    // 0x009804..0x0098f0
    void* tls_val = pthread_getspecific(g_create_layer_tls_key);
    if (tls_val == nullptr) {
        return;
    }
    pthread_setspecific(g_create_layer_tls_key, nullptr);
    uint64_t packed_wh = reinterpret_cast<uint64_t>(tls_val);
    if (g_create_layer_is_debug != 0) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag,
                            "makeRenderTarget_interceptor width: %d, height: %d, width_height: 0x%lx",
                            static_cast<int32_t>(packed_wh & 0xffffffffU),
                            static_cast<int32_t>(packed_wh >> 32),
                            static_cast<unsigned long>(packed_wh));
    }

    // SkImageInfo* is in x2 (cpu_ctx->regs[2] at offset +0x10)
    auto* sk_image_info = reinterpret_cast<int32_t*>(cpu_ctx->regs[2]);
    if (sk_image_info == nullptr) {
        return;
    }
    int32_t info_width  = sk_image_info[4];  // [x20, #0x10]
    int32_t info_height = sk_image_info[5];  // [x20, #0x14]
    if (info_width > g_create_layer_max_tex_size) {
        if (g_create_layer_is_debug != 0) {
            __android_log_print(ANDROID_LOG_ERROR, kLogTag,
                                "makeRenderTarget_interceptor info width: %d exceed maxTextureSize: %d",
                                info_width, g_create_layer_max_tex_size);
        }
        sk_image_info[4] = g_create_layer_max_tex_size;
    }
    if (info_height > g_create_layer_max_tex_size) {
        if (g_create_layer_is_debug != 0) {
            __android_log_print(ANDROID_LOG_ERROR, kLogTag,
                                "makeRenderTarget_interceptor info height: %d exceed maxTextureSize: %d",
                                info_height, g_create_layer_max_tex_size);
        }
        sk_image_info[5] = g_create_layer_max_tex_size;
    }
}

// ============================================================================
// SUBSYSTEM 10 STATE: GLESMaliOpt (.bss 0x0177d8..0x0177f8)
// ============================================================================
std::string g_mali_actual_build_id;   // .bss 0x0177d8..0x0177ef (guarded by 0x0177f0)
uint8_t     g_mali_is_debug = 0;      // .bss 0x0177f8

/**
 * @brief Extracts `.note.gnu.build-id` hex string from an ELF64 shared library (`0x009e14..0x00a1a8`).
 *        Trích xuất chuỗi hex `.note.gnu.build-id` từ thư viện chia sẻ ELF64 (`0x009e14..0x00a1a8`).
 */
void extract_elf64_build_id(const std::string& so_full_path) {
    int fd = open(so_full_path.c_str(), O_RDONLY);
    if (fd <= 0) {
        g_mali_actual_build_id.clear();
        return;
    }
    off_t file_size = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);
    void* mapped = mmap(nullptr, static_cast<size_t>(file_size), PROT_READ, MAP_PRIVATE, fd, 0);
    if (mapped == MAP_FAILED) {
        g_mali_actual_build_id.clear();
        close(fd);
        return;
    }

    auto* ehdr = static_cast<const Elf64_Ehdr*>(mapped);
    const auto* shdr_base = reinterpret_cast<const Elf64_Shdr*>(
        static_cast<const uint8_t*>(mapped) + ehdr->e_shoff);
    const char* shstrtab = reinterpret_cast<const char*>(
        static_cast<const uint8_t*>(mapped) + shdr_base[ehdr->e_shstrndx].sh_offset);

    std::vector<const Elf64_Shdr*> note_sections;
    for (uint16_t i = 0; i < ehdr->e_shnum; ++i) {
        if (shdr_base[i].sh_type == SHT_NOTE) {  // sh_type == 7 (0x009efc: cmp w8, #7)
            note_sections.push_back(&shdr_base[i]);
        }
    }

    g_mali_actual_build_id.clear();
    for (const Elf64_Shdr* sec : note_sections) {
        if (strncmp(shstrtab + sec->sh_name, ".note.gnu.build-id", 18) == 0) {
            if (sec->sh_size != 16 && sec->sh_size > 16) {
                const uint8_t* desc = static_cast<const uint8_t*>(mapped) + sec->sh_offset + 16;
                size_t desc_len = sec->sh_size - 16;
                for (size_t b = 0; b < desc_len; ++b) {
                    char hex_byte[4] = {};
                    format_buffer(hex_byte, 3, "%02x", desc[b]);
                    g_mali_actual_build_id.append(hex_byte);
                }
            }
            break;
        }
    }

    munmap(mapped, static_cast<size_t>(file_size));
    close(fd);
}

void mali_interceptor(ShadowHookCpuContext* cpu_ctx, void* /*data*/) {
    // 0x00a254..0x00a2c0:
    // Checks *(uint8_t*)(cpu_ctx->regs[20] + 8) == 1 && (uint32_t)cpu_ctx->regs[8] == 1;
    // If not, forces low 32 bits of cpu_ctx->regs[8] (slot_num) to 1!
    uint8_t* x20_ptr = reinterpret_cast<uint8_t*>(cpu_ctx->regs[20]);  // [x0, #0xa0]
    uint64_t x8_val  = cpu_ctx->regs[8];                               // [x0, #0x40]
    if (x20_ptr[8] == 1 && static_cast<uint32_t>(x8_val) == 1U) {
        return;
    }
    if (g_mali_is_debug != 0) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "mali interceptor, slot num = %d", 1);
    }
    cpu_ctx->regs[8] = (x8_val & 0xffffffff00000000ULL) | 1ULL;
}

// ============================================================================
// SUBSYSTEM 12 STATE: EglNotInitOpt (.bss 0x017828)
// ============================================================================
int32_t g_egl_wait_delay_ms = 0;  // .bss 0x017828

void egl_manager_initialize_proxy(void* egl_manager) {
    // 0x00a9c0..0x00aa38
    usleep(static_cast<useconds_t>(g_egl_wait_delay_ms * 1000));
    __android_log_print(ANDROID_LOG_INFO, kLogTag, "EglManager_initialize_proxy usleep %d ms", g_egl_wait_delay_ms);
    using InitFn = void (*)(void*);
    auto prev_fn = reinterpret_cast<InitFn>(
        shadowhook_get_prev_func(reinterpret_cast<void*>(egl_manager_initialize_proxy)));
    prev_fn(egl_manager);
    shadowhook_pop_stack(__builtin_return_address(0));
}

void render_thread_init_locals_proxy(void* render_thread) {
    // 0x00aa3c..0x00aab4
    usleep(static_cast<useconds_t>(g_egl_wait_delay_ms * 1000));
    __android_log_print(ANDROID_LOG_INFO, kLogTag, "RenderThread_initThreadLocals_proxy usleep %d ms", g_egl_wait_delay_ms);
    using InitLocalsFn = void (*)(void*);
    auto prev_fn = reinterpret_cast<InitLocalsFn>(
        shadowhook_get_prev_func(reinterpret_cast<void*>(render_thread_init_locals_proxy)));
    prev_fn(render_thread);
    shadowhook_pop_stack(__builtin_return_address(0));
}

// ============================================================================
// SUBSYSTEM 13 STATE: GLESAdrenoOpt (.data 0x017614..0x01761c, .bss 0x01782c..0x017868)
// ============================================================================
pthread_key_t g_adreno_df_tls_key      = 0;        // .data 0x017614
int32_t       g_adreno_df_slot_size    = 256;      // .data 0x017618 = 0x100
uint8_t       g_adreno_df_need_timing  = 1;        // .data 0x01761c = 1
int32_t       g_adreno_df_target_size  = 0;        // .bss  0x01782c
uint8_t       g_adreno_df_is_debug     = 0;        // .bss  0x017830
void*         g_adreno_df_bytehook_stub = nullptr; // .bss  0x017838
const char*   g_adreno_df_caller_path  = nullptr;  // .bss  0x017840
void*         g_adreno_df_egl_tls_stub = nullptr;  // .bss  0x017848

AdrenoUafAlphaConfig* g_adreno_uaf_alpha_cfg = nullptr;  // .bss 0x017850
AdrenoUafBetaConfig*  g_adreno_uaf_beta_cfg  = nullptr;  // .bss 0x017860

}  // namespace

// ============================================================================
// PUBLIC GPU SUBSYSTEM IMPLEMENTATIONS / TRIỂN KHAI CÁC PHÂN HỆ GPU
// ============================================================================

jint max_texture_opt_start(JNIEnv* env, jclass clazz, jint sdk_int) {
    // 0x0076c4..0x007838: sub w8, w2, #0x23; cmn w8, #3; b.hi #0x7704
    if (sdk_int >= 32 && sdk_int <= 34) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "sdk version not match %d", sdk_int);
        return 1;
    }
    if (env->GetJavaVM(&g_max_tex_jvm) != JNI_OK) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "Failed to get JavaVM from JNIEnv!");
        return 1;
    }
    g_max_tex_clazz = static_cast<jclass>(env->NewGlobalRef(clazz));
    void* sym = find_symbol_in_so(
        "libhwui.so",
        "_ZN7android10uirenderer12renderthread11RenderProxy14maxTextureSizeEv");
    g_max_tex_orig_fn = reinterpret_cast<int (*)()>(sym);
    if (sym == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag,
                            "in %s can not find MaxTextureSizeFunc symbol, sdkInt = %d",
                            "libhwui.so", sdk_int);
        return 3;
    }
    if (shadowhook_init(0, false) != 0) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "init shadowhook failed !!!");
        return 7;
    }
    void* stub = shadowhook_hook_sym_addr(
        sym,
        reinterpret_cast<void*>(max_texture_size_proxy),
        reinterpret_cast<void**>(&g_max_tex_orig_fn));
    if (stub != nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "do MaxTextureSizeFunc success!");
        return 0;
    }
    __android_log_print(ANDROID_LOG_ERROR, kLogTag, "hook MaxTextureSizeFunc failed !!!");
    return 5;
}

jint max_texture_opt_safe_max_size(JNIEnv* /*env*/, jclass /*clazz*/) {
    // 0x007a64..0x007a90
    __android_log_print(ANDROID_LOG_ERROR, kLogTag, "do nSafeMaxTextureSize");
    return g_max_tex_orig_fn();
}

jboolean make_from_texture_opt_s_start_hook(JNIEnv* /*env*/, jobject /*thiz*/) {
    // 0x007a94..0x007c14
    void* handle = npth_dlopen("libhwui.so");
    if (handle == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag,
                            "findMakeImageAndUnrefSymAddr(), can't find lib %s", "libhwui.so");
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "findMakeImageAndUnrefSymAddr() failed");
        return JNI_FALSE;
    }
    const char* make_image_sym =
        "_ZN7android10uirenderer25AutoBackendTextureRelease9makeImageEP15AHardwareBuffer19android_dataspace_tP15GrDirectContext";
    void* make_image_addr = npth_dlsym_symtab(handle, make_image_sym);
    if (make_image_addr == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "dlsym [%s] error: %s", make_image_sym, npth_dlerror());
        npth_dlclose(handle);
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "findMakeImageAndUnrefSymAddr() failed");
        return JNI_FALSE;
    }
    const char* unref_sym = "_ZN7android10uirenderer25AutoBackendTextureRelease5unrefEb";
    void* unref_addr = npth_dlsym_symtab(handle, unref_sym);
    if (unref_addr == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "dlsym [%s] error: %s", unref_sym, npth_dlerror());
        npth_dlclose(handle);
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "findMakeImageAndUnrefSymAddr() failed");
        return JNI_FALSE;
    }
    __android_log_print(ANDROID_LOG_INFO, kLogTag,
                        "findMakeImageAndUnrefSymAddr(), makeImageSymbol = %p, unrefSymbol = %p",
                        make_image_addr, unref_addr);
    npth_dlclose(handle);

    void* unref_token = shadowhook_hook_sym_addr(
        unref_addr, reinterpret_cast<void*>(proxy_unref_fun), &g_unref_orig_fn);
    void* make_image_token = shadowhook_hook_sym_addr(
        make_image_addr, reinterpret_cast<void*>(proxy_make_image_fun), &g_make_image_orig_fn);
    int err = shadowhook_get_errno();
    __android_log_print(ANDROID_LOG_INFO, kLogTag, "hook return: %d - %s", err, shadowhook_to_errmsg(err));
    __android_log_print(ANDROID_LOG_INFO, kLogTag,
                        "shadowhook ret makeImageToken = %p, unrefToken = %p",
                        make_image_token, unref_token);
    return JNI_TRUE;
}

void make_from_texture_opt_s_create_crash(JNIEnv* /*env*/, jobject /*thiz*/) {
    // 0x008518..0x008524
    g_make_tex_create_crash = 1;
}

int update_tex_image_byte_proxy_impl(void* surface_texture) {
    // 0x008528..0x008600
    if (g_update_tex_err_counter >= 11) {
        return static_cast<int>(call_update_tex_image_byte_orig(surface_texture));
    }
    TryExecuteTask task = {};
    task.magic = kTryExecuteMagic;
    task.target_fn = call_update_tex_image_byte_orig;
    int rc = safe_execute(&task, surface_texture);
    int ret = -1;
    if (rc != 0) {
        g_update_tex_err_counter++;
        __android_log_print(ANDROID_LOG_ERROR, kLogTag,
                            "updateTexImageByteProxy sExcuteErrCounter car: %d",
                            g_update_tex_err_counter);
    } else {
        ret = static_cast<int>(task.result);
    }
    if (bytehook_get_mode() == 0) {
        bytehook_pop_stack(__builtin_return_address(0));
    }
    return ret;
}

int update_tex_image_proxy_impl(void* surface_texture) {
    // 0x008640..0x0086fc
    if (g_update_tex_err_counter >= 11) {
        int ret = g_update_tex_image_orig(surface_texture);
        shadowhook_pop_stack(__builtin_return_address(0));
        return ret;
    }
    TryExecuteTask task = {};
    task.magic = kTryExecuteMagic;
    task.target_fn = call_update_tex_image_shadow_orig;
    int rc = safe_execute(&task, surface_texture);
    int ret = -1;
    if (rc != 0) {
        g_update_tex_err_counter++;
        __android_log_print(ANDROID_LOG_ERROR, kLogTag,
                            "updateTexImageProxy sExcuteErrCounter car: %d",
                            g_update_tex_err_counter);
    } else {
        ret = static_cast<int>(task.result);
    }
    shadowhook_pop_stack(__builtin_return_address(0));
    return ret;
}

jint surface_update_opt_start(JNIEnv* /*env*/, jobject /*thiz*/, jint sdk_int) {
    // 0x008700..0x008928
    const char* so_name = "libnativedisplay.so";
    void* sym = find_symbol_in_so(so_name, "_ZN7android14SurfaceTexture14updateTexImageEv");
    if (sym == nullptr) {
        so_name = "libhwui.so";
        sym = find_symbol_in_so(so_name, "_ZN7android14SurfaceTexture14updateTexImageEv");
        if (sym == nullptr) {
            __android_log_print(ANDROID_LOG_ERROR, kLogTag, "init_so_sym failed");
            return 3;
        }
    }
    g_update_tex_image_orig = reinterpret_cast<int (*)(void*)>(sym);
    g_update_tex_so_name = so_name;

    if (shadowhook_init(0, false) == 0 && bytehook_init(0, false) == 0) {
        void* bh_stub = bytehook_hook_single(
            "libandroid_runtime.so",
            g_update_tex_so_name,
            "_ZN7android14SurfaceTexture14updateTexImageEv",
            reinterpret_cast<void*>(update_tex_image_byte_proxy_impl),
            nullptr,
            nullptr);
        if (bh_stub != nullptr) {
            __android_log_print(ANDROID_LOG_ERROR, kLogTag, "do init_byteHook ret %d", 0);
            return 0;
        }
    }

    if (shadowhook_init(0, false) != 0) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "init shadowhook failed !!!");
        return 7;
    }
    void* sh_stub = shadowhook_hook_sym_addr(
        reinterpret_cast<void*>(g_update_tex_image_orig),
        reinterpret_cast<void*>(update_tex_image_proxy_impl),
        reinterpret_cast<void**>(&g_update_tex_image_orig));
    if (sh_stub != nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "hook updateTexImageFunc success !!!");
        return 0;
    }
    __android_log_print(ANDROID_LOG_ERROR, kLogTag, "hook updateTexImageFunc failed !!!");
    return 5;
}

jint create_layer_opt_init(JNIEnv* /*env*/, jclass /*clazz*/, jint sdk_int, jint max_texture_size, jboolean is_debug) {
    // 0x009538..0x0096e0
    __android_log_print(ANDROID_LOG_INFO, kLogTag, "nativeInit sdkInt: %d", sdk_int);
    __android_log_print(ANDROID_LOG_INFO, kLogTag, "nativeInit maxTextureSize: %d", max_texture_size);
    g_create_layer_max_tex_size = max_texture_size;

    if ((max_texture_size & kHwuiLayerSizeMask) == 0) {
        __android_log_print(ANDROID_LOG_INFO, kLogTag,
                            "maxTextureSize: %d is divisible by LAYER_SIZE", max_texture_size);
        return 0;
    }

    uint32_t api_idx = static_cast<uint32_t>(sdk_int - 31);
    if (api_idx <= 4U) {
        g_render_node_width_offset  = kRenderNodeWidthOffsets[api_idx];
        g_render_node_height_offset = kRenderNodeHeightOffsets[api_idx];
        g_create_layer_sym          = kCreateOrUpdateLayerSymbols[api_idx];
        g_make_render_target_sym    = kMakeRenderTargetSymbols[api_idx];
    }

    pthread_key_create(&g_create_layer_tls_key, nullptr);
    if (shadowhook_init(0, true) != 0) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "shadowhook_init failed");
        return -1;
    }

    g_create_layer_hook_stub = shadowhook_hook_sym_name(
        "libhwui.so", g_create_layer_sym, reinterpret_cast<void*>(create_or_update_layer_proxy), nullptr);
    if (g_create_layer_hook_stub == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "shadowhook_hook_sym_name failed");
        return -1;
    }

    g_make_render_target_stub = shadowhook_intercept_sym_name(
        "libhwui.so", g_make_render_target_sym, make_render_target_interceptor, nullptr, 0);
    if (g_make_render_target_stub == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "shadowhook_intercept_sym_name failed");
        shadowhook_unhook(g_create_layer_hook_stub);
        return -1;
    }

    g_create_layer_is_debug = (is_debug != JNI_FALSE) ? 1 : 0;
    return 0;
}

jint gles_mali_opt_init(JNIEnv* env, jclass /*clazz*/, jstring build_id, jstring target_sym, jlong offset, jboolean is_debug) {
    // 0x0098f4..0x009d98
    if (build_id == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "buildId is null");
        return -1;
    }
    if (target_sym == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "symbol is null");
        return -1;
    }
    if (offset <= 0) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "offset is invalid");
        return -1;
    }

    const char* build_id_cstr = env->GetStringUTFChars(build_id, nullptr);
    if (build_id_cstr == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "GetStringUTFChars failed");
        return -1;
    }
    const char* target_sym_cstr = env->GetStringUTFChars(target_sym, nullptr);
    if (target_sym_cstr == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "GetStringUTFChars failed");
        env->ReleaseStringUTFChars(build_id, build_id_cstr);
        return -1;
    }

    char maps_path[32] = {};
    pid_t pid = getpid();
    format_buffer(maps_path, sizeof(maps_path), "/proc/%d/maps", pid);
    FILE* fp = fopen(maps_path, "r");
    std::string mali_full_path;
    if (fp != nullptr) {
        char line[1024] = {};
        while (fgets(line, sizeof(line), fp) != nullptr) {
            unsigned long start_addr = 0, end_addr = 0;
            unsigned int offset_val = 0, inode = 0;
            char perms[8] = {}, path_buf[512] = {};
            int chars_read = 0;
            sscanf(line, "%lx-%lx %c%c%c%c %x %*x:%*x  %u %[^\n] %n",
                   &start_addr, &end_addr, &perms[0], &perms[1], &perms[2], &perms[3],
                   &offset_val, &inode, path_buf, &chars_read);
            if (strstr(path_buf, "libGLES_mali.so") != nullptr) {
                mali_full_path = path_buf;
                break;
            }
        }
        fclose(fp);
    } else {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "Failed to open /proc/%d/maps", pid);
    }

    int result = -1;
    if (!mali_full_path.empty()) {
        extract_elf64_build_id(mali_full_path);
        if (!g_mali_actual_build_id.empty()) {
            if (strncmp(build_id_cstr, g_mali_actual_build_id.c_str(), g_mali_actual_build_id.size()) == 0) {
                __android_log_print(ANDROID_LOG_ERROR, kLogTag,
                                    "build id match, config buildid: %s, actual buildid: %s",
                                    build_id_cstr, g_mali_actual_build_id.c_str());
                void* npth_handle = npth_dlopen("libGLES_mali.so");
                uintptr_t target_addr = 0;
                if (npth_handle != nullptr) {
                    void* base_sym = npth_dlsym(npth_handle, target_sym_cstr);
                    if (base_sym != nullptr) {
                        target_addr = reinterpret_cast<uintptr_t>(base_sym) + static_cast<uintptr_t>(offset);
                    }
                    npth_dlclose(npth_handle);
                }
                __android_log_print(ANDROID_LOG_ERROR, kLogTag,
                                    "base symbol find: %s, need hook target_addr = 0x%lx",
                                    target_sym_cstr, static_cast<unsigned long>(target_addr));
                if (target_addr != 0) {
                    void* stub = shadowhook_intercept_instr_addr(
                        reinterpret_cast<void*>(target_addr), mali_interceptor, nullptr, 0);
                    if (stub != nullptr) {
                        g_mali_is_debug = (is_debug != JNI_FALSE) ? 1 : 0;
                        result = 0;
                    } else {
                        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "shadowhook_intercept_instr_addr failed");
                    }
                }
            } else {
                __android_log_print(ANDROID_LOG_ERROR, kLogTag,
                                    "build id not match, expect %s, actual %s",
                                    build_id_cstr, g_mali_actual_build_id.c_str());
            }
        } else {
            __android_log_print(ANDROID_LOG_ERROR, kLogTag, "Failed to get %s build id", "libGLES_mali.so");
        }
    } else {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "Failed to find %s full path", "libGLES_mali.so");
    }

    env->ReleaseStringUTFChars(target_sym, target_sym_cstr);
    env->ReleaseStringUTFChars(build_id, build_id_cstr);
    return result;
}

jboolean egl_not_init_opt_wait(JNIEnv* /*env*/, jclass /*clazz*/, jint delay_ms) {
    // 0x00a888..0x00a9bc
    if (delay_ms < 1) {
        return JNI_FALSE;
    }
    if (shadowhook_init(0, false) != 0) {
        return JNI_FALSE;
    }
    g_egl_wait_delay_ms = delay_ms;
    void* init_locals_sym = find_symbol_in_so(
        "libhwui.so",
        "_ZN7android10uirenderer12renderthread12RenderThread16initThreadLocalsEv");
    if (init_locals_sym != nullptr) {
        __android_log_print(ANDROID_LOG_INFO, kLogTag,
                            "nativeWaitEglInit: initThreadLocals %p, delay_ms %d",
                            init_locals_sym, delay_ms);
        void* stub = shadowhook_hook_func_addr(
            init_locals_sym, reinterpret_cast<void*>(render_thread_init_locals_proxy), nullptr);
        return (stub != nullptr) ? JNI_TRUE : JNI_FALSE;
    }

    void* egl_init_sym = find_symbol_in_so(
        "libhwui.so",
        "_ZN7android10uirenderer12renderthread10EglManager10initializeEv");
    if (egl_init_sym != nullptr) {
        __android_log_print(ANDROID_LOG_INFO, kLogTag,
                            "nativeWaitEglInit: eglManagerInitialize %p, delay_ms %d",
                            egl_init_sym, delay_ms);
        void* stub = shadowhook_hook_func_addr(
            egl_init_sym, reinterpret_cast<void*>(egl_manager_initialize_proxy), nullptr);
        return (stub != nullptr) ? JNI_TRUE : JNI_FALSE;
    }
    return JNI_FALSE;
}

// ============================================================================
// SUBSYSTEM 13: GLESAdrenoOpt (Double-Free & UAF Alpha/Beta)
// ============================================================================

namespace {

void adreno_df_tls_destructor(void* ptr) {
    // 0x00aef0..0x00b01c
    if (ptr == nullptr) {
        return;
    }
    auto* q = static_cast<AdrenoDoubleFreeQuarantine*>(ptr);
    if (q->is_destroying == 0) {
        int32_t calls = q->dtor_calls;
        q->dtor_calls = calls + 1;
        if (calls <= 2) {
            pthread_setspecific(g_adreno_df_tls_key, q);
            return;
        }
    }
    if (g_adreno_df_is_debug != 0) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag,
                            "free_tls_destructor, dtor_calls_:%d, count_:%d",
                            q->dtor_calls, static_cast<int>(q->element_count));
    }
    AdrenoFreeHashNode* node = q->before_begin;
    while (node != nullptr) {
        if (node->ptr != nullptr) {
            free(node->ptr);
        }
        AdrenoFreeHashNode* next = node->next;
        operator delete(node);
        node = next;
    }
    if (q->buckets != nullptr) {
        operator delete(q->buckets);
    }
    operator delete(q);
    pthread_setspecific(g_adreno_df_tls_key, nullptr);
}

void adreno_egl_destruct_tls_proxy(void* tls_data) {
    // 0x00b210..0x00b2c8
    auto* q = static_cast<AdrenoDoubleFreeQuarantine*>(pthread_getspecific(g_adreno_df_tls_key));
    if (q != nullptr) {
        q->is_destroying = 1;
        if (g_adreno_df_is_debug != 0) {
            __android_log_print(ANDROID_LOG_ERROR, kLogTag,
                                "egl_destruct_tls_data_proxy, tls_data:%p, dtor_calls_:%d, count_:%d",
                                q, q->dtor_calls, static_cast<int>(q->element_count));
        }
    }
    using DestructFn = void (*)(void*);
    auto prev_fn = reinterpret_cast<DestructFn>(
        shadowhook_get_prev_func(reinterpret_cast<void*>(adreno_egl_destruct_tls_proxy)));
    prev_fn(tls_data);
    shadowhook_pop_stack(__builtin_return_address(0));
}

void adreno_free_proxy(void* ptr) {
    // 0x00b020..0x00b100:
    // Checks Scudo header: ldur w9, [x0, #-0x10]; cmp w8, w9, lsr #12
    if (ptr != nullptr) {
        uint32_t scudo_header = *reinterpret_cast<const uint32_t*>(static_cast<const uint8_t*>(ptr) - 0x10);
        if (static_cast<uint32_t>(g_adreno_df_target_size) == (scudo_header >> 12)) {
            auto* q = static_cast<AdrenoDoubleFreeQuarantine*>(pthread_getspecific(g_adreno_df_tls_key));
            if (q == nullptr && g_adreno_df_need_timing == 0) {
                q = new AdrenoDoubleFreeQuarantine{};
                q->max_load_factor = 0.2f;
                q->max_slot_capacity = static_cast<uint64_t>(g_adreno_df_slot_size);
                pthread_setspecific(g_adreno_df_tls_key, q);
            }
            if (q != nullptr) {
                // Quarantine pointer in per-thread hash set; if already present, log double-free and skip!
                for (AdrenoFreeHashNode* cur = q->before_begin; cur != nullptr; cur = cur->next) {
                    if (cur->ptr == ptr) {
                        __android_log_print(ANDROID_LOG_ERROR, kLogTag,
                                            "double free append, %p already free!", ptr);
                        if (bytehook_get_mode() == 0) {
                            bytehook_pop_stack(__builtin_return_address(0));
                        }
                        return;
                    }
                }
                if (q->element_count >= q->max_slot_capacity) {
                    // Flush quarantine when capacity reached (0x00b98c..0x00ba08)
                    AdrenoFreeHashNode* node = q->before_begin;
                    while (node != nullptr) {
                        if (node->ptr != nullptr) {
                            free(node->ptr);
                        }
                        AdrenoFreeHashNode* next = node->next;
                        operator delete(node);
                        node = next;
                    }
                    q->before_begin = nullptr;
                    q->element_count = 0;
                }
                auto* new_node = new AdrenoFreeHashNode{q->before_begin, hash_pointer_city64(ptr), ptr};
                q->before_begin = new_node;
                q->element_count++;
                if (bytehook_get_mode() == 0) {
                    bytehook_pop_stack(__builtin_return_address(0));
                }
                return;
            }
        }
    }

    using FreeFn = void (*)(void*);
    auto prev_fn = reinterpret_cast<FreeFn>(
        bytehook_get_prev_func(reinterpret_cast<void*>(adreno_free_proxy)));
    prev_fn(ptr);
    if (bytehook_get_mode() == 0) {
        bytehook_pop_stack(__builtin_return_address(0));
    }
}

}  // namespace

jint gles_adreno_opt_init_double_free(JNIEnv* /*env*/, jclass /*clazz*/, jint size, jint slot_size,
                                      jboolean need_timing, jboolean is_debug) {
    // 0x00aab8..0x00ae78
    if (size <= 0) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "offset is invalid");
        return -1;
    }
    if (slot_size <= 0) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "slotSize is invalid");
        return -1;
    }
    if (bytehook_init(0, false) != 0) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "bytehook_init failed");
        return -1;
    }
    if (shadowhook_init(0, false) != 0) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "shadowhook_init failed");
        return -1;
    }
    if (pthread_key_create(&g_adreno_df_tls_key, adreno_df_tls_destructor) != 0) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "pthread_key_create failed");
        return -1;
    }

    g_adreno_df_target_size = size;
    g_adreno_df_slot_size   = slot_size;
    g_adreno_df_need_timing = (need_timing != JNI_FALSE) ? 1 : 0;
    g_adreno_df_is_debug    = (is_debug != JNI_FALSE) ? 1 : 0;

    __android_log_print(ANDROID_LOG_ERROR, kLogTag,
                        "nativeInit, size:%d, slotSize:%d, need_timing:%d, is_debug:%d",
                        size, slot_size, g_adreno_df_need_timing, g_adreno_df_is_debug);

    g_adreno_df_bytehook_stub = bytehook_hook_single(
        "libGLESv2_adreno.so", nullptr, "free",
        reinterpret_cast<void*>(adreno_free_proxy), nullptr, nullptr);
    if (g_adreno_df_bytehook_stub == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "bytehook_hook_single failed");
        pthread_key_delete(g_adreno_df_tls_key);
        return -1;
    }
    return 0;
}

jint gles_adreno_opt_init_uaf(JNIEnv* env, jclass /*clazz*/, jint mode, jobject config_obj) {
    // 0x00ba0c..0x00ca04: Supports Mode 1 (Alpha) and Mode 2 (Beta)
    if (mode != 1 && mode != 2) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "invalid mode: %d", mode);
        return -1;
    }
    if (config_obj == nullptr) {
        return -1;
    }
    jclass cls = env->GetObjectClass(config_obj);
    if (cls == nullptr) {
        return -1;
    }

    if (mode == 1) {
        if (g_adreno_uaf_alpha_cfg == nullptr) {
            g_adreno_uaf_alpha_cfg = new AdrenoUafAlphaConfig{};
        }
        jfieldID f_target = env->GetFieldID(cls, "targetSymbol", "Ljava/lang/String;");
        jfieldID f_insert = env->GetFieldID(cls, "listNodeInsertSymbol", "Ljava/lang/String;");
        jfieldID f_find   = env->GetFieldID(cls, "findOrInsertNodeSymbol", "Ljava/lang/String;");
        g_adreno_uaf_alpha_cfg->target_symbol = convert_java_string_to_utf8(
            env, static_cast<jstring>(env->GetObjectField(config_obj, f_target)));
        g_adreno_uaf_alpha_cfg->list_node_insert_symbol = convert_java_string_to_utf8(
            env, static_cast<jstring>(env->GetObjectField(config_obj, f_insert)));
        g_adreno_uaf_alpha_cfg->find_or_insert_symbol = convert_java_string_to_utf8(
            env, static_cast<jstring>(env->GetObjectField(config_obj, f_find)));
        return 0;
    }

    if (g_adreno_uaf_beta_cfg == nullptr) {
        g_adreno_uaf_beta_cfg = new AdrenoUafBetaConfig{};
    }
    jfieldID f_target = env->GetFieldID(cls, "targetSymbol", "Ljava/lang/String;");
    g_adreno_uaf_beta_cfg->target_symbol = convert_java_string_to_utf8(
        env, static_cast<jstring>(env->GetObjectField(config_obj, f_target)));
    return 0;
}

}  // namespace touphic
}  // namespace godzilla
}  // namespace platform
}  // namespace bytedance
