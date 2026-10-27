// ============================================================================
// Clean-Room C++17 Core Interfaces for libquick.so (Target 116 / 169)
// Giao diện lõi C++17 sạch cho libquick.so (Mục tiêu 116 / 169)
// ============================================================================
#pragma once

#include "quick_types.h"

// Exported Heap Object Metadata Bitfield Functions (0x068440..0x068a90)
// Các hàm trường bit siêu dữ liệu đối tượng Heap xuất khẩu (0x068440..0x068a90)
void clear_mark(void* ptr) noexcept;
bool is_marked(void* ptr) noexcept;
bool is_marked_multi(void* ptr) noexcept;
int32_t get_alloc_tag(void* ptr) noexcept;
int32_t get_tag(void* ptr) noexcept;
void set_mark_multi(void* ptr) noexcept;
void set_alloc_tag(void* ptr, int32_t tag) noexcept;
void set_heap_obj_len(void* ptr, int32_t len) noexcept;
void set_hash_size(void* ptr, int32_t len) noexcept;
int32_t get_heap_obj_len(void* ptr) noexcept;
int32_t get_hash_size(void* ptr) noexcept;

// Reconstructed from 0x068a94..0x0690c4 (GarbageCollector)
// Tái dựng từ 0x068a94..0x0690c4 (GarbageCollector)
class GarbageCollector {
public:
    GarbageCollector(LEPUSRuntime* rt, malloc_state* state);
    ~GarbageCollector();

    void Init(LEPUSRuntime* rt);
    LEPUSRuntime* runtime() const noexcept { return runtime_; }
    malloc_state* state() const noexcept { return state_; }

private:
    int32_t status_{0};            // +0x00
    LEPUSRuntime* runtime_{nullptr}; // +0x08
    malloc_state* state_{nullptr}; // +0x28
    int32_t gc_phase_{-1};         // +0x150
};

// Reconstructed from 0x069f10..0x06a2b0 (GlobalHandles & NodeSpace)
// Tái dựng từ 0x069f10..0x06a2b0 (GlobalHandles & NodeSpace)
class GlobalHandles {
public:
    struct Node {
        LEPUSValue value{};
        void* parameter{nullptr};
        void (*finalizer)(void*){nullptr};
        Node* next_free{nullptr};
        uint8_t flags{0};
        uint8_t reserved[7]{0};
    };

    struct NodeBlock {
        Node nodes[256];              // +0x0000 .. +0x27ff (256 * 40 = 10,240 bytes)
        NodeBlock* next_block{nullptr}; // +0x2800
        GlobalHandles* global_handles{nullptr}; // +0x2808
        NodeBlock* next_used{nullptr};  // +0x2810
        NodeBlock* prev_used{nullptr};  // +0x2818
        uint32_t used_nodes{0};       // +0x2820
        uint32_t reserved{0};         // +0x2824
        void* owner_space{nullptr};   // +0x2828
    };

    class NodeSpace {
    public:
        explicit NodeSpace(GlobalHandles* owner) noexcept
            : owner_(owner), first_block_(nullptr), first_used_block_(nullptr),
              free_list_head_(nullptr), block_count_(0), handles_count_(0) {}
        ~NodeSpace();

        void PutNodesOnFreeList(NodeBlock* block) noexcept;
        void Release(Node* node) noexcept;

        GlobalHandles* owner_{nullptr};    // +0x00
        NodeBlock* first_block_{nullptr};  // +0x08
        NodeBlock* first_used_block_{nullptr}; // +0x10
        Node* free_list_head_{nullptr};    // +0x18
        size_t block_count_{0};            // +0x20
        size_t handles_count_{0};          // +0x28
    };

    // 0x06a04c..0x06a080
    explicit GlobalHandles(LEPUSRuntime* rt);
    // 0x06a084..0x06a0c4
    ~GlobalHandles();

    // 0x06a018..0x06a048
    size_t TotalSize() const noexcept;
    size_t UsedSize() const noexcept;
    size_t handles_count() const noexcept;

    // 0x06a0c8..0x06a2ac
    LEPUSValue* Create(LEPUSValue value, bool is_weak);
    void Destroy(LEPUSValue* location) noexcept;
    void SetWeak(LEPUSValue* location, void* parameter, void (*cb)(void*)) noexcept;
    void ClearWeak(LEPUSValue* location) noexcept;
    void SetWeakState(LEPUSValue* location) noexcept;

private:
    LEPUSRuntime* runtime_{nullptr}; // +0x00
    uint8_t is_marking_{0};          // +0x08
    NodeSpace* node_space_{nullptr}; // +0x10
};

namespace vmsdk {
namespace general {
namespace logging {
bool RegisterJNI(void* env);
void* GetALogPtr();
void InternalLogFromJava(int32_t level, const char* tag, const char* msg);
} // namespace logging

namespace monitor {
namespace android {
class VmSdkMonitorAndroid {
public:
    static bool RegisterJNI(void* env);
    static void MonitorEvent(const char* p0, const char* p1, const char* p2, const char* p3);
    static std::string GetSettingsWithKey(const char* key);
    static int32_t GetSettingsFlag();
};
} // namespace android
} // namespace monitor
} // namespace vmsdk

uint64_t execute_fde_shard_1(uint32_t fde_idx, uint64_t a0, uint64_t a1);
uint64_t execute_fde_shard_2(uint32_t fde_idx, uint64_t a0, uint64_t a1);
uint64_t execute_fde_shard_3(uint32_t fde_idx, uint64_t a0, uint64_t a1);
uint64_t execute_fde_shard_4(uint32_t fde_idx, uint64_t a0, uint64_t a1);
uint64_t execute_fde_shard_5(uint32_t fde_idx, uint64_t a0, uint64_t a1);
