# Clean-Room Reconstruction Analysis: `liburiparser.so`
# Phân Tích Tái Tạo Phòng Sạch: `liburiparser.so`

## 1. Binary Identity / Định Danh Nhị Phân
- **File**: `liburiparser.so`
- **Task ID**: `TASK-194-RECONSTRUCTION-LIBURIPARSER` (`TASK_SO_053_liburiparser`)
- **Size**: `100,224` bytes
- **SHA-256**: `e414976665fd4e5e719425bc356ee6b6c9e9cbcd640d8f4f2ed26045514976f6`
- **Architecture**: `AArch64 (EM_AARCH64, 64-bit LSB shared object)`
- **SONAME**: `liburiparser.so`

## 2. Exact ELF Layout & `.eh_frame_hdr` FDE Table / Bố Cục ELF & Bảng FDE
- `.plt`: `0x02f40` (`1,040` bytes)
- `.text`: `0x03350 .. 0x130cc` (`64,892` bytes = `16,223` AArch64 instructions)
- `.rodata`: `0x130d0` (`4,628` bytes — `file://`, `file:///`, RFC 3986 character classification & jump tables)
- `.eh_frame_hdr`: `0x142e4` (`1,420` bytes, `176` sorted FDE entries)
- `.eh_frame`: `0x14870` (`5,944` bytes)
- `.data.rel.ro`: `0x1bb88` (`56` bytes)
- `.data`: `0x1c000` (`48` bytes — `uriDefaultMemoryManager`)

## 3. Architecture & Mathematical Formulation / Kiến Trúc & Công Thức Toán Học
1. **RFC 3986 URI State Machine & `UriUriA` ABI (`160 bytes` = `0xa0`)**:
   - `uriResetUriA` (`0x338c`, `first_op = 0xb40000e0`) zeroes the 160-byte `UriUriA` (`UriUriW` @ `0x3ca4`) structure via `memset(x0, 0, 0xa0)`.
   - `uriCompareRangeA` (`0x33ac`, `first_op = 0xa9bf7bfd`) compares half-open text ranges $[\text{first}, \text{afterLast})$ lexicographically.
2. **Dot-Segment Removal (`uriRemoveDotSegmentsExA` @ `0x3458`, `uriRemoveDotSegmentsExW` @ `0x3d78`)**:
   - Implements RFC 3986 Section 5.2.4 over the singly-linked `UriPathSegmentA` list (`32` bytes per node), collapsing `.` and `..` segments in $O(N)$ time.
