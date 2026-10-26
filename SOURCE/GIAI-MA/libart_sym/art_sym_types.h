/**
 * ============================================================================
 * File: SOURCE/GIAI-MA/libart_sym/art_sym_types.h
 * Library: libart_sym.so (124,720 bytes, SHA-256: cb71702453fff0d212d2b7f20aac4c905fdc3e13333538bc0c305b1ad36532e8)
 * Target: 72 / 169 — ByteDance ART Internal Symbol & Offset Discovery Engine
 * ============================================================================
 *
 * [EN] Clean-room C++17 type definitions, ABI struct layouts, .data/.bss global
 * state layouts, RAII wrappers (DoOnFinally, ScopedElfHandle, ScopedPLTHook),
 * kernel memory probing utilities (/dev/random write probe), and byte-signal
 * fault-recovery (bytesig_*) structures reconstructed from AArch64 machine code
 * (0x013340..0x01c10c).
 *
 * [VN] Định nghĩa kiểu dữ liệu C++17 clean-room, bố cục struct ABI, trạng thái
 * toàn cục .data/.bss, các lớp bọc RAII (DoOnFinally, ScopedElfHandle,
 * ScopedPLTHook), tiện ích thăm dò bộ nhớ qua nhân (ghi thử /dev/random), và
 * cấu trúc phục hồi lỗi tín hiệu (bytesig_*) được tái dựng từ mã máy AArch64
 * (0x013340..0x01c10c).
 * ============================================================================
 */

#ifndef NEXTAI_OPENCUT_LIBART_SYM_TYPES_H_
#define NEXTAI_OPENCUT_LIBART_SYM_TYPES_H_

#include <csetjmp>
#include <csignal>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <list>
#include <mutex>

// Forward declarations for JNI types when compiling outside Android NDK
// Khai báo trước các kiểu JNI khi biên dịch ngoài Android NDK
#ifndef JNI_H_
struct _JavaVM;
struct _JNIEnv;
class _jobject;
class _jclass;
class _jstring;
class _jarray;
class _jobjectArray;
struct _jmethodID;
struct _jfieldID;
typedef _JavaVM JavaVM;
typedef _JNIEnv JNIEnv;
typedef _jobject* jobject;
typedef _jclass* jclass;
typedef _jstring* jstring;
typedef _jarray* jarray;
typedef _jobjectArray* jobjectArray;
typedef _jmethodID* jmethodID;
typedef _jfieldID* jfieldID;
typedef uint8_t jboolean;
typedef int32_t jint;
typedef int64_t jlong;
#endif

namespace art {

// ============================================================================
// 1. DoOnFinally — RAII Deferred Execution List (0x013a74 .. 0x013b98)
//    Danh sách thực thi trì hoãn theo chuẩn RAII khi kết thúc phạm vi hàm
// ============================================================================

/**
 * [EN] Stores a doubly-linked list (`std::list<std::function<void()>>`, 24 bytes
 * on LP64) of cleanup callbacks and invokes them in order upon destruction.
 * Used extensively in `ArtMethod::Init` (0x013390) and `ArtMethodModifier::Init`
 * (0x013f9c) to set `has_init_ = true` and release local JNI references.
 *
 * [VN] Lưu trữ danh sách liên kết đôi (`std::list<std::function<void()>>`, 24 byte
 * trên LP64) chứa các hàm dọn dẹp và gọi tuần tự khi hủy đối tượng. Được sử dụng
 * rộng rãi trong `ArtMethod::Init` (0x013390) và `ArtMethodModifier::Init`
 * (0x013f9c) để gán `has_init_ = true` và giải phóng tham chiếu JNI cục bộ.
 */
class DoOnFinally {
 public:
  // [0x013a74] Initializes sentinel self-pointing doubly-linked list node
  // Khởi tạo nút gốc tự trỏ của danh sách liên kết đôi
  DoOnFinally() noexcept;

  // [0x013a88] Iterates over list nodes, invokes each std::function<void()>,
  // and destroys the list via std::__list_imp::clear()
  // Duyệt qua các nút, gọi từng std::function<void()> và giải phóng danh sách
  ~DoOnFinally() noexcept;

  // [0x013b00] Appends a deferred callback to the tail of the list
  // Thêm một hàm gọi lại trì hoãn vào cuối danh sách
  void add(std::function<void()> fn);

