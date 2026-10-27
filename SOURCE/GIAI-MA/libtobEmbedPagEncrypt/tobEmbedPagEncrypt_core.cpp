// ============================================================================
// Clean-Room C++17 Implementation of libtobEmbedPagEncrypt.so (Target 127 / 169)
// Hiện thực hóa C++17 sạch của libtobEmbedPagEncrypt.so (Mục tiêu 127 / 169)
// ============================================================================
#include "tobEmbedPagEncrypt_core.h"

namespace tob_embed_pag_encrypt {

namespace {
// .bss 0x009830..0x009844 (20 bytes + null terminator safety)
alignas(16) char g_bss_key_0x9830[24] = {};

template <typename FnType>
inline FnType LoadEnvVtableSlot(JNIEnv* env, size_t offset) noexcept {
    if (!env) return nullptr;
    const auto* vtable = *reinterpret_cast<const uint8_t* const*>(env);
    if (!vtable) return nullptr;
    FnType fn = nullptr;
    std::memcpy(&fn, vtable + offset, sizeof(FnType));
    return fn;
}
} // namespace

const char* GetGlobalBssKeyBuffer() noexcept {
    return g_bss_key_0x9830;
}

// ----------------------------------------------------------------------------
// Internal Function `sub_d0c` (`0x000d0c..0x000ea0`, 404 bytes):
//   1. Clamps `copy_len = (key_len < 16) ? key_len : 16` (`cmp w21, #0x10; csel w9, w21, w9, lt` @ 0x0d2c..0x0d34)
//      and copies `raw_key[0..copy_len-1]` into `key_bytes[0..15]`.
//   2. If `key_len <= 15` (`cmp w21, #0xf; b.gt #0xd90` @ 0x0d54..0x0d58):
//      pads `key_bytes[i] = sbox1[key_bytes[i - 1]]` for `i = copy_len .. 15` (@ 0x0d7c..0x0d8c).
//   3. Substitutes all 16 bytes through `sbox0[b]` (@ 0x0d94..0x0e64) and byte-swaps each of the
//      4 32-bit words via `rev` (`0x0e58..0x0e74`)!
//      Note the exact instruction ordering at `0x0e04`: `ldp w11, w12, [x19]` is executed right before
//      `strb w9, [x19, #8]`, when bytes `0..7` (`w11, w12`) have already been substituted with `sbox0`!
// ----------------------------------------------------------------------------
void DeriveRoundKeys128(const uint8_t* raw_key, int32_t key_len, uint32_t out_k[4]) noexcept {
    uint8_t key_bytes[16] = {};
    const int32_t copy_len = (key_len < 16) ? ((key_len > 0) ? key_len : 0) : 16;
    if (raw_key && copy_len > 0) {
        std::memcpy(key_bytes, raw_key, static_cast<size_t>(copy_len));
    }
    if (key_len <= 15 && copy_len >= 1) {
        for (int32_t i = copy_len; i < 16; ++i) {
            key_bytes[i] = sbox1[key_bytes[i - 1]];
        }
    }
    for (int i = 0; i < 16; ++i) {
        key_bytes[i] = sbox0[key_bytes[i]];
    }
    for (int w = 0; w < 4; ++w) {
        uint32_t word_le = 0;
        std::memcpy(&word_le, key_bytes + w * 4, sizeof(uint32_t));
        out_k[w] = ByteSwap32(word_le);
    }
}

} // namespace tob_embed_pag_encrypt

