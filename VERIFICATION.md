# 核实指引（给 Codex / 独立复核者）

## 1. 这是什么

`_pypinot.so`（Python C 扩展）的**只读静态重建**。原始二进制与重建产物均未执行。

## 2. 构建

```bash
cd reconstructed_cpp/H0PP
g++ -std=gnu++17 -fsyntax-only -I . H0PP_tu/part_0001.cpp
g++ -std=gnu++17 -fsyntax-only -I . H0PP_tu/part_0002.cpp
g++ -std=gnu++17 -fsyntax-only -I . H0PP_tu/part_0003_fixes.cpp
```

三个都应 0 error。没有可链接入口，不要期望链接成功。

## 3. 要复算的数字

| 项 | 期望 |
|---|---|
| `grep -c "^===== IDX" H0PP_all_decompiled.txt` | 280 |
| 严格语法通过 | 280 / 280 |
| `semantic/api/methods.tsv` 行数 | 9 |
| `PyInit__pypinot` 地址 | `0x6fc0` |
| `PyModuleDef` 地址 | `0x2123c0` |
| 方法表地址 / 槽数 | `0x212440` / 10（末槽零哨兵） |
| `PyTypeObject` | 不存在 |

方法表可用 `semantic/api/extract.py` 重新解析，结果应与 `methods.tsv` 逐字节一致。

## 4. 保真性检查

抽查以下函数，确认控制流、偏移、常量与伪代码一致：

| 函数 | 地址 | 为什么看 |
|---|---|---|
| `pinot_open` | `0xbf60` | `dlopen` 插件 + `ifstream` 回退两条路径 |
| `pinot_decode_slice_helper` | `0xab80` | 原始缓冲 → `map<字段名, vector<double>>` |
| `SecInfo::SecInfo` | 见符号表 | 三份副本，需确认是重载还是重复生成 |
| `getRescale` | `0xcc10` | 复权因子换算 |

## 5. 已声明的偏差

1. **`long` → `long long`**：LP64 还原（MinGW 是 LLP64）。
2. **Python C API 结构**：`PyObject` / `PyTypeObject` / `PyMethodDef` 按字节数组 + 显式偏移访问。
3. **597 处 STL 声明是占位**（`rea_v` / `rea_adr`），不是真实 libstdc++ 布局。
   这是最大的已知缺口：编译能过，但**不能据此认为运行时会正确**。
4. **758 处 `rea_bind()`** 需要按真实偏移改回直接成员访问。

## 6. 不要做的事

- 不要执行 `.so` 或任何重建产物。
- 不要因为"能编译"就认为语义正确。
- 不要用 `semantic/api/strings.tsv` 里的 `0xfd1f "?"`——那是 `1.0` 双精度常量里的一个可打印字节，不是字符串。

## 7. 回报格式

```
条目：<文件>:<行> 或 <函数> @ <地址>
现象：<与伪代码/方法表哪一点不符>
证据：<伪代码行号 / 反汇编 / 重定位条目>
影响：<个例还是整个 API 层>
```
