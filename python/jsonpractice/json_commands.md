# JSON 常用命令速查（Python）

本文按使用场景整理了 `json` 模块的常见用法，便于快速查阅。

## 1. 读取 JSON 字符串

```python
import json

json_text = '{"name": "Alice", "age": 20}'
obj = json.loads(json_text)
print(obj["name"])  # Alice
```

- `json.loads(s)`：将 JSON 字符串解析为 Python 对象。

## 2. 读取 JSON 文件

```python
import json

with open("data.json", "r", encoding="utf-8") as f:
    obj = json.load(f)
```

- `json.load(fp)`：从文件对象读取 JSON。

## 3. 写入 JSON 字符串

```python
import json

data = {"name": "Alice", "age": 20}
text = json.dumps(data, ensure_ascii=False)
print(text)
```

- `json.dumps(obj)`：将 Python 对象转为 JSON 字符串。
- `ensure_ascii=False`：保留中文，避免转义为 `\uXXXX`。

## 4. 写入 JSON 文件

```python
import json

data = {"name": "Alice", "age": 20}
with open("data.json", "w", encoding="utf-8") as f:
    json.dump(data, f, ensure_ascii=False, indent=2)
```

- `json.dump(obj, fp)`：写入 JSON 到文件对象。
- `indent=2`：格式化缩进，便于阅读。

## 5. 排序键名

```python
import json

data = {"b": 2, "a": 1}
text = json.dumps(data, sort_keys=True)
print(text)  # {"a": 1, "b": 2}
```

- `sort_keys=True`：按键名排序输出。

## 6. 自定义序列化（处理 datetime 等）

```python
import json
from datetime import datetime

class DateTimeEncoder(json.JSONEncoder):
    def default(self, obj):
        if isinstance(obj, datetime):
            return obj.isoformat()
        return super().default(obj)

payload = {"time": datetime.now()}
text = json.dumps(payload, cls=DateTimeEncoder)
print(text)
```

- `cls=...`：自定义 `JSONEncoder` 以处理特殊类型。

## 7. 处理非标准 JSON

```python
import json

text = "{'name': 'Alice'}"  # 单引号，不是标准 JSON
# 先替换或清洗后再 loads
text = text.replace("'", '"')
obj = json.loads(text)
```

- 标准 JSON 必须使用双引号。

## 8. 常用参数速记

- `ensure_ascii`：是否转义非 ASCII 字符。
- `indent`：格式化缩进空格数。
- `separators`：控制分隔符，例如 `(',', ':')` 去掉空格。
- `sort_keys`：按键名排序。
- `default`：传入函数，处理无法序列化的对象。

---

如需补充实战示例，可在该文件中继续追加。
