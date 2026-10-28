# `_pypinot` Python 扩展：只读反编译重建

`_pypinot.so`（1,032,488 B，Linux x86-64）是一个 Python C 扩展，
用于读取 A 股行情快照（`pinot` 数据源）。**原始文件与重建产物均未执行。**

## 状态

| 项 | 值 |
|---|---|
| 反编译函数 | 280 |
| 严格语法（`g++ -std=gnu++17 -fsyntax-only`，无 `-fpermissive`） | **280 / 280** |
| 翻译单元 | 3（`part_0001/0002/0003_fixes`） |
| shim 单独编译 | 0 error |
| 导出 Python 方法 | **9** |
| 是否有 `PyTypeObject` | **无**（纯函数模块，无状态对象） |
| 依赖 | `dlopen("/opt/bbcluster/alpha/pinot/bin/libpinot_reader.so")`，失败回退 `ifstream` |

## 导出 API（9 个，全部 `METH_VARARGS`，doc 为空串）

| 方法 | 实现地址 | 用途 |
|---|---|---|
| `getRescale` | `0xcc10` | 复权因子换算 |
| `getPreClosePrice` | `0xc7c0` | 前收盘价 |
| `getLastClosePrice` | `0xc930` | 最近收盘价 |
| `getClosePrice` | `0xcaa0` | 收盘价 |
| `pinot_open` | `0xbf60` | 打开数据源（dlopen 插件，失败回退文件） |
| `pinot_close` | `0xc090` | 关闭数据源 |
| `pinot_getline` | `0xc0e0` | 读一行 |
| `pinot_decode_slice_helper` | `0xab80` | 解析原始切片缓冲 |
| `pinot_decode_trader_helper_request_helper` | `0x94e0` | 解析成交流请求 |

`PyInit__pypinot` 在 `0x6fc0`，`PyModuleDef` 在 `0x2123c0`，方法表在 `0x212440`（10 槽，末槽为零哨兵）。

所有 `ml_meth` 的静态字节是 0（`R_X86_64_64` 加数在 `.rela.dyn`），上表地址是重定位合并后的值，
每个目标都在 `.symtab` 里交叉核对为已定义 `FUNC`，且都是 `pydetail::PyWrapper<...>::wrap` thunk。

## 目录

```
reconstructed_cpp/H0PP/    280 个函数的 C++ 重建 + 反编译原文 + 报告
semantic/api/              方法表、字符串表、符号表、解析脚本
```

## 怎么验

```bash
cd reconstructed_cpp/H0PP
g++ -std=gnu++17 -fsyntax-only -I . H0PP_tu/part_0001.cpp   # 0 error
grep -c "^===== IDX" H0PP_all_decompiled.txt                 # 280
```

方法表可用 `semantic/api/extract.py` 从原始 `.so` 重新解析，
输出应与 `methods.tsv` 一致。

## 已声明的偏差

1. `long` 宽度按 LP64 还原为 `long long`（MinGW 是 LLP64）。
2. `PyObject` / `PyTypeObject` / `PyMethodDef` 等结构在 shim 里是字节数组 + 显式偏移。
3. 597 处 STL 局部变量声明是**可编译占位**（`rea_v` / `rea_adr`），不是真实 libstdc++ 布局；
   要真正运行需按真实布局重写。这是已知最大缺口。
