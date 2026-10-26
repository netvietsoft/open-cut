# Phân Tích Kiến Trúc & Giải Mã Nhị Phân `liborbuculumadapter.so` (Bilingual Architectural & Binary Analysis)

> **Tệp nhị phân gốc / Target Binary**: `SOURCE/apktool-res/lib/arm64-v8a/liborbuculumadapter.so`  
> **Dung lượng / Exact Size**: `149,936 bytes` (`0x249B0` bytes)  
> **Mã băm / SHA-256**: `c79326a4419e98be93ce70b6b08f70a82852980d7322dadb3d5edac7ea179785`  
> **Kiến trúc / Architecture**: AArch64 (`arm64-v8a`), Android NDK clang++ (`libc++_shared.so`)  
> **Thư viện phụ thuộc / Needed Libraries**: `libshadowhook.so`, `liblog.so`, `libc.so`, `libm.so`, `libdl.so`  
> **Thư viện nạp động / Dynamic `dlopen` Peers**: `liborbuculum.so`, `libpumbaa-network.so`  
> **Task ID**: `TASK-113-RECONSTRUCTION-LIBORBUCULUMADAPTER` (`TASK_SO_129_liborbuculumadapter`)

---

## 1. Tổng Quan Kiến Trúc (Architectural Overview)

**[EN]** `liborbuculumadapter.so` is the native JNI & ShadowHook bridge connecting the Java compliance/sandbox layer (`com.orbu.core.init.TTKNativeNetworkManager` and `com.orbu.core.init.TTKNativeLiveSeiFieldManager`) with ByteDance's native network compliance engines (`liborbuculum.so` and `libpumbaa-network.so`). Instead of exporting its C entry points only through the ELF `.dynsym` table, `liborbuculumadapter.so` uses `libshadowhook.so` to hook `libc.so`'s `setenv` and `getenv` functions (`0x011db4..0x012354`) and exposes 5 core validation function pointers formatted as `"%p"` strings inside a 5-entry lookup table at `.bss 0x028930`.

**[VN]** `liborbuculumadapter.so` là cầu nối JNI & ShadowHook native kết nối tầng kiểm soát tuân thủ/sandbox trên Java (`com.orbu.core.init.TTKNativeNetworkManager` và `com.orbu.core.init.TTKNativeLiveSeiFieldManager`) với các engine tuân thủ mạng native của ByteDance (`liborbuculum.so` và `libpumbaa-network.so`). Thay vì chỉ xuất các điểm vào C qua bảng `.dynsym` của ELF, `liborbuculumadapter.so` sử dụng `libshadowhook.so` để hook hai hàm `setenv` và `getenv` của `libc.so` (`0x011db4..0x012354`) và công bố 5 con trỏ hàm xác thực cốt lõi dưới dạng chuỗi địa chỉ `"%p"` trong bảng tra cứu 5 mục tại `.bss 0x028930`.

---

## 2. Bố Cục Các Phân Đoạn ELF (ELF Section Layout)

| Phân đoạn (Section) | Địa chỉ ảo (Virtual Address) | Kích thước (Size) | Mô tả chi tiết (EN / VN Description) |
|---|---|---|---|
| `.dynsym` | `0x000768` | `0x0013b0` (`147` entries) | `117` imported symbols (`shadowhook_*`, `sigsetjmp`, `dlopen`, `pthread_*`), `27` exported symbols (`JNI_OnLoad`, `JNI_OnUnload`, STL helpers) |
| `.plt` | `0x003dd0` | `0x000690` (`103` stubs) | Procedure Linkage Table stubs (`0x003dd0..0x004450`) |
| `.text` | `0x004460` | `0x01628c` (`90,764` bytes) | `22,691` AArch64 instructions implementing JNI bridges, parsers, ShadowHook table, ThreadPool, and SignalCrashGuard |
| `.rodata` | `0x01a6f0` | `0x001205` (`4,613` bytes) | JNI class/method signatures, log strings (`orbu.culumadapter`), default schemes, DFID constants |
| `.init_array` | `0x027638` | `0x000018` (`3` pointers) | Static constructors at `0x004460`, `0x0044ac`, and `0x0044c8` |
| `.data` | `0x028000` | `0x000158` (`344` bytes) | 8-entry `JNINativeMethod` table (`0x028000..0x0280b8`) & crash signal array (`SIGSEGV=11`, `SIGBUS=7`, `SIGABRT=6` at `0x02814c`) |
| `.bss` | `0x028160` | `0x000e70` (`3,696` bytes) | Global runtime state (`0x028160..0x028fd0`): `JavaVM*`, `NetConfigRepository`, `BlockSnapshot`, `EnvExportEntry[5]`, `SandboxThreadPool` |

---

## 3. Bảng 8 Phương Thức JNI `RegisterNatives` (`.data 0x028000..0x0280b8`)

Trong `JNI_OnLoad` (`0x004540..0x0049fc`), thư viện tìm lớp `com/orbu/core/init/TTKNativeNetworkManager` (`.rodata 0x01a8dc`) và gọi `env->RegisterNatives(cls, 0x028000, 8)`:

