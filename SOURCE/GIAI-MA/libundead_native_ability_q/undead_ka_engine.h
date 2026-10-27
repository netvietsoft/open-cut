/**
 * @file undead_ka_engine.h
 * @brief Clean-Room C++17 Declarations for ByteDance Vega UG Push Alive "Undead" Keep-Alive Engine (`0x015b10..0x016538`)
 *        Khai báo C++17 cho nhân Keep-Alive tiến trình chạy ngầm trên Android Q (`libundead_native_ability_q.so`,
 *        `.text 0x015b10..0x016538`).
 */

#ifndef NEXTAI_OPENCUT_UNDEAD_KA_ENGINE_H_
#define NEXTAI_OPENCUT_UNDEAD_KA_ENGINE_H_

#include "undead_types.h"
#include "undead_rodata_tables.h"

namespace nextai {
namespace opencut {
namespace undead_q {

// ============================================================================
// 1. GLOBAL `.bss` STATE (`.bss 0x0440b0 .. 0x0440e0`)
//    TRẠNG THÁI TOÀN CỤC TRONG PHÂN ĐOẠN `.bss` (`0x0440b0 .. 0x0440e0`)
// ============================================================================

/**
 * @brief Global `AIBinder_Class*` for `"android.app.IActivityManager"` stored at `.bss 0x0440b0`
 *        (`str x19, [x8, #0xb0]` @ `0x015b6c`, loaded at `0x0164f0`).
 */
extern AIBinder_Class* gActivityManagerBinderClass_0x0440b0;

/**
 * @brief Exported 40-byte (`0x28`) singleton `kaAbility` at `.bss 0x0440b8` (`STT_OBJECT`).
 *        Biến đơn thể toàn cục `kaAbility` kích thước 40 byte tại `.bss 0x0440b8`.
 */
extern ka_ability kaAbility;

// ============================================================================
// 2. NDK BINDER `AIBinder_*` & `AParcel_*` CLEAN-ROOM WRAPPERS
//    CÁC HÀM BAO TÁI DỰNG SẠCH `AIBinder_*` VÀ `AParcel_*` (`libbinder_ndk.so`)
// ============================================================================

AIBinder_Class* AIBinder_Class_define(const char* interfaceDescriptor,
                                      AIBinder_Class_onCreate onCreate,
                                      AIBinder_Class_onDestroy onDestroy,
                                      AIBinder_Class_onTransact onTransact) noexcept;

void AIBinder_Class_setOnDump(AIBinder_Class* clazz, AIBinder_Class_onDump onDump) noexcept;
AIBinder* AIBinder_fromJavaBinder(JNIEnv* env, jobject binder) noexcept;
bool AIBinder_associateClass(AIBinder* binder, const AIBinder_Class* clazz) noexcept;
void* AIBinder_getUserData(AIBinder* binder) noexcept;
binder_status_t AIBinder_prepareTransaction(AIBinder* binder, AParcel** in) noexcept;
binder_status_t AIBinder_transact(AIBinder* binder,
                                  transaction_code_t code,
                                  AParcel** in,
                                  AParcel** out,
                                  binder_flags_t flags) noexcept;

void AParcel_delete(AParcel* parcel) noexcept;
int32_t AParcel_getDataPosition(const AParcel* parcel) noexcept;
binder_status_t AParcel_setDataPosition(AParcel* parcel, int32_t position) noexcept;
binder_status_t AParcel_writeInt32(AParcel* parcel, int32_t value) noexcept;
binder_status_t AParcel_writeString(AParcel* parcel, const char* str, int32_t length) noexcept;
binder_status_t AParcel_writeStrongBinder(AParcel* parcel, AIBinder* binder) noexcept;

// ============================================================================
// 3. CORE KEEP-ALIVE & INSTRUMENTATION FUNCTIONS (`.text 0x015b10..0x016538`)
//    CÁC HÀM LÕI KEEP-ALIVE & KHỞI CHẠY INSTRUMENTATION (`.text 0x015b10..0x016538`)
// ============================================================================

/**
 * @brief `.init_array` global constructor (`0x015b10..0x015b84`, 116 bytes).
 *        Registers `"android.app.IActivityManager"` `AIBinder_Class` at `.bss 0x0440b0`,
 *        zeroes `kaAbility.parcel_in` / `parcel_out`, and registers `ka_ability::~ka_ability` via `__cxa_atexit`.
 */
void InitUndeadModuleConstructor_0x015b10() noexcept;

/**
 * @brief Default empty `onTransact` callback passed to `AIBinder_Class_define` (`0x016184..0x016188`, 8 bytes).
 *        Returns `0` (`STATUS_OK`).
 */
binder_status_t EmptyBinderOnTransact_0x016184(AIBinder* binder,
                                               transaction_code_t code,
                                               const AParcel* in,
                                               AParcel* out) noexcept;

/**
 * @brief Modifies both the `argv[0]` buffer (via Java-supplied function pointers) and the Linux thread comm name
 *        via `prctl(PR_SET_NAME = 0x0f)` (`_Z19modify_process_namePKlPKc` @ `0x015bd0..0x015c44`, 116 bytes).
 *        Đổi tên tiến trình qua cặp con trỏ hàm `argv0_ptrs` và lời gọi hệ thống `prctl(PR_SET_NAME = 15)`.
 */
bool modify_process_name(const long* argv0_ptrs, const char* new_name) noexcept;

/**
 * @brief Queries the current thread/process name via `prctl(PR_GET_NAME = 0x10)` into a 100-byte buffer
 *        (`_Z16get_process_namev` @ `0x015c44..0x015ca8`, 100 bytes).
 *        Truy vấn tên tiến trình hiện tại bằng `prctl(PR_GET_NAME = 16)`.
 */
const char* get_process_name() noexcept;

/**
 * @brief Core keep-alive watchdog launcher (`_Z5do_kaP7_JNIEnvP8_jobjectP11_jlongArrayP8_jstringlS6_S6_S6_S6_S6_hS6_S6_ii`
 *        @ `0x015ca8..0x016138`, 1,168 bytes).
 *        Hàm lõi khởi chạy tiến trình canh gác Keep-Alive bằng cơ chế double-fork, khóa tệp `flock`,
 *        kiểm tra dấu thời gian mili-giây (`0x20C49BA5E353F7CFULL`) và bắn gói tin `AIBinder_transact`.
 */
jint do_ka(JNIEnv* env,
           jobject j_argv_holder,
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
           jint transact_flags) noexcept;

/**
 * @brief Marshals the Android 10 (`Q`) `IActivityManager::startInstrumentation` transaction parcel into `kaAbility.parcel_in`
 *        (`_Z19init_instr_internalP8AIBinderPKcS2_S2_ii` @ `0x0161c8..0x016450`, 648 bytes).
 *        Đóng gói dữ liệu `AParcel` và `Bundle` (`0x4C444E42` `'B','N','D','L'`) cho giao dịch `startInstrumentation`.
 */
bool init_instr_internal(AIBinder* am_binder,
                         const char* pkg_name,
                         const char* cls_name,
                         const char* source_process,
                         int32_t transact_code,
                         int32_t transact_flags) noexcept;

/**
 * @brief Fires the pre-marshaled `kaAbility.parcel_in` transaction via `AIBinder_transact`
 *        (`_Z11start_instrv` @ `0x016450..0x016498`, 72 bytes).
 *        Thực thi giao dịch `AIBinder_transact` đã chuẩn bị sẵn trong `kaAbility`.
 */
bool start_instr() noexcept;

/**
 * @brief Converts a Java `IBinder` (`IActivityManager`) to `AIBinder*`, associates `"android.app.IActivityManager"`,
 *        and initializes `kaAbility` (`_Z12init_instr_qP7_JNIEnvP8_jobjectPKcS4_S4_ii` @ `0x016498..0x016528`, 144 bytes).
 */
bool init_instr_q(JNIEnv* env,
                  jobject j_am_binder,
                  const char* pkg_name,
                  const char* cls_name,
                  const char* source_process,
                  int32_t transact_code,
                  int32_t transact_flags) noexcept;

/**
 * @brief Queries whether `kaAbility` has already been initialized (`_Z10init_instrP7_JNIEnvP8_jobjectPKcS4_S4_ii`
 *        @ `0x016528..0x016538`, 16 bytes: `ldrb w0, [x8, #0x20]; ret`).
 */
bool init_instr(JNIEnv* env,
                jobject j_am_binder,
                const char* pkg_name,
                const char* cls_name,
                const char* source_process,
                int32_t transact_code,
                int32_t transact_flags) noexcept;

/**
 * @brief Computes current epoch milliseconds from `(tv_sec, tv_usec)` using the exact AArch64 unsigned
 *        magic reciprocal multiplication at `0x01608c..0x0160b0` (`0x20C49BA5E353F7CFULL`).
 *        Tính thời gian mili-giây từ `(tv_sec, tv_usec)` bằng đúng phép nhân nghịch đảo 64-bit tại `0x01608c..0x0160b0`.
 */
uint64_t ComputeEpochMsFromTimeval_0x01608c(uint64_t tv_sec, uint64_t tv_usec) noexcept;

extern "C" {
    /**
     * @brief JNI entrypoint `com.bytedance.vega.ug.push.alive.undead.ability.KaAbilityQ.doKaOnNative`
     *        (`0x016138..0x016184`, 76 bytes).
     */
    jint Java_com_bytedance_vega_ug_push_alive_undead_ability_KaAbilityQ_doKaOnNative(
        JNIEnv* env,
        jobject thiz,
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
        jint transact_flags) noexcept;
}

} // namespace undead_q
} // namespace opencut
} // namespace nextai

#endif // NEXTAI_OPENCUT_UNDEAD_KA_ENGINE_H_
