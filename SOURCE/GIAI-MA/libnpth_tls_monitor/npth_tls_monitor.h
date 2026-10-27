// ============================================================================
// NextAI OpenCut — Clean-Room C++17 Reconstruction
// Target Binary : libnpth_tls_monitor.so (15,904 bytes)
// SHA-256       : 7dc9ec38a56447ae99bde0d8bb89408b3583ea62097a3c0f7d55ba8c5b4e0fa7
// Task ID       : TASK-168-RECONSTRUCTION-LIBNPTH-TLS-MONITOR
// Legacy Task   : TASK_SO_090_libnpth_tls_monitor
// Architecture  : AArch64 (ARM64-v8a) ELF64 Shared Library
// ============================================================================
// EN: Bilingual clean-room header for ByteDance NPTH Pthread TLS Key Monitor
//     (.text 0x17ac..0x30a8, 18 FDEs @ 0x13d4, 1,599 AArch64 instructions).
// VI: File header C++17 phòng sạch song ngữ cho Bộ giám sát khóa TLS Pthread
//     của ByteDance NPTH (.text 0x17ac..0x30a8, 18 FDE @ 0x13d4, 1.599 lệnh).
// ============================================================================

#ifndef NEXTAI_OPENCUT_NPTH_TLS_MONITOR_H_
#define NEXTAI_OPENCUT_NPTH_TLS_MONITOR_H_

#include <cstddef>
#include <cstdint>
#include <ctime>
#include <mutex>

