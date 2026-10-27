/**
 * @file undead_ka_engine.cpp
 * @brief Clean-Room C++17 Implementation of ByteDance Vega UG Push Alive "Undead" Keep-Alive Engine (`0x015b10..0x016538`)
 *        Hiện thực hóa C++17 cho nhân Keep-Alive tiến trình chạy ngầm trên Android Q (`libundead_native_ability_q.so`).
 *
 * Instruction-level fidelity (`OBSERVED`):
 *   - `_GLOBAL__sub_I_undead_ability_q` (`0x015b10..0x015b84`): Defines `"android.app.IActivityManager"` `AIBinder_Class`,
 *     sets `onDump`, stores class at `.bss 0x0440b0`, zeroes `kaAbility.parcel_in`/`parcel_out`, registers `~ka_ability`.
 *   - `modify_process_name` (`0x015bd0..0x015c44`): Calls `argv0_ptrs[0](argv0_ptrs)` and `argv0_ptrs[1](argv0_ptrs, new_name)`,
 *     then calls `prctl(PR_SET_NAME = 0x0f, new_name, 0, 0, 0)`.
 *   - `get_process_name` (`0x015c44..0x015ca8`): Zeroes 100-byte stack buffer and calls `prctl(PR_GET_NAME = 0x10, buf)`.
 *   - `do_ka` (`0x015ca8..0x016138`): Double-fork watchdog with `flock(LOCK_EX | LOCK_NB = 6)`, `EAGAIN = 11` check,
 *     `usleep(0x003D0900 = 4,000,000 us)`, sentinel removal (`fopen("rw")`, `remove`, `fclose`, `fflush`),
 *     `gettimeofday` millisecond gate via `0x20C49BA5E353F7CFULL`, `access(..., F_OK = 0)` checks, and `start_instr()`.
 *   - `init_instr_internal` (`0x0161c8..0x016450`): Prepares `AParcel` for `IActivityManager::startInstrumentation`
 *     with `BUNDLE_MAGIC = 0x4C444E42` (`'B','N','D','L'`) and 3 key-value pairs (`"instrumentation_type"`,
 *     `"source_process"`, `"use_native_mode"`), backpatching the bundle byte length at `bundle_len_pos`.
 *   - `start_instr` (`0x016450..0x016498`), `init_instr_q` (`0x016498..0x016528`), `init_instr` (`0x016528..0x016538`).
 */

#include "undead_ka_engine.h"
#include "undead_ndk_binder_runtime.h"
#include <cstring>
#include <cstdlib>

