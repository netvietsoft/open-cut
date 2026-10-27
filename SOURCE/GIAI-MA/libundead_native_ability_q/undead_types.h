/**
 * @file undead_types.h
 * @brief Clean-Room C++17 Type & ABI Definitions for `libundead_native_ability_q.so` (`264,448 bytes`)
 *        Định nghĩa kiểu dữ liệu và bố cục ABI C++17 cho `libundead_native_ability_q.so`
 *        (ByteDance Vega UG Push Alive "Undead" Keep-Alive Native Ability for Android Q / Android 10+).
 *
 * Binary Telemetry / Thông số Nhị phân (`OBSERVED`):
 *   - File Size    : `264,448 bytes` (`0x40900`)
 *   - SHA-256      : `fbb084a422d41746a73918169874475da9170f3aae48b099f91d83635aab3d49`
 *   - `.text`      : `0x015b10 .. 0x0323ec` (`116,956 bytes`)
 *   - `.rodata`    : `0x0323f0 .. 0x034f8d` (`11,165 bytes`)
 *   - `.init_array`: `0x040550` (`8 bytes`, entry `0x015b10`)
 *   - `.fini_array`: `0x040558` (`16 bytes`, entries `0x015b98`, `0x015b88`)
 *   - `.data.rel.ro`: `0x040568 .. 0x0436d0` (`12,648 bytes`)
 *   - `.bss`       : `0x0440b0 .. 0x0448d0` (`2,080 bytes`, `kaAbility` @ `0x0440b8`, `40 bytes`)
 */

#ifndef NEXTAI_OPENCUT_UNDEAD_TYPES_H_
#define NEXTAI_OPENCUT_UNDEAD_TYPES_H_

#include <cstddef>
#include <cstdint>
#include <atomic>

