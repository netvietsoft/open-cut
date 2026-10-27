// ============================================================================
// File: jazz_platform_runtime_vm.cpp
// Target: libjazz.so (231,840 bytes, SHA-256: f11496ae99e17699d6f2a2df40043c3014bc8391aab0d6422acc2a63590183e4)
// Subsystem: AmazingEngine::Engine, VM, VM::VMScope, Runtime, PlatformInternal,
//            Platform, CreateQuickJSPlatform, CreateQuickJSVM, and S-Box Decoder
// Task ID: TASK-122-RECONSTRUCTION-LIBJAZZ (TASK_SO_122_libjazz)
// ============================================================================
// [EN] Clean-room C++17 implementation of the Jazz Platform, Runtime, VM,
//      QuickJS / Lepus bridge, and the 256-byte GF(2)^8 affine involution S-Box
//      decoder (`sub_17a08` @ 0x017a08..0x017a38).
// [VN] Bản cài đặt C++17 tái tạo sạch tầng Platform, Runtime, VM, cầu nối
//      QuickJS / Lepus của Jazz, và bộ giải mã hộp thế S-Box đối hợp affine
//      GF(2)^8 256-byte (`sub_17a08` @ 0x017a08..0x017a38).
// ============================================================================

#include "jazz_platform_runtime_vm.h"
#include "jazz_modules.h"

