# BẰNG CHỨNG XÁC MINH ĐỐI KHÁNG (ADVERSARIAL PROOF): `libttmplayer.so`

> **Thư viện**: `apktool-res/lib/arm64-v8a/libttmplayer.so` (`3,594,936` bytes)  
> **Trạng thái thẩm định**: `VERIFIED_AND_ACCEPTED` (Thư viện thứ **42 / 169**)  
> **Dung lượng C++17 & Header tái dựng**: `121,165` bytes (`12` tệp `.cpp`/`.h`, `306,555` bytes tổng trong `SOURCE/GIAI-MA/libttmplayer/`, `0` stub)

---

## 1. BẰNG CHỨNG DISASSEMBLY AARCH64 & BỐ CỤC STRUCT ABI

### 1.1. `JNI_OnLoad` (`0x197174`, 684 bytes) & Bảng 72 Phương thức `RegisterNatives`
- **Địa chỉ hàm**: `0x197174 .. 0x19741f`
- **Opcode đối chứng**:
  - `0x197198`: `adrp x0, #0x2b5000; add x0, x0, #0x982` (`"debug.ttplayer.log.enable"`)
  - `0x1971a0`: `mov w8, #0x6166; movk w8, #0x736c, lsl #16` + `0x65` (`"false"`)
  - `0x1971dc`: `mov w9, #0x6966; movk w9, #0x656c, lsl #16` (`"file"` = `0x656c6966`)
  - `0x1971ec`: `mov w9, #0x7274; movk w9, #0x6575, lsl #16` (`"true"` = `0x65757274`)
  - `0x197258`: `mov w20, #4; movk w20, #1, lsl #16` (`JNI_VERSION_1_4 = 0x00010004`)
  - `0x1972c0 .. 0x1972ec`: Gọi `sub_250de4` (`0x250de4`) 3 lần đăng ký:
    1. `com/ss/ttm/player/TTPlayer`: `62` phương thức tại `.data.rel.ro` `0x351eb8`
    2. `com/ss/ttm/strategycenter/TTPlayerStrategyCenter`: `4` phương thức tại `0x358f60`
    3. `com/ss/ttm/player/AJMediaCodec`: `6` phương thức tại `0x35d3d0`

### 1.2. `AVStrategyUtils::convertTTCodecIDToFF` (`0x1660cc` -> `0x261f20`)
- **Opcode đối chứng**:
  ```assembly
  0x261f20: 7100c41f  cmp  w0, #0x31
  0x261f24: 540000c8  b.hi #0x261f3c
  0x261f28: 92a01008  mov  x8, #-0x800001
  0x261f2c: f2de3fe8  movk x8, #0xf1ff, lsl #32
  0x261f30: f2e00068  movk x8, #3, lsl #48        ; x8 = 0x0003f1ffff7fffffULL
  0x261f34: 9ac02508  lsr  x8, x8, x0
  0x261f38: 37000068  tbnz w8, #0, #0x261f44
  0x261f3c: 2a0103e0  mov  w0, w1
  0x261f40: d65f03c0  ret
  0x261f44: d0000368  adrp x8, #0x2cf000
  0x261f48: 91010108  add  x8, x8, #0x40          ; .rodata table @ 0x2cf040
  0x261f4c: b860d900  ldr  w0, [x8, w0, sxtw #2]
  0x261f50: d65f03c0  ret
  ```

### 1.3. `VString` (24B), `Value` (32B), `Parcel` (32B) & `AJMediaCodec::onFilledBuffer` (`0x212b34`)
- `VString::c_str()` (`0x16b6a8`): Kiểm tra bit 0 tại `+0x00` (`ldrb w8, [x0]; tbnz w8, #0, #0x16b6b8`); nếu bằng 0 trả về `this + 1` (SSO), nếu bằng 1 trả về con trỏ heap tại `[this + 0x10]`.
- `Parcel::isFull()` (`0x16be78`): `ldp x9, x8, [x0, #8]; ldr x10, [x0]; sub x8, x8, x9; cmp x10, x8, asr #5; cset w0, eq` — mỗi phần tử `Value` có kích thước đúng `32` bytes (`1 << 5`).
- `AJMediaCodec::onFilledBuffer` (`0x212b34`): Bộ đệm vòng 64 khe (`cmp w8, #0x3f` tại `+0x828`, chỉ số ghi nguyên tử `ldaxr`/`stlxr` tại `+0x824` mặt nạ `& 0x3f`), mỗi khe 32 bytes (`lsl #5`) bắt đầu từ `+0x830` (`index` `+0x830`, `offset` `+0x834`, `size` `+0x838`, `pts` `+0x840`, `flags` `+0x848`).
