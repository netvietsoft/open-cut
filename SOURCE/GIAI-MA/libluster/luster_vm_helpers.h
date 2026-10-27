/**
 * @file luster_vm_helpers.h
 * @brief Clean-Room C++17 Declarations for libluster.so Core VM Bootstrap, Registration & Helper Callbacks
 *        Khai báo C++17 cho bộ khởi tạo VM, đăng ký JNI động và 7 hàm trợ giúp LusterHelperTable của libluster.so
 *
 * Binary Function Map / Bản đồ hàm nhị phân (.text 0x003590..0x0167d0):
 *   - 0x0035cc..0x003b94 (1,480 B): sub_35cc (Binary search over 212 hot string indices at 0x02fea0)
 *   - 0x003b94..0x004398 (2,052 B): sub_3b94 (Bootstrap EffectUtil.Ew0PFxIIElcAXVdHWFpVCEM0 registration)
 *   - 0x004398..0x0050a0 (3,336 B): sub_4398 (Dynamic JNI registration for 42 classes & 93 methods)
 *   - 0x014838..0x014d20 (1,256 B): Helper0_ResolveField (.bss 0x040b90, .rodata 0x02b7fc)
 *   - 0x014d20..0x0151cc (1,196 B): Helper1_ResolveMethod (.bss 0x042840, .rodata 0x02d4c0)
 *   - 0x0151cc..0x0152a0 (  212 B): Helper2_ResolveMethodDirect (.bss 0x042840, .rodata 0x02d4c0)
 *   - 0x0152a0..0x015400 (  352 B): Helper3_GetTypeClassName (.rodata 0x02cd80 -> 0x029380 -> 0x016a0c)
 *   - 0x015400..0x015808 (1,032 B): Helper4_ResolveClassByIndex (getCacheClass + FindClass + ThrowNew)
 *   - 0x015808..0x015ab8 (  688 B): Helper5_ResolveClassByDescriptor (strips 'L'...';' via __strncpy_chk)
 *   - 0x015ab8..0x016328 (2,160 B): Helper6_ResolveInternedString (java/lang/String.intern + mutex cache)
 *   - 0x016328..0x016354 (   44 B): sub_16328 (Stream XOR decryptor)
 *   - 0x016688..0x016748 (  192 B): sub_16688 (GetMethodID with ExceptionClear + GetStaticMethodID fallback)
 *   - 0x01674c..0x0167d0 (  132 B): JNI_OnLoad (GetEnv 0x00010006 -> cacheInitial(env, 0x272a) -> sub_3b94)
 */

#ifndef NEXTAI_OPENCUT_LUSTER_VM_HELPERS_H_
#define NEXTAI_OPENCUT_LUSTER_VM_HELPERS_H_

#include "luster_types.h"
#include "luster_rodata_tables.h"