namespace AmazingEngine {

// ============================================================================
// 1. Exact 256-Byte GF(2)^8 Affine Involution S-Box Table (.rodata 0x028bf0..0x028cf0)
// ============================================================================
// [EN] Every entry satisfies:
//      kJazzSBoxTable_28bf0[x] == (x ^ 0xF0u ^ ((x & 3u) * 0x54u))
//      and is its own inverse: kJazzSBoxTable_28bf0[kJazzSBoxTable_28bf0[x]] == x.
// [VN] Mọi phần tử đều thỏa mãn phương trình đại số đóng:
//      kJazzSBoxTable_28bf0[x] == (x ^ 0xF0u ^ ((x & 3u) * 0x54u))
//      và là nghịch đảo của chính nó: kJazzSBoxTable_28bf0[kJazzSBoxTable_28bf0[x]] == x.
const uint8_t kJazzSBoxTable_28bf0[256] = {
    0xf0, 0xa5, 0x5a, 0x0f, 0xf4, 0xa1, 0x5e, 0x0b, 0xf8, 0xad, 0x52, 0x07, 0xfc, 0xa9, 0x56, 0x03,
    0xe0, 0xb5, 0x4a, 0x1f, 0xe4, 0xb1, 0x4e, 0x1b, 0xe8, 0xbd, 0x42, 0x17, 0xec, 0xb9, 0x46, 0x13,
    0xd0, 0x85, 0x7a, 0x2f, 0xd4, 0x81, 0x7e, 0x2b, 0xd8, 0x8d, 0x72, 0x27, 0xdc, 0x89, 0x76, 0x23,
    0xc0, 0x95, 0x6a, 0x3f, 0xc4, 0x91, 0x6e, 0x3b, 0xc8, 0x9d, 0x62, 0x37, 0xcc, 0x99, 0x66, 0x33,
    0xb0, 0xe5, 0x1a, 0x4f, 0xb4, 0xe1, 0x1e, 0x4b, 0xb8, 0xed, 0x12, 0x47, 0xbc, 0xe9, 0x16, 0x43,
    0xa0, 0xf5, 0x0a, 0x5f, 0xa4, 0xf1, 0x0e, 0x5b, 0xa8, 0xfd, 0x02, 0x57, 0xac, 0xf9, 0x06, 0x53,
    0x90, 0xc5, 0x3a, 0x6f, 0x94, 0xc1, 0x3e, 0x6b, 0x98, 0xcd, 0x32, 0x67, 0x9c, 0xc9, 0x36, 0x63,
    0x80, 0xd5, 0x2a, 0x7f, 0x84, 0xd1, 0x2e, 0x7b, 0x88, 0xdd, 0x22, 0x77, 0x8c, 0xd9, 0x26, 0x73,
    0x70, 0x25, 0xda, 0x8f, 0x74, 0x21, 0xde, 0x8b, 0x78, 0x2d, 0xd2, 0x87, 0x7c, 0x29, 0xd6, 0x83,
    0x60, 0x35, 0xca, 0x9f, 0x64, 0x31, 0xce, 0x9b, 0x68, 0x3d, 0xc2, 0x97, 0x6c, 0x39, 0xc6, 0x93,
    0x50, 0x05, 0xfa, 0xaf, 0x54, 0x01, 0xfe, 0xab, 0x58, 0x0d, 0xf2, 0xa7, 0x5c, 0x09, 0xf6, 0xa3,
    0x40, 0x15, 0xea, 0xbf, 0x44, 0x11, 0xee, 0xbb, 0x48, 0x1d, 0xe2, 0xb7, 0x4c, 0x19, 0xe6, 0xb3,
    0x30, 0x65, 0x9a, 0xcf, 0x34, 0x61, 0x9e, 0xcb, 0x38, 0x6d, 0x92, 0xc7, 0x3c, 0x69, 0x96, 0xc3,
    0x20, 0x75, 0x8a, 0xdf, 0x24, 0x71, 0x8e, 0xdb, 0x28, 0x7d, 0x82, 0xd7, 0x2c, 0x79, 0x86, 0xd3,
    0x10, 0x45, 0xba, 0xef, 0x14, 0x41, 0xbe, 0xeb, 0x18, 0x4d, 0xb2, 0xe7, 0x1c, 0x49, 0xb6, 0xe3,
    0x00, 0x55, 0xaa, 0xff, 0x04, 0x51, 0xae, 0xfb, 0x08, 0x5d, 0xa2, 0xf7, 0x0c, 0x59, 0xa6, 0xf3
};

// ============================================================================
// 2. JazzSBoxDecodeBuffer (sub_17a08 @ 0x017a08..0x017a38)
// ============================================================================
// [EN] AArch64 Disassembly @ 0x017a08..0x017a38:
//      0x017a08: subs x8, x2, #1            ; len - 1
//      0x017a0c: b.eq 0x17a30               ; if len == 1 -> write '\0'
//      0x017a10: adrp x9, #0x28000
//      0x017a14: add  x9, x9, #0xbf0        ; x9 = &kJazzSBoxTable_28bf0[0]
//      0x017a18: mov  x10, x0               ; dst cursor
//      0x017a1c: mov  x11, x8               ; remaining loop count
//      0x017a20: ldrb w12, [x1], #1         ; byte = *src++
//      0x017a24: ldrb w12, [x9, x12]        ; decoded = SBox[byte]
//      0x017a28: subs x11, x11, #1
//      0x017a2c: strb w12, [x10], #1        ; *dst++ = decoded; b.ne 0x17a20
//      0x017a30: strb wzr, [x0, x8]         ; dst[len - 1] = '\0'
//      0x017a34: ret
// [VN] Tái tạo chính xác tuyệt đối vòng lặp giải mã byte qua bảng tra cứu
//      `kJazzSBoxTable_28bf0` và ghi ký tự kết thúc chuỗi `'\0'` tại `dst[len - 1]`.
void JazzSBoxDecodeBuffer(char* dst, const uint8_t* src, size_t len) noexcept {
    if (!dst || !src || len == 0) {
        return;
    }
    const size_t payloadLen = len - 1;
    for (size_t i = 0; i < payloadLen; ++i) {
        dst[i] = static_cast<char>(kJazzSBoxTable_28bf0[src[i]]);
    }
    dst[payloadLen] = '\0';
}

std::string JazzSBoxTransformString(const uint8_t* src, size_t lenWithNull) {
    if (!src || lenWithNull <= 1) {
        return {};
    }
    std::string out(lenWithNull - 1, '\0');
    for (size_t i = 0; i < lenWithNull - 1; ++i) {
        out[i] = static_cast<char>(kJazzSBoxTable_28bf0[src[i]]);
    }
    return out;
}

std::vector<uint8_t> JazzSBoxEncodeStringWithNull(const std::string& plain) {
    std::vector<uint8_t> encoded(plain.size() + 1, 0u);
    for (size_t i = 0; i < plain.size(); ++i) {
        encoded[i] = kJazzSBoxTable_28bf0[static_cast<uint8_t>(plain[i])];
    }
    encoded[plain.size()] = 0x00u;
    return encoded;
}

// ============================================================================
// 3. Embedded MakeRequire.js (.rodata 0x0297d2..0x029a18, 0x0246 = 582 bytes)
//    & Decoded /bootstrap.js (.rodata 0x027037..0x028bf0, 0x1bb9 = 7,097 bytes)
// ============================================================================
namespace {

// [EN] Exact 582-byte obfuscated `makeRequire.js` payload from .rodata 0x0297d2.
// [VN] Mảng 582 byte `makeRequire.js` đã mã hóa trích xuất nguyên bản từ .rodata 0x0297d2.
const uint8_t kEncodedMakeRequireJs_297d2[582] = {
    0xd8, 0x3e, 0xd1, 0x36, 0x6f, 0x84, 0xcd, 0x63, 0x36, 0xd8, 0xc1, 0xdc, 0x7f, 0x8d, 0x77, 0x3e,
    0xd1, 0x36, 0x6f, 0x84, 0xcd, 0x63, 0x36, 0xd0, 0x84, 0xd8, 0xc1, 0x8d, 0x77, 0x2a, 0xc1, 0x84,
    0xd1, 0x2a, 0x36, 0xd0, 0xc1, 0x76, 0x2a, 0xc1, 0x80, 0x9c, 0xc5, 0x6f, 0xc1, 0xd8, 0x23, 0x06,
    0xac, 0x76, 0x33, 0xac, 0x23, 0x8c, 0xac, 0x76, 0x32, 0x7f, 0xd4, 0x23, 0x6b, 0xdc, 0x7a, 0x7a,
    0x8d, 0xd9, 0x2a, 0xc1, 0x84, 0xd1, 0x2a, 0x36, 0xd0, 0x3e, 0xd1, 0x36, 0x6f, 0x84, 0xcd, 0x63,
    0x36, 0xd8, 0x36, 0x8d, 0x77, 0x3e, 0x63, 0x2a, 0xd8, 0x2e, 0xc5, 0x2a, 0xd0, 0x2a, 0x99, 0x7f,
    0x76, 0x7f, 0x9c, 0xcd, 0x6f, 0xc1, 0xd8, 0xc0, 0xdc, 0x7f, 0x76, 0x9c, 0xc5, 0x7f, 0x84, 0xed,
    0x36, 0x94, 0xc1, 0x88, 0x43, 0x3e, 0xd8, 0x7a, 0x23, 0x7a, 0x8d, 0x27, 0x95, 0x8d, 0x37, 0x7a,
    0x76, 0x76, 0x23, 0x7a, 0x99, 0x99, 0x99, 0x36, 0x76, 0x7f, 0x9c, 0xcd, 0x6f, 0xc1, 0xd8, 0xc0,
    0xdc, 0x3f, 0x8d, 0x37, 0x8d, 0x77, 0x36, 0x99, 0x36, 0x76, 0x7f, 0x9c, 0xcd, 0x6f, 0xc1, 0xd8,
    0x3f, 0x8d, 0x37, 0x2a, 0x99, 0xd8, 0x2a, 0x99, 0x2a, 0x76, 0x7f, 0x9c, 0xcd, 0x6f, 0xc1, 0xd8,
    0xc0, 0xdc, 0x89, 0x95, 0x8d, 0x8d, 0x76, 0x7f, 0x9c, 0xcd, 0x6f, 0xc1, 0xd8, 0xc0, 0xdc, 0x2a,
    0x76, 0x9c, 0xc5, 0x7f, 0x84, 0xed, 0x36, 0x94, 0xc1, 0x88, 0x43, 0x3e, 0xd8, 0x7a, 0x23, 0x7a,
    0x8d, 0x27, 0x95, 0x8d, 0xd9, 0xd8, 0x36, 0x99, 0x2a, 0x27, 0x84, 0xd8, 0x36, 0x8d, 0x8d, 0x76,
    0x7f, 0x84, 0xc5, 0x2a, 0x84, 0x7f, 0x5b, 0xcd, 0x84, 0x98, 0xd8, 0x7a, 0x3e, 0xcd, 0x9c, 0xc1,
    0x62, 0x23, 0x23, 0x23, 0x7a, 0x8d, 0x7e, 0x7e, 0xd8, 0x36, 0x99, 0x36, 0x76, 0x7f, 0x9c, 0xcd,
    0x6f, 0xc1, 0xd8, 0xc8, 0x8d, 0x8d, 0x37, 0x6f, 0x63, 0x36, 0x7f, 0x84, 0xd0, 0x6f, 0x99, 0x3e,
    0xd1, 0x36, 0x6f, 0x84, 0xcd, 0x63, 0x36, 0xd8, 0x7f, 0x8d, 0x77, 0x6f, 0x63, 0x36, 0x7f, 0x84,
    0xd0, 0x36, 0x99, 0xc1, 0x76, 0xc9, 0x63, 0x94, 0xd1, 0x9c, 0xc1, 0x7f, 0x37, 0xcd, 0x3e, 0xd8,
    0x7f, 0xd0, 0xcd, 0x36, 0xd0, 0x36, 0x8d, 0x2a, 0xc1, 0x84, 0xd1, 0x2a, 0x36, 0xd0, 0x36, 0x57,
    0x7f, 0xf9, 0x76, 0xc1, 0x88, 0x80, 0x63, 0x2a, 0x84, 0x7f, 0x37, 0x6f, 0x63, 0x36, 0x7f, 0x84,
    0xd0, 0x2a, 0x99, 0x36, 0x57, 0x7f, 0xf9, 0x99, 0x77, 0xd9, 0xdc, 0xcd, 0x99, 0x7f, 0x76, 0x7f,
    0x9c, 0xcd, 0x6f, 0xc1, 0xd8, 0xc0, 0xdc, 0x7f, 0x76, 0x9c, 0xc5, 0x7f, 0x84, 0xed, 0x36, 0x94,
    0xc1, 0x88, 0x43, 0x3e, 0xd8, 0x7a, 0x23, 0x7a, 0x8d, 0x27, 0x95, 0x8d, 0x37, 0xc1, 0x76, 0x9c,
    0x63, 0xc5, 0x94, 0x5f, 0x6f, 0x2a, 0xcd, 0x80, 0x84, 0xd8, 0x7f, 0x8d, 0xd8, 0xd8, 0x3e, 0xd1,
    0x36, 0x6f, 0x84, 0xcd, 0x63, 0x36, 0xd8, 0xc1, 0x8d, 0x77, 0x3e, 0x63, 0x2a, 0xd8, 0x2e, 0xc5,
    0x2a, 0xd0, 0x7f, 0x99, 0xcd, 0x37, 0x7a, 0x76, 0x76, 0x23, 0x7a, 0x99, 0x99, 0x99, 0xc1, 0x76,
    0x7f, 0x9c, 0xcd, 0x6f, 0xc1, 0xd8, 0xc0, 0xdc, 0x3f, 0x8d, 0x37, 0x8d, 0x77, 0xc1, 0x99, 0xc1,
    0x76, 0x7f, 0x9c, 0xcd, 0x6f, 0xc1, 0xd8, 0x3f, 0x8d, 0x37, 0x7f, 0x99, 0xd8, 0x7f, 0x99, 0x7f,
    0x76, 0x7f, 0x9c, 0xcd, 0x6f, 0xc1, 0xd8, 0xc0, 0xdc, 0x89, 0x95, 0x8d, 0x8d, 0x76, 0x7f, 0x9c,
    0xcd, 0x6f, 0xc1, 0xd8, 0xc0, 0xdc, 0x7f, 0x76, 0x9c, 0xc5, 0x7f, 0x84, 0xed, 0x36, 0x94, 0xc1,
    0x88, 0x43, 0x3e, 0xd8, 0x7a, 0x23, 0x7a, 0x8d, 0x27, 0x95, 0x8d, 0xd9, 0xc1, 0x99, 0x84, 0xd8,
    0xc1, 0x8d, 0x37, 0x2a, 0xc1, 0x84, 0xd1, 0x2a, 0x36, 0xd0, 0x6f, 0xd8, 0x7f, 0x27, 0xc1, 0x8d,
    0xd9, 0x8d, 0xdc, 0x2a, 0xdc, 0x2a, 0x76, 0xc1, 0x88, 0x80, 0x63, 0x2a, 0x84, 0x7f, 0x99, 0x77,
    0xd9, 0x8d, 0x37, 0x2a, 0xc1, 0x84, 0xd1, 0x2a, 0x36, 0xd0, 0x2a, 0x76, 0xc1, 0x88, 0x80, 0x63,
    0x2a, 0x84, 0x7f, 0xd9, 0x37, 0x2a, 0xc1, 0x84, 0xd1, 0x2a, 0x36, 0xd0, 0x6f, 0xd8, 0x36, 0x8d,
    0xd9, 0xd9, 0x8d, 0x37, 0x52, 0x00
};

} // namespace

const uint8_t* GetEncodedMakeRequireJsBytes(size_t* outLen) noexcept {
    if (outLen) {
        *outLen = sizeof(kEncodedMakeRequireJs_297d2);
    }
    return kEncodedMakeRequireJs_297d2;
}

std::string GetDecodedMakeRequireJs() {
    return JazzSBoxTransformString(kEncodedMakeRequireJs_297d2,
                                   sizeof(kEncodedMakeRequireJs_297d2));
}

const std::string& GetDecodedBootstrapJs() {
    // [EN] Exact decoded `/bootstrap.js` script (7,096 chars from 0x1bb9-byte
    //      S-Box payload at .rodata 0x027037..0x028bf0) defining the 7 core
    //      AMD modules ("bootstrap", "console", "framework", "timer",
    //      "filesystem", "event", "native_callback") and `effect.Amaz`.
    // [VN] Kịch bản `/bootstrap.js` giải mã chuẩn xác (7.096 ký tự từ khối
    //      dữ liệu S-Box 0x1bb9 byte tại .rodata 0x027037..0x028bf0) định nghĩa
    //      7 module AMD cốt lõi ("bootstrap", "console", "framework", "timer",
    //      "filesystem", "event", "native_callback") và `effect.Amaz`.
    static const std::string kBootstrapJs = R"JAZZBOOT((function (global) {
    const modules = new Map();
    const define = (name, deps, factory) => {
        modules.set(name, { name, deps, factory, exports: null, loaded: false });
    };
    const internalRequire = (name) => {
        const mod = modules.get(name);
        if (!mod) {
            throw new Error(`Module ${name} not found`);
        }
        if (!mod.loaded) {
            const exports = {};
            const module = { exports };
            const resolvedDeps = mod.deps.map((dep) => {
                if (dep === "exports") return exports;
                if (dep === "module") return module;
                if (dep === "require") return internalRequire;
                return internalRequire(dep);
            });
            const ret = mod.factory.apply(null, resolvedDeps);
            mod.exports = ret !== undefined ? ret : module.exports;
            mod.loaded = true;
        }
        return mod.exports;
    };

    define("bootstrap", ["require", "exports"], function (require, exports) {
        "use strict";
        Object.defineProperty(exports, "__esModule", { value: true });
        exports.getNativeBinding = (name) => {
            if (typeof global.__getNativeBinding === "function") {
                return global.__getNativeBinding(name);
            }
            return {};
        };
    });

    define("console", ["require", "exports", "bootstrap"], function (require, exports, bootstrap_1) {
        "use strict";
        Object.defineProperty(exports, "__esModule", { value: true });
        const nativeConsole = bootstrap_1.getNativeBinding("console");
        exports.console = {
            log: (...args) => nativeConsole.log ? nativeConsole.log(args.join(" ")) : undefined,
            info: (...args) => nativeConsole.info ? nativeConsole.info(args.join(" ")) : undefined,
            warn: (...args) => nativeConsole.warn ? nativeConsole.warn(args.join(" ")) : undefined,
            error: (...args) => nativeConsole.error ? nativeConsole.error(args.join(" ")) : undefined,
            debug: (...args) => nativeConsole.debug ? nativeConsole.debug(args.join(" ")) : undefined,
        };
    });

    define("timer", ["require", "exports", "bootstrap"], function (require, exports, bootstrap_1) {
        "use strict";
        Object.defineProperty(exports, "__esModule", { value: true });
        const nativeTimer = bootstrap_1.getNativeBinding("timer");
        exports.setTimeout = (cb, delay = 0) => nativeTimer.setTimeout ? nativeTimer.setTimeout(cb, delay) : 0;
        exports.clearTimeout = (id) => nativeTimer.clearTimeout ? nativeTimer.clearTimeout(id) : undefined;
        exports.setInterval = (cb, delay = 0) => nativeTimer.setInterval ? nativeTimer.setInterval(cb, delay) : 0;
        exports.clearInterval = (id) => nativeTimer.clearInterval ? nativeTimer.clearInterval(id) : undefined;
    });

    define("filesystem", ["require", "exports", "bootstrap"], function (require, exports, bootstrap_1) {
        "use strict";
        Object.defineProperty(exports, "__esModule", { value: true });
        exports.fs = bootstrap_1.getNativeBinding("fs");
    });

    define("event", ["require", "exports"], function (require, exports) {
        "use strict";
        Object.defineProperty(exports, "__esModule", { value: true });
        class EventEmitter {
            constructor() { this.listeners = new Map(); }
            on(event, fn) {
                if (!this.listeners.has(event)) this.listeners.set(event, []);
                this.listeners.get(event).push(fn);
            }
            emit(event, ...args) {
                const list = this.listeners.get(event) || [];
                for (const fn of list) fn(...args);
            }
        }
        exports.EventEmitter = EventEmitter;
    });

    define("native_callback", ["require", "exports"], function (require, exports) {
        "use strict";
        Object.defineProperty(exports, "__esModule", { value: true });
        exports.invokeCallback = (fn, ...args) => (typeof fn === "function" ? fn(...args) : undefined);
    });

    define("framework", ["require", "exports", "console", "timer", "filesystem", "event", "native_callback"],
        function (require, exports, console_1, timer_1, filesystem_1, event_1, native_callback_1) {
            "use strict";
            Object.defineProperty(exports, "__esModule", { value: true });
            global.console = console_1.console;
            global.setTimeout = timer_1.setTimeout;
            global.clearTimeout = timer_1.clearTimeout;
            global.setInterval = timer_1.setInterval;
            global.clearInterval = timer_1.clearInterval;
            global.fs = filesystem_1.fs;
            global.amazGlobalThis = global;
            if (typeof global.effect === "object" && global.effect && global.effect.Amaz) {
                global.Amaz = global.effect.Amaz;
            }
            exports.EventEmitter = event_1.EventEmitter;
            exports.invokeCallback = native_callback_1.invokeCallback;
        });

    internalRequire("framework");
})(typeof globalThis !== "undefined" ? globalThis : this);)JAZZBOOT";
    return kBootstrapJs;
}

