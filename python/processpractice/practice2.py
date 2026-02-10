from multiprocessing import Process
import time,os

class subprocess(Process):
    def __init__(self,name):
        super().__init__()
        self.name = name
    def run(self):
        print(f"子进程 {self.name} 开始运行，PID: {os.getpid()}, 其父进程PID: {os.getppid()}")
        time.sleep(1)
        print(f"子进程 {self.name} 结束运行，PID: {os.getpid()}")

if __name__ == "__main__":
    print(f"主进程 {os.getpid()} 开始运行")
    lst=[]
    for i in range(5):
        p = subprocess(name=f"SubProcess{i+1}")
        lst.append(p)
        p.start()
    for p in lst:
        p.join() #等待子进程结束
    print(f"主进程 {os.getpid()} 结束运行")