 private:
  std::list<std::function<void()>> callbacks_;
};

// ============================================================================
// 2. ScopedElfHandle — RAII Wrapper around npth_dlopen("libart.so")
//    Lớp bọc RAII quản lý vòng đời handle ELF từ npth_dlopen("libart.so")
//    Addresses / Địa chỉ: 0x0179e8 .. 0x017adc
// ============================================================================

/**
 * [EN] Opens an ELF shared library (specifically `"libart.so"`) via ByteDance's
 * internal `npth_dlopen` symbol-table reader and closes it via `npth_dlclose`
 * upon destruction. A cached static singleton handle is also maintained via
 * `ScopedElfHandle::Get()` (`.bss 0x0261e8`, guarded by `.bss 0x0261f0`).
 *
 * [VN] Mở thư viện chia sẻ ELF (cụ thể là `"libart.so"`) thông qua trình đọc
 * bảng ký hiệu `npth_dlopen` của ByteDance và đóng qua `npth_dlclose` khi hủy.
 * Một handle tĩnh duy nhất cũng được lưu đệm qua `ScopedElfHandle::Get()`
 * (`.bss 0x0261e8`, bảo vệ bởi biến tĩnh `.bss 0x0261f0`).
 */
class ScopedElfHandle {
 public:
  // [0x0179e8] Calls npth_dlopen(soname) and stores handle at offset +0x00
  // Gọi npth_dlopen(soname) và lưu handle tại offset +0x00
  explicit ScopedElfHandle(const char* soname) noexcept;

  // [0x017a2c] Calls npth_dlclose(handle_) if handle_ != nullptr
  // Gọi npth_dlclose(handle_) nếu handle_ khác nullptr
  ~ScopedElfHandle() noexcept;

  // [0x017a6c] Returns raw handle pointer
  // Trả về con trỏ handle thô
  void* get() const noexcept { return handle_; }

  // [0x017a74] Thread-safe Meyer's singleton for ScopedElfHandle("libart.so")
  // Singleton an toàn đa luồng cho ScopedElfHandle("libart.so")
  static const ScopedElfHandle& Get() noexcept;

 private:
  void* handle_;  // +0x00 (8 bytes)
};

// ============================================================================
// 3. ArtSymbolObject — Base Wrapper for Reflected Internal ART Objects
//    Lớp cơ sở bọc con trỏ đối tượng nội bộ của máy ảo ART
//    Addresses / Địa chỉ: 0x0157b8 .. 0x015860
// ============================================================================

/**
 * [EN] Lightweight 16-byte base class (vtable pointer at `+0x00`, raw `void*`
 * internal ART object pointer at `+0x08`) inherited by `ArtClassLinker`, `Heap`,
 * `ArtInstrumentation`, `Jit`, `JitCodeCache`, `JitOptions`, `ReaderWriterMutex`,
 * `ArtRuntime`, `ArtThread`, and `ThreadList`.
 *
 * [VN] Lớp cơ sở 16 byte gọn nhẹ (con trỏ vtable tại `+0x00`, con trỏ đối tượng
 * nội bộ ART `void*` tại `+0x08`) được kế thừa bởi `ArtClassLinker`, `Heap`,
 * `ArtInstrumentation`, `Jit`, `JitCodeCache`, `JitOptions`, `ReaderWriterMutex`,
 * `ArtRuntime`, `ArtThread`, và `ThreadList`.
 */
class ArtSymbolObject {
 public:
  // [0x0157b8] Default constructor: sets vtable (_ZTVN3art15ArtSymbolObjectE+0x10)
  // and initializes thiz_ (+0x08) = nullptr
  // Hàm tạo mặc định: gán vtable và khởi tạo thiz_ (+0x08) = nullptr
  ArtSymbolObject() noexcept : thiz_(nullptr) {}

  // [0x0157d8] Parameterized constructor: sets thiz_ (+0x08) = obj
  // Hàm tạo có tham số: gán thiz_ (+0x08) = obj
  explicit ArtSymbolObject(void* obj) noexcept : thiz_(obj) {}

  virtual ~ArtSymbolObject() = default;

  // [0x0157f8] Returns true if thiz_ != nullptr
  // Trả về true nếu thiz_ khác nullptr
  virtual bool IsValid() noexcept { return thiz_ != nullptr; }

  // [0x015808] Resolves a symbol from ScopedElfHandle::Get() via npth_dlsym
  // Phân giải ký hiệu từ ScopedElfHandle::Get() thông qua npth_dlsym
  static void* FindSymbol(const char* symbol_name) noexcept;