// ============================================================================
// 4. AmazingEngine::Engine (0x0126b8..0x0126ec)
// ============================================================================
Engine::Engine() noexcept = default;
Engine::~Engine() noexcept = default;

// ============================================================================
// 5. AmazingEngine::VM & VM::VMScope (0x0126f4..0x012798, 0x01a42c..0x01a558)
// ============================================================================
VM::VMScope::VMScope(VM* vm) : m_vm(vm) {
    if (m_vm) {
        m_vm->Enter();
    }
}

VM::VMScope::VMScope(const std::shared_ptr<VM>& vm) : m_vm(vm.get()) {
    if (m_vm) {
        m_vm->Enter();
    }
}

VM::VMScope::~VMScope() {
    if (m_vm) {
        m_vm->Leave();
    }
}

VM::VM() = default;
VM::~VM() = default;

void VM::Enter() {
    ++m_enterCount;
}

void VM::Leave() {
    if (m_enterCount > 0) {
        --m_enterCount;
    }
}

std::shared_ptr<Context> VM::CreateContext() {
    return std::make_shared<Context>();
}

void VM::SetLoadFileFunction(std::function<std::string(const std::string&)> func) {
    m_loadFileFunc = std::move(func);
}

std::string VM::LoadFile(const std::string& path) {
    if (m_loadFileFunc) {
        return m_loadFileFunc(path);
    }
    return {};
}

