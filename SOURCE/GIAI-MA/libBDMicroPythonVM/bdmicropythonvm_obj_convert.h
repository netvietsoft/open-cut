/**
 * @file bdmicropythonvm_obj_convert.h
 * @brief Pitaya <-> FastEngine Object Conversion, PTYExtDict/PTYExtList/CEPExtDictObj & GetCoreError Header
 *        Header Chuyển đổi Đối tượng Pitaya <-> FastEngine, PTYExtDict/PTYExtList/CEPExtDictObj & GetCoreError
 *
 * =================================================================================================
 * [EVIDENCE CLASSIFICATION: OBSERVED (100% Disassembled from libBDMicroPythonVM.so @ 0x03bec0..0x045714)]
 * [PHÂN LOẠI BẰNG CHỨNG: OBSERVED (Giải mã 100% từ nhị phân thật libBDMicroPythonVM.so @ 0x03bec0..0x045714)]
 * =================================================================================================
 *
 * Exported Functions Covered / Các hàm Export được tái dựng trong module này:
 * 1. _ZN6pitaya16CreatePTYExtDictEPvRKNSt6__ndk110shared_ptrINS_7PTYDictEEE (@ 0x03bec0, size 180 B)
 * 2. _ZN6pitaya16CreatePTYExtListEPvRKNSt6__ndk110shared_ptrINS_7PTYListEEE (@ 0x03bf74, size 180 B)
 * 3. _ZN6pitaya14CreateCepEventEPvRKNSt6__ndk110shared_ptrINS_7PTYDictEEE   (@ 0x03c028 -> 0x03c02c, size 260 B)
 * 4. _ZN6pitaya4TaskD2Ev                                                    (@ 0x041378, size 1,136 B)
 * 5. _ZN11fast_engine12GetCoreErrorEN6pitaya9ErrorCodeEPNS_6EngineE          (@ 0x0430ac, size 1,224 B)
 * 6. _ZN11fast_engine15EnvPTYObj2MPObjERKNSt6__ndk110shared_ptrIN6pitaya9PTYObjectEEERNS1_INS2_5ErrorEEEPvb (@ 0x043c84, size 224 B)
 * 7. _ZN11fast_engine12PTYObj2MPObjERKNSt6__ndk110shared_ptrIN6pitaya9PTYObjectEEEPNS_6EngineE (@ 0x043d64, size 12 B)
 * 8. _ZN11fast_engine12MPObj2PTYObjEPNS_3ObjEPNS_6EngineE                    (@ 0x0453d4, size 12 B)
 * 9. _ZN11fast_engine15EnvMPObj2PTYObjEPvRNSt6__ndk110shared_ptrIN6pitaya5ErrorEEES0_ (@ 0x0453e0, size 336 B)
 * 10. _ZN11fast_engine10GetPTYDictEPNS_3ObjEPNS_6EngineE                     (@ 0x045530, size 288 B)
 * 11. _ZN11fast_engine10GetPTYListEPNS_3ObjEPNS_6EngineE                     (@ 0x045650, size 196 B)
 */

#ifndef NEXTAI_OPENCUT_BDMICROPYTHONVM_OBJ_CONVERT_H_
#define NEXTAI_OPENCUT_BDMICROPYTHONVM_OBJ_CONVERT_H_

#include "bdmicropythonvm_types.h"

namespace pitaya {

/**
 * @brief pitaya::PTYExtDict (size 0x50 = 80 bytes, vtable @ 0x05ee30 in .data.rel.ro).
 *        Lớp từ điển mở rộng pitaya::PTYExtDict (kích thước 0x50 = 80 bytes, vtable tại 0x05ee30).
 *
 * [OBSERVED @ 0x03bec0..0x03bf70]:
 * - Base fast_engine::ExtDictObj (0x40 = 64 bytes)
 * - Offset +0x40..+0x48: std::shared_ptr<pitaya::PTYDict> pty_dict_ (`stp x9, x8, [x19, #0x40]`)
 * - Vtable methods @ 0x05ee40..0x05ee98:
 *   - 0x03c4e4: ~PTYExtDict() D2
 *   - 0x03c538: ~PTYExtDict() D0
 *   - 0x03c58c: Str()
 *   - 0x03c5e4: Reset()
 *   - 0x03c634: GetItem(Obj* key)
 *   - 0x03c660: SetItem(Obj* key, Obj* val)
 *   - 0x03cb90: DelItem(Obj* key)
 *   - 0x03ceb4: Keys()
 *   - 0x03d004: Len()
 *   - 0x03d224: Contains(Obj* key)
 */
class PTYExtDict : public fast_engine::ExtDictObj {
public:
    PTYExtDict(fast_engine::Engine* eng, std::shared_ptr<PTYDict> dict);
    ~PTYExtDict() override;

    std::string Str() const override;
    void Reset() override;

    fast_engine::Obj* GetItem(fast_engine::Obj* key) override;
    int SetItem(fast_engine::Obj* key, fast_engine::Obj* val) override;
    int DelItem(fast_engine::Obj* key) override;
    fast_engine::Obj* Keys() override;
    int64_t Len() const override;
    bool Contains(fast_engine::Obj* key) const override;

