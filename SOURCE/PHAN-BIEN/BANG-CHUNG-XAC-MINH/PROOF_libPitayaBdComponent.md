# BẰNG CHỨNG XÁC MINH NHỊ PHÂN & TOÁN HỌC: `libPitayaBdComponent.so` (TARGET 46)
# BINARY & MATHEMATICAL VERIFICATION PROOF: `libPitayaBdComponent.so` (TARGET 46)

## 1. Cổng Dung Lượng & Không Stub (Size Gate & Zero-Stub Proof)
- **Tổng dung lượng C++17 / Total C++17 Size**: `102,431` bytes trên `10` tệp `.cpp`/`.h` (`> 40,000` bytes gate, `0` stubs).
- **Nhị phân gốc / Original Binary**: `extracted/lib/arm64-v8a/libPitayaBdComponent.so` (`100,176` bytes, 60 dynamic symbols: 14 exported + 46 imported).

## 2. Đối Chiếu Opcode AArch64 Trực Tiếp (Direct AArch64 Opcode Parity)
1. **`Java_com_bytedance_pitaya_bdcomponentimpl_crash_NpthStackReporter_nativeGenerateAllStack` (`0x002780`, 132 B)**:
   - `0x0027a8: 94000017 bl #0x2804` (`pitaya::PitayaNpthUtil::Instance()`)
   - `0x0027bc: 97ffffa4 bl #0x264c` (`JStringToStdString`)
   - `0x0027c8: 94000034 bl #0x2898` (`pitaya::PitayaNpthUtil::GenerteTombstone`)
2. **`pitaya::PitayaNpthUtil::GenerteTombstone` (`0x002898`, 488 B)**:
   - `0x0028d8: 97ffff06 bl #0x24f0` (`npth_bt_all`)
   - `0x002970: 94000044 bl #0x2a80` (`ParseOriginStack`)
   - `0x0029a8: 52800841 mov w1, #0x42; 0x0029b0: 72a00101 movk w1, #8, lsl #16` (`flags = 0x80042` = `O_RDWR | O_CREAT | O_CLOEXEC`)
   - `0x0029b4: 52803002 mov w2, #0x180` (`mode = 0600`)
   - `0x0029dc: 940005af bl #0x4098` (`WriteThreadTombstone`)
   - `0x0029e0: 910182b5 add x21, x21, #0x60` (`sizeof(ThreadStackInfo) = 96` bytes)
3. **`Java_com_bytedance_pitaya_bdcomponentimpl_monitor_ALogPrinter_nativeGetFuncAddr` (`0x004c54`, 340 B)**:
   - `0x004c68: 52802041 mov w1, #0x102; 0x004c6c: 97fff60d bl #0x24a0` (`dlopen("libalog.so", 0x102)`)
   - `0x004c7c: 97fff5f9 bl #0x2460` (`dlsym(handle, "alog_write")`)
   - `0x004cd0: 97fff5dc bl #0x2440` (`npth_dlopen("libalog.so")`)
   - `0x004ce0: 97fff618 bl #0x2540` (`npth_dlsym(handle, "alog_write")`)

## 3. Chứng Minh Toán Học Nghịch Đảo Nhân 64-Bit (64-Bit Multiplicative Inverse Proof)
- Tại `0x002e54..0x002e68` (`ParseOriginStack`) và `0x0048e0..0x00490c` (`vector<ThreadStackInfo>::insert`), trình biên dịch Clang AArch64 sử dụng hằng số nghịch đảo nhân `0xaaaaaaaaaaaaaaabULL` (`-0x5555555555555556` + `movk #0xaaab`) vì:
  $$3 \times \text{0xaaaaaaaaaaaaaaab} = \text{0x20000000000000001} \equiv 1 \pmod{2^{64}}$$
- Khi chia độ lệch byte cho `24 = 8 * 3` (`sizeof(std::sub_match<const char*>)`):
  $$\frac{\Delta}{24} = (\Delta \gg 3) \times \text{0xaaaaaaaaaaaaaaab} \pmod{2^{64}}$$
- Khi chia độ lệch byte cho `96 = 32 * 3` (`sizeof(ThreadStackInfo)`):
  $$\frac{\Delta}{96} = (\Delta \gg 5) \times \text{0xaaaaaaaaaaaaaaab} \pmod{2^{64}}$$