extern "C" {

// ----------------------------------------------------------------------------
// Export [11] `ss_encrypted_size` (`0x000ad0..0x000b44`, 116 bytes):
//   0x0ae4: 11003C08  add  w8, w0, #0xf
//   0x0ae8: 7100001F  cmp  w0, #0
//   0x0aec: 1A80B108  csel w8, w8, w0, lt
//   0x0af0: 121C6D08  and  w8, w8, #0xfffffff0
//   0x0af8: 4B08000D  sub  w13, w0, w8          ; w13 = in_size % 16 (signed)
//   0x0b00: 4B0D0148  sub  w8, w10, w13         ; w8  = 16 - (in_size % 16)
//   ...
//   0x0b2c: 4B090108  sub  w8, w8, w9           ; w8  = (16 - (in_size % 16)) % 16
//   0x0b30: 0B080008  add  w8, w0, w8           ; w8  = in_size + pad_len
//   0x0b34: 11001900  add  w0, w8, #6           ; return in_size + pad_len + 6
// ----------------------------------------------------------------------------
int32_t ss_encrypted_size(int32_t in_size) {
    const int32_t rem16 = in_size % 16;
    const int32_t diff16 = (16 - rem16) % 16;
    return in_size + diff16 + tob_embed_pag_encrypt::kTcHeaderBytes;
}

// ----------------------------------------------------------------------------
// Export [12] `initKey` (`0x001018..0x001070`, 88 bytes):
//   0x1030: 3DC24160  ldr  q0, [x11, #0x900]     ; "UK*@3oKpFlVVnads"
//   0x1038: 528CCA8B  mov  w11, #0x6654
//   0x1040: 72A82C8B  movk w11, #0x4164, lsl #16 ; 0x41646654 ("Tfda")
//   0x1048: B900112B  str  w11, [x9, #0x10]
//   0x104c: 3D800120  str  q0, [x9]              ; .bss 0x009830
// ----------------------------------------------------------------------------
void initKey() {
    char* dst = const_cast<char*>(tob_embed_pag_encrypt::GetGlobalBssKeyBuffer());
    std::memcpy(dst, tob_embed_pag_encrypt::kDefaultEmbedPagKey20B, 20);
    dst[20] = '\0';
}

// ----------------------------------------------------------------------------
// Export [15] `ss_encrypt` (`0x000b44..0x000d0c`, 456 bytes):
//   1. Checks `key_len >= 1`, `key != nullptr`, `in_len >= 1`, `out_buf != nullptr` (else returns -1).
//   2. Calls `DeriveRoundKeys128(key, key_len, k)` (@ 0x0ba8).
//   3. Computes `pad_len = (-in_len) & 0x0F` (@ 0x0bac..0x0bb4), `padded_len = in_len + pad_len`,
//      `total_len = padded_len + 6`.
//   4. Copies `in_buf[0..in_len-1]` to `out_buf + 6` via `memmove` (@ 0x0bcc), zeroing any trailing pad bytes.
//   5. Writes 6-byte header at `out_buf[0..5]` (@ 0x0bd0..0x0bec):
//      `{'t', 'c', 0x03, static_cast<uint8_t>(pad_len), 0x00, 0x01}`.
//   6. Applies `sbox0` byte-by-byte to `out_buf[6 .. total_len - 1]` (@ 0x0bf4..0x0c14).
//   7. For each 16-byte block `(W0, W1, W2, W3)` at `out_buf + 6 + 16*b` (`b = 0 .. (padded_len >> 4) - 1`):
//        W0' = rev(rev(W0) ^ k[0])
//        W1' = rev(k[1] ^ ror(rev(W1), 24))
//        W2' = rev(k[2] ^ ror(rev(W2), 16))
//        W3' = rev(k[3] ^ ror(rev(W3),  8))
//      Returns 0 (`mov w0, wzr` @ 0x0cd4).
// ----------------------------------------------------------------------------
int32_t ss_encrypt(
    const uint8_t* in_buf,
    int32_t in_len,
    const uint8_t* key,
    int32_t key_len,
    uint8_t* out_buf) {
    using namespace tob_embed_pag_encrypt;
    if (key_len < 1 || !key || in_len < 1 || !out_buf || !in_buf) {
        return kErrInvalidArgs;
    }

    uint32_t k[4] = {};
    DeriveRoundKeys128(key, key_len, k);

    const uint32_t pad_len    = static_cast<uint32_t>(-in_len) & 0x0FU;
    const int32_t  padded_len = in_len + static_cast<int32_t>(pad_len);
    const int32_t  total_len  = padded_len + kTcHeaderBytes;

    std::memset(out_buf + kTcHeaderBytes + in_len, 0, pad_len);
    std::memmove(out_buf + kTcHeaderBytes, in_buf, static_cast<size_t>(in_len));

    // Write 6-byte header (`0x0bd0..0x0bec`)
    const uint16_t magic = kTcHeaderMagic16;
    const uint16_t flags = kTcHeaderFlags16;
    std::memcpy(out_buf + 0, &magic, sizeof(uint16_t));
    out_buf[2] = kTcHeaderVersion;
    out_buf[3] = static_cast<uint8_t>(pad_len);
    std::memcpy(out_buf + 4, &flags, sizeof(uint16_t));

    // Forward S-Box pass over payload (`0x0bf4..0x0c14`)
    for (int32_t i = kTcHeaderBytes; i < total_len; ++i) {
        out_buf[i] = sbox0[out_buf[i]];
    }

    // 16-byte Block XOR & Rotation pass (`0x0c18..0x0cd0`)
    const int32_t num_blocks = padded_len >> 4;
    for (int32_t b = 0; b < num_blocks; ++b) {
        uint8_t* blk = out_buf + kTcHeaderBytes + b * 16;
        uint32_t w0 = 0, w1 = 0, w2 = 0, w3 = 0;
        std::memcpy(&w0, blk +  0, 4);
        std::memcpy(&w1, blk +  4, 4);
        std::memcpy(&w2, blk +  8, 4);
        std::memcpy(&w3, blk + 12, 4);

        const uint32_t out_w0 = ByteSwap32(ByteSwap32(w0) ^ k[0]);
        const uint32_t rev_w1 = ByteSwap32(w1);
        const uint32_t out_w1 = ByteSwap32(k[1] ^ Ror32(rev_w1, 24));
        const uint32_t rev_w2 = ByteSwap32(w2);
        const uint32_t out_w2 = ByteSwap32(k[2] ^ Ror32(rev_w2, 16));
        const uint32_t rev_w3 = ByteSwap32(w3);
        const uint32_t out_w3 = ByteSwap32(k[3] ^ Ror32(rev_w3, 8));

        std::memcpy(blk +  0, &out_w0, 4);
        std::memcpy(blk +  4, &out_w1, 4);
        std::memcpy(blk +  8, &out_w2, 4);
        std::memcpy(blk + 12, &out_w3, 4);
    }

    return 0;
}

// ----------------------------------------------------------------------------
// Export [14] `ss_decrypt` (`0x000ea0..0x001018`, 376 bytes):
//   1. Checks `buf != nullptr`, `len >= 7`, `key_len >= 1`, `key != nullptr`,
//      and `((len - 6) & 0x0F) == 0` (else returns -1 @ 0x0ec4..0x0ef8).
//   2. Checks `buf[0] == 0x74 ('t')`, `buf[1] == 0x63 ('c')`, `buf[2] == 3` (else returns -2 @ 0x0f34).
//   3. Checks `pad_len = buf[3] <= 15` (else returns -3 @ 0x0f2c).
//   4. Calls `DeriveRoundKeys128(key, key_len, k)` (@ 0x0f6c).
//   5. For each 16-byte block `(W0, W1, W2, W3)` at `buf + 6 + 16*b` (`0x0f70..0x0fd8`):
//        W0 = rev(rev(W0) ^ k[0])
//        W1 = rev(ror(rev(W1) ^ k[1], 8))
//        W2 = rev16(rev(W2) ^ k[2])
//        W3 = rev(ror(rev(W3) ^ k[3], 24))
//   6. Applies inverse `sbox1` byte-by-byte to `buf[6 .. len - 1]` (@ 0x0fdc..0x1008).
//   7. Returns `(len - 6) - pad_len` (`sub w0, w22, w23` @ 0x100c)!
// ----------------------------------------------------------------------------
int32_t ss_decrypt(
    uint8_t* buf,
    int32_t len,
    const uint8_t* key,
    int32_t key_len) {
    using namespace tob_embed_pag_encrypt;
    if (!buf || len < 7 || key_len < 1 || !key) {
        return kErrInvalidArgs;
    }
    const int32_t payload_len = len - kTcHeaderBytes;
    if ((payload_len & 0x0F) != 0) {
        return kErrInvalidArgs;
    }
    if (buf[0] != 0x74U || buf[1] != 0x63U || buf[2] != kTcHeaderVersion) {
        return kErrInvalidMagic;
    }
    const uint8_t pad_len = buf[3];
    if (pad_len > 0x0FU) {
        return kErrInvalidPadding;
    }

    uint32_t k[4] = {};
    DeriveRoundKeys128(key, key_len, k);

    const int32_t num_blocks = payload_len >> 4;
    for (int32_t b = 0; b < num_blocks; ++b) {
        uint8_t* blk = buf + kTcHeaderBytes + b * 16;
        uint32_t w0 = 0, w1 = 0, w2 = 0, w3 = 0;
        std::memcpy(&w0, blk +  0, 4);
        std::memcpy(&w1, blk +  4, 4);
        std::memcpy(&w2, blk +  8, 4);
        std::memcpy(&w3, blk + 12, 4);

        const uint32_t dec_w0 = ByteSwap32(ByteSwap32(w0) ^ k[0]);
        const uint32_t dec_w1 = ByteSwap32(Ror32(ByteSwap32(w1) ^ k[1], 8));
        const uint32_t dec_w2 = Rev16_32(ByteSwap32(w2) ^ k[2]);
        const uint32_t dec_w3 = ByteSwap32(Ror32(ByteSwap32(w3) ^ k[3], 24));

        std::memcpy(blk +  0, &dec_w0, 4);
        std::memcpy(blk +  4, &dec_w1, 4);
        std::memcpy(blk +  8, &dec_w2, 4);
        std::memcpy(blk + 12, &dec_w3, 4);
    }

    for (int32_t i = kTcHeaderBytes; i < len; ++i) {
        buf[i] = sbox1[buf[i]];
    }

    return payload_len - static_cast<int32_t>(pad_len);
}

// ----------------------------------------------------------------------------
// Export [17] `Java_com_bytedance_sdk_component_embedapplog_PangleEncryptUtils_ttEncrypt`
// (`0x001070..0x0011c8`, 344 bytes)
// ----------------------------------------------------------------------------
jbyteArray Java_com_bytedance_sdk_component_embedapplog_PangleEncryptUtils_ttEncrypt(
    JNIEnv* env,
    jclass /*clazz*/,
    jbyteArray plain_array,
    jint plain_len) {
    using namespace tob_embed_pag_encrypt;
    if (!env || !plain_array || plain_len < 1) {
        return nullptr;
    }

    initKey();
    const char* key_str = GetGlobalBssKeyBuffer();
    const int32_t out_len = ss_encrypted_size(plain_len);
    auto* in_buf  = static_cast<uint8_t*>(std::malloc(static_cast<size_t>(plain_len)));
    auto* out_buf = static_cast<uint8_t*>(std::malloc(static_cast<size_t>(out_len)));
    if (!in_buf || !out_buf) {
        if (in_buf)  std::free(in_buf);
        if (out_buf) std::free(out_buf);
        return nullptr;
    }

    using GetByteArrayRegionFn = void (*)(JNIEnv*, jbyteArray, jsize, jsize, jbyte*);
    using NewByteArrayFn       = jbyteArray (*)(JNIEnv*, jsize);
    using SetByteArrayRegionFn = void (*)(JNIEnv*, jbyteArray, jsize, jsize, const jbyte*);

    auto get_region = LoadEnvVtableSlot<GetByteArrayRegionFn>(env, kEnvOffGetByteArrayRegion);
    if (get_region) {
        get_region(env, plain_array, 0, plain_len, reinterpret_cast<jbyte*>(in_buf));
    }

    const int32_t key_len = static_cast<int32_t>(std::strlen(key_str));
    const int32_t rc = ss_encrypt(in_buf, plain_len, reinterpret_cast<const uint8_t*>(key_str), key_len, out_buf);

    jbyteArray result_array = nullptr;
    if (rc >= 0) {
        auto new_byte_arr = LoadEnvVtableSlot<NewByteArrayFn>(env, kEnvOffNewByteArray);
        auto set_region   = LoadEnvVtableSlot<SetByteArrayRegionFn>(env, kEnvOffSetByteArrayRegion);
        if (new_byte_arr) {
            result_array = new_byte_arr(env, out_len);
            if (result_array && set_region) {
                set_region(env, result_array, 0, out_len, reinterpret_cast<const jbyte*>(out_buf));
            }
        }
    }

    std::free(in_buf);
    std::free(out_buf);
    return result_array;
}

// ----------------------------------------------------------------------------
// Export [16] `Java_com_bytedance_sdk_component_embedapplog_PangleEncryptUtils_ttDecrypt`
// (`0x0011c8..0x0012f8`, 304 bytes)
// ----------------------------------------------------------------------------
jbyteArray Java_com_bytedance_sdk_component_embedapplog_PangleEncryptUtils_ttDecrypt(
    JNIEnv* env,
    jclass /*clazz*/,
    jbyteArray cipher_array,
    jint cipher_len) {
    using namespace tob_embed_pag_encrypt;
    if (!env || !cipher_array || cipher_len < 1) {
        return nullptr;
    }

    initKey();
    const char* key_str = GetGlobalBssKeyBuffer();
    auto* work_buf = static_cast<uint8_t*>(std::malloc(static_cast<size_t>(cipher_len)));
    if (!work_buf) {
        return nullptr;
    }

    using GetByteArrayRegionFn = void (*)(JNIEnv*, jbyteArray, jsize, jsize, jbyte*);
    using NewByteArrayFn       = jbyteArray (*)(JNIEnv*, jsize);
    using SetByteArrayRegionFn = void (*)(JNIEnv*, jbyteArray, jsize, jsize, const jbyte*);

    auto get_region = LoadEnvVtableSlot<GetByteArrayRegionFn>(env, kEnvOffGetByteArrayRegion);
    if (get_region) {
        get_region(env, cipher_array, 0, cipher_len, reinterpret_cast<jbyte*>(work_buf));
    }

    const int32_t key_len = static_cast<int32_t>(std::strlen(key_str));
    const int32_t dec_len = ss_decrypt(work_buf, cipher_len, reinterpret_cast<const uint8_t*>(key_str), key_len);

    jbyteArray result_array = nullptr;
    if (dec_len >= 1) {
        auto new_byte_arr = LoadEnvVtableSlot<NewByteArrayFn>(env, kEnvOffNewByteArray);
        auto set_region   = LoadEnvVtableSlot<SetByteArrayRegionFn>(env, kEnvOffSetByteArrayRegion);
        if (new_byte_arr) {
            result_array = new_byte_arr(env, dec_len);
            if (result_array && set_region) {
                // Copies from `work_buf + 6` (`add x4, x20, #6` @ 0x1298)
                set_region(env, result_array, 0, dec_len, reinterpret_cast<const jbyte*>(work_buf + kTcHeaderBytes));
            }
        }
    }

    std::free(work_buf);
    return result_array;
}

} // extern "C"