    const std::shared_ptr<PTYDict>& InnerDict() const { return pty_dict_; }
    void SetInnerDict(std::shared_ptr<PTYDict> d) { pty_dict_ = std::move(d); }

private:
    std::shared_ptr<PTYDict> pty_dict_; // +0x40..+0x48 (total size = 0x50 = 80 bytes)
};

/**
 * @brief pitaya::CEPExtDictObj (size 0x50 = 80 bytes, vtable @ 0x05ee70 in .data.rel.ro).
 *        Đối tượng sự kiện CEP pitaya::CEPExtDictObj (kích thước 0x50 = 80 bytes, vtable tại 0x05ee70).
 *
 * [OBSERVED @ 0x03c02c..0x03c12c]:
 * - Reuses pooled instances from [engine + 0x30] (`ObjCachePool::Pop`) when available,
 *   or allocates 0x50 (80) bytes and sets vtable `0x05ee70 + 0x10`.
 */
class CEPExtDictObj : public PTYExtDict {
public:
    CEPExtDictObj(fast_engine::Engine* eng, std::shared_ptr<PTYDict> dict)
        : PTYExtDict(eng, std::move(dict)) {}
    ~CEPExtDictObj() override = default;
};

/**
 * @brief pitaya::PTYExtList (size 0x50 = 80 bytes, vtable @ 0x05eeb0 in .data.rel.ro).
 *        Lớp danh sách mở rộng pitaya::PTYExtList (kích thước 0x50 = 80 bytes, vtable tại 0x05eeb0).
 *
 * [OBSERVED @ 0x03bf74..0x03c024]:
 * - Base fast_engine::ExtListObj (0x40 = 64 bytes)
 * - Offset +0x40..+0x48: std::shared_ptr<pitaya::PTYList> pty_list_ (`stp x9, x8, [x19, #0x40]`)
 * - Vtable methods @ 0x05eec0..0x05ef08:
 *   - 0x03d3cc: ~PTYExtList() D2
 *   - 0x03d420: ~PTYExtList() D0
 *   - 0x03d474: Str()
 *   - 0x03d4cc: Reset()
 *   - 0x03d4fc: GetItem(int64_t idx)
 *   - 0x03d718: SetItem(int64_t idx, Obj* val)
 *   - 0x03da38: Append(Obj* val)
 *   - 0x03dcc8: Len()
 */
class PTYExtList : public fast_engine::ExtListObj {
public:
    PTYExtList(fast_engine::Engine* eng, std::shared_ptr<PTYList> list);
    ~PTYExtList() override;

    std::string Str() const override;
    void Reset() override;

    fast_engine::Obj* GetItem(int64_t index) override;
    int SetItem(int64_t index, fast_engine::Obj* val) override;
    int Append(fast_engine::Obj* val) override;
    int64_t Len() const override;

    const std::shared_ptr<PTYList>& InnerList() const { return pty_list_; }

private:
    std::shared_ptr<PTYList> pty_list_; // +0x40..+0x48 (total size = 0x50 = 80 bytes)
};

// Exported C++ symbols in namespace pitaya / Các ký hiệu C++ được export trong namespace pitaya
void* CreatePTYExtDict(void* engine_ptr, const std::shared_ptr<PTYDict>& dict);
void* CreatePTYExtList(void* engine_ptr, const std::shared_ptr<PTYList>& list);
void* CreateCepEvent(void* engine_ptr, const std::shared_ptr<PTYDict>& dict);

/**
 * @brief Splits string by delimiter (matching _ZN6pitaya5SplitERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEES8_ @ PLT 0x00ef90).
 *        Tách chuỗi theo ký tự phân cách (khớp với pitaya::Split tại PLT 0x00ef90).
 */
std::vector<std::string> Split(const std::string& input, const std::string& delimiter);

} // namespace pitaya

namespace fast_engine {

/**
 * @brief Internal recursive Pitaya -> MicroPy conversion at 0x043574.
 *        Hàm nội bộ chuyển đổi đệ quy Pitaya -> MicroPy tại 0x043574.
 */
Obj* PTYObj2MPObj_Internal(const std::shared_ptr<pitaya::PTYObject>& pty_obj,
                           bool return_null_on_empty,
                           Engine* engine);

/**
 * @brief Internal recursive MicroPy -> Pitaya conversion at 0x043d70.
 *        Hàm nội bộ chuyển đổi đệ quy MicroPy -> Pitaya tại 0x043d70.
 */
std::shared_ptr<pitaya::PTYObject> MPObj2PTYObj_Internal(Obj* mp_obj,
                                                         bool return_null_ptr_on_empty,
                                                         Engine* engine);

// Exported C++ symbols in namespace fast_engine / Các ký hiệu C++ được export trong namespace fast_engine
std::shared_ptr<pitaya::Error> GetCoreError(pitaya::ErrorCode code, Engine* engine);

void* EnvPTYObj2MPObj(const std::shared_ptr<pitaya::PTYObject>& pty_obj,
                      std::shared_ptr<pitaya::Error>& out_error,
                      void* engine_ptr,
                      bool return_null_on_empty);

Obj* PTYObj2MPObj(const std::shared_ptr<pitaya::PTYObject>& pty_obj, Engine* engine);

std::shared_ptr<pitaya::PTYObject> MPObj2PTYObj(Obj* mp_obj, Engine* engine);

std::shared_ptr<pitaya::PTYObject> EnvMPObj2PTYObj(void* mp_obj_ptr,
                                                   std::shared_ptr<pitaya::Error>& out_error,
                                                   void* engine_ptr);

std::shared_ptr<pitaya::PTYDict> GetPTYDict(Obj* mp_obj, Engine* engine);

std::shared_ptr<pitaya::PTYList> GetPTYList(Obj* mp_obj, Engine* engine);

} // namespace fast_engine

#endif // NEXTAI_OPENCUT_BDMICROPYTHONVM_OBJ_CONVERT_H_
