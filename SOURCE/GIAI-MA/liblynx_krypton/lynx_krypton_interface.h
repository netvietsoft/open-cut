/**
 * @file lynx_krypton_interface.h
 * @brief Public C/JNI interface and `.data.rel.ro` registration table inspector
 *        for `liblynx_krypton.so` (`JNI_OnLoad` @ `0x004ff4..0x005124`).
 *        Giao diện C/JNI công khai và trình kiểm tra bảng đăng ký `.data.rel.ro`
 *        cho `liblynx_krypton.so` (`JNI_OnLoad` @ `0x004ff4..0x005124`).
 */

#ifndef NEXTAI_OPENCUT_LYNX_KRYPTON_INTERFACE_H_
#define NEXTAI_OPENCUT_LYNX_KRYPTON_INTERFACE_H_

#include "lynx_krypton_surface_vsync.h"
#include "lynx_krypton_trace_log.h"
#include "lynx_krypton_types.h"

#include <array>
#include <cstdint>
#include <vector>

namespace nextai {
namespace opencut {
namespace lynx_krypton {

/**
 * @brief Metadata for each of the 4 JNI classes registered in `JNI_OnLoad` (`0x004ff4..0x005124`).
 *        Siêu dữ liệu cho từng lớp trong 4 lớp JNI được đăng ký tại `JNI_OnLoad` (`0x004ff4..0x005124`).
 */
struct JniClassRegistrationDescriptor {
    const char*                 class_name;
    uint32_t                    rodata_class_name_vaddr;
    uint32_t                    data_rel_ro_methods_vaddr;
    uint32_t                    bss_cached_jclass_vaddr;
    uint32_t                    method_count;
    const JNINativeMethodEntry* methods;
};

/**
 * @brief Metadata for the 5 C++ vtables in `.data.rel.ro` (`0x008090..0x0081b7`).
 *        Siêu dữ liệu cho 5 bảng phương thức ảo C++ (vtable) trong `.data.rel.ro` (`0x008090..0x0081b7`).
 */
struct DataRelRoVtableDescriptor {
    uint32_t    vtable_symbol_vaddr;   // Address of vtable symbol (before +0x10 address point)
    uint32_t    address_point_vaddr;   // Address stored in object +0x00 (`vtable + 0x10`)
    const char* description;
    uint32_t    dtor_d1_vaddr;
    uint32_t    dtor_d0_vaddr;
    uint32_t    call_operator_vaddr;
};

const std::array<JNINativeMethodEntry, 2>& GetCanvasManagerJniMethods() noexcept;
const std::array<JNINativeMethodEntry, 2>& GetDownStreamManagerJniMethods() noexcept;
const std::array<JNINativeMethodEntry, 4>& GetFrameServiceJniMethods() noexcept;
const std::array<JNINativeMethodEntry, 1>& GetUiCanvasSurfaceViewJniMethods() noexcept;

std::vector<JniClassRegistrationDescriptor> GetAllJniClassRegistrations();
std::vector<DataRelRoVtableDescriptor> GetAllDataRelRoVtables();

/**
 * @brief Executes the exact AArch64 control flow of `JNI_OnLoad` (`0x004ff4..0x005124`, 308 bytes).
 *        Thực thi luồng điều khiển AArch64 chính xác của `JNI_OnLoad` (`0x004ff4..0x005124`, 308 byte).
 */
jint ExecuteJniOnLoad(JavaVM* vm, void* reserved);

/**
 * @brief Runs an end-to-end C++17 self-test of all 4 JNI classes, 9 JNI methods,
 *        5-level log jump table, `dlopen("liblynxtrace.so")` trace loader,
 *        downstream surface creation/destruction, and VSync callbacks.
 *        Chạy tự kiểm tra C++17 đầu-cuối cho cả 4 lớp JNI, 9 phương thức JNI,
 *        bảng nhảy 5 mức log, bộ nạp trace `liblynxtrace.so`, tạo/xóa downstream surface và VSync.
 */
bool RunLibLynxKryptonSelfTest();

} // namespace lynx_krypton
} // namespace opencut
} // namespace nextai

extern "C" {

/**
 * @brief Exported ELF64 `.dynsym [040]` symbol `JNI_OnLoad` (`0x004ff4`, 308 bytes).
 *        Biểu tượng xuất ELF64 `.dynsym [040]` `JNI_OnLoad` (`0x004ff4`, 308 byte).
 */
nextai::opencut::lynx_krypton::jint JNI_OnLoad(
    nextai::opencut::lynx_krypton::JavaVM* vm,
    void* reserved);

} // extern "C"

#endif // NEXTAI_OPENCUT_LYNX_KRYPTON_INTERFACE_H_
