# TÓM TẮT KIẾN TRÚC KỸ THUẬT: `libttmplayer.so` (BYTEDANCE TTPLAYER MULTIMEDIA ENGINE)

## 1. Thông tin Nhị phân Gốc (`apktool-res/lib/arm64-v8a/libttmplayer.so`)
- **Kích thước**: `3,594,936` bytes (`3.43 MB`, ELF 64-bit AArch64)
- **Phân vùng ELF**:
  - `.text`: `0x0967b0 .. 0x29a1dc` (`2,112,044` bytes)
  - `.rodata`: `0x29a1e0 .. 0x2dbe26` (`269,382` bytes)
  - `.data.rel.ro`: `0x3394e8 .. 0x36dd48` (`215,136` bytes)
  - `.data`: `0x370000 .. 0x371288` (`4,744` bytes)
  - `.bss`: `0x371288 .. 0x374190` (`12,040` bytes)
- **Tổng số ký hiệu động (`.dynsym`)**: `866` symbols (`75` hàm JNI gồm `3` direct JNI exports + `62` hàm `TTPlayer` + `4` hàm `TTPlayerStrategyCenter` + `6` hàm `AJMediaCodec`).

## 2. Cấu trúc Module Tái cấu trúc Sạch (`SOURCE/GIAI-MA/libttmplayer/`)
1. `ttmplayer_types.h`: Định nghĩa chuẩn ABI AArch64 cho `VString` (24 bytes), `Value` (32 bytes), `Parcel` (32 bytes), `AVDropFrameOperator`, `AVLoadControlOperator`, `AJMediaCodecBufferSlot` (32 bytes), `AJMediaCodecNative`, và `TTPlayerNativeContext`.
2. `ttmplayer_value_parcel.h` / `.cpp`: Hiện thực đầy đủ `com::ss::ttm::player::VString` (`0x16b464..0x16b6a8`), `Value` (`0x16b6c0..0x16bc00`), và `Parcel` (`0x16bc04..0x16ca2c`).
3. `ttmplayer_strategy_operators.h` / `.cpp`: Hiện thực `AVStrategyUtils::convertTTCodecIDToFF` (`0x1660cc -> 0x261f20`, bitmask `0x0003f1ffff7fffffULL` + bảng 50 phần tử tại `.rodata` `0x2cf040`), `setPlayerGlobalConfigIntValue` (`0x1660d0`), `getPlayerGlobalConfigIntValue` (`0x166124`), `mdlInfoCallback` (`0x0c4af8`), `AVDropFrameOperator` (`0x16cde8`), `AVLoadControlOperator` (`0x16ce04`), và `TTPlayerStrategyCenter`.
4. `ttmplayer_ajmediacodec_audio.h` / `.cpp`: Hiện thực bộ đệm vòng 64-khe không khóa `AJMediaCodec::onFilledBuffer` (`0x212b34`), `onFormatChanged` (`0x212bd0`), `register_FFmpegAudioDecoders` (`0x1e7fa4`), `unregister_FFmpegAudioDecoders` (`0x1e8b24`), và đường ống âm thanh `SAMICore`.
5. `ttmplayer_player_jni.h` / `.cpp`: Hiện thực `JNI_OnLoad` (`0x197174`), `JNI_OnUnload` (`0x197420`), 3 hàm JNI `.dynsym` và toàn bộ 62 phương thức native của `com/ss/ttm/player/TTPlayer`.
6. `ttmplayer_interface.h` / `.cpp` & `ttmplayer_pseudocode.cpp`: Lớp điều phối `TTMPlayerEngine` và bộ tự kiểm thử 7 giai đoạn `runSelfTest()`.
