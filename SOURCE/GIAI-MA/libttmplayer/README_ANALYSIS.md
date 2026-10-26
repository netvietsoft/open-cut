# BÁO CÁO GIẢI MÃ KỸ THUẬT HOÀN CHỈNH: `libttmplayer.so`

- **Dung lượng nhị phân gốc**: `3,594,936` bytes (`3.43 MB`, ELF 64-bit AArch64)
- **Phân loại Lõi C++**: `CORE_04_MULTIMEDIA` (ByteDance TTPlayer Core Multimedia Playback, Hardware MediaCodec Ring-Buffer & ABR Strategy Engine)
- **Tổng số dynamic symbols**: `866`
- **Tổng số phương thức JNI**: `75` (`3` direct `.dynsym` exports + `62` `com/ss/ttm/player/TTPlayer` + `4` `com/ss/ttm/strategycenter/TTPlayerStrategyCenter` + `6` `com/ss/ttm/player/AJMediaCodec`)
- **Dung lượng mã nguồn C++17 tái dựng**: `12` tệp `.cpp`/`.h` (`0` stub, 100% chú thích song ngữ EN + VN)

## Danh mục Tệp Mã nguồn Tái cấu trúc
1. `ttmplayer_types.h`: Định nghĩa kiểu và bố cục ABI AArch64 (`VString`, `Value`, `Parcel`, `AJMediaCodecNative`, `TTPlayerNativeContext`).
2. `ttmplayer_value_parcel.h` / `ttmplayer_value_parcel.cpp`: Bộ tuần tự hóa `VString`, `Value`, `Parcel` (`0x16b464 .. 0x16ca2c`).
3. `ttmplayer_strategy_operators.h` / `ttmplayer_strategy_operators.cpp`: `AVStrategyUtils`, `AVDropFrameOperator`, `AVLoadControlOperator`, `mdlInfoCallback` (`0x0c4af8`), `TTPlayerStrategyCenter`.
4. `ttmplayer_ajmediacodec_audio.h` / `ttmplayer_ajmediacodec_audio.cpp`: Bộ đệm vòng 64-khe `AJMediaCodec` (`0x212b34 .. 0x21a9c8`), `register_FFmpegAudioDecoders` (`0x1e7fa4`), `unregister_FFmpegAudioDecoders` (`0x1e8b24`) và `SAMICore`.
5. `ttmplayer_player_jni.h` / `ttmplayer_player_jni.cpp`: `JNI_OnLoad` (`0x197174`), `JNI_OnUnload` (`0x197420`), 3 direct JNI exports và 62 phương thức `TTPlayer`.
6. `ttmplayer_interface.h` / `ttmplayer_interface.cpp` / `ttmplayer_pseudocode.cpp`: Động cơ `TTMPlayerEngine` & tự kiểm thử 7 giai đoạn.
