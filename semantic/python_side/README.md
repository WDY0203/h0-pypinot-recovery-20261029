# `_pypinot` 的 Python 侧语义（来自 zipapp 源码）

`pypinot.restored.pyz` 里带了完整可读的 Python 源码，所以这个扩展的语义**不需要靠反编译推断**。

## 文件清单

| 文件 | 作用 |
|---|---|
| `__init__.py` | 对外 API 封装，调用 `_pypinot` 的 6 个函数 |
| `simulator.py` | 回测循环（`SmallStepRunner`）、盈亏计算、分红处理 |
| `config_parser.py` | 配置解析 |
| `const.py` | 交易日历（2015–2019 逐日列表）等常量 |
| `util.py` | `import_so`：按 Python 版本加载 `.so` |
| `external/transport/` | 基于 `bbwebsocket` 的 JSON 消息总线 |

## Python 调用了哪 6 个 C 函数

| Python 调用点 | C 函数 | 语义 |
|---|---|---|
| `__init__.py:16` | `getRescale` | 复权因子，入参 `(code + ".CNSHS", int(date))` |
| `__init__.py:19` | `getClosePrice` | 收盘价 |
| `__init__.py:22` | `getPreClosePrice` | 前收盘价 |
| `__init__.py:25` | `getLastClosePrice` | 最近收盘价 |
| `__init__.py:66` | `pinot_decode_slice_helper` | 解码二进制切片 → DataFrame 字典 |
| `__init__.py:86` | `pinot_decode_trader_helper_request_helper` | 解码成交流请求 |

另外 3 个导出函数（`pinot_open` / `pinot_close` / `pinot_getline`）在 Python 源码里**没有调用点**——
它们是给别的（未随包发布的）调用方用的，或是给 C++ 侧直接调的。

## 关键常量

- 证券代码后缀固定 `.CNSHS`
- 日期是 `int(yyyymmdd)`
- `pinot` 数据插件路径：`/opt/bbcluster/alpha/pinot/bin/libpinot_reader.so`
  （失败时回退到普通 `ifstream`）
- 消息总线默认端口 **2433**（见 `external/transport`）

## 对重建的意义

1. 4 个价格接口的签名与语义由源码直接确认，不需要从汇编猜。
2. `decode_*` 两个函数是**二进制协议解码器**，输入是 `content['binary']`，
   输出被 `read_csv_string` 转成 `pandas.DataFrame`——所以它们的输出格式是
   **CSV 风格的字符串**，字段名在 `decode_hold` / `decode_slice_price` 等函数里。
3. `simulator.py` 的 `SmallStepRunner` 是本扩展的**使用方**，
   它决定了 `decode_raw_slice` 输出的字段必须满足哪些约束。

## 与 H0-WebSocket 的关系

`external/transport` 用的是 `bbwebsocket`——也就是本仓库同批重建的
`bbwebsocket.so` / `bbwebsocket3.so`。见
`h0-websocket-recovery-20261029/semantic/PYTHON_API.md`。