namespace nextai {
namespace opencut {
namespace npth_tls {

// EN: Android API level bounds checked at 0x180c..0x1814 (`sub w8, w0, #0x23; cmn w8, #0xc`)
//     and Bionic `_ZL7key_map` table sizes at 0x18c0..0x1918:
//       - API 26..33 (`sub w10, w19, #0x1a; cmp w10, #7`): 0x82 (130) entries = 0x820 (2,080) bytes
//       - API 23..25 (`cmp w19, #0x19`):                   0x8D (141) entries = 0x8D0 (2,256) bytes
// VI: Giới hạn Android API level kiểm tra tại 0x180c..0x1814 và kích thước bảng `_ZL7key_map`:
//       - API 26..33: 0x82 (130) phần tử = 0x820 (2.080) byte
//       - API 23..25: 0x8D (141) phần tử = 0x8D0 (2.256) byte
constexpr int32_t kMinSupportedApiLevel = 23;
constexpr int32_t kMaxSupportedApiLevel = 34;
constexpr size_t  kBionicKeyMapCountApi26To33 = 0x82U;  // 130 entries (2,080 B)
constexpr size_t  kBionicKeyMapCountApi23To25 = 0x8DU;  // 141 entries (2,256 B)

// EN: 16-byte Bionic `pthread_key_internal_t` entry inside `libc.so`'s `_ZL7key_map`
//     (inspected at 0x1ca4..0x1cb8: `ldr x25, [x8]; ldr x26, [x8, #8]`).
// VI: Cấu trúc 16 byte `pthread_key_internal_t` trong `_ZL7key_map` của `libc.so`
//     (truy cập tại 0x1ca4..0x1cb8: `ldr x25, [x8]; ldr x26, [x8, #8]`).
struct BionicKeyMapEntry {
    uintptr_t key_seq;         // +0x00: bit 0 indicates in-use ("use" vs "no_use" at 0x1c44)
    uintptr_t key_destructor;  // +0x08: destructor function pointer resolved via dladdr
};
static_assert(sizeof(BionicKeyMapEntry) == 0x10, "ABI size must be 16 bytes");

// EN: 112-byte (0x70) doubly-linked list node allocated at 0x194c (sentinel head) and
//     0x2254 (per-event record in `record_key_event` @ 0x2204).
// VI: Nút danh sách liên kết đôi 112 byte (0x70) cấp phát tại 0x194c (sentinel) và
//     0x2254 (bản ghi sự kiện tại `record_key_event` @ 0x2204).
struct TlsKeyMonitorNode {
    TlsKeyMonitorNode* next;   // +0x00: [x21, #0x00]
    TlsKeyMonitorNode* prev;   // +0x08: [x21, #0x08]
    uint8_t mutex_storage[40]; // +0x10..+0x37: pthread_mutex_t (locked at +0x10 in sentinel head)
    int32_t pid;               // +0x38: [x21, #0x38] from getpid() @ 0x2270
    int32_t tid;               // +0x3C: [x21, #0x3C] from gettid() @ 0x2278
    int32_t op_type;           // +0x40: [x21, #0x40] (1 = "create", 2 = "delete")
    int32_t reserved_44;       // +0x44
    char*   comm_name;         // +0x48: [x21, #0x48] strdup("/proc/%d/comm") @ 0x2308
    void*   key_addr;          // +0x50: [x21, #0x50] pthread_key_t* address
    void*   key_destructor;    // +0x58: [x21, #0x58] destructor callback
    void*   caller_pc;         // +0x60: [x21, #0x60] xpaclri return address (LR)
    time_t  timestamp;         // +0x68: [x21, #0x68] time(&node->timestamp) @ 0x231c
};
static_assert(sizeof(TlsKeyMonitorNode) == 0x70, "ABI size must be 0x70 (112 bytes)");

// EN: 76-byte (0x4C) `.bss` global state at 0x0b670..0x0b6bc.
// VI: Trạng thái toàn cục `.bss` 76 byte (0x4C) tại 0x0b670..0x0b6bc.
struct TlsMonitorBssState {
    uint8_t            is_initialized;   // 0x0b670
    uint8_t            pad_671[7];       // 0x0b671..0x0b677
    char*              dump_dir_path;    // 0x0b678 (strdup of log_dir)
    int32_t            api_level;        // 0x0b680
    int32_t            pad_684;          // 0x0b684
    const void*        libc_key_map_sym; // 0x0b688 (_ZL7key_map resolved via npth_dlsym_symtab)
    BionicKeyMapEntry* key_map_copy;     // 0x0b690 (calloc 0x820 or 0x8d0 bytes)
    int32_t            key_map_count;    // 0x0b698 (0x82 = 130 or 0x8d = 141)
    int32_t            pad_69c;          // 0x0b69c
    int32_t            key_map_status;   // 0x0b6a0 (1 = ok, -1 = failed)
    int32_t            pad_6a4;          // 0x0b6a4
    TlsKeyMonitorNode* list_head;        // 0x0b6a8 (calloc(1, 0x70) sentinel)
    int32_t            dump_stage;       // 0x0b6b0 (0 = recording, 1 = dumping map, 2 = dumping list, 3 = done)
    int32_t            create_count;     // 0x0b6b4 (incremented in hooked pthread_key_create @ 0x2118)
    int32_t            delete_count;     // 0x0b6b8 (incremented in hooked pthread_key_delete @ 0x21bc)
};

// EN: 16-byte exported `.data` interface table at 0x0b660 (`tls_native_interface_func`).
//     Contains `{ &npth_pthread_key_monitor_init, &npth_pthread_key_monitor_dump }`
//     relocated by `.rela.dyn` entries at 0x0b660 -> 0x17fc and 0x0b668 -> 0x1ac8.
// VI: Bảng giao diện `.data` 16 byte xuất khẩu tại 0x0b660 (`tls_native_interface_func`).
//     Chứa `{ &npth_pthread_key_monitor_init, &npth_pthread_key_monitor_dump }`.
struct TlsNativeInterfaceTable {
    int  (*init_func)(int api_level, const char* dump_dir);
    void (*dump_func)();
};
static_assert(sizeof(TlsNativeInterfaceTable) == 0x10, "ABI size must be 16 bytes");

extern const uint8_t  kNpthTlsMonitorRodata1258[1258];
extern const uint32_t kNpthTlsMonitorTextWords1599[1599];

// FDE[05] (0x17fc..0x1ac4): Initialize TLS key monitor and install ByteHook hooks.
int NpthPthreadKeyMonitorInit(int api_level, const char* dump_dir) noexcept;

// FDE[06] (0x1ac8..0x203c): Dump pthread_key_map.txt and pthread_key_info.txt.
void NpthPthreadKeyMonitorDump() noexcept;

// FDE[07] (0x2040..0x20b0): ByteHook caller library filter (excludes libc.so, libnpth.so, libbytehook.so, libnpth_dl.so).
bool NpthTlsCallerFilter(const char* caller_path_name) noexcept;

// FDE[08] (0x20b4..0x2144): ByteHook proxy for pthread_key_create.
int NpthHookedPthreadKeyCreate(uint32_t* key, void (*destructor)(void*), uintptr_t caller_lr) noexcept;

// FDE[10] (0x214c..0x2200): ByteHook proxy for pthread_key_delete.
int NpthHookedPthreadKeyDelete(uint32_t key, uintptr_t caller_lr) noexcept;

// FDE[11] (0x2204..0x2370): Record a create/delete event node into the doubly-linked list.
void NpthRecordTlsKeyEvent(int op_type, void* key_addr, uintptr_t caller_lr, void* destructor) noexcept;

// FDE[13..15] (0x2418..0x2ef4): Async-signal-safe custom vsnprintf / snprintf / dprintf_fd.
int NpthSafeFormatBuffer(char* buf, size_t size, const char* fmt, ...) noexcept;
int NpthSafeWriteFormattedFd(int fd, const char* fmt, ...) noexcept;

// FDE[16] (0x2ef8..0x2f88): Robust write loop retrying on EINTR (errno == 4).
int NpthWriteAllRetryEintr(int fd, const void* buf, size_t len) noexcept;

// FDE[17] (0x2f8c..0x30a4): Open file with O_CLOEXEC and automatic RLIMIT_NOFILE raise on EMFILE (errno == 24).
int NpthOpenWithRlimitRetry(const char* path, int flags) noexcept;

}  // namespace npth_tls
}  // namespace opencut
}  // namespace nextai

extern "C" {

// Exported .dynsym[39] STT_OBJECT at 0x0b660 (size = 16 bytes)
extern nextai::opencut::npth_tls::TlsNativeInterfaceTable tls_native_interface_func;

}  // extern "C"

#endif  // NEXTAI_OPENCUT_NPTH_TLS_MONITOR_H_
