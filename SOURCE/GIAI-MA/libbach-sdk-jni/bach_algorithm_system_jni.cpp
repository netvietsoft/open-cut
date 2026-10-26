/**
 * @file bach_algorithm_system_jni.cpp
 * @brief Implementation of .init_array[0], BachAlgorithmSystemImpl, and all 10 BachAlgorithmSystem / BachBitmapHandle
 *        Exported JNI Functions for libbach-sdk-jni.so.
 *        Cài đặt chi tiết .init_array[0], BachAlgorithmSystemImpl và 10 hàm JNI xuất khẩu của
 *        BachAlgorithmSystem / BachBitmapHandle cho libbach-sdk-jni.so.
 *
 * Target Binary / Nhị phân mục tiêu:
 *   - File: libbach-sdk-jni.so (117,112 bytes)
 *   - SHA-256: 6330cb09b6721ef41639c6ed472b4d60e3b81a9f03c699f5d8c1cbefe5804929
 */

#include "bach_algorithm_system_jni.h"

#include <cstring>
#include <mutex>

namespace com {
namespace bytedance {
namespace bach_sdk {

// ============================================================================
// 1. .init_array[0] (`0x003820..0x0038f4`): Global 39-Element Result Type Set
//    Khởi tạo tập hợp 39 mã loại kết quả toàn cục tại `.bss 0x020010` [OBSERVED]
// ============================================================================

namespace {

std::unordered_set<int32_t> BuildDirectBufferResultTypeSet() {
    // [OBSERVED at 0x003820..0x0038f4 (_GLOBAL__sub_I_BachAlgorithmSystemJNI.cpp)]:
    //   0x003848: mov w8, #0x3f800000 (1.0f)
    //   0x003854: str w8, [x19, #0x20] (max_load_factor = 1.0f at .bss 0x020030)
    //   0x003890: ldr w8, [x22, x21]   (reads int32_t from .rodata 0x014f98 + offset)
    //   0x003898: bl 0x006560          (__hash_table::__emplace_unique_key_args<int, const int&>)
    //   0x0038a0: add x21, x21, #4; cmp x21, #0x9c; b.ne 0x003890 (39 elements = 156 bytes)
    std::unordered_set<int32_t> s;
    s.max_load_factor(1.0f);
    for (size_t i = 0; i < 39U; ++i) {
        s.insert(kBachDirectBufferResultTypes[i]);
    }
    return s;
}

} // namespace

const std::unordered_set<int32_t>& GetGlobalDirectBufferResultTypes() {
    static const std::unordered_set<int32_t> kGlobalResultTypes = BuildDirectBufferResultTypeSet();
    return kGlobalResultTypes;
}

bool IsDirectBufferResultType(int32_t result_type) {
    // [OBSERVED at 0x005ca8..0x005d5c]:
    //   Checks if `result_type` is in `.bss 0x020010` using NEON popcount bucket mask (`0x005cc8`)
    const auto& global_set = GetGlobalDirectBufferResultTypes();
    return global_set.find(result_type) != global_set.end();
}

// ============================================================================
// 2. Concrete Implementation of `Bach::BachAlgorithmFactory` & `ToGeneralBuffer`
//    Cài đặt chi tiết `Bach::BachAlgorithmFactory` & `Bach::ToGeneralBuffer` [OBSERVED]
// ============================================================================

BachAlgorithmSystemImpl::BachAlgorithmSystemImpl() = default;

BachAlgorithmSystemImpl::~BachAlgorithmSystemImpl() noexcept {
    for (auto& kv : outputs_) {
        if (kv.second != nullptr) {
            kv.second->release();
        }
    }
    outputs_.clear();
}

int BachAlgorithmSystemImpl::init(const Bach::BachSystemInitConfig& config) {
    init_config_ = config;
    return 0;
}

int BachAlgorithmSystemImpl::initGraph(const std::string& config_path) {
    if (config_path.empty()) {
        return -1;
    }
    graph_config_path_ = config_path;
    return 0;
}

int BachAlgorithmSystemImpl::exec(Bach::BachAlgorithmInput* input) {
    if (input == nullptr) {
        return -1;
    }
    if (auto* img = dynamic_cast<Bach::BachImageBuffer*>(input)) {
        last_input_width_ = img->width();
        last_input_height_ = img->height();
        return 0;
    }
    if (auto* multi = dynamic_cast<Bach::BachMultiInput*>(input)) {
        for (const auto& kv : multi->inputs()) {
            if (kv.second != nullptr) {
                last_input_width_ = kv.second->width();
                last_input_height_ = kv.second->height();
            }
        }
        return 0;
    }
    return 0;
}

int BachAlgorithmSystemImpl::setEnable(const std::string& algorithm_name, bool enable) {
    enabled_algorithms_[algorithm_name] = enable;
    return 0;
}

int BachAlgorithmSystemImpl::setIntParams(
    const std::string& algorithm_name,
    const std::unordered_map<std::string, int64_t>& params) {
    auto& dst = int_params_[algorithm_name];
    for (const auto& kv : params) {
        dst[kv.first] = kv.second;
    }
    return 0;
}

int BachAlgorithmSystemImpl::setFloatParams(
    const std::string& algorithm_name,
    const std::unordered_map<std::string, float>& params) {
    auto& dst = float_params_[algorithm_name];
    for (const auto& kv : params) {
        dst[kv.first] = kv.second;
    }
    return 0;
}

int BachAlgorithmSystemImpl::setStringParams(
    const std::string& algorithm_name,
    const std::unordered_map<std::string, std::string>& params) {
    auto& dst = string_params_[algorithm_name];
    for (const auto& kv : params) {
        dst[kv.first] = kv.second;
    }
    return 0;
}

Bach::BachAlgorithmOutput* BachAlgorithmSystemImpl::getResult(
    const std::string& algorithm_name, int32_t index) {
    const std::string key = algorithm_name + "#" + std::to_string(index);
    auto it = outputs_.find(key);
    if (it != outputs_.end()) {
        return it->second;
    }
    auto it_base = outputs_.find(algorithm_name);
    if (it_base != outputs_.end()) {
        return it_base->second;
    }
    return nullptr;
}

bool BachAlgorithmSystemImpl::is_enabled(const std::string& name) const {
    auto it = enabled_algorithms_.find(name);
    return it != enabled_algorithms_.end() ? it->second : false;
}

void BachAlgorithmSystemImpl::RegisterMockOutput(
    const std::string& algorithm_name,
    int32_t index,
    Bach::BachAlgorithmOutput* output) {
    const std::string key = algorithm_name + "#" + std::to_string(index);
    auto it = outputs_.find(key);
    if (it != outputs_.end() && it->second != output) {
        if (it->second != nullptr) {
            it->second->release();
        }
    }
    if (output != nullptr) {
        output->retain();
    }
    outputs_[key] = output;
}

namespace Bach {

BachAlgorithmSystem* BachAlgorithmFactory::CreateAlgorithmSystem() {
    // [OBSERVED at 0x003a2c: bl _ZN4Bach20BachAlgorithmFactory21CreateAlgorithmSystemEv]
    return new BachAlgorithmSystemImpl();
}

int BachAlgorithmFactory::DestroyAlgorithmSystem(BachAlgorithmSystem* system) {
    // [OBSERVED at 0x005184: bl _ZN4Bach20BachAlgorithmFactory22DestroyAlgorithmSystemEPNS_19BachAlgorithmSystemE]
    if (system == nullptr) {
        return -1;
    }
    system->release();
    return 0;
}

void ToGeneralBuffer(const BachAlgorithmOutput* output, BachBuffer* out_buffer) {
    // [OBSERVED at 0x005da8: bl _ZN4Bach15ToGeneralBufferEPKNS_19BachAlgorithmOutputEPNS_10BachBufferE]
    if (output == nullptr || out_buffer == nullptr) {
        return;
    }
    out_buffer->set_type(output->getResultType());
    for (auto* existing : out_buffer->maps()) {
        if (existing != nullptr) {
            existing->release();
        }
    }
    out_buffer->maps().clear();
    for (const auto* src_map : output->buffer().maps()) {
        if (src_map != nullptr) {
            auto* cloned_map = new BachMap();
            cloned_map->map() = src_map->map();
            out_buffer->maps().push_back(cloned_map);
        } else {
            out_buffer->maps().push_back(nullptr);
        }
    }
}

} // namespace Bach

// ============================================================================
// 3. Implementation of BachAlgorithmSystem Native Bridge Functions
//    Cài đặt chi tiết các hàm cầu nối Native của BachAlgorithmSystem [OBSERVED]
// ============================================================================

int64_t NativeCreateBachAlgorithmSystem(int32_t finder_type,
                                        int64_t resource_finder_ptr,
                                        const std::string& application_name,
                                        const std::string& device_name) {
    // [OBSERVED at 0x0039c4..0x003bfb]:
    //   1. Calls BachAlgorithmFactory::CreateAlgorithmSystem() (`0x003a2c`).
    //   2. Checks `finder_type`:
    //      - If `finder_type == 1` (`0x003a40: cmp w24, #1`): uses `resource_finder_ptr`
    //      - If `finder_type == 2` (`0x003a38: cmp w24, #2`): uses `resource_finder_ptr`
    //      - Otherwise returns 0 (`0x003af0: mov x20, xzr; b 0x003bc8`)
    //   3. Populates 64-byte `BachSystemInitConfig` on stack (`sp+0x50..sp+0x8f`):
    //      `struct_type = 1`, `resource_finder = resource_finder_ptr`, `application_name`, `device_name`.
    //   4. Calls `system->init(config)` via vtable `+0x10` (`0x003b30: ldr x8, [x8, #0x10]; blr x8`).
    Bach::BachAlgorithmSystem* system = Bach::BachAlgorithmFactory::CreateAlgorithmSystem();
    if (finder_type != 1 && finder_type != 2) {
        if (system != nullptr) {
            Bach::BachAlgorithmFactory::DestroyAlgorithmSystem(system);
        }
        return 0;
    }
    if (system == nullptr) {
        return 0;
    }

    Bach::BachSystemInitConfig config;
    config.struct_type = 1;
    config.resource_finder = resource_finder_ptr;
    config.application_name = application_name;
    config.device_name = device_name;
    system->init(config);
    return reinterpret_cast<int64_t>(system);
}

int32_t NativeInitGraphBachAlgorithmSystem(int64_t system_ptr, const std::string& config_path) {
    // [OBSERVED at 0x003bfc..0x003c8b]:
    //   Checks `system_ptr != 0` (`0x003c14: cbz x20, #0x3c60` -> returns -1 = `0xffffffff`).
    //   Calls `system->initGraph(config_path)` via vtable `+0x18` (`0x003c38: ldr x8, [x8, #0x18]; blr x8`).
    if (system_ptr == 0) {
        return -1;
    }
    auto* system = reinterpret_cast<Bach::BachAlgorithmSystem*>(system_ptr);
    return system->initGraph(config_path);
}

int32_t NativeSetEnableBachAlgorithmSystem(int64_t system_ptr,
                                           const std::string& algorithm_name,
                                           bool enable) {
    // [OBSERVED at 0x003c8c..0x003d77]:
    //   Checks `system_ptr != 0` (`0x003cb0: cbz x21, #0x3d44` -> returns -1).
    //   Calls `system->setEnable(algorithm_name, enable != 0)` via vtable `+0x40` (`0x003cfc: ldr x8, [x8, #0x40]`).
    if (system_ptr == 0) {
        return -1;
    }
    auto* system = reinterpret_cast<Bach::BachAlgorithmSystem*>(system_ptr);
    return system->setEnable(algorithm_name, enable);
}

int32_t NativeSetIntParamsBachAlgorithmSystem(
    int64_t system_ptr,
    const std::string& algorithm_name,
    const std::unordered_map<std::string, int64_t>& params) {
    // [OBSERVED at 0x003d78..0x0044e3]:
    //   Checks `system_ptr != 0` (`0x003da4: cbz x22, #0x4168` -> returns -1).
    //   Iterates Java HashMap<String, Integer>, widening each `intValue()I` (`0x0040bc: sxtw x8, w0`)
    //   to `int64_t` in `std::unordered_map<std::string, int64_t>` (`max_load_factor = 1.0f` @ `sp+0x68`),
    //   then invokes `system->setIntParams(algorithm_name, map)` via vtable `+0x60` (`0x004194`).
    if (system_ptr == 0) {
        return -1;
    }
    auto* system = reinterpret_cast<Bach::BachAlgorithmSystem*>(system_ptr);
    return system->setIntParams(algorithm_name, params);
}

int32_t NativeSetFloatParamsBachAlgorithmSystem(
    int64_t system_ptr,
    const std::string& algorithm_name,
    const std::unordered_map<std::string, float>& params) {
    // [OBSERVED at 0x0044e4..0x004b1b]:
    //   Checks `system_ptr != 0` (`0x004510: cbz x22, #0x48d4` -> returns -1).
    //   Iterates Java HashMap<String, Float>, storing `floatValue()F` (`0x00483c: str s0, [x0, #0x28]`)
    //   into `std::unordered_map<std::string, float>`, then invokes `system->setFloatParams` via vtable `+0x68` (`0x004900`).
    if (system_ptr == 0) {
        return -1;
    }
    auto* system = reinterpret_cast<Bach::BachAlgorithmSystem*>(system_ptr);
    return system->setFloatParams(algorithm_name, params);
}

int32_t NativeSetStringParamsBachAlgorithmSystem(
    int64_t system_ptr,
    const std::string& algorithm_name,
    const std::unordered_map<std::string, std::string>& params) {
    // [OBSERVED at 0x004b1c..0x00515b]:
    //   Checks `system_ptr != 0` (`0x004b48: cbz x22, #0x4f60` -> returns -1).
    //   Iterates Java HashMap<String, String>, converting key and value via `jstringToStdString` (`0x010464`),
    //   then invokes `system->setStringParams` via vtable `+0x70` (`0x004f8c`).
    if (system_ptr == 0) {
        return -1;
    }
    auto* system = reinterpret_cast<Bach::BachAlgorithmSystem*>(system_ptr);
    return system->setStringParams(algorithm_name, params);
}

int32_t NativeDestroyBachAlgorithmSystem(int64_t system_ptr) {
    // [OBSERVED at 0x00515c..0x00519b]:
    //   Checks `system_ptr != 0` (`0x005168: cbz x2, #0x5178` -> returns -1).
    //   Calls `BachAlgorithmFactory::DestroyAlgorithmSystem(system)` (`0x005184`).
    if (system_ptr == 0) {
        return -1;
    }
    auto* system = reinterpret_cast<Bach::BachAlgorithmSystem*>(system_ptr);
    return Bach::BachAlgorithmFactory::DestroyAlgorithmSystem(system);
}

namespace {

Bach::BachImageBuffer* CreateBachImageBufferFromAndroidBitmap(
    int32_t width,
    int32_t height,
    int32_t android_bitmap_format,
    const uint8_t* pixels,
    size_t pixel_byte_count) {
    // [OBSERVED at 0x0053d0..0x00547c]:
    //   - AndroidBitmapFormat == 1 (`ANDROID_BITMAP_FORMAT_RGBA_8888`):
    //     `format = kRGBA8888 (3)`, `channels = 4`, `stride = width << 2` (`0x005418..0x00542c`)
    //   - AndroidBitmapFormat == 8 (`ANDROID_BITMAP_FORMAT_A_8`):
    //     `format = kGray8 (0)`, `channels = 1`, `stride = width` (`0x005434..0x005444`)
    //   - Otherwise returns nullptr (`0x0054d8: mov w20, #-1`).
    Bach::BachPixelFormat fmt = Bach::BachPixelFormat::kRGBA8888;
    int32_t channels = 4;
    int32_t stride = width * 4;
    if (android_bitmap_format == 1) {
        fmt = Bach::BachPixelFormat::kRGBA8888;
        channels = 4;
        stride = width << 2;
    } else if (android_bitmap_format == 8) {
        fmt = Bach::BachPixelFormat::kGray8;
        channels = 1;
        stride = width;
    } else {
        return nullptr;
    }

    const size_t expected_bytes = static_cast<size_t>(stride) * static_cast<size_t>(height);
    std::vector<uint8_t> raw_bytes(expected_bytes, 0U);
    if (pixels != nullptr && pixel_byte_count > 0U) {
        const size_t copy_len = pixel_byte_count < expected_bytes ? pixel_byte_count : expected_bytes;
        std::memcpy(raw_bytes.data(), pixels, copy_len);
    }

    auto* prim_vec = new AmazingEngine::PrimitiveVector<uint8_t>(std::move(raw_bytes));
    auto* img = new Bach::BachImageBuffer();
    img->set_input_type(1);
    img->set_width(width);
    img->set_height(height);
    img->set_channels(channels);
    img->set_stride(stride);
    img->set_input_data(prim_vec);
    img->set_input_format(fmt);
    return img;
}

} // namespace

int32_t NativeExecBitmapInput(int64_t system_ptr,
                              int32_t width,
                              int32_t height,
                              int32_t android_bitmap_format,
                              const uint8_t* pixels,
                              size_t pixel_byte_count) {
    // [OBSERVED at 0x00519c..0x0054dc]:
    //   Dispatches when `input.getInputType() == 1` (`0x00523c: cmp w0, #1; b.eq #0x52b8`).
    //   Constructs 56-byte `BachImageBuffer` (`0x0053e0: mov w0, #0x38; bl operator new`),
    //   calls `system->exec(img)` via vtable `+0x28` (`0x005484: ldr x8, [x8, #0x28]`),
    //   and releases `img` (`0x005494..0x00549c`).
    if (system_ptr == 0 || width <= 0 || height <= 0) {
        return -1;
    }
    auto* system = reinterpret_cast<Bach::BachAlgorithmSystem*>(system_ptr);
    Bach::BachImageBuffer* img = CreateBachImageBufferFromAndroidBitmap(
        width, height, android_bitmap_format, pixels, pixel_byte_count);
    if (img == nullptr) {
        return -1;
    }
    const int32_t rc = system->exec(img);
    img->release();
    return rc;
}

int32_t NativeExecMultiInput(int64_t system_ptr,
                             const std::vector<NamedBitmapInputSlice>& slices) {
    // [OBSERVED at 0x005230..0x005b50]:
    //   Dispatches when `input.getInputType() == 3` (`0x005234: cmp w0, #3; b.ne #0x54d8`).
    //   Iterates `BachMultiInput.m_inputs` (`HashMap<String, BachAlgorithmInput>`), converts each
    //   `BachBitmapInput` into a `BachImageBuffer*`, inserts into `BachMultiInput` (`sp+0x58`),
    //   and invokes `system->exec(&multi_input)` via vtable `+0x28` (`0x005a30: ldr x8, [x8, #0x28]`).
    if (system_ptr == 0) {
        return -1;
    }
    auto* system = reinterpret_cast<Bach::BachAlgorithmSystem*>(system_ptr);
    Bach::BachMultiInput multi_input;
    for (const auto& s : slices) {
        if (s.width <= 0 || s.height <= 0) {
            return -1;
        }
        Bach::BachImageBuffer* img = CreateBachImageBufferFromAndroidBitmap(
            s.width, s.height, s.android_bitmap_format, s.pixels.data(), s.pixels.size());
        if (img == nullptr) {
            return -1;
        }
        auto it = multi_input.inputs().find(s.name);
        if (it != multi_input.inputs().end() && it->second != nullptr) {
            it->second->release();
        }
        multi_input.inputs()[s.name] = img;
    }
    return system->exec(&multi_input);
}

std::shared_ptr<JavaAlgorithmOutputPackage> NativeGetResultBachAlgorithmSystem(
    int64_t system_ptr,
    const std::string& algorithm_name,
    int32_t index) {
    // [OBSERVED at 0x005c14..0x0061e0]:
    //   1. Checks `system_ptr != 0` (`0x005c38: cbz x22, #0x604c` -> returns nullptr).
    //   2. Calls `output = system->getResult(algorithm_name, index)` via vtable `+0x78` (`0x005c60`).
    //   3. If `output == nullptr`, returns nullptr (`0x005c78: cbz x21, #0x604c`).
    //   4. Calls `type = output->getResultType()` via vtable `+0x28` (`0x005ca0: ldr x8, [x8, #0x28]`).
    //   5. Looks up `type` in `.bss 0x020010` (`0x005ca8..0x005d5c`):
    //      - If found (`IsDirectBufferResultType(type)`): copies `output->buffer()` directly (`0x005d60..0x005d8c`)
    //      - Otherwise: calls `Bach::ToGeneralBuffer(output, &local_buffer)` (`0x005da8`)
    //   6. Releases `output` (`0x005db4: ldr x8, [x8, #8]; blr x8`).
    //   7. Converts each `BachMap*` in `local_buffer.maps()` (`+0x18..+0x20`) into a `HashMap<String, BachObject>`
    //      by calling `convertBachObjectToJava` (`0x005f04: bl #0x702c`).
    //   8. Selects the Java output subclass based on `local_buffer.type()` (`+0x10` @ `0x005fec..0x006024`):
    //      - `type == 8`  -> `com/bytedance/byted_bach_sdk/output/BachFaceAlgorithmOutput` (`.rodata 0x015111`)
    //      - `type == 13` -> `com/bytedance/byted_bach_sdk/output/BachExpressionDetectAlgorithmOutput` (`.rodata 0x0150bd`)
    //      - default      -> `com/bytedance/byted_bach_sdk/output/BachAlgorithmOutput` (`.rodata 0x0150fc`)
    if (system_ptr == 0) {
        return nullptr;
    }
    auto* system = reinterpret_cast<Bach::BachAlgorithmSystem*>(system_ptr);
    Bach::BachAlgorithmOutput* output = system->getResult(algorithm_name, index);
    if (output == nullptr) {
        return nullptr;
    }

    const int32_t rtype = output->getResultType();
    const bool is_direct = IsDirectBufferResultType(rtype);

    Bach::BachBuffer local_buffer;
    if (is_direct) {
        local_buffer.set_type(output->buffer().type() != 0 ? output->buffer().type() : rtype);
        for (auto* m : output->buffer().maps()) {
            if (m != nullptr) {
                m->retain();
            }
            local_buffer.maps().push_back(m);
        }
    } else {
        Bach::ToGeneralBuffer(output, &local_buffer);
    }

    auto pkg = std::make_shared<JavaAlgorithmOutputPackage>();
    pkg->result_type = local_buffer.type();
    pkg->used_direct_buffer = is_direct;

    if (pkg->result_type == 8) {
        pkg->output_class = JavaOutputClassKind::kFaceAlgorithmOutput;
    } else if (pkg->result_type == 13) {
        pkg->output_class = JavaOutputClassKind::kExpressionDetectAlgorithmOutput;
    } else {
        pkg->output_class = JavaOutputClassKind::kGenericBachAlgorithmOutput;
    }

    for (const Bach::BachMap* bmap : local_buffer.maps()) {
        std::unordered_map<std::string, std::shared_ptr<JavaBachObject>> jmap;
        if (bmap != nullptr) {
            for (const auto& kv : bmap->map()) {
                jmap[kv.first] = ConvertBachObjectToJava(kv.second);
            }
        }
        pkg->result_maps.push_back(std::move(jmap));
    }

    return pkg;
}

} // namespace bach_sdk
} // namespace bytedance
} // namespace com

