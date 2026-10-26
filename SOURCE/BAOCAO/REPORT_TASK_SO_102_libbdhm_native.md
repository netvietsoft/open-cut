# BÁO CÁO NGHIỆM THU TÁI DỰNG: `libbdhm_native.so` (`TASK_SO_102` / `TASK-091-RECONSTRUCTION-LIBBDHM_NATIVE`)

- **Thư viện mục tiêu**: `apktool-res/lib/arm64-v8a/libbdhm_native.so` (`599,968 bytes`, 78 dynamic symbols: 27 exported + 51 imported)
- **Trạng thái đối kháng Agent 13**: `VERIFIED_AND_ACCEPTED`
- **Tổng số tệp C++17 / Header tái dựng**: 8 tệp (`> 74 KB` C++17/H, `0 stubs`)

## Danh sách Tệp Mã nguồn Tái dựng (`SOURCE/GIAI-MA/libbdhm_native/`)
1. `bdhm_types.h`: Định nghĩa bố cục bộ nhớ ELF64, địa chỉ ảo 27 hàm xuất `.dynsym`, hằng số `.rodata` (`__SYS__###`, `__st_string;`, `__st_number;`, `__st_bool;`), `PropValue`, `ContextInstance`, `DeclaredManifest`, `DeclaredEvent`, `SparkTracingPerfStat`.
2. `bdhm_expr_clause_engine.h` & `bdhm_expr_clause_engine.cpp`: Triển khai `BdhmExprEngine` (`Tokenize`, `EvaluateExpression`, `ComputeFactorial`, `abs`) và `BdhmClauseEvaluator` (`$if`, `$then`, `$else`, `$eq`, `$neq`, `$lt`, `$lte`, `$gt`, `$gte`, `$in`, `$nin`, `$like`, `$not_like`, `$nil`, `$not_nil`, `$and`, `$or`) cùng `BdhmManifestParser`.
3. `bdhm_spark_tracing_engine.h` & `bdhm_spark_tracing_engine.cpp`: Triển khai `ContextPropsRepo` (kiểm tra chu trình đồ thị DAG `ring exist!`, `GetChildIds` với mặt nạ SwissTable `0x8080808080808080`, thu gom rác `RecycleExpired`) và `SparkTracingNativeEngine`.
4. `bdhm_native_interface.h`, `bdhm_native_interface.cpp` & `bdhm_native_pseudocode.cpp`: Triển khai đầy đủ 27 hàm xuất `.dynsym` (`JNI_OnLoad`, `JNI_OnUnload`, 8 hàm `JNIReachabilityFence`, 17 hàm `SparkTracingNative`).