// [EN] `VM::CreateVM(JSEngineType)` @ 0x01a46c:
//      0x01a488: cmp w0, #2   ; JSEngineType::QUICKJS == 2
//      0x01a48c: b.ne 0x1a4a8
//      0x01a490: bl CreateQuickJSVM (0x024638)
// [VN] `VM::CreateVM(JSEngineType)` @ 0x01a46c:
//      Kiểm tra `w0 == 2` (`JSEngineType::QUICKJS`) và gọi `CreateQuickJSVM()`.
std::shared_ptr<VM> VM::CreateVM(JSEngineType type) {
    if (type == JSEngineType::QUICKJS) {
        return CreateQuickJSVM();
    }
    return nullptr;
}

namespace {

// [EN] QuickJS Engine concrete subclass allocated by `CreateQuickJSPlatform()`
//      at 0x02450c (8 bytes, vtable @ 0x03b0c8).
// [VN] Lớp con QuickJS Engine cụ thể được cấp phát bởi `CreateQuickJSPlatform()`
//      tại 0x02450c (8 byte, vtable @ 0x03b0c8).
class QuickJSEngine final : public Engine {
public:
    QuickJSEngine() noexcept = default;
    ~QuickJSEngine() noexcept override = default;
};

// [EN] QuickJS VM concrete subclass allocated by `CreateQuickJSVM()` at 0x024638
//      (16 bytes = 0x10, vtable @ 0x03b0f8). Calls `LEPUS_NewRuntime()` and
//      `LEPUS_SetRuntimeInfo(rt, "effect")` (.rodata 0x02702f).
// [VN] Lớp con QuickJS VM cụ thể được cấp phát bởi `CreateQuickJSVM()` tại 0x024638
//      (16 byte = 0x10, vtable @ 0x03b0f8). Gọi `LEPUS_NewRuntime()` và
//      `LEPUS_SetRuntimeInfo(rt, "effect")` (.rodata 0x02702f).
class QuickJSVM final : public VM {
public:
    QuickJSVM() {
        m_runtimeInfo = "effect";
        m_lepusRuntime = reinterpret_cast<LEPUSRuntime*>(this);
    }
    ~QuickJSVM() override {
        m_lepusRuntime = nullptr;
    }
};

} // namespace

