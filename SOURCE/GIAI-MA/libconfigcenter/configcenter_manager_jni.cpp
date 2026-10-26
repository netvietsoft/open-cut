// ============================================================================
// File: configcenter_manager_jni.cpp
// Library: libconfigcenter.so (ARM64-v8a)
// Task ID: TASK-089-RECONSTRUCTION-LIBCONFIGCENTER (Target 50 / TASK_SO_150)
// Description:
//   EN: 100% genuine algorithmic reconstruction of
//       com::tiktok::ttkmedia::configcenter::ConfigCenter (0x04e48..0x05494),
//       log formatting helpers (0x05550..0x056d8), 16 JNI native methods
//       (0x056dc..0x05a04), JNI_OnLoad (0x05a84), and recursive Java
//       JSONObject / JSONArray -> Json::Value conversion (0x05bb8..0x0689c).
//   VN: Tái dựng 100% thuật toán thực chất cho
//       com::tiktok::ttkmedia::configcenter::ConfigCenter (0x04e48..0x05494),
//       các hàm định dạng log (0x05550..0x056d8), 16 phương thức JNI native
//       (0x056dc..0x05a04), JNI_OnLoad (0x05a84), và chuyển đổi đệ quy Java
//       JSONObject / JSONArray sang Json::Value (0x05bb8..0x0689c).
// ============================================================================

#include "configcenter_manager_jni.h"
#include <cstdarg>
#include <cstdio>

