# Adversarial Proof & Binary Verification Dossier: `liblynxtrace.so` (`TASK_SO_149` / `TASK-098`)

## 1. Binary & ELF64 Verification Summary
## 1. Tóm tắt Đối soát Nhị phân & ELF64

- **Target Binary / Tệp nhị phân**: `extracted/lib/arm64-v8a/liblynxtrace.so` (`51,200 bytes`)
- **Exported `.dynsym` Symbols / Tổng số ký hiệu xuất**: `34` (`[010]..[043]`)
- **Imported `.dynsym` Symbols / Tổng số ký hiệu nhập**: `9` (`[001]..[009]`, plus PLT index `9` for `_ZN4lynx5trace15TraceController8InstanceEv` `[011]`)
- **`.rela.dyn` Entries / Mục tái định vị động**: `62` (`R_AARCH64_RELATIVE` at `0x001500..0x001acf`)
- **`.rela.plt` Entries / Mục khe nhảy PLT**: `10` (`R_AARCH64_JUMP_SLOT` at `0x001ad0..0x001bbf`)

---

## 2. Exact AArch64 Opcode Proofs
## 2. Bằng chứng Mã máy AArch64 Chính xác

### 2.1 `JNI_OnLoad` (`0x00403c..0x0040f4`)
- `0x00403c`: `0xd10103ff` (`sub sp, sp, #0x40`)
- `0x004048`: `0x94000086` (`bl #0x4260` -> `_ZN4lynx4base7android6InitVMEP7_JavaVM`)
- `0x00404c`: `0x94000089` (`bl #0x4270` -> `_ZN4lynx4base7android19AttachCurrentThreadEv`)
- `0x004054`: `0x912f0021` (`add x1, x1, #0xbc0` -> `.rodata 0x001bc0` `"com/lynx/tasm/base/TraceController"`)
- `0x004088`: `0x91020042` (`add x2, x2, #0x80` -> `.data.rel.ro 0x008080` `TraceController::kMethods[4]`)
- `0x00408c`: `0xf9435d08` (`ldr x8, [x8, #0x6b8]` -> `JNIEnv::RegisterNatives`)
- `0x004090`: `0x52800083` (`mov w3, #4`)
- `0x0040a0`: `0x913a0021` (`add x1, x1, #0xe80` -> `.rodata 0x001e80` `"com/lynx/tasm/base/TraceEvent"`)
- `0x0040cc`: `0x91042042` (`add x2, x2, #0x108` -> `.data.rel.ro 0x008108` `TraceEvent::kMethods[10]`)
- `0x0040d4`: `0x52800143` (`mov w3, #0xa`)
- `0x0040e8..0x0040ec`: `0x528000c0` (`mov w0, #6`) + `0x72a00020` (`movk w0, #1, lsl #16` -> `0x00010006` = `JNI_VERSION_1_6`)

### 2.2 `lynx::trace::TraceController::Instance()` (`0x0040fc..0x004158`) & Destructors (`0x00415c..0x004198`)
- `0x004108`: `0x08dffd08` (`ldarb w8, [x8]` on `.bss 0x00c010`)
- `0x00410c`: `0x360000a8` (`tbz w8, #0, #0x4120`)
- `0x004128`: `0x9400005a` (`bl #0x4290` -> `__cxa_guard_acquire`)
- `0x00413c`: `0x91057000` (`add x0, x0, #0x15c` -> `~TraceController` D1 at `0x00415c`)
- `0x004148`: `0x94000042` (`bl #0x4250` -> `__cxa_atexit`)
- `0x004154`: `0x94000053` (`bl #0x42a0` -> `__cxa_guard_release`)
- `0x00416c`: `0xa9007d09` (`stp x9, xzr, [x8]` -> resets `vptr = 0x008018` and `delegate_ = nullptr`)
- `0x004208..0x00420c`: `0xa9007d1f` (`stp xzr, xzr, [x8]`) + `0xf900091f` (`str xzr, [x8, #0x10]` -> zeros 24-byte indirect return `std::string` at `[x8]`)

---

## 3. Reconstructed C++17 Files & Verification Suite
## 3. Danh sách Tệp C++17 Tái dựng & Bộ Kiểm thử

- **Reconstructed Source Directory**: [`SOURCE/GIAI-MA/liblynxtrace/`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/liblynxtrace/) (`8` C++17 & Header files, `> 65 KB`, `0 stubs`)
- **Automated Verification Method**: `verify_liblynxtrace(self)` in [`SOURCE/scripts/verify_reconstruction_suite.py`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/scripts/verify_reconstruction_suite.py) (`6 / 6 PASS`)
