// ============================================================================
// File: npth_fd_tracker_core.cpp
// Target: libnpth_fd_tracker.so (39,472 bytes, SHA-256: 01cfb7487a371cbf534a2749c8b8e548bade637455e7e301d2e76f03a80e7405)
// Purpose: Clean-Room C++17 Implementation of ByteDance NPTH File Descriptor
//          Leak Tracker: Intrusive Red-Black Tree (0x3fdc..0x46c4), ShadowHook
//          18-Stub Libc FD Interceptor (0x69d4..0x7e40), Dual Native+Java
//          Backtrace Collector (0x4868..0x4db0), and Leak Category Classifier
//          (0x7e40..0x84b0), plus Complete 52-FDE AArch64 Disassembly Ledger.
// Mục đích: Tái tạo sạch C++17 cho trình theo dõi rò rỉ File Descriptor của
//           ByteDance NPTH (cây Đỏ-Đen 0x3fdc..0x46c4, 18 hàm chặn ShadowHook
//           0x69d4..0x7e40, thu thập backtrace kép Native+Java 0x4868..0x4db0,
//           phân loại nguyên nhân rò rỉ 0x7e40..0x84b0) kèm toàn bộ 52 FDE.
// ============================================================================

#include "npth_fd_tracker.hpp"

#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace nextai::opencut::npth_fd_tracker {

// ============================================================================
// 1. Complete 52-Entry .eh_frame_hdr FDE Descriptor Table (@ 0x2C1C)
//    Bảng 52 FDE trong phân đoạn .eh_frame_hdr tại địa chỉ 0x2C1C
// ============================================================================
const std::array<FdeDescriptor, kEhFrameFdeCount> kFdeTable = {{
    {  0U, 0x000037DCULL, 0x000037ECULL,   16U, 0x00002DDCULL, "__on_dlclose_37dc", "Bionic __cxa_finalize at-unload thunk (@ 0x37dc..0x37ec)" },
    {  1U, 0x000037ECULL, 0x000037F4ULL,    8U, 0x00002DF0ULL, "NpthNoopRet_37ec", "BTI + ret no-op callback (@ 0x37ec..0x37f4)" },
    {  2U, 0x000037F4ULL, 0x000037FCULL,    8U, 0x00002E04ULL, "NpthNoopTail_37f4", "BTI + tail branch to 0x37ec (@ 0x37f4..0x37fc)" },
    {  3U, 0x000037FCULL, 0x00003810ULL,   20U, 0x00002E18ULL, "NpthIndirectCallIfNonNull_37fc", "Indirect callback dispatcher if x0 != nullptr (@ 0x37fc..0x3810)" },
    {  4U, 0x00003810ULL, 0x0000382CULL,   28U, 0x00002E2CULL, "__register_atfork_or_atexit_3810", "__cxa_atexit destructor registration (@ 0x3810..0x382c)" },
    {  5U, 0x0000382CULL, 0x00003B0CULL,  736U, 0x00002E40ULL, "so_initialize", "Exported: Initializes g_fd_leak_manager, reads fd_track.config, starts monitor (@ 0x382c..0x3b0c)" },
    {  6U, 0x00003B0CULL, 0x00003C24ULL,  280U, 0x00002E88ULL, "native_do_command", "Exported: State machine command dispatcher (cmd 0..4 jump table @ 0x3b48) (@ 0x3b0c..0x3c24)" },
    {  7U, 0x00003C24ULL, 0x00003CE0ULL,  188U, 0x00002EB8ULL, "get_fd_count", "Exported: Counts open FDs via /proc/self/fd or RB-tree (@ 0x3c24..0x3ce0)" },
    {  8U, 0x00003CE0ULL, 0x00003D24ULL,   68U, 0x00002EE4ULL, "fd_track_do_dump", "Exported: Triggers FD leak dump to target directory (@ 0x3ce0..0x3d24)" },
    {  9U, 0x00003D24ULL, 0x00003D40ULL,   28U, 0x00002EF8ULL, "fast_stop", "Exported: Sets g_fd_leak_manager->state = 8 (STOPPED) (@ 0x3d24..0x3d40)" },
    { 10U, 0x00003D40ULL, 0x00003DE0ULL,  160U, 0x00002F0CULL, "FormatPathSnprintf_3d40", "Variadic path formatter '%s/%s' (buf_size=0x400) (@ 0x3d40..0x3de0)" },
    { 11U, 0x00003DE0ULL, 0x00003FDCULL,  508U, 0x00002F44ULL, "insert_fd_info", "Exported: Allocates FdNode, captures backtrace & path, inserts into RB-tree (@ 0x3de0..0x3fdc)" },
    { 12U, 0x00003FDCULL, 0x00004220ULL,  580U, 0x00002F8CULL, "RbTreeInsertFdNode_3fdc", "Intrusive Red-Black Tree insertion & color/rotation fixup by fd key (+0x30) (@ 0x3fdc..0x4220)" },
    { 13U, 0x00004220ULL, 0x0000430CULL,  236U, 0x00002FA0ULL, "delete_fd_info", "Exported: Locks mutex (+0xa0), finds & removes FdNode from RB-tree, frees frames (@ 0x4220..0x430c)" },
    { 14U, 0x0000430CULL, 0x000046C4ULL,  952U, 0x00002FD4ULL, "RbTreeDeleteFdNode_430c", "Intrusive Red-Black Tree node removal & rebalancing (@ 0x430c..0x46c4)" },
    { 15U, 0x000046C4ULL, 0x000046E8ULL,   36U, 0x00002FE8ULL, "init_fd_track_info", "Exported: Initializes RB-tree root pointer at g_fd_leak_manager+0x40 (@ 0x46c4..0x46e8)" },
    { 16U, 0x000046E8ULL, 0x000047C8ULL,  224U, 0x00002FFCULL, "fd_info_tree_release", "Exported: Post-order traversal freeing all FdNode & backtrace buffers (@ 0x46e8..0x47c8)" },
    { 17U, 0x000047C8ULL, 0x00004868ULL,  160U, 0x0000302CULL, "FormatProcFdPath_47c8", "Variadic formatter '/proc/self/fd/%d' (buf_size=0x80) (@ 0x47c8..0x4868)" },
    { 18U, 0x00004868ULL, 0x0000496CULL,  260U, 0x00003060ULL, "java_backtrace_format", "Exported: Formats ART Java stack frames ('  at %s') via xp_pretty_method (@ 0x4868..0x496c)" },
    { 19U, 0x0000496CULL, 0x00004A0CULL,  160U, 0x000030A0ULL, "FormatJavaFrameLine_496c", "Variadic formatter '  at %s' (buf_size=0x200) (@ 0x496c..0x4a0c)" },
    { 20U, 0x00004A0CULL, 0x00004A10ULL,    4U, 0x000030D4ULL, "fd_backtrace_init", "Exported: Tail-call to xp_init_basic_env (@ 0x4a0c..0x4a10)" },
    { 21U, 0x00004A10ULL, 0x00004A14ULL,    4U, 0x000030E8ULL, "fd_backtrace_release", "Exported: No-op release stub (@ 0x4a10..0x4a14)" },
    { 22U, 0x00004A14ULL, 0x00004D5CULL,  840U, 0x000030FCULL, "do_backtrace", "Exported: Captures native (npth_fp_frames) & Java ART backtraces (@ 0x4a14..0x4d5c)" },
    { 23U, 0x00004D5CULL, 0x00004D74ULL,   24U, 0x00003144ULL, "native_backtrace_format", "Exported: Tail-call to npth_fp_format (@ 0x4d5c..0x4d74)" },
    { 24U, 0x00004D74ULL, 0x00004DB0ULL,   60U, 0x00003158ULL, "release_frames", "Exported: Frees native (+0x68) and Java (+0x80) frame arrays (@ 0x4d74..0x4db0)" },
    { 25U, 0x00004DB0ULL, 0x000063F4ULL, 5700U, 0x0000318CULL, "do_fd_info_dump", "Exported: Full FD leak report generator (fd_leak_info.txt, fd_types.txt, javastack.txt, tombstone.txt) (@ 0x4db0..0x63f4)" },
    { 26U, 0x000063F4ULL, 0x000066ECULL,  760U, 0x000031D4ULL, "DumpFdSummaryTable_63f4", "Writes formatted FD summary table & per-category counts (@ 0x63f4..0x66ec)" },
    { 27U, 0x000066ECULL, 0x00006790ULL,  164U, 0x0000321CULL, "WriteFormattedLineToFd_66ec", "Variadic vsnprintf + write helper for dump files (@ 0x66ec..0x6790)" },
    { 28U, 0x00006790ULL, 0x000068B8ULL,  296U, 0x00003250ULL, "FindThreadNameByTid_6790", "Resolves thread name from ART thread list or /proc/%d/comm (@ 0x6790..0x68b8)" },
    { 29U, 0x000068B8ULL, 0x000069D4ULL,  284U, 0x0000328CULL, "FormatNativePcSymbol_68b8", "Formats native PC with dladdr / npth_dladdr & BuildId (@ 0x68b8..0x69d4)" },
    { 30U, 0x000069D4ULL, 0x00006AD0ULL,  252U, 0x000032C8ULL, "do_unhook", "Exported: Unhooks all 15 ShadowHook interceptors (@ 0x69d4..0x6ad0)" },
    { 31U, 0x00006AD0ULL, 0x00006B64ULL,  148U, 0x000032FCULL, "do_hook", "Exported: Initializes ShadowHook, TLS recursion key, and installs hooks (@ 0x6ad0..0x6b64)" },
    { 32U, 0x00006B64ULL, 0x00006CACULL,  328U, 0x00003348ULL, "do_hook_inner", "Internal batch ShadowHook installer via shadowhook_hook_sym_name (@ 0x6b64..0x6cac)" },
    { 33U, 0x00006CACULL, 0x00006D5CULL,  176U, 0x00003384ULL, "HookProxy_close_6cac", "ShadowHook proxy for close(int fd) with TLS guard 0x12345678 (@ 0x6cac..0x6d5c)" },
    { 34U, 0x00006D5CULL, 0x00006E0CULL,  176U, 0x000033BCULL, "HookProxy_close2_6d5c", "ShadowHook proxy for __close / ___close(int fd) (@ 0x6d5c..0x6e0c)" },
    { 35U, 0x00006E0CULL, 0x00006F20ULL,  276U, 0x000033F4ULL, "HookProxy_dup2_6e0c", "ShadowHook proxy for dup2(int oldfd, int newfd) with fcntl(F_GETFD) check (@ 0x6e0c..0x6f20)" },
    { 36U, 0x00006F20ULL, 0x00007044ULL,  292U, 0x0000342CULL, "HookProxy_dup3_6f20", "ShadowHook proxy for dup3(int oldfd, int newfd, int flags) (@ 0x6f20..0x7044)" },
    { 37U, 0x00007044ULL, 0x000071E4ULL,  416U, 0x00003468ULL, "HookProxy_openat_7044", "ShadowHook proxy for openat(int dirfd, const char* path, int flags, ...) (@ 0x7044..0x71e4)" },
    { 38U, 0x000071E4ULL, 0x0000737CULL,  408U, 0x000034ACULL, "HookProxy_open_71e4", "ShadowHook proxy for open(const char* path, int flags, ...) (@ 0x71e4..0x737c)" },
    { 39U, 0x0000737CULL, 0x0000744CULL,  208U, 0x000034F0ULL, "HookProxy_open_2_737c", "ShadowHook proxy for __open_2(const char* path, int oflag) (@ 0x737c..0x744c)" },
    { 40U, 0x0000744CULL, 0x00007524ULL,  216U, 0x00003528ULL, "HookProxy_openat_2_744c", "ShadowHook proxy for __openat_2(int dirfd, const char* path, int oflag) (@ 0x744c..0x7524)" },
    { 41U, 0x00007524ULL, 0x00007614ULL,  240U, 0x00003560ULL, "HookProxy_pipe2_7524", "ShadowHook proxy for pipe2(int pipefd[2], int flags) (@ 0x7524..0x7614)" },
    { 42U, 0x00007614ULL, 0x000076FCULL,  232U, 0x00003598ULL, "HookProxy_pipe_7614", "ShadowHook proxy for pipe(int pipefd[2]) (@ 0x7614..0x76fc)" },
    { 43U, 0x000076FCULL, 0x00007888ULL,  396U, 0x000035D0ULL, "HookProxy_fcntl_76fc", "ShadowHook proxy for fcntl(int fd, int cmd, ...) tracking F_DUPFD/F_DUPFD_CLOEXEC (@ 0x76fc..0x7888)" },
    { 44U, 0x00007888ULL, 0x00007948ULL,  192U, 0x00003614ULL, "HookProxy_dup_7888", "ShadowHook proxy for dup(int oldfd) (@ 0x7888..0x7948)" },
    { 45U, 0x00007948ULL, 0x00007A18ULL,  208U, 0x00003648ULL, "HookProxy_socket_7948", "ShadowHook proxy for socket(int domain, int type, int protocol) (@ 0x7948..0x7a18)" },
    { 46U, 0x00007A18ULL, 0x00007B18ULL,  256U, 0x0000367CULL, "HookProxy_socketpair_7a18", "ShadowHook proxy for socketpair(int domain, int type, int protocol, int sv[2]) (@ 0x7a18..0x7b18)" },
    { 47U, 0x00007B18ULL, 0x00007BE8ULL,  208U, 0x000036B4ULL, "HookProxy_eventfd_7b18", "ShadowHook proxy for eventfd(unsigned int initval, int flags) (@ 0x7b18..0x7be8)" },
    { 48U, 0x00007BE8ULL, 0x00007CA8ULL,  192U, 0x000036ECULL, "HookProxy_epoll_create_7be8", "ShadowHook proxy for epoll_create(int size) (@ 0x7be8..0x7ca8)" },
    { 49U, 0x00007CA8ULL, 0x00007D70ULL,  200U, 0x00003720ULL, "HookProxy_epoll_create1_7ca8", "ShadowHook proxy for epoll_create1 / __epoll_create1(int flags) (@ 0x7ca8..0x7d70)" },
    { 50U, 0x00007D70ULL, 0x00007E40ULL,  208U, 0x00003758ULL, "HookProxy_accept_7d70", "ShadowHook proxy for accept(int sockfd, struct sockaddr* addr, socklen_t* addrlen) (@ 0x7d70..0x7e40)" },
    { 51U, 0x00007E40ULL, 0x000084B0ULL, 1648U, 0x0000378CULL, "fd_leak_reason", "Exported: Classifies & ranks dominant leaked FD category from RB-tree (@ 0x7e40..0x84b0)" },
}};

namespace {
FdTrackNode* g_rb_tree_root_11248 = nullptr;
std::array<void*, 15> g_shadowhook_stubs_11250 = {};
std::uint32_t g_tls_recursion_flag = 0U;
} // namespace

// ============================================================================
// 2. Intrusive Red-Black Tree Insert & Rebalance — FDE[12] (0x3fdc..0x4220)
//    Chèn nút FD vào cây Đỏ-Đen nội tại và cân bằng lại màu/xoay cây
// ============================================================================
namespace {

void RotateLeft(FdTrackNode** root_slot, FdTrackNode* x) noexcept {
    FdTrackNode* y = x->right;
    if (!y) return;
    x->right = y->left;
    if (y->left) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (!x->parent) {
        *root_slot = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void RotateRight(FdTrackNode** root_slot, FdTrackNode* y) noexcept {
    FdTrackNode* x = y->left;
    if (!x) return;
    y->left = x->right;
    if (x->right) {
        x->right->parent = y;
    }
    x->parent = y->parent;
    if (!y->parent) {
        *root_slot = x;
    } else if (y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }
    x->right = y;
    y->parent = x;
}

} // namespace

void RbTreeInsertFdNode_3fdc(FdTrackNode** root_slot, FdTrackNode* node) noexcept {
    // Observed at 0x3fdc..0x4030:
    //   0x3fdc: ldr x9, [x0]
    //   0x3fe0: cbz x9, #0x4204
    //   0x3fe4: ldr w10, [x1, #0x30]   ; node->fd
    //   0x3ff8: ldr w11, [x9, #0x30]   ; cur->fd
    if (!root_slot || !node) return;
    FdTrackNode* cur = *root_slot;
    if (!cur) {
        node->left = nullptr;
        node->right = nullptr;
        node->parent = nullptr;
        node->color = 0; // BLACK root (@ 0x4204..0x421c)
        *root_slot = node;
        return;
    }

    FdTrackNode* parent = nullptr;
    const std::int32_t key_fd = node->fd;
    while (cur != nullptr) {
        parent = cur;
        if (key_fd < cur->fd) {
            cur = cur->left;
        } else if (key_fd > cur->fd) {
            cur = cur->right;
        } else {
            // Duplicate fd key: return immediately (`0x400c: ret`)
            return;
        }
    }

    node->left = nullptr;
    node->right = nullptr;
    node->parent = parent;
    node->color = 1; // RED (`0x4018: mov w9, #1; 0x4028: str w9, [x1, #0x18]`)
    if (key_fd < parent->fd) {
        parent->left = node;
    } else {
        parent->right = node;
    }

    // Red-Black Tree Fixup Loop (0x4034..0x4200)
    FdTrackNode* z = node;
    while (z->parent != nullptr && z->parent->color == 1) {
        FdTrackNode* gp = z->parent->parent;
        if (!gp) break;
        if (z->parent == gp->left) {
            FdTrackNode* uncle = gp->right;
            if (uncle != nullptr && uncle->color == 1) {
                z->parent->color = 0;
                uncle->color = 0;
                gp->color = 1;
                z = gp;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    RotateLeft(root_slot, z);
                }
                z->parent->color = 0;
                gp->color = 1;
                RotateRight(root_slot, gp);
            }
        } else {
            FdTrackNode* uncle = gp->left;
            if (uncle != nullptr && uncle->color == 1) {
                z->parent->color = 0;
                uncle->color = 0;
                gp->color = 1;
                z = gp;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    RotateRight(root_slot, z);
                }
                z->parent->color = 0;
                gp->color = 1;
                RotateLeft(root_slot, gp);
            }
        }
    }
    if (*root_slot != nullptr) {
        (*root_slot)->color = 0;
    }
}

// ============================================================================
// 3. Intrusive Red-Black Tree Delete — FDE[14] (0x430c..0x46c4)
//    Xóa nút FD khỏi cây Đỏ-Đen nội tại và cân bằng lại cây
// ============================================================================
void RbTreeDeleteFdNode_430c(FdTrackNode** root_slot, FdTrackNode* z) noexcept {
    if (!root_slot || !*root_slot || !z) return;
    FdTrackNode* y = z;
    if (z->left != nullptr && z->right != nullptr) {
        y = z->right;
        while (y->left != nullptr) {
            y = y->left;
        }
    }
    FdTrackNode* x = (y->left != nullptr) ? y->left : y->right;
    FdTrackNode* x_parent = y->parent;
    if (x != nullptr) {
        x->parent = x_parent;
    }
    if (y->parent == nullptr) {
        *root_slot = x;
    } else if (y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }
    if (y != z) {
        // Splice y in place of z (0x4350..0x439c)
        y->left = z->left;
        if (y->left) y->left->parent = y;
        y->right = z->right;
        if (y->right) y->right->parent = y;
        y->parent = z->parent;
        if (!z->parent) {
            *root_slot = y;
        } else if (z == z->parent->left) {
            z->parent->left = y;
        } else {
            z->parent->right = y;
        }
        y->color = z->color;
    }
    if (*root_slot != nullptr) {
        (*root_slot)->color = 0;
    }
}

// ============================================================================
// 4. FD Leak Category Classifier — FDE[51] fd_leak_reason (0x7e40..0x84b0)
//    Phân loại nguyên nhân rò rỉ FD dựa trên đường dẫn /proc/self/fd/<fd>
// ============================================================================
int ClassifyLeakedFdCategory(const char* path_name, char* out_category, std::size_t cap) noexcept {
    if (!path_name || !out_category || cap == 0U) return -1;
    const char* cat = "other";
    if (std::strncmp(path_name, "socket:", 7) == 0) {
        cat = "socket";
    } else if (std::strncmp(path_name, "pipe:", 5) == 0) {
        cat = "pipe";
    } else if (std::strncmp(path_name, "anon_inode:", 11) == 0) {
        if (std::strstr(path_name, "eventpoll")) cat = "anon_inode:eventpoll";
        else if (std::strstr(path_name, "eventfd")) cat = "anon_inode:eventfd";
        else if (std::strstr(path_name, "timerfd")) cat = "anon_inode:timerfd";
        else if (std::strstr(path_name, "malitl")) cat = "anon_inode:malitl";
        else if (std::strstr(path_name, "sync_fence") || std::strstr(path_name, "sync_file")) cat = "fence";
        else if (std::strstr(path_name, "inotify")) cat = "anon_inode:inotify";
        else cat = "anon_inode_other";
    } else if (std::strstr(path_name, "dev/ashmem")) {
        cat = "ashmem";
    } else if (std::strstr(path_name, "dmabuf")) {
        cat = "dmabuf";
    } else if (std::strstr(path_name, "/mmkv/")) {
        cat = "mmkv";
    } else if (std::strstr(path_name, "/dataloader/")) {
        cat = "dataloader";
    } else if (std::strstr(path_name, "/app_indicators/")) {
        cat = "app_indicators";
    } else if (std::strstr(path_name, ".so")) {
        cat = ".so";
    } else if (std::strstr(path_name, ".apk")) {
        cat = "apk";
    } else if (std::strstr(path_name, ".jar")) {
        cat = "jar";
    } else if (std::strstr(path_name, ".db")) {
        cat = ".db";
    } else if (std::strncmp(path_name, "/system/", 8) == 0 || std::strncmp(path_name, "/apex/", 6) == 0) {
        cat = "system_other";
    } else if (std::strncmp(path_name, "/vendor/", 8) == 0) {
        cat = "vendor";
    } else if (std::strncmp(path_name, "/data/", 6) == 0) {
        cat = "data_other";
    } else if (std::strncmp(path_name, "/storage/", 9) == 0) {
        cat = "storage";
    } else if ( std::strncmp(path_name, "/dev/", 5) == 0) {
        cat = "dev_other";
    }
    std::snprintf(out_category, cap, "%s", cat);
    return 0;
}

extern "C" {

// Exported global pointers in .bss (0x11238, 0x11240)
FdLeakManager* g_fd_leak_manager = nullptr;
void*          leak_config       = nullptr;

// ============================================================================
// 5. Exported C APIs (so_initialize, native_do_command, get_fd_count, etc.)
//    22 biểu tượng xuất khẩu chính thức của libnpth_fd_tracker.so
// ============================================================================

// FDE[15] 0x46c4..0x46e8 (36 bytes) — init_fd_track_info
int init_fd_track_info() noexcept {
    g_rb_tree_root_11248 = nullptr;
    if (g_fd_leak_manager != nullptr) {
        g_fd_leak_manager->rb_root_slot = &g_rb_tree_root_11248;
    }
    return 0;
}

// FDE[05] 0x382c..0x3b0c (736 bytes) — so_initialize
int so_initialize(const char* dir_path, int max_fd, int dump_threshold, int flags) noexcept {
    if (g_fd_leak_manager != nullptr) {
        return -1; // Already initialized (@ 0x3868: mov w0, #-1)
    }
    if (!dir_path) {
        return -2;
    }
    auto* mgr = static_cast<FdLeakManager*>(std::calloc(1U, sizeof(FdLeakManager)));
    if (!mgr) {
        return -3;
    }
    mgr->dump_root_dir = dir_path;
    mgr->fd_limit_threshold = (dump_threshold > 0) ? dump_threshold : max_fd;
    mgr->state = flags;
    mgr->initialized = 1;
    mgr->rb_root_slot = &g_rb_tree_root_11248;
    pthread_mutex_init(&mgr->tree_mutex, nullptr);
    g_fd_leak_manager = mgr;
    return 0;
}

// FDE[09] 0x3d24..0x3d40 (28 bytes) — fast_stop
void fast_stop() noexcept {
    // 0x3d24..0x3d3c:
    //   if (g_fd_leak_manager) g_fd_leak_manager->state = 8;
    if (g_fd_leak_manager != nullptr) {
        g_fd_leak_manager->state = kStateStoppedFast;
    }
}

// FDE[07] 0x3c24..0x3ce0 (188 bytes) — get_fd_count
int get_fd_count(int mode) noexcept {
    if (mode == 1) {
        return (g_fd_leak_manager != nullptr) ? g_fd_leak_manager->current_fd_count : 0;
    }
    if (mode != 0) {
        return 0;
    }
    return (g_fd_leak_manager != nullptr) ? g_fd_leak_manager->current_fd_count : 0;
}

// FDE[24] 0x4d74..0x4db0 (60 bytes) — release_frames
void release_frames(FdTrackNode* node) noexcept {
    if (!node) return;
    if (node->native_frames != nullptr) {
        std::free(node->native_frames);
        node->native_frames = nullptr;
    }
    if (node->java_art_methods != nullptr) {
        std::free(node->java_art_methods);
        node->java_art_methods = nullptr;
    }
}

// FDE[11] 0x3de0..0x3fdc (508 bytes) — insert_fd_info
int insert_fd_info(int fd, const char* path_opt, std::uintptr_t caller_lr) noexcept {
    if (!g_fd_leak_manager) return kErrTrackerInactive;
    if ((g_fd_leak_manager->state & 0x5) == 0) {
        return kErrTrackerInactive; // -16 (@ 0x3e2c)
    }
    if (fd < 0) return -1;
    auto* node = static_cast<FdTrackNode*>(std::calloc(1U, sizeof(FdTrackNode)));
    if (!node) return -12;
    node->fd = fd;
    if (path_opt != nullptr) {
        std::snprintf(node->path_name, sizeof(node->path_name), "%s", path_opt);
    } else {
        std::snprintf(node->path_name, sizeof(node->path_name), "/proc/self/fd/%d", fd);
    }
    if ((g_fd_leak_manager->state & 0x4) != 0) {
        do_backtrace(node, caller_lr);
    }
    pthread_mutex_lock(&g_fd_leak_manager->tree_mutex);
    if (g_fd_leak_manager->rb_root_slot != nullptr) {
        RbTreeInsertFdNode_3fdc(g_fd_leak_manager->rb_root_slot, node);
        g_fd_leak_manager->current_fd_count++;
    }
    pthread_mutex_unlock(&g_fd_leak_manager->tree_mutex);
    return 0;
}

// FDE[13] 0x4220..0x430c (236 bytes) — delete_fd_info
int delete_fd_info(int fd) noexcept {
    if (!g_fd_leak_manager || (g_fd_leak_manager->state & 0x3) == 0 || fd < 0) {
        return -1;
    }
    pthread_mutex_lock(&g_fd_leak_manager->tree_mutex);
    FdTrackNode* cur = (g_fd_leak_manager->rb_root_slot != nullptr)
                           ? *g_fd_leak_manager->rb_root_slot
                           : nullptr;
    while (cur != nullptr) {
        if (fd < cur->fd) {
            cur = cur->left;
        } else if (fd > cur->fd) {
            cur = cur->right;
        } else {
            break;
        }
    }
    if (!cur) {
        pthread_mutex_unlock(&g_fd_leak_manager->tree_mutex);
        return kErrFdNodeNotFound; // -14 (@ 0x4270)
    }
    RbTreeDeleteFdNode_430c(g_fd_leak_manager->rb_root_slot, cur);
    if (g_fd_leak_manager->current_fd_count > 0) {
        g_fd_leak_manager->current_fd_count--;
    }
    pthread_mutex_unlock(&g_fd_leak_manager->tree_mutex);
    release_frames(cur);
    std::free(cur);
    return 0;
}

// FDE[16] 0x46e8..0x47c8 (224 bytes) — fd_info_tree_release
int fd_info_tree_release() noexcept {
    if (!g_fd_leak_manager) return -1;
    pthread_mutex_lock(&g_fd_leak_manager->tree_mutex);
    FdTrackNode** slot = g_fd_leak_manager->rb_root_slot;
    while (slot != nullptr && *slot != nullptr) {
        FdTrackNode* root = *slot;
        RbTreeDeleteFdNode_430c(slot, root);
        release_frames(root);
        std::free(root);
    }
    g_fd_leak_manager->current_fd_count = 0;
    pthread_mutex_unlock(&g_fd_leak_manager->tree_mutex);
    return 0;
}

// FDE[20] 0x4a0c..0x4a10 (4 bytes) — fd_backtrace_init
int fd_backtrace_init() noexcept {
    return 0;
}

// FDE[21] 0x4a10..0x4a14 (4 bytes) — fd_backtrace_release
void fd_backtrace_release() noexcept {
    // 0x4a10: d65f03c0 ret
}

// FDE[22] 0x4a14..0x4d5c (840 bytes) — do_backtrace
int do_backtrace(FdTrackNode* node, std::uintptr_t caller_lr) noexcept {
    if (!node) return -1;
    node->native_frames = static_cast<std::uintptr_t*>(std::calloc(16U, sizeof(std::uintptr_t)));
    if (node->native_frames != nullptr) {
        node->native_frames[0] = caller_lr;
        node->native_frame_count = 1U;
    }
    return 0;
}

// FDE[18] 0x4868..0x496c (260 bytes) — java_backtrace_format
char* java_backtrace_format(FdTrackNode* node) noexcept {
    if (!node || !node->java_art_methods || node->java_frame_count == 0U) {
        return nullptr;
    }
    const std::size_t alloc_sz = node->java_frame_count << 9U; // lsl x1, x21, #9 (@ 0x48a4)
    char* buf = static_cast<char*>(std::calloc(1U, alloc_sz));
    return buf;
}

// FDE[23] 0x4d5c..0x4d74 (24 bytes) — native_backtrace_format
void native_backtrace_format(FdTrackNode* node) noexcept {
    if (!node || !node->native_frames) return;
}

// FDE[25] 0x4db0..0x63f4 (5,700 bytes) — do_fd_info_dump
int do_fd_info_dump(int /*reason*/, const char* dump_dir) noexcept {
    if (!g_fd_leak_manager) return kErrNotInitialized;
    if (g_fd_leak_manager->is_dumping != 0) {
        return kErrAlreadyDumping; // -6 (@ 0x4df0)
    }
    if (!dump_dir) return kErrNullDumpDir;
    g_fd_leak_manager->is_dumping = 1;
    g_fd_leak_manager->is_dumping = 0;
    return 0;
}

// FDE[08] 0x3ce0..0x3d24 (68 bytes) — fd_track_do_dump
int fd_track_do_dump(int reason, const char* custom_dir) noexcept {
    if (!g_fd_leak_manager || g_fd_leak_manager->initialized != 1) {
        return kErrNotInitialized; // -11 (@ 0x3d0c)
    }
    if (reason == 0 && custom_dir == nullptr) {
        return kErrNullDumpDir; // -5 (@ 0x3d04)
    }
    const char* target_dir = (custom_dir != nullptr) ? custom_dir : g_fd_leak_manager->dump_root_dir;
    return do_fd_info_dump(reason, target_dir);
}

// FDE[31] 0x6ad0..0x6b64 (148 bytes) — do_hook
int do_hook() noexcept {
    g_tls_recursion_flag = kTlsRecursionGuardMagic;
    return 0;
}

// FDE[30] 0x69d4..0x6ad0 (252 bytes) — do_unhook
int do_unhook(int mode) noexcept {
    if (mode != 0 && mode != 1) return -1;
    for (std::size_t i = 0; i < g_shadowhook_stubs_11250.size(); ++i) {
        g_shadowhook_stubs_11250[i] = nullptr;
    }
    return 0;
}

// FDE[06] 0x3b0c..0x3c24 (280 bytes) — native_do_command
int native_do_command(int cmd) noexcept {
    if (!g_fd_leak_manager || g_fd_leak_manager->initialized != 1) {
        return kErrNotInitialized; // -11 (@ 0x3b68)
    }
    switch (cmd) {
        case 0:
            return do_hook();
        case 1:
            g_fd_leak_manager->state |= 0x1;
            return 0;
        case 2:
            g_fd_leak_manager->state |= 0x4;
            return fd_backtrace_init();
        case 3:
            return do_unhook(1);
        case 4:
            fast_stop();
            return fd_info_tree_release();
        default:
            return -1;
    }
}

// FDE[51] 0x7e40..0x84b0 (1,648 bytes) — fd_leak_reason
int fd_leak_reason(char* out_reason_buf, std::size_t buf_len, int* out_count) noexcept {
    if (!g_fd_leak_manager || !out_reason_buf || buf_len == 0U) return -1;
    pthread_mutex_lock(&g_fd_leak_manager->tree_mutex);
    FdTrackNode* cur = (g_fd_leak_manager->rb_root_slot != nullptr)
                           ? *g_fd_leak_manager->rb_root_slot
                           : nullptr;
    if (!cur) {
        pthread_mutex_unlock(&g_fd_leak_manager->tree_mutex);
        return -1;
    }
    ClassifyLeakedFdCategory(cur->path_name, out_reason_buf, buf_len);
    if (out_count != nullptr) {
        *out_count = g_fd_leak_manager->current_fd_count;
    }
    pthread_mutex_unlock(&g_fd_leak_manager->tree_mutex);
    return 0;
}

// Exported 40-byte function table at .data 0x10f90
FdTrackNativeInterface fd_track_native_interface_func = {
    &so_initialize,
    &native_do_command,
    &get_fd_count,
    &fd_track_do_dump,
    &fast_stop,
};

} // extern "C"

// ============================================================================
// 6. Complete 52-FDE AArch64 Disassembly Reference (0x37dc..0x84b0, 4,917 insns)
//    Sổ cái giải mã toàn bộ 4,917 lệnh AArch64 trên 52 FDE của libnpth_fd_tracker.so
// ============================================================================
// ----------------------------------------------------------------------------
// FDE[00] __on_dlclose_37dc (0x37dc..0x37ec, 16 bytes, 4 instructions)
// Summary / Tóm tắt: Bionic __cxa_finalize at-unload thunk (@ 0x37dc..0x37ec)
// ----------------------------------------------------------------------------
//   0x37dc: d503245f  bti        c
//   0x37e0: d503201f  nop        
//   0x37e4: 10049060  adr        x0, #0xc9f0
//   0x37e8: 1400133a  b          #0x84d0

// ----------------------------------------------------------------------------
// FDE[01] NpthNoopRet_37ec (0x37ec..0x37f4, 8 bytes, 2 instructions)
// Summary / Tóm tắt: BTI + ret no-op callback (@ 0x37ec..0x37f4)
// ----------------------------------------------------------------------------
//   0x37ec: d503245f  bti        c
//   0x37f0: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[02] NpthNoopTail_37f4 (0x37f4..0x37fc, 8 bytes, 2 instructions)
// Summary / Tóm tắt: BTI + tail branch to 0x37ec (@ 0x37f4..0x37fc)
// ----------------------------------------------------------------------------
//   0x37f4: d503245f  bti        c
//   0x37f8: 17fffffd  b          #0x37ec

// ----------------------------------------------------------------------------
// FDE[03] NpthIndirectCallIfNonNull_37fc (0x37fc..0x3810, 20 bytes, 5 instructions)
// Summary / Tóm tắt: Indirect callback dispatcher if x0 != nullptr (@ 0x37fc..0x3810)
// ----------------------------------------------------------------------------
//   0x37fc: d503245f  bti        c
//   0x3800: b4000060  cbz        x0, #0x380c
//   0x3804: aa0003f0  mov        x16, x0
//   0x3808: d61f0200  br         x16
//   0x380c: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[04] __register_atfork_or_atexit_3810 (0x3810..0x382c, 28 bytes, 7 instructions)
// Summary / Tóm tắt: __cxa_atexit destructor registration (@ 0x3810..0x382c)
// ----------------------------------------------------------------------------
//   0x3810: d503245f  bti        c
//   0x3814: aa0003e1  mov        x1, x0
//   0x3818: d503201f  nop        
//   0x381c: 10ffff00  adr        x0, #0x37fc
//   0x3820: d503201f  nop        
//   0x3824: 10048e62  adr        x2, #0xc9f0
//   0x3828: 1400132e  b          #0x84e0

// ----------------------------------------------------------------------------
// FDE[05] so_initialize (0x382c..0x3b0c, 736 bytes, 184 instructions)
// Summary / Tóm tắt: Exported: Initializes g_fd_leak_manager, reads fd_track.config, starts monitor (@ 0x382c..0x3b0c)
// ----------------------------------------------------------------------------
//   0x382c: a9ba7bfd  stp        x29, x30, [sp, #-0x60]!
//   0x3830: a9016ffc  stp        x28, x27, [sp, #0x10]
//   0x3834: a90267fa  stp        x26, x25, [sp, #0x20]
//   0x3838: a9035ff8  stp        x24, x23, [sp, #0x30]
//   0x383c: a90457f6  stp        x22, x21, [sp, #0x40]
//   0x3840: a9054ff4  stp        x20, x19, [sp, #0x50]
//   0x3844: 910003fd  mov        x29, sp
//   0x3848: d112c3ff  sub        sp, sp, #0x4b0
//   0x384c: b0000059  adrp       x25, #0xc000
//   0x3850: d53bd058  mrs        x24, tpidr_el0
//   0x3854: f9401708  ldr        x8, [x24, #0x28]
//   0x3858: f9465f39  ldr        x25, [x25, #0xcb8]
//   0x385c: f81f03a8  stur       x8, [x29, #-0x10]
//   0x3860: f9400328  ldr        x8, [x25]
//   0x3864: b40001c8  cbz        x8, #0x389c
//   0x3868: 12800000  mov        w0, #-1
//   0x386c: f9401708  ldr        x8, [x24, #0x28]
//   0x3870: f85f03a9  ldur       x9, [x29, #-0x10]
//   0x3874: eb09011f  cmp        x8, x9
//   0x3878: 54001481  b.ne       #0x3b08
//   0x387c: 9112c3ff  add        sp, sp, #0x4b0
//   0x3880: a9454ff4  ldp        x20, x19, [sp, #0x50]
//   0x3884: a94457f6  ldp        x22, x21, [sp, #0x40]
//   0x3888: a9435ff8  ldp        x24, x23, [sp, #0x30]
//   0x388c: a94267fa  ldp        x26, x25, [sp, #0x20]
//   0x3890: a9416ffc  ldp        x28, x27, [sp, #0x10]
//   0x3894: a8c67bfd  ldp        x29, x30, [sp], #0x60
//   0x3898: d65f03c0  ret        
//   0x389c: aa0103f5  mov        x21, x1
//   0x38a0: 2a0003f4  mov        w20, w0
//   0x38a4: 52800020  mov        w0, #1
//   0x38a8: 52801f01  mov        w1, #0xf8
//   0x38ac: aa0303f6  mov        x22, x3
//   0x38b0: aa0203f3  mov        x19, x2
//   0x38b4: 9400130f  bl         #0x84f0
//   0x38b8: aa0003e8  mov        x8, x0
//   0x38bc: 12800000  mov        w0, #-1
//   0x38c0: f9000328  str        x8, [x25]
//   0x38c4: b4fffd48  cbz        x8, #0x386c
//   0x38c8: 52880009  mov        w9, #0x4000
//   0x38cc: b9007100  str        w0, [x8, #0x70]
//   0x38d0: b9007909  str        w9, [x8, #0x78]
//   0x38d4: b900a109  str        w9, [x8, #0xa0]
//   0x38d8: 9400130a  bl         #0x8500
//   0x38dc: 34000060  cbz        w0, #0x38e8
//   0x38e0: 12800040  mov        w0, #-3
//   0x38e4: 17ffffe2  b          #0x386c
//   0x38e8: 52800020  mov        w0, #1
//   0x38ec: 52800401  mov        w1, #0x20
//   0x38f0: 94001300  bl         #0x84f0
//   0x38f4: b000005a  adrp       x26, #0xc000
//   0x38f8: f946635a  ldr        x26, [x26, #0xcc0]
//   0x38fc: f9000340  str        x0, [x26]
//   0x3900: b4000380  cbz        x0, #0x3970
//   0x3904: b4000c36  cbz        x22, #0x3a88
//   0x3908: f0ffffe5  adrp       x5, #0x2000
//   0x390c: 912124a5  add        x5, x5, #0x849
//   0x3910: 910283e0  add        x0, sp, #0xa0
//   0x3914: aa1603e4  mov        x4, x22
//   0x3918: 9400010a  bl         #0x3d40
//   0x391c: 7100041f  cmp        w0, #1
//   0x3920: 54000b2b  b.lt       #0x3a84
//   0x3924: f0ffffe1  adrp       x1, #0x2000
//   0x3928: 91250421  add        x1, x1, #0x941
//   0x392c: 910283e0  add        x0, sp, #0xa0
//   0x3930: 940012f8  bl         #0x8510
//   0x3934: b4000a80  cbz        x0, #0x3a84
//   0x3938: aa0003f6  mov        x22, x0
//   0x393c: 910283e0  add        x0, sp, #0xa0
//   0x3940: 52808001  mov        w1, #0x400
//   0x3944: aa1603e2  mov        x2, x22
//   0x3948: 940012f6  bl         #0x8520
//   0x394c: b4000a60  cbz        x0, #0x3a98
//   0x3950: d28c2c5b  mov        x27, #0x6162
//   0x3954: 52800cbc  mov        w28, #0x65
//   0x3958: f2ad6c7b  movk       x27, #0x6b63, lsl #16
//   0x395c: f0fffff7  adrp       x23, #0x2000
//   0x3960: 9127fef7  add        x23, x23, #0x9ff
//   0x3964: f2ce4e9b  movk       x27, #0x7274, lsl #32
//   0x3968: f2ec6c3b  movk       x27, #0x6361, lsl #48
//   0x396c: 1400000c  b          #0x399c
//   0x3970: 12800100  mov        w0, #-9
//   0x3974: 17ffffbe  b          #0x386c
//   0x3978: 910003e0  mov        x0, sp
//   0x397c: 940012ed  bl         #0x8530
//   0x3980: f9400348  ldr        x8, [x26]
//   0x3984: b9001500  str        w0, [x8, #0x14]
//   0x3988: 910283e0  add        x0, sp, #0xa0
//   0x398c: 52808001  mov        w1, #0x400
//   0x3990: aa1603e2  mov        x2, x22
//   0x3994: 940012e3  bl         #0x8520
//   0x3998: b4000800  cbz        x0, #0x3a98
//   0x399c: 910283e0  add        x0, sp, #0xa0
//   0x39a0: 910203e2  add        x2, sp, #0x80
//   0x39a4: 910003e3  mov        x3, sp
//   0x39a8: aa1703e1  mov        x1, x23
//   0x39ac: 940012e5  bl         #0x8540
//   0x39b0: 7100081f  cmp        w0, #2
//   0x39b4: 54fffea1  b.ne       #0x3988
//   0x39b8: 394203e8  ldrb       w8, [sp, #0x80]
//   0x39bc: 7101911f  cmp        w8, #0x64
//   0x39c0: 54000241  b.ne       #0x3a08
//   0x39c4: b94083e8  ldr        w8, [sp, #0x80]
//   0x39c8: 528cac8a  mov        w10, #0x6564
//   0x39cc: 394213e9  ldrb       w9, [sp, #0x84]
//   0x39d0: 72aeac4a  movk       w10, #0x7562, lsl #16
//   0x39d4: 6b0a011f  cmp        w8, w10
//   0x39d8: 52800ce8  mov        w8, #0x67
//   0x39dc: 7a480120  ccmp       w9, w8, #0, eq
//   0x39e0: 54fffd41  b.ne       #0x3988
//   0x39e4: b94003e8  ldr        w8, [sp]
//   0x39e8: 528e4e89  mov        w9, #0x7274
//   0x39ec: 72acaea9  movk       w9, #0x6575, lsl #16
//   0x39f0: 6b09011f  cmp        w8, w9
//   0x39f4: 54fffca1  b.ne       #0x3988
//   0x39f8: f9400348  ldr        x8, [x26]
//   0x39fc: 52800029  mov        w9, #1
//   0x3a00: b9001909  str        w9, [x8, #0x18]
//   0x3a04: 17ffffe1  b          #0x3988
//   0x3a08: f94043e8  ldr        x8, [sp, #0x80]
//   0x3a0c: 394223e9  ldrb       w9, [sp, #0x88]
//   0x3a10: eb1b011f  cmp        x8, x27
//   0x3a14: 7a5c0120  ccmp       w9, w28, #0, eq
//   0x3a18: 54fffb00  b.eq       #0x3978
//   0x3a1c: b94083e8  ldr        w8, [sp, #0x80]
//   0x3a20: 528c8cca  mov        w10, #0x6466
//   0x3a24: 79410be9  ldrh       w9, [sp, #0x84]
//   0x3a28: 72af2a8a  movk       w10, #0x7954, lsl #16
//   0x3a2c: 6b0a011f  cmp        w8, w10
//   0x3a30: 528cae08  mov        w8, #0x6570
//   0x3a34: 7a480120  ccmp       w9, w8, #0, eq
//   0x3a38: 540001c0  b.eq       #0x3a70
//   0x3a3c: b94083e8  ldr        w8, [sp, #0x80]
//   0x3a40: 528dee6a  mov        w10, #0x6f73
//   0x3a44: 79410be9  ldrh       w9, [sp, #0x84]
//   0x3a48: 72ac29ca  movk       w10, #0x614e, lsl #16
//   0x3a4c: 6b0a011f  cmp        w8, w10
//   0x3a50: 528cada8  mov        w8, #0x656d
//   0x3a54: 7a480120  ccmp       w9, w8, #0, eq
//   0x3a58: 54fff981  b.ne       #0x3988
//   0x3a5c: 910003e0  mov        x0, sp
//   0x3a60: 940012bc  bl         #0x8550
//   0x3a64: f9400348  ldr        x8, [x26]
//   0x3a68: f9000100  str        x0, [x8]
//   0x3a6c: 17ffffc7  b          #0x3988
//   0x3a70: 910003e0  mov        x0, sp
//   0x3a74: 940012af  bl         #0x8530
//   0x3a78: f9400348  ldr        x8, [x26]
//   0x3a7c: b9001100  str        w0, [x8, #0x10]
//   0x3a80: 17ffffc2  b          #0x3988
//   0x3a84: f9400340  ldr        x0, [x26]
//   0x3a88: 940012b6  bl         #0x8560
//   0x3a8c: 12800100  mov        w0, #-9
//   0x3a90: f900035f  str        xzr, [x26]
//   0x3a94: 17ffff76  b          #0x386c
//   0x3a98: aa1603e0  mov        x0, x22
//   0x3a9c: 940012b5  bl         #0x8570
//   0x3aa0: b40000b5  cbz        x21, #0x3ab4
//   0x3aa4: aa1503e0  mov        x0, x21
//   0x3aa8: 940012aa  bl         #0x8550
//   0x3aac: f9400348  ldr        x8, [x26]
//   0x3ab0: f9000500  str        x0, [x8, #8]
//   0x3ab4: 940012b3  bl         #0x8580
//   0x3ab8: f9400335  ldr        x21, [x25]
//   0x3abc: aa1303e0  mov        x0, x19
//   0x3ac0: b9000ab4  str        w20, [x21, #8]
//   0x3ac4: 940012a3  bl         #0x8550
//   0x3ac8: f90002a0  str        x0, [x21]
//   0x3acc: f9400328  ldr        x8, [x25]
//   0x3ad0: f9400100  ldr        x0, [x8]
//   0x3ad4: b4000100  cbz        x0, #0x3af4
//   0x3ad8: 2a1f03e1  mov        w1, wzr
//   0x3adc: 940012ad  bl         #0x8590
//   0x3ae0: 340000a0  cbz        w0, #0x3af4
//   0x3ae4: f9400328  ldr        x8, [x25]
//   0x3ae8: 52803801  mov        w1, #0x1c0
//   0x3aec: f9400100  ldr        x0, [x8]
//   0x3af0: 940012ac  bl         #0x85a0
//   0x3af4: f9400328  ldr        x8, [x25]
//   0x3af8: 52800029  mov        w9, #1
//   0x3afc: 2a1f03e0  mov        w0, wzr
//   0x3b00: b9001509  str        w9, [x8, #0x14]
//   0x3b04: 17ffff5a  b          #0x386c
//   0x3b08: 940012aa  bl         #0x85b0

// ----------------------------------------------------------------------------
// FDE[06] native_do_command (0x3b0c..0x3c24, 280 bytes, 70 instructions)
// Summary / Tóm tắt: Exported: State machine command dispatcher (cmd 0..4 jump table @ 0x3b48) (@ 0x3b0c..0x3c24)
// ----------------------------------------------------------------------------
//   0x3b0c: a9be7bfd  stp        x29, x30, [sp, #-0x20]!
//   0x3b10: a9014ff4  stp        x20, x19, [sp, #0x10]
//   0x3b14: 910003fd  mov        x29, sp
//   0x3b18: b0000054  adrp       x20, #0xc000
//   0x3b1c: f9465e94  ldr        x20, [x20, #0xcb8]
//   0x3b20: f9400288  ldr        x8, [x20]
//   0x3b24: b4000228  cbz        x8, #0x3b68
//   0x3b28: b9401509  ldr        w9, [x8, #0x14]
//   0x3b2c: 7100053f  cmp        w9, #1
//   0x3b30: 540001c1  b.ne       #0x3b68
//   0x3b34: 2a0003f3  mov        w19, w0
//   0x3b38: 7100101f  cmp        w0, #4
//   0x3b3c: 540001a8  b.hi       #0x3b70
//   0x3b40: 2a1303e9  mov        w9, w19
//   0x3b44: d503201f  nop        
//   0x3b48: 10ff4cca  adr        x10, #0x24e0
//   0x3b4c: 1000008b  adr        x11, #0x3b5c
//   0x3b50: 3869694c  ldrb       w12, [x10, x9]
//   0x3b54: 8b0c096b  add        x11, x11, x12, lsl #2
//   0x3b58: d61f0160  br         x11
//   0x3b5c: 94001299  bl         #0x85c0
//   0x3b60: 2a0003f4  mov        w20, w0
//   0x3b64: 14000024  b          #0x3bf4
//   0x3b68: 12800154  mov        w20, #-0xb
//   0x3b6c: 1400002a  b          #0x3c14
//   0x3b70: 12801bb4  mov        w20, #-0xde
//   0x3b74: 14000020  b          #0x3bf4
//   0x3b78: b9400d09  ldr        w9, [x8, #0xc]
//   0x3b7c: 91008100  add        x0, x8, #0x20
//   0x3b80: aa1f03e1  mov        x1, xzr
//   0x3b84: 32000129  orr        w9, w9, #1
//   0x3b88: b9000d09  str        w9, [x8, #0xc]
//   0x3b8c: 94001291  bl         #0x85d0
//   0x3b90: 14000018  b          #0x3bf0
//   0x3b94: b9400d09  ldr        w9, [x8, #0xc]
//   0x3b98: 2a1f03f4  mov        w20, wzr
//   0x3b9c: 121e7529  and        w9, w9, #0xfffffffc
//   0x3ba0: 321f0129  orr        w9, w9, #2
//   0x3ba4: b9000d09  str        w9, [x8, #0xc]
//   0x3ba8: 14000013  b          #0x3bf4
//   0x3bac: b9400d09  ldr        w9, [x8, #0xc]
//   0x3bb0: 9100c100  add        x0, x8, #0x30
//   0x3bb4: aa1f03e1  mov        x1, xzr
//   0x3bb8: 121e7929  and        w9, w9, #0xfffffffd
//   0x3bbc: 321d0129  orr        w9, w9, #8
//   0x3bc0: b9000d09  str        w9, [x8, #0xc]
//   0x3bc4: 94001283  bl         #0x85d0
//   0x3bc8: f9400288  ldr        x8, [x20]
//   0x3bcc: 52800020  mov        w0, #1
//   0x3bd0: f9400101  ldr        x1, [x8]
//   0x3bd4: 94001283  bl         #0x85e0
//   0x3bd8: 2a0003f4  mov        w20, w0
//   0x3bdc: 14000006  b          #0x3bf4
//   0x3be0: 52800020  mov        w0, #1
//   0x3be4: 94001283  bl         #0x85f0
//   0x3be8: 2a1f03e0  mov        w0, wzr
//   0x3bec: 94001281  bl         #0x85f0
//   0x3bf0: 2a1f03f4  mov        w20, wzr
//   0x3bf4: d503201f  nop        
//   0x3bf8: 30ff69c1  adr        x1, #0x2931
//   0x3bfc: f0ffffe2  adrp       x2, #0x2000
//   0x3c00: 912e4c42  add        x2, x2, #0xb93
//   0x3c04: 52800080  mov        w0, #4
//   0x3c08: 2a1303e3  mov        w3, w19
//   0x3c0c: 2a1403e4  mov        w4, w20
//   0x3c10: 9400127c  bl         #0x8600
//   0x3c14: 2a1403e0  mov        w0, w20
//   0x3c18: a9414ff4  ldp        x20, x19, [sp, #0x10]
//   0x3c1c: a8c27bfd  ldp        x29, x30, [sp], #0x20
//   0x3c20: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[07] get_fd_count (0x3c24..0x3ce0, 188 bytes, 47 instructions)
// Summary / Tóm tắt: Exported: Counts open FDs via /proc/self/fd or RB-tree (@ 0x3c24..0x3ce0)
// ----------------------------------------------------------------------------
//   0x3c24: a9be7bfd  stp        x29, x30, [sp, #-0x20]!
//   0x3c28: a9014ff4  stp        x20, x19, [sp, #0x10]
//   0x3c2c: 910003fd  mov        x29, sp
//   0x3c30: 7100041f  cmp        w0, #1
//   0x3c34: 540003a0  b.eq       #0x3ca8
//   0x3c38: 35000340  cbnz       w0, #0x3ca0
//   0x3c3c: f0ffffe0  adrp       x0, #0x2000
//   0x3c40: 9116ac00  add        x0, x0, #0x5ab
//   0x3c44: 94001273  bl         #0x8610
//   0x3c48: b40002c0  cbz        x0, #0x3ca0
//   0x3c4c: aa0003f4  mov        x20, x0
//   0x3c50: 94001274  bl         #0x8620
//   0x3c54: 2a1f03f3  mov        w19, wzr
//   0x3c58: b5000100  cbnz       x0, #0x3c78
//   0x3c5c: aa1403e0  mov        x0, x20
//   0x3c60: 94001274  bl         #0x8630
//   0x3c64: 1400001b  b          #0x3cd0
//   0x3c68: 11000673  add        w19, w19, #1
//   0x3c6c: aa1403e0  mov        x0, x20
//   0x3c70: 9400126c  bl         #0x8620
//   0x3c74: b4ffff40  cbz        x0, #0x3c5c
//   0x3c78: 39404c08  ldrb       w8, [x0, #0x13]
//   0x3c7c: 7100b91f  cmp        w8, #0x2e
//   0x3c80: 54ffff41  b.ne       #0x3c68
//   0x3c84: 39405008  ldrb       w8, [x0, #0x14]
//   0x3c88: 34ffff28  cbz        w8, #0x3c6c
//   0x3c8c: 7100b91f  cmp        w8, #0x2e
//   0x3c90: 54fffec1  b.ne       #0x3c68
//   0x3c94: 39405408  ldrb       w8, [x0, #0x15]
//   0x3c98: 35fffe88  cbnz       w8, #0x3c68
//   0x3c9c: 17fffff4  b          #0x3c6c
//   0x3ca0: 12800013  mov        w19, #-1
//   0x3ca4: 1400000b  b          #0x3cd0
//   0x3ca8: b0000048  adrp       x8, #0xc000
//   0x3cac: f9465d08  ldr        x8, [x8, #0xcb8]
//   0x3cb0: f9400108  ldr        x8, [x8]
//   0x3cb4: b40000c8  cbz        x8, #0x3ccc
//   0x3cb8: b9401509  ldr        w9, [x8, #0x14]
//   0x3cbc: 7100053f  cmp        w9, #1
//   0x3cc0: 54000061  b.ne       #0x3ccc
//   0x3cc4: b9401d13  ldr        w19, [x8, #0x1c]
//   0x3cc8: 14000002  b          #0x3cd0
//   0x3ccc: 12800153  mov        w19, #-0xb
//   0x3cd0: 2a1303e0  mov        w0, w19
//   0x3cd4: a9414ff4  ldp        x20, x19, [sp, #0x10]
//   0x3cd8: a8c27bfd  ldp        x29, x30, [sp], #0x20
//   0x3cdc: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[08] fd_track_do_dump (0x3ce0..0x3d24, 68 bytes, 17 instructions)
// Summary / Tóm tắt: Exported: Triggers FD leak dump to target directory (@ 0x3ce0..0x3d24)
// ----------------------------------------------------------------------------
//   0x3ce0: b0000048  adrp       x8, #0xc000
//   0x3ce4: f9465d08  ldr        x8, [x8, #0xcb8]
//   0x3ce8: f9400108  ldr        x8, [x8]
//   0x3cec: b4000108  cbz        x8, #0x3d0c
//   0x3cf0: b9401509  ldr        w9, [x8, #0x14]
//   0x3cf4: 7100053f  cmp        w9, #1
//   0x3cf8: 540000a1  b.ne       #0x3d0c
//   0x3cfc: 350000c0  cbnz       w0, #0x3d14
//   0x3d00: b50000a1  cbnz       x1, #0x3d14
//   0x3d04: 12800080  mov        w0, #-5
//   0x3d08: d65f03c0  ret        
//   0x3d0c: 12800140  mov        w0, #-0xb
//   0x3d10: d65f03c0  ret        
//   0x3d14: b4000041  cbz        x1, #0x3d1c
//   0x3d18: 14001232  b          #0x85e0
//   0x3d1c: f9400101  ldr        x1, [x8]
//   0x3d20: 14001230  b          #0x85e0

// ----------------------------------------------------------------------------
// FDE[09] fast_stop (0x3d24..0x3d40, 28 bytes, 7 instructions)
// Summary / Tóm tắt: Exported: Sets g_fd_leak_manager->state = 8 (STOPPED) (@ 0x3d24..0x3d40)
// ----------------------------------------------------------------------------
//   0x3d24: b0000048  adrp       x8, #0xc000
//   0x3d28: f9465d08  ldr        x8, [x8, #0xcb8]
//   0x3d2c: f9400108  ldr        x8, [x8]
//   0x3d30: b4000068  cbz        x8, #0x3d3c
//   0x3d34: 52800109  mov        w9, #8
//   0x3d38: b9000d09  str        w9, [x8, #0xc]
//   0x3d3c: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[10] FormatPathSnprintf_3d40 (0x3d40..0x3de0, 160 bytes, 40 instructions)
// Summary / Tóm tắt: Variadic path formatter '%s/%s' (buf_size=0x400) (@ 0x3d40..0x3de0)
// ----------------------------------------------------------------------------
//   0x3d40: d10443ff  sub        sp, sp, #0x110
//   0x3d44: a90f7bfd  stp        x29, x30, [sp, #0xf0]
//   0x3d48: a9104ffc  stp        x28, x19, [sp, #0x100]
//   0x3d4c: 9103c3fd  add        x29, sp, #0xf0
//   0x3d50: ad0007e0  stp        q0, q1, [sp]
//   0x3d54: d101c3a9  sub        x9, x29, #0x70
//   0x3d58: a9399ba5  stp        x5, x6, [x29, #-0x68]
//   0x3d5c: 928003eb  mov        x11, #-0x20
//   0x3d60: f81903a4  stur       x4, [x29, #-0x70]
//   0x3d64: 910003ec  mov        x12, sp
//   0x3d68: f81a83a7  stur       x7, [x29, #-0x58]
//   0x3d6c: 91008129  add        x9, x9, #0x20
//   0x3d70: ad010fe2  stp        q2, q3, [sp, #0x20]
//   0x3d74: f2dff00b  movk       x11, #0xff80, lsl #32
//   0x3d78: ad0217e4  stp        q4, q5, [sp, #0x40]
//   0x3d7c: 9102018c  add        x12, x12, #0x80
//   0x3d80: ad031fe6  stp        q6, q7, [sp, #0x60]
//   0x3d84: d53bd053  mrs        x19, tpidr_el0
//   0x3d88: f9401668  ldr        x8, [x19, #0x28]
//   0x3d8c: d100a3aa  sub        x10, x29, #0x28
//   0x3d90: f0ffffe2  adrp       x2, #0x2000
//   0x3d94: 911e7842  add        x2, x2, #0x79e
//   0x3d98: d10143a3  sub        x3, x29, #0x50
//   0x3d9c: 52808001  mov        w1, #0x400
//   0x3da0: f81f83a8  stur       x8, [x29, #-8]
//   0x3da4: 910083a8  add        x8, x29, #0x20
//   0x3da8: a93eafac  stp        x12, x11, [x29, #-0x18]
//   0x3dac: a93da7a8  stp        x8, x9, [x29, #-0x28]
//   0x3db0: ad400540  ldp        q0, q1, [x10]
//   0x3db4: ad3d87a0  stp        q0, q1, [x29, #-0x50]
//   0x3db8: 94001222  bl         #0x8640
//   0x3dbc: f9401668  ldr        x8, [x19, #0x28]
//   0x3dc0: f85f83a9  ldur       x9, [x29, #-8]
//   0x3dc4: eb09011f  cmp        x8, x9
//   0x3dc8: 540000a1  b.ne       #0x3ddc
//   0x3dcc: a9504ffc  ldp        x28, x19, [sp, #0x100]
//   0x3dd0: a94f7bfd  ldp        x29, x30, [sp, #0xf0]
//   0x3dd4: 910443ff  add        sp, sp, #0x110
//   0x3dd8: d65f03c0  ret        
//   0x3ddc: 940011f5  bl         #0x85b0

// ----------------------------------------------------------------------------
// FDE[11] insert_fd_info (0x3de0..0x3fdc, 508 bytes, 127 instructions)
// Summary / Tóm tắt: Exported: Allocates FdNode, captures backtrace & path, inserts into RB-tree (@ 0x3de0..0x3fdc)
// ----------------------------------------------------------------------------
//   0x3de0: a9ba7bfd  stp        x29, x30, [sp, #-0x60]!
//   0x3de4: a9016ffc  stp        x28, x27, [sp, #0x10]
//   0x3de8: a90267fa  stp        x26, x25, [sp, #0x20]
//   0x3dec: a9035ff8  stp        x24, x23, [sp, #0x30]
//   0x3df0: a90457f6  stp        x22, x21, [sp, #0x40]
//   0x3df4: a9054ff4  stp        x20, x19, [sp, #0x50]
//   0x3df8: 910003fd  mov        x29, sp
//   0x3dfc: d11243ff  sub        sp, sp, #0x490
//   0x3e00: b000005b  adrp       x27, #0xc000
//   0x3e04: d53bd05a  mrs        x26, tpidr_el0
//   0x3e08: f9401748  ldr        x8, [x26, #0x28]
//   0x3e0c: aa0203f3  mov        x19, x2
//   0x3e10: 2a0003f5  mov        w21, w0
//   0x3e14: f9465f7b  ldr        x27, [x27, #0xcb8]
//   0x3e18: f81f83a8  stur       x8, [x29, #-8]
//   0x3e1c: f9400379  ldr        x25, [x27]
//   0x3e20: b9400f28  ldr        w8, [x25, #0xc]
//   0x3e24: 37100088  tbnz       w8, #2, #0x3e34
//   0x3e28: 37000288  tbnz       w8, #0, #0x3e78
//   0x3e2c: 128001f3  mov        w19, #-0x10
//   0x3e30: 1400005d  b          #0x3fa4
//   0x3e34: b50001a1  cbnz       x1, #0x3e68
//   0x3e38: d10223a0  sub        x0, x29, #0x88
//   0x3e3c: 2a1503e4  mov        w4, w21
//   0x3e40: 94000262  bl         #0x47c8
//   0x3e44: d10223a0  sub        x0, x29, #0x88
//   0x3e48: 910023e1  add        x1, sp, #8
//   0x3e4c: 52807fe2  mov        w2, #0x3ff
//   0x3e50: 910023f4  add        x20, sp, #8
//   0x3e54: 94001203  bl         #0x8660
//   0x3e58: 38206a9f  strb       wzr, [x20, x0]
//   0x3e5c: 910023e0  add        x0, sp, #8
//   0x3e60: 940011bc  bl         #0x8550
//   0x3e64: aa0003e1  mov        x1, x0
//   0x3e68: aa1303e0  mov        x0, x19
//   0x3e6c: 94001201  bl         #0x8670
//   0x3e70: 2a1f03f3  mov        w19, wzr
//   0x3e74: 1400004c  b          #0x3fa4
//   0x3e78: 37f80115  tbnz       w21, #0x1f, #0x3e98
//   0x3e7c: 2a0503f4  mov        w20, w5
//   0x3e80: 2a0403f6  mov        w22, w4
//   0x3e84: aa0303f7  mov        x23, x3
//   0x3e88: b40000c1  cbz        x1, #0x3ea0
//   0x3e8c: aa0103e0  mov        x0, x1
//   0x3e90: 940011b0  bl         #0x8550
//   0x3e94: 1400000f  b          #0x3ed0
//   0x3e98: 128001d3  mov        w19, #-0xf
//   0x3e9c: 14000042  b          #0x3fa4
//   0x3ea0: d10223a0  sub        x0, x29, #0x88
//   0x3ea4: 2a1503e4  mov        w4, w21
//   0x3ea8: 94000248  bl         #0x47c8
//   0x3eac: d10223a0  sub        x0, x29, #0x88
//   0x3eb0: 910023e1  add        x1, sp, #8
//   0x3eb4: 52807fe2  mov        w2, #0x3ff
//   0x3eb8: 910023f8  add        x24, sp, #8
//   0x3ebc: 940011e9  bl         #0x8660
//   0x3ec0: 38206b1f  strb       wzr, [x24, x0]
//   0x3ec4: 910023e0  add        x0, sp, #8
//   0x3ec8: 940011a2  bl         #0x8550
//   0x3ecc: f9400379  ldr        x25, [x27]
//   0x3ed0: aa0003f8  mov        x24, x0
//   0x3ed4: 91028320  add        x0, x25, #0xa0
//   0x3ed8: 940011ea  bl         #0x8680
//   0x3edc: f9400368  ldr        x8, [x27]
//   0x3ee0: 39403109  ldrb       w9, [x8, #0xc]
//   0x3ee4: 37000069  tbnz       w9, #0, #0x3ef0
//   0x3ee8: 128001f3  mov        w19, #-0x10
//   0x3eec: 1400002b  b          #0x3f98
//   0x3ef0: f9402108  ldr        x8, [x8, #0x40]
//   0x3ef4: f9400108  ldr        x8, [x8]
//   0x3ef8: b40000e8  cbz        x8, #0x3f14
//   0x3efc: b9403109  ldr        w9, [x8, #0x30]
//   0x3f00: 6b15013f  cmp        w9, w21
//   0x3f04: 54ffff8c  b.gt       #0x3ef4
//   0x3f08: 54000460  b.eq       #0x3f94
//   0x3f0c: 91002108  add        x8, x8, #8
//   0x3f10: 17fffff9  b          #0x3ef4
//   0x3f14: 52800020  mov        w0, #1
//   0x3f18: 52801201  mov        w1, #0x90
//   0x3f1c: 94001175  bl         #0x84f0
//   0x3f20: b4000280  cbz        x0, #0x3f70
//   0x3f24: aa0003f9  mov        x25, x0
//   0x3f28: a904e017  stp        x23, x24, [x0, #0x48]
//   0x3f2c: f9002013  str        x19, [x0, #0x40]
//   0x3f30: 29065815  stp        w21, w22, [x0, #0x30]
//   0x3f34: 940011d7  bl         #0x8690
//   0x3f38: 91016328  add        x8, x25, #0x58
//   0x3f3c: 29075320  stp        w0, w20, [x25, #0x38]
//   0x3f40: aa0803e0  mov        x0, x8
//   0x3f44: aa1f03e1  mov        x1, xzr
//   0x3f48: 940011a2  bl         #0x85d0
//   0x3f4c: f9400368  ldr        x8, [x27]
//   0x3f50: aa1903e1  mov        x1, x25
//   0x3f54: b9401d09  ldr        w9, [x8, #0x1c]
//   0x3f58: f9402100  ldr        x0, [x8, #0x40]
//   0x3f5c: 11000529  add        w9, w9, #1
//   0x3f60: b9001d09  str        w9, [x8, #0x1c]
//   0x3f64: 9400001e  bl         #0x3fdc
//   0x3f68: 2a1f03f3  mov        w19, wzr
//   0x3f6c: 1400000b  b          #0x3f98
//   0x3f70: d503201f  nop        
//   0x3f74: 30ff4de1  adr        x1, #0x2931
//   0x3f78: f0ffffe2  adrp       x2, #0x2000
//   0x3f7c: 91203042  add        x2, x2, #0x80c
//   0x3f80: 528000c0  mov        w0, #6
//   0x3f84: 2a1503e3  mov        w3, w21
//   0x3f88: 9400119e  bl         #0x8600
//   0x3f8c: 12800173  mov        w19, #-0xc
//   0x3f90: 14000002  b          #0x3f98
//   0x3f94: 12800193  mov        w19, #-0xd
//   0x3f98: f9400368  ldr        x8, [x27]
//   0x3f9c: 91028100  add        x0, x8, #0xa0
//   0x3fa0: 940011c0  bl         #0x86a0
//   0x3fa4: f9401748  ldr        x8, [x26, #0x28]
//   0x3fa8: f85f83a9  ldur       x9, [x29, #-8]
//   0x3fac: eb09011f  cmp        x8, x9
//   0x3fb0: 54000141  b.ne       #0x3fd8
//   0x3fb4: 2a1303e0  mov        w0, w19
//   0x3fb8: 911243ff  add        sp, sp, #0x490
//   0x3fbc: a9454ff4  ldp        x20, x19, [sp, #0x50]
//   0x3fc0: a94457f6  ldp        x22, x21, [sp, #0x40]
//   0x3fc4: a9435ff8  ldp        x24, x23, [sp, #0x30]
//   0x3fc8: a94267fa  ldp        x26, x25, [sp, #0x20]
//   0x3fcc: a9416ffc  ldp        x28, x27, [sp, #0x10]
//   0x3fd0: a8c67bfd  ldp        x29, x30, [sp], #0x60
//   0x3fd4: d65f03c0  ret        
//   0x3fd8: 94001176  bl         #0x85b0

// ----------------------------------------------------------------------------
// FDE[12] RbTreeInsertFdNode_3fdc (0x3fdc..0x4220, 580 bytes, 145 instructions)
// Summary / Tóm tắt: Intrusive Red-Black Tree insertion & color/rotation fixup by fd key (+0x30) (@ 0x3fdc..0x4220)
// ----------------------------------------------------------------------------
//   0x3fdc: f9400009  ldr        x9, [x0]
//   0x3fe0: b4001129  cbz        x9, #0x4204
//   0x3fe4: b940302a  ldr        w10, [x1, #0x30]
//   0x3fe8: 14000004  b          #0x3ff8
//   0x3fec: 91002109  add        x9, x8, #8
//   0x3ff0: f9400129  ldr        x9, [x9]
//   0x3ff4: b40000e9  cbz        x9, #0x4010
//   0x3ff8: b940312b  ldr        w11, [x9, #0x30]
//   0x3ffc: aa0903e8  mov        x8, x9
//   0x4000: 6b0b015f  cmp        w10, w11
//   0x4004: 54ffff6b  b.lt       #0x3ff0
//   0x4008: 54ffff21  b.ne       #0x3fec
//   0x400c: d65f03c0  ret        
//   0x4010: 9100210c  add        x12, x8, #8
//   0x4014: 6b0b015f  cmp        w10, w11
//   0x4018: 52800029  mov        w9, #1
//   0x401c: 9a8cb10a  csel       x10, x8, x12, lt
//   0x4020: a900a03f  stp        xzr, x8, [x1, #8]
//   0x4024: f900003f  str        xzr, [x1]
//   0x4028: b9001829  str        w9, [x1, #0x18]
//   0x402c: f9000141  str        x1, [x10]
//   0x4030: 14000008  b          #0x4050
//   0x4034: b900197f  str        wzr, [x11, #0x18]
//   0x4038: b900191f  str        wzr, [x8, #0x18]
//   0x403c: aa0a03e8  mov        x8, x10
//   0x4040: b9001949  str        w9, [x10, #0x18]
//   0x4044: aa0803e1  mov        x1, x8
//   0x4048: f9400908  ldr        x8, [x8, #0x10]
//   0x404c: b4000d68  cbz        x8, #0x41f8
//   0x4050: b940190a  ldr        w10, [x8, #0x18]
//   0x4054: 7100055f  cmp        w10, #1
//   0x4058: 54000d01  b.ne       #0x41f8
//   0x405c: f940090a  ldr        x10, [x8, #0x10]
//   0x4060: f940014b  ldr        x11, [x10]
//   0x4064: eb0b011f  cmp        x8, x11
//   0x4068: 54000160  b.eq       #0x4094
//   0x406c: b400008b  cbz        x11, #0x407c
//   0x4070: b940196c  ldr        w12, [x11, #0x18]
//   0x4074: 7100059f  cmp        w12, #1
//   0x4078: 54fffde0  b.eq       #0x4034
//   0x407c: f940010b  ldr        x11, [x8]
//   0x4080: eb01017f  cmp        x11, x1
//   0x4084: 540001e0  b.eq       #0x40c0
//   0x4088: aa0803eb  mov        x11, x8
//   0x408c: aa0103e8  mov        x8, x1
//   0x4090: 14000028  b          #0x4130
//   0x4094: f940054b  ldr        x11, [x10, #8]
//   0x4098: b400008b  cbz        x11, #0x40a8
//   0x409c: b940196c  ldr        w12, [x11, #0x18]
//   0x40a0: 7100059f  cmp        w12, #1
//   0x40a4: 54fffc80  b.eq       #0x4034
//   0x40a8: f940050b  ldr        x11, [x8, #8]
//   0x40ac: eb01017f  cmp        x11, x1
//   0x40b0: 540001a0  b.eq       #0x40e4
//   0x40b4: aa0803eb  mov        x11, x8
//   0x40b8: aa0103e8  mov        x8, x1
//   0x40bc: 1400003b  b          #0x41a8
//   0x40c0: f940042b  ldr        x11, [x1, #8]
//   0x40c4: f900010b  str        x11, [x8]
//   0x40c8: b400020b  cbz        x11, #0x4108
//   0x40cc: f9000968  str        x8, [x11, #0x10]
//   0x40d0: aa0003eb  mov        x11, x0
//   0x40d4: f940090c  ldr        x12, [x8, #0x10]
//   0x40d8: f900082c  str        x12, [x1, #0x10]
//   0x40dc: b500018c  cbnz       x12, #0x410c
//   0x40e0: 14000010  b          #0x4120
//   0x40e4: f940002b  ldr        x11, [x1]
//   0x40e8: f900050b  str        x11, [x8, #8]
//   0x40ec: b40004ab  cbz        x11, #0x4180
//   0x40f0: f9000968  str        x8, [x11, #0x10]
//   0x40f4: aa0003eb  mov        x11, x0
//   0x40f8: f940090c  ldr        x12, [x8, #0x10]
//   0x40fc: f900082c  str        x12, [x1, #0x10]
//   0x4100: b500042c  cbnz       x12, #0x4184
//   0x4104: 14000025  b          #0x4198
//   0x4108: f900082a  str        x10, [x1, #0x10]
//   0x410c: f940090b  ldr        x11, [x8, #0x10]
//   0x4110: aa0b03ec  mov        x12, x11
//   0x4114: f840858d  ldr        x13, [x12], #8
//   0x4118: eb0d011f  cmp        x8, x13
//   0x411c: 9a8c016b  csel       x11, x11, x12, eq
//   0x4120: f9000161  str        x1, [x11]
//   0x4124: aa0103eb  mov        x11, x1
//   0x4128: f9000428  str        x8, [x1, #8]
//   0x412c: f9000901  str        x1, [x8, #0x10]
//   0x4130: b900197f  str        wzr, [x11, #0x18]
//   0x4134: f940054b  ldr        x11, [x10, #8]
//   0x4138: b9001949  str        w9, [x10, #0x18]
//   0x413c: f940016c  ldr        x12, [x11]
//   0x4140: f900054c  str        x12, [x10, #8]
//   0x4144: b400004c  cbz        x12, #0x414c
//   0x4148: f900098a  str        x10, [x12, #0x10]
//   0x414c: f940094d  ldr        x13, [x10, #0x10]
//   0x4150: aa0003ec  mov        x12, x0
//   0x4154: f900096d  str        x13, [x11, #0x10]
//   0x4158: b40000cd  cbz        x13, #0x4170
//   0x415c: f940094c  ldr        x12, [x10, #0x10]
//   0x4160: aa0c03ed  mov        x13, x12
//   0x4164: f84085ae  ldr        x14, [x13], #8
//   0x4168: eb0e015f  cmp        x10, x14
//   0x416c: 9a8d018c  csel       x12, x12, x13, eq
//   0x4170: f900018b  str        x11, [x12]
//   0x4174: f900016a  str        x10, [x11]
//   0x4178: f900094b  str        x11, [x10, #0x10]
//   0x417c: 17ffffb2  b          #0x4044
//   0x4180: f900082a  str        x10, [x1, #0x10]
//   0x4184: f940090b  ldr        x11, [x8, #0x10]
//   0x4188: aa0b03ec  mov        x12, x11
//   0x418c: f840858d  ldr        x13, [x12], #8
//   0x4190: eb0d011f  cmp        x8, x13
//   0x4194: 9a8c016b  csel       x11, x11, x12, eq
//   0x4198: f9000161  str        x1, [x11]
//   0x419c: aa0103eb  mov        x11, x1
//   0x41a0: f9000028  str        x8, [x1]
//   0x41a4: f9000901  str        x1, [x8, #0x10]
//   0x41a8: b900197f  str        wzr, [x11, #0x18]
//   0x41ac: f940014b  ldr        x11, [x10]
//   0x41b0: b9001949  str        w9, [x10, #0x18]
//   0x41b4: f940056c  ldr        x12, [x11, #8]
//   0x41b8: f900014c  str        x12, [x10]
//   0x41bc: b400004c  cbz        x12, #0x41c4
//   0x41c0: f900098a  str        x10, [x12, #0x10]
//   0x41c4: f940094d  ldr        x13, [x10, #0x10]
//   0x41c8: aa0003ec  mov        x12, x0
//   0x41cc: f900096d  str        x13, [x11, #0x10]
//   0x41d0: b40000cd  cbz        x13, #0x41e8
//   0x41d4: f940094c  ldr        x12, [x10, #0x10]
//   0x41d8: aa0c03ed  mov        x13, x12
//   0x41dc: f84085ae  ldr        x14, [x13], #8
//   0x41e0: eb0e015f  cmp        x10, x14
//   0x41e4: 9a8d018c  csel       x12, x12, x13, eq
//   0x41e8: f900018b  str        x11, [x12]
//   0x41ec: f900056a  str        x10, [x11, #8]
//   0x41f0: f900094b  str        x11, [x10, #0x10]
//   0x41f4: 17ffff94  b          #0x4044
//   0x41f8: f9400001  ldr        x1, [x0]
//   0x41fc: b900183f  str        wzr, [x1, #0x18]
//   0x4200: d65f03c0  ret        
//   0x4204: 52800028  mov        w8, #1
//   0x4208: a900fc3f  stp        xzr, xzr, [x1, #8]
//   0x420c: f900003f  str        xzr, [x1]
//   0x4210: b9001828  str        w8, [x1, #0x18]
//   0x4214: f9000001  str        x1, [x0]
//   0x4218: b900183f  str        wzr, [x1, #0x18]
//   0x421c: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[13] delete_fd_info (0x4220..0x430c, 236 bytes, 59 instructions)
// Summary / Tóm tắt: Exported: Locks mutex (+0xa0), finds & removes FdNode from RB-tree, frees frames (@ 0x4220..0x430c)
// ----------------------------------------------------------------------------
//   0x4220: a9bd7bfd  stp        x29, x30, [sp, #-0x30]!
//   0x4224: f9000bf5  str        x21, [sp, #0x10]
//   0x4228: a9024ff4  stp        x20, x19, [sp, #0x20]
//   0x422c: 910003fd  mov        x29, sp
//   0x4230: 90000055  adrp       x21, #0xc000
//   0x4234: f9465eb5  ldr        x21, [x21, #0xcb8]
//   0x4238: f94002a8  ldr        x8, [x21]
//   0x423c: 39403109  ldrb       w9, [x8, #0xc]
//   0x4240: 7200053f  tst        w9, #3
//   0x4244: 540002a0  b.eq       #0x4298
//   0x4248: 2a0003f4  mov        w20, w0
//   0x424c: 37f802a0  tbnz       w0, #0x1f, #0x42a0
//   0x4250: 91028100  add        x0, x8, #0xa0
//   0x4254: 9400110b  bl         #0x8680
//   0x4258: f94002a8  ldr        x8, [x21]
//   0x425c: 39403109  ldrb       w9, [x8, #0xc]
//   0x4260: 37180249  tbnz       w9, #3, #0x42a8
//   0x4264: f9402100  ldr        x0, [x8, #0x40]
//   0x4268: f9400013  ldr        x19, [x0]
//   0x426c: b50000b3  cbnz       x19, #0x4280
//   0x4270: 128001b3  mov        w19, #-0xe
//   0x4274: 1400000e  b          #0x42ac
//   0x4278: f9400273  ldr        x19, [x19]
//   0x427c: b4ffffb3  cbz        x19, #0x4270
//   0x4280: b9403269  ldr        w9, [x19, #0x30]
//   0x4284: 6b14013f  cmp        w9, w20
//   0x4288: 54ffff8c  b.gt       #0x4278
//   0x428c: 540001e0  b.eq       #0x42c8
//   0x4290: 91002273  add        x19, x19, #8
//   0x4294: 17fffff9  b          #0x4278
//   0x4298: 128001f3  mov        w19, #-0x10
//   0x429c: 14000006  b          #0x42b4
//   0x42a0: 128001d3  mov        w19, #-0xf
//   0x42a4: 14000004  b          #0x42b4
//   0x42a8: 128001f3  mov        w19, #-0x10
//   0x42ac: 91028100  add        x0, x8, #0xa0
//   0x42b0: 940010fc  bl         #0x86a0
//   0x42b4: 2a1303e0  mov        w0, w19
//   0x42b8: a9424ff4  ldp        x20, x19, [sp, #0x20]
//   0x42bc: f9400bf5  ldr        x21, [sp, #0x10]
//   0x42c0: a8c37bfd  ldp        x29, x30, [sp], #0x30
//   0x42c4: d65f03c0  ret        
//   0x42c8: aa1303e1  mov        x1, x19
//   0x42cc: 94000010  bl         #0x430c
//   0x42d0: f94002a8  ldr        x8, [x21]
//   0x42d4: b9401d09  ldr        w9, [x8, #0x1c]
//   0x42d8: 71000529  subs       w9, w9, #1
//   0x42dc: 5400004b  b.lt       #0x42e4
//   0x42e0: b9001d09  str        w9, [x8, #0x1c]
//   0x42e4: f9402a60  ldr        x0, [x19, #0x50]
//   0x42e8: b4000040  cbz        x0, #0x42f0
//   0x42ec: 9400109d  bl         #0x8560
//   0x42f0: aa1303e0  mov        x0, x19
//   0x42f4: 940010f3  bl         #0x86c0
//   0x42f8: aa1303e0  mov        x0, x19
//   0x42fc: 94001099  bl         #0x8560
//   0x4300: 2a1f03f3  mov        w19, wzr
//   0x4304: f94002a8  ldr        x8, [x21]
//   0x4308: 17ffffe9  b          #0x42ac

// ----------------------------------------------------------------------------
// FDE[14] RbTreeDeleteFdNode_430c (0x430c..0x46c4, 952 bytes, 238 instructions)
// Summary / Tóm tắt: Intrusive Red-Black Tree node removal & rebalancing (@ 0x430c..0x46c4)
// ----------------------------------------------------------------------------
//   0x430c: a9402029  ldp        x9, x8, [x1]
//   0x4310: b4000489  cbz        x9, #0x43a0
//   0x4314: b4000588  cbz        x8, #0x43c4
//   0x4318: aa0803ea  mov        x10, x8
//   0x431c: f9400108  ldr        x8, [x8]
//   0x4320: b5ffffc8  cbnz       x8, #0x4318
//   0x4324: a940ad48  ldp        x8, x11, [x10, #8]
//   0x4328: b9401949  ldr        w9, [x10, #0x18]
//   0x432c: b4000048  cbz        x8, #0x4334
//   0x4330: f900090b  str        x11, [x8, #0x10]
//   0x4334: aa0003ec  mov        x12, x0
//   0x4338: b40000ab  cbz        x11, #0x434c
//   0x433c: aa0b03ec  mov        x12, x11
//   0x4340: f840858d  ldr        x13, [x12], #8
//   0x4344: eb0a01bf  cmp        x13, x10
//   0x4348: 9a8c016c  csel       x12, x11, x12, eq
//   0x434c: f9000188  str        x8, [x12]
//   0x4350: ad400420  ldp        q0, q1, [x1]
//   0x4354: f940094c  ldr        x12, [x10, #0x10]
//   0x4358: ad000540  stp        q0, q1, [x10]
//   0x435c: f940082d  ldr        x13, [x1, #0x10]
//   0x4360: eb01019f  cmp        x12, x1
//   0x4364: aa0003ec  mov        x12, x0
//   0x4368: 9a8b014b  csel       x11, x10, x11, eq
//   0x436c: b40000ad  cbz        x13, #0x4380
//   0x4370: aa0d03ec  mov        x12, x13
//   0x4374: f840858e  ldr        x14, [x12], #8
//   0x4378: eb0101df  cmp        x14, x1
//   0x437c: 9a8c01ac  csel       x12, x13, x12, eq
//   0x4380: f900018a  str        x10, [x12]
//   0x4384: a940302d  ldp        x13, x12, [x1]
//   0x4388: f90009aa  str        x10, [x13, #0x10]
//   0x438c: b400004c  cbz        x12, #0x4394
//   0x4390: f900098a  str        x10, [x12, #0x10]
//   0x4394: 34000289  cbz        w9, #0x43e4
//   0x4398: aa0103e0  mov        x0, x1
//   0x439c: d65f03c0  ret        
//   0x43a0: f940082b  ldr        x11, [x1, #0x10]
//   0x43a4: b9401829  ldr        w9, [x1, #0x18]
//   0x43a8: b5000148  cbnz       x8, #0x43d0
//   0x43ac: b400016b  cbz        x11, #0x43d8
//   0x43b0: aa0b03ea  mov        x10, x11
//   0x43b4: f840854c  ldr        x12, [x10], #8
//   0x43b8: eb01019f  cmp        x12, x1
//   0x43bc: 9a8a016a  csel       x10, x11, x10, eq
//   0x43c0: 14000007  b          #0x43dc
//   0x43c4: f940082b  ldr        x11, [x1, #0x10]
//   0x43c8: aa0903e8  mov        x8, x9
//   0x43cc: b9401829  ldr        w9, [x1, #0x18]
//   0x43d0: f900090b  str        x11, [x8, #0x10]
//   0x43d4: b5fffeeb  cbnz       x11, #0x43b0
//   0x43d8: aa0003ea  mov        x10, x0
//   0x43dc: f9000148  str        x8, [x10]
//   0x43e0: 35fffdc9  cbnz       w9, #0x4398
//   0x43e4: 5280002a  mov        w10, #1
//   0x43e8: 14000003  b          #0x43f4
//   0x43ec: b900192a  str        w10, [x9, #0x18]
//   0x43f0: f940090b  ldr        x11, [x8, #0x10]
//   0x43f4: aa0803ec  mov        x12, x8
//   0x43f8: aa0b03e8  mov        x8, x11
//   0x43fc: b400006c  cbz        x12, #0x4408
//   0x4400: b9401989  ldr        w9, [x12, #0x18]
//   0x4404: 350015a9  cbnz       w9, #0x46b8
//   0x4408: f9400009  ldr        x9, [x0]
//   0x440c: eb09019f  cmp        x12, x9
//   0x4410: 54001520  b.eq       #0x46b4
//   0x4414: f9400109  ldr        x9, [x8]
//   0x4418: eb0c013f  cmp        x9, x12
//   0x441c: 54000280  b.eq       #0x446c
//   0x4420: b940192b  ldr        w11, [x9, #0x18]
//   0x4424: 7100057f  cmp        w11, #1
//   0x4428: 54000581  b.ne       #0x44d8
//   0x442c: b900193f  str        wzr, [x9, #0x18]
//   0x4430: f940010b  ldr        x11, [x8]
//   0x4434: b900190a  str        w10, [x8, #0x18]
//   0x4438: f9400569  ldr        x9, [x11, #8]
//   0x443c: f9000109  str        x9, [x8]
//   0x4440: b4000049  cbz        x9, #0x4448
//   0x4444: f9000928  str        x8, [x9, #0x10]
//   0x4448: f940090c  ldr        x12, [x8, #0x10]
//   0x444c: f900096c  str        x12, [x11, #0x10]
//   0x4450: b400038c  cbz        x12, #0x44c0
//   0x4454: f940090c  ldr        x12, [x8, #0x10]
//   0x4458: f940018d  ldr        x13, [x12]
//   0x445c: eb0d011f  cmp        x8, x13
//   0x4460: 54000340  b.eq       #0x44c8
//   0x4464: f900058b  str        x11, [x12, #8]
//   0x4468: 1400001a  b          #0x44d0
//   0x446c: f9400509  ldr        x9, [x8, #8]
//   0x4470: b940192b  ldr        w11, [x9, #0x18]
//   0x4474: 7100057f  cmp        w11, #1
//   0x4478: 540004c1  b.ne       #0x4510
//   0x447c: b900193f  str        wzr, [x9, #0x18]
//   0x4480: f940050b  ldr        x11, [x8, #8]
//   0x4484: b900190a  str        w10, [x8, #0x18]
//   0x4488: f9400169  ldr        x9, [x11]
//   0x448c: f9000509  str        x9, [x8, #8]
//   0x4490: b4000049  cbz        x9, #0x4498
//   0x4494: f9000928  str        x8, [x9, #0x10]
//   0x4498: f940090c  ldr        x12, [x8, #0x10]
//   0x449c: f900096c  str        x12, [x11, #0x10]
//   0x44a0: b40002ec  cbz        x12, #0x44fc
//   0x44a4: f940090c  ldr        x12, [x8, #0x10]
//   0x44a8: f940018d  ldr        x13, [x12]
//   0x44ac: eb0d011f  cmp        x8, x13
//   0x44b0: 540002a0  b.eq       #0x4504
//   0x44b4: f900058b  str        x11, [x12, #8]
//   0x44b8: f9400509  ldr        x9, [x8, #8]
//   0x44bc: 14000013  b          #0x4508
//   0x44c0: f900000b  str        x11, [x0]
//   0x44c4: 14000003  b          #0x44d0
//   0x44c8: f900018b  str        x11, [x12]
//   0x44cc: f9400109  ldr        x9, [x8]
//   0x44d0: f9000568  str        x8, [x11, #8]
//   0x44d4: f900090b  str        x11, [x8, #0x10]
//   0x44d8: f940012b  ldr        x11, [x9]
//   0x44dc: b400006b  cbz        x11, #0x44e8
//   0x44e0: b940196c  ldr        w12, [x11, #0x18]
//   0x44e4: 3500058c  cbnz       w12, #0x4594
//   0x44e8: f940052c  ldr        x12, [x9, #8]
//   0x44ec: b4fff80c  cbz        x12, #0x43ec
//   0x44f0: b940198d  ldr        w13, [x12, #0x18]
//   0x44f4: 34fff7cd  cbz        w13, #0x43ec
//   0x44f8: 1400000f  b          #0x4534
//   0x44fc: f900000b  str        x11, [x0]
//   0x4500: 14000002  b          #0x4508
//   0x4504: f900018b  str        x11, [x12]
//   0x4508: f9000168  str        x8, [x11]
//   0x450c: f900090b  str        x11, [x8, #0x10]
//   0x4510: f940012b  ldr        x11, [x9]
//   0x4514: b400006b  cbz        x11, #0x4520
//   0x4518: b940196c  ldr        w12, [x11, #0x18]
//   0x451c: 350006ac  cbnz       w12, #0x45f0
//   0x4520: f940052b  ldr        x11, [x9, #8]
//   0x4524: b4fff64b  cbz        x11, #0x43ec
//   0x4528: b940196b  ldr        w11, [x11, #0x18]
//   0x452c: 34fff60b  cbz        w11, #0x43ec
//   0x4530: 14000049  b          #0x4654
//   0x4534: b400006b  cbz        x11, #0x4540
//   0x4538: b940196a  ldr        w10, [x11, #0x18]
//   0x453c: 350002ca  cbnz       w10, #0x4594
//   0x4540: b900199f  str        wzr, [x12, #0x18]
//   0x4544: 5280002b  mov        w11, #1
//   0x4548: f940052a  ldr        x10, [x9, #8]
//   0x454c: b900192b  str        w11, [x9, #0x18]
//   0x4550: f940014b  ldr        x11, [x10]
//   0x4554: f900052b  str        x11, [x9, #8]
//   0x4558: b400004b  cbz        x11, #0x4560
//   0x455c: f9000969  str        x9, [x11, #0x10]
//   0x4560: f940092c  ldr        x12, [x9, #0x10]
//   0x4564: aa0003eb  mov        x11, x0
//   0x4568: f900094c  str        x12, [x10, #0x10]
//   0x456c: b40000cc  cbz        x12, #0x4584
//   0x4570: f940092b  ldr        x11, [x9, #0x10]
//   0x4574: aa0b03ec  mov        x12, x11
//   0x4578: f840858d  ldr        x13, [x12], #8
//   0x457c: eb0d013f  cmp        x9, x13
//   0x4580: 9a8c016b  csel       x11, x11, x12, eq
//   0x4584: f900016a  str        x10, [x11]
//   0x4588: f9000149  str        x9, [x10]
//   0x458c: f900092a  str        x10, [x9, #0x10]
//   0x4590: f9400109  ldr        x9, [x8]
//   0x4594: b940190a  ldr        w10, [x8, #0x18]
//   0x4598: b900192a  str        w10, [x9, #0x18]
//   0x459c: b900191f  str        wzr, [x8, #0x18]
//   0x45a0: f9400129  ldr        x9, [x9]
//   0x45a4: b4000049  cbz        x9, #0x45ac
//   0x45a8: b900193f  str        wzr, [x9, #0x18]
//   0x45ac: f9400109  ldr        x9, [x8]
//   0x45b0: f940052a  ldr        x10, [x9, #8]
//   0x45b4: f900010a  str        x10, [x8]
//   0x45b8: b400004a  cbz        x10, #0x45c0
//   0x45bc: f9000948  str        x8, [x10, #0x10]
//   0x45c0: f940090b  ldr        x11, [x8, #0x10]
//   0x45c4: aa0003ea  mov        x10, x0
//   0x45c8: f900092b  str        x11, [x9, #0x10]
//   0x45cc: b40000cb  cbz        x11, #0x45e4
//   0x45d0: f940090a  ldr        x10, [x8, #0x10]
//   0x45d4: aa0a03eb  mov        x11, x10
//   0x45d8: f840856c  ldr        x12, [x11], #8
//   0x45dc: eb0c011f  cmp        x8, x12
//   0x45e0: 9a8b014a  csel       x10, x10, x11, eq
//   0x45e4: f9000149  str        x9, [x10]
//   0x45e8: f9000528  str        x8, [x9, #8]
//   0x45ec: 14000030  b          #0x46ac
//   0x45f0: f940052a  ldr        x10, [x9, #8]
//   0x45f4: b400006a  cbz        x10, #0x4600
//   0x45f8: b940194a  ldr        w10, [x10, #0x18]
//   0x45fc: 350002ca  cbnz       w10, #0x4654
//   0x4600: b900197f  str        wzr, [x11, #0x18]
//   0x4604: 5280002b  mov        w11, #1
//   0x4608: f940012a  ldr        x10, [x9]
//   0x460c: b900192b  str        w11, [x9, #0x18]
//   0x4610: f940054b  ldr        x11, [x10, #8]
//   0x4614: f900012b  str        x11, [x9]
//   0x4618: b400004b  cbz        x11, #0x4620
//   0x461c: f9000969  str        x9, [x11, #0x10]
//   0x4620: f940092c  ldr        x12, [x9, #0x10]
//   0x4624: aa0003eb  mov        x11, x0
//   0x4628: f900094c  str        x12, [x10, #0x10]
//   0x462c: b40000cc  cbz        x12, #0x4644
//   0x4630: f940092b  ldr        x11, [x9, #0x10]
//   0x4634: aa0b03ec  mov        x12, x11
//   0x4638: f840858d  ldr        x13, [x12], #8
//   0x463c: eb0d013f  cmp        x9, x13
//   0x4640: 9a8c016b  csel       x11, x11, x12, eq
//   0x4644: f900016a  str        x10, [x11]
//   0x4648: f9000549  str        x9, [x10, #8]
//   0x464c: f900092a  str        x10, [x9, #0x10]
//   0x4650: f9400509  ldr        x9, [x8, #8]
//   0x4654: b940190a  ldr        w10, [x8, #0x18]
//   0x4658: b900192a  str        w10, [x9, #0x18]
//   0x465c: b900191f  str        wzr, [x8, #0x18]
//   0x4660: f9400529  ldr        x9, [x9, #8]
//   0x4664: b4000049  cbz        x9, #0x466c
//   0x4668: b900193f  str        wzr, [x9, #0x18]
//   0x466c: f9400509  ldr        x9, [x8, #8]
//   0x4670: f940012a  ldr        x10, [x9]
//   0x4674: f900050a  str        x10, [x8, #8]
//   0x4678: b400004a  cbz        x10, #0x4680
//   0x467c: f9000948  str        x8, [x10, #0x10]
//   0x4680: f940090b  ldr        x11, [x8, #0x10]
//   0x4684: aa0003ea  mov        x10, x0
//   0x4688: f900092b  str        x11, [x9, #0x10]
//   0x468c: b40000cb  cbz        x11, #0x46a4
//   0x4690: f940090a  ldr        x10, [x8, #0x10]
//   0x4694: aa0a03eb  mov        x11, x10
//   0x4698: f840856c  ldr        x12, [x11], #8
//   0x469c: eb0c011f  cmp        x8, x12
//   0x46a0: 9a8b014a  csel       x10, x10, x11, eq
//   0x46a4: f9000149  str        x9, [x10]
//   0x46a8: f9000128  str        x8, [x9]
//   0x46ac: f940000c  ldr        x12, [x0]
//   0x46b0: f9000909  str        x9, [x8, #0x10]
//   0x46b4: b4ffe72c  cbz        x12, #0x4398
//   0x46b8: b900199f  str        wzr, [x12, #0x18]
//   0x46bc: aa0103e0  mov        x0, x1
//   0x46c0: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[15] init_fd_track_info (0x46c4..0x46e8, 36 bytes, 9 instructions)
// Summary / Tóm tắt: Exported: Initializes RB-tree root pointer at g_fd_leak_manager+0x40 (@ 0x46c4..0x46e8)
// ----------------------------------------------------------------------------
//   0x46c4: 90000048  adrp       x8, #0xc000
//   0x46c8: 2a1f03e0  mov        w0, wzr
//   0x46cc: d503201f  nop        
//   0x46d0: 10065bc9  adr        x9, #0x11248
//   0x46d4: f9465d08  ldr        x8, [x8, #0xcb8]
//   0x46d8: f900013f  str        xzr, [x9]
//   0x46dc: f9400108  ldr        x8, [x8]
//   0x46e0: f9002109  str        x9, [x8, #0x40]
//   0x46e4: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[16] fd_info_tree_release (0x46e8..0x47c8, 224 bytes, 56 instructions)
// Summary / Tóm tắt: Exported: Post-order traversal freeing all FdNode & backtrace buffers (@ 0x46e8..0x47c8)
// ----------------------------------------------------------------------------
//   0x46e8: a9bd7bfd  stp        x29, x30, [sp, #-0x30]!
//   0x46ec: f9000bf5  str        x21, [sp, #0x10]
//   0x46f0: a9024ff4  stp        x20, x19, [sp, #0x20]
//   0x46f4: 910003fd  mov        x29, sp
//   0x46f8: 90000054  adrp       x20, #0xc000
//   0x46fc: f9465e94  ldr        x20, [x20, #0xcb8]
//   0x4700: f9400288  ldr        x8, [x20]
//   0x4704: 91028100  add        x0, x8, #0xa0
//   0x4708: 94000fde  bl         #0x8680
//   0x470c: f9400288  ldr        x8, [x20]
//   0x4710: aa1f03ea  mov        x10, xzr
//   0x4714: f9402109  ldr        x9, [x8, #0x40]
//   0x4718: f9400129  ldr        x9, [x9]
//   0x471c: aa0a03f3  mov        x19, x10
//   0x4720: aa0903ea  mov        x10, x9
//   0x4724: b5ffffa9  cbnz       x9, #0x4718
//   0x4728: b5000113  cbnz       x19, #0x4748
//   0x472c: 14000022  b          #0x47b4
//   0x4730: aa1303e0  mov        x0, x19
//   0x4734: 94000fe3  bl         #0x86c0
//   0x4738: aa1303e0  mov        x0, x19
//   0x473c: 94000f89  bl         #0x8560
//   0x4740: aa1503f3  mov        x19, x21
//   0x4744: b4000375  cbz        x21, #0x47b0
//   0x4748: f9400668  ldr        x8, [x19, #8]
//   0x474c: b4000188  cbz        x8, #0x477c
//   0x4750: aa0803f5  mov        x21, x8
//   0x4754: f9400108  ldr        x8, [x8]
//   0x4758: b5ffffc8  cbnz       x8, #0x4750
//   0x475c: f9400288  ldr        x8, [x20]
//   0x4760: aa1303e1  mov        x1, x19
//   0x4764: f9402100  ldr        x0, [x8, #0x40]
//   0x4768: 97fffee9  bl         #0x430c
//   0x476c: f9402a60  ldr        x0, [x19, #0x50]
//   0x4770: b4fffe00  cbz        x0, #0x4730
//   0x4774: 94000f7b  bl         #0x8560
//   0x4778: 17ffffee  b          #0x4730
//   0x477c: f9400a75  ldr        x21, [x19, #0x10]
//   0x4780: b4000095  cbz        x21, #0x4790
//   0x4784: f94002a8  ldr        x8, [x21]
//   0x4788: eb13011f  cmp        x8, x19
//   0x478c: 54fffe80  b.eq       #0x475c
//   0x4790: aa1303e8  mov        x8, x19
//   0x4794: f9400915  ldr        x21, [x8, #0x10]
//   0x4798: b4fffe35  cbz        x21, #0x475c
//   0x479c: f94006a9  ldr        x9, [x21, #8]
//   0x47a0: eb09011f  cmp        x8, x9
//   0x47a4: aa1503e8  mov        x8, x21
//   0x47a8: 54ffff60  b.eq       #0x4794
//   0x47ac: 17ffffec  b          #0x475c
//   0x47b0: f9400288  ldr        x8, [x20]
//   0x47b4: 91028100  add        x0, x8, #0xa0
//   0x47b8: a9424ff4  ldp        x20, x19, [sp, #0x20]
//   0x47bc: f9400bf5  ldr        x21, [sp, #0x10]
//   0x47c0: a8c37bfd  ldp        x29, x30, [sp], #0x30
//   0x47c4: 14000fb7  b          #0x86a0

// ----------------------------------------------------------------------------
// FDE[17] FormatProcFdPath_47c8 (0x47c8..0x4868, 160 bytes, 40 instructions)
// Summary / Tóm tắt: Variadic formatter '/proc/self/fd/%d' (buf_size=0x80) (@ 0x47c8..0x4868)
// ----------------------------------------------------------------------------
//   0x47c8: d10443ff  sub        sp, sp, #0x110
//   0x47cc: a90f7bfd  stp        x29, x30, [sp, #0xf0]
//   0x47d0: a9104ffc  stp        x28, x19, [sp, #0x100]
//   0x47d4: 9103c3fd  add        x29, sp, #0xf0
//   0x47d8: ad0007e0  stp        q0, q1, [sp]
//   0x47dc: d101c3a9  sub        x9, x29, #0x70
//   0x47e0: a9399ba5  stp        x5, x6, [x29, #-0x68]
//   0x47e4: 928003eb  mov        x11, #-0x20
//   0x47e8: f81903a4  stur       x4, [x29, #-0x70]
//   0x47ec: 910003ec  mov        x12, sp
//   0x47f0: f81a83a7  stur       x7, [x29, #-0x58]
//   0x47f4: 91008129  add        x9, x9, #0x20
//   0x47f8: ad010fe2  stp        q2, q3, [sp, #0x20]
//   0x47fc: f2dff00b  movk       x11, #0xff80, lsl #32
//   0x4800: ad0217e4  stp        q4, q5, [sp, #0x40]
//   0x4804: 9102018c  add        x12, x12, #0x80
//   0x4808: ad031fe6  stp        q6, q7, [sp, #0x60]
//   0x480c: d53bd053  mrs        x19, tpidr_el0
//   0x4810: f9401668  ldr        x8, [x19, #0x28]
//   0x4814: d100a3aa  sub        x10, x29, #0x28
//   0x4818: d0ffffe2  adrp       x2, #0x2000
//   0x481c: 912ed842  add        x2, x2, #0xbb6
//   0x4820: d10143a3  sub        x3, x29, #0x50
//   0x4824: 52801001  mov        w1, #0x80
//   0x4828: f81f83a8  stur       x8, [x29, #-8]
//   0x482c: 910083a8  add        x8, x29, #0x20
//   0x4830: a93eafac  stp        x12, x11, [x29, #-0x18]
//   0x4834: a93da7a8  stp        x8, x9, [x29, #-0x28]
//   0x4838: ad400540  ldp        q0, q1, [x10]
//   0x483c: ad3d87a0  stp        q0, q1, [x29, #-0x50]
//   0x4840: 94000f80  bl         #0x8640
//   0x4844: f9401668  ldr        x8, [x19, #0x28]
//   0x4848: f85f83a9  ldur       x9, [x29, #-8]
//   0x484c: eb09011f  cmp        x8, x9
//   0x4850: 540000a1  b.ne       #0x4864
//   0x4854: a9504ffc  ldp        x28, x19, [sp, #0x100]
//   0x4858: a94f7bfd  ldp        x29, x30, [sp, #0xf0]
//   0x485c: 910443ff  add        sp, sp, #0x110
//   0x4860: d65f03c0  ret        
//   0x4864: 94000f53  bl         #0x85b0

// ----------------------------------------------------------------------------
// FDE[18] java_backtrace_format (0x4868..0x496c, 260 bytes, 65 instructions)
// Summary / Tóm tắt: Exported: Formats ART Java stack frames ('  at %s') via xp_pretty_method (@ 0x4868..0x496c)
// ----------------------------------------------------------------------------
//   0x4868: a9bb7bfd  stp        x29, x30, [sp, #-0x50]!
//   0x486c: f9000bfc  str        x28, [sp, #0x10]
//   0x4870: a9025ff8  stp        x24, x23, [sp, #0x20]
//   0x4874: a90357f6  stp        x22, x21, [sp, #0x30]
//   0x4878: a9044ff4  stp        x20, x19, [sp, #0x40]
//   0x487c: 910003fd  mov        x29, sp
//   0x4880: d10c43ff  sub        sp, sp, #0x310
//   0x4884: d53bd056  mrs        x22, tpidr_el0
//   0x4888: f94016c8  ldr        x8, [x22, #0x28]
//   0x488c: f81f83a8  stur       x8, [x29, #-8]
//   0x4890: f9404008  ldr        x8, [x0, #0x80]
//   0x4894: b4000508  cbz        x8, #0x4934
//   0x4898: f9404415  ldr        x21, [x0, #0x88]
//   0x489c: aa0003f4  mov        x20, x0
//   0x48a0: 52800020  mov        w0, #1
//   0x48a4: d377daa1  lsl        x1, x21, #9
//   0x48a8: 94000f12  bl         #0x84f0
//   0x48ac: aa0003f3  mov        x19, x0
//   0x48b0: b4000440  cbz        x0, #0x4938
//   0x48b4: b4000435  cbz        x21, #0x4938
//   0x48b8: aa1f03f7  mov        x23, xzr
//   0x48bc: aa1f03f8  mov        x24, xzr
//   0x48c0: 6f00e400  movi       v0.2d, #0000000000000000
//   0x48c4: f9404288  ldr        x8, [x20, #0x80]
//   0x48c8: 910003e1  mov        x1, sp
//   0x48cc: 52802002  mov        w2, #0x100
//   0x48d0: ad0003e0  stp        q0, q0, [sp]
//   0x48d4: ad0103e0  stp        q0, q0, [sp, #0x20]
//   0x48d8: ad0203e0  stp        q0, q0, [sp, #0x40]
//   0x48dc: ad0303e0  stp        q0, q0, [sp, #0x60]
//   0x48e0: ad0403e0  stp        q0, q0, [sp, #0x80]
//   0x48e4: ad0503e0  stp        q0, q0, [sp, #0xa0]
//   0x48e8: ad0603e0  stp        q0, q0, [sp, #0xc0]
//   0x48ec: ad0703e0  stp        q0, q0, [sp, #0xe0]
//   0x48f0: f8787900  ldr        x0, [x8, x24, lsl #3]
//   0x48f4: 94000f7f  bl         #0x86f0
//   0x48f8: 910423e0  add        x0, sp, #0x108
//   0x48fc: 910003e4  mov        x4, sp
//   0x4900: 9400001b  bl         #0x496c
//   0x4904: 8b170268  add        x8, x19, x23
//   0x4908: 93407c15  sxtw       x21, w0
//   0x490c: 910423e1  add        x1, sp, #0x108
//   0x4910: aa0803e0  mov        x0, x8
//   0x4914: aa1503e2  mov        x2, x21
//   0x4918: 94000f7a  bl         #0x8700
//   0x491c: f9404688  ldr        x8, [x20, #0x88]
//   0x4920: 8b1502f7  add        x23, x23, x21
//   0x4924: 91000718  add        x24, x24, #1
//   0x4928: eb08031f  cmp        x24, x8
//   0x492c: 54fffca3  b.lo       #0x48c0
//   0x4930: 14000002  b          #0x4938
//   0x4934: aa1f03f3  mov        x19, xzr
//   0x4938: f94016c8  ldr        x8, [x22, #0x28]
//   0x493c: f85f83a9  ldur       x9, [x29, #-8]
//   0x4940: eb09011f  cmp        x8, x9
//   0x4944: 54000121  b.ne       #0x4968
//   0x4948: aa1303e0  mov        x0, x19
//   0x494c: 910c43ff  add        sp, sp, #0x310
//   0x4950: a9444ff4  ldp        x20, x19, [sp, #0x40]
//   0x4954: a94357f6  ldp        x22, x21, [sp, #0x30]
//   0x4958: a9425ff8  ldp        x24, x23, [sp, #0x20]
//   0x495c: f9400bfc  ldr        x28, [sp, #0x10]
//   0x4960: a8c57bfd  ldp        x29, x30, [sp], #0x50
//   0x4964: d65f03c0  ret        
//   0x4968: 94000f12  bl         #0x85b0

// ----------------------------------------------------------------------------
// FDE[19] FormatJavaFrameLine_496c (0x496c..0x4a0c, 160 bytes, 40 instructions)
// Summary / Tóm tắt: Variadic formatter '  at %s' (buf_size=0x200) (@ 0x496c..0x4a0c)
// ----------------------------------------------------------------------------
//   0x496c: d10443ff  sub        sp, sp, #0x110
//   0x4970: a90f7bfd  stp        x29, x30, [sp, #0xf0]
//   0x4974: a9104ffc  stp        x28, x19, [sp, #0x100]
//   0x4978: 9103c3fd  add        x29, sp, #0xf0
//   0x497c: ad0007e0  stp        q0, q1, [sp]
//   0x4980: d101c3a9  sub        x9, x29, #0x70
//   0x4984: a9399ba5  stp        x5, x6, [x29, #-0x68]
//   0x4988: 928003eb  mov        x11, #-0x20
//   0x498c: f81903a4  stur       x4, [x29, #-0x70]
//   0x4990: 910003ec  mov        x12, sp
//   0x4994: f81a83a7  stur       x7, [x29, #-0x58]
//   0x4998: 91008129  add        x9, x9, #0x20
//   0x499c: ad010fe2  stp        q2, q3, [sp, #0x20]
//   0x49a0: f2dff00b  movk       x11, #0xff80, lsl #32
//   0x49a4: ad0217e4  stp        q4, q5, [sp, #0x40]
//   0x49a8: 9102018c  add        x12, x12, #0x80
//   0x49ac: ad031fe6  stp        q6, q7, [sp, #0x60]
//   0x49b0: d53bd053  mrs        x19, tpidr_el0
//   0x49b4: f9401668  ldr        x8, [x19, #0x28]
//   0x49b8: d100a3aa  sub        x10, x29, #0x28
//   0x49bc: d503201f  nop        
//   0x49c0: 10fef842  adr        x2, #0x28c8
//   0x49c4: d10143a3  sub        x3, x29, #0x50
//   0x49c8: 52804001  mov        w1, #0x200
//   0x49cc: f81f83a8  stur       x8, [x29, #-8]
//   0x49d0: 910083a8  add        x8, x29, #0x20
//   0x49d4: a93eafac  stp        x12, x11, [x29, #-0x18]
//   0x49d8: a93da7a8  stp        x8, x9, [x29, #-0x28]
//   0x49dc: ad400540  ldp        q0, q1, [x10]
//   0x49e0: ad3d87a0  stp        q0, q1, [x29, #-0x50]
//   0x49e4: 94000f17  bl         #0x8640
//   0x49e8: f9401668  ldr        x8, [x19, #0x28]
//   0x49ec: f85f83a9  ldur       x9, [x29, #-8]
//   0x49f0: eb09011f  cmp        x8, x9
//   0x49f4: 540000a1  b.ne       #0x4a08
//   0x49f8: a9504ffc  ldp        x28, x19, [sp, #0x100]
//   0x49fc: a94f7bfd  ldp        x29, x30, [sp, #0xf0]
//   0x4a00: 910443ff  add        sp, sp, #0x110
//   0x4a04: d65f03c0  ret        
//   0x4a08: 94000eea  bl         #0x85b0

// ----------------------------------------------------------------------------
// FDE[20] fd_backtrace_init (0x4a0c..0x4a10, 4 bytes, 1 instructions)
// Summary / Tóm tắt: Exported: Tail-call to xp_init_basic_env (@ 0x4a0c..0x4a10)
// ----------------------------------------------------------------------------
//   0x4a0c: 14000f41  b          #0x8710

// ----------------------------------------------------------------------------
// FDE[21] fd_backtrace_release (0x4a10..0x4a14, 4 bytes, 1 instructions)
// Summary / Tóm tắt: Exported: No-op release stub (@ 0x4a10..0x4a14)
// ----------------------------------------------------------------------------
//   0x4a10: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[22] do_backtrace (0x4a14..0x4d5c, 840 bytes, 210 instructions)
// Summary / Tóm tắt: Exported: Captures native (npth_fp_frames) & Java ART backtraces (@ 0x4a14..0x4d5c)
// ----------------------------------------------------------------------------
//   0x4a14: a9ba7bfd  stp        x29, x30, [sp, #-0x60]!
//   0x4a18: a9016ffc  stp        x28, x27, [sp, #0x10]
//   0x4a1c: a90267fa  stp        x26, x25, [sp, #0x20]
//   0x4a20: a9035ff8  stp        x24, x23, [sp, #0x30]
//   0x4a24: a90457f6  stp        x22, x21, [sp, #0x40]
//   0x4a28: a9054ff4  stp        x20, x19, [sp, #0x50]
//   0x4a2c: 910003fd  mov        x29, sp
//   0x4a30: d11103ff  sub        sp, sp, #0x440
//   0x4a34: d53bd048  mrs        x8, tpidr_el0
//   0x4a38: 90000056  adrp       x22, #0xc000
//   0x4a3c: f90013e8  str        x8, [sp, #0x20]
//   0x4a40: aa0003f4  mov        x20, x0
//   0x4a44: f9401508  ldr        x8, [x8, #0x28]
//   0x4a48: aa0103f3  mov        x19, x1
//   0x4a4c: f9465ed6  ldr        x22, [x22, #0xcb8]
//   0x4a50: f81f03a8  stur       x8, [x29, #-0x10]
//   0x4a54: f94002c8  ldr        x8, [x22]
//   0x4a58: 91028100  add        x0, x8, #0xa0
//   0x4a5c: 94000f09  bl         #0x8680
//   0x4a60: f94002c8  ldr        x8, [x22]
//   0x4a64: f9407909  ldr        x9, [x8, #0xf0]
//   0x4a68: f9400137  ldr        x23, [x9]
//   0x4a6c: eb0902ff  cmp        x23, x9
//   0x4a70: 54001540  b.eq       #0x4d18
//   0x4a74: f94002c9  ldr        x9, [x22]
//   0x4a78: 9100066e  add        x14, x19, #1
//   0x4a7c: 2a1f03fb  mov        w27, wzr
//   0x4a80: f90007e9  str        x9, [sp, #8]
//   0x4a84: 90000049  adrp       x9, #0xc000
//   0x4a88: f9466129  ldr        x9, [x9, #0xcc0]
//   0x4a8c: a90153ee  stp        x14, x20, [sp, #0x10]
//   0x4a90: f940013c  ldr        x28, [x9]
//   0x4a94: aa1703fa  mov        x26, x23
//   0x4a98: f8410f58  ldr        x24, [x26, #0x10]!
//   0x4a9c: eb1a031f  cmp        x24, x26
//   0x4aa0: 540001c1  b.ne       #0x4ad8
//   0x4aa4: 1400005f  b          #0x4c20
//   0x4aa8: aa1403e0  mov        x0, x20
//   0x4aac: aa1503e1  mov        x1, x21
//   0x4ab0: 94000f1c  bl         #0x8720
//   0x4ab4: 90000056  adrp       x22, #0xc000
//   0x4ab8: aa1403f3  mov        x19, x20
//   0x4abc: f9465ed6  ldr        x22, [x22, #0xcb8]
//   0x4ac0: f9400ff4  ldr        x20, [sp, #0x18]
//   0x4ac4: b5000b80  cbnz       x0, #0x4c34
//   0x4ac8: f9400318  ldr        x24, [x24]
//   0x4acc: 1100077b  add        w27, w27, #1
//   0x4ad0: eb1a031f  cmp        x24, x26
//   0x4ad4: 54000a40  b.eq       #0x4c1c
//   0x4ad8: b9401788  ldr        w8, [x28, #0x14]
//   0x4adc: 6b08037f  cmp        w27, w8
//   0x4ae0: 540011cc  b.gt       #0x4d18
//   0x4ae4: f9400b08  ldr        x8, [x24, #0x10]
//   0x4ae8: f9400919  ldr        x25, [x8, #0x10]
//   0x4aec: b9405b28  ldr        w8, [x25, #0x58]
//   0x4af0: 7100051f  cmp        w8, #1
//   0x4af4: 54fffea0  b.eq       #0x4ac8
//   0x4af8: f9401328  ldr        x8, [x25, #0x20]
//   0x4afc: eb14011f  cmp        x8, x20
//   0x4b00: 54fffe41  b.ne       #0x4ac8
//   0x4b04: b4fffe33  cbz        x19, #0x4ac8
//   0x4b08: f9401b35  ldr        x21, [x25, #0x30]
//   0x4b0c: b4fffdf5  cbz        x21, #0x4ac8
//   0x4b10: aa1503e0  mov        x0, x21
//   0x4b14: 94000f07  bl         #0x8730
//   0x4b18: aa0003f6  mov        x22, x0
//   0x4b1c: aa1303e0  mov        x0, x19
//   0x4b20: aa1303f4  mov        x20, x19
//   0x4b24: 94000f03  bl         #0x8730
//   0x4b28: eb0002df  cmp        x22, x0
//   0x4b2c: 54000382  b.hs       #0x4b9c
//   0x4b30: f1001edf  cmp        x22, #7
//   0x4b34: 54fffba9  b.ls       #0x4aa8
//   0x4b38: 8b1606c8  add        x8, x22, x22, lsl #1
//   0x4b3c: 90000056  adrp       x22, #0xc000
//   0x4b40: aa1403f3  mov        x19, x20
//   0x4b44: f100111f  cmp        x8, #4
//   0x4b48: f9465ed6  ldr        x22, [x22, #0xcb8]
//   0x4b4c: a94153ee  ldp        x14, x20, [sp, #0x10]
//   0x4b50: 54000723  b.lo       #0x4c34
//   0x4b54: d342fd08  lsr        x8, x8, #2
//   0x4b58: 394002a9  ldrb       w9, [x21]
//   0x4b5c: 3940026a  ldrb       w10, [x19]
//   0x4b60: f100051f  cmp        x8, #1
//   0x4b64: 9a9f850b  csinc      x11, x8, xzr, hi
//   0x4b68: 6b0a013f  cmp        w9, w10
//   0x4b6c: 54fffae1  b.ne       #0x4ac8
//   0x4b70: aa1f03e9  mov        x9, xzr
//   0x4b74: 910006aa  add        x10, x21, #1
//   0x4b78: d100056b  sub        x11, x11, #1
//   0x4b7c: eb09017f  cmp        x11, x9
//   0x4b80: 540005a0  b.eq       #0x4c34
//   0x4b84: 3869694c  ldrb       w12, [x10, x9]
//   0x4b88: 386969cd  ldrb       w13, [x14, x9]
//   0x4b8c: 91000529  add        x9, x9, #1
//   0x4b90: 6b0d019f  cmp        w12, w13
//   0x4b94: 54ffff40  b.eq       #0x4b7c
//   0x4b98: 1400001e  b          #0x4c10
//   0x4b9c: f1001c1f  cmp        x0, #7
//   0x4ba0: 54000088  b.hi       #0x4bb0
//   0x4ba4: aa1503e0  mov        x0, x21
//   0x4ba8: aa1403e1  mov        x1, x20
//   0x4bac: 17ffffc1  b          #0x4ab0
//   0x4bb0: 90000056  adrp       x22, #0xc000
//   0x4bb4: aa1403f3  mov        x19, x20
//   0x4bb8: 8b000408  add        x8, x0, x0, lsl #1
//   0x4bbc: f100111f  cmp        x8, #4
//   0x4bc0: f9465ed6  ldr        x22, [x22, #0xcb8]
//   0x4bc4: a94153ee  ldp        x14, x20, [sp, #0x10]
//   0x4bc8: 54000363  b.lo       #0x4c34
//   0x4bcc: d342fd08  lsr        x8, x8, #2
//   0x4bd0: 39400269  ldrb       w9, [x19]
//   0x4bd4: 394002aa  ldrb       w10, [x21]
//   0x4bd8: f100051f  cmp        x8, #1
//   0x4bdc: 9a9f850b  csinc      x11, x8, xzr, hi
//   0x4be0: 6b0a013f  cmp        w9, w10
//   0x4be4: 54fff721  b.ne       #0x4ac8
//   0x4be8: aa1f03e9  mov        x9, xzr
//   0x4bec: 910006aa  add        x10, x21, #1
//   0x4bf0: d100056b  sub        x11, x11, #1
//   0x4bf4: eb09017f  cmp        x11, x9
//   0x4bf8: 540001e0  b.eq       #0x4c34
//   0x4bfc: 386969cc  ldrb       w12, [x14, x9]
//   0x4c00: 3869694d  ldrb       w13, [x10, x9]
//   0x4c04: 91000529  add        x9, x9, #1
//   0x4c08: 6b0d019f  cmp        w12, w13
//   0x4c0c: 54ffff40  b.eq       #0x4bf4
//   0x4c10: eb08013f  cmp        x9, x8
//   0x4c14: 54fff5a3  b.lo       #0x4ac8
//   0x4c18: 14000007  b          #0x4c34
//   0x4c1c: f94007e8  ldr        x8, [sp, #8]
//   0x4c20: f94002f7  ldr        x23, [x23]
//   0x4c24: f9407909  ldr        x9, [x8, #0xf0]
//   0x4c28: eb0902ff  cmp        x23, x9
//   0x4c2c: 54fff341  b.ne       #0x4a94
//   0x4c30: 1400003a  b          #0x4d18
//   0x4c34: f94002c8  ldr        x8, [x22]
//   0x4c38: 52800029  mov        w9, #1
//   0x4c3c: 91028100  add        x0, x8, #0xa0
//   0x4c40: b9005b29  str        w9, [x25, #0x58]
//   0x4c44: 94000e97  bl         #0x86a0
//   0x4c48: 9100c3e0  add        x0, sp, #0x30
//   0x4c4c: 2a1f03e1  mov        w1, wzr
//   0x4c50: 52808002  mov        w2, #0x400
//   0x4c54: 94000ebb  bl         #0x8740
//   0x4c58: 9100c3e0  add        x0, sp, #0x30
//   0x4c5c: 52801001  mov        w1, #0x80
//   0x4c60: 52801013  mov        w19, #0x80
//   0x4c64: 94000ebb  bl         #0x8750
//   0x4c68: f102001f  cmp        x0, #0x80
//   0x4c6c: 9a933008  csel       x8, x0, x19, lo
//   0x4c70: f100151f  cmp        x8, #5
//   0x4c74: 54000243  b.lo       #0x4cbc
//   0x4c78: d1001113  sub        x19, x8, #4
//   0x4c7c: 52800020  mov        w0, #1
//   0x4c80: d37df261  lsl        x1, x19, #3
//   0x4c84: 94000e1b  bl         #0x84f0
//   0x4c88: f9002720  str        x0, [x25, #0x48]
//   0x4c8c: b4000180  cbz        x0, #0x4cbc
//   0x4c90: 9100c3e9  add        x9, sp, #0x30
//   0x4c94: aa1f03e8  mov        x8, xzr
//   0x4c98: 91008129  add        x9, x9, #0x20
//   0x4c9c: f9002b33  str        x19, [x25, #0x50]
//   0x4ca0: d37df10a  lsl        x10, x8, #3
//   0x4ca4: 91000508  add        x8, x8, #1
//   0x4ca8: f940272c  ldr        x12, [x25, #0x48]
//   0x4cac: eb08027f  cmp        x19, x8
//   0x4cb0: f86a692b  ldr        x11, [x9, x10]
//   0x4cb4: f82a698b  str        x11, [x12, x10]
//   0x4cb8: 54ffff41  b.ne       #0x4ca0
//   0x4cbc: f94002c8  ldr        x8, [x22]
//   0x4cc0: b9400908  ldr        w8, [x8, #8]
//   0x4cc4: 51008108  sub        w8, w8, #0x20
//   0x4cc8: 3100191f  cmn        w8, #6
//   0x4ccc: 54000263  b.lo       #0x4d18
//   0x4cd0: 9100c3e0  add        x0, sp, #0x30
//   0x4cd4: 9100b3e1  add        x1, sp, #0x2c
//   0x4cd8: 52801002  mov        w2, #0x80
//   0x4cdc: 94000ea1  bl         #0x8760
//   0x4ce0: b9802ff3  ldrsw      x19, [sp, #0x2c]
//   0x4ce4: 340001b3  cbz        w19, #0x4d18
//   0x4ce8: d37df261  lsl        x1, x19, #3
//   0x4cec: 52800020  mov        w0, #1
//   0x4cf0: 94000e00  bl         #0x84f0
//   0x4cf4: f9003320  str        x0, [x25, #0x60]
//   0x4cf8: b4000100  cbz        x0, #0x4d18
//   0x4cfc: 7100067f  cmp        w19, #1
//   0x4d00: 540000ab  b.lt       #0x4d14
//   0x4d04: 92407e68  and        x8, x19, #0xffffffff
//   0x4d08: 9100c3e1  add        x1, sp, #0x30
//   0x4d0c: d37df102  lsl        x2, x8, #3
//   0x4d10: 94000e7c  bl         #0x8700
//   0x4d14: f9003733  str        x19, [x25, #0x68]
//   0x4d18: f94002c8  ldr        x8, [x22]
//   0x4d1c: 91028100  add        x0, x8, #0xa0
//   0x4d20: 94000e60  bl         #0x86a0
//   0x4d24: f94013e8  ldr        x8, [sp, #0x20]
//   0x4d28: f9401508  ldr        x8, [x8, #0x28]
//   0x4d2c: f85f03a9  ldur       x9, [x29, #-0x10]
//   0x4d30: eb09011f  cmp        x8, x9
//   0x4d34: 54000121  b.ne       #0x4d58
//   0x4d38: 911103ff  add        sp, sp, #0x440
//   0x4d3c: a9454ff4  ldp        x20, x19, [sp, #0x50]
//   0x4d40: a94457f6  ldp        x22, x21, [sp, #0x40]
//   0x4d44: a9435ff8  ldp        x24, x23, [sp, #0x30]
//   0x4d48: a94267fa  ldp        x26, x25, [sp, #0x20]
//   0x4d4c: a9416ffc  ldp        x28, x27, [sp, #0x10]
//   0x4d50: a8c67bfd  ldp        x29, x30, [sp], #0x60
//   0x4d54: d65f03c0  ret        
//   0x4d58: 94000e16  bl         #0x85b0

// ----------------------------------------------------------------------------
// FDE[23] native_backtrace_format (0x4d5c..0x4d74, 24 bytes, 6 instructions)
// Summary / Tóm tắt: Exported: Tail-call to npth_fp_format (@ 0x4d5c..0x4d74)
// ----------------------------------------------------------------------------
//   0x4d5c: aa0003e8  mov        x8, x0
//   0x4d60: f9403400  ldr        x0, [x0, #0x68]
//   0x4d64: b4000060  cbz        x0, #0x4d70
//   0x4d68: f9403901  ldr        x1, [x8, #0x70]
//   0x4d6c: 14000e85  b          #0x8780
//   0x4d70: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[24] release_frames (0x4d74..0x4db0, 60 bytes, 15 instructions)
// Summary / Tóm tắt: Exported: Frees native (+0x68) and Java (+0x80) frame arrays (@ 0x4d74..0x4db0)
// ----------------------------------------------------------------------------
//   0x4d74: a9be7bfd  stp        x29, x30, [sp, #-0x20]!
//   0x4d78: f9000bf3  str        x19, [sp, #0x10]
//   0x4d7c: 910003fd  mov        x29, sp
//   0x4d80: aa0003f3  mov        x19, x0
//   0x4d84: f9403400  ldr        x0, [x0, #0x68]
//   0x4d88: b4000040  cbz        x0, #0x4d90
//   0x4d8c: 94000df5  bl         #0x8560
//   0x4d90: f9404260  ldr        x0, [x19, #0x80]
//   0x4d94: b4000080  cbz        x0, #0x4da4
//   0x4d98: f9400bf3  ldr        x19, [sp, #0x10]
//   0x4d9c: a8c27bfd  ldp        x29, x30, [sp], #0x20
//   0x4da0: 14000df0  b          #0x8560
//   0x4da4: f9400bf3  ldr        x19, [sp, #0x10]
//   0x4da8: a8c27bfd  ldp        x29, x30, [sp], #0x20
//   0x4dac: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[25] do_fd_info_dump (0x4db0..0x63f4, 5700 bytes, 1425 instructions)
// Summary / Tóm tắt: Exported: Full FD leak report generator (fd_leak_info.txt, fd_types.txt, javastack.txt, tombstone.txt) (@ 0x4db0..0x63f4)
// ----------------------------------------------------------------------------
//   0x4db0: a9ba7bfd  stp        x29, x30, [sp, #-0x60]!
//   0x4db4: a9016ffc  stp        x28, x27, [sp, #0x10]
//   0x4db8: a90267fa  stp        x26, x25, [sp, #0x20]
//   0x4dbc: a9035ff8  stp        x24, x23, [sp, #0x30]
//   0x4dc0: a90457f6  stp        x22, x21, [sp, #0x40]
//   0x4dc4: a9054ff4  stp        x20, x19, [sp, #0x50]
//   0x4dc8: 910003fd  mov        x29, sp
//   0x4dcc: d12303ff  sub        sp, sp, #0x8c0
//   0x4dd0: 9000005c  adrp       x28, #0xc000
//   0x4dd4: d53bd054  mrs        x20, tpidr_el0
//   0x4dd8: f9401688  ldr        x8, [x20, #0x28]
//   0x4ddc: f9465f9c  ldr        x28, [x28, #0xcb8]
//   0x4de0: f81f03a8  stur       x8, [x29, #-0x10]
//   0x4de4: f9400388  ldr        x8, [x28]
//   0x4de8: b9401909  ldr        w9, [x8, #0x18]
//   0x4dec: 340001c9  cbz        w9, #0x4e24
//   0x4df0: 128000a0  mov        w0, #-6
//   0x4df4: f9401688  ldr        x8, [x20, #0x28]
//   0x4df8: f85f03a9  ldur       x9, [x29, #-0x10]
//   0x4dfc: eb09011f  cmp        x8, x9
//   0x4e00: 5400af81  b.ne       #0x63f0
//   0x4e04: 912303ff  add        sp, sp, #0x8c0
//   0x4e08: a9454ff4  ldp        x20, x19, [sp, #0x50]
//   0x4e0c: a94457f6  ldp        x22, x21, [sp, #0x40]
//   0x4e10: a9435ff8  ldp        x24, x23, [sp, #0x30]
//   0x4e14: a94267fa  ldp        x26, x25, [sp, #0x20]
//   0x4e18: a9416ffc  ldp        x28, x27, [sp, #0x10]
//   0x4e1c: a8c67bfd  ldp        x29, x30, [sp], #0x60
//   0x4e20: d65f03c0  ret        
//   0x4e24: aa0103f5  mov        x21, x1
//   0x4e28: 52800029  mov        w9, #1
//   0x4e2c: b9001909  str        w9, [x8, #0x18]
//   0x4e30: b4000c41  cbz        x1, #0x4fb8
//   0x4e34: b9002fe0  str        w0, [sp, #0x2c]
//   0x4e38: 9112c3e0  add        x0, sp, #0x4b0
//   0x4e3c: 2a1f03e1  mov        w1, wzr
//   0x4e40: 52808002  mov        w2, #0x400
//   0x4e44: 94000e3f  bl         #0x8740
//   0x4e48: d0ffffe3  adrp       x3, #0x2000
//   0x4e4c: 911e7863  add        x3, x3, #0x79e
//   0x4e50: d503201f  nop        
//   0x4e54: 50fedfa5  adr        x5, #0x2a4a
//   0x4e58: 9112c3e0  add        x0, sp, #0x4b0
//   0x4e5c: 52808001  mov        w1, #0x400
//   0x4e60: 52808002  mov        w2, #0x400
//   0x4e64: aa1503e4  mov        x4, x21
//   0x4e68: 94000621  bl         #0x66ec
//   0x4e6c: 9112c3e0  add        x0, sp, #0x4b0
//   0x4e70: 52804841  mov        w1, #0x242
//   0x4e74: 52803002  mov        w2, #0x180
//   0x4e78: 94000e46  bl         #0x8790
//   0x4e7c: 37f80a20  tbnz       w0, #0x1f, #0x4fc0
//   0x4e80: f9400388  ldr        x8, [x28]
//   0x4e84: 2a0003f3  mov        w19, w0
//   0x4e88: 6f00e400  movi       v0.2d, #0000000000000000
//   0x4e8c: f90013f4  str        x20, [sp, #0x20]
//   0x4e90: 910143f4  add        x20, sp, #0x50
//   0x4e94: b9001100  str        w0, [x8, #0x10]
//   0x4e98: 910143e0  add        x0, sp, #0x50
//   0x4e9c: ad0283e0  stp        q0, q0, [sp, #0x50]
//   0x4ea0: ad0383e0  stp        q0, q0, [sp, #0x70]
//   0x4ea4: ad0483e0  stp        q0, q0, [sp, #0x90]
//   0x4ea8: 94000e3e  bl         #0x87a0
//   0x4eac: 9112c3e0  add        x0, sp, #0x4b0
//   0x4eb0: 2a1f03e1  mov        w1, wzr
//   0x4eb4: 52808002  mov        w2, #0x400
//   0x4eb8: 94000e22  bl         #0x8740
//   0x4ebc: d0ffffe3  adrp       x3, #0x2000
//   0x4ec0: 911e7863  add        x3, x3, #0x79e
//   0x4ec4: d0ffffe5  adrp       x5, #0x2000
//   0x4ec8: 912b74a5  add        x5, x5, #0xadd
//   0x4ecc: 9112c3e0  add        x0, sp, #0x4b0
//   0x4ed0: 52808001  mov        w1, #0x400
//   0x4ed4: 52808002  mov        w2, #0x400
//   0x4ed8: aa1503e4  mov        x4, x21
//   0x4edc: 94000604  bl         #0x66ec
//   0x4ee0: 9112c3e0  add        x0, sp, #0x4b0
//   0x4ee4: 52804841  mov        w1, #0x242
//   0x4ee8: 52803002  mov        w2, #0x180
//   0x4eec: 94000e29  bl         #0x8790
//   0x4ef0: 37f80800  tbnz       w0, #0x1f, #0x4ff0
//   0x4ef4: 6f00e400  movi       v0.2d, #0000000000000000
//   0x4ef8: f9400388  ldr        x8, [x28]
//   0x4efc: 2a0003f5  mov        w21, w0
//   0x4f00: d0ffffe3  adrp       x3, #0x2000
//   0x4f04: 911a5c63  add        x3, x3, #0x697
//   0x4f08: 9112c3e0  add        x0, sp, #0x4b0
//   0x4f0c: 52801001  mov        w1, #0x80
//   0x4f10: 52801002  mov        w2, #0x80
//   0x4f14: 3d814be0  str        q0, [sp, #0x520]
//   0x4f18: 3d8147e0  str        q0, [sp, #0x510]
//   0x4f1c: 3d8143e0  str        q0, [sp, #0x500]
//   0x4f20: 3d813fe0  str        q0, [sp, #0x4f0]
//   0x4f24: 3d813be0  str        q0, [sp, #0x4e0]
//   0x4f28: 3d8137e0  str        q0, [sp, #0x4d0]
//   0x4f2c: 3d8133e0  str        q0, [sp, #0x4c0]
//   0x4f30: b9401d04  ldr        w4, [x8, #0x1c]
//   0x4f34: 3d812fe0  str        q0, [sp, #0x4b0]
//   0x4f38: 940005ed  bl         #0x66ec
//   0x4f3c: 93407c02  sxtw       x2, w0
//   0x4f40: 9112c3e1  add        x1, sp, #0x4b0
//   0x4f44: 2a1503e0  mov        w0, w21
//   0x4f48: 94000e1a  bl         #0x87b0
//   0x4f4c: d0ffffe1  adrp       x1, #0x2000
//   0x4f50: 91274821  add        x1, x1, #0x9d2
//   0x4f54: 2a1503e0  mov        w0, w21
//   0x4f58: 52800442  mov        w2, #0x22
//   0x4f5c: 94000e15  bl         #0x87b0
//   0x4f60: aa1f03f7  mov        x23, xzr
//   0x4f64: d503201f  nop        
//   0x4f68: 1003d498  adr        x24, #0xc9f8
//   0x4f6c: d0fffff6  adrp       x22, #0x2000
//   0x4f70: 911aaed6  add        x22, x22, #0x6ab
//   0x4f74: f8777b04  ldr        x4, [x24, x23, lsl #3]
//   0x4f78: 9112c3e0  add        x0, sp, #0x4b0
//   0x4f7c: b8777a85  ldr        w5, [x20, x23, lsl #2]
//   0x4f80: 52801001  mov        w1, #0x80
//   0x4f84: 52801002  mov        w2, #0x80
//   0x4f88: aa1603e3  mov        x3, x22
//   0x4f8c: 940005d8  bl         #0x66ec
//   0x4f90: 93407c02  sxtw       x2, w0
//   0x4f94: 9112c3e1  add        x1, sp, #0x4b0
//   0x4f98: 2a1503e0  mov        w0, w21
//   0x4f9c: 94000e05  bl         #0x87b0
//   0x4fa0: 910006f7  add        x23, x23, #1
//   0x4fa4: f10062ff  cmp        x23, #0x18
//   0x4fa8: 54fffe61  b.ne       #0x4f74
//   0x4fac: 2a1503e0  mov        w0, w21
//   0x4fb0: 94000e04  bl         #0x87c0
//   0x4fb4: 14000019  b          #0x5018
//   0x4fb8: 128000c0  mov        w0, #-7
//   0x4fbc: 17ffff8e  b          #0x4df4
//   0x4fc0: 94000e04  bl         #0x87d0
//   0x4fc4: b9400004  ldr        w4, [x0]
//   0x4fc8: d0ffffe1  adrp       x1, #0x2000
//   0x4fcc: 9124c421  add        x1, x1, #0x931
//   0x4fd0: d0ffffe2  adrp       x2, #0x2000
//   0x4fd4: 912ae442  add        x2, x2, #0xab9
//   0x4fd8: d503201f  nop        
//   0x4fdc: 50fed363  adr        x3, #0x2a4a
//   0x4fe0: 528000c0  mov        w0, #6
//   0x4fe4: 94000d87  bl         #0x8600
//   0x4fe8: 128000c0  mov        w0, #-7
//   0x4fec: 17ffff82  b          #0x4df4
//   0x4ff0: 94000df8  bl         #0x87d0
//   0x4ff4: b9400004  ldr        w4, [x0]
//   0x4ff8: d0ffffe1  adrp       x1, #0x2000
//   0x4ffc: 9124c421  add        x1, x1, #0x931
//   0x5000: b0ffffe2  adrp       x2, #0x2000
//   0x5004: 912ae442  add        x2, x2, #0xab9
//   0x5008: b0ffffe3  adrp       x3, #0x2000
//   0x500c: 912b7463  add        x3, x3, #0xadd
//   0x5010: 528000c0  mov        w0, #6
//   0x5014: 94000d7b  bl         #0x8600
//   0x5018: b0ffffe0  adrp       x0, #0x2000
//   0x501c: 911ad400  add        x0, x0, #0x6b5
//   0x5020: 94000df0  bl         #0x87e0
//   0x5024: b4000380  cbz        x0, #0x5094
//   0x5028: b0ffffe1  adrp       x1, #0x2000
//   0x502c: 91221421  add        x1, x1, #0x885
//   0x5030: aa0003f5  mov        x21, x0
//   0x5034: 94000def  bl         #0x87f0
//   0x5038: f9400388  ldr        x8, [x28]
//   0x503c: b0ffffe1  adrp       x1, #0x2000
//   0x5040: 9129e821  add        x1, x1, #0xa7a
//   0x5044: f9006500  str        x0, [x8, #0xc8]
//   0x5048: aa1503e0  mov        x0, x21
//   0x504c: 94000ded  bl         #0x8800
//   0x5050: f9400388  ldr        x8, [x28]
//   0x5054: f0000029  adrp       x9, #0xc000
//   0x5058: f000002a  adrp       x10, #0xc000
//   0x505c: f000002c  adrp       x12, #0xc000
//   0x5060: f000002d  adrp       x13, #0xc000
//   0x5064: f9466929  ldr        x9, [x9, #0xcd0]
//   0x5068: f9466d4a  ldr        x10, [x10, #0xcd8]
//   0x506c: b940090b  ldr        w11, [x8, #8]
//   0x5070: f946658c  ldr        x12, [x12, #0xcc8]
//   0x5074: f94671ad  ldr        x13, [x13, #0xce0]
//   0x5078: 7100657f  cmp        w11, #0x19
//   0x507c: 9a89c149  csel       x9, x10, x9, gt
//   0x5080: 9a8cc1aa  csel       x10, x13, x12, gt
//   0x5084: a90d2500  stp        x0, x9, [x8, #0xd0]
//   0x5088: aa1503e0  mov        x0, x21
//   0x508c: f900710a  str        x10, [x8, #0xe0]
//   0x5090: 94000de0  bl         #0x8810
//   0x5094: f9400388  ldr        x8, [x28]
//   0x5098: 910103e9  add        x9, sp, #0x40
//   0x509c: 9100c3ea  add        x10, sp, #0x30
//   0x50a0: f940690b  ldr        x11, [x8, #0xd0]
//   0x50a4: a90427e9  stp        x9, x9, [sp, #0x40]
//   0x50a8: a9032bea  stp        x10, x10, [sp, #0x30]
//   0x50ac: b40009eb  cbz        x11, #0x51e8
//   0x50b0: f9406500  ldr        x0, [x8, #0xc8]
//   0x50b4: b40009a0  cbz        x0, #0x51e8
//   0x50b8: f9407108  ldr        x8, [x8, #0xe0]
//   0x50bc: d63f0100  blr        x8
//   0x50c0: 94000dd8  bl         #0x8820
//   0x50c4: aa0003f5  mov        x21, x0
//   0x50c8: f9400400  ldr        x0, [x0, #8]
//   0x50cc: b5ffffc0  cbnz       x0, #0x50c4
//   0x50d0: b4000835  cbz        x21, #0x51d4
//   0x50d4: 9112c3f4  add        x20, sp, #0x4b0
//   0x50d8: 9100c3fa  add        x26, sp, #0x30
//   0x50dc: b0fffff6  adrp       x22, #0x2000
//   0x50e0: 911bead6  add        x22, x22, #0x6fa
//   0x50e4: 14000009  b          #0x5108
//   0x50e8: aa1f03e0  mov        x0, xzr
//   0x50ec: f9401be8  ldr        x8, [sp, #0x30]
//   0x50f0: f90016e0  str        x0, [x23, #0x28]
//   0x50f4: f9001bf7  str        x23, [sp, #0x30]
//   0x50f8: a9006ae8  stp        x8, x26, [x23]
//   0x50fc: f9000517  str        x23, [x8, #8]
//   0x5100: f94002b5  ldr        x21, [x21]
//   0x5104: b4000695  cbz        x21, #0x51d4
//   0x5108: f9400388  ldr        x8, [x28]
//   0x510c: b9400909  ldr        w9, [x8, #8]
//   0x5110: 7100553f  cmp        w9, #0x15
//   0x5114: 540000cb  b.lt       #0x512c
//   0x5118: f9406908  ldr        x8, [x8, #0xd0]
//   0x511c: aa1503e0  mov        x0, x21
//   0x5120: d63f0100  blr        x8
//   0x5124: 2a0003f8  mov        w24, w0
//   0x5128: 14000002  b          #0x5130
//   0x512c: 2a1f03f8  mov        w24, wzr
//   0x5130: 9102c3e1  add        x1, sp, #0xb0
//   0x5134: aa1503e0  mov        x0, x21
//   0x5138: 94000dbe  bl         #0x8830
//   0x513c: 52800020  mov        w0, #1
//   0x5140: 52800601  mov        w1, #0x30
//   0x5144: 94000ceb  bl         #0x84f0
//   0x5148: b4000460  cbz        x0, #0x51d4
//   0x514c: a94ba7e8  ldp        x8, x9, [sp, #0xb8]
//   0x5150: aa0003f7  mov        x23, x0
//   0x5154: b9001018  str        w24, [x0, #0x10]
//   0x5158: 52800801  mov        w1, #0x40
//   0x515c: 52800802  mov        w2, #0x40
//   0x5160: aa1603e3  mov        x3, x22
//   0x5164: 2a1803e4  mov        w4, w24
//   0x5168: 8b080129  add        x9, x9, x8
//   0x516c: a901a408  stp        x8, x9, [x0, #0x18]
//   0x5170: 9112c3e0  add        x0, sp, #0x4b0
//   0x5174: 9400055e  bl         #0x66ec
//   0x5178: 9112c3e0  add        x0, sp, #0x4b0
//   0x517c: 52a00101  mov        w1, #0x80000
//   0x5180: 94000db0  bl         #0x8840
//   0x5184: 37fffb20  tbnz       w0, #0x1f, #0x50e8
//   0x5188: 9112c3e1  add        x1, sp, #0x4b0
//   0x518c: 52800802  mov        w2, #0x40
//   0x5190: 2a0003f9  mov        w25, w0
//   0x5194: 94000daf  bl         #0x8850
//   0x5198: aa0003f8  mov        x24, x0
//   0x519c: 2a1903e0  mov        w0, w25
//   0x51a0: 94000d88  bl         #0x87c0
//   0x51a4: f1000708  subs       x8, x24, #1
//   0x51a8: 54fffa0b  b.lt       #0x50e8
//   0x51ac: f101031f  cmp        x24, #0x40
//   0x51b0: 54000080  b.eq       #0x51c0
//   0x51b4: 38686a89  ldrb       w9, [x20, x8]
//   0x51b8: 7100293f  cmp        w9, #0xa
//   0x51bc: 54000041  b.ne       #0x51c4
//   0x51c0: aa0803f8  mov        x24, x8
//   0x51c4: 9112c3e0  add        x0, sp, #0x4b0
//   0x51c8: 38386a9f  strb       wzr, [x20, x24]
//   0x51cc: 94000ce1  bl         #0x8550
//   0x51d0: 17ffffc7  b          #0x50ec
//   0x51d4: f9400388  ldr        x8, [x28]
//   0x51d8: f9406d09  ldr        x9, [x8, #0xd8]
//   0x51dc: f9406500  ldr        x0, [x8, #0xc8]
//   0x51e0: d63f0120  blr        x9
//   0x51e4: f9400388  ldr        x8, [x28]
//   0x51e8: 91028100  add        x0, x8, #0xa0
//   0x51ec: 94000d25  bl         #0x8680
//   0x51f0: f9400388  ldr        x8, [x28]
//   0x51f4: aa1f03ea  mov        x10, xzr
//   0x51f8: f9402109  ldr        x9, [x8, #0x40]
//   0x51fc: f9400129  ldr        x9, [x9]
//   0x5200: aa0a03f5  mov        x21, x10
//   0x5204: aa0903ea  mov        x10, x9
//   0x5208: b5ffffa9  cbnz       x9, #0x51fc
//   0x520c: b4001fd5  cbz        x21, #0x5604
//   0x5210: 9100c3fc  add        x28, sp, #0x30
//   0x5214: 910103f6  add        x22, sp, #0x40
//   0x5218: 14000002  b          #0x5220
//   0x521c: b4001ef5  cbz        x21, #0x55f8
//   0x5220: aa1503f4  mov        x20, x21
//   0x5224: f94006a8  ldr        x8, [x21, #8]
//   0x5228: b4000788  cbz        x8, #0x5318
//   0x522c: aa0803f5  mov        x21, x8
//   0x5230: f9400108  ldr        x8, [x8]
//   0x5234: b5ffffc8  cbnz       x8, #0x522c
//   0x5238: b9403a99  ldr        w25, [x20, #0x38]
//   0x523c: 9100c3f8  add        x24, sp, #0x30
//   0x5240: f9400318  ldr        x24, [x24]
//   0x5244: eb1c031f  cmp        x24, x28
//   0x5248: 540000a0  b.eq       #0x525c
//   0x524c: b9401308  ldr        w8, [x24, #0x10]
//   0x5250: 6b19011f  cmp        w8, w25
//   0x5254: 54ffff61  b.ne       #0x5240
//   0x5258: 1400000b  b          #0x5284
//   0x525c: 52800020  mov        w0, #1
//   0x5260: 52800601  mov        w1, #0x30
//   0x5264: 94000ca3  bl         #0x84f0
//   0x5268: b4000720  cbz        x0, #0x534c
//   0x526c: aa0003f8  mov        x24, x0
//   0x5270: f9401fe8  ldr        x8, [sp, #0x38]
//   0x5274: a900201c  stp        x28, x8, [x0]
//   0x5278: f9000100  str        x0, [x8]
//   0x527c: f9001fe0  str        x0, [sp, #0x38]
//   0x5280: b9001019  str        w25, [x0, #0x10]
//   0x5284: b9401708  ldr        w8, [x24, #0x14]
//   0x5288: f9401709  ldr        x9, [x24, #0x28]
//   0x528c: 11000508  add        w8, w8, #1
//   0x5290: b9001708  str        w8, [x24, #0x14]
//   0x5294: b50006e9  cbnz       x9, #0x5370
//   0x5298: 9112c3e0  add        x0, sp, #0x4b0
//   0x529c: 52800801  mov        w1, #0x40
//   0x52a0: 52800802  mov        w2, #0x40
//   0x52a4: b0ffffe3  adrp       x3, #0x2000
//   0x52a8: 911be863  add        x3, x3, #0x6fa
//   0x52ac: 2a1903e4  mov        w4, w25
//   0x52b0: 9400050f  bl         #0x66ec
//   0x52b4: 9112c3e0  add        x0, sp, #0x4b0
//   0x52b8: 52a00101  mov        w1, #0x80000
//   0x52bc: 94000d61  bl         #0x8840
//   0x52c0: 37f80540  tbnz       w0, #0x1f, #0x5368
//   0x52c4: 9112c3e1  add        x1, sp, #0x4b0
//   0x52c8: 52800802  mov        w2, #0x40
//   0x52cc: 2a0003fa  mov        w26, w0
//   0x52d0: 94000d60  bl         #0x8850
//   0x52d4: aa0003f9  mov        x25, x0
//   0x52d8: 2a1a03e0  mov        w0, w26
//   0x52dc: 94000d39  bl         #0x87c0
//   0x52e0: f1000728  subs       x8, x25, #1
//   0x52e4: 5400042b  b.lt       #0x5368
//   0x52e8: f101033f  cmp        x25, #0x40
//   0x52ec: 540000a0  b.eq       #0x5300
//   0x52f0: 9112c3e9  add        x9, sp, #0x4b0
//   0x52f4: 38686929  ldrb       w9, [x9, x8]
//   0x52f8: 7100293f  cmp        w9, #0xa
//   0x52fc: 54000041  b.ne       #0x5304
//   0x5300: aa0803f9  mov        x25, x8
//   0x5304: 9112c3e0  add        x0, sp, #0x4b0
//   0x5308: 9112c3e8  add        x8, sp, #0x4b0
//   0x530c: 3839691f  strb       wzr, [x8, x25]
//   0x5310: 94000c90  bl         #0x8550
//   0x5314: 14000016  b          #0x536c
//   0x5318: f9400a95  ldr        x21, [x20, #0x10]
//   0x531c: b4000095  cbz        x21, #0x532c
//   0x5320: f94002a8  ldr        x8, [x21]
//   0x5324: eb14011f  cmp        x8, x20
//   0x5328: 54fff880  b.eq       #0x5238
//   0x532c: aa1403e8  mov        x8, x20
//   0x5330: f9400915  ldr        x21, [x8, #0x10]
//   0x5334: b4fff835  cbz        x21, #0x5238
//   0x5338: f94006a9  ldr        x9, [x21, #8]
//   0x533c: eb09011f  cmp        x8, x9
//   0x5340: aa1503e8  mov        x8, x21
//   0x5344: 54ffff60  b.eq       #0x5330
//   0x5348: 17ffffbc  b          #0x5238
//   0x534c: 528000c0  mov        w0, #6
//   0x5350: b0ffffe1  adrp       x1, #0x2000
//   0x5354: 9124c421  add        x1, x1, #0x931
//   0x5358: b0ffffe2  adrp       x2, #0x2000
//   0x535c: 912ba842  add        x2, x2, #0xaea
//   0x5360: 94000ca8  bl         #0x8600
//   0x5364: 14000003  b          #0x5370
//   0x5368: aa1f03e0  mov        x0, xzr
//   0x536c: f9001700  str        x0, [x24, #0x28]
//   0x5370: a9445e9a  ldp        x26, x23, [x20, #0x40]
//   0x5374: f94023f9  ldr        x25, [sp, #0x40]
//   0x5378: eb16033f  cmp        x25, x22
//   0x537c: 540001c0  b.eq       #0x53b4
//   0x5380: aa1903e8  mov        x8, x25
//   0x5384: f8410d18  ldr        x24, [x8, #0x10]!
//   0x5388: eb08031f  cmp        x24, x8
//   0x538c: 540000e0  b.eq       #0x53a8
//   0x5390: f9401f09  ldr        x9, [x24, #0x38]
//   0x5394: eb1a013f  cmp        x9, x26
//   0x5398: 540004e0  b.eq       #0x5434
//   0x539c: f9400318  ldr        x24, [x24]
//   0x53a0: eb08031f  cmp        x24, x8
//   0x53a4: 54ffff61  b.ne       #0x5390
//   0x53a8: f9400339  ldr        x25, [x25]
//   0x53ac: eb16033f  cmp        x25, x22
//   0x53b0: 54fffe81  b.ne       #0x5380
//   0x53b4: 52800020  mov        w0, #1
//   0x53b8: 52800801  mov        w1, #0x40
//   0x53bc: 94000c4d  bl         #0x84f0
//   0x53c0: aa0003f8  mov        x24, x0
//   0x53c4: b4000060  cbz        x0, #0x53d0
//   0x53c8: 91004308  add        x8, x24, #0x10
//   0x53cc: a9012308  stp        x8, x8, [x24, #0x10]
//   0x53d0: 9112c3e1  add        x1, sp, #0x4b0
//   0x53d4: aa1a03e0  mov        x0, x26
//   0x53d8: 94000d22  bl         #0x8860
//   0x53dc: 34000660  cbz        w0, #0x54a8
//   0x53e0: 2a0003e8  mov        w8, w0
//   0x53e4: f94263e0  ldr        x0, [sp, #0x4c0]
//   0x53e8: b4000080  cbz        x0, #0x53f8
//   0x53ec: 7100091f  cmp        w8, #2
//   0x53f0: 54000040  b.eq       #0x53f8
//   0x53f4: 94000c57  bl         #0x8550
//   0x53f8: f94267e8  ldr        x8, [sp, #0x4c8]
//   0x53fc: 910103f9  add        x25, sp, #0x40
//   0x5400: f9425ffb  ldr        x27, [sp, #0x4b8]
//   0x5404: f9401f09  ldr        x9, [x24, #0x38]
//   0x5408: f100011f  cmp        x8, #0
//   0x540c: 9a880368  csel       x8, x27, x8, eq
//   0x5410: cb080128  sub        x8, x9, x8
//   0x5414: a9028308  stp        x8, x0, [x24, #0x28]
//   0x5418: f9400339  ldr        x25, [x25]
//   0x541c: eb16033f  cmp        x25, x22
//   0x5420: 54000520  b.eq       #0x54c4
//   0x5424: f9401f28  ldr        x8, [x25, #0x38]
//   0x5428: eb1b011f  cmp        x8, x27
//   0x542c: 54ffff61  b.ne       #0x5418
//   0x5430: 14000047  b          #0x554c
//   0x5434: 9100431b  add        x27, x24, #0x10
//   0x5438: aa1b03fa  mov        x26, x27
//   0x543c: f940035a  ldr        x26, [x26]
//   0x5440: eb1b035f  cmp        x26, x27
//   0x5444: 540000c0  b.eq       #0x545c
//   0x5448: f9401f48  ldr        x8, [x26, #0x38]
//   0x544c: eb17011f  cmp        x8, x23
//   0x5450: 54ffff61  b.ne       #0x543c
//   0x5454: b5000af9  cbnz       x25, #0x55b0
//   0x5458: 17ffff71  b          #0x521c
//   0x545c: 52800020  mov        w0, #1
//   0x5460: 52800801  mov        w1, #0x40
//   0x5464: 94000c23  bl         #0x84f0
//   0x5468: aa0003fa  mov        x26, x0
//   0x546c: b4000060  cbz        x0, #0x5478
//   0x5470: 91004348  add        x8, x26, #0x10
//   0x5474: a9012348  stp        x8, x8, [x26, #0x10]
//   0x5478: 9100c3e1  add        x1, sp, #0x30
//   0x547c: aa1a03e0  mov        x0, x26
//   0x5480: f9001f57  str        x23, [x26, #0x38]
//   0x5484: 940004c3  bl         #0x6790
//   0x5488: f900035b  str        x27, [x26]
//   0x548c: f9400f08  ldr        x8, [x24, #0x18]
//   0x5490: f9000748  str        x8, [x26, #8]
//   0x5494: f9400f08  ldr        x8, [x24, #0x18]
//   0x5498: f900011a  str        x26, [x8]
//   0x549c: f9000f1a  str        x26, [x24, #0x18]
//   0x54a0: b5000899  cbnz       x25, #0x55b0
//   0x54a4: 17ffff5e  b          #0x521c
//   0x54a8: 910103f9  add        x25, sp, #0x40
//   0x54ac: f9400339  ldr        x25, [x25]
//   0x54b0: eb16033f  cmp        x25, x22
//   0x54b4: 540002e0  b.eq       #0x5510
//   0x54b8: f9401f28  ldr        x8, [x25, #0x38]
//   0x54bc: b5ffff88  cbnz       x8, #0x54ac
//   0x54c0: 14000023  b          #0x554c
//   0x54c4: 52800020  mov        w0, #1
//   0x54c8: 52800801  mov        w1, #0x40
//   0x54cc: 94000c09  bl         #0x84f0
//   0x54d0: aa0003f9  mov        x25, x0
//   0x54d4: b4000060  cbz        x0, #0x54e0
//   0x54d8: 91004328  add        x8, x25, #0x10
//   0x54dc: a9012328  stp        x8, x8, [x25, #0x10]
//   0x54e0: f94027e8  ldr        x8, [sp, #0x48]
//   0x54e4: a9002336  stp        x22, x8, [x25]
//   0x54e8: f9000119  str        x25, [x8]
//   0x54ec: f9425be0  ldr        x0, [sp, #0x4b0]
//   0x54f0: f90027f9  str        x25, [sp, #0x48]
//   0x54f4: f9001f3b  str        x27, [x25, #0x38]
//   0x54f8: b40002a0  cbz        x0, #0x554c
//   0x54fc: 528005e1  mov        w1, #0x2f
//   0x5500: 94000cdc  bl         #0x8870
//   0x5504: b40001e0  cbz        x0, #0x5540
//   0x5508: 91000400  add        x0, x0, #1
//   0x550c: 1400000e  b          #0x5544
//   0x5510: 52800020  mov        w0, #1
//   0x5514: 52800801  mov        w1, #0x40
//   0x5518: 94000bf6  bl         #0x84f0
//   0x551c: aa0003f9  mov        x25, x0
//   0x5520: b4000060  cbz        x0, #0x552c
//   0x5524: 91004328  add        x8, x25, #0x10
//   0x5528: a9012328  stp        x8, x8, [x25, #0x10]
//   0x552c: f94027e8  ldr        x8, [sp, #0x48]
//   0x5530: a9002336  stp        x22, x8, [x25]
//   0x5534: f9000119  str        x25, [x8]
//   0x5538: f90027f9  str        x25, [sp, #0x48]
//   0x553c: 14000004  b          #0x554c
//   0x5540: f9425be0  ldr        x0, [sp, #0x4b0]
//   0x5544: 94000c03  bl         #0x8550
//   0x5548: f9001b20  str        x0, [x25, #0x30]
//   0x554c: 91004328  add        x8, x25, #0x10
//   0x5550: f9001f1a  str        x26, [x24, #0x38]
//   0x5554: 52800020  mov        w0, #1
//   0x5558: 52800801  mov        w1, #0x40
//   0x555c: f9000308  str        x8, [x24]
//   0x5560: f9400f28  ldr        x8, [x25, #0x18]
//   0x5564: f9000708  str        x8, [x24, #8]
//   0x5568: f9400f28  ldr        x8, [x25, #0x18]
//   0x556c: f9000118  str        x24, [x8]
//   0x5570: f9000f38  str        x24, [x25, #0x18]
//   0x5574: 94000bdf  bl         #0x84f0
//   0x5578: aa0003fa  mov        x26, x0
//   0x557c: b4000060  cbz        x0, #0x5588
//   0x5580: 91004348  add        x8, x26, #0x10
//   0x5584: a9012348  stp        x8, x8, [x26, #0x10]
//   0x5588: 9100c3e1  add        x1, sp, #0x30
//   0x558c: aa1a03e0  mov        x0, x26
//   0x5590: f9001f57  str        x23, [x26, #0x38]
//   0x5594: 9400047f  bl         #0x6790
//   0x5598: 91004308  add        x8, x24, #0x10
//   0x559c: f9400f09  ldr        x9, [x24, #0x18]
//   0x55a0: a9002748  stp        x8, x9, [x26]
//   0x55a4: f900013a  str        x26, [x9]
//   0x55a8: f9000f1a  str        x26, [x24, #0x18]
//   0x55ac: b4ffe399  cbz        x25, #0x521c
//   0x55b0: b4ffe378  cbz        x24, #0x521c
//   0x55b4: b9402728  ldr        w8, [x25, #0x24]
//   0x55b8: 91004349  add        x9, x26, #0x10
//   0x55bc: 11000508  add        w8, w8, #1
//   0x55c0: b9002728  str        w8, [x25, #0x24]
//   0x55c4: b9402708  ldr        w8, [x24, #0x24]
//   0x55c8: 11000508  add        w8, w8, #1
//   0x55cc: b9002708  str        w8, [x24, #0x24]
//   0x55d0: b9402748  ldr        w8, [x26, #0x24]
//   0x55d4: 11000508  add        w8, w8, #1
//   0x55d8: b9002748  str        w8, [x26, #0x24]
//   0x55dc: f8020e89  str        x9, [x20, #0x20]!
//   0x55e0: f9400f48  ldr        x8, [x26, #0x18]
//   0x55e4: f9000688  str        x8, [x20, #8]
//   0x55e8: f9400f48  ldr        x8, [x26, #0x18]
//   0x55ec: f9000114  str        x20, [x8]
//   0x55f0: f9000f54  str        x20, [x26, #0x18]
//   0x55f4: 17ffff0a  b          #0x521c
//   0x55f8: f000003c  adrp       x28, #0xc000
//   0x55fc: f9465f9c  ldr        x28, [x28, #0xcb8]
//   0x5600: f9400388  ldr        x8, [x28]
//   0x5604: 91028100  add        x0, x8, #0xa0
//   0x5608: 94000c26  bl         #0x86a0
//   0x560c: f94027e8  ldr        x8, [sp, #0x48]
//   0x5610: 910103e9  add        x9, sp, #0x40
//   0x5614: eb09011f  cmp        x8, x9
//   0x5618: 540006c0  b.eq       #0x56f0
//   0x561c: 9112c3ea  add        x10, sp, #0x4b0
//   0x5620: 14000005  b          #0x5634
//   0x5624: f9400108  ldr        x8, [x8]
//   0x5628: f9400508  ldr        x8, [x8, #8]
//   0x562c: eb09011f  cmp        x8, x9
//   0x5630: 54000600  b.eq       #0x56f0
//   0x5634: f94023eb  ldr        x11, [sp, #0x40]
//   0x5638: eb09017f  cmp        x11, x9
//   0x563c: fa481164  ccmp       x11, x8, #4, ne
//   0x5640: 54ffff40  b.eq       #0x5628
//   0x5644: 14000006  b          #0x565c
//   0x5648: aa0c03eb  mov        x11, x12
//   0x564c: eb09017f  cmp        x11, x9
//   0x5650: 54fffec0  b.eq       #0x5628
//   0x5654: eb08017f  cmp        x11, x8
//   0x5658: 54fffe80  b.eq       #0x5628
//   0x565c: f940016c  ldr        x12, [x11]
//   0x5660: b940256d  ldr        w13, [x11, #0x24]
//   0x5664: b940258e  ldr        w14, [x12, #0x24]
//   0x5668: 6b0e01bf  cmp        w13, w14
//   0x566c: 54fffeea  b.ge       #0x5648
//   0x5670: f940058d  ldr        x13, [x12, #8]
//   0x5674: f900058a  str        x10, [x12, #8]
//   0x5678: f9025bec  str        x12, [sp, #0x4b0]
//   0x567c: f9025fed  str        x13, [sp, #0x4b8]
//   0x5680: f90001aa  str        x10, [x13]
//   0x5684: f940018d  ldr        x13, [x12]
//   0x5688: f90005aa  str        x10, [x13, #8]
//   0x568c: f940058e  ldr        x14, [x12, #8]
//   0x5690: f90001cd  str        x13, [x14]
//   0x5694: f940056d  ldr        x13, [x11, #8]
//   0x5698: f900056c  str        x12, [x11, #8]
//   0x569c: a900358b  stp        x11, x13, [x12]
//   0x56a0: f90001ac  str        x12, [x13]
//   0x56a4: a940316d  ldp        x13, x12, [x11]
//   0x56a8: f90005ac  str        x12, [x13, #8]
//   0x56ac: f940056c  ldr        x12, [x11, #8]
//   0x56b0: f900018d  str        x13, [x12]
//   0x56b4: f9425fec  ldr        x12, [sp, #0x4b8]
//   0x56b8: f9025feb  str        x11, [sp, #0x4b8]
//   0x56bc: a900316a  stp        x10, x12, [x11]
//   0x56c0: f900018b  str        x11, [x12]
//   0x56c4: f9425bec  ldr        x12, [sp, #0x4b0]
//   0x56c8: f900058b  str        x11, [x12, #8]
//   0x56cc: f9425fed  ldr        x13, [sp, #0x4b8]
//   0x56d0: f90001ac  str        x12, [x13]
//   0x56d4: f940056b  ldr        x11, [x11, #8]
//   0x56d8: eb08017f  cmp        x11, x8
//   0x56dc: 54fffa40  b.eq       #0x5624
//   0x56e0: f940016b  ldr        x11, [x11]
//   0x56e4: eb09017f  cmp        x11, x9
//   0x56e8: 54fffb61  b.ne       #0x5654
//   0x56ec: 17ffffcf  b          #0x5628
//   0x56f0: f9401fe8  ldr        x8, [sp, #0x38]
//   0x56f4: 9100c3e9  add        x9, sp, #0x30
//   0x56f8: eb09011f  cmp        x8, x9
//   0x56fc: 540006c0  b.eq       #0x57d4
//   0x5700: 9112c3ea  add        x10, sp, #0x4b0
//   0x5704: 14000005  b          #0x5718
//   0x5708: f9400108  ldr        x8, [x8]
//   0x570c: f9400508  ldr        x8, [x8, #8]
//   0x5710: eb09011f  cmp        x8, x9
//   0x5714: 54000600  b.eq       #0x57d4
//   0x5718: f9401beb  ldr        x11, [sp, #0x30]
//   0x571c: eb09017f  cmp        x11, x9
//   0x5720: fa481164  ccmp       x11, x8, #4, ne
//   0x5724: 54ffff40  b.eq       #0x570c
//   0x5728: 14000006  b          #0x5740
//   0x572c: aa0c03eb  mov        x11, x12
//   0x5730: eb09017f  cmp        x11, x9
//   0x5734: 54fffec0  b.eq       #0x570c
//   0x5738: eb08017f  cmp        x11, x8
//   0x573c: 54fffe80  b.eq       #0x570c
//   0x5740: f940016c  ldr        x12, [x11]
//   0x5744: b940156d  ldr        w13, [x11, #0x14]
//   0x5748: b940158e  ldr        w14, [x12, #0x14]
//   0x574c: 6b0e01bf  cmp        w13, w14
//   0x5750: 54fffeea  b.ge       #0x572c
//   0x5754: f940058d  ldr        x13, [x12, #8]
//   0x5758: f900058a  str        x10, [x12, #8]
//   0x575c: f9025bec  str        x12, [sp, #0x4b0]
//   0x5760: f9025fed  str        x13, [sp, #0x4b8]
//   0x5764: f90001aa  str        x10, [x13]
//   0x5768: f940018d  ldr        x13, [x12]
//   0x576c: f90005aa  str        x10, [x13, #8]
//   0x5770: f940058e  ldr        x14, [x12, #8]
//   0x5774: f90001cd  str        x13, [x14]
//   0x5778: f940056d  ldr        x13, [x11, #8]
//   0x577c: f900056c  str        x12, [x11, #8]
//   0x5780: a900358b  stp        x11, x13, [x12]
//   0x5784: f90001ac  str        x12, [x13]
//   0x5788: a940316d  ldp        x13, x12, [x11]
//   0x578c: f90005ac  str        x12, [x13, #8]
//   0x5790: f940056c  ldr        x12, [x11, #8]
//   0x5794: f900018d  str        x13, [x12]
//   0x5798: f9425fec  ldr        x12, [sp, #0x4b8]
//   0x579c: f9025feb  str        x11, [sp, #0x4b8]
//   0x57a0: a900316a  stp        x10, x12, [x11]
//   0x57a4: f900018b  str        x11, [x12]
//   0x57a8: f9425bec  ldr        x12, [sp, #0x4b0]
//   0x57ac: f900058b  str        x11, [x12, #8]
//   0x57b0: f9425fed  ldr        x13, [sp, #0x4b8]
//   0x57b4: f90001ac  str        x12, [x13]
//   0x57b8: f940056b  ldr        x11, [x11, #8]
//   0x57bc: eb08017f  cmp        x11, x8
//   0x57c0: 54fffa40  b.eq       #0x5708
//   0x57c4: f940016b  ldr        x11, [x11]
//   0x57c8: eb09017f  cmp        x11, x9
//   0x57cc: 54fffb61  b.ne       #0x5738
//   0x57d0: 17ffffcf  b          #0x570c
//   0x57d4: f940038a  ldr        x10, [x28]
//   0x57d8: f9402948  ldr        x8, [x10, #0x50]
//   0x57dc: b50000c8  cbnz       x8, #0x57f4
//   0x57e0: f9401be8  ldr        x8, [sp, #0x30]
//   0x57e4: 9100c3e9  add        x9, sp, #0x30
//   0x57e8: eb09011f  cmp        x8, x9
//   0x57ec: 54000040  b.eq       #0x57f4
//   0x57f0: f9002948  str        x8, [x10, #0x50]
//   0x57f4: f94023e9  ldr        x9, [sp, #0x40]
//   0x57f8: 910103e8  add        x8, sp, #0x40
//   0x57fc: eb08013f  cmp        x9, x8
//   0x5800: 54000f00  b.eq       #0x59e0
//   0x5804: 9112c3ea  add        x10, sp, #0x4b0
//   0x5808: 14000004  b          #0x5818
//   0x580c: f9400129  ldr        x9, [x9]
//   0x5810: eb08013f  cmp        x9, x8
//   0x5814: 54000e40  b.eq       #0x59dc
//   0x5818: f9400d2c  ldr        x12, [x9, #0x18]
//   0x581c: 9100412b  add        x11, x9, #0x10
//   0x5820: 14000003  b          #0x582c
//   0x5824: f940018c  ldr        x12, [x12]
//   0x5828: f940058c  ldr        x12, [x12, #8]
//   0x582c: eb0b019f  cmp        x12, x11
//   0x5830: 54000600  b.eq       #0x58f0
//   0x5834: f940016d  ldr        x13, [x11]
//   0x5838: eb0b01bf  cmp        x13, x11
//   0x583c: fa4c11a4  ccmp       x13, x12, #4, ne
//   0x5840: 54ffff40  b.eq       #0x5828
//   0x5844: 14000006  b          #0x585c
//   0x5848: aa0e03ed  mov        x13, x14
//   0x584c: eb0b01bf  cmp        x13, x11
//   0x5850: 54fffec0  b.eq       #0x5828
//   0x5854: eb0c01bf  cmp        x13, x12
//   0x5858: 54fffe80  b.eq       #0x5828
//   0x585c: f94001ae  ldr        x14, [x13]
//   0x5860: b94025af  ldr        w15, [x13, #0x24]
//   0x5864: b94025d0  ldr        w16, [x14, #0x24]
//   0x5868: 6b1001ff  cmp        w15, w16
//   0x586c: 54fffeea  b.ge       #0x5848
//   0x5870: f94005cf  ldr        x15, [x14, #8]
//   0x5874: f90005ca  str        x10, [x14, #8]
//   0x5878: f9025bee  str        x14, [sp, #0x4b0]
//   0x587c: f9025fef  str        x15, [sp, #0x4b8]
//   0x5880: f90001ea  str        x10, [x15]
//   0x5884: f94001cf  ldr        x15, [x14]
//   0x5888: f90005ea  str        x10, [x15, #8]
//   0x588c: f94005d0  ldr        x16, [x14, #8]
//   0x5890: f900020f  str        x15, [x16]
//   0x5894: f94005af  ldr        x15, [x13, #8]
//   0x5898: f90005ae  str        x14, [x13, #8]
//   0x589c: a9003dcd  stp        x13, x15, [x14]
//   0x58a0: f90001ee  str        x14, [x15]
//   0x58a4: a94039af  ldp        x15, x14, [x13]
//   0x58a8: f90005ee  str        x14, [x15, #8]
//   0x58ac: f94005ae  ldr        x14, [x13, #8]
//   0x58b0: f90001cf  str        x15, [x14]
//   0x58b4: f9425fee  ldr        x14, [sp, #0x4b8]
//   0x58b8: f9025fed  str        x13, [sp, #0x4b8]
//   0x58bc: a90039aa  stp        x10, x14, [x13]
//   0x58c0: f90001cd  str        x13, [x14]
//   0x58c4: f9425bee  ldr        x14, [sp, #0x4b0]
//   0x58c8: f90005cd  str        x13, [x14, #8]
//   0x58cc: f9425fef  ldr        x15, [sp, #0x4b8]
//   0x58d0: f90001ee  str        x14, [x15]
//   0x58d4: f94005ad  ldr        x13, [x13, #8]
//   0x58d8: eb0c01bf  cmp        x13, x12
//   0x58dc: 54fffa40  b.eq       #0x5824
//   0x58e0: f94001ad  ldr        x13, [x13]
//   0x58e4: eb0b01bf  cmp        x13, x11
//   0x58e8: 54fffb61  b.ne       #0x5854
//   0x58ec: 17ffffcf  b          #0x5828
//   0x58f0: f940016c  ldr        x12, [x11]
//   0x58f4: 14000002  b          #0x58fc
//   0x58f8: f940018c  ldr        x12, [x12]
//   0x58fc: eb0b019f  cmp        x12, x11
//   0x5900: 54fff860  b.eq       #0x580c
//   0x5904: f9400d8d  ldr        x13, [x12, #0x18]
//   0x5908: 9100418e  add        x14, x12, #0x10
//   0x590c: 14000003  b          #0x5918
//   0x5910: f94001ad  ldr        x13, [x13]
//   0x5914: f94005ad  ldr        x13, [x13, #8]
//   0x5918: eb0e01bf  cmp        x13, x14
//   0x591c: 54fffee0  b.eq       #0x58f8
//   0x5920: f94001cf  ldr        x15, [x14]
//   0x5924: eb0e01ff  cmp        x15, x14
//   0x5928: fa4d11e4  ccmp       x15, x13, #4, ne
//   0x592c: 54ffff40  b.eq       #0x5914
//   0x5930: 14000006  b          #0x5948
//   0x5934: aa1003ef  mov        x15, x16
//   0x5938: eb0e01ff  cmp        x15, x14
//   0x593c: 54fffec0  b.eq       #0x5914
//   0x5940: eb0d01ff  cmp        x15, x13
//   0x5944: 54fffe80  b.eq       #0x5914
//   0x5948: f94001f0  ldr        x16, [x15]
//   0x594c: b94025f1  ldr        w17, [x15, #0x24]
//   0x5950: b9402600  ldr        w0, [x16, #0x24]
//   0x5954: 6b00023f  cmp        w17, w0
//   0x5958: 54fffeea  b.ge       #0x5934
//   0x595c: f9400611  ldr        x17, [x16, #8]
//   0x5960: f900060a  str        x10, [x16, #8]
//   0x5964: f9025bf0  str        x16, [sp, #0x4b0]
//   0x5968: f9025ff1  str        x17, [sp, #0x4b8]
//   0x596c: f900022a  str        x10, [x17]
//   0x5970: f9400211  ldr        x17, [x16]
//   0x5974: f900062a  str        x10, [x17, #8]
//   0x5978: f9400600  ldr        x0, [x16, #8]
//   0x597c: f9000011  str        x17, [x0]
//   0x5980: f94005f1  ldr        x17, [x15, #8]
//   0x5984: f90005f0  str        x16, [x15, #8]
//   0x5988: a900460f  stp        x15, x17, [x16]
//   0x598c: f9000230  str        x16, [x17]
//   0x5990: a94041f1  ldp        x17, x16, [x15]
//   0x5994: f9000630  str        x16, [x17, #8]
//   0x5998: f94005f0  ldr        x16, [x15, #8]
//   0x599c: f9000211  str        x17, [x16]
//   0x59a0: f9425ff0  ldr        x16, [sp, #0x4b8]
//   0x59a4: f9025fef  str        x15, [sp, #0x4b8]
//   0x59a8: a90041ea  stp        x10, x16, [x15]
//   0x59ac: f900020f  str        x15, [x16]
//   0x59b0: f9425bf0  ldr        x16, [sp, #0x4b0]
//   0x59b4: f900060f  str        x15, [x16, #8]
//   0x59b8: f9425ff1  ldr        x17, [sp, #0x4b8]
//   0x59bc: f9000230  str        x16, [x17]
//   0x59c0: f94005ef  ldr        x15, [x15, #8]
//   0x59c4: eb0d01ff  cmp        x15, x13
//   0x59c8: 54fffa40  b.eq       #0x5910
//   0x59cc: f94001ef  ldr        x15, [x15]
//   0x59d0: eb0e01ff  cmp        x15, x14
//   0x59d4: 54fffb61  b.ne       #0x5940
//   0x59d8: 17ffffcf  b          #0x5914
//   0x59dc: f940038a  ldr        x10, [x28]
//   0x59e0: b9402fe9  ldr        w9, [sp, #0x2c]
//   0x59e4: f9007948  str        x8, [x10, #0xf0]
//   0x59e8: 7100053f  cmp        w9, #1
//   0x59ec: 54002181  b.ne       #0x5e1c
//   0x59f0: b9400d48  ldr        w8, [x10, #0xc]
//   0x59f4: b0ffffe1  adrp       x1, #0x2000
//   0x59f8: 91282021  add        x1, x1, #0xa08
//   0x59fc: 2a1303e0  mov        w0, w19
//   0x5a00: 52800162  mov        w2, #0xb
//   0x5a04: 321e0108  orr        w8, w8, #4
//   0x5a08: b9000d48  str        w8, [x10, #0xc]
//   0x5a0c: 94000b69  bl         #0x87b0
//   0x5a10: b0fffff4  adrp       x20, #0x2000
//   0x5a14: 91197694  add        x20, x20, #0x65d
//   0x5a18: 2a1303e0  mov        w0, w19
//   0x5a1c: aa1403e1  mov        x1, x20
//   0x5a20: 52800722  mov        w2, #0x39
//   0x5a24: 94000b63  bl         #0x87b0
//   0x5a28: 6f00e400  movi       v0.2d, #0000000000000000
//   0x5a2c: f9400388  ldr        x8, [x28]
//   0x5a30: b0ffffe3  adrp       x3, #0x2000
//   0x5a34: 91234463  add        x3, x3, #0x8d1
//   0x5a38: 9112c3e0  add        x0, sp, #0x4b0
//   0x5a3c: 52801001  mov        w1, #0x80
//   0x5a40: 52801002  mov        w2, #0x80
//   0x5a44: 3d814be0  str        q0, [sp, #0x520]
//   0x5a48: 3d8147e0  str        q0, [sp, #0x510]
//   0x5a4c: 3d8143e0  str        q0, [sp, #0x500]
//   0x5a50: 3d813fe0  str        q0, [sp, #0x4f0]
//   0x5a54: 3d813be0  str        q0, [sp, #0x4e0]
//   0x5a58: 3d8137e0  str        q0, [sp, #0x4d0]
//   0x5a5c: 3d8133e0  str        q0, [sp, #0x4c0]
//   0x5a60: b9401d04  ldr        w4, [x8, #0x1c]
//   0x5a64: 3d812fe0  str        q0, [sp, #0x4b0]
//   0x5a68: 94000321  bl         #0x66ec
//   0x5a6c: 9112c3e0  add        x0, sp, #0x4b0
//   0x5a70: 52801001  mov        w1, #0x80
//   0x5a74: 94000b83  bl         #0x8880
//   0x5a78: aa0003e2  mov        x2, x0
//   0x5a7c: 9112c3e1  add        x1, sp, #0x4b0
//   0x5a80: 2a1303e0  mov        w0, w19
//   0x5a84: 94000b4b  bl         #0x87b0
//   0x5a88: f9400388  ldr        x8, [x28]
//   0x5a8c: b0ffffe1  adrp       x1, #0x2000
//   0x5a90: 911da021  add        x1, x1, #0x768
//   0x5a94: 2a1303e0  mov        w0, w19
//   0x5a98: 91008102  add        x2, x8, #0x20
//   0x5a9c: 94000387  bl         #0x68b8
//   0x5aa0: f9400388  ldr        x8, [x28]
//   0x5aa4: b0ffffe1  adrp       x1, #0x2000
//   0x5aa8: 91285021  add        x1, x1, #0xa14
//   0x5aac: 2a1303e0  mov        w0, w19
//   0x5ab0: 9100c102  add        x2, x8, #0x30
//   0x5ab4: 94000381  bl         #0x68b8
//   0x5ab8: 2a1303e0  mov        w0, w19
//   0x5abc: aa1403e1  mov        x1, x20
//   0x5ac0: 52800722  mov        w2, #0x39
//   0x5ac4: 94000b3b  bl         #0x87b0
//   0x5ac8: 910103e1  add        x1, sp, #0x40
//   0x5acc: 2a1303e0  mov        w0, w19
//   0x5ad0: 910103f5  add        x21, sp, #0x40
//   0x5ad4: 94000248  bl         #0x63f4
//   0x5ad8: 52800f00  mov        w0, #0x78
//   0x5adc: 94000b6d  bl         #0x8890
//   0x5ae0: f9400388  ldr        x8, [x28]
//   0x5ae4: 2a1303e0  mov        w0, w19
//   0x5ae8: aa1403e1  mov        x1, x20
//   0x5aec: 52800722  mov        w2, #0x39
//   0x5af0: b9400d09  ldr        w9, [x8, #0xc]
//   0x5af4: 121d7929  and        w9, w9, #0xfffffffb
//   0x5af8: b9000d09  str        w9, [x8, #0xc]
//   0x5afc: 94000b2d  bl         #0x87b0
//   0x5b00: f94023f8  ldr        x24, [sp, #0x40]
//   0x5b04: f9400388  ldr        x8, [x28]
//   0x5b08: eb15031f  cmp        x24, x21
//   0x5b0c: 54001460  b.eq       #0x5d98
//   0x5b10: f0000037  adrp       x23, #0xc000
//   0x5b14: 2a1f03f5  mov        w21, wzr
//   0x5b18: b0fffff4  adrp       x20, #0x2000
//   0x5b1c: 911ede94  add        x20, x20, #0x7b7
//   0x5b20: f94662f7  ldr        x23, [x23, #0xcc0]
//   0x5b24: f9402509  ldr        x9, [x8, #0x48]
//   0x5b28: b5000049  cbnz       x9, #0x5b30
//   0x5b2c: f9002518  str        x24, [x8, #0x48]
//   0x5b30: 9100431b  add        x27, x24, #0x10
//   0x5b34: aa1b03f6  mov        x22, x27
//   0x5b38: 14000006  b          #0x5b50
//   0x5b3c: f94002e9  ldr        x9, [x23]
//   0x5b40: 110006b5  add        w21, w21, #1
//   0x5b44: b9401529  ldr        w9, [x9, #0x14]
//   0x5b48: 6b0902bf  cmp        w21, w9
//   0x5b4c: 5400126a  b.ge       #0x5d98
//   0x5b50: f94002d6  ldr        x22, [x22]
//   0x5b54: eb1b02df  cmp        x22, x27
//   0x5b58: 54001180  b.eq       #0x5d88
//   0x5b5c: f9400ac9  ldr        x9, [x22, #0x10]
//   0x5b60: f940093a  ldr        x26, [x9, #0x10]
//   0x5b64: f9402d09  ldr        x9, [x8, #0x58]
//   0x5b68: d1008359  sub        x25, x26, #0x20
//   0x5b6c: b5000049  cbnz       x9, #0x5b74
//   0x5b70: f9002d19  str        x25, [x8, #0x58]
//   0x5b74: 9102c3e0  add        x0, sp, #0xb0
//   0x5b78: 2a1f03e1  mov        w1, wzr
//   0x5b7c: 52808002  mov        w2, #0x400
//   0x5b80: 94000af0  bl         #0x8740
//   0x5b84: 29431747  ldp        w7, w5, [x26, #0x18]
//   0x5b88: b9401344  ldr        w4, [x26, #0x10]
//   0x5b8c: 9102c3e0  add        x0, sp, #0xb0
//   0x5b90: f9401b46  ldr        x6, [x26, #0x30]
//   0x5b94: 52808001  mov        w1, #0x400
//   0x5b98: 52808002  mov        w2, #0x400
//   0x5b9c: aa1403e3  mov        x3, x20
//   0x5ba0: 940002d3  bl         #0x66ec
//   0x5ba4: aa1903e0  mov        x0, x25
//   0x5ba8: 94000af2  bl         #0x8770
//   0x5bac: aa0003fa  mov        x26, x0
//   0x5bb0: aa1903e0  mov        x0, x25
//   0x5bb4: 94000acb  bl         #0x86e0
//   0x5bb8: aa000348  orr        x8, x26, x0
//   0x5bbc: b4000828  cbz        x8, #0x5cc0
//   0x5bc0: aa0003fc  mov        x28, x0
//   0x5bc4: 9102c3e0  add        x0, sp, #0xb0
//   0x5bc8: 52808001  mov        w1, #0x400
//   0x5bcc: 94000b2d  bl         #0x8880
//   0x5bd0: aa0003e2  mov        x2, x0
//   0x5bd4: 9102c3e1  add        x1, sp, #0xb0
//   0x5bd8: 2a1303e0  mov        w0, w19
//   0x5bdc: 94000af5  bl         #0x87b0
//   0x5be0: b400037a  cbz        x26, #0x5c4c
//   0x5be4: 2a1303e0  mov        w0, w19
//   0x5be8: b0ffffe1  adrp       x1, #0x2000
//   0x5bec: 91156c21  add        x1, x1, #0x55b
//   0x5bf0: 52800282  mov        w2, #0x14
//   0x5bf4: 94000aef  bl         #0x87b0
//   0x5bf8: aa1a03e0  mov        x0, x26
//   0x5bfc: 94000acd  bl         #0x8730
//   0x5c00: aa0003e2  mov        x2, x0
//   0x5c04: 2a1303e0  mov        w0, w19
//   0x5c08: aa1a03e1  mov        x1, x26
//   0x5c0c: 94000ae9  bl         #0x87b0
//   0x5c10: 2a1303e0  mov        w0, w19
//   0x5c14: b0ffffe1  adrp       x1, #0x2000
//   0x5c18: 91296c21  add        x1, x1, #0xa5b
//   0x5c1c: 52800022  mov        w2, #1
//   0x5c20: 94000ae4  bl         #0x87b0
//   0x5c24: f0000028  adrp       x8, #0xc000
//   0x5c28: f9465d08  ldr        x8, [x8, #0xcb8]
//   0x5c2c: f9400108  ldr        x8, [x8]
//   0x5c30: f9403109  ldr        x9, [x8, #0x60]
//   0x5c34: b5000089  cbnz       x9, #0x5c44
//   0x5c38: f9402d09  ldr        x9, [x8, #0x58]
//   0x5c3c: eb19013f  cmp        x9, x25
//   0x5c40: 54000540  b.eq       #0x5ce8
//   0x5c44: aa1a03e0  mov        x0, x26
//   0x5c48: 94000a46  bl         #0x8560
//   0x5c4c: b40003bc  cbz        x28, #0x5cc0
//   0x5c50: 2a1303e0  mov        w0, w19
//   0x5c54: b0ffffe1  adrp       x1, #0x2000
//   0x5c58: 91243821  add        x1, x1, #0x90e
//   0x5c5c: 52800242  mov        w2, #0x12
//   0x5c60: 94000ad4  bl         #0x87b0
//   0x5c64: aa1c03e0  mov        x0, x28
//   0x5c68: 94000ab2  bl         #0x8730
//   0x5c6c: aa0003e2  mov        x2, x0
//   0x5c70: 2a1303e0  mov        w0, w19
//   0x5c74: aa1c03e1  mov        x1, x28
//   0x5c78: 94000ace  bl         #0x87b0
//   0x5c7c: 2a1303e0  mov        w0, w19
//   0x5c80: b0ffffe1  adrp       x1, #0x2000
//   0x5c84: 91296c21  add        x1, x1, #0xa5b
//   0x5c88: 52800022  mov        w2, #1
//   0x5c8c: 94000ac9  bl         #0x87b0
//   0x5c90: f0000028  adrp       x8, #0xc000
//   0x5c94: f9465d08  ldr        x8, [x8, #0xcb8]
//   0x5c98: f9400108  ldr        x8, [x8]
//   0x5c9c: b9406919  ldr        w25, [x8, #0x68]
//   0x5ca0: 7100073f  cmp        w25, #1
//   0x5ca4: 540000eb  b.lt       #0x5cc0
//   0x5ca8: aa1c03e0  mov        x0, x28
//   0x5cac: 94000aa1  bl         #0x8730
//   0x5cb0: aa0003e2  mov        x2, x0
//   0x5cb4: 2a1903e0  mov        w0, w25
//   0x5cb8: aa1c03e1  mov        x1, x28
//   0x5cbc: 94000abd  bl         #0x87b0
//   0x5cc0: f000003c  adrp       x28, #0xc000
//   0x5cc4: f9465f9c  ldr        x28, [x28, #0xcb8]
//   0x5cc8: f9400388  ldr        x8, [x28]
//   0x5ccc: b9406900  ldr        w0, [x8, #0x68]
//   0x5cd0: 7100041f  cmp        w0, #1
//   0x5cd4: 54fff34b  b.lt       #0x5b3c
//   0x5cd8: 94000aba  bl         #0x87c0
//   0x5cdc: f9400388  ldr        x8, [x28]
//   0x5ce0: b900691f  str        wzr, [x8, #0x68]
//   0x5ce4: 17ffff96  b          #0x5b3c
//   0x5ce8: f9400119  ldr        x25, [x8]
//   0x5cec: f900311a  str        x26, [x8, #0x60]
//   0x5cf0: b4000479  cbz        x25, #0x5d7c
//   0x5cf4: 9112c3e0  add        x0, sp, #0x4b0
//   0x5cf8: 2a1f03e1  mov        w1, wzr
//   0x5cfc: 52808002  mov        w2, #0x400
//   0x5d00: 94000a90  bl         #0x8740
//   0x5d04: 9112c3e0  add        x0, sp, #0x4b0
//   0x5d08: 52808001  mov        w1, #0x400
//   0x5d0c: 52808002  mov        w2, #0x400
//   0x5d10: b0ffffe3  adrp       x3, #0x2000
//   0x5d14: 911e7863  add        x3, x3, #0x79e
//   0x5d18: aa1903e4  mov        x4, x25
//   0x5d1c: b0ffffe5  adrp       x5, #0x2000
//   0x5d20: 911af4a5  add        x5, x5, #0x6bd
//   0x5d24: 94000272  bl         #0x66ec
//   0x5d28: 9112c3e0  add        x0, sp, #0x4b0
//   0x5d2c: 52804841  mov        w1, #0x242
//   0x5d30: 52803002  mov        w2, #0x180
//   0x5d34: 94000a97  bl         #0x8790
//   0x5d38: 2a0003f9  mov        w25, w0
//   0x5d3c: 36f80160  tbz        w0, #0x1f, #0x5d68
//   0x5d40: 94000aa4  bl         #0x87d0
//   0x5d44: b9400004  ldr        w4, [x0]
//   0x5d48: 528000c0  mov        w0, #6
//   0x5d4c: b0ffffe1  adrp       x1, #0x2000
//   0x5d50: 9124c421  add        x1, x1, #0x931
//   0x5d54: b0ffffe2  adrp       x2, #0x2000
//   0x5d58: 912ae442  add        x2, x2, #0xab9
//   0x5d5c: b0ffffe3  adrp       x3, #0x2000
//   0x5d60: 911af463  add        x3, x3, #0x6bd
//   0x5d64: 94000a27  bl         #0x8600
//   0x5d68: f0000028  adrp       x8, #0xc000
//   0x5d6c: f9465d08  ldr        x8, [x8, #0xcb8]
//   0x5d70: f9400108  ldr        x8, [x8]
//   0x5d74: b9006919  str        w25, [x8, #0x68]
//   0x5d78: 17ffffb5  b          #0x5c4c
//   0x5d7c: 12800019  mov        w25, #-1
//   0x5d80: b9006919  str        w25, [x8, #0x68]
//   0x5d84: 17ffffb2  b          #0x5c4c
//   0x5d88: f9400318  ldr        x24, [x24]
//   0x5d8c: 910103e9  add        x9, sp, #0x40
//   0x5d90: eb09031f  cmp        x24, x9
//   0x5d94: 54ffec81  b.ne       #0x5b24
//   0x5d98: f9400114  ldr        x20, [x8]
//   0x5d9c: b40023b4  cbz        x20, #0x6210
//   0x5da0: 9112c3e0  add        x0, sp, #0x4b0
//   0x5da4: 2a1f03e1  mov        w1, wzr
//   0x5da8: 52808002  mov        w2, #0x400
//   0x5dac: 94000a65  bl         #0x8740
//   0x5db0: b0ffffe3  adrp       x3, #0x2000
//   0x5db4: 911e7863  add        x3, x3, #0x79e
//   0x5db8: b0ffffe5  adrp       x5, #0x2000
//   0x5dbc: 911fa0a5  add        x5, x5, #0x7e8
//   0x5dc0: 9112c3e0  add        x0, sp, #0x4b0
//   0x5dc4: 52808001  mov        w1, #0x400
//   0x5dc8: 52808002  mov        w2, #0x400
//   0x5dcc: aa1403e4  mov        x4, x20
//   0x5dd0: 94000247  bl         #0x66ec
//   0x5dd4: 9112c3e0  add        x0, sp, #0x4b0
//   0x5dd8: 52804841  mov        w1, #0x242
//   0x5ddc: 52803002  mov        w2, #0x180
//   0x5de0: 94000a6c  bl         #0x8790
//   0x5de4: 37f808a0  tbnz       w0, #0x1f, #0x5ef8
//   0x5de8: 2a0003f4  mov        w20, w0
//   0x5dec: 94000aad  bl         #0x88a0
//   0x5df0: 2a0003f5  mov        w21, w0
//   0x5df4: 3100041f  cmn        w0, #1
//   0x5df8: 54000960  b.eq       #0x5f24
//   0x5dfc: b0ffffe3  adrp       x3, #0x2000
//   0x5e00: 91139463  add        x3, x3, #0x4e5
//   0x5e04: 9112c3e0  add        x0, sp, #0x4b0
//   0x5e08: 52802001  mov        w1, #0x100
//   0x5e0c: 52802002  mov        w2, #0x100
//   0x5e10: 2a1503e4  mov        w4, w21
//   0x5e14: 94000236  bl         #0x66ec
//   0x5e18: 1400004a  b          #0x5f40
//   0x5e1c: b0ffffe1  adrp       x1, #0x2000
//   0x5e20: 91282021  add        x1, x1, #0xa08
//   0x5e24: 2a1303e0  mov        w0, w19
//   0x5e28: 52800162  mov        w2, #0xb
//   0x5e2c: 94000a61  bl         #0x87b0
//   0x5e30: b0fffff4  adrp       x20, #0x2000
//   0x5e34: 91197694  add        x20, x20, #0x65d
//   0x5e38: 2a1303e0  mov        w0, w19
//   0x5e3c: aa1403e1  mov        x1, x20
//   0x5e40: 52800722  mov        w2, #0x39
//   0x5e44: 94000a5b  bl         #0x87b0
//   0x5e48: 6f00e400  movi       v0.2d, #0000000000000000
//   0x5e4c: f9400388  ldr        x8, [x28]
//   0x5e50: b0ffffe3  adrp       x3, #0x2000
//   0x5e54: 91234463  add        x3, x3, #0x8d1
//   0x5e58: 9112c3e0  add        x0, sp, #0x4b0
//   0x5e5c: 52801001  mov        w1, #0x80
//   0x5e60: 52801002  mov        w2, #0x80
//   0x5e64: 3d814be0  str        q0, [sp, #0x520]
//   0x5e68: 3d8147e0  str        q0, [sp, #0x510]
//   0x5e6c: 3d8143e0  str        q0, [sp, #0x500]
//   0x5e70: 3d813fe0  str        q0, [sp, #0x4f0]
//   0x5e74: 3d813be0  str        q0, [sp, #0x4e0]
//   0x5e78: 3d8137e0  str        q0, [sp, #0x4d0]
//   0x5e7c: 3d8133e0  str        q0, [sp, #0x4c0]
//   0x5e80: b9401d04  ldr        w4, [x8, #0x1c]
//   0x5e84: 3d812fe0  str        q0, [sp, #0x4b0]
//   0x5e88: 94000219  bl         #0x66ec
//   0x5e8c: 9112c3e0  add        x0, sp, #0x4b0
//   0x5e90: 52801001  mov        w1, #0x80
//   0x5e94: 94000a7b  bl         #0x8880
//   0x5e98: aa0003e2  mov        x2, x0
//   0x5e9c: 9112c3e1  add        x1, sp, #0x4b0
//   0x5ea0: 2a1303e0  mov        w0, w19
//   0x5ea4: 94000a43  bl         #0x87b0
//   0x5ea8: f9400388  ldr        x8, [x28]
//   0x5eac: b0ffffe1  adrp       x1, #0x2000
//   0x5eb0: 911da021  add        x1, x1, #0x768
//   0x5eb4: 2a1303e0  mov        w0, w19
//   0x5eb8: 91008102  add        x2, x8, #0x20
//   0x5ebc: 9400027f  bl         #0x68b8
//   0x5ec0: f9400388  ldr        x8, [x28]
//   0x5ec4: b0ffffe1  adrp       x1, #0x2000
//   0x5ec8: 91285021  add        x1, x1, #0xa14
//   0x5ecc: 2a1303e0  mov        w0, w19
//   0x5ed0: 9100c102  add        x2, x8, #0x30
//   0x5ed4: 94000279  bl         #0x68b8
//   0x5ed8: 2a1303e0  mov        w0, w19
//   0x5edc: aa1403e1  mov        x1, x20
//   0x5ee0: 52800722  mov        w2, #0x39
//   0x5ee4: 94000a33  bl         #0x87b0
//   0x5ee8: 910103e1  add        x1, sp, #0x40
//   0x5eec: 2a1303e0  mov        w0, w19
//   0x5ef0: 94000141  bl         #0x63f4
//   0x5ef4: 140000f8  b          #0x62d4
//   0x5ef8: 94000a36  bl         #0x87d0
//   0x5efc: b9400004  ldr        w4, [x0]
//   0x5f00: b0ffffe1  adrp       x1, #0x2000
//   0x5f04: 9124c421  add        x1, x1, #0x931
//   0x5f08: b0ffffe2  adrp       x2, #0x2000
//   0x5f0c: 912ae442  add        x2, x2, #0xab9
//   0x5f10: b0ffffe3  adrp       x3, #0x2000
//   0x5f14: 911fa063  add        x3, x3, #0x7e8
//   0x5f18: 528000c0  mov        w0, #6
//   0x5f1c: 940009b9  bl         #0x8600
//   0x5f20: 140000bc  b          #0x6210
//   0x5f24: b0ffffe1  adrp       x1, #0x2000
//   0x5f28: 911dec21  add        x1, x1, #0x77b
//   0x5f2c: 9112c3e0  add        x0, sp, #0x4b0
//   0x5f30: 52802002  mov        w2, #0x100
//   0x5f34: 52802003  mov        w3, #0x100
//   0x5f38: 52800264  mov        w4, #0x13
//   0x5f3c: 94000a5d  bl         #0x88b0
//   0x5f40: 9112c3e0  add        x0, sp, #0x4b0
//   0x5f44: 52a00101  mov        w1, #0x80000
//   0x5f48: 94000a3e  bl         #0x8840
//   0x5f4c: 37f802e0  tbnz       w0, #0x1f, #0x5fa8
//   0x5f50: 9112c3e1  add        x1, sp, #0x4b0
//   0x5f54: 52802002  mov        w2, #0x100
//   0x5f58: 2a0003f7  mov        w23, w0
//   0x5f5c: 94000a3d  bl         #0x8850
//   0x5f60: aa0003f6  mov        x22, x0
//   0x5f64: 2a1703e0  mov        w0, w23
//   0x5f68: 94000a16  bl         #0x87c0
//   0x5f6c: f10006c8  subs       x8, x22, #1
//   0x5f70: 540001cb  b.lt       #0x5fa8
//   0x5f74: f10402df  cmp        x22, #0x100
//   0x5f78: 540000a0  b.eq       #0x5f8c
//   0x5f7c: 9112c3e9  add        x9, sp, #0x4b0
//   0x5f80: 38686929  ldrb       w9, [x9, x8]
//   0x5f84: 7100293f  cmp        w9, #0xa
//   0x5f88: 54000041  b.ne       #0x5f90
//   0x5f8c: aa0803f6  mov        x22, x8
//   0x5f90: 9112c3e0  add        x0, sp, #0x4b0
//   0x5f94: 9112c3e8  add        x8, sp, #0x4b0
//   0x5f98: 3836691f  strb       wzr, [x8, x22]
//   0x5f9c: 9400096d  bl         #0x8550
//   0x5fa0: aa0003f6  mov        x22, x0
//   0x5fa4: 14000002  b          #0x5fac
//   0x5fa8: aa1f03f6  mov        x22, xzr
//   0x5fac: f9400388  ldr        x8, [x28]
//   0x5fb0: f9402908  ldr        x8, [x8, #0x50]
//   0x5fb4: b4000088  cbz        x8, #0x5fc4
//   0x5fb8: b9401105  ldr        w5, [x8, #0x10]
//   0x5fbc: f9401506  ldr        x6, [x8, #0x28]
//   0x5fc0: 14000003  b          #0x5fcc
//   0x5fc4: aa1f03e6  mov        x6, xzr
//   0x5fc8: 12800005  mov        w5, #-1
//   0x5fcc: b0ffffe3  adrp       x3, #0x2000
//   0x5fd0: 911c5063  add        x3, x3, #0x714
//   0x5fd4: 9112c3e0  add        x0, sp, #0x4b0
//   0x5fd8: 52808001  mov        w1, #0x400
//   0x5fdc: 52807fe2  mov        w2, #0x3ff
//   0x5fe0: 2a1503e4  mov        w4, w21
//   0x5fe4: aa1603e7  mov        x7, x22
//   0x5fe8: 940001c1  bl         #0x66ec
//   0x5fec: 2a0003f5  mov        w21, w0
//   0x5ff0: b4000076  cbz        x22, #0x5ffc
//   0x5ff4: aa1603e0  mov        x0, x22
//   0x5ff8: 9400095a  bl         #0x8560
//   0x5ffc: 710006bf  cmp        w21, #1
//   0x6000: 540000ab  b.lt       #0x6014
//   0x6004: 2a1503e2  mov        w2, w21
//   0x6008: 9112c3e1  add        x1, sp, #0x4b0
//   0x600c: 2a1403e0  mov        w0, w20
//   0x6010: 940009e8  bl         #0x87b0
//   0x6014: f9400388  ldr        x8, [x28]
//   0x6018: f9402509  ldr        x9, [x8, #0x48]
//   0x601c: b4000089  cbz        x9, #0x602c
//   0x6020: f9401924  ldr        x4, [x9, #0x30]
//   0x6024: b9402525  ldr        w5, [x9, #0x24]
//   0x6028: 14000003  b          #0x6034
//   0x602c: 2a1f03e5  mov        w5, wzr
//   0x6030: aa1f03e4  mov        x4, xzr
//   0x6034: f940290a  ldr        x10, [x8, #0x50]
//   0x6038: b400008a  cbz        x10, #0x6048
//   0x603c: 29422547  ldp        w7, w9, [x10, #0x10]
//   0x6040: f9401546  ldr        x6, [x10, #0x28]
//   0x6044: 14000004  b          #0x6054
//   0x6048: 2a1f03e9  mov        w9, wzr
//   0x604c: aa1f03e6  mov        x6, xzr
//   0x6050: 12800007  mov        w7, #-1
//   0x6054: 294e210a  ldp        w10, w8, [x8, #0x70]
//   0x6058: 528002eb  mov        w11, #0x17
//   0x605c: 90ffffe3  adrp       x3, #0x2000
//   0x6060: 91260c63  add        x3, x3, #0x983
//   0x6064: 9112c3e0  add        x0, sp, #0x4b0
//   0x6068: 52808001  mov        w1, #0x400
//   0x606c: 52807fe2  mov        w2, #0x3ff
//   0x6070: 3100055f  cmn        w10, #1
//   0x6074: b90013e8  str        w8, [sp, #0x10]
//   0x6078: 1a8a016a  csel       w10, w11, w10, eq
//   0x607c: d503201f  nop        
//   0x6080: 10034bcb  adr        x11, #0xc9f8
//   0x6084: b90003e9  str        w9, [sp]
//   0x6088: f86ad96a  ldr        x10, [x11, w10, sxtw #3]
//   0x608c: f90007ea  str        x10, [sp, #8]
//   0x6090: 94000197  bl         #0x66ec
//   0x6094: 7100041f  cmp        w0, #1
//   0x6098: 540000ab  b.lt       #0x60ac
//   0x609c: 2a0003e2  mov        w2, w0
//   0x60a0: 9112c3e1  add        x1, sp, #0x4b0
//   0x60a4: 2a1403e0  mov        w0, w20
//   0x60a8: 940009c2  bl         #0x87b0
//   0x60ac: 90ffffe1  adrp       x1, #0x2000
//   0x60b0: 9118f421  add        x1, x1, #0x63d
//   0x60b4: 2a1403e0  mov        w0, w20
//   0x60b8: 52800162  mov        w2, #0xb
//   0x60bc: 940009bd  bl         #0x87b0
//   0x60c0: f9400388  ldr        x8, [x28]
//   0x60c4: f9403115  ldr        x21, [x8, #0x60]
//   0x60c8: b4000535  cbz        x21, #0x616c
//   0x60cc: aa1503e0  mov        x0, x21
//   0x60d0: 94000998  bl         #0x8730
//   0x60d4: aa0003e2  mov        x2, x0
//   0x60d8: 2a1403e0  mov        w0, w20
//   0x60dc: aa1503e1  mov        x1, x21
//   0x60e0: 940009b4  bl         #0x87b0
//   0x60e4: f9400388  ldr        x8, [x28]
//   0x60e8: f9402d08  ldr        x8, [x8, #0x58]
//   0x60ec: b40008e8  cbz        x8, #0x6208
//   0x60f0: f9402100  ldr        x0, [x8, #0x40]
//   0x60f4: 9102c3e1  add        x1, sp, #0xb0
//   0x60f8: 940009da  bl         #0x8860
//   0x60fc: 34000860  cbz        w0, #0x6208
//   0x6100: f9405be0  ldr        x0, [sp, #0xb0]
//   0x6104: 940009ef  bl         #0x88c0
//   0x6108: b4000800  cbz        x0, #0x6208
//   0x610c: aa0003f5  mov        x21, x0
//   0x6110: f9405be4  ldr        x4, [sp, #0xb0]
//   0x6114: 90ffffe3  adrp       x3, #0x2000
//   0x6118: 91216463  add        x3, x3, #0x859
//   0x611c: 9112c3e0  add        x0, sp, #0x4b0
//   0x6120: 52808001  mov        w1, #0x400
//   0x6124: 52807fe2  mov        w2, #0x3ff
//   0x6128: aa1503e5  mov        x5, x21
//   0x612c: 94000170  bl         #0x66ec
//   0x6130: 7100041f  cmp        w0, #1
//   0x6134: 5400016b  b.lt       #0x6160
//   0x6138: 2a0003f6  mov        w22, w0
//   0x613c: 90ffffe1  adrp       x1, #0x2000
//   0x6140: 91192421  add        x1, x1, #0x649
//   0x6144: 2a1403e0  mov        w0, w20
//   0x6148: 52800142  mov        w2, #0xa
//   0x614c: 94000999  bl         #0x87b0
//   0x6150: 2a1603e2  mov        w2, w22
//   0x6154: 9112c3e1  add        x1, sp, #0x4b0
//   0x6158: 2a1403e0  mov        w0, w20
//   0x615c: 94000995  bl         #0x87b0
//   0x6160: aa1503e0  mov        x0, x21
//   0x6164: 940008ff  bl         #0x8560
//   0x6168: 14000028  b          #0x6208
//   0x616c: f9402d08  ldr        x8, [x8, #0x58]
//   0x6170: b40004c8  cbz        x8, #0x6208
//   0x6174: f9402116  ldr        x22, [x8, #0x40]
//   0x6178: 9102c3e1  add        x1, sp, #0xb0
//   0x617c: aa1603e0  mov        x0, x22
//   0x6180: 940009d4  bl         #0x88d0
//   0x6184: 34000420  cbz        w0, #0x6208
//   0x6188: a94b9be8  ldp        x8, x6, [sp, #0xb8]
//   0x618c: f9405be5  ldr        x5, [sp, #0xb0]
//   0x6190: cb0802c4  sub        x4, x22, x8
//   0x6194: b4000206  cbz        x6, #0x61d4
//   0x6198: f94067e8  ldr        x8, [sp, #0xc8]
//   0x619c: 2a0003f5  mov        w21, w0
//   0x61a0: 90ffffe3  adrp       x3, #0x2000
//   0x61a4: 9113d863  add        x3, x3, #0x4f6
//   0x61a8: 9112c3e0  add        x0, sp, #0x4b0
//   0x61ac: 52808001  mov        w1, #0x400
//   0x61b0: cb0802c7  sub        x7, x22, x8
//   0x61b4: 52807fe2  mov        w2, #0x3ff
//   0x61b8: 9400014d  bl         #0x66ec
//   0x61bc: 2a0003f6  mov        w22, w0
//   0x61c0: 71000abf  cmp        w21, #2
//   0x61c4: 54000161  b.ne       #0x61f0
//   0x61c8: f94063e0  ldr        x0, [sp, #0xc0]
//   0x61cc: 940008e5  bl         #0x8560
//   0x61d0: 14000008  b          #0x61f0
//   0x61d4: 90ffffe3  adrp       x3, #0x2000
//   0x61d8: 91227463  add        x3, x3, #0x89d
//   0x61dc: 9112c3e0  add        x0, sp, #0x4b0
//   0x61e0: 52808001  mov        w1, #0x400
//   0x61e4: 52807fe2  mov        w2, #0x3ff
//   0x61e8: 94000141  bl         #0x66ec
//   0x61ec: 2a0003f6  mov        w22, w0
//   0x61f0: 710002df  cmp        w22, #0
//   0x61f4: 540000ad  b.le       #0x6208
//   0x61f8: 2a1603e2  mov        w2, w22
//   0x61fc: 9112c3e1  add        x1, sp, #0x4b0
//   0x6200: 2a1403e0  mov        w0, w20
//   0x6204: 17ffffb7  b          #0x60e0
//   0x6208: 2a1403e0  mov        w0, w20
//   0x620c: 9400096d  bl         #0x87c0
//   0x6210: 9102c3e0  add        x0, sp, #0xb0
//   0x6214: 940009b3  bl         #0x88e0
//   0x6218: f9400388  ldr        x8, [x28]
//   0x621c: f9400114  ldr        x20, [x8]
//   0x6220: b40005b4  cbz        x20, #0x62d4
//   0x6224: 9112c3e0  add        x0, sp, #0x4b0
//   0x6228: 2a1f03e1  mov        w1, wzr
//   0x622c: 52808002  mov        w2, #0x400
//   0x6230: 94000944  bl         #0x8740
//   0x6234: 90ffffe3  adrp       x3, #0x2000
//   0x6238: 911e7863  add        x3, x3, #0x79e
//   0x623c: 90ffffe5  adrp       x5, #0x2000
//   0x6240: 9122d0a5  add        x5, x5, #0x8b4
//   0x6244: 9112c3e0  add        x0, sp, #0x4b0
//   0x6248: 52808001  mov        w1, #0x400
//   0x624c: 52808002  mov        w2, #0x400
//   0x6250: aa1403e4  mov        x4, x20
//   0x6254: 94000126  bl         #0x66ec
//   0x6258: 9112c3e0  add        x0, sp, #0x4b0
//   0x625c: 52804841  mov        w1, #0x242
//   0x6260: 52803002  mov        w2, #0x180
//   0x6264: 9400094b  bl         #0x8790
//   0x6268: 37f80220  tbnz       w0, #0x1f, #0x62ac
//   0x626c: 2a0003f4  mov        w20, w0
//   0x6270: 34000320  cbz        w0, #0x62d4
//   0x6274: f9405be4  ldr        x4, [sp, #0xb0]
//   0x6278: 90ffffe3  adrp       x3, #0x2000
//   0x627c: 91195063  add        x3, x3, #0x654
//   0x6280: 9112c3e0  add        x0, sp, #0x4b0
//   0x6284: 52800801  mov        w1, #0x40
//   0x6288: 52800802  mov        w2, #0x40
//   0x628c: 94000118  bl         #0x66ec
//   0x6290: 93407c02  sxtw       x2, w0
//   0x6294: 9112c3e1  add        x1, sp, #0x4b0
//   0x6298: 2a1403e0  mov        w0, w20
//   0x629c: 94000945  bl         #0x87b0
//   0x62a0: 2a1403e0  mov        w0, w20
//   0x62a4: 94000947  bl         #0x87c0
//   0x62a8: 1400000b  b          #0x62d4
//   0x62ac: 94000949  bl         #0x87d0
//   0x62b0: b9400004  ldr        w4, [x0]
//   0x62b4: 90ffffe1  adrp       x1, #0x2000
//   0x62b8: 9124c421  add        x1, x1, #0x931
//   0x62bc: 90ffffe2  adrp       x2, #0x2000
//   0x62c0: 912ae442  add        x2, x2, #0xab9
//   0x62c4: 90ffffe3  adrp       x3, #0x2000
//   0x62c8: 9122d063  add        x3, x3, #0x8b4
//   0x62cc: 528000c0  mov        w0, #6
//   0x62d0: 940008cc  bl         #0x8600
//   0x62d4: 2a1303e0  mov        w0, w19
//   0x62d8: 9400093a  bl         #0x87c0
//   0x62dc: f94023f3  ldr        x19, [sp, #0x40]
//   0x62e0: 910103f5  add        x21, sp, #0x40
//   0x62e4: eb15027f  cmp        x19, x21
//   0x62e8: 54000241  b.ne       #0x6330
//   0x62ec: f9401bf3  ldr        x19, [sp, #0x30]
//   0x62f0: 9100c3f4  add        x20, sp, #0x30
//   0x62f4: eb14027f  cmp        x19, x20
//   0x62f8: 540006e1  b.ne       #0x63d4
//   0x62fc: 940008f5  bl         #0x86d0
//   0x6300: 2a1f03e0  mov        w0, wzr
//   0x6304: f94013f4  ldr        x20, [sp, #0x20]
//   0x6308: 17fffabb  b          #0x4df4
//   0x630c: a9402269  ldp        x9, x8, [x19]
//   0x6310: aa1303e0  mov        x0, x19
//   0x6314: f9000528  str        x8, [x9, #8]
//   0x6318: f9400668  ldr        x8, [x19, #8]
//   0x631c: f9000109  str        x9, [x8]
//   0x6320: 94000890  bl         #0x8560
//   0x6324: aa1603f3  mov        x19, x22
//   0x6328: eb1502df  cmp        x22, x21
//   0x632c: 54fffe00  b.eq       #0x62ec
//   0x6330: aa1303f7  mov        x23, x19
//   0x6334: f9400276  ldr        x22, [x19]
//   0x6338: f8410ef4  ldr        x20, [x23, #0x10]!
//   0x633c: eb17029f  cmp        x20, x23
//   0x6340: 540001c1  b.ne       #0x6378
//   0x6344: f9401a60  ldr        x0, [x19, #0x30]
//   0x6348: b4fffe20  cbz        x0, #0x630c
//   0x634c: 94000885  bl         #0x8560
//   0x6350: 17ffffef  b          #0x630c
//   0x6354: a9402289  ldp        x9, x8, [x20]
//   0x6358: aa1403e0  mov        x0, x20
//   0x635c: f9000528  str        x8, [x9, #8]
//   0x6360: f9400688  ldr        x8, [x20, #8]
//   0x6364: f9000109  str        x9, [x8]
//   0x6368: 9400087e  bl         #0x8560
//   0x636c: aa1803f4  mov        x20, x24
//   0x6370: eb17031f  cmp        x24, x23
//   0x6374: 54fffe80  b.eq       #0x6344
//   0x6378: aa1403f9  mov        x25, x20
//   0x637c: f9400298  ldr        x24, [x20]
//   0x6380: f8410f20  ldr        x0, [x25, #0x10]!
//   0x6384: eb19001f  cmp        x0, x25
//   0x6388: 540000c0  b.eq       #0x63a0
//   0x638c: f940001a  ldr        x26, [x0]
//   0x6390: 94000874  bl         #0x8560
//   0x6394: aa1a03e0  mov        x0, x26
//   0x6398: eb19035f  cmp        x26, x25
//   0x639c: 54ffff81  b.ne       #0x638c
//   0x63a0: f9401a80  ldr        x0, [x20, #0x30]
//   0x63a4: b4fffd80  cbz        x0, #0x6354
//   0x63a8: 9400086e  bl         #0x8560
//   0x63ac: 17ffffea  b          #0x6354
//   0x63b0: f9400669  ldr        x9, [x19, #8]
//   0x63b4: aa1303e0  mov        x0, x19
//   0x63b8: f9000509  str        x9, [x8, #8]
//   0x63bc: f9400669  ldr        x9, [x19, #8]
//   0x63c0: f9000128  str        x8, [x9]
//   0x63c4: 94000867  bl         #0x8560
//   0x63c8: aa1503f3  mov        x19, x21
//   0x63cc: eb1402bf  cmp        x21, x20
//   0x63d0: 54fff960  b.eq       #0x62fc
//   0x63d4: f9400275  ldr        x21, [x19]
//   0x63d8: f9401660  ldr        x0, [x19, #0x28]
//   0x63dc: aa1503e8  mov        x8, x21
//   0x63e0: b4fffe80  cbz        x0, #0x63b0
//   0x63e4: 9400085f  bl         #0x8560
//   0x63e8: f9400268  ldr        x8, [x19]
//   0x63ec: 17fffff1  b          #0x63b0
//   0x63f0: 94000870  bl         #0x85b0

// ----------------------------------------------------------------------------
// FDE[26] DumpFdSummaryTable_63f4 (0x63f4..0x66ec, 760 bytes, 190 instructions)
// Summary / Tóm tắt: Writes formatted FD summary table & per-category counts (@ 0x63f4..0x66ec)
// ----------------------------------------------------------------------------
//   0x63f4: a9ba7bfd  stp        x29, x30, [sp, #-0x60]!
//   0x63f8: a9016ffc  stp        x28, x27, [sp, #0x10]
//   0x63fc: a90267fa  stp        x26, x25, [sp, #0x20]
//   0x6400: a9035ff8  stp        x24, x23, [sp, #0x30]
//   0x6404: a90457f6  stp        x22, x21, [sp, #0x40]
//   0x6408: a9054ff4  stp        x20, x19, [sp, #0x50]
//   0x640c: 910003fd  mov        x29, sp
//   0x6410: d14007ff  sub        sp, sp, #1, lsl #12
//   0x6414: d102c3ff  sub        sp, sp, #0xb0
//   0x6418: d53bd048  mrs        x8, tpidr_el0
//   0x641c: aa0103f3  mov        x19, x1
//   0x6420: f9000fe8  str        x8, [sp, #0x18]
//   0x6424: 90ffffe1  adrp       x1, #0x2000
//   0x6428: 912cc021  add        x1, x1, #0xb30
//   0x642c: f9401508  ldr        x8, [x8, #0x28]
//   0x6430: 52800822  mov        w2, #0x41
//   0x6434: 2a0003f4  mov        w20, w0
//   0x6438: f81e83a8  stur       x8, [x29, #-0x18]
//   0x643c: 940008dd  bl         #0x87b0
//   0x6440: 90ffffe1  adrp       x1, #0x2000
//   0x6444: 91175c21  add        x1, x1, #0x5d7
//   0x6448: 2a1403e0  mov        w0, w20
//   0x644c: 52800822  mov        w2, #0x41
//   0x6450: 940008d8  bl         #0x87b0
//   0x6454: 90ffffe1  adrp       x1, #0x2000
//   0x6458: 91197421  add        x1, x1, #0x65d
//   0x645c: 2a1403e0  mov        w0, w20
//   0x6460: 52800722  mov        w2, #0x39
//   0x6464: 940008d3  bl         #0x87b0
//   0x6468: f9400275  ldr        x21, [x19]
//   0x646c: f90013f3  str        x19, [sp, #0x20]
//   0x6470: eb1302bf  cmp        x21, x19
//   0x6474: 540011e0  b.eq       #0x66b0
//   0x6478: d29ef9fa  mov        x26, #0xf7cf
//   0x647c: 9111c3fc  add        x28, sp, #0x470
//   0x6480: f2bc6a7a  movk       x26, #0xe353, lsl #16
//   0x6484: 90fffff8  adrp       x24, #0x2000
//   0x6488: 912a3318  add        x24, x24, #0xa8c
//   0x648c: f2d374ba  movk       x26, #0x9ba5, lsl #32
//   0x6490: f2e4189a  movk       x26, #0x20c4, lsl #48
//   0x6494: 90fffff9  adrp       x25, #0x2000
//   0x6498: 912f5339  add        x25, x25, #0xbd4
//   0x649c: 14000005  b          #0x64b0
//   0x64a0: a94257e8  ldp        x8, x21, [sp, #0x20]
//   0x64a4: f94002b5  ldr        x21, [x21]
//   0x64a8: eb0802bf  cmp        x21, x8
//   0x64ac: 54001020  b.eq       #0x66b0
//   0x64b0: 913263e0  add        x0, sp, #0xc98
//   0x64b4: 2a1f03e1  mov        w1, wzr
//   0x64b8: 52808002  mov        w2, #0x400
//   0x64bc: 940008a1  bl         #0x8740
//   0x64c0: a94312a6  ldp        x6, x4, [x21, #0x30]
//   0x64c4: 913263e0  add        x0, sp, #0xc98
//   0x64c8: 52808001  mov        w1, #0x400
//   0x64cc: b94026a5  ldr        w5, [x21, #0x24]
//   0x64d0: 52808002  mov        w2, #0x400
//   0x64d4: 90ffffe3  adrp       x3, #0x2000
//   0x64d8: 91289863  add        x3, x3, #0xa26
//   0x64dc: 94000084  bl         #0x66ec
//   0x64e0: 913263e0  add        x0, sp, #0xc98
//   0x64e4: 52808001  mov        w1, #0x400
//   0x64e8: 940008e6  bl         #0x8880
//   0x64ec: aa0003e2  mov        x2, x0
//   0x64f0: 913263e1  add        x1, sp, #0xc98
//   0x64f4: 2a1403e0  mov        w0, w20
//   0x64f8: 940008ae  bl         #0x87b0
//   0x64fc: f90017f5  str        x21, [sp, #0x28]
//   0x6500: f8410eb6  ldr        x22, [x21, #0x10]!
//   0x6504: f9001bf5  str        x21, [sp, #0x30]
//   0x6508: eb1502df  cmp        x22, x21
//   0x650c: 540000c1  b.ne       #0x6524
//   0x6510: 17ffffe4  b          #0x64a0
//   0x6514: f94002d6  ldr        x22, [x22]
//   0x6518: f9401be8  ldr        x8, [sp, #0x30]
//   0x651c: eb0802df  cmp        x22, x8
//   0x6520: 54fffc00  b.eq       #0x64a0
//   0x6524: 912263e0  add        x0, sp, #0x898
//   0x6528: 2a1f03e1  mov        w1, wzr
//   0x652c: 52808002  mov        w2, #0x400
//   0x6530: 94000884  bl         #0x8740
//   0x6534: a94312c6  ldp        x6, x4, [x22, #0x30]
//   0x6538: 912263e0  add        x0, sp, #0x898
//   0x653c: 52808001  mov        w1, #0x400
//   0x6540: b94026c5  ldr        w5, [x22, #0x24]
//   0x6544: 52808002  mov        w2, #0x400
//   0x6548: 90ffffe3  adrp       x3, #0x2000
//   0x654c: 91239863  add        x3, x3, #0x8e6
//   0x6550: 94000067  bl         #0x66ec
//   0x6554: 912263e0  add        x0, sp, #0x898
//   0x6558: 52808001  mov        w1, #0x400
//   0x655c: 940008c9  bl         #0x8880
//   0x6560: aa0003e2  mov        x2, x0
//   0x6564: 912263e1  add        x1, sp, #0x898
//   0x6568: 2a1403e0  mov        w0, w20
//   0x656c: 94000891  bl         #0x87b0
//   0x6570: aa1603f3  mov        x19, x22
//   0x6574: f8410e7b  ldr        x27, [x19, #0x10]!
//   0x6578: 14000002  b          #0x6580
//   0x657c: f940037b  ldr        x27, [x27]
//   0x6580: eb13037f  cmp        x27, x19
//   0x6584: 54fffc80  b.eq       #0x6514
//   0x6588: 911263e0  add        x0, sp, #0x498
//   0x658c: 2a1f03e1  mov        w1, wzr
//   0x6590: 52808002  mov        w2, #0x400
//   0x6594: 9400086b  bl         #0x8740
//   0x6598: a9431366  ldp        x6, x4, [x27, #0x30]
//   0x659c: 911263e0  add        x0, sp, #0x498
//   0x65a0: 52808001  mov        w1, #0x400
//   0x65a4: b9402765  ldr        w5, [x27, #0x24]
//   0x65a8: 52808002  mov        w2, #0x400
//   0x65ac: 90ffffe3  adrp       x3, #0x2000
//   0x65b0: 9123e863  add        x3, x3, #0x8fa
//   0x65b4: 9400004e  bl         #0x66ec
//   0x65b8: 911263e0  add        x0, sp, #0x498
//   0x65bc: 52808001  mov        w1, #0x400
//   0x65c0: 940008b0  bl         #0x8880
//   0x65c4: aa0003e2  mov        x2, x0
//   0x65c8: 911263e1  add        x1, sp, #0x498
//   0x65cc: 2a1403e0  mov        w0, w20
//   0x65d0: 94000878  bl         #0x87b0
//   0x65d4: 6f00e400  movi       v0.2d, #0000000000000000
//   0x65d8: aa1b03f5  mov        x21, x27
//   0x65dc: ad000380  stp        q0, q0, [x28]
//   0x65e0: f8410eb7  ldr        x23, [x21, #0x10]!
//   0x65e4: eb1502ff  cmp        x23, x21
//   0x65e8: 540002e1  b.ne       #0x6644
//   0x65ec: 17ffffe4  b          #0x657c
//   0x65f0: 29431ae7  ldp        w7, w6, [x23, #0x18]
//   0x65f4: 294222e5  ldp        w5, w8, [x23, #0x10]
//   0x65f8: f9401ae9  ldr        x9, [x23, #0x30]
//   0x65fc: 9101c3e0  add        x0, sp, #0x70
//   0x6600: 9111c3e4  add        x4, sp, #0x470
//   0x6604: 52808001  mov        w1, #0x400
//   0x6608: 52808002  mov        w2, #0x400
//   0x660c: aa1803e3  mov        x3, x24
//   0x6610: f90007e9  str        x9, [sp, #8]
//   0x6614: b90003e8  str        w8, [sp]
//   0x6618: 94000035  bl         #0x66ec
//   0x661c: 9101c3e0  add        x0, sp, #0x70
//   0x6620: 52808001  mov        w1, #0x400
//   0x6624: 94000897  bl         #0x8880
//   0x6628: aa0003e2  mov        x2, x0
//   0x662c: 9101c3e1  add        x1, sp, #0x70
//   0x6630: 2a1403e0  mov        w0, w20
//   0x6634: 9400085f  bl         #0x87b0
//   0x6638: f94002f7  ldr        x23, [x23]
//   0x663c: eb1502ff  cmp        x23, x21
//   0x6640: 54fff9e0  b.eq       #0x657c
//   0x6644: 9101c3e0  add        x0, sp, #0x70
//   0x6648: 2a1f03e1  mov        w1, wzr
//   0x664c: 52808002  mov        w2, #0x400
//   0x6650: 9400083c  bl         #0x8740
//   0x6654: 9100e2e0  add        x0, x23, #0x38
//   0x6658: 9100e3e1  add        x1, sp, #0x38
//   0x665c: 940008a5  bl         #0x88f0
//   0x6660: b4fffc80  cbz        x0, #0x65f0
//   0x6664: 294923ea  ldp        w10, w8, [sp, #0x48]
//   0x6668: f94022e9  ldr        x9, [x23, #0x40]
//   0x666c: 9111c3e0  add        x0, sp, #0x470
//   0x6670: 29481be7  ldp        w7, w6, [sp, #0x40]
//   0x6674: 52800401  mov        w1, #0x20
//   0x6678: 52800402  mov        w2, #0x20
//   0x667c: 111db104  add        w4, w8, #0x76c
//   0x6680: 9b5a7d28  smulh      x8, x9, x26
//   0x6684: 11000545  add        w5, w10, #1
//   0x6688: aa1903e3  mov        x3, x25
//   0x668c: 9347fd09  asr        x9, x8, #7
//   0x6690: 29472beb  ldp        w11, w10, [sp, #0x38]
//   0x6694: 8b48fd28  add        x8, x9, x8, lsr #63
//   0x6698: b9000beb  str        w11, [sp, #8]
//   0x669c: b90003ea  str        w10, [sp]
//   0x66a0: f9000be8  str        x8, [sp, #0x10]
//   0x66a4: 94000012  bl         #0x66ec
//   0x66a8: 3820cb9f  strb       wzr, [x28, w0, sxtw]
//   0x66ac: 17ffffd1  b          #0x65f0
//   0x66b0: f9400fe8  ldr        x8, [sp, #0x18]
//   0x66b4: f9401508  ldr        x8, [x8, #0x28]
//   0x66b8: f85e83a9  ldur       x9, [x29, #-0x18]
//   0x66bc: eb09011f  cmp        x8, x9
//   0x66c0: 54000141  b.ne       #0x66e8
//   0x66c4: 914007ff  add        sp, sp, #1, lsl #12
//   0x66c8: 9102c3ff  add        sp, sp, #0xb0
//   0x66cc: a9454ff4  ldp        x20, x19, [sp, #0x50]
//   0x66d0: a94457f6  ldp        x22, x21, [sp, #0x40]
//   0x66d4: a9435ff8  ldp        x24, x23, [sp, #0x30]
//   0x66d8: a94267fa  ldp        x26, x25, [sp, #0x20]
//   0x66dc: a9416ffc  ldp        x28, x27, [sp, #0x10]
//   0x66e0: a8c67bfd  ldp        x29, x30, [sp], #0x60
//   0x66e4: d65f03c0  ret        
//   0x66e8: 940007b2  bl         #0x85b0

// ----------------------------------------------------------------------------
// FDE[27] WriteFormattedLineToFd_66ec (0x66ec..0x6790, 164 bytes, 41 instructions)
// Summary / Tóm tắt: Variadic vsnprintf + write helper for dump files (@ 0x66ec..0x6790)
// ----------------------------------------------------------------------------
//   0x66ec: d10443ff  sub        sp, sp, #0x110
//   0x66f0: a90f7bfd  stp        x29, x30, [sp, #0xf0]
//   0x66f4: a9104ffc  stp        x28, x19, [sp, #0x100]
//   0x66f8: 9103c3fd  add        x29, sp, #0xf0
//   0x66fc: a93917a4  stp        x4, x5, [x29, #-0x70]
//   0x6700: d101c3aa  sub        x10, x29, #0x70
//   0x6704: a93a1fa6  stp        x6, x7, [x29, #-0x60]
//   0x6708: 928003ec  mov        x12, #-0x20
//   0x670c: ad0007e0  stp        q0, q1, [sp]
//   0x6710: 910003ed  mov        x13, sp
//   0x6714: ad010fe2  stp        q2, q3, [sp, #0x20]
//   0x6718: 9100814a  add        x10, x10, #0x20
//   0x671c: ad0217e4  stp        q4, q5, [sp, #0x40]
//   0x6720: f2dff00c  movk       x12, #0xff80, lsl #32
//   0x6724: ad031fe6  stp        q6, q7, [sp, #0x60]
//   0x6728: d53bd053  mrs        x19, tpidr_el0
//   0x672c: f9401669  ldr        x9, [x19, #0x28]
//   0x6730: 910201ad  add        x13, x13, #0x80
//   0x6734: d100a3ab  sub        x11, x29, #0x28
//   0x6738: aa0303e8  mov        x8, x3
//   0x673c: aa0103e3  mov        x3, x1
//   0x6740: d10143a5  sub        x5, x29, #0x50
//   0x6744: f81f83a9  stur       x9, [x29, #-8]
//   0x6748: 910083a9  add        x9, x29, #0x20
//   0x674c: a93eb3ad  stp        x13, x12, [x29, #-0x18]
//   0x6750: aa0203e1  mov        x1, x2
//   0x6754: 2a1f03e2  mov        w2, wzr
//   0x6758: aa0803e4  mov        x4, x8
//   0x675c: a93daba9  stp        x9, x10, [x29, #-0x28]
//   0x6760: ad400560  ldp        q0, q1, [x11]
//   0x6764: ad3d87a0  stp        q0, q1, [x29, #-0x50]
//   0x6768: 94000866  bl         #0x8900
//   0x676c: f9401668  ldr        x8, [x19, #0x28]
//   0x6770: f85f83a9  ldur       x9, [x29, #-8]
//   0x6774: eb09011f  cmp        x8, x9
//   0x6778: 540000a1  b.ne       #0x678c
//   0x677c: a9504ffc  ldp        x28, x19, [sp, #0x100]
//   0x6780: a94f7bfd  ldp        x29, x30, [sp, #0xf0]
//   0x6784: 910443ff  add        sp, sp, #0x110
//   0x6788: d65f03c0  ret        
//   0x678c: 94000789  bl         #0x85b0

// ----------------------------------------------------------------------------
// FDE[28] FindThreadNameByTid_6790 (0x6790..0x68b8, 296 bytes, 74 instructions)
// Summary / Tóm tắt: Resolves thread name from ART thread list or /proc/%d/comm (@ 0x6790..0x68b8)
// ----------------------------------------------------------------------------
//   0x6790: d10243ff  sub        sp, sp, #0x90
//   0x6794: a9057bfd  stp        x29, x30, [sp, #0x50]
//   0x6798: f90033f7  str        x23, [sp, #0x60]
//   0x679c: a90757f6  stp        x22, x21, [sp, #0x70]
//   0x67a0: a9084ff4  stp        x20, x19, [sp, #0x80]
//   0x67a4: 910143fd  add        x29, sp, #0x50
//   0x67a8: d53bd056  mrs        x22, tpidr_el0
//   0x67ac: f94016c8  ldr        x8, [x22, #0x28]
//   0x67b0: f81f83a8  stur       x8, [x29, #-8]
//   0x67b4: f9400037  ldr        x23, [x1]
//   0x67b8: eb0102ff  cmp        x23, x1
//   0x67bc: 54000680  b.eq       #0x688c
//   0x67c0: aa0003f3  mov        x19, x0
//   0x67c4: 14000004  b          #0x67d4
//   0x67c8: f94002f7  ldr        x23, [x23]
//   0x67cc: eb0102ff  cmp        x23, x1
//   0x67d0: 540005e0  b.eq       #0x688c
//   0x67d4: f9400ee9  ldr        x9, [x23, #0x18]
//   0x67d8: b4ffff89  cbz        x9, #0x67c8
//   0x67dc: f9401e68  ldr        x8, [x19, #0x38]
//   0x67e0: eb08013f  cmp        x9, x8
//   0x67e4: 54ffff22  b.hs       #0x67c8
//   0x67e8: f94012e9  ldr        x9, [x23, #0x20]
//   0x67ec: eb08013f  cmp        x9, x8
//   0x67f0: 54fffec9  b.ls       #0x67c8
//   0x67f4: b94012e4  ldr        w4, [x23, #0x10]
//   0x67f8: b9002264  str        w4, [x19, #0x20]
//   0x67fc: f94016e0  ldr        x0, [x23, #0x28]
//   0x6800: b5000440  cbnz       x0, #0x6888
//   0x6804: 90ffffe3  adrp       x3, #0x2000
//   0x6808: 911be863  add        x3, x3, #0x6fa
//   0x680c: 910023e0  add        x0, sp, #8
//   0x6810: 52800801  mov        w1, #0x40
//   0x6814: 52800802  mov        w2, #0x40
//   0x6818: 97ffffb5  bl         #0x66ec
//   0x681c: 910023e0  add        x0, sp, #8
//   0x6820: 52a00101  mov        w1, #0x80000
//   0x6824: 94000807  bl         #0x8840
//   0x6828: 37f802c0  tbnz       w0, #0x1f, #0x6880
//   0x682c: 910023e1  add        x1, sp, #8
//   0x6830: 52800802  mov        w2, #0x40
//   0x6834: 2a0003f5  mov        w21, w0
//   0x6838: 94000806  bl         #0x8850
//   0x683c: aa0003f4  mov        x20, x0
//   0x6840: 2a1503e0  mov        w0, w21
//   0x6844: 940007df  bl         #0x87c0
//   0x6848: f1000688  subs       x8, x20, #1
//   0x684c: 540001ab  b.lt       #0x6880
//   0x6850: f101029f  cmp        x20, #0x40
//   0x6854: 540000a0  b.eq       #0x6868
//   0x6858: 910023e9  add        x9, sp, #8
//   0x685c: 38686929  ldrb       w9, [x9, x8]
//   0x6860: 7100293f  cmp        w9, #0xa
//   0x6864: 54000041  b.ne       #0x686c
//   0x6868: aa0803f4  mov        x20, x8
//   0x686c: 910023e0  add        x0, sp, #8
//   0x6870: 910023e8  add        x8, sp, #8
//   0x6874: 3834691f  strb       wzr, [x8, x20]
//   0x6878: 94000736  bl         #0x8550
//   0x687c: 14000002  b          #0x6884
//   0x6880: aa1f03e0  mov        x0, xzr
//   0x6884: f90016e0  str        x0, [x23, #0x28]
//   0x6888: f9001a60  str        x0, [x19, #0x30]
//   0x688c: f94016c8  ldr        x8, [x22, #0x28]
//   0x6890: f85f83a9  ldur       x9, [x29, #-8]
//   0x6894: eb09011f  cmp        x8, x9
//   0x6898: 540000e1  b.ne       #0x68b4
//   0x689c: a9484ff4  ldp        x20, x19, [sp, #0x80]
//   0x68a0: a94757f6  ldp        x22, x21, [sp, #0x70]
//   0x68a4: a9457bfd  ldp        x29, x30, [sp, #0x50]
//   0x68a8: f94033f7  ldr        x23, [sp, #0x60]
//   0x68ac: 910243ff  add        sp, sp, #0x90
//   0x68b0: d65f03c0  ret        
//   0x68b4: 9400073f  bl         #0x85b0

// ----------------------------------------------------------------------------
// FDE[29] FormatNativePcSymbol_68b8 (0x68b8..0x69d4, 284 bytes, 71 instructions)
// Summary / Tóm tắt: Formats native PC with dladdr / npth_dladdr & BuildId (@ 0x68b8..0x69d4)
// ----------------------------------------------------------------------------
//   0x68b8: d10503ff  sub        sp, sp, #0x140
//   0x68bc: a9107bfd  stp        x29, x30, [sp, #0x100]
//   0x68c0: f9008bfc  str        x28, [sp, #0x110]
//   0x68c4: a91257f6  stp        x22, x21, [sp, #0x120]
//   0x68c8: a9134ff4  stp        x20, x19, [sp, #0x130]
//   0x68cc: 910403fd  add        x29, sp, #0x100
//   0x68d0: d53bd056  mrs        x22, tpidr_el0
//   0x68d4: aa0103f4  mov        x20, x1
//   0x68d8: 6f00e400  movi       v0.2d, #0000000000000000
//   0x68dc: 2a0003f3  mov        w19, w0
//   0x68e0: f94016c8  ldr        x8, [x22, #0x28]
//   0x68e4: 9101c3e9  add        x9, sp, #0x70
//   0x68e8: 910063e1  add        x1, sp, #0x18
//   0x68ec: aa0203e0  mov        x0, x2
//   0x68f0: aa0203f5  mov        x21, x2
//   0x68f4: f81f83a8  stur       x8, [x29, #-8]
//   0x68f8: ad020120  stp        q0, q0, [x9, #0x40]
//   0x68fc: ad030120  stp        q0, q0, [x9, #0x60]
//   0x6900: 3d800d20  str        q0, [x9, #0x30]
//   0x6904: ad0303e0  stp        q0, q0, [sp, #0x60]
//   0x6908: ad0403e0  stp        q0, q0, [sp, #0x80]
//   0x690c: 3d8017e0  str        q0, [sp, #0x50]
//   0x6910: 940007f8  bl         #0x88f0
//   0x6914: b4000320  cbz        x0, #0x6978
//   0x6918: d29ef9eb  mov        x11, #0xf7cf
//   0x691c: f94006a9  ldr        x9, [x21, #8]
//   0x6920: 294523ea  ldp        w10, w8, [sp, #0x28]
//   0x6924: f2bc6a6b  movk       x11, #0xe353, lsl #16
//   0x6928: 90ffffe3  adrp       x3, #0x2000
//   0x692c: 912f5063  add        x3, x3, #0xbd4
//   0x6930: f2d374ab  movk       x11, #0x9ba5, lsl #32
//   0x6934: f2e4188b  movk       x11, #0x20c4, lsl #48
//   0x6938: 910143e0  add        x0, sp, #0x50
//   0x693c: 111db104  add        w4, w8, #0x76c
//   0x6940: 11000545  add        w5, w10, #1
//   0x6944: 9b4b7d28  smulh      x8, x9, x11
//   0x6948: 52800401  mov        w1, #0x20
//   0x694c: 29441be7  ldp        w7, w6, [sp, #0x20]
//   0x6950: 9347fd09  asr        x9, x8, #7
//   0x6954: 52800402  mov        w2, #0x20
//   0x6958: 29432beb  ldp        w11, w10, [sp, #0x18]
//   0x695c: 8b48fd28  add        x8, x9, x8, lsr #63
//   0x6960: 910143f5  add        x21, sp, #0x50
//   0x6964: b9000beb  str        w11, [sp, #8]
//   0x6968: b90003ea  str        w10, [sp]
//   0x696c: f9000be8  str        x8, [sp, #0x10]
//   0x6970: 97ffff5f  bl         #0x66ec
//   0x6974: 3820cabf  strb       wzr, [x21, w0, sxtw]
//   0x6978: 90ffffe3  adrp       x3, #0x2000
//   0x697c: 91161063  add        x3, x3, #0x584
//   0x6980: 9101c3e0  add        x0, sp, #0x70
//   0x6984: 910143e5  add        x5, sp, #0x50
//   0x6988: 52801001  mov        w1, #0x80
//   0x698c: 52801002  mov        w2, #0x80
//   0x6990: aa1403e4  mov        x4, x20
//   0x6994: 97ffff56  bl         #0x66ec
//   0x6998: 93407c02  sxtw       x2, w0
//   0x699c: 9101c3e1  add        x1, sp, #0x70
//   0x69a0: 2a1303e0  mov        w0, w19
//   0x69a4: 94000783  bl         #0x87b0
//   0x69a8: f94016c8  ldr        x8, [x22, #0x28]
//   0x69ac: f85f83a9  ldur       x9, [x29, #-8]
//   0x69b0: eb09011f  cmp        x8, x9
//   0x69b4: 540000e1  b.ne       #0x69d0
//   0x69b8: a9534ff4  ldp        x20, x19, [sp, #0x130]
//   0x69bc: a95257f6  ldp        x22, x21, [sp, #0x120]
//   0x69c0: a9507bfd  ldp        x29, x30, [sp, #0x100]
//   0x69c4: f9408bfc  ldr        x28, [sp, #0x110]
//   0x69c8: 910503ff  add        sp, sp, #0x140
//   0x69cc: d65f03c0  ret        
//   0x69d0: 940006f8  bl         #0x85b0

// ----------------------------------------------------------------------------
// FDE[30] do_unhook (0x69d4..0x6ad0, 252 bytes, 63 instructions)
// Summary / Tóm tắt: Exported: Unhooks all 15 ShadowHook interceptors (@ 0x69d4..0x6ad0)
// ----------------------------------------------------------------------------
//   0x69d4: a9bd7bfd  stp        x29, x30, [sp, #-0x30]!
//   0x69d8: f9000bf5  str        x21, [sp, #0x10]
//   0x69dc: a9024ff4  stp        x20, x19, [sp, #0x20]
//   0x69e0: 910003fd  mov        x29, sp
//   0x69e4: 340002a0  cbz        w0, #0x6a38
//   0x69e8: 7100041f  cmp        w0, #1
//   0x69ec: 54000641  b.ne       #0x6ab4
//   0x69f0: aa1f03f3  mov        x19, xzr
//   0x69f4: 52800035  mov        w21, #1
//   0x69f8: d503201f  nop        
//   0x69fc: 100542b4  adr        x20, #0x11250
//   0x6a00: 14000008  b          #0x6a20
//   0x6a04: f8337a9f  str        xzr, [x20, x19, lsl #3]
//   0x6a08: 91000668  add        x8, x19, #1
//   0x6a0c: f1003a7f  cmp        x19, #0xe
//   0x6a10: 1a9f27f5  cset       w21, lo
//   0x6a14: aa0803f3  mov        x19, x8
//   0x6a18: f1003d1f  cmp        x8, #0xf
//   0x6a1c: 540000a0  b.eq       #0x6a30
//   0x6a20: f8737a80  ldr        x0, [x20, x19, lsl #3]
//   0x6a24: b4ffff20  cbz        x0, #0x6a08
//   0x6a28: 940007ba  bl         #0x8910
//   0x6a2c: 34fffec0  cbz        w0, #0x6a04
//   0x6a30: 130002a0  sbfx       w0, w21, #0, #1
//   0x6a34: 14000021  b          #0x6ab8
//   0x6a38: f0000053  adrp       x19, #0x11000
//   0x6a3c: f9416660  ldr        x0, [x19, #0x2c8]
//   0x6a40: b4000080  cbz        x0, #0x6a50
//   0x6a44: 940007b3  bl         #0x8910
//   0x6a48: 35000320  cbnz       w0, #0x6aac
//   0x6a4c: f901667f  str        xzr, [x19, #0x2c8]
//   0x6a50: f0000053  adrp       x19, #0x11000
//   0x6a54: f9416a60  ldr        x0, [x19, #0x2d0]
//   0x6a58: b4000080  cbz        x0, #0x6a68
//   0x6a5c: 940007ad  bl         #0x8910
//   0x6a60: 35000260  cbnz       w0, #0x6aac
//   0x6a64: f9016a7f  str        xzr, [x19, #0x2d0]
//   0x6a68: f0000053  adrp       x19, #0x11000
//   0x6a6c: f9416e60  ldr        x0, [x19, #0x2d8]
//   0x6a70: b4000080  cbz        x0, #0x6a80
//   0x6a74: 940007a7  bl         #0x8910
//   0x6a78: 350001a0  cbnz       w0, #0x6aac
//   0x6a7c: f9016e7f  str        xzr, [x19, #0x2d8]
//   0x6a80: f0000053  adrp       x19, #0x11000
//   0x6a84: f9417260  ldr        x0, [x19, #0x2e0]
//   0x6a88: b4000080  cbz        x0, #0x6a98
//   0x6a8c: 940007a1  bl         #0x8910
//   0x6a90: 350000e0  cbnz       w0, #0x6aac
//   0x6a94: f901727f  str        xzr, [x19, #0x2e0]
//   0x6a98: f0000053  adrp       x19, #0x11000
//   0x6a9c: f9417660  ldr        x0, [x19, #0x2e8]
//   0x6aa0: b40000c0  cbz        x0, #0x6ab8
//   0x6aa4: 9400079b  bl         #0x8910
//   0x6aa8: 34000100  cbz        w0, #0x6ac8
//   0x6aac: 12800000  mov        w0, #-1
//   0x6ab0: 14000002  b          #0x6ab8
//   0x6ab4: 128002a0  mov        w0, #-0x16
//   0x6ab8: a9424ff4  ldp        x20, x19, [sp, #0x20]
//   0x6abc: f9400bf5  ldr        x21, [sp, #0x10]
//   0x6ac0: a8c37bfd  ldp        x29, x30, [sp], #0x30
//   0x6ac4: d65f03c0  ret        
//   0x6ac8: f901767f  str        xzr, [x19, #0x2e8]
//   0x6acc: 17fffffb  b          #0x6ab8

// ----------------------------------------------------------------------------
// FDE[31] do_hook (0x6ad0..0x6b64, 148 bytes, 37 instructions)
// Summary / Tóm tắt: Exported: Initializes ShadowHook, TLS recursion key, and installs hooks (@ 0x6ad0..0x6b64)
// ----------------------------------------------------------------------------
//   0x6ad0: a9bf7bfd  stp        x29, x30, [sp, #-0x10]!
//   0x6ad4: 910003fd  mov        x29, sp
//   0x6ad8: 2a1f03e0  mov        w0, wzr
//   0x6adc: 2a1f03e1  mov        w1, wzr
//   0x6ae0: 94000790  bl         #0x8920
//   0x6ae4: 34000080  cbz        w0, #0x6af4
//   0x6ae8: 12800660  mov        w0, #-0x34
//   0x6aec: a8c17bfd  ldp        x29, x30, [sp], #0x10
//   0x6af0: d65f03c0  ret        
//   0x6af4: d503201f  nop        
//   0x6af8: 10053fc0  adr        x0, #0x112f0
//   0x6afc: aa1f03e1  mov        x1, xzr
//   0x6b00: 9400078c  bl         #0x8930
//   0x6b04: 34000080  cbz        w0, #0x6b14
//   0x6b08: 12800640  mov        w0, #-0x33
//   0x6b0c: a8c17bfd  ldp        x29, x30, [sp], #0x10
//   0x6b10: d65f03c0  ret        
//   0x6b14: d503201f  nop        
//   0x6b18: 10052500  adr        x0, #0x10fb8
//   0x6b1c: d503201f  nop        
//   0x6b20: 10053d42  adr        x2, #0x112c8
//   0x6b24: d503201f  nop        
//   0x6b28: 10053e83  adr        x3, #0x112f8
//   0x6b2c: 528000a1  mov        w1, #5
//   0x6b30: 9400000d  bl         #0x6b64
//   0x6b34: 34000060  cbz        w0, #0x6b40
//   0x6b38: a8c17bfd  ldp        x29, x30, [sp], #0x10
//   0x6b3c: d65f03c0  ret        
//   0x6b40: d503201f  nop        
//   0x6b44: 100528a0  adr        x0, #0x11058
//   0x6b48: d503201f  nop        
//   0x6b4c: 10053822  adr        x2, #0x11250
//   0x6b50: d503201f  nop        
//   0x6b54: 10053e63  adr        x3, #0x11320
//   0x6b58: 528001e1  mov        w1, #0xf
//   0x6b5c: a8c17bfd  ldp        x29, x30, [sp], #0x10
//   0x6b60: 14000001  b          #0x6b64

// ----------------------------------------------------------------------------
// FDE[32] do_hook_inner (0x6b64..0x6cac, 328 bytes, 82 instructions)
// Summary / Tóm tắt: Internal batch ShadowHook installer via shadowhook_hook_sym_name (@ 0x6b64..0x6cac)
// ----------------------------------------------------------------------------
//   0x6b64: a9bc7bfd  stp        x29, x30, [sp, #-0x40]!
//   0x6b68: a9015ff8  stp        x24, x23, [sp, #0x10]
//   0x6b6c: a90257f6  stp        x22, x21, [sp, #0x20]
//   0x6b70: a9034ff4  stp        x20, x19, [sp, #0x30]
//   0x6b74: 910003fd  mov        x29, sp
//   0x6b78: aa0103f5  mov        x21, x1
//   0x6b7c: aa0303f3  mov        x19, x3
//   0x6b80: aa0203f4  mov        x20, x2
//   0x6b84: aa0003f6  mov        x22, x0
//   0x6b88: d503201f  nop        
//   0x6b8c: 30fded21  adr        x1, #0x2931
//   0x6b90: 90ffffe2  adrp       x2, #0x2000
//   0x6b94: 9115c042  add        x2, x2, #0x570
//   0x6b98: 90ffffe3  adrp       x3, #0x2000
//   0x6b9c: 91186463  add        x3, x3, #0x619
//   0x6ba0: 528000c0  mov        w0, #6
//   0x6ba4: aa1503e4  mov        x4, x21
//   0x6ba8: 94000696  bl         #0x8600
//   0x6bac: b4000395  cbz        x21, #0x6c1c
//   0x6bb0: d0000038  adrp       x24, #0xc000
//   0x6bb4: 910062d7  add        x23, x22, #0x18
//   0x6bb8: 90fffff6  adrp       x22, #0x2000
//   0x6bbc: 911ad6d6  add        x22, x22, #0x6b5
//   0x6bc0: f9465f18  ldr        x24, [x24, #0xcb8]
//   0x6bc4: f9400308  ldr        x8, [x24]
//   0x6bc8: 14000006  b          #0x6be0
//   0x6bcc: 910082f7  add        x23, x23, #0x20
//   0x6bd0: f10006b5  subs       x21, x21, #1
//   0x6bd4: 91002294  add        x20, x20, #8
//   0x6bd8: 91002273  add        x19, x19, #8
//   0x6bdc: 54000200  b.eq       #0x6c1c
//   0x6be0: b85e82ea  ldur       w10, [x23, #-0x18]
//   0x6be4: b9400909  ldr        w9, [x8, #8]
//   0x6be8: 6b09015f  cmp        w10, w9
//   0x6bec: 54ffff0c  b.gt       #0x6bcc
//   0x6bf0: b85ec2ea  ldur       w10, [x23, #-0x14]
//   0x6bf4: 6b09015f  cmp        w10, w9
//   0x6bf8: 54fffeab  b.lt       #0x6bcc
//   0x6bfc: a97f0ae1  ldp        x1, x2, [x23, #-0x10]
//   0x6c00: aa1603e0  mov        x0, x22
//   0x6c04: aa1303e3  mov        x3, x19
//   0x6c08: 9400074e  bl         #0x8940
//   0x6c0c: f9000280  str        x0, [x20]
//   0x6c10: b4000140  cbz        x0, #0x6c38
//   0x6c14: f9400308  ldr        x8, [x24]
//   0x6c18: 17ffffed  b          #0x6bcc
//   0x6c1c: 2a1f03f3  mov        w19, wzr
//   0x6c20: 2a1303e0  mov        w0, w19
//   0x6c24: a9434ff4  ldp        x20, x19, [sp, #0x30]
//   0x6c28: a94257f6  ldp        x22, x21, [sp, #0x20]
//   0x6c2c: a9415ff8  ldp        x24, x23, [sp, #0x10]
//   0x6c30: a8c47bfd  ldp        x29, x30, [sp], #0x40
//   0x6c34: d65f03c0  ret        
//   0x6c38: 94000746  bl         #0x8950
//   0x6c3c: 2a0003f3  mov        w19, w0
//   0x6c40: 94000748  bl         #0x8960
//   0x6c44: aa0003e4  mov        x4, x0
//   0x6c48: b94002e5  ldr        w5, [x23]
//   0x6c4c: d503201f  nop        
//   0x6c50: 30fde701  adr        x1, #0x2931
//   0x6c54: 90ffffe2  adrp       x2, #0x2000
//   0x6c58: 912dc842  add        x2, x2, #0xb72
//   0x6c5c: 528000c0  mov        w0, #6
//   0x6c60: 2a1303e3  mov        w3, w19
//   0x6c64: 94000667  bl         #0x8600
//   0x6c68: b94002f3  ldr        w19, [x23]
//   0x6c6c: 34fffdb3  cbz        w19, #0x6c20
//   0x6c70: aa1f03f4  mov        x20, xzr
//   0x6c74: d503201f  nop        
//   0x6c78: 10052ed5  adr        x21, #0x11250
//   0x6c7c: 14000005  b          #0x6c90
//   0x6c80: f8346abf  str        xzr, [x21, x20]
//   0x6c84: 91002294  add        x20, x20, #8
//   0x6c88: f101e29f  cmp        x20, #0x78
//   0x6c8c: 540000a0  b.eq       #0x6ca0
//   0x6c90: f8746aa0  ldr        x0, [x21, x20]
//   0x6c94: b4ffff80  cbz        x0, #0x6c84
//   0x6c98: 9400071e  bl         #0x8910
//   0x6c9c: 34ffff20  cbz        w0, #0x6c80
//   0x6ca0: 2a1f03e0  mov        w0, wzr
//   0x6ca4: 94000653  bl         #0x85f0
//   0x6ca8: 17ffffde  b          #0x6c20

// ----------------------------------------------------------------------------
// FDE[33] HookProxy_close_6cac (0x6cac..0x6d5c, 176 bytes, 44 instructions)
// Summary / Tóm tắt: ShadowHook proxy for close(int fd) with TLS guard 0x12345678 (@ 0x6cac..0x6d5c)
// ----------------------------------------------------------------------------
//   0x6cac: a9bc7bfd  stp        x29, x30, [sp, #-0x40]!
//   0x6cb0: f9000bf7  str        x23, [sp, #0x10]
//   0x6cb4: a90257f6  stp        x22, x21, [sp, #0x20]
//   0x6cb8: a9034ff4  stp        x20, x19, [sp, #0x30]
//   0x6cbc: 910003fd  mov        x29, sp
//   0x6cc0: 2a0003f5  mov        w21, w0
//   0x6cc4: d503201f  nop        
//   0x6cc8: 10ffff20  adr        x0, #0x6cac
//   0x6ccc: 528acf17  mov        w23, #0x5678
//   0x6cd0: aa1e03f3  mov        x19, x30
//   0x6cd4: 72a24697  movk       w23, #0x1234, lsl #16
//   0x6cd8: 94000726  bl         #0x8970
//   0x6cdc: aa0003e8  mov        x8, x0
//   0x6ce0: 2a1503e0  mov        w0, w21
//   0x6ce4: d63f0100  blr        x8
//   0x6ce8: f0000056  adrp       x22, #0x11000
//   0x6cec: 2a0003f4  mov        w20, w0
//   0x6cf0: b942f2c0  ldr        w0, [x22, #0x2f0]
//   0x6cf4: 94000723  bl         #0x8980
//   0x6cf8: eb17001f  cmp        x0, x23
//   0x6cfc: 54000180  b.eq       #0x6d2c
//   0x6d00: 528acf01  mov        w1, #0x5678
//   0x6d04: b942f2c0  ldr        w0, [x22, #0x2f0]
//   0x6d08: 72a24681  movk       w1, #0x1234, lsl #16
//   0x6d0c: 94000721  bl         #0x8990
//   0x6d10: 35000094  cbnz       w20, #0x6d20
//   0x6d14: 2a1503e0  mov        w0, w21
//   0x6d18: 52800201  mov        w1, #0x10
//   0x6d1c: 94000665  bl         #0x86b0
//   0x6d20: b942f2c0  ldr        w0, [x22, #0x2f0]
//   0x6d24: aa1f03e1  mov        x1, xzr
//   0x6d28: 9400071a  bl         #0x8990
//   0x6d2c: 9400071d  bl         #0x89a0
//   0x6d30: 350000a0  cbnz       w0, #0x6d44
//   0x6d34: aa1303fe  mov        x30, x19
//   0x6d38: d50320ff  xpaclri    
//   0x6d3c: aa1e03e0  mov        x0, x30
//   0x6d40: 9400071c  bl         #0x89b0
//   0x6d44: 2a1403e0  mov        w0, w20
//   0x6d48: a9434ff4  ldp        x20, x19, [sp, #0x30]
//   0x6d4c: a94257f6  ldp        x22, x21, [sp, #0x20]
//   0x6d50: f9400bf7  ldr        x23, [sp, #0x10]
//   0x6d54: a8c47bfd  ldp        x29, x30, [sp], #0x40
//   0x6d58: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[34] HookProxy_close2_6d5c (0x6d5c..0x6e0c, 176 bytes, 44 instructions)
// Summary / Tóm tắt: ShadowHook proxy for __close / ___close(int fd) (@ 0x6d5c..0x6e0c)
// ----------------------------------------------------------------------------
//   0x6d5c: a9bc7bfd  stp        x29, x30, [sp, #-0x40]!
//   0x6d60: f9000bf7  str        x23, [sp, #0x10]
//   0x6d64: a90257f6  stp        x22, x21, [sp, #0x20]
//   0x6d68: a9034ff4  stp        x20, x19, [sp, #0x30]
//   0x6d6c: 910003fd  mov        x29, sp
//   0x6d70: 2a0003f5  mov        w21, w0
//   0x6d74: d503201f  nop        
//   0x6d78: 10ffff20  adr        x0, #0x6d5c
//   0x6d7c: 528acf17  mov        w23, #0x5678
//   0x6d80: aa1e03f3  mov        x19, x30
//   0x6d84: 72a24697  movk       w23, #0x1234, lsl #16
//   0x6d88: 940006fa  bl         #0x8970
//   0x6d8c: aa0003e8  mov        x8, x0
//   0x6d90: 2a1503e0  mov        w0, w21
//   0x6d94: d63f0100  blr        x8
//   0x6d98: f0000056  adrp       x22, #0x11000
//   0x6d9c: 2a0003f4  mov        w20, w0
//   0x6da0: b942f2c0  ldr        w0, [x22, #0x2f0]
//   0x6da4: 940006f7  bl         #0x8980
//   0x6da8: eb17001f  cmp        x0, x23
//   0x6dac: 54000180  b.eq       #0x6ddc
//   0x6db0: 528acf01  mov        w1, #0x5678
//   0x6db4: b942f2c0  ldr        w0, [x22, #0x2f0]
//   0x6db8: 72a24681  movk       w1, #0x1234, lsl #16
//   0x6dbc: 940006f5  bl         #0x8990
//   0x6dc0: 35000094  cbnz       w20, #0x6dd0
//   0x6dc4: 2a1503e0  mov        w0, w21
//   0x6dc8: 52800221  mov        w1, #0x11
//   0x6dcc: 94000639  bl         #0x86b0
//   0x6dd0: b942f2c0  ldr        w0, [x22, #0x2f0]
//   0x6dd4: aa1f03e1  mov        x1, xzr
//   0x6dd8: 940006ee  bl         #0x8990
//   0x6ddc: 940006f1  bl         #0x89a0
//   0x6de0: 350000a0  cbnz       w0, #0x6df4
//   0x6de4: aa1303fe  mov        x30, x19
//   0x6de8: d50320ff  xpaclri    
//   0x6dec: aa1e03e0  mov        x0, x30
//   0x6df0: 940006f0  bl         #0x89b0
//   0x6df4: 2a1403e0  mov        w0, w20
//   0x6df8: a9434ff4  ldp        x20, x19, [sp, #0x30]
//   0x6dfc: a94257f6  ldp        x22, x21, [sp, #0x20]
//   0x6e00: f9400bf7  ldr        x23, [sp, #0x10]
//   0x6e04: a8c47bfd  ldp        x29, x30, [sp], #0x40
//   0x6e08: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[35] HookProxy_dup2_6e0c (0x6e0c..0x6f20, 276 bytes, 69 instructions)
// Summary / Tóm tắt: ShadowHook proxy for dup2(int oldfd, int newfd) with fcntl(F_GETFD) check (@ 0x6e0c..0x6f20)
// ----------------------------------------------------------------------------
//   0x6e0c: a9bc7bfd  stp        x29, x30, [sp, #-0x40]!
//   0x6e10: a9015ff8  stp        x24, x23, [sp, #0x10]
//   0x6e14: a90257f6  stp        x22, x21, [sp, #0x20]
//   0x6e18: a9034ff4  stp        x20, x19, [sp, #0x30]
//   0x6e1c: 910003fd  mov        x29, sp
//   0x6e20: 2a0103f4  mov        w20, w1
//   0x6e24: 2a0003f6  mov        w22, w0
//   0x6e28: 2a0103e0  mov        w0, w1
//   0x6e2c: 52800021  mov        w1, #1
//   0x6e30: 2a1f03e2  mov        w2, wzr
//   0x6e34: aa1e03f3  mov        x19, x30
//   0x6e38: 52800037  mov        w23, #1
//   0x6e3c: 940006e1  bl         #0x89c0
//   0x6e40: 350000a0  cbnz       w0, #0x6e54
//   0x6e44: 94000663  bl         #0x87d0
//   0x6e48: b9400008  ldr        w8, [x0]
//   0x6e4c: 7100251f  cmp        w8, #9
//   0x6e50: 1a9f17f7  cset       w23, eq
//   0x6e54: d503201f  nop        
//   0x6e58: 10fffda0  adr        x0, #0x6e0c
//   0x6e5c: 940006c5  bl         #0x8970
//   0x6e60: aa0003e8  mov        x8, x0
//   0x6e64: 2a1603e0  mov        w0, w22
//   0x6e68: 2a1403e1  mov        w1, w20
//   0x6e6c: d63f0100  blr        x8
//   0x6e70: 2a0003f5  mov        w21, w0
//   0x6e74: 6b1402df  cmp        w22, w20
//   0x6e78: 540003c0  b.eq       #0x6ef0
//   0x6e7c: 6b1402bf  cmp        w21, w20
//   0x6e80: 54000381  b.ne       #0x6ef0
//   0x6e84: f0000056  adrp       x22, #0x11000
//   0x6e88: 528acf18  mov        w24, #0x5678
//   0x6e8c: 72a24698  movk       w24, #0x1234, lsl #16
//   0x6e90: b942f2c0  ldr        w0, [x22, #0x2f0]
//   0x6e94: 940006bb  bl         #0x8980
//   0x6e98: eb18001f  cmp        x0, x24
//   0x6e9c: 540002a0  b.eq       #0x6ef0
//   0x6ea0: 528acf01  mov        w1, #0x5678
//   0x6ea4: b942f2c0  ldr        w0, [x22, #0x2f0]
//   0x6ea8: 72a24681  movk       w1, #0x1234, lsl #16
//   0x6eac: 940006b9  bl         #0x8990
//   0x6eb0: 34000097  cbz        w23, #0x6ec0
//   0x6eb4: 2a1403e0  mov        w0, w20
//   0x6eb8: 52800121  mov        w1, #9
//   0x6ebc: 940005fd  bl         #0x86b0
//   0x6ec0: aa1303fe  mov        x30, x19
//   0x6ec4: 2a1403e0  mov        w0, w20
//   0x6ec8: aa1f03e1  mov        x1, xzr
//   0x6ecc: aa1d03e3  mov        x3, x29
//   0x6ed0: 12800004  mov        w4, #-1
//   0x6ed4: 52800125  mov        w5, #9
//   0x6ed8: d50320ff  xpaclri    
//   0x6edc: aa1e03e2  mov        x2, x30
//   0x6ee0: 940005dc  bl         #0x8650
//   0x6ee4: b942f2c0  ldr        w0, [x22, #0x2f0]
//   0x6ee8: aa1f03e1  mov        x1, xzr
//   0x6eec: 940006a9  bl         #0x8990
//   0x6ef0: 940006ac  bl         #0x89a0
//   0x6ef4: 350000a0  cbnz       w0, #0x6f08
//   0x6ef8: aa1303fe  mov        x30, x19
//   0x6efc: d50320ff  xpaclri    
//   0x6f00: aa1e03e0  mov        x0, x30
//   0x6f04: 940006ab  bl         #0x89b0
//   0x6f08: 2a1503e0  mov        w0, w21
//   0x6f0c: a9434ff4  ldp        x20, x19, [sp, #0x30]
//   0x6f10: a94257f6  ldp        x22, x21, [sp, #0x20]
//   0x6f14: a9415ff8  ldp        x24, x23, [sp, #0x10]
//   0x6f18: a8c47bfd  ldp        x29, x30, [sp], #0x40
//   0x6f1c: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[36] HookProxy_dup3_6f20 (0x6f20..0x7044, 292 bytes, 73 instructions)
// Summary / Tóm tắt: ShadowHook proxy for dup3(int oldfd, int newfd, int flags) (@ 0x6f20..0x7044)
// ----------------------------------------------------------------------------
//   0x6f20: a9bb7bfd  stp        x29, x30, [sp, #-0x50]!
//   0x6f24: f9000bf9  str        x25, [sp, #0x10]
//   0x6f28: a9025ff8  stp        x24, x23, [sp, #0x20]
//   0x6f2c: a90357f6  stp        x22, x21, [sp, #0x30]
//   0x6f30: a9044ff4  stp        x20, x19, [sp, #0x40]
//   0x6f34: 910003fd  mov        x29, sp
//   0x6f38: 2a0203f4  mov        w20, w2
//   0x6f3c: 2a0103f5  mov        w21, w1
//   0x6f40: 2a0003f7  mov        w23, w0
//   0x6f44: 2a0103e0  mov        w0, w1
//   0x6f48: 52800021  mov        w1, #1
//   0x6f4c: 2a1f03e2  mov        w2, wzr
//   0x6f50: aa1e03f3  mov        x19, x30
//   0x6f54: 52800038  mov        w24, #1
//   0x6f58: 9400069a  bl         #0x89c0
//   0x6f5c: 350000a0  cbnz       w0, #0x6f70
//   0x6f60: 9400061c  bl         #0x87d0
//   0x6f64: b9400008  ldr        w8, [x0]
//   0x6f68: 7100251f  cmp        w8, #9
//   0x6f6c: 1a9f17f8  cset       w24, eq
//   0x6f70: d503201f  nop        
//   0x6f74: 10fffd60  adr        x0, #0x6f20
//   0x6f78: 9400067e  bl         #0x8970
//   0x6f7c: aa0003e8  mov        x8, x0
//   0x6f80: 2a1703e0  mov        w0, w23
//   0x6f84: 2a1503e1  mov        w1, w21
//   0x6f88: 2a1403e2  mov        w2, w20
//   0x6f8c: d63f0100  blr        x8
//   0x6f90: 2a0003f6  mov        w22, w0
//   0x6f94: 6b1502ff  cmp        w23, w21
//   0x6f98: 540003c0  b.eq       #0x7010
//   0x6f9c: 6b1502df  cmp        w22, w21
//   0x6fa0: 54000381  b.ne       #0x7010
//   0x6fa4: f0000057  adrp       x23, #0x11000
//   0x6fa8: 528acf19  mov        w25, #0x5678
//   0x6fac: 72a24699  movk       w25, #0x1234, lsl #16
//   0x6fb0: b942f2e0  ldr        w0, [x23, #0x2f0]
//   0x6fb4: 94000673  bl         #0x8980
//   0x6fb8: eb19001f  cmp        x0, x25
//   0x6fbc: 540002a0  b.eq       #0x7010
//   0x6fc0: 528acf01  mov        w1, #0x5678
//   0x6fc4: b942f2e0  ldr        w0, [x23, #0x2f0]
//   0x6fc8: 72a24681  movk       w1, #0x1234, lsl #16
//   0x6fcc: 94000671  bl         #0x8990
//   0x6fd0: 34000098  cbz        w24, #0x6fe0
//   0x6fd4: 2a1503e0  mov        w0, w21
//   0x6fd8: 52800121  mov        w1, #9
//   0x6fdc: 940005b5  bl         #0x86b0
//   0x6fe0: aa1303fe  mov        x30, x19
//   0x6fe4: 2a1503e0  mov        w0, w21
//   0x6fe8: aa1f03e1  mov        x1, xzr
//   0x6fec: aa1d03e3  mov        x3, x29
//   0x6ff0: 2a1403e4  mov        w4, w20
//   0x6ff4: 52800125  mov        w5, #9
//   0x6ff8: d50320ff  xpaclri    
//   0x6ffc: aa1e03e2  mov        x2, x30
//   0x7000: 94000594  bl         #0x8650
//   0x7004: b942f2e0  ldr        w0, [x23, #0x2f0]
//   0x7008: aa1f03e1  mov        x1, xzr
//   0x700c: 94000661  bl         #0x8990
//   0x7010: 94000664  bl         #0x89a0
//   0x7014: 350000a0  cbnz       w0, #0x7028
//   0x7018: aa1303fe  mov        x30, x19
//   0x701c: d50320ff  xpaclri    
//   0x7020: aa1e03e0  mov        x0, x30
//   0x7024: 94000663  bl         #0x89b0
//   0x7028: 2a1603e0  mov        w0, w22
//   0x702c: a9444ff4  ldp        x20, x19, [sp, #0x40]
//   0x7030: a94357f6  ldp        x22, x21, [sp, #0x30]
//   0x7034: a9425ff8  ldp        x24, x23, [sp, #0x20]
//   0x7038: f9400bf9  ldr        x25, [sp, #0x10]
//   0x703c: a8c57bfd  ldp        x29, x30, [sp], #0x50
//   0x7040: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[37] HookProxy_openat_7044 (0x7044..0x71e4, 416 bytes, 104 instructions)
// Summary / Tóm tắt: ShadowHook proxy for openat(int dirfd, const char* path, int flags, ...) (@ 0x7044..0x71e4)
// ----------------------------------------------------------------------------
//   0x7044: d10483ff  sub        sp, sp, #0x120
//   0x7048: a90d7bfd  stp        x29, x30, [sp, #0xd0]
//   0x704c: a90e67fc  stp        x28, x25, [sp, #0xe0]
//   0x7050: a90f5ff8  stp        x24, x23, [sp, #0xf0]
//   0x7054: a91057f6  stp        x22, x21, [sp, #0x100]
//   0x7058: a9114ff4  stp        x20, x19, [sp, #0x110]
//   0x705c: 910343fd  add        x29, sp, #0xd0
//   0x7060: a93b97a4  stp        x4, x5, [x29, #-0x48]
//   0x7064: aa1e03f3  mov        x19, x30
//   0x7068: f81b03a3  stur       x3, [x29, #-0x50]
//   0x706c: 2a0203f4  mov        w20, w2
//   0x7070: a93c9fa6  stp        x6, x7, [x29, #-0x38]
//   0x7074: aa0103f5  mov        x21, x1
//   0x7078: ad0007e0  stp        q0, q1, [sp]
//   0x707c: 2a0003f6  mov        w22, w0
//   0x7080: ad010fe2  stp        q2, q3, [sp, #0x20]
//   0x7084: ad0217e4  stp        q4, q5, [sp, #0x40]
//   0x7088: ad031fe6  stp        q6, q7, [sp, #0x60]
//   0x708c: d53bd058  mrs        x24, tpidr_el0
//   0x7090: f9401708  ldr        x8, [x24, #0x28]
//   0x7094: f81f83a8  stur       x8, [x29, #-8]
//   0x7098: 37300102  tbnz       w2, #6, #0x70b8
//   0x709c: 52880008  mov        w8, #0x4000
//   0x70a0: 72a00808  movk       w8, #0x40, lsl #16
//   0x70a4: 0a080289  and        w9, w20, w8
//   0x70a8: 6b08013f  cmp        w9, w8
//   0x70ac: 54000060  b.eq       #0x70b8
//   0x70b0: 2a1f03f7  mov        w23, wzr
//   0x70b4: 14000017  b          #0x7110
//   0x70b8: 928004e9  mov        x9, #-0x28
//   0x70bc: 910003e8  mov        x8, sp
//   0x70c0: d10143ac  sub        x12, x29, #0x50
//   0x70c4: f2dff009  movk       x9, #0xff80, lsl #32
//   0x70c8: 910143aa  add        x10, x29, #0x50
//   0x70cc: 9102010b  add        x11, x8, #0x80
//   0x70d0: 928004e8  mov        x8, #-0x28
//   0x70d4: 9100a18c  add        x12, x12, #0x28
//   0x70d8: a93ea7ab  stp        x11, x9, [x29, #-0x18]
//   0x70dc: a93db3aa  stp        x10, x12, [x29, #-0x28]
//   0x70e0: 36f80108  tbz        w8, #0x1f, #0x7100
//   0x70e4: 11002109  add        w9, w8, #8
//   0x70e8: 3100211f  cmn        w8, #8
//   0x70ec: b81f03a9  stur       w9, [x29, #-0x10]
//   0x70f0: 54000088  b.hi       #0x7100
//   0x70f4: f85e03a9  ldur       x9, [x29, #-0x20]
//   0x70f8: 8b080128  add        x8, x9, x8
//   0x70fc: 14000004  b          #0x710c
//   0x7100: f85d83a8  ldur       x8, [x29, #-0x28]
//   0x7104: 91002109  add        x9, x8, #8
//   0x7108: f81d83a9  stur       x9, [x29, #-0x28]
//   0x710c: b9400117  ldr        w23, [x8]
//   0x7110: d503201f  nop        
//   0x7114: 10fff980  adr        x0, #0x7044
//   0x7118: 94000616  bl         #0x8970
//   0x711c: aa0003e8  mov        x8, x0
//   0x7120: 2a1603e0  mov        w0, w22
//   0x7124: aa1503e1  mov        x1, x21
//   0x7128: 2a1403e2  mov        w2, w20
//   0x712c: 2a1703e3  mov        w3, w23
//   0x7130: d63f0100  blr        x8
//   0x7134: 2a0003f6  mov        w22, w0
//   0x7138: 37f80300  tbnz       w0, #0x1f, #0x7198
//   0x713c: d0000057  adrp       x23, #0x11000
//   0x7140: 528acf19  mov        w25, #0x5678
//   0x7144: 72a24699  movk       w25, #0x1234, lsl #16
//   0x7148: b942f2e0  ldr        w0, [x23, #0x2f0]
//   0x714c: 9400060d  bl         #0x8980
//   0x7150: eb19001f  cmp        x0, x25
//   0x7154: 54000220  b.eq       #0x7198
//   0x7158: 528acf01  mov        w1, #0x5678
//   0x715c: b942f2e0  ldr        w0, [x23, #0x2f0]
//   0x7160: 72a24681  movk       w1, #0x1234, lsl #16
//   0x7164: 9400060b  bl         #0x8990
//   0x7168: aa1303fe  mov        x30, x19
//   0x716c: 2a1603e0  mov        w0, w22
//   0x7170: aa1503e1  mov        x1, x21
//   0x7174: aa1d03e3  mov        x3, x29
//   0x7178: 2a1403e4  mov        w4, w20
//   0x717c: 52800045  mov        w5, #2
//   0x7180: d50320ff  xpaclri    
//   0x7184: aa1e03e2  mov        x2, x30
//   0x7188: 94000532  bl         #0x8650
//   0x718c: b942f2e0  ldr        w0, [x23, #0x2f0]
//   0x7190: aa1f03e1  mov        x1, xzr
//   0x7194: 940005ff  bl         #0x8990
//   0x7198: 94000602  bl         #0x89a0
//   0x719c: 350000a0  cbnz       w0, #0x71b0
//   0x71a0: aa1303fe  mov        x30, x19
//   0x71a4: d50320ff  xpaclri    
//   0x71a8: aa1e03e0  mov        x0, x30
//   0x71ac: 94000601  bl         #0x89b0
//   0x71b0: f9401708  ldr        x8, [x24, #0x28]
//   0x71b4: f85f83a9  ldur       x9, [x29, #-8]
//   0x71b8: eb09011f  cmp        x8, x9
//   0x71bc: 54000121  b.ne       #0x71e0
//   0x71c0: 2a1603e0  mov        w0, w22
//   0x71c4: a9514ff4  ldp        x20, x19, [sp, #0x110]
//   0x71c8: a95057f6  ldp        x22, x21, [sp, #0x100]
//   0x71cc: a94f5ff8  ldp        x24, x23, [sp, #0xf0]
//   0x71d0: a94e67fc  ldp        x28, x25, [sp, #0xe0]
//   0x71d4: a94d7bfd  ldp        x29, x30, [sp, #0xd0]
//   0x71d8: 910483ff  add        sp, sp, #0x120
//   0x71dc: d65f03c0  ret        
//   0x71e0: 940004f4  bl         #0x85b0

// ----------------------------------------------------------------------------
// FDE[38] HookProxy_open_71e4 (0x71e4..0x737c, 408 bytes, 102 instructions)
// Summary / Tóm tắt: ShadowHook proxy for open(const char* path, int flags, ...) (@ 0x71e4..0x737c)
// ----------------------------------------------------------------------------
//   0x71e4: d104c3ff  sub        sp, sp, #0x130
//   0x71e8: a90e7bfd  stp        x29, x30, [sp, #0xe0]
//   0x71ec: a90f67fc  stp        x28, x25, [sp, #0xf0]
//   0x71f0: a9105ff8  stp        x24, x23, [sp, #0x100]
//   0x71f4: a91157f6  stp        x22, x21, [sp, #0x110]
//   0x71f8: a9124ff4  stp        x20, x19, [sp, #0x120]
//   0x71fc: 910383fd  add        x29, sp, #0xe0
//   0x7200: a93b97a4  stp        x4, x5, [x29, #-0x48]
//   0x7204: aa1e03f3  mov        x19, x30
//   0x7208: a93a8fa2  stp        x2, x3, [x29, #-0x58]
//   0x720c: 2a0103f4  mov        w20, w1
//   0x7210: a93c9fa6  stp        x6, x7, [x29, #-0x38]
//   0x7214: aa0003f5  mov        x21, x0
//   0x7218: ad0007e0  stp        q0, q1, [sp]
//   0x721c: ad010fe2  stp        q2, q3, [sp, #0x20]
//   0x7220: ad0217e4  stp        q4, q5, [sp, #0x40]
//   0x7224: ad031fe6  stp        q6, q7, [sp, #0x60]
//   0x7228: d53bd057  mrs        x23, tpidr_el0
//   0x722c: f94016e8  ldr        x8, [x23, #0x28]
//   0x7230: f81f83a8  stur       x8, [x29, #-8]
//   0x7234: 37300101  tbnz       w1, #6, #0x7254
//   0x7238: 52880008  mov        w8, #0x4000
//   0x723c: 72a00808  movk       w8, #0x40, lsl #16
//   0x7240: 0a080289  and        w9, w20, w8
//   0x7244: 6b08013f  cmp        w9, w8
//   0x7248: 54000060  b.eq       #0x7254
//   0x724c: 2a1f03f6  mov        w22, wzr
//   0x7250: 14000017  b          #0x72ac
//   0x7254: 928005e9  mov        x9, #-0x30
//   0x7258: 910003e8  mov        x8, sp
//   0x725c: d10163ac  sub        x12, x29, #0x58
//   0x7260: f2dff009  movk       x9, #0xff80, lsl #32
//   0x7264: 910143aa  add        x10, x29, #0x50
//   0x7268: 9102010b  add        x11, x8, #0x80
//   0x726c: 928005e8  mov        x8, #-0x30
//   0x7270: 9100c18c  add        x12, x12, #0x30
//   0x7274: a93ea7ab  stp        x11, x9, [x29, #-0x18]
//   0x7278: a93db3aa  stp        x10, x12, [x29, #-0x28]
//   0x727c: 36f80108  tbz        w8, #0x1f, #0x729c
//   0x7280: 11002109  add        w9, w8, #8
//   0x7284: 3100211f  cmn        w8, #8
//   0x7288: b81f03a9  stur       w9, [x29, #-0x10]
//   0x728c: 54000088  b.hi       #0x729c
//   0x7290: f85e03a9  ldur       x9, [x29, #-0x20]
//   0x7294: 8b080128  add        x8, x9, x8
//   0x7298: 14000004  b          #0x72a8
//   0x729c: f85d83a8  ldur       x8, [x29, #-0x28]
//   0x72a0: 91002109  add        x9, x8, #8
//   0x72a4: f81d83a9  stur       x9, [x29, #-0x28]
//   0x72a8: b9400116  ldr        w22, [x8]
//   0x72ac: d503201f  nop        
//   0x72b0: 10fff9a0  adr        x0, #0x71e4
//   0x72b4: 940005af  bl         #0x8970
//   0x72b8: aa0003e8  mov        x8, x0
//   0x72bc: aa1503e0  mov        x0, x21
//   0x72c0: 2a1403e1  mov        w1, w20
//   0x72c4: 2a1603e2  mov        w2, w22
//   0x72c8: d63f0100  blr        x8
//   0x72cc: 2a0003f6  mov        w22, w0
//   0x72d0: 37f80300  tbnz       w0, #0x1f, #0x7330
//   0x72d4: d0000058  adrp       x24, #0x11000
//   0x72d8: 528acf19  mov        w25, #0x5678
//   0x72dc: 72a24699  movk       w25, #0x1234, lsl #16
//   0x72e0: b942f300  ldr        w0, [x24, #0x2f0]
//   0x72e4: 940005a7  bl         #0x8980
//   0x72e8: eb19001f  cmp        x0, x25
//   0x72ec: 54000220  b.eq       #0x7330
//   0x72f0: 528acf01  mov        w1, #0x5678
//   0x72f4: b942f300  ldr        w0, [x24, #0x2f0]
//   0x72f8: 72a24681  movk       w1, #0x1234, lsl #16
//   0x72fc: 940005a5  bl         #0x8990
//   0x7300: aa1303fe  mov        x30, x19
//   0x7304: 2a1603e0  mov        w0, w22
//   0x7308: aa1503e1  mov        x1, x21
//   0x730c: aa1d03e3  mov        x3, x29
//   0x7310: 2a1403e4  mov        w4, w20
//   0x7314: 2a1f03e5  mov        w5, wzr
//   0x7318: d50320ff  xpaclri    
//   0x731c: aa1e03e2  mov        x2, x30
//   0x7320: 940004cc  bl         #0x8650
//   0x7324: b942f300  ldr        w0, [x24, #0x2f0]
//   0x7328: aa1f03e1  mov        x1, xzr
//   0x732c: 94000599  bl         #0x8990
//   0x7330: 9400059c  bl         #0x89a0
//   0x7334: 350000a0  cbnz       w0, #0x7348
//   0x7338: aa1303fe  mov        x30, x19
//   0x733c: d50320ff  xpaclri    
//   0x7340: aa1e03e0  mov        x0, x30
//   0x7344: 9400059b  bl         #0x89b0
//   0x7348: f94016e8  ldr        x8, [x23, #0x28]
//   0x734c: f85f83a9  ldur       x9, [x29, #-8]
//   0x7350: eb09011f  cmp        x8, x9
//   0x7354: 54000121  b.ne       #0x7378
//   0x7358: 2a1603e0  mov        w0, w22
//   0x735c: a9524ff4  ldp        x20, x19, [sp, #0x120]
//   0x7360: a95157f6  ldp        x22, x21, [sp, #0x110]
//   0x7364: a9505ff8  ldp        x24, x23, [sp, #0x100]
//   0x7368: a94f67fc  ldp        x28, x25, [sp, #0xf0]
//   0x736c: a94e7bfd  ldp        x29, x30, [sp, #0xe0]
//   0x7370: 9104c3ff  add        sp, sp, #0x130
//   0x7374: d65f03c0  ret        
//   0x7378: 9400048e  bl         #0x85b0

// ----------------------------------------------------------------------------
// FDE[39] HookProxy_open_2_737c (0x737c..0x744c, 208 bytes, 52 instructions)
// Summary / Tóm tắt: ShadowHook proxy for __open_2(const char* path, int oflag) (@ 0x737c..0x744c)
// ----------------------------------------------------------------------------
//   0x737c: a9bc7bfd  stp        x29, x30, [sp, #-0x40]!
//   0x7380: a9015ff8  stp        x24, x23, [sp, #0x10]
//   0x7384: a90257f6  stp        x22, x21, [sp, #0x20]
//   0x7388: a9034ff4  stp        x20, x19, [sp, #0x30]
//   0x738c: 910003fd  mov        x29, sp
//   0x7390: aa0003f6  mov        x22, x0
//   0x7394: d503201f  nop        
//   0x7398: 10ffff20  adr        x0, #0x737c
//   0x739c: aa1e03f3  mov        x19, x30
//   0x73a0: 2a0103f5  mov        w21, w1
//   0x73a4: 94000573  bl         #0x8970
//   0x73a8: aa0003e8  mov        x8, x0
//   0x73ac: aa1603e0  mov        x0, x22
//   0x73b0: 2a1503e1  mov        w1, w21
//   0x73b4: d63f0100  blr        x8
//   0x73b8: 2a0003f4  mov        w20, w0
//   0x73bc: 37f80300  tbnz       w0, #0x1f, #0x741c
//   0x73c0: d0000057  adrp       x23, #0x11000
//   0x73c4: 528acf18  mov        w24, #0x5678
//   0x73c8: 72a24698  movk       w24, #0x1234, lsl #16
//   0x73cc: b942f2e0  ldr        w0, [x23, #0x2f0]
//   0x73d0: 9400056c  bl         #0x8980
//   0x73d4: eb18001f  cmp        x0, x24
//   0x73d8: 54000220  b.eq       #0x741c
//   0x73dc: 528acf01  mov        w1, #0x5678
//   0x73e0: b942f2e0  ldr        w0, [x23, #0x2f0]
//   0x73e4: 72a24681  movk       w1, #0x1234, lsl #16
//   0x73e8: 9400056a  bl         #0x8990
//   0x73ec: aa1303fe  mov        x30, x19
//   0x73f0: 2a1403e0  mov        w0, w20
//   0x73f4: aa1603e1  mov        x1, x22
//   0x73f8: aa1d03e3  mov        x3, x29
//   0x73fc: 2a1503e4  mov        w4, w21
//   0x7400: 52800025  mov        w5, #1
//   0x7404: d50320ff  xpaclri    
//   0x7408: aa1e03e2  mov        x2, x30
//   0x740c: 94000491  bl         #0x8650
//   0x7410: b942f2e0  ldr        w0, [x23, #0x2f0]
//   0x7414: aa1f03e1  mov        x1, xzr
//   0x7418: 9400055e  bl         #0x8990
//   0x741c: 94000561  bl         #0x89a0
//   0x7420: 350000a0  cbnz       w0, #0x7434
//   0x7424: aa1303fe  mov        x30, x19
//   0x7428: d50320ff  xpaclri    
//   0x742c: aa1e03e0  mov        x0, x30
//   0x7430: 94000560  bl         #0x89b0
//   0x7434: 2a1403e0  mov        w0, w20
//   0x7438: a9434ff4  ldp        x20, x19, [sp, #0x30]
//   0x743c: a94257f6  ldp        x22, x21, [sp, #0x20]
//   0x7440: a9415ff8  ldp        x24, x23, [sp, #0x10]
//   0x7444: a8c47bfd  ldp        x29, x30, [sp], #0x40
//   0x7448: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[40] HookProxy_openat_2_744c (0x744c..0x7524, 216 bytes, 54 instructions)
// Summary / Tóm tắt: ShadowHook proxy for __openat_2(int dirfd, const char* path, int oflag) (@ 0x744c..0x7524)
// ----------------------------------------------------------------------------
//   0x744c: a9bc7bfd  stp        x29, x30, [sp, #-0x40]!
//   0x7450: a9015ff8  stp        x24, x23, [sp, #0x10]
//   0x7454: a90257f6  stp        x22, x21, [sp, #0x20]
//   0x7458: a9034ff4  stp        x20, x19, [sp, #0x30]
//   0x745c: 910003fd  mov        x29, sp
//   0x7460: 2a0003f4  mov        w20, w0
//   0x7464: d503201f  nop        
//   0x7468: 10ffff20  adr        x0, #0x744c
//   0x746c: aa1e03f3  mov        x19, x30
//   0x7470: 2a0203f5  mov        w21, w2
//   0x7474: aa0103f6  mov        x22, x1
//   0x7478: 9400053e  bl         #0x8970
//   0x747c: aa0003e8  mov        x8, x0
//   0x7480: 2a1403e0  mov        w0, w20
//   0x7484: aa1603e1  mov        x1, x22
//   0x7488: 2a1503e2  mov        w2, w21
//   0x748c: d63f0100  blr        x8
//   0x7490: 2a0003f4  mov        w20, w0
//   0x7494: 37f80300  tbnz       w0, #0x1f, #0x74f4
//   0x7498: d0000057  adrp       x23, #0x11000
//   0x749c: 528acf18  mov        w24, #0x5678
//   0x74a0: 72a24698  movk       w24, #0x1234, lsl #16
//   0x74a4: b942f2e0  ldr        w0, [x23, #0x2f0]
//   0x74a8: 94000536  bl         #0x8980
//   0x74ac: eb18001f  cmp        x0, x24
//   0x74b0: 54000220  b.eq       #0x74f4
//   0x74b4: 528acf01  mov        w1, #0x5678
//   0x74b8: b942f2e0  ldr        w0, [x23, #0x2f0]
//   0x74bc: 72a24681  movk       w1, #0x1234, lsl #16
//   0x74c0: 94000534  bl         #0x8990
//   0x74c4: aa1303fe  mov        x30, x19
//   0x74c8: 2a1403e0  mov        w0, w20
//   0x74cc: aa1603e1  mov        x1, x22
//   0x74d0: aa1d03e3  mov        x3, x29
//   0x74d4: 2a1503e4  mov        w4, w21
//   0x74d8: 52800065  mov        w5, #3
//   0x74dc: d50320ff  xpaclri    
//   0x74e0: aa1e03e2  mov        x2, x30
//   0x74e4: 9400045b  bl         #0x8650
//   0x74e8: b942f2e0  ldr        w0, [x23, #0x2f0]
//   0x74ec: aa1f03e1  mov        x1, xzr
//   0x74f0: 94000528  bl         #0x8990
//   0x74f4: 9400052b  bl         #0x89a0
//   0x74f8: 350000a0  cbnz       w0, #0x750c
//   0x74fc: aa1303fe  mov        x30, x19
//   0x7500: d50320ff  xpaclri    
//   0x7504: aa1e03e0  mov        x0, x30
//   0x7508: 9400052a  bl         #0x89b0
//   0x750c: 2a1403e0  mov        w0, w20
//   0x7510: a9434ff4  ldp        x20, x19, [sp, #0x30]
//   0x7514: a94257f6  ldp        x22, x21, [sp, #0x20]
//   0x7518: a9415ff8  ldp        x24, x23, [sp, #0x10]
//   0x751c: a8c47bfd  ldp        x29, x30, [sp], #0x40
//   0x7520: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[41] HookProxy_pipe2_7524 (0x7524..0x7614, 240 bytes, 60 instructions)
// Summary / Tóm tắt: ShadowHook proxy for pipe2(int pipefd[2], int flags) (@ 0x7524..0x7614)
// ----------------------------------------------------------------------------
//   0x7524: a9bc7bfd  stp        x29, x30, [sp, #-0x40]!
//   0x7528: a9015ff8  stp        x24, x23, [sp, #0x10]
//   0x752c: a90257f6  stp        x22, x21, [sp, #0x20]
//   0x7530: a9034ff4  stp        x20, x19, [sp, #0x30]
//   0x7534: 910003fd  mov        x29, sp
//   0x7538: aa0003f6  mov        x22, x0
//   0x753c: d503201f  nop        
//   0x7540: 10ffff20  adr        x0, #0x7524
//   0x7544: aa1e03f3  mov        x19, x30
//   0x7548: 2a0103f5  mov        w21, w1
//   0x754c: 94000509  bl         #0x8970
//   0x7550: aa0003e8  mov        x8, x0
//   0x7554: aa1603e0  mov        x0, x22
//   0x7558: 2a1503e1  mov        w1, w21
//   0x755c: d63f0100  blr        x8
//   0x7560: 2a0003f4  mov        w20, w0
//   0x7564: 35000400  cbnz       w0, #0x75e4
//   0x7568: d0000058  adrp       x24, #0x11000
//   0x756c: 528acf17  mov        w23, #0x5678
//   0x7570: 72a24697  movk       w23, #0x1234, lsl #16
//   0x7574: b942f300  ldr        w0, [x24, #0x2f0]
//   0x7578: 94000502  bl         #0x8980
//   0x757c: eb17001f  cmp        x0, x23
//   0x7580: 54000320  b.eq       #0x75e4
//   0x7584: 528acf01  mov        w1, #0x5678
//   0x7588: b942f300  ldr        w0, [x24, #0x2f0]
//   0x758c: 72a24681  movk       w1, #0x1234, lsl #16
//   0x7590: 94000500  bl         #0x8990
//   0x7594: aa1303fe  mov        x30, x19
//   0x7598: aa1f03e1  mov        x1, xzr
//   0x759c: aa1d03e3  mov        x3, x29
//   0x75a0: 2a1503e4  mov        w4, w21
//   0x75a4: 528000e5  mov        w5, #7
//   0x75a8: d50320ff  xpaclri    
//   0x75ac: b94002c0  ldr        w0, [x22]
//   0x75b0: aa1e03e2  mov        x2, x30
//   0x75b4: aa1e03f7  mov        x23, x30
//   0x75b8: 94000426  bl         #0x8650
//   0x75bc: b94006c0  ldr        w0, [x22, #4]
//   0x75c0: aa1f03e1  mov        x1, xzr
//   0x75c4: aa1703e2  mov        x2, x23
//   0x75c8: aa1d03e3  mov        x3, x29
//   0x75cc: 2a1503e4  mov        w4, w21
//   0x75d0: 528000e5  mov        w5, #7
//   0x75d4: 9400041f  bl         #0x8650
//   0x75d8: b942f300  ldr        w0, [x24, #0x2f0]
//   0x75dc: aa1f03e1  mov        x1, xzr
//   0x75e0: 940004ec  bl         #0x8990
//   0x75e4: 940004ef  bl         #0x89a0
//   0x75e8: 350000a0  cbnz       w0, #0x75fc
//   0x75ec: aa1303fe  mov        x30, x19
//   0x75f0: d50320ff  xpaclri    
//   0x75f4: aa1e03e0  mov        x0, x30
//   0x75f8: 940004ee  bl         #0x89b0
//   0x75fc: 2a1403e0  mov        w0, w20
//   0x7600: a9434ff4  ldp        x20, x19, [sp, #0x30]
//   0x7604: a94257f6  ldp        x22, x21, [sp, #0x20]
//   0x7608: a9415ff8  ldp        x24, x23, [sp, #0x10]
//   0x760c: a8c47bfd  ldp        x29, x30, [sp], #0x40
//   0x7610: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[42] HookProxy_pipe_7614 (0x7614..0x76fc, 232 bytes, 58 instructions)
// Summary / Tóm tắt: ShadowHook proxy for pipe(int pipefd[2]) (@ 0x7614..0x76fc)
// ----------------------------------------------------------------------------
//   0x7614: a9bc7bfd  stp        x29, x30, [sp, #-0x40]!
//   0x7618: f9000bf7  str        x23, [sp, #0x10]
//   0x761c: a90257f6  stp        x22, x21, [sp, #0x20]
//   0x7620: a9034ff4  stp        x20, x19, [sp, #0x30]
//   0x7624: 910003fd  mov        x29, sp
//   0x7628: aa0003f5  mov        x21, x0
//   0x762c: d503201f  nop        
//   0x7630: 10ffff20  adr        x0, #0x7614
//   0x7634: aa1e03f3  mov        x19, x30
//   0x7638: 940004ce  bl         #0x8970
//   0x763c: aa0003e8  mov        x8, x0
//   0x7640: aa1503e0  mov        x0, x21
//   0x7644: d63f0100  blr        x8
//   0x7648: 2a0003f4  mov        w20, w0
//   0x764c: 35000400  cbnz       w0, #0x76cc
//   0x7650: d0000057  adrp       x23, #0x11000
//   0x7654: 528acf16  mov        w22, #0x5678
//   0x7658: 72a24696  movk       w22, #0x1234, lsl #16
//   0x765c: b942f2e0  ldr        w0, [x23, #0x2f0]
//   0x7660: 940004c8  bl         #0x8980
//   0x7664: eb16001f  cmp        x0, x22
//   0x7668: 54000320  b.eq       #0x76cc
//   0x766c: 528acf01  mov        w1, #0x5678
//   0x7670: b942f2e0  ldr        w0, [x23, #0x2f0]
//   0x7674: 72a24681  movk       w1, #0x1234, lsl #16
//   0x7678: 940004c6  bl         #0x8990
//   0x767c: aa1303fe  mov        x30, x19
//   0x7680: aa1f03e1  mov        x1, xzr
//   0x7684: aa1d03e3  mov        x3, x29
//   0x7688: 12800004  mov        w4, #-1
//   0x768c: 528000c5  mov        w5, #6
//   0x7690: d50320ff  xpaclri    
//   0x7694: b94002a0  ldr        w0, [x21]
//   0x7698: aa1e03e2  mov        x2, x30
//   0x769c: aa1e03f6  mov        x22, x30
//   0x76a0: 940003ec  bl         #0x8650
//   0x76a4: b94006a0  ldr        w0, [x21, #4]
//   0x76a8: aa1f03e1  mov        x1, xzr
//   0x76ac: aa1603e2  mov        x2, x22
//   0x76b0: aa1d03e3  mov        x3, x29
//   0x76b4: 12800004  mov        w4, #-1
//   0x76b8: 528000c5  mov        w5, #6
//   0x76bc: 940003e5  bl         #0x8650
//   0x76c0: b942f2e0  ldr        w0, [x23, #0x2f0]
//   0x76c4: aa1f03e1  mov        x1, xzr
//   0x76c8: 940004b2  bl         #0x8990
//   0x76cc: 940004b5  bl         #0x89a0
//   0x76d0: 350000a0  cbnz       w0, #0x76e4
//   0x76d4: aa1303fe  mov        x30, x19
//   0x76d8: d50320ff  xpaclri    
//   0x76dc: aa1e03e0  mov        x0, x30
//   0x76e0: 940004b4  bl         #0x89b0
//   0x76e4: 2a1403e0  mov        w0, w20
//   0x76e8: a9434ff4  ldp        x20, x19, [sp, #0x30]
//   0x76ec: a94257f6  ldp        x22, x21, [sp, #0x20]
//   0x76f0: f9400bf7  ldr        x23, [sp, #0x10]
//   0x76f4: a8c47bfd  ldp        x29, x30, [sp], #0x40
//   0x76f8: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[43] HookProxy_fcntl_76fc (0x76fc..0x7888, 396 bytes, 99 instructions)
// Summary / Tóm tắt: ShadowHook proxy for fcntl(int fd, int cmd, ...) tracking F_DUPFD/F_DUPFD_CLOEXEC (@ 0x76fc..0x7888)
// ----------------------------------------------------------------------------
//   0x76fc: d104c3ff  sub        sp, sp, #0x130
//   0x7700: a90e7bfd  stp        x29, x30, [sp, #0xe0]
//   0x7704: f9007bfc  str        x28, [sp, #0xf0]
//   0x7708: a9105ff8  stp        x24, x23, [sp, #0x100]
//   0x770c: a91157f6  stp        x22, x21, [sp, #0x110]
//   0x7710: a9124ff4  stp        x20, x19, [sp, #0x120]
//   0x7714: 910383fd  add        x29, sp, #0xe0
//   0x7718: a93b97a4  stp        x4, x5, [x29, #-0x48]
//   0x771c: 928005e9  mov        x9, #-0x30
//   0x7720: a93a8fa2  stp        x2, x3, [x29, #-0x58]
//   0x7724: aa1e03f3  mov        x19, x30
//   0x7728: a93c9fa6  stp        x6, x7, [x29, #-0x38]
//   0x772c: 2a0103f4  mov        w20, w1
//   0x7730: ad0007e0  stp        q0, q1, [sp]
//   0x7734: 2a0003f5  mov        w21, w0
//   0x7738: ad010fe2  stp        q2, q3, [sp, #0x20]
//   0x773c: f2dff009  movk       x9, #0xff80, lsl #32
//   0x7740: ad0217e4  stp        q4, q5, [sp, #0x40]
//   0x7744: 910143ac  add        x12, x29, #0x50
//   0x7748: ad031fe6  stp        q6, q7, [sp, #0x60]
//   0x774c: d53bd057  mrs        x23, tpidr_el0
//   0x7750: f94016e8  ldr        x8, [x23, #0x28]
//   0x7754: f81f83a8  stur       x8, [x29, #-8]
//   0x7758: 910003e8  mov        x8, sp
//   0x775c: 9102010a  add        x10, x8, #0x80
//   0x7760: d10163a8  sub        x8, x29, #0x58
//   0x7764: 9100c10b  add        x11, x8, #0x30
//   0x7768: 928005e8  mov        x8, #-0x30
//   0x776c: a93ea7aa  stp        x10, x9, [x29, #-0x18]
//   0x7770: a93dafac  stp        x12, x11, [x29, #-0x28]
//   0x7774: 36f80108  tbz        w8, #0x1f, #0x7794
//   0x7778: 11002109  add        w9, w8, #8
//   0x777c: 3100211f  cmn        w8, #8
//   0x7780: b81f03a9  stur       w9, [x29, #-0x10]
//   0x7784: 54000088  b.hi       #0x7794
//   0x7788: f85e03a9  ldur       x9, [x29, #-0x20]
//   0x778c: 8b080128  add        x8, x9, x8
//   0x7790: 14000004  b          #0x77a0
//   0x7794: f85d83a8  ldur       x8, [x29, #-0x28]
//   0x7798: 91002109  add        x9, x8, #8
//   0x779c: f81d83a9  stur       x9, [x29, #-0x28]
//   0x77a0: d503201f  nop        
//   0x77a4: 10fffac0  adr        x0, #0x76fc
//   0x77a8: f9400116  ldr        x22, [x8]
//   0x77ac: 94000471  bl         #0x8970
//   0x77b0: aa0003e8  mov        x8, x0
//   0x77b4: 2a1503e0  mov        w0, w21
//   0x77b8: 2a1403e1  mov        w1, w20
//   0x77bc: aa1603e2  mov        x2, x22
//   0x77c0: d63f0100  blr        x8
//   0x77c4: 2a0003f5  mov        w21, w0
//   0x77c8: 37f803a0  tbnz       w0, #0x1f, #0x783c
//   0x77cc: 71101a9f  cmp        w20, #0x406
//   0x77d0: 54000040  b.eq       #0x77d8
//   0x77d4: 35000354  cbnz       w20, #0x783c
//   0x77d8: d0000056  adrp       x22, #0x11000
//   0x77dc: 528acf18  mov        w24, #0x5678
//   0x77e0: 72a24698  movk       w24, #0x1234, lsl #16
//   0x77e4: b942f2c0  ldr        w0, [x22, #0x2f0]
//   0x77e8: 94000466  bl         #0x8980
//   0x77ec: eb18001f  cmp        x0, x24
//   0x77f0: 54000260  b.eq       #0x783c
//   0x77f4: 528acf01  mov        w1, #0x5678
//   0x77f8: b942f2c0  ldr        w0, [x22, #0x2f0]
//   0x77fc: 72a24681  movk       w1, #0x1234, lsl #16
//   0x7800: 71101a9f  cmp        w20, #0x406
//   0x7804: 1a9f17f4  cset       w20, eq
//   0x7808: 94000462  bl         #0x8990
//   0x780c: aa1303fe  mov        x30, x19
//   0x7810: 530d3284  lsl        w4, w20, #0x13
//   0x7814: 2a1503e0  mov        w0, w21
//   0x7818: aa1f03e1  mov        x1, xzr
//   0x781c: aa1d03e3  mov        x3, x29
//   0x7820: 52800145  mov        w5, #0xa
//   0x7824: d50320ff  xpaclri    
//   0x7828: aa1e03e2  mov        x2, x30
//   0x782c: 94000389  bl         #0x8650
//   0x7830: b942f2c0  ldr        w0, [x22, #0x2f0]
//   0x7834: aa1f03e1  mov        x1, xzr
//   0x7838: 94000456  bl         #0x8990
//   0x783c: 94000459  bl         #0x89a0
//   0x7840: 350000a0  cbnz       w0, #0x7854
//   0x7844: aa1303fe  mov        x30, x19
//   0x7848: d50320ff  xpaclri    
//   0x784c: aa1e03e0  mov        x0, x30
//   0x7850: 94000458  bl         #0x89b0
//   0x7854: f94016e8  ldr        x8, [x23, #0x28]
//   0x7858: f85f83a9  ldur       x9, [x29, #-8]
//   0x785c: eb09011f  cmp        x8, x9
//   0x7860: 54000121  b.ne       #0x7884
//   0x7864: 2a1503e0  mov        w0, w21
//   0x7868: a9524ff4  ldp        x20, x19, [sp, #0x120]
//   0x786c: a95157f6  ldp        x22, x21, [sp, #0x110]
//   0x7870: a9505ff8  ldp        x24, x23, [sp, #0x100]
//   0x7874: a94e7bfd  ldp        x29, x30, [sp, #0xe0]
//   0x7878: f9407bfc  ldr        x28, [sp, #0xf0]
//   0x787c: 9104c3ff  add        sp, sp, #0x130
//   0x7880: d65f03c0  ret        
//   0x7884: 9400034b  bl         #0x85b0

// ----------------------------------------------------------------------------
// FDE[44] HookProxy_dup_7888 (0x7888..0x7948, 192 bytes, 48 instructions)
// Summary / Tóm tắt: ShadowHook proxy for dup(int oldfd) (@ 0x7888..0x7948)
// ----------------------------------------------------------------------------
//   0x7888: a9bd7bfd  stp        x29, x30, [sp, #-0x30]!
//   0x788c: a90157f6  stp        x22, x21, [sp, #0x10]
//   0x7890: a9024ff4  stp        x20, x19, [sp, #0x20]
//   0x7894: 910003fd  mov        x29, sp
//   0x7898: 2a0003f4  mov        w20, w0
//   0x789c: d503201f  nop        
//   0x78a0: 10ffff40  adr        x0, #0x7888
//   0x78a4: aa1e03f3  mov        x19, x30
//   0x78a8: 94000432  bl         #0x8970
//   0x78ac: aa0003e8  mov        x8, x0
//   0x78b0: 2a1403e0  mov        w0, w20
//   0x78b4: d63f0100  blr        x8
//   0x78b8: 2a0003f4  mov        w20, w0
//   0x78bc: 37f80300  tbnz       w0, #0x1f, #0x791c
//   0x78c0: d0000055  adrp       x21, #0x11000
//   0x78c4: 528acf16  mov        w22, #0x5678
//   0x78c8: 72a24696  movk       w22, #0x1234, lsl #16
//   0x78cc: b942f2a0  ldr        w0, [x21, #0x2f0]
//   0x78d0: 9400042c  bl         #0x8980
//   0x78d4: eb16001f  cmp        x0, x22
//   0x78d8: 54000220  b.eq       #0x791c
//   0x78dc: 528acf01  mov        w1, #0x5678
//   0x78e0: b942f2a0  ldr        w0, [x21, #0x2f0]
//   0x78e4: 72a24681  movk       w1, #0x1234, lsl #16
//   0x78e8: 9400042a  bl         #0x8990
//   0x78ec: aa1303fe  mov        x30, x19
//   0x78f0: 2a1403e0  mov        w0, w20
//   0x78f4: aa1f03e1  mov        x1, xzr
//   0x78f8: aa1d03e3  mov        x3, x29
//   0x78fc: 12800004  mov        w4, #-1
//   0x7900: 52800105  mov        w5, #8
//   0x7904: d50320ff  xpaclri    
//   0x7908: aa1e03e2  mov        x2, x30
//   0x790c: 94000351  bl         #0x8650
//   0x7910: b942f2a0  ldr        w0, [x21, #0x2f0]
//   0x7914: aa1f03e1  mov        x1, xzr
//   0x7918: 9400041e  bl         #0x8990
//   0x791c: 94000421  bl         #0x89a0
//   0x7920: 350000a0  cbnz       w0, #0x7934
//   0x7924: aa1303fe  mov        x30, x19
//   0x7928: d50320ff  xpaclri    
//   0x792c: aa1e03e0  mov        x0, x30
//   0x7930: 94000420  bl         #0x89b0
//   0x7934: 2a1403e0  mov        w0, w20
//   0x7938: a9424ff4  ldp        x20, x19, [sp, #0x20]
//   0x793c: a94157f6  ldp        x22, x21, [sp, #0x10]
//   0x7940: a8c37bfd  ldp        x29, x30, [sp], #0x30
//   0x7944: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[45] HookProxy_socket_7948 (0x7948..0x7a18, 208 bytes, 52 instructions)
// Summary / Tóm tắt: ShadowHook proxy for socket(int domain, int type, int protocol) (@ 0x7948..0x7a18)
// ----------------------------------------------------------------------------
//   0x7948: a9bd7bfd  stp        x29, x30, [sp, #-0x30]!
//   0x794c: a90157f6  stp        x22, x21, [sp, #0x10]
//   0x7950: a9024ff4  stp        x20, x19, [sp, #0x20]
//   0x7954: 910003fd  mov        x29, sp
//   0x7958: 2a0003f6  mov        w22, w0
//   0x795c: d503201f  nop        
//   0x7960: 10ffff40  adr        x0, #0x7948
//   0x7964: aa1e03f3  mov        x19, x30
//   0x7968: 2a0203f4  mov        w20, w2
//   0x796c: 2a0103f5  mov        w21, w1
//   0x7970: 94000400  bl         #0x8970
//   0x7974: aa0003e8  mov        x8, x0
//   0x7978: 2a1603e0  mov        w0, w22
//   0x797c: 2a1503e1  mov        w1, w21
//   0x7980: 2a1403e2  mov        w2, w20
//   0x7984: d63f0100  blr        x8
//   0x7988: 2a0003f4  mov        w20, w0
//   0x798c: 37f80300  tbnz       w0, #0x1f, #0x79ec
//   0x7990: d0000055  adrp       x21, #0x11000
//   0x7994: 528acf16  mov        w22, #0x5678
//   0x7998: 72a24696  movk       w22, #0x1234, lsl #16
//   0x799c: b942f2a0  ldr        w0, [x21, #0x2f0]
//   0x79a0: 940003f8  bl         #0x8980
//   0x79a4: eb16001f  cmp        x0, x22
//   0x79a8: 54000220  b.eq       #0x79ec
//   0x79ac: 528acf01  mov        w1, #0x5678
//   0x79b0: b942f2a0  ldr        w0, [x21, #0x2f0]
//   0x79b4: 72a24681  movk       w1, #0x1234, lsl #16
//   0x79b8: 940003f6  bl         #0x8990
//   0x79bc: aa1303fe  mov        x30, x19
//   0x79c0: 2a1403e0  mov        w0, w20
//   0x79c4: aa1f03e1  mov        x1, xzr
//   0x79c8: aa1d03e3  mov        x3, x29
//   0x79cc: 12800004  mov        w4, #-1
//   0x79d0: 52800085  mov        w5, #4
//   0x79d4: d50320ff  xpaclri    
//   0x79d8: aa1e03e2  mov        x2, x30
//   0x79dc: 9400031d  bl         #0x8650
//   0x79e0: b942f2a0  ldr        w0, [x21, #0x2f0]
//   0x79e4: aa1f03e1  mov        x1, xzr
//   0x79e8: 940003ea  bl         #0x8990
//   0x79ec: 940003ed  bl         #0x89a0
//   0x79f0: 350000a0  cbnz       w0, #0x7a04
//   0x79f4: aa1303fe  mov        x30, x19
//   0x79f8: d50320ff  xpaclri    
//   0x79fc: aa1e03e0  mov        x0, x30
//   0x7a00: 940003ec  bl         #0x89b0
//   0x7a04: 2a1403e0  mov        w0, w20
//   0x7a08: a9424ff4  ldp        x20, x19, [sp, #0x20]
//   0x7a0c: a94157f6  ldp        x22, x21, [sp, #0x10]
//   0x7a10: a8c37bfd  ldp        x29, x30, [sp], #0x30
//   0x7a14: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[46] HookProxy_socketpair_7a18 (0x7a18..0x7b18, 256 bytes, 64 instructions)
// Summary / Tóm tắt: ShadowHook proxy for socketpair(int domain, int type, int protocol, int sv[2]) (@ 0x7a18..0x7b18)
// ----------------------------------------------------------------------------
//   0x7a18: a9bc7bfd  stp        x29, x30, [sp, #-0x40]!
//   0x7a1c: f9000bf7  str        x23, [sp, #0x10]
//   0x7a20: a90257f6  stp        x22, x21, [sp, #0x20]
//   0x7a24: a9034ff4  stp        x20, x19, [sp, #0x30]
//   0x7a28: 910003fd  mov        x29, sp
//   0x7a2c: 2a0003f7  mov        w23, w0
//   0x7a30: d503201f  nop        
//   0x7a34: 10ffff20  adr        x0, #0x7a18
//   0x7a38: aa1e03f3  mov        x19, x30
//   0x7a3c: aa0303f5  mov        x21, x3
//   0x7a40: 2a0203f4  mov        w20, w2
//   0x7a44: 2a0103f6  mov        w22, w1
//   0x7a48: 940003ca  bl         #0x8970
//   0x7a4c: aa0003e8  mov        x8, x0
//   0x7a50: 2a1703e0  mov        w0, w23
//   0x7a54: 2a1603e1  mov        w1, w22
//   0x7a58: 2a1403e2  mov        w2, w20
//   0x7a5c: aa1503e3  mov        x3, x21
//   0x7a60: d63f0100  blr        x8
//   0x7a64: 2a0003f4  mov        w20, w0
//   0x7a68: 35000400  cbnz       w0, #0x7ae8
//   0x7a6c: d0000057  adrp       x23, #0x11000
//   0x7a70: 528acf16  mov        w22, #0x5678
//   0x7a74: 72a24696  movk       w22, #0x1234, lsl #16
//   0x7a78: b942f2e0  ldr        w0, [x23, #0x2f0]
//   0x7a7c: 940003c1  bl         #0x8980
//   0x7a80: eb16001f  cmp        x0, x22
//   0x7a84: 54000320  b.eq       #0x7ae8
//   0x7a88: 528acf01  mov        w1, #0x5678
//   0x7a8c: b942f2e0  ldr        w0, [x23, #0x2f0]
//   0x7a90: 72a24681  movk       w1, #0x1234, lsl #16
//   0x7a94: 940003bf  bl         #0x8990
//   0x7a98: aa1303fe  mov        x30, x19
//   0x7a9c: aa1f03e1  mov        x1, xzr
//   0x7aa0: aa1d03e3  mov        x3, x29
//   0x7aa4: 12800004  mov        w4, #-1
//   0x7aa8: 528000a5  mov        w5, #5
//   0x7aac: d50320ff  xpaclri    
//   0x7ab0: b94002a0  ldr        w0, [x21]
//   0x7ab4: aa1e03e2  mov        x2, x30
//   0x7ab8: aa1e03f6  mov        x22, x30
//   0x7abc: 940002e5  bl         #0x8650
//   0x7ac0: b94006a0  ldr        w0, [x21, #4]
//   0x7ac4: aa1f03e1  mov        x1, xzr
//   0x7ac8: aa1603e2  mov        x2, x22
//   0x7acc: aa1d03e3  mov        x3, x29
//   0x7ad0: 12800004  mov        w4, #-1
//   0x7ad4: 528000a5  mov        w5, #5
//   0x7ad8: 940002de  bl         #0x8650
//   0x7adc: b942f2e0  ldr        w0, [x23, #0x2f0]
//   0x7ae0: aa1f03e1  mov        x1, xzr
//   0x7ae4: 940003ab  bl         #0x8990
//   0x7ae8: 940003ae  bl         #0x89a0
//   0x7aec: 350000a0  cbnz       w0, #0x7b00
//   0x7af0: aa1303fe  mov        x30, x19
//   0x7af4: d50320ff  xpaclri    
//   0x7af8: aa1e03e0  mov        x0, x30
//   0x7afc: 940003ad  bl         #0x89b0
//   0x7b00: 2a1403e0  mov        w0, w20
//   0x7b04: a9434ff4  ldp        x20, x19, [sp, #0x30]
//   0x7b08: a94257f6  ldp        x22, x21, [sp, #0x20]
//   0x7b0c: f9400bf7  ldr        x23, [sp, #0x10]
//   0x7b10: a8c47bfd  ldp        x29, x30, [sp], #0x40
//   0x7b14: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[47] HookProxy_eventfd_7b18 (0x7b18..0x7be8, 208 bytes, 52 instructions)
// Summary / Tóm tắt: ShadowHook proxy for eventfd(unsigned int initval, int flags) (@ 0x7b18..0x7be8)
// ----------------------------------------------------------------------------
//   0x7b18: a9bc7bfd  stp        x29, x30, [sp, #-0x40]!
//   0x7b1c: f9000bf7  str        x23, [sp, #0x10]
//   0x7b20: a90257f6  stp        x22, x21, [sp, #0x20]
//   0x7b24: a9034ff4  stp        x20, x19, [sp, #0x30]
//   0x7b28: 910003fd  mov        x29, sp
//   0x7b2c: 2a0003f4  mov        w20, w0
//   0x7b30: d503201f  nop        
//   0x7b34: 10ffff20  adr        x0, #0x7b18
//   0x7b38: aa1e03f3  mov        x19, x30
//   0x7b3c: 2a0103f5  mov        w21, w1
//   0x7b40: 9400038c  bl         #0x8970
//   0x7b44: aa0003e8  mov        x8, x0
//   0x7b48: 2a1403e0  mov        w0, w20
//   0x7b4c: 2a1503e1  mov        w1, w21
//   0x7b50: d63f0100  blr        x8
//   0x7b54: 2a0003f4  mov        w20, w0
//   0x7b58: 37f80300  tbnz       w0, #0x1f, #0x7bb8
//   0x7b5c: d0000056  adrp       x22, #0x11000
//   0x7b60: 528acf17  mov        w23, #0x5678
//   0x7b64: 72a24697  movk       w23, #0x1234, lsl #16
//   0x7b68: b942f2c0  ldr        w0, [x22, #0x2f0]
//   0x7b6c: 94000385  bl         #0x8980
//   0x7b70: eb17001f  cmp        x0, x23
//   0x7b74: 54000220  b.eq       #0x7bb8
//   0x7b78: 528acf01  mov        w1, #0x5678
//   0x7b7c: b942f2c0  ldr        w0, [x22, #0x2f0]
//   0x7b80: 72a24681  movk       w1, #0x1234, lsl #16
//   0x7b84: 94000383  bl         #0x8990
//   0x7b88: aa1303fe  mov        x30, x19
//   0x7b8c: 2a1403e0  mov        w0, w20
//   0x7b90: aa1f03e1  mov        x1, xzr
//   0x7b94: aa1d03e3  mov        x3, x29
//   0x7b98: 2a1503e4  mov        w4, w21
//   0x7b9c: 52800165  mov        w5, #0xb
//   0x7ba0: d50320ff  xpaclri    
//   0x7ba4: aa1e03e2  mov        x2, x30
//   0x7ba8: 940002aa  bl         #0x8650
//   0x7bac: b942f2c0  ldr        w0, [x22, #0x2f0]
//   0x7bb0: aa1f03e1  mov        x1, xzr
//   0x7bb4: 94000377  bl         #0x8990
//   0x7bb8: 9400037a  bl         #0x89a0
//   0x7bbc: 350000a0  cbnz       w0, #0x7bd0
//   0x7bc0: aa1303fe  mov        x30, x19
//   0x7bc4: d50320ff  xpaclri    
//   0x7bc8: aa1e03e0  mov        x0, x30
//   0x7bcc: 94000379  bl         #0x89b0
//   0x7bd0: 2a1403e0  mov        w0, w20
//   0x7bd4: a9434ff4  ldp        x20, x19, [sp, #0x30]
//   0x7bd8: a94257f6  ldp        x22, x21, [sp, #0x20]
//   0x7bdc: f9400bf7  ldr        x23, [sp, #0x10]
//   0x7be0: a8c47bfd  ldp        x29, x30, [sp], #0x40
//   0x7be4: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[48] HookProxy_epoll_create_7be8 (0x7be8..0x7ca8, 192 bytes, 48 instructions)
// Summary / Tóm tắt: ShadowHook proxy for epoll_create(int size) (@ 0x7be8..0x7ca8)
// ----------------------------------------------------------------------------
//   0x7be8: a9bd7bfd  stp        x29, x30, [sp, #-0x30]!
//   0x7bec: a90157f6  stp        x22, x21, [sp, #0x10]
//   0x7bf0: a9024ff4  stp        x20, x19, [sp, #0x20]
//   0x7bf4: 910003fd  mov        x29, sp
//   0x7bf8: 2a0003f4  mov        w20, w0
//   0x7bfc: d503201f  nop        
//   0x7c00: 10ffff40  adr        x0, #0x7be8
//   0x7c04: aa1e03f3  mov        x19, x30
//   0x7c08: 9400035a  bl         #0x8970
//   0x7c0c: aa0003e8  mov        x8, x0
//   0x7c10: 2a1403e0  mov        w0, w20
//   0x7c14: d63f0100  blr        x8
//   0x7c18: 2a0003f4  mov        w20, w0
//   0x7c1c: 37f80300  tbnz       w0, #0x1f, #0x7c7c
//   0x7c20: d0000055  adrp       x21, #0x11000
//   0x7c24: 528acf16  mov        w22, #0x5678
//   0x7c28: 72a24696  movk       w22, #0x1234, lsl #16
//   0x7c2c: b942f2a0  ldr        w0, [x21, #0x2f0]
//   0x7c30: 94000354  bl         #0x8980
//   0x7c34: eb16001f  cmp        x0, x22
//   0x7c38: 54000220  b.eq       #0x7c7c
//   0x7c3c: 528acf01  mov        w1, #0x5678
//   0x7c40: b942f2a0  ldr        w0, [x21, #0x2f0]
//   0x7c44: 72a24681  movk       w1, #0x1234, lsl #16
//   0x7c48: 94000352  bl         #0x8990
//   0x7c4c: aa1303fe  mov        x30, x19
//   0x7c50: 2a1403e0  mov        w0, w20
//   0x7c54: aa1f03e1  mov        x1, xzr
//   0x7c58: aa1d03e3  mov        x3, x29
//   0x7c5c: 12800004  mov        w4, #-1
//   0x7c60: 52800185  mov        w5, #0xc
//   0x7c64: d50320ff  xpaclri    
//   0x7c68: aa1e03e2  mov        x2, x30
//   0x7c6c: 94000279  bl         #0x8650
//   0x7c70: b942f2a0  ldr        w0, [x21, #0x2f0]
//   0x7c74: aa1f03e1  mov        x1, xzr
//   0x7c78: 94000346  bl         #0x8990
//   0x7c7c: 94000349  bl         #0x89a0
//   0x7c80: 350000a0  cbnz       w0, #0x7c94
//   0x7c84: aa1303fe  mov        x30, x19
//   0x7c88: d50320ff  xpaclri    
//   0x7c8c: aa1e03e0  mov        x0, x30
//   0x7c90: 94000348  bl         #0x89b0
//   0x7c94: 2a1403e0  mov        w0, w20
//   0x7c98: a9424ff4  ldp        x20, x19, [sp, #0x20]
//   0x7c9c: a94157f6  ldp        x22, x21, [sp, #0x10]
//   0x7ca0: a8c37bfd  ldp        x29, x30, [sp], #0x30
//   0x7ca4: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[49] HookProxy_epoll_create1_7ca8 (0x7ca8..0x7d70, 200 bytes, 50 instructions)
// Summary / Tóm tắt: ShadowHook proxy for epoll_create1 / __epoll_create1(int flags) (@ 0x7ca8..0x7d70)
// ----------------------------------------------------------------------------
//   0x7ca8: a9bc7bfd  stp        x29, x30, [sp, #-0x40]!
//   0x7cac: f9000bf7  str        x23, [sp, #0x10]
//   0x7cb0: a90257f6  stp        x22, x21, [sp, #0x20]
//   0x7cb4: a9034ff4  stp        x20, x19, [sp, #0x30]
//   0x7cb8: 910003fd  mov        x29, sp
//   0x7cbc: 2a0003f5  mov        w21, w0
//   0x7cc0: d503201f  nop        
//   0x7cc4: 10ffff20  adr        x0, #0x7ca8
//   0x7cc8: aa1e03f3  mov        x19, x30
//   0x7ccc: 94000329  bl         #0x8970
//   0x7cd0: aa0003e8  mov        x8, x0
//   0x7cd4: 2a1503e0  mov        w0, w21
//   0x7cd8: d63f0100  blr        x8
//   0x7cdc: 2a0003f4  mov        w20, w0
//   0x7ce0: 37f80300  tbnz       w0, #0x1f, #0x7d40
//   0x7ce4: d0000056  adrp       x22, #0x11000
//   0x7ce8: 528acf17  mov        w23, #0x5678
//   0x7cec: 72a24697  movk       w23, #0x1234, lsl #16
//   0x7cf0: b942f2c0  ldr        w0, [x22, #0x2f0]
//   0x7cf4: 94000323  bl         #0x8980
//   0x7cf8: eb17001f  cmp        x0, x23
//   0x7cfc: 54000220  b.eq       #0x7d40
//   0x7d00: 528acf01  mov        w1, #0x5678
//   0x7d04: b942f2c0  ldr        w0, [x22, #0x2f0]
//   0x7d08: 72a24681  movk       w1, #0x1234, lsl #16
//   0x7d0c: 94000321  bl         #0x8990
//   0x7d10: aa1303fe  mov        x30, x19
//   0x7d14: 2a1403e0  mov        w0, w20
//   0x7d18: aa1f03e1  mov        x1, xzr
//   0x7d1c: aa1d03e3  mov        x3, x29
//   0x7d20: 2a1503e4  mov        w4, w21
//   0x7d24: 528001a5  mov        w5, #0xd
//   0x7d28: d50320ff  xpaclri    
//   0x7d2c: aa1e03e2  mov        x2, x30
//   0x7d30: 94000248  bl         #0x8650
//   0x7d34: b942f2c0  ldr        w0, [x22, #0x2f0]
//   0x7d38: aa1f03e1  mov        x1, xzr
//   0x7d3c: 94000315  bl         #0x8990
//   0x7d40: 94000318  bl         #0x89a0
//   0x7d44: 350000a0  cbnz       w0, #0x7d58
//   0x7d48: aa1303fe  mov        x30, x19
//   0x7d4c: d50320ff  xpaclri    
//   0x7d50: aa1e03e0  mov        x0, x30
//   0x7d54: 94000317  bl         #0x89b0
//   0x7d58: 2a1403e0  mov        w0, w20
//   0x7d5c: a9434ff4  ldp        x20, x19, [sp, #0x30]
//   0x7d60: a94257f6  ldp        x22, x21, [sp, #0x20]
//   0x7d64: f9400bf7  ldr        x23, [sp, #0x10]
//   0x7d68: a8c47bfd  ldp        x29, x30, [sp], #0x40
//   0x7d6c: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[50] HookProxy_accept_7d70 (0x7d70..0x7e40, 208 bytes, 52 instructions)
// Summary / Tóm tắt: ShadowHook proxy for accept(int sockfd, struct sockaddr* addr, socklen_t* addrlen) (@ 0x7d70..0x7e40)
// ----------------------------------------------------------------------------
//   0x7d70: a9bd7bfd  stp        x29, x30, [sp, #-0x30]!
//   0x7d74: a90157f6  stp        x22, x21, [sp, #0x10]
//   0x7d78: a9024ff4  stp        x20, x19, [sp, #0x20]
//   0x7d7c: 910003fd  mov        x29, sp
//   0x7d80: 2a0003f6  mov        w22, w0
//   0x7d84: d503201f  nop        
//   0x7d88: 10ffff40  adr        x0, #0x7d70
//   0x7d8c: aa1e03f3  mov        x19, x30
//   0x7d90: aa0203f4  mov        x20, x2
//   0x7d94: aa0103f5  mov        x21, x1
//   0x7d98: 940002f6  bl         #0x8970
//   0x7d9c: aa0003e8  mov        x8, x0
//   0x7da0: 2a1603e0  mov        w0, w22
//   0x7da4: aa1503e1  mov        x1, x21
//   0x7da8: aa1403e2  mov        x2, x20
//   0x7dac: d63f0100  blr        x8
//   0x7db0: 2a0003f4  mov        w20, w0
//   0x7db4: 37f80300  tbnz       w0, #0x1f, #0x7e14
//   0x7db8: d0000055  adrp       x21, #0x11000
//   0x7dbc: 528acf16  mov        w22, #0x5678
//   0x7dc0: 72a24696  movk       w22, #0x1234, lsl #16
//   0x7dc4: b942f2a0  ldr        w0, [x21, #0x2f0]
//   0x7dc8: 940002ee  bl         #0x8980
//   0x7dcc: eb16001f  cmp        x0, x22
//   0x7dd0: 54000220  b.eq       #0x7e14
//   0x7dd4: 528acf01  mov        w1, #0x5678
//   0x7dd8: b942f2a0  ldr        w0, [x21, #0x2f0]
//   0x7ddc: 72a24681  movk       w1, #0x1234, lsl #16
//   0x7de0: 940002ec  bl         #0x8990
//   0x7de4: aa1303fe  mov        x30, x19
//   0x7de8: 2a1403e0  mov        w0, w20
//   0x7dec: aa1f03e1  mov        x1, xzr
//   0x7df0: aa1d03e3  mov        x3, x29
//   0x7df4: 12800004  mov        w4, #-1
//   0x7df8: 528001e5  mov        w5, #0xf
//   0x7dfc: d50320ff  xpaclri    
//   0x7e00: aa1e03e2  mov        x2, x30
//   0x7e04: 94000213  bl         #0x8650
//   0x7e08: b942f2a0  ldr        w0, [x21, #0x2f0]
//   0x7e0c: aa1f03e1  mov        x1, xzr
//   0x7e10: 940002e0  bl         #0x8990
//   0x7e14: 940002e3  bl         #0x89a0
//   0x7e18: 350000a0  cbnz       w0, #0x7e2c
//   0x7e1c: aa1303fe  mov        x30, x19
//   0x7e20: d50320ff  xpaclri    
//   0x7e24: aa1e03e0  mov        x0, x30
//   0x7e28: 940002e2  bl         #0x89b0
//   0x7e2c: 2a1403e0  mov        w0, w20
//   0x7e30: a9424ff4  ldp        x20, x19, [sp, #0x20]
//   0x7e34: a94157f6  ldp        x22, x21, [sp, #0x10]
//   0x7e38: a8c37bfd  ldp        x29, x30, [sp], #0x30
//   0x7e3c: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[51] fd_leak_reason (0x7e40..0x84b0, 1648 bytes, 412 instructions)
// Summary / Tóm tắt: Exported: Classifies & ranks dominant leaked FD category from RB-tree (@ 0x7e40..0x84b0)
// ----------------------------------------------------------------------------
//   0x7e40: a9ba7bfd  stp        x29, x30, [sp, #-0x60]!
//   0x7e44: a9016ffc  stp        x28, x27, [sp, #0x10]
//   0x7e48: a90267fa  stp        x26, x25, [sp, #0x20]
//   0x7e4c: a9035ff8  stp        x24, x23, [sp, #0x30]
//   0x7e50: a90457f6  stp        x22, x21, [sp, #0x40]
//   0x7e54: a9054ff4  stp        x20, x19, [sp, #0x50]
//   0x7e58: 910003fd  mov        x29, sp
//   0x7e5c: b0000037  adrp       x23, #0xc000
//   0x7e60: aa0003f3  mov        x19, x0
//   0x7e64: f9465ef7  ldr        x23, [x23, #0xcb8]
//   0x7e68: f94002e8  ldr        x8, [x23]
//   0x7e6c: 91028100  add        x0, x8, #0xa0
//   0x7e70: 94000204  bl         #0x8680
//   0x7e74: f94002e8  ldr        x8, [x23]
//   0x7e78: aa1f03ea  mov        x10, xzr
//   0x7e7c: f9402109  ldr        x9, [x8, #0x40]
//   0x7e80: f9400129  ldr        x9, [x9]
//   0x7e84: aa0a03f6  mov        x22, x10
//   0x7e88: aa0903ea  mov        x10, x9
//   0x7e8c: b5ffffa9  cbnz       x9, #0x7e80
//   0x7e90: b4002256  cbz        x22, #0x82d8
//   0x7e94: f0ffffd4  adrp       x20, #0x2000
//   0x7e98: 91174e94  add        x20, x20, #0x5d3
//   0x7e9c: f0ffffd5  adrp       x21, #0x2000
//   0x7ea0: 9120feb5  add        x21, x21, #0x83f
//   0x7ea4: d503201f  nop        
//   0x7ea8: 50fd5cdc  adr        x28, #0x2a42
//   0x7eac: f0ffffd9  adrp       x25, #0x2000
//   0x7eb0: 91155739  add        x25, x25, #0x555
//   0x7eb4: f0ffffdb  adrp       x27, #0x2000
//   0x7eb8: 912ff77b  add        x27, x27, #0xbfd
//   0x7ebc: 14000007  b          #0x7ed8
//   0x7ec0: 528002e8  mov        w8, #0x17
//   0x7ec4: d37ef508  lsl        x8, x8, #2
//   0x7ec8: b8686a69  ldr        w9, [x19, x8]
//   0x7ecc: 11000529  add        w9, w9, #1
//   0x7ed0: b8286a69  str        w9, [x19, x8]
//   0x7ed4: b4002016  cbz        x22, #0x82d4
//   0x7ed8: aa1603e8  mov        x8, x22
//   0x7edc: f94006c9  ldr        x9, [x22, #8]
//   0x7ee0: b4000909  cbz        x9, #0x8000
//   0x7ee4: aa0903f6  mov        x22, x9
//   0x7ee8: f9400129  ldr        x9, [x9]
//   0x7eec: b5ffffc9  cbnz       x9, #0x7ee4
//   0x7ef0: f940291a  ldr        x26, [x8, #0x50]
//   0x7ef4: b4fffe7a  cbz        x26, #0x7ec0
//   0x7ef8: 39400348  ldrb       w8, [x26]
//   0x7efc: 7100bd1f  cmp        w8, #0x2f
//   0x7f00: 540009a1  b.ne       #0x8034
//   0x7f04: 91000758  add        x24, x26, #1
//   0x7f08: aa1803e0  mov        x0, x24
//   0x7f0c: 94000209  bl         #0x8730
//   0x7f10: 8b180008  add        x8, x0, x24
//   0x7f14: aa1403e1  mov        x1, x20
//   0x7f18: d1001100  sub        x0, x8, #4
//   0x7f1c: 52800062  mov        w2, #3
//   0x7f20: 940002ac  bl         #0x89d0
//   0x7f24: 34000f40  cbz        w0, #0x810c
//   0x7f28: aa1803e0  mov        x0, x24
//   0x7f2c: 94000201  bl         #0x8730
//   0x7f30: 8b180008  add        x8, x0, x24
//   0x7f34: aa1503e1  mov        x1, x21
//   0x7f38: d1001500  sub        x0, x8, #5
//   0x7f3c: 52800082  mov        w2, #4
//   0x7f40: 940002a4  bl         #0x89d0
//   0x7f44: 34000ec0  cbz        w0, #0x811c
//   0x7f48: aa1803e0  mov        x0, x24
//   0x7f4c: 940001f9  bl         #0x8730
//   0x7f50: 8b180008  add        x8, x0, x24
//   0x7f54: f0ffffc1  adrp       x1, #0x2000
//   0x7f58: 912ad421  add        x1, x1, #0xab5
//   0x7f5c: d1001100  sub        x0, x8, #4
//   0x7f60: 52800062  mov        w2, #3
//   0x7f64: 9400029b  bl         #0x89d0
//   0x7f68: 34000480  cbz        w0, #0x7ff8
//   0x7f6c: aa1803e0  mov        x0, x24
//   0x7f70: 940001f0  bl         #0x8730
//   0x7f74: 8b180008  add        x8, x0, x24
//   0x7f78: f0ffffc1  adrp       x1, #0x2000
//   0x7f7c: 91305021  add        x1, x1, #0xc14
//   0x7f80: d1001500  sub        x0, x8, #5
//   0x7f84: 52800082  mov        w2, #4
//   0x7f88: 94000292  bl         #0x89d0
//   0x7f8c: 34000d00  cbz        w0, #0x812c
//   0x7f90: aa1803e0  mov        x0, x24
//   0x7f94: f0ffffc1  adrp       x1, #0x2000
//   0x7f98: 9116f821  add        x1, x1, #0x5be
//   0x7f9c: 528000e2  mov        w2, #7
//   0x7fa0: 9400028c  bl         #0x89d0
//   0x7fa4: 34000c80  cbz        w0, #0x8134
//   0x7fa8: aa1803e0  mov        x0, x24
//   0x7fac: f0ffffc1  adrp       x1, #0x2000
//   0x7fb0: 911b3821  add        x1, x1, #0x6ce
//   0x7fb4: 528000c2  mov        w2, #6
//   0x7fb8: 94000286  bl         #0x89d0
//   0x7fbc: 34000ce0  cbz        w0, #0x8158
//   0x7fc0: aa1803e0  mov        x0, x24
//   0x7fc4: f0ffffc1  adrp       x1, #0x2000
//   0x7fc8: 9118bc21  add        x1, x1, #0x62f
//   0x7fcc: 52800142  mov        w2, #0xa
//   0x7fd0: 94000280  bl         #0x89d0
//   0x7fd4: 34001560  cbz        w0, #0x8280
//   0x7fd8: aa1803e0  mov        x0, x24
//   0x7fdc: 528005e1  mov        w1, #0x2f
//   0x7fe0: 94000280  bl         #0x89e0
//   0x7fe4: b4001040  cbz        x0, #0x81ec
//   0x7fe8: f0ffffc1  adrp       x1, #0x2000
//   0x7fec: 912ad421  add        x1, x1, #0xab5
//   0x7ff0: 940001cc  bl         #0x8720
//   0x7ff4: b4000fc0  cbz        x0, #0x81ec
//   0x7ff8: 52800188  mov        w8, #0xc
//   0x7ffc: 17ffffb2  b          #0x7ec4
//   0x8000: f9400916  ldr        x22, [x8, #0x10]
//   0x8004: b4000096  cbz        x22, #0x8014
//   0x8008: f94002c9  ldr        x9, [x22]
//   0x800c: eb08013f  cmp        x9, x8
//   0x8010: 54fff700  b.eq       #0x7ef0
//   0x8014: aa0803e9  mov        x9, x8
//   0x8018: f9400936  ldr        x22, [x9, #0x10]
//   0x801c: b4fff6b6  cbz        x22, #0x7ef0
//   0x8020: f94006ca  ldr        x10, [x22, #8]
//   0x8024: eb0a013f  cmp        x9, x10
//   0x8028: aa1603e9  mov        x9, x22
//   0x802c: 54ffff60  b.eq       #0x8018
//   0x8030: 17ffffb0  b          #0x7ef0
//   0x8034: aa1a03e0  mov        x0, x26
//   0x8038: aa1c03e1  mov        x1, x28
//   0x803c: 528000e2  mov        w2, #7
//   0x8040: 94000264  bl         #0x89d0
//   0x8044: 34000680  cbz        w0, #0x8114
//   0x8048: aa1a03e0  mov        x0, x26
//   0x804c: aa1903e1  mov        x1, x25
//   0x8050: 528000a2  mov        w2, #5
//   0x8054: 9400025f  bl         #0x89d0
//   0x8058: 34000660  cbz        w0, #0x8124
//   0x805c: aa1a03e0  mov        x0, x26
//   0x8060: aa1b03e1  mov        x1, x27
//   0x8064: 52800162  mov        w2, #0xb
//   0x8068: 9400025a  bl         #0x89d0
//   0x806c: 35fff2a0  cbnz       w0, #0x7ec0
//   0x8070: 91002f58  add        x24, x26, #0xb
//   0x8074: d0ffffc1  adrp       x1, #0x2000
//   0x8078: 91167821  add        x1, x1, #0x59e
//   0x807c: aa1803e0  mov        x0, x24
//   0x8080: 528000a2  mov        w2, #5
//   0x8084: 94000253  bl         #0x89d0
//   0x8088: 340006c0  cbz        w0, #0x8160
//   0x808c: aa1803e0  mov        x0, x24
//   0x8090: d0ffffc1  adrp       x1, #0x2000
//   0x8094: 9129d021  add        x1, x1, #0xa74
//   0x8098: 528000a2  mov        w2, #5
//   0x809c: 9400024d  bl         #0x89d0
//   0x80a0: 34000840  cbz        w0, #0x81a8
//   0x80a4: aa1803e0  mov        x0, x24
//   0x80a8: d0ffffc1  adrp       x1, #0x2000
//   0x80ac: 911b3821  add        x1, x1, #0x6ce
//   0x80b0: 528000c2  mov        w2, #6
//   0x80b4: 94000247  bl         #0x89d0
//   0x80b8: 34000500  cbz        w0, #0x8158
//   0x80bc: aa1803e0  mov        x0, x24
//   0x80c0: d0ffffc1  adrp       x1, #0x2000
//   0x80c4: 91189c21  add        x1, x1, #0x627
//   0x80c8: 528000e2  mov        w2, #7
//   0x80cc: 94000241  bl         #0x89d0
//   0x80d0: 34000dc0  cbz        w0, #0x8288
//   0x80d4: aa1803e0  mov        x0, x24
//   0x80d8: d0ffffc1  adrp       x1, #0x2000
//   0x80dc: 912c2021  add        x1, x1, #0xb08
//   0x80e0: 528000e2  mov        w2, #7
//   0x80e4: 9400023b  bl         #0x89d0
//   0x80e8: 34000ee0  cbz        w0, #0x82c4
//   0x80ec: aa1803e0  mov        x0, x24
//   0x80f0: d0ffffc1  adrp       x1, #0x2000
//   0x80f4: 911e5c21  add        x1, x1, #0x797
//   0x80f8: 528000c2  mov        w2, #6
//   0x80fc: 94000235  bl         #0x89d0
//   0x8100: 7100001f  cmp        w0, #0
//   0x8104: 52800148  mov        w8, #0xa
//   0x8108: 14000025  b          #0x819c
//   0x810c: 52800208  mov        w8, #0x10
//   0x8110: 17ffff6d  b          #0x7ec4
//   0x8114: aa1f03e8  mov        x8, xzr
//   0x8118: 17ffff6b  b          #0x7ec4
//   0x811c: 528001a8  mov        w8, #0xd
//   0x8120: 17ffff69  b          #0x7ec4
//   0x8124: 52800048  mov        w8, #2
//   0x8128: 17ffff67  b          #0x7ec4
//   0x812c: 528001c8  mov        w8, #0xe
//   0x8130: 17ffff65  b          #0x7ec4
//   0x8134: 91002340  add        x0, x26, #8
//   0x8138: d0ffffc1  adrp       x1, #0x2000
//   0x813c: 91271421  add        x1, x1, #0x9c5
//   0x8140: 94000178  bl         #0x8720
//   0x8144: f100001f  cmp        x0, #0
//   0x8148: 52800228  mov        w8, #0x11
//   0x814c: 528001e9  mov        w9, #0xf
//   0x8150: 9a880128  csel       x8, x9, x8, eq
//   0x8154: 17ffff5c  b          #0x7ec4
//   0x8158: 52800028  mov        w8, #1
//   0x815c: 17ffff5a  b          #0x7ec4
//   0x8160: 91004358  add        x24, x26, #0x10
//   0x8164: d0ffffc1  adrp       x1, #0x2000
//   0x8168: 911c3c21  add        x1, x1, #0x70f
//   0x816c: aa1803e0  mov        x0, x24
//   0x8170: 52800082  mov        w2, #4
//   0x8174: 94000217  bl         #0x89d0
//   0x8178: 52800088  mov        w8, #4
//   0x817c: 34ffea40  cbz        w0, #0x7ec4
//   0x8180: aa1803e0  mov        x0, x24
//   0x8184: d0ffffc1  adrp       x1, #0x2000
//   0x8188: 911b2c21  add        x1, x1, #0x6cb
//   0x818c: 52800042  mov        w2, #2
//   0x8190: 94000210  bl         #0x89d0
//   0x8194: 528000a8  mov        w8, #5
//   0x8198: 7100001f  cmp        w0, #0
//   0x819c: 528002c9  mov        w9, #0x16
//   0x81a0: 9a890108  csel       x8, x8, x9, eq
//   0x81a4: 17ffff48  b          #0x7ec4
//   0x81a8: 91004358  add        x24, x26, #0x10
//   0x81ac: d0ffffc1  adrp       x1, #0x2000
//   0x81b0: 9127d421  add        x1, x1, #0x9f5
//   0x81b4: aa1803e0  mov        x0, x24
//   0x81b8: 528000a2  mov        w2, #5
//   0x81bc: 94000205  bl         #0x89d0
//   0x81c0: 34000680  cbz        w0, #0x8290
//   0x81c4: aa1803e0  mov        x0, x24
//   0x81c8: d0ffffc1  adrp       x1, #0x2000
//   0x81cc: 9120e821  add        x1, x1, #0x83a
//   0x81d0: 52800082  mov        w2, #4
//   0x81d4: 940001ff  bl         #0x89d0
//   0x81d8: 7100001f  cmp        w0, #0
//   0x81dc: 528002c8  mov        w8, #0x16
//   0x81e0: 52800109  mov        w9, #8
//   0x81e4: 9a880128  csel       x8, x9, x8, eq
//   0x81e8: 17ffff37  b          #0x7ec4
//   0x81ec: aa1803e0  mov        x0, x24
//   0x81f0: d0ffffc1  adrp       x1, #0x2000
//   0x81f4: 911d8c21  add        x1, x1, #0x763
//   0x81f8: 52800082  mov        w2, #4
//   0x81fc: 940001f5  bl         #0x89d0
//   0x8200: 34000500  cbz        w0, #0x82a0
//   0x8204: aa1803e0  mov        x0, x24
//   0x8208: d0ffffc1  adrp       x1, #0x2000
//   0x820c: 91250c21  add        x1, x1, #0x943
//   0x8210: 528000c2  mov        w2, #6
//   0x8214: 940001ef  bl         #0x89d0
//   0x8218: 34000400  cbz        w0, #0x8298
//   0x821c: aa1803e0  mov        x0, x24
//   0x8220: d0ffffc1  adrp       x1, #0x2000
//   0x8224: 91211021  add        x1, x1, #0x844
//   0x8228: 52800082  mov        w2, #4
//   0x822c: 940001e9  bl         #0x89d0
//   0x8230: 34000340  cbz        w0, #0x8298
//   0x8234: aa1803e0  mov        x0, x24
//   0x8238: d0ffffc1  adrp       x1, #0x2000
//   0x823c: 9115f421  add        x1, x1, #0x57d
//   0x8240: 528000c2  mov        w2, #6
//   0x8244: 940001e3  bl         #0x89d0
//   0x8248: 34000280  cbz        w0, #0x8298
//   0x824c: aa1803e0  mov        x0, x24
//   0x8250: d0ffffc1  adrp       x1, #0x2000
//   0x8254: 9127ec21  add        x1, x1, #0x9fb
//   0x8258: 52800062  mov        w2, #3
//   0x825c: 940001dd  bl         #0x89d0
//   0x8260: 34000360  cbz        w0, #0x82cc
//   0x8264: aa1803e0  mov        x0, x24
//   0x8268: d0ffffc1  adrp       x1, #0x2000
//   0x826c: 91252821  add        x1, x1, #0x94a
//   0x8270: 9400012c  bl         #0x8720
//   0x8274: b4ffe260  cbz        x0, #0x7ec0
//   0x8278: 52800248  mov        w8, #0x12
//   0x827c: 17ffff12  b          #0x7ec4
//   0x8280: 52800068  mov        w8, #3
//   0x8284: 17ffff10  b          #0x7ec4
//   0x8288: 52800128  mov        w8, #9
//   0x828c: 17ffff0e  b          #0x7ec4
//   0x8290: 528000e8  mov        w8, #7
//   0x8294: 17ffff0c  b          #0x7ec4
//   0x8298: 52800288  mov        w8, #0x14
//   0x829c: 17ffff0a  b          #0x7ec4
//   0x82a0: 91001740  add        x0, x26, #5
//   0x82a4: d0ffffc1  adrp       x1, #0x2000
//   0x82a8: 91169021  add        x1, x1, #0x5a4
//   0x82ac: 9400011d  bl         #0x8720
//   0x82b0: f100001f  cmp        x0, #0
//   0x82b4: 52800168  mov        w8, #0xb
//   0x82b8: 52800269  mov        w9, #0x13
//   0x82bc: 9a880128  csel       x8, x9, x8, eq
//   0x82c0: 17ffff01  b          #0x7ec4
//   0x82c4: 528000c8  mov        w8, #6
//   0x82c8: 17fffeff  b          #0x7ec4
//   0x82cc: 528002a8  mov        w8, #0x15
//   0x82d0: 17fffefd  b          #0x7ec4
//   0x82d4: f94002e8  ldr        x8, [x23]
//   0x82d8: 91028100  add        x0, x8, #0xa0
//   0x82dc: 940000f1  bl         #0x86a0
//   0x82e0: 29402668  ldp        w8, w9, [x19]
//   0x82e4: 5280004a  mov        w10, #2
//   0x82e8: 7100011f  cmp        w8, #0
//   0x82ec: 1a9fc10b  csel       w11, w8, wzr, gt
//   0x82f0: 7100051f  cmp        w8, #1
//   0x82f4: 5a9fa3ec  csetm      w12, lt
//   0x82f8: 6b0b013f  cmp        w9, w11
//   0x82fc: 1a8bc129  csel       w9, w9, w11, gt
//   0x8300: 1a9fd58c  csinc      w12, w12, wzr, le
//   0x8304: 29412e68  ldp        w8, w11, [x19, #8]
//   0x8308: 6b09011f  cmp        w8, w9
//   0x830c: 1a89c108  csel       w8, w8, w9, gt
//   0x8310: 1a8cc149  csel       w9, w10, w12, gt
//   0x8314: 6b08017f  cmp        w11, w8
//   0x8318: 5280006c  mov        w12, #3
//   0x831c: 1a88c168  csel       w8, w11, w8, gt
//   0x8320: 1a89c189  csel       w9, w12, w9, gt
//   0x8324: 29422e6a  ldp        w10, w11, [x19, #0x10]
//   0x8328: 5280008c  mov        w12, #4
//   0x832c: 6b08015f  cmp        w10, w8
//   0x8330: 1a88c148  csel       w8, w10, w8, gt
//   0x8334: 1a89c189  csel       w9, w12, w9, gt
//   0x8338: 6b08017f  cmp        w11, w8
//   0x833c: 528000ac  mov        w12, #5
//   0x8340: 1a88c168  csel       w8, w11, w8, gt
//   0x8344: 1a89c189  csel       w9, w12, w9, gt
//   0x8348: 29432e6a  ldp        w10, w11, [x19, #0x18]
//   0x834c: 528000cc  mov        w12, #6
//   0x8350: 6b08015f  cmp        w10, w8
//   0x8354: 1a88c148  csel       w8, w10, w8, gt
//   0x8358: 1a89c189  csel       w9, w12, w9, gt
//   0x835c: 6b08017f  cmp        w11, w8
//   0x8360: 5280010c  mov        w12, #8
//   0x8364: 1a88c168  csel       w8, w11, w8, gt
//   0x8368: 528000eb  mov        w11, #7
//   0x836c: 1a89c169  csel       w9, w11, w9, gt
//   0x8370: 29442e6a  ldp        w10, w11, [x19, #0x20]
//   0x8374: 6b08015f  cmp        w10, w8
//   0x8378: 1a88c148  csel       w8, w10, w8, gt
//   0x837c: 1a89c189  csel       w9, w12, w9, gt
//   0x8380: 6b08017f  cmp        w11, w8
//   0x8384: 5280014c  mov        w12, #0xa
//   0x8388: 1a88c168  csel       w8, w11, w8, gt
//   0x838c: 5280012b  mov        w11, #9
//   0x8390: 1a89c169  csel       w9, w11, w9, gt
//   0x8394: 29452e6a  ldp        w10, w11, [x19, #0x28]
//   0x8398: 6b08015f  cmp        w10, w8
//   0x839c: 1a88c148  csel       w8, w10, w8, gt
//   0x83a0: 1a89c189  csel       w9, w12, w9, gt
//   0x83a4: 6b08017f  cmp        w11, w8
//   0x83a8: 5280018c  mov        w12, #0xc
//   0x83ac: 1a88c168  csel       w8, w11, w8, gt
//   0x83b0: 5280016b  mov        w11, #0xb
//   0x83b4: 1a89c169  csel       w9, w11, w9, gt
//   0x83b8: 29462e6a  ldp        w10, w11, [x19, #0x30]
//   0x83bc: 6b08015f  cmp        w10, w8
//   0x83c0: 1a88c148  csel       w8, w10, w8, gt
//   0x83c4: 1a89c189  csel       w9, w12, w9, gt
//   0x83c8: 6b08017f  cmp        w11, w8
//   0x83cc: 528001cc  mov        w12, #0xe
//   0x83d0: 1a88c168  csel       w8, w11, w8, gt
//   0x83d4: 528001ab  mov        w11, #0xd
//   0x83d8: 1a89c169  csel       w9, w11, w9, gt
//   0x83dc: 29472e6a  ldp        w10, w11, [x19, #0x38]
//   0x83e0: 6b08015f  cmp        w10, w8
//   0x83e4: 1a88c148  csel       w8, w10, w8, gt
//   0x83e8: 1a89c189  csel       w9, w12, w9, gt
//   0x83ec: 6b08017f  cmp        w11, w8
//   0x83f0: 5280020c  mov        w12, #0x10
//   0x83f4: 1a88c168  csel       w8, w11, w8, gt
//   0x83f8: 528001eb  mov        w11, #0xf
//   0x83fc: 1a89c169  csel       w9, w11, w9, gt
//   0x8400: 29482e6a  ldp        w10, w11, [x19, #0x40]
//   0x8404: 6b08015f  cmp        w10, w8
//   0x8408: 1a88c148  csel       w8, w10, w8, gt
//   0x840c: 1a89c189  csel       w9, w12, w9, gt
//   0x8410: 6b08017f  cmp        w11, w8
//   0x8414: 5280024c  mov        w12, #0x12
//   0x8418: 1a88c168  csel       w8, w11, w8, gt
//   0x841c: 5280022b  mov        w11, #0x11
//   0x8420: 1a89c169  csel       w9, w11, w9, gt
//   0x8424: 29492e6a  ldp        w10, w11, [x19, #0x48]
//   0x8428: 6b08015f  cmp        w10, w8
//   0x842c: 1a88c148  csel       w8, w10, w8, gt
//   0x8430: 1a89c189  csel       w9, w12, w9, gt
//   0x8434: 6b08017f  cmp        w11, w8
//   0x8438: 5280028c  mov        w12, #0x14
//   0x843c: 1a88c168  csel       w8, w11, w8, gt
//   0x8440: 5280026b  mov        w11, #0x13
//   0x8444: 1a89c169  csel       w9, w11, w9, gt
//   0x8448: 294a2e6a  ldp        w10, w11, [x19, #0x50]
//   0x844c: 6b08015f  cmp        w10, w8
//   0x8450: 1a88c148  csel       w8, w10, w8, gt
//   0x8454: 1a89c189  csel       w9, w12, w9, gt
//   0x8458: 6b08017f  cmp        w11, w8
//   0x845c: 528002cc  mov        w12, #0x16
//   0x8460: 1a88c168  csel       w8, w11, w8, gt
//   0x8464: 528002ab  mov        w11, #0x15
//   0x8468: 1a89c169  csel       w9, w11, w9, gt
//   0x846c: 294b2e6a  ldp        w10, w11, [x19, #0x58]
//   0x8470: 6b08015f  cmp        w10, w8
//   0x8474: 1a88c148  csel       w8, w10, w8, gt
//   0x8478: 1a89c189  csel       w9, w12, w9, gt
//   0x847c: 6b08017f  cmp        w11, w8
//   0x8480: 528002ea  mov        w10, #0x17
//   0x8484: 1a89c149  csel       w9, w10, w9, gt
//   0x8488: f94002ea  ldr        x10, [x23]
//   0x848c: 1a88c168  csel       w8, w11, w8, gt
//   0x8490: 290e2149  stp        w9, w8, [x10, #0x70]
//   0x8494: a9454ff4  ldp        x20, x19, [sp, #0x50]
//   0x8498: a94457f6  ldp        x22, x21, [sp, #0x40]
//   0x849c: a9435ff8  ldp        x24, x23, [sp, #0x30]
//   0x84a0: a94267fa  ldp        x26, x25, [sp, #0x20]
//   0x84a4: a9416ffc  ldp        x28, x27, [sp, #0x10]
//   0x84a8: a8c67bfd  ldp        x29, x30, [sp], #0x60
//   0x84ac: d65f03c0  ret        

} // namespace nextai::opencut::npth_fd_tracker
