# socket 模块常用方法速查

本文档面向初学者，整理 `socket` 模块的常用方法、基本用法与注意点，并附带练习题。

---

## 1. 基本概念

- `socket` 用于网络通信，常见有 TCP 和 UDP。
- TCP 面向连接、可靠；UDP 无连接、轻量。
- 服务器端与客户端的流程略有不同。

---

## 2. 常用对象与方法

### 2.1 创建 socket

```python
import socket

# TCP 套接字
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# UDP 套接字
u = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
```

### 2.2 服务器端常用方法（TCP）

- `bind((ip, port))`：绑定 IP 和端口
- `listen(backlog)`：开始监听，`backlog` 为最大等待连接数
- `accept()`：等待客户端连接，返回 `(conn, addr)`
- `recv(size)`：接收数据
- `send(data)` / `sendall(data)`：发送数据
- `close()`：关闭连接

```python
import socket

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(("127.0.0.1", 8080))
server.listen(5)

conn, addr = server.accept()
print("client:", addr)

data = conn.recv(1024)
conn.sendall(b"ok")

conn.close()
server.close()
```

### 2.3 客户端常用方法（TCP）

- `connect((ip, port))`：连接服务器
- `send(data)` / `sendall(data)`：发送数据
- `recv(size)`：接收数据
- `close()`：关闭连接

```python
import socket

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(("127.0.0.1", 8080))

client.sendall(b"hello")
resp = client.recv(1024)
print(resp)

client.close()
```

### 2.4 UDP 常用方法

- `sendto(data, (ip, port))`：发送 UDP 数据
- `recvfrom(size)`：接收 UDP 数据，返回 `(data, addr)`

```python
import socket

udp = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
udp.sendto(b"ping", ("127.0.0.1", 9000))

data, addr = udp.recvfrom(1024)
print(data, addr)

udp.close()
```

---

## 3. 常见注意点

- TCP 必须 `connect()` 才能 `send()`，UDP 不需要连接。
- `send()` 可能只发送部分数据，建议用 `sendall()`。
- `recv()` 返回 `b""` 表示对端关闭。
- 端口号范围是 0-65535，常用 1024 以上。

---