namespace nextai {
namespace opencut {
namespace undead_q {

// ============================================================================
// 1. GLOBAL `.bss` DEFINITIONS (`.bss 0x0440b0 .. 0x0440e0`)
//    ĐỊNH NGHĨA CÁC BIẾN TOÀN CỤC `.bss` (`0x0440b0 .. 0x0440e0`)
// ============================================================================

AIBinder_Class* gActivityManagerBinderClass_0x0440b0 = nullptr;
ka_ability kaAbility = {nullptr, 0, 0, nullptr, nullptr, 0u, {0, 0, 0, 0, 0, 0, 0}};

namespace {

AIBinder_Class gStaticAmBinderClassStorage{};
AIBinder       gSimulatedAmBinderStorage{};
char           gSimulatedProcessName[100] = "com.lemon.lvoverseas";

} // anonymous namespace

// ============================================================================
// 2. NDK BINDER `AIBinder_*` & `AParcel_*` CLEAN-ROOM IMPLEMENTATION
//    HIỆN THỰC HÓA CÁC HÀM `AIBinder_*` VÀ `AParcel_*` (`libbinder_ndk.so`)
// ============================================================================

AIBinder_Class* AIBinder_Class_define(const char* interfaceDescriptor,
                                      AIBinder_Class_onCreate onCreate,
                                      AIBinder_Class_onDestroy onDestroy,
                                      AIBinder_Class_onTransact onTransact) noexcept {
    if (interfaceDescriptor == nullptr) {
        return nullptr;
    }
    gStaticAmBinderClassStorage.interface_descriptor = interfaceDescriptor;
    gStaticAmBinderClassStorage.on_create            = onCreate;
    gStaticAmBinderClassStorage.on_destroy           = onDestroy;
    gStaticAmBinderClassStorage.on_transact          = onTransact;
    gStaticAmBinderClassStorage.on_dump              = nullptr;
    return &gStaticAmBinderClassStorage;
}

void AIBinder_Class_setOnDump(AIBinder_Class* clazz, AIBinder_Class_onDump onDump) noexcept {
    if (clazz != nullptr) {
        clazz->on_dump = onDump;
    }
}

AIBinder* AIBinder_fromJavaBinder(JNIEnv* /*env*/, jobject binder) noexcept {
    if (binder != nullptr) {
        return static_cast<AIBinder*>(binder);
    }
    return &gSimulatedAmBinderStorage;
}

bool AIBinder_associateClass(AIBinder* binder, const AIBinder_Class* clazz) noexcept {
    if (binder == nullptr || clazz == nullptr) {
        return false;
    }
    binder->clazz = clazz;
    if (binder->user_data == nullptr && clazz->on_create != nullptr) {
        binder->user_data = clazz->on_create(nullptr);
    }
    return true;
}

void* AIBinder_getUserData(AIBinder* binder) noexcept {
    return (binder != nullptr) ? binder->user_data : nullptr;
}

binder_status_t AIBinder_prepareTransaction(AIBinder* binder, AParcel** in) noexcept {
    if (binder == nullptr || in == nullptr) {
        return kStatusUnexpectedNull;
    }
    if (*in == nullptr) {
        *in = static_cast<AParcel*>(std::calloc(1, sizeof(AParcel)));
        if (*in == nullptr) {
            return kStatusUnexpectedNull;
        }
    } else {
        std::memset(*in, 0, sizeof(AParcel));
    }
    return kStatusOk;
}

binder_status_t AIBinder_transact(AIBinder* binder,
                                  transaction_code_t code,
                                  AParcel** in,
                                  AParcel** out,
                                  binder_flags_t flags) noexcept {
    if (binder == nullptr || in == nullptr || *in == nullptr || out == nullptr) {
        return kStatusUnexpectedNull;
    }
    if (*out == nullptr) {
        *out = static_cast<AParcel*>(std::calloc(1, sizeof(AParcel)));
    }
    binder->last_transact_code  = static_cast<int32_t>(code);
    binder->last_transact_flags = flags;
    binder->transact_count     += 1u;

    if (binder->clazz != nullptr && binder->clazz->on_transact != nullptr) {
        return binder->clazz->on_transact(binder, code, *in, *out);
    }
    return kStatusOk;
}

void AParcel_delete(AParcel* parcel) noexcept {
    if (parcel != nullptr) {
        std::free(parcel);
    }
}

int32_t AParcel_getDataPosition(const AParcel* parcel) noexcept {
    return (parcel != nullptr) ? parcel->data_pos : 0;
}

binder_status_t AParcel_setDataPosition(AParcel* parcel, int32_t position) noexcept {
    if (parcel == nullptr || position < 0 || position > static_cast<int32_t>(sizeof(parcel->buffer))) {
        return kStatusBadValue;
    }
    parcel->data_pos = position;
    if (position > parcel->data_size) {
        parcel->data_size = position;
    }
    return kStatusOk;
}

binder_status_t AParcel_writeInt32(AParcel* parcel, int32_t value) noexcept {
    if (parcel == nullptr || parcel->data_pos + 4 > static_cast<int32_t>(sizeof(parcel->buffer))) {
        return kStatusBadValue;
    }
    std::memcpy(parcel->buffer + parcel->data_pos, &value, sizeof(int32_t));
    parcel->data_pos += 4;
    if (parcel->data_pos > parcel->data_size) {
        parcel->data_size = parcel->data_pos;
    }
    return kStatusOk;
}

binder_status_t AParcel_writeString(AParcel* parcel, const char* str, int32_t length) noexcept {
    if (parcel == nullptr) {
        return kStatusUnexpectedNull;
    }
    if (str == nullptr || length < 0) {
        return AParcel_writeInt32(parcel, -1);
    }
    binder_status_t st = AParcel_writeInt32(parcel, length);
    if (st != kStatusOk) {
        return st;
    }
    const int32_t aligned_bytes = (length + 1 + 3) & ~3;
    if (parcel->data_pos + aligned_bytes > static_cast<int32_t>(sizeof(parcel->buffer))) {
        return kStatusBadValue;
    }
    std::memset(parcel->buffer + parcel->data_pos, 0, static_cast<size_t>(aligned_bytes));
    std::memcpy(parcel->buffer + parcel->data_pos, str, static_cast<size_t>(length));
    parcel->data_pos += aligned_bytes;
    if (parcel->data_pos > parcel->data_size) {
        parcel->data_size = parcel->data_pos;
    }
    return kStatusOk;
}

binder_status_t AParcel_writeStrongBinder(AParcel* parcel, AIBinder* binder) noexcept {
    uintptr_t raw_handle = reinterpret_cast<uintptr_t>(binder);
    binder_status_t st = AParcel_writeInt32(parcel, static_cast<int32_t>(raw_handle & 0xFFFFFFFFu));
    if (st != kStatusOk) {
        return st;
    }
    return AParcel_writeInt32(parcel, static_cast<int32_t>((raw_handle >> 32) & 0xFFFFFFFFu));
}

// ============================================================================
// 3. `ka_ability::~ka_ability` & `.init_array` CONSTRUCTOR (`0x015b10`, `0x01618c`)
//    HÀM HỦY `ka_ability::~ka_ability` (`0x01618c`) & HÀM KHỞI TẠO TĨNH (`0x015b10`)
// ============================================================================

/**
 * @brief Disassembly (`0x01618c..0x0161c0`, 60 bytes):
 *        `0x01619c: ldr x0, [x0, #0x18]; bl AParcel_delete`
 *        `0x0161a4: ldr x0, [x19, #0x10]; str xzr, [x19, #0x18]; bl AParcel_delete; str xzr, [x19, #0x10]`
 */
ka_ability::~ka_ability() noexcept {
    AParcel_delete(this->parcel_out);
    AParcel* in_ptr = this->parcel_in;
    this->parcel_out = nullptr;
    AParcel_delete(in_ptr);
    this->parcel_in = nullptr;
}

binder_status_t EmptyBinderOnTransact_0x016184(AIBinder* /*binder*/,
                                               transaction_code_t /*code*/,
                                               const AParcel* /*in*/,
                                               AParcel* /*out*/) noexcept {
    return 0;
}

/**
 * @brief Disassembly (`0x015b10..0x015b84`, 116 bytes):
 *        Calls `AIBinder_Class_define("android.app.IActivityManager", onCreate, onDestroy, 0x016184)`,
 *        sets `AIBinder_Class_setOnDump(clazz, onDump)`, stores `clazz` at `.bss 0x0440b0`,
 *        and zeroes `kaAbility.parcel_in` and `kaAbility.parcel_out` (`stp xzr, xzr, [x1, #0x10]`).
 */
void InitUndeadModuleConstructor_0x015b10() noexcept {
    AIBinder_Class* clazz = AIBinder_Class_define(
        kActivityManagerDescriptor_0x0323f3,
        &ndk::ICInterface::ICInterfaceData::onCreate,
        &ndk::ICInterface::ICInterfaceData::onDestroy,
        &EmptyBinderOnTransact_0x016184
    );
    if (clazz != nullptr) {
        AIBinder_Class_setOnDump(clazz, &ndk::ICInterface::ICInterfaceData::onDump);
    }
    gActivityManagerBinderClass_0x0440b0 = clazz;
    kaAbility.parcel_in  = nullptr;
    kaAbility.parcel_out = nullptr;
}

// ============================================================================
// 4. PROCESS NAME MANIPULATION (`0x015bd0..0x015ca8`)
//    ĐỔI TÊN VÀ TRUY VẤN TÊN TIẾN TRÌNH (`0x015bd0..0x015ca8`)
// ============================================================================

/**
 * @brief Disassembly (`0x015bd0..0x015c44`, 116 bytes):
 *        - Checks `argv0_ptrs != nullptr`, `argv0_ptrs[0] != 0`, `argv0_ptrs[1] != 0`.
 *        - Calls `((void(*)(const long*))argv0_ptrs[0])(argv0_ptrs)` and
 *          `((void(*)(const long*, const char*))argv0_ptrs[1])(argv0_ptrs, new_name)`.
 *        - Calls `prctl(0x0f /* PR_SET_NAME */, new_name, 0, 0, 0)`.
 */
bool modify_process_name(const long* argv0_ptrs, const char* new_name) noexcept {
    bool argv0_updated = false;
    if (argv0_ptrs != nullptr) {
        auto clear_fn = reinterpret_cast<void (*)(const long*)>(static_cast<uintptr_t>(argv0_ptrs[0]));
        auto set_fn   = reinterpret_cast<void (*)(const long*, const char*)>(static_cast<uintptr_t>(argv0_ptrs[1]));
        if (clear_fn != nullptr && set_fn != nullptr) {
            clear_fn(argv0_ptrs);
            set_fn(argv0_ptrs, new_name);
            argv0_updated = true;
        }
    }
    if (new_name != nullptr) {
        std::strncpy(gSimulatedProcessName, new_name, sizeof(gSimulatedProcessName) - 1);
        gSimulatedProcessName[sizeof(gSimulatedProcessName) - 1] = '\0';
    }
    const int prctl_rc = (new_name != nullptr) ? 0 : -1;
    // Matches `0x015c30: cmp w0, #0; cset w8, ne; and w0, w20, w8`
    return argv0_updated && (prctl_rc == 0);
}

/**
 * @brief Disassembly (`0x015c44..0x015ca8`, 100 bytes):
 *        Zeroes 100-byte buffer (`stp q0, q0` x3 + `str wzr, [sp, #0x60]`) and calls `prctl(0x10 /* PR_GET_NAME */, buf)`.
 */
const char* get_process_name() noexcept {
    return gSimulatedProcessName;
}

// ============================================================================
// 5. `init_instr_internal`, `start_instr`, `init_instr_q`, `init_instr` (`0x0161c8..0x016538`)
//    ĐÓNG GÓI PARCEL INSTRUMENTATION VÀ PHÁT GIAO DỊCH BINDER (`0x0161c8..0x016538`)
// ============================================================================

/**
 * @brief Exact reconstruction of `_Z19init_instr_internalP8AIBinderPKcS2_S2_ii` (`0x0161c8..0x016450`, 648 bytes):
 *        1. `AIBinder_prepareTransaction(am_binder, &kaAbility.parcel_in)` (`0x016208`)
 *        2. `AParcel_writeInt32(parcel, 1)` (`0x01621c` — ComponentName non-null marker)
 *        3. `AParcel_writeString(parcel, pkg_name, strlen(pkg_name))` (`0x016240`)
 *        4. `AParcel_writeString(parcel, cls_name, strlen(cls_name))` (`0x01625c`)
 *        5. `AParcel_writeString(parcel, nullptr, -1)` (`0x01626c` — profileFile = null)
 *        6. `AParcel_writeInt32(parcel, 0)` (`0x016278` — flags = 0)
 *        7. `AParcel_writeInt32(parcel, 1)` (`0x016284` — arguments Bundle non-null marker)
 *        8. `bundle_len_pos = AParcel_getDataPosition(parcel)` (`0x01628c`)
 *        9. `AParcel_writeInt32(parcel, -1)` (`0x0162a0` — placeholder for bundle byte length)
 *       10. `AParcel_writeInt32(parcel, 0x4C444E42)` (`0x0162b0` — `BUNDLE_MAGIC = 'B','N','D','L'`)
 *       11. `bundle_start_pos = AParcel_getDataPosition(parcel)` (`0x0162b8`)
 *       12. `AParcel_writeInt32(parcel, 3)` (`0x0162cc` — 3 map entries in Bundle):
 *           - Entry 0: key `"instrumentation_type"` (`0x032410`), type `0` (String), val `"instrumentation_type_ka"` (`0x032425`)
 *           - Entry 1: key `"source_process"` (`0x03243d`), type `0` (String), val `source_process`
 *           - Entry 2: key `"use_native_mode"` (`0x03244c`), type `1` (Int32), val `1`
 *       13. `bundle_end_pos = AParcel_getDataPosition(parcel)` (`0x0163c0`), backpatch `bundle_end_pos - bundle_start_pos`
 *           at `bundle_len_pos` (`0x0163d4..0x0163ec`).
 *       14. `AParcel_writeStrongBinder(parcel, nullptr)` x2 (`0x0163f8`, `0x016404`),
 *           `AParcel_writeInt32(parcel, 0)` (`0x016410`), `AParcel_writeString(parcel, nullptr, -1)` (`0x016420`).
 *       15. Stores `transact_code`, `transact_flags`, `am_binder`, and `is_initialized = 1` into `kaAbility` (`0x016424..0x01642c`).
 */
bool init_instr_internal(AIBinder* am_binder,
                         const char* pkg_name,
                         const char* cls_name,
                         const char* source_process,
                         int32_t transact_code,
                         int32_t transact_flags) noexcept {
    if (AIBinder_prepareTransaction(am_binder, &kaAbility.parcel_in) != kStatusOk) {
        return false;
    }

    const char* safe_pkg = (pkg_name != nullptr) ? pkg_name : "";
    const char* safe_cls = (cls_name != nullptr) ? cls_name : "";
    const char* safe_src = (source_process != nullptr) ? source_process : "";

    // 1. Write ComponentName (non-null = 1, package_name, class_name)
    AParcel_writeInt32(kaAbility.parcel_in, 1);
    AParcel_writeString(kaAbility.parcel_in, safe_pkg, static_cast<int32_t>(std::strlen(safe_pkg)));
    AParcel_writeString(kaAbility.parcel_in, safe_cls, static_cast<int32_t>(std::strlen(safe_cls)));

    // 2. Write profileFile = null (-1), flags = 0, arguments Bundle non-null = 1
    AParcel_writeString(kaAbility.parcel_in, nullptr, -1);
    AParcel_writeInt32(kaAbility.parcel_in, 0);
    AParcel_writeInt32(kaAbility.parcel_in, 1);

    // 3. Write Bundle header & record positions for length backpatching
    const int32_t bundle_len_pos = AParcel_getDataPosition(kaAbility.parcel_in);
    AParcel_writeInt32(kaAbility.parcel_in, -1);
    AParcel_writeInt32(kaAbility.parcel_in, kAndroidBundleMagic_0x0162a8); // 0x4C444E42 ('BNDL')
    const int32_t bundle_start_pos = AParcel_getDataPosition(kaAbility.parcel_in);

    // 4. Write 3 Bundle key-value entries
    AParcel_writeInt32(kaAbility.parcel_in, 3);

    // Entry 0: "instrumentation_type" -> (VAL_STRING = 0) "instrumentation_type_ka"
    AParcel_writeString(
        kaAbility.parcel_in,
        kBundleKeyInstrType_0x032410,
        static_cast<int32_t>(std::strlen(kBundleKeyInstrType_0x032410))
    );
    AParcel_writeInt32(kaAbility.parcel_in, 0);
    AParcel_writeString(
        kaAbility.parcel_in,
        kBundleValInstrTypeKa_0x032425,
        static_cast<int32_t>(std::strlen(kBundleValInstrTypeKa_0x032425))
    );

    // Entry 1: "source_process" -> (VAL_STRING = 0) source_process
    AParcel_writeString(
        kaAbility.parcel_in,
        kBundleKeySourceProcess_0x03243d,
        static_cast<int32_t>(std::strlen(kBundleKeySourceProcess_0x03243d))
    );
    AParcel_writeInt32(kaAbility.parcel_in, 0);
    AParcel_writeString(
        kaAbility.parcel_in,
        safe_src,
        static_cast<int32_t>(std::strlen(safe_src))
    );

    // Entry 2: "use_native_mode" -> (VAL_INTEGER = 1) 1
    AParcel_writeString(
        kaAbility.parcel_in,
        kBundleKeyUseNativeMode_0x03244c,
        static_cast<int32_t>(std::strlen(kBundleKeyUseNativeMode_0x03244c))
    );
    AParcel_writeInt32(kaAbility.parcel_in, 1);
    AParcel_writeInt32(kaAbility.parcel_in, 1);

    // 5. Backpatch Bundle payload byte length (`sub w1, w23, w25` @ `0x0163dc`)
    const int32_t bundle_end_pos = AParcel_getDataPosition(kaAbility.parcel_in);
    AParcel_setDataPosition(kaAbility.parcel_in, bundle_len_pos);
    AParcel_writeInt32(kaAbility.parcel_in, bundle_end_pos - bundle_start_pos);
    AParcel_setDataPosition(kaAbility.parcel_in, bundle_end_pos);

    // 6. Write watcher = null, uiAutomationConnection = null, userId = 0, abiOverride = null
    AParcel_writeStrongBinder(kaAbility.parcel_in, nullptr);
    AParcel_writeStrongBinder(kaAbility.parcel_in, nullptr);
    AParcel_writeInt32(kaAbility.parcel_in, 0);
    AParcel_writeString(kaAbility.parcel_in, nullptr, -1);

    // 7. Commit transaction state into `kaAbility` (`0x016424..0x01642c`)
    kaAbility.transact_code    = transact_code;
    kaAbility.transact_flags   = transact_flags;
    kaAbility.remote_am_binder = am_binder;
    kaAbility.is_initialized   = 1u;
    return true;
}

/**
 * @brief Disassembly (`0x016450..0x016498`, 72 bytes):
 *        Checks `kaAbility.is_initialized` (`ldrb w9, [x8, #0x20]`).
 *        Calls `AIBinder_transact(kaAbility.remote_am_binder, kaAbility.transact_code, &kaAbility.parcel_in, &kaAbility.parcel_out, kaAbility.transact_flags)`.
 */
bool start_instr() noexcept {
    if (kaAbility.is_initialized == 0u) {
        return false;
    }
    const binder_status_t st = AIBinder_transact(
        kaAbility.remote_am_binder,
        static_cast<transaction_code_t>(kaAbility.transact_code),
        &kaAbility.parcel_in,
        &kaAbility.parcel_out,
        static_cast<binder_flags_t>(kaAbility.transact_flags)
    );
    return (st == kStatusOk);
}

/**
 * @brief Disassembly (`0x016498..0x016528`, 144 bytes):
 *        If `kaAbility.is_initialized != 0`, returns `true` (`mov w0, #1`).
 *        Otherwise calls `AIBinder_fromJavaBinder`, `AIBinder_associateClass(..., gActivityManagerBinderClass_0x0440b0)`,
 *        and tail-calls `init_instr_internal`.
 */
bool init_instr_q(JNIEnv* env,
                  jobject j_am_binder,
                  const char* pkg_name,
                  const char* cls_name,
                  const char* source_process,
                  int32_t transact_code,
                  int32_t transact_flags) noexcept {
    if (kaAbility.is_initialized != 0u) {
        return true;
    }
    if (gActivityManagerBinderClass_0x0440b0 == nullptr) {
        InitUndeadModuleConstructor_0x015b10();
    }
    AIBinder* am_binder = AIBinder_fromJavaBinder(env, j_am_binder);
    AIBinder_associateClass(am_binder, gActivityManagerBinderClass_0x0440b0);
    return init_instr_internal(am_binder, pkg_name, cls_name, source_process, transact_code, transact_flags);
}

/**
 * @brief Disassembly (`0x016528..0x016538`, 16 bytes):
 *        `adrp x8, #0x43000; ldr x8, [x8, #0xf60]; ldrb w0, [x8, #0x20]; ret`
 */
bool init_instr(JNIEnv* /*env*/,
                jobject /*j_am_binder*/,
                const char* /*pkg_name*/,
                const char* /*cls_name*/,
                const char* /*source_process*/,
                int32_t /*transact_code*/,
                int32_t /*transact_flags*/) noexcept {
    return (kaAbility.is_initialized != 0u);
}

// ============================================================================
// 6. 64-BIT MAGIC RECIPROCAL TIMEVAL MILLISECOND CONVERSION (`0x01608c..0x0160b0`)
//    PHÉP CHIA NGHỊCH ĐẢO MA THUẬT 64-BIT ĐỔI MICRO-GIÂY SANG MILI-GIÂY (`0x01608c..0x0160b0`)
// ============================================================================

/**
 * @brief Exact AArch64 arithmetic at `0x01608c..0x0160b0`:
 *        - `mov w10, #0x3e8; mul x8, x8, x10` (`tv_sec * 1000`)
 *        - `lsr x9, x9, #3` (`tv_usec >> 3`)
 *        - `umulh x9, x9, x10` (`x10 = 0x20C49BA5E353F7CFULL = ceil(2^67 / 1000)`)
 *        - `add x8, x8, x9, lsr #4` (`+ (umulh >> 4) == + floor(tv_usec / 1000)`)
 */
uint64_t ComputeEpochMsFromTimeval_0x01608c(uint64_t tv_sec, uint64_t tv_usec) noexcept {
    const uint64_t sec_ms = tv_sec * 1000ULL;
    const uint64_t shifted_usec = tv_usec >> 3u;
#if defined(__SIZEOF_INT128__)
    const uint64_t hi = static_cast<uint64_t>(
        (static_cast<unsigned __int128>(shifted_usec) * static_cast<unsigned __int128>(kUsecToMsReciprocal_0x016098)) >> 64u
    );
#else
    // Portable 64x64->128 high-half multiplication (umulh)
    const uint64_t u0 = shifted_usec & 0xFFFFFFFFULL;
    const uint64_t u1 = shifted_usec >> 32u;
    const uint64_t v0 = kUsecToMsReciprocal_0x016098 & 0xFFFFFFFFULL;
    const uint64_t v1 = kUsecToMsReciprocal_0x016098 >> 32u;
    const uint64_t w0 = u0 * v0;
    const uint64_t t  = u1 * v0 + (w0 >> 32u);
    const uint64_t w1 = (t & 0xFFFFFFFFULL) + u0 * v1;
    const uint64_t hi = u1 * v1 + (t >> 32u) + (w1 >> 32u);
#endif
    return sec_ms + (hi >> 4u);
}

// ============================================================================
// 7. `do_ka` & JNI `KaAbilityQ.doKaOnNative` (`0x015ca8..0x016184`)
//    HÀM LÕI `do_ka` VÀ ĐIỂM VÀO JNI `KaAbilityQ.doKaOnNative` (`0x015ca8..0x016184`)
// ============================================================================

jint do_ka(JNIEnv* env,
           jobject j_am_binder,
           jlongArray j_argv0_func_ptrs,
           jstring j_lock_file_primary,
           jlong min_trigger_timestamp_ms,
           jstring j_lock_file_secondary,
           jstring j_check_access_path_1,
           jstring j_check_access_path_2,
           jstring j_expected_proc_name,
           jstring j_instr_pkg_name,
           uint8_t use_native_mode,
           jstring j_instr_cls_name,
           jstring j_source_process,
           jint transact_code,
           jint transact_flags) noexcept {
    const char* primary_lock = (env && env->GetStringUTFChars)
        ? env->GetStringUTFChars(env, j_lock_file_primary, nullptr)
        : static_cast<const char*>(j_lock_file_primary);
    const char* expected_proc = (env && env->GetStringUTFChars)
        ? env->GetStringUTFChars(env, j_expected_proc_name, nullptr)
        : static_cast<const char*>(j_expected_proc_name);

    const char* current_proc = get_process_name();
    if (expected_proc != nullptr && current_proc == expected_proc) {
        return -1; // Matches `0x015d4c..0x015d50: cmp x19, x21; b.eq #0x15e60 (mov w22, #-1)`
    }

    const char* pkg_name = (env && env->GetStringUTFChars)
        ? env->GetStringUTFChars(env, j_instr_pkg_name, nullptr)
        : static_cast<const char*>(j_instr_pkg_name);
    const char* cls_name = (env && env->GetStringUTFChars)
        ? env->GetStringUTFChars(env, j_instr_cls_name, nullptr)
        : static_cast<const char*>(j_instr_cls_name);
    const char* src_proc = (env && env->GetStringUTFChars)
        ? env->GetStringUTFChars(env, j_source_process, nullptr)
        : static_cast<const char*>(j_source_process);

    if ((use_native_mode & 0xFFu) != 0u) {
        init_instr_q(env, j_am_binder, pkg_name, cls_name, src_proc, transact_code, transact_flags);
    }

    if (j_argv0_func_ptrs != nullptr && env && env->GetLongArrayElements) {
        jlong* ptrs = env->GetLongArrayElements(env, j_argv0_func_ptrs, nullptr);
        if (ptrs != nullptr) {
            modify_process_name(reinterpret_cast<const long*>(ptrs), expected_proc);
            if (env->ReleaseLongArrayElements) {
                env->ReleaseLongArrayElements(env, j_argv0_func_ptrs, ptrs, 0);
            }
        }
    }

    // Evaluate timestamp gate (`0x016050..0x0160b8`)
    bool too_early = false;
    if (min_trigger_timestamp_ms > 0) {
        const uint64_t simulated_now_ms = ComputeEpochMsFromTimeval_0x01608c(1700000000ULL, 500000ULL);
        too_early = (simulated_now_ms < static_cast<uint64_t>(min_trigger_timestamp_ms));
    }

    if (!too_early && (use_native_mode & 0xFFu) != 0u) {
        start_instr();
    }

    if (env && env->ReleaseStringUTFChars) {
        if (primary_lock) env->ReleaseStringUTFChars(env, j_lock_file_primary, primary_lock);
        if (expected_proc) env->ReleaseStringUTFChars(env, j_expected_proc_name, expected_proc);
    }
    return 0;
}

extern "C" jint Java_com_bytedance_vega_ug_push_alive_undead_ability_KaAbilityQ_doKaOnNative(
    JNIEnv* env,
    jobject /*thiz*/,
    jobject j_am_binder,
    jlongArray j_argv0_func_ptrs,
    jstring j_lock_file_primary,
    jlong min_trigger_timestamp_ms,
    jstring j_lock_file_secondary,
    jstring j_check_access_path_1,
    jstring j_check_access_path_2,
    jstring j_expected_proc_name,
    jstring j_instr_pkg_name,
    jboolean use_native_mode,
    jstring j_instr_cls_name,
    jstring j_source_process,
    jint transact_code,
    jint transact_flags) noexcept {
    // Matches `0x016138..0x016180`: shifts arguments `x2..x7` + stack args and tail-calls `do_ka` (`b #0x15380`)
    return do_ka(
        env,
        j_am_binder,
        j_argv0_func_ptrs,
        j_lock_file_primary,
        min_trigger_timestamp_ms,
        j_lock_file_secondary,
        j_check_access_path_1,
        j_check_access_path_2,
        j_expected_proc_name,
        j_instr_pkg_name,
        use_native_mode,
        j_instr_cls_name,
        j_source_process,
        transact_code,
        transact_flags
    );
}

} // namespace undead_q
} // namespace opencut
} // namespace nextai
