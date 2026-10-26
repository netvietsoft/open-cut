/**
 * @file lynxtrace_interface.h
 * @brief Public C/C++/JNI interface, `.data.rel.ro` registration & vtable inspectors,
 *        and all 34 exported `.dynsym` symbols (`[010]..[043]`) for `liblynxtrace.so`.
 *        Giao diện C/C++/JNI công khai, trình kiểm tra bảng `.data.rel.ro` & vtable,
 *        và toàn bộ 34 biểu tượng xuất `.dynsym` (`[010]..[043]`) cho `liblynxtrace.so`.
 */

#ifndef NEXTAI_OPENCUT_LYNXTRACE_INTERFACE_H_
#define NEXTAI_OPENCUT_LYNXTRACE_INTERFACE_H_

#include "lynxtrace_controller_jni.h"
#include "lynxtrace_perfetto_event.h"
#include "lynxtrace_types.h"

#include <array>
#include <cstdint>
#include <vector>

namespace nextai {
namespace opencut {
namespace lynxtrace {

struct JniClassRegistrationDescriptor {
    const char*                 class_name;
    uint32_t                    rodata_class_name_vaddr;
    uint32_t                    data_rel_ro_methods_vaddr;
    uint32_t                    bss_cached_jclass_vaddr;
    uint32_t                    method_count;
    const JNINativeMethodEntry* methods;
};

struct ExportedDynSymEntry {
    uint32_t    dynsym_index;
    uint32_t    vaddr;
    uint32_t    size_bytes;
    const char* mangled_name;
    const char* demangled_signature;
};

const std::array<JNINativeMethodEntry, 4>& GetTraceControllerJniMethods() noexcept;
const std::array<JNINativeMethodEntry, 10>& GetTraceEventJniMethods() noexcept;
const std::array<uint32_t, 13>& GetTraceControllerVtableSlots() noexcept;
const std::array<ExportedDynSymEntry, 34>& GetExportedDynSymTable() noexcept;

std::vector<JniClassRegistrationDescriptor> GetAllJniClassRegistrations();

/**
 * @brief Executes the exact AArch64 control flow of `JNI_OnLoad` (`0x00403c..0x0040f4`, 188 bytes).
 *        Thực thi luồng điều khiển AArch64 chính xác của `JNI_OnLoad` (`0x00403c..0x0040f4`, 188 byte).
 */
jint ExecuteJniOnLoad(JavaVM* vm, void* reserved);

/**
 * @brief Runs an end-to-end C++17 self-test of all 34 exported `.dynsym` symbols,
 *        both registered Java classes (`TraceController`: 4 methods, `TraceEvent`: 10 methods),
 *        the 13-slot `TraceController` vtable (`0x008018..0x008078`), and telemetry capture mode.
 *        Chạy tự kiểm tra C++17 đầu-cuối cho toàn bộ 34 biểu tượng xuất `.dynsym`,
 *        2 lớp Java (`TraceController` và `TraceEvent`), vtable 13 khe, và chế độ thu thập telemetry.
 */
bool RunLibLynxTraceSelfTest();

} // namespace lynxtrace
} // namespace opencut
} // namespace nextai

extern "C" {

// [024] JNI_OnLoad @ 0x00403c (188 bytes)
nextai::opencut::lynxtrace::jint JNI_OnLoad(
    nextai::opencut::lynxtrace::JavaVM* vm,
    void* reserved);

// [010] TraceEventBeginEx @ 0x0040f8 (4 bytes)
void TraceEventBeginEx(const char* category, const char* name);

// [025] TraceEventEndEx @ 0x0040f8 (4 bytes)
void TraceEventEndEx(const char* category, const char* name);

// [020] TraceCounterEx @ 0x0040f8 (4 bytes)
void TraceCounterEx(const char* category, const char* name, uint64_t value, bool incremental);

} // extern "C"

#endif // NEXTAI_OPENCUT_LYNXTRACE_INTERFACE_H_
