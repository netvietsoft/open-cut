// ============================================================================
// File: terrain_cache_and_cxxabi.h
// Target: libterrain.so (336,672 bytes)
// Task ID: TASK-136-RECONSTRUCTION-LIBTERRAIN (TASK_SO_062_libterrain)
// EN: Declarations for the exported JNI class cache initializer (`cacheInitial`
//     at 0x02673c), primitive wrapper `TYPE` lookup (`getCacheClass` at 0x0275ec),
//     exported global VM state (`gVm` at 0x055b80), JNI method call bridge
//     (0x01cb98..0x02673b), and static libc++abi / Itanium demangler runtime
//     (0x0276a8..0x03f52f).
// VN: Khai báo cho trình khởi tạo bộ nhớ đệm lớp JNI xuất (`cacheInitial` tại
//     0x02673c), tra cứu `TYPE` lớp bao nguyên thủy (`getCacheClass` tại 0x0275ec),
//     trạng thái máy ảo toàn cục xuất (`gVm` tại 0x055b80), cầu nối gọi hàm JNI
//     (0x01cb98..0x02673b) và runtime libc++abi / Itanium demangler tĩnh.
// ============================================================================

#pragma once

#include "terrain_types.h"
#include "terrain_rodata_tables.h"
#include <cstdint>
#include <cstddef>
#include <string>

namespace nextai {
namespace opencut {
namespace terrain {

// EN: Accessor for the reconstructed JNI class cache (.bss 0x055be0..0x055ef0).
// VN: Hàm truy cập bộ nhớ đệm lớp JNI đã tái tạo (.bss 0x055be0..0x055ef0).
TerrainJniCache& GetTerrainJniCache_055be0() noexcept;

// EN: Reconstructs 0x0274bc..0x0275e8:
//     Resolves `static final Class<?> TYPE` on a primitive wrapper class
//     (e.g., `java/lang/Integer` -> `Integer.TYPE`) using decoded strings
//     `"TYPE"` (0x04006c) and `"Ljava/lang/Class;"` (0x040080).
// VN: Tái tạo 0x0274bc..0x0275e8:
//     Phân giải trường tĩnh `TYPE` trên lớp bao nguyên thủy (ví dụ `java/lang/Integer`)
//     bằng các chuỗi giải mã `"TYPE"` (0x04006c) và `"Ljava/lang/Class;"` (0x040080).
jclass ResolvePrimitiveWrapperType_0274bc(void* jni_env, const char* wrapper_class_name) noexcept;

// EN: Reconstructs FDE #027 (0x01cb98..0x023f94, 29,692 bytes):
//     JNI Method Invocation Bridge with NEON shift constants (0x03fbe8..0x03fc68)
//     and MBA state-machine dispatch (0x01cd34..0x01cdc0: (7 * 8 * 9) % 3 == 0).
// VN: Tái tạo FDE #027 (0x01cb98..0x023f94, 29,692 byte):
//     Cầu nối gọi phương thức JNI với các hằng số dịch NEON (0x03fbe8..0x03fc68)
//     và điều phối máy trạng thái MBA (0x01cd34..0x01cdc0: (7 * 8 * 9) % 3 == 0).
bool VerifyMbaOpaquePredicateMod3_01cd7c(uint64_t x = 7) noexcept;

// EN: Reconstructs Itanium C++ ABI symbol demangler (__cxa_demangle at 0x0294e0..0x0368f0).
// VN: Tái tạo bộ giải mã tên biểu tượng Itanium C++ ABI (__cxa_demangle tại 0x0294e0..0x0368f0).
std::string CleanRoomDemangleItanium_0294e0(const char* mangled_name, int* out_status = nullptr);

} // namespace terrain
} // namespace opencut
} // namespace nextai

extern "C" {
// EN: Exported global VM state symbol `gVm` at .bss 0x055b80 (96 bytes).
// VN: Biểu tượng trạng thái máy ảo toàn cục xuất `gVm` tại .bss 0x055b80 (96 byte).
extern nextai::opencut::terrain::TerrainGlobalVmState gVm;

// EN: Exported C symbol `cacheInitial` at 0x02673c (3,456 bytes).
// VN: Biểu tượng C xuất `cacheInitial` tại 0x02673c (3,456 byte).
void cacheInitial(void* jni_env);

// EN: Exported C symbol `getCacheClass` at 0x0275ec (140 bytes).
// VN: Biểu tượng C xuất `getCacheClass` tại 0x0275ec (140 byte).
nextai::opencut::terrain::jclass getCacheClass(void* jni_env, const char* shorty_or_desc);
}
