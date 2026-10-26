/**
 * @file tailor_interface.h
 * @brief Master Public C/C++17 & JNI Interface Header for `libtailor.so`
 *        (ByteDance Tailor HPROF Binary Heap Dump Cropper, Streaming Zlib/File Writer,
 *        Embedded xHook PLT/GOT Hooking Engine, and Crash Log Discovery Bridge).
 *        Tệp tiêu đề giao diện C/C++17 & JNI tổng thể cho `libtailor.so`
 *        (Bộ cắt gọt luồng nhị phân HPROF ByteDance Tailor, Bộ ghi nén Zlib/Tệp,
 *        Bộ máy xHook PLT/GOT nhúng và Cầu nối quét nhật ký sự cố).
 *
 * Binary Ground Truth (libtailor.so - 84,136 bytes, 27 ELF64 sections, 175 .dynsym entries):
 * - 92 Exported Dynamic Symbols (`[083..174]` in `.dynsym`):
 *   - 63 Exported Function Symbols (`FUNC GLOBAL DEFAULT 15`)
 *   - 29 Exported Data/Vtable/RTTI/Global Symbols (`OBJECT GLOBAL/WEAK DEFAULT 17/22/24`)
 * - 5 JNI Native Methods registered on `com/bytedance/tailor/Tailor` (`0x0177f8..0x01786f`)
 */

#ifndef OPENCUT_TAILOR_INTERFACE_H_
#define OPENCUT_TAILOR_INTERFACE_H_

#include "tailor_types.h"
#include "tailor_stream_writer.h"
#include "tailor_hprof_engine.h"
#include "tailor_xhook_jni.h"

namespace opencut {
namespace tailor {

/**
 * @brief Complete Symbol Descriptor for the 92 Exported `.dynsym` Entries of `libtailor.so`.
 *        Cấu trúc mô tả biểu tượng đầy đủ cho 92 mục `.dynsym` xuất khẩu của `libtailor.so`.
 */
struct TailorExportedSymbolDescriptor {
    uint32_t dynsym_index;
    uint64_t virtual_address;
    uint32_t size_bytes;
    const char* mangled_name;
    const char* demangled_signature;
    const char* subsystem;
};

/**
 * @brief Returns the complete 92-entry `.dynsym` symbol table of `libtailor.so`.
 *        Trả về bảng 92 biểu tượng `.dynsym` xuất khẩu đầy đủ của `libtailor.so`.
 */
const TailorExportedSymbolDescriptor* getTailorExportedSymbolTable(size_t* out_count) noexcept;

/**
 * @brief Runs an end-to-end self-test of the reconstructed `libtailor.so` pipeline:
 *        - Constructs a synthetic HPROF 1.0.3 binary stream containing:
 *          1. 31-byte header (`"JAVA PROFILE 1.0.3\0"`, `id_size = 4`, timestamp)
 *          2. `HPROF_TAG_STRING (0x01)` records for `"android.graphics.Bitmap"` and `"com.example.Foo"`
 *          3. `HPROF_TAG_LOAD_CLASS (0x02)` records mapping class IDs
 *          4. `HPROF_TAG_HEAP_DUMP_SEGMENT (0x1C)` containing `HPROF_GC_CLASS_DUMP (0x20)`,
 *             `HPROF_GC_INSTANCE_DUMP (0x21)`, `HPROF_GC_OBJ_ARRAY_DUMP (0x22)`, and
 *             `HPROF_GC_PRIM_ARRAY_DUMP (0x23)` (with a 1,024-byte `byte[]` payload)
 *          5. `HPROF_TAG_HEAP_DUMP_END (0x2C)`
 *        - Passes the HPROF stream through `TailorImpl` (`tailor_XHOOK`) and verifies that
 *          the 1,024-byte `byte[]` primitive array payload is stripped while the object graph,
 *          `Bitmap` instance fields, and `HPROF_TAG_HEAP_DUMP_END (0x2C)` trailer are preserved!
 *        Chạy tự kiểm tra toàn trình cho đường ống `libtailor.so` đã tái tạo.
 */
bool runTailorEndToEndSelfTest(size_t* out_input_bytes, size_t* out_cropped_bytes);

} // namespace tailor
} // namespace opencut

#endif // OPENCUT_TAILOR_INTERFACE_H_