  // [0x015850] Sets underlying ART object pointer
  // Thiết lập con trỏ đối tượng ART bên dưới
  void SetObj(void* obj) noexcept { thiz_ = obj; }

  // [0x015858] Returns underlying ART object pointer
  // Trả về con trỏ đối tượng ART bên dưới
  void* GetObj() const noexcept { return thiz_; }

 protected:
  void* thiz_;  // +0x08: Raw pointer to internal ART C++ instance
};

// ============================================================================
// 4. Memory Probing & Offset Discovery Utilities (0x01541c .. 0x0157b4)
//    Bộ công cụ thăm dò bộ nhớ an toàn và dò tìm offset tự động
// ============================================================================

/**
 * [EN] Retrieves the process-wide `JavaVM*` via `JNIEnv::GetJavaVM` (vtable
 * offset `+0x6d8`) and caches it in `.bss 0x0260d8`.
 * [VN] Lấy con trỏ `JavaVM*` toàn tiến trình qua `JNIEnv::GetJavaVM` (offset
 * vtable `+0x6d8`) và lưu đệm tại `.bss 0x0260d8`.
 * Address / Địa chỉ: 0x01541c
 */
JavaVM* GetJavaVM(JNIEnv* env) noexcept;

/**
 * [EN] Checks whether a pointer is 4-byte aligned: `(reinterpret_cast<uintptr_t>(p) & 3) == 0`.
 * [VN] Kiểm tra xem con trỏ có căn chỉnh 4 byte hay không: `(reinterpret_cast<uintptr_t>(p) & 3) == 0`.
 * Address / Địa chỉ: 0x015498
 */
bool IsAligned(void* p, size_t alignment) noexcept;

/**
 * [EN] Safe kernel-assisted memory readability probe without triggering `SIGSEGV`.
 * Opens `"/dev/random"` with `O_WRONLY` (`1`) via `__open_2` (cached in static
 * `fd` at `.bss 0x0260e0`, guarded by `.bss 0x0260e8`), then calls
 * `write(fd, ptr, size)`. If the kernel VMA copy-from-user succeeds (`ret >= 0`),
 * the address range `[ptr, ptr + size)` is mapped and readable!
 *
 * [VN] Thăm dò khả năng đọc bộ nhớ an toàn nhờ nhân Linux mà không gây lỗi `SIGSEGV`.
 * Mở `"/dev/random"` với cờ `O_WRONLY` (`1`) qua `__open_2` (lưu đệm trong biến
 * tĩnh `fd` tại `.bss 0x0260e0`, bảo vệ bởi `.bss 0x0260e8`), sau đó gọi
 * `write(fd, ptr, size)`. Nếu nhân đọc thành công từ không gian người dùng (`ret >= 0`),
 * vùng địa chỉ `[ptr, ptr + size)` hoàn toàn hợp lệ và đọc được!
 * Address / Địa chỉ: 0x0154a4
 */
bool IsValidPtr(const void* ptr, size_t size = sizeof(void*)) noexcept;

/**
 * [EN] Compares two arrays of 32-bit integers (`uint32_t* a`, `uint32_t* b`) up to
 * `max_count` elements to find the unique index where `a[i] != b[i]`. Returns `-1`
 * if multiple indices differ or if no index differs.
 *
 * [VN] So sánh hai mảng số nguyên 32-bit (`uint32_t* a`, `uint32_t* b`) tối đa
 * `max_count` phần tử để tìm chỉ số duy nhất mà `a[i] != b[i]`. Trả về `-1`
 * nếu có nhiều hơn một vị trí khác biệt hoặc không có vị trí nào khác biệt.
 * Address / Địa chỉ: 0x015514
 */
int32_t DiffIndex(void* a, void* b, size_t max_count) noexcept;

/**
 * [EN] Two-pass canary object size detector for opaque ART C++ classes!
 * Allocates two 1024-byte buffers (`256 * sizeof(uint32_t)`):
 * - Pass 1 fills the buffer with `0x12345678`, invokes `init_fn(buf)`, and scans
 *   from the end (`idx = 255` down to `0`) for the last modified 32-bit word.
 * - Pass 2 fills the buffer with `0x12345678 << 1 = 0x2468acf0`, invokes
 *   `init_fn(buf)`, and scans from the end for the last word != `0x2468acf0`.
 * Taking `std::max(pass1_idx, pass2_idx) + 1` eliminates false negatives when an
 * initialized member happens to equal `0x12345678`!
 *
 * [VN] Trình dò kích thước đối tượng C++ ART ẩn bằng kỹ thuật canary 2 lượt!
 * Cấp phát hai vùng nhớ 1024 byte (`256 * sizeof(uint32_t)`):
 * - Lượt 1 lấp đầy bằng `0x12345678`, gọi `init_fn(buf)`, và quét ngược từ cuối
 *   (`idx = 255` về `0`) để tìm từ 32-bit cuối cùng bị ghi đè.
 * - Lượt 2 lấp đầy bằng `0x12345678 << 1 = 0x2468acf0`, gọi `init_fn(buf)`, và
 *   quét ngược từ cuối để tìm từ cuối cùng khác `0x2468acf0`.
 * Lấy `std::max(pass1_idx, pass2_idx) + 1` giúp triệt tiêu hoàn toàn sai số nếu
 * một trường khởi tạo tình cờ trùng khớp với hằng số `0x12345678`!
 * Address / Địa chỉ: 0x0155f4
 */
size_t DetectObjectSize(std::function<void(void*)> init_fn) noexcept;

/**
 * [EN] Calls `DetectObjectSize(init_fn)` and rounds up the resulting 32-bit word
 * count to an even number (8-byte pointer alignment on 64-bit): `(words + 1) & ~1ULL`.
 *
 * [VN] Gọi `DetectObjectSize(init_fn)` và làm tròn số lượng từ 32-bit lên số chẵn
 * (căn chỉnh con trỏ 8 byte trên hệ 64-bit): `(words + 1) & ~1ULL`.
 * Address / Địa chỉ: 0x015724
 */
size_t DetectObjectSizeWithPointerAlign(std::function<void(void*)> init_fn) noexcept;

/**
 * [EN] Template helper instantiated at 0x013cb4 (`T = void*, Pred = IsEqual<void*>`),
 * 0x01448c (`T = uint32_t, Pred = IsEqual<uint32_t>`), 0x016554 (`T = uint64_t`),
 * 0x016758 (`T = void*, Pred = CheckMember`), 0x0192b8..0x01a11c (Runtime members).
 * Scans `array[start .. end - 1]` and returns the first index `i` where `pred(array[i])`
 * is true, or `-1` if not found.
 *
 * [VN] Hàm mẫu được khởi tạo tại 0x013cb4, 0x01448c, 0x016554, 0x016758, và
 * 0x0192b8..0x01a11c. Quét mảng `array[start .. end - 1]` và trả về chỉ số `i`
 * đầu tiên thỏa mãn `pred(array[i])`, hoặc `-1` nếu không tìm thấy.
 */
template <typename T, typename Pred>
int32_t SearchIndex(const T* array, int32_t start, int32_t end, Pred pred) noexcept {
  if (array == nullptr || start < 0 || start >= end) {
    return -1;
  }
  for (int32_t i = start; i < end; ++i) {
    if (pred(array[i])) {
      return i;
    }
  }
  return -1;
}

/**
 * [EN] Backward search template instantiated at 0x014ad8 (`T = uint32_t`) and
 * 0x01a084 (`T = void*`). Scans backward from `start` down to `end + 1`.
 *
 * [VN] Hàm mẫu tìm kiếm ngược được khởi tạo tại 0x014ad8 (`T = uint32_t`) và
 * 0x01a084 (`T = void*`). Quét ngược từ `start` lùi về `end + 1`.
 */
template <typename T, typename Pred>
int32_t SearchIndexReverse(const T* array, int32_t start, int32_t end, Pred pred) noexcept {
  if (array == nullptr || start <= end) {
    return -1;
  }
  for (int32_t i = start; i > end; --i) {
    if (pred(array[i])) {
      return i;
    }
  }
  return -1;
}

// ============================================================================
// 5. StackVisitorL / StackVisitorM / StackVisitor (0x01b388 .. 0x01b5bc)
//    Cấu trúc duyệt ngăn xếp tương thích Android 5.x (L) và 6.0+ (M..U)
// ============================================================================

class ArtThread;

/**
 * [EN] Base StackVisitor for Android 5.0/5.1 (API 21..22, Lollipop).
 * Size reserves 520 bytes (`0x208`: vtable at `+0x00`, `char reserved_[512]` at `+0x08`).
 * [VN] Lớp cơ sở StackVisitor cho Android 5.0/5.1 (API 21..22, Lollipop).
 * Kích thước dự trữ 520 byte (`0x208`: vtable tại `+0x00`, `char reserved_[512]` tại `+0x08`).
 * Addresses / Địa chỉ: 0x01b388 .. 0x01b434
 */
class StackVisitorL {
 public:
  // [0x01b388] Calls _ZN3art12StackVisitorC2EPNS_6ThreadEPNS_7ContextE
  StackVisitorL(ArtThread* thread, void* context) noexcept;

