// ============================================================================
// Clean-Room C++17 Core Implementation for libquick.so (Target 116 / 169)
// Hiện thực C++17 sạch lõi cho libquick.so (Heap Bitfields, GarbageCollector, GlobalHandles)
// ============================================================================
#include "quick_core.h"
#include <cstdlib>
#include <cstring>

// 0x068440..0x068444: str wzr, [x0, #-4]; ret
void clear_mark(void* ptr) noexcept {
    if (!ptr) return;
    auto* mark_ptr = reinterpret_cast<uint32_t*>( static_cast<uint8_t*>(ptr) - 4 );
    *mark_ptr = 0;
}

// 0x068a28..0x068a34: ldur w8, [x0, #-4]; cmp w8, #0; cset w0, ne; ret
bool is_marked(void* ptr) noexcept {
    if (!ptr) return false;
    const auto* mark_ptr = reinterpret_cast<const uint32_t*>( static_cast<const uint8_t*>(ptr) - 4 );
    return (*mark_ptr) != 0;
}

bool is_marked_multi(void* ptr) noexcept {
    return is_marked(ptr);
}

// 0x068a38..0x068a40: ldur w8, [x0, #-8]; and w0, w8, #0x3f; ret
int32_t get_alloc_tag(void* ptr) noexcept {
    if (!ptr) return 0;
    const auto* hdr_ptr = reinterpret_cast<const uint32_t*>( static_cast<const uint8_t*>(ptr) - 8 );
    return static_cast<int32_t>((*hdr_ptr) & kHeapObjTagMask);
}

int32_t get_tag(void* ptr) noexcept {
    return get_alloc_tag(ptr);
}

// 0x068a44..0x068a4c: mov w8, #1; stur w8, [x0, #-4]; ret
void set_mark_multi(void* ptr) noexcept {
    if (!ptr) return;
    auto* mark_ptr = reinterpret_cast<uint32_t*>( static_cast<uint8_t*>(ptr) - 4 );
    *mark_ptr = 1U;
}

// 0x068a50..0x068a60: ldur w8, [x0, #-8]; and w8, w8, #0xffffffc0; orr w8, w8, w1; stur w8, [x0, #-8]; ret
void set_alloc_tag(void* ptr, int32_t tag) noexcept {
    if (!ptr) return;
    auto* hdr_ptr = reinterpret_cast<uint32_t*>( static_cast<uint8_t*>(ptr) - 8 );
    uint32_t w8 = *hdr_ptr;
    w8 = (w8 & 0xFFFFFFC0U) | (static_cast<uint32_t>(tag) & kHeapObjTagMask);
    *hdr_ptr = w8;
}

// 0x068a64..0x068a84: mov w8, #0x2000000; cmp w1, w8; b.lt; ... bfi w8, w1, #6, #0x1a; stur w8, [x0, #-8]; ret
void set_heap_obj_len(void* ptr, int32_t len) noexcept {
    if (!ptr) return;
    if (static_cast<uint32_t>(len) >= kHeapObjMaxLen) {
        std::abort(); // 0x068a70: mov w8, #0xdead; str wzr, [x8]
    }
    auto* hdr_ptr = reinterpret_cast<uint32_t*>( static_cast<uint8_t*>(ptr) - 8 );
    uint32_t w8 = *hdr_ptr;
    w8 = (w8 & kHeapObjTagMask) | (static_cast<uint32_t>(len) << kHeapObjLenShift);
    *hdr_ptr = w8;
}

void set_hash_size(void* ptr, int32_t len) noexcept {
    set_heap_obj_len(ptr, len);
}

// 0x068a88..0x068a90: ldur w8, [x0, #-8]; asr w0, w8, #6; ret
int32_t get_heap_obj_len(void* ptr) noexcept {
    if (!ptr) return 0;
    const auto* hdr_ptr = reinterpret_cast<const int32_t*>( static_cast<const uint8_t*>(ptr) - 8 );
    return (*hdr_ptr) >> kHeapObjLenShift;
}

int32_t get_hash_size(void* ptr) noexcept {
    return get_heap_obj_len(ptr);
}