| Chỉ số | Địa chỉ `.data` | Tên phương thức Java | Chữ ký JNI (Signature) | Địa chỉ hàm `.text` | Chức năng (EN / VN) |
|---|---|---|---|---|---|
| `[0]` | `0x028000` | `activesdk` | `(IZI)I` | `0x004f6c` | Lưu `sdk_enable_strategy` (`0x028220`), `pumbaa_strategy` (`0x028224`) và gắn 3 con trỏ upcall (`0x028230..0x028240`) |
| `[1]` | `0x028018` | `initcall` | `(IZ)I` | `0x004fec` | Lưu `sdk_report_strategy` (`0x028228`), `hit_sample_drop` (`0x02822c`) và gọi `hookAndSetupEnv` (`0x012050`) |
| `[2]` | `0x028030` | `initnetconfig` | `(Lcom/orbu/core/config/BootConfig;)V` | `0x005058` | Phân tích `BootConfig` & `AgConfig` vào `NetConfigRepository` (`0x028248`, `240 bytes`) |
| `[3]` | `0x028048` | `unhook` | `()V` | `0x005c24` | Nhảy tới `0x012358` gỡ hook `setenv` (`0x028868`) và `getenv` (`0x028870`) qua `shadowhook_unhook` |
| `[4]` | `0x028060` | `doNativeNetworkValidate` | `(Ljava/lang/String;Ljava/lang/String;Ljava/util/Map;Ljava/lang/String;ILjava/lang/String;I)I` | `0x005c28` | Trích xuất `Map` header Java và xác thực yêu cầu mạng qua `orbuculumIsProceedRequestForTTNet` (`0x00eb48`) |
| `[5]` | `0x028078` | `setNativeHardBlockConfigInner` | `(ZZZLjava/util/List;Ljava/util/List;)V` | `0x006874` | Trích xuất `allowCodeList` & `allowDfidList`, hoán đổi nguyên tử `std::shared_ptr<BlockSnapshot>` (`0x028340`) |
| `[6]` | `0x028090` | `isNativeNetworkResultNeedBlock` | `(ILjava/lang/String;)Z` | `0x007174` | Đánh giá kết quả xác thực mạng có cần chặn cứng hay không (`0x00cfc0..0x00d27c`) |
| `[7]` | `0x0280a8` | `setNativeDebug` | `(Z)V` | `0x0072ec` | Đặt cờ `g_native_debug` (`0x02822d`) |

---

## 4. Cơ Chế Xuất 5 Hàm Cốt Lõi Qua ShadowHook `getenv` (`0x011db4..0x012354`)

Khi `initcall` (`0x004fec`) gọi `hookAndSetupEnv` (`0x012050`):
1. Gọi `shadowhook_init(0, false)`.
2. Hook `"setenv"` của `"libc.so"` vào `0x011db4` (được bảo vệ bởi khóa ghi độc quyền `std::shared_timed_mutex` tại `0x0287b8`).
3. Hook `"getenv"` của `"libc.so"` vào `0x011e74` (được bảo vệ bởi khóa đọc chia sẻ `std::shared_timed_mutex` tại `0x0287b8`).
4. Hàm `setupEnvTable` (`0x012174`) định dạng 5 địa chỉ hàm bằng `snprintf(buf, 64, "%p", fn)` và lưu vào mảng 5 phần tử `EnvExportEntry` tại `.bss 0x028930` (mỗi phần tử `128 bytes`: `+0x00` tên hàm, `+0x40` chuỗi địa chỉ `"%p"`, biến đếm `= 5` tại `0x028d30`, cờ khởi tạo `= 1` tại `0x028d34`):
   - `[0]` `"orbuculumIsProceedRequest"` $\rightarrow$ `0x011178`
   - `[1]` `"orbuculumIsProceedRequestForTTNet"` $\rightarrow$ `0x00eb48`
   - `[2]` `"orbuculumIsProceedResponseImpl"` $\rightarrow$ `0x011808`
   - `[3]` `"orbuculumRegisterLiveShutdownCallback"` $\rightarrow$ `0x00d490`
   - `[4]` `"orbuculumIsProceedSeiField"` $\rightarrow$ `0x00d2e8`

---

## 5. Cấu Trúc Thư Mục Mã Nguồn Phục Dựng (`SOURCE/GIAI-MA/liborbuculumadapter/`)

| Tệp tin (File) | Vai trò (EN / VN Role) |
|---|---|
| `orbuculumadapter_types.h` | Toàn bộ cấu trúc dữ liệu ABI (`NetConfig`, `NetConfigRepository`, `BlockSnapshot`, `SeiFieldPayload`, `EnvExportEntry`, `GlobalRuntimeState`) |
| `orbuculumadapter_config_parser.h` / `.cpp` | Bộ phân tích HTTP header RFC & KV, bộ trích xuất URL host/path, bộ khớp quy tắc đại diện `-.`/`*.`, bổ sung DFID 1P/3P, chuyển đổi DFID hex/dec và đánh giá `BlockSnapshot` |
| `orbuculumadapter_runtime_hooks.h` / `.cpp` | Engine ShadowHook `setenv`/`getenv`, hồ 2 luồng `SandboxTP-%zu`, `sendAsync`, cầu nối `dlopen`/`dlsym` tới `liborbuculum.so` & `libpumbaa-network.so`, và `SignalCrashGuard` (`sigsetjmp`/`siglongjmp`) |
| `orbuculumadapter_interface.h` | Giao diện công khai C/C++17 & JNI |
| `orbuculumadapter_pseudocode.cpp` | Mã nguồn phục dựng tổng thể toàn diện (`> 45 KB`), bao gồm `JNI_OnLoad`, `JNI_OnUnload`, 8 phương thức JNI, 5 điểm vào `getenv`, bảng danh mục 40 hàm nhị phân và bộ tự kiểm thử tất định |
