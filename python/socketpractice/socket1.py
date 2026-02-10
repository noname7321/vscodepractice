#### 练习 1：回显服务器（TCP）

# 目标：
# - 服务端接收客户端消息，并原样返回。
# - 客户端发送一句话，打印服务端返回内容。

# 要求：
# - 端口使用 `8888`。
# - 服务端一次只处理一个客户端即可。

# 提示：
# - 服务端流程：`socket -> bind -> listen -> accept -> recv -> sendall -> close`。

from socket import socket, AF_INET, SOCK_STREAM
import time     
import threading
#AF_INET 表示使用 IPv4 协议，SOCK_STREAM 表示使用 TCP 协议
ip='127.0.0.1'
port = 8888

def start_server():
    server_socket = socket(AF_INET, SOCK_STREAM)
    server_socket.bind((ip, port)) #绑定 IP 和端口
    server_socket.listen() #开始监听
    print(f"服务器已启动，监听 {ip}:{port} ...\n")
    client_socket, client_addr = server_socket.accept() #等待客户端连接
    print(f"客户端 {client_addr} 已连接\n")
    data=client_socket.recv(1024) #接收客户端消息
    print(f"收到客户端消息: {data.decode()}\n")
    client_socket.sendall(data) #将消息原样返回给客户端
    client_socket.close() #关闭客户端连接
    server_socket.close() #关闭服务器套接字

def start_client():
    client_socket = socket(AF_INET, SOCK_STREAM)
    client_socket.connect((ip, port)) #连接服务器
    message = "Hello, Server!"
    for i in range(5):
        client_socket.sendall(message.encode()) #发送消息
    data = client_socket.recv(1024) #接收服务器返回的消息
    print(f"收到服务器返回消息: {data.decode()}\n")
    client_socket.close() #关闭客户端套接字

if __name__ == "__main__":
    # 先启动服务器，再启动客户端

    server_thread = threading.Thread(target=start_server)
    server_thread.start()

    time.sleep(1) #确保服务器先启动
    
    start_client()