// 0x068a94..0x068ba0: GarbageCollector
GarbageCollector::GarbageCollector(LEPUSRuntime* rt, malloc_state* state)
    : status_(0), runtime_(rt), state_(state), gc_phase_(-1) {}

GarbageCollector::~GarbageCollector() = default;

void GarbageCollector::Init(LEPUSRuntime* rt) {
    runtime_ = rt;
    status_ = 0;
}

// 0x069f28..0x06a2ac: GlobalHandles & NodeSpace
GlobalHandles::NodeSpace::~NodeSpace() {
    NodeBlock* cur = first_block_;
    while (cur) {
        NodeBlock* next = cur->next_block; // [x0, #0x2800] @ 0x06a09c
        delete cur;
        cur = next;
    }
}

void GlobalHandles::NodeSpace::PutNodesOnFreeList(NodeBlock* block) noexcept {
    if (!block) return;
    for (int32_t i = 255; i >= 0; --i) {
        block->nodes[i].next_free = free_list_head_;
        free_list_head_ = &block->nodes[i];
    }
}

void GlobalHandles::NodeSpace::Release(Node* node) noexcept {
    if (!node) return;
    node->value = LEPUSValue{};
    node->parameter = nullptr;
    node->finalizer = nullptr;
    node->flags = 0;
    node->next_free = free_list_head_;
    free_list_head_ = node;
    if (handles_count_ > 0) {
        --handles_count_;
    }
}

// 0x06a04c..0x06a080
GlobalHandles::GlobalHandles(LEPUSRuntime* rt)
    : runtime_(rt), is_marking_(0), node_space_(new NodeSpace(this)) {}

// 0x06a084..0x06a0c4
GlobalHandles::~GlobalHandles() {
    delete node_space_;
    node_space_ = nullptr;
}

// 0x06a018..0x06a028: (block_count_ * 5) << 11 = block_count_ * 10240 (0x2800)
size_t GlobalHandles::TotalSize() const noexcept {
    if (!node_space_) return 0;
    return (node_space_->block_count_ * 5ULL) << 11;
}

// 0x06a02c..0x06a03c: (handles_count_ * 5) << 3 = handles_count_ * 40
size_t GlobalHandles::UsedSize() const noexcept {
    if (!node_space_) return 0;
    return (node_space_->handles_count_ * 5ULL) << 3;
}

// 0x06a040..0x06a048: ldr x0, [node_space_, #0x28]
size_t GlobalHandles::handles_count() const noexcept {
    if (!node_space_) return 0;
    return node_space_->handles_count_;
}

// 0x06a0c8..0x06a1df: GlobalHandles::Create
LEPUSValue* GlobalHandles::Create(LEPUSValue value, bool is_weak) {
    if (!node_space_->free_list_head_) {
        auto* block = new NodeBlock();
        block->next_block = node_space_->first_block_;
        block->global_handles = this;
        block->owner_space = node_space_;
        node_space_->first_block_ = block;
        ++node_space_->block_count_;
        node_space_->PutNodesOnFreeList(block);
    }
    Node* node = node_space_->free_list_head_;
    node_space_->free_list_head_ = node->next_free;
    node->value = value;
    node->flags = is_weak ? 1 : 0;
    ++node_space_->handles_count_;
    return &node->value;
}

void GlobalHandles::Destroy(LEPUSValue* location) noexcept {
    if (!location || !node_space_) return;
    auto* node = reinterpret_cast<Node*>(location);
    node_space_->Release(node);
}

void GlobalHandles::SetWeak(LEPUSValue* location, void* parameter, void (*cb)(void*)) noexcept {
    if (!location) return;
    auto* node = reinterpret_cast<Node*>(location);
    node->parameter = parameter;
    node->finalizer = cb;
    node->flags |= 2;
}

void GlobalHandles::ClearWeak(LEPUSValue* location) noexcept {
    if (!location) return;
    auto* node = reinterpret_cast<Node*>(location);
    node->parameter = nullptr;
    node->finalizer = nullptr;
    node->flags &= ~2;
}

void GlobalHandles::SetWeakState(LEPUSValue* location) noexcept {
    if (!location) return;
    auto* node = reinterpret_cast<Node*>(location);
    node->flags |= 4;
}
