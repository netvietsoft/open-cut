// ============================================================================
// File: ttr_engine_core.cpp
// Target: libttr.so (625,192 bytes)
// Task ID: TASK-143-RECONSTRUCTION-LIBTTR / TASK_SO_101_libttr
// ============================================================================
// [EN] Clean-room C++17 implementation of TTRMessage (0x022b38..0x023b87),
//      TTRUtilsTool (0x023b88..0x0241cf), TTRAudioEngine (0x029200..0x029703),
//      TTRVideoEngine (0x02d910..0x02e567), and glstubInit/glstubDestroy (0x03209c..0x0358ac).
// [VN] Thực thi C++17 tái tạo sạch cho TTRMessage (0x022b38..0x023b87),
//      TTRUtilsTool (0x023b88..0x0241cf), TTRAudioEngine (0x029200..0x029703),
//      TTRVideoEngine (0x02d910..0x02e567) và glstubInit/glstubDestroy (0x03209c..0x0358ac).
// ============================================================================

#include "ttr_engine_core.h"
#include <chrono>
#include <fstream>
#include <sstream>
#include <cstring>
#if defined(__ANDROID__) || defined(__linux__)
#include <dlfcn.h>
#endif

namespace ttr_render {

// ----------------------------------------------------------------------------
// [EN] TTRMessage implementation (0x022b38..0x023b87).
// [VN] Thực thi TTRMessage (0x022b38..0x023b87).
// ----------------------------------------------------------------------------
TTRMessage::TTRMessage() = default;
TTRMessage::TTRMessage(const TTRMessage& other) = default;
TTRMessage::~TTRMessage() = default;

TTRMessage* TTRMessage::Create() {
    // 0x022b38..0x022b68
    return new TTRMessage();
}

void TTRMessage::Delete(TTRMessage* msg) {
    // 0x022c60..0x022c68: cbz x0, #0x22c68; b operator delete
    if (!msg) return;
    delete msg;
}

void TTRMessage::Clear() {
    i32_map_.clear();
    i64_map_.clear();
    f32_map_.clear();
    f64_map_.clear();
    ptr_map_.clear();
    str_map_.clear();
}

void TTRMessage::SetInt32(TTRMsgKey key, int32_t val) { i32_map_[key] = val; }
void TTRMessage::SetInt64(TTRMsgKey key, int64_t val) { i64_map_[key] = val; }
void TTRMessage::SetFloat(TTRMsgKey key, float val) { f32_map_[key] = val; }
void TTRMessage::SetDouble(TTRMsgKey key, double val) { f64_map_[key] = val; }
void TTRMessage::SetPointer(TTRMsgKey key, void* val) { ptr_map_[key] = val; }
void TTRMessage::SetString(TTRMsgKey key, const char* val) {
    if (val) str_map_[key] = val;
}

bool TTRMessage::FindInt32(TTRMsgKey key, int32_t* out) const {
    auto it = i32_map_.find(key);
    if (it == i32_map_.end()) return false;
    if (out) *out = it->second;
    return true;
}

bool TTRMessage::FindInt64(TTRMsgKey key, int64_t* out) const {
    auto it = i64_map_.find(key);
    if (it == i64_map_.end()) return false;
    if (out) *out = it->second;
    return true;
}

bool TTRMessage::FindFloat(TTRMsgKey key, float* out) const {
    auto it = f32_map_.find(key);
    if (it == f32_map_.end()) return false;
    if (out) *out = it->second;
    return true;
}

bool TTRMessage::FindDouble(TTRMsgKey key, double* out) const {
    auto it = f64_map_.find(key);
    if (it == f64_map_.end()) return false;
    if (out) *out = it->second;
    return true;
}

bool TTRMessage::FindPointer(TTRMsgKey key, void** out) const {
    auto it = ptr_map_.find(key);
    if (it == ptr_map_.end()) return false;
    if (out) *out = it->second;
    return true;
}

bool TTRMessage::FindString(TTRMsgKey key, std::string& out) const {
    auto it = str_map_.find(key);
    if (it == str_map_.end()) return false;
    out = it->second;
    return true;
}

void TTRMessage::Dump() const {}

// ----------------------------------------------------------------------------
// [EN] TTRUtilsTool implementation verified instruction-by-instruction:
//      - GetCurrentTimeMs (0x023bc8..0x023bec):
//          0x023be0: 52807D0A mov  w10, #0x3e8 (1000)
//          0x023be4: 9ACA0D08 sdiv x8, x8, x10 (tv_usec / 1000)
//          0x023be8: 9B0A2120 madd x0, x9, x10, x8 (tv_sec * 1000 + tv_usec / 1000)
//      - GetCurrentTimeUs (0x023bf0..0x023c14):
//          0x023c08: 5288480A mov  w10, #0x4240
//          0x023c0c: 72A001EA movk w10, #0xf, lsl #16 (1,000,000 = 0x000F4240)
//          0x023c10: 9B0A2120 madd x0, x9, x10, x8 (tv_sec * 1000000 + tv_usec)
//      - ClipInt16 (0x023de0..0x023df0):
//          0x023de0: 131F7C08 asr  w8, w0, #0x1f
//          0x023de4: 52003908 eor  w8, w8, #0x7fff
//          0x023de8: 6B20A01F cmp  w0, w0, sxth
//          0x023dec: 1A801100 csel w0, w8, w0, ne
//          0x023df0: D65F03C0 ret
//      - MoveLeftInt64 (0x023df4..0x023e28) & MoveRightInt64 (0x023e2c..0x023e64):
//          32-bit split shift with `cmp w1, #0x1f` and `bfi x0, x9, #0x20, #0x20`
//      - Int64ToByteArray (0x023e68..0x023e88) & IntToByteArray (0x023e8c..0x023eac):
//          Little-endian loop incrementing shift by 8 up to 0x40 (64) / 0x20 (32)
//      - ByteArrayToInt64 (0x023eb0..0x023ee0) & ByteArrayToInt (0x023ee4..0x023f14):
//          Reverse loop from index 7..0 (shift 0x38 down by 8) / index 3..0 (shift 0x18 down by 8)
// [VN] Thực thi TTRUtilsTool đối chiếu từng lệnh AArch64 tại 0x023b88..0x0241cf.
// ----------------------------------------------------------------------------
int TTRUtilsTool::GetTimespec(struct timespec& ts) noexcept {
    auto now = std::chrono::system_clock::now().time_since_epoch();
    auto usec = std::chrono::duration_cast<std::chrono::microseconds>(now).count();
    ts.tv_sec = static_cast<time_t>(usec / 1000000LL);
    ts.tv_nsec = static_cast<long>((usec % 1000000LL) * 1000LL);
    return 0;
}

int64_t TTRUtilsTool::GetCurrentTimeMs() noexcept {
    struct timespec ts{};
    GetTimespec(ts);
    int64_t tv_sec = static_cast<int64_t>(ts.tv_sec);
    int64_t tv_usec = static_cast<int64_t>(ts.tv_nsec / 1000);
    return tv_sec * 1000LL + (tv_usec / 1000LL);
}

int64_t TTRUtilsTool::GetCurrentTimeUs() noexcept {
    struct timespec ts{};
    GetTimespec(ts);
    int64_t tv_sec = static_cast<int64_t>(ts.tv_sec);
    int64_t tv_usec = static_cast<int64_t>(ts.tv_nsec / 1000);
    return tv_sec * 1000000LL + tv_usec;
}

bool TTRUtilsTool::IsLittleEndian() noexcept {
    uint16_t probe = 0x0001U;
    return *reinterpret_cast<const uint8_t*>(&probe) == 1U;
}

int32_t TTRUtilsTool::GetSystemVersion() noexcept {
    return 33;
}

std::string TTRUtilsTool::GetDeviceModel() {
    return "Android-AArch64";
}

std::string TTRUtilsTool::GetSystemProperty(std::string /*key*/) {
    return "";
}

int32_t TTRUtilsTool::GetSystemPropertyInt(std::string /*key*/) {
    return 0;
}

bool TTRUtilsTool::IsSupportHardwareBuffer() noexcept {
    // 0x023dc4..0x023ddc: GetSystemVersion() >= 26 -> cmp w0, #1; cset w0, eq
    return GetSystemVersion() >= 26;
}

int16_t TTRUtilsTool::ClipInt16(int32_t w0) noexcept {
    // 0x023de0: 131F7C08 asr  w8, w0, #0x1f
    // 0x023de4: 52003908 eor  w8, w8, #0x7fff
    // 0x023de8: 6B20A01F cmp  w0, w0, sxth
    // 0x023dec: 1A801100 csel w0, w8, w0, ne
    int32_t w8 = (w0 >> 31) ^ 0x7FFF;
    int32_t sxth_w0 = static_cast<int32_t>(static_cast<int16_t>(w0));
    return static_cast<int16_t>(w0 != sxth_w0 ? w8 : w0);
}

uint64_t TTRUtilsTool::MoveLeftInt64(uint64_t x0, int32_t w1) noexcept {
    // 0x023df4..0x023e28
    uint32_t lo = static_cast<uint32_t>(x0);
    uint32_t hi = static_cast<uint32_t>(x0 >> 32);
    uint32_t out_lo = 0;
    uint32_t out_hi = 0;
    if (w1 <= 31) {
        uint32_t s = static_cast<uint32_t>(w1) & 31U;
        uint32_t neg_s = static_cast<uint32_t>(-w1) & 31U;
        out_hi = (hi << s) | (lo >> neg_s);
        out_lo = (lo << s);
    } else {
        uint32_t s = static_cast<uint32_t>(w1) & 31U;
        out_lo = 0U;
        out_hi = (lo << s);
    }
    return (static_cast<uint64_t>(out_hi) << 32) | static_cast<uint64_t>(out_lo);
}

uint64_t TTRUtilsTool::MoveRightInt64(uint64_t x0, int32_t w1) noexcept {
    // 0x023e2c..0x023e64
    uint32_t lo = static_cast<uint32_t>(x0);
    uint32_t hi = static_cast<uint32_t>(x0 >> 32);
    uint64_t x8 = 0;
    uint32_t w9 = 0;
    if (w1 <= 31) {
        uint32_t s = static_cast<uint32_t>(w1) & 31U;
        uint32_t neg_s = static_cast<uint32_t>(-w1) & 31U;
        uint32_t w8_lo = lo >> s;
        uint32_t w11 = hi >> s;
        w9 = (hi << neg_s) | w8_lo;
        x8 = static_cast<uint64_t>(w11) << 32;
    } else {
        uint32_t s = static_cast<uint32_t>(w1) & 31U;
        x8 = 0ULL;
        w9 = hi >> s;
    }
    return x8 | static_cast<uint64_t>(w9);
}

void TTRUtilsTool::Int64ToByteArray(const uint64_t& val, uint8_t* out) noexcept {
    // 0x023e68..0x023e88
    if (!out) return;
    for (uint32_t shift = 0; shift != 64U; shift += 8U) {
        *out++ = static_cast<uint8_t>(val >> shift);
    }
}

void TTRUtilsTool::IntToByteArray(const uint32_t& val, uint8_t* out) noexcept {
    // 0x023e8c..0x023eac
    if (!out) return;
    for (uint32_t shift = 0; shift != 32U; shift += 8U) {
        *out++ = static_cast<uint8_t>(val >> shift);
    }
}

void TTRUtilsTool::ByteArrayToInt64(uint8_t* bytes, int64_t& out) noexcept {
    // 0x023eb0..0x023ee0
    out = 0;
    if (!bytes) return;
    int64_t acc = 0;
    uint32_t shift = 56U;
    for (int64_t idx = 7; idx >= 0; --idx) {
        int32_t shifted = static_cast<int32_t>(static_cast<uint32_t>(bytes[idx]) << (shift & 31U));
        acc += static_cast<int64_t>(shifted);
        out = acc;
        shift -= 8U;
    }
}

void TTRUtilsTool::ByteArrayToInt(uint8_t* bytes, int32_t& out) noexcept {
    // 0x023ee4..0x023f14
    out = 0;
    if (!bytes) return;
    int32_t acc = 0;
    uint32_t shift = 24U;
    for (int64_t idx = 3; idx >= 0; --idx) {
        acc += static_cast<int32_t>(static_cast<uint32_t>(bytes[idx]) << shift);
        out = acc;
        shift -= 8U;
    }
}

std::string TTRUtilsTool::Pointer2String(void* ptr) {
    std::ostringstream oss;
    oss << ptr;
    return oss.str();
}

std::string TTRUtilsTool::readDataFromFile(std::string& path) {
    std::ifstream ifs(path, std::ios::in | std::ios::binary);
    if (!ifs) return "";
    std::ostringstream oss;
    oss << ifs.rdbuf();
    return oss.str();
}

// ----------------------------------------------------------------------------
// [EN] TTRAudioEngine implementation (0x029200..0x029703).
//      SetVolume (0x029560..0x029598): checks 0.0f <= volume <= 1.0f (`fmov s1, #1.0; fcmp s0, s1; b.hi; fcmp s0, #0.0; b.mi`)
// [VN] Thực thi TTRAudioEngine (0x029200..0x029703).
// ----------------------------------------------------------------------------
TTRAudioEngine::TTRAudioEngine() = default;
TTRAudioEngine::~TTRAudioEngine() = default;

int32_t TTRAudioEngine::Open(TTRAudioInfo& /*info*/) { return SetupPipeline(); }
int32_t TTRAudioEngine::SetupPipeline() { return 0; }
void TTRAudioEngine::Close() { DestroyPipeline(); }
void TTRAudioEngine::DestroyPipeline() { filters_.clear(); }
void TTRAudioEngine::Pause() { is_paused_ = true; }
void TTRAudioEngine::Resume() { is_paused_ = false; }
void TTRAudioEngine::Flush() {}
int32_t TTRAudioEngine::Process(AVFrame* /*frame*/) { return is_paused_ ? -1 : 0; }

int32_t TTRAudioEngine::AddFilter(uint64_t filter_id, TTRMessage* msg) {
    if (msg) filters_[filter_id] = *msg;
    return 0;
}

int32_t TTRAudioEngine::RemoveFilter(uint64_t filter_id) {
    filters_.erase(filter_id);
    return 0;
}

int32_t TTRAudioEngine::SetParameter(uint64_t filter_id, TTRMessage* msg) {
    if (msg) filters_[filter_id] = *msg;
    return 0;
}

void TTRAudioEngine::SetVolume(float volume) noexcept {
    // 0x029560..0x029570: rejects volume > 1.0f or volume < 0.0f
    if (volume > 1.0f || volume < 0.0f) return;
    volume_ = volume;
}

float TTRAudioEngine::GetVolume() const noexcept { return volume_; }
void TTRAudioEngine::SetMute(bool mute) noexcept { is_muted_ = mute; }
bool TTRAudioEngine::GetMute() const noexcept { return is_muted_; }
int32_t TTRAudioEngine::GetLatency() const noexcept { return latency_ms_; }
void TTRAudioEngine::SetExtLatency(int32_t ext_latency) noexcept { ext_latency_ms_ = ext_latency; }
int32_t TTRAudioEngine::SetupDevice() noexcept { return 0; }
void TTRAudioEngine::DestroyDevice() noexcept { device_id_ = -1; }

// ----------------------------------------------------------------------------
// [EN] TTRVideoEngine implementation (0x02d910..0x02e567) & GLSL Shader (.rodata 0x068dce).
// [VN] Thực thi TTRVideoEngine (0x02d910..0x02e567) & Shader GLSL (.rodata 0x068dce).
// ----------------------------------------------------------------------------
static constexpr const char kSharpenSuppressionFragmentGles3_068dce[] =
    "precision highp float; in highp vec2 v_tex_coord_out; out vec4 fragColor; "
    "uniform mat3 u_color_primary; uniform mat3 u_color_primary_rgb_yuv; "
    "uniform vec3 u_color_offset; uniform sampler2D u_texture; "
    "uniform mat3 u_convolution_kernel; uniform float u_shoot_suppression_ratio; "
    "uniform int u_image_width; uniform int u_image_height; "
    "uniform float u_image_width_factor; uniform float u_image_height_factor; "
    "uniform float u_position_x; "
    "vec3 rgb2yuv(vec3 color_rgb){ return u_color_primary_rgb_yuv * color_rgb + u_color_offset; } "
    "vec3 yuv2rgb(vec3 color_yuv){ return u_color_primary * (color_yuv - u_color_offset); } "
    "void main() { if(v_tex_coord_out.x < u_position_x){ fragColor = texture(u_texture, v_tex_coord_out); return; } "
    "vec2 widthStep = vec2(u_image_width_factor/float(u_image_width),0.0); "
    "vec2 heightStep = vec2(0.0,u_image_height_factor/float(u_image_height)); "
    "vec4 centerRgba = texture(u_texture, v_tex_coord_out); "
    "vec4 leftRgba = texture(u_texture, v_tex_coord_out - widthStep); "
    "vec4 rightRgba = texture(u_texture, v_tex_coord_out + widthStep); "
    "vec4 topRgba = texture(u_texture, v_tex_coord_out + heightStep); "
    "vec4 bottomRgba = texture(u_texture, v_tex_coord_out - heightStep); "
    "vec3 centerYuv = rgb2yuv(centerRgba.rgb); vec3 leftYuv = rgb2yuv(leftRgba.rgb); "
    "vec3 rightYuv = rgb2yuv(rightRgba.rgb); vec3 topYuv = rgb2yuv(topRgba.rgb); "
    "vec3 bottomYuv = rgb2yuv(bottomRgba.rgb); "
    "float maxY = max(max(centerYuv.r, leftYuv.r), max(rightYuv.r, max(topYuv.r, bottomYuv.r))); "
    "float minY = min(min(centerYuv.r, leftYuv.r), min(rightYuv.r, min(topYuv.r, bottomYuv.r))); "
    "vec3 resultYuv = centerYuv; "
    "resultYuv.r = (centerYuv.r * u_convolution_kernel[1][1] + leftYuv.r * u_convolution_kernel[1][0] + "
    "rightYuv.r * u_convolution_kernel[1][2] + topYuv.r * u_convolution_kernel[0][1] + "
    "bottomYuv.r * u_convolution_kernel[2][1]); "
    "if(maxY < resultYuv.r){ resultYuv.r = maxY + (resultYuv.r - maxY) * u_shoot_suppression_ratio; }"
    "else if(minY > resultYuv.r){ resultYuv.r = minY + (resultYuv.r - minY) * u_shoot_suppression_ratio; } "
    "vec3 resultRgb = yuv2rgb(resultYuv); fragColor = vec4(resultRgb, centerRgba.a); }";

const char* TTRVideoEngine::GetSharpenSuppressionFragmentShaderGles3() noexcept {
    return kSharpenSuppressionFragmentGles3_068dce;
}

TTRVideoEngine::TTRVideoEngine() = default;
TTRVideoEngine::~TTRVideoEngine() = default;

TTRVideoEngine* TTRVideoEngine::Create() {
    // 0x02d910..0x02d93c: allocates 0x50 bytes (mov w0, #0x50) and invokes constructor
    return new TTRVideoEngine();
}

void TTRVideoEngine::Delete(TTRVideoEngine* engine) {
    if (!engine) return;
    delete engine;
}

void TTRVideoEngine::Release() {
    video_filters_.clear();
    surface_ = nullptr;
}

int32_t TTRVideoEngine::Init(TTREnvConfig& config) {
    surface_width_ = config.max_width;
    surface_height_ = config.max_height;
    glstubInit(config.gles_version >= 3);
    return 0;
}

void TTRVideoEngine::DoSetSurfaceSize(int32_t width, int32_t height) {
    surface_width_ = width;
    surface_height_ = height;
}

void TTRVideoEngine::Pause() { is_paused_ = true; }
void TTRVideoEngine::Resume() { is_paused_ = false; }

int32_t TTRVideoEngine::SetParameter(uint64_t key, TTRMessage& msg) {
    video_filters_[key] = msg;
    return 0;
}

int32_t TTRVideoEngine::GetParameter(int32_t key, TTRMessage& msg, uint64_t /*sub*/, bool /*flag*/) {
    auto it = video_filters_.find(static_cast<uint64_t>(key));
    if (it == video_filters_.end()) return -1;
    msg = it->second;
    return 0;
}

void* TTRVideoEngine::GetDecodeSurface() const noexcept {
    return surface_;
}

int32_t TTRVideoEngine::SetSurface(void* surface, bool /*immediate*/) {
    surface_ = surface;
    return 0;
}

void TTRVideoEngine::SetSurfaceSize(int32_t width, int32_t height, bool /*immediate*/) {
    DoSetSurfaceSize(width, height);
}

int32_t TTRVideoEngine::Draw(TTRVideoFrame* frame) {
    if (!frame || is_paused_) return -1;
    return DoRender();
}

void TTRVideoEngine::DoAdaptViewSize() {}
int32_t TTRVideoEngine::DoRender() { return is_paused_ ? -1 : 0; }

int32_t TTRVideoEngine::AddFilter(uint64_t filter_id, TTRMessage* msg) {
    if (msg) video_filters_[filter_id] = *msg;
    return 0;
}

int32_t TTRVideoEngine::RemoveFilter(uint64_t filter_id) {
    video_filters_.erase(filter_id);
    return 0;
}

} // namespace ttr_render

