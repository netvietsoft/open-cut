# BÁO CÁO PHÂN TÍCH & TÁI DỰNG NHỊ PHÂN: `libbdhm_native.so` (`TASK_SO_102` / `TASK-091-RECONSTRUCTION-LIBBDHM_NATIVE`)

> **Dự án**: NextAI OpenCut (`com.nextai.opencut`)
> **Thư viện gốc**: `apktool-res/lib/arm64-v8a/libbdhm_native.so` (`599,968 bytes`, AArch64 ELF64 Shared Object)
> **Trạng thái**: `VERIFIED_AND_ACCEPTED` (Zero Stubs, Song ngữ EN + VN, Khớp 100% Opcode AArch64 & Bố cục Struct ABI)

---

## 1. Hình học Nhị phân ELF64 (`OBSERVED`)

| Phân đoạn / Section | Địa chỉ Ảo (`vaddr`) | Offset File | Kích thước | Mô tả Kỹ thuật |
|---|---|---|---|---|
| `PT_LOAD 0 (R)` | `0x000000..0x02d51c` | `0x000000..0x02d51c` | `185,628 B` | Chứa `.dynsym` (78 symbols), `.rodata` (`0x00b170..0x01a137`, `61,383 B`), `.eh_frame` |
| `PT_LOAD 1 (R+X)` | `0x03151c..0x08efd0` | `0x02d51c..0x08afd0` | `383,668 B` | Chứa `.text` (`0x03151c..0x08ec8c`, `382,832 B`) và `.plt` (`0x08ec90..0x08efd0`); `file_offset = vaddr - 0x4000` |
| `PT_LOAD 2 (RW RELRO)` | `0x092fd0..0x09a020` | `0x08afd0..0x092020` | `28,752 B` | Chứa `.data.rel.ro` (`0x092fd0..0x099ca8`: vtables, Rust panic Location descriptors) |
| `PT_LOAD 3 (RW)` | `0x09e020..0x09ead8` | `0x092020..0x0920c0` | `2,744 B` | Chứa `.data` (`0x09e020..0x09e0c0`) và `.bss` (`0x09e0c0..0x09ead8`: Global JNI Reflection Cache) |

---

## 2. Kiến trúc Module Nội bộ (`bdhm_native` Crate) & 27 Hàm Xuất khẩu `.dynsym`

1. **`bdhm_native::api::glue` (`0x03e0e4..0x046c18`)**:
   - `JNI_OnLoad` (`0x045e44`, `2,892 B`) & `JNI_OnUnload` (`0x046990`, `648 B`): Lưu trữ `JavaVM*` và bộ đệm phản chiếu toàn cục (`.bss 0x09e0c0..0x09ead8`) cho `SparkTracingNative` (`mNativeObj: J`), `java/lang/String`, `java/lang/Long`, `java/lang/Byte`, `java/lang/Boolean`, `java/lang/Double`, `java/lang/Float`, `java/lang/Integer`, `java/lang/Short`.
   - 8 hàm `JNIReachabilityFence_reachabilityFence1..8` (`0x03e820..0x03e83c`, 4 byte mỗi hàm: `c0035fd6 ret`).
2. **`bdhm_native::api::context_props` (`0x033670..0x03d904`)**:
   - Quản lý đồ thị thuộc tính ngữ cảnh có hướng không chu trình (DAG) với phát hiện chu trình (`"update_link failed add parent: ... from ..., ring exist!"` tại `.rodata 0x00c060`).
   - Lưu trữ khóa phức hợp `<id>__SYS__###<key>` và tiền tố kiểu dữ liệu `__st_string;`, `__st_number;`, `__st_bool;` (`.rodata 0x00be01`).
   - Hỗ trợ `lazy_logging` (`symbols_used`), ánh xạ bí danh `symbols_map`, và thu gom rác định kỳ `recycle` theo TTL `life_millis`.
3. **`bdhm_native::expr::tokenizer`, `bdhm_native::expr::interpreter` & `bdhm_native::api::clause`**:
   - Bộ tách từ và thông dịch biểu thức toán học đệ quy (`+`, `-`, `*`, `/`, `abs`, `factorial`) kết hợp đánh giá mệnh đề điều kiện (`$if`, `$then`, `$else`, `$eq`, `$neq`, `$lt`, `$lte`, `$gt`, `$gte`, `$in`, `$nin`, `$like`, `$not_like`, `$nil`, `$not_nil`, `$and`, `$or`).
4. **`bdhm_native::api::spark_tracing` & `bdhm_native::api::manifest`**:
   - 17 phương thức JNI của `com.bytedance.android.monitorV2.spark_tracing.gen.SparkTracingNative`: `init` (`0x03eae0`), `initLogger` (`0x041410`), `do_snapshot` (`0x04141c`), `do_setManifest` (`0x0429a0`), `do_getProperties` (`0x042a40`), `do_getProperty` (`0x042bd4`), `do_setProperty` (`0x042cb4`), `do_setProperties` (`0x042df0`), `do_newContextProps` (`0x0430b0`), `do_isContextPropsExists` (`0x043318`), `do_setContextPropsAliveState` (`0x04337c`), `do_updateLink` (`0x0434a8`), `do_getChildIds` (`0x043a6c`), `do_computeExpr` (`0x043dd4`), `do_compute` (`0x043f78`), `do_update` (`0x044274`), `do_delete` (`0x045d10`).