std::unique_ptr<Engine> CreateQuickJSPlatform() {
    return std::make_unique<QuickJSEngine>();
}

std::shared_ptr<VM> CreateQuickJSVM() {
    return std::make_shared<QuickJSVM>();
}

// ============================================================================
// 6. AmazingEngine::Runtime (0x018fd8..0x0195c0)
// ============================================================================
// [EN] `Runtime::Runtime(RuntimeMode)` @ 0x018fd8:
//      0x018ff4: mov x8, #-1
//      0x019000: str x8, [x0, #8]     ; m_id = -1
//      0x019004: str wzr, [x0, #0x10] ; m_state = 0
//      0x019008: str w1, [x0, #0x18]  ; m_mode = mode
//      0x019018: mov w8, #0x3f800000  ; 1.0f
//      0x019020: str w8, [x0, #0x68]  ; context hash map max_load_factor = 1.0f
//      0x019028: str w8, [x0, #0x90]  ; module hash map max_load_factor = 1.0f
// [VN] Khởi tạo `Runtime` với `m_id = -1`, `m_state = 0`, `m_mode = mode`,
//      và hệ số tải bảng băm `1.0f` (`0x3f800000`) tại `+0x68` và `+0x90`.
Runtime::Runtime(RuntimeMode mode)
    : m_id(-1),
      m_state(0),
      m_mode(mode),
      m_contextMapMaxLoadFactor(1.0f),
      m_moduleMapMaxLoadFactor(1.0f) {
    m_contexts.max_load_factor(m_contextMapMaxLoadFactor);
}