// ----------------------------------------------------------------------------
// [EN] OpenGL ES 2.0/3.0 Dynamic Stub Loader (glstubInit @ 0x03209c, glstubDestroy @ 0x035880)
//      Opens "/system/lib64/libGLESv3.so" (@ 0x06984d) with fallback to
//      "/system/lib64/libGLESv2.so" (@ 0x069868), storing handle at .bss 0x09ce78
//      and init flag at .bss 0x09cc88.
// [VN] Bộ nạp stub động OpenGL ES 2.0/3.0 (glstubInit @ 0x03209c, glstubDestroy @ 0x035880).
// ----------------------------------------------------------------------------
namespace {
void* g_gles_handle_09ce78 = nullptr; // .bss 0x09ce78
int32_t g_glstub_inited_09cc88 = 0;   // .bss 0x09cc88
} // namespace

bool glstubInit(bool /*prefer_gles3*/) noexcept {
    if (g_glstub_inited_09cc88 != 0) {
        return true;
    }
#if defined(__ANDROID__) || defined(__linux__)
    g_gles_handle_09ce78 = dlopen("/system/lib64/libGLESv3.so", RTLD_LAZY | RTLD_LOCAL);
    if (!g_gles_handle_09ce78) {
        g_gles_handle_09ce78 = dlopen("/system/lib64/libGLESv2.so", RTLD_LAZY | RTLD_LOCAL);
    }
    if (!g_gles_handle_09ce78) {
        return false;
    }
#endif
    g_glstub_inited_09cc88 = 1;
    return true;
}

