import threading
from threading import Thread
import time,os

def test():
    for i in range(3):
        print(f"子线程 {threading.current_thread().name} 正在运行{i}，线程ID: {threading.get_ident()}")
        time.sleep(0.1)
if __name__ == "__main__":
    time_start=time.time()
    print(f"主线程 {threading.current_thread().name} 开始运行，线程ID: {threading.get_ident()}")
    lst=[]
    for i in range(5):
        t = Thread(target=test,name=f"Thread-{i+1}")# 各个thread执行的顺序是不确定的
        lst.append(t)
        t.start()
    for t in lst:
        t.join() #等待子线程结束
    print(f"主线程 {threading.current_thread().name} 结束运行，线程ID: {threading.get_ident()}")
    time_end=time.time()
    print(f"程序运行时间：{time_end-time_start}秒")