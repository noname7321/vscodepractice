from multiprocessing import Process, Queue
import time,os

a=100

def write_msg(q):#q是一个Queue对象
    global a
    print(f"子进程 1 开始运行")
    if not q.full(): #判断队列是否已满
        for i in range(5):
            a+=20
            q.put(a) #将a的值放入队列中
            print(f"子进程 1 向队列中放入了一个元素：{a}")
            time.sleep(1)
    q.put(None) #向队列中放入一个None，表示写进程结束
    print(f"子进程 1 结束运行")

def read_msg(q):
    time.sleep(0.5) #让读进程稍微晚一点启动，确保写进程已经向队列中放入了一些元素
    while True:
        msg = q.get()  # 阻塞等待
        if msg is None:
            break
        print(f"子进程 2 取出：{msg}")
        time.sleep(0.5)

    # while not q.empty(): #判断队列是否为空
    #     msg = q.get() #从队列中取出一个元素
    #     print(f"子进程 2 从队列中取出了一个元素：{msg}")
    #     time.sleep(0.5)
# multiprocessing.Queue.empty() / full() 在多进程间并不可靠；
# 在调用 q.empty() 后队列状态可能立即改变（竞态条件）。
# 因此用 while not q.empty(): 来控制读取会导致读进程有时提前退出或错过数据。
# q.get() 默认会阻塞直到有元素；如果你用 not q.empty() 来判断再调用 q.get()，
# 在两者间可能发生调度切换导致问题。
if __name__ == "__main__":
    print(f"主进程 开始运行")
    q = Queue(5) #创建一个容量为5的队列
    p1 = Process(target=write_msg,args=(q,)) #创建写进程，传入队列对象作为参数，只有一个参数q也要写逗号
    p2 = Process(target=read_msg,args=(q,)) #创建读进程，传入队列对象作为参数
    
    p2.start() #启动读进程，先启动读进程是为了
    #让它等待写进程向队列中放入元素，避免读进程一开始就发现队列为空而退出
    #同时可以实现读进程在写进程写入元素的过程中持续读取，模拟生产者消费者模型
    p1.start() #启动写进程
    
    p1.join() #等待写进程结束
    p2.join() #等待读进程结束
    print('子进程2 结束运行')
    print(f"主进程 结束运行")