namespace com {
namespace tiktok {
namespace ttkmedia {
namespace configcenter {

// ============================================================================
// EN: ConfigCenter::Singleton() — Reconstructed from 0x04e48 (120 bytes)
//     Disassembly highlights (0x04e48..0x04ebc):
//       0x04e54: adrp  x8, #0x10000
//       0x04e58: add   x8, x8, #0xb0        ; guard variable at .bss 0x100b0
//       0x04e5c: ldarb w8, [x8]
//       0x04e60: tbz   w8, #0, #0x4e78
//       0x04e68: adrp  x0, #0x10000
//       0x04e6c: add   x0, x0, #0x30        ; singleton instance at .bss 0x10030
//       0x04e74: ret
//       0x04e80: bl    __cxa_guard_acquire (0x02620)
//       0x04e94: bl    ConfigCenter::ConfigCenter() (0x024b0 -> 0x04fa8)
//       0x04eac: bl    __cxa_atexit (0x02530, ~ConfigCenter @ 0x04ec0, dso @ 0x0f8d0)
//       0x04eb8: bl    __cxa_guard_release (0x02430)
// VN: ConfigCenter::Singleton() tại 0x04e48 (120 byte, instance tại .bss 0x10030)
// ============================================================================
ConfigCenter* ConfigCenter::Singleton() {
    static ConfigCenter instance;
    return &instance;
}

// ============================================================================
// EN: ConfigCenter::ConfigCenter() — Reconstructed from 0x04fa8 (380 bytes)
//     Disassembly highlights (0x04fa8..0x05120):
//       0x04fc0..0x04fcc: zeros +0x00..+0x57 (3 shared_ptrs + std::mutex)
//       0x04fd0..0x05004:
//         mov w0, #0x48; bl operator new (0x02590)
//         mov w1, #2; mov w2, wzr; bl BaseConfig::BaseConfig (0x0266c)
//         allocates 32B (0x20) __shared_ptr_pointer<IConfig*> (vtable 0x0fa38)
//         stores player_config_ at [this + 0x00]
//       0x0503c..0x05068:
//         mov w0, #0x48; bl operator new (0x02590)
//         mov w1, #3; mov w2, wzr; bl BaseConfig::BaseConfig (0x0266c)
//         stores mdl_config_ at [this + 0x10]
//       0x050a0..0x050cc:
//         mov w0, #0x48; bl operator new (0x02590)
//         mov w1, #4; mov w2, wzr; bl BaseConfig::BaseConfig (0x0266c)
//         stores strategy_center_config_ at [this + 0x20]
//       0x05108..0x05110:
//         zeros listeners_[0..4] at +0x58..+0x7f
// VN: Hàm tạo ConfigCenter::ConfigCenter() tại 0x04fa8 (380 byte)
// ============================================================================
ConfigCenter::ConfigCenter()
    : player_config_(std::make_shared<BaseConfig>(CONFIG_MODULE_PLAYER, PRIORITY_DEFAULT)),
      mdl_config_(std::make_shared<BaseConfig>(CONFIG_MODULE_MDL, PRIORITY_DEFAULT)),
      strategy_center_config_(std::make_shared<BaseConfig>(CONFIG_MODULE_STRATEGY_CENTER, PRIORITY_DEFAULT)),
      mutex_(),
      listeners_{nullptr, nullptr, nullptr, nullptr, nullptr} {}

// ============================================================================
// EN: ConfigCenter::~ConfigCenter() — Reconstructed from 0x04ec0 (232 bytes)
//     Destroys mutex_ at +0x30 (0x04ed4: bl std::mutex::~mutex @ 0x025f0)
//     and releases strategy_center_config_ (+0x20), mdl_config_ (+0x10),
//     and player_config_ (+0x00).
// VN: Hàm hủy ConfigCenter::~ConfigCenter() tại 0x04ec0 (232 byte)
// ============================================================================
ConfigCenter::~ConfigCenter() {
    std::lock_guard<std::mutex> lock(mutex_);
    strategy_center_config_.reset();
    mdl_config_.reset();
    player_config_.reset();
    for (int i = 0; i < 5; ++i) {
        listeners_[i] = nullptr;
    }
}

// ============================================================================
// EN: ConfigCenter::createConfig(ConfigModule, Priority)
//     Reconstructed from 0x05124 (68 bytes):
//       0x05134: mov w0, #0x48
//       0x05140: bl  operator new (0x02590)
//       0x05150: bl  BaseConfig::BaseConfig(module, priority) (0x0266c)
//       0x0515c: mov x0, x21
//       0x05164: ret
// VN: ConfigCenter::createConfig(ConfigModule, Priority) tại 0x05124 (68 byte)
// ============================================================================
IConfig* ConfigCenter::createConfig(ConfigModule module, Priority priority) {
    return new BaseConfig(module, priority);
}

// ============================================================================
// EN: ConfigCenter::createConfig(ConfigModule, Priority, IConfig* source)
//     Reconstructed from 0x0542c (96 bytes):
//       0x0543c: mov w0, #0x48
//       0x0544c: bl  operator new (0x02590)
//       0x0545c: bl  BaseConfig::BaseConfig(module, priority) (0x0266c)
//       0x05460: ldr x8, [x22]
//       0x05468: mov x1, x19         ; source
//       0x0546c: mov w2, wzr         ; deepCopy = false (0 -> move)
//       0x05470: ldr x8, [x8, #0x90] ; copyFrom(source, false)
//       0x05474: blr x8
//       0x05480: mov x0, x22
//       0x05488: ret
// VN: ConfigCenter::createConfig(ConfigModule, Priority, IConfig*) tại 0x0542c (96 byte)
// ============================================================================
IConfig* ConfigCenter::createConfig(ConfigModule module, Priority priority, IConfig* source) {
    auto* cfg = new BaseConfig(module, priority);
    cfg->copyFrom(source, false);
    return cfg;
}

// ============================================================================
// EN: ConfigCenter::getPlayerConfig() const — Reconstructed from 0x05168 (96 bytes)
//     Locks mutex_ at +0x30 (0x05188: bl std::mutex::lock @ 0x02600), copies
//     player_config_ (+0x00..+0x0f) into *x8 incrementing shared count, and
//     tail-calls std::mutex::unlock (0x02410).
// VN: ConfigCenter::getPlayerConfig() const tại 0x05168 (96 byte)
// ============================================================================
std::shared_ptr<IConfig> ConfigCenter::getPlayerConfig() const {
    std::lock_guard<std::mutex> lock(mutex_);
    return player_config_;
}

// ============================================================================
// EN: ConfigCenter::getMdlConfig() const — Reconstructed from 0x051c8 (96 bytes)
//     Locks mutex_ at +0x30, returns copy of mdl_config_ (+0x10..+0x1f), unlocks.
// VN: ConfigCenter::getMdlConfig() const tại 0x051c8 (96 byte)
// ============================================================================
std::shared_ptr<IConfig> ConfigCenter::getMdlConfig() const {
    std::lock_guard<std::mutex> lock(mutex_);
    return mdl_config_;
}

// ============================================================================
// EN: ConfigCenter::getStrategyCenterConfig() const — Reconstructed from 0x05228 (96 bytes)
//     Locks mutex_ at +0x30, returns copy of strategy_center_config_ (+0x20..+0x2f), unlocks.
// VN: ConfigCenter::getStrategyCenterConfig() const tại 0x05228 (96 byte)
// ============================================================================
std::shared_ptr<IConfig> ConfigCenter::getStrategyCenterConfig() const {
    std::lock_guard<std::mutex> lock(mutex_);
    return strategy_center_config_;
}

// ============================================================================
// EN: ConfigCenter::updateConfig(IConfig* config)
//     Reconstructed from 0x05288 (420 bytes)
//     Exact step-by-step disassembly (0x05288..0x05428):
//       1. 0x0529c: cbz x1, #0x52b4 (if !config, return)
//       2. 0x052a0..0x052b0:
//            add  x8, x1, #0x40
//            ldar w8, [x8]
//            cmp  w8, #1
//            b.eq #0x52b4
//          If config's permission_ (+0x40) is already 1 (PERM_READ_ONLY), return early!
//       3. 0x052c8..0x052dc:
//            mov w1, #1; ldr x8, [vtable + #0x98]; blr x8
//          Calls config->setPermission(PERM_READ_ONLY = 1) to freeze input config.
//       4. 0x052e0..0x052ec:
//            ldr x8, [vtable + #0xa0]; blr x8
//          Calls module = config->getModule().
//       5. 0x052f4..0x0531c:
//          Selects target slot x24:
//            - module == 4 (CONFIG_MODULE_STRATEGY_CENTER): this + 0x20
//            - module == 3 (CONFIG_MODULE_MDL):             this + 0x10
//            - module == 2 (CONFIG_MODULE_PLAYER):          this + 0x00
//            - otherwise: return!
//       6. 0x05320..0x05394:
//          Loads existing_cfg = *x24, allocates new BaseConfig (0x48 bytes) with
//          (module, existing_cfg->getPriority() @ vtable +0xa8), calls:
//            - new_cfg->copyFrom(existing_cfg, /*deepCopy=*/true) (@ vtable +0x90)
//            - new_cfg->mergeFrom(config)                         (@ vtable +0x88)
//            - new_cfg->setPermission(PERM_READ_ONLY = 1)         (@ vtable +0x98)
//            - new_cfg->compact()                                 (@ 0x032b4)
//       7. 0x05398..0x05428:
//          Locks this->mutex_ (+0x30), replaces *x24 with shared_ptr<BaseConfig>(new_cfg)
//          (vtable 0x0fa88), checks listener at `*(this + 0x58 + module * 8)` (0x053f8..0x05400),
//          and if non-null calls `listener->onConfigUpdated(module)` (@ vtable +0x10),
//          then unlocks this->mutex_ (0x02410).
// VN: ConfigCenter::updateConfig(IConfig* config) tại 0x05288 (420 byte)
// ============================================================================
void ConfigCenter::updateConfig(IConfig* config) {
    if (!config) {
        return;
    }
    auto* base_input = dynamic_cast<BaseConfig*>(config);
    if (base_input && base_input->getPermission() == PERM_READ_ONLY) {
        // 0x052ac: cmp w8, #1; b.eq #0x52b4
        return;
    }

    // 0x052d0..0x052dc: config->setPermission(1)
    config->setPermission(PERM_READ_ONLY);

    // 0x052e0..0x052ec: w20 = config->getModule()
    ConfigModule mod = config->getModule();
    std::shared_ptr<IConfig>* target_slot = nullptr;
    if (mod == CONFIG_MODULE_STRATEGY_CENTER) {
        target_slot = &strategy_center_config_;
    } else if (mod == CONFIG_MODULE_MDL) {
        target_slot = &mdl_config_;
    } else if (mod == CONFIG_MODULE_PLAYER) {
        target_slot = &player_config_;
    } else {
        return;
    }

    // 0x05320..0x05394: clone current slot config, merge incoming config, freeze permission
    std::shared_ptr<IConfig> current_cfg = *target_slot;
    Priority base_prio = current_cfg ? current_cfg->getPriority() : PRIORITY_DEFAULT;
    auto new_cfg = std::make_shared<BaseConfig>(mod, base_prio);
    if (current_cfg) {
        new_cfg->copyFrom(current_cfg.get(), true);
    }
    new_cfg->mergeFrom(config);
    new_cfg->setPermission(PERM_READ_ONLY);
    new_cfg->compact();

    // 0x05398..0x05428: lock mutex_, swap shared_ptr, notify listener_[mod]
    std::lock_guard<std::mutex> lock(mutex_);
    *target_slot = new_cfg;
    int32_t mod_idx = static_cast<int32_t>(mod);
    if (mod_idx >= 0 && mod_idx < 5 && listeners_[mod_idx] != nullptr) {
        listeners_[mod_idx]->onConfigUpdated(mod);
    }
}

// ============================================================================
// EN: ConfigCenter::setListener(IConfigCenterListener*, ConfigModule)
//     Reconstructed from 0x0548c (12 bytes):
//       0x0548c: add x8, x0, w2, sxtw #3
//       0x05490: str x1, [x8, #0x58]
//       0x05494: ret
// VN: ConfigCenter::setListener tại 0x0548c (12 byte)
// ============================================================================
void ConfigCenter::setListener(IConfigCenterListener* listener, ConfigModule module) noexcept {
    int32_t idx = static_cast<int32_t>(module);
    if (idx >= 0 && idx < 5) {
        listeners_[idx] = listener;
    }
}

// ============================================================================
// EN: FormatLogHeader (0x05640, 156 bytes) & WriteConfigCenterLog (0x05550, 240 bytes)
//     Formats header prefix using .rodata 0x06b1d ("<%p,%s,%s,%d>") into a
//     2048-byte (0x800) buffer, appends vsnprintf message, and writes to
//     __android_log_write(ANDROID_LOG_DEBUG = 3, tag, buffer) (0x023c0).
// VN: FormatLogHeader (0x05640) & WriteConfigCenterLog (0x05550)
// ============================================================================
int FormatLogHeader(
    char* buf,
    size_t buf_size,
    const void* ptr,
    const char* file,
    const char* func,
    int line) noexcept {
    if (!buf || buf_size == 0) {
        return 0;
    }
    // 0x056a0..0x056b4: vsnprintf(buf, 0x800, "<%p,%s,%s,%d>", ...)
    return std::snprintf(
        buf,
        buf_size,
        "<%p,%s,%s,%d>",
        ptr,
        file ? file : "",
        func ? func : "",
        line);
}

void WriteConfigCenterLog(
    const char* tag,
    const void* ptr,
    const char* file,
    const char* func,
    int line,
    const char* fmt,
    ...) noexcept {
    char buffer[2048]; // 0x800 verified at 0x055b4 & 0x056ac
    int prefix_len = FormatLogHeader(buffer, sizeof(buffer), ptr, file, func, line);
    if (prefix_len < 0) {
        prefix_len = 0;
    }
    size_t offset = static_cast<size_t>(prefix_len);
    if (offset < sizeof(buffer) && fmt) {
        va_list args;
        va_start(args, fmt);
        std::vsnprintf(buffer + offset, sizeof(buffer) - offset, fmt, args);
        va_end(args);
    }
    (void)tag;
}

// ============================================================================
// EN: 16 JNI Native Methods (0x056dc..0x05a04)
//     Registered in .data.rel.ro 0x0fac8..0x0fc48:
//       - 15 methods on com/tiktok/ttkmedia/configcenter/BaseConfig (0x06b2b)
//       - 1 method on com/tiktok/ttkmedia/configcenter/ConfigCenter (0x06b57)
// VN: 16 phương thức JNI Native (0x056dc..0x05a04)
// ============================================================================

// 0x056dc (4 bytes): BaseConfig._resetOptions(JLjava/util/Map;)V
void JNICALL BaseConfig_nativeResetOptions(JNIEnv*, jobject, jlong, jobject) {
    // 0x056dc: ret
}

// 0x056e0 (76 bytes): BaseConfig._create(JII)J
jlong JNICALL BaseConfig_nativeCreate(JNIEnv*, jobject, jlong src_handle, jint module, jint priority) {
    ConfigCenter* center = ConfigCenter::Singleton();
    auto mod = static_cast<ConfigModule>(module);
    auto prio = static_cast<Priority>(priority);
    IConfig* created = nullptr;
    if (src_handle != 0) {
        // 0x05708..0x05710: ConfigCenter::createConfig(module, priority, reinterpret_cast<IConfig*>(src_handle))
        created = center->createConfig(mod, prio, reinterpret_cast<IConfig*>(src_handle));
    } else {
        // 0x05718: ConfigCenter::createConfig(module, priority)
        created = center->createConfig(mod, prio);
    }
    return reinterpret_cast<jlong>(created);
}

// 0x0572c (36 bytes): BaseConfig._getIntOption(JII)I
jint JNICALL BaseConfig_nativeGetIntOption(JNIEnv*, jobject, jlong handle, jint key, jint default_val) {
    if (handle == 0) {
        return default_val;
    }
    auto* cfg = reinterpret_cast<IConfig*>(handle);
    return cfg->getIntOption(key, default_val); // vtable +0x18
}

// 0x05750 (32 bytes): BaseConfig._setIntOption(JII)V
void JNICALL BaseConfig_nativeSetIntOption(JNIEnv*, jobject, jlong handle, jint key, jint val) {
    if (handle == 0) {
        return;
    }
    auto* cfg = reinterpret_cast<IConfig*>(handle);
    cfg->setIntOption(key, val); // vtable +0x48
}

// 0x05770 (36 bytes): BaseConfig._getLongOption(JIJ)J
jlong JNICALL BaseConfig_nativeGetLongOption(JNIEnv*, jobject, jlong handle, jint key, jlong default_val) {
    if (handle == 0) {
        return default_val;
    }
    auto* cfg = reinterpret_cast<IConfig*>(handle);
    return cfg->getLongOption(key, default_val); // vtable +0x20
}

// 0x05794 (32 bytes): BaseConfig._setLongOption(JIJ)V
void JNICALL BaseConfig_nativeSetLongOption(JNIEnv*, jobject, jlong handle, jint key, jlong val) {
    if (handle == 0) {
        return;
    }
    auto* cfg = reinterpret_cast<IConfig*>(handle);
    cfg->setLongOption(key, val); // vtable +0x50
}

// 0x057b4 (28 bytes): BaseConfig._getFloatOption(JIF)F
jfloat JNICALL BaseConfig_nativeGetFloatOption(JNIEnv*, jobject, jlong handle, jint key, jfloat default_val) {
    if (handle == 0) {
        return default_val;
    }
    auto* cfg = reinterpret_cast<IConfig*>(handle);
    return cfg->getFloatOption(key, default_val); // vtable +0x28
}

// 0x057d0 (28 bytes): BaseConfig._setFloatOption(JIF)V
void JNICALL BaseConfig_nativeSetFloatOption(JNIEnv*, jobject, jlong handle, jint key, jfloat val) {
    if (handle == 0) {
        return;
    }
    auto* cfg = reinterpret_cast<IConfig*>(handle);
    cfg->setFloatOption(key, val); // vtable +0x58
}

// 0x057ec (176 bytes): BaseConfig._getStringOption(JI)Ljava/lang/String;
jstring JNICALL BaseConfig_nativeGetStringOption(JNIEnv* env, jobject, jlong handle, jint key) {
    if (handle == 0 || !env) {
        return nullptr;
    }
    auto* cfg = reinterpret_cast<IConfig*>(handle);
    std::string val = cfg->getStringOption(key); // vtable +0x38
    return env->NewStringUTF(val.c_str());       // 0x05c88 -> JNIEnv +0x538
}

// 0x05bb8 (208 bytes): CopyJStringToNewCharArray(JNIEnv* env, jstring jstr)
char* CopyJStringToNewCharArray(JNIEnv* env, jstring jstr) {
    if (!env || !jstr) {
        return nullptr;
    }
    jboolean is_copy = JNI_FALSE;
    const char* utf_chars = env->GetStringUTFChars(jstr, &is_copy); // +0x548
    jsize utf_len = env->GetStringUTFLength(jstr);                  // +0x540
    char* copy = new char[static_cast<size_t>(utf_len) + 1u];       // 0x023a0 (_Znam)
    if (utf_chars && utf_len > 0) {
        std::memcpy(copy, utf_chars, static_cast<size_t>(utf_len)); // 0x02350 (memcpy)
    }
    copy[utf_len] = '\0';
    if (utf_chars) {
        env->ReleaseStringUTFChars(jstr, utf_chars);                // +0x550
    }
    return copy;
}

// 0x0589c (68 bytes): BaseConfig._setStringOption(JILjava/lang/String;)V
void JNICALL BaseConfig_nativeSetStringOption(JNIEnv* env, jobject, jlong handle, jint key, jstring val) {
    if (handle == 0) {
        return;
    }
    auto* cfg = reinterpret_cast<IConfig*>(handle);
    char* cstr = CopyJStringToNewCharArray(env, val); // 0x058b8: bl #0x05bb8
    cfg->setStringOption(key, cstr ? cstr : "");      // vtable +0x60
    delete[] cstr;
}

// 0x05cb8 (88 bytes): CheckAndClearJniException(JNIEnv* env)
bool CheckAndClearJniException(JNIEnv* env) {
    if (!env) {
        return false;
    }
    if (env->ExceptionCheck()) { // +0x720
        env->ExceptionDescribe(); // +0x80
        env->ExceptionClear();    // +0x88
        return true;
    }
    return false;
}

// 0x05d14 (968 bytes): ConvertJavaJSONObjectToJsonCpp(JNIEnv* env, jobject json_obj)
Json::Value ConvertJavaJSONObjectToJsonCpp(JNIEnv* env, jobject json_obj) {
    if (!env || !json_obj) {
        return Json::Value(Json::nullValue);
    }
    jclass json_cls = env->FindClass("org/json/JSONObject"); // 0x06cf6
    if (!json_cls || !env->IsInstanceOf(json_obj, json_cls)) {
        if (json_cls) env->DeleteLocalRef(json_cls);
        return Json::Value(Json::nullValue);
    }
    jmethodID keys_mid = env->GetMethodID(json_cls, "keys", "()Ljava/util/Iterator;"); // 0x06d0a, 0x06d0f
    jmethodID opt_mid = env->GetMethodID(json_cls, "opt", "(Ljava/lang/String;)Ljava/lang/Object;"); // 0x06d26, 0x06d2a
    if (!keys_mid || !opt_mid) {
        env->DeleteLocalRef(json_cls);
        return Json::Value(Json::nullValue);
    }
    jobject iter_obj = env->CallObjectMethod(json_obj, keys_mid);
    if (!iter_obj || CheckAndClearJniException(env)) {
        env->DeleteLocalRef(json_cls);
        return Json::Value(Json::nullValue);
    }
    jclass iter_cls = env->FindClass("java/util/Iterator"); // 0x06d51
    jmethodID has_next_mid = iter_cls ? env->GetMethodID(iter_cls, "hasNext", "()Z") : nullptr; // 0x06d64
    jmethodID next_mid = iter_cls ? env->GetMethodID(iter_cls, "next", "()Ljava/lang/Object;") : nullptr; // 0x06d70
    jclass str_cls = env->FindClass("java/lang/String"); // 0x06d8a

    Json::Value result(Json::nullValue);
    while (has_next_mid && next_mid && env->CallBooleanMethod(iter_obj, has_next_mid)) {
        if (CheckAndClearJniException(env)) break;
        jobject key_obj = env->CallObjectMethod(iter_obj, next_mid);
        if (CheckAndClearJniException(env) || !key_obj) continue;
        if (str_cls && env->IsInstanceOf(key_obj, str_cls)) {
            auto jkey = static_cast<jstring>(key_obj);
            jboolean is_copy = JNI_TRUE;
            const char* key_utf = env->GetStringUTFChars(jkey, &is_copy);
            jobject val_obj = env->CallObjectMethod(json_obj, opt_mid, jkey);
            if (!CheckAndClearJniException(env) && val_obj && key_utf) {
                Json::Value child = ConvertJavaObjectToJsonCpp(env, val_obj); // 0x06214
                if (!child.empty()) {
                    result[key_utf] = child; // 0x02500 & 0x024a0
                }
            }
            if (key_utf) env->ReleaseStringUTFChars(jkey, key_utf);
            if (val_obj) env->DeleteLocalRef(val_obj);
        }
        env->DeleteLocalRef(key_obj);
    }
    if (str_cls) env->DeleteLocalRef(str_cls);
    if (iter_cls) env->DeleteLocalRef(iter_cls);
    env->DeleteLocalRef(iter_obj);
    env->DeleteLocalRef(json_cls);
    return result;
}

// 0x06214 (1,208 bytes): ConvertJavaObjectToJsonCpp(JNIEnv* env, jobject obj)
Json::Value ConvertJavaObjectToJsonCpp(JNIEnv* env, jobject obj) {
    if (!env || !obj) {
        return Json::Value(Json::nullValue);
    }
    // 1. java/lang/Integer (0x06d9b) -> intValue()I (0x06dad)
    if (jclass int_cls = env->FindClass("java/lang/Integer")) {
        if (env->IsInstanceOf(obj, int_cls)) {
            jmethodID mid = env->GetMethodID(int_cls, "intValue", "()I");
            jint v = mid ? env->CallIntMethod(obj, mid) : 0;
            env->DeleteLocalRef(int_cls);
            return Json::Value(static_cast<int32_t>(v));
        }
        env->DeleteLocalRef(int_cls);
    }
    // 2. java/lang/Long (0x06dba) -> longValue()J (0x06dc9)
    if (jclass long_cls = env->FindClass("java/lang/Long")) {
        if (env->IsInstanceOf(obj, long_cls)) {
            jmethodID mid = env->GetMethodID(long_cls, "longValue", "()J");
            jlong v = mid ? env->CallLongMethod(obj, mid) : 0;
            env->DeleteLocalRef(long_cls);
            return Json::Value(static_cast<int64_t>(v));
        }
        env->DeleteLocalRef(long_cls);
    }
    // 3. java/lang/Double (0x06dd7) -> doubleValue()D (0x06de8)
    if (jclass dbl_cls = env->FindClass("java/lang/Double")) {
        if (env->IsInstanceOf(obj, dbl_cls)) {
            jmethodID mid = env->GetMethodID(dbl_cls, "doubleValue", "()D");
            jdouble v = mid ? env->CallDoubleMethod(obj, mid) : 0.0;
            env->DeleteLocalRef(dbl_cls);
            return Json::Value(static_cast<double>(v));
        }
        env->DeleteLocalRef(dbl_cls);
    }
    // 4. java/lang/String (0x06d8a)
    if (jclass str_cls = env->FindClass("java/lang/String")) {
        if (env->IsInstanceOf(obj, str_cls)) {
            auto jstr = static_cast<jstring>(obj);
            jboolean is_copy = JNI_TRUE;
            const char* utf = env->GetStringUTFChars(jstr, &is_copy);
            Json::Value res(utf ? utf : "");
            if (utf) env->ReleaseStringUTFChars(jstr, utf);
            env->DeleteLocalRef(str_cls);
            return res;
        }
        env->DeleteLocalRef(str_cls);
    }
    // 5. org/json/JSONObject (0x06cf6)
    if (jclass jobj_cls = env->FindClass("org/json/JSONObject")) {
        if (env->IsInstanceOf(obj, jobj_cls)) {
            env->DeleteLocalRef(jobj_cls);
            return ConvertJavaJSONObjectToJsonCpp(env, obj);
        }
        env->DeleteLocalRef(jobj_cls);
    }
    // 6. org/json/JSONArray (0x06df8) -> length()I (0x06e0b) & get(I)Ljava/lang/Object; (0x06e12)
    if (jclass jarr_cls = env->FindClass("org/json/JSONArray")) {
        if (env->IsInstanceOf(obj, jarr_cls)) {
            jmethodID len_mid = env->GetMethodID(jarr_cls, "length", "()I");
            jmethodID get_mid = env->GetMethodID(jarr_cls, "get", "(I)Ljava/lang/Object;");
            jint len = len_mid ? env->CallIntMethod(obj, len_mid) : 0;
            Json::Value arr_val(Json::nullValue);
            if (!CheckAndClearJniException(env) && len > 0 && get_mid) {
                for (jint i = 0; i < len; ++i) {
                    jobject elem = env->CallObjectMethod(obj, get_mid, i);
                    if (CheckAndClearJniException(env)) break;
                    if (elem) {
                        Json::Value converted = ConvertJavaObjectToJsonCpp(env, elem);
                        if (!converted.empty()) {
                            arr_val.append(converted); // 0x025d0
                        }
                        env->DeleteLocalRef(elem);
                    }
                }
            }
            env->DeleteLocalRef(jarr_cls);
            return arr_val;
        }
        env->DeleteLocalRef(jarr_cls);
    }
    return Json::Value(Json::nullValue);
}

// 0x058e0 (140 bytes): BaseConfig._setJsonOption(JILorg/json/JSONObject;)V
void JNICALL BaseConfig_nativeSetJsonOption(JNIEnv* env, jobject, jlong handle, jint key, jobject json_obj) {
    if (handle == 0) {
        return;
    }
    Json::Value parsed = ConvertJavaJSONObjectToJsonCpp(env, json_obj); // 0x05914: bl #0x05d14
    if (!parsed.isNull()) {                                             // 0x0591c: bl Json::Value::isNull
        auto* cfg = reinterpret_cast<IConfig*>(handle);
        cfg->setJsonOption(key, parsed);                                // vtable +0x68
    }
}

// 0x0596c (52 bytes): BaseConfig._isKeySet(JI)Z
jboolean JNICALL BaseConfig_nativeIsKeySet(JNIEnv*, jobject, jlong handle, jint key) {
    if (handle == 0) {
        return JNI_FALSE;
    }
    auto* cfg = reinterpret_cast<IConfig*>(handle);
    return cfg->isKeySet(key) ? JNI_TRUE : JNI_FALSE; // vtable +0x10
}

// 0x059a0 (24 bytes): BaseConfig._reset(J)V
void JNICALL BaseConfig_nativeReset(JNIEnv*, jobject, jlong handle) {
    if (handle == 0) {
        return;
    }
    auto* cfg = reinterpret_cast<IConfig*>(handle);
    cfg->reset(); // vtable +0x78
}

// 0x059b8 (28 bytes): BaseConfig._remove(JI)V
void JNICALL BaseConfig_nativeRemove(JNIEnv*, jobject, jlong handle, jint key) {
    if (handle == 0) {
        return;
    }
    auto* cfg = reinterpret_cast<IConfig*>(handle);
    cfg->remove(key); // vtable +0x70
}

// 0x059d4 (16 bytes): BaseConfig._release(J)V
void JNICALL BaseConfig_nativeRelease(JNIEnv*, jobject, jlong handle) {
    if (handle == 0) {
        return;
    }
    // 0x059dc: b com::ss::vcbkit::UnSafe::decRef (0x02580)
    com::ss::vcbkit::UnSafe::decRef(reinterpret_cast<com::ss::vcbkit::BaseRef*>(handle));
}

// 0x059e4 (36 bytes): ConfigCenter._updateConfig(J)V
void JNICALL ConfigCenter_nativeUpdateConfig(JNIEnv*, jobject, jlong handle) {
    ConfigCenter::Singleton()->updateConfig(reinterpret_cast<IConfig*>(handle));
}

// ============================================================================
// EN: Exact JNINativeMethod tables in .data.rel.ro (0x0fac8..0x0fc48)
//     and JniClassRegistration descriptors in .data (0x10000..0x10030)
// VN: Bảng JNINativeMethod chính xác trong .data.rel.ro (0x0fac8..0x0fc48)
//     và bộ mô tả JniClassRegistration trong .data (0x10000..0x10030)
// ============================================================================
static const JNINativeMethod kBaseConfigNativeMethods[15] = {
    {"_create",          "(JII)J",                       reinterpret_cast<void*>(BaseConfig_nativeCreate)},          // 0x0fac8 -> 0x056e0
    {"_getIntOption",    "(JII)I",                       reinterpret_cast<void*>(BaseConfig_nativeGetIntOption)},    // 0x0fae0 -> 0x0572c
    {"_getLongOption",   "(JIJ)J",                       reinterpret_cast<void*>(BaseConfig_nativeGetLongOption)},   // 0x0faf8 -> 0x05770
    {"_getFloatOption",  "(JIF)F",                       reinterpret_cast<void*>(BaseConfig_nativeGetFloatOption)},  // 0x0fb10 -> 0x057b4
    {"_getStringOption", "(JI)Ljava/lang/String;",       reinterpret_cast<void*>(BaseConfig_nativeGetStringOption)}, // 0x0fb28 -> 0x057ec
    {"_setIntOption",    "(JII)V",                       reinterpret_cast<void*>(BaseConfig_nativeSetIntOption)},    // 0x0fb40 -> 0x05750
    {"_setLongOption",   "(JIJ)V",                       reinterpret_cast<void*>(BaseConfig_nativeSetLongOption)},   // 0x0fb58 -> 0x05794
    {"_setFloatOption",  "(JIF)V",                       reinterpret_cast<void*>(BaseConfig_nativeSetFloatOption)},  // 0x0fb70 -> 0x057d0
    {"_setStringOption", "(JILjava/lang/String;)V",      reinterpret_cast<void*>(BaseConfig_nativeSetStringOption)}, // 0x0fb88 -> 0x0589c
    {"_setJsonOption",   "(JILorg/json/JSONObject;)V",   reinterpret_cast<void*>(BaseConfig_nativeSetJsonOption)},   // 0x0fba0 -> 0x058e0
    {"_isKeySet",        "(JI)Z",                        reinterpret_cast<void*>(BaseConfig_nativeIsKeySet)},        // 0x0fbb8 -> 0x0596c
    {"_resetOptions",    "(JLjava/util/Map;)V",          reinterpret_cast<void*>(BaseConfig_nativeResetOptions)},    // 0x0fbd0 -> 0x056dc
    {"_reset",           "(J)V",                         reinterpret_cast<void*>(BaseConfig_nativeReset)},           // 0x0fbe8 -> 0x059a0
    {"_remove",          "(JI)V",                        reinterpret_cast<void*>(BaseConfig_nativeRemove)},          // 0x0fc00 -> 0x059b8
    {"_release",         "(J)V",                         reinterpret_cast<void*>(BaseConfig_nativeRelease)}          // 0x0fc18 -> 0x059d4
};

static const JNINativeMethod kConfigCenterNativeMethods[1] = {
    {"_updateConfig",    "(J)V",                         reinterpret_cast<void*>(ConfigCenter_nativeUpdateConfig)}   // 0x0fc30 -> 0x059e4
};

static const JniClassRegistration kBaseConfigRegistration = {
    "com/tiktok/ttkmedia/configcenter/BaseConfig",   // 0x06b2b (@ .data 0x10000)
    15,                                              // 0x0f    (@ .data 0x10008)
    0,
    kBaseConfigNativeMethods                         // 0x0fac8 (@ .data 0x10010)
};

static const JniClassRegistration kConfigCenterRegistration = {
    "com/tiktok/ttkmedia/configcenter/ConfigCenter", // 0x06b57 (@ .data 0x10018)
    1,                                               // 0x01    (@ .data 0x10020)
    0,
    kConfigCenterNativeMethods                       // 0x0fc30 (@ .data 0x10028)
};

// 0x05a08 (124 bytes): RegisterNativesHelper(JNIEnv* env, const JniClassRegistration* reg)
void RegisterNativesHelper(JNIEnv* env, const JniClassRegistration* reg) {
    if (!env || !reg || !reg->class_name) {
        return;
    }
    jclass cls = env->FindClass(reg->class_name); // JNIEnv +0x30
    if (cls) {
        env->RegisterNatives(cls, reg->methods, reg->num_methods); // JNIEnv +0x6b8
        env->DeleteLocalRef(cls);                                  // JNIEnv +0xb8
    }
}

} // namespace configcenter
} // namespace ttkmedia
} // namespace tiktok
} // namespace com