  // [0x01b408] Virtual destructor
  virtual ~StackVisitorL() noexcept = default;

  // Pure virtual VisitFrame() = 0 in vtable slot 2 (_ZTVN3art13StackVisitorLE)
  virtual bool VisitFrame() = 0;

 protected:
  uint8_t reserved_[512];  // +0x08 .. +0x207 (Zero-initialized via memset in derived)
};

/**
 * [EN] Base StackVisitor for Android 6.0+ (API >= 23, Marshmallow through Android 14).
 * Resolves 3 constructor variants across API levels:
 * - `_ZN3art12StackVisitorC2EPNS_6ThreadEPNS_7ContextENS0_13StackWalkKindE` (API 23)
 * - `_ZN3art12StackVisitorC2EPNS_6ThreadEPNS_7ContextENS0_13StackWalkKindEb` (API 24..27)
 * - `_ZN3art12StackVisitorC2EPNS_6ThreadEPNS_7ContextENS0_13StackWalkKindEmb` (API 28+)
 *
 * [VN] Lớp cơ sở StackVisitor cho Android 6.0+ (API >= 23, Marshmallow đến Android 14).
 * Phân giải 3 biến thể hàm tạo qua các phiên bản API.
 * Addresses / Địa chỉ: 0x01b438 .. 0x01b52c
 */
class StackVisitorM {
 public:
  // [0x01b438] Initializes visitor with StackWalkKind::kIncludeInlinedFrames (0)
  StackVisitorM(ArtThread* thread, void* context, uint32_t walk_kind) noexcept;

