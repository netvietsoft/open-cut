# BÁO CÁO NGHIỆM THU TÁI CẤU TRÚC C++17: `libnpth_unw.so` (`TASK-095` / `TASK_SO_083`)

- **Thư viện mục tiêu**: `libnpth_unw.so` (`29,336 bytes`, 97 `.dynsym` entries: 73 imported + 23 exported)
- **Dung lượng C++17 & Header phục dựng**: `137,991 bytes` (`8` tệp trong `SOURCE/GIAI-MA/libnpth_unw/`, `0 stubs`)
- **Trạng thái kiểm định Agent 13**: `VERIFIED_AND_ACCEPTED`
- **Các hạng mục chính**:
  1. Phục dựng đầy đủ 23 hàm C API xuất khẩu (`npth_unw_current*`, `npth_unw_thread*`, `npth_unw_any_thread*`, `npth_unw_process*`, `npth_unw_all*`, `npth_unw_fast*`, `npth_unw_frames*`, `npth_unw_ucontext*`, `npth_unw_format*`, `npth_unw_context_*`).
  2. Chứng minh toán học phép chia cho `80` (`sizeof(FrameData) = 0x50`) bằng hằng số `0xcccccccccccccccdULL` (`0x003898..0x0038a4`) và chia cho `24` (`sizeof(std::string) = 0x18`) bằng hằng số `0xaaaaaaaaaaaaaaabULL` (`0x00395c..0x003968`).
  3. Phục dựng Cây Đỏ-Đen `56-byte` (`0x38`) khử trùng lặp ELF BuildId (`0x0047dc..0x004c78`) và bộ định dạng khung ngăn xếp 3 chế độ (`0x004198..0x004798`).