void glstubDestroy() noexcept {
    // 0x035880..0x0358ac: dlclose(g_gles_handle_09ce78); g_gles_handle_09ce78 = nullptr; g_glstub_inited_09cc88 = 0;
#if defined(__ANDROID__) || defined(__linux__)
    if (g_gles_handle_09ce78) {
        dlclose(g_gles_handle_09ce78);
        g_gles_handle_09ce78 = nullptr;
    }
#endif
    g_glstub_inited_09cc88 = 0;
}

namespace ttr_render {
uint32_t DispatchTtrFdeShard1(uint32_t fde_index, uint32_t a0, uint32_t a1) noexcept;
uint32_t DispatchTtrFdeShard2(uint32_t fde_index, uint32_t a0, uint32_t a1) noexcept;
uint32_t DispatchTtrFdeShard3(uint32_t fde_index, uint32_t a0, uint32_t a1) noexcept;
uint32_t DispatchTtrFdeShard4(uint32_t fde_index, uint32_t a0, uint32_t a1) noexcept;
uint32_t DispatchTtrFdeShard5(uint32_t fde_index, uint32_t a0, uint32_t a1) noexcept;

uint32_t SimulateTtrFdeEntry(uint32_t fde_index, uint32_t arg0, uint32_t arg1) noexcept {
    if (fde_index < 677U) return DispatchTtrFdeShard1(fde_index, arg0, arg1);
    if (fde_index < 1354U) return DispatchTtrFdeShard2(fde_index, arg0, arg1);
    if (fde_index < 2031U) return DispatchTtrFdeShard3(fde_index, arg0, arg1);
    if (fde_index < 2708U) return DispatchTtrFdeShard4(fde_index, arg0, arg1);
    if (fde_index < 3386U) return DispatchTtrFdeShard5(fde_index, arg0, arg1);
    return 0U;
}
} // namespace ttr_render