  // [0x01b520] Virtual destructor
  virtual ~StackVisitorM() noexcept = default;

  // Pure virtual VisitFrame() = 0 in vtable slot 2 (_ZTVN3art13StackVisitorME)
  virtual bool VisitFrame() = 0;

 protected:
  uint8_t reserved_[512];  // +0x08 .. +0x207
};

/**
 * [EN] Unified StackVisitor wrapper (`0x01b530 .. 0x01b540`) used by
 * `InstrumentationStackPopper` (`0x0171dc`) to walk frames and extract `ArtMethod*`
 * at offset `+0x18` (when `reserved_[0x10] == nullptr`) or `+0x10` (when non-null).
 *
 * [VN] Lớp bọc StackVisitor hợp nhất (`0x01b530 .. 0x01b540`) được dùng bởi
 * `InstrumentationStackPopper` (`0x0171dc`) để duyệt khung ngăn xếp và trích xuất
 * `ArtMethod*` tại offset `+0x18` (khi `reserved_[0x10] == nullptr`) hoặc `+0x10`.
 */
class StackVisitor : public StackVisitorM {
 public:
  // [0x01b530] Zeroes 512 bytes at +0x08 and invokes StackVisitorM(thread, nullptr, 0)
  explicit StackVisitor(ArtThread* thread) noexcept;

  ~StackVisitor() noexcept override = default;
};

class StackVisitorUtils {
 public:
  // [0x01b540] Walks stack on `thread` using `_ZN3art12StackVisitor9WalkStackEb`
  // Duyệt ngăn xếp trên `thread` bằng `_ZN3art12StackVisitor9WalkStackEb`
  static void WalkStack(StackVisitor* visitor, bool include_transitions) noexcept;
};

}  // namespace art

// ============================================================================
// 6. ScopedPLTHook & ByteSig Fault Protection (0x01b5c0 .. 0x01c03c)
//    Cấu trúc Hook PLT/GOT tạm thời & Bảo vệ tín hiệu lỗi trang nhớ ByteSig
// ============================================================================

