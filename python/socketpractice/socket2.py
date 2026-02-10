# 目标：
# - 写一个 UDP 程序，能发送消息到指定 IP+端口，并接收对方消息。

# 要求：
# - 使用 `sendto()` 和 `recvfrom()`。
# - 发送与接收可以放在两个循环中（先简单写单线程即可）。

# ---
from socket import socket, AF_INET, SOCK_DGRAM
import time
import threading
ip='127.0.0.1'
port = 8888
def start_udp_server():
    server_socket = socket(AF_INET, SOCK_DGRAM) #创建 UDP 套接字
    server_socket.bind((ip, port)) #绑定 IP 和端口
    print(f"UDP 服务器已启动，监听 {ip}:{port} ...\n")
    recv_data, addr = server_socket.recvfrom(1024) #接收对方消息4
    print(f"收到来自 {addr} 的消息: {recv_data.decode('utf-8')}\n")
    server_socket.close() #关闭服务器套接字

def start_udp_client():
    client_socket = socket(AF_INET, SOCK_DGRAM) #创建 UDP 套接字
    data=input("请输入要发送的消息：")
    client_socket.sendto(data.encode('utf-8'), (ip, port)) #发送消息到指定 IP 和端口
    print(f"已发送消息: {data}\n")
    recv_data, addr = client_socket.recvfrom(1024)
    #接收对方消息，addr 是发送方的地址
    print(f"收到来自 {addr} 的消息: {recv_data.decode('utf-8')}\n")
    client_socket.close() #关闭客户端套接字

if __name__ == "__main__":
    # 先启动服务器，再启动客户端

    server_thread = threading.Thread(target=start_udp_server)
    server_thread.start()

    time.sleep(1) #确保服务器先启动
    
    start_udp_client()  