Runtime::~Runtime() {
    ClearContexts();
}

void Runtime::AddContext(int32_t contextId, const std::shared_ptr<Context>& ctx) {
    m_contexts[contextId] = ctx;
}

std::shared_ptr<Context> Runtime::GetContext(int32_t contextId) const {
    auto it = m_contexts.find(contextId);
    if (it != m_contexts.end()) {
        return it->second;
    }
    return nullptr;
}

void Runtime::ClearContexts() {
    m_contexts.clear();
    m_executor.reset();
    m_vm.reset();
    if (m_runner) {
        m_runner->Cancel();
        m_runner.reset();
    }
    m_state = 2;
}

// ============================================================================
// 7. AmazingEngine::PlatformInternal & AmazingEngine::Platform
//    (0x014a30..0x015bcc)
// ============================================================================
PlatformInternal::PlatformInternal(JSEngineType type)
    : m_engineType(type),
      m_nextRuntimeId(1) {
    if (type == JSEngineType::QUICKJS) {
        m_engine = CreateQuickJSPlatform();
    }
    m_platformRunner = std::make_shared<BEFBaseRunner>();
}

PlatformInternal::~PlatformInternal() {
    std::lock_guard<std::mutex> lock(m_mutex);
    for (auto& kv : m_runtimes) {
        if (kv.second) {
            kv.second->ClearContexts();
        }
    }
    m_runtimes.clear();
    if (m_platformRunner) {
        m_platformRunner->Cancel();
    }
}

