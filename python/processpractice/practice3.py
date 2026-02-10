from multiprocessing import Process

a=100
def add():
    global a
    print(f"子进程 1 开始运行")
    a+=20
    print(f"子进程 1 结束运行")
    print(a)

def sub():
    global a
    print(f"子进程 2 开始运行")
    a-=20
    print(f"子进程 2 结束运行")
    print(a)

if __name__ == "__main__":
    print(f"主进程 开始运行")
    print(a)
    p1 = Process(target=add)
    p2 = Process(target=sub)
    
    p1.start()
    p2.start()
    
    p1.join() #等待子进程1结束
    p2.join() #等待子进程2结束

    print(a) #主进程中的a值没有被子进程修改，因为每个子进程都有自己独立的内存空间，
    #子进程对a的修改不会影响主进程中的a值
    print(f"主进程 结束运行")

