# os 模块常用函数速查

本文档面向初学者，整理 `os` 模块常用函数的用途、要点与示例，方便学习与速查。

---

## 1. 基础概念

- `os` 提供操作系统相关功能（目录、路径、文件、环境变量等）。
- 不同系统（Windows / macOS / Linux）部分函数行为略有差异。
- 路径处理尽量用 `os.path`，避免手写分隔符。

---

## 2. 目录与路径常用函数

### 2.1 获取与切换当前目录

- `os.getcwd()`：获取当前工作目录

```python
import os
print(os.getcwd())
```

- `os.chdir(path)`：切换当前工作目录

```python
os.chdir("C:/Users")
print(os.getcwd())
```

### 2.2 查看目录内容

- `os.listdir(path=".")`：列出目录下的文件和文件夹名称（不含完整路径）

```python
print(os.listdir("."))
print(os.listdir("C:/Users"))
```

### 2.3 创建目录

- `os.mkdir(path)`：创建单级目录
- `os.makedirs(path, exist_ok=False)`：创建多级目录

```python
os.mkdir("demo")
os.makedirs("a/b/c", exist_ok=True)
```

### 2.4 删除目录

- `os.rmdir(path)`：删除空目录
- `os.removedirs(path)`：递归删除空目录链

```python
os.rmdir("demo")
os.removedirs("a/b/c")
```

---

## 3. 文件操作常用函数

### 3.1 删除与重命名

- `os.remove(path)`：删除文件
- `os.rename(src, dst)`：重命名或移动文件

```python
os.remove("data.txt")
os.rename("old.txt", "new.txt")
```

### 3.2 文件信息

- `os.stat(path)`：获取文件状态信息（大小、时间、权限等）

```python
info = os.stat("data.txt")
print(info.st_size)
```

### 3.3 启动文件（Windows 常用）

- `os.startfile(path)`：用系统默认程序打开文件（Windows 专用）

```python
os.startfile("report.pdf")
```

---

## 4. 目录遍历

- `os.walk(top)`：递归遍历目录树

```python
for root, dirs, files in os.walk("."):
    print(root)
    print(dirs)
    print(files)
```

---

## 5. os.path 常用函数

路径处理建议使用 `os.path`，保证跨平台。

- `os.path.join(a, b, c)`：拼接路径
- `os.path.exists(path)`：判断路径是否存在
- `os.path.isfile(path)` / `os.path.isdir(path)`：判断文件或目录
- `os.path.abspath(path)`：绝对路径
- `os.path.basename(path)`：文件名部分
- `os.path.dirname(path)`：目录部分
- `os.path.splitext(path)`：分离文件名和扩展名
- `os.path.normpath(path)`：规范化路径

```python
import os
p = os.path.join("C:", "Users", "abc", "file.txt")
print(os.path.exists(p))
print(os.path.basename(p))
print(os.path.splitext(p))
```

---

## 6. 环境变量

- `os.environ`：环境变量字典
- `os.getenv(key, default=None)`：读取环境变量
- `os.putenv(key, value)`：设置环境变量

```python
print(os.getenv("PATH"))
os.putenv("MY_VAR", "123")
```

---

## 7. 常见注意点

- `os.remove()` 只能删除文件，删除目录用 `os.rmdir()`。
- `os.rmdir()` 只能删除空目录。
- Windows 与 Unix 系统路径分隔符不同，务必使用 `os.path.join()`。
- `os.startfile()` 仅在 Windows 可用。

---

## 8. 快速清单（速查表）

| 分类 | 常用函数 | 作用 |
| --- | --- | --- |
| 当前目录 | `getcwd()` | 获取当前目录 |
| 切换目录 | `chdir(path)` | 设置当前目录 |
| 列目录 | `listdir(path)` | 获取目录内容 |
| 创建目录 | `mkdir(path)` | 创建单级目录 |
| 创建多级 | `makedirs(path)` | 创建多级目录 |
| 删除目录 | `rmdir(path)` | 删除空目录 |
| 删除多级 | `removedirs(path)` | 删除多级空目录 |
| 删除文件 | `remove(path)` | 删除文件 |
| 重命名 | `rename(old, new)` | 重命名或移动 |
| 文件信息 | `stat(path)` | 获取文件状态 |
| 遍历目录 | `walk(path)` | 递归遍历目录 |
| 打开文件 | `startfile(path)` | 调用系统打开（Windows） |

---

如果你希望我再补充更多示例（比如文件复制、权限管理、系统命令执行），告诉我想关注的方向即可。