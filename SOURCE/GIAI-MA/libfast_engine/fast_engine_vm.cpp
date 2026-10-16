// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libfast_engine.so (ByteDance Embedded Bytecode Scripting Engine & VM)
// File: fast_engine_vm.cpp
// Description: Implementation of VM execution loop, Frame, CodeObj, and Specializations
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#include "fast_engine_vm.h"
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <algorithm>

namespace fast_engine {

// ===================================================================================
// CODE OBJECT IMPLEMENTATION
// ===================================================================================

CodeObj::CodeObj(const std::string& n, const std::string& f, int32_t args)
    : Obj(ObjTypeTag::TYPE_CODE), name(n), filename(f), arg_count(args) {}

CodeObj::~CodeObj() {
    for (Obj* c : consts) {
        if (c) c->DecRef();
    }
}

// EN: Query source line number from bytecode address (Opcode 0xb7b20: CodeObj::Addr2Line)
// VN: Tra cứu số dòng mã nguồn từ địa chỉ bytecode (Opcode 0xb7b20: CodeObj::Addr2Line)
int32_t CodeObj::Addr2Line(int32_t addr) const {
    if (line_offsets.empty()) return 1;

    int32_t last_line = line_offsets[0].second;
    for (const auto& entry : line_offsets) {
        if (entry.first > addr) break;
        last_line = entry.second;
    }
    return last_line;
}

// ===================================================================================
// STACK FRAME IMPLEMENTATION
// ===================================================================================

FrameObj::FrameObj(CodeObj* c, DictObj* g, FrameObj* b)
    : Obj(ObjTypeTag::TYPE_CUSTOM), code(c), back(b), globals(g), ip(0) {
    if (code) {
        code->IncRef();
        locals.assign(code->varnames.size(), nullptr);
    }
    if (globals) {
        globals->IncRef();
    }
    stack.reserve(64);
}

FrameObj::~FrameObj() {
    for (Obj* loc : locals) {
        if (loc) loc->DecRef();
    }
    for (Obj* s : stack) {
        if (s) s->DecRef();
    }
    if (code) code->DecRef();
    if (globals) globals->DecRef();
}

void FrameObj::Push(Obj* obj) {
    if (obj) obj->IncRef();
    stack.push_back(obj);
}

Obj* FrameObj::Pop() {
    if (stack.empty()) return nullptr;
    Obj* top = stack.back();
    stack.pop_back();
    // Return with existing reference
    return top;
}

Obj* FrameObj::Top() const {
    return stack.empty() ? nullptr : stack.back();
}

void FrameObj::SetLocal(size_t index, Obj* obj) {
    if (index >= locals.size()) {
        locals.resize(index + 1, nullptr);
    }
    if (obj) obj->IncRef();
    if (locals[index]) locals[index]->DecRef();
    locals[index] = obj;
}

Obj* FrameObj::GetLocal(size_t index) const {
    if (index >= locals.size()) return nullptr;
    return locals[index];
}

// ===================================================================================
// FUNCTION OBJECT IMPLEMENTATION
// ===================================================================================

FuncObj::FuncObj(CodeObj* c, DictObj* g, const std::string& n)
    : Obj(ObjTypeTag::TYPE_FUNC), code(c), globals(g), name(n) {
    if (code) code->IncRef();
    if (globals) globals->IncRef();
}

FuncObj::~FuncObj() {
    if (code) code->DecRef();
    if (globals) globals->DecRef();
}

CFuncObj::CFuncObj(const std::string& n, NativeFn fn)
    : Obj(ObjTypeTag::TYPE_CFUNC), name(n), callback(std::move(fn)) {}

// ===================================================================================
// VIRTUAL MACHINE EXECUTION LOOP & ARITHMETIC DISPATCH
// ===================================================================================

Obj* VM::BinaryOp(Opcode op, Obj* left, Obj* right, Engine* engine) {
    if (!left || !right) return nullptr;

    // Both Integers
    if (left->type_tag == ObjTypeTag::TYPE_INT && right->type_tag == ObjTypeTag::TYPE_INT) {
        int64_t a = static_cast<LongObj*>(left)->val;
        int64_t b = static_cast<LongObj*>(right)->val;

        switch (op) {
            case Opcode::BINARY_ADD:
            case Opcode::INPLACE_ADD:
                return new LongObj(a + b);
            case Opcode::BINARY_SUBTRACT:
            case Opcode::INPLACE_SUBTRACT: // Opcode 0x4cfb0: InplaceSub
                return new LongObj(a - b);
            case Opcode::BINARY_MULTIPLY:
                return new LongObj(a * b);
            case Opcode::BINARY_TRUE_DIVIDE:
                if (b == 0) return nullptr; // Zero Division
                return new FloatObj(static_cast<double>(a) / static_cast<double>(b));
            case Opcode::BINARY_MODULO:
                if (b == 0) return nullptr;
                return new LongObj(a % b);
            case Opcode::BINARY_POWER:
                return new LongObj(static_cast<int64_t>(std::pow(a, b)));
            case Opcode::BINARY_AND: // Opcode 0x4cbc0: InplaceAnd
                return new LongObj(a & b);
            case Opcode::BINARY_OR:
                return new LongObj(a | b);
            case Opcode::BINARY_XOR:
                return new LongObj(a ^ b);
            default:
                break;
        }
    }

    // Floating point operations (either is Float)
    if ((left->type_tag == ObjTypeTag::TYPE_FLOAT || left->type_tag == ObjTypeTag::TYPE_INT) &&
        (right->type_tag == ObjTypeTag::TYPE_FLOAT || right->type_tag == ObjTypeTag::TYPE_INT)) {
        double a = (left->type_tag == ObjTypeTag::TYPE_FLOAT)
            ? static_cast<FloatObj*>(left)->val
            : static_cast<double>(static_cast<LongObj*>(left)->val);
        double b = (right->type_tag == ObjTypeTag::TYPE_FLOAT)
            ? static_cast<FloatObj*>(right)->val
            : static_cast<double>(static_cast<LongObj*>(right)->val);

        switch (op) {
            case Opcode::BINARY_ADD:
            case Opcode::INPLACE_ADD:
                return new FloatObj(a + b);
            case Opcode::BINARY_SUBTRACT:
            case Opcode::INPLACE_SUBTRACT:
                return new FloatObj(a - b);
            case Opcode::BINARY_MULTIPLY:
                return new FloatObj(a * b);
            case Opcode::BINARY_TRUE_DIVIDE:
                if (std::abs(b) < 1e-15) return nullptr;
                return new FloatObj(a / b);
            case Opcode::BINARY_POWER:
                return new FloatObj(std::pow(a, b));
            default:
                break;
        }
    }

    // String Concatenation & Repetition
    if (left->type_tag == ObjTypeTag::TYPE_STR && right->type_tag == ObjTypeTag::TYPE_STR) {
        if (op == Opcode::BINARY_ADD || op == Opcode::INPLACE_ADD) {
            return new StrObj(static_cast<StrObj*>(left)->val + static_cast<StrObj*>(right)->val);
        }
    }

    if (left->type_tag == ObjTypeTag::TYPE_STR && right->type_tag == ObjTypeTag::TYPE_INT) {
        if (op == Opcode::BINARY_MULTIPLY) {
            int64_t count = static_cast<LongObj*>(right)->val;
            std::string res;
            if (count > 0) {
                res.reserve(static_cast<StrObj*>(left)->val.length() * count);
                for (int64_t i = 0; i < count; ++i) {
                    res += static_cast<StrObj*>(left)->val;
                }
            }
            return new StrObj(res);
        }
    }

    return nullptr;
}

bool VM::Compare(CompareOp op, Obj* left, Obj* right, Engine* /*engine*/) {
    if (!left || !right) return false;

    // Numerical comparison
    if ((left->type_tag == ObjTypeTag::TYPE_INT || left->type_tag == ObjTypeTag::TYPE_FLOAT) &&
        (right->type_tag == ObjTypeTag::TYPE_INT || right->type_tag == ObjTypeTag::TYPE_FLOAT)) {
        double a = (left->type_tag == ObjTypeTag::TYPE_FLOAT)
            ? static_cast<FloatObj*>(left)->val
            : static_cast<double>(static_cast<LongObj*>(left)->val);
        double b = (right->type_tag == ObjTypeTag::TYPE_FLOAT)
            ? static_cast<FloatObj*>(right)->val
            : static_cast<double>(static_cast<LongObj*>(right)->val);

        switch (op) {
            case CompareOp::LT: return a < b;
            case CompareOp::LE: return a <= b;
            case CompareOp::EQ: return a == b;
            case CompareOp::NE: return a != b;
            case CompareOp::GT: return a > b;
            case CompareOp::GE: return a >= b;
        }
    }

    // String comparison
    if (left->type_tag == ObjTypeTag::TYPE_STR && right->type_tag == ObjTypeTag::TYPE_STR) {
        const std::string& a = static_cast<StrObj*>(left)->val;
        const std::string& b = static_cast<StrObj*>(right)->val;

        switch (op) {
            case CompareOp::LT: return a < b;
            case CompareOp::LE: return a <= b;
            case CompareOp::EQ: return a == b;
            case CompareOp::NE: return a != b;
            case CompareOp::GT: return a > b;
            case CompareOp::GE: return a >= b;
        }
    }

    if (op == CompareOp::EQ) return left->Equals(right);
    if (op == CompareOp::NE) return !left->Equals(right);

    return false;
}

// EN: Core bytecode interpreter loop (Opcode 0x510a8: fast_engine::Call)
// VN: Vòng lặp thông dịch bytecode cốt lõi (Opcode 0x510a8: fast_engine::Call)
Obj* VM::Execute(FrameObj* frame, Engine* engine) {
    if (!frame || !frame->code) return nullptr;

    const auto& bc = frame->code->bytecode;
    size_t bc_size = bc.size();

    while (frame->ip < bc_size) {
        uint8_t op_byte = bc[frame->ip++];
        auto op = static_cast<Opcode>(op_byte);

        uint16_t arg = 0;
        // Opcodes >= 90 have a 16-bit argument encoded in little-endian
        if (op_byte >= 90 && frame->ip + 1 < bc_size) {
            arg = static_cast<uint16_t>(bc[frame->ip]) | (static_cast<uint16_t>(bc[frame->ip + 1]) << 8);
            frame->ip += 2;
        }

        switch (op) {
            case Opcode::NOP:
                break;

            case Opcode::POP_TOP: {
                Obj* top = frame->Pop();
                if (top) top->DecRef();
                break;
            }

            case Opcode::LOAD_CONST: {
                if (arg < frame->code->consts.size()) {
                    frame->Push(frame->code->consts[arg]);
                }
                break;
            }

            case Opcode::LOAD_FAST: {
                Obj* local_val = frame->GetLocal(arg);
                frame->Push(local_val ? local_val : NullObj::GetInstance());
                break;
            }

            case Opcode::STORE_FAST: {
                Obj* val = frame->Pop();
                frame->SetLocal(arg, val);
                if (val) val->DecRef();
                break;
            }

            case Opcode::LOAD_GLOBAL: {
                if (arg < frame->code->names.size()) {
                    const std::string& name = frame->code->names[arg];
                    Obj* global_val = frame->globals ? frame->globals->GetItemString(name) : nullptr;
                    frame->Push(global_val ? global_val : NullObj::GetInstance());
                }
                break;
            }

            case Opcode::STORE_GLOBAL: {
                if (arg < frame->code->names.size() && frame->globals) {
                    const std::string& name = frame->code->names[arg];
                    Obj* val = frame->Pop();
                    frame->globals->SetItemStringRef(name, val, engine);
                    if (val) val->DecRef();
                }
                break;
            }

            case Opcode::BINARY_ADD:
            case Opcode::BINARY_SUBTRACT:
            case Opcode::BINARY_MULTIPLY:
            case Opcode::BINARY_TRUE_DIVIDE:
            case Opcode::BINARY_MODULO:
            case Opcode::BINARY_POWER:
            case Opcode::BINARY_AND:
            case Opcode::BINARY_OR:
            case Opcode::BINARY_XOR:
            case Opcode::INPLACE_ADD:
            case Opcode::INPLACE_SUBTRACT: {
                Obj* right = frame->Pop();
                Obj* left = frame->Pop();
                Obj* res = BinaryOp(op, left, right, engine);
                frame->Push(res ? res : NullObj::GetInstance());
                if (res) res->DecRef(); // Frame::Push increfs, so balance new allocation
                if (left) left->DecRef();
                if (right) right->DecRef();
                break;
            }

            case Opcode::COMPARE_OP: {
                Obj* right = frame->Pop();
                Obj* left = frame->Pop();
                bool cmp_result = Compare(static_cast<CompareOp>(arg), left, right, engine);
                frame->Push(BoolObj::FromBool(cmp_result));
                if (left) left->DecRef();
                if (right) right->DecRef();
                break;
            }

            case Opcode::POP_JUMP_IF_FALSE: {
                Obj* cond = frame->Pop();
                if (cond && !cond->IsTrue()) {
                    frame->ip = arg;
                }
                if (cond) cond->DecRef();
                break;
            }

            case Opcode::POP_JUMP_IF_TRUE: {
                Obj* cond = frame->Pop();
                if (cond && cond->IsTrue()) {
                    frame->ip = arg;
                }
                if (cond) cond->DecRef();
                break;
            }

            case Opcode::JUMP_FORWARD: {
                frame->ip += arg;
                break;
            }

            case Opcode::JUMP_ABSOLUTE: {
                frame->ip = arg;
                break;
            }

            case Opcode::BUILD_TUPLE: {
                std::vector<Obj*> elements(arg, nullptr);
                for (int i = arg - 1; i >= 0; --i) {
                    elements[i] = frame->Pop();
                }
                auto* tup = new TupleObj(elements);
                frame->Push(tup);
                tup->DecRef();
                for (Obj* elem : elements) {
                    if (elem) elem->DecRef();
                }
                break;
            }

            case Opcode::BUILD_LIST: {
                auto* list = new ListObj(arg);
                std::vector<Obj*> elements(arg, nullptr);
                for (int i = arg - 1; i >= 0; --i) {
                    elements[i] = frame->Pop();
                }
                for (Obj* elem : elements) {
                    list->Append(elem);
                    if (elem) elem->DecRef();
                }
                frame->Push(list);
                list->DecRef();
                break;
            }

            case Opcode::BUILD_MAP: {
                auto* dict = new DictObj();
                // Pop arg pairs of (key, value)
                for (size_t i = 0; i < arg; ++i) {
                    Obj* val = frame->Pop();
                    Obj* key = frame->Pop();
                    dict->SetItem(key, val, engine);
                    if (key) key->DecRef();
                    if (val) val->DecRef();
                }
                frame->Push(dict);
                dict->DecRef();
                break;
            }

            case Opcode::BINARY_SUBSCR: {
                Obj* sub = frame->Pop();
                Obj* container = frame->Pop();
                Obj* item = nullptr;

                if (container && sub) {
                    if (container->type_tag == ObjTypeTag::TYPE_LIST && sub->type_tag == ObjTypeTag::TYPE_INT) {
                        int64_t idx = static_cast<LongObj*>(sub)->val;
                        auto* lst = static_cast<ListObj*>(container);
                        if (idx >= 0 && static_cast<size_t>(idx) < lst->Size()) {
                            item = lst->GetItem(static_cast<size_t>(idx));
                        }
                    } else if (container->type_tag == ObjTypeTag::TYPE_DICT) {
                        item = static_cast<DictObj*>(container)->GetItem(sub, engine);
                    }
                }

                frame->Push(item ? item : NullObj::GetInstance());
                if (container) container->DecRef();
                if (sub) sub->DecRef();
                break;
            }

            case Opcode::CALL_FUNCTION: {
                std::vector<Obj*> args(arg, nullptr);
                for (int i = arg - 1; i >= 0; --i) {
                    args[i] = frame->Pop();
                }
                Obj* callable = frame->Pop();
                Obj* res = CallFunctionObjArgs(engine, callable, args);
                frame->Push(res ? res : NullObj::GetInstance());
                if (res) res->DecRef();
                if (callable) callable->DecRef();
                for (Obj* a : args) {
                    if (a) a->DecRef();
                }
                break;
            }

            case Opcode::RETURN_VALUE: {
                return frame->Pop();
            }

            default:
                break;
        }
    }

    return NullObj::GetInstance();
}

// EN: Global call dispatcher matching ABI symbol fast_engine::Call (Opcode 0x510a8)
// VN: Hàm điều phối gọi hàm toàn cục khớp biểu tượng ABI fast_engine::Call (Opcode 0x510a8)
Obj* Call(Engine* engine, Obj* callable, TupleObj* args, DictObj* kwargs) {
    if (!callable) return nullptr;

    if (callable->type_tag == ObjTypeTag::TYPE_FUNC) {
        auto* func = static_cast<FuncObj*>(callable);
        auto* child_frame = new FrameObj(func->code, func->globals);

        if (args) {
            for (size_t i = 0; i < args->Size(); ++i) {
                child_frame->SetLocal(i, args->GetItem(i));
            }
        }

        Obj* ret_val = VM::Execute(child_frame, engine);
        child_frame->DecRef();
        return ret_val;
    }

    if (callable->type_tag == ObjTypeTag::TYPE_CFUNC) {
        auto* cfunc = static_cast<CFuncObj*>(callable);
        if (cfunc->callback) {
            return cfunc->callback(engine, args, kwargs);
        }
    }

    return nullptr;
}

// EN: Variadic call dispatcher matching ABI symbol fast_engine::CallFunctionObjArgs (Opcode 0x512fc)
// VN: Hàm điều phối gọi hàm với danh sách tham số bất định (Opcode 0x512fc)
Obj* CallFunctionObjArgs(Engine* engine, Obj* callable, const std::vector<Obj*>& args) {
    auto* tuple_args = new TupleObj(args);
    Obj* res = Call(engine, callable, tuple_args, nullptr);
    tuple_args->DecRef();
    return res;
}

namespace specialize {

// EN: Specialized inline global loading cache (Opcode 0x573dc: specialize::LoadGlobal)
// VN: Bộ nhớ đệm nạp biến toàn cục nội tuyến chuyên biệt hóa (Opcode 0x573dc: specialize::LoadGlobal)
Obj* LoadGlobal(DictObj* globals, DictObj* builtins, uint16_t* /*cache_index*/, StrObj* name, Engine* engine) {
    if (!name) return nullptr;

    if (globals) {
        Obj* val = globals->GetItem(name, engine);
        if (val) return val;
    }

    if (builtins) {
        Obj* val = builtins->GetItem(name, engine);
        if (val) return val;
    }

    return nullptr;
}

// EN: Specialized inline method lookup cache (Opcode 0x57234: specialize::LoadMethod)
// VN: Bộ nhớ đệm tra cứu phương thức nội tuyến chuyên biệt hóa (Opcode 0x57234: specialize::LoadMethod)
Obj* LoadMethod(Obj* target, Obj* method_name, uint16_t* /*cache_index*/, Engine* engine) {
    if (!target || !method_name) return nullptr;

    if (target->type_tag == ObjTypeTag::TYPE_DICT) {
        return static_cast<DictObj*>(target)->GetItem(method_name, engine);
    }

    return nullptr;
}

} // namespace specialize

} // namespace fast_engine
