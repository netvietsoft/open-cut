# Bằng Chứng Xác Minh Đối Kháng: `liblynx_krypton.so` (`TASK-097` / `TASK_SO_151`)

> **Thư viện mục tiêu**: `liblynx_krypton.so` (`51,112 bytes`, ELF64 AArch64)  
> **Trạng thái nghiệm thu**: `VERIFIED_AND_ACCEPTED`  
> **Phân loại bằng chứng**: `OBSERVED` (100% Disassembly & Relocation Table Proof)

---

## 1. Bằng Chứng 1: Bảng Nhảy 5 Mức Log Trong `KryptonLogFunction` (`0x00403c..0x004148` & `.rodata 0x001970`)

Tại `.text 0x00406c..0x0040c0`, hàm callback log của Krypton kiểm tra `GetMinLogLevel()` (`0x005270`), sau đó ánh xạ tham số `int level` (`w21`) sang mức độ nghiêm trọng của `lynx::base::logging::LogMessage` bằng bảng nhảy 5 byte tại `.rodata 0x001970`:

```asm
0x004054: sub  w8, w0, #1              ; w8 = level - 1
0x004064: cmp  w8, #4                  ; Kiểm tra level nằm trong [1..5]
0x00406c: b.hi #0x40ec                 ; Ngoài miền -> nhảy tới 0x0040ec (mov w3, wzr)
0x004070: adrp x9, #0x1000
0x004074: add  x9, x9, #0x970          ; .rodata 0x001970 = {0x00, 0x05, 0x0a, 0x0f, 0x14}
0x004078: adr  x10, #0x4088
0x00407c: ldrb w11, [x9, x8]
0x004080: add  x10, x10, x11, lsl #2   ; PC = 0x004088 + w11 * 4
0x004084: br   x10
```

- `level = 1` (`w8 = 0`, `w11 = 0x00`) $\rightarrow$ `0x004088 + 0 = 0x004088`: `mov w3, #1` (`LOG_INFO`)
- `level = 2` (`w8 = 1`, `w11 = 0x05`) $\rightarrow$ `0x004088 + 20 = 0x00409c`: `mov w3, #5` (`LOG_FATAL`)
- `level = 3` (`w8 = 2`, `w11 = 0x0a`) $\rightarrow$ `0x004088 + 40 = 0x0040b0`: `mov w3, #3` (`LOG_ERROR`)
- `level = 4` (`w8 = 3`, `w11 = 0x0f`) $\rightarrow$ `0x004088 + 60 = 0x0040c4`: `mov w3, #4` (`LOG_REPORT`)
- `level = 5` (`w8 = 4`, `w11 = 0x14`) $\rightarrow$ `0x004088 + 80 = 0x0040d8`: `mov w3, #2` (`LOG_WARNING`)

---

## 2. Bằng Chứng 2: Nạp Động `liblynxtrace.so` Trong `RuntimeLoadLynxTraceFunc` (`0x00416c..0x004324`)

- Kiểm tra `.bss 0x00c008` (`ldr x8, [x19, #8]; cbz x8, #0x4200` @ `0x004198`).
- Khi chưa nạp, gọi `dlopen("liblynxtrace.so", RTLD_LAZY = 2)` (`mov w1, #2; bl #0x52e0` @ `0x00421c..0x004220`).
- Phân giải 3 biểu tượng qua `dlsym` (`0x0052f0`):
  - `"TraceEventBeginEx"` (`0x0019a2`) $\rightarrow$ `.bss 0x00c008`
  - `"TraceEventEndEx"` (`0x0019b4`) $\rightarrow$ `.bss 0x00c010`
  - `"TraceCounterEx"` (`0x001993`) $\rightarrow$ `.bss 0x00c018`
- Sao chép cấu trúc 24-byte `KryptonTraceFunctions` lên stack (`ldur q0, [x19, #8]; ldr x8, [x19, #0x18]; str q0, [sp, #0x18]; str x8, [sp, #0x28]` @ `0x0041a0..0x0041b0`) và gọi `lynx::canvas::AttachKryptonTraceHandler` (`0x0052d0`).

---

## 3. Bằng Chứng 3: Quản Lý Downstream Surface & Bố Cục `SurfaceConfig` 72-Byte (`0x004328..0x004b44`)

- `nativeAddSurface` (`0x004328..0x0045b8`):
  - Giải bọc `std::weak_ptr<CanvasAppAndroid>` (`0x005320`) và khóa thành `std::shared_ptr` (`0x005330`).
  - Gọi `ANativeWindow_fromSurface(env, jsurface)` (`0x005340`) và cấp phát `32 bytes` (`mov w0, #0x20; bl operator new` @ `0x0043ac`) cho `lynx::canvas::SurfaceWithAndroidNativeWindow`.
  - Tại `0x004a2c..0x004aa0`, khởi tạo `SurfaceConfig` (`72 bytes` trên stack `[sp, #8..#0x4c]`) với cờ `packed_flags = 0x00010100` (`mov w8, #0x10100; str w8, [sp, #0x24]` @ `0x004a7c..0x004a84`) và gọi `PlatformViewObserver::OnSurfaceCreated` (`0x005420`).
  - Nếu gọi khác luồng `TaskRunner` (`vtable + 0x08` @ `0x005158`), cấp phát closure `96 bytes` (`mov w0, #0x60` @ `0x004538`, vtable `.data.rel.ro 0x0080c8`) và đẩy vào `TaskRunner::PostTask` (`0x0053e0`).

---

## 4. Bằng Chứng 4: Bảng Đăng Ký 4 Lớp JNI Trong `JNI_OnLoad` (`0x004ff4..0x005124`)

1. `com/lynx/canvas/CanvasManager` (`0x001975`, `.bss 0x00c000`, `.data.rel.ro 0x008008`, `2` phương thức: `nativeGetLogFunctionPtr`, `nativeRegisterTraceFunc`).
2. `com/lynx/canvas/LynxCanvasDownStreamManager` (`0x001c98`, `.bss 0x00c020`, `.data.rel.ro 0x008060`, `2` phương thức: `nativeAddSurface`, `nativeRemoveSurface`).
3. `com/lynx/canvas/LynxKryptonFrameService` (`0x001cc4`, `.bss 0x00c028`, `.data.rel.ro 0x0080e0`, `4` phương thức: `nativeCreateFrameService`, `nativeDestroyFrameService`, `nativeDoRequestVSync`, `nativeDoRegisterBeforeVSyncEndListener`).
4. `com/lynx/canvas/UICanvasSurfaceView` (`0x001cec`, `.bss 0x00c040`, `.data.rel.ro 0x0081b8`, `1` phương thức: `nativeCreateSurface`).
5. Giá trị trả về: `0x00010006` (`JNI_VERSION_1_6` qua `mov w0, #0x6; movk w0, #0x1, lsl #16` @ `0x00510c..0x005110`).