namespace nextai {
namespace opencut {
namespace luster {

// ============================================================================
// 1. IMPORTED SYMBOLS FROM libterrain.so (PLT 0x034b0, 0x034c0, 0x034e0, GOT 0x03fff8)
//    BIỂU TƯỢNG NHẬP KHẨU TỪ libterrain.so
// ============================================================================

extern "C" {
    /// Imported at PLT 0x034b0 (GOT 0x03ff80): Initializes Terrain VM class/method cache with `capacity` slots.
    /// Nhập khẩu tại PLT 0x034b0 (GOT 0x03ff80): Khởi tạo bộ nhớ đệm lớp/phương thức của Terrain VM (0x272a = 10,026).
    void cacheInitial(JNIEnv* env, uint32_t capacity);

    /// Imported at PLT 0x034c0 (GOT 0x03ff88): Looks up a globally cached jclass in libterrain.so by descriptor.
    /// Nhập khẩu tại PLT 0x034c0 (GOT 0x03ff88): Tra cứu jclass toàn cục đã lưu đệm trong libterrain.so.
    jclass getCacheClass(JNIEnv* env, const char* class_descriptor);

    /// Imported at PLT 0x034e0 (GOT 0x03ff98): Executes a Terrain VM bytecode unit on the given frame.
    /// Nhập khẩu tại PLT 0x034e0 (GOT 0x03ff98): Thực thi đơn vị mã byte Terrain VM trên khung ngăn xếp.
    uint64_t vmInterpret(JNIEnv* env,
                         TerrainVMContext* ctx,
                         const LusterHelperTable* helpers,
                         jclass target_class);

    /// Imported at GOT 0x03fff8 (.dynsym [10]): Global VM / NoClassDefFoundError state pointer in libterrain.so.
    /// Nhập khẩu tại GOT 0x03fff8 (.dynsym [10]): Con trỏ trạng thái VM toàn cục từ libterrain.so.
    extern jclass gVm;

    /// Exported at .text 0x01674c (132 bytes): Standard Android JNI_OnLoad entrypoint.
    /// Xuất khẩu tại .text 0x01674c (132 byte): Điểm vào chuẩn JNI_OnLoad của Android.
    jint JNI_OnLoad(JavaVM* vm, void* reserved);
}

// ============================================================================
// 2. CORE INTERNAL FUNCTIONS (.text 0x0035cc..0x016748)
//    CÁC HÀM NỘI BỘ LÕI (.text 0x0035cc..0x016748)
// ============================================================================

/**
 * @brief Binary search over sorted 32-bit hot string indices (sub_35cc @ 0x0035cc..0x003b94).
 *        Tìm kiếm nhị phân trên mảng 212 chỉ mục chuỗi nóng đã sắp xếp (sub_35cc @ 0x0035cc..0x003b94).
 */
int32_t sub_35cc(const int32_t* sorted_indices, int32_t count, int32_t target_str_idx) noexcept;

/**
 * @brief Decrypts EffectUtil strings and registers sub_4398 via RegisterNatives (sub_3b94 @ 0x003b94..0x004398).
 *        Giải mã chuỗi EffectUtil và đăng ký hàm gốc sub_4398 qua RegisterNatives (sub_3b94 @ 0x003b94..0x004398).
 */
int32_t sub_3b94(JNIEnv* env) noexcept;

/**
 * @brief Dynamic JNI native method registration handler for class `class_index` (0..41)
 *        bound to `com.illusion.light.EffectUtil.Ew0PFxIIElcAXVdHWFpVCEM0(I)V` (sub_4398 @ 0x004398..0x0050a0).
 *        Trình đăng ký phương thức gốc JNI động cho lớp `class_index` (0..41) gắn với EffectUtil (0x004398..0x0050a0).
 */
void sub_4398(JNIEnv* env, jclass effect_util_clazz, jint class_index) noexcept;

/**
 * @brief Resolves an instance or static jmethodID with automatic ExceptionClear fallback (sub_16688 @ 0x016688..0x016748).
 *        Phân giải jmethodID đối tượng hoặc tĩnh kèm cơ chế tự động xóa ngoại lệ và thử lại (0x016688..0x016748).
 */
jmethodID sub_16688(JNIEnv* env, jclass clazz, const char* method_name, const char* method_sig) noexcept;

// ============================================================================
// 3. THE 7 LUSTER HELPER CALLBACKS (.data.rel.ro 0x03fd20..0x03fd58)
//    7 HÀM TRỢ GIÚP TRONG BẢNG LUSTER HELPER TABLE (.data.rel.ro 0x03fd20..0x03fd58)
// ============================================================================

LusterFieldCacheSlot* Helper0_ResolveField(JNIEnv* env, uint32_t field_idx, uint32_t is_static) noexcept;
LusterMethodCacheSlot* Helper1_ResolveMethod(JNIEnv* env, uint32_t method_idx, uint32_t is_static) noexcept;
jmethodID Helper2_ResolveMethodDirect(JNIEnv* env, uint32_t method_idx, uint32_t is_static, jclass clazz) noexcept;
const char* Helper3_GetTypeClassName(JNIEnv* env, uint32_t type_idx) noexcept;
jclass Helper4_ResolveClassByIndex(JNIEnv* env, uint32_t class_idx) noexcept;
jclass Helper5_ResolveClassByDescriptor(JNIEnv* env, const char* descriptor) noexcept;
jstring Helper6_ResolveInternedString(JNIEnv* env, int32_t str_idx) noexcept;

extern const LusterHelperTable kLusterHelperTable;

} // namespace luster
} // namespace opencut
} // namespace nextai

#endif // NEXTAI_OPENCUT_LUSTER_VM_HELPERS_H_
