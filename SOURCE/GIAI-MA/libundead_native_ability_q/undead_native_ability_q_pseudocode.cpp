/**
 * @file undead_native_ability_q_pseudocode.cpp
 * @brief Unified Clean-Room C++17 Orchestration & Mathematical Self-Verification Harness for `libundead_native_ability_q.so`
 *        Bộ điều phối hợp nhất C++17 & kiểm thử tự xác minh toán học cho `libundead_native_ability_q.so` (`264,448 bytes`).
 */

#include "undead_native_ability_q_interface.h"
#include <cstring>
#include <cstdlib>

namespace nextai {
namespace opencut {
namespace undead_q {

namespace {

constexpr UndeadBinaryDescriptor kDescriptor = {
    "libundead_native_ability_q.so",
    264448u,
    "fbb084a422d41746a73918169874475da9170f3aae48b099f91d83635aab3d49",
    0x00015B10u,
    0x0001C8DCu, // 116,956 bytes
    0x000323F0u,
    0x00002B9Du, // 11,165 bytes
    0x00040550u, // .init_array -> 0x015b10
    0x00040568u,
    0x00003168u, // 12,648 bytes
    0x000440B0u,
    0x00000820u, // 2,080 bytes
    0x000440B8u, // kaAbility
    0x00000028u, // 40 bytes
    589u
};

} // anonymous namespace

const UndeadBinaryDescriptor& GetUndeadBinaryDescriptor() noexcept {
    return kDescriptor;
}

bool RunUndeadNativeAbilityQSelfTest() noexcept {
    // ------------------------------------------------------------------------
    // 1. Verify `.rodata` string literals (`0x0323f0..0x03244c`) & `ka_ability` ABI size (40 B)
    //    Kiểm tra các chuỗi tĩnh `.rodata` và kích thước ABI 40 byte của `ka_ability`
    // ------------------------------------------------------------------------
    if (sizeof(ka_ability) != 0x28u) {
        return false;
    }
    if (std::strcmp(reinterpret_cast<const char*>(&kUndeadRodataBytes_0x0323f0[0x00]), "rw") != 0 ||
        std::strcmp(reinterpret_cast<const char*>(&kUndeadRodataBytes_0x0323f0[0x03]), "android.app.IActivityManager") != 0 ||
        std::strcmp(reinterpret_cast<const char*>(&kUndeadRodataBytes_0x0323f0[0x20]), "instrumentation_type") != 0 ||
        std::strcmp(reinterpret_cast<const char*>(&kUndeadRodataBytes_0x0323f0[0x35]), "instrumentation_type_ka") != 0 ||
        std::strcmp(reinterpret_cast<const char*>(&kUndeadRodataBytes_0x0323f0[0x4d]), "source_process") != 0 ||
        std::strcmp(reinterpret_cast<const char*>(&kUndeadRodataBytes_0x0323f0[0x5c]), "use_native_mode") != 0) {
        return false;
    }

    // ------------------------------------------------------------------------
    // 2. Verify `.init_array` constructor (`0x015b10`), `init_instr_q` (`0x016498`),
    //    `init_instr_internal` (`0x0161c8`), `BUNDLE_MAGIC = 0x4C444E42`, and `start_instr()` (`0x016450`)
    //    Kiểm tra đóng gói `AParcel` + `Bundle` (`0x4C444E42`) và phát giao dịch `start_instr()`
    // ------------------------------------------------------------------------
    InitUndeadModuleConstructor_0x015b10();
    if (gActivityManagerBinderClass_0x0440b0 == nullptr ||
        std::strcmp(gActivityManagerBinderClass_0x0440b0->interface_descriptor, "android.app.IActivityManager") != 0) {
        return false;
    }

    kaAbility.is_initialized = 0u;
    JNIEnv env{};
    const bool init_ok = init_instr_q(
        &env,
        nullptr,
        "com.lemon.lvoverseas",
        "com.bytedance.vega.ug.push.alive.undead.KaInstrumentation",
        "com.lemon.lvoverseas:push",
        44,
        1
    );
    if (!init_ok || !init_instr(&env, nullptr, nullptr, nullptr, nullptr, 0, 0) || kaAbility.parcel_in == nullptr) {
        return false;
    }

    // Verify that `kAndroidBundleMagic_0x0162a8` (0x4C444E42 = 'BNDL') was written into `kaAbility.parcel_in`
    bool found_bundle_magic = false;
    for (int32_t pos = 0; pos + 4 <= kaAbility.parcel_in->data_size; pos += 4) {
        int32_t word = 0;
        std::memcpy(&word, kaAbility.parcel_in->buffer + pos, sizeof(int32_t));
        if (word == kAndroidBundleMagic_0x0162a8) {
            found_bundle_magic = true;
            break;
        }
    }
    if (!found_bundle_magic) {
        return false;
    }

    if (!start_instr() || kaAbility.remote_am_binder->last_transact_code != 44) {
        return false;
    }

    // ------------------------------------------------------------------------
    // 3. Verify 64-bit Magic Reciprocal Division by 1000 (`0x20C49BA5E353F7CFULL` @ `0x01608c..0x0160b0`)
    //    Kiểm tra phép nhân nghịch đảo 64-bit chia `tv_usec` cho 1000 (`0x01608c..0x0160b0`)
    // ------------------------------------------------------------------------
    constexpr uint64_t kTestUsecs[] = {0ULL, 1ULL, 999ULL, 1000ULL, 1001ULL, 123456ULL, 500000ULL, 999999ULL};
    for (uint64_t usec : kTestUsecs) {
        const uint64_t actual   = ComputeEpochMsFromTimeval_0x01608c(1700000000ULL, usec);
        const uint64_t expected = 1700000000ULL * 1000ULL + (usec / 1000ULL);
        if (actual != expected) {
            return false;
        }
    }

    // ------------------------------------------------------------------------
    // 4. Verify `ndk::ICInterface::ICInterfaceData` (`onCreate`, `onDump`, `onDestroy`) & `StdNdk1Align_0x016cd0`
    //    Kiểm tra vòng đời `ndk::ICInterface::ICInterfaceData` và hàm căn chỉnh bộ nhớ `std::__ndk1::align`
    // ------------------------------------------------------------------------
    auto* iface = new ndk::ICInterface();
    void* user_data = ndk::ICInterface::ICInterfaceData::onCreate(iface);
    if (user_data == nullptr) {
        delete iface;
        return false;
    }
    AIBinder dummy_binder{};
    dummy_binder.user_data = user_data;
    if (ndk::ICInterface::ICInterfaceData::onDump(&dummy_binder, 1, nullptr, 0) != kStatusOk) {
        ndk::ICInterface::ICInterfaceData::onDestroy(user_data);
        return false;
    }
    ndk::ICInterface::ICInterfaceData::onDestroy(user_data);

    alignas(64) uint8_t raw_buf[128];
    void* unaligned_ptr = raw_buf + 3;
    size_t space = 100;
    void* aligned_ptr = StdNdk1Align_0x016cd0(16, 32, unaligned_ptr, space);
    if (aligned_ptr == nullptr || (reinterpret_cast<uintptr_t>(aligned_ptr) & 0xFu) != 0u) {
        return false;
    }

    // ------------------------------------------------------------------------
    // 5. Verify Itanium Demangler (`DemangleUndeadSymbol_0x01b980`)
    //    Kiểm tra giải mã tên biểu tượng Itanium C++ ABI
    // ------------------------------------------------------------------------
    int demangle_status = -1;
    char* demangled = DemangleUndeadSymbol_0x01b980("_Z19modify_process_namePKlPKc", nullptr, nullptr, &demangle_status);
    if (demangled == nullptr || demangle_status != 0 ||
        std::strcmp(demangled, "modify_process_name(long const*, char const*)") != 0) {
        std::free(demangled);
        return false;
    }
    std::free(demangled);

    return true;
}

} // namespace undead_q
} // namespace opencut
} // namespace nextai
