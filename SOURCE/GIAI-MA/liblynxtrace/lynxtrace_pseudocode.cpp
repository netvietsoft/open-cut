/**
 * @file lynxtrace_pseudocode.cpp
 * @brief Complete AArch64 instruction-level reconstruction, `.rela.dyn` (62 relocations),
 *        `.rela.plt` (10 relocations), `.text` subroutine directory (18 functions),
 *        and `RunLibLynxTraceSelfTest()` for `liblynxtrace.so` (`51,200 bytes`).
 *        Tái dựng toàn diện ở cấp độ lệnh AArch64, `.rela.dyn` (62 mục), `.rela.plt` (10 mục),
 *        danh mục hàm `.text` (18 hàm), và `RunLibLynxTraceSelfTest()` cho `liblynxtrace.so`.
 */

#include "lynxtrace_controller_jni.h"
#include "lynxtrace_interface.h"
#include "lynxtrace_perfetto_event.h"
#include "lynxtrace_types.h"

#include <array>
#include <cstdint>

namespace nextai {
namespace opencut {
namespace lynxtrace {

// ============================================================================
// 1. Complete `.text` Subroutine Directory (`0x004000..0x004210`, 18 Subroutines)
//    Danh mục Hàm con `.text` Hoàn chỉnh (`0x004000..0x004210`, 18 Hàm con)
// ============================================================================

struct TextSubroutineDescriptor {
    uint32_t    start_vaddr;
    uint32_t    end_vaddr;
    uint32_t    size_bytes;
    const char* symbol_or_role_en;
    const char* symbol_or_role_vn;
};

constexpr std::array<TextSubroutineDescriptor, 18> kTextSubroutineDirectory = {{
    {
        0x004000u, 0x00400cu, 12u,
        "__cxa_finalize_trampoline (.fini_array[1])",
        "Trampoline gọi __cxa_finalize(&__dso_handle) khi dỡ thư viện",
    },
    {
        0x00400cu, 0x004014u, 8u,
        "__fini_noop_stub (.fini_array[0])",
        "Hàm rỗng kết thúc trong .fini_array[0]",
    },
    {
        0x004014u, 0x004020u, 12u,
        "__atexit_indirect_caller(void (*fn)())",
        "Gọi hàm gián tiếp nếu con trỏ hàm khác NULL (cbz x0, #0x401c; br x0)",
    },
    {
        0x004020u, 0x00403cu, 28u,
        "__register_at_exit_wrapper",
        "Đăng ký hàm dọn dẹp qua __cxa_atexit với __dso_handle @ 0x008000",
    },
    {
        0x00403cu, 0x0040f8u, 188u,
        "JNI_OnLoad(JavaVM*, void*)",
        "Khởi tạo VM, đăng ký 4 hàm JNI cho TraceController (0x008080) và 10 hàm JNI cho TraceEvent (0x008108), trả về 0x00010006",
    },
    {
        0x0040f8u, 0x0040fcu, 4u,
        "ReleaseNoOpVoidStub (ret) — shared by 27 void exports & vtable slots",
        "Lệnh ret đơn (4 byte) dùng chung cho 27 hàm xuất void (TraceEventBeginEx, TraceEventEndEx, TraceCounterEx, TrackEvent, LynxDebugAnnotation)",
    },
    {
        0x0040fcu, 0x00415cu, 96u,
        "lynx::trace::TraceController::Instance()",
        "Khởi tạo an toàn đa luồng singleton TraceController tại .data 0x00c000 với biến bảo vệ tại .bss 0x00c010",
    },
    {
        0x00415cu, 0x004184u, 40u,
        "lynx::trace::TraceController::~TraceController() [D1 complete object destructor]",
        "Hàm hủy D1 của TraceController: đặt lại vptr = 0x008018 và hủy delegate tại +0x08 nếu khác NULL",
    },
    {
        0x004184u, 0x00419cu, 24u,
        "lynx::trace::TraceController::~TraceController() [D0 deleting destructor]",
        "Hàm hủy D0 của TraceController: gọi hàm hủy D1 (0x00415c) và operator delete (0x0042b0)",
    },
    {
        0x00419cu, 0x0041a4u, 8u,
        "TraceController::StartTracing / nativeStartTracing (mov w0, #-1; ret)",
        "Trả về -1 (0xffffffff) cho StartTracing và nativeStartTracing",
    },
    {
        0x0041a4u, 0x0041a8u, 4u,
        "BranchToReturnZeroW0 (b #0x41e4) — TraceEventCategoryEnabled & bool getters",
        "Nhảy tới 0x0041e4 trả về w0 = 0 (false) cho TraceEventCategoryEnabled và các hàm kiểm tra trạng thái",
    },
    {
        0x0041a8u, 0x0041acu, 4u,
        "BranchToZeroInit24ByteReturnStruct (b #0x4208)",
        "Nhảy tới 0x004208 khởi tạo chuỗi/vector rỗng 24 byte tại thanh ghi kết quả gián tiếp x8",
    },
    {
        0x0041acu, 0x0041b0u, 4u,
        "BranchToReturnZeroX0 (b #0x41ec) — GetFlowId, GetTraceTimeNs, ThreadTrack::Current",
        "Nhảy tới 0x0041ec trả về x0 = 0 (64-bit zero / nullptr)",
    },
    {
        0x0041b0u, 0x0041c4u, 20u,
        "lynx::base::android::ScopedLocalJavaRef<jobject>::~ScopedLocalJavaRef()",
        "Đặt vptr = 0x0080f0 và gọi JavaRef<jobject>::ReleaseLocalRef(env) qua PLT 0x0042c0",
    },
    {
        0x0041c4u, 0x0041dcu, 24u,
        "Java_com_lynx_tasm_base_TraceController_nativeCreateTraceController(JNIEnv*, jobject)",
        "Gọi TraceController::Instance() (0x0042d0) và trả về địa chỉ .data 0x00c000 kiểu jlong",
    },
    {
        0x0041dcu, 0x0041e4u, 8u,
        "JavaRef<jobject>::HasValueStub (mov w0, #1; ret)",
        "Phương thức vtable 0x0080f0 trả về w0 = 1",
    },
    {
        0x0041e4u, 0x0041f4u, 16u,
        "ReturnZero32And64Stubs (0x0041e4: mov w0, wzr; ret / 0x0041ec: mov x0, xzr; ret)",
        "Cặp hàm trả về 0 32-bit (w0 = 0) và 64-bit (x0 = 0)",
    },
    {
        0x0041f4u, 0x004214u, 32u,
        "JNIEnv_NewGlobalRefHelper (0x0041f4) & ZeroInit24ByteIndirectReturn (0x004208)",
        "Gọi JNIEnv::NewGlobalRef (vtable + 0xa8) và xóa 24 byte tại [x8] (stp xzr, xzr, [x8]; str xzr, [x8, #0x10])",
    },
}};

// ============================================================================
// 2. Complete `.rela.plt` Jump Slot Table (`0x001ad0..0x001bbf`, 10 Entries)
//    Bảng Khe Nhảy `.rela.plt` Hoàn chỉnh (`0x001ad0..0x001bbf`, 10 Mục)
// ============================================================================

struct PltImportEntry {
    uint32_t    plt_index;
    uint32_t    plt_stub_vaddr;
    uint32_t    got_plt_vaddr;
    const char* symbol_name;
};

constexpr std::array<PltImportEntry, 10> kPltImportTable = {{
    {0u, 0x004240u, 0x0083d0u, "__cxa_finalize"},
    {1u, 0x004250u, 0x0083d8u, "__cxa_atexit"},
    {2u, 0x004260u, 0x0083e0u, "_ZN4lynx4base7android6InitVMEP7_JavaVM"},
    {3u, 0x004270u, 0x0083e8u, "_ZN4lynx4base7android19AttachCurrentThreadEv"},
    {4u, 0x004280u, 0x0083f0u, "_ZN4lynx4base7android8GetClassEP7_JNIEnvPKc"},
    {5u, 0x004290u, 0x0083f8u, "__cxa_guard_acquire"},
    {6u, 0x0042a0u, 0x008400u, "__cxa_guard_release"},
    {7u, 0x0042b0u, 0x008408u, "_ZdlPv"},
    {8u, 0x0042c0u, 0x008410u, "_ZN4lynx4base7android7JavaRefIP8_jobjectE15ReleaseLocalRefEP7_JNIEnv"},
    {9u, 0x0042d0u, 0x008418u, "_ZN4lynx5trace15TraceController8InstanceEv"},
}};

// ============================================================================
// 3. Complete `.rela.dyn` Table (`0x001500..0x001acf`, 62 `R_AARCH64_RELATIVE` Entries)
//    Bảng Tái định vị `.rela.dyn` Hoàn chỉnh (`0x001500..0x001acf`, 62 Mục)
// ============================================================================

struct RelaDynRelativeEntry {
    uint32_t    index;
    uint32_t    r_offset;
    uint32_t    r_addend;
    const char* target_role_en;
    const char* target_role_vn;
};

constexpr std::array<RelaDynRelativeEntry, 62> kRelaDynRelativeTable = {{
    {0u,  0x008000u, 0x008000u, "__dso_handle self-pointer", "Con trỏ tự tham chiếu __dso_handle tại 0x008000"},
    {1u,  0x008018u, 0x00415cu, "TraceController vtable[0] -> ~TraceController() D1 (0x00415c)", "Khe 0 vtable TraceController -> hàm hủy D1"},
    {2u,  0x008020u, 0x004184u, "TraceController vtable[1] -> ~TraceController() D0 (0x004184)", "Khe 1 vtable TraceController -> hàm hủy D0"},
    {3u,  0x008028u, 0x00419cu, "TraceController vtable[2] -> StartTracing (0x00419c)", "Khe 2 vtable TraceController -> StartTracing (-1)"},
    {4u,  0x008030u, 0x0041a4u, "TraceController vtable[3] -> StopTracing (0x0041a4)", "Khe 3 vtable TraceController -> StopTracing (false)"},
    {5u,  0x008038u, 0x0040f8u, "TraceController vtable[4] -> AddTracePlugin (0x0040f8)", "Khe 4 vtable TraceController -> AddTracePlugin"},
    {6u,  0x008040u, 0x0041a4u, "TraceController vtable[5] -> DeleteTracePlugin (0x0041a4)", "Khe 5 vtable TraceController -> DeleteTracePlugin"},
    {7u,  0x008048u, 0x0040f8u, "TraceController vtable[6] -> StartStartupTracingIfNeeded (0x0040f8)", "Khe 6 vtable TraceController -> StartStartupTracingIfNeeded"},
    {8u,  0x008050u, 0x0040f8u, "TraceController vtable[7] -> SetStartupTracingConfig (0x0040f8)", "Khe 7 vtable TraceController -> SetStartupTracingConfig"},
    {9u,  0x008058u, 0x0040f8u, "TraceController vtable[8] -> SetTraceBufferSize (0x0040f8)", "Khe 8 vtable TraceController -> SetTraceBufferSize"},
    {10u, 0x008060u, 0x0040f8u, "TraceController vtable[9] -> AddCompleteCallback (0x0040f8)", "Khe 9 vtable TraceController -> AddCompleteCallback"},
    {11u, 0x008068u, 0x0041a8u, "TraceController vtable[10] -> GetStartupTracingConfig (0x0041a8)", "Khe 10 vtable TraceController -> GetStartupTracingConfig"},
    {12u, 0x008070u, 0x0041a8u, "TraceController vtable[11] -> GetTraceFilePath (0x0041a8)", "Khe 11 vtable TraceController -> GetTraceFilePath"},
    {13u, 0x008078u, 0x0041a4u, "TraceController vtable[12] -> IsTracingStarted (0x0041a4)", "Khe 12 vtable TraceController -> IsTracingStarted"},
    {14u, 0x008080u, 0x001c4cu, "TraceController::kMethods[0].name -> \"nativeCreateTraceController\"", "Tên hàm JNI nativeCreateTraceController"},
    {15u, 0x008088u, 0x001e3du, "TraceController::kMethods[0].signature -> \"()J\"", "Chữ ký JNI ()J của nativeCreateTraceController"},
    {16u, 0x008090u, 0x0041c4u, "TraceController::kMethods[0].fnPtr -> 0x0041c4", "Con trỏ hàm nativeCreateTraceController @ 0x0041c4"},
    {17u, 0x008098u, 0x001c8cu, "TraceController::kMethods[1].name -> \"nativeStartTracing\"", "Tên hàm JNI nativeStartTracing"},
    {18u, 0x0080a0u, 0x001e41u, "TraceController::kMethods[1].signature -> \"(JI[Ljava/lang/String;[Ljava/lang/String;Ljava/lang/String;Z)I\"", "Chữ ký JNI của nativeStartTracing"},
    {19u, 0x0080a8u, 0x00419cu, "TraceController::kMethods[1].fnPtr -> 0x00419c", "Con trỏ hàm nativeStartTracing @ 0x00419c"},
    {20u, 0x0080b0u, 0x001c9fu, "TraceController::kMethods[2].name -> \"nativeStopTracing\"", "Tên hàm JNI nativeStopTracing"},
    {21u, 0x0080b8u, 0x001d65u, "TraceController::kMethods[2].signature -> \"(JI)V\"", "Chữ ký JNI (JI)V của nativeStopTracing"},
    {22u, 0x0080c0u, 0x0040f8u, "TraceController::kMethods[2].fnPtr -> 0x0040f8", "Con trỏ hàm nativeStopTracing @ 0x0040f8"},
    {23u, 0x0080c8u, 0x001cfbu, "TraceController::kMethods[3].name -> \"nativeStartStartupTracingIfNeeded\"", "Tên hàm JNI nativeStartStartupTracingIfNeeded"},
    {24u, 0x0080d0u, 0x001d60u, "TraceController::kMethods[3].signature -> \"(J)V\"", "Chữ ký JNI (J)V của nativeStartStartupTracingIfNeeded"},
    {25u, 0x0080d8u, 0x0040f8u, "TraceController::kMethods[3].fnPtr -> 0x0040f8", "Con trỏ hàm nativeStartStartupTracingIfNeeded @ 0x0040f8"},
    {26u, 0x0080f0u, 0x0041dcu, "JavaRef<jobject> vtable[0] -> 0x0041dc", "Khe 0 vtable JavaRef<jobject> @ 0x0041dc"},
    {27u, 0x0080f8u, 0x0041a4u, "JavaRef<jobject> vtable[1] -> 0x0041a4", "Khe 1 vtable JavaRef<jobject> @ 0x0041a4"},
    {28u, 0x008100u, 0x0041a4u, "JavaRef<jobject> vtable[2] -> 0x0041a4", "Khe 2 vtable JavaRef<jobject> @ 0x0041a4"},
    {29u, 0x008108u, 0x001c68u, "TraceEvent::kMethods[0].name -> \"nativeBeginSection\"", "Tên hàm JNI nativeBeginSection"},
    {30u, 0x008110u, 0x001e15u, "TraceEvent::kMethods[0].signature -> \"(Ljava/lang/String;Ljava/lang/String;)V\"", "Chữ ký JNI của nativeBeginSection"},
    {31u, 0x008118u, 0x0040f8u, "TraceEvent::kMethods[0].fnPtr -> 0x0040f8", "Con trỏ hàm nativeBeginSection @ 0x0040f8"},
    {32u, 0x008120u, 0x001c08u, "TraceEvent::kMethods[1].name -> \"nativeBeginSectionWithProps\"", "Tên hàm JNI nativeBeginSectionWithProps"},
    {33u, 0x008128u, 0x001da3u, "TraceEvent::kMethods[1].signature -> \"(Ljava/lang/String;Ljava/lang/String;Ljava/util/Map;)V\"", "Chữ ký JNI của nativeBeginSectionWithProps"},
    {34u, 0x008130u, 0x0040f8u, "TraceEvent::kMethods[1].fnPtr -> 0x0040f8", "Con trỏ hàm nativeBeginSectionWithProps @ 0x0040f8"},
    {35u, 0x008138u, 0x001c7bu, "TraceEvent::kMethods[2].name -> \"nativeEndSection\"", "Tên hàm JNI nativeEndSection"},
    {36u, 0x008140u, 0x001e15u, "TraceEvent::kMethods[2].signature -> \"(Ljava/lang/String;Ljava/lang/String;)V\"", "Chữ ký JNI của nativeEndSection"},
    {37u, 0x008148u, 0x0040f8u, "TraceEvent::kMethods[2].fnPtr -> 0x0040f8", "Con trỏ hàm nativeEndSection @ 0x0040f8"},
    {38u, 0x008150u, 0x001c24u, "TraceEvent::kMethods[3].name -> \"nativeEndSectionWithProps\"", "Tên hàm JNI nativeEndSectionWithProps"},
    {39u, 0x008158u, 0x001da3u, "TraceEvent::kMethods[3].signature -> \"(Ljava/lang/String;Ljava/lang/String;Ljava/util/Map;)V\"", "Chữ ký JNI của nativeEndSectionWithProps"},
    {40u, 0x008160u, 0x0040f8u, "TraceEvent::kMethods[3].fnPtr -> 0x0040f8", "Con trỏ hàm nativeEndSectionWithProps @ 0x0040f8"},
    {41u, 0x008168u, 0x001be3u, "TraceEvent::kMethods[4].name -> \"nativeInstant\"", "Tên hàm JNI nativeInstant"},
    {42u, 0x008170u, 0x001ddau, "TraceEvent::kMethods[4].signature -> \"(Ljava/lang/String;Ljava/lang/String;JLjava/lang/String;)V\"", "Chữ ký JNI của nativeInstant"},
    {43u, 0x008178u, 0x0040f8u, "TraceEvent::kMethods[4].fnPtr -> 0x0040f8", "Con trỏ hàm nativeInstant @ 0x0040f8"},
    {44u, 0x008180u, 0x001bf1u, "TraceEvent::kMethods[5].name -> \"nativeInstantWithProps\"", "Tên hàm JNI nativeInstantWithProps"},
    {45u, 0x008188u, 0x001d6bu, "TraceEvent::kMethods[5].signature -> \"(Ljava/lang/String;Ljava/lang/String;JLjava/util/Map;)V\"", "Chữ ký JNI của nativeInstantWithProps"},
    {46u, 0x008190u, 0x0040f8u, "TraceEvent::kMethods[5].fnPtr -> 0x0040f8", "Con trỏ hàm nativeInstantWithProps @ 0x0040f8"},
    {47u, 0x008198u, 0x001c3eu, "TraceEvent::kMethods[6].name -> \"nativeCounter\"", "Tên hàm JNI nativeCounter"},
    {48u, 0x0081a0u, 0x001d37u, "TraceEvent::kMethods[6].signature -> \"(Ljava/lang/String;Ljava/lang/String;J)V\"", "Chữ ký JNI của nativeCounter"},
    {49u, 0x0081a8u, 0x0040f8u, "TraceEvent::kMethods[6].fnPtr -> 0x0040f8", "Con trỏ hàm nativeCounter @ 0x0040f8"},
    {50u, 0x0081b0u, 0x001cb1u, "TraceEvent::kMethods[7].name -> \"nativeCategoryEnabled\"", "Tên hàm JNI nativeCategoryEnabled"},
    {51u, 0x0081b8u, 0x001d1du, "TraceEvent::kMethods[7].signature -> \"(Ljava/lang/String;)Z\"", "Chữ ký JNI của nativeCategoryEnabled"},
    {52u, 0x0081c0u, 0x0041a4u, "TraceEvent::kMethods[7].fnPtr -> 0x0041a4", "Con trỏ hàm nativeCategoryEnabled @ 0x0041a4"},
    {53u, 0x0081c8u, 0x001ce2u, "TraceEvent::kMethods[8].name -> \"nativeSystemTraceEnabled\"", "Tên hàm JNI nativeSystemTraceEnabled"},
    {54u, 0x0081d0u, 0x001d33u, "TraceEvent::kMethods[8].signature -> \"()Z\"", "Chữ ký JNI ()Z của nativeSystemTraceEnabled"},
    {55u, 0x0081d8u, 0x0041a4u, "TraceEvent::kMethods[8].fnPtr -> 0x0041a4", "Con trỏ hàm nativeSystemTraceEnabled @ 0x0041a4"},
    {56u, 0x0081e0u, 0x001cc7u, "TraceEvent::kMethods[9].name -> \"nativePerfettoTraceEnabled\"", "Tên hàm JNI nativePerfettoTraceEnabled"},
    {57u, 0x0081e8u, 0x001d33u, "TraceEvent::kMethods[9].signature -> \"()Z\"", "Chữ ký JNI ()Z của nativePerfettoTraceEnabled"},
    {58u, 0x0081f0u, 0x0041a4u, "TraceEvent::kMethods[9].fnPtr -> 0x0041a4", "Con trỏ hàm nativePerfettoTraceEnabled @ 0x0041a4"},
    {59u, 0x0081f8u, 0x004010u, ".fini_array[0] -> 0x004010", "Mục .fini_array[0] @ 0x004010"},
    {60u, 0x008200u, 0x004000u, ".fini_array[1] -> 0x004000 (__cxa_finalize)", "Mục .fini_array[1] @ 0x004000"},
    {61u, 0x00c000u, 0x008018u, ".data 0x00c000 TraceController::s_instance.vptr -> 0x008018", "Khởi tạo con trỏ vptr của singleton TraceController tại .data 0x00c000"},
}};

// ============================================================================
// 4. Complete AArch64 Instruction Verification Matrix (`0x004000..0x004210`)
//    Ma trận Đối soát Lệnh AArch64 Hoàn chỉnh (`0x004000..0x004210`)
// ============================================================================

struct AArch64InstructionVerificationEntry {
    uint32_t    vaddr;
    uint32_t    opcode_le;
    const char* mnemonic_and_operands;
    const char* semantic_explanation_en_vn;
};

constexpr std::array<AArch64InstructionVerificationEntry, 60> kVerifiedAArch64Instructions = {{
    {0x004000u, 0x90000020u, "adrp x0, #0x8000", "Load page of __dso_handle (0x008000) / Nạp trang của __dso_handle"},
    {0x004008u, 0x1400008eu, "b #0x4240", "Tail-call __cxa_finalize via PLT 0x004240 / Gọi đuôi __cxa_finalize"},
    {0x004014u, 0xb4000040u, "cbz x0, #0x401c", "Null check function pointer in atexit helper / Kiểm tra con trỏ hàm khác NULL"},
    {0x004018u, 0xd61f0000u, "br x0", "Indirect branch to cleanup callback / Nhảy gián tiếp tới hàm dọn dẹp"},
    {0x004038u, 0x14000086u, "b #0x4250", "Tail-call __cxa_atexit via PLT 0x004250 / Gọi đuôi __cxa_atexit"},
    {0x00403cu, 0xd10103ffu, "sub sp, sp, #0x40", "JNI_OnLoad prologue (64B stack frame) / Mở đầu hàm JNI_OnLoad (khung stack 64B)"},
    {0x004048u, 0x94000086u, "bl #0x4260", "Call lynx::base::android::InitVM(vm) / Khởi tạo JavaVM"},
    {0x00404cu, 0x94000089u, "bl #0x4270", "Call lynx::base::android::AttachCurrentThread() / Gắn luồng hiện tại vào JVM"},
    {0x004054u, 0x912f0021u, "add x1, x1, #0xbc0", "Load \"com/lynx/tasm/base/TraceController\" (.rodata 0x001bc0) / Nạp tên lớp TraceController"},
    {0x004060u, 0x94000088u, "bl #0x4280", "Call GetClass(env, \"com/lynx/tasm/base/TraceController\") / Tìm lớp TraceController"},
    {0x004064u, 0x94000064u, "bl #0x41f4", "Call JNIEnv::NewGlobalRef (vtable + 0xa8) / Tạo tham chiếu toàn cục JNI"},
    {0x00406cu, 0x91006294u, "add x20, x20, #0x18", "Compute .bss 0x00c018 address / Tính địa chỉ .bss 0x00c018"},
    {0x004070u, 0xf9000280u, "str x0, [x20]", "Store TraceController jclass at .bss 0x00c018 / Lưu jclass TraceController tại .bss 0x00c018"},
    {0x004078u, 0x9400004eu, "bl #0x41b0", "Release ScopedLocalJavaRef via 0x0041b0 / Giải phóng tham chiếu cục bộ"},
    {0x004088u, 0x91020042u, "add x2, x2, #0x80", "Load .data.rel.ro 0x008080 (TraceController JNINativeMethod[4]) / Nạp bảng 4 hàm JNI"},
    {0x00408cu, 0xf9435d08u, "ldr x8, [x8, #0x6b8]", "Load JNIEnv::RegisterNatives (offset 0x6b8) / Đọc con trỏ hàm RegisterNatives"},
    {0x004090u, 0x52800083u, "mov w3, #4", "Register 4 native methods on TraceController / Đăng ký 4 phương thức native"},
    {0x004098u, 0xd63f0100u, "blr x8", "Invoke RegisterNatives for TraceController / Gọi RegisterNatives"},
    {0x0040a0u, 0x913a0021u, "add x1, x1, #0xe80", "Load \"com/lynx/tasm/base/TraceEvent\" (.rodata 0x001e80) / Nạp tên lớp TraceEvent"},
    {0x0040acu, 0x94000075u, "bl #0x4280", "Call GetClass(env, \"com/lynx/tasm/base/TraceEvent\") / Tìm lớp TraceEvent"},
    {0x0040b4u, 0xf9000680u, "str x0, [x20, #8]", "Store TraceEvent jclass at .bss 0x00c020 / Lưu jclass TraceEvent tại .bss 0x00c020"},
    {0x0040ccu, 0x91042042u, "add x2, x2, #0x108", "Load .data.rel.ro 0x008108 (TraceEvent JNINativeMethod[10]) / Nạp bảng 10 hàm JNI"},
    {0x0040d4u, 0x52800143u, "mov w3, #0xa", "Register 10 (0xa) native methods on TraceEvent / Đăng ký 10 phương thức native"},
    {0x0040dcu, 0xd63f0100u, "blr x8", "Invoke RegisterNatives for TraceEvent / Gọi RegisterNatives"},
    {0x0040e8u, 0x528000c0u, "mov w0, #6", "Set low 16 bits of JNI_VERSION_1_6 / Đặt 16 bit thấp của 0x00010006"},
    {0x0040ecu, 0x72a00020u, "movk w0, #1, lsl #16", "Return JNI_VERSION_1_6 (0x00010006) / Trả về phiên bản JNI 0x00010006"},
    {0x0040f4u, 0xd65f03c0u, "ret", "Return from JNI_OnLoad / Kết thúc JNI_OnLoad"},
    {0x0040f8u, 0xd65f03c0u, "ret", "Shared release-mode no-op stub (TraceEventBeginEx, TraceEventEndEx, TraceCounterEx, etc.) / Stub ret dùng chung"},
    {0x0040fcu, 0xf81f0ffeu, "str x30, [sp, #-0x10]!", "TraceController::Instance() prologue / Mở đầu TraceController::Instance()"},
    {0x004104u, 0x91004108u, "add x8, x8, #0x10", "Address of guard variable at .bss 0x00c010 / Địa chỉ biến bảo vệ tại .bss 0x00c010"},
    {0x004108u, 0x08dffd08u, "ldarb w8, [x8]", "Load-acquire guard byte / Đọc nguyên tử acquire byte bảo vệ"},
    {0x00410cu, 0x360000a8u, "tbz w8, #0, #0x4120", "Branch to __cxa_guard_acquire if uninitialized / Nhảy tới khởi tạo nếu bit 0 == 0"},
    {0x004110u, 0x90000040u, "adrp x0, #0xc000", "Return &TraceController::s_instance at .data 0x00c000 / Trả về địa chỉ .data 0x00c000"},
    {0x004128u, 0x9400005au, "bl #0x4290", "Call __cxa_guard_acquire(0x00c010) / Khóa biến bảo vệ"},
    {0x00413cu, 0x91057000u, "add x0, x0, #0x15c", "Pass ~TraceController D1 (0x00415c) to __cxa_atexit / Truyền hàm hủy 0x00415c vào __cxa_atexit"},
    {0x004148u, 0x94000042u, "bl #0x4250", "Call __cxa_atexit(~TraceController, 0x00c000, 0x008000) / Đăng ký hủy khi thoát"},
    {0x004154u, 0x94000053u, "bl #0x42a0", "Call __cxa_guard_release(0x00c010) / Giải phóng biến bảo vệ"},
    {0x00415cu, 0xaa0003e8u, "mov x8, x0", "~TraceController D1 destructor prologue / Mở đầu hàm hủy D1"},
    {0x004160u, 0xf9400400u, "ldr x0, [x0, #8]", "Load delegate_ pointer at +0x08 / Nạp con trỏ delegate_ tại +0x08"},
    {0x004168u, 0x91006129u, "add x9, x9, #0x18", "Load vptr 0x008018 / Nạp địa chỉ vtable 0x008018"},
    {0x00416cu, 0xa9007d09u, "stp x9, xzr, [x8]", "Store vptr = 0x008018 and delegate_ = nullptr / Đặt lại vptr và xóa delegate_"},
    {0x004170u, 0xb4000080u, "cbz x0, #0x4180", "Return if delegate_ was nullptr / Thoát nếu delegate_ là NULL"},
    {0x004178u, 0xf9400501u, "ldr x1, [x8, #8]", "Load delegate deleting destructor (vtable + 0x08) / Đọc hàm hủy D0 của delegate"},
    {0x00417cu, 0xd61f0020u, "br x1", "Tail-call delegate destructor / Gọi đuôi hàm hủy của delegate"},
    {0x00418cu, 0x97fffff4u, "bl #0x415c", "~TraceController D0 calls D1 destructor / Hàm hủy D0 gọi hàm hủy D1"},
    {0x004198u, 0x14000046u, "b #0x42b0", "Tail-call operator delete(this) via PLT 0x0042b0 / Giải phóng bộ nhớ qua operator delete"},
    {0x00419cu, 0x12800000u, "mov w0, #-1", "Return -1 (0xffffffff) in StartTracing / Trả về -1 trong StartTracing"},
    {0x0041a4u, 0x14000010u, "b #0x41e4", "Branch to mov w0, wzr; ret / Nhảy tới hàm trả về false (0)"},
    {0x0041a8u, 0x14000018u, "b #0x4208", "Branch to 24-byte indirect return zero-initializer / Nhảy tới hàm xóa 24 byte tại [x8]"},
    {0x0041acu, 0x14000010u, "b #0x41ec", "Branch to mov x0, xzr; ret / Nhảy tới hàm trả về 0 64-bit"},
    {0x0041b0u, 0xf9400801u, "ldr x1, [x0, #0x10]", "Load jobject at +0x10 in ~ScopedLocalJavaRef / Nạp jobject tại +0x10"},
    {0x0041b8u, 0x9103c108u, "add x8, x8, #0xf0", "Load JavaRef vtable 0x0080f0 / Nạp vtable 0x0080f0"},
    {0x0041c0u, 0x14000040u, "b #0x42c0", "Tail-call JavaRef<jobject>::ReleaseLocalRef(env) / Gọi đuôi ReleaseLocalRef"},
    {0x0041c8u, 0x94000042u, "bl #0x42d0", "Call TraceController::Instance() in nativeCreateTraceController / Gọi Instance()"},
    {0x0041dcu, 0x52800020u, "mov w0, #1", "Return 1 in JavaRef vtable[0] / Trả về 1"},
    {0x0041e4u, 0x2a1f03e0u, "mov w0, wzr", "Return 0 (false) / Trả về 0 (32-bit)"},
    {0x0041ecu, 0xaa1f03e0u, "mov x0, xzr", "Return 0ULL / nullptr / Trả về 0 (64-bit)"},
    {0x004200u, 0xf9405508u, "ldr x8, [x8, #0xa8]", "Load JNIEnv::NewGlobalRef (offset 0xa8) / Đọc con trỏ NewGlobalRef"},
    {0x004208u, 0xa9007d1fu, "stp xzr, xzr, [x8]", "Zero bytes [0..15] of indirect return std::string at [x8] / Xóa 16 byte đầu tại [x8]"},
    {0x00420cu, 0xf900091fu, "str xzr, [x8, #0x10]", "Zero bytes [16..23] of indirect return std::string at [x8, #0x10] / Xóa 8 byte cuối tại [x8, #0x10]"},
}};

// ============================================================================
// 5. Complete `.rodata` String Pool Directory (`0x001bc0..0x001e9f`)
//    Danh mục Chuỗi Hằng `.rodata` Hoàn chỉnh (`0x001bc0..0x001e9f`)
// ============================================================================

struct RodataStringDescriptor {
    uint32_t    vaddr;
    const char* literal;
    const char* usage_role_en_vn;
};

constexpr std::array<RodataStringDescriptor, 23> kRodataStringDirectory = {{
    {0x001bc0u, "com/lynx/tasm/base/TraceController", "JNI class name passed to GetClass at 0x004054 / Tên lớp JNI TraceController nạp tại 0x004054"},
    {0x001be3u, "nativeInstant", "TraceEvent::kMethods[4].name (.rela.dyn[41] -> 0x008168) / Tên phương thức nativeInstant"},
    {0x001bf1u, "nativeInstantWithProps", "TraceEvent::kMethods[5].name (.rela.dyn[44] -> 0x008180) / Tên phương thức nativeInstantWithProps"},
    {0x001c08u, "nativeBeginSectionWithProps", "TraceEvent::kMethods[1].name (.rela.dyn[32] -> 0x008120) / Tên phương thức nativeBeginSectionWithProps"},
    {0x001c24u, "nativeEndSectionWithProps", "TraceEvent::kMethods[3].name (.rela.dyn[38] -> 0x008150) / Tên phương thức nativeEndSectionWithProps"},
    {0x001c3eu, "nativeCounter", "TraceEvent::kMethods[6].name (.rela.dyn[47] -> 0x008198) / Tên phương thức nativeCounter"},
    {0x001c4cu, "nativeCreateTraceController", "TraceController::kMethods[0].name (.rela.dyn[14] -> 0x008080) / Tên phương thức nativeCreateTraceController"},
    {0x001c68u, "nativeBeginSection", "TraceEvent::kMethods[0].name (.rela.dyn[29] -> 0x008108) / Tên phương thức nativeBeginSection"},
    {0x001c7bu, "nativeEndSection", "TraceEvent::kMethods[2].name (.rela.dyn[35] -> 0x008138) / Tên phương thức nativeEndSection"},
    {0x001c8cu, "nativeStartTracing", "TraceController::kMethods[1].name (.rela.dyn[17] -> 0x008098) / Tên phương thức nativeStartTracing"},
    {0x001c9fu, "nativeStopTracing", "TraceController::kMethods[2].name (.rela.dyn[20] -> 0x0080b0) / Tên phương thức nativeStopTracing"},
    {0x001cb1u, "nativeCategoryEnabled", "TraceEvent::kMethods[7].name (.rela.dyn[50] -> 0x0081b0) / Tên phương thức nativeCategoryEnabled"},
    {0x001cc7u, "nativePerfettoTraceEnabled", "TraceEvent::kMethods[9].name (.rela.dyn[56] -> 0x0081e0) / Tên phương thức nativePerfettoTraceEnabled"},
    {0x001ce2u, "nativeSystemTraceEnabled", "TraceEvent::kMethods[8].name (.rela.dyn[53] -> 0x0081c8) / Tên phương thức nativeSystemTraceEnabled"},
    {0x001cfbu, "nativeStartStartupTracingIfNeeded", "TraceController::kMethods[3].name (.rela.dyn[23] -> 0x0080c8) / Tên phương thức nativeStartStartupTracingIfNeeded"},
    {0x001d1du, "(Ljava/lang/String;)Z", "JNI signature for nativeCategoryEnabled / Chữ ký JNI của nativeCategoryEnabled"},
    {0x001d33u, "()Z", "JNI signature for nativeSystemTraceEnabled & nativePerfettoTraceEnabled / Chữ ký JNI ()Z"},
    {0x001d37u, "(Ljava/lang/String;Ljava/lang/String;J)V", "JNI signature for nativeCounter / Chữ ký JNI của nativeCounter"},
    {0x001d60u, "(J)V", "JNI signature for nativeStartStartupTracingIfNeeded / Chữ ký JNI (J)V"},
    {0x001d65u, "(JI)V", "JNI signature for nativeStopTracing / Chữ ký JNI (JI)V"},
    {0x001d6bu, "(Ljava/lang/String;Ljava/lang/String;JLjava/util/Map;)V", "JNI signature for nativeInstantWithProps / Chữ ký JNI của nativeInstantWithProps"},
    {0x001da3u, "(Ljava/lang/String;Ljava/lang/String;Ljava/util/Map;)V", "JNI signature for nativeBeginSectionWithProps & nativeEndSectionWithProps / Chữ ký JNI kèm Map"},
    {0x001e80u, "com/lynx/tasm/base/TraceEvent", "JNI class name passed to GetClass at 0x0040a0 / Tên lớp JNI TraceEvent nạp tại 0x0040a0"},
}};

// ============================================================================
// 6. Perfetto Protobuf Wire-Format Varint & Length-Delimited Encoder/Decoder
//    Bộ Mã hóa / Giải mã Định dạng Dây Protobuf Perfetto (Varint & Length-Delimited)
// ============================================================================
//
// Provides a clean, deterministic Protobuf wire-format serializer for
// `perfetto::protos::pbzero::TrackEvent` (`type`, `categories`, `name`,
// `track_uuid`, `flow_ids`, `counter_value`, `debug_annotations`, and
// `legacy_event`) so that `NextAI OpenCut` telemetry consumers can export
// captured `RecordedTraceEvent` records directly to Perfetto `.pftrace` streams.
// Cung cấp bộ tuần tự hóa định dạng dây Protobuf chuẩn xác cho `TrackEvent`
// để xuất các bản ghi `RecordedTraceEvent` sang luồng `.pftrace` của Perfetto.

namespace {

inline void AppendVarint64(std::vector<uint8_t>& buf, uint64_t value) {
    while (value >= 0x80u) {
        buf.push_back(static_cast<uint8_t>((value & 0x7Fu) | 0x80u));
        value >>= 7u;
    }
    buf.push_back(static_cast<uint8_t>(value & 0x7Fu));
}

inline void AppendTagAndVarint(std::vector<uint8_t>& buf, uint32_t field_number, uint64_t value) {
    const uint64_t tag = (static_cast<uint64_t>(field_number) << 3u) | 0u; // WireType 0 (Varint)
    AppendVarint64(buf, tag);
    AppendVarint64(buf, value);
}

inline void AppendTagAndBytes(std::vector<uint8_t>& buf,
                              uint32_t field_number,
                              const void* data,
                              size_t size) {
    const uint64_t tag = (static_cast<uint64_t>(field_number) << 3u) | 2u; // WireType 2 (Length-delimited)
    AppendVarint64(buf, tag);
    AppendVarint64(buf, static_cast<uint64_t>(size));
    const auto* bytes = static_cast<const uint8_t*>(data);
    buf.insert(buf.end(), bytes, bytes + size);
}

inline void AppendTagAndString(std::vector<uint8_t>& buf,
                               uint32_t field_number,
                               const std::string& text) {
    AppendTagAndBytes(buf, field_number, text.data(), text.size());
}

} // namespace

/**
 * @brief Serializes a `RecordedLynxTraceEvent` into a Perfetto `TrackEvent` Protobuf payload.
 *        Tuần tự hóa một bản ghi `RecordedLynxTraceEvent` thành gói Protobuf `TrackEvent` của Perfetto.
 *
 * Field numbers matching `lynx::perfetto::TrackEvent` and `LynxDebugAnnotation`:
 * - Field 3 (`categories`): repeated string
 * - Field 9 (`type`): varint (`TYPE_SLICE_BEGIN=1`, `TYPE_SLICE_END=2`, `TYPE_INSTANT=3`, `TYPE_COUNTER=4`)
 * - Field 23 (`name`): string
 * - Field 30 (`counter_value`): sint64/varint
 */
std::vector<uint8_t> SerializePerfettoTrackEventProto(const RecordedLynxTraceEvent& ev) {
    std::vector<uint8_t> out;
    out.reserve(64u);

    // Field 9: TrackEvent::Type
    AppendTagAndVarint(out, 9u, static_cast<uint64_t>(ev.type));

    // Field 3: category
    if (!ev.category.empty()) {
        AppendTagAndString(out, 3u, ev.category);
    }

    // Field 23: name
    if (!ev.name.empty()) {
        AppendTagAndString(out, 23u, ev.name);
    }

    // Field 30: counter_value
    if (ev.type == TraceEventType::kCounter || ev.counter_value != 0u) {
        AppendTagAndVarint(out, 30u, ev.counter_value);
    }

    return out;
}

// ============================================================================
// 7. End-to-End Runtime Self-Test (`RunLibLynxTraceSelfTest`)
//    Hàm Tự Kiểm thử Thực thi Đầu-Cuối (`RunLibLynxTraceSelfTest`)
// ============================================================================

bool RunLibLynxTraceSelfTest() {
    ResetLynxTraceBssState();

    // 1. Verify JNI_OnLoad (0x00403c..0x0040f4) returns JNI_VERSION_1_6 (0x00010006)
    //    and populates .bss 0x00c018 (TraceController) and 0x00c020 (TraceEvent).
    if (ExecuteJniOnLoad(nullptr, nullptr) != kJniVersion1_6) {
        return false;
    }
    const LynxTraceBssSegment& bss = GetLynxTraceBssState();
    if (bss.trace_controller_class == nullptr || bss.trace_event_class == nullptr) {
        return false;
    }

    // 2. Verify TraceController::Instance() (0x0040fc..0x004158) & nativeCreateTraceController (0x0041c4)
    const jlong ctrl_ptr = TraceController_nativeCreateTraceController(nullptr, nullptr);
    if (ctrl_ptr == 0 || (bss.guard_var_trace_controller & 1u) != 1u) {
        return false;
    }
    auto* ctrl = reinterpret_cast<TraceController*>(ctrl_ptr);
    if (ctrl->StartTracing(nullptr) != -1 ||
        ctrl->StopTracing(0) != false ||
        ctrl->IsTracingStarted() != false ||
        !ctrl->GetStartupTracingConfig().empty() ||
        !ctrl->GetTraceFilePath(0).empty()) {
        return false;
    }

    // 3. Verify release-mode default parity (0x0041a4 / 0x0041ac / 0x0040f8)
    if (TraceEvent_nativeCategoryEnabled(nullptr, nullptr, nullptr) != kJniFalse ||
        TraceEvent_nativeSystemTraceEnabled(nullptr, nullptr) != kJniFalse ||
        TraceEvent_nativePerfettoTraceEnabled(nullptr, nullptr) != kJniFalse ||
        GetFlowIdImpl() != 0u ||
        GetTraceTimeNsImpl() != 0 ||
        ThreadTrack::Current().uuid != 0u) {
        return false;
    }

    // 4. Verify telemetry capture mode across TraceEventBeginEx / TraceEventEndEx / TraceCounterEx & TrackEvent
    SetTelemetryCaptureMode(true);
    TraceEventBeginEx("lynx", "RenderFrame");
    TraceCounterEx("lynx", "FrameTimeUs", 16667u, false);
    TraceEventEndEx("lynx", "RenderFrame");

    const auto events = GetRecordedLynxTraceEvents();
    if (events.size() != 3u ||
        events[0].type != TraceEventType::kBegin ||
        events[1].type != TraceEventType::kCounter ||
        events[1].counter_value != 16667u ||
        events[2].type != TraceEventType::kEnd) {
        return false;
    }

    // 5. Verify Perfetto Protobuf TrackEvent serializer produces non-empty wire payload
    const auto proto_bytes = SerializePerfettoTrackEventProto(events[1]);
    if (proto_bytes.empty()) {
        return false;
    }

    SetTelemetryCaptureMode(false);
    return kExportedDynSymTable.size() == 34u &&
           kRelaDynRelativeTable.size() == 62u &&
           kPltImportTable.size() == 10u &&
           kRodataStringDirectory.size() == 23u;
}

} // namespace lynxtrace
} // namespace opencut
} // namespace nextai
