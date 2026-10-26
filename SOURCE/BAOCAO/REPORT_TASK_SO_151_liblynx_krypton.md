# Báo Cáo Hoàn Thành Tái Dựng Nhị Phân: `liblynx_krypton.so` (`TASK-097` / `TASK_SO_151`)

- **Thư viện mục tiêu**: `liblynx_krypton.so` (`51,112 bytes`)
- **Trạng thái nghiệm thu**: `VERIFIED_AND_ACCEPTED` (100%)
- **Hồ sơ bằng chứng đối kháng**: [`PROOF_liblynx_krypton.json`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/PHAN-BIEN/BANG-CHUNG-XAC-MINH/PROOF_liblynx_krypton.json) & [`PROOF_liblynx_krypton.md`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/PHAN-BIEN/BANG-CHUNG-XAC-MINH/PROOF_liblynx_krypton.md)
- **Thư mục mã nguồn C++17 tái dựng**: [`SOURCE/GIAI-MA/liblynx_krypton/`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/liblynx_krypton/) (`8` tập tin `.h`/`.cpp`, `0 stubs`)

## Tóm Tắt Kỹ Thuật (Technical Summary)

1. **`JNI_OnLoad` (`0x004ff4..0x005124`) & `.bss` (`0x00c000..0x00c047`)**:
   - Đăng ký `9` phương thức JNI thuộc `4` lớp Java trong `.data.rel.ro` (`0x008008..0x0081cf`) và lưu 4 tham chiếu `jclass` toàn cục tại `.bss 0x00c000`, `0x00c020`, `0x00c028`, `0x00c040`.
   - Trả về `JNI_VERSION_1_6` (`0x00010006`).
2. **`KryptonLogFunction` (`0x00403c..0x004148`) & `RuntimeLoadLynxTraceFunc` (`0x00416c..0x0042fc`)**:
   - Bảng nhảy 5 byte tại `.rodata 0x001970` (`{0x05, 0x09, 0x0b, 0x0d, 0x07}`) ánh xạ mức log `1..5` sang `1, 5, 3, 4, 2`.
   - Nạp động `liblynxtrace.so` qua `dlopen(..., RTLD_LAZY=2)` và `dlsym` (`TraceEventBeginEx`, `TraceEventEndEx`, `TraceCounterEx`) vào `.bss 0x00c008..0x00c01f` trước khi gọi `AttachKryptonTraceHandler`.
3. **`LynxCanvasDownStreamManager`, `LynxKryptonFrameService` & `UICanvasSurfaceView` (`0x004328..0x004ff0`)**:
   - Khởi tạo `SurfaceWithAndroidNativeWindow` (`32 B`) và `SurfaceConfig` (`72 B`, `packed_flags = 0x00010100`), điều phối closure `96 B` (`0x0080c8`) và `72 B` (`0x0080a0`) qua `TaskRunner::PostTask`.
   - Quản lý callback JNI `OnVSync(J)V` (`.bss 0x00c038`) và `OnBeforeVSyncEnd(J)V` (`.bss 0x00c030`).
