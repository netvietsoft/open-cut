// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libfast_engine.so (ByteDance Embedded Bytecode Scripting Engine & VM)
// File: fast_engine_vm.h
// Description: Virtual Machine bytecode execution loop, Frame, CodeObj, and Specializations
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#pragma once

#include "fast_engine_types.h"
#include "fast_engine_obj.h"
#include <vector>
#include <string>
#include <memory>
#include <functional>

namespace fast_engine {

// EN: Code Object containing compiled bytecode and constant pool (Opcode 0x13cbb8: vtable for CodeObj)
// VN: Đối tượng mã lệnh chứa bytecode đã biên dịch và bảng hằng số (Opcode 0x13cbb8: vtable for CodeObj)
class CodeObj : public Obj {
public:
    std::string name;
    std::string filename;
    std::vector<uint8_t> bytecode;
    std::vector<Obj*> consts;
    std::vector<std::string> varnames;
    std::vector<std::string> names;
    std::vector<std::pair<int32_t, int32_t>> line_offsets; // (bytecode_offset, line_number)
    int32_t arg_count = 0;

    CodeObj(const std::string& n, const std::string& f, int32_t args);
    ~CodeObj() override;

    // EN: Query source line number from bytecode address (Opcode 0xb7b20: CodeObj::Addr2Line)
    // VN: Tra cứu số dòng mã nguồn từ địa chỉ bytecode (Opcode 0xb7b20: CodeObj::Addr2Line)
    int32_t Addr2Line(int32_t addr) const;

    std::string Repr() const override { return "<code object " + name + ">"; }
};

// EN: Execution Stack Frame holding locals, stack, and IP (Opcode 0xcb244: FrameObj)
// VN: Khung ngăn xếp thực thi lưu biến cục bộ, stack và con trỏ lệnh (Opcode 0xcb244: FrameObj)
class FrameObj : public Obj {
public:
    CodeObj* code = nullptr;
    FrameObj* back = nullptr;
    DictObj* globals = nullptr;
    std::vector<Obj*> locals;
    std::vector<Obj*> stack;
    size_t ip = 0;

    FrameObj(CodeObj* c, DictObj* g, FrameObj* b = nullptr);
    ~FrameObj() override;

    void Push(Obj* obj);
    Obj* Pop();
    Obj* Top() const;
    void SetLocal(size_t index, Obj* obj);
    Obj* GetLocal(size_t index) const;

    std::string Repr() const override { return "<frame for " + (code ? code->name : "unknown") + ">"; }
};

// EN: User-defined Bytecode Function Object (Opcode 0xccee0: FuncObj)
// VN: Đối tượng hàm bytecode do người dùng định nghĩa (Opcode 0xccee0: FuncObj)
class FuncObj : public Obj {
public:
    CodeObj* code = nullptr;
    DictObj* globals = nullptr;
    std::string name;

    FuncObj(CodeObj* c, DictObj* g, const std::string& n);
    ~FuncObj() override;

    std::string Repr() const override { return "<function " + name + ">"; }
};

// EN: Native C++ Function Binding Object (Opcode 0xcc668: CFuncObj)
// VN: Đối tượng liên kết hàm C++ bản địa (Opcode 0xcc668: CFuncObj)
class CFuncObj : public Obj {
public:
    using NativeFn = std::function<Obj*(Engine*, TupleObj*, DictObj*)>;

    std::string name;
    NativeFn callback;

    CFuncObj(const std::string& n, NativeFn fn);
    ~CFuncObj() override = default;

    std::string Repr() const override { return "<built-in function " + name + ">"; }
};

// EN: Virtual Machine Engine Bytecode Evaluator
// VN: Bộ thực thi mã lệnh Bytecode của máy ảo
class VM {
public:
    // EN: Execute bytecode instructions in given frame until completion or error
    // VN: Thực thi chuỗi mã lệnh trong khung ngăn xếp cho đến khi hoàn tất hoặc lỗi
    static Obj* Execute(FrameObj* frame, Engine* engine);

    // EN: Perform binary arithmetic operation on two objects
    // VN: Thực hiện phép toán học nhị phân giữa hai đối tượng
    static Obj* BinaryOp(Opcode op, Obj* left, Obj* right, Engine* engine);

    // EN: Perform comparison operation between two objects
    // VN: Thực hiện phép so sánh giữa hai đối tượng
    static bool Compare(CompareOp op, Obj* left, Obj* right, Engine* engine);
};

// EN: Global call dispatcher matching ABI symbol fast_engine::Call (Opcode 0x510a8, 0x51034)
// VN: Hàm điều phối gọi hàm toàn cục khớp biểu tượng ABI fast_engine::Call (Opcode 0x510a8, 0x51034)
Obj* Call(Engine* engine, Obj* callable, TupleObj* args, DictObj* kwargs);

// EN: Variadic call dispatcher matching ABI symbol fast_engine::CallFunctionObjArgs (Opcode 0x512fc)
// VN: Hàm điều phối gọi hàm với danh sách tham số bất định (Opcode 0x512fc)
Obj* CallFunctionObjArgs(Engine* engine, Obj* callable, const std::vector<Obj*>& args);

namespace specialize {

// EN: Specialized inline global loading cache (Opcode 0x573dc: specialize::LoadGlobal)
// VN: Bộ nhớ đệm nạp biến toàn cục nội tuyến chuyên biệt hóa (Opcode 0x573dc: specialize::LoadGlobal)
Obj* LoadGlobal(DictObj* globals, DictObj* builtins, uint16_t* cache_index, StrObj* name, Engine* engine);

// EN: Specialized inline method lookup cache (Opcode 0x57234: specialize::LoadMethod)
// VN: Bộ nhớ đệm tra cứu phương thức nội tuyến chuyên biệt hóa (Opcode 0x57234: specialize::LoadMethod)
Obj* LoadMethod(Obj* target, Obj* method_name, uint16_t* cache_index, Engine* engine);

} // namespace specialize

} // namespace fast_engine