/**
 * [EN] Per-signal thread protection table entry (`0x110 = 272 bytes` per signal
 * in `.bss 0x0263e8`), supporting up to 8 concurrent threads per signal:
 * - `+0x00`: `int32_t active_count` (atomic counter updated with `ldaxr/stlxr`)
 * - `+0x04..+0x23`: `pid_t tids[8]` (thread IDs protected for this signal)
 * - `+0x28..+0x67`: `sigjmp_buf* jmp_bufs[8]` (jump buffers for `siglongjmp`)
 * - `+0x68..+0x107`: `struct sigaction64 old_action` (160 bytes)
 *
 * [VN] Phần tử bảng bảo vệ luồng theo từng tín hiệu (`0x110 = 272 byte` mỗi tín hiệu
 * tại `.bss 0x0263e8`), hỗ trợ tối đa 8 luồng đồng thời trên mỗi tín hiệu:
 * - `+0x00`: `int32_t active_count` (bộ đếm nguyên tử cập nhật bằng `ldaxr/stlxr`)
 * - `+0x04..+0x23`: `pid_t tids[8]` (mảng 8 mã luồng đang được bảo vệ)
 * - `+0x28..+0x67`: `sigjmp_buf* jmp_bufs[8]` (mảng 8 con trỏ `sigjmp_buf`)
 * - `+0x68..+0x107`: `struct sigaction64 old_action` (160 byte)
 */
struct ByteSigSignalSlot {
  int32_t active_count;         // +0x00
  int32_t tids[8];              // +0x04 .. +0x23
  uint32_t padding_;            // +0x24
  sigjmp_buf* jmp_bufs[8];      // +0x28 .. +0x67
  uint8_t old_sigaction[160];   // +0x68 .. +0x107
  uint64_t reserved_tail;       // +0x108 .. +0x10f (total = 0x110 = 272 bytes)
};

// [0x01bb4c] Registers SA_SIGINFO|SA_ONSTACK|SA_RESTART|SA_NODEFER (0x58000004) handler
int bytesig_init(int signum) noexcept;

// [0x01bed8] Protects `tid` against `signums[0..count-1]` using `jmp_buf`
void bytesig_protect(int32_t tid, sigjmp_buf* jmp_buf, const int* signums, size_t count) noexcept;

// [0x01bfc0] Unprotects `tid` from `signums[0..count-1]`
void bytesig_unprotect(int32_t tid, const int* signums, size_t count) noexcept;

/**
 * [EN] RAII PLT/GOT hooker (`0x01b5c0 .. 0x01ba9c`). Uses `npth_dlrel_plt_got` to
 * find all GOT slots for `symbol_name` inside `soname` (e.g., `"libart.so"`),
 * changes page permissions via `mprotect(PROT_READ | PROT_WRITE)` under `bytesig_protect`
 * (`SIGSEGV=11, SIGTRAP=5`), replaces slots matching `old_func` (or any slot if
 * `old_func == nullptr`) with `new_func`, and restores original GOT entries in
 * `~ScopedPLTHook()`.
 *
 * [VN] Trình hook PLT/GOT theo chuẩn RAII (`0x01b5c0 .. 0x01ba9c`). Dùng `npth_dlrel_plt_got`
 * để tìm tất cả các ô GOT của `symbol_name` trong `soname` (ví dụ `"libart.so"`),
 * đổi quyền trang nhớ qua `mprotect(PROT_READ | PROT_WRITE)` dưới sự bảo vệ của
 * `bytesig_protect` (`SIGSEGV=11, SIGTRAP=5`), thay thế các ô khớp `old_func` bằng
 * `new_func`, và khôi phục lại giá trị GOT gốc trong `~ScopedPLTHook()`.
 */
class ScopedPLTHook {
 public:
  struct SavedGotEntry {
    void** got_slot;   // +0x00: Address of GOT slot
    void* old_target;  // +0x08: Original function pointer before hook
  };

  // [0x01b5c0] Installs PLT/GOT hook for symbol_name in soname
  ScopedPLTHook(const char* soname, const char* symbol_name, void* new_func, void* old_func = nullptr) noexcept;

  // [0x01b788] Restores all hooked GOT slots
  ~ScopedPLTHook() noexcept;

 private:
  // [0x01b848] Modifies *got_slot = target with mprotect + bytesig_protect + __builtin___clear_cache
  static bool DoHook(void** got_slot, void* target, void** out_previous) noexcept;

  const char* soname_;                  // +0x00
  const char* symbol_name_;             // +0x08
  void* new_func_;                      // +0x10
  void* old_func_;                      // +0x18
  std::list<SavedGotEntry> saved_got_;  // +0x20 .. +0x37 (24 bytes on LP64)
};

#endif  // NEXTAI_OPENCUT_LIBART_SYM_TYPES_H_
