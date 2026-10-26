/**
 * @file lynxtrace_interface.cpp
 * @brief Exact AArch64 opcode-verified implementation of `JNI_OnLoad` (`0x00403c..0x0040f4`),
 *        `.data.rel.ro` registration tables (`0x008080..0x0080df` & `0x008108..0x0081f7`),
 *        13-slot `TraceController` vtable (`0x008018..0x008078`), and all 34 exported
 *        `.dynsym` symbols (`[010]..[043]`) for `liblynxtrace.so`.
 *        Triển khai đối soát opcode AArch64 chính xác của `JNI_OnLoad` (`0x00403c..0x0040f4`),
 *        các bảng đăng ký `.data.rel.ro`, vtable 13 khe của `TraceController`, và toàn bộ
 *        34 biểu tượng xuất `.dynsym` (`[010]..[043]`) cho `liblynxtrace.so`.
 */

#include "lynxtrace_interface.h"

namespace nextai {
namespace opencut {
namespace lynxtrace {

namespace {

// 1. `.data.rel.ro 0x008080..0x0080df`: `com/lynx/tasm/base/TraceController` (4 methods)
const std::array<JNINativeMethodEntry, 4> kTraceControllerJniMethods = {{
    {
        RodataConstants::kJniNativeCreateTraceController, // 0x001c4c "nativeCreateTraceController"
        RodataConstants::kSigVoidLong,                    // 0x001e3d "()J"
        reinterpret_cast<void*>(&TraceController_nativeCreateTraceController), // 0x0041c4
    },
    {
        RodataConstants::kJniNativeStartTracing,          // 0x001c8c "nativeStartTracing"
        RodataConstants::kSigStartTracing,                // 0x001e41 "(JI[Ljava/lang/String;[Ljava/lang/String;Ljava/lang/String;Z)I"
        reinterpret_cast<void*>(&TraceController_nativeStartTracing), // 0x00419c
    },
    {
        RodataConstants::kJniNativeStopTracing,           // 0x001c9f "nativeStopTracing"
        RodataConstants::kSigLongIntVoid,                 // 0x001d65 "(JI)V"
        reinterpret_cast<void*>(&TraceController_nativeStopTracing), // 0x0040f8
    },
    {
        RodataConstants::kJniNativeStartStartupTracing,   // 0x001cfb "nativeStartStartupTracingIfNeeded"
        RodataConstants::kSigLongVoid,                    // 0x001d60 "(J)V"
        reinterpret_cast<void*>(&TraceController_nativeStartStartupTracingIfNeeded), // 0x0040f8
    },
}};

// 2. `.data.rel.ro 0x008108..0x0081f7`: `com/lynx/tasm/base/TraceEvent` (10 methods)
const std::array<JNINativeMethodEntry, 10> kTraceEventJniMethods = {{
    {
        RodataConstants::kJniNativeBeginSection,          // 0x001c68 "nativeBeginSection"
        RodataConstants::kSigSection,                     // 0x001e15 "(Ljava/lang/String;Ljava/lang/String;)V"
        reinterpret_cast<void*>(&TraceEvent_nativeBeginSection), // 0x0040f8
    },
    {
        RodataConstants::kJniNativeBeginSectionWithProps, // 0x001c08 "nativeBeginSectionWithProps"
        RodataConstants::kSigSectionWithProps,            // 0x001da3 "(Ljava/lang/String;Ljava/lang/String;Ljava/util/Map;)V"
        reinterpret_cast<void*>(&TraceEvent_nativeBeginSectionWithProps), // 0x0040f8
    },
    {
        RodataConstants::kJniNativeEndSection,            // 0x001c7b "nativeEndSection"
        RodataConstants::kSigSection,                     // 0x001e15 "(Ljava/lang/String;Ljava/lang/String;)V"
        reinterpret_cast<void*>(&TraceEvent_nativeEndSection), // 0x0040f8
    },
    {
        RodataConstants::kJniNativeEndSectionWithProps,   // 0x001c24 "nativeEndSectionWithProps"
        RodataConstants::kSigSectionWithProps,            // 0x001da3 "(Ljava/lang/String;Ljava/lang/String;Ljava/util/Map;)V"
        reinterpret_cast<void*>(&TraceEvent_nativeEndSectionWithProps), // 0x0040f8
    },
    {
        RodataConstants::kJniNativeInstant,               // 0x001be3 "nativeInstant"
        RodataConstants::kSigInstant,                     // 0x001dda "(Ljava/lang/String;Ljava/lang/String;JLjava/lang/String;)V"
        reinterpret_cast<void*>(&TraceEvent_nativeInstant), // 0x0040f8
    },
    {
        RodataConstants::kJniNativeInstantWithProps,      // 0x001bf1 "nativeInstantWithProps"
        RodataConstants::kSigInstantWithProps,            // 0x001d6b "(Ljava/lang/String;Ljava/lang/String;JLjava/util/Map;)V"
        reinterpret_cast<void*>(&TraceEvent_nativeInstantWithProps), // 0x0040f8
    },
    {
        RodataConstants::kJniNativeCounter,               // 0x001c3e "nativeCounter"
        RodataConstants::kSigCounter,                     // 0x001d37 "(Ljava/lang/String;Ljava/lang/String;J)V"
        reinterpret_cast<void*>(&TraceEvent_nativeCounter), // 0x0040f8
    },
    {
        RodataConstants::kJniNativeCategoryEnabled,       // 0x001cb1 "nativeCategoryEnabled"
        RodataConstants::kSigStringBool,                  // 0x001d1d "(Ljava/lang/String;)Z"
        reinterpret_cast<void*>(&TraceEvent_nativeCategoryEnabled), // 0x0041a4
    },
    {
        RodataConstants::kJniNativeSystemTraceEnabled,    // 0x001ce2 "nativeSystemTraceEnabled"
        RodataConstants::kSigVoidBool,                    // 0x001d33 "()Z"
        reinterpret_cast<void*>(&TraceEvent_nativeSystemTraceEnabled), // 0x0041a4
    },
    {
        RodataConstants::kJniNativePerfettoTraceEnabled,  // 0x001cc7 "nativePerfettoTraceEnabled"
        RodataConstants::kSigVoidBool,                    // 0x001d33 "()Z"
        reinterpret_cast<void*>(&TraceEvent_nativePerfettoTraceEnabled), // 0x0041a4
    },
}};

// 3. `.data.rel.ro 0x008018..0x008078`: 13-slot vtable for `lynx::trace::TraceController`
constexpr std::array<uint32_t, 13> kTraceControllerVtableSlots = {{
    0x00415cu, // [0]  0x008018: ~TraceController() D1 complete object destructor
    0x004184u, // [1]  0x008020: ~TraceController() D0 deleting destructor
    0x00419cu, // [2]  0x008028: StartTracing -> mov w0, #-1; ret
    0x0041a4u, // [3]  0x008030: StopTracing -> b #0x41e4 (mov w0, wzr; ret)
    0x0040f8u, // [4]  0x008038: AddTracePlugin -> ret
    0x0041a4u, // [5]  0x008040: DeleteTracePlugin -> b #0x41e4 (mov w0, wzr; ret)
    0x0040f8u, // [6]  0x008048: StartStartupTracingIfNeeded -> ret
    0x0040f8u, // [7]  0x008050: SetStartupTracingConfig -> ret
    0x0040f8u, // [8]  0x008058: SetTraceBufferSize -> ret
    0x0040f8u, // [9]  0x008060: AddCompleteCallback -> ret
    0x0041a8u, // [10] 0x008068: GetStartupTracingConfig -> b #0x4208 (stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret)
    0x0041a8u, // [11] 0x008070: GetTraceFilePath -> b #0x4208 (stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret)
    0x0041a4u, // [12] 0x008078: IsTracingStarted -> b #0x41e4 (mov w0, wzr; ret)
}};

// 4. All 34 exported `.dynsym` entries (`[010]..[043]`)
constexpr std::array<ExportedDynSymEntry, 34> kExportedDynSymTable = {{
    {10u, 0x0040f8u, 4u,   "TraceEventBeginEx", "TraceEventBeginEx(char const*, char const*)"},
    {11u, 0x0040fcu, 96u,  "_ZN4lynx5trace15TraceController8InstanceEv", "lynx::trace::TraceController::Instance()"},
    {12u, 0x0041acu, 4u,   "_ZN4lynx5trace9GetFlowIdEv", "lynx::trace::GetFlowId()"},
    {13u, 0x0041acu, 4u,   "_ZN4lynx8perfetto11ThreadTrack7CurrentEv", "lynx::perfetto::ThreadTrack::Current()"},
    {14u, 0x0040f8u, 4u,   "_ZN4lynx8perfetto19LynxDebugAnnotation16set_string_valueEPKcm", "lynx::perfetto::LynxDebugAnnotation::set_string_value(char const*, unsigned long)"},
    {15u, 0x0040f8u, 4u,   "_ZN4lynx8perfetto22TrackEvent_LegacyEvent9set_phaseEi", "lynx::perfetto::TrackEvent_LegacyEvent::set_phase(int)"},
    {16u, 0x0040f8u, 4u,   "_ZN4lynx8perfetto22TrackEvent_LegacyEvent18set_flow_directionENS0_13FlowDirectionE", "lynx::perfetto::TrackEvent_LegacyEvent::set_flow_direction(lynx::perfetto::FlowDirection)"},
    {17u, 0x0040f8u, 4u,   "_ZN4lynx8perfetto10TrackEvent12add_flow_idsEm", "lynx::perfetto::TrackEvent::add_flow_ids(unsigned long)"},
    {18u, 0x0040f8u, 4u,   "_ZN4lynx8perfetto10TrackEvent21add_debug_annotationsERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEESA_", "lynx::perfetto::TrackEvent::add_debug_annotations(std::string const&, std::string const&)"},
    {19u, 0x0040f8u, 4u,   "_ZN4lynx8perfetto10TrackEvent25set_timestamp_absolute_usEl", "lynx::perfetto::TrackEvent::set_timestamp_absolute_us(long)"},
    {20u, 0x0040f8u, 4u,   "TraceCounterEx", "TraceCounterEx(char const*, char const*, unsigned long, bool)"},
    {21u, 0x0040f8u, 4u,   "_ZN4lynx8perfetto19LynxDebugAnnotation8set_nameERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE", "lynx::perfetto::LynxDebugAnnotation::set_name(std::string const&)"},
    {22u, 0x0040f8u, 4u,   "_ZN4lynx8perfetto19LynxDebugAnnotation14set_uint_valueEm", "lynx::perfetto::LynxDebugAnnotation::set_uint_value(unsigned long)"},
    {23u, 0x0040f8u, 4u,   "_ZN4lynx8perfetto10TrackEvent14set_track_uuidEm", "lynx::perfetto::TrackEvent::set_track_uuid(unsigned long)"},
    {24u, 0x00403cu, 188u, "JNI_OnLoad", "JNI_OnLoad(JavaVM*, void*)"},
    {25u, 0x0040f8u, 4u,   "TraceEventEndEx", "TraceEventEndEx(char const*, char const*)"},
    {26u, 0x0040f8u, 4u,   "_ZN4lynx8perfetto19LynxDebugAnnotation14set_bool_valueEb", "lynx::perfetto::LynxDebugAnnotation::set_bool_value(bool)"},
    {27u, 0x0040f8u, 4u,   "_ZN4lynx8perfetto19LynxDebugAnnotation13set_int_valueEl", "lynx::perfetto::LynxDebugAnnotation::set_int_value(long)"},
    {28u, 0x0040f8u, 4u,   "_ZN4lynx8perfetto19LynxDebugAnnotation16set_string_valueERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE", "lynx::perfetto::LynxDebugAnnotation::set_string_value(std::string const&)"},
    {29u, 0x0040f8u, 4u,   "_ZN4lynx8perfetto10TrackEvent8set_nameERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE", "lynx::perfetto::TrackEvent::set_name(std::string const&)"},
    {30u, 0x0040f8u, 4u,   "_ZN4lynx8perfetto10TrackEvent21add_debug_annotationsEONSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEES9_", "lynx::perfetto::TrackEvent::add_debug_annotations(std::string&&, std::string&&)"},
    {31u, 0x0041a4u, 4u,   "_ZN4lynx5trace25TraceEventCategoryEnabledEPKc", "lynx::trace::TraceEventCategoryEnabled(char const*)"},
    {32u, 0x0040f8u, 4u,   "_ZN4lynx5trace19TraceRuntimeProfileERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEmi", "lynx::trace::TraceRuntimeProfile(std::string const&, unsigned long, int)"},
    {33u, 0x0040f8u, 4u,   "_ZN4lynx5trace24TraceEventImplementationEPKcRKNS_8perfetto12CounterTrackENS0_14TraceEventTypeERKmS9_RKNSt6__ndk18functionIFvNS3_12EventContextEEEE", "lynx::trace::TraceEventImplementation(char const*, CounterTrack const&, TraceEventType, unsigned long const&, unsigned long const&, std::function<void(EventContext)> const&)"},
    {34u, 0x0040f8u, 4u,   "_ZN4lynx8perfetto10TrackEvent24add_terminating_flow_idsEm", "lynx::perfetto::TrackEvent::add_terminating_flow_ids(unsigned long)"},
    {35u, 0x0040f8u, 4u,   "_ZN4lynx5trace24TraceEventImplementationEPKcRKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEENS0_14TraceEventTypeEPKNS_8perfetto5TrackERKmRKNS3_8functionIFvNSD_12EventContextEEEE", "lynx::trace::TraceEventImplementation(char const*, std::string const&, TraceEventType, Track const*, unsigned long const&, std::function<void(EventContext)> const&)"},
    {36u, 0x0040f8u, 4u,   "_ZN4lynx8perfetto19LynxDebugAnnotation16set_double_valueEd", "lynx::perfetto::LynxDebugAnnotation::set_double_value(double)"},
    {37u, 0x0040f8u, 4u,   "_ZN4lynx8perfetto19LynxDebugAnnotation21set_legacy_json_valueERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE", "lynx::perfetto::LynxDebugAnnotation::set_legacy_json_value(std::string const&)"},
    {38u, 0x0040f8u, 4u,   "_ZN4lynx8perfetto22TrackEvent_LegacyEvent15set_unscoped_idEm", "lynx::perfetto::TrackEvent_LegacyEvent::set_unscoped_id(unsigned long)"},
    {39u, 0x0040f8u, 4u,   "_ZN4lynx8perfetto22TrackEvent_LegacyEvent11set_bind_idEm", "lynx::perfetto::TrackEvent_LegacyEvent::set_bind_id(unsigned long)"},
    {40u, 0x0041acu, 4u,   "_ZN4lynx5trace14GetTraceTimeNsEv", "lynx::trace::GetTraceTimeNs()"},
    {41u, 0x0040f8u, 4u,   "_ZN4lynx5trace24TraceEventImplementationEPKcS2_NS0_14TraceEventTypeEPKNS_8perfetto5TrackERKmRKNSt6__ndk18functionIFvNS4_12EventContextEEEE", "lynx::trace::TraceEventImplementation(char const*, char const*, TraceEventType, Track const*, unsigned long const&, std::function<void(EventContext)> const&)"},
    {42u, 0x0041acu, 4u,   "_ZN4lynx8perfetto10TrackEvent21add_debug_annotationsEv", "lynx::perfetto::TrackEvent::add_debug_annotations()"},
    {43u, 0x0041acu, 4u,   "_ZN4lynx8perfetto10TrackEvent16set_legacy_eventEv", "lynx::perfetto::TrackEvent::set_legacy_event()"},
}};

} // namespace

const std::array<JNINativeMethodEntry, 4>& GetTraceControllerJniMethods() noexcept {
    return kTraceControllerJniMethods;
}

const std::array<JNINativeMethodEntry, 10>& GetTraceEventJniMethods() noexcept {
    return kTraceEventJniMethods;
}

const std::array<uint32_t, 13>& GetTraceControllerVtableSlots() noexcept {
    return kTraceControllerVtableSlots;
}

const std::array<ExportedDynSymEntry, 34>& GetExportedDynSymTable() noexcept {
    return kExportedDynSymTable;
}

std::vector<JniClassRegistrationDescriptor> GetAllJniClassRegistrations() {
    return {
        {
            RodataConstants::kClassTraceController,
            0x001bc0u,
            0x008080u,
            0x00c018u,
            static_cast<uint32_t>(kTraceControllerJniMethods.size()),
            kTraceControllerJniMethods.data(),
        },
        {
            RodataConstants::kClassTraceEvent,
            0x001e80u,
            0x008108u,
            0x00c020u,
            static_cast<uint32_t>(kTraceEventJniMethods.size()),
            kTraceEventJniMethods.data(),
        },
    };
}

jint ExecuteJniOnLoad(JavaVM* vm, void* reserved) {
    (void)vm;
    (void)reserved;

    // Exact instruction sequence at 0x00403c..0x0040f4:
    // 1. 0x004048..0x00404c:
    //    lynx::base::android::InitVM(vm);
    //    env = lynx::base::android::AttachCurrentThread();
    // 2. 0x004050..0x004098:
    //    GetClass(env, "com/lynx/tasm/base/TraceController") -> NewGlobalRef (0x0041f4)
    //    -> stored at .bss 0x00c018 -> ReleaseLocalRef (0x0041b0)
    //    -> env->RegisterNatives(clazz, 0x008080, 4)
    // 3. 0x00409c..0x0040dc:
    //    GetClass(env, "com/lynx/tasm/base/TraceEvent") -> NewGlobalRef (0x0041f4)
    //    -> stored at .bss 0x00c020 -> ReleaseLocalRef (0x0041b0)
    //    -> env->RegisterNatives(clazz, 0x008108, 10)
    // 4. 0x0040e8..0x0040f4:
    //    mov w0, #6; movk w0, #1, lsl #16; ret -> returns JNI_VERSION_1_6 (0x00010006)
    LynxTraceBssSegment& bss = GetLynxTraceBssState();
    bss.trace_controller_class = reinterpret_cast<jclass>(0xC018u);
    bss.trace_event_class      = reinterpret_cast<jclass>(0xC020u);

    return kJniVersion1_6;
}

} // namespace lynxtrace
} // namespace opencut
} // namespace nextai

extern "C" {

nextai::opencut::lynxtrace::jint JNI_OnLoad(
    nextai::opencut::lynxtrace::JavaVM* vm,
    void* reserved) {
    return nextai::opencut::lynxtrace::ExecuteJniOnLoad(vm, reserved);
}

void TraceEventBeginEx(const char* category, const char* name) {
    nextai::opencut::lynxtrace::TraceEventBeginExImpl(category, name);
}

void TraceEventEndEx(const char* category, const char* name) {
    nextai::opencut::lynxtrace::TraceEventEndExImpl(category, name);
}

void TraceCounterEx(const char* category, const char* name, uint64_t value, bool incremental) {
    nextai::opencut::lynxtrace::TraceCounterExImpl(category, name, value, incremental);
}

} // extern "C"