// ============================================================================
// 4. Exported JNI C Symbols (.dynsym [093], [095..097], [099], [104..106], [109..110])
//    10 biểu tượng hàm JNI xuất khẩu trong .dynsym [OBSERVED]
// ============================================================================

extern "C" {

// [095] 0x0039c4: Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeCreate
int64_t Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeCreate(
    void* /*env*/,
    void* /*thiz*/,
    int32_t finder_type,
    int64_t resource_finder_ptr,
    const char* application_name,
    const char* device_name) {
    return com::bytedance::bach_sdk::NativeCreateBachAlgorithmSystem(
        finder_type,
        resource_finder_ptr,
        application_name ? application_name : "",
        device_name ? device_name : "");
}

// [109] 0x003bfc: Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeInitGraph
int32_t Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeInitGraph(
    void* /*env*/,
    void* /*thiz*/,
    int64_t system_ptr,
    const char* config_path) {
    return com::bytedance::bach_sdk::NativeInitGraphBachAlgorithmSystem(
        system_ptr, config_path ? config_path : "");
}

// [093] 0x003c8c: Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeSetEnable
int32_t Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeSetEnable(
    void* /*env*/,
    void* /*thiz*/,
    int64_t system_ptr,
    const char* algorithm_name,
    uint8_t enable) {
    return com::bytedance::bach_sdk::NativeSetEnableBachAlgorithmSystem(
        system_ptr, algorithm_name ? algorithm_name : "", enable != 0U);
}

// [106] 0x003d78: Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeSetIntParams
int32_t Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeSetIntParams(
    void* /*env*/,
    void* /*thiz*/,
    int64_t system_ptr,
    const char* algorithm_name,
    const std::unordered_map<std::string, int64_t>* params) {
    static const std::unordered_map<std::string, int64_t> kEmpty;
    return com::bytedance::bach_sdk::NativeSetIntParamsBachAlgorithmSystem(
        system_ptr, algorithm_name ? algorithm_name : "", params ? *params : kEmpty);
}

// [105] 0x0044e4: Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeSetFloatParams
int32_t Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeSetFloatParams(
    void* /*env*/,
    void* /*thiz*/,
    int64_t system_ptr,
    const char* algorithm_name,
    const std::unordered_map<std::string, float>* params) {
    static const std::unordered_map<std::string, float> kEmpty;
    return com::bytedance::bach_sdk::NativeSetFloatParamsBachAlgorithmSystem(
        system_ptr, algorithm_name ? algorithm_name : "", params ? *params : kEmpty);
}

// [097] 0x004b1c: Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeSetStringParams
int32_t Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeSetStringParams(
    void* /*env*/,
    void* /*thiz*/,
    int64_t system_ptr,
    const char* algorithm_name,
    const std::unordered_map<std::string, std::string>* params) {
    static const std::unordered_map<std::string, std::string> kEmpty;
    return com::bytedance::bach_sdk::NativeSetStringParamsBachAlgorithmSystem(
        system_ptr, algorithm_name ? algorithm_name : "", params ? *params : kEmpty);
}

// [104] 0x00515c: Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeDestroy
int32_t Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeDestroy(
    void* /*env*/,
    void* /*thiz*/,
    int64_t system_ptr) {
    return com::bytedance::bach_sdk::NativeDestroyBachAlgorithmSystem(system_ptr);
}

// [099] 0x00519c: Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeExec
int32_t Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeExec(
    void* /*env*/,
    void* /*thiz*/,
    int64_t system_ptr,
    int32_t input_type,
    int32_t width,
    int32_t height,
    int32_t android_bitmap_format,
    const uint8_t* pixels,
    size_t pixel_byte_count) {
    if (input_type == 1) {
        return com::bytedance::bach_sdk::NativeExecBitmapInput(
            system_ptr, width, height, android_bitmap_format, pixels, pixel_byte_count);
    }
    return -1;
}

// [096] 0x005c14: Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeGetResult
void* Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeGetResult(
    void* /*env*/,
    void* /*thiz*/,
    int64_t system_ptr,
    const char* algorithm_name,
    int32_t index) {
    auto pkg = com::bytedance::bach_sdk::NativeGetResultBachAlgorithmSystem(
        system_ptr, algorithm_name ? algorithm_name : "", index);
    if (!pkg) {
        return nullptr;
    }
    return new std::shared_ptr<com::bytedance::bach_sdk::JavaAlgorithmOutputPackage>(std::move(pkg));
}

// [110] 0x00eb38: Java_com_bytedance_byted_1bach_1sdk_buffer_BachBitmapHandle_nativeGet
void* Java_com_bytedance_byted_1bach_1sdk_buffer_BachBitmapHandle_nativeGet(
    void* /*env*/,
    void* /*thiz*/,
    int64_t bitmap_handle_ptr) {
    const auto* handle = reinterpret_cast<const com::bytedance::bach_sdk::Bach::BachImageBuffer*>(bitmap_handle_ptr);
    auto out_rgba = std::make_unique<std::vector<uint8_t>>();
    int32_t w = 0;
    int32_t h = 0;
    if (!com::bytedance::bach_sdk::ExtractBachBitmapHandleToRGBA8888(handle, out_rgba.get(), &w, &h)) {
        return nullptr;
    }
    return out_rgba.release();
}

} // extern "C"