namespace nextai {
namespace opencut {
namespace undead_q {

// ============================================================================
// 1. STANDALONE JNI & ANDROID NDK BINDER DEFINITIONS (`libbinder_ndk.so`)
//    ĐỊNH NGHĨA ĐỘC LẬP CHO JNI VÀ ANDROID NDK BINDER (`libbinder_ndk.so`)
// ============================================================================

using jboolean   = uint8_t;
using jbyte      = int8_t;
using jint       = int32_t;
using jlong      = int64_t;
using jsize      = int32_t;
using jobject    = void*;
using jstring    = void*;
using jlongArray = void*;
using binder_status_t = int32_t;
using transaction_code_t = uint32_t;
using binder_flags_t = uint32_t;

constexpr binder_status_t kStatusOk           = 0;
constexpr binder_status_t kStatusUnexpectedNull = -7;
constexpr binder_status_t kStatusBadValue     = -22;

/**
 * @brief Android Parcel `Bundle` magic word `'B','N','D','L'` (`0x4C444E42`)
 *        Verified at `0x0162a8..0x0162ac`: `mov w1, #0x4e42; movk w1, #0x4c44, lsl #16`.
 */
constexpr int32_t kAndroidBundleMagic_0x0162a8 = 0x4C444E42;

/**
 * @brief Polling sleep interval (`4,000,000 us = 4.0 seconds`) when peer holds `flock` (`EAGAIN = 11`).
 *        Verified at `0x015fac..0x015fb0`: `mov w0, #0x900; movk w0, #0x3d, lsl #16`.
 */
constexpr uint32_t kFlockPollSleepUs_0x015fac = 0x003D0900u;

/**
 * @brief 64-bit unsigned magic reciprocal for dividing `tv_usec` by 1000 (`0x20C49BA5E353F7CFULL`).
 *        Verified at `0x016098..0x0160b0`:
 *        `mov x10, #0xf7cf; movk x10, #0xe353, lsl #16; movk x10, #0x9ba5, lsl #32; movk x10, #0x20c4, lsl #48`
 *        `lsr x9, x9, #3; umulh x9, x9, x10; add x8, x8, x9, lsr #4`.
 */
constexpr uint64_t kUsecToMsReciprocal_0x016098 = 0x20C49BA5E353F7CFULL;

/**
 * @brief Minimal JNIEnv simulation table matching offsets accessed in `do_ka` (`0x015ca8..0x016138`):
 *        - `+0x548`: `GetStringUTFChars`
 *        - `+0x550`: `ReleaseStringUTFChars`
 *        - `+0x5E0`: `GetLongArrayElements`
 *        - `+0x620`: `ReleaseLongArrayElements`
 */
struct JNIEnv {
    const char* (*GetStringUTFChars)(JNIEnv*, jstring, jboolean*);
    void (*ReleaseStringUTFChars)(JNIEnv*, jstring, const char*);
    jlong* (*GetLongArrayElements)(JNIEnv*, jlongArray, jboolean*);
    void (*ReleaseLongArrayElements)(JNIEnv*, jlongArray, jlong*, jint);
};

// ============================================================================
// 2. NDK BINDER `AIBinder`, `AIBinder_Class`, AND `AParcel` ABI STRUCTURES
//    CẤU TRÚC ABI CỦA `AIBinder`, `AIBinder_Class` VÀ `AParcel`
// ============================================================================

struct AIBinder;
struct AIBinder_Class;
struct AParcel;

using AIBinder_Class_onCreate   = void* (*)(void* args);
using AIBinder_Class_onDestroy  = void (*)(void* userData);
using AIBinder_Class_onTransact = binder_status_t (*)(AIBinder* binder, transaction_code_t code, const AParcel* in, AParcel* out);
using AIBinder_Class_onDump     = binder_status_t (*)(AIBinder* binder, int fd, const char** args, uint32_t numArgs);

struct AIBinder_Class {
    const char*               interface_descriptor; ///< e.g. "android.app.IActivityManager" @ 0x0323f3
    AIBinder_Class_onCreate   on_create;            ///< 0x016538
    AIBinder_Class_onDestroy  on_destroy;           ///< 0x016634
    AIBinder_Class_onTransact on_transact;          ///< 0x016184
    AIBinder_Class_onDump     on_dump;              ///< 0x016694
};

struct AIBinder {
    const AIBinder_Class* clazz;
    void*                 user_data;
    int32_t               last_transact_code;
    uint32_t              last_transact_flags;
    uint32_t              transact_count;
};

/**
 * @brief Clean-room `AParcel` byte buffer supporting position tracking and backpatching
 *        (`AParcel_getDataPosition`, `AParcel_setDataPosition`, `AParcel_writeInt32`,
 *        `AParcel_writeString`, `AParcel_writeStrongBinder`).
 */
struct AParcel {
    uint8_t  buffer[1024];
    int32_t  data_pos;
    int32_t  data_size;
};

// ============================================================================
// 3. `ka_ability` GLOBAL SINGLETON STRUCT (`.bss 0x0440b8`, `40 bytes` / `0x28`)
//    CẤU TRÚC ĐƠN THỂ TOÀN CỤC `ka_ability` TẠI `.bss 0x0440b8` (`40 byte`)
// ============================================================================

/**
 * @brief Exact 40-byte (`0x28`) layout of `kaAbility` at `.bss 0x0440b8` (`OBSERVED`):
 *        - `+0x00`: `AIBinder* remote_am_binder` (`str x21, [x28]` @ `0x016428`, `ldr x0, [x8]` @ `0x016468`)
 *        - `+0x08`: `int32_t transact_code` (`stp w20, w19, [x28, #8]` @ `0x016424`, `ldp w1, w4, [x8, #8]` @ `0x01646c`)
 *        - `+0x0C`: `int32_t transact_flags` (`stp w20, w19, [x28, #8]` @ `0x016424`)
 *        - `+0x10`: `AParcel* parcel_in` (`add x1, x28, #0x10` @ `0x0161f8`, freed in `~ka_ability` @ `0x0161a4..0x0161b0`)
 *        - `+0x18`: `AParcel* parcel_out` (`add x3, x8, #0x18` @ `0x016474`, freed in `~ka_ability` @ `0x01619c..0x0161a8`)
 *        - `+0x20`: `uint8_t is_initialized` (`strb w22, [x28, #0x20]` @ `0x01642c`, `ldrb w9, [x8, #0x20]` @ `0x016460`)
 */
struct ka_ability {
    AIBinder* remote_am_binder; ///< +0x00
    int32_t   transact_code;    ///< +0x08
    int32_t   transact_flags;   ///< +0x0C
    AParcel*  parcel_in;        ///< +0x10
    AParcel*  parcel_out;       ///< +0x18
    uint8_t   is_initialized;   ///< +0x20
    uint8_t   padding_[7];      ///< +0x21..+0x27

    ~ka_ability() noexcept;
};

static_assert(sizeof(ka_ability) == 0x28, "ka_ability must be exactly 40 bytes (0x28)");

/**
 * @brief Symbol descriptor for exported `.dynsym` entries in `libundead_native_ability_q.so`.
 *        Bộ mô tả biểu tượng xuất khẩu `.dynsym` trong `libundead_native_ability_q.so`.
 */
struct UndeadExportedSymbol {
    uint32_t    vaddr;
    uint32_t    size;
    const char* type_name;
    const char* mangled_name;
};

} // namespace undead_q
} // namespace opencut
} // namespace nextai

#endif // NEXTAI_OPENCUT_UNDEAD_TYPES_H_
