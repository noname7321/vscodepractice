from multiprocessing import Process
import time,os

def run():
    print(f"子进程 {os.getpid()} 开始运行")
    # p指的是process对象，id指的是进程id
    time.sleep(1)
    print(f"子进程 {os.getpid()} 结束运行")
if __name__ == "__main__":
    print(f"主进程 {os.getpid()} 开始运行")
    for i in range(3):
        p = Process(target=run)
        p.start()
        p.join() #等待子进程结束
    print(f"主进程 {os.getpid()} 结束运行")