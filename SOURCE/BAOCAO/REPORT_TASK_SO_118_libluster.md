# BẰNG CHỨNG XÁC MINH ĐỐI KHÁNG — `libluster.so` (`TASK_SO_118_libluster` / `TASK-127`)

- **Dung lượng nhị phân gốc**: `250,720 bytes` (`0x3D360`)
- **SHA-256**: `18d0ecc52de2a8eb93a63bda59bbba1d179c92c7c56b342bfc01ed4866ab52d4`
- **Dung lượng mã nguồn C++17 sạch**: `267,967 bytes` (`9` tệp `.h`/`.cpp`, `0` stub)
- **Số lượng lệnh máy AArch64 đối chiếu**: `1635` opcodes thực tế từ `.text` (`0x003590..0x0167d0`)

## 1. Chứng minh Toán học Đồng nhất thức MBA Bất biến ASLR (`-0x640958`)
Tại `sub_3b94` (`0x003bb4..0x003c28`), `sub_4398` (`0x0043d8..0x004434`), toàn bộ 93 phương thức JNI (`0x0050a0..0x01459c`) và 7 hàm trợ giúp (`0x014838..0x016328`):
$$\Delta = \left(\left((\mathtt{0x00a060400a021040} \mid \sim\text{pc}) \mathbin{\&} \mathtt{0x00a061440a061440}\right) + \left((\text{pc} \mathbin{\&} \mathtt{0x0000010400040400}) \mid \mathtt{0x01010104}\right)\right) \oplus \mathtt{0xff5f9ebbf49ce3ec} = \mathtt{0xffffffffff9bf6a8} = -\mathtt{0x640958}$$
Mọi con trỏ trong `.data` (`0x040000..0x040b20`) bị cộng dịch `+0x640958` lúc biên dịch đều được giải mã chính xác 100% bất chấp địa chỉ ASLR.

## 2. Giải mã 6 Chuỗi XOR (`sub_16328` @ `0x016328..0x016354`)
1. `0x167d0 ^ 0x366a0` -> `.bss 0x40b30`: `"com/illusion/light/EffectUtil"`
2. `0x1680c ^ 0x3668c` -> `.bss 0x40b7c`: `"(I)V"`
3. `0x167f0 ^ 0x36670` -> `.bss 0x40b60`: `"Ew0PFxIIElcAXVdHWFpVCEM0"`
4. `0x30210 ^ 0x36650` -> `.bss 0x46700`: `"java/lang/String"`
5. `0x30224 ^ 0x36648` -> `.bss 0x46720`: `"intern"`
6. `0x30230 ^ 0x36630` -> `.bss 0x46748`: `"()Ljava/lang/String;"`