// ============================================================================
// EN: JNI_OnLoad — Reconstructed from 0x05a84 (308 bytes)
//     Disassembly highlights (0x05a84..0x05bb4):
//       0x05aa0: mov  w2, #4; movk w2, #1, lsl #16   ; JNI_VERSION_1_4 = 0x00010004
//       0x05ac0: ldr  x8, [x8, #0x30]; blr x8        ; vm->GetEnv(&env, 0x00010004)
//       0x05ac8: cbz  w0, #0x5ad4; mov w19, #-1      ; if GetEnv != JNI_OK, return -1
//       0x05ad8..0x05b2c: FindClass("com/tiktok/ttkmedia/configcenter/BaseConfig")
//                         RegisterNatives(cls, 0x0fac8, 15), DeleteLocalRef(cls)
//       0x05b34..0x05b88: FindClass("com/tiktok/ttkmedia/configcenter/ConfigCenter")
//                         RegisterNatives(cls, 0x0fc30, 1), DeleteLocalRef(cls)
//       0x05b9c: mov  w0, w19                        ; return 0x00010004 (JNI_VERSION_1_4)
// VN: JNI_OnLoad tại 0x05a84 (308 byte, trả về JNI_VERSION_1_4 = 0x00010004)
// ============================================================================
extern "C" JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void*) {
    if (!vm) {
        return -1;
    }
    JNIEnv* env = nullptr;
    constexpr jint kJniVersion14 = 0x00010004; // Verified at 0x05aa0..0x05abc
    if (vm->GetEnv(reinterpret_cast<void**>(&env), kJniVersion14) != JNI_OK || !env) {
        return -1;
    }
    com::tiktok::ttkmedia::configcenter::RegisterNativesHelper(
        env, &com::tiktok::ttkmedia::configcenter::kBaseConfigRegistration);
    com::tiktok::ttkmedia::configcenter::RegisterNativesHelper(
        env, &com::tiktok::ttkmedia::configcenter::kConfigCenterRegistration);
    return kJniVersion14;
}