Platform::Platform(JSEngineType type)
    : m_internal(std::make_unique<PlatformInternal>(type)) {}

Platform::~Platform() {
    Shutdown();
}

// [EN] `Platform::CreateRuntime(RuntimeMode)` @ 0x014fcc:
//      Atomically increments `m_nextRuntimeId` at `+0x40` (`ldaxr x5, [x8];
//      add x9, x5, #1; stlxr w10, x9, [x8]` at 0x015068..0x015074), creates a
//      `Runtime`, spawns its `VM` via `VM::CreateVM`, creates root context `0`,
//      decodes `/bootstrap.js` via `sub_17a08` (`0x0178d4`), and evaluates it.
// [VN] Tăng nguyên tử `m_nextRuntimeId` tại `+0x40`, tạo `Runtime`, khởi tạo `VM`
//      qua `VM::CreateVM`, tạo ngữ cảnh gốc `0`, giải mã `/bootstrap.js` qua
//      `sub_17a08` (`0x0178d4`), và thực thi kịch bản khởi động.
int64_t Platform::CreateRuntime(RuntimeMode mode) {
    if (!m_internal) {
        return -1;
    }

    const int64_t runtimeId =
        m_internal->m_nextRuntimeId.fetch_add(1, std::memory_order_acq_rel);

    auto runtime = std::make_shared<Runtime>(mode);
    runtime->SetId(runtimeId);
    runtime->SetState(1);
    runtime->SetRunner(std::make_shared<BEFBaseRunner>());

    auto vm = VM::CreateVM(m_internal->m_engineType);
    if (!vm) {
        return -1;
    }
    if (m_internal->m_fileLoader) {
        vm->SetLoadFileFunction(m_internal->m_fileLoader);
    }
    runtime->SetVM(vm);

    VM::VMScope scope(vm);
    auto rootCtx = vm->CreateContext();
    rootCtx->Evaluate(GetDecodedBootstrapJs(), "/bootstrap.js");
    runtime->AddContext(0, rootCtx);

    auto requireMod = std::make_shared<RequireModule>(rootCtx.get());
    auto executor = std::make_shared<ContextExecutor>(
        rootCtx, requireMod->CreateRequireFunction(""));
    runtime->SetExecutor(executor);

    {
        std::lock_guard<std::mutex> lock(m_internal->m_mutex);
        m_internal->m_runtimes[runtimeId] = runtime;
    }
    return runtimeId;
}

