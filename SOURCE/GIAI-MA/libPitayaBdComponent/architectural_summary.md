# TÓM TẮT KIẾN TRÚC: `libPitayaBdComponent.so` (TARGET 46)
# ARCHITECTURAL SUMMARY: `libPitayaBdComponent.so` (TARGET 46)

## 1. Phân Hệ Cốt Lõi (Core Subsystems)
1. **`pitayabdcomponent_types.h` (`10,579 B`)**:
   - Toàn bộ hằng số chuỗi `.rodata` (`0x01230c..0x0124c3`) bao gồm các chuỗi dùng chung đuôi (`+5` bytes: `0x012458`, `0x012484`, `0x0124b8`), cờ `0x80042` / `0x180`, và cấu trúc `ThreadStackInfo` (`96` bytes = `0x60`).
2. **`pitayabdcomponent_npth_tombstone.h` / `.cpp` (`36,501 B`)**:
   - Toàn bộ `pitaya::PitayaNpthUtil` (`72` bytes = `0x48` @ `0x002848`): `Instance()` (`0x002804`), `GenerteTombstone` (`0x002898`), `ParseOriginStack` (`0x002a80`), `WriteThreadTombstone` (`0x004098`), `WriteBuildIds` (`0x004258`), `GetBuildIdForSo` (`0x00447c`), và máy trạng thái 4 khoảng trắng `ExtractSoPathFromFrame` (`0x004568`).
3. **`pitayabdcomponent_regex_stream.h` / `.cpp` (`23,258 B`)**:
   - Tái tạo `NdkStringBuf` (`seekoff` @ `0x005044`, `xsgetn` @ `0x005190`, `underflow` @ `0x0052c0`, `pbackfail` @ `0x005370`, `overflow` @ `0x005444`, `str` @ `0x005c50`), `RegexStreamEngine::GetLine` (`0x005e14`), `RegexSearchGroups` (`0x00de34` / `0x00e080`), và `InsertThreadStackInfoAtFront` (`0x0048b8`).
4. **`pitayabdcomponent_alog_jni.h` / `.cpp` (`18,795 B`)**:
   - Tái tạo `JStringToStdString` (`0x00264c`), `Java_com_bytedance_pitaya_bdcomponentimpl_crash_NpthStackReporter_nativeGenerateAllStack` (`0x002780`), và `Java_com_bytedance_pitaya_bdcomponentimpl_monitor_ALogPrinter_nativeGetFuncAddr` (`0x004c54`).
5. **`PitayaBdComponent_interface.h` / `pitayabdcomponent_interface.cpp` / `PitayaBdComponent_pseudocode.cpp` (`13,298 B`)**:
   - Bảng điều phối ký hiệu xuất khẩu và bộ tự kiểm thử khép kín 7 giai đoạn `RunSelfTest()`.
