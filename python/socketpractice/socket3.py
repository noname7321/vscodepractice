from socket import socket, AF_INET, SOCK_DGRAM
import time
import threading
ip='127.0.0.1'
port = 8888
def start_udp_server():
    server=socket(AF_INET,SOCK_DGRAM)#创建 UDP 套接字
    server.bind((ip,port))#绑定 IP 和端口
    print(f"UDP 服务器已启动，监听 {ip}:{port} ...\n")
    while True:
        data,addr=server.recvfrom(1024)
        print(f"收到来自 {addr} 的消息: {data.decode('utf-8')}\n")
        if data.decode('utf-8') == "exit":
            print("服务器已关闭\n")
            break
        data = input("请输入要发送的消息：")
        server.sendto(data.encode('utf-8'),addr)
    server.close()#关闭服务器套接字

def start_udp_client():
    client=socket(AF_INET,SOCK_DGRAM)#创建 UDP 套接字
    while True:
        data=input("请输入要发送的消息：")
        if data == "exit":
            print("客户端已关闭\n")
            break
        client.sendto(data.encode('utf-8'),(ip,port))#发送消息到指定 IP 和端口
        print(f"已发送消息: {data}\n")
        recv_data,addr=client.recvfrom(1024)
        print(f"收到来自 {addr} 的消息: {recv_data.decode('utf-8')}\n")
    client.close()#关闭客户端套接字