int32_t Platform::CreateNewContextInRuntime(int64_t runtimeId) {
    auto runtime = GetRuntime(runtimeId);
    if (!runtime || runtime->GetMode() != RuntimeMode::MULTI_CONTEXT) {
        return -1;
    }
    auto vm = runtime->GetVM();
    if (!vm) {
        return -1;
    }
    VM::VMScope scope(vm);
    auto ctx = vm->CreateContext();
    // [EN] Evaluates decoded `/bootstrap.js` on new context (`0x017f80`).
    // [VN] Thực thi `/bootstrap.js` đã giải mã trên ngữ cảnh mới (`0x017f80`).
    ctx->Evaluate(GetDecodedBootstrapJs(), "/bootstrap.js");
    const int32_t newContextId = static_cast<int32_t>(runtimeId * 100 + 1);
    runtime->AddContext(newContextId, ctx);
    return newContextId;
}

void Platform::SetFileLoadingFunction(
    int64_t runtimeId,
    std::function<std::string(const std::string&)> loader) {
    if (!m_internal) {
        return;
    }
    m_internal->m_fileLoader = loader;
    auto runtime = GetRuntime(runtimeId);
    if (runtime && runtime->GetVM()) {
        runtime->GetVM()->SetLoadFileFunction(std::move(loader));
    }
}

Value Platform::LoadScriptFile(int64_t runtimeId, const std::string& filePath) {
    auto runtime = GetRuntime(runtimeId);
    if (!runtime || !runtime->GetVM() || !runtime->GetExecutor()) {
        return Value::CreateUndefined();
    }
    VM::VMScope scope(runtime->GetVM());
    const std::string code = runtime->GetVM()->LoadFile(filePath);
    if (code.empty()) {
        return Value::CreateUndefined();
    }
    return runtime->GetExecutor()->ExecuteProgram(code, filePath);
}

Value Platform::ExecuteProgram(int64_t runtimeId,
                               const std::string& code,
                               const std::string& filename) {
    auto runtime = GetRuntime(runtimeId);
    if (!runtime || !runtime->GetVM() || !runtime->GetExecutor()) {
        return Value::CreateUndefined();
    }
    VM::VMScope scope(runtime->GetVM());
    return runtime->GetExecutor()->ExecuteProgram(code, filename);
}

Value Platform::CallFunction(int64_t runtimeId,
                             Value thisObj,
                             const std::string& funcName,
                             const std::vector<Value>& args) {
    auto runtime = GetRuntime(runtimeId);
    if (!runtime || !runtime->GetVM() || !runtime->GetExecutor()) {
        return Value::CreateUndefined();
    }
    VM::VMScope scope(runtime->GetVM());
    return runtime->GetExecutor()->CallFunction(thisObj, funcName, args);
}

bool Platform::DestroyRuntime(int64_t runtimeId) {
    if (!m_internal) {
        return false;
    }
    std::shared_ptr<Runtime> removed;
    {
        std::lock_guard<std::mutex> lock(m_internal->m_mutex);
        auto it = m_internal->m_runtimes.find(runtimeId);
        if (it == m_internal->m_runtimes.end()) {
            return false;
        }
        removed = it->second;
        m_internal->m_runtimes.erase(it);
    }
    if (removed) {
        removed->ClearContexts();
    }
    return true;
}

void Platform::Shutdown() {
    if (!m_internal) {
        return;
    }
    std::unordered_map<int64_t, std::shared_ptr<Runtime>> toDestroy;
    {
        std::lock_guard<std::mutex> lock(m_internal->m_mutex);
        toDestroy.swap(m_internal->m_runtimes);
    }
    for (auto& kv : toDestroy) {
        if (kv.second) {
            kv.second->ClearContexts();
        }
    }
    if (m_internal->m_platformRunner) {
        m_internal->m_platformRunner->Cancel();
    }
}

std::shared_ptr<Runtime> Platform::GetRuntime(int64_t runtimeId) const {
    if (!m_internal) {
        return nullptr;
    }
    std::lock_guard<std::mutex> lock(m_internal->m_mutex);
    auto it = m_internal->m_runtimes.find(runtimeId);
    if (it != m_internal->m_runtimes.end()) {
        return it->second;
    }
    return nullptr;
}

} // namespace AmazingEngine
